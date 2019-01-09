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
#define __ExpectedVersionDate                                     "Jan  4 2019"
#define __ExpectedVersionTime                                     "14:28:40"
#define __ActualVersionDate_x                                      0xAD111C
#define __ActualVersionTime_x                                      0xAD1110

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x616140
#define __MemChecker1_x                                            0x8EB050
#define __MemChecker2_x                                            0x6A5A80
#define __MemChecker3_x                                            0x6A59D0
#define __MemChecker4_x                                            0x8425E0
#define __EncryptPad0_x                                            0xC05340
#define __EncryptPad1_x                                            0xC635D0
#define __EncryptPad2_x                                            0xC15EC8
#define __EncryptPad3_x                                            0xC15AC8
#define __EncryptPad4_x                                            0xC53E40
#define __EncryptPad5_x                                            0x1034B08
#define __AC1_x                                                    0x7FF1A6
#define __AC2_x                                                    0x5D0DFF
#define __AC3_x                                                    0x5D7C8F
#define __AC4_x                                                    0x5DBAB0
#define __AC5_x                                                    0x5E1D20
#define __AC6_x                                                    0x5E62E6
#define __AC7_x                                                    0x5D0870
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E8A2B0

// Direct Input
#define DI8__Main_x                                                0x1034B2C
#define DI8__Keyboard_x                                            0x1034B30
#define DI8__Mouse_x                                               0xF2A78C
#define DI8__Mouse_Copy_x                                          0xE881B4
#define DI8__Mouse_Check_x                                         0xF2A790
#define __AutoSkillArray_x                                         0xE890CC
#define __Attack_x                                                 0xF26ED7
#define __Autofire_x                                               0xF26ED8
#define __BindList_x                                               0xBF3F20
#define g_eqCommandStates_x                                        0xBF4C90
#define __Clicks_x                                                 0xE8826C
#define __CommandList_x                                            0xBF5848
#define __CurrentMapLabel_x                                        0x103CA94
#define __CurrentSocial_x                                          0xBDE730
#define __DoAbilityList_x                                          0xEBE9F8
#define __do_loot_x                                                0x59E2B0
#define __DrawHandler_x                                            0x16B9468
#define __GroupCount_x                                             0xE7847A
#define __Guilds_x                                                 0xE7E9C0
#define __gWorld_x                                                 0xE7AD40
#define __HWnd_x                                                   0xF2A7A4
#define __heqmain_x                                                0x1034AF0
#define __InChatMode_x                                             0xE8819C
#define __LastTell_x                                               0xE8A0F4
#define __LMouseHeldTime_x                                         0xE882D8
#define __Mouse_x                                                  0x1034B14
#define __MouseLook_x                                              0xE88232
#define __MouseEventTime_x                                         0xF27990
#define __gpbCommandEvent_x                                        0xE7A7E8
#define __NetStatusToggle_x                                        0xE88235
#define __PCNames_x                                                0xE896AC
#define __RangeAttackReady_x                                       0xE893B0
#define __RMouseHeldTime_x                                         0xE882D4
#define __RunWalkState_x                                           0xE881A0
#define __ScreenMode_x                                             0xDC6AA0
#define __ScreenX_x                                                0xE88154
#define __ScreenY_x                                                0xE88150
#define __ScreenXMax_x                                             0xE88158
#define __ScreenYMax_x                                             0xE8815C
#define __ServerHost_x                                             0xE7AA2B
#define __ServerName_x                                             0xEBE9B8
#define __ShiftKeyDown_x                                           0xE8882C
#define __ShowNames_x                                              0xE8956C
#define __Socials_x                                                0xEBEAB8
#define __SubscriptionType_x                                       0x107E5E4
#define __TargetAggroHolder_x                                      0x103F450
#define __ZoneType_x                                               0xE88630
#define __GroupAggro_x                                             0x103F490
#define __LoginName_x                                              0x1035384
#define __Inviter_x                                                0xF26E54
#define __AttackOnAssist_x                                         0xE89528
#define __UseTellWindows_x                                         0xE89848
#define __gfMaxZoomCameraDistance_x                                0xAC6600
#define __gfMaxCameraDistance_x                                    0xAF3AF0
#define __pulAutoRun_x                                             0xE88250
#define __pulForward_x                                             0xE89880
#define __pulBackward_x                                            0xE89884
#define __pulTurnRight_x                                           0xE89888
#define __pulTurnLeft_x                                            0xE8988C
#define __pulStrafeLeft_x                                          0xE89890
#define __pulStrafeRight_x                                         0xE89894

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE7AD58
#define instEQZoneInfo_x                                           0xE88428
#define instKeypressHandler_x                                      0xF27940
#define pinstActiveBanker_x                                        0xE7A8A4
#define pinstActiveCorpse_x                                        0xE7A890
#define pinstActiveGMaster_x                                       0xE7A89C
#define pinstActiveMerchant_x                                      0xE7A88C
#define pinstAggroInfo_x                                           0xC79E08
#define pinstAltAdvManager_x                                       0xDC76F8
#define pinstAuraMgr_x                                             0xC95988
#define pinstBandageTarget_x                                       0xE7A8C4
#define pinstCamActor_x                                            0xDC6A90
#define pinstCDBStr_x                                              0xDC642C
#define pinstCDisplay_x                                            0xE7AB34
#define pinstCEverQuest_x                                          0x1034C48
#define pinstEverQuestInfo_x                                       0xE88148
#define pinstCharData_x                                            0xE7AD48
#define pinstCharSpawn_x                                           0xE7A91C
#define pinstControlledMissile_x                                   0xE7AD44
#define pinstControlledPlayer_x                                    0xE7A91C
#define pinstCResolutionHandler_x                                  0x16B9698
#define pinstCSidlManager_x                                        0x16B852C
#define pinstCXWndManager_x                                        0x16B8520
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
#define pinstImeManager_x                                          0x16B8524
#define pinstLocalPlayer_x                                         0xE7A884
#define pinstMercenaryData_x                                       0xF2813C
#define pinstMercenaryStats_x                                      0x103F59C
#define pinstMercAltAbilities_x                                    0xDC7CC8
#define pinstModelPlayer_x                                         0xE7A8B4
#define pinstPCData_x                                              0xE7AD48
#define pinstRealEstateItems_x                                     0xF29630
#define pinstSkillMgr_x                                            0xF29700
#define pinstSpawnManager_x                                        0xF28CF0
#define pinstSpellManager_x                                        0xF298D8
#define pinstSpellSets_x                                           0xF1FB00
#define pinstStringTable_x                                         0xE7A6C8
#define pinstSwitchManager_x                                       0xE782F8
#define pinstTarget_x                                              0xE7A918
#define pinstTargetObject_x                                        0xE7A924
#define pinstTargetSwitch_x                                        0xE7AD50
#define pinstTaskMember_x                                          0xDC61FC
#define pinstTrackTarget_x                                         0xE7A920
#define pinstTradeTarget_x                                         0xE7A8A8
#define instTributeActive_x                                        0xDC638D
#define pinstViewActor_x                                           0xDC6A8C
#define pinstWorldData_x                                           0xE7A7F4
#define pinstZoneAddr_x                                            0xE886C8
#define pinstPlayerPath_x                                          0xF28D88
#define pinstTargetIndicator_x                                     0xF29B40
#define pinstCTargetManager_x                                      0xF29BD8
#define EQObject_Top_x                                             0xE7A7FC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC6548
#define pinstCAchievementsWnd_x                                    0xDC653C
#define pinstCActionsWnd_x                                         0xDC65AC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC6A50
#define pinstCAdvancedLootWnd_x                                    0xDC6594
#define pinstCAdventureLeaderboardWnd_x                            0x1036268
#define pinstCAdventureRequestWnd_x                                0x1036318
#define pinstCAdventureStatsWnd_x                                  0x10363C8
#define pinstCAggroMeterWnd_x                                      0xDC6AD0
#define pinstCAlarmWnd_x                                           0xDC6B3C
#define pinstCAlertHistoryWnd_x                                    0xDC64F8
#define pinstCAlertStackWnd_x                                      0xDC6AE4
#define pinstCAlertWnd_x                                           0xDC6AFC
#define pinstCAltStorageWnd_x                                      0x1036728
#define pinstCAudioTriggersWindow_x                                0xC7A298
#define pinstCAuraWnd_x                                            0xDC6ACC
#define pinstCAvaZoneWnd_x                                         0xDC64FC
#define pinstCBandolierWnd_x                                       0xDC6B10
#define pinstCBankWnd_x                                            0xDC64F4
#define pinstCBarterMerchantWnd_x                                  0x1037968
#define pinstCBarterSearchWnd_x                                    0x1037A18
#define pinstCBarterWnd_x                                          0x1037AC8
#define pinstCBazaarConfirmationWnd_x                              0xDC6ADC
#define pinstCBazaarSearchWnd_x                                    0xDC65D4
#define pinstCBazaarWnd_x                                          0xDC6B14
#define pinstCBlockedBuffWnd_x                                     0xDC64D4
#define pinstCBlockedPetBuffWnd_x                                  0xDC6504
#define pinstCBodyTintWnd_x                                        0xDC6AB0
#define pinstCBookWnd_x                                            0xDC6B2C
#define pinstCBreathWnd_x                                          0xDC6550
#define pinstCBuffWindowNORMAL_x                                   0xDC6D50
#define pinstCBuffWindowSHORT_x                                    0xDC6D54
#define pinstCBugReportWnd_x                                       0xDC6544
#define pinstCButtonWnd_x                                          0x16B8750
#define pinstCCastingWnd_x                                         0xDC6540
#define pinstCCastSpellWnd_x                                       0xDC6A4C
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDC6554
#define pinstCChatWindowManager_x                                  0x1038588
#define pinstCClaimWnd_x                                           0x10386E0
#define pinstCColorPickerWnd_x                                     0xDC6580
#define pinstCCombatAbilityWnd_x                                   0xDC6AD8
#define pinstCCombatSkillsSelectWnd_x                              0xDC65A4
#define pinstCCompassWnd_x                                         0xDC6A84
#define pinstCConfirmationDialog_x                                 0x103D5E0
#define pinstCContainerMgr_x                                       0xDC6AF0
#define pinstCContextMenuManager_x                                 0x16B84E0
#define pinstCCursorAttachment_x                                   0xDC6538
#define pinstCDistillerInfo_x                                      0x103BFEC
#define pinstCDynamicZoneWnd_x                                     0x1038CA8
#define pinstCEditLabelWnd_x                                       0xDC6B40
#define pinstCEQMainWnd_x                                          0x1038EF0
#define pinstCEventCalendarWnd_x                                   0xDC6570
#define pinstCExtendedTargetWnd_x                                  0xDC6AC0
#define pinstCFacePick_x                                           0xDC6578
#define pinstCFactionWnd_x                                         0xDC6534
#define pinstCFellowshipWnd_x                                      0x10390F0
#define pinstCFileSelectionWnd_x                                   0xDC6588
#define pinstCFindItemWnd_x                                        0xDC6B30
#define pinstCFindLocationWnd_x                                    0x1039248
#define pinstCFriendsWnd_x                                         0xDC65C0
#define pinstCGemsGameWnd_x                                        0xDC6B0C
#define pinstCGiveWnd_x                                            0xDC6B38
#define pinstCGroupSearchFiltersWnd_x                              0xDC6AEC
#define pinstCGroupSearchWnd_x                                     0x1039640
#define pinstCGroupWnd_x                                           0x10396F0
#define pinstCGuildBankWnd_x                                       0xE8950C
#define pinstCGuildCreationWnd_x                                   0x1039850
#define pinstCGuildMgmtWnd_x                                       0x1039900
#define pinstCharacterCreation_x                                   0xDC6AD4
#define pinstCHelpWnd_x                                            0xDC6A80
#define pinstCHeritageSelectionWnd_x                               0xDC658C
#define pinstCHotButtonWnd_x                                       0x103BA58
#define pinstCHotButtonWnd1_x                                      0x103BA58
#define pinstCHotButtonWnd2_x                                      0x103BA5C
#define pinstCHotButtonWnd3_x                                      0x103BA60
#define pinstCHotButtonWnd4_x                                      0x103BA64
#define pinstCIconSelectionWnd_x                                   0xDC6518
#define pinstCInspectWnd_x                                         0xDC6514
#define pinstCInventoryWnd_x                                       0xDC6B18
#define pinstCInvSlotMgr_x                                         0xDC6AB8
#define pinstCItemDisplayManager_x                                 0x103BFE8
#define pinstCItemExpTransferWnd_x                                 0x103C118
#define pinstCItemOverflowWnd_x                                    0xDC663C
#define pinstCJournalCatWnd_x                                      0xDC659C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDC6564
#define pinstCKeyRingWnd_x                                         0xDC64D0
#define pinstCLargeDialogWnd_x                                     0x103E260
#define pinstCLayoutCopyWnd_x                                      0x103C468
#define pinstCLFGuildWnd_x                                         0x103C518
#define pinstCLoadskinWnd_x                                        0xDC6B24
#define pinstCLootFiltersCopyWnd_x                                 0xC962C0
#define pinstCLootFiltersWnd_x                                     0xDC6B34
#define pinstCLootSettingsWnd_x                                    0xDC6D4C
#define pinstCLootWnd_x                                            0xDC656C
#define pinstCMailAddressBookWnd_x                                 0xDC650C
#define pinstCMailCompositionWnd_x                                 0xDC64E4
#define pinstCMailIgnoreListWnd_x                                  0xDC6510
#define pinstCMailWnd_x                                            0xDC6D58
#define pinstCManageLootWnd_x                                      0xDC7B70
#define pinstCMapToolbarWnd_x                                      0xDC6B1C
#define pinstCMapViewWnd_x                                         0xDC6AF8
#define pinstCMarketplaceWnd_x                                     0xDC6574
#define pinstCMerchantWnd_x                                        0xDC65A0
#define pinstCMIZoneSelectWnd_x                                    0x103CD50
#define pinstCMusicPlayerWnd_x                                     0xDC64C8
#define pinstCNameChangeMercWnd_x                                  0xDC6AB4
#define pinstCNameChangePetWnd_x                                   0xDC6A78
#define pinstCNameChangeWnd_x                                      0xDC6558
#define pinstCNoteWnd_x                                            0xDC6A54
#define pinstCObjectPreviewWnd_x                                   0xDC6598
#define pinstCOptionsWnd_x                                         0xDC6B20
#define pinstCPetInfoWnd_x                                         0xDC64E8
#define pinstCPetitionQWnd_x                                       0xDC65B4
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDC6AAC
#define pinstCPlayerWnd_x                                          0xDC65B8
#define pinstCPopupWndManager_x                                    0x103D5E0
#define pinstCProgressionSelectionWnd_x                            0x103D690
#define pinstCPurchaseGroupWnd_x                                   0xDC6A44
#define pinstCPurchaseWnd_x                                        0xDC65A8
#define pinstCPvPLeaderboardWnd_x                                  0x103D740
#define pinstCPvPStatsWnd_x                                        0x103D7F0
#define pinstCQuantityWnd_x                                        0xDC6520
#define pinstCRaceChangeWnd_x                                      0xDC657C
#define pinstCRaidOptionsWnd_x                                     0xDC6AF4
#define pinstCRaidWnd_x                                            0xDC6524
#define pinstCRealEstateItemsWnd_x                                 0xDC654C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC6568
#define pinstCRealEstateManageWnd_x                                0xDC6D5C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC64D8
#define pinstCRealEstatePlotSearchWnd_x                            0xDC6500
#define pinstCRealEstatePurchaseWnd_x                              0xDC6528
#define pinstCRespawnWnd_x                                         0xDC6AE8
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDC6AC4
#define pinstCSendMoneyWnd_x                                       0xDC6D48
#define pinstCServerListWnd_x                                      0xDC64F0
#define pinstCSkillsSelectWnd_x                                    0xDC6584
#define pinstCSkillsWnd_x                                          0xDC6560
#define pinstCSocialEditWnd_x                                      0xDC6530
#define pinstCSocialWnd_x                                          0xDC6AC8
#define pinstCSpellBookWnd_x                                       0xDC6ABC
#define pinstCStoryWnd_x                                           0xDC6A58
#define pinstCTargetOfTargetWnd_x                                  0x103F620
#define pinstCTargetWnd_x                                          0xDC64DC
#define pinstCTaskOverlayWnd_x                                     0xDC6508
#define pinstCTaskSelectWnd_x                                      0x103F778
#define pinstCTaskManager_x                                        0xC96AC0
#define pinstCTaskTemplateSelectWnd_x                              0x103F828
#define pinstCTaskWnd_x                                            0x103F8D8
#define pinstCTextEntryWnd_x                                       0xDC6A88
#define pinstCTextOverlay_x                                        0xC7A5A8
#define pinstCTimeLeftWnd_x                                        0xDC6590
#define pinstCTipWndCONTEXT_x                                      0x103FADC
#define pinstCTipWndOFDAY_x                                        0x103FAD8
#define pinstCTitleWnd_x                                           0x103FB88
#define pinstCTrackingWnd_x                                        0xDC64EC
#define pinstCTradeskillWnd_x                                      0x103FCF0
#define pinstCTradeWnd_x                                           0xDC6A9C
#define pinstCTrainWnd_x                                           0xDC651C
#define pinstCTributeBenefitWnd_x                                  0x103FEF0
#define pinstCTributeMasterWnd_x                                   0x103FFA0
#define pinstCTributeTrophyWnd_x                                   0x1040050
#define pinstCVideoModesWnd_x                                      0xDC6AE0
#define pinstCVoiceMacroWnd_x                                      0xF2A108
#define pinstCVoteResultsWnd_x                                     0xDC6A48
#define pinstCVoteWnd_x                                            0xDC65BC
#define pinstCWebManager_x                                         0xF2A26C
#define pinstCZoneGuideWnd_x                                       0xDC64CC
#define pinstCZonePathWnd_x                                        0xDC64E0

