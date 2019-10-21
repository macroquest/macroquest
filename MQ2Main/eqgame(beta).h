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
#define __ExpectedVersionDate                                     "Oct 21 2019"
#define __ExpectedVersionTime                                     "04:44:10"
#define __ActualVersionDate_x                                      0xAFD950
#define __ActualVersionTime_x                                      0xAFD944
#define __ActualVersionBuild_x                                     0xAE963C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x624F40
#define __MemChecker1_x                                            0x8F6FF0
#define __MemChecker2_x                                            0x6B33E0
#define __MemChecker3_x                                            0x6B3330
#define __MemChecker4_x                                            0x84F2D0
#define __EncryptPad0_x                                            0xC333F0
#define __EncryptPad1_x                                            0xC915B0
#define __EncryptPad2_x                                            0xC43C88
#define __EncryptPad3_x                                            0xC43888
#define __EncryptPad4_x                                            0xC81C08
#define __EncryptPad5_x                                            0xF5ACA8
#define __AC1_x                                                    0x80BE76
#define __AC2_x                                                    0x5DED8F
#define __AC3_x                                                    0x5E648F
#define __AC4_x                                                    0x5EA450
#define __AC5_x                                                    0x5F075F
#define __AC6_x                                                    0x5F4D76
#define __AC7_x                                                    0x5DE800
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
#define __do_loot_x                                                0x5AB190
#define __DrawHandler_x                                            0x15ECEA8
#define __GroupCount_x                                             0xEA876A
#define __Guilds_x                                                 0xEACB80
#define __gWorld_x                                                 0xEA8620
#define __HWnd_x                                                   0xF5D1A4
#define __heqmain_x                                                0xF5D178
#define __InChatMode_x                                             0xEB635C
#define __LastTell_x                                               0xEB82D0
#define __LMouseHeldTime_x                                         0xEB6498
#define __Mouse_x                                                  0xF5D164
#define __MouseLook_x                                              0xEB63F2
#define __MouseEventTime_x                                         0xF55B94
#define __gpbCommandEvent_x                                        0xEA8974
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
#define __ServerHost_x                                             0xEA8C03
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
#define __gfMaxZoomCameraDistance_x                                0xAF32B0
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
#define pinstActiveBanker_x                                        0xEA898C
#define pinstActiveCorpse_x                                        0xEA8984
#define pinstActiveGMaster_x                                       0xEA8988
#define pinstActiveMerchant_x                                      0xEA8980
#define pinstAltAdvManager_x                                       0xDF5148
#define pinstBandageTarget_x                                       0xEA899C
#define pinstCamActor_x                                            0xDF3F38
#define pinstCDBStr_x                                              0xDF3E64
#define pinstCDisplay_x                                            0xEA861C
#define pinstCEverQuest_x                                          0xF5D19C
#define pinstEverQuestInfo_x                                       0xEB6308
#define pinstCharData_x                                            0xEA874C
#define pinstCharSpawn_x                                           0xEA8A54
#define pinstControlledMissile_x                                   0xEA8D0C
#define pinstControlledPlayer_x                                    0xEA8A54
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
#define pinstLocalPlayer_x                                         0xEA897C
#define pinstMercenaryData_x                                       0xF5768C
#define pinstMercenaryStats_x                                      0xF70634
#define pinstModelPlayer_x                                         0xEA8994
#define pinstPCData_x                                              0xEA874C
#define pinstSkillMgr_x                                            0xF597F0
#define pinstSpawnManager_x                                        0xF58298
#define pinstSpellManager_x                                        0xF59A10
#define pinstSpellSets_x                                           0xF4DCDC
#define pinstStringTable_x                                         0xEA8750
#define pinstSwitchManager_x                                       0xEA64B8
#define pinstTarget_x                                              0xEA8A50
#define pinstTargetObject_x                                        0xEA8A5C
#define pinstTargetSwitch_x                                        0xEA6614
#define pinstTaskMember_x                                          0xDF3C38
#define pinstTrackTarget_x                                         0xEA8A58
#define pinstTradeTarget_x                                         0xEA8990
#define instTributeActive_x                                        0xDF3DC9
#define pinstViewActor_x                                           0xDF3F34
#define pinstWorldData_x                                           0xEA6608
#define pinstZoneAddr_x                                            0xEB6888
#define pinstPlayerPath_x                                          0xF58330
#define pinstTargetIndicator_x                                     0xF59C78
#define EQObject_Top_x                                             0xEA8978
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDF41F8
#define pinstCAchievementsWnd_x                                    0xDF3F90
#define pinstCActionsWnd_x                                         0xDF3FBC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDF476C
#define pinstCAdvancedLootWnd_x                                    0xDF4338
#define pinstCAdventureLeaderboardWnd_x                            0xF67308
#define pinstCAdventureRequestWnd_x                                0xF673B8
#define pinstCAdventureStatsWnd_x                                  0xF67468
#define pinstCAggroMeterWnd_x                                      0xDF3F28
#define pinstCAlarmWnd_x                                           0xDF4278
#define pinstCAlertHistoryWnd_x                                    0xDF42CC
#define pinstCAlertStackWnd_x                                      0xDF4210
#define pinstCAlertWnd_x                                           0xDF4224
#define pinstCAltStorageWnd_x                                      0xF677C8
#define pinstCAudioTriggersWindow_x                                0xCA8B98
#define pinstCAuraWnd_x                                            0xDF4798
#define pinstCAvaZoneWnd_x                                         0xDF41FC
#define pinstCBandolierWnd_x                                       0xDF3F24
#define pinstCBankWnd_x                                            0xDF4794
#define pinstCBarterMerchantWnd_x                                  0xF68A08
#define pinstCBarterSearchWnd_x                                    0xF68AB8
#define pinstCBarterWnd_x                                          0xF68B68
#define pinstCBazaarConfirmationWnd_x                              0xDF3FC8
#define pinstCBazaarSearchWnd_x                                    0xDF3F84
#define pinstCBazaarWnd_x                                          0xDF4250
#define pinstCBlockedBuffWnd_x                                     0xDF3F00
#define pinstCBlockedPetBuffWnd_x                                  0xDF3F20
#define pinstCBodyTintWnd_x                                        0xDF3FD0
#define pinstCBookWnd_x                                            0xDF3F64
#define pinstCBreathWnd_x                                          0xDF421C
#define pinstCBuffWindowNORMAL_x                                   0xDF4784
#define pinstCBuffWindowSHORT_x                                    0xDF4788
#define pinstCBugReportWnd_x                                       0xDF4790
#define pinstCButtonWnd_x                                          0x15EC2D8
#define pinstCCastingWnd_x                                         0xDF3F54
#define pinstCCastSpellWnd_x                                       0xDF4214
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDF4258
#define pinstCChatWindowManager_x                                  0xF69628
#define pinstCClaimWnd_x                                           0xF69780
#define pinstCColorPickerWnd_x                                     0xDF3FC4
#define pinstCCombatAbilityWnd_x                                   0xDF4264
#define pinstCCombatSkillsSelectWnd_x                              0xDF42A4
#define pinstCCompassWnd_x                                         0xDF3FC0
#define pinstCConfirmationDialog_x                                 0xF6E680
#define pinstCContainerMgr_x                                       0xDF4248
#define pinstCContextMenuManager_x                                 0x15EC028
#define pinstCCursorAttachment_x                                   0xDF3F30
#define pinstCDynamicZoneWnd_x                                     0xF69D48
#define pinstCEditLabelWnd_x                                       0xDF4778
#define pinstCEQMainWnd_x                                          0xF69F90
#define pinstCEventCalendarWnd_x                                   0xDF4780
#define pinstCExtendedTargetWnd_x                                  0xDF3F14
#define pinstCFacePick_x                                           0xDF42B4
#define pinstCFactionWnd_x                                         0xDF4240
#define pinstCFellowshipWnd_x                                      0xF6A190
#define pinstCFileSelectionWnd_x                                   0xDF3F50
#define pinstCFindItemWnd_x                                        0xDF4230
#define pinstCFindLocationWnd_x                                    0xF6A2E8
#define pinstCFriendsWnd_x                                         0xDF4334
#define pinstCGemsGameWnd_x                                        0xDF423C
#define pinstCGiveWnd_x                                            0xDF427C
#define pinstCGroupSearchFiltersWnd_x                              0xDF3F5C
#define pinstCGroupSearchWnd_x                                     0xF6A6E0
#define pinstCGroupWnd_x                                           0xF6A790
#define pinstCGuildBankWnd_x                                       0xEB76CC
#define pinstCGuildCreationWnd_x                                   0xF6A8F0
#define pinstCGuildMgmtWnd_x                                       0xF6A9A0
#define pinstCharacterCreation_x                                   0xDF42AC
#define pinstCHelpWnd_x                                            0xDF4764
#define pinstCHeritageSelectionWnd_x                               0xDF4740
#define pinstCHotButtonWnd_x                                       0xF6CAF8
#define pinstCHotButtonWnd1_x                                      0xF6CAF8
#define pinstCHotButtonWnd2_x                                      0xF6CAFC
#define pinstCHotButtonWnd3_x                                      0xF6CB00
#define pinstCHotButtonWnd4_x                                      0xF6CB04
#define pinstCIconSelectionWnd_x                                   0xDF3F2C
#define pinstCInspectWnd_x                                         0xDF4760
#define pinstCInventoryWnd_x                                       0xDF4744
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
#define pinstCLoadskinWnd_x                                        0xDF424C
#define pinstCLootFiltersCopyWnd_x                                 0xCC5140
#define pinstCLootFiltersWnd_x                                     0xDF4218
#define pinstCLootSettingsWnd_x                                    0xDF422C
#define pinstCLootWnd_x                                            0xDF3F70
#define pinstCMailAddressBookWnd_x                                 0xDF4204
#define pinstCMailCompositionWnd_x                                 0xDF3FE4
#define pinstCMailIgnoreListWnd_x                                  0xDF4208
#define pinstCMailWnd_x                                            0xDF3FB8
#define pinstCManageLootWnd_x                                      0xDF55F8
#define pinstCMapToolbarWnd_x                                      0xDF4768
#define pinstCMapViewWnd_x                                         0xDF4750
#define pinstCMarketplaceWnd_x                                     0xDF4220
#define pinstCMerchantWnd_x                                        0xDF3F74
#define pinstCMIZoneSelectWnd_x                                    0xF6DDF0
#define pinstCMusicPlayerWnd_x                                     0xDF3F7C
#define pinstCNameChangeMercWnd_x                                  0xDF3FB4
#define pinstCNameChangePetWnd_x                                   0xDF3F94
#define pinstCNameChangeWnd_x                                      0xDF3FDC
#define pinstCNoteWnd_x                                            0xDF4754
#define pinstCObjectPreviewWnd_x                                   0xDF4228
#define pinstCOptionsWnd_x                                         0xDF4758
#define pinstCPetInfoWnd_x                                         0xDF3F98
#define pinstCPetitionQWnd_x                                       0xDF3F80
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDF3FD4
#define pinstCPlayerWnd_x                                          0xDF3F9C
#define pinstCPopupWndManager_x                                    0xF6E680
#define pinstCProgressionSelectionWnd_x                            0xF6E730
#define pinstCPurchaseGroupWnd_x                                   0xDF4294
#define pinstCPurchaseWnd_x                                        0xDF4244
#define pinstCPvPLeaderboardWnd_x                                  0xF6E7E0
#define pinstCPvPStatsWnd_x                                        0xF6E890
#define pinstCQuantityWnd_x                                        0xDF3F1C
#define pinstCRaceChangeWnd_x                                      0xDF4200
#define pinstCRaidOptionsWnd_x                                     0xDF3F60
#define pinstCRaidWnd_x                                            0xDF3FE8
#define pinstCRealEstateItemsWnd_x                                 0xDF3F88
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDF3F08
#define pinstCRealEstateManageWnd_x                                0xDF429C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDF42B8
#define pinstCRealEstatePlotSearchWnd_x                            0xDF4748
#define pinstCRealEstatePurchaseWnd_x                              0xDF475C
#define pinstCRespawnWnd_x                                         0xDF3F0C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDF420C
#define pinstCSendMoneyWnd_x                                       0xDF42A0
#define pinstCServerListWnd_x                                      0xDF477C
#define pinstCSkillsSelectWnd_x                                    0xDF425C
#define pinstCSkillsWnd_x                                          0xDF4234
#define pinstCSocialEditWnd_x                                      0xDF4770
#define pinstCSocialWnd_x                                          0xDF3FAC
#define pinstCSpellBookWnd_x                                       0xDF4260
#define pinstCStoryWnd_x                                           0xDF3FA0
#define pinstCTargetOfTargetWnd_x                                  0xF706B8
#define pinstCTargetWnd_x                                          0xDF3F04
#define pinstCTaskOverlayWnd_x                                     0xDF4290
#define pinstCTaskSelectWnd_x                                      0xF70810
#define pinstCTaskManager_x                                        0xCC5A80
#define pinstCTaskTemplateSelectWnd_x                              0xF708C0
#define pinstCTaskWnd_x                                            0xF70970
#define pinstCTextEntryWnd_x                                       0xDF478C
#define pinstCTimeLeftWnd_x                                        0xDF3F58
#define pinstCTipWndCONTEXT_x                                      0xF70B74
#define pinstCTipWndOFDAY_x                                        0xF70B70
#define pinstCTitleWnd_x                                           0xF70C20
#define pinstCTrackingWnd_x                                        0xDF474C
#define pinstCTradeskillWnd_x                                      0xF70D88
#define pinstCTradeWnd_x                                           0xDF3FE0
#define pinstCTrainWnd_x                                           0xDF3FD8
#define pinstCTributeBenefitWnd_x                                  0xF70F88
#define pinstCTributeMasterWnd_x                                   0xF71038
#define pinstCTributeTrophyWnd_x                                   0xF710E8
#define pinstCVideoModesWnd_x                                      0xDF3FEC
#define pinstCVoiceMacroWnd_x                                      0xF5A3E0
#define pinstCVoteResultsWnd_x                                     0xDF3F78
#define pinstCVoteWnd_x                                            0xDF3F68
#define pinstCWebManager_x                                         0xF5AA5C
#define pinstCZoneGuideWnd_x                                       0xDF4298
#define pinstCZonePathWnd_x                                        0xDF42A8

