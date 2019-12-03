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
#define __ExpectedVersionDate                                     "Dec  3 2019"
#define __ExpectedVersionTime                                     "04:23:21"
#define __ActualVersionDate_x                                      0xB0B30C
#define __ActualVersionTime_x                                      0xB0B300
#define __ActualVersionBuild_x                                     0xAF6FD4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62EF60
#define __MemChecker1_x                                            0x902BF0
#define __MemChecker2_x                                            0x6BDC50
#define __MemChecker3_x                                            0x6BDBA0
#define __MemChecker4_x                                            0x8599C0
#define __EncryptPad0_x                                            0xC413E8
#define __EncryptPad1_x                                            0xC9F5E8
#define __EncryptPad2_x                                            0xC51C80
#define __EncryptPad3_x                                            0xC51880
#define __EncryptPad4_x                                            0xC8FC00
#define __EncryptPad5_x                                            0xF6B1C0
#define __AC1_x                                                    0x816596
#define __AC2_x                                                    0x5E8FBF
#define __AC3_x                                                    0x5F06BF
#define __AC4_x                                                    0x5F4690
#define __AC5_x                                                    0x5FA99F
#define __AC6_x                                                    0x5FEFB6
#define __AC7_x                                                    0x5E8A30
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191A2C

// Direct Input
#define DI8__Main_x                                                0xF6B1E8
#define DI8__Keyboard_x                                            0xF6B1EC
#define DI8__Mouse_x                                               0xF6B1CC
#define DI8__Mouse_Copy_x                                          0xEC43CC
#define DI8__Mouse_Check_x                                         0xF68D14
#define __AutoSkillArray_x                                         0xEC52E4
#define __Attack_x                                                 0xF6310B
#define __Autofire_x                                               0xF6310C
#define __BindList_x                                               0xC2FE20
#define g_eqCommandStates_x                                        0xC30BA0
#define __Clicks_x                                                 0xEC4484
#define __CommandList_x                                            0xC31760
#define __CurrentMapLabel_x                                        0xF7BB8C
#define __CurrentSocial_x                                          0xC197CC
#define __DoAbilityList_x                                          0xEFAC2C
#define __do_loot_x                                                0x5B4A80
#define __DrawHandler_x                                            0x15FAF00
#define __GroupCount_x                                             0xEB6D82
#define __Guilds_x                                                 0xEBABD8
#define __gWorld_x                                                 0xEB6BD0
#define __HWnd_x                                                   0xF6B1D0
#define __heqmain_x                                                0xF6B1A8
#define __InChatMode_x                                             0xEC43B4
#define __LastTell_x                                               0xEC6328
#define __LMouseHeldTime_x                                         0xEC44F0
#define __Mouse_x                                                  0xF6B1D4
#define __MouseLook_x                                              0xEC444A
#define __MouseEventTime_x                                         0xF63BEC
#define __gpbCommandEvent_x                                        0xEB4670
#define __NetStatusToggle_x                                        0xEC444D
#define __PCNames_x                                                0xEC58D4
#define __RangeAttackReady_x                                       0xEC55C8
#define __RMouseHeldTime_x                                         0xEC44EC
#define __RunWalkState_x                                           0xEC43B8
#define __ScreenMode_x                                             0xE02014
#define __ScreenX_x                                                0xEC436C
#define __ScreenY_x                                                0xEC4368
#define __ScreenXMax_x                                             0xEC4370
#define __ScreenYMax_x                                             0xEC4374
#define __ServerHost_x                                             0xEB48A3
#define __ServerName_x                                             0xEFABEC
#define __ShiftKeyDown_x                                           0xEC4A44
#define __ShowNames_x                                              0xEC5784
#define __Socials_x                                                0xEFACEC
#define __SubscriptionType_x                                       0xFC0090
#define __TargetAggroHolder_x                                      0xF7E540
#define __ZoneType_x                                               0xEC4848
#define __GroupAggro_x                                             0xF7E580
#define __LoginName_x                                              0xF6B93C
#define __Inviter_x                                                0xF63088
#define __AttackOnAssist_x                                         0xEC5740
#define __UseTellWindows_x                                         0xEC5A70
#define __gfMaxZoomCameraDistance_x                                0xB00C70
#define __gfMaxCameraDistance_x                                    0xB2D1BC
#define __pulAutoRun_x                                             0xEC4468
#define __pulForward_x                                             0xEC5AA8
#define __pulBackward_x                                            0xEC5AAC
#define __pulTurnRight_x                                           0xEC5AB0
#define __pulTurnLeft_x                                            0xEC5AB4
#define __pulStrafeLeft_x                                          0xEC5AB8
#define __pulStrafeRight_x                                         0xEC5ABC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB6F78
#define instEQZoneInfo_x                                           0xEC4640
#define pinstActiveBanker_x                                        0xEB4688
#define pinstActiveCorpse_x                                        0xEB4680
#define pinstActiveGMaster_x                                       0xEB4684
#define pinstActiveMerchant_x                                      0xEB467C
#define pinstAltAdvManager_x                                       0xE031A8
#define pinstBandageTarget_x                                       0xEB4698
#define pinstCamActor_x                                            0xE02008
#define pinstCDBStr_x                                              0xE01EC4
#define pinstCDisplay_x                                            0xEB6BCC
#define pinstCEverQuest_x                                          0xF6B200
#define pinstEverQuestInfo_x                                       0xEC4360
#define pinstCharData_x                                            0xEB6D64
#define pinstCharSpawn_x                                           0xEB46D0
#define pinstControlledMissile_x                                   0xEB4BBC
#define pinstControlledPlayer_x                                    0xEB46D0
#define pinstCResolutionHandler_x                                  0x15FB130
#define pinstCSidlManager_x                                        0x15FA0C8
#define pinstCXWndManager_x                                        0x15FA0C4
#define instDynamicZone_x                                          0xEBAAB0
#define pinstDZMember_x                                            0xEBABC0
#define pinstDZTimerInfo_x                                         0xEBABC4
#define pinstEqLogin_x                                             0xF6B288
#define instEQMisc_x                                               0xE01E08
#define pinstEQSoundManager_x                                      0xE04178
#define pinstEQSpellStrings_x                                      0xCC4878
#define instExpeditionLeader_x                                     0xEBAAFA
#define instExpeditionName_x                                       0xEBAB3A
#define pinstGroup_x                                               0xEB6D7E
#define pinstImeManager_x                                          0x15FA0C0
#define pinstLocalPlayer_x                                         0xEB4678
#define pinstMercenaryData_x                                       0xF656DC
#define pinstMercenaryStats_x                                      0xF7E68C
#define pinstModelPlayer_x                                         0xEB4690
#define pinstPCData_x                                              0xEB6D64
#define pinstSkillMgr_x                                            0xF67848
#define pinstSpawnManager_x                                        0xF662F0
#define pinstSpellManager_x                                        0xF67A68
#define pinstSpellSets_x                                           0xF5BD34
#define pinstStringTable_x                                         0xEB6D68
#define pinstSwitchManager_x                                       0xEB4518
#define pinstTarget_x                                              0xEB46CC
#define pinstTargetObject_x                                        0xEB4758
#define pinstTargetSwitch_x                                        0xEB4BC4
#define pinstTaskMember_x                                          0xE01C98
#define pinstTrackTarget_x                                         0xEB46D4
#define pinstTradeTarget_x                                         0xEB468C
#define instTributeActive_x                                        0xE01E29
#define pinstViewActor_x                                           0xE02004
#define pinstWorldData_x                                           0xEB4BB8
#define pinstZoneAddr_x                                            0xEC48E0
#define pinstPlayerPath_x                                          0xF66388
#define pinstTargetIndicator_x                                     0xF67CD0
#define EQObject_Top_x                                             0xEB4674
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE02790
#define pinstCAchievementsWnd_x                                    0xE0278C
#define pinstCActionsWnd_x                                         0xE022DC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE01FC0
#define pinstCAdvancedLootWnd_x                                    0xE01F84
#define pinstCAdventureLeaderboardWnd_x                            0xF75360
#define pinstCAdventureRequestWnd_x                                0xF75410
#define pinstCAdventureStatsWnd_x                                  0xF754C0
#define pinstCAggroMeterWnd_x                                      0xE02044
#define pinstCAlarmWnd_x                                           0xE027EC
#define pinstCAlertHistoryWnd_x                                    0xE01FDC
#define pinstCAlertStackWnd_x                                      0xE027F4
#define pinstCAlertWnd_x                                           0xE01F64
#define pinstCAltStorageWnd_x                                      0xF75820
#define pinstCAudioTriggersWindow_x                                0xCB6BA8
#define pinstCAuraWnd_x                                            0xE01FFC
#define pinstCAvaZoneWnd_x                                         0xE02058
#define pinstCBandolierWnd_x                                       0xE0203C
#define pinstCBankWnd_x                                            0xE01FF8
#define pinstCBarterMerchantWnd_x                                  0xF76A60
#define pinstCBarterSearchWnd_x                                    0xF76B10
#define pinstCBarterWnd_x                                          0xF76BC0
#define pinstCBazaarConfirmationWnd_x                              0xE027B8
#define pinstCBazaarSearchWnd_x                                    0xE02090
#define pinstCBazaarWnd_x                                          0xE027D4
#define pinstCBlockedBuffWnd_x                                     0xE02000
#define pinstCBlockedPetBuffWnd_x                                  0xE02038
#define pinstCBodyTintWnd_x                                        0xE022EC
#define pinstCBookWnd_x                                            0xE02068
#define pinstCBreathWnd_x                                          0xE027A8
#define pinstCBuffWindowNORMAL_x                                   0xE01FE0
#define pinstCBuffWindowSHORT_x                                    0xE01FE4
#define pinstCBugReportWnd_x                                       0xE01FF0
#define pinstCButtonWnd_x                                          0x15FA330
#define pinstCCastingWnd_x                                         0xE0205C
#define pinstCCastSpellWnd_x                                       0xE027A4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE027D8
#define pinstCChatWindowManager_x                                  0xF77680
#define pinstCClaimWnd_x                                           0xF777D8
#define pinstCColorPickerWnd_x                                     0xE022E4
#define pinstCCombatAbilityWnd_x                                   0xE027E4
#define pinstCCombatSkillsSelectWnd_x                              0xE01F6C
#define pinstCCompassWnd_x                                         0xE022E0
#define pinstCConfirmationDialog_x                                 0xF7C6D8
#define pinstCContainerMgr_x                                       0xE027CC
#define pinstCContextMenuManager_x                                 0x15FA080
#define pinstCCursorAttachment_x                                   0xE0204C
#define pinstCDynamicZoneWnd_x                                     0xF77DA0
#define pinstCEditLabelWnd_x                                       0xE01FD8
#define pinstCEQMainWnd_x                                          0xF77FE8
#define pinstCEventCalendarWnd_x                                   0xE02050
#define pinstCExtendedTargetWnd_x                                  0xE0202C
#define pinstCFacePick_x                                           0xE01F7C
#define pinstCFactionWnd_x                                         0xE027C8
#define pinstCFellowshipWnd_x                                      0xF781E8
#define pinstCFileSelectionWnd_x                                   0xE02054
#define pinstCFindItemWnd_x                                        0xE027B4
#define pinstCFindLocationWnd_x                                    0xF78340
#define pinstCFriendsWnd_x                                         0xE01F80
#define pinstCGemsGameWnd_x                                        0xE027C4
#define pinstCGiveWnd_x                                            0xE027F0
#define pinstCGroupSearchFiltersWnd_x                              0xE02060
#define pinstCGroupSearchWnd_x                                     0xF78738
#define pinstCGroupWnd_x                                           0xF787E8
#define pinstCGuildBankWnd_x                                       0xEC5724
#define pinstCGuildCreationWnd_x                                   0xF78948
#define pinstCGuildMgmtWnd_x                                       0xF789F8
#define pinstCharacterCreation_x                                   0xE01F74
#define pinstCHelpWnd_x                                            0xE01FB8
#define pinstCHeritageSelectionWnd_x                               0xE01F88
#define pinstCHotButtonWnd_x                                       0xF7AB50
#define pinstCHotButtonWnd1_x                                      0xF7AB50
#define pinstCHotButtonWnd2_x                                      0xF7AB54
#define pinstCHotButtonWnd3_x                                      0xF7AB58
#define pinstCHotButtonWnd4_x                                      0xF7AB5C
#define pinstCIconSelectionWnd_x                                   0xE02048
#define pinstCInspectWnd_x                                         0xE01FB4
#define pinstCInventoryWnd_x                                       0xE01F8C
#define pinstCInvSlotMgr_x                                         0xE02788
#define pinstCItemDisplayManager_x                                 0xF7B0E0
#define pinstCItemExpTransferWnd_x                                 0xF7B210
#define pinstCItemOverflowWnd_x                                    0xE02094
#define pinstCJournalCatWnd_x                                      0xE0206C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE02030
#define pinstCKeyRingWnd_x                                         0xE01FD4
#define pinstCLargeDialogWnd_x                                     0xF7D358
#define pinstCLayoutCopyWnd_x                                      0xF7B560
#define pinstCLFGuildWnd_x                                         0xF7B610
#define pinstCLoadskinWnd_x                                        0xE027D0
#define pinstCLootFiltersCopyWnd_x                                 0xCD31A0
#define pinstCLootFiltersWnd_x                                     0xE027F8
#define pinstCLootSettingsWnd_x                                    0xE01F78
#define pinstCLootWnd_x                                            0xE02070
#define pinstCMailAddressBookWnd_x                                 0xE02798
#define pinstCMailCompositionWnd_x                                 0xE022FC
#define pinstCMailIgnoreListWnd_x                                  0xE0279C
#define pinstCMailWnd_x                                            0xE022D8
#define pinstCManageLootWnd_x                                      0xE03658
#define pinstCMapToolbarWnd_x                                      0xE01FBC
#define pinstCMapViewWnd_x                                         0xE01F98
#define pinstCMarketplaceWnd_x                                     0xE01F60
#define pinstCMerchantWnd_x                                        0xE02074
#define pinstCMIZoneSelectWnd_x                                    0xF7BE48
#define pinstCMusicPlayerWnd_x                                     0xE0207C
#define pinstCNameChangeMercWnd_x                                  0xE027B0
#define pinstCNameChangePetWnd_x                                   0xE02794
#define pinstCNameChangeWnd_x                                      0xE027C0
#define pinstCNoteWnd_x                                            0xE01F9C
#define pinstCObjectPreviewWnd_x                                   0xE01F70
#define pinstCOptionsWnd_x                                         0xE01FA4
#define pinstCPetInfoWnd_x                                         0xE020A0
#define pinstCPetitionQWnd_x                                       0xE02314
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE022F0
#define pinstCPlayerWnd_x                                          0xE020A4
#define pinstCPopupWndManager_x                                    0xF7C6D8
#define pinstCProgressionSelectionWnd_x                            0xF7C788
#define pinstCPurchaseGroupWnd_x                                   0xE01FA8
#define pinstCPurchaseWnd_x                                        0xE01F90
#define pinstCPvPLeaderboardWnd_x                                  0xF7C838
#define pinstCPvPStatsWnd_x                                        0xF7C8E8
#define pinstCQuantityWnd_x                                        0xE02034
#define pinstCRaceChangeWnd_x                                      0xE027E8
#define pinstCRaidOptionsWnd_x                                     0xE02064
#define pinstCRaidWnd_x                                            0xE0230C
#define pinstCRealEstateItemsWnd_x                                 0xE02384
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE02078
#define pinstCRealEstateManageWnd_x                                0xE01FB0
#define pinstCRealEstateNeighborhoodWnd_x                          0xE01FD0
#define pinstCRealEstatePlotSearchWnd_x                            0xE01FF4
#define pinstCRealEstatePurchaseWnd_x                              0xE02028
#define pinstCRespawnWnd_x                                         0xE02024
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE027A0
#define pinstCSendMoneyWnd_x                                       0xE01F68
#define pinstCServerListWnd_x                                      0xE02040
#define pinstCSkillsSelectWnd_x                                    0xE027DC
#define pinstCSkillsWnd_x                                          0xE027BC
#define pinstCSocialEditWnd_x                                      0xE01FCC
#define pinstCSocialWnd_x                                          0xE027AC
#define pinstCSpellBookWnd_x                                       0xE027E0
#define pinstCStoryWnd_x                                           0xE020A8
#define pinstCTargetOfTargetWnd_x                                  0xF7E710
#define pinstCTargetWnd_x                                          0xE02020
#define pinstCTaskOverlayWnd_x                                     0xE01FA0
#define pinstCTaskSelectWnd_x                                      0xF7E868
#define pinstCTaskManager_x                                        0xCD3AE0
#define pinstCTaskTemplateSelectWnd_x                              0xF7E918
#define pinstCTaskWnd_x                                            0xF7E9C8
#define pinstCTextEntryWnd_x                                       0xE01FE8
#define pinstCTimeLeftWnd_x                                        0xE022D4
#define pinstCTipWndCONTEXT_x                                      0xF7EBCC
#define pinstCTipWndOFDAY_x                                        0xF7EBC8
#define pinstCTitleWnd_x                                           0xF7EC78
#define pinstCTrackingWnd_x                                        0xE01F94
#define pinstCTradeskillWnd_x                                      0xF7EDE0
#define pinstCTradeWnd_x                                           0xE022F8
#define pinstCTrainWnd_x                                           0xE022F4
#define pinstCTributeBenefitWnd_x                                  0xF7EFE0
#define pinstCTributeMasterWnd_x                                   0xF7F090
#define pinstCTributeTrophyWnd_x                                   0xF7F140
#define pinstCVideoModesWnd_x                                      0xE020AC
#define pinstCVoiceMacroWnd_x                                      0xF68438
#define pinstCVoteResultsWnd_x                                     0xE02304
#define pinstCVoteWnd_x                                            0xE022E8
#define pinstCWebManager_x                                         0xF68AB4
#define pinstCZoneGuideWnd_x                                       0xE01FAC
#define pinstCZonePathWnd_x                                        0xE01FC4