#define pinstEQSuiteTextureLoader_x                                0xC650A0
#define pinstItemIconCache_x                                       0x1038EA8
#define pinstLootFiltersManager_x                                  0xC96370
#define pinstRewardSelectionWnd_x                                  0x103DF38

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC15ABC
#define __CastRay_x                                                0x5997D0
#define __CastRay2_x                                               0x599820
#define __ConvertItemTags_x                                        0x5B44B0
#define __CrashHandler_x                                           0x84BF20
#define __EQGetTime_x                                              0x8EAB40
#define __ExecuteCmd_x                                             0x592180
#define __FixHeading_x                                             0x97B790
#define __get_bearing_x                                            0x599320
#define __get_melee_range_x                                        0x599A10
#define __GetAnimationCache_x                                      0x709310
#define __GetGaugeValueFromEQ_x                                    0x7FD9B0
#define __GetLabelFromEQ_x                                         0x7FF130
#define __GetXTargetType_x                                         0x97D1F0
#define __HandleMouseWheel_x                                       0x6A5B30
#define __HeadingDiff_x                                            0x97B800
#define __HelpPath_x                                               0xF275AC
#define __LoadFrontEnd_x                                           0x6A18E0
#define __NewUIINI_x                                               0x7FD680
#define __pCrashHandler_x                                          0x105D440
#define __ProcessGameEvents_x                                      0x5F7600
#define __ProcessMouseEvent_x                                      0x5F6DC0
#define __SaveColors_x                                             0x543000
#define __STMLToText_x                                             0x91E8B0
#define __ToggleKeyRingItem_x                                      0x5063B0
#define CrashDetected_x                                            0x6A33D0
#define DrawNetStatus_x                                            0x623760
#define Expansion_HoT_x                                            0xE89514
#define Teleport_Table_Size_x                                      0xE7A888
#define Teleport_Table_x                                           0xE786C0
#define Util__FastTime_x                                           0x8EA700
#define wwsCrashReportCheckForUploader_x                           0x84CE20
#define wwsCrashReportPlatformLaunchUploader_x                     0x84F500

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B7C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494640
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494400

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54AA00
#define AltAdvManager__IsAbilityReady_x                            0x549950
#define AltAdvManager__GetAAById_x                                 0x549B50
#define AltAdvManager__CanTrainAbility_x                           0x549BC0
#define AltAdvManager__CanSeeAbility_x                             0x549F20

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C76E0
#define CharacterZoneClient__HasSkill_x                            0x4D25C0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3CE0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBB50
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B82C0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D66A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6780
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6860
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0630
#define CharacterZoneClient__BardCastBard_x                        0x4C3280
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8390
#define CharacterZoneClient__GetEffect_x                           0x4B8200
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1630
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1700
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1750
#define CharacterZoneClient__CalcAffectChange_x                    0x4C18A0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1A70
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B0100

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CB730
#define CBankWnd__WndNotification_x                                0x6CB510

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D92F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x605F20
#define CButtonWnd__CButtonWnd_x                                   0x91ACB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F7C70
#define CChatManager__InitContextMenu_x                            0x6F1D10
#define CChatManager__FreeChatWindow_x                             0x6F6B80
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FB5E0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F7A10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92F590
#define CContextMenu__dCContextMenu_x                              0x92F7C0
#define CContextMenu__AddMenuItem_x                                0x92F7D0
#define CContextMenu__RemoveMenuItem_x                             0x92FAE0
#define CContextMenu__RemoveAllMenuItems_x                         0x92FB00
#define CContextMenu__CheckMenuItem_x                              0x92FB80
#define CContextMenu__SetMenuItem_x                                0x92FA00
#define CContextMenu__AddSeparator_x                               0x92F960

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x930120
#define CContextMenuManager__RemoveMenu_x                          0x930190
#define CContextMenuManager__PopupMenu_x                           0x930250
#define CContextMenuManager__Flush_x                               0x9300C0
#define CContextMenuManager__GetMenu_x                             0x4968F0
#define CContextMenuManager__CreateDefaultMenu_x                   0x703B20

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CB6B0
#define CChatService__GetFriendName_x                              0x8CB6C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F81E0
#define CChatWindow__Clear_x                                       0x6F9240
#define CChatWindow__WndNotification_x                             0x6F97B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92CA10
#define CComboWnd__Draw_x                                          0x92BF00
#define CComboWnd__GetCurChoice_x                                  0x92C850
#define CComboWnd__GetListRect_x                                   0x92C3B0
#define CComboWnd__GetTextRect_x                                   0x92CA80
#define CComboWnd__InsertChoice_x                                  0x92C540
#define CComboWnd__SetColors_x                                     0x92C510
#define CComboWnd__SetChoice_x                                     0x92C820
#define CComboWnd__GetItemCount_x                                  0x92C860
#define CComboWnd__GetCurChoiceText_x                              0x92C8A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x701500
#define CContainerWnd__vftable_x                                   0xADA408
#define CContainerWnd__SetContainer_x                              0x702A70

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x542DC0
#define CDisplay__GetClickedActor_x                                0x535D80
#define CDisplay__GetUserDefinedColor_x                            0x52E460
#define CDisplay__GetWorldFilePath_x                               0x5377D0
#define CDisplay__is3dON_x                                         0x532A50
#define CDisplay__ReloadUI_x                                       0x53CEF0
#define CDisplay__WriteTextHD2_x                                   0x532830
#define CDisplay__TrueDistance_x                                   0x539430
#define CDisplay__SetViewActor_x                                   0x5356D0
#define CDisplay__GetFloorHeight_x                                 0x532B10
#define CDisplay__SetRenderWindow_x                                0x531440
#define CDisplay__ToggleScreenshotMode_x                           0x5351A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94ED80

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x933CB0
#define CEditWnd__GetCharIndexPt_x                                 0x934BB0
#define CEditWnd__GetDisplayString_x                               0x934A50
#define CEditWnd__GetHorzOffset_x                                  0x9332D0
#define CEditWnd__GetLineForPrintableChar_x                        0x935DB0
#define CEditWnd__GetSelStartPt_x                                  0x934E60
#define CEditWnd__GetSTMLSafeText_x                                0x934870
#define CEditWnd__PointFromPrintableChar_x                         0x9359E0
#define CEditWnd__SelectableCharFromPoint_x                        0x935B50
#define CEditWnd__SetEditable_x                                    0x934F30

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E5810
#define CEverQuest__ClickedPlayer_x                                0x5D7A70
#define CEverQuest__CreateTargetIndicator_x                        0x5F48B0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F4940
#define CEverQuest__DoTellWindow_x                                 0x4E3750
#define CEverQuest__OutputTextToLog_x                              0x4E3980
#define CEverQuest__DropHeldItemOnGround_x                         0x5CD330
#define CEverQuest__dsp_chat_x                                     0x4E3D10
#define CEverQuest__trimName_x                                     0x5F0C30
#define CEverQuest__Emote_x                                        0x5E6020
#define CEverQuest__EnterZone_x                                    0x5E00D0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EA4D0
#define CEverQuest__GetClassDesc_x                                 0x5EAB10
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EB110
#define CEverQuest__GetDeityDesc_x                                 0x5F3200
#define CEverQuest__GetLangDesc_x                                  0x5EB2D0
#define CEverQuest__GetRaceDesc_x                                  0x5EAAF0
#define CEverQuest__InterpretCmd_x                                 0x5F37D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D1520
#define CEverQuest__LMouseUp_x                                     0x5CF8A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D1E00
#define CEverQuest__RMouseUp_x                                     0x5D0830
#define CEverQuest__SetGameState_x                                 0x5CD0C0
#define CEverQuest__UPCNotificationFlush_x                         0x5F0B30
#define CEverQuest__IssuePetCommand_x                              0x5EC6D0
#define CEverQuest__ReportSuccessfulHit_x                          0x5E7420

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7133B0
#define CGaugeWnd__CalcLinesFillRect_x                             0x713410
#define CGaugeWnd__Draw_x                                          0x712AB0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACDE0
#define CGuild__GetGuildName_x                                     0x4ABEC0
#define CGuild__GetGuildIndex_x                                    0x4AC250

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72E750

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6062E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73B980
#define CInvSlotMgr__MoveItem_x                                    0x73A690
#define CInvSlotMgr__SelectSlot_x                                  0x73BA50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x738F40
#define CInvSlot__SliderComplete_x                                 0x736CB0
#define CInvSlot__GetItemBase_x                                    0x736630
#define CInvSlot__UpdateItem_x                                     0x7367A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73D380
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73C650
#define CInvSlotWnd__HandleLButtonUp_x                             0x73CF00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F9BA0
#define CItemDisplayWnd__UpdateStrings_x                           0x74B5F0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x745580
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x745AA0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74BC10
#define CItemDisplayWnd__AboutToShow_x                             0x74B260
#define CItemDisplayWnd__WndNotification_x                         0x74D160

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x831530

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x751290

