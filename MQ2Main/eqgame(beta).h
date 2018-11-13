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
#define __ExpectedVersionDate                                     "Nov 11 2018"
#define __ExpectedVersionTime                                     "04:42:23"
#define __ActualVersionDate_x                                      0xAC7B8C
#define __ActualVersionTime_x                                      0xAC7B80

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60E900
#define __MemChecker1_x                                            0x8E2F20
#define __MemChecker2_x                                            0x69DA10
#define __MemChecker3_x                                            0x69D960
#define __MemChecker4_x                                            0x83A650
#define __EncryptPad0_x                                            0xBFA998
#define __EncryptPad1_x                                            0xC58C28
#define __EncryptPad2_x                                            0xC0B520
#define __EncryptPad3_x                                            0xC0B120
#define __EncryptPad4_x                                            0xC49498
#define __EncryptPad5_x                                            0xF14B2C
#define __AC1_x                                                    0x7F6C36
#define __AC2_x                                                    0x5C978F
#define __AC3_x                                                    0x5D061F
#define __AC4_x                                                    0x5D4490
#define __AC5_x                                                    0x5DA64F
#define __AC6_x                                                    0x5DEB86
#define __AC7_x                                                    0x5C9200
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1BDB5C

// Direct Input
#define DI8__Main_x                                                0xF14B50
#define DI8__Keyboard_x                                            0xF14B54
#define DI8__Mouse_x                                               0xF14B18
#define DI8__Mouse_Copy_x                                          0xE72874
#define DI8__Mouse_Check_x                                         0xF15A18
#define __AutoSkillArray_x                                         0xE7378C
#define __Attack_x                                                 0xF1158F
#define __Autofire_x                                               0xF11590
#define __BindList_x                                               0xBE9590
#define g_eqCommandStates_x                                        0xBEA300
#define __Clicks_x                                                 0xE7292C
#define __CommandList_x                                            0xBEAEB8
#define __CurrentMapLabel_x                                        0x102713C
#define __CurrentSocial_x                                          0xBD4730
#define __DoAbilityList_x                                          0xEA90B0
#define __do_loot_x                                                0x597000
#define __DrawHandler_x                                            0x16A3B10
#define __GroupCount_x                                             0xE63222
#define __Guilds_x                                                 0xE69080
#define __gWorld_x                                                 0xE63204
#define __HWnd_x                                                   0xF14B1C
#define __heqmain_x                                                0x101FD74
#define __InChatMode_x                                             0xE7285C
#define __LastTell_x                                               0xE747AC
#define __LMouseHeldTime_x                                         0xE72998
#define __Mouse_x                                                  0xF14B38
#define __MouseLook_x                                              0xE728F2
#define __MouseEventTime_x                                         0xF12048
#define __gpbCommandEvent_x                                        0xE62CA0
#define __NetStatusToggle_x                                        0xE728F5
#define __PCNames_x                                                0xE73D6C
#define __RangeAttackReady_x                                       0xE73A70
#define __RMouseHeldTime_x                                         0xE72994
#define __RunWalkState_x                                           0xE72860
#define __ScreenMode_x                                             0xDB0C20
#define __ScreenX_x                                                0xE72814
#define __ScreenY_x                                                0xE72810
#define __ScreenXMax_x                                             0xE72818
#define __ScreenYMax_x                                             0xE7281C
#define __ServerHost_x                                             0xE62ED3
#define __ServerName_x                                             0xEA9070
#define __ShiftKeyDown_x                                           0xE72EEC
#define __ShowNames_x                                              0xE73C2C
#define __Socials_x                                                0xEA9170
#define __SubscriptionType_x                                       0x1068C8C
#define __TargetAggroHolder_x                                      0x1029AF8
#define __ZoneType_x                                               0xE72CF0
#define __GroupAggro_x                                             0x1029B38
#define __LoginName_x                                              0xF153AC
#define __Inviter_x                                                0xF1150C
#define __AttackOnAssist_x                                         0xE73BE8
#define __UseTellWindows_x                                         0xE73F04
#define __gfMaxZoomCameraDistance_x                                0xABCF68
#define __gfMaxCameraDistance_x                                    0xAEA5AC
#define __pulAutoRun_x                                             0xE72910
#define __pulForward_x                                             0xE73F3C
#define __pulBackward_x                                            0xE73F40
#define __pulTurnRight_x                                           0xE73F44
#define __pulTurnLeft_x                                            0xE73F48
#define __pulStrafeLeft_x                                          0xE73F4C
#define __pulStrafeRight_x                                         0xE73F50
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE65418
#define instEQZoneInfo_x                                           0xE72AE8
#define instKeypressHandler_x                                      0xF11FF8
#define pinstActiveBanker_x                                        0xE62D80
#define pinstActiveCorpse_x                                        0xE62D78
#define pinstActiveGMaster_x                                       0xE62D7C
#define pinstActiveMerchant_x                                      0xE62D74
#define pinstAggroInfo_x                                           0xC6F418
#define pinstAltAdvManager_x                                       0xDB1DC0
#define pinstAuraMgr_x                                             0xC80100
#define pinstBandageTarget_x                                       0xE62D90
#define pinstCamActor_x                                            0xDB0C14
#define pinstCDBStr_x                                              0xDB0AF4
#define pinstCDisplay_x                                            0xE631E4
#define pinstCEverQuest_x                                          0xF14C70
#define pinstEverQuestInfo_x                                       0xE72808
#define pinstCharData_x                                            0xE631F0
#define pinstCharSpawn_x                                           0xE62DC8
#define pinstControlledMissile_x                                   0xE631EC
#define pinstControlledPlayer_x                                    0xE62DC8
#define pinstCResolutionHandler_x                                  0x16A3D40
#define pinstCSidlManager_x                                        0x16A2BD4
#define pinstCXWndManager_x                                        0x16A2BC8
#define instDynamicZone_x                                          0xE68F58
#define pinstDZMember_x                                            0xE69068
#define pinstDZTimerInfo_x                                         0xE6906C
#define pinstEQItemList_x                                          0xE61608
#define pinstEQObjectList_x                                        0xE627F8
#define instEQMisc_x                                               0xDB0A30
#define pinstEQSoundManager_x                                      0xDB2620
#define pinstEQSpellStrings_x                                      0xC7D550
#define instExpeditionLeader_x                                     0xE68FA2
#define instExpeditionName_x                                       0xE68FE2
#define pinstGroup_x                                               0xE6321E
#define pinstImeManager_x                                          0x16A2BCC
#define pinstLocalPlayer_x                                         0xE62D70
#define pinstMercenaryData_x                                       0xF127F4
#define pinstMercenaryStats_x                                      0x1029C44
#define pinstMercAltAbilities_x                                    0xDB2390
#define pinstModelPlayer_x                                         0xE62D88
#define pinstPCData_x                                              0xE631F0
#define pinstRealEstateItems_x                                     0xF13CD8
#define pinstSkillMgr_x                                            0xF13DA8
#define pinstSpawnManager_x                                        0xF13398
#define pinstSpellManager_x                                        0xF13F80
#define pinstSpellSets_x                                           0xF0A1B8
#define pinstStringTable_x                                         0xE62B24
#define pinstSwitchManager_x                                       0xE629B8
#define pinstTarget_x                                              0xE62DC4
#define pinstTargetObject_x                                        0xE62FDC
#define pinstTargetSwitch_x                                        0xE631FC
#define pinstTaskMember_x                                          0xDB08C4
#define pinstTrackTarget_x                                         0xE62DD0
#define pinstTradeTarget_x                                         0xE62D84
#define instTributeActive_x                                        0xDB0A55
#define pinstViewActor_x                                           0xDB0C10
#define pinstWorldData_x                                           0xE631F4
#define pinstZoneAddr_x                                            0xE72D88
#define pinstPlayerPath_x                                          0xF13430
#define pinstTargetIndicator_x                                     0xF141E8
#define pinstCTargetManager_x                                      0xF14280
#define EQObject_Top_x                                             0xE62D6C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDB13F4
#define pinstCAchievementsWnd_x                                    0xDB0C44
#define pinstCActionsWnd_x                                         0xDB0BB8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDB13FC
#define pinstCAdvancedLootWnd_x                                    0xDB13D0
#define pinstCAdventureLeaderboardWnd_x                            0x1020910
#define pinstCAdventureRequestWnd_x                                0x10209C0
#define pinstCAdventureStatsWnd_x                                  0x1020A70
#define pinstCAggroMeterWnd_x                                      0xDB0C4C
#define pinstCAlarmWnd_x                                           0xDB0C0C
#define pinstCAlertHistoryWnd_x                                    0xDB0BF4
#define pinstCAlertStackWnd_x                                      0xDB141C
#define pinstCAlertWnd_x                                           0xDB0B98
#define pinstCAltStorageWnd_x                                      0x1020DD0
#define pinstCAudioTriggersWindow_x                                0xC6F8A8
#define pinstCAuraWnd_x                                            0xDB0C48
#define pinstCAvaZoneWnd_x                                         0xDB0BFC
#define pinstCBandolierWnd_x                                       0xDB0C90
#define pinstCBankWnd_x                                            0xDB0F78
#define pinstCBarterMerchantWnd_x                                  0x1022010
#define pinstCBarterSearchWnd_x                                    0x10220C0
#define pinstCBarterWnd_x                                          0x1022170
#define pinstCBazaarConfirmationWnd_x                              0xDB1418
#define pinstCBazaarSearchWnd_x                                    0xDB0BCC
#define pinstCBazaarWnd_x                                          0xDB0C80
#define pinstCBlockedBuffWnd_x                                     0xDB0EE8
#define pinstCBlockedPetBuffWnd_x                                  0xDB1388
#define pinstCBodyTintWnd_x                                        0xDB0B94
#define pinstCBookWnd_x                                            0xDB0CB8
#define pinstCBreathWnd_x                                          0xDB13F8
#define pinstCBuffWindowNORMAL_x                                   0xDB0CCC
#define pinstCBuffWindowSHORT_x                                    0xDB0ED0
#define pinstCBugReportWnd_x                                       0xDB13F0
#define pinstCButtonWnd_x                                          0x16A2DF8
#define pinstCCastingWnd_x                                         0xDB13EC
#define pinstCCastSpellWnd_x                                       0xDB0BDC
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDB1400
#define pinstCChatWindowManager_x                                  0x1022C30
#define pinstCClaimWnd_x                                           0x1022D88
#define pinstCColorPickerWnd_x                                     0xDB0BA0
#define pinstCCombatAbilityWnd_x                                   0xDB0C5C
#define pinstCCombatSkillsSelectWnd_x                              0xDB0BB4
#define pinstCCompassWnd_x                                         0xDB140C
#define pinstCConfirmationDialog_x                                 0x1027C88
#define pinstCContainerMgr_x                                       0xDB0C74
#define pinstCContextMenuManager_x                                 0x16A2B88
#define pinstCCursorAttachment_x                                   0xDB13E0
#define pinstCDistillerInfo_x                                      0x1026694
#define pinstCDynamicZoneWnd_x                                     0x1023350
#define pinstCEditLabelWnd_x                                       0xDB0CC0
#define pinstCEQMainWnd_x                                          0x1023598
#define pinstCEventCalendarWnd_x                                   0xDB0CA0
#define pinstCExtendedTargetWnd_x                                  0xDB0C3C
#define pinstCFacePick_x                                           0xDB0B9C
#define pinstCFellowshipWnd_x                                      0x1023798
#define pinstCFileSelectionWnd_x                                   0xDB1390
#define pinstCFindItemWnd_x                                        0xDB0CA8
#define pinstCFindLocationWnd_x                                    0x10238F0
#define pinstCFriendsWnd_x                                         0xDB0BC8
#define pinstCGemsGameWnd_x                                        0xDB0BE0
#define pinstCGiveWnd_x                                            0xDB0CB0
#define pinstCGroupSearchFiltersWnd_x                              0xDB0C64
#define pinstCGroupSearchWnd_x                                     0x1023CE8
#define pinstCGroupWnd_x                                           0x1023D98
#define pinstCGuildBankWnd_x                                       0xE73BCC
#define pinstCGuildCreationWnd_x                                   0x1023EF8
#define pinstCGuildMgmtWnd_x                                       0x1023FA8
#define pinstCharacterCreation_x                                   0xDB0C58
#define pinstCHelpWnd_x                                            0xDB0BF8
#define pinstCHeritageSelectionWnd_x                               0xDB0BA8
#define pinstCHotButtonWnd_x                                       0x1026100
#define pinstCHotButtonWnd1_x                                      0x1026100
#define pinstCHotButtonWnd2_x                                      0x1026104
#define pinstCHotButtonWnd3_x                                      0x1026108
#define pinstCHotButtonWnd4_x                                      0x102610C
#define pinstCIconSelectionWnd_x                                   0xDB1394
#define pinstCInspectWnd_x                                         0xDB138C
#define pinstCInventoryWnd_x                                       0xDB0C94
#define pinstCInvSlotMgr_x                                         0xDB0C2C
#define pinstCItemDisplayManager_x                                 0x1026690
#define pinstCItemExpTransferWnd_x                                 0x10267C0
#define pinstCItemOverflowWnd_x                                    0xDB0BD0
#define pinstCJournalCatWnd_x                                      0xDB13DC
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDB0EF8
#define pinstCKeyRingWnd_x                                         0xDB0EE0
#define pinstCLargeDialogWnd_x                                     0x1028908
#define pinstCLayoutCopyWnd_x                                      0x1026B10
#define pinstCLFGuildWnd_x                                         0x1026BC0
#define pinstCLoadskinWnd_x                                        0xDB0BF0
#define pinstCLootFiltersCopyWnd_x                                 0xC80988
#define pinstCLootFiltersWnd_x                                     0xDB0BAC
#define pinstCLootSettingsWnd_x                                    0xDB0BC0
#define pinstCLootWnd_x                                            0xDB1420
#define pinstCMailAddressBookWnd_x                                 0xDB1398
#define pinstCMailCompositionWnd_x                                 0xDB0F74
#define pinstCMailIgnoreListWnd_x                                  0xDB139C
#define pinstCMailWnd_x                                            0xDB0ED4
#define pinstCManageLootWnd_x                                      0xDB2238
#define pinstCMapToolbarWnd_x                                      0xDB0C9C
#define pinstCMapViewWnd_x                                         0xDB0C70
#define pinstCMarketplaceWnd_x                                     0xDB0CAC
#define pinstCMerchantWnd_x                                        0xDB0BB0
#define pinstCMIZoneSelectWnd_x                                    0x10273F8
#define pinstCMusicPlayerWnd_x                                     0xDB0EDC
#define pinstCNameChangeMercWnd_x                                  0xDB13E4
#define pinstCNameChangePetWnd_x                                   0xDB13CC
#define pinstCNameChangeWnd_x                                      0xDB0C78
#define pinstCNoteWnd_x                                            0xDB0BEC
#define pinstCObjectPreviewWnd_x                                   0xDB0ED8
#define pinstCOptionsWnd_x                                         0xDB0CA4
#define pinstCPetInfoWnd_x                                         0xDB0EFC
#define pinstCPetitionQWnd_x                                       0xDB13E8
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDB0B90
#define pinstCPlayerWnd_x                                          0xDB0BC4
#define pinstCPopupWndManager_x                                    0x1027C88
#define pinstCProgressionSelectionWnd_x                            0x1027D38
#define pinstCPurchaseGroupWnd_x                                   0xDB1380
#define pinstCPurchaseWnd_x                                        0xDB0EE4
#define pinstCPvPLeaderboardWnd_x                                  0x1027DE8
#define pinstCPvPStatsWnd_x                                        0x1027E98
#define pinstCQuantityWnd_x                                        0xDB13C8
#define pinstCRaceChangeWnd_x                                      0xDB0CBC
#define pinstCRaidOptionsWnd_x                                     0xDB0C6C
#define pinstCRaidWnd_x                                            0xDB13D4
#define pinstCRealEstateItemsWnd_x                                 0xDB0C50
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDB0C98
#define pinstCRealEstateManageWnd_x                                0xDB0BD4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDB0BE4
#define pinstCRealEstatePlotSearchWnd_x                            0xDB0C00
#define pinstCRealEstatePurchaseWnd_x                              0xDB0C30
#define pinstCRespawnWnd_x                                         0xDB0C60
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDB0C40
#define pinstCSendMoneyWnd_x                                       0xDB0CC4
#define pinstCServerListWnd_x                                      0xDB0C54
#define pinstCSkillsSelectWnd_x                                    0xDB0BA4
#define pinstCSkillsWnd_x                                          0xDB1410
#define pinstCSocialEditWnd_x                                      0xDB13D8
#define pinstCSocialWnd_x                                          0xDB1404
#define pinstCSpellBookWnd_x                                       0xDB0C38
#define pinstCStoryWnd_x                                           0xDB1408
#define pinstCTargetOfTargetWnd_x                                  0x1029CC8
#define pinstCTargetWnd_x                                          0xDB0EF4
#define pinstCTaskOverlayWnd_x                                     0xDB0C04
#define pinstCTaskSelectWnd_x                                      0x1029E20
#define pinstCTaskSomething_x                                      0xC81188
#define pinstCTaskTemplateSelectWnd_x                              0x1029ED0
#define pinstCTaskWnd_x                                            0x1029F80
#define pinstCTextEntryWnd_x                                       0xDB1414
#define pinstCTextOverlay_x                                        0xC6FBB8
#define pinstCTimeLeftWnd_x                                        0xDB13B8
#define pinstCTipWndCONTEXT_x                                      0x102A184
#define pinstCTipWndOFDAY_x                                        0x102A180
#define pinstCTitleWnd_x                                           0x102A230
#define pinstCTrackingWnd_x                                        0xDB0EEC
#define pinstCTradeskillWnd_x                                      0x102A398
#define pinstCTradeWnd_x                                           0xDB0C08
#define pinstCTrainWnd_x                                           0xDB13C4
#define pinstCTributeBenefitWnd_x                                  0x102A598
#define pinstCTributeMasterWnd_x                                   0x102A648
#define pinstCTributeTrophyWnd_x                                   0x102A6F8
#define pinstCVideoModesWnd_x                                      0xDB0C68
#define pinstCVoiceMacroWnd_x                                      0xF147B0
#define pinstCVoteResultsWnd_x                                     0xDB1384
#define pinstCVoteWnd_x                                            0xDB0EF0
#define pinstCWebManager_x                                         0xF14914
#define pinstCZoneGuideWnd_x                                       0xDB0BD8
#define pinstCZonePathWnd_x                                        0xDB0BE8

