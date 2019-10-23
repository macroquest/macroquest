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
#define __ExpectedVersionDate                                     "Oct 23 2019"
#define __ExpectedVersionTime                                     "04:22:47"
#define __ActualVersionDate_x                                      0xAFD978
#define __ActualVersionTime_x                                      0xAFD96C
#define __ActualVersionBuild_x                                     0xAE9644

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x624E10
#define __MemChecker1_x                                            0x8F7150
#define __MemChecker2_x                                            0x6B3860
#define __MemChecker3_x                                            0x6B37B0
#define __MemChecker4_x                                            0x84F740
#define __EncryptPad0_x                                            0xC333F0
#define __EncryptPad1_x                                            0xC915B0
#define __EncryptPad2_x                                            0xC43C88
#define __EncryptPad3_x                                            0xC43888
#define __EncryptPad4_x                                            0xC81C08
#define __EncryptPad5_x                                            0xF5ACA8
#define __AC1_x                                                    0x80C0C6
#define __AC2_x                                                    0x5DECDF
#define __AC3_x                                                    0x5E63DF
#define __AC4_x                                                    0x5EA3A0
#define __AC5_x                                                    0x5F06AF
#define __AC6_x                                                    0x5F4CB6
#define __AC7_x                                                    0x5DE750
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1B673C

