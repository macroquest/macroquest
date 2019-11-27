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
#define __ExpectedVersionDate                                     "Nov 21 2019"
#define __ExpectedVersionTime                                     "13:55:21"
#define __ActualVersionDate_x                                      0xAF2DF0
#define __ActualVersionTime_x                                      0xAF2DE4
#define __ActualVersionBuild_x                                     0xADE9F4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61CE00
#define __MemChecker1_x                                            0x8ED9A0
#define __MemChecker2_x                                            0x6AB0A0
#define __MemChecker3_x                                            0x6AAFF0
#define __MemChecker4_x                                            0x8471B0
#define __EncryptPad0_x                                            0xC26A40
#define __EncryptPad1_x                                            0xC84B18
#define __EncryptPad2_x                                            0xC372D8
#define __EncryptPad3_x                                            0xC36ED8
#define __EncryptPad4_x                                            0xC751F8
#define __EncryptPad5_x                                            0xF4DD54
#define __AC1_x                                                    0x8038F6
#define __AC2_x                                                    0x5D691F
#define __AC3_x                                                    0x5DE01F
#define __AC4_x                                                    0x5E1FF0
#define __AC5_x                                                    0x5E82FF
#define __AC6_x                                                    0x5EC916
#define __AC7_x                                                    0x5D6390
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
#define __do_loot_x                                                0x5A2C90
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
#define __ScreenMode_x                                             0xDE70F4
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
#define __gfMaxZoomCameraDistance_x                                0xAE8730
#define __gfMaxCameraDistance_x                                    0xB14C7C
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
#define pinstCamActor_x                                            0xDE70E8
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
#define pinstViewActor_x                                           0xDE70E4
#define pinstWorldData_x                                           0xE9B6CC
#define pinstZoneAddr_x                                            0xEA9938
#define pinstPlayerPath_x                                          0xF4B3D8
#define pinstTargetIndicator_x                                     0xF4CD20
#define EQObject_Top_x                                             0xE9BA84
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE716C
#define pinstCAchievementsWnd_x                                    0xDE710C
#define pinstCActionsWnd_x                                         0xDE7128
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE78E4
#define pinstCAdvancedLootWnd_x                                    0xDE741C
#define pinstCAdventureLeaderboardWnd_x                            0xF5A3B0
#define pinstCAdventureRequestWnd_x                                0xF5A460
#define pinstCAdventureStatsWnd_x                                  0xF5A510
#define pinstCAggroMeterWnd_x                                      0xDE70A4
#define pinstCAlarmWnd_x                                           0xDE73DC
#define pinstCAlertHistoryWnd_x                                    0xDE7414
#define pinstCAlertStackWnd_x                                      0xDE717C
#define pinstCAlertWnd_x                                           0xDE7194
#define pinstCAltStorageWnd_x                                      0xF5A870
#define pinstCAudioTriggersWindow_x                                0xC9BFD8
#define pinstCAuraWnd_x                                            0xDE7078
#define pinstCAvaZoneWnd_x                                         0xDE73B0
#define pinstCBandolierWnd_x                                       0xDE709C
#define pinstCBankWnd_x                                            0xDE7074
#define pinstCBarterMerchantWnd_x                                  0xF5BAB0
#define pinstCBarterSearchWnd_x                                    0xF5BB60
#define pinstCBarterWnd_x                                          0xF5BC10
#define pinstCBazaarConfirmationWnd_x                              0xDE7138
#define pinstCBazaarSearchWnd_x                                    0xDE7104
#define pinstCBazaarWnd_x                                          0xDE73C8
#define pinstCBlockedBuffWnd_x                                     0xDE707C
#define pinstCBlockedPetBuffWnd_x                                  0xDE7098
#define pinstCBodyTintWnd_x                                        0xDE713C
#define pinstCBookWnd_x                                            0xDE70C0
#define pinstCBreathWnd_x                                          0xDE718C
#define pinstCBuffWindowNORMAL_x                                   0xDE7064
#define pinstCBuffWindowSHORT_x                                    0xDE7068
#define pinstCBugReportWnd_x                                       0xDE7070
#define pinstCButtonWnd_x                                          0x15DC9B0
#define pinstCCastingWnd_x                                         0xDE70B0
#define pinstCCastSpellWnd_x                                       0xDE7180
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE73CC
#define pinstCChatWindowManager_x                                  0xF5C6D0
#define pinstCClaimWnd_x                                           0xF5C828
#define pinstCColorPickerWnd_x                                     0xDE7134
#define pinstCCombatAbilityWnd_x                                   0xDE73D8
#define pinstCCombatSkillsSelectWnd_x                              0xDE73FC
#define pinstCCompassWnd_x                                         0xDE7130
#define pinstCConfirmationDialog_x                                 0xF61728
#define pinstCContainerMgr_x                                       0xDE73C0
#define pinstCContextMenuManager_x                                 0x15DC700
#define pinstCCursorAttachment_x                                   0xDE70A8
#define pinstCDynamicZoneWnd_x                                     0xF5CDF0
#define pinstCEditLabelWnd_x                                       0xDE78F0
#define pinstCEQMainWnd_x                                          0xF5D038
#define pinstCEventCalendarWnd_x                                   0xDE7060
#define pinstCExtendedTargetWnd_x                                  0xDE7090
#define pinstCFacePick_x                                           0xDE7410
#define pinstCFactionWnd_x                                         0xDE73B8
#define pinstCFellowshipWnd_x                                      0xF5D238
#define pinstCFileSelectionWnd_x                                   0xDE70AC
#define pinstCFindItemWnd_x                                        0xDE73A8
#define pinstCFindLocationWnd_x                                    0xF5D390
#define pinstCFriendsWnd_x                                         0xDE7418
#define pinstCGemsGameWnd_x                                        0xDE73B4
#define pinstCGiveWnd_x                                            0xDE73E0
#define pinstCGroupSearchFiltersWnd_x                              0xDE70B8
#define pinstCGroupSearchWnd_x                                     0xF5D788
#define pinstCGroupWnd_x                                           0xF5D838
#define pinstCGuildBankWnd_x                                       0xEAA77C
#define pinstCGuildCreationWnd_x                                   0xF5D998
#define pinstCGuildMgmtWnd_x                                       0xF5DA48
#define pinstCharacterCreation_x                                   0xDE7404
#define pinstCHelpWnd_x                                            0xDE74D8
#define pinstCHeritageSelectionWnd_x                               0xDE7440
#define pinstCHotButtonWnd_x                                       0xF5FBA0
#define pinstCHotButtonWnd1_x                                      0xF5FBA0
#define pinstCHotButtonWnd2_x                                      0xF5FBA4
#define pinstCHotButtonWnd3_x                                      0xF5FBA8
#define pinstCHotButtonWnd4_x                                      0xF5FBAC
#define pinstCIconSelectionWnd_x                                   0xDE70A0
#define pinstCInspectWnd_x                                         0xDE74D4
#define pinstCInventoryWnd_x                                       0xDE7444
#define pinstCInvSlotMgr_x                                         0xDE7164
#define pinstCItemDisplayManager_x                                 0xF60130
#define pinstCItemExpTransferWnd_x                                 0xF60264
#define pinstCItemOverflowWnd_x                                    0xDE7108
#define pinstCJournalCatWnd_x                                      0xDE70CC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE708C
#define pinstCKeyRingWnd_x                                         0xDE78EC
#define pinstCLargeDialogWnd_x                                     0xF623A8
#define pinstCLayoutCopyWnd_x                                      0xF605B0
#define pinstCLFGuildWnd_x                                         0xF60660
#define pinstCLoadskinWnd_x                                        0xDE73C4
#define pinstCLootFiltersCopyWnd_x                                 0xCB82A0
#define pinstCLootFiltersWnd_x                                     0xDE7184
#define pinstCLootSettingsWnd_x                                    0xDE71A4
#define pinstCLootWnd_x                                            0xDE70D0
#define pinstCMailAddressBookWnd_x                                 0xDE7170
#define pinstCMailCompositionWnd_x                                 0xDE7150
#define pinstCMailIgnoreListWnd_x                                  0xDE7174
#define pinstCMailWnd_x                                            0xDE712C
#define pinstCManageLootWnd_x                                      0xDE8750
#define pinstCMapToolbarWnd_x                                      0xDE74DC
#define pinstCMapViewWnd_x                                         0xDE7450
#define pinstCMarketplaceWnd_x                                     0xDE7190
#define pinstCMerchantWnd_x                                        0xDE70D4
#define pinstCMIZoneSelectWnd_x                                    0xF60E98
#define pinstCMusicPlayerWnd_x                                     0xDE70E0
#define pinstCNameChangeMercWnd_x                                  0xDE7124
#define pinstCNameChangePetWnd_x                                   0xDE7110
#define pinstCNameChangeWnd_x                                      0xDE7144
#define pinstCNoteWnd_x                                            0xDE7454
#define pinstCObjectPreviewWnd_x                                   0xDE71A0
#define pinstCOptionsWnd_x                                         0xDE7458
#define pinstCPetInfoWnd_x                                         0xDE7114
#define pinstCPetitionQWnd_x                                       0xDE70DC
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE7140
#define pinstCPlayerWnd_x                                          0xDE7118
#define pinstCPopupWndManager_x                                    0xF61728
#define pinstCProgressionSelectionWnd_x                            0xF617D8
#define pinstCPurchaseGroupWnd_x                                   0xDE73E8
#define pinstCPurchaseWnd_x                                        0xDE73BC
#define pinstCPvPLeaderboardWnd_x                                  0xF61888
#define pinstCPvPStatsWnd_x                                        0xF61938
#define pinstCQuantityWnd_x                                        0xDE7094
#define pinstCRaceChangeWnd_x                                      0xDE7168
#define pinstCRaidOptionsWnd_x                                     0xDE70BC
#define pinstCRaidWnd_x                                            0xDE7154
#define pinstCRealEstateItemsWnd_x                                 0xDE7100
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE7080
#define pinstCRealEstateManageWnd_x                                0xDE73F0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE740C
#define pinstCRealEstatePlotSearchWnd_x                            0xDE7448
#define pinstCRealEstatePurchaseWnd_x                              0xDE746C
#define pinstCRespawnWnd_x                                         0xDE7088
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE7178
#define pinstCSendMoneyWnd_x                                       0xDE73F8
#define pinstCServerListWnd_x                                      0xDE78F4
#define pinstCSkillsSelectWnd_x                                    0xDE73D4
#define pinstCSkillsWnd_x                                          0xDE73AC
#define pinstCSocialEditWnd_x                                      0xDE78E8
#define pinstCSocialWnd_x                                          0xDE7120
#define pinstCSpellBookWnd_x                                       0xDE73D0
#define pinstCStoryWnd_x                                           0xDE711C
#define pinstCTargetOfTargetWnd_x                                  0xF63760
#define pinstCTargetWnd_x                                          0xDE7084
#define pinstCTaskOverlayWnd_x                                     0xDE73E4
#define pinstCTaskSelectWnd_x                                      0xF638B8
#define pinstCTaskManager_x                                        0xCB8BE0
#define pinstCTaskTemplateSelectWnd_x                              0xF63968
#define pinstCTaskWnd_x                                            0xF63A18
#define pinstCTextEntryWnd_x                                       0xDE706C
#define pinstCTimeLeftWnd_x                                        0xDE70B4
#define pinstCTipWndCONTEXT_x                                      0xF63C1C
#define pinstCTipWndOFDAY_x                                        0xF63C18
#define pinstCTitleWnd_x                                           0xF63CC8
#define pinstCTrackingWnd_x                                        0xDE744C
#define pinstCTradeskillWnd_x                                      0xF63E30
#define pinstCTradeWnd_x                                           0xDE714C
#define pinstCTrainWnd_x                                           0xDE7148
#define pinstCTributeBenefitWnd_x                                  0xF64030
#define pinstCTributeMasterWnd_x                                   0xF640E0
#define pinstCTributeTrophyWnd_x                                   0xF64190
#define pinstCVideoModesWnd_x                                      0xDE719C
#define pinstCVoiceMacroWnd_x                                      0xF4D488
#define pinstCVoteResultsWnd_x                                     0xDE70D8
#define pinstCVoteWnd_x                                            0xDE70C8
#define pinstCWebManager_x                                         0xF4DB04
#define pinstCZoneGuideWnd_x                                       0xDE73EC
#define pinstCZonePathWnd_x                                        0xDE7400

