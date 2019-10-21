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
#define __ExpectedVersionDate                                     "Oct 20 2019"
#define __ExpectedVersionTime                                     "04:43:42"
#define __ActualVersionDate_x                                      0xAFB960
#define __ActualVersionTime_x                                      0xAFB954
#define __ActualVersionBuild_x                                     0xAE763C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6249E0
#define __MemChecker1_x                                            0x8F6610
#define __MemChecker2_x                                            0x6B3300
#define __MemChecker3_x                                            0x6B3250
#define __MemChecker4_x                                            0x84E910
#define __EncryptPad0_x                                            0xC313F0
#define __EncryptPad1_x                                            0xC8F5B0
#define __EncryptPad2_x                                            0xC41C88
#define __EncryptPad3_x                                            0xC41888
#define __EncryptPad4_x                                            0xC7FC08
#define __EncryptPad5_x                                            0xF58CA8
#define __AC1_x                                                    0x80B6C6
#define __AC2_x                                                    0x5DE77F
#define __AC3_x                                                    0x5E5E7F
#define __AC4_x                                                    0x5E9E40
#define __AC5_x                                                    0x5F014F
#define __AC6_x                                                    0x5F4766
#define __AC7_x                                                    0x5DE1F0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1B273C

// Direct Input
#define DI8__Main_x                                                0xF5B184
#define DI8__Keyboard_x                                            0xF5B188
#define DI8__Mouse_x                                               0xF5B1A0
#define DI8__Mouse_Copy_x                                          0xEB4374
#define DI8__Mouse_Check_x                                         0xF58CD0
#define __AutoSkillArray_x                                         0xEB528C
#define __Attack_x                                                 0xF530B3
#define __Autofire_x                                               0xF530B4
#define __BindList_x                                               0xC1FE20
#define g_eqCommandStates_x                                        0xC20BA0
#define __Clicks_x                                                 0xEB442C
#define __CommandList_x                                            0xC21760
#define __CurrentMapLabel_x                                        0xF6BB34
#define __CurrentSocial_x                                          0xC097CC
#define __DoAbilityList_x                                          0xEEABD4
#define __do_loot_x                                                0x5AAA20
#define __DrawHandler_x                                            0x15EAEA8
#define __GroupCount_x                                             0xEA676A
#define __Guilds_x                                                 0xEAAB80
#define __gWorld_x                                                 0xEA6620
#define __HWnd_x                                                   0xF5B1A4
#define __heqmain_x                                                0xF5B178
#define __InChatMode_x                                             0xEB435C
#define __LastTell_x                                               0xEB62D0
#define __LMouseHeldTime_x                                         0xEB4498
#define __Mouse_x                                                  0xF5B164
#define __MouseLook_x                                              0xEB43F2
#define __MouseEventTime_x                                         0xF53B94
#define __gpbCommandEvent_x                                        0xEA6974
#define __NetStatusToggle_x                                        0xEB43F5
#define __PCNames_x                                                0xEB587C
#define __RangeAttackReady_x                                       0xEB5570
#define __RMouseHeldTime_x                                         0xEB4494
#define __RunWalkState_x                                           0xEB4360
#define __ScreenMode_x                                             0xDF1F44
#define __ScreenX_x                                                0xEB4314
#define __ScreenY_x                                                0xEB4310
#define __ScreenXMax_x                                             0xEB4318
#define __ScreenYMax_x                                             0xEB431C
#define __ServerHost_x                                             0xEA6C03
#define __ServerName_x                                             0xEEAB94
#define __ShiftKeyDown_x                                           0xEB49EC
#define __ShowNames_x                                              0xEB572C
#define __Socials_x                                                0xEEAC94
#define __SubscriptionType_x                                       0xFB0038
#define __TargetAggroHolder_x                                      0xF6E4E8
#define __ZoneType_x                                               0xEB47F0
#define __GroupAggro_x                                             0xF6E528
#define __LoginName_x                                              0xF5B8DC
#define __Inviter_x                                                0xF53030
#define __AttackOnAssist_x                                         0xEB56E8
#define __UseTellWindows_x                                         0xEB5A18
#define __gfMaxZoomCameraDistance_x                                0xAF12B0
#define __gfMaxCameraDistance_x                                    0xB1D83C
#define __pulAutoRun_x                                             0xEB4410
#define __pulForward_x                                             0xEB5A50
#define __pulBackward_x                                            0xEB5A54
#define __pulTurnRight_x                                           0xEB5A58
#define __pulTurnLeft_x                                            0xEB5A5C
#define __pulStrafeLeft_x                                          0xEB5A60
#define __pulStrafeRight_x                                         0xEB5A64

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEA6F18
#define instEQZoneInfo_x                                           0xEB45E8
#define pinstActiveBanker_x                                        0xEA698C
#define pinstActiveCorpse_x                                        0xEA6984
#define pinstActiveGMaster_x                                       0xEA6988
#define pinstActiveMerchant_x                                      0xEA6980
#define pinstAltAdvManager_x                                       0xDF3148
#define pinstBandageTarget_x                                       0xEA699C
#define pinstCamActor_x                                            0xDF1F38
#define pinstCDBStr_x                                              0xDF1E64
#define pinstCDisplay_x                                            0xEA661C
#define pinstCEverQuest_x                                          0xF5B19C
#define pinstEverQuestInfo_x                                       0xEB4308
#define pinstCharData_x                                            0xEA674C
#define pinstCharSpawn_x                                           0xEA6A54
#define pinstControlledMissile_x                                   0xEA6D0C
#define pinstControlledPlayer_x                                    0xEA6A54
#define pinstCResolutionHandler_x                                  0x15EB0D8
#define pinstCSidlManager_x                                        0x15EA070
#define pinstCXWndManager_x                                        0x15EA06C
#define instDynamicZone_x                                          0xEAAA58
#define pinstDZMember_x                                            0xEAAB68
#define pinstDZTimerInfo_x                                         0xEAAB6C
#define pinstEqLogin_x                                             0xF5B228
#define instEQMisc_x                                               0xDF1DA8
#define pinstEQSoundManager_x                                      0xDF4118
#define pinstEQSpellStrings_x                                      0xCB4868
#define instExpeditionLeader_x                                     0xEAAAA2
#define instExpeditionName_x                                       0xEAAAE2
#define pinstGroup_x                                               0xEA6766
#define pinstImeManager_x                                          0x15EA068
#define pinstLocalPlayer_x                                         0xEA697C
#define pinstMercenaryData_x                                       0xF5568C
#define pinstMercenaryStats_x                                      0xF6E634
#define pinstModelPlayer_x                                         0xEA6994
#define pinstPCData_x                                              0xEA674C
#define pinstSkillMgr_x                                            0xF577F0
#define pinstSpawnManager_x                                        0xF56298
#define pinstSpellManager_x                                        0xF57A10
#define pinstSpellSets_x                                           0xF4BCDC
#define pinstStringTable_x                                         0xEA6750
#define pinstSwitchManager_x                                       0xEA44B8
#define pinstTarget_x                                              0xEA6A50
#define pinstTargetObject_x                                        0xEA6A5C
#define pinstTargetSwitch_x                                        0xEA4614
#define pinstTaskMember_x                                          0xDF1C38
#define pinstTrackTarget_x                                         0xEA6A58
#define pinstTradeTarget_x                                         0xEA6990
#define instTributeActive_x                                        0xDF1DC9
#define pinstViewActor_x                                           0xDF1F34
#define pinstWorldData_x                                           0xEA4608
#define pinstZoneAddr_x                                            0xEB4888
#define pinstPlayerPath_x                                          0xF56330
#define pinstTargetIndicator_x                                     0xF57C78
#define EQObject_Top_x                                             0xEA6978
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDF21F8
#define pinstCAchievementsWnd_x                                    0xDF1F90
#define pinstCActionsWnd_x                                         0xDF1FBC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDF276C
#define pinstCAdvancedLootWnd_x                                    0xDF2338
#define pinstCAdventureLeaderboardWnd_x                            0xF65308
#define pinstCAdventureRequestWnd_x                                0xF653B8
#define pinstCAdventureStatsWnd_x                                  0xF65468
#define pinstCAggroMeterWnd_x                                      0xDF1F28
#define pinstCAlarmWnd_x                                           0xDF2278
#define pinstCAlertHistoryWnd_x                                    0xDF22CC
#define pinstCAlertStackWnd_x                                      0xDF2210
#define pinstCAlertWnd_x                                           0xDF2224
#define pinstCAltStorageWnd_x                                      0xF657C8
#define pinstCAudioTriggersWindow_x                                0xCA6B98
#define pinstCAuraWnd_x                                            0xDF2798
#define pinstCAvaZoneWnd_x                                         0xDF21FC
#define pinstCBandolierWnd_x                                       0xDF1F24
#define pinstCBankWnd_x                                            0xDF2794
#define pinstCBarterMerchantWnd_x                                  0xF66A08
#define pinstCBarterSearchWnd_x                                    0xF66AB8
#define pinstCBarterWnd_x                                          0xF66B68
#define pinstCBazaarConfirmationWnd_x                              0xDF1FC8
#define pinstCBazaarSearchWnd_x                                    0xDF1F84
#define pinstCBazaarWnd_x                                          0xDF2250
#define pinstCBlockedBuffWnd_x                                     0xDF1F00
#define pinstCBlockedPetBuffWnd_x                                  0xDF1F20
#define pinstCBodyTintWnd_x                                        0xDF1FD0
#define pinstCBookWnd_x                                            0xDF1F64
#define pinstCBreathWnd_x                                          0xDF221C
#define pinstCBuffWindowNORMAL_x                                   0xDF2784
#define pinstCBuffWindowSHORT_x                                    0xDF2788
#define pinstCBugReportWnd_x                                       0xDF2790
#define pinstCButtonWnd_x                                          0x15EA2D8
#define pinstCCastingWnd_x                                         0xDF1F54
#define pinstCCastSpellWnd_x                                       0xDF2214
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDF2258
#define pinstCChatWindowManager_x                                  0xF67628
#define pinstCClaimWnd_x                                           0xF67780
#define pinstCColorPickerWnd_x                                     0xDF1FC4
#define pinstCCombatAbilityWnd_x                                   0xDF2264
#define pinstCCombatSkillsSelectWnd_x                              0xDF22A4
#define pinstCCompassWnd_x                                         0xDF1FC0
#define pinstCConfirmationDialog_x                                 0xF6C680
#define pinstCContainerMgr_x                                       0xDF2248
#define pinstCContextMenuManager_x                                 0x15EA028
#define pinstCCursorAttachment_x                                   0xDF1F30
#define pinstCDynamicZoneWnd_x                                     0xF67D48
#define pinstCEditLabelWnd_x                                       0xDF2778
#define pinstCEQMainWnd_x                                          0xF67F90
#define pinstCEventCalendarWnd_x                                   0xDF2780
#define pinstCExtendedTargetWnd_x                                  0xDF1F14
#define pinstCFacePick_x                                           0xDF22B4
#define pinstCFactionWnd_x                                         0xDF2240
#define pinstCFellowshipWnd_x                                      0xF68190
#define pinstCFileSelectionWnd_x                                   0xDF1F50
#define pinstCFindItemWnd_x                                        0xDF2230
#define pinstCFindLocationWnd_x                                    0xF682E8
#define pinstCFriendsWnd_x                                         0xDF2334
#define pinstCGemsGameWnd_x                                        0xDF223C
#define pinstCGiveWnd_x                                            0xDF227C
#define pinstCGroupSearchFiltersWnd_x                              0xDF1F5C
#define pinstCGroupSearchWnd_x                                     0xF686E0
#define pinstCGroupWnd_x                                           0xF68790
#define pinstCGuildBankWnd_x                                       0xEB56CC
#define pinstCGuildCreationWnd_x                                   0xF688F0
#define pinstCGuildMgmtWnd_x                                       0xF689A0
#define pinstCharacterCreation_x                                   0xDF22AC
#define pinstCHelpWnd_x                                            0xDF2764
#define pinstCHeritageSelectionWnd_x                               0xDF2740
#define pinstCHotButtonWnd_x                                       0xF6AAF8
#define pinstCHotButtonWnd1_x                                      0xF6AAF8
#define pinstCHotButtonWnd2_x                                      0xF6AAFC
#define pinstCHotButtonWnd3_x                                      0xF6AB00
#define pinstCHotButtonWnd4_x                                      0xF6AB04
#define pinstCIconSelectionWnd_x                                   0xDF1F2C
#define pinstCInspectWnd_x                                         0xDF2760
#define pinstCInventoryWnd_x                                       0xDF2744
#define pinstCInvSlotMgr_x                                         0xDF1FF4
#define pinstCItemDisplayManager_x                                 0xF6B088
#define pinstCItemExpTransferWnd_x                                 0xF6B1BC
#define pinstCItemOverflowWnd_x                                    0xDF1F8C
#define pinstCJournalCatWnd_x                                      0xDF1F6C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDF1F18
#define pinstCKeyRingWnd_x                                         0xDF2774
#define pinstCLargeDialogWnd_x                                     0xF6D300
#define pinstCLayoutCopyWnd_x                                      0xF6B508
#define pinstCLFGuildWnd_x                                         0xF6B5B8
#define pinstCLoadskinWnd_x                                        0xDF224C
#define pinstCLootFiltersCopyWnd_x                                 0xCC3140
#define pinstCLootFiltersWnd_x                                     0xDF2218
#define pinstCLootSettingsWnd_x                                    0xDF222C
#define pinstCLootWnd_x                                            0xDF1F70
#define pinstCMailAddressBookWnd_x                                 0xDF2204
#define pinstCMailCompositionWnd_x                                 0xDF1FE4
#define pinstCMailIgnoreListWnd_x                                  0xDF2208
#define pinstCMailWnd_x                                            0xDF1FB8
#define pinstCManageLootWnd_x                                      0xDF35F8
#define pinstCMapToolbarWnd_x                                      0xDF2768
#define pinstCMapViewWnd_x                                         0xDF2750
#define pinstCMarketplaceWnd_x                                     0xDF2220
#define pinstCMerchantWnd_x                                        0xDF1F74
#define pinstCMIZoneSelectWnd_x                                    0xF6BDF0
#define pinstCMusicPlayerWnd_x                                     0xDF1F7C
#define pinstCNameChangeMercWnd_x                                  0xDF1FB4
#define pinstCNameChangePetWnd_x                                   0xDF1F94
#define pinstCNameChangeWnd_x                                      0xDF1FDC
#define pinstCNoteWnd_x                                            0xDF2754
#define pinstCObjectPreviewWnd_x                                   0xDF2228
#define pinstCOptionsWnd_x                                         0xDF2758
#define pinstCPetInfoWnd_x                                         0xDF1F98
#define pinstCPetitionQWnd_x                                       0xDF1F80
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDF1FD4
#define pinstCPlayerWnd_x                                          0xDF1F9C
#define pinstCPopupWndManager_x                                    0xF6C680
#define pinstCProgressionSelectionWnd_x                            0xF6C730
#define pinstCPurchaseGroupWnd_x                                   0xDF2294
#define pinstCPurchaseWnd_x                                        0xDF2244
#define pinstCPvPLeaderboardWnd_x                                  0xF6C7E0
#define pinstCPvPStatsWnd_x                                        0xF6C890
#define pinstCQuantityWnd_x                                        0xDF1F1C
#define pinstCRaceChangeWnd_x                                      0xDF2200
#define pinstCRaidOptionsWnd_x                                     0xDF1F60
#define pinstCRaidWnd_x                                            0xDF1FE8
#define pinstCRealEstateItemsWnd_x                                 0xDF1F88
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDF1F08
#define pinstCRealEstateManageWnd_x                                0xDF229C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDF22B8
#define pinstCRealEstatePlotSearchWnd_x                            0xDF2748
#define pinstCRealEstatePurchaseWnd_x                              0xDF275C
#define pinstCRespawnWnd_x                                         0xDF1F0C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDF220C
#define pinstCSendMoneyWnd_x                                       0xDF22A0
#define pinstCServerListWnd_x                                      0xDF277C
#define pinstCSkillsSelectWnd_x                                    0xDF225C
#define pinstCSkillsWnd_x                                          0xDF2234
#define pinstCSocialEditWnd_x                                      0xDF2770
#define pinstCSocialWnd_x                                          0xDF1FAC
#define pinstCSpellBookWnd_x                                       0xDF2260
#define pinstCStoryWnd_x                                           0xDF1FA0
#define pinstCTargetOfTargetWnd_x                                  0xF6E6B8
#define pinstCTargetWnd_x                                          0xDF1F04
#define pinstCTaskOverlayWnd_x                                     0xDF2290
#define pinstCTaskSelectWnd_x                                      0xF6E810
#define pinstCTaskManager_x                                        0xCC3A80
#define pinstCTaskTemplateSelectWnd_x                              0xF6E8C0
#define pinstCTaskWnd_x                                            0xF6E970
#define pinstCTextEntryWnd_x                                       0xDF278C
#define pinstCTimeLeftWnd_x                                        0xDF1F58
#define pinstCTipWndCONTEXT_x                                      0xF6EB74
#define pinstCTipWndOFDAY_x                                        0xF6EB70
#define pinstCTitleWnd_x                                           0xF6EC20
#define pinstCTrackingWnd_x                                        0xDF274C
#define pinstCTradeskillWnd_x                                      0xF6ED88
#define pinstCTradeWnd_x                                           0xDF1FE0
#define pinstCTrainWnd_x                                           0xDF1FD8
#define pinstCTributeBenefitWnd_x                                  0xF6EF88
#define pinstCTributeMasterWnd_x                                   0xF6F038
#define pinstCTributeTrophyWnd_x                                   0xF6F0E8
#define pinstCVideoModesWnd_x                                      0xDF1FEC
#define pinstCVoiceMacroWnd_x                                      0xF583E0
#define pinstCVoteResultsWnd_x                                     0xDF1F78
#define pinstCVoteWnd_x                                            0xDF1F68
#define pinstCWebManager_x                                         0xF58A5C
#define pinstCZoneGuideWnd_x                                       0xDF2298
#define pinstCZonePathWnd_x                                        0xDF22A8