// Direct Input
#define DI8__Main_x                                                0xF5D184
#define DI8__Keyboard_x                                            0xF5D188
#define DI8__Mouse_x                                               0xF5D1A0
#define DI8__Mouse_Copy_x                                          0xEB6374
#define DI8__Mouse_Check_x                                         0xF5ACD0
#define __AutoSkillArray_x                                         0xEB728C
#define __Attack_x                                                 0xF550B3
#define __Autofire_x                                               0xF550B4
#define __BindList_x                                               0xC21E20
#define g_eqCommandStates_x                                        0xC22BA0
#define __Clicks_x                                                 0xEB642C
#define __CommandList_x                                            0xC23760
#define __CurrentMapLabel_x                                        0xF6DB34
#define __CurrentSocial_x                                          0xC0B7CC
#define __DoAbilityList_x                                          0xEECBD4
#define __do_loot_x                                                0x5AB010
#define __DrawHandler_x                                            0x15ECEA8
#define __GroupCount_x                                             0xEA876A
#define __Guilds_x                                                 0xEACB80
#define __gWorld_x                                                 0xEA861C
#define __HWnd_x                                                   0xF5D1A4
#define __heqmain_x                                                0xF5D178
#define __InChatMode_x                                             0xEB635C
#define __LastTell_x                                               0xEB82D0
#define __LMouseHeldTime_x                                         0xEB6498
#define __Mouse_x                                                  0xF5D164
#define __MouseLook_x                                              0xEB63F2
#define __MouseEventTime_x                                         0xF55B94
#define __gpbCommandEvent_x                                        0xEA8960
#define __NetStatusToggle_x                                        0xEB63F5
#define __PCNames_x                                                0xEB787C
#define __RangeAttackReady_x                                       0xEB7570
#define __RMouseHeldTime_x                                         0xEB6494
#define __RunWalkState_x                                           0xEB6360
#define __ScreenMode_x                                             0xDF3F44
#define __ScreenX_x                                                0xEB6314
#define __ScreenY_x                                                0xEB6310
#define __ScreenXMax_x                                             0xEB6318
#define __ScreenYMax_x                                             0xEB631C
#define __ServerHost_x                                             0xEA8BB3
#define __ServerName_x                                             0xEECB94
#define __ShiftKeyDown_x                                           0xEB69EC
#define __ShowNames_x                                              0xEB772C
#define __Socials_x                                                0xEECC94
#define __SubscriptionType_x                                       0xFB2038
#define __TargetAggroHolder_x                                      0xF704E8
#define __ZoneType_x                                               0xEB67F0
#define __GroupAggro_x                                             0xF70528
#define __LoginName_x                                              0xF5D8DC
#define __Inviter_x                                                0xF55030
#define __AttackOnAssist_x                                         0xEB76E8
#define __UseTellWindows_x                                         0xEB7A18
#define __gfMaxZoomCameraDistance_x                                0xAF32B8
#define __gfMaxCameraDistance_x                                    0xB1F83C
#define __pulAutoRun_x                                             0xEB6410
#define __pulForward_x                                             0xEB7A50
#define __pulBackward_x                                            0xEB7A54
#define __pulTurnRight_x                                           0xEB7A58
#define __pulTurnLeft_x                                            0xEB7A5C
#define __pulStrafeLeft_x                                          0xEB7A60
#define __pulStrafeRight_x                                         0xEB7A64

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEA8F18
#define instEQZoneInfo_x                                           0xEB65E8
#define pinstActiveBanker_x                                        0xEA8978
#define pinstActiveCorpse_x                                        0xEA8970
#define pinstActiveGMaster_x                                       0xEA8974
#define pinstActiveMerchant_x                                      0xEA896C
#define pinstAltAdvManager_x                                       0xDF5148
#define pinstBandageTarget_x                                       0xEA8988
#define pinstCamActor_x                                            0xDF3F38
#define pinstCDBStr_x                                              0xDF3E64
#define pinstCDisplay_x                                            0xEA8620
#define pinstCEverQuest_x                                          0xF5D19C
#define pinstEverQuestInfo_x                                       0xEB6308
#define pinstCharData_x                                            0xEA874C
#define pinstCharSpawn_x                                           0xEA8A40
#define pinstControlledMissile_x                                   0xEA8F10
#define pinstControlledPlayer_x                                    0xEA8A40
#define pinstCResolutionHandler_x                                  0x15ED0D8
#define pinstCSidlManager_x                                        0x15EC070
#define pinstCXWndManager_x                                        0x15EC06C
#define instDynamicZone_x                                          0xEACA58
#define pinstDZMember_x                                            0xEACB68
#define pinstDZTimerInfo_x                                         0xEACB6C
#define pinstEqLogin_x                                             0xF5D228
#define instEQMisc_x                                               0xDF3DA8
#define pinstEQSoundManager_x                                      0xDF6118
#define pinstEQSpellStrings_x                                      0xCB6868
#define instExpeditionLeader_x                                     0xEACAA2
#define instExpeditionName_x                                       0xEACAE2
#define pinstGroup_x                                               0xEA8766
#define pinstImeManager_x                                          0x15EC068
#define pinstLocalPlayer_x                                         0xEA8968
#define pinstMercenaryData_x                                       0xF5768C
#define pinstMercenaryStats_x                                      0xF70634
#define pinstModelPlayer_x                                         0xEA8980
#define pinstPCData_x                                              0xEA874C
#define pinstSkillMgr_x                                            0xF597F0
#define pinstSpawnManager_x                                        0xF58298
#define pinstSpellManager_x                                        0xF59A10
#define pinstSpellSets_x                                           0xF4DCDC
#define pinstStringTable_x                                         0xEA8750
#define pinstSwitchManager_x                                       0xEA64B8
#define pinstTarget_x                                              0xEA89BC
#define pinstTargetObject_x                                        0xEA8A48
#define pinstTargetSwitch_x                                        0xEA6614
#define pinstTaskMember_x                                          0xDF3C38
#define pinstTrackTarget_x                                         0xEA8A44
#define pinstTradeTarget_x                                         0xEA897C
#define instTributeActive_x                                        0xDF3DC9
#define pinstViewActor_x                                           0xDF3F34
#define pinstWorldData_x                                           0xEA6608
#define pinstZoneAddr_x                                            0xEB6888
#define pinstPlayerPath_x                                          0xF58330
#define pinstTargetIndicator_x                                     0xF59C78
#define EQObject_Top_x                                             0xEA8964
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDF41F8
#define pinstCAchievementsWnd_x                                    0xDF3F90
#define pinstCActionsWnd_x                                         0xDF3FBC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDF476C
#define pinstCAdvancedLootWnd_x                                    0xDF42C4
#define pinstCAdventureLeaderboardWnd_x                            0xF67308
#define pinstCAdventureRequestWnd_x                                0xF673B8
#define pinstCAdventureStatsWnd_x                                  0xF67468
#define pinstCAggroMeterWnd_x                                      0xDF3F28
#define pinstCAlarmWnd_x                                           0xDF4264
#define pinstCAlertHistoryWnd_x                                    0xDF42BC
#define pinstCAlertStackWnd_x                                      0xDF420C
#define pinstCAlertWnd_x                                           0xDF4220
#define pinstCAltStorageWnd_x                                      0xF677C8
#define pinstCAudioTriggersWindow_x                                0xCA8B98
#define pinstCAuraWnd_x                                            0xDF4798
#define pinstCAvaZoneWnd_x                                         0xDF4228
#define pinstCBandolierWnd_x                                       0xDF3F24
#define pinstCBankWnd_x                                            0xDF4794
#define pinstCBarterMerchantWnd_x                                  0xF68A08
#define pinstCBarterSearchWnd_x                                    0xF68AB8
#define pinstCBarterWnd_x                                          0xF68B68
#define pinstCBazaarConfirmationWnd_x                              0xDF3FCC
#define pinstCBazaarSearchWnd_x                                    0xDF3F84
#define pinstCBazaarWnd_x                                          0xDF424C
#define pinstCBlockedBuffWnd_x                                     0xDF3F00
#define pinstCBlockedPetBuffWnd_x                                  0xDF3F20
#define pinstCBodyTintWnd_x                                        0xDF3FD0
#define pinstCBookWnd_x                                            0xDF3F64
#define pinstCBreathWnd_x                                          0xDF4218
#define pinstCBuffWindowNORMAL_x                                   0xDF4784
#define pinstCBuffWindowSHORT_x                                    0xDF4788
#define pinstCBugReportWnd_x                                       0xDF4790
#define pinstCButtonWnd_x                                          0x15EC2D8
#define pinstCCastingWnd_x                                         0xDF3F54
#define pinstCCastSpellWnd_x                                       0xDF4210
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDF4250
#define pinstCChatWindowManager_x                                  0xF69628
#define pinstCClaimWnd_x                                           0xF69780
#define pinstCColorPickerWnd_x                                     0xDF3FC4
#define pinstCCombatAbilityWnd_x                                   0xDF425C
#define pinstCCombatSkillsSelectWnd_x                              0xDF4284
#define pinstCCompassWnd_x                                         0xDF3FC0
#define pinstCConfirmationDialog_x                                 0xF6E680
#define pinstCContainerMgr_x                                       0xDF4244
#define pinstCContextMenuManager_x                                 0x15EC028
#define pinstCCursorAttachment_x                                   0xDF3F30
#define pinstCDynamicZoneWnd_x                                     0xF69D48
#define pinstCEditLabelWnd_x                                       0xDF4778
#define pinstCEQMainWnd_x                                          0xF69F90
#define pinstCEventCalendarWnd_x                                   0xDF4780
#define pinstCExtendedTargetWnd_x                                  0xDF3F14
#define pinstCFacePick_x                                           0xDF42B4
#define pinstCFactionWnd_x                                         0xDF423C
#define pinstCFellowshipWnd_x                                      0xF6A190
#define pinstCFileSelectionWnd_x                                   0xDF3F50
#define pinstCFindItemWnd_x                                        0xDF4230
#define pinstCFindLocationWnd_x                                    0xF6A2E8
#define pinstCFriendsWnd_x                                         0xDF42C0
#define pinstCGemsGameWnd_x                                        0xDF4238
#define pinstCGiveWnd_x                                            0xDF4268
#define pinstCGroupSearchFiltersWnd_x                              0xDF3F5C
#define pinstCGroupSearchWnd_x                                     0xF6A6E0
#define pinstCGroupWnd_x                                           0xF6A790
#define pinstCGuildBankWnd_x                                       0xEB76CC
#define pinstCGuildCreationWnd_x                                   0xF6A8F0
#define pinstCGuildMgmtWnd_x                                       0xF6A9A0
#define pinstCharacterCreation_x                                   0xDF428C
#define pinstCHelpWnd_x                                            0xDF4764
#define pinstCHeritageSelectionWnd_x                               0xDF42C8
#define pinstCHotButtonWnd_x                                       0xF6CAF8
#define pinstCHotButtonWnd1_x                                      0xF6CAF8
#define pinstCHotButtonWnd2_x                                      0xF6CAFC
#define pinstCHotButtonWnd3_x                                      0xF6CB00
#define pinstCHotButtonWnd4_x                                      0xF6CB04
#define pinstCIconSelectionWnd_x                                   0xDF3F2C
#define pinstCInspectWnd_x                                         0xDF4760
#define pinstCInventoryWnd_x                                       0xDF42CC
#define pinstCInvSlotMgr_x                                         0xDF3FF4
#define pinstCItemDisplayManager_x                                 0xF6D088
#define pinstCItemExpTransferWnd_x                                 0xF6D1BC
#define pinstCItemOverflowWnd_x                                    0xDF3F8C
#define pinstCJournalCatWnd_x                                      0xDF3F6C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDF3F18
#define pinstCKeyRingWnd_x                                         0xDF4774
#define pinstCLargeDialogWnd_x                                     0xF6F300
#define pinstCLayoutCopyWnd_x                                      0xF6D508
#define pinstCLFGuildWnd_x                                         0xF6D5B8
#define pinstCLoadskinWnd_x                                        0xDF4248
#define pinstCLootFiltersCopyWnd_x                                 0xCC5140
#define pinstCLootFiltersWnd_x                                     0xDF4214
#define pinstCLootSettingsWnd_x                                    0xDF422C
#define pinstCLootWnd_x                                            0xDF3F70
#define pinstCMailAddressBookWnd_x                                 0xDF4200
#define pinstCMailCompositionWnd_x                                 0xDF3FE4
#define pinstCMailIgnoreListWnd_x                                  0xDF4204
#define pinstCMailWnd_x                                            0xDF3FB8
#define pinstCManageLootWnd_x                                      0xDF55F8
#define pinstCMapToolbarWnd_x                                      0xDF4768
#define pinstCMapViewWnd_x                                         0xDF42E0
#define pinstCMarketplaceWnd_x                                     0xDF421C
#define pinstCMerchantWnd_x                                        0xDF3F74
#define pinstCMIZoneSelectWnd_x                                    0xF6DDF0
#define pinstCMusicPlayerWnd_x                                     0xDF3F7C
#define pinstCNameChangeMercWnd_x                                  0xDF3FB4
#define pinstCNameChangePetWnd_x                                   0xDF3F94
#define pinstCNameChangeWnd_x                                      0xDF3FDC
#define pinstCNoteWnd_x                                            0xDF4354
#define pinstCObjectPreviewWnd_x                                   0xDF4224
#define pinstCOptionsWnd_x                                         0xDF4758
#define pinstCPetInfoWnd_x                                         0xDF3F98
#define pinstCPetitionQWnd_x                                       0xDF3F80
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDF3FD4
#define pinstCPlayerWnd_x                                          0xDF3F9C
#define pinstCPopupWndManager_x                                    0xF6E680
#define pinstCProgressionSelectionWnd_x                            0xF6E730
#define pinstCPurchaseGroupWnd_x                                   0xDF4270
#define pinstCPurchaseWnd_x                                        0xDF4240
#define pinstCPvPLeaderboardWnd_x                                  0xF6E7E0
#define pinstCPvPStatsWnd_x                                        0xF6E890
#define pinstCQuantityWnd_x                                        0xDF3F1C
#define pinstCRaceChangeWnd_x                                      0xDF41FC
#define pinstCRaidOptionsWnd_x                                     0xDF3F60
#define pinstCRaidWnd_x                                            0xDF3FEC
#define pinstCRealEstateItemsWnd_x                                 0xDF3F88
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDF3F08
#define pinstCRealEstateManageWnd_x                                0xDF4278
#define pinstCRealEstateNeighborhoodWnd_x                          0xDF42B8
#define pinstCRealEstatePlotSearchWnd_x                            0xDF42D0
#define pinstCRealEstatePurchaseWnd_x                              0xDF475C
#define pinstCRespawnWnd_x                                         0xDF3F0C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDF4208
#define pinstCSendMoneyWnd_x                                       0xDF4280
#define pinstCServerListWnd_x                                      0xDF477C
#define pinstCSkillsSelectWnd_x                                    0xDF4254
#define pinstCSkillsWnd_x                                          0xDF4234
#define pinstCSocialEditWnd_x                                      0xDF4770
#define pinstCSocialWnd_x                                          0xDF3FB0
#define pinstCSpellBookWnd_x                                       0xDF4258
#define pinstCStoryWnd_x                                           0xDF3FA0
#define pinstCTargetOfTargetWnd_x                                  0xF706B8
#define pinstCTargetWnd_x                                          0xDF3F04
#define pinstCTaskOverlayWnd_x                                     0xDF426C
#define pinstCTaskSelectWnd_x                                      0xF70810
#define pinstCTaskManager_x                                        0xCC5A80
#define pinstCTaskTemplateSelectWnd_x                              0xF708C0
#define pinstCTaskWnd_x                                            0xF70970
#define pinstCTextEntryWnd_x                                       0xDF478C
#define pinstCTimeLeftWnd_x                                        0xDF3F58
#define pinstCTipWndCONTEXT_x                                      0xF70B74
#define pinstCTipWndOFDAY_x                                        0xF70B70
#define pinstCTitleWnd_x                                           0xF70C20
#define pinstCTrackingWnd_x                                        0xDF42D4
#define pinstCTradeskillWnd_x                                      0xF70D88
#define pinstCTradeWnd_x                                           0xDF3FE0
#define pinstCTrainWnd_x                                           0xDF3FD8
#define pinstCTributeBenefitWnd_x                                  0xF70F88
#define pinstCTributeMasterWnd_x                                   0xF71038
#define pinstCTributeTrophyWnd_x                                   0xF710E8
#define pinstCVideoModesWnd_x                                      0xDF3FE8
#define pinstCVoiceMacroWnd_x                                      0xF5A3E0
#define pinstCVoteResultsWnd_x                                     0xDF3F78
#define pinstCVoteWnd_x                                            0xDF3F68
#define pinstCWebManager_x                                         0xF5AA5C
#define pinstCZoneGuideWnd_x                                       0xDF4274
#define pinstCZonePathWnd_x                                        0xDF4288