#define pinstEQSuiteTextureLoader_x                                0xC5A6F8
#define pinstItemIconCache_x                                       0x1023550
#define pinstLootFiltersManager_x                                  0xC80A38
#define pinstRewardSelectionWnd_x                                  0x10285E0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0B114
#define __CastRay_x                                                0x592520
#define __CastRay2_x                                               0x592570
#define __ConvertItemTags_x                                        0x5AD120
#define __CrashHandler_x                                           0x843FD0
#define __EQGetTime_x                                              0x8E2A10
#define __ExecuteCmd_x                                             0x58AEA0
#define __FixHeading_x                                             0x973040
#define __get_bearing_x                                            0x592070
#define __get_melee_range_x                                        0x592760
#define __GetAnimationCache_x                                      0x7017B0
#define __GetGaugeValueFromEQ_x                                    0x7F5450
#define __GetLabelFromEQ_x                                         0x7F6BC0
#define __GetXTargetType_x                                         0x974B10
#define __HeadingDiff_x                                            0x9730B0
#define __HelpPath_x                                               0xF11C64
#define __LoadFrontEnd_x                                           0x699870
#define __NewUIINI_x                                               0x7F5120
#define __pCrashHandler_x                                          0x1047AE8
#define __ProcessGameEvents_x                                      0x5EFDB0
#define __ProcessMouseEvent_x                                      0x5EF570
#define __SaveColors_x                                             0x53BB10
#define __STMLToText_x                                             0x9165E0
#define __ToggleKeyRingItem_x                                      0x4FEAA0
#define CrashDetected_x                                            0x69B360
#define DrawNetStatus_x                                            0x61BE80
#define Expansion_HoT_x                                            0xE73BD4
#define Teleport_Table_Size_x                                      0xE62D2C
#define Teleport_Table_x                                           0xE63418
#define Util__FastTime_x                                           0x8E25D0
#define wwsCrashReportCheckForUploader_x                           0x8449E0
#define wwsCrashReportPlatformLaunchUploader_x                     0x8470A0
#define __HandleMouseWheel_x                                       0x69DAC0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B170
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493FE0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493DA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x543470
#define AltAdvManager__IsAbilityReady_x                            0x5424F0
#define AltAdvManager__GetAAById_x                                 0x5426F0
#define AltAdvManager__CanTrainAbility_x                           0x542760
#define AltAdvManager__CanSeeAbility_x                             0x542990

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6B90
#define CharacterZoneClient__HasSkill_x                            0x4D1850
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2F70
#define CharacterZoneClient__IsStackBlocked_x                      0x4BAEF0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7670
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5910
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D59F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5AD0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF9D0
#define CharacterZoneClient__BardCastBard_x                        0x4C2640
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7740
#define CharacterZoneClient__GetEffect_x                           0x4B75B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C09D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0AA0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0AF0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0C40
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0E10

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C3C50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D14A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FE630
#define CButtonWnd__CButtonWnd_x                                   0x9129E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F0210
#define CChatManager__InitContextMenu_x                            0x6EA2B0
#define CChatManager__FreeChatWindow_x                             0x6EF120
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F3AE0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EFFB0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9270D0
#define CContextMenu__dCContextMenu_x                              0x927300
#define CContextMenu__AddMenuItem_x                                0x927310
#define CContextMenu__RemoveMenuItem_x                             0x927620
#define CContextMenu__RemoveAllMenuItems_x                         0x927640
#define CContextMenu__CheckMenuItem_x                              0x9276C0
#define CContextMenu__SetMenuItem_x                                0x927540
#define CContextMenu__AddSeparator_x                               0x9274A0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x927C60
#define CContextMenuManager__RemoveMenu_x                          0x927CD0
#define CContextMenuManager__PopupMenu_x                           0x927D90
#define CContextMenuManager__Flush_x                               0x927C00
#define CContextMenuManager__GetMenu_x                             0x496110

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C3280
#define CChatService__GetFriendName_x                              0x8C3290

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F0790
#define CChatWindow__Clear_x                                       0x6F17F0
#define CChatWindow__WndNotification_x                             0x6F1D60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x924560
#define CComboWnd__Draw_x                                          0x923A60
#define CComboWnd__GetCurChoice_x                                  0x9243A0
#define CComboWnd__GetListRect_x                                   0x923F10
#define CComboWnd__GetTextRect_x                                   0x9245D0
#define CComboWnd__InsertChoice_x                                  0x9240A0
#define CComboWnd__SetColors_x                                     0x924070
#define CComboWnd__SetChoice_x                                     0x924370
#define CComboWnd__GetItemCount_x                                  0x9243B0
#define CComboWnd__GetCurChoiceText_x                              0x9243F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F99C0
#define CContainerWnd__vftable_x                                   0xAD0F88
#define CContainerWnd__SetContainer_x                              0x6FAF30

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53B8D0
#define CDisplay__GetClickedActor_x                                0x52E8E0
#define CDisplay__GetUserDefinedColor_x                            0x526FC0
#define CDisplay__GetWorldFilePath_x                               0x530330
#define CDisplay__is3dON_x                                         0x52B5B0
#define CDisplay__ReloadUI_x                                       0x535A50
#define CDisplay__WriteTextHD2_x                                   0x52B390
#define CDisplay__TrueDistance_x                                   0x531F90
#define CDisplay__SetViewActor_x                                   0x52E230
#define CDisplay__GetFloorHeight_x                                 0x52B670
#define CDisplay__SetRenderWindow_x                                0x529FA0
#define CDisplay__ToggleScreenshotMode_x                           0x52DD00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x946800

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92B7C0
#define CEditWnd__GetCharIndexPt_x                                 0x92C6C0
#define CEditWnd__GetDisplayString_x                               0x92C560
#define CEditWnd__GetHorzOffset_x                                  0x92AE00
#define CEditWnd__GetLineForPrintableChar_x                        0x92D800
#define CEditWnd__GetSelStartPt_x                                  0x92C970
#define CEditWnd__GetSTMLSafeText_x                                0x92C380
#define CEditWnd__PointFromPrintableChar_x                         0x92D430
#define CEditWnd__SelectableCharFromPoint_x                        0x92D5A0
#define CEditWnd__SetEditable_x                                    0x92CA40

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DE0B0
#define CEverQuest__ClickedPlayer_x                                0x5D0400
#define CEverQuest__CreateTargetIndicator_x                        0x5ED060
#define CEverQuest__DeleteTargetIndicator_x                        0x5ED0F0
#define CEverQuest__DoTellWindow_x                                 0x4E2C40
#define CEverQuest__OutputTextToLog_x                              0x4E2E70
#define CEverQuest__DropHeldItemOnGround_x                         0x5C5CC0
#define CEverQuest__dsp_chat_x                                     0x4E3200
#define CEverQuest__trimName_x                                     0x5E95D0
#define CEverQuest__Emote_x                                        0x5DE8C0
#define CEverQuest__EnterZone_x                                    0x5D8AA0
#define CEverQuest__GetBodyTypeDesc_x                              0x5E2E70
#define CEverQuest__GetClassDesc_x                                 0x5E34B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E3AB0
#define CEverQuest__GetDeityDesc_x                                 0x5EB9B0
#define CEverQuest__GetLangDesc_x                                  0x5E3C70
#define CEverQuest__GetRaceDesc_x                                  0x5E3490
#define CEverQuest__InterpretCmd_x                                 0x5EBF80
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C9EB0
#define CEverQuest__LMouseUp_x                                     0x5C8230
#define CEverQuest__RightClickedOnPlayer_x                         0x5CA790
#define CEverQuest__RMouseUp_x                                     0x5C91C0
#define CEverQuest__SetGameState_x                                 0x5C5A50
#define CEverQuest__UPCNotificationFlush_x                         0x5E94D0
#define CEverQuest__IssuePetCommand_x                              0x5E5070
#define CEverQuest__ReportSuccessfulHit_x                          0x5DFCC0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70B940
#define CGaugeWnd__CalcLinesFillRect_x                             0x70B9A0
#define CGaugeWnd__Draw_x                                          0x70B040

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC640
#define CGuild__GetGuildName_x                                     0x4AB720
#define CGuild__GetGuildIndex_x                                    0x4ABAB0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x726D60

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FE9F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x733D20
#define CInvSlotMgr__MoveItem_x                                    0x732A40
#define CInvSlotMgr__SelectSlot_x                                  0x733DF0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7312E0
#define CInvSlot__SliderComplete_x                                 0x72F040
#define CInvSlot__GetItemBase_x                                    0x72E9C0
#define CInvSlot__UpdateItem_x                                     0x72EB30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x735720
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7349F0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7352A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F1640
#define CItemDisplayWnd__UpdateStrings_x                           0x743600
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73D670
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73DBA0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x743BE0
#define CItemDisplayWnd__AboutToShow_x                             0x743250
#define CItemDisplayWnd__WndNotification_x                         0x745130

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x829000

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x749240