#define pinstEQSuiteTextureLoader_x                                0xC865F0
#define pinstItemIconCache_x                                       0xF5CFF0
#define pinstLootFiltersManager_x                                  0xCB8350
#define pinstRewardSelectionWnd_x                                  0xF62080

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x59E0F0
#define __CastRay2_x                                               0x59E140
#define __ConvertItemTags_x                                        0x5B9CA0
#define __CleanItemTags_x                                          0x47CAA0
#define __DoesFileExist_x                                          0x8F0A80
#define __EQGetTime_x                                              0x8ED470
#define __ExecuteCmd_x                                             0x596A40
#define __FixHeading_x                                             0x988450
#define __GameLoop_x                                               0x6AA290
#define __get_bearing_x                                            0x59DC60
#define __get_melee_range_x                                        0x59E330
#define __GetAnimationCache_x                                      0x70F5C0
#define __GetGaugeValueFromEQ_x                                    0x801DA0
#define __GetLabelFromEQ_x                                         0x803880
#define __GetXTargetType_x                                         0x989F10
#define __HandleMouseWheel_x                                       0x6AB150
#define __HeadingDiff_x                                            0x9884C0
#define __HelpPath_x                                               0xF48834
#define __LoadFrontEnd_x                                           0x6A75B0
#define __NewUIINI_x                                               0x801A70
#define __ProcessGameEvents_x                                      0x5FE190
#define __ProcessMouseEvent_x                                      0x5FD950
#define __SaveColors_x                                             0x547D80
#define __STMLToText_x                                             0x92BA00
#define __ToggleKeyRingItem_x                                      0x50B0A0
#define CMemoryMappedFile__SetFile_x                               0xA77730
#define CrashDetected_x                                            0x6A9050
#define DrawNetStatus_x                                            0x62A010
#define Expansion_HoT_x                                            0xEAA784
#define Teleport_Table_Size_x                                      0xE9BB70
#define Teleport_Table_x                                           0xE996C0
#define Util__FastTime_x                                           0x8ED040

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48FD30
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x498C40
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498A10
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4932C0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492710

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54F8F0
#define AltAdvManager__IsAbilityReady_x                            0x54E820
#define AltAdvManager__GetAAById_x                                 0x54EA20
#define AltAdvManager__CanTrainAbility_x                           0x54EA90
#define AltAdvManager__CanSeeAbility_x                             0x54EDF0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9BE0
#define CharacterZoneClient__HasSkill_x                            0x4D4AD0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D61F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BDEC0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA4C0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8B80
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8C60
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8D40
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2CB0
#define CharacterZoneClient__BardCastBard_x                        0x4C5810
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA590
#define CharacterZoneClient__GetEffect_x                           0x4BA400
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3D00
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3DD0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3E20
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3F70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4140
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B23A0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7150
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6BD0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D0D80
#define CBankWnd__WndNotification_x                                0x6D0B60

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DE630

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60CB90
#define CButtonWnd__CButtonWnd_x                                   0x927DF0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FE6D0
#define CChatManager__InitContextMenu_x                            0x6F7820
#define CChatManager__FreeChatWindow_x                             0x6FD210
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8090
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FE350
#define CChatManager__CreateChatWindow_x                           0x6FD850

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E81A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93C4B0
#define CContextMenu__dCContextMenu_x                              0x93C6E0
#define CContextMenu__AddMenuItem_x                                0x93C6F0
#define CContextMenu__RemoveMenuItem_x                             0x93CA00
#define CContextMenu__RemoveAllMenuItems_x                         0x93CA20
#define CContextMenu__CheckMenuItem_x                              0x93CAA0
#define CContextMenu__SetMenuItem_x                                0x93C920
#define CContextMenu__AddSeparator_x                               0x93C880

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93D040
#define CContextMenuManager__RemoveMenu_x                          0x93D0B0
#define CContextMenuManager__PopupMenu_x                           0x93D170
#define CContextMenuManager__Flush_x                               0x93CFE0
#define CContextMenuManager__GetMenu_x                             0x49AF10
#define CContextMenuManager__CreateDefaultMenu_x                   0x709DB0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CB4E0
#define CChatService__GetFriendName_x                              0x8CB4F0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FEF40
#define CChatWindow__Clear_x                                       0x700200
#define CChatWindow__WndNotification_x                             0x700990
#define CChatWindow__AddHistory_x                                  0x6FFAC0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9398F0
#define CComboWnd__Draw_x                                          0x938DF0
#define CComboWnd__GetCurChoice_x                                  0x939730
#define CComboWnd__GetListRect_x                                   0x9392A0
#define CComboWnd__GetTextRect_x                                   0x939960
#define CComboWnd__InsertChoice_x                                  0x939430
#define CComboWnd__SetColors_x                                     0x939400
#define CComboWnd__SetChoice_x                                     0x939700
#define CComboWnd__GetItemCount_x                                  0x939740
#define CComboWnd__GetCurChoiceText_x                              0x939780
#define CComboWnd__GetChoiceText_x                                 0x939750
#define CComboWnd__InsertChoiceAtIndex_x                           0x9394C0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7077A0
#define CContainerWnd__vftable_x                                   0xAFBFE4
#define CContainerWnd__SetContainer_x                              0x708D00

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x542820
#define CDisplay__PreZoneMainUI_x                                  0x542830
#define CDisplay__CleanGameUI_x                                    0x547B40
#define CDisplay__GetClickedActor_x                                0x53AB40
#define CDisplay__GetUserDefinedColor_x                            0x533200
#define CDisplay__GetWorldFilePath_x                               0x53C5B0
#define CDisplay__is3dON_x                                         0x5377A0
#define CDisplay__ReloadUI_x                                       0x541CB0
#define CDisplay__WriteTextHD2_x                                   0x537590
#define CDisplay__TrueDistance_x                                   0x53E270
#define CDisplay__SetViewActor_x                                   0x53A460
#define CDisplay__GetFloorHeight_x                                 0x537860
#define CDisplay__SetRenderWindow_x                                0x5361C0
#define CDisplay__ToggleScreenshotMode_x                           0x539F30

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95C270

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x93FA00
#define CEditWnd__GetCharIndexPt_x                                 0x940920
#define CEditWnd__GetDisplayString_x                               0x9407D0
#define CEditWnd__GetHorzOffset_x                                  0x93F050
#define CEditWnd__GetLineForPrintableChar_x                        0x941A90
#define CEditWnd__GetSelStartPt_x                                  0x940BD0
#define CEditWnd__GetSTMLSafeText_x                                0x9405F0
#define CEditWnd__PointFromPrintableChar_x                         0x9416D0
#define CEditWnd__SelectableCharFromPoint_x                        0x941840
#define CEditWnd__SetEditable_x                                    0x940C90
#define CEditWnd__SetWindowTextA_x                                 0x940370

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5EBDF0
#define CEverQuest__ClickedPlayer_x                                0x5DDE00
#define CEverQuest__CreateTargetIndicator_x                        0x5FB420
#define CEverQuest__DeleteTargetIndicator_x                        0x5FB4B0
#define CEverQuest__DoTellWindow_x                                 0x4E8280
#define CEverQuest__OutputTextToLog_x                              0x4E8500
#define CEverQuest__DropHeldItemOnGround_x                         0x5D2E40
#define CEverQuest__dsp_chat_x                                     0x4E8890
#define CEverQuest__trimName_x                                     0x5F7700
#define CEverQuest__Emote_x                                        0x5EC650
#define CEverQuest__EnterZone_x                                    0x5E65D0
#define CEverQuest__GetBodyTypeDesc_x                              0x5F0FC0
#define CEverQuest__GetClassDesc_x                                 0x5F1600
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F1C00
#define CEverQuest__GetDeityDesc_x                                 0x5F9D60
#define CEverQuest__GetLangDesc_x                                  0x5F1DC0
#define CEverQuest__GetRaceDesc_x                                  0x5F15E0
#define CEverQuest__InterpretCmd_x                                 0x5FA330
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D7040
#define CEverQuest__LMouseUp_x                                     0x5D53D0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D7920
#define CEverQuest__RMouseUp_x                                     0x5D6350
#define CEverQuest__SetGameState_x                                 0x5D2BD0
#define CEverQuest__UPCNotificationFlush_x                         0x5F7600
#define CEverQuest__IssuePetCommand_x                              0x5F31C0
#define CEverQuest__ReportSuccessfulHit_x                          0x5EDA40

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7195C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x719620
#define CGaugeWnd__Draw_x                                          0x718C50

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AEDA0
#define CGuild__GetGuildName_x                                     0x4ADE80
#define CGuild__GetGuildIndex_x                                    0x4AE210

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x734A20

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60CF50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7419D0
#define CInvSlotMgr__MoveItem_x                                    0x740710
#define CInvSlotMgr__SelectSlot_x                                  0x741AA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73EFC0
#define CInvSlot__SliderComplete_x                                 0x73CD40
#define CInvSlot__GetItemBase_x                                    0x73C6C0
#define CInvSlot__UpdateItem_x                                     0x73C830

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x743520
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7426C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7430A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FD0D0
#define CItemDisplayWnd__UpdateStrings_x                           0x751B80
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74B860
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74BD90
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x752180
#define CItemDisplayWnd__AboutToShow_x                             0x7517E0
#define CItemDisplayWnd__WndNotification_x                         0x753270
#define CItemDisplayWnd__RequestConvertItem_x                      0x752D30
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x750840
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x751600

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x835DD0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7577C0