#define pinstEQSuiteTextureLoader_x                                0xC91088
#define pinstItemIconCache_x                                       0xF67F48
#define pinstLootFiltersManager_x                                  0xCC31F0
#define pinstRewardSelectionWnd_x                                  0xF6CFD8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5A5E80
#define __CastRay2_x                                               0x5A5ED0
#define __ConvertItemTags_x                                        0x5C1A30
#define __CleanItemTags_x                                          0x47D0A0
#define __DoesFileExist_x                                          0x8F96A0
#define __EQGetTime_x                                              0x8F60E0
#define __ExecuteCmd_x                                             0x59E6D0
#define __FixHeading_x                                             0x98FEE0
#define __GameLoop_x                                               0x6B24F0
#define __get_bearing_x                                            0x5A59F0
#define __get_melee_range_x                                        0x5A60C0
#define __GetAnimationCache_x                                      0x717710
#define __GetGaugeValueFromEQ_x                                    0x809B70
#define __GetLabelFromEQ_x                                         0x80B650
#define __GetXTargetType_x                                         0x991A10
#define __HandleMouseWheel_x                                       0x6B33B0
#define __HeadingDiff_x                                            0x98FF50
#define __HelpPath_x                                               0xF53784
#define __LoadFrontEnd_x                                           0x6AF810
#define __NewUIINI_x                                               0x809840
#define __ProcessGameEvents_x                                      0x605FD0
#define __ProcessMouseEvent_x                                      0x605790
#define __SaveColors_x                                             0x54C220
#define __STMLToText_x                                             0x933490
#define __ToggleKeyRingItem_x                                      0x50F970
#define CMemoryMappedFile__SetFile_x                               0xA7F290
#define CrashDetected_x                                            0x6B12B0
#define DrawNetStatus_x                                            0x631E90
#define Expansion_HoT_x                                            0xEB56D4
#define Teleport_Table_Size_x                                      0xEA6ABC
#define Teleport_Table_x                                           0xEA4618
#define Util__FastTime_x                                           0x8F5CB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490340
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499250
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499020
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4938E0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D30

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x553D50
#define AltAdvManager__IsAbilityReady_x                            0x552CC0
#define AltAdvManager__GetAAById_x                                 0x552EC0
#define AltAdvManager__CanTrainAbility_x                           0x552F30
#define AltAdvManager__CanSeeAbility_x                             0x553290

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9D40
#define CharacterZoneClient__HasSkill_x                            0x4D4C30
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6350
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE160
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA760
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8CD0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8DB0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8E90
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2E10
#define CharacterZoneClient__BardCastBard_x                        0x4C5970
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA830
#define CharacterZoneClient__GetEffect_x                           0x4BA6A0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3E60
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3F30
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3F80
#define CharacterZoneClient__CalcAffectChange_x                    0x4C40D0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C42A0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B26A0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D72B0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6D30

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8FB0
#define CBankWnd__WndNotification_x                                0x6D8D90

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6870

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x614900
#define CButtonWnd__CButtonWnd_x                                   0x92F860

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706870
#define CChatManager__InitContextMenu_x                            0x6FF9D0
#define CChatManager__FreeChatWindow_x                             0x7053B0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8370
#define CChatManager__SetLockedActiveChatWindow_x                  0x7064F0
#define CChatManager__CreateChatWindow_x                           0x7059F0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8480

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x943EB0
#define CContextMenu__dCContextMenu_x                              0x9440E0
#define CContextMenu__AddMenuItem_x                                0x9440F0
#define CContextMenu__RemoveMenuItem_x                             0x944400
#define CContextMenu__RemoveAllMenuItems_x                         0x944420
#define CContextMenu__CheckMenuItem_x                              0x9444A0
#define CContextMenu__SetMenuItem_x                                0x944320
#define CContextMenu__AddSeparator_x                               0x944280

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x944A40
#define CContextMenuManager__RemoveMenu_x                          0x944AB0
#define CContextMenuManager__PopupMenu_x                           0x944B70
#define CContextMenuManager__Flush_x                               0x9449E0
#define CContextMenuManager__GetMenu_x                             0x49B470
#define CContextMenuManager__CreateDefaultMenu_x                   0x711ED0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D2FD0
#define CChatService__GetFriendName_x                              0x8D2FE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7070E0
#define CChatWindow__Clear_x                                       0x7083A0
#define CChatWindow__WndNotification_x                             0x708B30
#define CChatWindow__AddHistory_x                                  0x707C60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x941320
#define CComboWnd__Draw_x                                          0x940820
#define CComboWnd__GetCurChoice_x                                  0x941160
#define CComboWnd__GetListRect_x                                   0x940CD0
#define CComboWnd__GetTextRect_x                                   0x941390
#define CComboWnd__InsertChoice_x                                  0x940E60
#define CComboWnd__SetColors_x                                     0x940E30
#define CComboWnd__SetChoice_x                                     0x941130
#define CComboWnd__GetItemCount_x                                  0x941170
#define CComboWnd__GetCurChoiceText_x                              0x9411B0
#define CComboWnd__GetChoiceText_x                                 0x941180
#define CComboWnd__InsertChoiceAtIndex_x                           0x940EF0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70F8C0
#define CContainerWnd__vftable_x                                   0xB04B4C
#define CContainerWnd__SetContainer_x                              0x710E20

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x546C60
#define CDisplay__PreZoneMainUI_x                                  0x546C70
#define CDisplay__CleanGameUI_x                                    0x54BFE0
#define CDisplay__GetClickedActor_x                                0x53EF80
#define CDisplay__GetUserDefinedColor_x                            0x537640
#define CDisplay__GetWorldFilePath_x                               0x5409F0
#define CDisplay__is3dON_x                                         0x53BBE0
#define CDisplay__ReloadUI_x                                       0x5460F0
#define CDisplay__WriteTextHD2_x                                   0x53B9D0
#define CDisplay__TrueDistance_x                                   0x5426B0
#define CDisplay__SetViewActor_x                                   0x53E8A0
#define CDisplay__GetFloorHeight_x                                 0x53BCA0
#define CDisplay__SetRenderWindow_x                                0x53A600
#define CDisplay__ToggleScreenshotMode_x                           0x53E370

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x963AF0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x947400
#define CEditWnd__GetCharIndexPt_x                                 0x948330
#define CEditWnd__GetDisplayString_x                               0x9481D0
#define CEditWnd__GetHorzOffset_x                                  0x946A40
#define CEditWnd__GetLineForPrintableChar_x                        0x9494D0
#define CEditWnd__GetSelStartPt_x                                  0x9485E0
#define CEditWnd__GetSTMLSafeText_x                                0x947FF0
#define CEditWnd__PointFromPrintableChar_x                         0x949100
#define CEditWnd__SelectableCharFromPoint_x                        0x949270
#define CEditWnd__SetEditable_x                                    0x9486B0
#define CEditWnd__SetWindowTextA_x                                 0x947D70

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5F3C40
#define CEverQuest__ClickedPlayer_x                                0x5E5C60
#define CEverQuest__CreateTargetIndicator_x                        0x603270
#define CEverQuest__DeleteTargetIndicator_x                        0x603300
#define CEverQuest__DoTellWindow_x                                 0x4E8560
#define CEverQuest__OutputTextToLog_x                              0x4E87E0
#define CEverQuest__DropHeldItemOnGround_x                         0x5DACA0
#define CEverQuest__dsp_chat_x                                     0x4E8B70
#define CEverQuest__trimName_x                                     0x5FF550
#define CEverQuest__Emote_x                                        0x5F44A0
#define CEverQuest__EnterZone_x                                    0x5EE420
#define CEverQuest__GetBodyTypeDesc_x                              0x5F8E10
#define CEverQuest__GetClassDesc_x                                 0x5F9450
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F9A50
#define CEverQuest__GetDeityDesc_x                                 0x601BB0
#define CEverQuest__GetLangDesc_x                                  0x5F9C10
#define CEverQuest__GetRaceDesc_x                                  0x5F9430
#define CEverQuest__InterpretCmd_x                                 0x602180
#define CEverQuest__LeftClickedOnPlayer_x                          0x5DEEA0
#define CEverQuest__LMouseUp_x                                     0x5DD230
#define CEverQuest__RightClickedOnPlayer_x                         0x5DF780
#define CEverQuest__RMouseUp_x                                     0x5DE1B0
#define CEverQuest__SetGameState_x                                 0x5DAA30
#define CEverQuest__UPCNotificationFlush_x                         0x5FF450
#define CEverQuest__IssuePetCommand_x                              0x5FB010
#define CEverQuest__ReportSuccessfulHit_x                          0x5F5890

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7217F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x721850
#define CGaugeWnd__Draw_x                                          0x720E70

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF140
#define CGuild__GetGuildName_x                                     0x4AE220
#define CGuild__GetGuildIndex_x                                    0x4AE5B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73CC40