// CLabel 
#define CLabel__Draw_x                                             0x74ED40

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FCF30
#define CListWnd__dCListWnd_x                                      0x8FD250
#define CListWnd__AddColumn_x                                      0x901550
#define CListWnd__AddColumn1_x                                     0x9015A0
#define CListWnd__AddLine_x                                        0x901930
#define CListWnd__AddString_x                                      0x901730
#define CListWnd__CalculateFirstVisibleLine_x                      0x901310
#define CListWnd__CalculateVSBRange_x                              0x9010E0
#define CListWnd__ClearSel_x                                       0x902110
#define CListWnd__ClearAllSel_x                                    0x902170
#define CListWnd__CloseAndUpdateEditWindow_x                       0x902B80
#define CListWnd__Compare_x                                        0x900A30
#define CListWnd__Draw_x                                           0x8FD350
#define CListWnd__DrawColumnSeparators_x                           0x8FFB10
#define CListWnd__DrawHeader_x                                     0x8FFF70
#define CListWnd__DrawItem_x                                       0x900370
#define CListWnd__DrawLine_x                                       0x8FFC70
#define CListWnd__DrawSeparator_x                                  0x8FFBB0
#define CListWnd__EnableLine_x                                     0x8FF400
#define CListWnd__EnsureVisible_x                                  0x902AA0
#define CListWnd__ExtendSel_x                                      0x902040
#define CListWnd__GetColumnMinWidth_x                              0x8FEF40
#define CListWnd__GetColumnWidth_x                                 0x8FEEB0
#define CListWnd__GetCurSel_x                                      0x8FE840
#define CListWnd__GetItemAtPoint_x                                 0x8FF670
#define CListWnd__GetItemAtPoint1_x                                0x8FF6E0
#define CListWnd__GetItemData_x                                    0x8FE8C0
#define CListWnd__GetItemHeight_x                                  0x8FEC80
#define CListWnd__GetItemIcon_x                                    0x8FEA50
#define CListWnd__GetItemRect_x                                    0x8FF4F0
#define CListWnd__GetItemText_x                                    0x8FE900
#define CListWnd__GetSelList_x                                     0x9021C0
#define CListWnd__GetSeparatorRect_x                               0x8FF920
#define CListWnd__InsertLine_x                                     0x901D20
#define CListWnd__RemoveLine_x                                     0x901E70
#define CListWnd__SetColors_x                                      0x9010C0
#define CListWnd__SetColumnJustification_x                         0x900DF0
#define CListWnd__SetColumnWidth_x                                 0x900D10
#define CListWnd__SetCurSel_x                                      0x901F80
#define CListWnd__SetItemColor_x                                   0x902750
#define CListWnd__SetItemData_x                                    0x902710
#define CListWnd__SetItemText_x                                    0x902340
#define CListWnd__ShiftColumnSeparator_x                           0x900EB0
#define CListWnd__Sort_x                                           0x900BB0
#define CListWnd__ToggleSel_x                                      0x901FB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x764390
#define CMapViewWnd__GetWorldCoordinates_x                         0x762AA0
#define CMapViewWnd__HandleLButtonDown_x                           0x75FB00

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x787390
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x787C70
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7881B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x78AFF0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x785D80
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x790BE0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x786FC0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x891080
#define CPacketScrambler__hton_x                                   0x891070

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91BBB0
#define CSidlManager__FindScreenPieceTemplate_x                    0x91BFC0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91BDB0
#define CSidlManager__CreateLabel_x                                0x7E8B50
#define CSidlManager__CreateXWndFromTemplate_x                     0x91F090
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91F270
#define CSidlManager__CreateXWnd_x                                 0x7E8A80
#define CSidlManager__CreateHotButtonWnd_x                         0x7E9040

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x918720
#define CSidlScreenWnd__CalculateVSBRange_x                        0x918620
#define CSidlScreenWnd__ConvertToRes_x                             0x93D540
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9180B0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x917DA0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x917E70
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x917F40
#define CSidlScreenWnd__DrawSidlPiece_x                            0x918BA0
#define CSidlScreenWnd__EnableIniStorage_x                         0x919070
#define CSidlScreenWnd__GetSidlPiece_x                             0x918D90
#define CSidlScreenWnd__Init1_x                                    0x9179B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9190C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x919C20
#define CSidlScreenWnd__LoadSidlScreen_x                           0x916DC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x919790
#define CSidlScreenWnd__StoreIniVis_x                              0x919B00
#define CSidlScreenWnd__WndNotification_x                          0x918AB0
#define CSidlScreenWnd__GetChildItem_x                             0x918FF0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x908980
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A2A58

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x662B70
#define CSkillMgr__GetSkillCap_x                                   0x662D50
#define CSkillMgr__GetNameToken_x                                  0x662300

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x928A50
#define CSliderWnd__SetValue_x                                     0x9288C0
#define CSliderWnd__SetNumTicks_x                                  0x928920

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EE8C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x92F6A0
#define CStmlWnd__CalculateHSBRange_x                              0x930710
#define CStmlWnd__CalculateVSBRange_x                              0x930680
#define CStmlWnd__CanBreakAtCharacter_x                            0x934A50
#define CStmlWnd__FastForwardToEndOfTag_x                          0x935640
#define CStmlWnd__ForceParseNow_x                                  0x92FC40
#define CStmlWnd__GetNextTagPiece_x                                0x9349B0
#define CStmlWnd__GetSTMLText_x                                    0x4F10A0
#define CStmlWnd__GetVisibleText_x                                 0x92FC60
#define CStmlWnd__InitializeWindowVariables_x                      0x935490
#define CStmlWnd__MakeStmlColorTag_x                               0x92EE30
#define CStmlWnd__MakeWndNotificationTag_x                         0x92EEA0
#define CStmlWnd__SetSTMLText_x                                    0x92DF00
#define CStmlWnd__StripFirstSTMLLines_x                            0x9367A0
#define CStmlWnd__UpdateHistoryString_x                            0x935850

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93A420
#define CTabWnd__DrawCurrentPage_x                                 0x93AA40
#define CTabWnd__DrawTab_x                                         0x93A810
#define CTabWnd__GetCurrentPage_x                                  0x939C80
#define CTabWnd__GetPageInnerRect_x                                0x939EC0
#define CTabWnd__GetTabInnerRect_x                                 0x939E00
#define CTabWnd__GetTabRect_x                                      0x939CB0
#define CTabWnd__InsertPage_x                                      0x93A0B0
#define CTabWnd__SetPage_x                                         0x939F40
#define CTabWnd__SetPageRect_x                                     0x93A360
#define CTabWnd__UpdatePage_x                                      0x93A6D0
#define CTabWnd__GetPageFromTabIndex_x                             0x93A750
#define CTabWnd__GetCurrentTabIndex_x                              0x939C70

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7496C0
#define CPageWnd__SetTabText_x                                     0x946C10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6210

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9057F0
#define CTextureFont__GetTextExtent_x                              0x9059B0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6966B0
#define CHtmlComponentWnd__ValidateUri_x                           0x728750
#define CHtmlWnd__SetClientCallbacks_x                             0x6039B0
#define CHtmlWnd__AddObserver_x                                    0x6039D0
#define CHtmlWnd__RemoveObserver_x                                 0x603A30
#define Window__getProgress_x                                      0x841C40
#define Window__getStatus_x                                        0x841C60
#define Window__getURI_x                                           0x841C70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x943140

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F2810

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD8E0
#define CXStr__CXStr1_x                                            0x4EC000
#define CXStr__CXStr3_x                                            0x8DEB00
#define CXStr__dCXStr_x                                            0x472910
#define CXStr__operator_equal_x                                    0x8DED30
#define CXStr__operator_equal1_x                                   0x8DED70
#define CXStr__operator_plus_equal1_x                              0x8DF800

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x926CF0
#define CXWnd__BringToTop_x                                        0x90C0C0
#define CXWnd__Center_x                                            0x90BC40
#define CXWnd__ClrFocus_x                                          0x90BA90
#define CXWnd__Destroy_x                                           0x90BB30
#define CXWnd__DoAllDrawing_x                                      0x908110
#define CXWnd__DrawChildren_x                                      0x9080E0
#define CXWnd__DrawColoredRect_x                                   0x908570
#define CXWnd__DrawTooltip_x                                       0x906C30
#define CXWnd__DrawTooltipAtPoint_x                                0x906CF0
#define CXWnd__GetBorderFrame_x                                    0x9083D0
#define CXWnd__GetChildWndAt_x                                     0x90C160
#define CXWnd__GetClientClipRect_x                                 0x90A370
#define CXWnd__GetScreenClipRect_x                                 0x90A440
#define CXWnd__GetScreenRect_x                                     0x90A600
#define CXWnd__GetTooltipRect_x                                    0x9085C0
#define CXWnd__GetWindowTextA_x                                    0x497890
#define CXWnd__IsActive_x                                          0x90EFD0
#define CXWnd__IsDescendantOf_x                                    0x90B000
#define CXWnd__IsReallyVisible_x                                   0x90B030
#define CXWnd__IsType_x                                            0x90C7C0
#define CXWnd__Move_x                                              0x90B090
#define CXWnd__Move1_x                                             0x90B140
#define CXWnd__ProcessTransition_x                                 0x90BBF0
#define CXWnd__Refade_x                                            0x90B410
#define CXWnd__Resize_x                                            0x90B6B0
#define CXWnd__Right_x                                             0x90BE80
#define CXWnd__SetFocus_x                                          0x90BA50
#define CXWnd__SetFont_x                                           0x90BAC0
#define CXWnd__SetKeyTooltip_x                                     0x90C5E0
#define CXWnd__SetMouseOver_x                                      0x909510
#define CXWnd__StartFade_x                                         0x90AED0
#define CXWnd__GetChildItem_x                                      0x90C2D0
#define CXWnd__SetParent_x                                         0x90ADA0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93E610

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90F010
#define CXWndManager__DrawWindows_x                                0x90F030
#define CXWndManager__GetKeyboardFlags_x                           0x9116F0
#define CXWndManager__HandleKeyboardMsg_x                          0x9112F0
#define CXWndManager__RemoveWnd_x                                  0x911930
#define CXWndManager__RemovePendingDeletionWnd_x                   0x911E70

