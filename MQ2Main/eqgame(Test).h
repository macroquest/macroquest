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
#define __ExpectedVersionDate                                     "Oct  8 2018"
#define __ExpectedVersionTime                                     "17:02:39"
#define __ActualVersionDate_x                                      0xAC06DC
#define __ActualVersionTime_x                                      0xAC06D0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x609820
#define __MemChecker1_x                                            0x8DBC10
#define __MemChecker2_x                                            0x6980D0
#define __MemChecker3_x                                            0x698020
#define __MemChecker4_x                                            0x833D40
#define __EncryptPad0_x                                            0xBF24C0
#define __EncryptPad1_x                                            0xC501A0
#define __EncryptPad2_x                                            0xC03048
#define __EncryptPad3_x                                            0xC02C48
#define __EncryptPad4_x                                            0xC40F38
#define __EncryptPad5_x                                            0x1018E54
#define __AC1_x                                                    0x7F08E6
#define __AC2_x                                                    0x5C544F
#define __AC3_x                                                    0x5CC2DF
#define __AC4_x                                                    0x5D0150
#define __AC5_x                                                    0x5D630F
#define __AC6_x                                                    0x5DA846
#define __AC7_x                                                    0x5C4EC0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EBACDC

// Direct Input
#define DI8__Main_x                                                0x1018E74
#define DI8__Keyboard_x                                            0x1018E78
#define DI8__Mouse_x                                               0xF0DD30
#define DI8__Mouse_Copy_x                                          0xE6BA8C
#define DI8__Mouse_Check_x                                         0xF0EAE0
#define __AutoSkillArray_x                                         0xE6C9A4
#define __Attack_x                                                 0xF0A7A7
#define __Autofire_x                                               0xF0A7A8
#define __BindList_x                                               0xBE10C0
#define g_eqCommandStates_x                                        0xBE1E30
#define __Clicks_x                                                 0xE6BB44
#define __CommandList_x                                            0xBE29E8
#define __CurrentMapLabel_x                                        0x1020354
#define __CurrentSocial_x                                          0xBCC734
#define __DoAbilityList_x                                          0xEA22C8
#define __do_loot_x                                                0x592DA0
#define __DrawHandler_x                                            0x169B888
#define __GroupCount_x                                             0xE5BDBA
#define __Guilds_x                                                 0xE62298
#define __gWorld_x                                                 0xE5DFB4
#define __HWnd_x                                                   0xF0DD34
#define __heqmain_x                                                0x1018E3C
#define __InChatMode_x                                             0xE6BA74
#define __LastTell_x                                               0xE6D9C4
#define __LMouseHeldTime_x                                         0xE6BBB0
#define __Mouse_x                                                  0x1018E60
#define __MouseLook_x                                              0xE6BB0A
#define __MouseEventTime_x                                         0xF0B260
#define __gpbCommandEvent_x                                        0xE5E1CC
#define __NetStatusToggle_x                                        0xE6BB0D
#define __PCNames_x                                                0xE6CF84
#define __RangeAttackReady_x                                       0xE6CC88
#define __RMouseHeldTime_x                                         0xE6BBAC
#define __RunWalkState_x                                           0xE6BA78
#define __ScreenMode_x                                             0xDAA614
#define __ScreenX_x                                                0xE6BA2C
#define __ScreenY_x                                                0xE6BA28
#define __ScreenXMax_x                                             0xE6BA30
#define __ScreenYMax_x                                             0xE6BA34
#define __ServerHost_x                                             0xE5E31B
#define __ServerName_x                                             0xEA2288
#define __ShiftKeyDown_x                                           0xE6C104
#define __ShowNames_x                                              0xE6CE44
#define __Socials_x                                                0xEA2388
#define __SubscriptionType_x                                       0x1061E1C
#define __TargetAggroHolder_x                                      0x1022D0C
#define __ZoneType_x                                               0xE6BF08
#define __GroupAggro_x                                             0x1022D4C
#define __LoginName_x                                              0xF0E474
#define __Inviter_x                                                0xF0A724
#define __AttackOnAssist_x                                         0xE6CE00
#define __UseTellWindows_x                                         0xE6D11C
#define __gfMaxZoomCameraDistance_x                                0xAB5AD8
#define __gfMaxCameraDistance_x                                    0xAE3098
#define __pulAutoRun_x                                             0xE6BB28
#define __pulForward_x                                             0xE6D154
#define __pulBackward_x                                            0xE6D158
#define __pulTurnRight_x                                           0xE6D15C
#define __pulTurnLeft_x                                            0xE6D160
#define __pulStrafeLeft_x                                          0xE6D164
#define __pulStrafeRight_x                                         0xE6D168

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5E630
#define instEQZoneInfo_x                                           0xE6BD00
#define instKeypressHandler_x                                      0xF0B210
#define pinstActiveBanker_x                                        0xE5BD30
#define pinstActiveCorpse_x                                        0xE5BD28
#define pinstActiveGMaster_x                                       0xE5BD2C
#define pinstActiveMerchant_x                                      0xE5BD24
#define pinstAggroInfo_x                                           0xC669B8
#define pinstAltAdvManager_x                                       0xDAAFD0
#define pinstAuraMgr_x                                             0xC776A0
#define pinstBandageTarget_x                                       0xE5BD40
#define pinstCamActor_x                                            0xDAA608
#define pinstCDBStr_x                                              0xDA9D0C
#define pinstCDisplay_x                                            0xE5BD84
#define pinstCEverQuest_x                                          0x1018F90
#define pinstEverQuestInfo_x                                       0xE6BA20
#define pinstCharData_x                                            0xE5BD8C
#define pinstCharSpawn_x                                           0xE5BD78
#define pinstControlledMissile_x                                   0xE5BD90
#define pinstControlledPlayer_x                                    0xE5BD78
#define pinstCResolutionHandler_x                                  0x169BAB8
#define pinstCSidlManager_x                                        0x169A94C
#define pinstCXWndManager_x                                        0x169A940
#define instDynamicZone_x                                          0xE62170
#define pinstDZMember_x                                            0xE62280
#define pinstDZTimerInfo_x                                         0xE62284
#define pinstEQItemList_x                                          0xE5A820
#define pinstEQObjectList_x                                        0xE5BA10
#define instEQMisc_x                                               0xDA9C48
#define pinstEQSoundManager_x                                      0xDAB830
#define pinstEQSpellStrings_x                                      0xC74AF0
#define instExpeditionLeader_x                                     0xE621BA
#define instExpeditionName_x                                       0xE621FA
#define pinstGroup_x                                               0xE5BDB6
#define pinstImeManager_x                                          0x169A944
#define pinstLocalPlayer_x                                         0xE5BD20
#define pinstMercenaryData_x                                       0xF0BA00
#define pinstMercenaryStats_x                                      0x1022E58
#define pinstMercAltAbilities_x                                    0xDAB5A0
#define pinstModelPlayer_x                                         0xE5BD38
#define pinstPCData_x                                              0xE5BD8C
#define pinstRealEstateItems_x                                     0xF0CEF0
#define pinstSkillMgr_x                                            0xF0CFC0
#define pinstSpawnManager_x                                        0xF0C5B0
#define pinstSpellManager_x                                        0xF0D198
#define pinstSpellSets_x                                           0xF033D0
#define pinstStringTable_x                                         0xE5E01C
#define pinstSwitchManager_x                                       0xE5BBD0
#define pinstTarget_x                                              0xE5BD74
#define pinstTargetObject_x                                        0xE5BD80
#define pinstTargetSwitch_x                                        0xE5BD98
#define pinstTaskMember_x                                          0xDA9AD8
#define pinstTrackTarget_x                                         0xE5BD7C
#define pinstTradeTarget_x                                         0xE5BD34
#define instTributeActive_x                                        0xDA9C6D
#define pinstViewActor_x                                           0xDAA600
#define pinstWorldData_x                                           0xE5BDA4
#define pinstZoneAddr_x                                            0xE6BFA0
#define pinstPlayerPath_x                                          0xF0C648
#define pinstTargetIndicator_x                                     0xF0D400
#define pinstCTargetManager_x                                      0xF0D498
#define EQObject_Top_x                                             0xE5E424
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDAA594
#define pinstCAchievementsWnd_x                                    0xDA9DC8
#define pinstCActionsWnd_x                                         0xDAA5F4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDAA580
#define pinstCAdvancedLootWnd_x                                    0xDAA548
#define pinstCAdventureLeaderboardWnd_x                            0x1019B28
#define pinstCAdventureRequestWnd_x                                0x1019BD8
#define pinstCAdventureStatsWnd_x                                  0x1019C88
#define pinstCAggroMeterWnd_x                                      0xDA9E04
#define pinstCAlarmWnd_x                                           0xDA9DB4
#define pinstCAlertHistoryWnd_x                                    0xDAA634
#define pinstCAlertStackWnd_x                                      0xDAA5A8
#define pinstCAlertWnd_x                                           0xDAA5B8
#define pinstCAltStorageWnd_x                                      0x1019FE8
#define pinstCAudioTriggersWindow_x                                0xC66E48
#define pinstCAuraWnd_x                                            0xDA9DFC
#define pinstCAvaZoneWnd_x                                         0xDAA5F0
#define pinstCBandolierWnd_x                                       0xDAA040
#define pinstCBankWnd_x                                            0xDAA540
#define pinstCBarterMerchantWnd_x                                  0x101B228
#define pinstCBarterSearchWnd_x                                    0x101B2D8
#define pinstCBarterWnd_x                                          0x101B388
#define pinstCBazaarConfirmationWnd_x                              0xDAA5A0
#define pinstCBazaarSearchWnd_x                                    0xDAA620
#define pinstCBazaarWnd_x                                          0xDAA03C
#define pinstCBlockedBuffWnd_x                                     0xDAA524
#define pinstCBlockedPetBuffWnd_x                                  0xDAA54C
#define pinstCBodyTintWnd_x                                        0xDAA5B4
#define pinstCBookWnd_x                                            0xDAA064
#define pinstCBreathWnd_x                                          0xDAA5A4
#define pinstCBuffWindowNORMAL_x                                   0xDAA4E8
#define pinstCBuffWindowSHORT_x                                    0xDAA4EC
#define pinstCBugReportWnd_x                                       0xDAA58C
#define pinstCButtonWnd_x                                          0x169AB38
#define pinstCCastingWnd_x                                         0xDAA588
#define pinstCCastSpellWnd_x                                       0xDA9DAC
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDAA5B0
#define pinstCChatWindowManager_x                                  0x101BE48
#define pinstCClaimWnd_x                                           0x101BFA0
#define pinstCColorPickerWnd_x                                     0xDAA5CC
#define pinstCCombatAbilityWnd_x                                   0xDA9E0C
#define pinstCCombatSkillsSelectWnd_x                              0xDAA5EC
#define pinstCCompassWnd_x                                         0xDAA598
#define pinstCConfirmationDialog_x                                 0x1020EA0
#define pinstCContainerMgr_x                                       0xDAA034
#define pinstCContextMenuManager_x                                 0x169A900
#define pinstCCursorAttachment_x                                   0xDAA57C
#define pinstCDistillerInfo_x                                      0x101F8AC
#define pinstCDynamicZoneWnd_x                                     0x101C568
#define pinstCEditLabelWnd_x                                       0xDAA4D4
#define pinstCEQMainWnd_x                                          0x101C7B0
#define pinstCEventCalendarWnd_x                                   0xDA9E14
#define pinstCExtendedTargetWnd_x                                  0xDA9DF4
#define pinstCFacePick_x                                           0xDAA5D4
#define pinstCFellowshipWnd_x                                      0x101C9B0
#define pinstCFileSelectionWnd_x                                   0xDAA528
#define pinstCFindItemWnd_x                                        0xDAA02C
#define pinstCFindLocationWnd_x                                    0x101CB08
#define pinstCFriendsWnd_x                                         0xDAA624
#define pinstCGemsGameWnd_x                                        0xDAA5F8
#define pinstCGiveWnd_x                                            0xDAA050
#define pinstCGroupSearchFiltersWnd_x                              0xDAA020
#define pinstCGroupSearchWnd_x                                     0x101CF00
#define pinstCGroupWnd_x                                           0x101CFB0
#define pinstCGuildBankWnd_x                                       0xE6CDE4
#define pinstCGuildCreationWnd_x                                   0x101D110
#define pinstCGuildMgmtWnd_x                                       0x101D1C0
#define pinstCharacterCreation_x                                   0xDA9E08
#define pinstCHelpWnd_x                                            0xDA9DBC
#define pinstCHeritageSelectionWnd_x                               0xDAA5DC
#define pinstCHotButtonWnd_x                                       0x101F318
#define pinstCHotButtonWnd1_x                                      0x101F318
#define pinstCHotButtonWnd2_x                                      0x101F31C
#define pinstCHotButtonWnd3_x                                      0x101F320
#define pinstCHotButtonWnd4_x                                      0x101F324
#define pinstCIconSelectionWnd_x                                   0xDAA55C
#define pinstCInspectWnd_x                                         0xDAA554
#define pinstCInventoryWnd_x                                       0xDAA044
#define pinstCInvSlotMgr_x                                         0xDA9DD0
#define pinstCItemDisplayManager_x                                 0x101F8A8
#define pinstCItemExpTransferWnd_x                                 0x101F9DC
#define pinstCItemOverflowWnd_x                                    0xDAA628
#define pinstCJournalCatWnd_x                                      0xDAA550
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDAA4E4
#define pinstCKeyRingWnd_x                                         0xDAA518
#define pinstCLargeDialogWnd_x                                     0x1021B20
#define pinstCLayoutCopyWnd_x                                      0x101FD28
#define pinstCLFGuildWnd_x                                         0x101FDD8
#define pinstCLoadskinWnd_x                                        0xDAA630
#define pinstCLootFiltersCopyWnd_x                                 0xC77E80
#define pinstCLootFiltersWnd_x                                     0xDAA5C8
#define pinstCLootSettingsWnd_x                                    0xDAA5D8
#define pinstCLootWnd_x                                            0xDAA5C0
#define pinstCMailAddressBookWnd_x                                 0xDAA560
#define pinstCMailCompositionWnd_x                                 0xDAA544
#define pinstCMailIgnoreListWnd_x                                  0xDAA564
#define pinstCMailWnd_x                                            0xDAA51C
#define pinstCManageLootWnd_x                                      0xDAB448
#define pinstCMapToolbarWnd_x                                      0xDAA048
#define pinstCMapViewWnd_x                                         0xDAA028
#define pinstCMarketplaceWnd_x                                     0xDAA030
#define pinstCMerchantWnd_x                                        0xDAA5E8
#define pinstCMIZoneSelectWnd_x                                    0x1020610
#define pinstCMusicPlayerWnd_x                                     0xDAA510
#define pinstCNameChangeMercWnd_x                                  0xDAA558
#define pinstCNameChangePetWnd_x                                   0xDAA53C
#define pinstCNameChangeWnd_x                                      0xDA9E00
#define pinstCNoteWnd_x                                            0xDA9DB8
#define pinstCObjectPreviewWnd_x                                   0xDAA0CC
#define pinstCOptionsWnd_x                                         0xDAA04C
#define pinstCPetInfoWnd_x                                         0xDAA534
#define pinstCPetitionQWnd_x                                       0xDAA568
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDAA5AC
#define pinstCPlayerWnd_x                                          0xDAA62C
#define pinstCPopupWndManager_x                                    0x1020EA0
#define pinstCProgressionSelectionWnd_x                            0x1020F50
#define pinstCPurchaseGroupWnd_x                                   0xDAA514
#define pinstCPurchaseWnd_x                                        0xDAA4D8
#define pinstCPvPLeaderboardWnd_x                                  0x1021000
#define pinstCPvPStatsWnd_x                                        0x10210B0
#define pinstCQuantityWnd_x                                        0xDAA570
#define pinstCRaceChangeWnd_x                                      0xDAA038
#define pinstCRaidOptionsWnd_x                                     0xDAA024
#define pinstCRaidWnd_x                                            0xDAA574
#define pinstCRealEstateItemsWnd_x                                 0xDA9DD4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA9E10
#define pinstCRealEstateManageWnd_x                                0xDAA5E0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDAA5FC
#define pinstCRealEstatePlotSearchWnd_x                            0xDA9DA8
#define pinstCRealEstatePurchaseWnd_x                              0xDA9DC0
#define pinstCRespawnWnd_x                                         0xDA9E1C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDA9DF0
#define pinstCSendMoneyWnd_x                                       0xDAA4DC
#define pinstCServerListWnd_x                                      0xDA9DD8
#define pinstCSkillsSelectWnd_x                                    0xDAA5D0
#define pinstCSkillsWnd_x                                          0xDAA5BC
#define pinstCSocialEditWnd_x                                      0xDAA578
#define pinstCSocialWnd_x                                          0xDAA584
#define pinstCSpellBookWnd_x                                       0xDA9DEC
#define pinstCStoryWnd_x                                           0xDAA590
#define pinstCTargetOfTargetWnd_x                                  0x1022EE0
#define pinstCTargetWnd_x                                          0xDAA530
#define pinstCTaskOverlayWnd_x                                     0xDA9DB0
#define pinstCTaskSelectWnd_x                                      0x1023038
#define pinstCTaskSomething_x                                      0xC78680
#define pinstCTaskTemplateSelectWnd_x                              0x10230E8
#define pinstCTaskWnd_x                                            0x1023198
#define pinstCTextEntryWnd_x                                       0xDAA59C
#define pinstCTextOverlay_x                                        0xC67158
#define pinstCTimeLeftWnd_x                                        0xDAA538
#define pinstCTipWndCONTEXT_x                                      0x102339C
#define pinstCTipWndOFDAY_x                                        0x1023398
#define pinstCTitleWnd_x                                           0x1023448
#define pinstCTrackingWnd_x                                        0xDAA52C
#define pinstCTradeskillWnd_x                                      0x10235B0
#define pinstCTradeWnd_x                                           0xDA9DC4
#define pinstCTrainWnd_x                                           0xDAA56C
#define pinstCTributeBenefitWnd_x                                  0x10237B0
#define pinstCTributeMasterWnd_x                                   0x1023860
#define pinstCTributeTrophyWnd_x                                   0x1023910
#define pinstCVideoModesWnd_x                                      0xDA9DCC
#define pinstCVoiceMacroWnd_x                                      0xF0D9C8
#define pinstCVoteResultsWnd_x                                     0xDAA520
#define pinstCVoteWnd_x                                            0xDAA4E0
#define pinstCWebManager_x                                         0xF0DB2C
#define pinstCZoneGuideWnd_x                                       0xDAA5E4
#define pinstCZonePathWnd_x                                        0xDAA604