#define pinstEQSuiteTextureLoader_x                                0xC93088
#define pinstItemIconCache_x                                       0xF69F48
#define pinstLootFiltersManager_x                                  0xCC51F0
#define pinstRewardSelectionWnd_x                                  0xF6EFD8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5A65F0
#define __CastRay2_x                                               0x5A6640
#define __ConvertItemTags_x                                        0x5C2180
#define __CleanItemTags_x                                          0x47D240
#define __DoesFileExist_x                                          0x8FA0D0
#define __EQGetTime_x                                              0x8F6AC0
#define __ExecuteCmd_x                                             0x59EE90
#define __FixHeading_x                                             0x991EF0
#define __GameLoop_x                                               0x6B25D0
#define __get_bearing_x                                            0x5A6160
#define __get_melee_range_x                                        0x5A6830
#define __GetAnimationCache_x                                      0x717980
#define __GetGaugeValueFromEQ_x                                    0x80A320
#define __GetLabelFromEQ_x                                         0x80BE00
#define __GetXTargetType_x                                         0x9939B0
#define __HandleMouseWheel_x                                       0x6B3490
#define __HeadingDiff_x                                            0x991F60
#define __HelpPath_x                                               0xF55784
#define __LoadFrontEnd_x                                           0x6AF8F0
#define __NewUIINI_x                                               0x809FF0
#define __ProcessGameEvents_x                                      0x6065D0
#define __ProcessMouseEvent_x                                      0x605D90
#define __SaveColors_x                                             0x54CAC0
#define __STMLToText_x                                             0x935470
#define __ToggleKeyRingItem_x                                      0x50FDA0
#define CMemoryMappedFile__SetFile_x                               0xA81370
#define CrashDetected_x                                            0x6B1390
#define DrawNetStatus_x                                            0x6322F0
#define Expansion_HoT_x                                            0xEB76D4
#define Teleport_Table_Size_x                                      0xEA8ABC
#define Teleport_Table_x                                           0xEA6618
#define Util__FastTime_x                                           0x8F6690

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490500
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499410
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4991E0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493AA0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492EF0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x554600
#define AltAdvManager__IsAbilityReady_x                            0x553570
#define AltAdvManager__GetAAById_x                                 0x553770
#define AltAdvManager__CanTrainAbility_x                           0x5537E0
#define AltAdvManager__CanSeeAbility_x                             0x553B40

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA010
#define CharacterZoneClient__HasSkill_x                            0x4D4F00
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6620
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE430
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAA30
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8FC0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D90A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9180
#define CharacterZoneClient__FindAffectSlot_x                      0x4C30E0
#define CharacterZoneClient__BardCastBard_x                        0x4C5C40
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB00
#define CharacterZoneClient__GetEffect_x                           0x4BA970
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4130
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4200
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4250
#define CharacterZoneClient__CalcAffectChange_x                    0x4C43A0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4570
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2900
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7580
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7000

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D90F0
#define CBankWnd__WndNotification_x                                0x6D8ED0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6A80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x614DF0
#define CButtonWnd__CButtonWnd_x                                   0x931830

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706A60
#define CChatManager__InitContextMenu_x                            0x6FFBC0
#define CChatManager__FreeChatWindow_x                             0x7055A0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8530
#define CChatManager__SetLockedActiveChatWindow_x                  0x7066E0
#define CChatManager__CreateChatWindow_x                           0x705BE0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8640

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x945E40
#define CContextMenu__dCContextMenu_x                              0x946070
#define CContextMenu__AddMenuItem_x                                0x946080
#define CContextMenu__RemoveMenuItem_x                             0x946390
#define CContextMenu__RemoveAllMenuItems_x                         0x9463B0
#define CContextMenu__CheckMenuItem_x                              0x946430
#define CContextMenu__SetMenuItem_x                                0x9462B0
#define CContextMenu__AddSeparator_x                               0x946210

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9469D0
#define CContextMenuManager__RemoveMenu_x                          0x946A40
#define CContextMenuManager__PopupMenu_x                           0x946B00
#define CContextMenuManager__Flush_x                               0x946970
#define CContextMenuManager__GetMenu_x                             0x49B4D0
#define CContextMenuManager__CreateDefaultMenu_x                   0x712150

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D3A90
#define CChatService__GetFriendName_x                              0x8D3AA0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x707360
#define CChatWindow__Clear_x                                       0x708620
#define CChatWindow__WndNotification_x                             0x708DB0
#define CChatWindow__AddHistory_x                                  0x707EE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9432A0
#define CComboWnd__Draw_x                                          0x942790
#define CComboWnd__GetCurChoice_x                                  0x9430E0
#define CComboWnd__GetListRect_x                                   0x942C50
#define CComboWnd__GetTextRect_x                                   0x943310
#define CComboWnd__InsertChoice_x                                  0x942DE0
#define CComboWnd__SetColors_x                                     0x942DB0
#define CComboWnd__SetChoice_x                                     0x9430B0
#define CComboWnd__GetItemCount_x                                  0x9430F0
#define CComboWnd__GetCurChoiceText_x                              0x943130
#define CComboWnd__GetChoiceText_x                                 0x943100
#define CComboWnd__InsertChoiceAtIndex_x                           0x942E70

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70FB40
#define CContainerWnd__vftable_x                                   0xB06B4C
#define CContainerWnd__SetContainer_x                              0x7110A0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x547500
#define CDisplay__PreZoneMainUI_x                                  0x547510
#define CDisplay__CleanGameUI_x                                    0x54C880
#define CDisplay__GetClickedActor_x                                0x53F820
#define CDisplay__GetUserDefinedColor_x                            0x537EE0
#define CDisplay__GetWorldFilePath_x                               0x541290
#define CDisplay__is3dON_x                                         0x53C480
#define CDisplay__ReloadUI_x                                       0x546990
#define CDisplay__WriteTextHD2_x                                   0x53C270
#define CDisplay__TrueDistance_x                                   0x542F50
#define CDisplay__SetViewActor_x                                   0x53F140
#define CDisplay__GetFloorHeight_x                                 0x53C540
#define CDisplay__SetRenderWindow_x                                0x53AEA0
#define CDisplay__ToggleScreenshotMode_x                           0x53EC10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x965B60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x949390
#define CEditWnd__GetCharIndexPt_x                                 0x94A2C0
#define CEditWnd__GetDisplayString_x                               0x94A160
#define CEditWnd__GetHorzOffset_x                                  0x9489C0
#define CEditWnd__GetLineForPrintableChar_x                        0x94B460
#define CEditWnd__GetSelStartPt_x                                  0x94A570
#define CEditWnd__GetSTMLSafeText_x                                0x949F80
#define CEditWnd__PointFromPrintableChar_x                         0x94B090
#define CEditWnd__SelectableCharFromPoint_x                        0x94B200
#define CEditWnd__SetEditable_x                                    0x94A640
#define CEditWnd__SetWindowTextA_x                                 0x949D00

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5F4250
#define CEverQuest__ClickedPlayer_x                                0x5E6270
#define CEverQuest__CreateTargetIndicator_x                        0x603860
#define CEverQuest__DeleteTargetIndicator_x                        0x6038F0
#define CEverQuest__DoTellWindow_x                                 0x4E8720
#define CEverQuest__OutputTextToLog_x                              0x4E89A0
#define CEverQuest__DropHeldItemOnGround_x                         0x5DB2B0
#define CEverQuest__dsp_chat_x                                     0x4E8D30
#define CEverQuest__trimName_x                                     0x5FFB50
#define CEverQuest__Emote_x                                        0x5F4AB0
#define CEverQuest__EnterZone_x                                    0x5EEA30
#define CEverQuest__GetBodyTypeDesc_x                              0x5F9420
#define CEverQuest__GetClassDesc_x                                 0x5F9A60
#define CEverQuest__GetClassThreeLetterCode_x                      0x5FA060
#define CEverQuest__GetDeityDesc_x                                 0x6021A0
#define CEverQuest__GetLangDesc_x                                  0x5FA220
#define CEverQuest__GetRaceDesc_x                                  0x5F9A40
#define CEverQuest__InterpretCmd_x                                 0x602770
#define CEverQuest__LeftClickedOnPlayer_x                          0x5DF4B0
#define CEverQuest__LMouseUp_x                                     0x5DD840
#define CEverQuest__RightClickedOnPlayer_x                         0x5DFD90
#define CEverQuest__RMouseUp_x                                     0x5DE7C0
#define CEverQuest__SetGameState_x                                 0x5DB040
#define CEverQuest__UPCNotificationFlush_x                         0x5FFA50
#define CEverQuest__IssuePetCommand_x                              0x5FB620
#define CEverQuest__ReportSuccessfulHit_x                          0x5F5EA0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x721B00
#define CGaugeWnd__CalcLinesFillRect_x                             0x721B60
#define CGaugeWnd__Draw_x                                          0x721180

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF350
#define CGuild__GetGuildName_x                                     0x4AE430
#define CGuild__GetGuildIndex_x                                    0x4AE7C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73CF30

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6151B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x749F30
#define CInvSlotMgr__MoveItem_x                                    0x748C50
#define CInvSlotMgr__SelectSlot_x                                  0x74A000

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7474D0
#define CInvSlot__SliderComplete_x                                 0x745230
#define CInvSlot__GetItemBase_x                                    0x744BC0
#define CInvSlot__UpdateItem_x                                     0x744D30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74BA60
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74AC20
#define CInvSlotWnd__HandleLButtonUp_x                             0x74B5E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x805660
#define CItemDisplayWnd__UpdateStrings_x                           0x75A1B0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x753E90
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7543C0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75A7C0
#define CItemDisplayWnd__AboutToShow_x                             0x759DF0
#define CItemDisplayWnd__WndNotification_x                         0x75B8B0
#define CItemDisplayWnd__RequestConvertItem_x                      0x75B370
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x758E50
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x759C10

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x83E230

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75FDF0