// CDBStr
#define CDBStr__GetString_x                                        0x525F80

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8620
#define EQ_Character__Cur_HP_x                                     0x4CE8D0
#define EQ_Character__Cur_Mana_x                                   0x4D5FD0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB530
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF4B0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF600
#define EQ_Character__GetHPRegen_x                                 0x4DBF50
#define EQ_Character__GetEnduranceRegen_x                          0x4DC560
#define EQ_Character__GetManaRegen_x                               0x4DC9A0
#define EQ_Character__Max_Endurance_x                              0x629410
#define EQ_Character__Max_HP_x                                     0x4CE700
#define EQ_Character__Max_Mana_x                                   0x629210
#define EQ_Character__doCombatAbility_x                            0x62B8E0
#define EQ_Character__UseSkill_x                                   0x4DE790
#define EQ_Character__GetConLevel_x                                0x622BF0
#define EQ_Character__IsExpansionFlag_x                            0x589530
#define EQ_Character__TotalEffect_x                                0x4C1BC0
#define EQ_Character__GetPCSpellAffect_x                           0x4BC120
#define EQ_Character__SpellDuration_x                              0x4BBC50
#define EQ_Character__FindItemByRecord_x                           0x4D3EE0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1610
#define EQ_Character__GetBaseSkill_x                               0x4D25B0
#define EQ_Character__CanUseItem_x                                 0x4D62E0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B02B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63F700