// CLabel 
#define CLabel__Draw_x                                             0x756E30

// CListWnd
#define CListWnd__CListWnd_x                                       0x905160
#define CListWnd__dCListWnd_x                                      0x905480
#define CListWnd__AddColumn_x                                      0x909790
#define CListWnd__AddColumn1_x                                     0x9097E0
#define CListWnd__AddLine_x                                        0x909B70
#define CListWnd__AddString_x                                      0x909970
#define CListWnd__CalculateFirstVisibleLine_x                      0x909560
#define CListWnd__CalculateVSBRange_x                              0x909340
#define CListWnd__ClearSel_x                                       0x90A350
#define CListWnd__ClearAllSel_x                                    0x90A3B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90ADC0
#define CListWnd__Compare_x                                        0x908C80
#define CListWnd__Draw_x                                           0x905580
#define CListWnd__DrawColumnSeparators_x                           0x907D50
#define CListWnd__DrawHeader_x                                     0x9081C0
#define CListWnd__DrawItem_x                                       0x9085C0
#define CListWnd__DrawLine_x                                       0x907EC0
#define CListWnd__DrawSeparator_x                                  0x907DF0
#define CListWnd__EnableLine_x                                     0x907640
#define CListWnd__EnsureVisible_x                                  0x90ACF0
#define CListWnd__ExtendSel_x                                      0x90A280
#define CListWnd__GetColumnMinWidth_x                              0x907180
#define CListWnd__GetColumnWidth_x                                 0x9070F0
#define CListWnd__GetCurSel_x                                      0x906A80
#define CListWnd__GetItemAtPoint_x                                 0x9078B0
#define CListWnd__GetItemAtPoint1_x                                0x907920
#define CListWnd__GetItemData_x                                    0x906B00
#define CListWnd__GetItemHeight_x                                  0x906EC0
#define CListWnd__GetItemIcon_x                                    0x906C90
#define CListWnd__GetItemRect_x                                    0x907730
#define CListWnd__GetItemText_x                                    0x906B40
#define CListWnd__GetSelList_x                                     0x90A400
#define CListWnd__GetSeparatorRect_x                               0x907B60
#define CListWnd__InsertLine_x                                     0x909F60
#define CListWnd__RemoveLine_x                                     0x90A0B0
#define CListWnd__SetColors_x                                      0x909310
#define CListWnd__SetColumnJustification_x                         0x909040
#define CListWnd__SetColumnWidth_x                                 0x908F60
#define CListWnd__SetCurSel_x                                      0x90A1C0
#define CListWnd__SetItemColor_x                                   0x90A9B0
#define CListWnd__SetItemData_x                                    0x90A970
#define CListWnd__SetItemText_x                                    0x90A580
#define CListWnd__ShiftColumnSeparator_x                           0x909100
#define CListWnd__Sort_x                                           0x908E00
#define CListWnd__ToggleSel_x                                      0x90A1F0
#define CListWnd__SetColumnsSizable_x                              0x9091A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76C530
#define CMapViewWnd__GetWorldCoordinates_x                         0x76AC40
#define CMapViewWnd__HandleLButtonDown_x                           0x767CA0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78F590
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78FE70
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7903A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7931F0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78DF50
#define CMerchantWnd__SelectBuySellSlot_x                          0x798DE0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78F1B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x899570
#define CPacketScrambler__hton_x                                   0x899560

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x923EB0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9242C0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9240B0
#define CSidlManager__CreateLabel_x                                0x7F0FD0
#define CSidlManager__CreateXWndFromTemplate_x                     0x927390
#define CSidlManager__CreateXWndFromTemplate1_x                    0x927570
#define CSidlManager__CreateXWnd_x                                 0x7F0F00
#define CSidlManager__CreateHotButtonWnd_x                         0x7F14C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x920A10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x920910
#define CSidlScreenWnd__ConvertToRes_x                             0x945BC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9203A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x920090
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x920160
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x920230
#define CSidlScreenWnd__DrawSidlPiece_x                            0x920EA0
#define CSidlScreenWnd__EnableIniStorage_x                         0x921370
#define CSidlScreenWnd__GetSidlPiece_x                             0x921090
#define CSidlScreenWnd__Init1_x                                    0x91FC80
#define CSidlScreenWnd__LoadIniInfo_x                              0x9213C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x921F20
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91F090
#define CSidlScreenWnd__StoreIniInfo_x                             0x921A90
#define CSidlScreenWnd__StoreIniVis_x                              0x921E00
#define CSidlScreenWnd__WndNotification_x                          0x920DB0
#define CSidlScreenWnd__GetChildItem_x                             0x9212F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x910C20
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B83B0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66A800
#define CSkillMgr__GetSkillCap_x                                   0x66A9E0
#define CSkillMgr__GetNameToken_x                                  0x669F90
#define CSkillMgr__IsActivatedSkill_x                              0x66A0D0
#define CSkillMgr__IsCombatSkill_x                                 0x66A010

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x930F20
#define CSliderWnd__SetValue_x                                     0x930D90
#define CSliderWnd__SetNumTicks_x                                  0x930DF0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F70F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x937D20
#define CStmlWnd__CalculateHSBRange_x                              0x938DB0
#define CStmlWnd__CalculateVSBRange_x                              0x938D20
#define CStmlWnd__CanBreakAtCharacter_x                            0x93D120
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93DDB0
#define CStmlWnd__ForceParseNow_x                                  0x9382C0
#define CStmlWnd__GetNextTagPiece_x                                0x93D080
#define CStmlWnd__GetSTMLText_x                                    0x4F5850
#define CStmlWnd__GetVisibleText_x                                 0x9382E0
#define CStmlWnd__InitializeWindowVariables_x                      0x93DC00
#define CStmlWnd__MakeStmlColorTag_x                               0x937400
#define CStmlWnd__MakeWndNotificationTag_x                         0x937470
#define CStmlWnd__SetSTMLText_x                                    0x9364B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x93EF00
#define CStmlWnd__UpdateHistoryString_x                            0x93DFC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x942B80
#define CTabWnd__DrawCurrentPage_x                                 0x9431A0
#define CTabWnd__DrawTab_x                                         0x942F70
#define CTabWnd__GetCurrentPage_x                                  0x9423E0
#define CTabWnd__GetPageInnerRect_x                                0x942620
#define CTabWnd__GetTabInnerRect_x                                 0x942560
#define CTabWnd__GetTabRect_x                                      0x942410
#define CTabWnd__InsertPage_x                                      0x942810
#define CTabWnd__SetPage_x                                         0x9426A0
#define CTabWnd__SetPageRect_x                                     0x942AC0
#define CTabWnd__UpdatePage_x                                      0x942E30
#define CTabWnd__GetPageFromTabIndex_x                             0x942EB0
#define CTabWnd__GetCurrentTabIndex_x                              0x9423D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x751710
#define CPageWnd__SetTabText_x                                     0x94F190

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6AD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90DA80
#define CTextureFont__GetTextExtent_x                              0x90DC40

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69E710
#define CHtmlComponentWnd__ValidateUri_x                           0x730140
#define CHtmlWnd__SetClientCallbacks_x                             0x60B290
#define CHtmlWnd__AddObserver_x                                    0x60B2B0
#define CHtmlWnd__RemoveObserver_x                                 0x60B310
#define Window__getProgress_x                                      0x849B90
#define Window__getStatus_x                                        0x849BB0
#define Window__getURI_x                                           0x849BC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94B710

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FA940

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AE140
#define CXStr__CXStr1_x                                            0x9BD2A0
#define CXStr__CXStr3_x                                            0x8E6C70
#define CXStr__dCXStr_x                                            0x473070
#define CXStr__operator_equal_x                                    0x8E6EA0
#define CXStr__operator_equal1_x                                   0x8E6EE0
#define CXStr__operator_plus_equal1_x                              0x8E7970

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92F1A0
#define CXWnd__BringToTop_x                                        0x9142D0
#define CXWnd__Center_x                                            0x913E50
#define CXWnd__ClrFocus_x                                          0x913C90
#define CXWnd__Destroy_x                                           0x913D40
#define CXWnd__DoAllDrawing_x                                      0x9103B0
#define CXWnd__DrawChildren_x                                      0x910380
#define CXWnd__DrawColoredRect_x                                   0x910810
#define CXWnd__DrawTooltip_x                                       0x90EED0
#define CXWnd__DrawTooltipAtPoint_x                                0x90EF90
#define CXWnd__GetBorderFrame_x                                    0x910670
#define CXWnd__GetChildWndAt_x                                     0x914370
#define CXWnd__GetClientClipRect_x                                 0x912600
#define CXWnd__GetScreenClipRect_x                                 0x9126D0
#define CXWnd__GetScreenRect_x                                     0x912860
#define CXWnd__GetTooltipRect_x                                    0x910860
#define CXWnd__GetWindowTextA_x                                    0x498070
#define CXWnd__IsActive_x                                          0x9171C0
#define CXWnd__IsDescendantOf_x                                    0x913250
#define CXWnd__IsReallyVisible_x                                   0x913280
#define CXWnd__IsType_x                                            0x9149D0
#define CXWnd__Move_x                                              0x9132E0
#define CXWnd__Move1_x                                             0x913390
#define CXWnd__ProcessTransition_x                                 0x913E00
#define CXWnd__Refade_x                                            0x913650
#define CXWnd__Resize_x                                            0x9138B0
#define CXWnd__Right_x                                             0x914090
#define CXWnd__SetFocus_x                                          0x913C50
#define CXWnd__SetFont_x                                           0x913CC0
#define CXWnd__SetKeyTooltip_x                                     0x9147F0
#define CXWnd__SetMouseOver_x                                      0x9117B0
#define CXWnd__StartFade_x                                         0x913120
#define CXWnd__GetChildItem_x                                      0x9144E0
#define CXWnd__SetParent_x                                         0x912FF0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x946C90

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x917200
#define CXWndManager__DrawWindows_x                                0x917220
#define CXWndManager__GetKeyboardFlags_x                           0x9199A0
#define CXWndManager__HandleKeyboardMsg_x                          0x9195A0
#define CXWndManager__RemoveWnd_x                                  0x919BF0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91A120

