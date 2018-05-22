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
#define __ExpectedVersionDate                                     "Apr  9 2018"
#define __ExpectedVersionTime                                     "21:46:39"
#define __ActualVersionDate_x                                      0xABF23C
#define __ActualVersionTime_x                                      0xABF230

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x608D80
#define __MemChecker1_x                                            0x8D99E0
#define __MemChecker2_x                                            0x696EF0
#define __MemChecker3_x                                            0x696E40
#define __MemChecker4_x                                            0x831C00
#define __EncryptPad0_x                                            0xBF2FD0
#define __EncryptPad1_x                                            0xC50ED0
#define __EncryptPad2_x                                            0xC03B58
#define __EncryptPad3_x                                            0xC03758
#define __EncryptPad4_x                                            0xC41C80
#define __EncryptPad5_x                                            0xF0EAA4
#define __AC1_x                                                    0x7EF7B6
#define __AC2_x                                                    0x5C513F
#define __AC3_x                                                    0x5CBFCF
#define __AC4_x                                                    0x5CFE70
#define __AC5_x                                                    0x5D60B0
#define __AC6_x                                                    0x5DA4B2
#define __AC7_x                                                    0x5C4BB0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1AC54C

// Direct Input
#define DI8__Main_x                                                0xF0EAC8
#define DI8__Keyboard_x                                            0xF0EACC
#define DI8__Mouse_x                                               0xF0EA90
#define DI8__Mouse_Copy_x                                          0xE6C81C
#define DI8__Mouse_Check_x                                         0xF0F990
#define __AutoSkillArray_x                                         0xE6D72C
#define __Attack_x                                                 0xF0B507
#define __Autofire_x                                               0xF0B508
#define __BindList_x                                               0xBE1BD8
#define g_eqCommandStates_x                                        0xBE2940
#define __Clicks_x                                                 0xE6C8D4
#define __CommandList_x                                            0xBE34F8
#define __CurrentMapLabel_x                                        0x102115C
#define __CurrentSocial_x                                          0xBCD260
#define __DoAbilityList_x                                          0xEA3028
#define __do_loot_x                                                0x592900
#define __DrawHandler_x                                            0x169C598
#define __GroupCount_x                                             0xE5F1CA
#define __Guilds_x                                                 0xE63028
#define __gWorld_x                                                 0xE5D01C
#define __HWnd_x                                                   0xF0EA94
#define __heqmain_x                                                0x1019CEC
#define __InChatMode_x                                             0xE6C804
#define __LastTell_x                                               0xE6E724
#define __LMouseHeldTime_x                                         0xE6C940
#define __Mouse_x                                                  0xF0EAB0
#define __MouseLook_x                                              0xE6C89A
#define __MouseEventTime_x                                         0xF0BFC0
#define __gpbCommandEvent_x                                        0xE5CB40
#define __NetStatusToggle_x                                        0xE6C89D
#define __PCNames_x                                                0xE6DCE8
#define __RangeAttackReady_x                                       0xE6DA10
#define __RMouseHeldTime_x                                         0xE6C93C
#define __RunWalkState_x                                           0xE6C808
#define __ScreenMode_x                                             0xDAB380
#define __ScreenX_x                                                0xE6C7BC
#define __ScreenY_x                                                0xE6C7B8
#define __ScreenXMax_x                                             0xE6C7C0
#define __ScreenYMax_x                                             0xE6C7C4
#define __ServerHost_x                                             0xE5CD0B
#define __ServerName_x                                             0xEA2FE8
#define __ShiftKeyDown_x                                           0xE6CE94
#define __ShowNames_x                                              0xE6DBC8
#define __Socials_x                                                0xEA30E8
#define __SubscriptionType_x                                       0x1062B9C
#define __TargetAggroHolder_x                                      0x1023B2C
#define __ZoneType_x                                               0xE6CC98
#define __GroupAggro_x                                             0x1023B6C
#define __LoginName_x                                              0xF0F63C
#define __Inviter_x                                                0xF0B484
#define __AttackOnAssist_x                                         0xE6DB84
#define __UseTellWindows_x                                         0xE6DE80

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5F3D0
#define instEQZoneInfo_x                                           0xE6CA90
#define instKeypressHandler_x                                      0xF0BF70
#define pinstActiveBanker_x                                        0xE5F160
#define pinstActiveCorpse_x                                        0xE5F158
#define pinstActiveGMaster_x                                       0xE5F15C
#define pinstActiveMerchant_x                                      0xE5F154
#define pinstAggroInfo_x                                           0xC677E0
#define pinstAltAdvManager_x                                       0xDABD70
#define pinstAuraMgr_x                                             0xC78458
#define pinstBandageTarget_x                                       0xE5F170
#define pinstCamActor_x                                            0xDAB370
#define pinstCDBStr_x                                              0xDAAAC4
#define pinstCDisplay_x                                            0xE5F3B8
#define pinstCEverQuest_x                                          0xF0EBE8
#define pinstEverQuestInfo_x                                       0xE6C7B0
#define pinstCharData_x                                            0xE5F3C8
#define pinstCharSpawn_x                                           0xE5F1A8
#define pinstControlledMissile_x                                   0xE5CAC0
#define pinstControlledPlayer_x                                    0xE5F1A8
#define pinstCSidlManager_x                                        0x169B65C
#define pinstCXWndManager_x                                        0x169B650
#define instDynamicZone_x                                          0xE62F00
#define pinstDZMember_x                                            0xE63010
#define pinstDZTimerInfo_x                                         0xE63014
#define pinstEQItemList_x                                          0xE5B5C0
#define pinstEQObjectList_x                                        0xE5C7B0
#define instEQMisc_x                                               0xDAAA00
#define pinstEQSoundManager_x                                      0xDAC5D0
#define pinstEQSpellStrings_x                                      0xC758A8
#define instExpeditionLeader_x                                     0xE62F4A
#define instExpeditionName_x                                       0xE62F8A
#define pinstGroup_x                                               0xE5F1C6
#define pinstImeManager_x                                          0x169B654
#define pinstLocalPlayer_x                                         0xE5F150
#define pinstMercenaryData_x                                       0xF0C760
#define pinstMercenaryStats_x                                      0x1023C78
#define pinstMercAltAbilities_x                                    0xDAC340
#define pinstModelPlayer_x                                         0xE5F168
#define pinstPCData_x                                              0xE5F3C8
#define pinstRealEstateItems_x                                     0xF0DC50
#define pinstSkillMgr_x                                            0xF0DD20
#define pinstSpawnManager_x                                        0xF0D310
#define pinstSpellManager_x                                        0xF0DEF8
#define pinstSpellSets_x                                           0xF04130
#define pinstStringTable_x                                         0xE5F024
#define pinstSwitchManager_x                                       0xE5C970
#define pinstTarget_x                                              0xE5F1A4
#define pinstTargetObject_x                                        0xE5F1B4
#define pinstTargetSwitch_x                                        0xE5CAE0
#define pinstTaskMember_x                                          0xDAA890
#define pinstTrackTarget_x                                         0xE5F1AC
#define pinstTradeTarget_x                                         0xE5F164
#define instTributeActive_x                                        0xDAAA25
#define pinstViewActor_x                                           0xDAB36C
#define pinstWorldData_x                                           0xE5CE14
#define pinstZoneAddr_x                                            0xE6CD30
#define pinstPlayerPath_x                                          0xF0D3A8
#define pinstTargetIndicator_x                                     0xF0E160
#define pinstCTargetManager_x                                      0xF0E1F8
#define EQObject_Top_x                                             0xE5F14C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDAAB84
#define pinstCAchievementsWnd_x                                    0xDAAE2C
#define pinstCActionsWnd_x                                         0xDAADE0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDAAB64
#define pinstCAdvancedLootWnd_x                                    0xDAB3AC
#define pinstCAdventureLeaderboardWnd_x                            0x101A888
#define pinstCAdventureRequestWnd_x                                0x101A938
#define pinstCAdventureStatsWnd_x                                  0x101A9E8
#define pinstCAggroMeterWnd_x                                      0xDAAE54
#define pinstCAlarmWnd_x                                           0xDAAE14
#define pinstCAlertHistoryWnd_x                                    0xDAADEC
#define pinstCAlertStackWnd_x                                      0xDAAB78
#define pinstCAlertWnd_x                                           0xDAAB8C
#define pinstCAltStorageWnd_x                                      0x101AD48
#define pinstCAudioTriggersWindow_x                                0xC67C70
#define pinstCAuraWnd_x                                            0xDAAE4C
#define pinstCAvaZoneWnd_x                                         0xDAADCC
#define pinstCBandolierWnd_x                                       0xDAAF04
#define pinstCBankWnd_x                                            0xDAB3A8
#define pinstCBarterMerchantWnd_x                                  0x101BF88
#define pinstCBarterSearchWnd_x                                    0x101C038
#define pinstCBarterWnd_x                                          0x101C0E8
#define pinstCBazaarConfirmationWnd_x                              0xDAAB74
#define pinstCBazaarSearchWnd_x                                    0xDAAE04
#define pinstCBazaarWnd_x                                          0xDAAE7C
#define pinstCBlockedBuffWnd_x                                     0xDAB394
#define pinstCBlockedPetBuffWnd_x                                  0xDAB3Bc
#define pinstCBodyTintWnd_x                                        0xDAABA0
#define pinstCBookWnd_x                                            0xDAB318
#define pinstCBreathWnd_x                                          0xDAAB98
#define pinstCBuffWindowNORMAL_x                                   0xDAB358
#define pinstCBuffWindowSHORT_x                                    0xDAB35C
#define pinstCBugReportWnd_x                                       0xDAAB80
#define pinstCButtonWnd_x                                          0x169B810
#define pinstCCastingWnd_x                                         0xDAAB60
#define pinstCCastSpellWnd_x                                       0xDAAE0C
//#define pinstCCharacterCreationWnd_x                               0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDAABA4
#define pinstCChatWindowManager_x                                  0x101CBA8
#define pinstCClaimWnd_x                                           0x101CD00
#define pinstCColorPickerWnd_x                                     0xDAADBC
#define pinstCCombatAbilityWnd_x                                   0xDAAE50
#define pinstCCombatSkillsSelectWnd_x                              0xDAADE4
#define pinstCCompassWnd_x                                         0xDAAB88
#define pinstCConfirmationDialog_x                                 0x1021CA8
#define pinstCContainerMgr_x                                       0xDAAF00
#define pinstCContextMenuManager_x                                 0x169B610
#define pinstCCursorAttachment_x                                   0xDAB3EC
#define pinstCDynamicZoneWnd_x                                     0x101D2C8
#define pinstCEditLabelWnd_x                                       0xDAB344
#define pinstCEQMainWnd_x                                          0x101D510
#define pinstCEventCalendarWnd_x                                   0xDAAE48
#define pinstCExtendedTargetWnd_x                                  0xDAAE44
#define pinstCFacePick_x                                           0xDAADC4
#define pinstCFeedbackWnd_x                                        0xDAB3F0
#define pinstCFellowshipWnd_x                                      0x101D7B8
#define pinstCFileSelectionWnd_x                                   0xDAB398
#define pinstCFindItemWnd_x                                        0xDAAE70
#define pinstCFindLocationWnd_x                                    0x101D910
#define pinstCFriendsWnd_x                                         0xDAAE00
#define pinstCGemsGameWnd_x                                        0xDAADE8
#define pinstCGiveWnd_x                                            0xDAB314
#define pinstCGroupSearchFiltersWnd_x                              0xDAAE68
#define pinstCGroupSearchWnd_x                                     0x101DD08
#define pinstCGroupWnd_x                                           0x101DDB8
#define pinstCGuildBankWnd_x                                       0xE6DB6C
#define pinstCGuildCreationWnd_x                                   0x101DF18
#define pinstCGuildMgmtWnd_x                                       0x101DFC8
#define pinstCharacterCreation_x                                   0xDAAE5C
#define pinstCHelpWnd_x                                            0xDAAE1C
#define pinstCHeritageSelectionWnd_x                               0xDAADD0
#define pinstCHotButtonWnd_x                                       0x1020120
#define pinstCHotButtonWnd1_x                                      0x1020120
#define pinstCHotButtonWnd2_x                                      0x1020124
#define pinstCHotButtonWnd3_x                                      0x1020128
#define pinstCHotButtonWnd4_x                                      0x102012C
#define pinstCIconSelectionWnd_x                                   0xDAB3C8
#define pinstCInspectWnd_x                                         0xDAB3B8
#define pinstCInventoryWnd_x                                       0xDAAEFC
#define pinstCInvSlotMgr_x                                         0xDAAE40
#define pinstCItemDisplayManager_x                                 0x10206B0
#define pinstCItemExpTransferWnd_x                                 0x10207E4
#define pinstCItemOverflowWnd_x                                    0xDAADF4
#define pinstCJournalCatWnd_x                                      0xDAB3C0
//#define pinstCJournalNPCWnd_x                                      0xDAB354
#define pinstCJournalTextWnd_x                                     0xDAB354
#define pinstCKeyRingWnd_x                                         0xDAB360
#define pinstCLargeDialogWnd_x                                     0x1022928
#define pinstCLayoutCopyWnd_x                                      0x1020B30
#define pinstCLFGuildWnd_x                                         0x1020BE0
#define pinstCLoadskinWnd_x                                        0xDAADFC
#define pinstCLootFiltersCopyWnd_x                                 0xC78C38
#define pinstCLootFiltersWnd_x                                     0xDAABAC
#define pinstCLootSettingsWnd_x                                    0xDAADB8
#define pinstCLootWnd_x                                            0xDAADB0
#define pinstCMailAddressBookWnd_x                                 0xDAB3D0
#define pinstCMailCompositionWnd_x                                 0xDAB3B4
#define pinstCMailIgnoreListWnd_x                                  0xDAB3D4
#define pinstCMailWnd_x                                            0xDAB374
#define pinstCManageLootWnd_x                                      0xDAC1E8
#define pinstCMapToolbarWnd_x                                      0xDAB310
#define pinstCMapViewWnd_x                                         0xDAAE74
#define pinstCMarketplaceWnd_x                                     0xDAAE78
#define pinstCMerchantWnd_x                                        0xDAADD8
#define pinstCMIZoneSelectWnd_x                                    0x1021418
#define pinstCMusicPlayerWnd_x                                     0xDAB364
#define pinstCNameChangeMercWnd_x                                  0xDAB3B0
#define pinstCNameChangePetWnd_x                                   0xDAB38C
#define pinstCNameChangeWnd_x                                      0xDAAE58
#define pinstCNoteWnd_x                                            0xDAAE18
#define pinstCObjectPreviewWnd_x                                   0xDAB320
#define pinstCOptionsWnd_x                                         0xDAAF08
#define pinstCPetInfoWnd_x                                         0xDAB3A4
#define pinstCPetitionQWnd_x                                       0xDAB3C4
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDAAB9C
#define pinstCPlayerWnd_x                                          0xDAAE08
#define pinstCPopupWndManager_x                                    0x1021CA8
#define pinstCProgressionSelectionWnd_x                            0x1021D58
#define pinstCPurchaseGroupWnd_x                                   0xDAB368
#define pinstCPurchaseWnd_x                                        0xDAB34C
#define pinstCPvPLeaderboardWnd_x                                  0x1021E08
#define pinstCPvPStatsWnd_x                                        0x1021EB8
#define pinstCQuantityWnd_x                                        0xDAB3CC
#define pinstCRaceChangeWnd_x                                      0xDAAE84
#define pinstCRaidOptionsWnd_x                                     0xDAAE6C
#define pinstCRaidWnd_x                                            0xDAB3E0
#define pinstCRealEstateItemsWnd_x                                 0xDAAE38
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDAAE60
#define pinstCRealEstateManageWnd_x                                0xDAADD4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDAADF0
#define pinstCRealEstatePlotSearchWnd_x                            0xDAAE10
#define pinstCRealEstatePurchaseWnd_x                              0xDAAE24
#define pinstCRespawnWnd_x                                         0xDAAE64
//#define pinstCRewardSelectionWnd_x                                 0x1022600
#define pinstCSelectorWnd_x                                        0xDAAE3C
#define pinstCSendMoneyWnd_x                                       0xDAB334
#define pinstCServerListWnd_x                                      0xDAAE30
#define pinstCSkillsSelectWnd_x                                    0xDAADC0
#define pinstCSkillsWnd_x                                          0xDAADB4
#define pinstCSocialEditWnd_x                                      0xDAB3DC
#define pinstCSocialWnd_x                                          0xDAB3E4
#define pinstCSpellBookWnd_x                                       0xDAAE34
#define pinstCStoryWnd_x                                           0xDAAB7C
#define pinstCTargetOfTargetWnd_x                                  0x1023D00
#define pinstCTargetWnd_x                                          0xDAB39C
#define pinstCTaskOverlayWnd_x                                     0xDAADF8
#define pinstCTaskSelectWnd_x                                      0x1023E58
#define pinstCTaskSomething_x                                      0xC79438
#define pinstCTaskTemplateSelectWnd_x                              0x1023F08
#define pinstCTaskWnd_x                                            0x1023FB8
#define pinstCTextEntryWnd_x                                       0xDAAB90
#define pinstCTextOverlay_x                                        0xC67F10
#define pinstCTimeLeftWnd_x                                        0xDAB3A0
#define pinstCTipWndCONTEXT_x                                      0x10241BC
#define pinstCTipWndOFDAY_x                                        0x10241B8
#define pinstCTitleWnd_x                                           0x1024268
#define pinstCTrackingWnd_x                                        0xDAB390
#define pinstCTradeskillWnd_x                                      0x10243D0
#define pinstCTradeWnd_x                                           0xDAAE20
#define pinstCTrainWnd_x                                           0xDAB3D8
#define pinstCTributeBenefitWnd_x                                  0x10245D0
#define pinstCTributeMasterWnd_x                                   0x1024680
#define pinstCTributeTrophyWnd_x                                   0x1024730
#define pinstCVideoModesWnd_x                                      0xDAB3E8
#define pinstCVoiceMacroWnd_x                                      0xF0E728
#define pinstCVoteResultsWnd_x                                     0xDAB350
#define pinstCVoteWnd_x                                            0xDAB31C
#define pinstCWebManager_x                                         0xF0E88C
#define pinstCZoneGuideWnd_x                                       0xDAADC8
#define pinstCZonePathWnd_x                                        0xDAADDC