#define pinstEQSuiteTextureLoader_x                                0xCA10C0
#define pinstItemIconCache_x                                       0xF77FA0
#define pinstLootFiltersManager_x                                  0xCD3250
#define pinstRewardSelectionWnd_x                                  0xF7D030

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AFEE0
#define __CastRay2_x                                               0x5AFF30
#define __ConvertItemTags_x                                        0x5CBA90
#define __CleanItemTags_x                                          0x47D0A0
#define __DoesFileExist_x                                          0x905CD0
#define __EQGetTime_x                                              0x9026C0
#define __ExecuteCmd_x                                             0x5A8740
#define __FixHeading_x                                             0x99D750
#define __GameLoop_x                                               0x6BCE40
#define __get_bearing_x                                            0x5AFA50
#define __get_melee_range_x                                        0x5B0120
#define __GetAnimationCache_x                                      0x722290
#define __GetGaugeValueFromEQ_x                                    0x814A40
#define __GetLabelFromEQ_x                                         0x816520
#define __GetXTargetType_x                                         0x99F130
#define __HandleMouseWheel_x                                       0x6BDD00
#define __HeadingDiff_x                                            0x99D7C0
#define __HelpPath_x                                               0xF637DC
#define __LoadFrontEnd_x                                           0x6BA160
#define __NewUIINI_x                                               0x814710
#define __ProcessGameEvents_x                                      0x610820
#define __ProcessMouseEvent_x                                      0x60FFE0
#define __SaveColors_x                                             0x552040
#define __STMLToText_x                                             0x940DE0
#define __ToggleKeyRingItem_x                                      0x5159D0
#define CMemoryMappedFile__SetFile_x                               0xA8CB50
#define CrashDetected_x                                            0x6BBC00
#define DrawNetStatus_x                                            0x63C370
#define Expansion_HoT_x                                            0xEC572C
#define Teleport_Table_Size_x                                      0xEB4760
#define Teleport_Table_x                                           0xEB4BC8
#define Util__FastTime_x                                           0x902290

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490240
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499150
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F20
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4937E0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C30

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559C50
#define AltAdvManager__IsAbilityReady_x                            0x558B80
#define AltAdvManager__GetAAById_x                                 0x558D80
#define AltAdvManager__CanTrainAbility_x                           0x558DF0
#define AltAdvManager__CanSeeAbility_x                             0x559150

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA2E0
#define CharacterZoneClient__HasSkill_x                            0x4D51D0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D68F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE4A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAAA0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D92B0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9390
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9470
#define CharacterZoneClient__FindAffectSlot_x                      0x4C32A0
#define CharacterZoneClient__BardCastBard_x                        0x4C5E00
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB70
#define CharacterZoneClient__GetEffect_x                           0x4BA9E0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C42F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C43C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4410
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4560
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4730
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2970
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7850
#define CharacterZoneClient__FindItemByRecord_x                    0x4D72D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E39C0
#define CBankWnd__WndNotification_x                                0x6E37A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F1190

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61EE20
#define CButtonWnd__CButtonWnd_x                                   0x93D1B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x711440
#define CChatManager__InitContextMenu_x                            0x70A5A0
#define CChatManager__FreeChatWindow_x                             0x70FF80
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8930
#define CChatManager__SetLockedActiveChatWindow_x                  0x7110C0
#define CChatManager__CreateChatWindow_x                           0x7105C0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8A40

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9517C0
#define CContextMenu__dCContextMenu_x                              0x9519F0
#define CContextMenu__AddMenuItem_x                                0x951A00
#define CContextMenu__RemoveMenuItem_x                             0x951D10
#define CContextMenu__RemoveAllMenuItems_x                         0x951D30
#define CContextMenu__CheckMenuItem_x                              0x951DB0
#define CContextMenu__SetMenuItem_x                                0x951C30
#define CContextMenu__AddSeparator_x                               0x951B90

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x952350
#define CContextMenuManager__RemoveMenu_x                          0x9523C0
#define CContextMenuManager__PopupMenu_x                           0x952480
#define CContextMenuManager__Flush_x                               0x9522F0
#define CContextMenuManager__GetMenu_x                             0x49B370
#define CContextMenuManager__CreateDefaultMenu_x                   0x71CAA0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DDD10
#define CChatService__GetFriendName_x                              0x8DDD20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x711CB0
#define CChatWindow__Clear_x                                       0x712F70
#define CChatWindow__WndNotification_x                             0x713700
#define CChatWindow__AddHistory_x                                  0x712830

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94EC20
#define CComboWnd__Draw_x                                          0x94E110
#define CComboWnd__GetCurChoice_x                                  0x94EA60
#define CComboWnd__GetListRect_x                                   0x94E5D0
#define CComboWnd__GetTextRect_x                                   0x94EC90
#define CComboWnd__InsertChoice_x                                  0x94E760
#define CComboWnd__SetColors_x                                     0x94E730
#define CComboWnd__SetChoice_x                                     0x94EA30
#define CComboWnd__GetItemCount_x                                  0x94EA70
#define CComboWnd__GetCurChoiceText_x                              0x94EAB0
#define CComboWnd__GetChoiceText_x                                 0x94EA80
#define CComboWnd__InsertChoiceAtIndex_x                           0x94E7F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71A490
#define CContainerWnd__vftable_x                                   0xB14504
#define CContainerWnd__SetContainer_x                              0x71B9F0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54CA70
#define CDisplay__PreZoneMainUI_x                                  0x54CA80
#define CDisplay__CleanGameUI_x                                    0x551E00
#define CDisplay__GetClickedActor_x                                0x544D90
#define CDisplay__GetUserDefinedColor_x                            0x53D450
#define CDisplay__GetWorldFilePath_x                               0x546800
#define CDisplay__is3dON_x                                         0x5419F0
#define CDisplay__ReloadUI_x                                       0x54BF00
#define CDisplay__WriteTextHD2_x                                   0x5417E0
#define CDisplay__TrueDistance_x                                   0x5484C0
#define CDisplay__SetViewActor_x                                   0x5446B0
#define CDisplay__GetFloorHeight_x                                 0x541AB0
#define CDisplay__SetRenderWindow_x                                0x540410
#define CDisplay__ToggleScreenshotMode_x                           0x544180

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9713A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x954CFF
#define CEditWnd__GetCharIndexPt_x                                 0x955C30
#define CEditWnd__GetDisplayString_x                               0x955AE0
#define CEditWnd__GetHorzOffset_x                                  0x954350
#define CEditWnd__GetLineForPrintableChar_x                        0x956DA0
#define CEditWnd__GetSelStartPt_x                                  0x955EE0
#define CEditWnd__GetSTMLSafeText_x                                0x955900
#define CEditWnd__PointFromPrintableChar_x                         0x9569E0
#define CEditWnd__SelectableCharFromPoint_x                        0x956B50
#define CEditWnd__SetEditable_x                                    0x955FA0
#define CEditWnd__SetWindowTextA_x                                 0x955680

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FE490
#define CEverQuest__ClickedPlayer_x                                0x5F04A0
#define CEverQuest__CreateTargetIndicator_x                        0x60DAB0
#define CEverQuest__DeleteTargetIndicator_x                        0x60DB40
#define CEverQuest__DoTellWindow_x                                 0x4E8B20
#define CEverQuest__OutputTextToLog_x                              0x4E8DA0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E54E0
#define CEverQuest__dsp_chat_x                                     0x4E9130
#define CEverQuest__trimName_x                                     0x609D90
#define CEverQuest__Emote_x                                        0x5FECF0
#define CEverQuest__EnterZone_x                                    0x5F8C70
#define CEverQuest__GetBodyTypeDesc_x                              0x603660
#define CEverQuest__GetClassDesc_x                                 0x603CA0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6042A0
#define CEverQuest__GetDeityDesc_x                                 0x60C3F0
#define CEverQuest__GetLangDesc_x                                  0x604460
#define CEverQuest__GetRaceDesc_x                                  0x603C80
#define CEverQuest__InterpretCmd_x                                 0x60C9C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E96E0
#define CEverQuest__LMouseUp_x                                     0x5E7A70
#define CEverQuest__RightClickedOnPlayer_x                         0x5E9FC0
#define CEverQuest__RMouseUp_x                                     0x5E89F0
#define CEverQuest__SetGameState_x                                 0x5E5270
#define CEverQuest__UPCNotificationFlush_x                         0x609C90
#define CEverQuest__IssuePetCommand_x                              0x605860
#define CEverQuest__ReportSuccessfulHit_x                          0x6000E0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72C360
#define CGaugeWnd__CalcLinesFillRect_x                             0x72C3C0
#define CGaugeWnd__Draw_x                                          0x72B9E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF3D0
#define CGuild__GetGuildName_x                                     0x4AE4B0
#define CGuild__GetGuildIndex_x                                    0x4AE840

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x747740

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61F1E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x754750
#define CInvSlotMgr__MoveItem_x                                    0x753460
#define CInvSlotMgr__SelectSlot_x                                  0x754820

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x751CE0
#define CInvSlot__SliderComplete_x                                 0x74FA30
#define CInvSlot__GetItemBase_x                                    0x74F3B0
#define CInvSlot__UpdateItem_x                                     0x74F520

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7562A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x755440
#define CInvSlotWnd__HandleLButtonUp_x                             0x755E20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80FD80
#define CItemDisplayWnd__UpdateStrings_x                           0x764A20
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75E700
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75EC30
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x765030
#define CItemDisplayWnd__AboutToShow_x                             0x764670
#define CItemDisplayWnd__WndNotification_x                         0x766120
#define CItemDisplayWnd__RequestConvertItem_x                      0x765BE0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7636D0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x764490

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x848A60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76A660

