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
#define __ExpectedVersionDate                                     "Feb 12 2019"
#define __ExpectedVersionTime                                     "08:55:32"
#define __ActualVersionDate_x                                      0xAD11AC
#define __ActualVersionTime_x                                      0xAD11A0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x617100
#define __MemChecker1_x                                            0x8EBDF0
#define __MemChecker2_x                                            0x6A6690
#define __MemChecker3_x                                            0x6A65E0
#define __MemChecker4_x                                            0x843630
#define __EncryptPad0_x                                            0xC05348
#define __EncryptPad1_x                                            0xC635D0
#define __EncryptPad2_x                                            0xC15EC8
#define __EncryptPad3_x                                            0xC15AC8
#define __EncryptPad4_x                                            0xC53E40
#define __EncryptPad5_x                                            0x1034790
#define __AC1_x                                                    0x7FFB96
#define __AC2_x                                                    0x5D1CFF
#define __AC3_x                                                    0x5D8B8F
#define __AC4_x                                                    0x5DC9C0
#define __AC5_x                                                    0x5E2C30
#define __AC6_x                                                    0x5E71F6
#define __AC7_x                                                    0x5D1770
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E8AE2C

// Direct Input
#define DI8__Main_x                                                0x10347B4
#define DI8__Keyboard_x                                            0x10347B8
#define DI8__Mouse_x                                               0xF2A4C0
#define DI8__Mouse_Copy_x                                          0xE881B4
#define DI8__Mouse_Check_x                                         0x1035674
#define __AutoSkillArray_x                                         0xE890CC
#define __Attack_x                                                 0xF26EDB
#define __Autofire_x                                               0xF26EDC
#define __BindList_x                                               0xBF3F28
#define g_eqCommandStates_x                                        0xBF4C98
#define __Clicks_x                                                 0xE8826C
#define __CommandList_x                                            0xBF5850
#define __CurrentMapLabel_x                                        0x103CA74
#define __CurrentSocial_x                                          0xBDE730
#define __DoAbilityList_x                                          0xEBE9FC
#define __do_loot_x                                                0x59F060
#define __DrawHandler_x                                            0x16B9448
#define __GroupCount_x                                             0xE7847A
#define __Guilds_x                                                 0xE7E9C0
#define __gWorld_x                                                 0xE7AD40
#define __HWnd_x                                                   0xF2A4C4
#define __heqmain_x                                                0x1034778
#define __InChatMode_x                                             0xE8819C
#define __LastTell_x                                               0xE8A0F8
#define __LMouseHeldTime_x                                         0xE882D8
#define __Mouse_x                                                  0x103479C
#define __MouseLook_x                                              0xE88232
#define __MouseEventTime_x                                         0xF27990
#define __gpbCommandEvent_x                                        0xE7A7E4
#define __NetStatusToggle_x                                        0xE88235
#define __PCNames_x                                                0xE896B0
#define __RangeAttackReady_x                                       0xE893B0
#define __RMouseHeldTime_x                                         0xE882D4
#define __RunWalkState_x                                           0xE881A0
#define __ScreenMode_x                                             0xDC6A80
#define __ScreenX_x                                                0xE88154
#define __ScreenY_x                                                0xE88150
#define __ScreenXMax_x                                             0xE88158
#define __ScreenYMax_x                                             0xE8815C
#define __ServerHost_x                                             0xE7AA2B
#define __ServerName_x                                             0xEBE9BC
#define __ShiftKeyDown_x                                           0xE8882C
#define __ShowNames_x                                              0xE8956C
#define __Socials_x                                                0xEBEABC
#define __SubscriptionType_x                                       0x107E5C4
#define __TargetAggroHolder_x                                      0x103F430
#define __ZoneType_x                                               0xE88630
#define __GroupAggro_x                                             0x103F470
#define __LoginName_x                                              0x1035004
#define __Inviter_x                                                0xF26E58
#define __AttackOnAssist_x                                         0xE89528
#define __UseTellWindows_x                                         0xE8984C
#define __gfMaxZoomCameraDistance_x                                0xAC6620
#define __gfMaxCameraDistance_x                                    0xAF3A40
#define __pulAutoRun_x                                             0xE88250
#define __pulForward_x                                             0xE89884
#define __pulBackward_x                                            0xE89888
#define __pulTurnRight_x                                           0xE8988C
#define __pulTurnLeft_x                                            0xE89890
#define __pulStrafeLeft_x                                          0xE89894
#define __pulStrafeRight_x                                         0xE89898

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE7AD58
#define instEQZoneInfo_x                                           0xE88428
#define instKeypressHandler_x                                      0xF27940
#define pinstActiveBanker_x                                        0xE7A88C
#define pinstActiveCorpse_x                                        0xE7A884
#define pinstActiveGMaster_x                                       0xE7A888
#define pinstActiveMerchant_x                                      0xE7A880
#define pinstAggroInfo_x                                           0xC79E08
#define pinstAltAdvManager_x                                       0xDC76F8
#define pinstAuraMgr_x                                             0xC95988
#define pinstBandageTarget_x                                       0xE7A89C
#define pinstCamActor_x                                            0xDC6A74
#define pinstCDBStr_x                                              0xDC6424
#define pinstCDisplay_x                                            0xE7A924
#define pinstCEverQuest_x                                          0x10348CC
#define pinstEverQuestInfo_x                                       0xE88148
#define pinstCharData_x                                            0xE7AD48
#define pinstCharSpawn_x                                           0xE7A8D4
#define pinstControlledMissile_x                                   0xE7AD3C
#define pinstControlledPlayer_x                                    0xE7A8D4
#define pinstCResolutionHandler_x                                  0x16B9678
#define pinstCSidlManager_x                                        0x16B850C
#define pinstCXWndManager_x                                        0x16B8500
#define instDynamicZone_x                                          0xE7E898
#define pinstDZMember_x                                            0xE7E9A8
#define pinstDZTimerInfo_x                                         0xE7E9AC
#define pinstEQItemList_x                                          0xE76F48
#define pinstEQObjectList_x                                        0xE78138
#define instEQMisc_x                                               0xDC6368
#define pinstEQSoundManager_x                                      0xDC7F58
#define pinstEQSpellStrings_x                                      0xC87F40
#define instExpeditionLeader_x                                     0xE7E8E2
#define instExpeditionName_x                                       0xE7E922
#define pinstGroup_x                                               0xE78476
#define pinstImeManager_x                                          0x16B8504
#define pinstLocalPlayer_x                                         0xE7A7FC
#define pinstMercenaryData_x                                       0xF2813C
#define pinstMercenaryStats_x                                      0x103F57C
#define pinstMercAltAbilities_x                                    0xDC7CC8
#define pinstModelPlayer_x                                         0xE7A894
#define pinstPCData_x                                              0xE7AD48
#define pinstRealEstateItems_x                                     0xF29630
#define pinstSkillMgr_x                                            0xF29700
#define pinstSpawnManager_x                                        0xF28CF0
#define pinstSpellManager_x                                        0xF298D8
#define pinstSpellSets_x                                           0xF1FB04
#define pinstStringTable_x                                         0xE7A6C4
#define pinstSwitchManager_x                                       0xE782F8
#define pinstTarget_x                                              0xE7A8D0
#define pinstTargetObject_x                                        0xE7A8DC
#define pinstTargetSwitch_x                                        0xE7AD4C
#define pinstTaskMember_x                                          0xDC61FC
#define pinstTrackTarget_x                                         0xE7A8D8
#define pinstTradeTarget_x                                         0xE7A890
#define instTributeActive_x                                        0xDC6389
#define pinstViewActor_x                                           0xDC6A70
#define pinstWorldData_x                                           0xE7A7F0
#define pinstZoneAddr_x                                            0xE886C8
#define pinstPlayerPath_x                                          0xF28D88
#define pinstTargetIndicator_x                                     0xF29B40
#define pinstCTargetManager_x                                      0xF29BD8
#define EQObject_Top_x                                             0xE7A7F8
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC6530
#define pinstCAchievementsWnd_x                                    0xDC6528
#define pinstCActionsWnd_x                                         0xDC6588
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC6A40
#define pinstCAdvancedLootWnd_x                                    0xDC6580
#define pinstCAdventureLeaderboardWnd_x                            0x1036248
#define pinstCAdventureRequestWnd_x                                0x10362F8
#define pinstCAdventureStatsWnd_x                                  0x10363A8
#define pinstCAggroMeterWnd_x                                      0xDC6AC0
#define pinstCAlarmWnd_x                                           0xDC6D30
#define pinstCAlertHistoryWnd_x                                    0xDC64E4
#define pinstCAlertStackWnd_x                                      0xDC6AD4
#define pinstCAlertWnd_x                                           0xDC6AF4
#define pinstCAltStorageWnd_x                                      0x1036708
#define pinstCAudioTriggersWindow_x                                0xC7A298
#define pinstCAuraWnd_x                                            0xDC6AB8
#define pinstCAvaZoneWnd_x                                         0xDC64E8
#define pinstCBandolierWnd_x                                       0xDC6AFC
#define pinstCBankWnd_x                                            0xDC64D8
#define pinstCBarterMerchantWnd_x                                  0x1037948
#define pinstCBarterSearchWnd_x                                    0x10379F8
#define pinstCBarterWnd_x                                          0x1037AA8
#define pinstCBazaarConfirmationWnd_x                              0xDC6AD0
#define pinstCBazaarSearchWnd_x                                    0xDC6624
#define pinstCBazaarWnd_x                                          0xDC6B10
#define pinstCBlockedBuffWnd_x                                     0xDC64C0
#define pinstCBlockedPetBuffWnd_x                                  0xDC64EC
#define pinstCBodyTintWnd_x                                        0xDC6AA4
#define pinstCBookWnd_x                                            0xDC6B18
#define pinstCBreathWnd_x                                          0xDC653C
#define pinstCBuffWindowNORMAL_x                                   0xDC6D34
#define pinstCBuffWindowSHORT_x                                    0xDC6D3C
#define pinstCBugReportWnd_x                                       0xDC6538
#define pinstCButtonWnd_x                                          0x16B8730
#define pinstCCastingWnd_x                                         0xDC652C
#define pinstCCastSpellWnd_x                                       0xDC6A38
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDC6540
#define pinstCChatWindowManager_x                                  0x1038568
#define pinstCClaimWnd_x                                           0x10386C0
#define pinstCColorPickerWnd_x                                     0xDC656C
#define pinstCCombatAbilityWnd_x                                   0xDC6ABC
#define pinstCCombatSkillsSelectWnd_x                              0xDC6590
#define pinstCCompassWnd_x                                         0xDC6A8C
#define pinstCConfirmationDialog_x                                 0x103D5C0
#define pinstCContainerMgr_x                                       0xDC6ADC
#define pinstCContextMenuManager_x                                 0x16B84C0
#define pinstCCursorAttachment_x                                   0xDC651C
#define pinstCDistillerInfo_x                                      0x103BFCC
#define pinstCDynamicZoneWnd_x                                     0x1038C88
#define pinstCEditLabelWnd_x                                       0xDC6B28
#define pinstCEQMainWnd_x                                          0x1038ED0
#define pinstCEventCalendarWnd_x                                   0xDC6558
#define pinstCExtendedTargetWnd_x                                  0xDC6AAC
#define pinstCFacePick_x                                           0xDC6564
#define pinstCFactionWnd_x                                         0xDC6524
#define pinstCFellowshipWnd_x                                      0x10390D0
#define pinstCFileSelectionWnd_x                                   0xDC6574
#define pinstCFindItemWnd_x                                        0xDC6B20
#define pinstCFindLocationWnd_x                                    0x1039228
#define pinstCFriendsWnd_x                                         0xDC65A8
#define pinstCGemsGameWnd_x                                        0xDC6B00
#define pinstCGiveWnd_x                                            0xDC6B2C
#define pinstCGroupSearchFiltersWnd_x                              0xDC6AD8
#define pinstCGroupSearchWnd_x                                     0x1039620
#define pinstCGroupWnd_x                                           0x10396D0
#define pinstCGuildBankWnd_x                                       0xE8950C
#define pinstCGuildCreationWnd_x                                   0x1039830
#define pinstCGuildMgmtWnd_x                                       0x10398E0
#define pinstCharacterCreation_x                                   0xDC6AC4
#define pinstCHelpWnd_x                                            0xDC6A64
#define pinstCHeritageSelectionWnd_x                               0xDC6578
#define pinstCHotButtonWnd_x                                       0x103BA38
#define pinstCHotButtonWnd1_x                                      0x103BA38
#define pinstCHotButtonWnd2_x                                      0x103BA3C
#define pinstCHotButtonWnd3_x                                      0x103BA40
#define pinstCHotButtonWnd4_x                                      0x103BA44
#define pinstCIconSelectionWnd_x                                   0xDC6500
#define pinstCInspectWnd_x                                         0xDC650C
#define pinstCInventoryWnd_x                                       0xDC6AF8
#define pinstCInvSlotMgr_x                                         0xDC6A98
#define pinstCItemDisplayManager_x                                 0x103BFC8
#define pinstCItemExpTransferWnd_x                                 0x103C0F8
#define pinstCItemOverflowWnd_x                                    0xDC6A2C
#define pinstCJournalCatWnd_x                                      0xDC659C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDC655C
#define pinstCKeyRingWnd_x                                         0xDC6D4C
#define pinstCLargeDialogWnd_x                                     0x103E240
#define pinstCLayoutCopyWnd_x                                      0x103C448
#define pinstCLFGuildWnd_x                                         0x103C4F8
#define pinstCLoadskinWnd_x                                        0xDC6B14
#define pinstCLootFiltersCopyWnd_x                                 0xC962C0
#define pinstCLootFiltersWnd_x                                     0xDC6B1C
#define pinstCLootSettingsWnd_x                                    0xDC6D38
#define pinstCLootWnd_x                                            0xDC654C
#define pinstCMailAddressBookWnd_x                                 0xDC64F8
#define pinstCMailCompositionWnd_x                                 0xDC64D4
#define pinstCMailIgnoreListWnd_x                                  0xDC64FC
#define pinstCMailWnd_x                                            0xDC6D48
#define pinstCManageLootWnd_x                                      0xDC7B70
#define pinstCMapToolbarWnd_x                                      0xDC6B04
#define pinstCMapViewWnd_x                                         0xDC6AE4
#define pinstCMarketplaceWnd_x                                     0xDC6560
#define pinstCMerchantWnd_x                                        0xDC6598
#define pinstCMIZoneSelectWnd_x                                    0x103CD30
#define pinstCMusicPlayerWnd_x                                     0xDC6D50
#define pinstCNameChangeMercWnd_x                                  0xDC6A94
#define pinstCNameChangePetWnd_x                                   0xDC6A50
#define pinstCNameChangeWnd_x                                      0xDC6548
#define pinstCNoteWnd_x                                            0xDC6A3C
#define pinstCObjectPreviewWnd_x                                   0xDC6584
#define pinstCOptionsWnd_x                                         0xDC6B08
#define pinstCPetInfoWnd_x                                         0xDC64D0
#define pinstCPetitionQWnd_x                                       0xDC65AC
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDC6AA0
#define pinstCPlayerWnd_x                                          0xDC65A0
#define pinstCPopupWndManager_x                                    0x103D5C0
#define pinstCProgressionSelectionWnd_x                            0x103D670
#define pinstCPurchaseGroupWnd_x                                   0xDC6A28
#define pinstCPurchaseWnd_x                                        0xDC6594
#define pinstCPvPLeaderboardWnd_x                                  0x103D720
#define pinstCPvPStatsWnd_x                                        0x103D7D0
#define pinstCQuantityWnd_x                                        0xDC6504
#define pinstCRaceChangeWnd_x                                      0xDC6568
#define pinstCRaidOptionsWnd_x                                     0xDC6AE0
#define pinstCRaidWnd_x                                            0xDC6510
#define pinstCRealEstateItemsWnd_x                                 0xDC6534
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC6554
#define pinstCRealEstateManageWnd_x                                0xDC6D44
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC64C8
#define pinstCRealEstatePlotSearchWnd_x                            0xDC64F0
#define pinstCRealEstatePurchaseWnd_x                              0xDC6514
#define pinstCRespawnWnd_x                                         0xDC6ACC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDC6AB0
#define pinstCSendMoneyWnd_x                                       0xDC6D40
#define pinstCServerListWnd_x                                      0xDC64E0
#define pinstCSkillsSelectWnd_x                                    0xDC6570
#define pinstCSkillsWnd_x                                          0xDC6550
#define pinstCSocialEditWnd_x                                      0xDC6520
#define pinstCSocialWnd_x                                          0xDC6AB4
#define pinstCSpellBookWnd_x                                       0xDC6AA8
#define pinstCStoryWnd_x                                           0xDC6A44
#define pinstCTargetOfTargetWnd_x                                  0x103F600
#define pinstCTargetWnd_x                                          0xDC64C4
#define pinstCTaskOverlayWnd_x                                     0xDC64F4
#define pinstCTaskSelectWnd_x                                      0x103F758
#define pinstCTaskManager_x                                        0xC96AC0
#define pinstCTaskTemplateSelectWnd_x                              0x103F808
#define pinstCTaskWnd_x                                            0x103F8B8
#define pinstCTextEntryWnd_x                                       0xDC6A90
#define pinstCTextOverlay_x                                        0xC7A5A8
#define pinstCTimeLeftWnd_x                                        0xDC657C
#define pinstCTipWndCONTEXT_x                                      0x103FABC
#define pinstCTipWndOFDAY_x                                        0x103FAB8
#define pinstCTitleWnd_x                                           0x103FB68
#define pinstCTrackingWnd_x                                        0xDC64DC
#define pinstCTradeskillWnd_x                                      0x103FCD0
#define pinstCTradeWnd_x                                           0xDC6A9C
#define pinstCTrainWnd_x                                           0xDC6508
#define pinstCTributeBenefitWnd_x                                  0x103FED0
#define pinstCTributeMasterWnd_x                                   0x103FF80
#define pinstCTributeTrophyWnd_x                                   0x1040030
#define pinstCVideoModesWnd_x                                      0xDC6AC8
#define pinstCVoiceMacroWnd_x                                      0xF2A108
#define pinstCVoteResultsWnd_x                                     0xDC6A34
#define pinstCVoteWnd_x                                            0xDC65A4
#define pinstCWebManager_x                                         0xF2A26C
#define pinstCZoneGuideWnd_x                                       0xDC6D54
#define pinstCZonePathWnd_x                                        0xDC64CC

