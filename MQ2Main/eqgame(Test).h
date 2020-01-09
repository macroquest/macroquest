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
#define __ExpectedVersionDate                                     "Jan  6 2020"
#define __ExpectedVersionTime                                     "12:02:05"
#define __ActualVersionDate_x                                      0xB0C530
#define __ActualVersionTime_x                                      0xB0C524
#define __ActualVersionBuild_x                                     0xAF8224

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x6310B0
#define __MemChecker1_x                                            0x904210
#define __MemChecker2_x                                            0x6BFE80
#define __MemChecker3_x                                            0x6BFDD0
#define __MemChecker4_x                                            0x85AB60
#define __EncryptPad0_x                                            0xC433E8
#define __EncryptPad1_x                                            0xCA1650
#define __EncryptPad2_x                                            0xC53C80
#define __EncryptPad3_x                                            0xC53880
#define __EncryptPad4_x                                            0xC91C00
#define __EncryptPad5_x                                            0xF6DE10
#define __AC1_x                                                    0x8175F6
#define __AC2_x                                                    0x5EAF9F
#define __AC3_x                                                    0x5F269F
#define __AC4_x                                                    0x5F6670
#define __AC5_x                                                    0x5FC97F
#define __AC6_x                                                    0x600E76
#define __AC7_x                                                    0x5EAA10
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19139C