#define pinstEQSuiteTextureLoader_x                                0xC52970
#define pinstItemIconCache_x                                       0x101D4C8
#define pinstLootFiltersManager_x                                  0xC78CE8
#define pinstRewardSelectionWnd_x                                  0x1022600

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0374C
#define __CastRay_x                                                0x58DE20
#define __CastRay2_x                                               0x58DE70
#define __ConvertItemTags_x                                        0x5A8A40
#define __CrashHandler_x                                           0x83B730
#define __EQGetTime_x                                              0x8D9300
#define __ExecuteCmd_x                                             0x586860
#define __FixHeading_x                                             0x969DA0
#define __get_bearing_x                                            0x58D960
#define __get_melee_range_x                                        0x58E060
#define __GetAnimationCache_x                                      0x6FA5F0
#define __GetGaugeValueFromEQ_x                                    0x7EDFD0
#define __GetLabelFromEQ_x                                         0x7EF740
#define __GetXTargetType_x                                         0x96B850
#define __HeadingDiff_x                                            0x969E10
#define __HelpPath_x                                               0xF0BBDC
#define __LoadFrontEnd_x                                           0x692DE0
#define __NewUIINI_x                                               0x7EDCA0
#define __pCrashHandler_x                                          0x10419F8
#define __ProcessGameEvents_x                                      0x5EAD80
#define __ProcessMouseEvent_x                                      0x5EA550
#define __SaveColors_x                                             0x537820
#define __STMLToText_x                                             0x90D0B0
#define __ToggleKeyRingItem_x                                      0x4FABF0
#define CrashDetected_x                                            0x694830
#define DrawNetStatus_x                                            0x6163A0
#define Expansion_HoT_x                                            0xE6DB74
#define Teleport_Table_Size_x                                      0xE5CBC8
#define Teleport_Table_x                                           0xE5D020
#define Util__FastTime_x                                           0x8D8EC0
#define wwsCrashReportCheckForUploader_x                           0x83C210
#define wwsCrashReportPlatformLaunchUploader_x                     0x83E8E0
#define __SaveColors_x                                             0x537820

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AA50
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4937F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4935D0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53EED0
#define AltAdvManager__IsAbilityReady_x                            0x53DF90
#define AltAdvManager__GetAAById_x                                 0x53E190
#define AltAdvManager__CanTrainAbility_x                           0x53E200
#define AltAdvManager__CanSeeAbility_x                             0x53E430

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C5A10
#define CharacterZoneClient__HasSkill_x                            0x4D0BA0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D22C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4B9D40
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B6410
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4820
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4900
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D49E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BE820
#define CharacterZoneClient__BardCastBard_x                        0x4C15B0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B64E0
#define CharacterZoneClient__GetEffect_x                           0x4B6350
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4BF830
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4BF900
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4BF950
#define CharacterZoneClient__CalcAffectChange_x                    0x4BFAA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4BFC70

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BD050

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CAA30

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F8D50
#define CButtonWnd__CButtonWnd_x                                   0x9094A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6E9030
#define CChatManager__InitContextMenu_x                            0x6E3480
#define CChatManager__FreeChatWindow_x                             0x6E7FC0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EC8F0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6E8DD0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x91DC60
#define CContextMenu__dCContextMenu_x                              0x91DE90
#define CContextMenu__AddMenuItem_x                                0x91DEA0
#define CContextMenu__RemoveMenuItem_x                             0x91E1B0
#define CContextMenu__RemoveAllMenuItems_x                         0x91E1D0
#define CContextMenu__CheckMenuItem_x                              0x91E250
#define CContextMenu__SetMenuItem_x                                0x91E0D0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x91E7F0
#define CContextMenuManager__RemoveMenu_x                          0x91E860
#define CContextMenuManager__PopupMenu_x                           0x91E920
#define CContextMenuManager__Flush_x                               0x91E790
#define CContextMenuManager__GetMenu_x                             0x495770

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BB9A0
#define CChatService__GetFriendName_x                              0x8BB9B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6E95B0
#define CChatWindow__Clear_x                                       0x6EA610
#define CChatWindow__WndNotification_x                             0x6EAB80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91B0F0
#define CComboWnd__Draw_x                                          0x91A5F0
#define CComboWnd__GetCurChoice_x                                  0x91AF30
#define CComboWnd__GetListRect_x                                   0x91AAA0
#define CComboWnd__GetTextRect_x                                   0x91B160
#define CComboWnd__InsertChoice_x                                  0x91AC30
#define CComboWnd__SetColors_x                                     0x91AC00
#define CComboWnd__SetChoice_x                                     0x91AF00
#define CComboWnd__GetItemCount_x                                  0x91AF40
#define CComboWnd__GetCurChoiceText_x                              0x91AF80

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F27E0
#define CContainerWnd__vftable_x                                   0xAC8628

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5375E0
#define CDisplay__GetClickedActor_x                                0x52A5E0
#define CDisplay__GetUserDefinedColor_x                            0x522CE0
#define CDisplay__GetWorldFilePath_x                               0x52C030
#define CDisplay__is3dON_x                                         0x5272D0
#define CDisplay__ReloadUI_x                                       0x531750
#define CDisplay__WriteTextHD2_x                                   0x5270B0
#define CDisplay__TrueDistance_x                                   0x52DC90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93D6C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x921680
#define CEditWnd__GetCharIndexPt_x                                 0x922580
#define CEditWnd__GetDisplayString_x                               0x922420
#define CEditWnd__GetHorzOffset_x                                  0x920CC0
#define CEditWnd__GetLineForPrintableChar_x                        0x9236C0
#define CEditWnd__GetSelStartPt_x                                  0x922830
#define CEditWnd__GetSTMLSafeText_x                                0x922240
#define CEditWnd__PointFromPrintableChar_x                         0x9232F0
#define CEditWnd__SelectableCharFromPoint_x                        0x923460
#define CEditWnd__SetEditable_x                                    0x922900

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5D99E0
#define CEverQuest__ClickedPlayer_x                                0x5CBDB0
#define CEverQuest__CreateTargetIndicator_x                        0x5E8070
#define CEverQuest__DeleteTargetIndicator_x                        0x5E8100
#define CEverQuest__DoTellWindow_x                                 0x4E0B90
#define CEverQuest__OutputTextToLog_x                              0x4E0DC0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C1670
#define CEverQuest__dsp_chat_x                                     0x4E1190
#define CEverQuest__trimName_x                                     0x5E46F0
#define CEverQuest__Emote_x                                        0x5DA1F0
#define CEverQuest__EnterZone_x                                    0x5D44A0
#define CEverQuest__GetBodyTypeDesc_x                              0x5DDF90
#define CEverQuest__GetClassDesc_x                                 0x5DE5D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DEBD0
#define CEverQuest__GetDeityDesc_x                                 0x5E6A80
#define CEverQuest__GetLangDesc_x                                  0x5DED90
#define CEverQuest__GetRaceDesc_x                                  0x5DE5B0
#define CEverQuest__InterpretCmd_x                                 0x5E7050
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C5860
#define CEverQuest__LMouseUp_x                                     0x5C3BE0
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6140
#define CEverQuest__RMouseUp_x                                     0x5C4B70
#define CEverQuest__SetGameState_x                                 0x5C1400
#define CEverQuest__UPCNotificationFlush_x                         0x5E45F0
#define CEverQuest__IssuePetCommand_x                              0x5E0190
#define CEverQuest__ReportSuccessfulHit_x                          0x5DAE90

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x704BA0
#define CGaugeWnd__CalcLinesFillRect_x                             0x704C00
#define CGaugeWnd__Draw_x                                          0x704290

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABA60
#define CGuild__GetGuildName_x                                     0x4AAAA0
#define CGuild__GetGuildIndex_x                                    0x4AAE30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x720110

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72CF90
#define CInvSlotMgr__MoveItem_x                                    0x72BCA0
#define CInvSlotMgr__SelectSlot_x                                  0x72D060

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72A550
#define CInvSlot__SliderComplete_x                                 0x728380
#define CInvSlot__GetItemBase_x                                    0x727CF0
#define CInvSlot__UpdateItem_x                                     0x727E60

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x72E9B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72DC80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EA220
#define CItemDisplayWnd__UpdateStrings_x                           0x73C770
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x736890
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x736D80
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73CCF0
#define CItemDisplayWnd__AboutToShow_x                             0x73C3D0
#define CItemDisplayWnd__WndNotification_x                         0x73DFB0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x821C00

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x742030