// CLabel 
#define CLabel__Draw_x                                             0x765830

// CListWnd
#define CListWnd__CListWnd_x                                       0x91B910
#define CListWnd__dCListWnd_x                                      0x91BC30
#define CListWnd__AddColumn_x                                      0x9200B0
#define CListWnd__AddColumn1_x                                     0x920100
#define CListWnd__AddLine_x                                        0x920490
#define CListWnd__AddString_x                                      0x920290
#define CListWnd__CalculateFirstVisibleLine_x                      0x91FE70
#define CListWnd__CalculateVSBRange_x                              0x91FC60
#define CListWnd__ClearSel_x                                       0x920C70
#define CListWnd__ClearAllSel_x                                    0x920CD0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9216F0
#define CListWnd__Compare_x                                        0x91F590
#define CListWnd__Draw_x                                           0x91BD60
#define CListWnd__DrawColumnSeparators_x                           0x91E560
#define CListWnd__DrawHeader_x                                     0x91E9D0
#define CListWnd__DrawItem_x                                       0x91EED0
#define CListWnd__DrawLine_x                                       0x91E6D0
#define CListWnd__DrawSeparator_x                                  0x91E600
#define CListWnd__EnableLine_x                                     0x91DE30
#define CListWnd__EnsureVisible_x                                  0x921610
#define CListWnd__ExtendSel_x                                      0x920BA0
#define CListWnd__GetColumnTooltip_x                               0x91D970
#define CListWnd__GetColumnMinWidth_x                              0x91D9E0
#define CListWnd__GetColumnWidth_x                                 0x91D8E0
#define CListWnd__GetCurSel_x                                      0x91D270
#define CListWnd__GetItemAtPoint_x                                 0x91E0B0
#define CListWnd__GetItemAtPoint1_x                                0x91E120
#define CListWnd__GetItemData_x                                    0x91D2F0
#define CListWnd__GetItemHeight_x                                  0x91D6B0
#define CListWnd__GetItemIcon_x                                    0x91D480
#define CListWnd__GetItemRect_x                                    0x91DF20
#define CListWnd__GetItemText_x                                    0x91D330
#define CListWnd__GetSelList_x                                     0x920D20
#define CListWnd__GetSeparatorRect_x                               0x91E360
#define CListWnd__InsertLine_x                                     0x920880
#define CListWnd__RemoveLine_x                                     0x9209D0
#define CListWnd__SetColors_x                                      0x91FC30
#define CListWnd__SetColumnJustification_x                         0x91F960
#define CListWnd__SetColumnWidth_x                                 0x91F880
#define CListWnd__SetCurSel_x                                      0x920AE0
#define CListWnd__SetItemColor_x                                   0x9212C0
#define CListWnd__SetItemData_x                                    0x921280
#define CListWnd__SetItemText_x                                    0x920E90
#define CListWnd__ShiftColumnSeparator_x                           0x91FA20
#define CListWnd__Sort_x                                           0x91F710
#define CListWnd__ToggleSel_x                                      0x920B10
#define CListWnd__SetColumnsSizable_x                              0x91FAD0
#define CListWnd__SetItemWnd_x                                     0x921140
#define CListWnd__GetItemWnd_x                                     0x91D4D0
#define CListWnd__SetItemIcon_x                                    0x920F10
#define CListWnd__CalculateCustomWindowPositions_x                 0x91FF70
#define CListWnd__SetVScrollPos_x                                  0x91F860

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77AFA0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7796B0
#define CMapViewWnd__HandleLButtonDown_x                           0x7766F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79B090
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79B970
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79BEA0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79EE20
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x799C10
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A49D0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79ACB0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A13C0
#define CPacketScrambler__hton_x                                   0x8A13B0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x93AAB0
#define CSidlManager__FindScreenPieceTemplate_x                    0x93AEC0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x93ACB0
#define CSidlManager__CreateLabel_x                                0x7FCA60
#define CSidlManager__CreateXWndFromTemplate_x                     0x93DE20
#define CSidlManager__CreateXWndFromTemplate1_x                    0x93DFF0
#define CSidlManager__CreateXWnd_x                                 0x7FC990
#define CSidlManager__CreateHotButtonWnd_x                         0x7FCF30

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x937580
#define CSidlScreenWnd__CalculateVSBRange_x                        0x937480
#define CSidlScreenWnd__ConvertToRes_x                             0x95CB60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x936F20
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x936C10
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x936CE0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x936DB0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x937A20
#define CSidlScreenWnd__EnableIniStorage_x                         0x937EF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x937C10
#define CSidlScreenWnd__Init1_x                                    0x936810
#define CSidlScreenWnd__LoadIniInfo_x                              0x937F40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x938A90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x935C20
#define CSidlScreenWnd__StoreIniInfo_x                             0x938610
#define CSidlScreenWnd__StoreIniVis_x                              0x938970
#define CSidlScreenWnd__WndNotification_x                          0x937930
#define CSidlScreenWnd__GetChildItem_x                             0x937E70
#define CSidlScreenWnd__HandleLButtonUp_x                          0x927540
#define CSidlScreenWnd__m_layoutCopy_x                             0x15EBEF8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x679930
#define CSkillMgr__GetSkillCap_x                                   0x679B10
#define CSkillMgr__GetNameToken_x                                  0x6790B0
#define CSkillMgr__IsActivatedSkill_x                              0x6791F0
#define CSkillMgr__IsCombatSkill_x                                 0x679130

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9477A0
#define CSliderWnd__SetValue_x                                     0x947610
#define CSliderWnd__SetNumTicks_x                                  0x947670

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x802AF0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94FFA0
#define CStmlWnd__CalculateHSBRange_x                              0x951080
#define CStmlWnd__CalculateVSBRange_x                              0x950FF0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9553B0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x956040
#define CStmlWnd__ForceParseNow_x                                  0x950540
#define CStmlWnd__GetNextTagPiece_x                                0x955310
#define CStmlWnd__GetSTMLText_x                                    0x4FF770
#define CStmlWnd__GetVisibleText_x                                 0x950560
#define CStmlWnd__InitializeWindowVariables_x                      0x955E90
#define CStmlWnd__MakeStmlColorTag_x                               0x94F610
#define CStmlWnd__MakeWndNotificationTag_x                         0x94F680
#define CStmlWnd__SetSTMLText_x                                    0x94E6C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x957140
#define CStmlWnd__UpdateHistoryString_x                            0x956250