// Direct Input
#define DI8__Main_x                                                0xF6DE38
#define DI8__Keyboard_x                                            0xF6DE3C
#define DI8__Mouse_x                                               0xF6DE1C
#define DI8__Mouse_Copy_x                                          0xEC656C
#define DI8__Mouse_Check_x                                         0xF6B964
#define __AutoSkillArray_x                                         0xEC7484
#define __Attack_x                                                 0xF652AB
#define __Autofire_x                                               0xF652AC
#define __BindList_x                                               0xC31E20
#define g_eqCommandStates_x                                        0xC32BA0
#define __Clicks_x                                                 0xEC6624
#define __CommandList_x                                            0xC33760
#define __CurrentMapLabel_x                                        0xF7DD74
#define __CurrentSocial_x                                          0xC1B7C0
#define __DoAbilityList_x                                          0xEFCDCC
#define __do_loot_x                                                0x5B69D0
#define __DrawHandler_x                                            0x15FD0F0
#define __GroupCount_x                                             0xEB6822
#define __Guilds_x                                                 0xEBCD78
#define __gWorld_x                                                 0xEB6F68
#define __HWnd_x                                                   0xF6DE20
#define __heqmain_x                                                0xF6DDF8
#define __InChatMode_x                                             0xEC6554
#define __LastTell_x                                               0xEC84C8
#define __LMouseHeldTime_x                                         0xEC6690
#define __Mouse_x                                                  0xF6DE24
#define __MouseLook_x                                              0xEC65EA
#define __MouseEventTime_x                                         0xF65D8C
#define __gpbCommandEvent_x                                        0xEB6A24
#define __NetStatusToggle_x                                        0xEC65ED
#define __PCNames_x                                                0xEC7A74
#define __RangeAttackReady_x                                       0xEC7768
#define __RMouseHeldTime_x                                         0xEC668C
#define __RunWalkState_x                                           0xEC6558
#define __ScreenMode_x                                             0xE0423C
#define __ScreenX_x                                                0xEC650C
#define __ScreenY_x                                                0xEC6508
#define __ScreenXMax_x                                             0xEC6510
#define __ScreenYMax_x                                             0xEC6514
#define __ServerHost_x                                             0xEB6C53
#define __ServerName_x                                             0xEFCD8C
#define __ShiftKeyDown_x                                           0xEC6BE4
#define __ShowNames_x                                              0xEC7924
#define __Socials_x                                                0xEFCE8C
#define __SubscriptionType_x                                       0xFC2280
#define __TargetAggroHolder_x                                      0xF80728
#define __ZoneType_x                                               0xEC69E8
#define __GroupAggro_x                                             0xF80768
#define __LoginName_x                                              0xF6B5F4
#define __Inviter_x                                                0xF65228
#define __AttackOnAssist_x                                         0xEC78E0
#define __UseTellWindows_x                                         0xEC7C10
#define __gfMaxZoomCameraDistance_x                                0xB01E80
#define __gfMaxCameraDistance_x                                    0xB2E244
#define __pulAutoRun_x                                             0xEC6608
#define __pulForward_x                                             0xEC7C48
#define __pulBackward_x                                            0xEC7C4C
#define __pulTurnRight_x                                           0xEC7C50
#define __pulTurnLeft_x                                            0xEC7C54
#define __pulStrafeLeft_x                                          0xEC7C58
#define __pulStrafeRight_x                                         0xEC7C5C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB9110
#define instEQZoneInfo_x                                           0xEC67E0
#define pinstActiveBanker_x                                        0xEB6A38
#define pinstActiveCorpse_x                                        0xEB6A30
#define pinstActiveGMaster_x                                       0xEB6A34
#define pinstActiveMerchant_x                                      0xEB6A2C
#define pinstAltAdvManager_x                                       0xE05340
#define pinstBandageTarget_x                                       0xEB6A48
#define pinstCamActor_x                                            0xE04230
#define pinstCDBStr_x                                              0xE0405C
#define pinstCDisplay_x                                            0xEB8F78
#define pinstCEverQuest_x                                          0xF6AEB8
#define pinstEverQuestInfo_x                                       0xEC6500
#define pinstCharData_x                                            0xEB6804
#define pinstCharSpawn_x                                           0xEB6A80
#define pinstControlledMissile_x                                   0xEB6F64
#define pinstControlledPlayer_x                                    0xEB6A80
#define pinstCResolutionHandler_x                                  0x15FD320
#define pinstCSidlManager_x                                        0x15FC2B8
#define pinstCXWndManager_x                                        0x15FC2B4
#define instDynamicZone_x                                          0xEBCC50
#define pinstDZMember_x                                            0xEBCD60
#define pinstDZTimerInfo_x                                         0xEBCD64
#define pinstEqLogin_x                                             0xF6AF40
#define instEQMisc_x                                               0xE03FA0
#define pinstEQSoundManager_x                                      0xE06310
#define pinstEQSpellStrings_x                                      0xCC69B8
#define instExpeditionLeader_x                                     0xEBCC9A
#define instExpeditionName_x                                       0xEBCCDA
#define pinstGroup_x                                               0xEB681E
#define pinstImeManager_x                                          0x15FC2B0
#define pinstLocalPlayer_x                                         0xEB6A28
#define pinstMercenaryData_x                                       0xF67880
#define pinstMercenaryStats_x                                      0xF80874
#define pinstModelPlayer_x                                         0xEB6A40
#define pinstPCData_x                                              0xEB6804
#define pinstSkillMgr_x                                            0xF699E8
#define pinstSpawnManager_x                                        0xF68490
#define pinstSpellManager_x                                        0xF69C28
#define pinstSpellSets_x                                           0xF5DED4
#define pinstStringTable_x                                         0xEB6808
#define pinstSwitchManager_x                                       0xEB66B0
#define pinstTarget_x                                              0xEB6A7C
#define pinstTargetObject_x                                        0xEB6B08
#define pinstTargetSwitch_x                                        0xEB8F70
#define pinstTaskMember_x                                          0xE03E30
#define pinstTrackTarget_x                                         0xEB6A84
#define pinstTradeTarget_x                                         0xEB6A3C
#define instTributeActive_x                                        0xE03FC1
#define pinstViewActor_x                                           0xE0422C
#define pinstWorldData_x                                           0xEB6A14
#define pinstZoneAddr_x                                            0xEC6A80
#define pinstPlayerPath_x                                          0xF68528
#define pinstTargetIndicator_x                                     0xF69E90
#define EQObject_Top_x                                             0xEB6A20
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE04114
#define pinstCAchievementsWnd_x                                    0xE04170
#define pinstCActionsWnd_x                                         0xE0413C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE04268
#define pinstCAdvancedLootWnd_x                                    0xE04204
#define pinstCAdventureLeaderboardWnd_x                            0xF77548
#define pinstCAdventureRequestWnd_x                                0xF775F8
#define pinstCAdventureStatsWnd_x                                  0xF776A8
#define pinstCAggroMeterWnd_x                                      0xE0426C
#define pinstCAlarmWnd_x                                           0xE041D0
#define pinstCAlertHistoryWnd_x                                    0xE04294
#define pinstCAlertStackWnd_x                                      0xE041DC
#define pinstCAlertWnd_x                                           0xE041EC
#define pinstCAltStorageWnd_x                                      0xF77A08
#define pinstCAudioTriggersWindow_x                                0xCB8CE8
#define pinstCAuraWnd_x                                            0xE0420C
#define pinstCAvaZoneWnd_x                                         0xE04220
#define pinstCBandolierWnd_x                                       0xE04264
#define pinstCBankWnd_x                                            0xE042B4
#define pinstCBarterMerchantWnd_x                                  0xF78C48
#define pinstCBarterSearchWnd_x                                    0xF78CF8
#define pinstCBarterWnd_x                                          0xF78DA8
#define pinstCBazaarConfirmationWnd_x                              0xE04198
#define pinstCBazaarSearchWnd_x                                    0xE04118
#define pinstCBazaarWnd_x                                          0xE041B4
#define pinstCBlockedBuffWnd_x                                     0xE04218
#define pinstCBlockedPetBuffWnd_x                                  0xE04258
#define pinstCBodyTintWnd_x                                        0xE0414C
#define pinstCBookWnd_x                                            0xE042A4
#define pinstCBreathWnd_x                                          0xE04128
#define pinstCBuffWindowNORMAL_x                                   0xE041FC
#define pinstCBuffWindowSHORT_x                                    0xE04200
#define pinstCBugReportWnd_x                                       0xE042AC
#define pinstCButtonWnd_x                                          0x15FC520
#define pinstCCastingWnd_x                                         0xE04290
#define pinstCCastSpellWnd_x                                       0xE0411C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE04168
#define pinstCChatWindowManager_x                                  0xF79868
#define pinstCClaimWnd_x                                           0xF799C0
#define pinstCColorPickerWnd_x                                     0xE0478C
#define pinstCCombatAbilityWnd_x                                   0xE041C0
#define pinstCCombatSkillsSelectWnd_x                              0xE0417C
#define pinstCCompassWnd_x                                         0xE04140
#define pinstCConfirmationDialog_x                                 0xF7E8C0
#define pinstCContainerMgr_x                                       0xE04164
#define pinstCContextMenuManager_x                                 0x15FC270
#define pinstCCursorAttachment_x                                   0xE04278
#define pinstCDynamicZoneWnd_x                                     0xF79F88
#define pinstCEditLabelWnd_x                                       0xE041F0
#define pinstCEQMainWnd_x                                          0xF7A1D0
#define pinstCEventCalendarWnd_x                                   0xE0477C
#define pinstCExtendedTargetWnd_x                                  0xE04248
#define pinstCFacePick_x                                           0xE04194
#define pinstCFactionWnd_x                                         0xE041A4
#define pinstCFellowshipWnd_x                                      0xF7A3D0
#define pinstCFileSelectionWnd_x                                   0xE04784
#define pinstCFindItemWnd_x                                        0xE04190
#define pinstCFindLocationWnd_x                                    0xF7A528
#define pinstCFriendsWnd_x                                         0xE0418C
#define pinstCGemsGameWnd_x                                        0xE041A0
#define pinstCGiveWnd_x                                            0xE041D8
#define pinstCGroupSearchFiltersWnd_x                              0xE04298
#define pinstCGroupSearchWnd_x                                     0xF7A920
#define pinstCGroupWnd_x                                           0xF7A9D0
#define pinstCGuildBankWnd_x                                       0xEC78C4
#define pinstCGuildCreationWnd_x                                   0xF7AB30
#define pinstCGuildMgmtWnd_x                                       0xF7ABE0
#define pinstCharacterCreation_x                                   0xE04184
#define pinstCHelpWnd_x                                            0xE041CC
#define pinstCHeritageSelectionWnd_x                               0xE041A8
#define pinstCHotButtonWnd_x                                       0xF7CD38
#define pinstCHotButtonWnd1_x                                      0xF7CD38
#define pinstCHotButtonWnd2_x                                      0xF7CD3C
#define pinstCHotButtonWnd3_x                                      0xF7CD40
#define pinstCHotButtonWnd4_x                                      0xF7CD44
#define pinstCIconSelectionWnd_x                                   0xE04270
#define pinstCInspectWnd_x                                         0xE0425C
#define pinstCInventoryWnd_x                                       0xE04210
#define pinstCInvSlotMgr_x                                         0xE04124
#define pinstCItemDisplayManager_x                                 0xF7D2C8
#define pinstCItemExpTransferWnd_x                                 0xF7D3F8
#define pinstCItemOverflowWnd_x                                    0xE04120
#define pinstCJournalCatWnd_x                                      0xE040FC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE042EC
#define pinstCKeyRingWnd_x                                         0xE04284
#define pinstCLargeDialogWnd_x                                     0xF7F540
#define pinstCLayoutCopyWnd_x                                      0xF7D748
#define pinstCLFGuildWnd_x                                         0xF7D7F8
#define pinstCLoadskinWnd_x                                        0xE041B0
#define pinstCLootFiltersCopyWnd_x                                 0xCD5338
#define pinstCLootFiltersWnd_x                                     0xE041E0
#define pinstCLootSettingsWnd_x                                    0xE041F8
#define pinstCLootWnd_x                                            0xE04104
#define pinstCMailAddressBookWnd_x                                 0xE0412C
#define pinstCMailCompositionWnd_x                                 0xE04110
#define pinstCMailIgnoreListWnd_x                                  0xE04130
#define pinstCMailWnd_x                                            0xE04990
#define pinstCManageLootWnd_x                                      0xE057F0
#define pinstCMapToolbarWnd_x                                      0xE041D4
#define pinstCMapViewWnd_x                                         0xE041AC
#define pinstCMarketplaceWnd_x                                     0xE041E4
#define pinstCMerchantWnd_x                                        0xE04108
#define pinstCMIZoneSelectWnd_x                                    0xF7E030
#define pinstCMusicPlayerWnd_x                                     0xE042B8
#define pinstCNameChangeMercWnd_x                                  0xE04188
#define pinstCNameChangePetWnd_x                                   0xE04174
#define pinstCNameChangeWnd_x                                      0xE0419C
#define pinstCNoteWnd_x                                            0xE041B8
#define pinstCObjectPreviewWnd_x                                   0xE041F4
#define pinstCOptionsWnd_x                                         0xE041C4
#define pinstCPetInfoWnd_x                                         0xE042F4
#define pinstCPetitionQWnd_x                                       0xE04158
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE04150
#define pinstCPlayerWnd_x                                          0xE04778
#define pinstCPopupWndManager_x                                    0xF7E8C0
#define pinstCProgressionSelectionWnd_x                            0xF7E970
#define pinstCPurchaseGroupWnd_x                                   0xE04250
#define pinstCPurchaseWnd_x                                        0xE04214
#define pinstCPvPLeaderboardWnd_x                                  0xF7EA20
#define pinstCPvPStatsWnd_x                                        0xF7EAD0
#define pinstCQuantityWnd_x                                        0xE042F0
#define pinstCRaceChangeWnd_x                                      0xE041C8
#define pinstCRaidOptionsWnd_x                                     0xE042A0
#define pinstCRaidWnd_x                                            0xE04100
#define pinstCRealEstateItemsWnd_x                                 0xE0416C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE0410C
#define pinstCRealEstateManageWnd_x                                0xE04260
#define pinstCRealEstateNeighborhoodWnd_x                          0xE04288
#define pinstCRealEstatePlotSearchWnd_x                            0xE042B0
#define pinstCRealEstatePurchaseWnd_x                              0xE042E8
#define pinstCRespawnWnd_x                                         0xE04228
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE04178
#define pinstCSendMoneyWnd_x                                       0xE041E8
#define pinstCServerListWnd_x                                      0xE0430C
#define pinstCSkillsSelectWnd_x                                    0xE04160
#define pinstCSkillsWnd_x                                          0xE04144
#define pinstCSocialEditWnd_x                                      0xE0427C
#define pinstCSocialWnd_x                                          0xE04180
#define pinstCSpellBookWnd_x                                       0xE041BC
#define pinstCStoryWnd_x                                           0xE04134
#define pinstCTargetOfTargetWnd_x                                  0xF808F8
#define pinstCTargetWnd_x                                          0xE04224
#define pinstCTaskOverlayWnd_x                                     0xE0424C
#define pinstCTaskSelectWnd_x                                      0xF80A50
#define pinstCTaskManager_x                                        0xCD5C78
#define pinstCTaskTemplateSelectWnd_x                              0xF80B00
#define pinstCTaskWnd_x                                            0xF80BB0
#define pinstCTextEntryWnd_x                                       0xE0429C
#define pinstCTimeLeftWnd_x                                        0xE04138
#define pinstCTipWndCONTEXT_x                                      0xF80DB4
#define pinstCTipWndOFDAY_x                                        0xF80DB0
#define pinstCTitleWnd_x                                           0xF80E60
#define pinstCTrackingWnd_x                                        0xE0421C
#define pinstCTradeskillWnd_x                                      0xF80FC8
#define pinstCTradeWnd_x                                           0xE04154
#define pinstCTrainWnd_x                                           0xE040F8
#define pinstCTributeBenefitWnd_x                                  0xF811C8
#define pinstCTributeMasterWnd_x                                   0xF81278
#define pinstCTributeTrophyWnd_x                                   0xF81328
#define pinstCVideoModesWnd_x                                      0xE04780
#define pinstCVoiceMacroWnd_x                                      0xF6A5F8
#define pinstCVoteResultsWnd_x                                     0xE0415C
#define pinstCVoteWnd_x                                            0xE04148
#define pinstCWebManager_x                                         0xF6AC74
#define pinstCZoneGuideWnd_x                                       0xE04254
#define pinstCZonePathWnd_x                                        0xE04274