#define pinstEQSuiteTextureLoader_x                                0xC51C58
#define pinstItemIconCache_x                                       0x101C768
#define pinstLootFiltersManager_x                                  0xC77F30
#define pinstRewardSelectionWnd_x                                  0x10217F8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC02C3C
#define __CastRay_x                                                0x58E2C0
#define __CastRay2_x                                               0x58E310
#define __ConvertItemTags_x                                        0x5A8EA0
#define __CrashHandler_x                                           0x83D6D0
#define __EQGetTime_x                                              0x8DB700
#define __ExecuteCmd_x                                             0x586C20
#define __FixHeading_x                                             0x96BF10
#define __get_bearing_x                                            0x58DE00
#define __get_melee_range_x                                        0x58E500
#define __GetAnimationCache_x                                      0x6FBE60
#define __GetGaugeValueFromEQ_x                                    0x7EF100
#define __GetLabelFromEQ_x                                         0x7F0870
#define __GetXTargetType_x                                         0x96D970
#define __HandleMouseWheel_x                                       0x698180
#define __HeadingDiff_x                                            0x96BF80
#define __HelpPath_x                                               0xF0AE7C
#define __LoadFrontEnd_x                                           0x693F30
#define __NewUIINI_x                                               0x7EEDD0
#define __pCrashHandler_x                                          0x1040C78
#define __ProcessGameEvents_x                                      0x5EB300
#define __ProcessMouseEvent_x                                      0x5EAAC0
#define __SaveColors_x                                             0x5385C0
#define __STMLToText_x                                             0x90F5A0
#define __ToggleKeyRingItem_x                                      0x4FBA40
#define CrashDetected_x                                            0x695A20
#define DrawNetStatus_x                                            0x616C90
#define Expansion_HoT_x                                            0xE6CDEC
#define Teleport_Table_Size_x                                      0xE5E1D8
#define Teleport_Table_x                                           0xE5BFB0
#define Util__FastTime_x                                           0x8DB2C0
#define wwsCrashReportCheckForUploader_x                           0x83E480
#define wwsCrashReportPlatformLaunchUploader_x                     0x840B60

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A8E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4936D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4934B0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x540050
#define AltAdvManager__IsAbilityReady_x                            0x53F0D0
#define AltAdvManager__GetAAById_x                                 0x53F2D0
#define AltAdvManager__CanTrainAbility_x                           0x53F340
#define AltAdvManager__CanSeeAbility_x                             0x53F570

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C64F0
#define CharacterZoneClient__HasSkill_x                            0x4D1090
#define CharacterZoneClient__MakeMeVisible_x                       0x4D27B0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA950
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B70D0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4F10
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4FF0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D50D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF430
#define CharacterZoneClient__BardCastBard_x                        0x4C2090
#define CharacterZoneClient__GetMaxEffects_x                       0x4B71A0
#define CharacterZoneClient__GetEffect_x                           0x4B7010
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0430
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0500
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0550
#define CharacterZoneClient__CalcAffectChange_x                    0x4C06A0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0870

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BE360

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CBC50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F9590
#define CButtonWnd__CButtonWnd_x                                   0x90B9B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EA880
#define CChatManager__InitContextMenu_x                            0x6E4920
#define CChatManager__FreeChatWindow_x                             0x6E9790
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EE120
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EA620

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x920200
#define CContextMenu__dCContextMenu_x                              0x920430
#define CContextMenu__AddMenuItem_x                                0x920440
#define CContextMenu__RemoveMenuItem_x                             0x920740
#define CContextMenu__RemoveAllMenuItems_x                         0x920760
#define CContextMenu__CheckMenuItem_x                              0x9207E0
#define CContextMenu__SetMenuItem_x                                0x920670

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x920D80
#define CContextMenuManager__RemoveMenu_x                          0x920DF0
#define CContextMenuManager__PopupMenu_x                           0x920EB0
#define CContextMenuManager__Flush_x                               0x920D20
#define CContextMenuManager__GetMenu_x                             0x495890

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BC250
#define CChatService__GetFriendName_x                              0x8BC260

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EADF0
#define CChatWindow__Clear_x                                       0x6EBE40
#define CChatWindow__WndNotification_x                             0x6EC3B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91D690
#define CComboWnd__Draw_x                                          0x91CB90
#define CComboWnd__GetCurChoice_x                                  0x91D4D0
#define CComboWnd__GetListRect_x                                   0x91D040
#define CComboWnd__GetTextRect_x                                   0x91D6F0
#define CComboWnd__InsertChoice_x                                  0x91D1D0
#define CComboWnd__SetColors_x                                     0x91D1A0
#define CComboWnd__SetChoice_x                                     0x91D4A0
#define CComboWnd__GetItemCount_x                                  0x91D4E0
#define CComboWnd__GetCurChoiceText_x                              0x91D520

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F4030
#define CContainerWnd__vftable_x                                   0xAC9AD0
#define CContainerWnd__SetContainer_x                              0x6F5590

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x538380
#define CDisplay__GetClickedActor_x                                0x52B3D0
#define CDisplay__GetUserDefinedColor_x                            0x523AB0
#define CDisplay__GetWorldFilePath_x                               0x52CE20
#define CDisplay__is3dON_x                                         0x5280A0
#define CDisplay__ReloadUI_x                                       0x532540
#define CDisplay__WriteTextHD2_x                                   0x527E80
#define CDisplay__TrueDistance_x                                   0x52EA80
#define CDisplay__SetViewActor_x                                   0x52AD20
#define CDisplay__GetFloorHeight_x                                 0x528160
#define CDisplay__SetRenderWindow_x                                0x526A90
#define CDisplay__ToggleScreenshotMode_x                           0x52A7F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93F850

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x924900
#define CEditWnd__GetCharIndexPt_x                                 0x9257F0
#define CEditWnd__GetDisplayString_x                               0x925690
#define CEditWnd__GetHorzOffset_x                                  0x923F30
#define CEditWnd__GetLineForPrintableChar_x                        0x926930
#define CEditWnd__GetSelStartPt_x                                  0x925AA0
#define CEditWnd__GetSTMLSafeText_x                                0x9254B0
#define CEditWnd__PointFromPrintableChar_x                         0x926560
#define CEditWnd__SelectableCharFromPoint_x                        0x9266D0
#define CEditWnd__SetEditable_x                                    0x925B70

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5D9D70
#define CEverQuest__ClickedPlayer_x                                0x5CC0C0
#define CEverQuest__CreateTargetIndicator_x                        0x5E85E0
#define CEverQuest__DeleteTargetIndicator_x                        0x5E8670
#define CEverQuest__DoTellWindow_x                                 0x4E1390
#define CEverQuest__OutputTextToLog_x                              0x4E15C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C1980
#define CEverQuest__dsp_chat_x                                     0x4E1950
#define CEverQuest__trimName_x                                     0x5E4BA0
#define CEverQuest__Emote_x                                        0x5DA580
#define CEverQuest__EnterZone_x                                    0x5D4760
#define CEverQuest__GetBodyTypeDesc_x                              0x5DE440
#define CEverQuest__GetClassDesc_x                                 0x5DEA80
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DF080
#define CEverQuest__GetDeityDesc_x                                 0x5E6F30
#define CEverQuest__GetLangDesc_x                                  0x5DF240
#define CEverQuest__GetRaceDesc_x                                  0x5DEA60
#define CEverQuest__InterpretCmd_x                                 0x5E7500
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C5B70
#define CEverQuest__LMouseUp_x                                     0x5C3EF0
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6450
#define CEverQuest__RMouseUp_x                                     0x5C4E80
#define CEverQuest__SetGameState_x                                 0x5C1710
#define CEverQuest__UPCNotificationFlush_x                         0x5E4AA0
#define CEverQuest__IssuePetCommand_x                              0x5E0640
#define CEverQuest__ReportSuccessfulHit_x                          0x5DB2A0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x705FD0
#define CGaugeWnd__CalcLinesFillRect_x                             0x706030
#define CGaugeWnd__Draw_x                                          0x7056C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABF50
#define CGuild__GetGuildName_x                                     0x4AAF90
#define CGuild__GetGuildIndex_x                                    0x4AB320

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x721350

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72E250
#define CInvSlotMgr__MoveItem_x                                    0x72CFB0
#define CInvSlotMgr__SelectSlot_x                                  0x72E320

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72B860
#define CInvSlot__SliderComplete_x                                 0x729670
#define CInvSlot__GetItemBase_x                                    0x728FF0
#define CInvSlot__UpdateItem_x                                     0x729160

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x72FC70
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72EF40
#define CInvSlotWnd__HandleLButtonUp_x                             0x72F7F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EB2A0
#define CItemDisplayWnd__UpdateStrings_x                           0x73D960
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x737A40
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x737F00
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73DEF0
#define CItemDisplayWnd__AboutToShow_x                             0x73D5B0
#define CItemDisplayWnd__WndNotification_x                         0x73F200

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x822BF0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x743260