// CTabWnd 
#define CTabWnd__Draw_x                                            0x94D810
#define CTabWnd__DrawCurrentPage_x                                 0x94DF40
#define CTabWnd__DrawTab_x                                         0x94DC60
#define CTabWnd__GetCurrentPage_x                                  0x94D020
#define CTabWnd__GetPageInnerRect_x                                0x94D260
#define CTabWnd__GetTabInnerRect_x                                 0x94D1A0
#define CTabWnd__GetTabRect_x                                      0x94D050
#define CTabWnd__InsertPage_x                                      0x94D470
#define CTabWnd__SetPage_x                                         0x94D2E0
#define CTabWnd__SetPageRect_x                                     0x94D750
#define CTabWnd__UpdatePage_x                                      0x94DB20
#define CTabWnd__GetPageFromTabIndex_x                             0x94DBA0
#define CTabWnd__GetCurrentTabIndex_x                              0x94D010

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7601C0
#define CPageWnd__SetTabText_x                                     0x94CB70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8FF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9243E0
#define CTextureFont__GetTextExtent_x                              0x9245A0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC7A0
#define CHtmlComponentWnd__ValidateUri_x                           0x73E920
#define CHtmlWnd__SetClientCallbacks_x                             0x61A200
#define CHtmlWnd__AddObserver_x                                    0x61A220
#define CHtmlWnd__RemoveObserver_x                                 0x61A280
#define Window__getProgress_x                                      0x856880
#define Window__getStatus_x                                        0x8568A0
#define Window__getURI_x                                           0x8568B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9625B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x911380

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8370
#define CXStr__CXStr1_x                                            0x481730
#define CXStr__CXStr3_x                                            0x8F2BB0
#define CXStr__dCXStr_x                                            0x478820
#define CXStr__operator_equal_x                                    0x8F2DE0
#define CXStr__operator_equal1_x                                   0x8F2E20
#define CXStr__operator_plus_equal1_x                              0x8F38B0
#define CXStr__SetString_x                                         0x8F57B0
#define CXStr__operator_char_p_x                                   0x8F32F0
#define CXStr__GetChar_x                                           0x8F50E0
#define CXStr__Delete_x                                            0x8F49A0
#define CXStr__GetUnicode_x                                        0x8F5150
#define CXStr__GetLength_x                                         0x47D5F0
#define CXStr__Mid_x                                               0x47D600
#define CXStr__Insert_x                                            0x8F51B0
#define CXStr__FindNext_x                                          0x8F4E10

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x945A50
#define CXWnd__BringToTop_x                                        0x92ACE0
#define CXWnd__Center_x                                            0x92A860
#define CXWnd__ClrFocus_x                                          0x92A670
#define CXWnd__Destroy_x                                           0x92A720
#define CXWnd__DoAllDrawing_x                                      0x926CE0
#define CXWnd__DrawChildren_x                                      0x926CB0
#define CXWnd__DrawColoredRect_x                                   0x927130
#define CXWnd__DrawTooltip_x                                       0x925810
#define CXWnd__DrawTooltipAtPoint_x                                0x9258D0
#define CXWnd__GetBorderFrame_x                                    0x926F90
#define CXWnd__GetChildWndAt_x                                     0x92AD80
#define CXWnd__GetClientClipRect_x                                 0x928F70
#define CXWnd__GetScreenClipRect_x                                 0x929020
#define CXWnd__GetScreenRect_x                                     0x9291D0
#define CXWnd__GetTooltipRect_x                                    0x927180
#define CXWnd__GetWindowTextA_x                                    0x49CBB0
#define CXWnd__IsActive_x                                          0x9278B0
#define CXWnd__IsDescendantOf_x                                    0x929BA0
#define CXWnd__IsReallyVisible_x                                   0x929BD0
#define CXWnd__IsType_x                                            0x92B3E0
#define CXWnd__Move_x                                              0x929C40
#define CXWnd__Move1_x                                             0x929CF0
#define CXWnd__ProcessTransition_x                                 0x92A810
#define CXWnd__Refade_x                                            0x929FC0
#define CXWnd__Resize_x                                            0x92A290
#define CXWnd__Right_x                                             0x92AAA0
#define CXWnd__SetFocus_x                                          0x92A630
#define CXWnd__SetFont_x                                           0x92A6A0
#define CXWnd__SetKeyTooltip_x                                     0x92B210
#define CXWnd__SetMouseOver_x                                      0x928120
#define CXWnd__StartFade_x                                         0x929A80
#define CXWnd__GetChildItem_x                                      0x92AEF0
#define CXWnd__SetParent_x                                         0x929970
#define CXWnd__Minimize_x                                          0x92A300

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95DBE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x92DCC0
#define CXWndManager__DrawWindows_x                                0x92DCE0
#define CXWndManager__GetKeyboardFlags_x                           0x9304C0
#define CXWndManager__HandleKeyboardMsg_x                          0x930080
#define CXWndManager__RemoveWnd_x                                  0x930710
#define CXWndManager__RemovePendingDeletionWnd_x                   0x930C60

