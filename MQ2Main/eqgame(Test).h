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
#define __ExpectedVersionDate                                     "Jul 13 2018"
#define __ExpectedVersionTime                                     "12:21:57"
#define __ActualVersionDate_x                                      0xABF5EC
#define __ActualVersionTime_x                                      0xABF5E0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x60A0C0
#define __MemChecker1_x                                            0x8DB4C0
#define __MemChecker2_x                                            0x698AE0
#define __MemChecker3_x                                            0x698A30
#define __MemChecker4_x                                            0x834EA0
#define __EncryptPad0_x                                            0xBF1498
#define __EncryptPad1_x                                            0xC4F628
#define __EncryptPad2_x                                            0xC024D0
#define __EncryptPad3_x                                            0xC020D0
#define __EncryptPad4_x                                            0xC403C0
#define __EncryptPad5_x                                            0xF0D0C8
#define __AC1_x                                                    0x7F1AD6
#define __AC2_x                                                    0x5C5D7F
#define __AC3_x                                                    0x5CCC0F
#define __AC4_x                                                    0x5D0A90
#define __AC5_x                                                    0x5D6CC0
#define __AC6_x                                                    0x5DB1F2
#define __AC7_x                                                    0x5C57F0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1AC5B4

// Direct Input
#define DI8__Main_x                                                0xF0D0EC
#define DI8__Keyboard_x                                            0xF0D0F0
#define DI8__Mouse_x                                               0xF0D0B0
#define DI8__Mouse_Copy_x                                          0xE6ADA4
#define DI8__Mouse_Check_x                                         0xF0DFB0
#define __AutoSkillArray_x                                         0xE6BCB4
#define __Attack_x                                                 0xF09A9B
#define __Autofire_x                                               0xF09A9C
#define __BindList_x                                               0xBE0088
#define g_eqCommandStates_x                                        0xBE0DF8
#define __Clicks_x                                                 0xE6AE5C
#define __CommandList_x                                            0xBE19B0
#define __CurrentMapLabel_x                                        0x101F6D4
#define __CurrentSocial_x                                          0xBCB710
#define __DoAbilityList_x                                          0xEA15BC
#define __do_loot_x                                                0x5932B0
#define __DrawHandler_x                                            0x169ABE8
#define __GroupCount_x                                             0xE5B062
#define __Guilds_x                                                 0xE615B0
#define __gWorld_x                                                 0xE5B3AC
#define __HWnd_x                                                   0xF0D0B4
#define __heqmain_x                                                0x101830C
#define __InChatMode_x                                             0xE6AD8C
#define __LastTell_x                                               0xE6CCB8
#define __LMouseHeldTime_x                                         0xE6AEC8
#define __Mouse_x                                                  0xF0D0D4
#define __MouseLook_x                                              0xE6AE22
#define __MouseEventTime_x                                         0xF0A550
#define __gpbCommandEvent_x                                        0xE5B2E4
#define __NetStatusToggle_x                                        0xE6AE25
#define __PCNames_x                                                0xE6C278
#define __RangeAttackReady_x                                       0xE6BF98
#define __RMouseHeldTime_x                                         0xE6AEC4
#define __RunWalkState_x                                           0xE6AD90
#define __ScreenMode_x                                             0xDA9944
#define __ScreenX_x                                                0xE6AD44
#define __ScreenY_x                                                0xE6AD40
#define __ScreenXMax_x                                             0xE6AD48
#define __ScreenYMax_x                                             0xE6AD4C
#define __ServerHost_x                                             0xE5B4B3
#define __ServerName_x                                             0xEA157C
#define __ShiftKeyDown_x                                           0xE6B41C
#define __ShowNames_x                                              0xE6C150
#define __Socials_x                                                0xEA167C
#define __SubscriptionType_x                                       0x106119C
#define __TargetAggroHolder_x                                      0x102208C
#define __ZoneType_x                                               0xE6B220
#define __GroupAggro_x                                             0x10220CC
#define __LoginName_x                                              0xF0D944
#define __Inviter_x                                                0xF09A18
#define __AttackOnAssist_x                                         0xE6C10C
#define __UseTellWindows_x                                         0xE6C410
#define __gfMaxZoomCameraDistance_x                                0xAB4B28
#define __gfMaxCameraDistance_x                                    0xAE1F60
#define __pulAutoRun_x                                             0xE6AE40
#define __pulForward_x                                             0xE6C448
#define __pulBackward_x                                            0xE6C44C
#define __pulTurnRight_x                                           0xE6C450
#define __pulTurnLeft_x                                            0xE6C454
#define __pulStrafeLeft_x                                          0xE6C458
#define __pulStrafeRight_x                                         0xE6C45C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5D958
#define instEQZoneInfo_x                                           0xE6B018
#define instKeypressHandler_x                                      0xF0A500
#define pinstActiveBanker_x                                        0xE5D900
#define pinstActiveCorpse_x                                        0xE5D8F8
#define pinstActiveGMaster_x                                       0xE5D8FC
#define pinstActiveMerchant_x                                      0xE5D8F4
#define pinstAggroInfo_x                                           0xC65CF8
#define pinstAltAdvManager_x                                       0xDAA2F8
#define pinstAuraMgr_x                                             0xC769E0
#define pinstBandageTarget_x                                       0xE5D910
#define pinstCamActor_x                                            0xDA9924
#define pinstCDBStr_x                                              0xDA904C
#define pinstCDisplay_x                                            0xE5B04C
#define pinstCEverQuest_x                                          0xF0D208
#define pinstEverQuestInfo_x                                       0xE6AD38
#define pinstCharData_x                                            0xE5B25C
#define pinstCharSpawn_x                                           0xE5D948
#define pinstControlledMissile_x                                   0xE5B260
#define pinstControlledPlayer_x                                    0xE5D948
#define pinstCResolutionHandler_x                                  0x169AE18
#define pinstCSidlManager_x                                        0x1699CAC
#define pinstCXWndManager_x                                        0x1699CA0
#define instDynamicZone_x                                          0xE61488
#define pinstDZMember_x                                            0xE61598
#define pinstDZTimerInfo_x                                         0xE6159C
#define pinstEQItemList_x                                          0xE59B48
#define pinstEQObjectList_x                                        0xE5AD38
#define instEQMisc_x                                               0xDA8F88
#define pinstEQSoundManager_x                                      0xDAAB58
#define pinstEQSpellStrings_x                                      0xC73E30
#define instExpeditionLeader_x                                     0xE614D2
#define instExpeditionName_x                                       0xE61512
#define pinstGroup_x                                               0xE5B05E
#define pinstImeManager_x                                          0x1699CA4
#define pinstLocalPlayer_x                                         0xE5D8F0
#define pinstMercenaryData_x                                       0xF0ACF0
#define pinstMercenaryStats_x                                      0x10221D8
#define pinstMercAltAbilities_x                                    0xDAA8C8
#define pinstModelPlayer_x                                         0xE5D908
#define pinstPCData_x                                              0xE5B25C
#define pinstRealEstateItems_x                                     0xF0C1E0
#define pinstSkillMgr_x                                            0xF0C2B0
#define pinstSpawnManager_x                                        0xF0B8A0
#define pinstSpellManager_x                                        0xF0C518
#define pinstSpellSets_x                                           0xF026C4
#define pinstStringTable_x                                         0xE5B7C4
#define pinstSwitchManager_x                                       0xE5AEF8
#define pinstTarget_x                                              0xE5D944
#define pinstTargetObject_x                                        0xE5D950
#define pinstTargetSwitch_x                                        0xE5B268
#define pinstTaskMember_x                                          0xDA8E18
#define pinstTrackTarget_x                                         0xE5D94C
#define pinstTradeTarget_x                                         0xE5D904
#define instTributeActive_x                                        0xDA8FAD
#define pinstViewActor_x                                           0xDA991C
#define pinstWorldData_x                                           0xE5B2DC
#define pinstZoneAddr_x                                            0xE6B2B8
#define pinstPlayerPath_x                                          0xF0B938
#define pinstTargetIndicator_x                                     0xF0C780
#define pinstCTargetManager_x                                      0xF0C818
#define EQObject_Top_x                                             0xE5D8EC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDA9174
#define pinstCAchievementsWnd_x                                    0xDA9418
#define pinstCActionsWnd_x                                         0xDA93D0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDA915C
#define pinstCAdvancedLootWnd_x                                    0xDA9104
#define pinstCAdventureLeaderboardWnd_x                            0x1018EA8
#define pinstCAdventureRequestWnd_x                                0x1018F58
#define pinstCAdventureStatsWnd_x                                  0x1019008
#define pinstCAggroMeterWnd_x                                      0xDA943C
#define pinstCAlarmWnd_x                                           0xDA93FC
#define pinstCAlertHistoryWnd_x                                    0xDA93D8
#define pinstCAlertStackWnd_x                                      0xDA9170
#define pinstCAlertWnd_x                                           0xDA9384
#define pinstCAltStorageWnd_x                                      0x1019368
#define pinstCAudioTriggersWindow_x                                0xC66188
#define pinstCAuraWnd_x                                            0xDA9438
#define pinstCAvaZoneWnd_x                                         0xDA93B8
#define pinstCBandolierWnd_x                                       0xDA947C
#define pinstCBankWnd_x                                            0xDA9108
#define pinstCBarterMerchantWnd_x                                  0x101A5A8
#define pinstCBarterSearchWnd_x                                    0x101A658
#define pinstCBarterWnd_x                                          0x101A708
#define pinstCBazaarConfirmationWnd_x                              0xDA9168
#define pinstCBazaarSearchWnd_x                                    0xDA93E8
#define pinstCBazaarWnd_x                                          0xDA9474
#define pinstCBlockedBuffWnd_x                                     0xDA90F0
#define pinstCBlockedPetBuffWnd_x                                  0xDA9114
#define pinstCBodyTintWnd_x                                        0xDA9390
#define pinstCBookWnd_x                                            0xDA9904
#define pinstCBreathWnd_x                                          0xDA9388
#define pinstCBuffWindowNORMAL_x                                   0xDA9960
#define pinstCBuffWindowSHORT_x                                    0xDA9964
#define pinstCBugReportWnd_x                                       0xDA9164
#define pinstCButtonWnd_x                                          0x1699E98
#define pinstCCastingWnd_x                                         0xDA9160
#define pinstCCastSpellWnd_x                                       0xDA93F8
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDA9394
#define pinstCChatWindowManager_x                                  0x101B1C8
#define pinstCClaimWnd_x                                           0x101B320
#define pinstCColorPickerWnd_x                                     0xDA93A8
#define pinstCCombatAbilityWnd_x                                   0xDA9448
#define pinstCCombatSkillsSelectWnd_x                              0xDA93CC
#define pinstCCompassWnd_x                                         0xDA917C
#define pinstCConfirmationDialog_x                                 0x1020220
#define pinstCContainerMgr_x                                       0xDA946C
#define pinstCContextMenuManager_x                                 0x1699C60
#define pinstCCursorAttachment_x                                   0xDA9154
#define pinstCDynamicZoneWnd_x                                     0x101B8E8
#define pinstCEditLabelWnd_x                                       0xDA9910
#define pinstCEQMainWnd_x                                          0x101BB30
#define pinstCEventCalendarWnd_x                                   0xDA9434
#define pinstCExtendedTargetWnd_x                                  0xDA9430
#define pinstCFacePick_x                                           0xDA93B0
#define pinstCFellowshipWnd_x                                      0x101BD30
#define pinstCFileSelectionWnd_x                                   0xDA90EC
#define pinstCFindItemWnd_x                                        0xDA9460
#define pinstCFindLocationWnd_x                                    0x101BE88
#define pinstCFriendsWnd_x                                         0xDA93EC
#define pinstCGemsGameWnd_x                                        0xDA93D4
#define pinstCGiveWnd_x                                            0xDA9900
#define pinstCGroupSearchFiltersWnd_x                              0xDA9458
#define pinstCGroupSearchWnd_x                                     0x101C280
#define pinstCGroupWnd_x                                           0x101C330
#define pinstCGuildBankWnd_x                                       0xE6C0F4
#define pinstCGuildCreationWnd_x                                   0x101C490
#define pinstCGuildMgmtWnd_x                                       0x101C540
#define pinstCharacterCreation_x                                   0xDA9440
#define pinstCHelpWnd_x                                            0xDA9408
#define pinstCHeritageSelectionWnd_x                               0xDA93BC
#define pinstCHotButtonWnd_x                                       0x101E698
#define pinstCHotButtonWnd1_x                                      0x101E698
#define pinstCHotButtonWnd2_x                                      0x101E69C
#define pinstCHotButtonWnd3_x                                      0x101E6A0
#define pinstCHotButtonWnd4_x                                      0x101E6A4
#define pinstCIconSelectionWnd_x                                   0xDA9124
#define pinstCInspectWnd_x                                         0xDA9120
#define pinstCInventoryWnd_x                                       0xDA948C
#define pinstCInvSlotMgr_x                                         0xDA9420
#define pinstCItemDisplayManager_x                                 0x101EC28
#define pinstCItemExpTransferWnd_x                                 0x101ED58
#define pinstCItemOverflowWnd_x                                    0xDA93F0
#define pinstCJournalCatWnd_x                                      0xDA9118
//#define pinstCJournalNPCWnd_x                                      0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDA9958
#define pinstCKeyRingWnd_x                                         0xDA996C
#define pinstCLargeDialogWnd_x                                     0x1020EA0
#define pinstCLayoutCopyWnd_x                                      0x101F0A8
#define pinstCLFGuildWnd_x                                         0x101F158
#define pinstCLoadskinWnd_x                                        0xDA93E4
#define pinstCLootFiltersCopyWnd_x                                 0xC771C0
#define pinstCLootFiltersWnd_x                                     0xDA9398
#define pinstCLootSettingsWnd_x                                    0xDA93A4
#define pinstCLootWnd_x                                            0xDA93A0
#define pinstCMailAddressBookWnd_x                                 0xDA912C
#define pinstCMailCompositionWnd_x                                 0xDA910C
#define pinstCMailIgnoreListWnd_x                                  0xDA9130
#define pinstCMailWnd_x                                            0xDA9970
#define pinstCManageLootWnd_x                                      0xDAA770
#define pinstCMapToolbarWnd_x                                      0xDA94F4
#define pinstCMapViewWnd_x                                         0xDA9464
#define pinstCMarketplaceWnd_x                                     0xDA9468
#define pinstCMerchantWnd_x                                        0xDA93C8
#define pinstCMIZoneSelectWnd_x                                    0x101F990
#define pinstCMusicPlayerWnd_x                                     0xDA9968
#define pinstCNameChangeMercWnd_x                                  0xDA9110
#define pinstCNameChangePetWnd_x                                   0xDA90E8
#define pinstCNameChangeWnd_x                                      0xDA9444
#define pinstCNoteWnd_x                                            0xDA9404
#define pinstCObjectPreviewWnd_x                                   0xDA990C
#define pinstCOptionsWnd_x                                         0xDA94F8
#define pinstCPetInfoWnd_x                                         0xDA90FC
#define pinstCPetitionQWnd_x                                       0xDA9128
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDA938C
#define pinstCPlayerWnd_x                                          0xDA93F4
#define pinstCPopupWndManager_x                                    0x1020220
#define pinstCProgressionSelectionWnd_x                            0x10202D0
#define pinstCPurchaseGroupWnd_x                                   0xDA9974
#define pinstCPurchaseWnd_x                                        0xDA9950
#define pinstCPvPLeaderboardWnd_x                                  0x1020380
#define pinstCPvPStatsWnd_x                                        0x1020430
#define pinstCQuantityWnd_x                                        0xDA9140
#define pinstCRaceChangeWnd_x                                      0xDA9470
#define pinstCRaidOptionsWnd_x                                     0xDA945C
#define pinstCRaidWnd_x                                            0xDA9148
#define pinstCRealEstateItemsWnd_x                                 0xDA9424
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA9450
#define pinstCRealEstateManageWnd_x                                0xDA93C0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDA93DC
#define pinstCRealEstatePlotSearchWnd_x                            0xDA9400
#define pinstCRealEstatePurchaseWnd_x                              0xDA940C
#define pinstCRespawnWnd_x                                         0xDA9454
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDA942C
#define pinstCSendMoneyWnd_x                                       0xDA9954
#define pinstCServerListWnd_x                                      0xDA941C
#define pinstCSkillsSelectWnd_x                                    0xDA93AC
#define pinstCSkillsWnd_x                                          0xDA939C
#define pinstCSocialEditWnd_x                                      0xDA914C
#define pinstCSocialWnd_x                                          0xDA9150
#define pinstCSpellBookWnd_x                                       0xDA9428
#define pinstCStoryWnd_x                                           0xDA916C
#define pinstCTargetOfTargetWnd_x                                  0x1022260
#define pinstCTargetWnd_x                                          0xDA90F8
#define pinstCTaskOverlayWnd_x                                     0xDA93E0
#define pinstCTaskSelectWnd_x                                      0x10223B8
#define pinstCTaskSomething_x                                      0xC779C0
#define pinstCTaskTemplateSelectWnd_x                              0x1022468
#define pinstCTaskWnd_x                                            0x1022518
#define pinstCTextEntryWnd_x                                       0xDA9380
#define pinstCTextOverlay_x                                        0xC66498
#define pinstCTimeLeftWnd_x                                        0xDA9100
#define pinstCTipWndCONTEXT_x                                      0x102271C
#define pinstCTipWndOFDAY_x                                        0x1022718
#define pinstCTitleWnd_x                                           0x10227C8
#define pinstCTrackingWnd_x                                        0xDA90F4
#define pinstCTradeskillWnd_x                                      0x1022930
#define pinstCTradeWnd_x                                           0xDA9410
#define pinstCTrainWnd_x                                           0xDA9134
#define pinstCTributeBenefitWnd_x                                  0x1022B30
#define pinstCTributeMasterWnd_x                                   0x1022BE0
#define pinstCTributeTrophyWnd_x                                   0x1022C90
#define pinstCVideoModesWnd_x                                      0xDA911C
#define pinstCVoiceMacroWnd_x                                      0xF0CD48
#define pinstCVoteResultsWnd_x                                     0xDA995C
#define pinstCVoteWnd_x                                            0xDA9908
#define pinstCWebManager_x                                         0xF0CEAC
#define pinstCZoneGuideWnd_x                                       0xDA93B4
#define pinstCZonePathWnd_x                                        0xDA93C4

