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
#define __ExpectedVersionDate                                     "Nov  8 2019"
#define __ExpectedVersionTime                                     "14:16:50"
#define __ActualVersionDate_x                                      0xAF2DE8
#define __ActualVersionTime_x                                      0xAF2DDC
#define __ActualVersionBuild_x                                     0xADEA04

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61CE30
#define __MemChecker1_x                                            0x8EE260
#define __MemChecker2_x                                            0x6AB810
#define __MemChecker3_x                                            0x6AB760
#define __MemChecker4_x                                            0x847A90
#define __EncryptPad0_x                                            0xC26A40
#define __EncryptPad1_x                                            0xC84B18
#define __EncryptPad2_x                                            0xC372D8
#define __EncryptPad3_x                                            0xC36ED8
#define __EncryptPad4_x                                            0xC751F8
#define __EncryptPad5_x                                            0xF4DD54
#define __AC1_x                                                    0x8043C6
#define __AC2_x                                                    0x5D6A6F
#define __AC3_x                                                    0x5DE16F
#define __AC4_x                                                    0x5E2140
#define __AC5_x                                                    0x5E844F
#define __AC6_x                                                    0x5ECA66
#define __AC7_x                                                    0x5D64E0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x192114

// Direct Input
#define DI8__Main_x                                                0xF4DD74
#define DI8__Keyboard_x                                            0xF4DD78
#define DI8__Mouse_x                                               0xF4DD90
#define DI8__Mouse_Copy_x                                          0xEA9424
#define DI8__Mouse_Check_x                                         0xF4E840
#define __AutoSkillArray_x                                         0xEAA33C
#define __Attack_x                                                 0xF4815F
#define __Autofire_x                                               0xF48160
#define __BindList_x                                               0xC15490
#define g_eqCommandStates_x                                        0xC16208
#define __Clicks_x                                                 0xEA94DC
#define __CommandList_x                                            0xC16DC8
#define __CurrentMapLabel_x                                        0xF60BDC
#define __CurrentSocial_x                                          0xBFF7CC
#define __DoAbilityList_x                                          0xEDFC80
#define __do_loot_x                                                0x5A2D00
#define __DrawHandler_x                                            0x15DD580
#define __GroupCount_x                                             0xE9B88A
#define __Guilds_x                                                 0xE9FC30
#define __gWorld_x                                                 0xE9B868
#define __HWnd_x                                                   0xF4DD94
#define __heqmain_x                                                0xF50CD4
#define __InChatMode_x                                             0xEA940C
#define __LastTell_x                                               0xEAB37C
#define __LMouseHeldTime_x                                         0xEA9548
#define __Mouse_x                                                  0xF4DD60
#define __MouseLook_x                                              0xEA94A2
#define __MouseEventTime_x                                         0xF48C44
#define __gpbCommandEvent_x                                        0xE9BA80
#define __NetStatusToggle_x                                        0xEA94A5
#define __PCNames_x                                                0xEAA92C
#define __RangeAttackReady_x                                       0xEAA620
#define __RMouseHeldTime_x                                         0xEA9544
#define __RunWalkState_x                                           0xEA9410
#define __ScreenMode_x                                             0xDE70F0
#define __ScreenX_x                                                0xEA93C4
#define __ScreenY_x                                                0xEA93C0
#define __ScreenXMax_x                                             0xEA93C8
#define __ScreenYMax_x                                             0xEA93CC
#define __ServerHost_x                                             0xE9BCB3
#define __ServerName_x                                             0xEDFC40
#define __ShiftKeyDown_x                                           0xEA9A9C
#define __ShowNames_x                                              0xEAA7DC
#define __Socials_x                                                0xEDFD40
#define __SubscriptionType_x                                       0xFA2730
#define __TargetAggroHolder_x                                      0xF63590
#define __ZoneType_x                                               0xEA98A0
#define __GroupAggro_x                                             0xF635D0
#define __LoginName_x                                              0xF4E4D4
#define __Inviter_x                                                0xF480DC
#define __AttackOnAssist_x                                         0xEAA798
#define __UseTellWindows_x                                         0xEAAAC8
#define __gfMaxZoomCameraDistance_x                                0xAE8740
#define __gfMaxCameraDistance_x                                    0xB14C84
#define __pulAutoRun_x                                             0xEA94C0
#define __pulForward_x                                             0xEAAB00
#define __pulBackward_x                                            0xEAAB04
#define __pulTurnRight_x                                           0xEAAB08
#define __pulTurnLeft_x                                            0xEAAB0C
#define __pulStrafeLeft_x                                          0xEAAB10
#define __pulStrafeRight_x                                         0xEAAB14

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9BFC8
#define instEQZoneInfo_x                                           0xEA9698
#define pinstActiveBanker_x                                        0xE9BA98
#define pinstActiveCorpse_x                                        0xE9BA90
#define pinstActiveGMaster_x                                       0xE9BA94
#define pinstActiveMerchant_x                                      0xE9BA8C
#define pinstAltAdvManager_x                                       0xDE82A0
#define pinstBandageTarget_x                                       0xE9BAA8
#define pinstCamActor_x                                            0xDE70E4
#define pinstCDBStr_x                                              0xDE6FC4
#define pinstCDisplay_x                                            0xE9B80C
#define pinstCEverQuest_x                                          0xF4DD98
#define pinstEverQuestInfo_x                                       0xEA93B8
#define pinstCharData_x                                            0xE9B86C
#define pinstCharSpawn_x                                           0xE9BB60
#define pinstControlledMissile_x                                   0xE996B8
#define pinstControlledPlayer_x                                    0xE9BB60
#define pinstCResolutionHandler_x                                  0x15DD7B0
#define pinstCSidlManager_x                                        0x15DC748
#define pinstCXWndManager_x                                        0x15DC744
#define instDynamicZone_x                                          0xE9FB08
#define pinstDZMember_x                                            0xE9FC18
#define pinstDZTimerInfo_x                                         0xE9FC1C
#define pinstEqLogin_x                                             0xF4DE20
#define instEQMisc_x                                               0xDE6F08
#define pinstEQSoundManager_x                                      0xDE91C8
#define pinstEQSpellStrings_x                                      0xCA9CA8
#define instExpeditionLeader_x                                     0xE9FB52
#define instExpeditionName_x                                       0xE9FB92
#define pinstGroup_x                                               0xE9B886
#define pinstImeManager_x                                          0x15DC740
#define pinstLocalPlayer_x                                         0xE9BA88
#define pinstMercenaryData_x                                       0xF4A72C
#define pinstMercenaryStats_x                                      0xF636DC
#define pinstModelPlayer_x                                         0xE9BAA0
#define pinstPCData_x                                              0xE9B86C
#define pinstSkillMgr_x                                            0xF4C898
#define pinstSpawnManager_x                                        0xF4B340
#define pinstSpellManager_x                                        0xF4CAB8
#define pinstSpellSets_x                                           0xF40D88
#define pinstStringTable_x                                         0xE9B870
#define pinstSwitchManager_x                                       0xE99568
#define pinstTarget_x                                              0xE9BADC
#define pinstTargetObject_x                                        0xE9BB68
#define pinstTargetSwitch_x                                        0xE9B6C0
#define pinstTaskMember_x                                          0xDE6D98
#define pinstTrackTarget_x                                         0xE9BB64
#define pinstTradeTarget_x                                         0xE9BA9C
#define instTributeActive_x                                        0xDE6F29
#define pinstViewActor_x                                           0xDE70E0
#define pinstWorldData_x                                           0xE9B6CC
#define pinstZoneAddr_x                                            0xEA9938
#define pinstPlayerPath_x                                          0xF4B3D8
#define pinstTargetIndicator_x                                     0xF4CD20
#define EQObject_Top_x                                             0xE9BA84
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE7168
#define pinstCAchievementsWnd_x                                    0xDE7108
#define pinstCActionsWnd_x                                         0xDE7124
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE78E0
#define pinstCAdvancedLootWnd_x                                    0xDE7418
#define pinstCAdventureLeaderboardWnd_x                            0xF5A3B0
#define pinstCAdventureRequestWnd_x                                0xF5A460
#define pinstCAdventureStatsWnd_x                                  0xF5A510
#define pinstCAggroMeterWnd_x                                      0xDE70A0
#define pinstCAlarmWnd_x                                           0xDE73D8
#define pinstCAlertHistoryWnd_x                                    0xDE7410
#define pinstCAlertStackWnd_x                                      0xDE7178
#define pinstCAlertWnd_x                                           0xDE7190
#define pinstCAltStorageWnd_x                                      0xF5A870
#define pinstCAudioTriggersWindow_x                                0xC9BFD8
#define pinstCAuraWnd_x                                            0xDE7074
#define pinstCAvaZoneWnd_x                                         0xDE73AC
#define pinstCBandolierWnd_x                                       0xDE7098
#define pinstCBankWnd_x                                            0xDE7070
#define pinstCBarterMerchantWnd_x                                  0xF5BAB0
#define pinstCBarterSearchWnd_x                                    0xF5BB60
#define pinstCBarterWnd_x                                          0xF5BC10
#define pinstCBazaarConfirmationWnd_x                              0xDE7134
#define pinstCBazaarSearchWnd_x                                    0xDE7100
#define pinstCBazaarWnd_x                                          0xDE73C4
#define pinstCBlockedBuffWnd_x                                     0xDE7078
#define pinstCBlockedPetBuffWnd_x                                  0xDE7094
#define pinstCBodyTintWnd_x                                        0xDE7138
#define pinstCBookWnd_x                                            0xDE70BC
#define pinstCBreathWnd_x                                          0xDE7188
#define pinstCBuffWindowNORMAL_x                                   0xDE7060
#define pinstCBuffWindowSHORT_x                                    0xDE7064
#define pinstCBugReportWnd_x                                       0xDE706C
#define pinstCButtonWnd_x                                          0x15DC9B0
#define pinstCCastingWnd_x                                         0xDE70AC
#define pinstCCastSpellWnd_x                                       0xDE717C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE73C8
#define pinstCChatWindowManager_x                                  0xF5C6D0
#define pinstCClaimWnd_x                                           0xF5C828
#define pinstCColorPickerWnd_x                                     0xDE7130
#define pinstCCombatAbilityWnd_x                                   0xDE73D4
#define pinstCCombatSkillsSelectWnd_x                              0xDE73F8
#define pinstCCompassWnd_x                                         0xDE712C
#define pinstCConfirmationDialog_x                                 0xF61728
#define pinstCContainerMgr_x                                       0xDE73BC
#define pinstCContextMenuManager_x                                 0x15DC700
#define pinstCCursorAttachment_x                                   0xDE70A4
#define pinstCDynamicZoneWnd_x                                     0xF5CDF0
#define pinstCEditLabelWnd_x                                       0xDE78EC
#define pinstCEQMainWnd_x                                          0xF5D038
#define pinstCEventCalendarWnd_x                                   0xDE78F4
#define pinstCExtendedTargetWnd_x                                  0xDE708C
#define pinstCFacePick_x                                           0xDE740C
#define pinstCFactionWnd_x                                         0xDE73B4
#define pinstCFellowshipWnd_x                                      0xF5D238
#define pinstCFileSelectionWnd_x                                   0xDE70A8
#define pinstCFindItemWnd_x                                        0xDE73A4
#define pinstCFindLocationWnd_x                                    0xF5D390
#define pinstCFriendsWnd_x                                         0xDE7414
#define pinstCGemsGameWnd_x                                        0xDE73B0
#define pinstCGiveWnd_x                                            0xDE73DC
#define pinstCGroupSearchFiltersWnd_x                              0xDE70B4
#define pinstCGroupSearchWnd_x                                     0xF5D788
#define pinstCGroupWnd_x                                           0xF5D838
#define pinstCGuildBankWnd_x                                       0xEAA77C
#define pinstCGuildCreationWnd_x                                   0xF5D998
#define pinstCGuildMgmtWnd_x                                       0xF5DA48
#define pinstCharacterCreation_x                                   0xDE7400
#define pinstCHelpWnd_x                                            0xDE74D4
#define pinstCHeritageSelectionWnd_x                               0xDE743C
#define pinstCHotButtonWnd_x                                       0xF5FBA0
#define pinstCHotButtonWnd1_x                                      0xF5FBA0
#define pinstCHotButtonWnd2_x                                      0xF5FBA4
#define pinstCHotButtonWnd3_x                                      0xF5FBA8
#define pinstCHotButtonWnd4_x                                      0xF5FBAC
#define pinstCIconSelectionWnd_x                                   0xDE709C
#define pinstCInspectWnd_x                                         0xDE74D0
#define pinstCInventoryWnd_x                                       0xDE7440
#define pinstCInvSlotMgr_x                                         0xDE7160
#define pinstCItemDisplayManager_x                                 0xF60130
#define pinstCItemExpTransferWnd_x                                 0xF60264
#define pinstCItemOverflowWnd_x                                    0xDE7104
#define pinstCJournalCatWnd_x                                      0xDE70C8
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE7088
#define pinstCKeyRingWnd_x                                         0xDE78E8
#define pinstCLargeDialogWnd_x                                     0xF623A8
#define pinstCLayoutCopyWnd_x                                      0xF605B0
#define pinstCLFGuildWnd_x                                         0xF60660
#define pinstCLoadskinWnd_x                                        0xDE73C0
#define pinstCLootFiltersCopyWnd_x                                 0xCB82A0
#define pinstCLootFiltersWnd_x                                     0xDE7180
#define pinstCLootSettingsWnd_x                                    0xDE73A0
#define pinstCLootWnd_x                                            0xDE70CC
#define pinstCMailAddressBookWnd_x                                 0xDE716C
#define pinstCMailCompositionWnd_x                                 0xDE714C
#define pinstCMailIgnoreListWnd_x                                  0xDE7170
#define pinstCMailWnd_x                                            0xDE7128
#define pinstCManageLootWnd_x                                      0xDE8750
#define pinstCMapToolbarWnd_x                                      0xDE74D8
#define pinstCMapViewWnd_x                                         0xDE744C
#define pinstCMarketplaceWnd_x                                     0xDE718C
#define pinstCMerchantWnd_x                                        0xDE70D0
#define pinstCMIZoneSelectWnd_x                                    0xF60E98
#define pinstCMusicPlayerWnd_x                                     0xDE70DC
#define pinstCNameChangeMercWnd_x                                  0xDE7120
#define pinstCNameChangePetWnd_x                                   0xDE710C
#define pinstCNameChangeWnd_x                                      0xDE7140
#define pinstCNoteWnd_x                                            0xDE7450
#define pinstCObjectPreviewWnd_x                                   0xDE719C
#define pinstCOptionsWnd_x                                         0xDE7454
#define pinstCPetInfoWnd_x                                         0xDE7110
#define pinstCPetitionQWnd_x                                       0xDE70D8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE713C
#define pinstCPlayerWnd_x                                          0xDE7114
#define pinstCPopupWndManager_x                                    0xF61728
#define pinstCProgressionSelectionWnd_x                            0xF617D8
#define pinstCPurchaseGroupWnd_x                                   0xDE73E4
#define pinstCPurchaseWnd_x                                        0xDE73B8
#define pinstCPvPLeaderboardWnd_x                                  0xF61888
#define pinstCPvPStatsWnd_x                                        0xF61938
#define pinstCQuantityWnd_x                                        0xDE7090
#define pinstCRaceChangeWnd_x                                      0xDE7164
#define pinstCRaidOptionsWnd_x                                     0xDE70B8
#define pinstCRaidWnd_x                                            0xDE7150
#define pinstCRealEstateItemsWnd_x                                 0xDE70FC
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE707C
#define pinstCRealEstateManageWnd_x                                0xDE73EC
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE7408
#define pinstCRealEstatePlotSearchWnd_x                            0xDE7444
#define pinstCRealEstatePurchaseWnd_x                              0xDE74CC
#define pinstCRespawnWnd_x                                         0xDE7084
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE7174
#define pinstCSendMoneyWnd_x                                       0xDE73F4
#define pinstCServerListWnd_x                                      0xDE78F0
#define pinstCSkillsSelectWnd_x                                    0xDE73D0
#define pinstCSkillsWnd_x                                          0xDE73A8
#define pinstCSocialEditWnd_x                                      0xDE78E4
#define pinstCSocialWnd_x                                          0xDE711C
#define pinstCSpellBookWnd_x                                       0xDE73CC
#define pinstCStoryWnd_x                                           0xDE7118
#define pinstCTargetOfTargetWnd_x                                  0xF63760
#define pinstCTargetWnd_x                                          0xDE7080
#define pinstCTaskOverlayWnd_x                                     0xDE73E0
#define pinstCTaskSelectWnd_x                                      0xF638B8
#define pinstCTaskManager_x                                        0xCB8BE0
#define pinstCTaskTemplateSelectWnd_x                              0xF63968
#define pinstCTaskWnd_x                                            0xF63A18
#define pinstCTextEntryWnd_x                                       0xDE7068
#define pinstCTimeLeftWnd_x                                        0xDE70B0
#define pinstCTipWndCONTEXT_x                                      0xF63C1C
#define pinstCTipWndOFDAY_x                                        0xF63C18
#define pinstCTitleWnd_x                                           0xF63CC8
#define pinstCTrackingWnd_x                                        0xDE7448
#define pinstCTradeskillWnd_x                                      0xF63E30
#define pinstCTradeWnd_x                                           0xDE7148
#define pinstCTrainWnd_x                                           0xDE7144
#define pinstCTributeBenefitWnd_x                                  0xF64030
#define pinstCTributeMasterWnd_x                                   0xF640E0
#define pinstCTributeTrophyWnd_x                                   0xF64190
#define pinstCVideoModesWnd_x                                      0xDE7198
#define pinstCVoiceMacroWnd_x                                      0xF4D488
#define pinstCVoteResultsWnd_x                                     0xDE70D4
#define pinstCVoteWnd_x                                            0xDE70C4
#define pinstCWebManager_x                                         0xF4DB04
#define pinstCZoneGuideWnd_x                                       0xDE73E8
#define pinstCZonePathWnd_x                                        0xDE73FC