// CDBStr
#define CDBStr__GetString_x                                        0x52D430

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9270
#define EQ_Character__Cur_HP_x                                     0x4CF5A0
#define EQ_Character__Cur_Mana_x                                   0x4D6D60
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BC190
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFD40
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFE90
#define EQ_Character__GetHPRegen_x                                 0x4DCCA0
#define EQ_Character__GetEnduranceRegen_x                          0x4DD2B0
#define EQ_Character__GetManaRegen_x                               0x4DD6F0
#define EQ_Character__Max_Endurance_x                              0x6310F0
#define EQ_Character__Max_HP_x                                     0x4CF3D0
#define EQ_Character__Max_Mana_x                                   0x630EF0
#define EQ_Character__doCombatAbility_x                            0x6335C0
#define EQ_Character__UseSkill_x                                   0x4DF500
#define EQ_Character__GetConLevel_x                                0x62A630
#define EQ_Character__IsExpansionFlag_x                            0x590940
#define EQ_Character__TotalEffect_x                                0x4C2800
#define EQ_Character__GetPCSpellAffect_x                           0x4BCD80
#define EQ_Character__SpellDuration_x                              0x4BC8B0
#define EQ_Character__FindItemByRecord_x                           0x4D4C50
#define EQ_Character__GetAdjustedSkill_x                           0x4D2380
#define EQ_Character__GetBaseSkill_x                               0x4D3320
#define EQ_Character__CanUseItem_x                                 0x4D7070

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B8580

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6475D0