// CLabel 
#define CLabel__Draw_x                                             0x770040

// CListWnd
#define CListWnd__CListWnd_x                                       0x927380
#define CListWnd__dCListWnd_x                                      0x9276A0
#define CListWnd__AddColumn_x                                      0x92BB00
#define CListWnd__AddColumn1_x                                     0x92BB50
#define CListWnd__AddLine_x                                        0x92BEE0
#define CListWnd__AddString_x                                      0x92BCE0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92B8D0
#define CListWnd__CalculateVSBRange_x                              0x92B6C0
#define CListWnd__ClearSel_x                                       0x92C6C0
#define CListWnd__ClearAllSel_x                                    0x92C720
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92D120
#define CListWnd__Compare_x                                        0x92AFF0
#define CListWnd__Draw_x                                           0x9277D0
#define CListWnd__DrawColumnSeparators_x                           0x929FC0
#define CListWnd__DrawHeader_x                                     0x92A430
#define CListWnd__DrawItem_x                                       0x92A930
#define CListWnd__DrawLine_x                                       0x92A130
#define CListWnd__DrawSeparator_x                                  0x92A060
#define CListWnd__EnableLine_x                                     0x9298A0
#define CListWnd__EnsureVisible_x                                  0x92D050
#define CListWnd__ExtendSel_x                                      0x92C5F0
#define CListWnd__GetColumnTooltip_x                               0x9293E0
#define CListWnd__GetColumnMinWidth_x                              0x929450
#define CListWnd__GetColumnWidth_x                                 0x929350
#define CListWnd__GetCurSel_x                                      0x928CE0
#define CListWnd__GetItemAtPoint_x                                 0x929B10
#define CListWnd__GetItemAtPoint1_x                                0x929B80
#define CListWnd__GetItemData_x                                    0x928D60
#define CListWnd__GetItemHeight_x                                  0x929120
#define CListWnd__GetItemIcon_x                                    0x928EF0
#define CListWnd__GetItemRect_x                                    0x929990
#define CListWnd__GetItemText_x                                    0x928DA0
#define CListWnd__GetSelList_x                                     0x92C770
#define CListWnd__GetSeparatorRect_x                               0x929DC0
#define CListWnd__InsertLine_x                                     0x92C2D0
#define CListWnd__RemoveLine_x                                     0x92C420
#define CListWnd__SetColors_x                                      0x92B690
#define CListWnd__SetColumnJustification_x                         0x92B3C0
#define CListWnd__SetColumnWidth_x                                 0x92B2E0
#define CListWnd__SetCurSel_x                                      0x92C530
#define CListWnd__SetItemColor_x                                   0x92CD10
#define CListWnd__SetItemData_x                                    0x92CCD0
#define CListWnd__SetItemText_x                                    0x92C8E0
#define CListWnd__ShiftColumnSeparator_x                           0x92B480
#define CListWnd__Sort_x                                           0x92B170
#define CListWnd__ToggleSel_x                                      0x92C560
#define CListWnd__SetColumnsSizable_x                              0x92B530
#define CListWnd__SetItemWnd_x                                     0x92CB90
#define CListWnd__GetItemWnd_x                                     0x928F40
#define CListWnd__SetItemIcon_x                                    0x92C960
#define CListWnd__CalculateCustomWindowPositions_x                 0x92B9C0
#define CListWnd__SetVScrollPos_x                                  0x92B2C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x785810
#define CMapViewWnd__GetWorldCoordinates_x                         0x783F20
#define CMapViewWnd__HandleLButtonDown_x                           0x780F60

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A5800
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A60E0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A6610
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A95A0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A4360
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AF160
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A5410

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AB9B0
#define CPacketScrambler__hton_x                                   0x8AB9A0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x946430
#define CSidlManager__FindScreenPieceTemplate_x                    0x946840
#define CSidlManager__FindScreenPieceTemplate1_x                   0x946630
#define CSidlManager__CreateLabel_x                                0x8071C0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9497A0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x949970
#define CSidlManager__CreateXWnd_x                                 0x8070F0
#define CSidlManager__CreateHotButtonWnd_x                         0x8076A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x942EF0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x942DF0
#define CSidlScreenWnd__ConvertToRes_x                             0x968340
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x942890
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x942580
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x942650
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x942720
#define CSidlScreenWnd__DrawSidlPiece_x                            0x943380
#define CSidlScreenWnd__EnableIniStorage_x                         0x943850
#define CSidlScreenWnd__GetSidlPiece_x                             0x943570
#define CSidlScreenWnd__Init1_x                                    0x942180
#define CSidlScreenWnd__LoadIniInfo_x                              0x9438A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x944400
#define CSidlScreenWnd__LoadSidlScreen_x                           0x941590
#define CSidlScreenWnd__StoreIniInfo_x                             0x943F70
#define CSidlScreenWnd__StoreIniVis_x                              0x9442E0
#define CSidlScreenWnd__WndNotification_x                          0x943290
#define CSidlScreenWnd__GetChildItem_x                             0x9437D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x932F00
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F9F50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x683990
#define CSkillMgr__GetSkillCap_x                                   0x683B70
#define CSkillMgr__GetNameToken_x                                  0x683110
#define CSkillMgr__IsActivatedSkill_x                              0x683250
#define CSkillMgr__IsCombatSkill_x                                 0x683190

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x953130
#define CSliderWnd__SetValue_x                                     0x952FA0
#define CSliderWnd__SetNumTicks_x                                  0x953000

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80D200

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95B8C0
#define CStmlWnd__CalculateHSBRange_x                              0x95C9D0
#define CStmlWnd__CalculateVSBRange_x                              0x95C950
#define CStmlWnd__CanBreakAtCharacter_x                            0x960D00
#define CStmlWnd__FastForwardToEndOfTag_x                          0x961990
#define CStmlWnd__ForceParseNow_x                                  0x95BEB0
#define CStmlWnd__GetNextTagPiece_x                                0x960C60
#define CStmlWnd__GetSTMLText_x                                    0x505220
#define CStmlWnd__GetVisibleText_x                                 0x95BED0
#define CStmlWnd__InitializeWindowVariables_x                      0x9617E0
#define CStmlWnd__MakeStmlColorTag_x                               0x95AF30
#define CStmlWnd__MakeWndNotificationTag_x                         0x95AFA0
#define CStmlWnd__SetSTMLText_x                                    0x959FE0
#define CStmlWnd__StripFirstSTMLLines_x                            0x962A80
#define CStmlWnd__UpdateHistoryString_x                            0x961BA0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x959130
#define CTabWnd__DrawCurrentPage_x                                 0x959860
#define CTabWnd__DrawTab_x                                         0x959580
#define CTabWnd__GetCurrentPage_x                                  0x958940
#define CTabWnd__GetPageInnerRect_x                                0x958B80
#define CTabWnd__GetTabInnerRect_x                                 0x958AC0
#define CTabWnd__GetTabRect_x                                      0x958970
#define CTabWnd__InsertPage_x                                      0x958D90
#define CTabWnd__SetPage_x                                         0x958C00
#define CTabWnd__SetPageRect_x                                     0x959070
#define CTabWnd__UpdatePage_x                                      0x959440
#define CTabWnd__GetPageFromTabIndex_x                             0x9594C0
#define CTabWnd__GetCurrentTabIndex_x                              0x958930

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76AA30
#define CPageWnd__SetTabText_x                                     0x958490

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8FE0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92FDE0
#define CTextureFont__GetTextExtent_x                              0x92FFA0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B6D20
#define CHtmlComponentWnd__ValidateUri_x                           0x749130
#define CHtmlWnd__SetClientCallbacks_x                             0x624260
#define CHtmlWnd__AddObserver_x                                    0x624280
#define CHtmlWnd__RemoveObserver_x                                 0x6242E0
#define Window__getProgress_x                                      0x861000
#define Window__getStatus_x                                        0x861020
#define Window__getURI_x                                           0x861030

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96DE30

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91CFC0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8770
#define CXStr__CXStr1_x                                            0x500300
#define CXStr__CXStr3_x                                            0x8FE800
#define CXStr__dCXStr_x                                            0x478820
#define CXStr__operator_equal_x                                    0x8FEA30
#define CXStr__operator_equal1_x                                   0x8FEA70
#define CXStr__operator_plus_equal1_x                              0x8FF500
#define CXStr__SetString_x                                         0x9013F0
#define CXStr__operator_char_p_x                                   0x8FEF40
#define CXStr__GetChar_x                                           0x900D20
#define CXStr__Delete_x                                            0x9005F0
#define CXStr__GetUnicode_x                                        0x900D90
#define CXStr__GetLength_x                                         0x4A8D90
#define CXStr__Mid_x                                               0x47D450
#define CXStr__Insert_x                                            0x900DF0
#define CXStr__FindNext_x                                          0x900A60

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9513D0
#define CXWnd__BringToTop_x                                        0x9366C0
#define CXWnd__Center_x                                            0x936240
#define CXWnd__ClrFocus_x                                          0x936060
#define CXWnd__Destroy_x                                           0x936100
#define CXWnd__DoAllDrawing_x                                      0x9326B0
#define CXWnd__DrawChildren_x                                      0x932680
#define CXWnd__DrawColoredRect_x                                   0x932AF0
#define CXWnd__DrawTooltip_x                                       0x9311E0
#define CXWnd__DrawTooltipAtPoint_x                                0x9312A0
#define CXWnd__GetBorderFrame_x                                    0x932950
#define CXWnd__GetChildWndAt_x                                     0x936760
#define CXWnd__GetClientClipRect_x                                 0x934930
#define CXWnd__GetScreenClipRect_x                                 0x934A00
#define CXWnd__GetScreenRect_x                                     0x934BD0
#define CXWnd__GetTooltipRect_x                                    0x932B40
#define CXWnd__GetWindowTextA_x                                    0x94DA80
#define CXWnd__IsActive_x                                          0x933270
#define CXWnd__IsDescendantOf_x                                    0x9355D0
#define CXWnd__IsReallyVisible_x                                   0x935600
#define CXWnd__IsType_x                                            0x936DC0
#define CXWnd__Move_x                                              0x935670
#define CXWnd__Move1_x                                             0x935720
#define CXWnd__ProcessTransition_x                                 0x9361F0
#define CXWnd__Refade_x                                            0x9359F0
#define CXWnd__Resize_x                                            0x935C80
#define CXWnd__Right_x                                             0x936480
#define CXWnd__SetFocus_x                                          0x936020
#define CXWnd__SetFont_x                                           0x936090
#define CXWnd__SetKeyTooltip_x                                     0x936BF0
#define CXWnd__SetMouseOver_x                                      0x933AC0
#define CXWnd__StartFade_x                                         0x9354C0
#define CXWnd__GetChildItem_x                                      0x9368D0
#define CXWnd__SetParent_x                                         0x935370
#define CXWnd__Minimize_x                                          0x935CF0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9693C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9395F0
#define CXWndManager__DrawWindows_x                                0x939610
#define CXWndManager__GetKeyboardFlags_x                           0x93BDF0
#define CXWndManager__HandleKeyboardMsg_x                          0x93B9B0
#define CXWndManager__RemoveWnd_x                                  0x93C020
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93C590

