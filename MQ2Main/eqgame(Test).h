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
#define __ExpectedVersionDate                                     "Jun 11 2018"
#define __ExpectedVersionTime                                     "18:30:08"
#define __ActualVersionDate_x                                      0xABC2F4
#define __ActualVersionTime_x                                      0xABC2E8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x608440
#define __MemChecker1_x                                            0x8D8A40
#define __MemChecker2_x                                            0x696690
#define __MemChecker3_x                                            0x6965E0
#define __MemChecker4_x                                            0x831FC0
#define __EncryptPad0_x                                            0xBEE490
#define __EncryptPad1_x                                            0xC4C170
#define __EncryptPad2_x                                            0xBFF018
#define __EncryptPad3_x                                            0xBFEC18
#define __EncryptPad4_x                                            0xC3CF08
#define __EncryptPad5_x                                            0xF09B64
#define __AC1_x                                                    0x7EE896
#define __AC2_x                                                    0x5C3F0F
#define __AC3_x                                                    0x5CAD9F
#define __AC4_x                                                    0x5CEC20
#define __AC5_x                                                    0x5D4E60
#define __AC6_x                                                    0x5D93A2
#define __AC7_x                                                    0x5C3980
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x197BC8

// Direct Input
#define DI8__Main_x                                                0xF09B88
#define DI8__Keyboard_x                                            0xF09B8C
#define DI8__Mouse_x                                               0xF09B50
#define DI8__Mouse_Copy_x                                          0xE678DC
#define DI8__Mouse_Check_x                                         0xF0AA50
#define __AutoSkillArray_x                                         0xE687EC
#define __Attack_x                                                 0xF065CB
#define __Autofire_x                                               0xF065CC
#define __BindList_x                                               0xBDD088
#define g_eqCommandStates_x                                        0xBDDDF8
#define __Clicks_x                                                 0xE67994
#define __CommandList_x                                            0xBDE9B0
#define __CurrentMapLabel_x                                        0x101C174
#define __CurrentSocial_x                                          0xBC8710
#define __DoAbilityList_x                                          0xE9E0EC
#define __do_loot_x                                                0x5916A0
#define __DrawHandler_x                                            0x1697680
#define __GroupCount_x                                             0xE5A27A
#define __Guilds_x                                                 0xE5E0E8
#define __gWorld_x                                                 0xE580DC
#define __HWnd_x                                                   0xF09B58
#define __heqmain_x                                                0x1014DAC
#define __InChatMode_x                                             0xE678C4
#define __LastTell_x                                               0xE697E8
#define __LMouseHeldTime_x                                         0xE67A00
#define __Mouse_x                                                  0xF09B70
#define __MouseLook_x                                              0xE6795A
#define __MouseEventTime_x                                         0xF07080
#define __gpbCommandEvent_x                                        0xE57C00
#define __NetStatusToggle_x                                        0xE6795D
#define __PCNames_x                                                0xE68DA8
#define __RangeAttackReady_x                                       0xE68AD0
#define __RMouseHeldTime_x                                         0xE679FC
#define __RunWalkState_x                                           0xE678C8
#define __ScreenMode_x                                             0xDA6440
#define __ScreenX_x                                                0xE6787C
#define __ScreenY_x                                                0xE67878
#define __ScreenXMax_x                                             0xE67880
#define __ScreenYMax_x                                             0xE67884
#define __ServerHost_x                                             0xE57DCB
#define __ServerName_x                                             0xE9E0AC
#define __ShiftKeyDown_x                                           0xE67F54
#define __ShowNames_x                                              0xE68C88
#define __Socials_x                                                0xE9E1AC
#define __SubscriptionType_x                                       0x105DC3C
#define __TargetAggroHolder_x                                      0x101EB2C
#define __ZoneType_x                                               0xE67D58
#define __GroupAggro_x                                             0x101EB6C
#define __LoginName_x                                              0xF0A4E4
#define __Inviter_x                                                0xF06548
#define __AttackOnAssist_x                                         0xE68C44
#define __UseTellWindows_x                                         0xE68F40
#define __gfMaxZoomCameraDistance_x                                0xAB1AF8
#define __gfMaxCameraDistance_x                                    0xADEC10
#define __pulAutoRun_x                                             0xE67978
#define __pulForward_x                                             0xE68F78
#define __pulBackward_x                                            0xE68F7C
#define __pulTurnRight_x                                           0xE68F80
#define __pulTurnLeft_x                                            0xE68F84
#define __pulStrafeLeft_x                                          0xE68F88
#define __pulStrafeRight_x                                         0xE68F8C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5A490
#define instEQZoneInfo_x                                           0xE67B50
#define instKeypressHandler_x                                      0xF07030
#define pinstActiveBanker_x                                        0xE5A220
#define pinstActiveCorpse_x                                        0xE5A218
#define pinstActiveGMaster_x                                       0xE5A21C
#define pinstActiveMerchant_x                                      0xE5A214
#define pinstAggroInfo_x                                           0xC62838
#define pinstAltAdvManager_x                                       0xDA6E30
#define pinstAuraMgr_x                                             0xC73520
#define pinstBandageTarget_x                                       0xE5A230
#define pinstCamActor_x                                            0xDA642C
#define pinstCDBStr_x                                              0xDA5B8C
#define pinstCDisplay_x                                            0xE5A478
#define pinstCEverQuest_x                                          0xF09CA8
#define pinstEverQuestInfo_x                                       0xE67870
#define pinstCharData_x                                            0xE5A488
#define pinstCharSpawn_x                                           0xE5A46C
#define pinstControlledMissile_x                                   0xE57B80
#define pinstControlledPlayer_x                                    0xE5A46C
#define pinstCResolutionHandler_x                                  0x16978B0
#define pinstCSidlManager_x                                        0x1696744
#define pinstCXWndManager_x                                        0x1696738
#define instDynamicZone_x                                          0xE5DFC0
#define pinstDZMember_x                                            0xE5E0D0
#define pinstDZTimerInfo_x                                         0xE5E0D4
#define pinstEQItemList_x                                          0xE56680
#define pinstEQObjectList_x                                        0xE57870
#define instEQMisc_x                                               0xDA5AC8
#define pinstEQSoundManager_x                                      0xDA7690
#define pinstEQSpellStrings_x                                      0xC70970
#define instExpeditionLeader_x                                     0xE5E00A
#define instExpeditionName_x                                       0xE5E04A
#define pinstGroup_x                                               0xE5A276
#define pinstImeManager_x                                          0x169673C
#define pinstLocalPlayer_x                                         0xE5A210
#define pinstMercenaryData_x                                       0xF07820
#define pinstMercenaryStats_x                                      0x101EC78
#define pinstMercAltAbilities_x                                    0xDA7400
#define pinstModelPlayer_x                                         0xE5A228
#define pinstPCData_x                                              0xE5A488
#define pinstRealEstateItems_x                                     0xF08D10
#define pinstSkillMgr_x                                            0xF08DE0
#define pinstSpawnManager_x                                        0xF083D0
#define pinstSpellManager_x                                        0xF08FB8
#define pinstSpellSets_x                                           0xEFF1F4
#define pinstStringTable_x                                         0xE5A0E4
#define pinstSwitchManager_x                                       0xE57A30
#define pinstTarget_x                                              0xE5A468
#define pinstTargetObject_x                                        0xE5A474
#define pinstTargetSwitch_x                                        0xE57B88
#define pinstTaskMember_x                                          0xDA5958
#define pinstTrackTarget_x                                         0xE5A470
#define pinstTradeTarget_x                                         0xE5A224
#define instTributeActive_x                                        0xDA5AED
#define pinstViewActor_x                                           0xDA6428
#define pinstWorldData_x                                           0xE57ED4
#define pinstZoneAddr_x                                            0xE67DF0
#define pinstPlayerPath_x                                          0xF08468
#define pinstTargetIndicator_x                                     0xF09220
#define pinstCTargetManager_x                                      0xF092B8
#define EQObject_Top_x                                             0xE5A20C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDA5C4C
#define pinstCAchievementsWnd_x                                    0xDA5EF4
#define pinstCActionsWnd_x                                         0xDA5EAC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDA5C2C
#define pinstCAdvancedLootWnd_x                                    0xDA6470
#define pinstCAdventureLeaderboardWnd_x                            0x1015948
#define pinstCAdventureRequestWnd_x                                0x10159F8
#define pinstCAdventureStatsWnd_x                                  0x1015AA8
#define pinstCAggroMeterWnd_x                                      0xDA5F18
#define pinstCAlarmWnd_x                                           0xDA5ED8
#define pinstCAlertHistoryWnd_x                                    0xDA5EB4
#define pinstCAlertStackWnd_x                                      0xDA5C44
#define pinstCAlertWnd_x                                           0xDA5C5C
#define pinstCAltStorageWnd_x                                      0x1015E08
#define pinstCAudioTriggersWindow_x                                0xC62CC8
#define pinstCAuraWnd_x                                            0xDA5F14
#define pinstCAvaZoneWnd_x                                         0xDA5E94
#define pinstCBandolierWnd_x                                       0xDA5F5C
#define pinstCBankWnd_x                                            0xDA6474
#define pinstCBarterMerchantWnd_x                                  0x1017048
#define pinstCBarterSearchWnd_x                                    0x10170F8
#define pinstCBarterWnd_x                                          0x10171A8
#define pinstCBazaarConfirmationWnd_x                              0xDA5C40
#define pinstCBazaarSearchWnd_x                                    0xDA5EC4
#define pinstCBazaarWnd_x                                          0xDA5F4C
#define pinstCBlockedBuffWnd_x                                     0xDA645C
#define pinstCBlockedPetBuffWnd_x                                  0xDA6480
#define pinstCBodyTintWnd_x                                        0xDA5C68
#define pinstCBookWnd_x                                            0xDA63E0
#define pinstCBreathWnd_x                                          0xDA5C60
#define pinstCBuffWindowNORMAL_x                                   0xDA6420
#define pinstCBuffWindowSHORT_x                                    0xDA6424
#define pinstCBugReportWnd_x                                       0xDA5C3C
#define pinstCButtonWnd_x                                          0x1696930
#define pinstCCastingWnd_x                                         0xDA5C38
#define pinstCCastSpellWnd_x                                       0xDA5ED4
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDA5C6C
#define pinstCChatWindowManager_x                                  0x1017C68
#define pinstCClaimWnd_x                                           0x1017DC0
#define pinstCColorPickerWnd_x                                     0xDA5E84
#define pinstCCombatAbilityWnd_x                                   0xDA5F24
#define pinstCCombatSkillsSelectWnd_x                              0xDA5EA8
#define pinstCCompassWnd_x                                         0xDA5C50
#define pinstCConfirmationDialog_x                                 0x101CCC0
#define pinstCContainerMgr_x                                       0xDA5F50
#define pinstCContextMenuManager_x                                 0x16966F8
#define pinstCCursorAttachment_x                                   0xDA64B4
#define pinstCDynamicZoneWnd_x                                     0x1018388
#define pinstCEditLabelWnd_x                                       0xDA63F0
#define pinstCEQMainWnd_x                                          0x10185D0
#define pinstCEventCalendarWnd_x                                   0xDA5F10
#define pinstCExtendedTargetWnd_x                                  0xDA5F0C
#define pinstCFacePick_x                                           0xDA5E8C
#define pinstCFellowshipWnd_x                                      0x10187D0
#define pinstCFileSelectionWnd_x                                   0xDA6458
#define pinstCFindItemWnd_x                                        0xDA5F38
#define pinstCFindLocationWnd_x                                    0x1018928
#define pinstCFriendsWnd_x                                         0xDA5EC8
#define pinstCGemsGameWnd_x                                        0xDA5EB0
#define pinstCGiveWnd_x                                            0xDA63DC
#define pinstCGroupSearchFiltersWnd_x                              0xDA5F30
#define pinstCGroupSearchWnd_x                                     0x1018D20
#define pinstCGroupWnd_x                                           0x1018DD0
#define pinstCGuildBankWnd_x                                       0xE68C2C
#define pinstCGuildCreationWnd_x                                   0x1018F30
#define pinstCGuildMgmtWnd_x                                       0x1018FE0
#define pinstCharacterCreation_x                                   0xDA5F1C
#define pinstCHelpWnd_x                                            0xDA5EE4
#define pinstCHeritageSelectionWnd_x                               0xDA5E98
#define pinstCHotButtonWnd_x                                       0x101B138
#define pinstCHotButtonWnd1_x                                      0x101B138
#define pinstCHotButtonWnd2_x                                      0x101B13C
#define pinstCHotButtonWnd3_x                                      0x101B140
#define pinstCHotButtonWnd4_x                                      0x101B144
#define pinstCIconSelectionWnd_x                                   0xDA648C
#define pinstCInspectWnd_x                                         0xDA6488
#define pinstCInventoryWnd_x                                       0xDA5FCC
#define pinstCInvSlotMgr_x                                         0xDA5EFC
#define pinstCItemDisplayManager_x                                 0x101B6C8
#define pinstCItemExpTransferWnd_x                                 0x101B7FC
#define pinstCItemOverflowWnd_x                                    0xDA5ECC
#define pinstCJournalCatWnd_x                                      0xDA6484
//#define pinstCJournalNPCWnd_x                                      0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDA641C
#define pinstCKeyRingWnd_x                                         0xDA6438
#define pinstCLargeDialogWnd_x                                     0x101D940
#define pinstCLayoutCopyWnd_x                                      0x101BB48
#define pinstCLFGuildWnd_x                                         0x101BBF8
#define pinstCLoadskinWnd_x                                        0xDA5EC0
#define pinstCLootFiltersCopyWnd_x                                 0xC73D00
#define pinstCLootFiltersWnd_x                                     0xDA5C74
#define pinstCLootSettingsWnd_x                                    0xDA5E80
#define pinstCLootWnd_x                                            0xDA5E7C
#define pinstCMailAddressBookWnd_x                                 0xDA6494
#define pinstCMailCompositionWnd_x                                 0xDA6478
#define pinstCMailIgnoreListWnd_x                                  0xDA6498
#define pinstCMailWnd_x                                            0xDA644C
#define pinstCManageLootWnd_x                                      0xDA72A8
#define pinstCMapToolbarWnd_x                                      0xDA5FD0
#define pinstCMapViewWnd_x                                         0xDA5F3C
#define pinstCMarketplaceWnd_x                                     0xDA5F40
#define pinstCMerchantWnd_x                                        0xDA5EA4
#define pinstCMIZoneSelectWnd_x                                    0x101C430
#define pinstCMusicPlayerWnd_x                                     0xDA6430
#define pinstCNameChangeMercWnd_x                                  0xDA647C
#define pinstCNameChangePetWnd_x                                   0xDA6454
#define pinstCNameChangeWnd_x                                      0xDA5F20
#define pinstCNoteWnd_x                                            0xDA5EE0
#define pinstCObjectPreviewWnd_x                                   0xDA63E8
#define pinstCOptionsWnd_x                                         0xDA5FD4
#define pinstCPetInfoWnd_x                                         0xDA6468
#define pinstCPetitionQWnd_x                                       0xDA6490
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDA5C64
#define pinstCPlayerWnd_x                                          0xDA5ED0
#define pinstCPopupWndManager_x                                    0x101CCC0
#define pinstCProgressionSelectionWnd_x                            0x101CD70
#define pinstCPurchaseGroupWnd_x                                   0xDA6450
#define pinstCPurchaseWnd_x                                        0xDA6410
#define pinstCPvPLeaderboardWnd_x                                  0x101CE20
#define pinstCPvPStatsWnd_x                                        0x101CED0
#define pinstCQuantityWnd_x                                        0xDA64A0
#define pinstCRaceChangeWnd_x                                      0xDA5F48
#define pinstCRaidOptionsWnd_x                                     0xDA5F34
#define pinstCRaidWnd_x                                            0xDA64A4
#define pinstCRealEstateItemsWnd_x                                 0xDA5F00
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA5F28
#define pinstCRealEstateManageWnd_x                                0xDA5E9C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDA5EB8
#define pinstCRealEstatePlotSearchWnd_x                            0xDA5EDC
#define pinstCRealEstatePurchaseWnd_x                              0xDA5EE8
#define pinstCRespawnWnd_x                                         0xDA5F2C
//#define pinstCRewardSelectionWnd_x                                 0x10205B0
#define pinstCSelectorWnd_x                                        0xDA5F08
#define pinstCSendMoneyWnd_x                                       0xDA6414
#define pinstCServerListWnd_x                                      0xDA5EF8
#define pinstCSkillsSelectWnd_x                                    0xDA5E88
#define pinstCSkillsWnd_x                                          0xDA5E78
#define pinstCSocialEditWnd_x                                      0xDA64A8
#define pinstCSocialWnd_x                                          0xDA64B0
#define pinstCSpellBookWnd_x                                       0xDA5F04
#define pinstCStoryWnd_x                                           0xDA5C48
#define pinstCTargetOfTargetWnd_x                                  0x101ED00
#define pinstCTargetWnd_x                                          0xDA6464
#define pinstCTaskOverlayWnd_x                                     0xDA5EBC
#define pinstCTaskSelectWnd_x                                      0x101EE58
#define pinstCTaskSomething_x                                      0xC74500
#define pinstCTaskTemplateSelectWnd_x                              0x101EF08
#define pinstCTaskWnd_x                                            0x101EFB8
#define pinstCTextEntryWnd_x                                       0xDA5C58
#define pinstCTextOverlay_x                                        0xC62FD8
#define pinstCTimeLeftWnd_x                                        0xDA646C
#define pinstCTipWndCONTEXT_x                                      0x101F1BC
#define pinstCTipWndOFDAY_x                                        0x101F1B8
#define pinstCTitleWnd_x                                           0x101F268
#define pinstCTrackingWnd_x                                        0xDA6460
#define pinstCTradeskillWnd_x                                      0x101F3D0
#define pinstCTradeWnd_x                                           0xDA5EEC
#define pinstCTrainWnd_x                                           0xDA649C
#define pinstCTributeBenefitWnd_x                                  0x101F5D0
#define pinstCTributeMasterWnd_x                                   0x101F680
#define pinstCTributeTrophyWnd_x                                   0x101F730
#define pinstCVideoModesWnd_x                                      0xDA64AC
#define pinstCVoiceMacroWnd_x                                      0xF097E8
#define pinstCVoteResultsWnd_x                                     0xDA6418
#define pinstCVoteWnd_x                                            0xDA63E4
#define pinstCWebManager_x                                         0xF0994C
#define pinstCZoneGuideWnd_x                                       0xDA5E90
#define pinstCZonePathWnd_x                                        0xDA5EA0