// CLabel 
#define CLabel__Draw_x                                             0x747AA0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F3930
#define CListWnd__dCListWnd_x                                      0x8F3C50
#define CListWnd__AddColumn_x                                      0x8F7F70
#define CListWnd__AddColumn1_x                                     0x8F7FC0
#define CListWnd__AddLine_x                                        0x8F8350
#define CListWnd__AddString_x                                      0x8F8150
#define CListWnd__CalculateFirstVisibleLine_x                      0x8F7D30
#define CListWnd__CalculateVSBRange_x                              0x8F7B00
#define CListWnd__ClearSel_x                                       0x8F8B30
#define CListWnd__ClearAllSel_x                                    0x8F8B90
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8F9590
#define CListWnd__Compare_x                                        0x8F7450
#define CListWnd__Draw_x                                           0x8F3D50
#define CListWnd__DrawColumnSeparators_x                           0x8F6520
#define CListWnd__DrawHeader_x                                     0x8F6990
#define CListWnd__DrawItem_x                                       0x8F6D90
#define CListWnd__DrawLine_x                                       0x8F6690
#define CListWnd__DrawSeparator_x                                  0x8F65C0
#define CListWnd__EnableLine_x                                     0x8F5E00
#define CListWnd__EnsureVisible_x                                  0x8F94B0
#define CListWnd__ExtendSel_x                                      0x8F8A60
#define CListWnd__GetColumnMinWidth_x                              0x8F5940
#define CListWnd__GetColumnWidth_x                                 0x8F58B0
#define CListWnd__GetCurSel_x                                      0x8F5240
#define CListWnd__GetItemAtPoint_x                                 0x8F6080
#define CListWnd__GetItemAtPoint1_x                                0x8F60F0
#define CListWnd__GetItemData_x                                    0x8F52C0
#define CListWnd__GetItemHeight_x                                  0x8F5680
#define CListWnd__GetItemIcon_x                                    0x8F5450
#define CListWnd__GetItemRect_x                                    0x8F5EF0
#define CListWnd__GetItemText_x                                    0x8F5300
#define CListWnd__GetSelList_x                                     0x8F8BE0
#define CListWnd__GetSeparatorRect_x                               0x8F6330
#define CListWnd__InsertLine_x                                     0x8F8740
#define CListWnd__RemoveLine_x                                     0x8F8890
#define CListWnd__SetColors_x                                      0x8F7AE0
#define CListWnd__SetColumnJustification_x                         0x8F7810
#define CListWnd__SetColumnWidth_x                                 0x8F7730
#define CListWnd__SetCurSel_x                                      0x8F89A0
#define CListWnd__SetItemColor_x                                   0x8F9160
#define CListWnd__SetItemData_x                                    0x8F9120
#define CListWnd__SetItemText_x                                    0x8F8D60
#define CListWnd__ShiftColumnSeparator_x                           0x8F78D0
#define CListWnd__Sort_x                                           0x8F75D0
#define CListWnd__ToggleSel_x                                      0x8F89D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75D130

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x780290
#define CMerchantWnd__RequestBuyItem_x                             0x780B70
#define CMerchantWnd__RequestSellItem_x                            0x7810A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x783EE0
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x7808F0
#define CMerchantWnd__ActualSelect_x                               0x789A10

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x887FD0
#define CPacketScrambler__hton_x                                   0x887FC0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x912680
#define CSidlManager__FindScreenPieceTemplate_x                    0x912A90
#define CSidlManager__FindScreenPieceTemplate1_x                   0x912880
#define CSidlManager__CreateLabel_x                                0x7E1650
#define CSidlManager__CreateXWndFromTemplate_x                     0x915B60
#define CSidlManager__CreateXWndFromTemplate1_x                    0x915D40

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x90F1F0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x90F0F0
#define CSidlScreenWnd__ConvertToRes_x                             0x933E90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x90EB80
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x90E870
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x90E940
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x90EA10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x90F690
#define CSidlScreenWnd__EnableIniStorage_x                         0x90FB60
#define CSidlScreenWnd__GetSidlPiece_x                             0x90F880
#define CSidlScreenWnd__Init1_x                                    0x90E480
#define CSidlScreenWnd__LoadIniInfo_x                              0x90FBB0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9106F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90D890
#define CSidlScreenWnd__StoreIniInfo_x                             0x910270
#define CSidlScreenWnd__StoreIniVis_x                              0x9105D0
#define CSidlScreenWnd__WndNotification_x                          0x90F5A0
#define CSidlScreenWnd__GetChildItem_x                             0x90FAE0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8FF390
#define CSidlScreenWnd__m_layoutCopy_x                             0x169B4E0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65C8A0
#define CSkillMgr__GetSkillCap_x                                   0x65CA80
#define CSkillMgr__GetNameToken_x                                  0x65C030

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x933550
#define CSliderWnd__SetValue_x                                     0x9333C0
#define CSliderWnd__SetNumTicks_x                                  0x933420

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E74B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x925540
#define CStmlWnd__CalculateHSBRange_x                              0x9265D0
#define CStmlWnd__CalculateVSBRange_x                              0x926540
#define CStmlWnd__CanBreakAtCharacter_x                            0x92A8E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92B470
#define CStmlWnd__ForceParseNow_x                                  0x925AE0
#define CStmlWnd__GetNextTagPiece_x                                0x92A840
#define CStmlWnd__GetSTMLText_x                                    0x4EEFA0
#define CStmlWnd__GetVisibleText_x                                 0x925B00
#define CStmlWnd__InitializeWindowVariables_x                      0x92B2C0
#define CStmlWnd__MakeStmlColorTag_x                               0x924CD0
#define CStmlWnd__MakeWndNotificationTag_x                         0x924D40
#define CStmlWnd__SetSTMLText_x                                    0x923DC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x92C5D0
#define CStmlWnd__UpdateHistoryString_x                            0x92B680