#define pinstEQSuiteTextureLoader_x                                0xC650A0
#define pinstItemIconCache_x                                       0x1038E88
#define pinstLootFiltersManager_x                                  0xC96370
#define pinstRewardSelectionWnd_x                                  0x103DF18

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC15ABC
#define __CastRay_x                                                0x59A580
#define __CastRay2_x                                               0x59A5D0
#define __ConvertItemTags_x                                        0x5B5260
#define __CrashHandler_x                                           0x84CFA0
#define __EQGetTime_x                                              0x8EB8E0
#define __ExecuteCmd_x                                             0x592EF0
#define __FixHeading_x                                             0x97B450
#define __GameLoop_x                                               0x6A5A90
#define __get_bearing_x                                            0x59A0D0
#define __get_melee_range_x                                        0x59A7C0
#define __GetAnimationCache_x                                      0x709F50
#define __GetGaugeValueFromEQ_x                                    0x7FE3A0
#define __GetLabelFromEQ_x                                         0x7FFB20
#define __GetXTargetType_x                                         0x97CEB0
#define __HandleMouseWheel_x                                       0x6A6740
#define __HeadingDiff_x                                            0x97B4C0
#define __HelpPath_x                                               0xF275AC
#define __LoadFrontEnd_x                                           0x6A2570
#define __NewUIINI_x                                               0x7FE070
#define __pCrashHandler_x                                          0x105D420
#define __ProcessGameEvents_x                                      0x5F8600
#define __ProcessMouseEvent_x                                      0x5F7DC0
#define __SaveColors_x                                             0x542DE0
#define __STMLToText_x                                             0x91EE70
#define __ToggleKeyRingItem_x                                      0x505D00
#define CrashDetected_x                                            0x6A3FE0
#define DrawNetStatus_x                                            0x624790
#define Expansion_HoT_x                                            0xE89514
#define Teleport_Table_Size_x                                      0xE7A8E4
#define Teleport_Table_x                                           0xE786B8
#define Util__FastTime_x                                           0x8EB4A0
#define wwsCrashReportCheckForUploader_x                           0x84D970
#define wwsCrashReportPlatformLaunchUploader_x                     0x850030

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B380
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494200
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493FC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54A910
#define AltAdvManager__IsAbilityReady_x                            0x549860
#define AltAdvManager__GetAAById_x                                 0x549A60
#define AltAdvManager__CanTrainAbility_x                           0x549AD0
#define AltAdvManager__CanSeeAbility_x                             0x549E30

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C70C0
#define CharacterZoneClient__HasSkill_x                            0x4D1F90
#define CharacterZoneClient__MakeMeVisible_x                       0x4D36B0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB540
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7CC0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6060
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6140
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6220
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0020
#define CharacterZoneClient__BardCastBard_x                        0x4C2C60
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7D90
#define CharacterZoneClient__GetEffect_x                           0x4B7C00
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1020
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C10F0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1140
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1290
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1460
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AFAA0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4620
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4090

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CC2C0
#define CBankWnd__WndNotification_x                                0x6CC0A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D9990

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x606EA0
#define CButtonWnd__CButtonWnd_x                                   0x91B280

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F88A0
#define CChatManager__InitContextMenu_x                            0x6F28F0
#define CChatManager__FreeChatWindow_x                             0x6F77B0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FC210
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F8640

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92FA40
#define CContextMenu__dCContextMenu_x                              0x92FC70
#define CContextMenu__AddMenuItem_x                                0x92FC80
#define CContextMenu__RemoveMenuItem_x                             0x92FF90
#define CContextMenu__RemoveAllMenuItems_x                         0x92FFB0
#define CContextMenu__CheckMenuItem_x                              0x930030
#define CContextMenu__SetMenuItem_x                                0x92FEB0
#define CContextMenu__AddSeparator_x                               0x92FE10

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9305D0
#define CContextMenuManager__RemoveMenu_x                          0x930640
#define CContextMenuManager__PopupMenu_x                           0x930700
#define CContextMenuManager__Flush_x                               0x930570
#define CContextMenuManager__GetMenu_x                             0x496320
#define CContextMenuManager__CreateDefaultMenu_x                   0x704730

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CC3C0
#define CChatService__GetFriendName_x                              0x8CC3D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F8E10
#define CChatWindow__Clear_x                                       0x6F9E70
#define CChatWindow__WndNotification_x                             0x6FA3E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92CED0
#define CComboWnd__Draw_x                                          0x92C3C0
#define CComboWnd__GetCurChoice_x                                  0x92CD10
#define CComboWnd__GetListRect_x                                   0x92C870
#define CComboWnd__GetTextRect_x                                   0x92CF40
#define CComboWnd__InsertChoice_x                                  0x92CA00
#define CComboWnd__SetColors_x                                     0x92C9D0
#define CComboWnd__SetChoice_x                                     0x92CCE0
#define CComboWnd__GetItemCount_x                                  0x92CD20
#define CComboWnd__GetCurChoiceText_x                              0x92CD60

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x702120
#define CContainerWnd__vftable_x                                   0xADA388
#define CContainerWnd__SetContainer_x                              0x703690

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x542BA0
#define CDisplay__GetClickedActor_x                                0x535B60
#define CDisplay__GetUserDefinedColor_x                            0x52E240
#define CDisplay__GetWorldFilePath_x                               0x5375B0
#define CDisplay__is3dON_x                                         0x532830
#define CDisplay__ReloadUI_x                                       0x53CCD0
#define CDisplay__WriteTextHD2_x                                   0x532610
#define CDisplay__TrueDistance_x                                   0x539210
#define CDisplay__SetViewActor_x                                   0x5354B0
#define CDisplay__GetFloorHeight_x                                 0x5328F0
#define CDisplay__SetRenderWindow_x                                0x531220
#define CDisplay__ToggleScreenshotMode_x                           0x534F80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94EE00

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x934130
#define CEditWnd__GetCharIndexPt_x                                 0x935030
#define CEditWnd__GetDisplayString_x                               0x934ED0
#define CEditWnd__GetHorzOffset_x                                  0x933760
#define CEditWnd__GetLineForPrintableChar_x                        0x936230
#define CEditWnd__GetSelStartPt_x                                  0x9352E0
#define CEditWnd__GetSTMLSafeText_x                                0x934CF0
#define CEditWnd__PointFromPrintableChar_x                         0x935E60
#define CEditWnd__SelectableCharFromPoint_x                        0x935FD0
#define CEditWnd__SetEditable_x                                    0x9353B0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E6720
#define CEverQuest__ClickedPlayer_x                                0x5D8970
#define CEverQuest__CreateTargetIndicator_x                        0x5F58B0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F5940
#define CEverQuest__DoTellWindow_x                                 0x4E3220
#define CEverQuest__OutputTextToLog_x                              0x4E3450
#define CEverQuest__DropHeldItemOnGround_x                         0x5CE230
#define CEverQuest__dsp_chat_x                                     0x4E37E0
#define CEverQuest__trimName_x                                     0x5F1BA0
#define CEverQuest__Emote_x                                        0x5E6F30
#define CEverQuest__EnterZone_x                                    0x5E0FE0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EB440
#define CEverQuest__GetClassDesc_x                                 0x5EBA80
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EC080
#define CEverQuest__GetDeityDesc_x                                 0x5F4200
#define CEverQuest__GetLangDesc_x                                  0x5EC240
#define CEverQuest__GetRaceDesc_x                                  0x5EBA60
#define CEverQuest__InterpretCmd_x                                 0x5F47D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D2420
#define CEverQuest__LMouseUp_x                                     0x5D07A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D2D00
#define CEverQuest__RMouseUp_x                                     0x5D1730
#define CEverQuest__SetGameState_x                                 0x5CDFC0
#define CEverQuest__UPCNotificationFlush_x                         0x5F1AA0
#define CEverQuest__IssuePetCommand_x                              0x5ED640
#define CEverQuest__ReportSuccessfulHit_x                          0x5E8330

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7140B0
#define CGaugeWnd__CalcLinesFillRect_x                             0x714110
#define CGaugeWnd__Draw_x                                          0x7137A0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC730
#define CGuild__GetGuildName_x                                     0x4AB810
#define CGuild__GetGuildIndex_x                                    0x4ABBA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72F460