// CDBStr
#define CDBStr__GetString_x                                        0x53C400

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBA80
#define EQ_Character__Cur_HP_x                                     0x4D2210
#define EQ_Character__Cur_Mana_x                                   0x4D9970
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEAF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B25B0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2700
#define EQ_Character__GetHPRegen_x                                 0x4DF740
#define EQ_Character__GetEnduranceRegen_x                          0x4DFD40
#define EQ_Character__GetManaRegen_x                               0x4E0180
#define EQ_Character__Max_Endurance_x                              0x64A540
#define EQ_Character__Max_HP_x                                     0x4D2040
#define EQ_Character__Max_Mana_x                                   0x64A340
#define EQ_Character__doCombatAbility_x                            0x64C9A0
#define EQ_Character__UseSkill_x                                   0x4E1F60
#define EQ_Character__GetConLevel_x                                0x643340
#define EQ_Character__IsExpansionFlag_x                            0x5A6ED0
#define EQ_Character__TotalEffect_x                                0x4C5540
#define EQ_Character__GetPCSpellAffect_x                           0x4BF840
#define EQ_Character__SpellDuration_x                              0x4BF370
#define EQ_Character__GetAdjustedSkill_x                           0x4D4F90
#define EQ_Character__GetBaseSkill_x                               0x4D5F30
#define EQ_Character__CanUseItem_x                                 0x4D9C80

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CABF0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x660A50