#define pinstEQSuiteTextureLoader_x                                0xC93088
#define pinstItemIconCache_x                                       0xF69F48
#define pinstLootFiltersManager_x                                  0xCC51F0
#define pinstRewardSelectionWnd_x                                  0xF6EFD8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5A6470
#define __CastRay2_x                                               0x5A64C0
#define __ConvertItemTags_x                                        0x5C2020
#define __CleanItemTags_x                                          0x47D120
#define __DoesFileExist_x                                          0x8FA230
#define __EQGetTime_x                                              0x8F6C20
#define __ExecuteCmd_x                                             0x59ED20
#define __FixHeading_x                                             0x991C00
#define __GameLoop_x                                               0x6B2A50
#define __get_bearing_x                                            0x5A5FE0
#define __get_melee_range_x                                        0x5A66B0
#define __GetAnimationCache_x                                      0x717DE0
#define __GetGaugeValueFromEQ_x                                    0x80A570
#define __GetLabelFromEQ_x                                         0x80C050
#define __GetXTargetType_x                                         0x993720
#define __HandleMouseWheel_x                                       0x6B3910
#define __HeadingDiff_x                                            0x991C70
#define __HelpPath_x                                               0xF55784
#define __LoadFrontEnd_x                                           0x6AFD70
#define __NewUIINI_x                                               0x80A240
#define __ProcessGameEvents_x                                      0x606530
#define __ProcessMouseEvent_x                                      0x605CF0
#define __SaveColors_x                                             0x54C570
#define __STMLToText_x                                             0x934FD0
#define __ToggleKeyRingItem_x                                      0x50FDE0
#define CMemoryMappedFile__SetFile_x                               0xA80F40
#define CrashDetected_x                                            0x6B1810
#define DrawNetStatus_x                                            0x632190
#define Expansion_HoT_x                                            0xEB76D4
#define Teleport_Table_Size_x                                      0xEA8A64
#define Teleport_Table_x                                           0xEA6618
#define Util__FastTime_x                                           0x8F67F0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4993D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4991A0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A50
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492EA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5540E0
#define AltAdvManager__IsAbilityReady_x                            0x553050
#define AltAdvManager__GetAAById_x                                 0x553250
#define AltAdvManager__CanTrainAbility_x                           0x5532C0
#define AltAdvManager__CanSeeAbility_x                             0x553620

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA010
#define CharacterZoneClient__HasSkill_x                            0x4D4F00
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6620
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE3B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA9B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8FD0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D90B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9190
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3060
#define CharacterZoneClient__BardCastBard_x                        0x4C5BC0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA80
#define CharacterZoneClient__GetEffect_x                           0x4BA8F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C40B0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4180
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C41D0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4320
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C44F0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2830
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7580
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7000

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D94F0
#define CBankWnd__WndNotification_x                                0x6D92D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6DB0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x614C90
#define CButtonWnd__CButtonWnd_x                                   0x931380

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706E90
#define CChatManager__InitContextMenu_x                            0x6FFFE0
#define CChatManager__FreeChatWindow_x                             0x7059D0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8550
#define CChatManager__SetLockedActiveChatWindow_x                  0x706B10
#define CChatManager__CreateChatWindow_x                           0x706010

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8660

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9459F0
#define CContextMenu__dCContextMenu_x                              0x945C30
#define CContextMenu__AddMenuItem_x                                0x945C40
#define CContextMenu__RemoveMenuItem_x                             0x945F50
#define CContextMenu__RemoveAllMenuItems_x                         0x945F70
#define CContextMenu__CheckMenuItem_x                              0x945FF0
#define CContextMenu__SetMenuItem_x                                0x945E70
#define CContextMenu__AddSeparator_x                               0x945DD0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x946590
#define CContextMenuManager__RemoveMenu_x                          0x946600
#define CContextMenuManager__PopupMenu_x                           0x9466C0
#define CContextMenuManager__Flush_x                               0x946530
#define CContextMenuManager__GetMenu_x                             0x49B5F0
#define CContextMenuManager__CreateDefaultMenu_x                   0x7125C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x89D360
#define CChatService__GetFriendName_x                              0x8D3B70

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x707740
#define CChatWindow__Clear_x                                       0x708A00
#define CChatWindow__WndNotification_x                             0x709190
#define CChatWindow__AddHistory_x                                  0x7082C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x942E40
#define CComboWnd__Draw_x                                          0x942340
#define CComboWnd__GetCurChoice_x                                  0x942C80
#define CComboWnd__GetListRect_x                                   0x9427F0
#define CComboWnd__GetTextRect_x                                   0x942EB0
#define CComboWnd__InsertChoice_x                                  0x942980
#define CComboWnd__SetColors_x                                     0x942950
#define CComboWnd__SetChoice_x                                     0x942C50
#define CComboWnd__GetItemCount_x                                  0x942C90
#define CComboWnd__GetCurChoiceText_x                              0x942CD0
#define CComboWnd__GetChoiceText_x                                 0x942CA0
#define CComboWnd__InsertChoiceAtIndex_x                           0x942A10

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70FFA0
#define CContainerWnd__vftable_x                                   0xB06B5C
#define CContainerWnd__SetContainer_x                              0x711500

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x546FB0
#define CDisplay__PreZoneMainUI_x                                  0x546FC0
#define CDisplay__CleanGameUI_x                                    0x54C330
#define CDisplay__GetClickedActor_x                                0x53F2D0
#define CDisplay__GetUserDefinedColor_x                            0x537990
#define CDisplay__GetWorldFilePath_x                               0x540D40
#define CDisplay__is3dON_x                                         0x53BF30
#define CDisplay__ReloadUI_x                                       0x546440
#define CDisplay__WriteTextHD2_x                                   0x53BD20
#define CDisplay__TrueDistance_x                                   0x542A00
#define CDisplay__SetViewActor_x                                   0x53EBF0
#define CDisplay__GetFloorHeight_x                                 0x53BFF0
#define CDisplay__SetRenderWindow_x                                0x53A950
#define CDisplay__ToggleScreenshotMode_x                           0x53E6C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x965760

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x948F50
#define CEditWnd__GetCharIndexPt_x                                 0x949E80
#define CEditWnd__GetDisplayString_x                               0x949D20
#define CEditWnd__GetHorzOffset_x                                  0x948590
#define CEditWnd__GetLineForPrintableChar_x                        0x94B020
#define CEditWnd__GetSelStartPt_x                                  0x94A130
#define CEditWnd__GetSTMLSafeText_x                                0x949B40
#define CEditWnd__PointFromPrintableChar_x                         0x94AC50
#define CEditWnd__SelectableCharFromPoint_x                        0x94ADC0
#define CEditWnd__SetEditable_x                                    0x94A200
#define CEditWnd__SetWindowTextA_x                                 0x9498C0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5F4190
#define CEverQuest__ClickedPlayer_x                                0x5E61C0
#define CEverQuest__CreateTargetIndicator_x                        0x6037C0
#define CEverQuest__DeleteTargetIndicator_x                        0x603850
#define CEverQuest__DoTellWindow_x                                 0x4E8740
#define CEverQuest__OutputTextToLog_x                              0x4E89C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5DB200
#define CEverQuest__dsp_chat_x                                     0x4E8D50
#define CEverQuest__trimName_x                                     0x5FFAA0
#define CEverQuest__Emote_x                                        0x5F49F0
#define CEverQuest__EnterZone_x                                    0x5EE980
#define CEverQuest__GetBodyTypeDesc_x                              0x5F9360
#define CEverQuest__GetClassDesc_x                                 0x5F99A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F9FA0
#define CEverQuest__GetDeityDesc_x                                 0x602100
#define CEverQuest__GetLangDesc_x                                  0x5FA160
#define CEverQuest__GetRaceDesc_x                                  0x5F9980
#define CEverQuest__InterpretCmd_x                                 0x6026D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5DF400
#define CEverQuest__LMouseUp_x                                     0x5DD790
#define CEverQuest__RightClickedOnPlayer_x                         0x5DFCE0
#define CEverQuest__RMouseUp_x                                     0x5DE710
#define CEverQuest__SetGameState_x                                 0x5DAF90
#define CEverQuest__UPCNotificationFlush_x                         0x5FF9A0
#define CEverQuest__IssuePetCommand_x                              0x5FB560
#define CEverQuest__ReportSuccessfulHit_x                          0x5F5DE0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x721FA0
#define CGaugeWnd__CalcLinesFillRect_x                             0x722000
#define CGaugeWnd__Draw_x                                          0x721620

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF350
#define CGuild__GetGuildName_x                                     0x4AE430
#define CGuild__GetGuildIndex_x                                    0x4AE7C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73D3B0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x615050

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74A3F0
#define CInvSlotMgr__MoveItem_x                                    0x749100
#define CInvSlotMgr__SelectSlot_x                                  0x74A4C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x747980
#define CInvSlot__SliderComplete_x                                 0x7456E0
#define CInvSlot__GetItemBase_x                                    0x745050
#define CInvSlot__UpdateItem_x                                     0x7451C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74BF10
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74B0C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74BA90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8058C0
#define CItemDisplayWnd__UpdateStrings_x                           0x75A540
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7542B0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7547C0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75AB40
#define CItemDisplayWnd__AboutToShow_x                             0x75A190
#define CItemDisplayWnd__WndNotification_x                         0x75BC30
#define CItemDisplayWnd__RequestConvertItem_x                      0x75B6F0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7591F0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x759FB0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x83E3B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x760140