// CDBStr
#define CDBStr__GetString_x                                        0x536E80

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBA10
#define EQ_Character__Cur_HP_x                                     0x4D1F40
#define EQ_Character__Cur_Mana_x                                   0x4D9680
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEA80
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2540
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2690
#define EQ_Character__GetHPRegen_x                                 0x4DF450
#define EQ_Character__GetEnduranceRegen_x                          0x4DFA50
#define EQ_Character__GetManaRegen_x                               0x4DFE90
#define EQ_Character__Max_Endurance_x                              0x640070
#define EQ_Character__Max_HP_x                                     0x4D1D70
#define EQ_Character__Max_Mana_x                                   0x63FE70
#define EQ_Character__doCombatAbility_x                            0x6424C0
#define EQ_Character__UseSkill_x                                   0x4E1C60
#define EQ_Character__GetConLevel_x                                0x639240
#define EQ_Character__IsExpansionFlag_x                            0x59D630
#define EQ_Character__TotalEffect_x                                0x4C5380
#define EQ_Character__GetPCSpellAffect_x                           0x4BF690
#define EQ_Character__SpellDuration_x                              0x4BF1C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4CC0
#define EQ_Character__GetBaseSkill_x                               0x4D5C60
#define EQ_Character__CanUseItem_x                                 0x4D9990

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C08E0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6569A0