//PcClient
#define PcClient__PcClient_x                                       0x640A70

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B96F0
#define CCharacterListWnd__EnterWorld_x                            0x4B9130
#define CCharacterListWnd__Quit_x                                  0x4B8E80
#define CCharacterListWnd__UpdateList_x                            0x4B92C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6254A0
#define EQ_Item__CreateItemTagString_x                             0x8A5210
#define EQ_Item__IsStackable_x                                     0x8A9D80
#define EQ_Item__GetImageNum_x                                     0x8A6CA0
#define EQ_Item__CreateItemClient_x                                0x624680
#define EQ_Item__GetItemValue_x                                    0x8A7FC0
#define EQ_Item__ValueSellMerchant_x                               0x8AB590
#define EQ_Item__IsKeyRingItem_x                                   0x8A96A0
#define EQ_Item__CanGoInBag_x                                      0x6255C0
#define EQ_Item__IsEmpty_x                                         0x8A91D0
#define EQ_Item__GetMaxItemCount_x                                 0x8A83D0
#define EQ_Item__GetHeldItem_x                                     0x8A6B70
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A4B90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55A960
#define EQ_LoadingS__Array_x                                       0xC28B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64AEA0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B47E0
#define EQ_PC__GetCombatAbility_x                                  0x8B4E50
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B4EC0
#define EQ_PC__GetItemRecastTimer_x                                0x64CF20
#define EQ_PC__HasLoreItem_x                                       0x643B00
#define EQ_PC__AlertInventoryChanged_x                             0x642C70
#define EQ_PC__GetPcZoneClient_x                                   0x66F4F0
#define EQ_PC__RemoveMyAffect_x                                    0x650150
#define EQ_PC__GetKeyRingItems_x                                   0x8B5750
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B54E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B5A50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AD470
#define EQItemList__add_object_x                                   0x5DADE0
#define EQItemList__add_item_x                                     0x5AD9D0
#define EQItemList__delete_item_x                                  0x5ADA20
#define EQItemList__FreeItemList_x                                 0x5AD920

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538F40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6622D0
#define EQPlayer__dEQPlayer_x                                      0x655610
#define EQPlayer__DoAttack_x                                       0x66A180
#define EQPlayer__EQPlayer_x                                       0x655CD0
#define EQPlayer__SetNameSpriteState_x                             0x659FB0
#define EQPlayer__SetNameSpriteTint_x                              0x65AE80
#define PlayerBase__HasProperty_j_x                                0x99BAF0
#define EQPlayer__IsTargetable_x                                   0x99BF90
#define EQPlayer__CanSee_x                                         0x99BDF0
#define EQPlayer__CanSee1_x                                        0x99BEC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x99BBB0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66CF80
#define PlayerZoneClient__GetLevel_x                               0x66F530
#define PlayerZoneClient__IsValidTeleport_x                        0x5DBF50
#define PlayerZoneClient__LegalPlayerRace_x                        0x553C90

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x665090
#define EQPlayerManager__GetSpawnByName_x                          0x665140
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6651D0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x628AE0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x628B60
#define KeypressHandler__AttachKeyToEqCommand_x                    0x628BA0
#define KeypressHandler__ClearCommandStateArray_x                  0x629FB0
#define KeypressHandler__HandleKeyDown_x                           0x629FD0
#define KeypressHandler__HandleKeyUp_x                             0x62A070
#define KeypressHandler__SaveKeymapping_x                          0x62A4C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x781680
#define MapViewMap__SaveEx_x                                       0x784A40
#define MapViewMap__SetZoom_x                                      0x789100

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C8B10