// CTabWnd 
#define CTabWnd__Draw_x                                            0x92FCE0
#define CTabWnd__DrawCurrentPage_x                                 0x930300
#define CTabWnd__DrawTab_x                                         0x9300D0
#define CTabWnd__GetCurrentPage_x                                  0x92F540
#define CTabWnd__GetPageInnerRect_x                                0x92F780
#define CTabWnd__GetTabInnerRect_x                                 0x92F6C0
#define CTabWnd__GetTabRect_x                                      0x92F570
#define CTabWnd__InsertPage_x                                      0x92F970
#define CTabWnd__SetPage_x                                         0x92F800
#define CTabWnd__SetPageRect_x                                     0x92FC20
#define CTabWnd__UpdatePage_x                                      0x92FF90
#define CTabWnd__GetPageFromTabIndex_x                             0x930010
#define CTabWnd__GetCurrentTabIndex_x                              0x92F530

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x742490
#define CPageWnd__SetTabText_x                                     0x93DAD0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5570

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FC1E0
#define CTextureFont__GetTextExtent_x                              0x8FC3A0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x68FB40
#define CHtmlComponentWnd__ValidateUri_x                           0x721A70
#define CHtmlWnd__SetClientCallbacks_x                             0x5FDE80
#define CHtmlWnd__AddObserver_x                                    0x5FDEA0
#define CHtmlWnd__RemoveObserver_x                                 0x5FDF00
#define Window__getProgress_x                                      0x8391C0
#define Window__getStatus_x                                        0x8391E0
#define Window__getURI_x                                           0x8391F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93A050

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8E9250

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ACCE0
#define CXStr__CXStr1_x                                            0x4E9EC0
#define CXStr__CXStr3_x                                            0x8D5430
#define CXStr__dCXStr_x                                            0x472460
#define CXStr__operator_equal_x                                    0x8D5660
#define CXStr__operator_equal1_x                                   0x8D56A0
#define CXStr__operator_plus_equal1_x                              0x8D6130

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91D880
#define CXWnd__BringToTop_x                                        0x902AF0
#define CXWnd__Center_x                                            0x902670
#define CXWnd__ClrFocus_x                                          0x9024A0
#define CXWnd__Destroy_x                                           0x902550
#define CXWnd__DoAllDrawing_x                                      0x8FEB40
#define CXWnd__DrawChildren_x                                      0x8FEB10
#define CXWnd__DrawColoredRect_x                                   0x8FEFA0
#define CXWnd__DrawTooltip_x                                       0x8FD660
#define CXWnd__DrawTooltipAtPoint_x                                0x8FD720
#define CXWnd__GetBorderFrame_x                                    0x8FEE00
#define CXWnd__GetChildWndAt_x                                     0x902B90
#define CXWnd__GetClientClipRect_x                                 0x900D90
#define CXWnd__GetScreenClipRect_x                                 0x900E60
#define CXWnd__GetScreenRect_x                                     0x901020
#define CXWnd__GetTooltipRect_x                                    0x8FEFF0
#define CXWnd__GetWindowTextA_x                                    0x496D40
#define CXWnd__IsActive_x                                          0x905A60
#define CXWnd__IsDescendantOf_x                                    0x901A30
#define CXWnd__IsReallyVisible_x                                   0x901A60
#define CXWnd__IsType_x                                            0x903210
#define CXWnd__Move_x                                              0x901AC0
#define CXWnd__Move1_x                                             0x901B80
#define CXWnd__ProcessTransition_x                                 0x902620
#define CXWnd__Refade_x                                            0x901E40
#define CXWnd__Resize_x                                            0x9020C0
#define CXWnd__Right_x                                             0x9028B0
#define CXWnd__SetFocus_x                                          0x902460
#define CXWnd__SetFont_x                                           0x9024D0
#define CXWnd__SetKeyTooltip_x                                     0x903020
#define CXWnd__SetMouseOver_x                                      0x8FFF60
#define CXWnd__StartFade_x                                         0x901910
#define CXWnd__GetChildItem_x                                      0x902D00
#define CXWnd__SetParent_x                                         0x9017D0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x934F60

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x905AA0
#define CXWndManager__DrawWindows_x                                0x905AC0
#define CXWndManager__GetKeyboardFlags_x                           0x908190
#define CXWndManager__HandleKeyboardMsg_x                          0x907D90
#define CXWndManager__RemoveWnd_x                                  0x9083E0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x908930