#define pinstEQSuiteTextureLoader_x                                0xCA3128
#define pinstItemIconCache_x                                       0xF7A188
#define pinstLootFiltersManager_x                                  0xCD53E8
#define pinstRewardSelectionWnd_x                                  0xF7F218

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B1E30
#define __CastRay2_x                                               0x5B1E80
#define __ConvertItemTags_x                                        0x5CD9E0
#define __CleanItemTags_x                                          0x47CFD0
#define __DoesFileExist_x                                          0x907240
#define __EQGetTime_x                                              0x903CE0
#define __ExecuteCmd_x                                             0x5AA660
#define __FixHeading_x                                             0x99F230
#define __GameLoop_x                                               0x6BF070
#define __get_bearing_x                                            0x5B19A0
#define __get_melee_range_x                                        0x5B2070
#define __GetAnimationCache_x                                      0x724300
#define __GetGaugeValueFromEQ_x                                    0x815AA0
#define __GetLabelFromEQ_x                                         0x817580
#define __GetXTargetType_x                                         0x9A0C80
#define __HandleMouseWheel_x                                       0x6BFF30
#define __HeadingDiff_x                                            0x99F2A0
#define __HelpPath_x                                               0xF6597C
#define __LoadFrontEnd_x                                           0x6BC390
#define __NewUIINI_x                                               0x815770
#define __ProcessGameEvents_x                                      0x612620
#define __ProcessMouseEvent_x                                      0x611DE0
#define __SaveColors_x                                             0x553230
#define __STMLToText_x                                             0x942630
#define __ToggleKeyRingItem_x                                      0x516520
#define CMemoryMappedFile__SetFile_x                               0xA8E5B0
#define CrashDetected_x                                            0x6BDE30
#define DrawNetStatus_x                                            0x63E3A0
#define Expansion_HoT_x                                            0xEC78CC
#define Teleport_Table_Size_x                                      0xEB6B10
#define Teleport_Table_x                                           0xEB6F70
#define Util__FastTime_x                                           0x9038B0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490290
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499180
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F50
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493820
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55AD10
#define AltAdvManager__IsAbilityReady_x                            0x559C40
#define AltAdvManager__GetAAById_x                                 0x559E40
#define AltAdvManager__CanTrainAbility_x                           0x559EB0
#define AltAdvManager__CanSeeAbility_x                             0x55A210

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9D70
#define CharacterZoneClient__HasSkill_x                            0x4D4C60
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6380
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE620
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAC50
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8D40
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8E20
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8F00
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2E30
#define CharacterZoneClient__BardCastBard_x                        0x4C5990
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAD20
#define CharacterZoneClient__GetEffect_x                           0x4BAB90
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3E80
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3F50
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3FA0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C40F0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C42C0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2AF0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D72E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6D60

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E5980
#define CBankWnd__WndNotification_x                                0x6E5760

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F32E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x620EF0
#define CButtonWnd__CButtonWnd_x                                   0x93EA00

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x713480
#define CChatManager__InitContextMenu_x                            0x70C5D0
#define CChatManager__FreeChatWindow_x                             0x711FC0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E83C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x713100
#define CChatManager__CreateChatWindow_x                           0x712600

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E84D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9530E0
#define CContextMenu__dCContextMenu_x                              0x953320
#define CContextMenu__AddMenuItem_x                                0x953330
#define CContextMenu__RemoveMenuItem_x                             0x953640
#define CContextMenu__RemoveAllMenuItems_x                         0x953660
#define CContextMenu__CheckMenuItem_x                              0x9536E0
#define CContextMenu__SetMenuItem_x                                0x953560
#define CContextMenu__AddSeparator_x                               0x9534C0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x953C80
#define CContextMenuManager__RemoveMenu_x                          0x953CF0
#define CContextMenuManager__PopupMenu_x                           0x953DB0
#define CContextMenuManager__Flush_x                               0x953C20
#define CContextMenuManager__GetMenu_x                             0x49B310
#define CContextMenuManager__CreateDefaultMenu_x                   0x71EAE0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DF2F0
#define CChatService__GetFriendName_x                              0x8DF300

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x713CF0
#define CChatWindow__Clear_x                                       0x714FC0
#define CChatWindow__WndNotification_x                             0x715750
#define CChatWindow__AddHistory_x                                  0x714880

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x950530
#define CComboWnd__Draw_x                                          0x94FA20
#define CComboWnd__GetCurChoice_x                                  0x950370
#define CComboWnd__GetListRect_x                                   0x94FED0
#define CComboWnd__GetTextRect_x                                   0x9505A0
#define CComboWnd__InsertChoice_x                                  0x950060
#define CComboWnd__SetColors_x                                     0x950030
#define CComboWnd__SetChoice_x                                     0x950340
#define CComboWnd__GetItemCount_x                                  0x950380
#define CComboWnd__GetCurChoiceText_x                              0x9503C0
#define CComboWnd__GetChoiceText_x                                 0x950390
#define CComboWnd__InsertChoiceAtIndex_x                           0x950100

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71C4E0
#define CContainerWnd__vftable_x                                   0xB15724
#define CContainerWnd__SetContainer_x                              0x71DA30

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54DC60
#define CDisplay__PreZoneMainUI_x                                  0x54DC70
#define CDisplay__CleanGameUI_x                                    0x552FF0
#define CDisplay__GetClickedActor_x                                0x545F80
#define CDisplay__GetUserDefinedColor_x                            0x53E630
#define CDisplay__GetWorldFilePath_x                               0x5479F0
#define CDisplay__is3dON_x                                         0x542BE0
#define CDisplay__ReloadUI_x                                       0x54D0F0
#define CDisplay__WriteTextHD2_x                                   0x5429D0
#define CDisplay__TrueDistance_x                                   0x5496B0
#define CDisplay__SetViewActor_x                                   0x5458A0
#define CDisplay__GetFloorHeight_x                                 0x542CA0
#define CDisplay__SetRenderWindow_x                                0x541600
#define CDisplay__ToggleScreenshotMode_x                           0x545370

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x972E70

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x956630
#define CEditWnd__GetCharIndexPt_x                                 0x957560
#define CEditWnd__GetDisplayString_x                               0x957400
#define CEditWnd__GetHorzOffset_x                                  0x955C60
#define CEditWnd__GetLineForPrintableChar_x                        0x958700
#define CEditWnd__GetSelStartPt_x                                  0x957810
#define CEditWnd__GetSTMLSafeText_x                                0x957220
#define CEditWnd__PointFromPrintableChar_x                         0x958330
#define CEditWnd__SelectableCharFromPoint_x                        0x9584A0
#define CEditWnd__SetEditable_x                                    0x9578E0
#define CEditWnd__SetWindowTextA_x                                 0x956FA0
#define CEditWnd__ReplaceSelection_x                               0x957FA0
#define CEditWnd__ReplaceSelection1_x                              0x957F20

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x600350
#define CEverQuest__ClickedPlayer_x                                0x5F2480
#define CEverQuest__CreateTargetIndicator_x                        0x60F8C0
#define CEverQuest__DeleteTargetIndicator_x                        0x60F950
#define CEverQuest__DoTellWindow_x                                 0x4E85B0
#define CEverQuest__OutputTextToLog_x                              0x4E8880
#define CEverQuest__DropHeldItemOnGround_x                         0x5E74C0
#define CEverQuest__dsp_chat_x                                     0x4E8C10
#define CEverQuest__trimName_x                                     0x60BBB0
#define CEverQuest__Emote_x                                        0x600BB0
#define CEverQuest__EnterZone_x                                    0x5FAC50
#define CEverQuest__GetBodyTypeDesc_x                              0x605470
#define CEverQuest__GetClassDesc_x                                 0x605AB0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6060B0
#define CEverQuest__GetDeityDesc_x                                 0x60E200
#define CEverQuest__GetLangDesc_x                                  0x606270
#define CEverQuest__GetRaceDesc_x                                  0x605A90
#define CEverQuest__InterpretCmd_x                                 0x60E7D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EB6C0
#define CEverQuest__LMouseUp_x                                     0x5E9A50
#define CEverQuest__RightClickedOnPlayer_x                         0x5EBFA0
#define CEverQuest__RMouseUp_x                                     0x5EA9D0
#define CEverQuest__SetGameState_x                                 0x5E7250
#define CEverQuest__UPCNotificationFlush_x                         0x60BAB0
#define CEverQuest__IssuePetCommand_x                              0x607670
#define CEverQuest__ReportSuccessfulHit_x                          0x601F00

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72E470
#define CGaugeWnd__CalcLinesFillRect_x                             0x72E4D0
#define CGaugeWnd__Draw_x                                          0x72DAF0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF5C0
#define CGuild__GetGuildName_x                                     0x4AE5E0
#define CGuild__GetGuildIndex_x                                    0x4AEA30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x748670

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6212B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x755660
#define CInvSlotMgr__MoveItem_x                                    0x7543C0
#define CInvSlotMgr__SelectSlot_x                                  0x755730

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x752C00
#define CInvSlot__SliderComplete_x                                 0x750950
#define CInvSlot__GetItemBase_x                                    0x7502E0
#define CInvSlot__UpdateItem_x                                     0x750450

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7571A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x756330
#define CInvSlotWnd__HandleLButtonUp_x                             0x756D20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x810DF0
#define CItemDisplayWnd__UpdateStrings_x                           0x765820
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75F590
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75FA90
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x765E30
#define CItemDisplayWnd__AboutToShow_x                             0x765480
#define CItemDisplayWnd__WndNotification_x                         0x766F10
#define CItemDisplayWnd__RequestConvertItem_x                      0x7669D0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7644E0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7652A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8499E0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76B440