//CHotButton
#define CHotButton__SetButtonSize_x                                0x614CC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x749BE0
#define CInvSlotMgr__MoveItem_x                                    0x748950
#define CInvSlotMgr__SelectSlot_x                                  0x749CB0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7471D0
#define CInvSlot__SliderComplete_x                                 0x744F30
#define CInvSlot__GetItemBase_x                                    0x7448D0
#define CInvSlot__UpdateItem_x                                     0x744A40

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74B720
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74A8D0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74B2A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x804DF0
#define CItemDisplayWnd__UpdateStrings_x                           0x759C00
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7539F0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x753EF0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75A1F0
#define CItemDisplayWnd__AboutToShow_x                             0x759860
#define CItemDisplayWnd__WndNotification_x                         0x75B2D0
#define CItemDisplayWnd__RequestConvertItem_x                      0x75AD90
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7588C0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x759680

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x83D940

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75F7C0

// CLabel 
#define CLabel__Draw_x                                             0x765270

// CListWnd
#define CListWnd__CListWnd_x                                       0x919AE0
#define CListWnd__dCListWnd_x                                      0x919E00
#define CListWnd__AddColumn_x                                      0x91E240
#define CListWnd__AddColumn1_x                                     0x91E290
#define CListWnd__AddLine_x                                        0x91E620
#define CListWnd__AddString_x                                      0x91E420
#define CListWnd__CalculateFirstVisibleLine_x                      0x91E010
#define CListWnd__CalculateVSBRange_x                              0x91DE00
#define CListWnd__ClearSel_x                                       0x91EE00
#define CListWnd__ClearAllSel_x                                    0x91EE60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91F860
#define CListWnd__Compare_x                                        0x91D740
#define CListWnd__Draw_x                                           0x919F30
#define CListWnd__DrawColumnSeparators_x                           0x91C710
#define CListWnd__DrawHeader_x                                     0x91CB80
#define CListWnd__DrawItem_x                                       0x91D080
#define CListWnd__DrawLine_x                                       0x91C880
#define CListWnd__DrawSeparator_x                                  0x91C7B0
#define CListWnd__EnableLine_x                                     0x91BFF0
#define CListWnd__EnsureVisible_x                                  0x91F790
#define CListWnd__ExtendSel_x                                      0x91ED30
#define CListWnd__GetColumnTooltip_x                               0x91BB30
#define CListWnd__GetColumnMinWidth_x                              0x91BBA0
#define CListWnd__GetColumnWidth_x                                 0x91BAA0
#define CListWnd__GetCurSel_x                                      0x91B430
#define CListWnd__GetItemAtPoint_x                                 0x91C260
#define CListWnd__GetItemAtPoint1_x                                0x91C2D0
#define CListWnd__GetItemData_x                                    0x91B4B0
#define CListWnd__GetItemHeight_x                                  0x91B870
#define CListWnd__GetItemIcon_x                                    0x91B640
#define CListWnd__GetItemRect_x                                    0x91C0E0
#define CListWnd__GetItemText_x                                    0x91B4F0
#define CListWnd__GetSelList_x                                     0x91EEB0
#define CListWnd__GetSeparatorRect_x                               0x91C510
#define CListWnd__InsertLine_x                                     0x91EA10
#define CListWnd__RemoveLine_x                                     0x91EB60
#define CListWnd__SetColors_x                                      0x91DDE0
#define CListWnd__SetColumnJustification_x                         0x91DB10
#define CListWnd__SetColumnWidth_x                                 0x91DA30
#define CListWnd__SetCurSel_x                                      0x91EC70
#define CListWnd__SetItemColor_x                                   0x91F450
#define CListWnd__SetItemData_x                                    0x91F410
#define CListWnd__SetItemText_x                                    0x91F020
#define CListWnd__ShiftColumnSeparator_x                           0x91DBD0
#define CListWnd__Sort_x                                           0x91D8C0
#define CListWnd__ToggleSel_x                                      0x91ECA0
#define CListWnd__SetColumnsSizable_x                              0x91DC80
#define CListWnd__SetItemWnd_x                                     0x91F2D0
#define CListWnd__GetItemWnd_x                                     0x91B690
#define CListWnd__SetItemIcon_x                                    0x91F0A0
#define CListWnd__CalculateCustomWindowPositions_x                 0x91E100
#define CListWnd__SetVScrollPos_x                                  0x91DA10

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77A9E0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7790F0
#define CMapViewWnd__HandleLButtonDown_x                           0x776130

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79ABD0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79B4B0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79B9E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79E950
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x799740
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A44F0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79A7E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A09D0
#define CPacketScrambler__hton_x                                   0x8A09C0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x938AC0
#define CSidlManager__FindScreenPieceTemplate_x                    0x938ED0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x938CC0
#define CSidlManager__CreateLabel_x                                0x7FC250
#define CSidlManager__CreateXWndFromTemplate_x                     0x93BE30
#define CSidlManager__CreateXWndFromTemplate1_x                    0x93C000
#define CSidlManager__CreateXWnd_x                                 0x7FC180
#define CSidlManager__CreateHotButtonWnd_x                         0x7FC730

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9355B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9354B0
#define CSidlScreenWnd__ConvertToRes_x                             0x95AAD0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x934F50
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x934C40
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x934D10
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x934DE0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x935A40
#define CSidlScreenWnd__EnableIniStorage_x                         0x935F10
#define CSidlScreenWnd__GetSidlPiece_x                             0x935C30
#define CSidlScreenWnd__Init1_x                                    0x934840
#define CSidlScreenWnd__LoadIniInfo_x                              0x935F60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x936AA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x933C40
#define CSidlScreenWnd__StoreIniInfo_x                             0x936620
#define CSidlScreenWnd__StoreIniVis_x                              0x936980
#define CSidlScreenWnd__WndNotification_x                          0x935950
#define CSidlScreenWnd__GetChildItem_x                             0x935E90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9256A0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15E9EF8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x679340
#define CSkillMgr__GetSkillCap_x                                   0x679520
#define CSkillMgr__GetNameToken_x                                  0x678AC0
#define CSkillMgr__IsActivatedSkill_x                              0x678C00
#define CSkillMgr__IsCombatSkill_x                                 0x678B40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x945820
#define CSliderWnd__SetValue_x                                     0x945690
#define CSliderWnd__SetNumTicks_x                                  0x9456F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x802270

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94E000
#define CStmlWnd__CalculateHSBRange_x                              0x94F160
#define CStmlWnd__CalculateVSBRange_x                              0x94F0E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x953480
#define CStmlWnd__FastForwardToEndOfTag_x                          0x954110
#define CStmlWnd__ForceParseNow_x                                  0x94E640
#define CStmlWnd__GetNextTagPiece_x                                0x9533E0
#define CStmlWnd__GetSTMLText_x                                    0x4FF420
#define CStmlWnd__GetVisibleText_x                                 0x94E660
#define CStmlWnd__InitializeWindowVariables_x                      0x953F60
#define CStmlWnd__MakeStmlColorTag_x                               0x94D670
#define CStmlWnd__MakeWndNotificationTag_x                         0x94D6E0
#define CStmlWnd__SetSTMLText_x                                    0x94C720
#define CStmlWnd__StripFirstSTMLLines_x                            0x955200
#define CStmlWnd__UpdateHistoryString_x                            0x954320