#define pinstEQSuiteTextureLoader_x                                0xC4DC28
#define pinstItemIconCache_x                                       0x1018588
#define pinstLootFiltersManager_x                                  0xC73DB0
#define pinstRewardSelectionWnd_x                                  0x101D618

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xBFEC0C
#define __CastRay_x                                                0x58CBC0
#define __CastRay2_x                                               0x58CC10
#define __ConvertItemTags_x                                        0x5A77F0
#define __CrashHandler_x                                           0x83B950
#define __EQGetTime_x                                              0x8D8370
#define __ExecuteCmd_x                                             0x585530
#define __FixHeading_x                                             0x968B40
#define __get_bearing_x                                            0x58C700
#define __get_melee_range_x                                        0x58CE00
#define __GetAnimationCache_x                                      0x6F9FD0
#define __GetGaugeValueFromEQ_x                                    0x7ED0B0
#define __GetLabelFromEQ_x                                         0x7EE820
#define __GetXTargetType_x                                         0x96A610
#define __HeadingDiff_x                                            0x968BB0
#define __HelpPath_x                                               0xF06C9C
#define __LoadFrontEnd_x                                           0x6924F0
#define __NewUIINI_x                                               0x7ECD80
#define __pCrashHandler_x                                          0x103CA98
#define __ProcessGameEvents_x                                      0x5E9D50
#define __ProcessMouseEvent_x                                      0x5E9510
#define __SaveColors_x                                             0x5378E0
#define __STMLToText_x                                             0x90C200
#define __ToggleKeyRingItem_x                                      0x4FAA90
#define CrashDetected_x                                            0x693FE0
#define DrawNetStatus_x                                            0x6159B0
#define Expansion_HoT_x                                            0xE68C34
#define Teleport_Table_Size_x                                      0xE57C88
#define Teleport_Table_x                                           0xE580E0
#define Util__FastTime_x                                           0x8D7F30
#define wwsCrashReportCheckForUploader_x                           0x83C360
#define wwsCrashReportPlatformLaunchUploader_x                     0x83EA40
#define __SaveColors_x                                             0x5378E0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A980
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493760
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493540

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53F000
#define AltAdvManager__IsAbilityReady_x                            0x53E0C0
#define AltAdvManager__GetAAById_x                                 0x53E2C0
#define AltAdvManager__CanTrainAbility_x                           0x53E330
#define AltAdvManager__CanSeeAbility_x                             0x53E560

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C5B00
#define CharacterZoneClient__HasSkill_x                            0x4D05D0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D1CF0
#define CharacterZoneClient__IsStackBlocked_x                      0x4B9F50
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B6620
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4430
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4510
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D45F0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BEA40
#define CharacterZoneClient__BardCastBard_x                        0x4C16C0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B66F0
#define CharacterZoneClient__GetEffect_x                           0x4B6560
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4BFA50
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4BFB20
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4BFB70
#define CharacterZoneClient__CalcAffectChange_x                    0x4BFCC0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4BFE90

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BC870

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CA170

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F8230
#define CButtonWnd__CButtonWnd_x                                   0x908610

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6E8960
#define CChatManager__InitContextMenu_x                            0x6E2DB0
#define CChatManager__FreeChatWindow_x                             0x6E78F0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EC210
#define CChatManager__SetLockedActiveChatWindow_x                  0x6E8700

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x91CE30
#define CContextMenu__dCContextMenu_x                              0x91D060
#define CContextMenu__AddMenuItem_x                                0x91D070
#define CContextMenu__RemoveMenuItem_x                             0x91D370
#define CContextMenu__RemoveAllMenuItems_x                         0x91D390
#define CContextMenu__CheckMenuItem_x                              0x91D410
#define CContextMenu__SetMenuItem_x                                0x91D2A0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x91D9B0
#define CContextMenuManager__RemoveMenu_x                          0x91DA20
#define CContextMenuManager__PopupMenu_x                           0x91DAE0
#define CContextMenuManager__Flush_x                               0x91D950
#define CContextMenuManager__GetMenu_x                             0x495820

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BA570
#define CChatService__GetFriendName_x                              0x8BA580

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6E8ED0
#define CChatWindow__Clear_x                                       0x6E9F30
#define CChatWindow__WndNotification_x                             0x6EA4A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91A2B0
#define CComboWnd__Draw_x                                          0x9197B0
#define CComboWnd__GetCurChoice_x                                  0x91A0F0
#define CComboWnd__GetListRect_x                                   0x919C60
#define CComboWnd__GetTextRect_x                                   0x91A310
#define CComboWnd__InsertChoice_x                                  0x919DF0
#define CComboWnd__SetColors_x                                     0x919DC0
#define CComboWnd__SetChoice_x                                     0x91A0C0
#define CComboWnd__GetItemCount_x                                  0x91A100
#define CComboWnd__GetCurChoiceText_x                              0x91A140

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F2100
#define CContainerWnd__vftable_x                                   0xAC56F8
#define CContainerWnd__SetContainer_x                              0x6F3670

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5376A0
#define CDisplay__GetClickedActor_x                                0x52A6F0
#define CDisplay__GetUserDefinedColor_x                            0x522DF0
#define CDisplay__GetWorldFilePath_x                               0x52C140
#define CDisplay__is3dON_x                                         0x5273E0
#define CDisplay__ReloadUI_x                                       0x531860
#define CDisplay__WriteTextHD2_x                                   0x5271C0
#define CDisplay__TrueDistance_x                                   0x52DDA0
#define CDisplay__SetViewActor_x                                   0x52A040

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93C490

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x921510
#define CEditWnd__GetCharIndexPt_x                                 0x922400
#define CEditWnd__GetDisplayString_x                               0x9222A0
#define CEditWnd__GetHorzOffset_x                                  0x920B40
#define CEditWnd__GetLineForPrintableChar_x                        0x923540
#define CEditWnd__GetSelStartPt_x                                  0x9226B0
#define CEditWnd__GetSTMLSafeText_x                                0x9220C0
#define CEditWnd__PointFromPrintableChar_x                         0x923170
#define CEditWnd__SelectableCharFromPoint_x                        0x9232E0
#define CEditWnd__SetEditable_x                                    0x922780

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5D88D0
#define CEverQuest__ClickedPlayer_x                                0x5CAB80
#define CEverQuest__CreateTargetIndicator_x                        0x5E7030
#define CEverQuest__DeleteTargetIndicator_x                        0x5E70C0
#define CEverQuest__DoTellWindow_x                                 0x4E0770
#define CEverQuest__OutputTextToLog_x                              0x4E09A0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C0440
#define CEverQuest__dsp_chat_x                                     0x4E0D30
#define CEverQuest__trimName_x                                     0x5E35F0
#define CEverQuest__Emote_x                                        0x5D90E0
#define CEverQuest__EnterZone_x                                    0x5D3240
#define CEverQuest__GetBodyTypeDesc_x                              0x5DCE80
#define CEverQuest__GetClassDesc_x                                 0x5DD4C0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DDAC0
#define CEverQuest__GetDeityDesc_x                                 0x5E5980
#define CEverQuest__GetLangDesc_x                                  0x5DDC80
#define CEverQuest__GetRaceDesc_x                                  0x5DD4A0
#define CEverQuest__InterpretCmd_x                                 0x5E5F50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C4630
#define CEverQuest__LMouseUp_x                                     0x5C29B0
#define CEverQuest__RightClickedOnPlayer_x                         0x5C4F10
#define CEverQuest__RMouseUp_x                                     0x5C3940
#define CEverQuest__SetGameState_x                                 0x5C01D0
#define CEverQuest__UPCNotificationFlush_x                         0x5E34F0
#define CEverQuest__IssuePetCommand_x                              0x5DF080
#define CEverQuest__ReportSuccessfulHit_x                          0x5D9D80

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7040F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x704150
#define CGaugeWnd__Draw_x                                          0x7037E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABB70
#define CGuild__GetGuildName_x                                     0x4AABB0
#define CGuild__GetGuildIndex_x                                    0x4AAF40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x71F440

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72C360
#define CInvSlotMgr__MoveItem_x                                    0x72B080
#define CInvSlotMgr__SelectSlot_x                                  0x72C430

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x729930
#define CInvSlot__SliderComplete_x                                 0x727750
#define CInvSlot__GetItemBase_x                                    0x7270C0
#define CInvSlot__UpdateItem_x                                     0x727230

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x72DD80
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72D050
#define CInvSlotWnd__HandleLButtonUp_x                             0x72D900

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7E92C0
#define CItemDisplayWnd__UpdateStrings_x                           0x73B9D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x735B40
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x736010
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73BF60
#define CItemDisplayWnd__AboutToShow_x                             0x73B610
#define CItemDisplayWnd__WndNotification_x                         0x73D250

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x820A90

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x741290