#define pinstEQSuiteTextureLoader_x                                0xC510E0
#define pinstItemIconCache_x                                       0x101BAE8
#define pinstLootFiltersManager_x                                  0xC77270
#define pinstRewardSelectionWnd_x                                  0x1020B78

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC020C4
#define __CastRay_x                                                0x58E7D0
#define __CastRay2_x                                               0x58E820
#define __ConvertItemTags_x                                        0x5A9540
#define __CrashHandler_x                                           0x83E800
#define __EQGetTime_x                                              0x8DADF0
#define __ExecuteCmd_x                                             0x587130
#define __FixHeading_x                                             0x96B760
#define __get_bearing_x                                            0x58E310
#define __get_melee_range_x                                        0x58EA10
#define __GetAnimationCache_x                                      0x6FC2D0
#define __GetGaugeValueFromEQ_x                                    0x7F02F0
#define __GetLabelFromEQ_x                                         0x7F1A60
#define __GetXTargetType_x                                         0x96D230
#define __HeadingDiff_x                                            0x96B7D0
#define __HelpPath_x                                               0xF0A16C
#define __LoadFrontEnd_x                                           0x694940
#define __NewUIINI_x                                               0x7EFFC0
#define __pCrashHandler_x                                          0x103FFF8
#define __ProcessGameEvents_x                                      0x5EBBC0
#define __ProcessMouseEvent_x                                      0x5EB380
#define __SaveColors_x                                             0x5384E0
#define __STMLToText_x                                             0x90ECD0
#define __ToggleKeyRingItem_x                                      0x4FB7F0
#define CrashDetected_x                                            0x696430
#define DrawNetStatus_x                                            0x617730
#define Expansion_HoT_x                                            0xE6C0FC
#define Teleport_Table_Size_x                                      0xE5B36C
#define Teleport_Table_x                                           0xE5B7C8
#define Util__FastTime_x                                           0x8DA9B0
#define wwsCrashReportCheckForUploader_x                           0x83F620
#define wwsCrashReportPlatformLaunchUploader_x                     0x841D00
#define __HandleMouseWheel_x                                       0x698B90

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AB10
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493910
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4936F0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53FC50
#define AltAdvManager__IsAbilityReady_x                            0x53ED10
#define AltAdvManager__GetAAById_x                                 0x53EF10
#define AltAdvManager__CanTrainAbility_x                           0x53EF80
#define AltAdvManager__CanSeeAbility_x                             0x53F1B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6580
#define CharacterZoneClient__HasSkill_x                            0x4D1120
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2840
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA810
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B6EB0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4F80
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5060
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5140
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF440
#define CharacterZoneClient__BardCastBard_x                        0x4C20C0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B6F80
#define CharacterZoneClient__GetEffect_x                           0x4B6DF0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0450
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0520
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0570
#define CharacterZoneClient__CalcAffectChange_x                    0x4C06C0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0890

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BEBB0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CC670

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F9F60
#define CButtonWnd__CButtonWnd_x                                   0x90B0D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EAD10
#define CChatManager__InitContextMenu_x                            0x6E5070
#define CChatManager__FreeChatWindow_x                             0x6E9C60
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EE5A0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EAAB0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x91F920
#define CContextMenu__dCContextMenu_x                              0x91FB50
#define CContextMenu__AddMenuItem_x                                0x91FB60
#define CContextMenu__RemoveMenuItem_x                             0x91FE70
#define CContextMenu__RemoveAllMenuItems_x                         0x91FE90
#define CContextMenu__CheckMenuItem_x                              0x91FF10
#define CContextMenu__SetMenuItem_x                                0x91FD90

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9204B0
#define CContextMenuManager__RemoveMenu_x                          0x920520
#define CContextMenuManager__PopupMenu_x                           0x9205E0
#define CContextMenuManager__Flush_x                               0x920450
#define CContextMenuManager__GetMenu_x                             0x4959A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BCC10
#define CChatService__GetFriendName_x                              0x8BCC20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EB280
#define CChatWindow__Clear_x                                       0x6EC2D0
#define CChatWindow__WndNotification_x                             0x6EC830

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91CDB0
#define CComboWnd__Draw_x                                          0x91C2B0
#define CComboWnd__GetCurChoice_x                                  0x91CBF0
#define CComboWnd__GetListRect_x                                   0x91C760
#define CComboWnd__GetTextRect_x                                   0x91CE20
#define CComboWnd__InsertChoice_x                                  0x91C8F0
#define CComboWnd__SetColors_x                                     0x91C8C0
#define CComboWnd__SetChoice_x                                     0x91CBC0
#define CComboWnd__GetItemCount_x                                  0x91CC00
#define CComboWnd__GetCurChoiceText_x                              0x91CC40

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F44C0
#define CContainerWnd__vftable_x                                   0xAC89D8
#define CContainerWnd__SetContainer_x                              0x6F5A30

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5382A0
#define CDisplay__GetClickedActor_x                                0x52B2F0
#define CDisplay__GetUserDefinedColor_x                            0x5239F0
#define CDisplay__GetWorldFilePath_x                               0x52CD40
#define CDisplay__is3dON_x                                         0x527FE0
#define CDisplay__ReloadUI_x                                       0x532460
#define CDisplay__WriteTextHD2_x                                   0x527DC0
#define CDisplay__TrueDistance_x                                   0x52E9A0
#define CDisplay__SetViewActor_x                                   0x52AC40

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93F020

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x924010
#define CEditWnd__GetCharIndexPt_x                                 0x924F10
#define CEditWnd__GetDisplayString_x                               0x924DB0
#define CEditWnd__GetHorzOffset_x                                  0x923640
#define CEditWnd__GetLineForPrintableChar_x                        0x926050
#define CEditWnd__GetSelStartPt_x                                  0x9251C0
#define CEditWnd__GetSTMLSafeText_x                                0x924BD0
#define CEditWnd__PointFromPrintableChar_x                         0x925C80
#define CEditWnd__SelectableCharFromPoint_x                        0x925DF0
#define CEditWnd__SetEditable_x                                    0x925290

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DA720
#define CEverQuest__ClickedPlayer_x                                0x5CC9F0
#define CEverQuest__CreateTargetIndicator_x                        0x5E8EA0
#define CEverQuest__DeleteTargetIndicator_x                        0x5E8F30
#define CEverQuest__DoTellWindow_x                                 0x4E13C0
#define CEverQuest__OutputTextToLog_x                              0x4E15F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C22B0
#define CEverQuest__dsp_chat_x                                     0x4E1980
#define CEverQuest__trimName_x                                     0x5E5460
#define CEverQuest__Emote_x                                        0x5DAF30
#define CEverQuest__EnterZone_x                                    0x5D50B0
#define CEverQuest__GetBodyTypeDesc_x                              0x5DED00
#define CEverQuest__GetClassDesc_x                                 0x5DF340
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DF940
#define CEverQuest__GetDeityDesc_x                                 0x5E77F0
#define CEverQuest__GetLangDesc_x                                  0x5DFB00
#define CEverQuest__GetRaceDesc_x                                  0x5DF320
#define CEverQuest__InterpretCmd_x                                 0x5E7DC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C64A0
#define CEverQuest__LMouseUp_x                                     0x5C4820
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6D80
#define CEverQuest__RMouseUp_x                                     0x5C57B0
#define CEverQuest__SetGameState_x                                 0x5C2040
#define CEverQuest__UPCNotificationFlush_x                         0x5E5360
#define CEverQuest__IssuePetCommand_x                              0x5E0F00
#define CEverQuest__ReportSuccessfulHit_x                          0x5DBBD0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7063D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x706430
#define CGaugeWnd__Draw_x                                          0x705AD0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABE20
#define CGuild__GetGuildName_x                                     0x4AAE60
#define CGuild__GetGuildIndex_x                                    0x4AB1F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x721770

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72E660
#define CInvSlotMgr__MoveItem_x                                    0x72D380
#define CInvSlotMgr__SelectSlot_x                                  0x72E730

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72BC30
#define CInvSlot__SliderComplete_x                                 0x729A60
#define CInvSlot__GetItemBase_x                                    0x7293D0
#define CInvSlot__UpdateItem_x                                     0x729540

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x730080
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72F350
#define CInvSlotWnd__HandleLButtonUp_x                             0x72FC00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EC4C0
#define CItemDisplayWnd__UpdateStrings_x                           0x73ED30
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x738D20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x739210
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73F2C0
#define CItemDisplayWnd__AboutToShow_x                             0x73E980
#define CItemDisplayWnd__WndNotification_x                         0x7405E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x823BA0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x744600