// CLabel 
#define CLabel__Draw_x                                             0x748D80

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F5CE0
#define CListWnd__dCListWnd_x                                      0x8F5FF0
#define CListWnd__AddColumn_x                                      0x8FA2D0
#define CListWnd__AddColumn1_x                                     0x8FA320
#define CListWnd__AddLine_x                                        0x8FA6B0
#define CListWnd__AddString_x                                      0x8FA4B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8FA090
#define CListWnd__CalculateVSBRange_x                              0x8F9E90
#define CListWnd__ClearSel_x                                       0x8FAE90
#define CListWnd__ClearAllSel_x                                    0x8FAEF0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FB8D0
#define CListWnd__Compare_x                                        0x8F97D0
#define CListWnd__Draw_x                                           0x8F60F0
#define CListWnd__DrawColumnSeparators_x                           0x8F88C0
#define CListWnd__DrawHeader_x                                     0x8F8D20
#define CListWnd__DrawItem_x                                       0x8F9110
#define CListWnd__DrawLine_x                                       0x8F8A20
#define CListWnd__DrawSeparator_x                                  0x8F8960
#define CListWnd__EnableLine_x                                     0x8F81A0
#define CListWnd__EnsureVisible_x                                  0x8FB800
#define CListWnd__ExtendSel_x                                      0x8FADC0
#define CListWnd__GetColumnMinWidth_x                              0x8F7CE0
#define CListWnd__GetColumnWidth_x                                 0x8F7C50
#define CListWnd__GetCurSel_x                                      0x8F75E0
#define CListWnd__GetItemAtPoint_x                                 0x8F8410
#define CListWnd__GetItemAtPoint1_x                                0x8F8480
#define CListWnd__GetItemData_x                                    0x8F7660
#define CListWnd__GetItemHeight_x                                  0x8F7A20
#define CListWnd__GetItemIcon_x                                    0x8F77F0
#define CListWnd__GetItemRect_x                                    0x8F8290
#define CListWnd__GetItemText_x                                    0x8F76A0
#define CListWnd__GetSelList_x                                     0x8FAF40
#define CListWnd__GetSeparatorRect_x                               0x8F86C0
#define CListWnd__InsertLine_x                                     0x8FAAA0
#define CListWnd__RemoveLine_x                                     0x8FABF0
#define CListWnd__SetColors_x                                      0x8F9E60
#define CListWnd__SetColumnJustification_x                         0x8F9B90
#define CListWnd__SetColumnWidth_x                                 0x8F9AB0
#define CListWnd__SetCurSel_x                                      0x8FAD00
#define CListWnd__SetItemColor_x                                   0x8FB4C0
#define CListWnd__SetItemData_x                                    0x8FB480
#define CListWnd__SetItemText_x                                    0x8FB0C0
#define CListWnd__ShiftColumnSeparator_x                           0x8F9C50
#define CListWnd__Sort_x                                           0x8F9950
#define CListWnd__ToggleSel_x                                      0x8FAD30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75E380
#define CMapViewWnd__GetWorldCoordinates_x                         0x75CA90
#define CMapViewWnd__HandleLButtonDown_x                           0x759AF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x781380
#define CMerchantWnd__RequestBuyItem_x                             0x781C60
#define CMerchantWnd__RequestSellItem_x                            0x782190
#define CMerchantWnd__SelectRecoverySlot_x                         0x784FC0
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x7819E0
#define CMerchantWnd__ActualSelect_x                               0x78AB50

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88A140
#define CPacketScrambler__hton_x                                   0x88A130

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x914C00
#define CSidlManager__FindScreenPieceTemplate_x                    0x915010
#define CSidlManager__FindScreenPieceTemplate1_x                   0x914E00
#define CSidlManager__CreateLabel_x                                0x7E26E0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9180E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9182C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x911730
#define CSidlScreenWnd__CalculateVSBRange_x                        0x911620
#define CSidlScreenWnd__ConvertToRes_x                             0x9360F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9110B0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x910DA0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x910E70
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x910F40
#define CSidlScreenWnd__DrawSidlPiece_x                            0x911BC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x912090
#define CSidlScreenWnd__GetSidlPiece_x                             0x911DB0
#define CSidlScreenWnd__Init1_x                                    0x910990
#define CSidlScreenWnd__LoadIniInfo_x                              0x9120E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x912C40
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90FD90
#define CSidlScreenWnd__StoreIniInfo_x                             0x9127B0
#define CSidlScreenWnd__StoreIniVis_x                              0x912B20
#define CSidlScreenWnd__WndNotification_x                          0x911AD0
#define CSidlScreenWnd__GetChildItem_x                             0x912010
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9016E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x169A7D0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65D560
#define CSkillMgr__GetSkillCap_x                                   0x65D740
#define CSkillMgr__GetNameToken_x                                  0x65CCF0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x921B80
#define CSliderWnd__SetValue_x                                     0x9219F0
#define CSliderWnd__SetNumTicks_x                                  0x921A50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E8510

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9287D0
#define CStmlWnd__CalculateHSBRange_x                              0x929890
#define CStmlWnd__CalculateVSBRange_x                              0x929800
#define CStmlWnd__CanBreakAtCharacter_x                            0x92DBC0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92E7B0
#define CStmlWnd__ForceParseNow_x                                  0x928DC0
#define CStmlWnd__GetNextTagPiece_x                                0x92DB20
#define CStmlWnd__GetSTMLText_x                                    0x4EF7D0
#define CStmlWnd__GetVisibleText_x                                 0x928DE0
#define CStmlWnd__InitializeWindowVariables_x                      0x92E600
#define CStmlWnd__MakeStmlColorTag_x                               0x927F60
#define CStmlWnd__MakeWndNotificationTag_x                         0x927FD0
#define CStmlWnd__SetSTMLText_x                                    0x927030
#define CStmlWnd__StripFirstSTMLLines_x                            0x92F910
#define CStmlWnd__UpdateHistoryString_x                            0x92E9C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x933080
#define CTabWnd__DrawCurrentPage_x                                 0x9336A0
#define CTabWnd__DrawTab_x                                         0x933470
#define CTabWnd__GetCurrentPage_x                                  0x9328E0
#define CTabWnd__GetPageInnerRect_x                                0x932B20
#define CTabWnd__GetTabInnerRect_x                                 0x932A60
#define CTabWnd__GetTabRect_x                                      0x932910
#define CTabWnd__InsertPage_x                                      0x932D10
#define CTabWnd__SetPage_x                                         0x932BA0
#define CTabWnd__SetPageRect_x                                     0x932FC0
#define CTabWnd__UpdatePage_x                                      0x933330
#define CTabWnd__GetPageFromTabIndex_x                             0x9333B0
#define CTabWnd__GetCurrentTabIndex_x                              0x9328D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7436C0
#define CPageWnd__SetTabText_x                                     0x93FC60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A59C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FE520
#define CTextureFont__GetTextExtent_x                              0x8FE6E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x690D80
#define CHtmlComponentWnd__ValidateUri_x                           0x722D50
#define CHtmlWnd__SetClientCallbacks_x                             0x5FE950
#define CHtmlWnd__AddObserver_x                                    0x5FE970
#define CHtmlWnd__RemoveObserver_x                                 0x5FE9D0
#define Window__getProgress_x                                      0x83B320
#define Window__getStatus_x                                        0x83B340
#define Window__getURI_x                                           0x83B350

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93C1E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8EB410

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD270
#define CXStr__CXStr1_x                                            0x8F3F10
#define CXStr__CXStr3_x                                            0x8D77F0
#define CXStr__dCXStr_x                                            0x472340
#define CXStr__operator_equal_x                                    0x8D7A20
#define CXStr__operator_equal1_x                                   0x8D7A60
#define CXStr__operator_plus_equal1_x                              0x8D84F0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91FE20
#define CXWnd__BringToTop_x                                        0x904E80
#define CXWnd__Center_x                                            0x904A00
#define CXWnd__ClrFocus_x                                          0x904840
#define CXWnd__Destroy_x                                           0x9048E0
#define CXWnd__DoAllDrawing_x                                      0x900E70
#define CXWnd__DrawChildren_x                                      0x900E40
#define CXWnd__DrawColoredRect_x                                   0x9012D0
#define CXWnd__DrawTooltip_x                                       0x8FF990
#define CXWnd__DrawTooltipAtPoint_x                                0x8FFA50
#define CXWnd__GetBorderFrame_x                                    0x901130
#define CXWnd__GetChildWndAt_x                                     0x904F20
#define CXWnd__GetClientClipRect_x                                 0x9030F0
#define CXWnd__GetScreenClipRect_x                                 0x9031C0
#define CXWnd__GetScreenRect_x                                     0x903350
#define CXWnd__GetTooltipRect_x                                    0x901320
#define CXWnd__GetWindowTextA_x                                    0x496F30
#define CXWnd__IsActive_x                                          0x907DF0
#define CXWnd__IsDescendantOf_x                                    0x903D60
#define CXWnd__IsReallyVisible_x                                   0x903D90
#define CXWnd__IsType_x                                            0x905590
#define CXWnd__Move_x                                              0x903E00
#define CXWnd__Move1_x                                             0x903EB0
#define CXWnd__ProcessTransition_x                                 0x9049B0
#define CXWnd__Refade_x                                            0x904190
#define CXWnd__Resize_x                                            0x904450
#define CXWnd__Right_x                                             0x904C40
#define CXWnd__SetFocus_x                                          0x904800
#define CXWnd__SetFont_x                                           0x904870
#define CXWnd__SetKeyTooltip_x                                     0x9053A0
#define CXWnd__SetMouseOver_x                                      0x902250
#define CXWnd__StartFade_x                                         0x903C30
#define CXWnd__GetChildItem_x                                      0x905090
#define CXWnd__SetParent_x                                         0x903B00

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9371D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x907E30
#define CXWndManager__DrawWindows_x                                0x907E50
#define CXWndManager__GetKeyboardFlags_x                           0x90A5D0
#define CXWndManager__HandleKeyboardMsg_x                          0x90A1D0
#define CXWndManager__RemoveWnd_x                                  0x90A820
#define CXWndManager__RemovePendingDeletionWnd_x                   0x90AD80