#define pinstEQSuiteTextureLoader_x                                0xC865F0
#define pinstItemIconCache_x                                       0xF5CFF0
#define pinstLootFiltersManager_x                                  0xCB8350
#define pinstRewardSelectionWnd_x                                  0xF62080

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x59E160
#define __CastRay2_x                                               0x59E1B0
#define __ConvertItemTags_x                                        0x5B9D10
#define __CleanItemTags_x                                          0x47CA30
#define __DoesFileExist_x                                          0x8F1340
#define __EQGetTime_x                                              0x8EDD30
#define __ExecuteCmd_x                                             0x596AC0
#define __FixHeading_x                                             0x9881B0
#define __GameLoop_x                                               0x6AAA00
#define __get_bearing_x                                            0x59DCD0
#define __get_melee_range_x                                        0x59E3A0
#define __GetAnimationCache_x                                      0x70FEA0
#define __GetGaugeValueFromEQ_x                                    0x802870
#define __GetLabelFromEQ_x                                         0x804350
#define __GetXTargetType_x                                         0x989C00
#define __HandleMouseWheel_x                                       0x6AB8C0
#define __HeadingDiff_x                                            0x988220
#define __HelpPath_x                                               0xF48834
#define __LoadFrontEnd_x                                           0x6A7D20
#define __NewUIINI_x                                               0x802540
#define __ProcessGameEvents_x                                      0x5FE2D0
#define __ProcessMouseEvent_x                                      0x5FDA90
#define __SaveColors_x                                             0x547820
#define __STMLToText_x                                             0x92B7B0
#define __ToggleKeyRingItem_x                                      0x50B0E0
#define CMemoryMappedFile__SetFile_x                               0xA77480
#define CrashDetected_x                                            0x6A97C0
#define DrawNetStatus_x                                            0x62A290
#define Expansion_HoT_x                                            0xEAA784
#define Teleport_Table_Size_x                                      0xE9BB70
#define Teleport_Table_x                                           0xE996C0
#define Util__FastTime_x                                           0x8ED900

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48FBD0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x498AE0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4988B0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493170
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x4925C0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54F300
#define AltAdvManager__IsAbilityReady_x                            0x54E230
#define AltAdvManager__GetAAById_x                                 0x54E430
#define AltAdvManager__CanTrainAbility_x                           0x54E4A0
#define AltAdvManager__CanSeeAbility_x                             0x54E800

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9B30
#define CharacterZoneClient__HasSkill_x                            0x4D4A20
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6140
#define CharacterZoneClient__IsStackBlocked_x                      0x4BDD80
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA380
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8B00
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8BE0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8CC0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2B70
#define CharacterZoneClient__BardCastBard_x                        0x4C56D0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA450
#define CharacterZoneClient__GetEffect_x                           0x4BA2C0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3BC0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3C90
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3CE0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3E30
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4000
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2230
#define CharacterZoneClient__FindItemByGuid_x                      0x4D70A0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6B20

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D15B0
#define CBankWnd__WndNotification_x                                0x6D1390

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DECB0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60CC90
#define CButtonWnd__CButtonWnd_x                                   0x927BB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FF020
#define CChatManager__InitContextMenu_x                            0x6F8180
#define CChatManager__FreeChatWindow_x                             0x6FDB60
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8180
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FECA0
#define CChatManager__CreateChatWindow_x                           0x6FE1A0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8290

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93C0E0
#define CContextMenu__dCContextMenu_x                              0x93C310
#define CContextMenu__AddMenuItem_x                                0x93C320
#define CContextMenu__RemoveMenuItem_x                             0x93C630
#define CContextMenu__RemoveAllMenuItems_x                         0x93C650
#define CContextMenu__CheckMenuItem_x                              0x93C6D0
#define CContextMenu__SetMenuItem_x                                0x93C550
#define CContextMenu__AddSeparator_x                               0x93C4B0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93CC70
#define CContextMenuManager__RemoveMenu_x                          0x93CCE0
#define CContextMenuManager__PopupMenu_x                           0x93CDA0
#define CContextMenuManager__Flush_x                               0x93CC10
#define CContextMenuManager__GetMenu_x                             0x49AC60
#define CContextMenuManager__CreateDefaultMenu_x                   0x70A6C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CBB70
#define CChatService__GetFriendName_x                              0x8CBB80

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FF8D0
#define CChatWindow__Clear_x                                       0x700B90
#define CChatWindow__WndNotification_x                             0x701320
#define CChatWindow__AddHistory_x                                  0x700450

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x939550
#define CComboWnd__Draw_x                                          0x938A50
#define CComboWnd__GetCurChoice_x                                  0x939390
#define CComboWnd__GetListRect_x                                   0x938F00
#define CComboWnd__GetTextRect_x                                   0x9395C0
#define CComboWnd__InsertChoice_x                                  0x939090
#define CComboWnd__SetColors_x                                     0x939060
#define CComboWnd__SetChoice_x                                     0x939360
#define CComboWnd__GetItemCount_x                                  0x9393A0
#define CComboWnd__GetCurChoiceText_x                              0x9393E0
#define CComboWnd__GetChoiceText_x                                 0x9393B0
#define CComboWnd__InsertChoiceAtIndex_x                           0x939120

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7080B0
#define CContainerWnd__vftable_x                                   0xAFBFDC
#define CContainerWnd__SetContainer_x                              0x709610

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5422C0
#define CDisplay__PreZoneMainUI_x                                  0x5422D0
#define CDisplay__CleanGameUI_x                                    0x5475E0
#define CDisplay__GetClickedActor_x                                0x53A5E0
#define CDisplay__GetUserDefinedColor_x                            0x532CA0
#define CDisplay__GetWorldFilePath_x                               0x53C050
#define CDisplay__is3dON_x                                         0x537240
#define CDisplay__ReloadUI_x                                       0x541750
#define CDisplay__WriteTextHD2_x                                   0x537030
#define CDisplay__TrueDistance_x                                   0x53DD10
#define CDisplay__SetViewActor_x                                   0x539F00
#define CDisplay__GetFloorHeight_x                                 0x537300
#define CDisplay__SetRenderWindow_x                                0x535C60
#define CDisplay__ToggleScreenshotMode_x                           0x5399D0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95BE00

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x93F610
#define CEditWnd__GetCharIndexPt_x                                 0x940530
#define CEditWnd__GetDisplayString_x                               0x9403E0
#define CEditWnd__GetHorzOffset_x                                  0x93EC50
#define CEditWnd__GetLineForPrintableChar_x                        0x9416A0
#define CEditWnd__GetSelStartPt_x                                  0x9407E0
#define CEditWnd__GetSTMLSafeText_x                                0x940200
#define CEditWnd__PointFromPrintableChar_x                         0x9412E0
#define CEditWnd__SelectableCharFromPoint_x                        0x941450
#define CEditWnd__SetEditable_x                                    0x9408A0
#define CEditWnd__SetWindowTextA_x                                 0x93FF80

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5EBF40
#define CEverQuest__ClickedPlayer_x                                0x5DDF50
#define CEverQuest__CreateTargetIndicator_x                        0x5FB570
#define CEverQuest__DeleteTargetIndicator_x                        0x5FB600
#define CEverQuest__DoTellWindow_x                                 0x4E8370
#define CEverQuest__OutputTextToLog_x                              0x4E85F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5D2F90
#define CEverQuest__dsp_chat_x                                     0x4E8980
#define CEverQuest__trimName_x                                     0x5F7850
#define CEverQuest__Emote_x                                        0x5EC7A0
#define CEverQuest__EnterZone_x                                    0x5E6720
#define CEverQuest__GetBodyTypeDesc_x                              0x5F1110
#define CEverQuest__GetClassDesc_x                                 0x5F1750
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F1D50
#define CEverQuest__GetDeityDesc_x                                 0x5F9EB0
#define CEverQuest__GetLangDesc_x                                  0x5F1F10
#define CEverQuest__GetRaceDesc_x                                  0x5F1730
#define CEverQuest__InterpretCmd_x                                 0x5FA480
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D7190
#define CEverQuest__LMouseUp_x                                     0x5D5520
#define CEverQuest__RightClickedOnPlayer_x                         0x5D7A70
#define CEverQuest__RMouseUp_x                                     0x5D64A0
#define CEverQuest__SetGameState_x                                 0x5D2D20
#define CEverQuest__UPCNotificationFlush_x                         0x5F7750
#define CEverQuest__IssuePetCommand_x                              0x5F3310
#define CEverQuest__ReportSuccessfulHit_x                          0x5EDB90

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71A010
#define CGaugeWnd__CalcLinesFillRect_x                             0x71A070
#define CGaugeWnd__Draw_x                                          0x719690

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AED10
#define CGuild__GetGuildName_x                                     0x4ADDF0
#define CGuild__GetGuildIndex_x                                    0x4AE180

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x735460

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60D050

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7423C0
#define CInvSlotMgr__MoveItem_x                                    0x741140
#define CInvSlotMgr__SelectSlot_x                                  0x742490

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73F9E0
#define CInvSlot__SliderComplete_x                                 0x73D750
#define CInvSlot__GetItemBase_x                                    0x73D0F0
#define CInvSlot__UpdateItem_x                                     0x73D260

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x743F10
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7430B0
#define CInvSlotWnd__HandleLButtonUp_x                             0x743A90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FDBC0
#define CItemDisplayWnd__UpdateStrings_x                           0x752640
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74C3B0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74C8D0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x752C50
#define CItemDisplayWnd__AboutToShow_x                             0x752290
#define CItemDisplayWnd__WndNotification_x                         0x753D30
#define CItemDisplayWnd__RequestConvertItem_x                      0x7537F0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x751300
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7520B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8366E0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x758270