// CLabel 
#define CLabel__Draw_x                                             0x74A090

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F55D0
#define CListWnd__dCListWnd_x                                      0x8F58F0
#define CListWnd__AddColumn_x                                      0x8F9C10
#define CListWnd__AddColumn1_x                                     0x8F9C60
#define CListWnd__AddLine_x                                        0x8F9FF0
#define CListWnd__AddString_x                                      0x8F9DF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8F99D0
#define CListWnd__CalculateVSBRange_x                              0x8F97B0
#define CListWnd__ClearSel_x                                       0x8FA7D0
#define CListWnd__ClearAllSel_x                                    0x8FA830
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FB230
#define CListWnd__Compare_x                                        0x8F90F0
#define CListWnd__Draw_x                                           0x8F59F0
#define CListWnd__DrawColumnSeparators_x                           0x8F81D0
#define CListWnd__DrawHeader_x                                     0x8F8630
#define CListWnd__DrawItem_x                                       0x8F8A30
#define CListWnd__DrawLine_x                                       0x8F8330
#define CListWnd__DrawSeparator_x                                  0x8F8270
#define CListWnd__EnableLine_x                                     0x8F7AB0
#define CListWnd__EnsureVisible_x                                  0x8FB150
#define CListWnd__ExtendSel_x                                      0x8FA700
#define CListWnd__GetColumnMinWidth_x                              0x8F75F0
#define CListWnd__GetColumnWidth_x                                 0x8F7560
#define CListWnd__GetCurSel_x                                      0x8F6EF0
#define CListWnd__GetItemAtPoint_x                                 0x8F7D20
#define CListWnd__GetItemAtPoint1_x                                0x8F7D90
#define CListWnd__GetItemData_x                                    0x8F6F70
#define CListWnd__GetItemHeight_x                                  0x8F7330
#define CListWnd__GetItemIcon_x                                    0x8F7100
#define CListWnd__GetItemRect_x                                    0x8F7BA0
#define CListWnd__GetItemText_x                                    0x8F6FB0
#define CListWnd__GetSelList_x                                     0x8FA880
#define CListWnd__GetSeparatorRect_x                               0x8F7FD0
#define CListWnd__InsertLine_x                                     0x8FA3E0
#define CListWnd__RemoveLine_x                                     0x8FA530
#define CListWnd__SetColors_x                                      0x8F9780
#define CListWnd__SetColumnJustification_x                         0x8F94B0
#define CListWnd__SetColumnWidth_x                                 0x8F93D0
#define CListWnd__SetCurSel_x                                      0x8FA640
#define CListWnd__SetItemColor_x                                   0x8FAE00
#define CListWnd__SetItemData_x                                    0x8FADC0
#define CListWnd__SetItemText_x                                    0x8FAA00
#define CListWnd__ShiftColumnSeparator_x                           0x8F9570
#define CListWnd__Sort_x                                           0x8F9270
#define CListWnd__ToggleSel_x                                      0x8FA670

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75F510

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x782740
#define CMerchantWnd__RequestBuyItem_x                             0x783020
#define CMerchantWnd__RequestSellItem_x                            0x783550
#define CMerchantWnd__SelectRecoverySlot_x                         0x786390
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x782DA0
#define CMerchantWnd__ActualSelect_x                               0x78BF00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88B090
#define CPacketScrambler__hton_x                                   0x88B080

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9142A0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9146B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9144A0
#define CSidlManager__CreateLabel_x                                0x7E39A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x917780
#define CSidlManager__CreateXWndFromTemplate1_x                    0x917960

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x910E40
#define CSidlScreenWnd__CalculateVSBRange_x                        0x910D40
#define CSidlScreenWnd__ConvertToRes_x                             0x935810
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9107E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9104D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9105A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x910670
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9112D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9117A0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9114C0
#define CSidlScreenWnd__Init1_x                                    0x9100C0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9117F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x912310
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90F4C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x911E90
#define CSidlScreenWnd__StoreIniVis_x                              0x9121F0
#define CSidlScreenWnd__WndNotification_x                          0x9111E0
#define CSidlScreenWnd__GetChildItem_x                             0x911720
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9010C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1699B30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65DCD0
#define CSkillMgr__GetSkillCap_x                                   0x65DEB0
#define CSkillMgr__GetNameToken_x                                  0x65D460

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x921290
#define CSliderWnd__SetValue_x                                     0x921100
#define CSliderWnd__SetNumTicks_x                                  0x921160

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E9740

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x927F00
#define CStmlWnd__CalculateHSBRange_x                              0x928F70
#define CStmlWnd__CalculateVSBRange_x                              0x928EE0
#define CStmlWnd__CanBreakAtCharacter_x                            0x92D2A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92DE90
#define CStmlWnd__ForceParseNow_x                                  0x9284A0
#define CStmlWnd__GetNextTagPiece_x                                0x92D200
#define CStmlWnd__GetSTMLText_x                                    0x4EF7B0
#define CStmlWnd__GetVisibleText_x                                 0x9284C0
#define CStmlWnd__InitializeWindowVariables_x                      0x92DCE0
#define CStmlWnd__MakeStmlColorTag_x                               0x927690
#define CStmlWnd__MakeWndNotificationTag_x                         0x927700
#define CStmlWnd__SetSTMLText_x                                    0x926760
#define CStmlWnd__StripFirstSTMLLines_x                            0x92EFF0
#define CStmlWnd__UpdateHistoryString_x                            0x92E0A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9326B0
#define CTabWnd__DrawCurrentPage_x                                 0x932CD0
#define CTabWnd__DrawTab_x                                         0x932AA0
#define CTabWnd__GetCurrentPage_x                                  0x931F10
#define CTabWnd__GetPageInnerRect_x                                0x932150
#define CTabWnd__GetTabInnerRect_x                                 0x932090
#define CTabWnd__GetTabRect_x                                      0x931F40
#define CTabWnd__InsertPage_x                                      0x932340
#define CTabWnd__SetPage_x                                         0x9321D0
#define CTabWnd__SetPageRect_x                                     0x9325F0
#define CTabWnd__UpdatePage_x                                      0x932960
#define CTabWnd__GetPageFromTabIndex_x                             0x9329E0
#define CTabWnd__GetCurrentTabIndex_x                              0x931F00

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x744A60
#define CPageWnd__SetTabText_x                                     0x93F430

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5970

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FDF50
#define CTextureFont__GetTextExtent_x                              0x8FE110

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6916E0
#define CHtmlComponentWnd__ValidateUri_x                           0x723160
#define CHtmlWnd__SetClientCallbacks_x                             0x5FF2B0
#define CHtmlWnd__AddObserver_x                                    0x5FF2D0
#define CHtmlWnd__RemoveObserver_x                                 0x5FF330
#define Window__getProgress_x                                      0x83C460
#define Window__getStatus_x                                        0x83C480
#define Window__getURI_x                                           0x83C490

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93B9B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8EAEB0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD140
#define CXStr__CXStr1_x                                            0x82CC30
#define CXStr__CXStr3_x                                            0x8D6ED0
#define CXStr__dCXStr_x                                            0x472530
#define CXStr__operator_equal_x                                    0x8D7100
#define CXStr__operator_equal1_x                                   0x8D7140
#define CXStr__operator_plus_equal1_x                              0x8D7BD0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91F530
#define CXWnd__BringToTop_x                                        0x904760
#define CXWnd__Center_x                                            0x9042E0
#define CXWnd__ClrFocus_x                                          0x904120
#define CXWnd__Destroy_x                                           0x9041C0
#define CXWnd__DoAllDrawing_x                                      0x900870
#define CXWnd__DrawChildren_x                                      0x900840
#define CXWnd__DrawColoredRect_x                                   0x900CC0
#define CXWnd__DrawTooltip_x                                       0x8FF3A0
#define CXWnd__DrawTooltipAtPoint_x                                0x8FF460
#define CXWnd__GetBorderFrame_x                                    0x900B20
#define CXWnd__GetChildWndAt_x                                     0x904800
#define CXWnd__GetClientClipRect_x                                 0x902AC0
#define CXWnd__GetScreenClipRect_x                                 0x902B90
#define CXWnd__GetScreenRect_x                                     0x902D30
#define CXWnd__GetTooltipRect_x                                    0x900D10
#define CXWnd__GetWindowTextA_x                                    0x497020
#define CXWnd__IsActive_x                                          0x907690
#define CXWnd__IsDescendantOf_x                                    0x9036E0
#define CXWnd__IsReallyVisible_x                                   0x903710
#define CXWnd__IsType_x                                            0x904E70
#define CXWnd__Move_x                                              0x903780
#define CXWnd__Move1_x                                             0x903830
#define CXWnd__ProcessTransition_x                                 0x904290
#define CXWnd__Refade_x                                            0x903AD0
#define CXWnd__Resize_x                                            0x903D60
#define CXWnd__Right_x                                             0x904520
#define CXWnd__SetFocus_x                                          0x9040E0
#define CXWnd__SetFont_x                                           0x904150
#define CXWnd__SetKeyTooltip_x                                     0x904C80
#define CXWnd__SetMouseOver_x                                      0x901C30
#define CXWnd__StartFade_x                                         0x9035B0
#define CXWnd__GetChildItem_x                                      0x904970
#define CXWnd__SetParent_x                                         0x903480

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9368E0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9076D0
#define CXWndManager__DrawWindows_x                                0x9076F0
#define CXWndManager__GetKeyboardFlags_x                           0x909DA0
#define CXWndManager__HandleKeyboardMsg_x                          0x9099B0
#define CXWndManager__RemoveWnd_x                                  0x909FF0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x90A550