// CLabel 
#define CLabel__Draw_x                                             0x75D260

// CListWnd
#define CListWnd__CListWnd_x                                       0x9120C0
#define CListWnd__dCListWnd_x                                      0x9123D0
#define CListWnd__AddColumn_x                                      0x916800
#define CListWnd__AddColumn1_x                                     0x916850
#define CListWnd__AddLine_x                                        0x916BE0
#define CListWnd__AddString_x                                      0x9169E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9165D0
#define CListWnd__CalculateVSBRange_x                              0x9163B0
#define CListWnd__ClearSel_x                                       0x9173C0
#define CListWnd__ClearAllSel_x                                    0x917420
#define CListWnd__CloseAndUpdateEditWindow_x                       0x917E20
#define CListWnd__Compare_x                                        0x915D00
#define CListWnd__Draw_x                                           0x912500
#define CListWnd__DrawColumnSeparators_x                           0x914CD0
#define CListWnd__DrawHeader_x                                     0x915140
#define CListWnd__DrawItem_x                                       0x915640
#define CListWnd__DrawLine_x                                       0x914E40
#define CListWnd__DrawSeparator_x                                  0x914D70
#define CListWnd__EnableLine_x                                     0x9145B0
#define CListWnd__EnsureVisible_x                                  0x917D50
#define CListWnd__ExtendSel_x                                      0x9172F0
#define CListWnd__GetColumnTooltip_x                               0x9140F0
#define CListWnd__GetColumnMinWidth_x                              0x914160
#define CListWnd__GetColumnWidth_x                                 0x914060
#define CListWnd__GetCurSel_x                                      0x9139F0
#define CListWnd__GetItemAtPoint_x                                 0x914820
#define CListWnd__GetItemAtPoint1_x                                0x914890
#define CListWnd__GetItemData_x                                    0x913A70
#define CListWnd__GetItemHeight_x                                  0x913E30
#define CListWnd__GetItemIcon_x                                    0x913C00
#define CListWnd__GetItemRect_x                                    0x9146A0
#define CListWnd__GetItemText_x                                    0x913AB0
#define CListWnd__GetSelList_x                                     0x917470
#define CListWnd__GetSeparatorRect_x                               0x914AD0
#define CListWnd__InsertLine_x                                     0x916FD0
#define CListWnd__RemoveLine_x                                     0x917120
#define CListWnd__SetColors_x                                      0x916390
#define CListWnd__SetColumnJustification_x                         0x9160D0
#define CListWnd__SetColumnWidth_x                                 0x915FF0
#define CListWnd__SetCurSel_x                                      0x917230
#define CListWnd__SetItemColor_x                                   0x917A10
#define CListWnd__SetItemData_x                                    0x9179D0
#define CListWnd__SetItemText_x                                    0x9175E0
#define CListWnd__ShiftColumnSeparator_x                           0x916190
#define CListWnd__Sort_x                                           0x915E80
#define CListWnd__ToggleSel_x                                      0x917260
#define CListWnd__SetColumnsSizable_x                              0x916230
#define CListWnd__SetItemWnd_x                                     0x917890
#define CListWnd__GetItemWnd_x                                     0x913C50
#define CListWnd__SetItemIcon_x                                    0x917660
#define CListWnd__CalculateCustomWindowPositions_x                 0x9166C0
#define CListWnd__SetVScrollPos_x                                  0x915FD0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x772A30
#define CMapViewWnd__GetWorldCoordinates_x                         0x771140
#define CMapViewWnd__HandleLButtonDown_x                           0x76E180

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x792A30
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x793310
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x793840
#define CMerchantWnd__SelectRecoverySlot_x                         0x7967C0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7915A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x79C360
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x792640

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8991D0
#define CPacketScrambler__hton_x                                   0x8991C0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x931030
#define CSidlManager__FindScreenPieceTemplate_x                    0x931440
#define CSidlManager__FindScreenPieceTemplate1_x                   0x931230
#define CSidlManager__CreateLabel_x                                0x7F44F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9343A0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x934580
#define CSidlManager__CreateXWnd_x                                 0x7F4420
#define CSidlManager__CreateHotButtonWnd_x                         0x7F49F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92DB30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92DA30
#define CSidlScreenWnd__ConvertToRes_x                             0x9532C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92D4C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92D1B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92D280
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92D350
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92DFD0
#define CSidlScreenWnd__EnableIniStorage_x                         0x92E4A0
#define CSidlScreenWnd__GetSidlPiece_x                             0x92E1C0
#define CSidlScreenWnd__Init1_x                                    0x92CDB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x92E4F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92F010
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92C1B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x92EB90
#define CSidlScreenWnd__StoreIniVis_x                              0x92EEF0
#define CSidlScreenWnd__WndNotification_x                          0x92DEE0
#define CSidlScreenWnd__GetChildItem_x                             0x92E420
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91DC90
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DC5D0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x671540
#define CSkillMgr__GetSkillCap_x                                   0x671720
#define CSkillMgr__GetNameToken_x                                  0x670CC0
#define CSkillMgr__IsActivatedSkill_x                              0x670E00
#define CSkillMgr__IsCombatSkill_x                                 0x670D40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93DE30
#define CSliderWnd__SetValue_x                                     0x93DCA0
#define CSliderWnd__SetNumTicks_x                                  0x93DD00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FA540

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9465D0
#define CStmlWnd__CalculateHSBRange_x                              0x9476E0
#define CStmlWnd__CalculateVSBRange_x                              0x947660
#define CStmlWnd__CanBreakAtCharacter_x                            0x94BA20
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94C6B0
#define CStmlWnd__ForceParseNow_x                                  0x946BC0
#define CStmlWnd__GetNextTagPiece_x                                0x94B980
#define CStmlWnd__GetSTMLText_x                                    0x4FAA10
#define CStmlWnd__GetVisibleText_x                                 0x946BE0
#define CStmlWnd__InitializeWindowVariables_x                      0x94C500
#define CStmlWnd__MakeStmlColorTag_x                               0x945C40
#define CStmlWnd__MakeWndNotificationTag_x                         0x945CB0
#define CStmlWnd__SetSTMLText_x                                    0x944CF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x94D7A0
#define CStmlWnd__UpdateHistoryString_x                            0x94C8C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x943E40
#define CTabWnd__DrawCurrentPage_x                                 0x944570
#define CTabWnd__DrawTab_x                                         0x944290
#define CTabWnd__GetCurrentPage_x                                  0x943640
#define CTabWnd__GetPageInnerRect_x                                0x943880
#define CTabWnd__GetTabInnerRect_x                                 0x9437C0
#define CTabWnd__GetTabRect_x                                      0x943670
#define CTabWnd__InsertPage_x                                      0x943A90
#define CTabWnd__SetPage_x                                         0x943900
#define CTabWnd__SetPageRect_x                                     0x943D80
#define CTabWnd__UpdatePage_x                                      0x944150
#define CTabWnd__GetPageFromTabIndex_x                             0x9441D0
#define CTabWnd__GetCurrentTabIndex_x                              0x943630

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x757BB0
#define CPageWnd__SetTabText_x                                     0x943180

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8A30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91AB00
#define CTextureFont__GetTextExtent_x                              0x91ACC0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A4450
#define CHtmlComponentWnd__ValidateUri_x                           0x736410
#define CHtmlWnd__SetClientCallbacks_x                             0x611FD0
#define CHtmlWnd__AddObserver_x                                    0x611FF0
#define CHtmlWnd__RemoveObserver_x                                 0x612050
#define Window__getProgress_x                                      0x84E790
#define Window__getStatus_x                                        0x84E7B0
#define Window__getURI_x                                           0x84E7C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x958D00

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x907DA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E7F80
#define CXStr__CXStr1_x                                            0x4F5960
#define CXStr__CXStr3_x                                            0x8E95B0
#define CXStr__dCXStr_x                                            0x478030
#define CXStr__operator_equal_x                                    0x8E97E0
#define CXStr__operator_equal1_x                                   0x8E9820
#define CXStr__operator_plus_equal1_x                              0x8EA2B0
#define CXStr__SetString_x                                         0x8EC1A0
#define CXStr__operator_char_p_x                                   0x8E9D20
#define CXStr__GetChar_x                                           0x8EBAD0
#define CXStr__Delete_x                                            0x8EB3A0
#define CXStr__GetUnicode_x                                        0x8EBB40
#define CXStr__GetLength_x                                         0x4A87E0
#define CXStr__Mid_x                                               0x47CE50
#define CXStr__Insert_x                                            0x8EBBA0
#define CXStr__FindNext_x                                          0x8EB810

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93C0B0
#define CXWnd__BringToTop_x                                        0x921380
#define CXWnd__Center_x                                            0x920F00
#define CXWnd__ClrFocus_x                                          0x920D20
#define CXWnd__Destroy_x                                           0x920DC0
#define CXWnd__DoAllDrawing_x                                      0x91D420
#define CXWnd__DrawChildren_x                                      0x91D3F0
#define CXWnd__DrawColoredRect_x                                   0x91D880
#define CXWnd__DrawTooltip_x                                       0x91BF20
#define CXWnd__DrawTooltipAtPoint_x                                0x91BFE0
#define CXWnd__GetBorderFrame_x                                    0x91D6E0
#define CXWnd__GetChildWndAt_x                                     0x921420
#define CXWnd__GetClientClipRect_x                                 0x91F6D0
#define CXWnd__GetScreenClipRect_x                                 0x91F7A0
#define CXWnd__GetScreenRect_x                                     0x91F970
#define CXWnd__GetTooltipRect_x                                    0x91D8D0
#define CXWnd__GetWindowTextA_x                                    0x49C5E0
#define CXWnd__IsActive_x                                          0x91E010
#define CXWnd__IsDescendantOf_x                                    0x920310
#define CXWnd__IsReallyVisible_x                                   0x920340
#define CXWnd__IsType_x                                            0x921A90
#define CXWnd__Move_x                                              0x9203B0
#define CXWnd__Move1_x                                             0x920460
#define CXWnd__ProcessTransition_x                                 0x920EB0
#define CXWnd__Refade_x                                            0x920710
#define CXWnd__Resize_x                                            0x9209A0
#define CXWnd__Right_x                                             0x921140
#define CXWnd__SetFocus_x                                          0x920CE0
#define CXWnd__SetFont_x                                           0x920D50
#define CXWnd__SetKeyTooltip_x                                     0x9218A0
#define CXWnd__SetMouseOver_x                                      0x91E830
#define CXWnd__StartFade_x                                         0x920200
#define CXWnd__GetChildItem_x                                      0x921590
#define CXWnd__SetParent_x                                         0x9200C0
#define CXWnd__Minimize_x                                          0x920A00

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x954340

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x924240
#define CXWndManager__DrawWindows_x                                0x924260
#define CXWndManager__GetKeyboardFlags_x                           0x926A60
#define CXWndManager__HandleKeyboardMsg_x                          0x926610
#define CXWndManager__RemoveWnd_x                                  0x926C90
#define CXWndManager__RemovePendingDeletionWnd_x                   0x927210