// CLabel 
#define CLabel__Draw_x                                             0x765B20

// CListWnd
#define CListWnd__CListWnd_x                                       0x91B4C0
#define CListWnd__dCListWnd_x                                      0x91B7E0
#define CListWnd__AddColumn_x                                      0x91FC40
#define CListWnd__AddColumn1_x                                     0x91FC90
#define CListWnd__AddLine_x                                        0x920020
#define CListWnd__AddString_x                                      0x91FE20
#define CListWnd__CalculateFirstVisibleLine_x                      0x91FA00
#define CListWnd__CalculateVSBRange_x                              0x91F7F0
#define CListWnd__ClearSel_x                                       0x920800
#define CListWnd__ClearAllSel_x                                    0x920860
#define CListWnd__CloseAndUpdateEditWindow_x                       0x921280
#define CListWnd__Compare_x                                        0x91F130
#define CListWnd__Draw_x                                           0x91B910
#define CListWnd__DrawColumnSeparators_x                           0x91E100
#define CListWnd__DrawHeader_x                                     0x91E570
#define CListWnd__DrawItem_x                                       0x91EA70
#define CListWnd__DrawLine_x                                       0x91E270
#define CListWnd__DrawSeparator_x                                  0x91E1A0
#define CListWnd__EnableLine_x                                     0x91D9D0
#define CListWnd__EnsureVisible_x                                  0x9211A0
#define CListWnd__ExtendSel_x                                      0x920730
#define CListWnd__GetColumnTooltip_x                               0x91D510
#define CListWnd__GetColumnMinWidth_x                              0x91D580
#define CListWnd__GetColumnWidth_x                                 0x91D480
#define CListWnd__GetCurSel_x                                      0x91CE10
#define CListWnd__GetItemAtPoint_x                                 0x91DC50
#define CListWnd__GetItemAtPoint1_x                                0x91DCC0
#define CListWnd__GetItemData_x                                    0x91CE90
#define CListWnd__GetItemHeight_x                                  0x91D250
#define CListWnd__GetItemIcon_x                                    0x91D020
#define CListWnd__GetItemRect_x                                    0x91DAC0
#define CListWnd__GetItemText_x                                    0x91CED0
#define CListWnd__GetSelList_x                                     0x9208B0
#define CListWnd__GetSeparatorRect_x                               0x91DF00
#define CListWnd__InsertLine_x                                     0x920410
#define CListWnd__RemoveLine_x                                     0x920560
#define CListWnd__SetColors_x                                      0x91F7D0
#define CListWnd__SetColumnJustification_x                         0x91F500
#define CListWnd__SetColumnWidth_x                                 0x91F420
#define CListWnd__SetCurSel_x                                      0x920670
#define CListWnd__SetItemColor_x                                   0x920E50
#define CListWnd__SetItemData_x                                    0x920E10
#define CListWnd__SetItemText_x                                    0x920A20
#define CListWnd__ShiftColumnSeparator_x                           0x91F5C0
#define CListWnd__Sort_x                                           0x91F2B0
#define CListWnd__ToggleSel_x                                      0x9206A0
#define CListWnd__SetColumnsSizable_x                              0x91F670
#define CListWnd__SetItemWnd_x                                     0x920CD0
#define CListWnd__GetItemWnd_x                                     0x91D070
#define CListWnd__SetItemIcon_x                                    0x920AA0
#define CListWnd__CalculateCustomWindowPositions_x                 0x91FB00
#define CListWnd__SetVScrollPos_x                                  0x91F400

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77B1B0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7798C0
#define CMapViewWnd__HandleLButtonDown_x                           0x776900

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79B2D0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79BBB0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79C0E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79F070
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x799E30
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4C20
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79AEE0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A1450
#define CPacketScrambler__hton_x                                   0x8A1440

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x93A610
#define CSidlManager__FindScreenPieceTemplate_x                    0x93AA20
#define CSidlManager__FindScreenPieceTemplate1_x                   0x93A810
#define CSidlManager__CreateLabel_x                                0x7FCC80
#define CSidlManager__CreateXWndFromTemplate_x                     0x93D980
#define CSidlManager__CreateXWndFromTemplate1_x                    0x93DB50
#define CSidlManager__CreateXWnd_x                                 0x7FCBB0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FD180

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x937100
#define CSidlScreenWnd__CalculateVSBRange_x                        0x937000
#define CSidlScreenWnd__ConvertToRes_x                             0x95C700
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x936A90
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x936780
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x936850
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x936920
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9375A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x937A70
#define CSidlScreenWnd__GetSidlPiece_x                             0x937790
#define CSidlScreenWnd__Init1_x                                    0x936380
#define CSidlScreenWnd__LoadIniInfo_x                              0x937AC0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9385F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x935780
#define CSidlScreenWnd__StoreIniInfo_x                             0x938170
#define CSidlScreenWnd__StoreIniVis_x                              0x9384D0
#define CSidlScreenWnd__WndNotification_x                          0x9374B0
#define CSidlScreenWnd__GetChildItem_x                             0x9379F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9270F0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15EBEF8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6794B0
#define CSkillMgr__GetSkillCap_x                                   0x679690
#define CSkillMgr__GetNameToken_x                                  0x678C30
#define CSkillMgr__IsActivatedSkill_x                              0x678D70
#define CSkillMgr__IsCombatSkill_x                                 0x678CB0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x947370
#define CSliderWnd__SetValue_x                                     0x9471E0
#define CSliderWnd__SetNumTicks_x                                  0x947240

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x802D50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94FBA0
#define CStmlWnd__CalculateHSBRange_x                              0x950CD0
#define CStmlWnd__CalculateVSBRange_x                              0x950C40
#define CStmlWnd__CanBreakAtCharacter_x                            0x955000
#define CStmlWnd__FastForwardToEndOfTag_x                          0x955C90
#define CStmlWnd__ForceParseNow_x                                  0x950190
#define CStmlWnd__GetNextTagPiece_x                                0x954F60
#define CStmlWnd__GetSTMLText_x                                    0x4FF3B0
#define CStmlWnd__GetVisibleText_x                                 0x9501B0
#define CStmlWnd__InitializeWindowVariables_x                      0x955AE0
#define CStmlWnd__MakeStmlColorTag_x                               0x94F210
#define CStmlWnd__MakeWndNotificationTag_x                         0x94F280
#define CStmlWnd__SetSTMLText_x                                    0x94E2C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x956D90
#define CStmlWnd__UpdateHistoryString_x                            0x955EA0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x94D3F0
#define CTabWnd__DrawCurrentPage_x                                 0x94DB20
#define CTabWnd__DrawTab_x                                         0x94D840
#define CTabWnd__GetCurrentPage_x                                  0x94CBF0
#define CTabWnd__GetPageInnerRect_x                                0x94CE30
#define CTabWnd__GetTabInnerRect_x                                 0x94CD70
#define CTabWnd__GetTabRect_x                                      0x94CC20
#define CTabWnd__InsertPage_x                                      0x94D040
#define CTabWnd__SetPage_x                                         0x94CEB0
#define CTabWnd__SetPageRect_x                                     0x94D330
#define CTabWnd__UpdatePage_x                                      0x94D700
#define CTabWnd__GetPageFromTabIndex_x                             0x94D780
#define CTabWnd__GetCurrentTabIndex_x                              0x94CBE0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x760510
#define CPageWnd__SetTabText_x                                     0x94C730

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9040

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x923F70
#define CTextureFont__GetTextExtent_x                              0x924130

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC920
#define CHtmlComponentWnd__ValidateUri_x                           0x73EDB0
#define CHtmlWnd__SetClientCallbacks_x                             0x61A0D0
#define CHtmlWnd__AddObserver_x                                    0x61A0F0
#define CHtmlWnd__RemoveObserver_x                                 0x61A150
#define Window__getProgress_x                                      0x856D40
#define Window__getStatus_x                                        0x856D60
#define Window__getURI_x                                           0x856D70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9621B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x910FC0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8390
#define CXStr__CXStr1_x                                            0x481620
#define CXStr__CXStr3_x                                            0x8F2D20
#define CXStr__dCXStr_x                                            0x478750
#define CXStr__operator_equal_x                                    0x8F2F50
#define CXStr__operator_equal1_x                                   0x8F2F90
#define CXStr__operator_plus_equal1_x                              0x8F3A20
#define CXStr__SetString_x                                         0x8F5910
#define CXStr__operator_char_p_x                                   0x8F3490
#define CXStr__GetChar_x                                           0x8F5240
#define CXStr__Delete_x                                            0x8F4B10
#define CXStr__GetUnicode_x                                        0x8F52B0
#define CXStr__GetLength_x                                         0x4A8DF0
#define CXStr__Mid_x                                               0x47D4D0
#define CXStr__Insert_x                                            0x8F5310
#define CXStr__FindNext_x                                          0x8F4F80

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x945600
#define CXWnd__BringToTop_x                                        0x92A900
#define CXWnd__Center_x                                            0x92A480
#define CXWnd__ClrFocus_x                                          0x92A2A0
#define CXWnd__Destroy_x                                           0x92A340
#define CXWnd__DoAllDrawing_x                                      0x926880
#define CXWnd__DrawChildren_x                                      0x926850
#define CXWnd__DrawColoredRect_x                                   0x926CE0
#define CXWnd__DrawTooltip_x                                       0x9253B0
#define CXWnd__DrawTooltipAtPoint_x                                0x925470
#define CXWnd__GetBorderFrame_x                                    0x926B40
#define CXWnd__GetChildWndAt_x                                     0x92A9A0
#define CXWnd__GetClientClipRect_x                                 0x928B50
#define CXWnd__GetScreenClipRect_x                                 0x928C20
#define CXWnd__GetScreenRect_x                                     0x928DF0
#define CXWnd__GetTooltipRect_x                                    0x926D30
#define CXWnd__GetWindowTextA_x                                    0x49CD60
#define CXWnd__IsActive_x                                          0x927470
#define CXWnd__IsDescendantOf_x                                    0x9297D0
#define CXWnd__IsReallyVisible_x                                   0x929800
#define CXWnd__IsType_x                                            0x92B010
#define CXWnd__Move_x                                              0x929880
#define CXWnd__Move1_x                                             0x929940
#define CXWnd__ProcessTransition_x                                 0x92A430
#define CXWnd__Refade_x                                            0x929C20
#define CXWnd__Resize_x                                            0x929EC0
#define CXWnd__Right_x                                             0x92A6C0
#define CXWnd__SetFocus_x                                          0x92A260
#define CXWnd__SetFont_x                                           0x92A2D0
#define CXWnd__SetKeyTooltip_x                                     0x92AE30
#define CXWnd__SetMouseOver_x                                      0x927CA0
#define CXWnd__StartFade_x                                         0x9296C0
#define CXWnd__GetChildItem_x                                      0x92AB10
#define CXWnd__SetParent_x                                         0x9295B0
#define CXWnd__Minimize_x                                          0x929F30

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95D780

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x92D8A0
#define CXWndManager__DrawWindows_x                                0x92D8C0
#define CXWndManager__GetKeyboardFlags_x                           0x92FFB0
#define CXWndManager__HandleKeyboardMsg_x                          0x92FB60
#define CXWndManager__RemoveWnd_x                                  0x930200
#define CXWndManager__RemovePendingDeletionWnd_x                   0x930750