// CDBStr
#define CDBStr__GetString_x                                        0x522A60

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8080
#define EQ_Character__Cur_HP_x                                     0x4CE110
#define EQ_Character__Cur_Mana_x                                   0x4D55D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BAF90
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AEED0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF020
#define EQ_Character__GetHPRegen_x                                 0x4DACB0
#define EQ_Character__GetEnduranceRegen_x                          0x4DB2C0
#define EQ_Character__GetManaRegen_x                               0x4DB700
#define EQ_Character__Max_Endurance_x                              0x6243C0
#define EQ_Character__Max_HP_x                                     0x4CDF40
#define EQ_Character__Max_Mana_x                                   0x6241C0
#define EQ_Character__doCombatAbility_x                            0x626570
#define EQ_Character__UseSkill_x                                   0x4DD510
#define EQ_Character__GetConLevel_x                                0x61D9D0
#define EQ_Character__IsExpansionFlag_x                            0x5854E0
#define EQ_Character__TotalEffect_x                                0x4C1610
#define EQ_Character__GetPCSpellAffect_x                           0x4BBB80
#define EQ_Character__SpellDuration_x                              0x4BB6B0
#define EQ_Character__FindItemByRecord_x                           0x4D3720
#define EQ_Character__GetAdjustedSkill_x                           0x4D0E50
#define EQ_Character__GetBaseSkill_x                               0x4D1DF0
#define EQ_Character__CanUseItem_x                                 0x4D58E0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8A92C0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63A340