// CDBStr
#define CDBStr__GetString_x                                        0x521CB0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B73C0
#define EQ_Character__Cur_HP_x                                     0x4CDC30
#define EQ_Character__Cur_Mana_x                                   0x4D4EE0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BA320
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AE760
#define EQ_Character__GetFocusRangeModifier_x                      0x4AE8B0
#define EQ_Character__GetHPRegen_x                                 0x4DA4D0
#define EQ_Character__GetEnduranceRegen_x                          0x4DAB00
#define EQ_Character__GetManaRegen_x                               0x4DAF40
#define EQ_Character__Max_Endurance_x                              0x623CD0
#define EQ_Character__Max_HP_x                                     0x4CDA60
#define EQ_Character__Max_Mana_x                                   0x623B50
#define EQ_Character__doCombatAbility_x                            0x625E20
#define EQ_Character__UseSkill_x                                   0x4DCD50
#define EQ_Character__GetConLevel_x                                0x61D100
#define EQ_Character__IsExpansionFlag_x                            0x5851F0
#define EQ_Character__TotalEffect_x                                0x4C0B30
#define EQ_Character__GetPCSpellAffect_x                           0x4BAF10
#define EQ_Character__SpellDuration_x                              0x4BAA40
#define EQ_Character__FindItemByRecord_x                           0x4D3230
#define EQ_Character__GetAdjustedSkill_x                           0x4D0960
#define EQ_Character__GetBaseSkill_x                               0x4D1900
#define EQ_Character__CanUseItem_x                                 0x4D51F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8A6EA0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x639B60