// CLabel 
#define CLabel__Draw_x                                             0x75DC50

// CListWnd
#define CListWnd__CListWnd_x                                       0x911E10
#define CListWnd__dCListWnd_x                                      0x912130
#define CListWnd__AddColumn_x                                      0x916590
#define CListWnd__AddColumn1_x                                     0x9165E0
#define CListWnd__AddLine_x                                        0x916970
#define CListWnd__AddString_x                                      0x916770
#define CListWnd__CalculateFirstVisibleLine_x                      0x916350
#define CListWnd__CalculateVSBRange_x                              0x916140
#define CListWnd__ClearSel_x                                       0x917150
#define CListWnd__ClearAllSel_x                                    0x9171B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x917BD0
#define CListWnd__Compare_x                                        0x915A80
#define CListWnd__Draw_x                                           0x912260
#define CListWnd__DrawColumnSeparators_x                           0x914A50
#define CListWnd__DrawHeader_x                                     0x914EC0
#define CListWnd__DrawItem_x                                       0x9153C0
#define CListWnd__DrawLine_x                                       0x914BC0
#define CListWnd__DrawSeparator_x                                  0x914AF0
#define CListWnd__EnableLine_x                                     0x914320
#define CListWnd__EnsureVisible_x                                  0x917AF0
#define CListWnd__ExtendSel_x                                      0x917080
#define CListWnd__GetColumnTooltip_x                               0x913E60
#define CListWnd__GetColumnMinWidth_x                              0x913ED0
#define CListWnd__GetColumnWidth_x                                 0x913DD0
#define CListWnd__GetCurSel_x                                      0x913760
#define CListWnd__GetItemAtPoint_x                                 0x9145A0
#define CListWnd__GetItemAtPoint1_x                                0x914610
#define CListWnd__GetItemData_x                                    0x9137E0
#define CListWnd__GetItemHeight_x                                  0x913BA0
#define CListWnd__GetItemIcon_x                                    0x913970
#define CListWnd__GetItemRect_x                                    0x914410
#define CListWnd__GetItemText_x                                    0x913820
#define CListWnd__GetSelList_x                                     0x917200
#define CListWnd__GetSeparatorRect_x                               0x914850
#define CListWnd__InsertLine_x                                     0x916D60
#define CListWnd__RemoveLine_x                                     0x916EB0
#define CListWnd__SetColors_x                                      0x916110
#define CListWnd__SetColumnJustification_x                         0x915E50
#define CListWnd__SetColumnWidth_x                                 0x915D70
#define CListWnd__SetCurSel_x                                      0x916FC0
#define CListWnd__SetItemColor_x                                   0x9177A0
#define CListWnd__SetItemData_x                                    0x917760
#define CListWnd__SetItemText_x                                    0x917370
#define CListWnd__ShiftColumnSeparator_x                           0x915F10
#define CListWnd__Sort_x                                           0x915C00
#define CListWnd__ToggleSel_x                                      0x916FF0
#define CListWnd__SetColumnsSizable_x                              0x915FB0
#define CListWnd__SetItemWnd_x                                     0x917620
#define CListWnd__GetItemWnd_x                                     0x9139C0
#define CListWnd__SetItemIcon_x                                    0x9173F0
#define CListWnd__CalculateCustomWindowPositions_x                 0x916450
#define CListWnd__SetVScrollPos_x                                  0x915D50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x773470
#define CMapViewWnd__GetWorldCoordinates_x                         0x771B80
#define CMapViewWnd__HandleLButtonDown_x                           0x76EBC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7935E0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x793EC0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7943F0
#define CMerchantWnd__SelectRecoverySlot_x                         0x797370
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x792140
#define CMerchantWnd__SelectBuySellSlot_x                          0x79CF30
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7931F0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x899700
#define CPacketScrambler__hton_x                                   0x8996F0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x930E00
#define CSidlManager__FindScreenPieceTemplate_x                    0x931210
#define CSidlManager__FindScreenPieceTemplate1_x                   0x931000
#define CSidlManager__CreateLabel_x                                0x7F50A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x934170
#define CSidlManager__CreateXWndFromTemplate1_x                    0x934340
#define CSidlManager__CreateXWnd_x                                 0x7F4FD0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F5580

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92D8C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92D7C0
#define CSidlScreenWnd__ConvertToRes_x                             0x952D00
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92D260
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92CF50
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92D020
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92D0F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92DD60
#define CSidlScreenWnd__EnableIniStorage_x                         0x92E230
#define CSidlScreenWnd__GetSidlPiece_x                             0x92DF50
#define CSidlScreenWnd__Init1_x                                    0x92CB50
#define CSidlScreenWnd__LoadIniInfo_x                              0x92E280
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92EDE0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92BF60
#define CSidlScreenWnd__StoreIniInfo_x                             0x92E950
#define CSidlScreenWnd__StoreIniVis_x                              0x92ECC0
#define CSidlScreenWnd__WndNotification_x                          0x92DC70
#define CSidlScreenWnd__GetChildItem_x                             0x92E1B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91D980
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DC5D0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6716C0
#define CSkillMgr__GetSkillCap_x                                   0x6718A0
#define CSkillMgr__GetNameToken_x                                  0x670E40
#define CSkillMgr__IsActivatedSkill_x                              0x670F80
#define CSkillMgr__IsCombatSkill_x                                 0x670EC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93DA30
#define CSliderWnd__SetValue_x                                     0x93D8A0
#define CSliderWnd__SetNumTicks_x                                  0x93D900

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FB060

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9461F0
#define CStmlWnd__CalculateHSBRange_x                              0x947310
#define CStmlWnd__CalculateVSBRange_x                              0x947290
#define CStmlWnd__CanBreakAtCharacter_x                            0x94B640
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94C2D0
#define CStmlWnd__ForceParseNow_x                                  0x9467E0
#define CStmlWnd__GetNextTagPiece_x                                0x94B5A0
#define CStmlWnd__GetSTMLText_x                                    0x4FA980
#define CStmlWnd__GetVisibleText_x                                 0x946800
#define CStmlWnd__InitializeWindowVariables_x                      0x94C120
#define CStmlWnd__MakeStmlColorTag_x                               0x945860
#define CStmlWnd__MakeWndNotificationTag_x                         0x9458D0
#define CStmlWnd__SetSTMLText_x                                    0x944910
#define CStmlWnd__StripFirstSTMLLines_x                            0x94D3D0
#define CStmlWnd__UpdateHistoryString_x                            0x94C4E0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x943A60
#define CTabWnd__DrawCurrentPage_x                                 0x944190
#define CTabWnd__DrawTab_x                                         0x943EB0
#define CTabWnd__GetCurrentPage_x                                  0x943270
#define CTabWnd__GetPageInnerRect_x                                0x9434B0
#define CTabWnd__GetTabInnerRect_x                                 0x9433F0
#define CTabWnd__GetTabRect_x                                      0x9432A0
#define CTabWnd__InsertPage_x                                      0x9436C0
#define CTabWnd__SetPage_x                                         0x943530
#define CTabWnd__SetPageRect_x                                     0x9439A0
#define CTabWnd__UpdatePage_x                                      0x943D70
#define CTabWnd__GetPageFromTabIndex_x                             0x943DF0
#define CTabWnd__GetCurrentTabIndex_x                              0x943260

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x758640
#define CPageWnd__SetTabText_x                                     0x942DB0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A89A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91A820
#define CTextureFont__GetTextExtent_x                              0x91A9E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A48B0
#define CHtmlComponentWnd__ValidateUri_x                           0x736E50
#define CHtmlWnd__SetClientCallbacks_x                             0x6120D0
#define CHtmlWnd__AddObserver_x                                    0x6120F0
#define CHtmlWnd__RemoveObserver_x                                 0x612150
#define Window__getProgress_x                                      0x84F030
#define Window__getStatus_x                                        0x84F050
#define Window__getURI_x                                           0x84F060

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x958890

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x907B00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E7EC0
#define CXStr__CXStr1_x                                            0x4F5950
#define CXStr__CXStr3_x                                            0x8E9E70
#define CXStr__dCXStr_x                                            0x478050
#define CXStr__operator_equal_x                                    0x8EA0A0
#define CXStr__operator_equal1_x                                   0x8EA0E0
#define CXStr__operator_plus_equal1_x                              0x8EAB70
#define CXStr__SetString_x                                         0x8ECA60
#define CXStr__operator_char_p_x                                   0x8EA5B0
#define CXStr__GetChar_x                                           0x8EC390
#define CXStr__Delete_x                                            0x8EBC60
#define CXStr__GetUnicode_x                                        0x8EC400
#define CXStr__GetLength_x                                         0x47CDE0
#define CXStr__Mid_x                                               0x47CDF0
#define CXStr__Insert_x                                            0x8EC460
#define CXStr__FindNext_x                                          0x8EC0D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93BD00
#define CXWnd__BringToTop_x                                        0x9210F0
#define CXWnd__Center_x                                            0x920C70
#define CXWnd__ClrFocus_x                                          0x920A80
#define CXWnd__Destroy_x                                           0x920B30
#define CXWnd__DoAllDrawing_x                                      0x91D130
#define CXWnd__DrawChildren_x                                      0x91D100
#define CXWnd__DrawColoredRect_x                                   0x91D570
#define CXWnd__DrawTooltip_x                                       0x91BC50
#define CXWnd__DrawTooltipAtPoint_x                                0x91BD10
#define CXWnd__GetBorderFrame_x                                    0x91D3D0
#define CXWnd__GetChildWndAt_x                                     0x921190
#define CXWnd__GetClientClipRect_x                                 0x91F380
#define CXWnd__GetScreenClipRect_x                                 0x91F450
#define CXWnd__GetScreenRect_x                                     0x91F620
#define CXWnd__GetTooltipRect_x                                    0x91D5C0
#define CXWnd__GetWindowTextA_x                                    0x49C350
#define CXWnd__IsActive_x                                          0x91DCF0
#define CXWnd__IsDescendantOf_x                                    0x91FFE0
#define CXWnd__IsReallyVisible_x                                   0x920010
#define CXWnd__IsType_x                                            0x9217F0
#define CXWnd__Move_x                                              0x920080
#define CXWnd__Move1_x                                             0x920130
#define CXWnd__ProcessTransition_x                                 0x920C20
#define CXWnd__Refade_x                                            0x920400
#define CXWnd__Resize_x                                            0x920690
#define CXWnd__Right_x                                             0x920EB0
#define CXWnd__SetFocus_x                                          0x920A40
#define CXWnd__SetFont_x                                           0x920AB0
#define CXWnd__SetKeyTooltip_x                                     0x921620
#define CXWnd__SetMouseOver_x                                      0x91E520
#define CXWnd__StartFade_x                                         0x91FEC0
#define CXWnd__GetChildItem_x                                      0x921300
#define CXWnd__SetParent_x                                         0x91FDC0
#define CXWnd__Minimize_x                                          0x920700

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x953D80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9240A0
#define CXWndManager__DrawWindows_x                                0x9240C0
#define CXWndManager__GetKeyboardFlags_x                           0x926860
#define CXWndManager__HandleKeyboardMsg_x                          0x926420
#define CXWndManager__RemoveWnd_x                                  0x926AA0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x926FF0