// CLabel 
#define CLabel__Draw_x                                             0x746CF0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F2970
#define CListWnd__dCListWnd_x                                      0x8F2C90
#define CListWnd__AddColumn_x                                      0x8F6FA0
#define CListWnd__AddColumn1_x                                     0x8F6FF0
#define CListWnd__AddLine_x                                        0x8F7380
#define CListWnd__AddString_x                                      0x8F7180
#define CListWnd__CalculateFirstVisibleLine_x                      0x8F6D60
#define CListWnd__CalculateVSBRange_x                              0x8F6B40
#define CListWnd__ClearSel_x                                       0x8F7B60
#define CListWnd__ClearAllSel_x                                    0x8F7BC0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8F85B0
#define CListWnd__Compare_x                                        0x8F6480
#define CListWnd__Draw_x                                           0x8F2D90
#define CListWnd__DrawColumnSeparators_x                           0x8F5560
#define CListWnd__DrawHeader_x                                     0x8F59D0
#define CListWnd__DrawItem_x                                       0x8F5DC0
#define CListWnd__DrawLine_x                                       0x8F56D0
#define CListWnd__DrawSeparator_x                                  0x8F5600
#define CListWnd__EnableLine_x                                     0x8F4E40
#define CListWnd__EnsureVisible_x                                  0x8F84E0
#define CListWnd__ExtendSel_x                                      0x8F7A90
#define CListWnd__GetColumnMinWidth_x                              0x8F4980
#define CListWnd__GetColumnWidth_x                                 0x8F48F0
#define CListWnd__GetCurSel_x                                      0x8F4280
#define CListWnd__GetItemAtPoint_x                                 0x8F50B0
#define CListWnd__GetItemAtPoint1_x                                0x8F5120
#define CListWnd__GetItemData_x                                    0x8F4300
#define CListWnd__GetItemHeight_x                                  0x8F46C0
#define CListWnd__GetItemIcon_x                                    0x8F4490
#define CListWnd__GetItemRect_x                                    0x8F4F30
#define CListWnd__GetItemText_x                                    0x8F4340
#define CListWnd__GetSelList_x                                     0x8F7C10
#define CListWnd__GetSeparatorRect_x                               0x8F5360
#define CListWnd__InsertLine_x                                     0x8F7770
#define CListWnd__RemoveLine_x                                     0x8F78C0
#define CListWnd__SetColors_x                                      0x8F6B10
#define CListWnd__SetColumnJustification_x                         0x8F6840
#define CListWnd__SetColumnWidth_x                                 0x8F6760
#define CListWnd__SetCurSel_x                                      0x8F79D0
#define CListWnd__SetItemColor_x                                   0x8F81A0
#define CListWnd__SetItemData_x                                    0x8F8160
#define CListWnd__SetItemText_x                                    0x8F7D90
#define CListWnd__ShiftColumnSeparator_x                           0x8F6900
#define CListWnd__Sort_x                                           0x8F6600
#define CListWnd__ToggleSel_x                                      0x8F7A00

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75C280

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x77F230
#define CMerchantWnd__RequestBuyItem_x                             0x77FB10
#define CMerchantWnd__RequestSellItem_x                            0x780040
#define CMerchantWnd__SelectRecoverySlot_x                         0x782E80
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x77F890
#define CMerchantWnd__ActualSelect_x                               0x7889E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x887F80
#define CPacketScrambler__hton_x                                   0x887F70

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x911800
#define CSidlManager__FindScreenPieceTemplate_x                    0x911C10
#define CSidlManager__FindScreenPieceTemplate1_x                   0x911A00
#define CSidlManager__CreateLabel_x                                0x7E0710
#define CSidlManager__CreateXWndFromTemplate_x                     0x914CE0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x914EC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x90E370
#define CSidlScreenWnd__CalculateVSBRange_x                        0x90E260
#define CSidlScreenWnd__ConvertToRes_x                             0x932D30
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x90DCF0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x90D9E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x90DAB0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x90DB80
#define CSidlScreenWnd__DrawSidlPiece_x                            0x90E810
#define CSidlScreenWnd__EnableIniStorage_x                         0x90ECE0
#define CSidlScreenWnd__GetSidlPiece_x                             0x90EA00
#define CSidlScreenWnd__Init1_x                                    0x90D5D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x90ED30
#define CSidlScreenWnd__LoadIniListWnd_x                           0x90F870
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90C9E0
#define CSidlScreenWnd__StoreIniInfo_x                             0x90F3F0
#define CSidlScreenWnd__StoreIniVis_x                              0x90F750
#define CSidlScreenWnd__WndNotification_x                          0x90E720
#define CSidlScreenWnd__GetChildItem_x                             0x90EC60
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8FE430
#define CSidlScreenWnd__m_layoutCopy_x                             0x16965C8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65BFA0
#define CSkillMgr__GetSkillCap_x                                   0x65C180
#define CSkillMgr__GetNameToken_x                                  0x65B730

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x91E7A0
#define CSliderWnd__SetValue_x                                     0x91E610
#define CSliderWnd__SetNumTicks_x                                  0x91E670

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E6530

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9253F0
#define CStmlWnd__CalculateHSBRange_x                              0x926480
#define CStmlWnd__CalculateVSBRange_x                              0x9263F0
#define CStmlWnd__CanBreakAtCharacter_x                            0x92A7C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92B3B0
#define CStmlWnd__ForceParseNow_x                                  0x925990
#define CStmlWnd__GetNextTagPiece_x                                0x92A720
#define CStmlWnd__GetSTMLText_x                                    0x4EEA60
#define CStmlWnd__GetVisibleText_x                                 0x9259B0
#define CStmlWnd__InitializeWindowVariables_x                      0x92B200
#define CStmlWnd__MakeStmlColorTag_x                               0x924B80
#define CStmlWnd__MakeWndNotificationTag_x                         0x924BF0
#define CStmlWnd__SetSTMLText_x                                    0x923C50
#define CStmlWnd__StripFirstSTMLLines_x                            0x92C510
#define CStmlWnd__UpdateHistoryString_x                            0x92B5C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x92FC20
#define CTabWnd__DrawCurrentPage_x                                 0x930240
#define CTabWnd__DrawTab_x                                         0x930010
#define CTabWnd__GetCurrentPage_x                                  0x92F480
#define CTabWnd__GetPageInnerRect_x                                0x92F6C0
#define CTabWnd__GetTabInnerRect_x                                 0x92F600
#define CTabWnd__GetTabRect_x                                      0x92F4B0
#define CTabWnd__InsertPage_x                                      0x92F8B0
#define CTabWnd__SetPage_x                                         0x92F740
#define CTabWnd__SetPageRect_x                                     0x92FB60
#define CTabWnd__UpdatePage_x                                      0x92FED0
#define CTabWnd__GetPageFromTabIndex_x                             0x92FF50
#define CTabWnd__GetCurrentTabIndex_x                              0x92F470

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7416F0
#define CPageWnd__SetTabText_x                                     0x93C8A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A56B0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FB270
#define CTextureFont__GetTextExtent_x                              0x8FB430

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x68F290
#define CHtmlComponentWnd__ValidateUri_x                           0x720E30
#define CHtmlWnd__SetClientCallbacks_x                             0x5FD590
#define CHtmlWnd__AddObserver_x                                    0x5FD5B0
#define CHtmlWnd__RemoveObserver_x                                 0x5FD610
#define Window__getProgress_x                                      0x8395C0
#define Window__getStatus_x                                        0x8395E0
#define Window__getURI_x                                           0x8395F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x938E20

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8E82E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ACE90
#define CXStr__CXStr1_x                                            0x47B0F0
#define CXStr__CXStr3_x                                            0x8D44A0
#define CXStr__dCXStr_x                                            0x472260
#define CXStr__operator_equal_x                                    0x8D46D0
#define CXStr__operator_equal1_x                                   0x8D4710
#define CXStr__operator_plus_equal1_x                              0x8D51A0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91CA30
#define CXWnd__BringToTop_x                                        0x901BB0
#define CXWnd__Center_x                                            0x901730
#define CXWnd__ClrFocus_x                                          0x901570
#define CXWnd__Destroy_x                                           0x901610
#define CXWnd__DoAllDrawing_x                                      0x8FDBC0
#define CXWnd__DrawChildren_x                                      0x8FDB90
#define CXWnd__DrawColoredRect_x                                   0x8FE020
#define CXWnd__DrawTooltip_x                                       0x8FC6E0
#define CXWnd__DrawTooltipAtPoint_x                                0x8FC7A0
#define CXWnd__GetBorderFrame_x                                    0x8FDE80
#define CXWnd__GetChildWndAt_x                                     0x901C50
#define CXWnd__GetClientClipRect_x                                 0x8FFE90
#define CXWnd__GetScreenClipRect_x                                 0x8FFF60
#define CXWnd__GetScreenRect_x                                     0x9000F0
#define CXWnd__GetTooltipRect_x                                    0x8FE070
#define CXWnd__GetWindowTextA_x                                    0x496EB0
#define CXWnd__IsActive_x                                          0x904AC0
#define CXWnd__IsDescendantOf_x                                    0x900B10
#define CXWnd__IsReallyVisible_x                                   0x900B40
#define CXWnd__IsType_x                                            0x9022D0
#define CXWnd__Move_x                                              0x900BB0
#define CXWnd__Move1_x                                             0x900C70
#define CXWnd__ProcessTransition_x                                 0x9016E0
#define CXWnd__Refade_x                                            0x900F30
#define CXWnd__Resize_x                                            0x9011C0
#define CXWnd__Right_x                                             0x901970
#define CXWnd__SetFocus_x                                          0x901530
#define CXWnd__SetFont_x                                           0x9015A0
#define CXWnd__SetKeyTooltip_x                                     0x9020E0
#define CXWnd__SetMouseOver_x                                      0x8FEFE0
#define CXWnd__StartFade_x                                         0x9009E0
#define CXWnd__GetChildItem_x                                      0x901DC0
#define CXWnd__SetParent_x                                         0x9008A0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x933E00

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x904B00
#define CXWndManager__DrawWindows_x                                0x904B20
#define CXWndManager__GetKeyboardFlags_x                           0x907290
#define CXWndManager__HandleKeyboardMsg_x                          0x906E90
#define CXWndManager__RemoveWnd_x                                  0x9074E0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x907A30