// CDBStr
#define CDBStr__GetString_x                                        0x536960

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB990
#define EQ_Character__Cur_HP_x                                     0x4D1F40
#define EQ_Character__Cur_Mana_x                                   0x4D9690
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEA00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2470
#define EQ_Character__GetFocusRangeModifier_x                      0x4B25C0
#define EQ_Character__GetHPRegen_x                                 0x4DF450
#define EQ_Character__GetEnduranceRegen_x                          0x4DFA50
#define EQ_Character__GetManaRegen_x                               0x4DFE90
#define EQ_Character__Max_Endurance_x                              0x640270
#define EQ_Character__Max_HP_x                                     0x4D1D70
#define EQ_Character__Max_Mana_x                                   0x640070
#define EQ_Character__doCombatAbility_x                            0x6426D0
#define EQ_Character__UseSkill_x                                   0x4E1C70
#define EQ_Character__GetConLevel_x                                0x639110
#define EQ_Character__IsExpansionFlag_x                            0x59D4E0
#define EQ_Character__TotalEffect_x                                0x4C5300
#define EQ_Character__GetPCSpellAffect_x                           0x4BF610
#define EQ_Character__SpellDuration_x                              0x4BF140
#define EQ_Character__GetAdjustedSkill_x                           0x4D4CC0
#define EQ_Character__GetBaseSkill_x                               0x4D5C60
#define EQ_Character__CanUseItem_x                                 0x4D99A0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C0AD0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6567E0