//PcClient
#define PcClient__PcClient_x                                       0x61A9E0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B51A0
#define CCharacterListWnd__EnterWorld_x                            0x4B4BE0
#define CCharacterListWnd__Quit_x                                  0x4B48F0
#define CCharacterListWnd__UpdateList_x                            0x4B4D70

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5FF0B0
#define EQ_Item__CreateItemTagString_x                             0x8822C0
#define EQ_Item__IsStackable_x                                     0x8864C0
#define EQ_Item__GetImageNum_x                                     0x883B30
#define EQ_Item__CreateItemClient_x                                0x5FE280
#define EQ_Item__GetItemValue_x                                    0x884C00
#define EQ_Item__ValueSellMerchant_x                               0x887B70
#define EQ_Item__IsKeyRingItem_x                                   0x885E90
#define EQ_Item__CanGoInBag_x                                      0x5FF1D0
#define EQ_Item__GetMaxItemCount_x                                 0x884D00
#define EQ_Item__GetHeldItem_x                                     0x883940
#define EQ_Item__GetAugmentFitBySlot_x                             0x881E10

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x53FBB0
#define EQ_LoadingS__Array_x                                       0xBDADE8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6245D0
#define EQ_PC__GetAlternateAbilityId_x                             0x890BC0
#define EQ_PC__GetCombatAbility_x                                  0x891230
#define EQ_PC__GetCombatAbilityTimer_x                             0x8912A0
#define EQ_PC__GetItemRecastTimer_x                                0x6263A0
#define EQ_PC__HasLoreItem_x                                       0x61D870
#define EQ_PC__AlertInventoryChanged_x                             0x61CBD0
#define EQ_PC__GetPcZoneClient_x                                   0x6481F0
#define EQ_PC__RemoveMyAffect_x                                    0x629550
#define EQ_PC__GetKeyRingItems_x                                   0x891B40
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8918C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x891E30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58B3A0
#define EQItemList__add_object_x                                   0x5B6DA0
#define EQItemList__add_item_x                                     0x58B9B0
#define EQItemList__delete_item_x                                  0x58BA00
#define EQItemList__FreeItemList_x                                 0x58B900

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51F310

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63B3E0
#define EQPlayer__dEQPlayer_x                                      0x62EC00
#define EQPlayer__DoAttack_x                                       0x642F00
#define EQPlayer__EQPlayer_x                                       0x62F2B0
#define EQPlayer__SetNameSpriteState_x                             0x633450
#define EQPlayer__SetNameSpriteTint_x                              0x6342E0
#define PlayerBase__HasProperty_j_x                                0x968180
#define EQPlayer__IsTargetable_x                                   0x968620
#define EQPlayer__CanSee_x                                         0x968480
#define EQPlayer__CanSee1_x                                        0x968550
#define PlayerBase__GetVisibilityLineSegment_x                     0x968240

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x645CC0
#define PlayerZoneClient__GetLevel_x                               0x648230
#define PlayerZoneClient__IsValidTeleport_x                        0x5B7EF0
#define PlayerZoneClient__LegalPlayerRace_x                        0x539390

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63E030
#define EQPlayerManager__GetSpawnByName_x                          0x63E050
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63E0E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x602A00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x602A40
#define KeypressHandler__ClearCommandStateArray_x                  0x603E30
#define KeypressHandler__HandleKeyDown_x                           0x603E50
#define KeypressHandler__HandleKeyUp_x                             0x603EF0
#define KeypressHandler__SaveKeymapping_x                          0x6042D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x758FC0
#define MapViewMap__SaveEx_x                                       0x75C360
#define MapViewMap__SetZoom_x                                      0x760A30

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A4D90