// CDBStr
#define CDBStr__GetString_x                                        0x5229C0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7E60
#define EQ_Character__Cur_HP_x                                     0x4CE1A0
#define EQ_Character__Cur_Mana_x                                   0x4D5640
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BAFA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AED10
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEE60
#define EQ_Character__GetHPRegen_x                                 0x4DACF0
#define EQ_Character__GetEnduranceRegen_x                          0x4DB300
#define EQ_Character__GetManaRegen_x                               0x4DB740
#define EQ_Character__Max_Endurance_x                              0x624FD0
#define EQ_Character__Max_HP_x                                     0x4CDFD0
#define EQ_Character__Max_Mana_x                                   0x624DD0
#define EQ_Character__doCombatAbility_x                            0x627180
#define EQ_Character__UseSkill_x                                   0x4DD550
#define EQ_Character__GetConLevel_x                                0x61E410
#define EQ_Character__IsExpansionFlag_x                            0x585AF0
#define EQ_Character__TotalEffect_x                                0x4C1640
#define EQ_Character__GetPCSpellAffect_x                           0x4BBB90
#define EQ_Character__SpellDuration_x                              0x4BB6C0
#define EQ_Character__FindItemByRecord_x                           0x4D37B0
#define EQ_Character__GetAdjustedSkill_x                           0x4D0EE0
#define EQ_Character__GetBaseSkill_x                               0x4D1E80
#define EQ_Character__CanUseItem_x                                 0x4D5950

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8A9F80

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63AED0