// StringTable 
#define StringTable__getString_x                                   0x8C39E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64FDC0
#define PcZoneClient__RemovePetEffect_x                            0x6503F0
#define PcZoneClient__HasAlternateAbility_x                        0x64A170
#define PcZoneClient__GetCurrentMod_x                              0x4E5020
#define PcZoneClient__GetModCap_x                                  0x4E4F20
#define PcZoneClient__CanEquipItem_x                               0x64A840
#define PcZoneClient__GetItemByID_x                                0x64D390
#define PcZoneClient__GetItemByItemClass_x                         0x64D4E0
#define PcZoneClient__RemoveBuffEffect_x                           0x650410
#define PcZoneClient__BandolierSwap_x                              0x64B460
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64CEC0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E09F0

//IconCache
#define IconCache__GetIcon_x                                       0x721B30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x719630
#define CContainerMgr__CloseContainer_x                            0x719900
#define CContainerMgr__OpenExperimentContainer_x                   0x71A380

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D9780

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61D5E0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x777B10
#define CLootWnd__RequestLootSlot_x                                0x776D40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57A9B0
#define EQ_Spell__SpellAffects_x                                   0x57AE20
#define EQ_Spell__SpellAffectBase_x                                0x57ABE0
#define EQ_Spell__IsStackable_x                                    0x4C9C60
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9AB0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6AA0
#define EQ_Spell__IsSPAStacking_x                                  0x57BC70
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57B180
#define EQ_Spell__IsNoRemove_x                                     0x4C9C40
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57BC80
#define __IsResEffectSpell_x                                       0x4C8F80

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD0B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D3190

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x820550
#define CTargetWnd__WndNotification_x                              0x81FDE0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8200B0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81EF50

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x824B50

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5369B0
#define CTaskManager__HandleMessage_x                              0x534E30
#define CTaskManager__GetTaskStatus_x                              0x536A60
#define CTaskManager__GetElementDescription_x                      0x536AE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575F00
#define EqSoundManager__PlayScriptMp3_x                            0x576060
#define EqSoundManager__SoundAssistPlay_x                          0x687960
#define EqSoundManager__WaveInstancePlay_x                         0x686ED0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52A720

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9579A0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562340
#define CAltAbilityData__GetMercMaxRank_x                          0x5622D0
#define CAltAbilityData__GetMaxRank_x                              0x557A00