// CDBStr
#define CDBStr__GetString_x                                        0x521D90

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B75D0
#define EQ_Character__Cur_HP_x                                     0x4CD6B0
#define EQ_Character__Cur_Mana_x                                   0x4D4AF0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BA540
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AE900
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEA50
#define EQ_Character__GetHPRegen_x                                 0x4DA0C0
#define EQ_Character__GetEnduranceRegen_x                          0x4DA6D0
#define EQ_Character__GetManaRegen_x                               0x4DAB10
#define EQ_Character__Max_Endurance_x                              0x623160
#define EQ_Character__Max_HP_x                                     0x4CD4E0
#define EQ_Character__Max_Mana_x                                   0x622FE0
#define EQ_Character__doCombatAbility_x                            0x6252B0
#define EQ_Character__UseSkill_x                                   0x4DC920
#define EQ_Character__GetConLevel_x                                0x61C710
#define EQ_Character__IsExpansionFlag_x                            0x583EF0
#define EQ_Character__TotalEffect_x                                0x4C0C40
#define EQ_Character__GetPCSpellAffect_x                           0x4BB130
#define EQ_Character__SpellDuration_x                              0x4BAC60
#define EQ_Character__FindItemByRecord_x                           0x4D2C60
#define EQ_Character__GetAdjustedSkill_x                           0x4D0390
#define EQ_Character__GetBaseSkill_x                               0x4D1330
#define EQ_Character__CanUseItem_x                                 0x4D4E00

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8A7060

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6390C0