//PcClient
#define PcClient__PcClient_x                                       0x61B2A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5E60
#define CCharacterListWnd__EnterWorld_x                            0x4B58A0
#define CCharacterListWnd__Quit_x                                  0x4B55B0
#define CCharacterListWnd__UpdateList_x                            0x4B5A30

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5FFB50
#define EQ_Item__CreateItemTagString_x                             0x884470
#define EQ_Item__IsStackable_x                                     0x888600
#define EQ_Item__GetImageNum_x                                     0x885C30
#define EQ_Item__CreateItemClient_x                                0x5FED30
#define EQ_Item__GetItemValue_x                                    0x886CF0
#define EQ_Item__ValueSellMerchant_x                               0x889CE0
#define EQ_Item__IsKeyRingItem_x                                   0x887FD0
#define EQ_Item__CanGoInBag_x                                      0x5FFC70
#define EQ_Item__GetMaxItemCount_x                                 0x886DF0
#define EQ_Item__GetHeldItem_x                                     0x885B00
#define EQ_Item__GetAugmentFitBySlot_x                             0x883FD0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x540D50
#define EQ_LoadingS__Array_x                                       0xBDA2D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x624D20
#define EQ_PC__GetAlternateAbilityId_x                             0x892FE0
#define EQ_PC__GetCombatAbility_x                                  0x893650
#define EQ_PC__GetCombatAbilityTimer_x                             0x8936C0
#define EQ_PC__GetItemRecastTimer_x                                0x626AF0
#define EQ_PC__HasLoreItem_x                                       0x61E140
#define EQ_PC__AlertInventoryChanged_x                             0x61D4B0
#define EQ_PC__GetPcZoneClient_x                                   0x648BA0
#define EQ_PC__RemoveMyAffect_x                                    0x629C20
#define EQ_PC__GetKeyRingItems_x                                   0x893F60
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x893CE0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x894250

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58B830
#define EQItemList__add_object_x                                   0x5B7120
#define EQItemList__add_item_x                                     0x58BE40
#define EQItemList__delete_item_x                                  0x58BE90
#define EQItemList__FreeItemList_x                                 0x58BD90

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x520070

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63BBC0
#define EQPlayer__dEQPlayer_x                                      0x62F290
#define EQPlayer__DoAttack_x                                       0x6438A0
#define EQPlayer__EQPlayer_x                                       0x62F940
#define EQPlayer__SetNameSpriteState_x                             0x633BF0
#define EQPlayer__SetNameSpriteTint_x                              0x634AC0
#define PlayerBase__HasProperty_j_x                                0x96A2E0
#define EQPlayer__IsTargetable_x                                   0x96A780
#define EQPlayer__CanSee_x                                         0x96A5E0
#define EQPlayer__CanSee1_x                                        0x96A6B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x96A3A0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x646670
#define PlayerZoneClient__GetLevel_x                               0x648BE0
#define PlayerZoneClient__IsValidTeleport_x                        0x5B8270
#define PlayerZoneClient__LegalPlayerRace_x                        0x53A180

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63E9D0
#define EQPlayerManager__GetSpawnByName_x                          0x63E9F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63EA80

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6033E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x603420
#define KeypressHandler__ClearCommandStateArray_x                  0x604810
#define KeypressHandler__HandleKeyDown_x                           0x604830
#define KeypressHandler__HandleKeyUp_x                             0x6048D0
#define KeypressHandler__SaveKeymapping_x                          0x604CB0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75A210
#define MapViewMap__SaveEx_x                                       0x75D5B0
#define MapViewMap__SetZoom_x                                      0x761C80

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A71B0