//PcClient
#define PcClient__PcClient_x                                       0x6204C0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6400
#define CCharacterListWnd__EnterWorld_x                            0x4B5E40
#define CCharacterListWnd__Quit_x                                  0x4B5B50
#define CCharacterListWnd__UpdateList_x                            0x4B5FD0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x604BE0
#define EQ_Item__CreateItemTagString_x                             0x88A9B0
#define EQ_Item__IsStackable_x                                     0x88F450
#define EQ_Item__GetImageNum_x                                     0x88C400
#define EQ_Item__CreateItemClient_x                                0x603D90
#define EQ_Item__GetItemValue_x                                    0x88D6A0
#define EQ_Item__ValueSellMerchant_x                               0x890C20
#define EQ_Item__IsKeyRingItem_x                                   0x88EDB0
#define EQ_Item__CanGoInBag_x                                      0x604D00
#define EQ_Item__GetMaxItemCount_x                                 0x88DA60
#define EQ_Item__GetHeldItem_x                                     0x88C2D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x88A300

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x544190
#define EQ_LoadingS__Array_x                                       0xBE27A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x629D70
#define EQ_PC__GetAlternateAbilityId_x                             0x899EE0
#define EQ_PC__GetCombatAbility_x                                  0x89A550
#define EQ_PC__GetCombatAbilityTimer_x                             0x89A5C0
#define EQ_PC__GetItemRecastTimer_x                                0x62BE60
#define EQ_PC__HasLoreItem_x                                       0x6233C0
#define EQ_PC__AlertInventoryChanged_x                             0x6226C0
#define EQ_PC__GetPcZoneClient_x                                   0x64DE30
#define EQ_PC__RemoveMyAffect_x                                    0x62F050
#define EQ_PC__GetKeyRingItems_x                                   0x89AE60
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89ABE0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89B150

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58FA80
#define EQItemList__add_object_x                                   0x5BB430
#define EQItemList__add_item_x                                     0x590090
#define EQItemList__delete_item_x                                  0x5900E0
#define EQItemList__FreeItemList_x                                 0x58FFE0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5235A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x640F80
#define EQPlayer__dEQPlayer_x                                      0x634670
#define EQPlayer__DoAttack_x                                       0x648B30
#define EQPlayer__EQPlayer_x                                       0x634D20
#define EQPlayer__SetNameSpriteState_x                             0x638FC0
#define EQPlayer__SetNameSpriteTint_x                              0x639E80
#define PlayerBase__HasProperty_j_x                                0x971420
#define EQPlayer__IsTargetable_x                                   0x9718C0
#define EQPlayer__CanSee_x                                         0x971720
#define EQPlayer__CanSee1_x                                        0x9717F0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9714E0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64B900
#define PlayerZoneClient__GetLevel_x                               0x64DE70
#define PlayerZoneClient__IsValidTeleport_x                        0x5BC590
#define PlayerZoneClient__LegalPlayerRace_x                        0x53D650

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x643C60
#define EQPlayerManager__GetSpawnByName_x                          0x643C80
#define EQPlayerManager__GetPlayerFromPartialName_x                0x643D10

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x608560
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6085A0
#define KeypressHandler__ClearCommandStateArray_x                  0x609990
#define KeypressHandler__HandleKeyDown_x                           0x6099B0
#define KeypressHandler__HandleKeyUp_x                             0x609A50
#define KeypressHandler__SaveKeymapping_x                          0x609E30