// CTabWnd 
#define CTabWnd__Draw_x                                            0x94B870
#define CTabWnd__DrawCurrentPage_x                                 0x94BFA0
#define CTabWnd__DrawTab_x                                         0x94BCC0
#define CTabWnd__GetCurrentPage_x                                  0x94B080
#define CTabWnd__GetPageInnerRect_x                                0x94B2C0
#define CTabWnd__GetTabInnerRect_x                                 0x94B200
#define CTabWnd__GetTabRect_x                                      0x94B0B0
#define CTabWnd__InsertPage_x                                      0x94B4D0
#define CTabWnd__SetPage_x                                         0x94B340
#define CTabWnd__SetPageRect_x                                     0x94B7B0
#define CTabWnd__UpdatePage_x                                      0x94BB80
#define CTabWnd__GetPageFromTabIndex_x                             0x94BC00
#define CTabWnd__GetCurrentTabIndex_x                              0x94B070

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75FC00
#define CPageWnd__SetTabText_x                                     0x94ABD0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8E30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x922540
#define CTextureFont__GetTextExtent_x                              0x922700

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC6E0
#define CHtmlComponentWnd__ValidateUri_x                           0x73E630
#define CHtmlWnd__SetClientCallbacks_x                             0x619D20
#define CHtmlWnd__AddObserver_x                                    0x619D40
#define CHtmlWnd__RemoveObserver_x                                 0x619DA0
#define Window__getProgress_x                                      0x855ED0
#define Window__getStatus_x                                        0x855EF0
#define Window__getURI_x                                           0x855F00

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x960580

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90F7D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E81B0
#define CXStr__CXStr1_x                                            0x4FA5F0
#define CXStr__CXStr3_x                                            0x8F2220
#define CXStr__dCXStr_x                                            0x478670
#define CXStr__operator_equal_x                                    0x8F2450
#define CXStr__operator_equal1_x                                   0x8F2490
#define CXStr__operator_plus_equal1_x                              0x8F2F20
#define CXStr__SetString_x                                         0x8F4E10
#define CXStr__operator_char_p_x                                   0x8F2960
#define CXStr__GetChar_x                                           0x8F4760
#define CXStr__Delete_x                                            0x8F4010
#define CXStr__GetUnicode_x                                        0x8F47D0
#define CXStr__GetLength_x                                         0x47D450
#define CXStr__Mid_x                                               0x47D460
#define CXStr__Insert_x                                            0x8F4830
#define CXStr__FindNext_x                                          0x8F4480

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x943AD0
#define CXWnd__BringToTop_x                                        0x928E00
#define CXWnd__Center_x                                            0x928980
#define CXWnd__ClrFocus_x                                          0x9287A0
#define CXWnd__Destroy_x                                           0x928840
#define CXWnd__DoAllDrawing_x                                      0x924E50
#define CXWnd__DrawChildren_x                                      0x924E20
#define CXWnd__DrawColoredRect_x                                   0x925290
#define CXWnd__DrawTooltip_x                                       0x923980
#define CXWnd__DrawTooltipAtPoint_x                                0x923A40
#define CXWnd__GetBorderFrame_x                                    0x9250F0
#define CXWnd__GetChildWndAt_x                                     0x928EA0
#define CXWnd__GetClientClipRect_x                                 0x9270E0
#define CXWnd__GetScreenClipRect_x                                 0x9271B0
#define CXWnd__GetScreenRect_x                                     0x927340
#define CXWnd__GetTooltipRect_x                                    0x9252E0
#define CXWnd__GetWindowTextA_x                                    0x49CB70
#define CXWnd__IsActive_x                                          0x925A10
#define CXWnd__IsDescendantOf_x                                    0x927CF0
#define CXWnd__IsReallyVisible_x                                   0x927D20
#define CXWnd__IsType_x                                            0x929500
#define CXWnd__Move_x                                              0x927D90
#define CXWnd__Move1_x                                             0x927E40
#define CXWnd__ProcessTransition_x                                 0x928930
#define CXWnd__Refade_x                                            0x928110
#define CXWnd__Resize_x                                            0x9283B0
#define CXWnd__Right_x                                             0x928BC0
#define CXWnd__SetFocus_x                                          0x928760
#define CXWnd__SetFont_x                                           0x9287D0
#define CXWnd__SetKeyTooltip_x                                     0x929320
#define CXWnd__SetMouseOver_x                                      0x926270
#define CXWnd__StartFade_x                                         0x927BE0
#define CXWnd__GetChildItem_x                                      0x929010
#define CXWnd__SetParent_x                                         0x927AE0
#define CXWnd__Minimize_x                                          0x928420

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95BB50

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x92BDD0
#define CXWndManager__DrawWindows_x                                0x92BDF0
#define CXWndManager__GetKeyboardFlags_x                           0x92E4F0
#define CXWndManager__HandleKeyboardMsg_x                          0x92E0B0
#define CXWndManager__RemoveWnd_x                                  0x92E740
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92EC90