// CDBStr
#define CDBStr__GetString_x                                        0x5321D0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB4A0
#define EQ_Character__Cur_HP_x                                     0x4D1B10
#define EQ_Character__Cur_Mana_x                                   0x4D9240
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE510
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B1FE0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2130
#define EQ_Character__GetHPRegen_x                                 0x4DF010
#define EQ_Character__GetEnduranceRegen_x                          0x4DF610
#define EQ_Character__GetManaRegen_x                               0x4DFA50
#define EQ_Character__Max_Endurance_x                              0x637FA0
#define EQ_Character__Max_HP_x                                     0x4D1940
#define EQ_Character__Max_Mana_x                                   0x637DA0
#define EQ_Character__doCombatAbility_x                            0x63A3E0
#define EQ_Character__UseSkill_x                                   0x4E1820
#define EQ_Character__GetConLevel_x                                0x630F00
#define EQ_Character__IsExpansionFlag_x                            0x595200
#define EQ_Character__TotalEffect_x                                0x4C4F50
#define EQ_Character__GetPCSpellAffect_x                           0x4BF260
#define EQ_Character__SpellDuration_x                              0x4BED90
#define EQ_Character__GetAdjustedSkill_x                           0x4D4890
#define EQ_Character__GetBaseSkill_x                               0x4D5830
#define EQ_Character__CanUseItem_x                                 0x4D9550

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B8370

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64E570