//PcClient
#define PcClient__PcClient_x                                       0x627D70

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6F10
#define CCharacterListWnd__EnterWorld_x                            0x4B6950
#define CCharacterListWnd__Quit_x                                  0x4B6660
#define CCharacterListWnd__UpdateList_x                            0x4B6AE0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60C4C0
#define EQ_Item__CreateItemTagString_x                             0x892EF0
#define EQ_Item__IsStackable_x                                     0x897930
#define EQ_Item__GetImageNum_x                                     0x894950
#define EQ_Item__CreateItemClient_x                                0x60B690
#define EQ_Item__GetItemValue_x                                    0x895BD0
#define EQ_Item__ValueSellMerchant_x                               0x899100
#define EQ_Item__IsKeyRingItem_x                                   0x897280
#define EQ_Item__CanGoInBag_x                                      0x60C5E0
#define EQ_Item__IsEmpty_x                                         0x896DB0
#define EQ_Item__GetMaxItemCount_x                                 0x895FA0
#define EQ_Item__GetHeldItem_x                                     0x894820
#define EQ_Item__GetAugmentFitBySlot_x                             0x892840

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54B710
#define EQ_LoadingS__Array_x                                       0xBED130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x631A50
#define EQ_PC__GetAlternateAbilityId_x                             0x8A22E0
#define EQ_PC__GetCombatAbility_x                                  0x8A2950
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A29C0
#define EQ_PC__GetItemRecastTimer_x                                0x633B40
#define EQ_PC__HasLoreItem_x                                       0x62ADF0
#define EQ_PC__AlertInventoryChanged_x                             0x629F70
#define EQ_PC__GetPcZoneClient_x                                   0x655D90
#define EQ_PC__RemoveMyAffect_x                                    0x636D60
#define EQ_PC__GetKeyRingItems_x                                   0x8A3260
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A2FE0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A3550