//PcClient
#define PcClient__PcClient_x                                       0x636850

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95D0
#define CCharacterListWnd__EnterWorld_x                            0x4B9010
#define CCharacterListWnd__Quit_x                                  0x4B8D60
#define CCharacterListWnd__UpdateList_x                            0x4B91A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x61B320
#define EQ_Item__CreateItemTagString_x                             0x89ACF0
#define EQ_Item__IsStackable_x                                     0x89F820
#define EQ_Item__GetImageNum_x                                     0x89C760
#define EQ_Item__CreateItemClient_x                                0x61A4F0
#define EQ_Item__GetItemValue_x                                    0x89DA80
#define EQ_Item__ValueSellMerchant_x                               0x8A1030
#define EQ_Item__IsKeyRingItem_x                                   0x89F150
#define EQ_Item__CanGoInBag_x                                      0x61B440
#define EQ_Item__IsEmpty_x                                         0x89EC90
#define EQ_Item__GetMaxItemCount_x                                 0x89DE90
#define EQ_Item__GetHeldItem_x                                     0x89C630
#define EQ_Item__GetAugmentFitBySlot_x                             0x89A680

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x554DB0
#define EQ_LoadingS__Array_x                                       0xC1AB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x640BD0
#define EQ_PC__GetAlternateAbilityId_x                             0x8AA320
#define EQ_PC__GetCombatAbility_x                                  0x8AA990
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AAA00
#define EQ_PC__GetItemRecastTimer_x                                0x642C50
#define EQ_PC__HasLoreItem_x                                       0x639920
#define EQ_PC__AlertInventoryChanged_x                             0x638A50
#define EQ_PC__GetPcZoneClient_x                                   0x665380
#define EQ_PC__RemoveMyAffect_x                                    0x645E80
#define EQ_PC__GetKeyRingItems_x                                   0x8AB290
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AB020
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AB590

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A3A30
#define EQItemList__add_object_x                                   0x5D0A40
#define EQItemList__add_item_x                                     0x5A3F90
#define EQItemList__delete_item_x                                  0x5A3FE0
#define EQItemList__FreeItemList_x                                 0x5A3EE0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5333F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x658060
#define EQPlayer__dEQPlayer_x                                      0x64B3B0
#define EQPlayer__DoAttack_x                                       0x660040
#define EQPlayer__EQPlayer_x                                       0x64BA70
#define EQPlayer__SetNameSpriteState_x                             0x64FD50
#define EQPlayer__SetNameSpriteTint_x                              0x650C10
#define PlayerBase__HasProperty_j_x                                0x98FFE0
#define EQPlayer__IsTargetable_x                                   0x990480
#define EQPlayer__CanSee_x                                         0x9902E0
#define EQPlayer__CanSee1_x                                        0x9903B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9900A0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x662E10
#define PlayerZoneClient__GetLevel_x                               0x6653C0
#define PlayerZoneClient__IsValidTeleport_x                        0x5D1BC0
#define PlayerZoneClient__LegalPlayerRace_x                        0x54E160

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x65AEA0
#define EQPlayerManager__GetSpawnByName_x                          0x65AF50
#define EQPlayerManager__GetPlayerFromPartialName_x                0x65AFE0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x61E960
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x61E9E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x61EA20
#define KeypressHandler__ClearCommandStateArray_x                  0x61FE30
#define KeypressHandler__HandleKeyDown_x                           0x61FE50
#define KeypressHandler__HandleKeyUp_x                             0x61FEF0
#define KeypressHandler__SaveKeymapping_x                          0x620340