//PcClient
#define PcClient__PcClient_x                                       0x62E630

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9110
#define CCharacterListWnd__EnterWorld_x                            0x4B8B50
#define CCharacterListWnd__Quit_x                                  0x4B88A0
#define CCharacterListWnd__UpdateList_x                            0x4B8CE0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x613200
#define EQ_Item__CreateItemTagString_x                             0x892AB0
#define EQ_Item__IsStackable_x                                     0x8975B0
#define EQ_Item__GetImageNum_x                                     0x894520
#define EQ_Item__CreateItemClient_x                                0x6123D0
#define EQ_Item__GetItemValue_x                                    0x8957E0
#define EQ_Item__ValueSellMerchant_x                               0x898DA0
#define EQ_Item__IsKeyRingItem_x                                   0x896F00
#define EQ_Item__CanGoInBag_x                                      0x613320
#define EQ_Item__IsEmpty_x                                         0x896A50
#define EQ_Item__GetMaxItemCount_x                                 0x895C00
#define EQ_Item__GetHeldItem_x                                     0x8943F0
#define EQ_Item__GetAugmentFitBySlot_x                             0x892410

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x550600
#define EQ_LoadingS__Array_x                                       0xC0E698

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6388F0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A1FE0
#define EQ_PC__GetCombatAbility_x                                  0x8A2650
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A26C0
#define EQ_PC__GetItemRecastTimer_x                                0x63A960
#define EQ_PC__HasLoreItem_x                                       0x6316C0
#define EQ_PC__AlertInventoryChanged_x                             0x630830
#define EQ_PC__GetPcZoneClient_x                                   0x65CFD0
#define EQ_PC__RemoveMyAffect_x                                    0x63DBA0
#define EQ_PC__GetKeyRingItems_x                                   0x8A2F20
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A2CE0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A3210