// EQItemList 
#define EQItemList__EQItemList_x                                   0x596DA0
#define EQItemList__add_object_x                                   0x5C2A70
#define EQItemList__add_item_x                                     0x5973B0
#define EQItemList__delete_item_x                                  0x597400
#define EQItemList__FreeItemList_x                                 0x597300

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52AA00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x648E50
#define EQPlayer__dEQPlayer_x                                      0x63C410
#define EQPlayer__DoAttack_x                                       0x650A50
#define EQPlayer__EQPlayer_x                                       0x63CAC0
#define EQPlayer__SetNameSpriteState_x                             0x640D50
#define EQPlayer__SetNameSpriteTint_x                              0x641C10
#define PlayerBase__HasProperty_j_x                                0x979B10
#define EQPlayer__IsTargetable_x                                   0x979FB0
#define EQPlayer__CanSee_x                                         0x979E10
#define EQPlayer__CanSee1_x                                        0x979EE0
#define PlayerBase__GetVisibilityLineSegment_x                     0x979BD0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x653820
#define PlayerZoneClient__GetLevel_x                               0x655DD0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C3BC0
#define PlayerZoneClient__LegalPlayerRace_x                        0x544B40

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64BB40
#define EQPlayerManager__GetSpawnByName_x                          0x64BB60
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64BBF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60FD50
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60FD90
#define KeypressHandler__ClearCommandStateArray_x                  0x611180
#define KeypressHandler__HandleKeyDown_x                           0x6111A0
#define KeypressHandler__HandleKeyUp_x                             0x611240
#define KeypressHandler__SaveKeymapping_x                          0x611620

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7683C0
#define MapViewMap__SaveEx_x                                       0x76B760
#define MapViewMap__SetZoom_x                                      0x76FE30

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B6470