// CDBStr
#define CDBStr__GetString_x                                        0x531C70

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB360
#define EQ_Character__Cur_HP_x                                     0x4D1A60
#define EQ_Character__Cur_Mana_x                                   0x4D91C0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE3D0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B1E70
#define EQ_Character__GetFocusRangeModifier_x                      0x4B1FC0
#define EQ_Character__GetHPRegen_x                                 0x4DEF90
#define EQ_Character__GetEnduranceRegen_x                          0x4DF590
#define EQ_Character__GetManaRegen_x                               0x4DF9D0
#define EQ_Character__Max_Endurance_x                              0x637FA0
#define EQ_Character__Max_HP_x                                     0x4D1890
#define EQ_Character__Max_Mana_x                                   0x637DA0
#define EQ_Character__doCombatAbility_x                            0x63A3F0
#define EQ_Character__UseSkill_x                                   0x4E17B0
#define EQ_Character__GetConLevel_x                                0x6311F0
#define EQ_Character__IsExpansionFlag_x                            0x5952A0
#define EQ_Character__TotalEffect_x                                0x4C4E10
#define EQ_Character__GetPCSpellAffect_x                           0x4BF120
#define EQ_Character__SpellDuration_x                              0x4BEC50
#define EQ_Character__GetAdjustedSkill_x                           0x4D47E0
#define EQ_Character__GetBaseSkill_x                               0x4D5780
#define EQ_Character__CanUseItem_x                                 0x4D94D0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B89A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64E4B0