//PcClient
#define PcClient__PcClient_x                                       0x61BCD0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5C40
#define CCharacterListWnd__EnterWorld_x                            0x4B5680
#define CCharacterListWnd__Quit_x                                  0x4B5390
#define CCharacterListWnd__UpdateList_x                            0x4B5810

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6004D0
#define EQ_Item__CreateItemTagString_x                             0x885420
#define EQ_Item__IsStackable_x                                     0x889590
#define EQ_Item__GetImageNum_x                                     0x886BD0
#define EQ_Item__CreateItemClient_x                                0x5FF6B0
#define EQ_Item__GetItemValue_x                                    0x887C90
#define EQ_Item__ValueSellMerchant_x                               0x88AC30
#define EQ_Item__IsKeyRingItem_x                                   0x888F60
#define EQ_Item__CanGoInBag_x                                      0x6005F0
#define EQ_Item__GetMaxItemCount_x                                 0x887D90
#define EQ_Item__GetHeldItem_x                                     0x886AA0
#define EQ_Item__GetAugmentFitBySlot_x                             0x884F80

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x540970
#define EQ_LoadingS__Array_x                                       0xBD9298

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x625930
#define EQ_PC__GetAlternateAbilityId_x                             0x893C00
#define EQ_PC__GetCombatAbility_x                                  0x894270
#define EQ_PC__GetCombatAbilityTimer_x                             0x8942E0
#define EQ_PC__GetItemRecastTimer_x                                0x627700
#define EQ_PC__HasLoreItem_x                                       0x61EB80
#define EQ_PC__AlertInventoryChanged_x                             0x61DEE0
#define EQ_PC__GetPcZoneClient_x                                   0x649710
#define EQ_PC__RemoveMyAffect_x                                    0x62A830
#define EQ_PC__GetKeyRingItems_x                                   0x894B80
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x894900
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x894E70

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58BD40
#define EQItemList__add_object_x                                   0x5B7930
#define EQItemList__add_item_x                                     0x58C350
#define EQItemList__delete_item_x                                  0x58C3A0
#define EQItemList__FreeItemList_x                                 0x58C2A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51FF10

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63C750
#define EQPlayer__dEQPlayer_x                                      0x62FE50
#define EQPlayer__DoAttack_x                                       0x644420
#define EQPlayer__EQPlayer_x                                       0x630500
#define EQPlayer__SetNameSpriteState_x                             0x6347C0
#define EQPlayer__SetNameSpriteTint_x                              0x635650
#define PlayerBase__HasProperty_j_x                                0x969B40
#define EQPlayer__IsTargetable_x                                   0x969FE0
#define EQPlayer__CanSee_x                                         0x969E40
#define EQPlayer__CanSee1_x                                        0x969F10
#define PlayerBase__GetVisibilityLineSegment_x                     0x969C00

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6471E0
#define PlayerZoneClient__GetLevel_x                               0x649750
#define PlayerZoneClient__IsValidTeleport_x                        0x5B8A90
#define PlayerZoneClient__LegalPlayerRace_x                        0x53A020

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63F550
#define EQPlayerManager__GetSpawnByName_x                          0x63F570
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63F600

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x603D40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x603D80
#define KeypressHandler__ClearCommandStateArray_x                  0x605170
#define KeypressHandler__HandleKeyDown_x                           0x605190
#define KeypressHandler__HandleKeyUp_x                             0x605230
#define KeypressHandler__SaveKeymapping_x                          0x605610

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75B3A0
#define MapViewMap__SaveEx_x                                       0x75E740
#define MapViewMap__SetZoom_x                                      0x762E00

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A7DC0