//CHotButton
#define CHotButton__SetButtonSize_x                                0x607260

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73C2D0
#define CInvSlotMgr__MoveItem_x                                    0x73B030
#define CInvSlotMgr__SelectSlot_x                                  0x73C3A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7398E0
#define CInvSlot__SliderComplete_x                                 0x737640
#define CInvSlot__GetItemBase_x                                    0x736FD0
#define CInvSlot__UpdateItem_x                                     0x737140

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73DDE0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73CF90
#define CInvSlotWnd__HandleLButtonUp_x                             0x73D960

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FA5F0
#define CItemDisplayWnd__UpdateStrings_x                           0x74C160
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x745F50
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x746470
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74C780
#define CItemDisplayWnd__AboutToShow_x                             0x74BDB0
#define CItemDisplayWnd__WndNotification_x                         0x74DC90
#define CItemDisplayWnd__RequestConvertItem_x                      0x74D7F0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x74AE10
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x74BBD0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x832020

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x751D60

// CLabel 
#define CLabel__Draw_x                                             0x7577A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9055A0
#define CListWnd__dCListWnd_x                                      0x9058C0
#define CListWnd__AddColumn_x                                      0x909BF0
#define CListWnd__AddColumn1_x                                     0x909C40
#define CListWnd__AddLine_x                                        0x909FD0
#define CListWnd__AddString_x                                      0x909DD0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9099B0
#define CListWnd__CalculateVSBRange_x                              0x909790
#define CListWnd__ClearSel_x                                       0x90A7B0
#define CListWnd__ClearAllSel_x                                    0x90A810
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90B230
#define CListWnd__Compare_x                                        0x9090D0
#define CListWnd__Draw_x                                           0x9059C0
#define CListWnd__DrawColumnSeparators_x                           0x9081A0
#define CListWnd__DrawHeader_x                                     0x908610
#define CListWnd__DrawItem_x                                       0x908A10
#define CListWnd__DrawLine_x                                       0x908310
#define CListWnd__DrawSeparator_x                                  0x908240
#define CListWnd__EnableLine_x                                     0x907A80
#define CListWnd__EnsureVisible_x                                  0x90B150
#define CListWnd__ExtendSel_x                                      0x90A6E0
#define CListWnd__GetColumnTooltip_x                               0x9075C0
#define CListWnd__GetColumnMinWidth_x                              0x907630
#define CListWnd__GetColumnWidth_x                                 0x907530
#define CListWnd__GetCurSel_x                                      0x906EC0
#define CListWnd__GetItemAtPoint_x                                 0x907D00
#define CListWnd__GetItemAtPoint1_x                                0x907D70
#define CListWnd__GetItemData_x                                    0x906F40
#define CListWnd__GetItemHeight_x                                  0x907300
#define CListWnd__GetItemIcon_x                                    0x9070D0
#define CListWnd__GetItemRect_x                                    0x907B70
#define CListWnd__GetItemText_x                                    0x906F80
#define CListWnd__GetSelList_x                                     0x90A860
#define CListWnd__GetSeparatorRect_x                               0x907FB0
#define CListWnd__InsertLine_x                                     0x90A3C0
#define CListWnd__RemoveLine_x                                     0x90A510
#define CListWnd__SetColors_x                                      0x909760
#define CListWnd__SetColumnJustification_x                         0x909490
#define CListWnd__SetColumnWidth_x                                 0x9093B0
#define CListWnd__SetCurSel_x                                      0x90A620
#define CListWnd__SetItemColor_x                                   0x90AE00
#define CListWnd__SetItemData_x                                    0x90ADC0
#define CListWnd__SetItemText_x                                    0x90A9D0
#define CListWnd__ShiftColumnSeparator_x                           0x909550
#define CListWnd__Sort_x                                           0x909250
#define CListWnd__ToggleSel_x                                      0x90A650
#define CListWnd__SetColumnsSizable_x                              0x9095F0
#define CListWnd__SetItemWnd_x                                     0x90AC80
#define CListWnd__GetItemWnd_x                                     0x907120
#define CListWnd__SetItemIcon_x                                    0x90AA50
#define CListWnd__CalculateCustomWindowPositions_x                 0x909AB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76CD00
#define CMapViewWnd__GetWorldCoordinates_x                         0x76B410
#define CMapViewWnd__HandleLButtonDown_x                           0x768470

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78FFD0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7908B0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x790DE0
#define CMerchantWnd__SelectRecoverySlot_x                         0x793D60
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78EB10
#define CMerchantWnd__SelectBuySellSlot_x                          0x799930
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78FBE0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89A010
#define CPacketScrambler__hton_x                                   0x89A000

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x924440
#define CSidlManager__FindScreenPieceTemplate_x                    0x924850
#define CSidlManager__FindScreenPieceTemplate1_x                   0x924640
#define CSidlManager__CreateLabel_x                                0x7F18F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x927900
#define CSidlManager__CreateXWndFromTemplate1_x                    0x927AE0
#define CSidlManager__CreateXWnd_x                                 0x7F1820
#define CSidlManager__CreateHotButtonWnd_x                         0x7F1DF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x920FC0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x920EC0
#define CSidlScreenWnd__ConvertToRes_x                             0x945E20
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x920950
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x920640
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x920710
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9207E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x921460
#define CSidlScreenWnd__EnableIniStorage_x                         0x921930
#define CSidlScreenWnd__GetSidlPiece_x                             0x921650
#define CSidlScreenWnd__Init1_x                                    0x920240
#define CSidlScreenWnd__LoadIniInfo_x                              0x921980
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9224B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91F650
#define CSidlScreenWnd__StoreIniInfo_x                             0x922030
#define CSidlScreenWnd__StoreIniVis_x                              0x922390
#define CSidlScreenWnd__WndNotification_x                          0x921370
#define CSidlScreenWnd__GetChildItem_x                             0x9218B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x911130
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B8390

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66B980
#define CSkillMgr__GetSkillCap_x                                   0x66BB60
#define CSkillMgr__GetNameToken_x                                  0x66B110
#define CSkillMgr__IsActivatedSkill_x                              0x66B250
#define CSkillMgr__IsCombatSkill_x                                 0x66B190

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9313C0
#define CSliderWnd__SetValue_x                                     0x931230
#define CSliderWnd__SetNumTicks_x                                  0x931290

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F7B40

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9381A0
#define CStmlWnd__CalculateHSBRange_x                              0x939290
#define CStmlWnd__CalculateVSBRange_x                              0x939200
#define CStmlWnd__CanBreakAtCharacter_x                            0x93D5D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93E260
#define CStmlWnd__ForceParseNow_x                                  0x938740
#define CStmlWnd__GetNextTagPiece_x                                0x93D530
#define CStmlWnd__GetSTMLText_x                                    0x4F52F0
#define CStmlWnd__GetVisibleText_x                                 0x938760
#define CStmlWnd__InitializeWindowVariables_x                      0x93E0B0
#define CStmlWnd__MakeStmlColorTag_x                               0x937880
#define CStmlWnd__MakeWndNotificationTag_x                         0x9378F0
#define CStmlWnd__SetSTMLText_x                                    0x936930
#define CStmlWnd__StripFirstSTMLLines_x                            0x93F360
#define CStmlWnd__UpdateHistoryString_x                            0x93E470