// CDBStr
#define CDBStr__GetString_x                                        0x536600

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB740
#define EQ_Character__Cur_HP_x                                     0x4D1C70
#define EQ_Character__Cur_Mana_x                                   0x4D9390
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE7B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B22E0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2430
#define EQ_Character__GetHPRegen_x                                 0x4DF130
#define EQ_Character__GetEnduranceRegen_x                          0x4DF730
#define EQ_Character__GetManaRegen_x                               0x4DFB70
#define EQ_Character__Max_Endurance_x                              0x63FA00
#define EQ_Character__Max_HP_x                                     0x4D1AA0
#define EQ_Character__Max_Mana_x                                   0x63F800
#define EQ_Character__doCombatAbility_x                            0x641E50
#define EQ_Character__UseSkill_x                                   0x4E1940
#define EQ_Character__GetConLevel_x                                0x638DF0
#define EQ_Character__IsExpansionFlag_x                            0x59CEB0
#define EQ_Character__TotalEffect_x                                0x4C50B0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF3C0
#define EQ_Character__SpellDuration_x                              0x4BEEF0
#define EQ_Character__GetAdjustedSkill_x                           0x4D49F0
#define EQ_Character__GetBaseSkill_x                               0x4D5990
#define EQ_Character__CanUseItem_x                                 0x4D96A0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BFEF0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x655F70