// StringTable 
#define StringTable__getString_x                                   0x8A2D50

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62A4A0
#define PcZoneClient__RemovePetEffect_x                            0x62AAD0
#define PcZoneClient__HasAlternateAbility_x                        0x624C10
#define PcZoneClient__GetCurrentMod_x                              0x4E04B0
#define PcZoneClient__GetModCap_x                                  0x4E03B0
#define PcZoneClient__CanEquipItem_x                               0x6252C0
#define PcZoneClient__GetItemByID_x                                0x627B70
#define PcZoneClient__GetItemByItemClass_x                         0x627C00
#define PcZoneClient__RemoveBuffEffect_x                           0x62AAF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BD6E0

//IconCache
#define IconCache__GetIcon_x                                       0x6FBB60

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F3660
#define CContainerMgr__CloseContainer_x                            0x6F3930
#define CContainerMgr__OpenExperimentContainer_x                   0x6F43B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B6370

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F8750

//CLootWnd
#define CLootWnd__LootAll_x                                        0x751840
#define CLootWnd__RequestLootSlot_x                                0x750BF0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x558D20
#define EQ_Spell__SpellAffects_x                                   0x559190
#define EQ_Spell__SpellAffectBase_x                                0x558F50
#define EQ_Spell__IsStackable_x                                    0x4C5EA0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5D20
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3230
#define EQ_Spell__IsSPAStacking_x                                  0x559F40
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5594E0
#define EQ_Spell__IsNoRemove_x                                     0x4C5E80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x559F50
#define __IsResEffectSpell_x                                       0x4C51B0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9AB0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B21C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FB830
#define CTargetWnd__WndNotification_x                              0x7FB0C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FB390
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FA220

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FFF00

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5542B0
#define EqSoundManager__PlayScriptMp3_x                            0x554410
#define EqSoundManager__SoundAssistPlay_x                          0x661870
#define EqSoundManager__WaveInstancePlay_x                         0x660D20

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x511870

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x922C70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x548510
#define CAltAbilityData__GetMercMaxRank_x                          0x5484B0
#define CAltAbilityData__GetMaxRank_x                              0x53DC40

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F6860

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5D00
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7D00
#define CharacterBase__CreateItemIndex_x                           0x5FE8C0
#define CharacterBase__GetItemPossession_x                         0x4B30E0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8BA730
#define CharacterBase__GetEffectId_x                               0x4C5CB0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DBB70
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DC390