//PcClient
#define PcClient__PcClient_x                                       0x62E920

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B8FC0
#define CCharacterListWnd__EnterWorld_x                            0x4B8A00
#define CCharacterListWnd__Quit_x                                  0x4B8750
#define CCharacterListWnd__UpdateList_x                            0x4B8B90

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x613320
#define EQ_Item__CreateItemTagString_x                             0x892FB0
#define EQ_Item__IsStackable_x                                     0x897AD0
#define EQ_Item__GetImageNum_x                                     0x894A30
#define EQ_Item__CreateItemClient_x                                0x6124F0
#define EQ_Item__GetItemValue_x                                    0x895D50
#define EQ_Item__ValueSellMerchant_x                               0x8992E0
#define EQ_Item__IsKeyRingItem_x                                   0x897440
#define EQ_Item__CanGoInBag_x                                      0x613440
#define EQ_Item__IsEmpty_x                                         0x896F70
#define EQ_Item__GetMaxItemCount_x                                 0x896160
#define EQ_Item__GetHeldItem_x                                     0x894900
#define EQ_Item__GetAugmentFitBySlot_x                             0x892930

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x550050
#define EQ_LoadingS__Array_x                                       0xC0E698

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6388F0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A24C0
#define EQ_PC__GetCombatAbility_x                                  0x8A2B30
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A2BA0
#define EQ_PC__GetItemRecastTimer_x                                0x63A970
#define EQ_PC__HasLoreItem_x                                       0x631A00
#define EQ_PC__AlertInventoryChanged_x                             0x630B20
#define EQ_PC__GetPcZoneClient_x                                   0x65CF10
#define EQ_PC__RemoveMyAffect_x                                    0x63DBA0
#define EQ_PC__GetKeyRingItems_x                                   0x8A3400
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A31C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A36F0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x59B770
#define EQItemList__add_object_x                                   0x5C8700
#define EQItemList__add_item_x                                     0x59BCD0
#define EQItemList__delete_item_x                                  0x59BD20
#define EQItemList__FreeItemList_x                                 0x59BC20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52E780

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64FD30
#define EQPlayer__dEQPlayer_x                                      0x643070
#define EQPlayer__DoAttack_x                                       0x657BC0
#define EQPlayer__EQPlayer_x                                       0x643730
#define EQPlayer__SetNameSpriteState_x                             0x647A10
#define EQPlayer__SetNameSpriteTint_x                              0x6488E0
#define PlayerBase__HasProperty_j_x                                0x9865A0
#define EQPlayer__IsTargetable_x                                   0x986A40
#define EQPlayer__CanSee_x                                         0x9868A0
#define EQPlayer__CanSee1_x                                        0x986970
#define PlayerBase__GetVisibilityLineSegment_x                     0x986660

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x65A9A0
#define PlayerZoneClient__GetLevel_x                               0x65CF50
#define PlayerZoneClient__IsValidTeleport_x                        0x5C9870
#define PlayerZoneClient__LegalPlayerRace_x                        0x549410

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x652AA0
#define EQPlayerManager__GetSpawnByName_x                          0x652B50
#define EQPlayerManager__GetPlayerFromPartialName_x                0x652BE0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x616930
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6169B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6169F0
#define KeypressHandler__ClearCommandStateArray_x                  0x617E00
#define KeypressHandler__HandleKeyDown_x                           0x617E20
#define KeypressHandler__HandleKeyUp_x                             0x617EC0
#define KeypressHandler__SaveKeymapping_x                          0x618300

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76F2E0
#define MapViewMap__SaveEx_x                                       0x7726A0
#define MapViewMap__SetZoom_x                                      0x776D50

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B68C0