//PcClient
#define PcClient__PcClient_x                                       0x636970

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B96A0
#define CCharacterListWnd__EnterWorld_x                            0x4B90E0
#define CCharacterListWnd__Quit_x                                  0x4B8E30
#define CCharacterListWnd__UpdateList_x                            0x4B9270

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x61B440
#define EQ_Item__CreateItemTagString_x                             0x89AC20
#define EQ_Item__IsStackable_x                                     0x89F7B0
#define EQ_Item__GetImageNum_x                                     0x89C6A0
#define EQ_Item__CreateItemClient_x                                0x61A620
#define EQ_Item__GetItemValue_x                                    0x89D9D0
#define EQ_Item__ValueSellMerchant_x                               0x8A0FA0
#define EQ_Item__IsKeyRingItem_x                                   0x89F0E0
#define EQ_Item__CanGoInBag_x                                      0x61B560
#define EQ_Item__IsEmpty_x                                         0x89EC20
#define EQ_Item__GetMaxItemCount_x                                 0x89DDE0
#define EQ_Item__GetHeldItem_x                                     0x89C570
#define EQ_Item__GetAugmentFitBySlot_x                             0x89A5A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x555310
#define EQ_LoadingS__Array_x                                       0xC1AB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6409D0
#define EQ_PC__GetAlternateAbilityId_x                             0x8AA170
#define EQ_PC__GetCombatAbility_x                                  0x8AA7E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AA850
#define EQ_PC__GetItemRecastTimer_x                                0x642A40
#define EQ_PC__HasLoreItem_x                                       0x639A50
#define EQ_PC__AlertInventoryChanged_x                             0x638B70
#define EQ_PC__GetPcZoneClient_x                                   0x665490
#define EQ_PC__RemoveMyAffect_x                                    0x645C70
#define EQ_PC__GetKeyRingItems_x                                   0x8AB0E0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AAE70
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AB3E0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A3BE0
#define EQItemList__add_object_x                                   0x5D0B20
#define EQItemList__add_item_x                                     0x5A4140
#define EQItemList__delete_item_x                                  0x5A4190
#define EQItemList__FreeItemList_x                                 0x5A4090

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x533970

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x658220
#define EQPlayer__dEQPlayer_x                                      0x64B130
#define EQPlayer__DoAttack_x                                       0x660160
#define EQPlayer__EQPlayer_x                                       0x64B7F0
#define EQPlayer__SetNameSpriteState_x                             0x64FF00
#define EQPlayer__SetNameSpriteTint_x                              0x650DD0
#define PlayerBase__HasProperty_j_x                                0x9902C0
#define EQPlayer__IsTargetable_x                                   0x990760
#define EQPlayer__CanSee_x                                         0x9905C0
#define EQPlayer__CanSee1_x                                        0x990690
#define PlayerBase__GetVisibilityLineSegment_x                     0x990380

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x662F30
#define PlayerZoneClient__GetLevel_x                               0x6654D0
#define PlayerZoneClient__IsValidTeleport_x                        0x5D1C90
#define PlayerZoneClient__LegalPlayerRace_x                        0x54E740

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x65B050
#define EQPlayerManager__GetSpawnByName_x                          0x65B100
#define EQPlayerManager__GetPlayerFromPartialName_x                0x65B190

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x61EA70
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x61EAF0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x61EB30
#define KeypressHandler__ClearCommandStateArray_x                  0x61FF40
#define KeypressHandler__HandleKeyDown_x                           0x61FF60
#define KeypressHandler__HandleKeyUp_x                             0x620000
#define KeypressHandler__SaveKeymapping_x                          0x620450