// CLabel 
#define CLabel__Draw_x                                             0x770F30

// CListWnd
#define CListWnd__CListWnd_x                                       0x928C90
#define CListWnd__dCListWnd_x                                      0x928FB0
#define CListWnd__AddColumn_x                                      0x92D430
#define CListWnd__AddColumn1_x                                     0x92D480
#define CListWnd__AddLine_x                                        0x92D810
#define CListWnd__AddString_x                                      0x92D610
#define CListWnd__CalculateFirstVisibleLine_x                      0x92D1F0
#define CListWnd__CalculateVSBRange_x                              0x92CFD0
#define CListWnd__ClearSel_x                                       0x92DFF0
#define CListWnd__ClearAllSel_x                                    0x92E050
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92EA70
#define CListWnd__Compare_x                                        0x92C900
#define CListWnd__Draw_x                                           0x9290E0
#define CListWnd__DrawColumnSeparators_x                           0x92B8D0
#define CListWnd__DrawHeader_x                                     0x92BD40
#define CListWnd__DrawItem_x                                       0x92C240
#define CListWnd__DrawLine_x                                       0x92BA40
#define CListWnd__DrawSeparator_x                                  0x92B970
#define CListWnd__EnableLine_x                                     0x92B1A0
#define CListWnd__EnsureVisible_x                                  0x92E990
#define CListWnd__ExtendSel_x                                      0x92DF20
#define CListWnd__GetColumnTooltip_x                               0x92ACE0
#define CListWnd__GetColumnMinWidth_x                              0x92AD50
#define CListWnd__GetColumnWidth_x                                 0x92AC50
#define CListWnd__GetCurSel_x                                      0x92A5E0
#define CListWnd__GetItemAtPoint_x                                 0x92B420
#define CListWnd__GetItemAtPoint1_x                                0x92B490
#define CListWnd__GetItemData_x                                    0x92A660
#define CListWnd__GetItemHeight_x                                  0x92AA20
#define CListWnd__GetItemIcon_x                                    0x92A7F0
#define CListWnd__GetItemRect_x                                    0x92B290
#define CListWnd__GetItemText_x                                    0x92A6A0
#define CListWnd__GetSelList_x                                     0x92E0A0
#define CListWnd__GetSeparatorRect_x                               0x92B6D0
#define CListWnd__InsertLine_x                                     0x92DC00
#define CListWnd__RemoveLine_x                                     0x92DD50
#define CListWnd__SetColors_x                                      0x92CFA0
#define CListWnd__SetColumnJustification_x                         0x92CCD0
#define CListWnd__SetColumnWidth_x                                 0x92CBF0
#define CListWnd__SetCurSel_x                                      0x92DE60
#define CListWnd__SetItemColor_x                                   0x92E640
#define CListWnd__SetItemData_x                                    0x92E600
#define CListWnd__SetItemText_x                                    0x92E210
#define CListWnd__ShiftColumnSeparator_x                           0x92CD90
#define CListWnd__Sort_x                                           0x92CA80
#define CListWnd__ToggleSel_x                                      0x92DE90
#define CListWnd__SetColumnsSizable_x                              0x92CE40
#define CListWnd__SetItemWnd_x                                     0x92E4C0
#define CListWnd__GetItemWnd_x                                     0x92A840
#define CListWnd__SetItemIcon_x                                    0x92E290
#define CListWnd__CalculateCustomWindowPositions_x                 0x92D2F0
#define CListWnd__SetVScrollPos_x                                  0x92CBD0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x786670
#define CMapViewWnd__GetWorldCoordinates_x                         0x784D80
#define CMapViewWnd__HandleLButtonDown_x                           0x781DC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A6720
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A7000
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A7520
#define CMerchantWnd__SelectRecoverySlot_x                         0x7AA4A0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A5280
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B0040
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A6330

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8ACE10
#define CPacketScrambler__hton_x                                   0x8ACE00

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x947C90
#define CSidlManager__FindScreenPieceTemplate_x                    0x9480A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x947E90
#define CSidlManager__CreateLabel_x                                0x808000
#define CSidlManager__CreateXWndFromTemplate_x                     0x94B000
#define CSidlManager__CreateXWndFromTemplate1_x                    0x94B1E0
#define CSidlManager__CreateXWnd_x                                 0x807F30
#define CSidlManager__CreateHotButtonWnd_x                         0x808500

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x944740
#define CSidlScreenWnd__CalculateVSBRange_x                        0x944640
#define CSidlScreenWnd__ConvertToRes_x                             0x969E60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9440D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x943DC0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x943E90
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x943F60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x944BE0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9450B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x944DD0
#define CSidlScreenWnd__Init1_x                                    0x9439E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x945100
#define CSidlScreenWnd__LoadIniListWnd_x                           0x945C40
#define CSidlScreenWnd__LoadSidlScreen_x                           0x942DE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9457C0
#define CSidlScreenWnd__StoreIniVis_x                              0x945B20
#define CSidlScreenWnd__WndNotification_x                          0x944AF0
#define CSidlScreenWnd__GetChildItem_x                             0x945030
#define CSidlScreenWnd__HandleLButtonUp_x                          0x934840
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FC140

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x685B60
#define CSkillMgr__GetSkillCap_x                                   0x685D40
#define CSkillMgr__GetNameToken_x                                  0x6852E0
#define CSkillMgr__IsActivatedSkill_x                              0x685420
#define CSkillMgr__IsCombatSkill_x                                 0x685360

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x954A40
#define CSliderWnd__SetValue_x                                     0x9548B0
#define CSliderWnd__SetNumTicks_x                                  0x954910

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80E0E0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95D250
#define CStmlWnd__CalculateHSBRange_x                              0x95E330
#define CStmlWnd__CalculateVSBRange_x                              0x95E2A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x962670
#define CStmlWnd__FastForwardToEndOfTag_x                          0x963300
#define CStmlWnd__ForceParseNow_x                                  0x95D7F0
#define CStmlWnd__GetNextTagPiece_x                                0x9625D0
#define CStmlWnd__GetSTMLText_x                                    0x505DF0
#define CStmlWnd__GetVisibleText_x                                 0x95D810
#define CStmlWnd__InitializeWindowVariables_x                      0x963150
#define CStmlWnd__MakeStmlColorTag_x                               0x95C8C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x95C930
#define CStmlWnd__SetSTMLText_x                                    0x95B970
#define CStmlWnd__StripFirstSTMLLines_x                            0x964400
#define CStmlWnd__UpdateHistoryString_x                            0x963510