//PcClient
#define PcClient__PcClient_x                                       0x619FD0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B53B0
#define CCharacterListWnd__EnterWorld_x                            0x4B4DF0
#define CCharacterListWnd__Quit_x                                  0x4B4B00
#define CCharacterListWnd__UpdateList_x                            0x4B4F80

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5FE7B0
#define EQ_Item__CreateItemTagString_x                             0x8822E0
#define EQ_Item__IsStackable_x                                     0x8864A0
#define EQ_Item__GetImageNum_x                                     0x883AC0
#define EQ_Item__CreateItemClient_x                                0x5FD990
#define EQ_Item__GetItemValue_x                                    0x884BB0
#define EQ_Item__ValueSellMerchant_x                               0x887B20
#define EQ_Item__IsKeyRingItem_x                                   0x885E70
#define EQ_Item__CanGoInBag_x                                      0x5FE8D0
#define EQ_Item__GetMaxItemCount_x                                 0x884CB0
#define EQ_Item__GetHeldItem_x                                     0x883990
#define EQ_Item__GetAugmentFitBySlot_x                             0x881E40

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x53FD30
#define EQ_LoadingS__Array_x                                       0xBD6298

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x623A60
#define EQ_PC__GetAlternateAbilityId_x                             0x890AD0
#define EQ_PC__GetCombatAbility_x                                  0x891140
#define EQ_PC__GetCombatAbilityTimer_x                             0x8911B0
#define EQ_PC__GetItemRecastTimer_x                                0x625830
#define EQ_PC__HasLoreItem_x                                       0x61CE80
#define EQ_PC__AlertInventoryChanged_x                             0x61C1E0
#define EQ_PC__GetPcZoneClient_x                                   0x6477B0
#define EQ_PC__RemoveMyAffect_x                                    0x628960
#define EQ_PC__GetKeyRingItems_x                                   0x891A50
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8917D0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x891D40

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58A140
#define EQItemList__add_object_x                                   0x5B5B90
#define EQItemList__add_item_x                                     0x58A750
#define EQItemList__delete_item_x                                  0x58A7A0
#define EQItemList__FreeItemList_x                                 0x58A6A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51F2C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63A940
#define EQPlayer__dEQPlayer_x                                      0x62E030
#define EQPlayer__DoAttack_x                                       0x6424C0
#define EQPlayer__EQPlayer_x                                       0x62E6E0
#define EQPlayer__SetNameSpriteState_x                             0x6329B0
#define EQPlayer__SetNameSpriteTint_x                              0x633840
#define PlayerBase__HasProperty_j_x                                0x966F20
#define EQPlayer__IsTargetable_x                                   0x9673C0
#define EQPlayer__CanSee_x                                         0x967220
#define EQPlayer__CanSee1_x                                        0x9672F0
#define PlayerBase__GetVisibilityLineSegment_x                     0x966FE0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x645280
#define PlayerZoneClient__GetLevel_x                               0x6477F0
#define PlayerZoneClient__IsValidTeleport_x                        0x5B6CE0
#define PlayerZoneClient__LegalPlayerRace_x                        0x539480

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63D5F0
#define EQPlayerManager__GetSpawnByName_x                          0x63D610
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63D6A0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x602040
#define KeypressHandler__AttachKeyToEqCommand_x                    0x602080
#define KeypressHandler__ClearCommandStateArray_x                  0x603470
#define KeypressHandler__HandleKeyDown_x                           0x603490
#define KeypressHandler__HandleKeyUp_x                             0x603530
#define KeypressHandler__SaveKeymapping_x                          0x603910