// EQItemList 
#define EQItemList__EQItemList_x                                   0x59B6F0
#define EQItemList__add_object_x                                   0x5C86D0
#define EQItemList__add_item_x                                     0x59BC50
#define EQItemList__delete_item_x                                  0x59BCA0
#define EQItemList__FreeItemList_x                                 0x59BBA0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52ECF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64FDF0
#define EQPlayer__dEQPlayer_x                                      0x6430F0
#define EQPlayer__DoAttack_x                                       0x657C90
#define EQPlayer__EQPlayer_x                                       0x6437B0
#define EQPlayer__SetNameSpriteState_x                             0x647AD0
#define EQPlayer__SetNameSpriteTint_x                              0x6489A0
#define PlayerBase__HasProperty_j_x                                0x986840
#define EQPlayer__IsTargetable_x                                   0x986CE0
#define EQPlayer__CanSee_x                                         0x986B40
#define EQPlayer__CanSee1_x                                        0x986C10
#define PlayerBase__GetVisibilityLineSegment_x                     0x986900

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x65AA70
#define PlayerZoneClient__GetLevel_x                               0x65D010
#define PlayerZoneClient__IsValidTeleport_x                        0x5C9840
#define PlayerZoneClient__LegalPlayerRace_x                        0x549A00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x652BA0
#define EQPlayerManager__GetSpawnByName_x                          0x652C50
#define EQPlayerManager__GetPlayerFromPartialName_x                0x652CE0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6168F0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x616970
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6169B0
#define KeypressHandler__ClearCommandStateArray_x                  0x617DC0
#define KeypressHandler__HandleKeyDown_x                           0x617DE0
#define KeypressHandler__HandleKeyUp_x                             0x617E80
#define KeypressHandler__SaveKeymapping_x                          0x6182C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76E8A0
#define MapViewMap__SaveEx_x                                       0x771C60
#define MapViewMap__SetZoom_x                                      0x776320

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B6290