//PcClient
#define PcClient__PcClient_x                                       0x636530

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B93E0
#define CCharacterListWnd__EnterWorld_x                            0x4B8E20
#define CCharacterListWnd__Quit_x                                  0x4B8B70
#define CCharacterListWnd__UpdateList_x                            0x4B8FB0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x61AF50
#define EQ_Item__CreateItemTagString_x                             0x89A240
#define EQ_Item__IsStackable_x                                     0x89ED70
#define EQ_Item__GetImageNum_x                                     0x89BC90
#define EQ_Item__CreateItemClient_x                                0x61A120
#define EQ_Item__GetItemValue_x                                    0x89CF80
#define EQ_Item__ValueSellMerchant_x                               0x8A05A0
#define EQ_Item__IsKeyRingItem_x                                   0x89E6A0
#define EQ_Item__CanGoInBag_x                                      0x61B070
#define EQ_Item__IsEmpty_x                                         0x89E1E0
#define EQ_Item__GetMaxItemCount_x                                 0x89D390
#define EQ_Item__GetHeldItem_x                                     0x89BB60
#define EQ_Item__GetAugmentFitBySlot_x                             0x899BD0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x554A20
#define EQ_LoadingS__Array_x                                       0xC18B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x640360
#define EQ_PC__GetAlternateAbilityId_x                             0x8A97F0
#define EQ_PC__GetCombatAbility_x                                  0x8A9E60
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A9ED0
#define EQ_PC__GetItemRecastTimer_x                                0x6423D0
#define EQ_PC__HasLoreItem_x                                       0x6395B0
#define EQ_PC__AlertInventoryChanged_x                             0x638730
#define EQ_PC__GetPcZoneClient_x                                   0x664970
#define EQ_PC__RemoveMyAffect_x                                    0x645600
#define EQ_PC__GetKeyRingItems_x                                   0x8AA760
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AA4F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AAA60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A3420
#define EQItemList__add_object_x                                   0x5D0420
#define EQItemList__add_item_x                                     0x5A3980
#define EQItemList__delete_item_x                                  0x5A39D0
#define EQItemList__FreeItemList_x                                 0x5A38D0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x533110

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6577F0
#define EQPlayer__dEQPlayer_x                                      0x64AB30
#define EQPlayer__DoAttack_x                                       0x65F640
#define EQPlayer__EQPlayer_x                                       0x64B1F0
#define EQPlayer__SetNameSpriteState_x                             0x64F4D0
#define EQPlayer__SetNameSpriteTint_x                              0x6503A0
#define PlayerBase__HasProperty_j_x                                0x98E270
#define EQPlayer__IsTargetable_x                                   0x98E710
#define EQPlayer__CanSee_x                                         0x98E570
#define EQPlayer__CanSee1_x                                        0x98E640
#define PlayerBase__GetVisibilityLineSegment_x                     0x98E330

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x662410
#define PlayerZoneClient__GetLevel_x                               0x6649B0
#define PlayerZoneClient__IsValidTeleport_x                        0x5D1590
#define PlayerZoneClient__LegalPlayerRace_x                        0x54DE40

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x65A550
#define EQPlayerManager__GetSpawnByName_x                          0x65A600
#define EQPlayerManager__GetPlayerFromPartialName_x                0x65A690

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x61E570
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x61E5F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x61E630
#define KeypressHandler__ClearCommandStateArray_x                  0x61FA40
#define KeypressHandler__HandleKeyDown_x                           0x61FA60
#define KeypressHandler__HandleKeyUp_x                             0x61FB00
#define KeypressHandler__SaveKeymapping_x                          0x61FF50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x776850
#define MapViewMap__SaveEx_x                                       0x779C10
#define MapViewMap__SetZoom_x                                      0x77E2C0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BDE10