// MapViewMap 
#define MapViewMap__Clear_x                                        0x760220
#define MapViewMap__SaveEx_x                                       0x7635C0
#define MapViewMap__SetZoom_x                                      0x767C90

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8AE1A0

// StringTable 
#define StringTable__getString_x                                   0x8A9060

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62ECC0
#define PcZoneClient__RemovePetEffect_x                            0x62F2F0
#define PcZoneClient__HasAlternateAbility_x                        0x629050
#define PcZoneClient__GetCurrentMod_x                              0x4E1880
#define PcZoneClient__GetModCap_x                                  0x4E1780
#define PcZoneClient__CanEquipItem_x                               0x629700
#define PcZoneClient__GetItemByID_x                                0x62C2D0
#define PcZoneClient__GetItemByItemClass_x                         0x62C420
#define PcZoneClient__RemoveBuffEffect_x                           0x62F310
#define PcZoneClient__BandolierSwap_x                              0x62A330

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C1120

//IconCache
#define IconCache__GetIcon_x                                       0x701040

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F8B60
#define CContainerMgr__CloseContainer_x                            0x6F8E30
#define CContainerMgr__OpenExperimentContainer_x                   0x6F98B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BB230

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FCE10

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7566C0
#define CLootWnd__RequestLootSlot_x                                0x755A80

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55C580
#define EQ_Spell__SpellAffects_x                                   0x55C9F0
#define EQ_Spell__SpellAffectBase_x                                0x55C7B0
#define EQ_Spell__IsStackable_x                                    0x4C64C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6340
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B39C0
#define EQ_Spell__IsSPAStacking_x                                  0x55D820
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55CD40
#define EQ_Spell__IsNoRemove_x                                     0x4C64A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55D830
#define __IsResEffectSpell_x                                       0x4C5720

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA360

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B8730

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8009B0
#define CTargetWnd__WndNotification_x                              0x800240
#define CTargetWnd__RefreshTargetBuffs_x                           0x800510
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FF3A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x805070

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x557B20
#define EqSoundManager__PlayScriptMp3_x                            0x557C80
#define EqSoundManager__SoundAssistPlay_x                          0x666A30
#define EqSoundManager__WaveInstancePlay_x                         0x665FA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x514EB0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92A430

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54BDF0
#define CAltAbilityData__GetMercMaxRank_x                          0x54BD90
#define CAltAbilityData__GetMaxRank_x                              0x5413A0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FAF10

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6320
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FAED0
#define CharacterBase__CreateItemIndex_x                           0x602FE0
#define CharacterBase__GetItemPossession_x                         0x4B3870
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C0DB0
#define CharacterBase__GetEffectId_x                               0x4C62D0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E0BB0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E13D0