// CTabWnd 
#define CTabWnd__Draw_x                                            0x95AAC0
#define CTabWnd__DrawCurrentPage_x                                 0x95B1F0
#define CTabWnd__DrawTab_x                                         0x95AF10
#define CTabWnd__GetCurrentPage_x                                  0x95A2C0
#define CTabWnd__GetPageInnerRect_x                                0x95A500
#define CTabWnd__GetTabInnerRect_x                                 0x95A440
#define CTabWnd__GetTabRect_x                                      0x95A2F0
#define CTabWnd__InsertPage_x                                      0x95A710
#define CTabWnd__SetPage_x                                         0x95A580
#define CTabWnd__SetPageRect_x                                     0x95AA00
#define CTabWnd__UpdatePage_x                                      0x95ADD0
#define CTabWnd__GetPageFromTabIndex_x                             0x95AE50
#define CTabWnd__GetCurrentTabIndex_x                              0x95A2B0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76B810
#define CPageWnd__SetTabText_x                                     0x959E10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9030

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9316F0
#define CTextureFont__GetTextExtent_x                              0x9318B0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B8F50
#define CHtmlComponentWnd__ValidateUri_x                           0x74A060
#define CHtmlWnd__SetClientCallbacks_x                             0x626360
#define CHtmlWnd__AddObserver_x                                    0x626380
#define CHtmlWnd__RemoveObserver_x                                 0x6263E0
#define Window__getProgress_x                                      0x862180
#define Window__getStatus_x                                        0x8621A0
#define Window__getURI_x                                           0x8621B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96F900

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91E700

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8200
#define CXStr__CXStr1_x                                            0x4B6570
#define CXStr__CXStr3_x                                            0x8FFE20
#define CXStr__dCXStr_x                                            0x478700
#define CXStr__operator_equal_x                                    0x900050
#define CXStr__operator_equal1_x                                   0x900090
#define CXStr__operator_plus_equal1_x                              0x900B20
#define CXStr__SetString_x                                         0x902A10
#define CXStr__operator_char_p_x                                   0x900590
#define CXStr__GetChar_x                                           0x902340
#define CXStr__Delete_x                                            0x901C10
#define CXStr__GetUnicode_x                                        0x9023B0
#define CXStr__GetLength_x                                         0x47D380
#define CXStr__Mid_x                                               0x47D390
#define CXStr__Insert_x                                            0x902410
#define CXStr__FindNext_x                                          0x902080

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x952CF0
#define CXWnd__BringToTop_x                                        0x938030
#define CXWnd__Center_x                                            0x937BB0
#define CXWnd__ClrFocus_x                                          0x9379C0
#define CXWnd__Destroy_x                                           0x937A70
#define CXWnd__DoAllDrawing_x                                      0x933FD0
#define CXWnd__DrawChildren_x                                      0x933FA0
#define CXWnd__DrawColoredRect_x                                   0x934430
#define CXWnd__DrawTooltip_x                                       0x932AF0
#define CXWnd__DrawTooltipAtPoint_x                                0x932BB0
#define CXWnd__GetBorderFrame_x                                    0x934290
#define CXWnd__GetChildWndAt_x                                     0x9380D0
#define CXWnd__GetClientClipRect_x                                 0x936250
#define CXWnd__GetScreenClipRect_x                                 0x936320
#define CXWnd__GetScreenRect_x                                     0x9364F0
#define CXWnd__GetTooltipRect_x                                    0x934480
#define CXWnd__GetWindowTextA_x                                    0x49C9E0
#define CXWnd__IsActive_x                                          0x934BC0
#define CXWnd__IsDescendantOf_x                                    0x936F10
#define CXWnd__IsReallyVisible_x                                   0x936F40
#define CXWnd__IsType_x                                            0x938740
#define CXWnd__Move_x                                              0x936FC0
#define CXWnd__Move1_x                                             0x937070
#define CXWnd__ProcessTransition_x                                 0x937B60
#define CXWnd__Refade_x                                            0x937350
#define CXWnd__Resize_x                                            0x9375D0
#define CXWnd__Right_x                                             0x937DF0
#define CXWnd__SetFocus_x                                          0x937980
#define CXWnd__SetFont_x                                           0x9379F0
#define CXWnd__SetKeyTooltip_x                                     0x938560
#define CXWnd__SetMouseOver_x                                      0x9353D0
#define CXWnd__StartFade_x                                         0x936DF0
#define CXWnd__GetChildItem_x                                      0x938240
#define CXWnd__SetParent_x                                         0x936CA0
#define CXWnd__Minimize_x                                          0x937640

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96AEE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x93AF50
#define CXWndManager__DrawWindows_x                                0x93AF70
#define CXWndManager__GetKeyboardFlags_x                           0x93D690
#define CXWndManager__HandleKeyboardMsg_x                          0x93D240
#define CXWndManager__RemoveWnd_x                                  0x93D8C0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93DE40