// StringTable 
#define StringTable__getString_x                                   0x8B1690

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63D810
#define PcZoneClient__RemovePetEffect_x                            0x63DE40
#define PcZoneClient__HasAlternateAbility_x                        0x637BD0
#define PcZoneClient__GetCurrentMod_x                              0x4E4870
#define PcZoneClient__GetModCap_x                                  0x4E4770
#define PcZoneClient__CanEquipItem_x                               0x638290
#define PcZoneClient__GetItemByID_x                                0x63ADE0
#define PcZoneClient__GetItemByItemClass_x                         0x63AF30
#define PcZoneClient__RemoveBuffEffect_x                           0x63DE60
#define PcZoneClient__BandolierSwap_x                              0x638EB0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x63A910

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CE450

//IconCache
#define IconCache__GetIcon_x                                       0x70F740

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x707250
#define CContainerMgr__CloseContainer_x                            0x707520
#define CContainerMgr__OpenExperimentContainer_x                   0x707FA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C7540

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x60B470

//CLootWnd
#define CLootWnd__LootAll_x                                        0x765720
#define CLootWnd__RequestLootSlot_x                                0x764950

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x568530
#define EQ_Spell__SpellAffects_x                                   0x5689A0
#define EQ_Spell__SpellAffectBase_x                                0x568760
#define EQ_Spell__IsStackable_x                                    0x4C9490
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9310
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6340
#define EQ_Spell__IsSPAStacking_x                                  0x5697F0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x568D00
#define EQ_Spell__IsNoRemove_x                                     0x4C9470
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x569800
#define __IsResEffectSpell_x                                       0x4C8830

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACA50

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C1000

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80E2E0
#define CTargetWnd__WndNotification_x                              0x80DB70
#define CTargetWnd__RefreshTargetBuffs_x                           0x80DE40
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80CCE0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8128E0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52C1C0
#define CTaskManager__HandleMessage_x                              0x52A660
#define CTaskManager__GetTaskStatus_x                              0x52C270
#define CTaskManager__GetElementDescription_x                      0x52C2F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x563AA0
#define EqSoundManager__PlayScriptMp3_x                            0x563C00
#define EqSoundManager__SoundAssistPlay_x                          0x6755E0
#define EqSoundManager__WaveInstancePlay_x                         0x674B50

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51FFD0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9422C0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x557AF0
#define CAltAbilityData__GetMercMaxRank_x                          0x557A80
#define CAltAbilityData__GetMaxRank_x                              0x54D0B0