// CTabWnd 
#define CTabWnd__Draw_x                                            0x942DB0
#define CTabWnd__DrawCurrentPage_x                                 0x9433D0
#define CTabWnd__DrawTab_x                                         0x9431A0
#define CTabWnd__GetCurrentPage_x                                  0x942610
#define CTabWnd__GetPageInnerRect_x                                0x942850
#define CTabWnd__GetTabInnerRect_x                                 0x942790
#define CTabWnd__GetTabRect_x                                      0x942640
#define CTabWnd__InsertPage_x                                      0x942A40
#define CTabWnd__SetPage_x                                         0x9428D0
#define CTabWnd__SetPageRect_x                                     0x942CF0
#define CTabWnd__UpdatePage_x                                      0x943060
#define CTabWnd__GetPageFromTabIndex_x                             0x9430E0
#define CTabWnd__GetCurrentTabIndex_x                              0x942600

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x752130
#define CPageWnd__SetTabText_x                                     0x94F210

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6410

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90DF50
#define CTextureFont__GetTextExtent_x                              0x90E110

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69F4D0
#define CHtmlComponentWnd__ValidateUri_x                           0x730E50
#define CHtmlWnd__SetClientCallbacks_x                             0x60C220
#define CHtmlWnd__AddObserver_x                                    0x60C240
#define CHtmlWnd__RemoveObserver_x                                 0x60C2A0
#define Window__getProgress_x                                      0x84AC10
#define Window__getStatus_x                                        0x84AC30
#define Window__getURI_x                                           0x84AC40

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94B830

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FB0C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADA90
#define CXStr__CXStr1_x                                            0x4F0390
#define CXStr__CXStr3_x                                            0x8E7A10
#define CXStr__dCXStr_x                                            0x472F90
#define CXStr__operator_equal_x                                    0x8E7C40
#define CXStr__operator_equal1_x                                   0x8E7C80
#define CXStr__operator_plus_equal1_x                              0x8E8710
#define CXStr__SetString_x                                         0x8EA600

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92F660
#define CXWnd__BringToTop_x                                        0x914850
#define CXWnd__Center_x                                            0x9143D0
#define CXWnd__ClrFocus_x                                          0x914200
#define CXWnd__Destroy_x                                           0x9142B0
#define CXWnd__DoAllDrawing_x                                      0x9108C0
#define CXWnd__DrawChildren_x                                      0x910890
#define CXWnd__DrawColoredRect_x                                   0x910D20
#define CXWnd__DrawTooltip_x                                       0x90F3C0
#define CXWnd__DrawTooltipAtPoint_x                                0x90F480
#define CXWnd__GetBorderFrame_x                                    0x910B80
#define CXWnd__GetChildWndAt_x                                     0x9148F0
#define CXWnd__GetClientClipRect_x                                 0x912B20
#define CXWnd__GetScreenClipRect_x                                 0x912BF0
#define CXWnd__GetScreenRect_x                                     0x912DA0
#define CXWnd__GetTooltipRect_x                                    0x910D70
#define CXWnd__GetWindowTextA_x                                    0x497AA0
#define CXWnd__IsActive_x                                          0x917780
#define CXWnd__IsDescendantOf_x                                    0x9137B0
#define CXWnd__IsReallyVisible_x                                   0x9137E0
#define CXWnd__IsType_x                                            0x914F70
#define CXWnd__Move_x                                              0x913850
#define CXWnd__Move1_x                                             0x913910
#define CXWnd__ProcessTransition_x                                 0x914380
#define CXWnd__Refade_x                                            0x913BE0
#define CXWnd__Resize_x                                            0x913E70
#define CXWnd__Right_x                                             0x914610
#define CXWnd__SetFocus_x                                          0x9141C0
#define CXWnd__SetFont_x                                           0x914230
#define CXWnd__SetKeyTooltip_x                                     0x914D80
#define CXWnd__SetMouseOver_x                                      0x911CC0
#define CXWnd__StartFade_x                                         0x913680
#define CXWnd__GetChildItem_x                                      0x914A60
#define CXWnd__SetParent_x                                         0x913550

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x946EB0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9177C0
#define CXWndManager__DrawWindows_x                                0x9177E0
#define CXWndManager__GetKeyboardFlags_x                           0x919F60
#define CXWndManager__HandleKeyboardMsg_x                          0x919B60
#define CXWndManager__RemoveWnd_x                                  0x91A1B0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91A700