// StringTable 
#define StringTable__getString_x                                   0x8A2100

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x629890
#define PcZoneClient__RemovePetEffect_x                            0x629EC0
#define PcZoneClient__HasAlternateAbility_x                        0x624000
#define PcZoneClient__GetCurrentMod_x                              0x4E0480
#define PcZoneClient__GetModCap_x                                  0x4E0380
#define PcZoneClient__CanEquipItem_x                               0x6246B0
#define PcZoneClient__GetItemByID_x                                0x626F60
#define PcZoneClient__GetItemByItemClass_x                         0x626FF0
#define PcZoneClient__RemoveBuffEffect_x                           0x629EE0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BCE60

//IconCache
#define IconCache__GetIcon_x                                       0x6FB6F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F31D0
#define CContainerMgr__CloseContainer_x                            0x6F34A0
#define CContainerMgr__OpenExperimentContainer_x                   0x6F3F20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B50C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F7D70

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7506F0
#define CLootWnd__RequestLootSlot_x                                0x74FAA0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x559550
#define EQ_Spell__SpellAffects_x                                   0x5599C0
#define EQ_Spell__SpellAffectBase_x                                0x559780
#define EQ_Spell__IsStackable_x                                    0x4C5E10
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5CC0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3400
#define EQ_Spell__IsSPAStacking_x                                  0x55A7F0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x559D10
#define EQ_Spell__IsNoRemove_x                                     0x4C5DF0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55A800
#define __IsResEffectSpell_x                                       0x4C5150

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9BC0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B1800

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FA650
#define CTargetWnd__WndNotification_x                              0x7F9EE0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FA1B0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7F9030

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FED20

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x554AF0
#define EqSoundManager__PlayScriptMp3_x                            0x554C50
#define EqSoundManager__SoundAssistPlay_x                          0x661040
#define EqSoundManager__WaveInstancePlay_x                         0x6605B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x511970

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x923570

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x548A80
#define CAltAbilityData__GetMercMaxRank_x                          0x548A20
#define CAltAbilityData__GetMaxRank_x                              0x53DF80

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F5E80

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5CA0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7E40
#define CharacterBase__CreateItemIndex_x                           0x5FDF60
#define CharacterBase__GetItemPossession_x                         0x4B32B0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8B9D60
#define CharacterBase__GetEffectId_x                               0x4C5C50

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DB350
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DBB70