//messages
#define msg_spell_worn_off_x                                       0x581560
#define msg_new_text_x                                             0x576460
#define __msgTokenTextParam_x                                      0x583BB0
#define msgTokenText_x                                             0x583E00

//SpellManager
#define SpellManager__vftable_x                                    0xAAB8A0
#define SpellManager__SpellManager_x                               0x669D60
#define Spellmanager__LoadTextSpells_x                             0x66A630
#define SpellManager__GetSpellByGroupAndRank_x                     0x669F30

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x975400

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FB580
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x587A20
#define ItemGlobalIndex__IsEquippedLocation_x                      0x589510
#define ItemGlobalIndex__IsValidIndex_x                            0x4FB5E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B9070
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B92F0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74F080

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FD2A0
#define CCursorAttachment__Deactivate_x                            0x6FE280

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93CA30
#define CEQSuiteTextureLoader__GetTexture_x                        0x93C6F0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F8570

//IString
#define IString__Append_x                                          0x4EB140

//Camera
#define CDisplay__cameraType_x                                     0xDB0CC8
#define EverQuest__Cameras_x                                       0xE73F10

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x500D20
#define LootFiltersManager__GetItemFilterData_x                    0x500610
#define LootFiltersManager__RemoveItemLootFilter_x                 0x500640
#define LootFiltersManager__SetItemLootFilter_x                    0x500860

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A9290

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97B100
#define CResolutionHandler__GetWindowedStyle_x                     0x6616C0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F5940

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CB770

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x715B00
#define CGroupWnd__UpdateDisplay_x                                 0x714E60

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