// StringTable 
#define StringTable__getString_x                                   0x8B8AC0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x645270
#define PcZoneClient__RemovePetEffect_x                            0x6458A0
#define PcZoneClient__HasAlternateAbility_x                        0x63F630
#define PcZoneClient__GetCurrentMod_x                              0x4E4A00
#define PcZoneClient__GetModCap_x                                  0x4E4900
#define PcZoneClient__CanEquipItem_x                               0x63FD00
#define PcZoneClient__GetItemByID_x                                0x642840
#define PcZoneClient__GetItemByItemClass_x                         0x642990
#define PcZoneClient__RemoveBuffEffect_x                           0x6458C0
#define PcZoneClient__BandolierSwap_x                              0x640910
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x642370

//Doors
#define EQSwitch__UseSwitch_x                                      0x5D6100

//IconCache
#define IconCache__GetIcon_x                                       0x716FB0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70EA50
#define CContainerMgr__CloseContainer_x                            0x70ED20
#define CContainerMgr__OpenExperimentContainer_x                   0x70F7A0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CE9A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6130D0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76CD40
#define CLootWnd__RequestLootSlot_x                                0x76BF70

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5708D0
#define EQ_Spell__SpellAffects_x                                   0x570D40
#define EQ_Spell__SpellAffectBase_x                                0x570B00
#define EQ_Spell__IsStackable_x                                    0x4C96A0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C94F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6790
#define EQ_Spell__IsSPAStacking_x                                  0x571B90
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5710A0
#define EQ_Spell__IsNoRemove_x                                     0x4C9680
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x571BA0
#define __IsResEffectSpell_x                                       0x4C8A30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACE70

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C8470

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x815610
#define CTargetWnd__WndNotification_x                              0x814EA0
#define CTargetWnd__RefreshTargetBuffs_x                           0x815170
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814010

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x819C20

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x530B50
#define CTaskManager__HandleMessage_x                              0x52EFE0
#define CTaskManager__GetTaskStatus_x                              0x530C00
#define CTaskManager__GetElementDescription_x                      0x530C80

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x56BE40
#define EqSoundManager__PlayScriptMp3_x                            0x56BFA0
#define EqSoundManager__SoundAssistPlay_x                          0x67D2B0
#define EqSoundManager__WaveInstancePlay_x                         0x67C820

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x524800

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x94A0E0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55C4B0
#define CAltAbilityData__GetMercMaxRank_x                          0x55C440
#define CAltAbilityData__GetMaxRank_x                              0x551B80