// StringTable 
#define StringTable__getString_x                                   0x8B1180

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63D810
#define PcZoneClient__RemovePetEffect_x                            0x63DE40
#define PcZoneClient__HasAlternateAbility_x                        0x637BD0
#define PcZoneClient__GetCurrentMod_x                              0x4E48E0
#define PcZoneClient__GetModCap_x                                  0x4E47E0
#define PcZoneClient__CanEquipItem_x                               0x638290
#define PcZoneClient__GetItemByID_x                                0x63ADE0
#define PcZoneClient__GetItemByItemClass_x                         0x63AF30
#define PcZoneClient__RemoveBuffEffect_x                           0x63DE60
#define PcZoneClient__BandolierSwap_x                              0x638EA0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x63A900

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CE360

//IconCache
#define IconCache__GetIcon_x                                       0x70EE60

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x706940
#define CContainerMgr__CloseContainer_x                            0x706C10
#define CContainerMgr__OpenExperimentContainer_x                   0x707690

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C68B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x60B350

//CLootWnd
#define CLootWnd__LootAll_x                                        0x764D30
#define CLootWnd__RequestLootSlot_x                                0x763F60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x568B80
#define EQ_Spell__SpellAffects_x                                   0x568FF0
#define EQ_Spell__SpellAffectBase_x                                0x568DB0
#define EQ_Spell__IsStackable_x                                    0x4C9540
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C93C0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6490
#define EQ_Spell__IsSPAStacking_x                                  0x569E40
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x569350
#define EQ_Spell__IsNoRemove_x                                     0x4C9520
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x569E50
#define __IsResEffectSpell_x                                       0x4C8990

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACAF0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C0990

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80D840
#define CTargetWnd__WndNotification_x                              0x80D0D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x80D3A0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80C230

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x811E60

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52C740
#define CTaskManager__HandleMessage_x                              0x52ABC0
#define CTaskManager__GetTaskStatus_x                              0x52C7F0
#define CTaskManager__GetElementDescription_x                      0x52C870

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5640F0
#define EqSoundManager__PlayScriptMp3_x                            0x564250
#define EqSoundManager__SoundAssistPlay_x                          0x6754B0
#define EqSoundManager__WaveInstancePlay_x                         0x674A20

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x520550

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x942690

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x557FA0
#define CAltAbilityData__GetMercMaxRank_x                          0x557F30
#define CAltAbilityData__GetMaxRank_x                              0x54D6A0