// CDBStr
#define CDBStr__GetString_x                                        0x52D1F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8C70
#define EQ_Character__Cur_HP_x                                     0x4CEF70
#define EQ_Character__Cur_Mana_x                                   0x4D6720
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BBB80
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF6E0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF830
#define EQ_Character__GetHPRegen_x                                 0x4DC680
#define EQ_Character__GetEnduranceRegen_x                          0x4DCC90
#define EQ_Character__GetManaRegen_x                               0x4DD0D0
#define EQ_Character__Max_Endurance_x                              0x6323D0
#define EQ_Character__Max_HP_x                                     0x4CEDA0
#define EQ_Character__Max_Mana_x                                   0x6321D0
#define EQ_Character__doCombatAbility_x                            0x634890
#define EQ_Character__UseSkill_x                                   0x4DEEE0
#define EQ_Character__GetConLevel_x                                0x62B670
#define EQ_Character__IsExpansionFlag_x                            0x591670
#define EQ_Character__TotalEffect_x                                0x4C21E0
#define EQ_Character__GetPCSpellAffect_x                           0x4BC770
#define EQ_Character__SpellDuration_x                              0x4BC2A0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1D50
#define EQ_Character__GetBaseSkill_x                               0x4D2CF0
#define EQ_Character__CanUseItem_x                                 0x4D6A30

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B9270

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6488B0