//CTargetRing
#define CTargetRing__Cast_x                                        0x609590

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C92F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5079A0
#define CharacterBase__CreateItemIndex_x                           0x611690
#define CharacterBase__GetItemPossession_x                         0x4F3240
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C9610
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8C9670
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EE330
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EEB60
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6EEC10

//messages
#define msg_spell_worn_off_x                                       0x58D460
#define msg_new_text_x                                             0x5821F0
#define __msgTokenTextParam_x                                      0x58F990
#define msgTokenText_x                                             0x58FBE0

//SpellManager
#define SpellManager__vftable_x                                    0xAD6AC4
#define SpellManager__SpellManager_x                               0x678910
#define Spellmanager__LoadTextSpells_x                             0x679200
#define SpellManager__GetSpellByGroupAndRank_x                     0x678AE0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98A4F0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x508060
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x593740
#define ItemGlobalIndex__IsEquippedLocation_x                      0x62A0F0
#define ItemGlobalIndex__IsValidIndex_x                            0x5080C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C19A0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C1C20

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75DF90

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70B960
#define CCursorAttachment__AttachToCursor1_x                       0x70B9A0
#define CCursorAttachment__Deactivate_x                            0x70C970

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x935150
#define CSidlManagerBase__CreatePageWnd_x                          0x934970
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x930C20
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x930BB0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9522E0
#define CEQSuiteTextureLoader__GetTexture_x                        0x951FA0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x504F70
#define CFindItemWnd__WndNotification_x                            0x505A50
#define CFindItemWnd__Update_x                                     0x506590
#define CFindItemWnd__PickupSelectedItem_x                         0x5047D0