// MapViewMap 
#define MapViewMap__Clear_x                                        0x777020
#define MapViewMap__SaveEx_x                                       0x77A3E0
#define MapViewMap__SetZoom_x                                      0x77EAA0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BE9F0

// StringTable 
#define StringTable__getString_x                                   0x8B9660

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x645AF0
#define PcZoneClient__RemovePetEffect_x                            0x646120
#define PcZoneClient__HasAlternateAbility_x                        0x63FEA0
#define PcZoneClient__GetCurrentMod_x                              0x4E4D20
#define PcZoneClient__GetModCap_x                                  0x4E4C20
#define PcZoneClient__CanEquipItem_x                               0x640570
#define PcZoneClient__GetItemByID_x                                0x6430C0
#define PcZoneClient__GetItemByItemClass_x                         0x643210
#define PcZoneClient__RemoveBuffEffect_x                           0x646140
#define PcZoneClient__BandolierSwap_x                              0x641190
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x642BF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5D6670

//IconCache
#define IconCache__GetIcon_x                                       0x717680

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70F140
#define CContainerMgr__CloseContainer_x                            0x70F410
#define CContainerMgr__OpenExperimentContainer_x                   0x70FE90

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CF1A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x613480

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76D5F0
#define CLootWnd__RequestLootSlot_x                                0x76C820

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x570CB0
#define EQ_Spell__SpellAffects_x                                   0x571120
#define EQ_Spell__SpellAffectBase_x                                0x570EE0
#define EQ_Spell__IsStackable_x                                    0x4C9960
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C97E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6960
#define EQ_Spell__IsSPAStacking_x                                  0x571F70
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x571480
#define EQ_Spell__IsNoRemove_x                                     0x4C9940
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x571F80
#define __IsResEffectSpell_x                                       0x4C8D40

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD080

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C9040

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x816060
#define CTargetWnd__WndNotification_x                              0x8158F0
#define CTargetWnd__RefreshTargetBuffs_x                           0x815BC0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814A50

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81A650

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x530E10
#define CTaskManager__HandleMessage_x                              0x52F2B0
#define CTaskManager__GetTaskStatus_x                              0x530EC0
#define CTaskManager__GetElementDescription_x                      0x530F40

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x56C220
#define EqSoundManager__PlayScriptMp3_x                            0x56C380
#define EqSoundManager__SoundAssistPlay_x                          0x67D420
#define EqSoundManager__WaveInstancePlay_x                         0x67C990

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x524B70

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x94BC40

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55C750
#define CAltAbilityData__GetMercMaxRank_x                          0x55C6E0
#define CAltAbilityData__GetMaxRank_x                              0x551F10