//CTargetRing
#define CTargetRing__Cast_x                                        0x609470

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C93A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x507890
#define CharacterBase__CreateItemIndex_x                           0x611580
#define CharacterBase__GetItemPossession_x                         0x4F3190
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C8F80
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8C8FE0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EDAA0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EE2D0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6EE380

//messages
#define msg_spell_worn_off_x                                       0x58D4A0
#define msg_new_text_x                                             0x582280
#define __msgTokenTextParam_x                                      0x58F9D0
#define msgTokenText_x                                             0x58FC20

//SpellManager
#define SpellManager__vftable_x                                    0xAD6A9C
#define SpellManager__SpellManager_x                               0x6787E0
#define Spellmanager__LoadTextSpells_x                             0x6790D0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6789B0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98A800

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x507F40
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x593770
#define ItemGlobalIndex__IsEquippedLocation_x                      0x629E70
#define ItemGlobalIndex__IsValidIndex_x                            0x507FA0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C1330
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C15B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75D5A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70B050
#define CCursorAttachment__AttachToCursor1_x                       0x70B090
#define CCursorAttachment__Deactivate_x                            0x70C050

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9353D0
#define CSidlManagerBase__CreatePageWnd_x                          0x934BD0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x930E50
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x930DE0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9528F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9525B0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x504E00
#define CFindItemWnd__WndNotification_x                            0x5058E0
#define CFindItemWnd__Update_x                                     0x506450
#define CFindItemWnd__PickupSelectedItem_x                         0x504660

//IString
#define IString__Append_x                                          0x4F4A20

//Camera
#define CDisplay__cameraType_x                                     0xDE7198
#define EverQuest__Cameras_x                                       0xEAAAD4

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50D370
#define LootFiltersManager__GetItemFilterData_x                    0x50CC70
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50CCA0
#define LootFiltersManager__SetItemLootFilter_x                    0x50CEC0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B48A0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x990420
#define CResolutionHandler__GetWindowedStyle_x                     0x66FFB0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7036A0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3CB0
#define CDistillerInfo__Instance_x                                 0x8D3C50

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x723810
#define CGroupWnd__UpdateDisplay_x                                 0x722B70

//ItemBase
#define ItemBase__IsLore_x                                         0x896F60
#define ItemBase__IsLoreEquipped_x                                 0x896FE0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C8630
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C8770
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C87D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6656E0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x669090

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4FB260

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E9C80
#define FactionManagerClient__HandleFactionMessage_x               0x4EA2F0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4EA8B0
#define FactionManagerClient__GetMaxFaction_x                      0x4EA8CF
#define FactionManagerClient__GetMinFaction_x                      0x4EA880

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F3160

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x919A90

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49B8F0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F3450

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x557430

//CTargetManager
#define CTargetManager__Get_x                                      0x67C020

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6656E0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A87F0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59BB40

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF48164

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