// StringTable 
#define StringTable__getString_x                                   0x8B14D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6369D0
#define PcZoneClient__RemovePetEffect_x                            0x637000
#define PcZoneClient__HasAlternateAbility_x                        0x630D30
#define PcZoneClient__GetCurrentMod_x                              0x4E25F0
#define PcZoneClient__GetModCap_x                                  0x4E24F0
#define PcZoneClient__CanEquipItem_x                               0x6313E0
#define PcZoneClient__GetItemByID_x                                0x633FB0
#define PcZoneClient__GetItemByItemClass_x                         0x634100
#define PcZoneClient__RemoveBuffEffect_x                           0x637020
#define PcZoneClient__BandolierSwap_x                              0x632010
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x633AE0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C8750

//IconCache
#define IconCache__GetIcon_x                                       0x708BA0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7006A0
#define CContainerMgr__CloseContainer_x                            0x700970
#define CContainerMgr__OpenExperimentContainer_x                   0x7013F0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C36C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x604710

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75E840
#define CLootWnd__RequestLootSlot_x                                0x75DBF0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x563C40
#define EQ_Spell__SpellAffects_x                                   0x5640B0
#define EQ_Spell__SpellAffectBase_x                                0x563E70
#define EQ_Spell__IsStackable_x                                    0x4C6FD0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6EB0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4250
#define EQ_Spell__IsSPAStacking_x                                  0x564EE0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x564400
#define EQ_Spell__IsNoRemove_x                                     0x4C6FB0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x564EF0
#define __IsResEffectSpell_x                                       0x4C6360

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAAF0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C0B00

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x808F60
#define CTargetWnd__WndNotification_x                              0x8087F0
#define CTargetWnd__RefreshTargetBuffs_x                           0x808AC0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x807940

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80D630

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x528420
#define CTaskManager__HandleMessage_x                              0x526B90

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55F1F0
#define EqSoundManager__PlayScriptMp3_x                            0x55F350
#define EqSoundManager__SoundAssistPlay_x                          0x66E830
#define EqSoundManager__WaveInstancePlay_x                         0x66DDA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51C430

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x932900

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5534D0
#define CAltAbilityData__GetMercMaxRank_x                          0x553470
#define CAltAbilityData__GetMaxRank_x                              0x548800