//PcClient
#define PcClient__PcClient_x                                       0x628DA0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B68D0
#define CCharacterListWnd__EnterWorld_x                            0x4B6310
#define CCharacterListWnd__Quit_x                                  0x4B6020
#define CCharacterListWnd__UpdateList_x                            0x4B64A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60D450
#define EQ_Item__CreateItemTagString_x                             0x893970
#define EQ_Item__IsStackable_x                                     0x8983A0
#define EQ_Item__GetImageNum_x                                     0x8953B0
#define EQ_Item__CreateItemClient_x                                0x60C620
#define EQ_Item__GetItemValue_x                                    0x896640
#define EQ_Item__ValueSellMerchant_x                               0x899BB0
#define EQ_Item__IsKeyRingItem_x                                   0x897D00
#define EQ_Item__CanGoInBag_x                                      0x60D570
#define EQ_Item__IsEmpty_x                                         0x897800
#define EQ_Item__GetMaxItemCount_x                                 0x896A00
#define EQ_Item__GetHeldItem_x                                     0x895280
#define EQ_Item__GetAugmentFitBySlot_x                             0x8932D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54B600
#define EQ_LoadingS__Array_x                                       0xBED138

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x632D30
#define EQ_PC__GetAlternateAbilityId_x                             0x8A2E30
#define EQ_PC__GetCombatAbility_x                                  0x8A34A0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A3510
#define EQ_PC__GetItemRecastTimer_x                                0x634E10
#define EQ_PC__HasLoreItem_x                                       0x62BDE0
#define EQ_PC__AlertInventoryChanged_x                             0x62AFA0
#define EQ_PC__GetPcZoneClient_x                                   0x657050
#define EQ_PC__RemoveMyAffect_x                                    0x638030
#define EQ_PC__GetKeyRingItems_x                                   0x8A3DB0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A3B30
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A40A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x597B10
#define EQItemList__add_object_x                                   0x5C3990
#define EQItemList__add_item_x                                     0x598120
#define EQItemList__delete_item_x                                  0x598170
#define EQItemList__FreeItemList_x                                 0x598070

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52A790

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64A130
#define EQPlayer__dEQPlayer_x                                      0x63D710
#define EQPlayer__DoAttack_x                                       0x651D00
#define EQPlayer__EQPlayer_x                                       0x63DDC0
#define EQPlayer__SetNameSpriteState_x                             0x642030
#define EQPlayer__SetNameSpriteTint_x                              0x642EF0
#define PlayerBase__HasProperty_j_x                                0x979830
#define EQPlayer__IsTargetable_x                                   0x979CD0
#define EQPlayer__CanSee_x                                         0x979B30
#define EQPlayer__CanSee1_x                                        0x979C00
#define PlayerBase__GetVisibilityLineSegment_x                     0x9798F0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x654AE0
#define PlayerZoneClient__GetLevel_x                               0x657090
#define PlayerZoneClient__IsValidTeleport_x                        0x5C4AF0
#define PlayerZoneClient__LegalPlayerRace_x                        0x544A40

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64CEC0
#define EQPlayerManager__GetSpawnByName_x                          0x64CEE0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64CF70

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x610CE0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x610D20
#define KeypressHandler__ClearCommandStateArray_x                  0x612110
#define KeypressHandler__HandleKeyDown_x                           0x612130
#define KeypressHandler__HandleKeyUp_x                             0x6121D0
#define KeypressHandler__SaveKeymapping_x                          0x6125B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x768B90
#define MapViewMap__SaveEx_x                                       0x76BF30
#define MapViewMap__SetZoom_x                                      0x770600

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B7160