//messages
#define msg_spell_worn_off_x                                       0x57DD90
#define msg_new_text_x                                             0x572F50
#define __msgTokenTextParam_x                                      0x5803E0
#define msgTokenText_x                                             0x580630

//SpellManager
#define SpellManager__vftable_x                                    0xAA4828
#define SpellManager__SpellManager_x                               0x664370
#define Spellmanager__LoadTextSpells_x                             0x664C40
#define SpellManager__GetSpellByGroupAndRank_x                     0x664540

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96E260

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F8520
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x583BC0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x616AF0
#define ItemGlobalIndex__IsValidIndex_x                            0x4F8580

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B2140
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B23C0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7490D0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F7940
#define CCursorAttachment__Deactivate_x                            0x6F8920

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9355D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x935290

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F5490

//IString
#define IString__Append_x                                          0x4E97E0

//Camera
#define CDisplay__cameraType_x                                     0xDA9E18
#define EverQuest__Cameras_x                                       0xE6D128

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FDCD0
#define LootFiltersManager__GetItemFilterData_x                    0x4FD5C0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FD5F0
#define LootFiltersManager__SetItemLootFilter_x                    0x4FD810

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A3100

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x973FF0
#define CResolutionHandler__GetWindowedStyle_x                     0x65BF90

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6EFF90

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8C40F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
#if defined(ROF2EMU) || defined(UFEMU)
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\xFD\xFF\xFF\x8B\xCE\x5E\xE9\x00\x00\xFF\xFF\xC7\x01";
static char lpMask[] = "xxxx?xxxxxxx??xxxx";
#else
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
#endif