//CTargetRing
#define CTargetRing__Cast_x                                        0x602800

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6E90
#define CharacterBase__CreateItemGlobalIndex_x                     0x502830
#define CharacterBase__CreateItemIndex_x                           0x60A8D0
#define CharacterBase__GetItemPossession_x                         0x4B4100
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C9190
#define CharacterBase__GetEffectId_x                               0x4C6E40

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E8660
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E8E80

//messages
#define msg_spell_worn_off_x                                       0x588A10
#define msg_new_text_x                                             0x57D7F0
#define __msgTokenTextParam_x                                      0x58B080
#define msgTokenText_x                                             0x58B2D0

//SpellManager
#define SpellManager__vftable_x                                    0xAB4A40
#define SpellManager__SpellManager_x                               0x671B60
#define Spellmanager__LoadTextSpells_x                             0x672430
#define SpellManager__GetSpellByGroupAndRank_x                     0x671D30

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97DAE0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x502EE0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58EEC0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6235C0
#define ItemGlobalIndex__IsValidIndex_x                            0x502F40

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C1440
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C16C0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x757170

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x704E00
#define CCursorAttachment__Deactivate_x                            0x705DE0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9283B0
#define CSidlManagerBase__CreatePageWnd_x                          0x927BC0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x945230
#define CEQSuiteTextureLoader__GetTexture_x                        0x944EF0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FFDD0

//IString
#define IString__Append_x                                          0x4EFAB0

//Camera
#define CDisplay__cameraType_x                                     0xDC6B44
#define EverQuest__Cameras_x                                       0xE89854

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x508620
#define LootFiltersManager__GetItemFilterData_x                    0x507F20
#define LootFiltersManager__RemoveItemLootFilter_x                 0x507F50
#define LootFiltersManager__SetItemLootFilter_x                    0x508170

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B15B0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x983770
#define CResolutionHandler__GetWindowedStyle_x                     0x669220

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FD450

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3D10

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71D530
#define CGroupWnd__UpdateDisplay_x                                 0x71C890

//ItemBase
#define ItemBase__IsLore_x                                         0x8972E0
#define ItemBase__IsLoreEquipped_x                                 0x897350

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C2960
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C2B10
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C2B70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65E820
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6624A0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F5EA0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E5190
#define FactionManagerClient__HandleFactionMessage_x               0x4E5810
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E5E20
#define FactionManagerClient__GetMaxFaction_x                      0x4E5E70
#define FactionManagerClient__GetMinFaction_x                      0x4E5DF0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