// CDBStr
#define CDBStr__GetString_x                                        0x53D5E0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBC30
#define EQ_Character__Cur_HP_x                                     0x4D1CA0
#define EQ_Character__Cur_Mana_x                                   0x4D9400
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEC70
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2730
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2880
#define EQ_Character__GetHPRegen_x                                 0x4DF1D0
#define EQ_Character__GetEnduranceRegen_x                          0x4DF7D0
#define EQ_Character__GetManaRegen_x                               0x4DFC10
#define EQ_Character__Max_Endurance_x                              0x64BEF0
#define EQ_Character__Max_HP_x                                     0x4D1AD0
#define EQ_Character__Max_Mana_x                                   0x64BCF0
#define EQ_Character__doCombatAbility_x                            0x64E350
#define EQ_Character__UseSkill_x                                   0x4E19F0
#define EQ_Character__GetConLevel_x                                0x645280
#define EQ_Character__IsExpansionFlag_x                            0x5A8E30
#define EQ_Character__TotalEffect_x                                0x4C50D0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF9C0
#define EQ_Character__SpellDuration_x                              0x4BF4F0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4A20
#define EQ_Character__GetBaseSkill_x                               0x4D59C0
#define EQ_Character__CanUseItem_x                                 0x4D9710

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CC1E0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6628A0