// MapViewMap 
#define MapViewMap__Clear_x                                        0x776E10
#define MapViewMap__SaveEx_x                                       0x77A1D0
#define MapViewMap__SetZoom_x                                      0x77E880

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BE800

// StringTable 
#define StringTable__getString_x                                   0x8B9410

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6458E0
#define PcZoneClient__RemovePetEffect_x                            0x645F10
#define PcZoneClient__HasAlternateAbility_x                        0x63FCA0
#define PcZoneClient__GetCurrentMod_x                              0x4E4D20
#define PcZoneClient__GetModCap_x                                  0x4E4C20
#define PcZoneClient__CanEquipItem_x                               0x640370
#define PcZoneClient__GetItemByID_x                                0x642EB0
#define PcZoneClient__GetItemByItemClass_x                         0x643000
#define PcZoneClient__RemoveBuffEffect_x                           0x645F30
#define PcZoneClient__BandolierSwap_x                              0x640F80
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6429E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5D6730

//IconCache
#define IconCache__GetIcon_x                                       0x717220

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70ECE0
#define CContainerMgr__CloseContainer_x                            0x70EFB0
#define CContainerMgr__OpenExperimentContainer_x                   0x70FA30

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CEE30

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6135C0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76D320
#define CLootWnd__RequestLootSlot_x                                0x76C550

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x571150
#define EQ_Spell__SpellAffects_x                                   0x5715C0
#define EQ_Spell__SpellAffectBase_x                                0x571380
#define EQ_Spell__IsStackable_x                                    0x4C9950
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9800
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B69F0
#define EQ_Spell__IsSPAStacking_x                                  0x572410
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x571920
#define EQ_Spell__IsNoRemove_x                                     0x4C9930
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x572420
#define __IsResEffectSpell_x                                       0x4C8D20

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD080

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C8F70

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x815DC0
#define CTargetWnd__WndNotification_x                              0x815650
#define CTargetWnd__RefreshTargetBuffs_x                           0x815920
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8147C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81A3C0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x531380
#define CTaskManager__HandleMessage_x                              0x52F800
#define CTaskManager__GetTaskStatus_x                              0x531430
#define CTaskManager__GetElementDescription_x                      0x5314B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x56C6C0
#define EqSoundManager__PlayScriptMp3_x                            0x56C820
#define EqSoundManager__SoundAssistPlay_x                          0x67D890
#define EqSoundManager__WaveInstancePlay_x                         0x67CE00

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5250E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x94C080

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55CD70
#define CAltAbilityData__GetMercMaxRank_x                          0x55CD00
#define CAltAbilityData__GetMaxRank_x                              0x552430