//CTargetRing
#define CTargetRing__Cast_x                                        0x61B700

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9A90
#define CharacterBase__CreateItemGlobalIndex_x                     0x511F60
#define CharacterBase__CreateItemIndex_x                           0x623810
#define CharacterBase__GetItemPossession_x                         0x4FDC70
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DB7A0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DB800
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x700750
#define CCastSpellWnd__IsBardSongPlaying_x                         0x700F80
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x701030

//messages
#define msg_spell_worn_off_x                                       0x59F1C0
#define msg_new_text_x                                             0x594010
#define __msgTokenTextParam_x                                      0x5A16F0
#define msgTokenText_x                                             0x5A1940

//SpellManager
#define SpellManager__vftable_x                                    0xAEE4DC
#define SpellManager__SpellManager_x                               0x68AC90
#define Spellmanager__LoadTextSpells_x                             0x68B580
#define SpellManager__GetSpellByGroupAndRank_x                     0x68AE60

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99FA20

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5125E0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A54B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63C1D0
#define ItemGlobalIndex__IsValidIndex_x                            0x512640

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D3B30
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D3DB0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x770380

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71DD40
#define CCursorAttachment__AttachToCursor1_x                       0x71DD80
#define CCursorAttachment__Deactivate_x                            0x71ED60

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94A790
#define CSidlManagerBase__CreatePageWnd_x                          0x949FA0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x946250
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9461E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9678A0
#define CEQSuiteTextureLoader__GetTexture_x                        0x967560

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F500
#define CFindItemWnd__WndNotification_x                            0x50FFE0
#define CFindItemWnd__Update_x                                     0x510B20
#define CFindItemWnd__PickupSelectedItem_x                         0x50ED40