//PcClient
#define PcClient__PcClient_x                                       0x6429C0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B98A0
#define CCharacterListWnd__EnterWorld_x                            0x4B92E0
#define CCharacterListWnd__Quit_x                                  0x4B9030
#define CCharacterListWnd__UpdateList_x                            0x4B9470

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x627510
#define EQ_Item__CreateItemTagString_x                             0x8A6410
#define EQ_Item__IsStackable_x                                     0x8AB060
#define EQ_Item__GetImageNum_x                                     0x8A7EC0
#define EQ_Item__CreateItemClient_x                                0x626760
#define EQ_Item__GetItemValue_x                                    0x8A9290
#define EQ_Item__ValueSellMerchant_x                               0x8AC9F0
#define EQ_Item__IsKeyRingItem_x                                   0x8AA980
#define EQ_Item__CanGoInBag_x                                      0x627630
#define EQ_Item__IsEmpty_x                                         0x8AA4C0
#define EQ_Item__GetMaxItemCount_x                                 0x8A96A0
#define EQ_Item__GetHeldItem_x                                     0x8A7D90
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A5D50

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55B9E0
#define EQ_LoadingS__Array_x                                       0xC2AB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64C850
#define EQ_PC__GetAlternateAbilityId_x                             0x8B5D10
#define EQ_PC__GetCombatAbility_x                                  0x8B6380
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B63F0
#define EQ_PC__GetItemRecastTimer_x                                0x64E8D0
#define EQ_PC__HasLoreItem_x                                       0x645A40
#define EQ_PC__AlertInventoryChanged_x                             0x644BC0
#define EQ_PC__GetPcZoneClient_x                                   0x6712B0
#define EQ_PC__RemoveMyAffect_x                                    0x651B00
#define EQ_PC__GetKeyRingItems_x                                   0x8B6C80
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B6A10
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B6F80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AF370
#define EQItemList__add_object_x                                   0x5DCD80
#define EQItemList__add_item_x                                     0x5AF8D0
#define EQItemList__delete_item_x                                  0x5AF920
#define EQItemList__FreeItemList_x                                 0x5AF820

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A170

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x664120
#define EQPlayer__dEQPlayer_x                                      0x657050
#define EQPlayer__DoAttack_x                                       0x66BF40
#define EQPlayer__EQPlayer_x                                       0x657710
#define EQPlayer__SetNameSpriteState_x                             0x65BE10
#define EQPlayer__SetNameSpriteTint_x                              0x65CCD0
#define PlayerBase__HasProperty_j_x                                0x99D630
#define EQPlayer__IsTargetable_x                                   0x99DAD0
#define EQPlayer__CanSee_x                                         0x99D930
#define EQPlayer__CanSee1_x                                        0x99DA00
#define PlayerBase__GetVisibilityLineSegment_x                     0x99D6F0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66ED40
#define PlayerZoneClient__GetLevel_x                               0x6712F0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DDEF0
#define PlayerZoneClient__LegalPlayerRace_x                        0x554E20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x666E40
#define EQPlayerManager__GetSpawnByName_x                          0x666EF0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x666F80

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62ABF0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62AC70
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62ACB0
#define KeypressHandler__ClearCommandStateArray_x                  0x62C0C0
#define KeypressHandler__HandleKeyDown_x                           0x62C0E0
#define KeypressHandler__HandleKeyUp_x                             0x62C180
#define KeypressHandler__SaveKeymapping_x                          0x62C5D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7824E0
#define MapViewMap__SaveEx_x                                       0x7858A0
#define MapViewMap__SetZoom_x                                      0x789F70

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8CA100