// MapViewMap 
#define MapViewMap__Clear_x                                        0x758110
#define MapViewMap__SaveEx_x                                       0x75B4B0
#define MapViewMap__SetZoom_x                                      0x75FB80

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A4F50

// StringTable 
#define StringTable__getString_x                                   0x89FD90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6285D0
#define PcZoneClient__RemovePetEffect_x                            0x628C00
#define PcZoneClient__HasAlternateAbility_x                        0x622E20
#define PcZoneClient__GetCurrentMod_x                              0x4DF870
#define PcZoneClient__GetModCap_x                                  0x4DF770
#define PcZoneClient__CanEquipItem_x                               0x6233F0
#define PcZoneClient__GetItemByID_x                                0x625CA0
#define PcZoneClient__GetItemByItemClass_x                         0x625D30
#define PcZoneClient__RemoveBuffEffect_x                           0x628C20

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BB8C0

//IconCache
#define IconCache__GetIcon_x                                       0x6F9860

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F12A0
#define CContainerMgr__CloseContainer_x                            0x6F1570

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B2FB0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F6A10

//CLootWnd
#define CLootWnd__LootAll_x                                        0x74E660
#define CLootWnd__RequestLootSlot_x                                0x74DA10

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5584B0
#define EQ_Spell__SpellAffects_x                                   0x558920
#define EQ_Spell__SpellAffectBase_x                                0x5586E0
#define EQ_Spell__IsStackable_x                                    0x4C5430
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5280
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B29B0
#define EQ_Spell__IsSPAStacking_x                                  0x559560
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x558C70
#define EQ_Spell__IsNoRemove_x                                     0x4C5410
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x559570
#define __IsResEffectSpell_x                                       0x4C47B0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A97F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8AF850

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7F85D0
#define CTargetWnd__WndNotification_x                              0x7F7E60
#define CTargetWnd__RefreshTargetBuffs_x                           0x7F8130
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7F6FB0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FCCB0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5539F0
#define EqSoundManager__PlayScriptMp3_x                            0x553B50
#define EqSoundManager__SoundAssistPlay_x                          0x65FB40
#define EqSoundManager__WaveInstancePlay_x                         0x65EFF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x510C60

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x920180

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x547950
#define CAltAbilityData__GetMercMaxRank_x                          0x5478F0
#define CAltAbilityData__GetMaxRank_x                              0x53D1B0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F4B20

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5260
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F6F60
#define CharacterBase__CreateItemIndex_x                           0x5FCBA0
#define CharacterBase__GetItemPossession_x                         0x4B2860
#define CharacterBase__GetItemByGlobalIndex_x                      0x8B8060
#define CharacterBase__GetEffectId_x                               0x4C5210

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6D98C0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DA0E0