//IString
#define IString__Append_x                                          0x4F0790

//Camera
#define CDisplay__cameraType_x                                     0xE020B0
#define EverQuest__Cameras_x                                       0xEC5A7C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517D80
#define LootFiltersManager__GetItemFilterData_x                    0x517680
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5176B0
#define LootFiltersManager__SetItemLootFilter_x                    0x5178D0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C7730

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A5640
#define CResolutionHandler__GetWindowedStyle_x                     0x682380

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x716400

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E8C30
#define CDistillerInfo__Instance_x                                 0x8E8BD0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x736520
#define CGroupWnd__UpdateDisplay_x                                 0x735880

//ItemBase
#define ItemBase__IsLore_x                                         0x8A9750
#define ItemBase__IsLoreEquipped_x                                 0x8A97C0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DAD40
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DAE80
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DAEE0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x677C10
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67B5C0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505870

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2350
#define FactionManagerClient__HandleFactionMessage_x               0x4F29C0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2F80
#define FactionManagerClient__GetMaxFaction_x                      0x4F2F9F
#define FactionManagerClient__GetMinFaction_x                      0x4F2F50

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FDC40

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92EE10

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD70

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FDEC0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5617E0

//CTargetManager
#define CTargetManager__Get_x                                      0x68E4F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x677C10

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8DA0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AD8C0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF63110

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