//CTargetRing
#define CTargetRing__Cast_x                                        0x6116E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C97E0
#define CharacterBase__CreateItemGlobalIndex_x                     0x50C420
#define CharacterBase__CreateItemIndex_x                           0x6197C0
#define CharacterBase__GetItemPossession_x                         0x4F8130
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D1560
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D15C0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5E70
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F66A0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6750

//messages
#define msg_spell_worn_off_x                                       0x595800
#define msg_new_text_x                                             0x58A590
#define __msgTokenTextParam_x                                      0x597D30
#define msgTokenText_x                                             0x597F80

//SpellManager
#define SpellManager__vftable_x                                    0xAE0F2C
#define SpellManager__SpellManager_x                               0x680BC0
#define Spellmanager__LoadTextSpells_x                             0x6814B0
#define SpellManager__GetSpellByGroupAndRank_x                     0x680D90

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9942A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50CAA0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x59BAF0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x632150
#define ItemGlobalIndex__IsValidIndex_x                            0x50CB00

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C9910
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C9B90

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x765B70

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7133F0
#define CCursorAttachment__AttachToCursor1_x                       0x713430
#define CCursorAttachment__Deactivate_x                            0x714420

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x93EE00
#define CSidlManagerBase__CreatePageWnd_x                          0x93E620
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x93A8D0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x93A860

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x95BE10
#define CEQSuiteTextureLoader__GetTexture_x                        0x95BAD0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5099C0
#define CFindItemWnd__WndNotification_x                            0x50A4A0
#define CFindItemWnd__Update_x                                     0x50AFE0
#define CFindItemWnd__PickupSelectedItem_x                         0x509200

//IString
#define IString__Append_x                                          0x4F9920

//Camera
#define CDisplay__cameraType_x                                     0xDF3FF0
#define EverQuest__Cameras_x                                       0xEB7A24

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5120E0
#define LootFiltersManager__GetItemFilterData_x                    0x5119F0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x511A20
#define LootFiltersManager__SetItemLootFilter_x                    0x511C40

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BCE30

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x999E30
#define CResolutionHandler__GetWindowedStyle_x                     0x6784B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70BAB0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DD220
#define CDistillerInfo__Instance_x                                 0x8DD1C0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72BD10
#define CGroupWnd__UpdateDisplay_x                                 0x72B070

//ItemBase
#define ItemBase__IsLore_x                                         0x89F180
#define ItemBase__IsLoreEquipped_x                                 0x89F1F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D0A80
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D0BC0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D0C20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x66DBE0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x671570

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4FFD70

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4EE8F0
#define FactionManagerClient__HandleFactionMessage_x               0x4EEF60
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4EF560
#define FactionManagerClient__GetMaxFaction_x                      0x4EF57F
#define FactionManagerClient__GetMinFaction_x                      0x4EF530

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F8100

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x923360

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BEC0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F8330

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55C240

//CTargetManager
#define CTargetManager__Get_x                                      0x684410

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x66DBE0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8DB0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A4030

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF550B8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