// StringTable 
#define StringTable__getString_x                                   0x8B20B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x637CA0
#define PcZoneClient__RemovePetEffect_x                            0x6382D0
#define PcZoneClient__HasAlternateAbility_x                        0x632010
#define PcZoneClient__GetCurrentMod_x                              0x4E1FC0
#define PcZoneClient__GetModCap_x                                  0x4E1EC0
#define PcZoneClient__CanEquipItem_x                               0x6326C0
#define PcZoneClient__GetItemByID_x                                0x635280
#define PcZoneClient__GetItemByItemClass_x                         0x6353D0
#define PcZoneClient__RemoveBuffEffect_x                           0x6382F0
#define PcZoneClient__BandolierSwap_x                              0x6332F0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x634DB0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C9680

//IconCache
#define IconCache__GetIcon_x                                       0x7097E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7012C0
#define CContainerMgr__CloseContainer_x                            0x701590
#define CContainerMgr__OpenExperimentContainer_x                   0x702010

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C3F50

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x605680

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75EFD0
#define CLootWnd__RequestLootSlot_x                                0x75E370

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x563AC0
#define EQ_Spell__SpellAffects_x                                   0x563F30
#define EQ_Spell__SpellAffectBase_x                                0x563CF0
#define EQ_Spell__IsStackable_x                                    0x4C69C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6840
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3C70
#define EQ_Spell__IsSPAStacking_x                                  0x564D60
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x564280
#define EQ_Spell__IsNoRemove_x                                     0x4C69A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x564D70
#define __IsResEffectSpell_x                                       0x4C5D30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA430

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C17F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x809930
#define CTargetWnd__WndNotification_x                              0x8091C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x809490
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x808310

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80E000

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5280B0
#define CTaskManager__HandleMessage_x                              0x526810

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55F070
#define EqSoundManager__PlayScriptMp3_x                            0x55F1D0
#define EqSoundManager__SoundAssistPlay_x                          0x66F9F0
#define EqSoundManager__WaveInstancePlay_x                         0x66EF60

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51C0B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x932DA0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5532E0
#define CAltAbilityData__GetMercMaxRank_x                          0x553280
#define CAltAbilityData__GetMaxRank_x                              0x548710