//CTargetRing
#define CTargetRing__Cast_x                                        0x6111F0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C94D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x50BFC0
#define CharacterBase__CreateItemIndex_x                           0x6192D0
#define CharacterBase__GetItemPossession_x                         0x4F7F10
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D0A60
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D0AC0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5C10
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6440
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F64F0

//messages
#define msg_spell_worn_off_x                                       0x595030
#define msg_new_text_x                                             0x589E00
#define __msgTokenTextParam_x                                      0x597550
#define msgTokenText_x                                             0x5977A0

//SpellManager
#define SpellManager__vftable_x                                    0xADEF34
#define SpellManager__SpellManager_x                               0x6805D0
#define Spellmanager__LoadTextSpells_x                             0x680EC0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6807A0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x992300

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50C650
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x59B310
#define ItemGlobalIndex__IsEquippedLocation_x                      0x631CF0
#define ItemGlobalIndex__IsValidIndex_x                            0x50C6B0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C8E10
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C9090

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7655B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x713180
#define CCursorAttachment__AttachToCursor1_x                       0x7131C0
#define CCursorAttachment__Deactivate_x                            0x7141B0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x93CE20
#define CSidlManagerBase__CreatePageWnd_x                          0x93C630
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9388E0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x938870

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x95A0B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x959D70

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x509560
#define CFindItemWnd__WndNotification_x                            0x50A040
#define CFindItemWnd__Update_x                                     0x50AB80
#define CFindItemWnd__PickupSelectedItem_x                         0x508DB0

//IString
#define IString__Append_x                                          0x4F9700

//Camera
#define CDisplay__cameraType_x                                     0xDF1FF0
#define EverQuest__Cameras_x                                       0xEB5A24

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x511CC0
#define LootFiltersManager__GetItemFilterData_x                    0x5115C0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5115F0
#define LootFiltersManager__SetItemLootFilter_x                    0x511810

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BC9B0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x997EB0
#define CResolutionHandler__GetWindowedStyle_x                     0x677C00

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70B830

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DC800
#define CDistillerInfo__Instance_x                                 0x8DC7A0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72B9F0
#define CGroupWnd__UpdateDisplay_x                                 0x72AD60

//ItemBase
#define ItemBase__IsLore_x                                         0x89E740
#define ItemBase__IsLoreEquipped_x                                 0x89E7B0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D0380
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D04C0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D0520

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x66D070
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6709F0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4FFA20

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4EE5F0
#define FactionManagerClient__HandleFactionMessage_x               0x4EEC60
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4EF260
#define FactionManagerClient__GetMaxFaction_x                      0x4EF27F
#define FactionManagerClient__GetMinFaction_x                      0x4EF230

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F7EE0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x921500

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE80

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F8110

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55B950

//CTargetManager
#define CTargetManager__Get_x                                      0x683E10

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x66D070

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8BF0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A3870

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF530B8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