//CTargetRing
#define CTargetRing__Cast_x                                        0x6115A0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C97C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x50C400
#define CharacterBase__CreateItemIndex_x                           0x619680
#define CharacterBase__GetItemPossession_x                         0x4F7E10
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D1640
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D16A0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F6230
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6A60
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6B10

//messages
#define msg_spell_worn_off_x                                       0x5955B0
#define msg_new_text_x                                             0x58A340
#define __msgTokenTextParam_x                                      0x597AE0
#define msgTokenText_x                                             0x597D30

//SpellManager
#define SpellManager__vftable_x                                    0xAE0F34
#define SpellManager__SpellManager_x                               0x680750
#define Spellmanager__LoadTextSpells_x                             0x681040
#define SpellManager__GetSpellByGroupAndRank_x                     0x680920

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x994010

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50CA50
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x59B8A0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x631FF0
#define ItemGlobalIndex__IsValidIndex_x                            0x50CAB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C99E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C9C60

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x765E60

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x713850
#define CCursorAttachment__AttachToCursor1_x                       0x713890
#define CCursorAttachment__Deactivate_x                            0x714880

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x93E9B0
#define CSidlManagerBase__CreatePageWnd_x                          0x93E1A0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x93A430
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x93A3C0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x95BBA0
#define CEQSuiteTextureLoader__GetTexture_x                        0x95B860

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x509960
#define CFindItemWnd__WndNotification_x                            0x50A440
#define CFindItemWnd__Update_x                                     0x50AFB0
#define CFindItemWnd__PickupSelectedItem_x                         0x5091B0

//IString
#define IString__Append_x                                          0x4F9600

//Camera
#define CDisplay__cameraType_x                                     0xDF3FF0
#define EverQuest__Cameras_x                                       0xEB7A24

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x512180
#define LootFiltersManager__GetItemFilterData_x                    0x511A80
#define LootFiltersManager__RemoveItemLootFilter_x                 0x511AB0
#define LootFiltersManager__SetItemLootFilter_x                    0x511CD0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BD180

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x999C00
#define CResolutionHandler__GetWindowedStyle_x                     0x678080

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70BEA0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DD2A0
#define CDistillerInfo__Instance_x                                 0x8DD240

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72C160
#define CGroupWnd__UpdateDisplay_x                                 0x72B4C0

//ItemBase
#define ItemBase__IsLore_x                                         0x89F1F0
#define ItemBase__IsLoreEquipped_x                                 0x89F260

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D09A0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D0AE0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D0B40

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x66DB10
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x671460

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4FFDC0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4EE890
#define FactionManagerClient__HandleFactionMessage_x               0x4EEF00
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4EF4C0
#define FactionManagerClient__GetMaxFaction_x                      0x4EF4DF
#define FactionManagerClient__GetMinFaction_x                      0x4EF490

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F7DE0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x922F20

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C070

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F8010

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55BC10

//CTargetManager
#define CTargetManager__Get_x                                      0x683F60

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x66DB10

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E00

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A3E80

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF550B8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