//messages
#define msg_spell_worn_off_x                                       0x57E2A0
#define msg_new_text_x                                             0x573490
#define __msgTokenTextParam_x                                      0x5808F0
#define msgTokenText_x                                             0x580B40

//SpellManager
#define SpellManager__vftable_x                                    0xAA3840
#define SpellManager__SpellManager_x                               0x664B70
#define Spellmanager__LoadTextSpells_x                             0x6653D0
#define SpellManager__GetSpellByGroupAndRank_x                     0x664D40

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96DB20

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F83B0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x584050
#define ItemGlobalIndex__IsEquippedLocation_x                      0x617590
#define ItemGlobalIndex__IsValidIndex_x                            0x4F8410

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B2B00
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B2D80

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74A3E0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F7DB0
#define CCursorAttachment__Deactivate_x                            0x6F8D90

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x934CE0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9349A0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F5380

//IString
#define IString__Append_x                                          0x4E9840

//Camera
#define CDisplay__cameraType_x                                     0xDA9178
#define EverQuest__Cameras_x                                       0xE6C41C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FDA60
#define LootFiltersManager__GetItemFilterData_x                    0x4FD360
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FD390
#define LootFiltersManager__SetItemLootFilter_x                    0x4FD5B0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A43C0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x973940
#define CResolutionHandler__GetWindowedStyle_x                     0x65C840

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F0410

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