//messages
#define msg_spell_worn_off_x                                       0x57C690
#define msg_new_text_x                                             0x571860
#define __msgTokenTextParam_x                                      0x57ECE0
#define msgTokenText_x                                             0x57EF30

//SpellManager
#define SpellManager__vftable_x                                    0xAA0810
#define SpellManager__SpellManager_x                               0x662E40
#define Spellmanager__LoadTextSpells_x                             0x6631C0
#define SpellManager__GetSpellByGroupAndRank_x                     0x663010

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96AF00

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F7640
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x582480
#define ItemGlobalIndex__IsEquippedLocation_x                      0x615810
#define ItemGlobalIndex__IsValidIndex_x                            0x4F76A0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B0230
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B04B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x747050

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F5A00
#define CCursorAttachment__Deactivate_x                            0x6F69E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x932160
#define CEQSuiteTextureLoader__GetTexture_x                        0x931E20

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F45B0

//IString
#define IString__Append_x                                          0x4E8B70

//Camera
#define CDisplay__cameraType_x                                     0xDA5C70
#define EverQuest__Cameras_x                                       0xE68F4C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FCD00
#define LootFiltersManager__GetItemFilterData_x                    0x4FC600
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FC630
#define LootFiltersManager__SetItemLootFilter_x                    0x4FC850

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A0EC0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x970CD0
#define CResolutionHandler__GetWindowedStyle_x                     0x65A9F0

//CContainerMgr
#define CContainerMgr__OpenExperimentContainer_x                   0x6F1FF0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6EE060

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