// StringTable 
#define StringTable__getString_x                                   0x89FCB0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6291C0
#define PcZoneClient__RemovePetEffect_x                            0x6297F0
#define PcZoneClient__HasAlternateAbility_x                        0x623990
#define PcZoneClient__GetCurrentMod_x                              0x4DFCA0
#define PcZoneClient__GetModCap_x                                  0x4DFBA0
#define PcZoneClient__CanEquipItem_x                               0x623F60
#define PcZoneClient__GetItemByID_x                                0x626810
#define PcZoneClient__GetItemByItemClass_x                         0x6268A0
#define PcZoneClient__RemoveBuffEffect_x                           0x629810

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BCAD0

//IconCache
#define IconCache__GetIcon_x                                       0x6F9E80

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F1980
#define CContainerMgr__CloseContainer_x                            0x6F1C50

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B3EB0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F7540

//CLootWnd
#define CLootWnd__LootAll_x                                        0x74F410
#define CLootWnd__RequestLootSlot_x                                0x74E7C0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5581B0
#define EQ_Spell__SpellAffects_x                                   0x558640
#define EQ_Spell__SpellAffectBase_x                                0x5583E0
#define EQ_Spell__IsStackable_x                                    0x4C5340
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5190
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B2810
#define EQ_Spell__IsSPAStacking_x                                  0x559220
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x558990
#define EQ_Spell__IsNoRemove_x                                     0x4C5320
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x559230
#define __IsResEffectSpell_x                                       0x4C46B0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A96D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B0CE0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7F96D0
#define CTargetWnd__WndNotification_x                              0x7F8F60
#define CTargetWnd__RefreshTargetBuffs_x                           0x7F9230
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7F80B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FDDA0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5536F0
#define EqSoundManager__PlayScriptMp3_x                            0x553850

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x510C30

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9202F0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x547870
#define CAltAbilityData__GetMercMaxRank_x                          0x547810
#define CAltAbilityData__GetMaxRank_x                              0x53D080

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F5650

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5170
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F70F0
#define CharacterBase__CreateItemIndex_x                           0x5FD490
#define CharacterBase__GetItemPossession_x                         0x4B26C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8B93F0
#define CharacterBase__GetEffectId_x                               0x4C5120

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DA010
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DA830

//messages
#define msg_spell_worn_off_x                                       0x57DB40
#define msg_new_text_x                                             0x572D10
#define __msgTokenTextParam_x                                      0x580190
#define msgTokenText_x                                             0x5803E0

//SpellManager
#define SpellManager__vftable_x                                    0xAA37A0
#define SpellManager__SpellManager_x                               0x663590
#define Spellmanager__LoadTextSpells_x                             0x663910

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96C140

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F77A0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x583910
#define ItemGlobalIndex__IsEquippedLocation_x                      0x616200
#define ItemGlobalIndex__IsValidIndex_x                            0x4F7800

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B16C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B1940

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x747DE0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F60D0
#define CCursorAttachment__Deactivate_x                            0x6F70B0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x932760
#define CEQSuiteTextureLoader__GetTexture_x                        0x932420

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F4770

//IString
#define IString__Append_x                                          0x4E9000

//Camera
#define CDisplay__cameraType_x                                     0xDAABA8
#define EverQuest__Cameras_x                                       0xE6DE8C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FCE70
#define LootFiltersManager__GetItemFilterData_x                    0x4FC760
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FC790
#define LootFiltersManager__SetItemLootFilter_x                    0x4FC9B0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A1D40

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