//CTargetRing
#define CTargetRing__Cast_x                                        0x603780

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6820
#define CharacterBase__CreateItemGlobalIndex_x                     0x502130
#define CharacterBase__CreateItemIndex_x                           0x60B860
#define CharacterBase__GetItemPossession_x                         0x4EDD50
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C9E40
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8C9EA0
#define CharacterBase__GetEffectId_x                               0x4C67D0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E9160
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E9980

//messages
#define msg_spell_worn_off_x                                       0x589890
#define msg_new_text_x                                             0x57E650
#define __msgTokenTextParam_x                                      0x58BDB0
#define msgTokenText_x                                             0x58C000

//SpellManager
#define SpellManager__vftable_x                                    0xAB4A20
#define SpellManager__SpellManager_x                               0x672D10
#define Spellmanager__LoadTextSpells_x                             0x6735E0
#define SpellManager__GetSpellByGroupAndRank_x                     0x672EE0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97D7A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x502880
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58FBC0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6245F0
#define ItemGlobalIndex__IsValidIndex_x                            0x5028E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C2130
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C23B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x757AF0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7059D0
#define CCursorAttachment__AttachToCursor1_x                       0x705A10
#define CCursorAttachment__Deactivate_x                            0x7069F0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x928930
#define CSidlManagerBase__CreatePageWnd_x                          0x928130
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x924260
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9241F0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x945420
#define CEQSuiteTextureLoader__GetTexture_x                        0x9450E0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FF6D0
#define CFindItemWnd__WndNotification_x                            0x5001B0
#define CFindItemWnd__Update_x                                     0x500D20
#define CFindItemWnd__PickupSelectedItem_x                         0x4FEF30

//IString
#define IString__Append_x                                          0x4EF400

//Camera
#define CDisplay__cameraType_x                                     0xDC6B24
#define EverQuest__Cameras_x                                       0xE89858

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x507F70
#define LootFiltersManager__GetItemFilterData_x                    0x507870
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5078A0
#define LootFiltersManager__SetItemLootFilter_x                    0x507AC0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B1F90

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x983460
#define CResolutionHandler__GetWindowedStyle_x                     0x66A380

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FE080

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D4940

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71E220
#define CGroupWnd__UpdateDisplay_x                                 0x71D580

//ItemBase
#define ItemBase__IsLore_x                                         0x897D60
#define ItemBase__IsLoreEquipped_x                                 0x897DD0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C3880
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C3A30
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C3A90

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65FB50
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x663830

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F5980

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E4B70
#define FactionManagerClient__HandleFactionMessage_x               0x4E51E0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E5800
#define FactionManagerClient__GetMaxFaction_x                      0x4E5850
#define FactionManagerClient__GetMinFaction_x                      0x4E57D0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4EDD20

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x90CEE0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