//IString
#define IString__Append_x                                          0x4F4A10

//Camera
#define CDisplay__cameraType_x                                     0xDE7194
#define EverQuest__Cameras_x                                       0xEAAAD4

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50D3B0
#define LootFiltersManager__GetItemFilterData_x                    0x50CCB0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50CCE0
#define LootFiltersManager__SetItemLootFilter_x                    0x50CF00

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B5520

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x990080
#define CResolutionHandler__GetWindowedStyle_x                     0x6702A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x704020

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D4400
#define CDistillerInfo__Instance_x                                 0x8D43A0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x724220
#define CGroupWnd__UpdateDisplay_x                                 0x723580

//ItemBase
#define ItemBase__IsLore_x                                         0x8974A0
#define ItemBase__IsLoreEquipped_x                                 0x897510

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C8660
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C87A0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C8800

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6656A0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x668FF0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4FB3E0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E9D10
#define FactionManagerClient__HandleFactionMessage_x               0x4EA380
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4EA940
#define FactionManagerClient__GetMaxFaction_x                      0x4EA95F
#define FactionManagerClient__GetMinFaction_x                      0x4EA910

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F3210

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x919870

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49B660

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F3440

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x556FA0

//CTargetManager
#define CTargetManager__Get_x                                      0x67C160

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6656A0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8760

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59BBC0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF48164

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