// StringTable 
#define StringTable__getString_x                                   0x8C4FE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x651770
#define PcZoneClient__RemovePetEffect_x                            0x651DA0
#define PcZoneClient__HasAlternateAbility_x                        0x64BB20
#define PcZoneClient__GetCurrentMod_x                              0x4E4AA0
#define PcZoneClient__GetModCap_x                                  0x4E49A0
#define PcZoneClient__CanEquipItem_x                               0x64C1F0
#define PcZoneClient__GetItemByID_x                                0x64ED40
#define PcZoneClient__GetItemByItemClass_x                         0x64EE90
#define PcZoneClient__RemoveBuffEffect_x                           0x651DC0
#define PcZoneClient__BandolierSwap_x                              0x64CE10
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64E870

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E29B0

//IconCache
#define IconCache__GetIcon_x                                       0x723BA0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71B680
#define CContainerMgr__CloseContainer_x                            0x71B950
#define CContainerMgr__OpenExperimentContainer_x                   0x71C3D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DA570

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61F6A0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7789F0
#define CLootWnd__RequestLootSlot_x                                0x777C20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57C560
#define EQ_Spell__SpellAffects_x                                   0x57C9D0
#define EQ_Spell__SpellAffectBase_x                                0x57C790
#define EQ_Spell__IsStackable_x                                    0x4C96E0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9560
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6C30
#define EQ_Spell__IsSPAStacking_x                                  0x57D820
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57CD30
#define EQ_Spell__IsNoRemove_x                                     0x4C96C0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57D830
#define __IsResEffectSpell_x                                       0x4C8AF0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD120

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D4760

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x821530
#define CTargetWnd__WndNotification_x                              0x820DC0
#define CTargetWnd__RefreshTargetBuffs_x                           0x821090
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81FF20

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x825B20

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x537BC0
#define CTaskManager__HandleMessage_x                              0x536050
#define CTaskManager__GetTaskStatus_x                              0x537C70
#define CTaskManager__GetElementDescription_x                      0x537CF0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x577570
#define EqSoundManager__PlayScriptMp3_x                            0x577830
#define EqSoundManager__SoundAssistPlay_x                          0x689AF0
#define EqSoundManager__WaveInstancePlay_x                         0x689060

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52B440

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x959320

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x563450
#define CAltAbilityData__GetMercMaxRank_x                          0x5633E0
#define CAltAbilityData__GetMaxRank_x                              0x558AC0

//CTargetRing
#define CTargetRing__Cast_x                                        0x61D7C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9540
#define CharacterBase__CreateItemGlobalIndex_x                     0x512BB0
#define CharacterBase__CreateItemIndex_x                           0x625910
#define CharacterBase__GetItemPossession_x                         0x4FE700
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DCD60
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DCDC0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x7026B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x702EE0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x702F90

//messages
#define msg_spell_worn_off_x                                       0x5A1070
#define msg_new_text_x                                             0x595DF0
#define __msgTokenTextParam_x                                      0x5A35A0
#define msgTokenText_x                                             0x5A37F0

//SpellManager
#define SpellManager__vftable_x                                    0xAEF554
#define SpellManager__SpellManager_x                               0x68CE10
#define Spellmanager__LoadTextSpells_x                             0x68D700
#define SpellManager__GetSpellByGroupAndRank_x                     0x68CFE0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A1570

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x513200
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A7370
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63E200
#define ItemGlobalIndex__IsValidIndex_x                            0x513260

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D5100
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D5380

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x771270

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71FD70
#define CCursorAttachment__AttachToCursor1_x                       0x71FDB0
#define CCursorAttachment__Deactivate_x                            0x720DA0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94C040
#define CSidlManagerBase__CreatePageWnd_x                          0x94B830
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x947AB0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x947A40

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x969260
#define CEQSuiteTextureLoader__GetTexture_x                        0x968F20

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x510120
#define CFindItemWnd__WndNotification_x                            0x510C00
#define CFindItemWnd__Update_x                                     0x511770
#define CFindItemWnd__PickupSelectedItem_x                         0x50F970

//IString
#define IString__Append_x                                          0x4F10B0

//Camera
#define CDisplay__cameraType_x                                     0xE04788
#define EverQuest__Cameras_x                                       0xEC7C1C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5188C0
#define LootFiltersManager__GetItemFilterData_x                    0x5181C0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5181F0
#define LootFiltersManager__SetItemLootFilter_x                    0x518410

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C8560

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A70C0
#define CResolutionHandler__GetWindowedStyle_x                     0x684610

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x718460

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8EA370
#define CDistillerInfo__Instance_x                                 0x8EA310

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x737450
#define CGroupWnd__UpdateDisplay_x                                 0x7367A0

//ItemBase
#define ItemBase__IsLore_x                                         0x8AAA30
#define ItemBase__IsLoreEquipped_x                                 0x8AAAA0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DCCE0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DCE20
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DCE80

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x679A60
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67D3E0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x5063F0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2FD0
#define FactionManagerClient__HandleFactionMessage_x               0x4F3640
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3C40
#define FactionManagerClient__GetMaxFaction_x                      0x4F3C5F
#define FactionManagerClient__GetMinFaction_x                      0x4F3C10

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FE6D0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x930710

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BCF0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FEA70

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562910

//CTargetManager
#define CTargetManager__Get_x                                      0x690640

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x679A60

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8DF0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AF7C0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF652B0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
