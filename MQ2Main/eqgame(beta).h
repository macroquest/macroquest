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
#define __ExpectedVersionDate                                     "Nov 30 2019"
#define __ExpectedVersionTime                                     "04:23:58"
#define __ActualVersionDate_x                                      0xB0B2F0
#define __ActualVersionTime_x                                      0xB0B2E4
#define __ActualVersionBuild_x                                     0xAF6F74

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62FFB0
#define __MemChecker1_x                                            0x903180
#define __MemChecker2_x                                            0x6BE3B0
#define __MemChecker3_x                                            0x6BE300
#define __MemChecker4_x                                            0x85A170
#define __EncryptPad0_x                                            0xC413E8
#define __EncryptPad1_x                                            0xC9F5E8
#define __EncryptPad2_x                                            0xC51C80
#define __EncryptPad3_x                                            0xC51880
#define __EncryptPad4_x                                            0xC8FC00
#define __EncryptPad5_x                                            0xF6B1C0
#define __AC1_x                                                    0x816DF6
#define __AC2_x                                                    0x5E9E6F
#define __AC3_x                                                    0x5F156F
#define __AC4_x                                                    0x5F5540
#define __AC5_x                                                    0x5FB84F
#define __AC6_x                                                    0x5FFE66
#define __AC7_x                                                    0x5E98E0
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
#define __do_loot_x                                                0x5B5810
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
#define __gfMaxZoomCameraDistance_x                                0xB00C10
#define __gfMaxCameraDistance_x                                    0xB2D154
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
#define pinstCAvaZoneWnd_x                                         0xE02054
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
#define pinstCFileSelectionWnd_x                                   0xE02058
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
#define pinstCMailCompositionWnd_x                                 0xE02304
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
#define pinstCPetitionQWnd_x                                       0xE0237C
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
#define pinstCRaidWnd_x                                            0xE02378
#define pinstCRealEstateItemsWnd_x                                 0xE02784
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
#define pinstCTimeLeftWnd_x                                        0xE020D4
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
#define pinstCVoteResultsWnd_x                                     0xE02374
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
#define __CastRay_x                                                0x5B0C70
#define __CastRay2_x                                               0x5B0CC0
#define __ConvertItemTags_x                                        0x5CC820
#define __CleanItemTags_x                                          0x47D050
#define __DoesFileExist_x                                          0x906280
#define __EQGetTime_x                                              0x902C50
#define __ExecuteCmd_x                                             0x5A94B0
#define __FixHeading_x                                             0x99DA90
#define __GameLoop_x                                               0x6BD5A0
#define __get_bearing_x                                            0x5B07E0
#define __get_melee_range_x                                        0x5B0EB0
#define __GetAnimationCache_x                                      0x722A90
#define __GetGaugeValueFromEQ_x                                    0x8152A0
#define __GetLabelFromEQ_x                                         0x816D80
#define __GetXTargetType_x                                         0x99F470
#define __HandleMouseWheel_x                                       0x6BE460
#define __HeadingDiff_x                                            0x99DB00
#define __HelpPath_x                                               0xF637DC
#define __LoadFrontEnd_x                                           0x6BA8C0
#define __NewUIINI_x                                               0x814F70
#define __ProcessGameEvents_x                                      0x6116D0
#define __ProcessMouseEvent_x                                      0x610E90
#define __SaveColors_x                                             0x5522E0
#define __STMLToText_x                                             0x940F90
#define __ToggleKeyRingItem_x                                      0x5154A0
#define CMemoryMappedFile__SetFile_x                               0xA8CE00
#define CrashDetected_x                                            0x6BC360
#define DrawNetStatus_x                                            0x63D210
#define Expansion_HoT_x                                            0xEC572C
#define Teleport_Table_Size_x                                      0xEB4760
#define Teleport_Table_x                                           0xEB4BC8
#define Util__FastTime_x                                           0x902820

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490240
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499160
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F30
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4937E0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C30

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559E20
#define AltAdvManager__IsAbilityReady_x                            0x558D50
#define AltAdvManager__GetAAById_x                                 0x558F50
#define AltAdvManager__CanTrainAbility_x                           0x558FC0
#define AltAdvManager__CanSeeAbility_x                             0x559320

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA070
#define CharacterZoneClient__HasSkill_x                            0x4D4F60
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6680
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE2A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA8A0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9030
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9110
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D91F0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C30A0
#define CharacterZoneClient__BardCastBard_x                        0x4C5C00
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA970
#define CharacterZoneClient__GetEffect_x                           0x4BA7E0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C40F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C41C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4210
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4360
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4530
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B26C0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D75E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7060

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E4180
#define CBankWnd__WndNotification_x                                0x6E3F60

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F18F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61FE40
#define CButtonWnd__CButtonWnd_x                                   0x93D340

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x711BD0
#define CChatManager__InitContextMenu_x                            0x70AD20
#define CChatManager__FreeChatWindow_x                             0x710710
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E86E0
#define CChatManager__SetLockedActiveChatWindow_x                  0x711850
#define CChatManager__CreateChatWindow_x                           0x710D50

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E87F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x951930
#define CContextMenu__dCContextMenu_x                              0x951B70
#define CContextMenu__AddMenuItem_x                                0x951B80
#define CContextMenu__RemoveMenuItem_x                             0x951E90
#define CContextMenu__RemoveAllMenuItems_x                         0x951EB0
#define CContextMenu__CheckMenuItem_x                              0x951F30
#define CContextMenu__SetMenuItem_x                                0x951DB0
#define CContextMenu__AddSeparator_x                               0x951D10

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9524C0
#define CContextMenuManager__RemoveMenu_x                          0x952530
#define CContextMenuManager__PopupMenu_x                           0x9525F0
#define CContextMenuManager__Flush_x                               0x952460
#define CContextMenuManager__GetMenu_x                             0x49B290
#define CContextMenuManager__CreateDefaultMenu_x                   0x71D290

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DE450
#define CChatService__GetFriendName_x                              0x8DE460

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x712450
#define CChatWindow__Clear_x                                       0x713720
#define CChatWindow__WndNotification_x                             0x713EB0
#define CChatWindow__AddHistory_x                                  0x712FE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94ED90
#define CComboWnd__Draw_x                                          0x94E280
#define CComboWnd__GetCurChoice_x                                  0x94EBD0
#define CComboWnd__GetListRect_x                                   0x94E730
#define CComboWnd__GetTextRect_x                                   0x94EE00
#define CComboWnd__InsertChoice_x                                  0x94E8C0
#define CComboWnd__SetColors_x                                     0x94E890
#define CComboWnd__SetChoice_x                                     0x94EBA0
#define CComboWnd__GetItemCount_x                                  0x94EBE0
#define CComboWnd__GetCurChoiceText_x                              0x94EC20
#define CComboWnd__GetChoiceText_x                                 0x94EBF0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94E960

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71AC70
#define CContainerWnd__vftable_x                                   0xB144E4
#define CContainerWnd__SetContainer_x                              0x71C1D0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54CD10
#define CDisplay__PreZoneMainUI_x                                  0x54CD20
#define CDisplay__CleanGameUI_x                                    0x5520A0
#define CDisplay__GetClickedActor_x                                0x545030
#define CDisplay__GetUserDefinedColor_x                            0x53D6F0
#define CDisplay__GetWorldFilePath_x                               0x546AA0
#define CDisplay__is3dON_x                                         0x541C90
#define CDisplay__ReloadUI_x                                       0x54C1A0
#define CDisplay__WriteTextHD2_x                                   0x541A80
#define CDisplay__TrueDistance_x                                   0x548760
#define CDisplay__SetViewActor_x                                   0x544950
#define CDisplay__GetFloorHeight_x                                 0x541D50
#define CDisplay__SetRenderWindow_x                                0x5406B0
#define CDisplay__ToggleScreenshotMode_x                           0x544420

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x971570

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x954E9F
#define CEditWnd__GetCharIndexPt_x                                 0x955DE0
#define CEditWnd__GetDisplayString_x                               0x955C80
#define CEditWnd__GetHorzOffset_x                                  0x9544E0
#define CEditWnd__GetLineForPrintableChar_x                        0x956F80
#define CEditWnd__GetSelStartPt_x                                  0x956090
#define CEditWnd__GetSTMLSafeText_x                                0x955AA0
#define CEditWnd__PointFromPrintableChar_x                         0x956BB0
#define CEditWnd__SelectableCharFromPoint_x                        0x956D20
#define CEditWnd__SetEditable_x                                    0x956160
#define CEditWnd__SetWindowTextA_x                                 0x955820

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FF340
#define CEverQuest__ClickedPlayer_x                                0x5F1350
#define CEverQuest__CreateTargetIndicator_x                        0x60E970
#define CEverQuest__DeleteTargetIndicator_x                        0x60EA00
#define CEverQuest__DoTellWindow_x                                 0x4E88D0
#define CEverQuest__OutputTextToLog_x                              0x4E8B50
#define CEverQuest__DropHeldItemOnGround_x                         0x5E6390
#define CEverQuest__dsp_chat_x                                     0x4E8EE0
#define CEverQuest__trimName_x                                     0x60AC50
#define CEverQuest__Emote_x                                        0x5FFBA0
#define CEverQuest__EnterZone_x                                    0x5F9B20
#define CEverQuest__GetBodyTypeDesc_x                              0x604510
#define CEverQuest__GetClassDesc_x                                 0x604B50
#define CEverQuest__GetClassThreeLetterCode_x                      0x605150
#define CEverQuest__GetDeityDesc_x                                 0x60D2B0
#define CEverQuest__GetLangDesc_x                                  0x605310
#define CEverQuest__GetRaceDesc_x                                  0x604B30
#define CEverQuest__InterpretCmd_x                                 0x60D880
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EA590
#define CEverQuest__LMouseUp_x                                     0x5E8920
#define CEverQuest__RightClickedOnPlayer_x                         0x5EAE70
#define CEverQuest__RMouseUp_x                                     0x5E98A0
#define CEverQuest__SetGameState_x                                 0x5E6120
#define CEverQuest__UPCNotificationFlush_x                         0x60AB50
#define CEverQuest__IssuePetCommand_x                              0x606710
#define CEverQuest__ReportSuccessfulHit_x                          0x600F90

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72CA60
#define CGaugeWnd__CalcLinesFillRect_x                             0x72CAC0
#define CGaugeWnd__Draw_x                                          0x72C0E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF1A0
#define CGuild__GetGuildName_x                                     0x4AE280
#define CGuild__GetGuildIndex_x                                    0x4AE610

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x747F30

//CHotButton
#define CHotButton__SetButtonSize_x                                0x620200

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x754EF0
#define CInvSlotMgr__MoveItem_x                                    0x753C50
#define CInvSlotMgr__SelectSlot_x                                  0x754FC0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7524D0
#define CInvSlot__SliderComplete_x                                 0x750230
#define CInvSlot__GetItemBase_x                                    0x74FBC0
#define CInvSlot__UpdateItem_x                                     0x74FD30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x756A40
#define CInvSlotWnd__CInvSlotWnd_x                                 0x755BE0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7565C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8105E0
#define CItemDisplayWnd__UpdateStrings_x                           0x7650E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75EE20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75F340
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7656E0
#define CItemDisplayWnd__AboutToShow_x                             0x764D20
#define CItemDisplayWnd__WndNotification_x                         0x7667C0
#define CItemDisplayWnd__RequestConvertItem_x                      0x766280
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x763D80
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x764B40

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x848F40

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76ACE0

// CLabel 
#define CLabel__Draw_x                                             0x7707D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x927540
#define CListWnd__dCListWnd_x                                      0x927860
#define CListWnd__AddColumn_x                                      0x92BCF0
#define CListWnd__AddColumn1_x                                     0x92BD40
#define CListWnd__AddLine_x                                        0x92C0D0
#define CListWnd__AddString_x                                      0x92BED0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92BAB0
#define CListWnd__CalculateVSBRange_x                              0x92B890
#define CListWnd__ClearSel_x                                       0x92C8B0
#define CListWnd__ClearAllSel_x                                    0x92C910
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92D330
#define CListWnd__Compare_x                                        0x92B1C0
#define CListWnd__Draw_x                                           0x927990
#define CListWnd__DrawColumnSeparators_x                           0x92A190
#define CListWnd__DrawHeader_x                                     0x92A600
#define CListWnd__DrawItem_x                                       0x92AB00
#define CListWnd__DrawLine_x                                       0x92A300
#define CListWnd__DrawSeparator_x                                  0x92A230
#define CListWnd__EnableLine_x                                     0x929A60
#define CListWnd__EnsureVisible_x                                  0x92D250
#define CListWnd__ExtendSel_x                                      0x92C7E0
#define CListWnd__GetColumnTooltip_x                               0x9295A0
#define CListWnd__GetColumnMinWidth_x                              0x929610
#define CListWnd__GetColumnWidth_x                                 0x929510
#define CListWnd__GetCurSel_x                                      0x928EA0
#define CListWnd__GetItemAtPoint_x                                 0x929CE0
#define CListWnd__GetItemAtPoint1_x                                0x929D50
#define CListWnd__GetItemData_x                                    0x928F20
#define CListWnd__GetItemHeight_x                                  0x9292E0
#define CListWnd__GetItemIcon_x                                    0x9290B0
#define CListWnd__GetItemRect_x                                    0x929B50
#define CListWnd__GetItemText_x                                    0x928F60
#define CListWnd__GetSelList_x                                     0x92C960
#define CListWnd__GetSeparatorRect_x                               0x929F90
#define CListWnd__InsertLine_x                                     0x92C4C0
#define CListWnd__RemoveLine_x                                     0x92C610
#define CListWnd__SetColors_x                                      0x92B860
#define CListWnd__SetColumnJustification_x                         0x92B590
#define CListWnd__SetColumnWidth_x                                 0x92B4B0
#define CListWnd__SetCurSel_x                                      0x92C720
#define CListWnd__SetItemColor_x                                   0x92CF00
#define CListWnd__SetItemData_x                                    0x92CEC0
#define CListWnd__SetItemText_x                                    0x92CAD0
#define CListWnd__ShiftColumnSeparator_x                           0x92B650
#define CListWnd__Sort_x                                           0x92B340
#define CListWnd__ToggleSel_x                                      0x92C750
#define CListWnd__SetColumnsSizable_x                              0x92B700
#define CListWnd__SetItemWnd_x                                     0x92CD80
#define CListWnd__GetItemWnd_x                                     0x929100
#define CListWnd__SetItemIcon_x                                    0x92CB50
#define CListWnd__CalculateCustomWindowPositions_x                 0x92BBB0
#define CListWnd__SetVScrollPos_x                                  0x92B490

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x785F70
#define CMapViewWnd__GetWorldCoordinates_x                         0x784680
#define CMapViewWnd__HandleLButtonDown_x                           0x7816C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A6010
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A68F0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A6E20
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A9DA0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A4B70
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AF960
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A5C20

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8ABEE0
#define CPacketScrambler__hton_x                                   0x8ABED0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9465D0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9469E0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9467D0
#define CSidlManager__CreateLabel_x                                0x807A10
#define CSidlManager__CreateXWndFromTemplate_x                     0x949940
#define CSidlManager__CreateXWndFromTemplate1_x                    0x949B20
#define CSidlManager__CreateXWnd_x                                 0x807940
#define CSidlManager__CreateHotButtonWnd_x                         0x807F10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9430A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x942FA0
#define CSidlScreenWnd__ConvertToRes_x                             0x9685C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x942A30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x942720
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9427F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9428C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x943540
#define CSidlScreenWnd__EnableIniStorage_x                         0x943A10
#define CSidlScreenWnd__GetSidlPiece_x                             0x943730
#define CSidlScreenWnd__Init1_x                                    0x942320
#define CSidlScreenWnd__LoadIniInfo_x                              0x943A60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9445B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x941740
#define CSidlScreenWnd__StoreIniInfo_x                             0x944130
#define CSidlScreenWnd__StoreIniVis_x                              0x944490
#define CSidlScreenWnd__WndNotification_x                          0x943450
#define CSidlScreenWnd__GetChildItem_x                             0x943990
#define CSidlScreenWnd__HandleLButtonUp_x                          0x933170
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F9F50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x684810
#define CSkillMgr__GetSkillCap_x                                   0x6849F0
#define CSkillMgr__GetNameToken_x                                  0x683F90
#define CSkillMgr__IsActivatedSkill_x                              0x6840D0
#define CSkillMgr__IsCombatSkill_x                                 0x684010

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9532B0
#define CSliderWnd__SetValue_x                                     0x953120
#define CSliderWnd__SetNumTicks_x                                  0x953180

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80DA70

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95BAE0
#define CStmlWnd__CalculateHSBRange_x                              0x95CBC0
#define CStmlWnd__CalculateVSBRange_x                              0x95CB30
#define CStmlWnd__CanBreakAtCharacter_x                            0x960F00
#define CStmlWnd__FastForwardToEndOfTag_x                          0x961B90
#define CStmlWnd__ForceParseNow_x                                  0x95C080
#define CStmlWnd__GetNextTagPiece_x                                0x960E60
#define CStmlWnd__GetSTMLText_x                                    0x504DF0
#define CStmlWnd__GetVisibleText_x                                 0x95C0A0
#define CStmlWnd__InitializeWindowVariables_x                      0x9619E0
#define CStmlWnd__MakeStmlColorTag_x                               0x95B150
#define CStmlWnd__MakeWndNotificationTag_x                         0x95B1C0
#define CStmlWnd__SetSTMLText_x                                    0x95A200
#define CStmlWnd__StripFirstSTMLLines_x                            0x962C90
#define CStmlWnd__UpdateHistoryString_x                            0x961DA0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x959350
#define CTabWnd__DrawCurrentPage_x                                 0x959A80
#define CTabWnd__DrawTab_x                                         0x9597A0
#define CTabWnd__GetCurrentPage_x                                  0x958B50
#define CTabWnd__GetPageInnerRect_x                                0x958D90
#define CTabWnd__GetTabInnerRect_x                                 0x958CD0
#define CTabWnd__GetTabRect_x                                      0x958B80
#define CTabWnd__InsertPage_x                                      0x958FA0
#define CTabWnd__SetPage_x                                         0x958E10
#define CTabWnd__SetPageRect_x                                     0x959290
#define CTabWnd__UpdatePage_x                                      0x959660
#define CTabWnd__GetPageFromTabIndex_x                             0x9596E0
#define CTabWnd__GetCurrentTabIndex_x                              0x958B40

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76B0B0
#define CPageWnd__SetTabText_x                                     0x958690

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8DF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x930050
#define CTextureFont__GetTextExtent_x                              0x930210

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B7770
#define CHtmlComponentWnd__ValidateUri_x                           0x749920
#define CHtmlWnd__SetClientCallbacks_x                             0x625280
#define CHtmlWnd__AddObserver_x                                    0x6252A0
#define CHtmlWnd__RemoveObserver_x                                 0x625300
#define Window__getProgress_x                                      0x8617C0
#define Window__getStatus_x                                        0x8617E0
#define Window__getURI_x                                           0x8617F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96E000

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91D110

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8420
#define CXStr__CXStr1_x                                            0x4FFF00
#define CXStr__CXStr3_x                                            0x8FED50
#define CXStr__dCXStr_x                                            0x478780
#define CXStr__operator_equal_x                                    0x8FEF80
#define CXStr__operator_equal1_x                                   0x8FEFC0
#define CXStr__operator_plus_equal1_x                              0x8FFA50
#define CXStr__SetString_x                                         0x901940
#define CXStr__operator_char_p_x                                   0x8FF4C0
#define CXStr__GetChar_x                                           0x901270
#define CXStr__Delete_x                                            0x900B40
#define CXStr__GetUnicode_x                                        0x9012E0
#define CXStr__GetLength_x                                         0x4A8BA0
#define CXStr__Mid_x                                               0x47D400
#define CXStr__Insert_x                                            0x901340
#define CXStr__FindNext_x                                          0x900FB0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x951550
#define CXWnd__BringToTop_x                                        0x936910
#define CXWnd__Center_x                                            0x936490
#define CXWnd__ClrFocus_x                                          0x9362B0
#define CXWnd__Destroy_x                                           0x936350
#define CXWnd__DoAllDrawing_x                                      0x932920
#define CXWnd__DrawChildren_x                                      0x9328F0
#define CXWnd__DrawColoredRect_x                                   0x932D80
#define CXWnd__DrawTooltip_x                                       0x931450
#define CXWnd__DrawTooltipAtPoint_x                                0x931510
#define CXWnd__GetBorderFrame_x                                    0x932BE0
#define CXWnd__GetChildWndAt_x                                     0x9369B0
#define CXWnd__GetClientClipRect_x                                 0x934BB0
#define CXWnd__GetScreenClipRect_x                                 0x934C80
#define CXWnd__GetScreenRect_x                                     0x934E40
#define CXWnd__GetTooltipRect_x                                    0x932DD0
#define CXWnd__GetWindowTextA_x                                    0x49C980
#define CXWnd__IsActive_x                                          0x9334F0
#define CXWnd__IsDescendantOf_x                                    0x935830
#define CXWnd__IsReallyVisible_x                                   0x935860
#define CXWnd__IsType_x                                            0x937020
#define CXWnd__Move_x                                              0x9358C0
#define CXWnd__Move1_x                                             0x935970
#define CXWnd__ProcessTransition_x                                 0x936440
#define CXWnd__Refade_x                                            0x935C40
#define CXWnd__Resize_x                                            0x935ED0
#define CXWnd__Right_x                                             0x9366D0
#define CXWnd__SetFocus_x                                          0x936270
#define CXWnd__SetFont_x                                           0x9362E0
#define CXWnd__SetKeyTooltip_x                                     0x936E40
#define CXWnd__SetMouseOver_x                                      0x933D30
#define CXWnd__StartFade_x                                         0x935720
#define CXWnd__GetChildItem_x                                      0x936B20
#define CXWnd__SetParent_x                                         0x9355E0
#define CXWnd__Minimize_x                                          0x935F40

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x969640

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9398A0
#define CXWndManager__DrawWindows_x                                0x9398C0
#define CXWndManager__GetKeyboardFlags_x                           0x93BFC0
#define CXWndManager__HandleKeyboardMsg_x                          0x93BB70
#define CXWndManager__RemoveWnd_x                                  0x93C1F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93C760

// CDBStr
#define CDBStr__GetString_x                                        0x53C6B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB880
#define EQ_Character__Cur_HP_x                                     0x4D1FA0
#define EQ_Character__Cur_Mana_x                                   0x4D96F0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE8F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2300
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2450
#define EQ_Character__GetHPRegen_x                                 0x4DF4B0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFAB0
#define EQ_Character__GetManaRegen_x                               0x4DFEF0
#define EQ_Character__Max_Endurance_x                              0x64ADE0
#define EQ_Character__Max_HP_x                                     0x4D1DD0
#define EQ_Character__Max_Mana_x                                   0x64ABE0
#define EQ_Character__doCombatAbility_x                            0x64D240
#define EQ_Character__UseSkill_x                                   0x4E1CD0
#define EQ_Character__GetConLevel_x                                0x644170
#define EQ_Character__IsExpansionFlag_x                            0x5A7C70
#define EQ_Character__TotalEffect_x                                0x4C5340
#define EQ_Character__GetPCSpellAffect_x                           0x4BF640
#define EQ_Character__SpellDuration_x                              0x4BF170
#define EQ_Character__GetAdjustedSkill_x                           0x4D4D20
#define EQ_Character__GetBaseSkill_x                               0x4D5CC0
#define EQ_Character__CanUseItem_x                                 0x4D9A00

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CB330

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x661340

//PcClient
#define PcClient__PcClient_x                                       0x6418A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B94D0
#define CCharacterListWnd__EnterWorld_x                            0x4B8F10
#define CCharacterListWnd__Quit_x                                  0x4B8C60
#define CCharacterListWnd__UpdateList_x                            0x4B90A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6264D0
#define EQ_Item__CreateItemTagString_x                             0x8A57B0
#define EQ_Item__IsStackable_x                                     0x8AA2D0
#define EQ_Item__GetImageNum_x                                     0x8A7230
#define EQ_Item__CreateItemClient_x                                0x6256A0
#define EQ_Item__GetItemValue_x                                    0x8A8530
#define EQ_Item__ValueSellMerchant_x                               0x8ABAC0
#define EQ_Item__IsKeyRingItem_x                                   0x8A9BF0
#define EQ_Item__CanGoInBag_x                                      0x6265F0
#define EQ_Item__IsEmpty_x                                         0x8A9730
#define EQ_Item__GetMaxItemCount_x                                 0x8A8940
#define EQ_Item__GetHeldItem_x                                     0x8A7100
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A5140

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55AC10
#define EQ_LoadingS__Array_x                                       0xC28B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64B740
#define EQ_PC__GetAlternateAbilityId_x                             0x8B4D10
#define EQ_PC__GetCombatAbility_x                                  0x8B5380
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B53F0
#define EQ_PC__GetItemRecastTimer_x                                0x64D7C0
#define EQ_PC__HasLoreItem_x                                       0x644930
#define EQ_PC__AlertInventoryChanged_x                             0x643AA0
#define EQ_PC__GetPcZoneClient_x                                   0x66FDE0
#define EQ_PC__RemoveMyAffect_x                                    0x6509F0
#define EQ_PC__GetKeyRingItems_x                                   0x8B5C80
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B5A10
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B5F80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AE1E0
#define EQItemList__add_object_x                                   0x5DBBB0
#define EQItemList__add_item_x                                     0x5AE740
#define EQItemList__delete_item_x                                  0x5AE790
#define EQItemList__FreeItemList_x                                 0x5AE690

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x539160

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x662BC0
#define EQPlayer__dEQPlayer_x                                      0x655F10
#define EQPlayer__DoAttack_x                                       0x66AA70
#define EQPlayer__EQPlayer_x                                       0x6565D0
#define EQPlayer__SetNameSpriteState_x                             0x65A8A0
#define EQPlayer__SetNameSpriteTint_x                              0x65B770
#define PlayerBase__HasProperty_j_x                                0x99BE90
#define EQPlayer__IsTargetable_x                                   0x99C330
#define EQPlayer__CanSee_x                                         0x99C190
#define EQPlayer__CanSee1_x                                        0x99C260
#define PlayerBase__GetVisibilityLineSegment_x                     0x99BF50

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66D870
#define PlayerZoneClient__GetLevel_x                               0x66FE20
#define PlayerZoneClient__IsValidTeleport_x                        0x5DCD20
#define PlayerZoneClient__LegalPlayerRace_x                        0x553F30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x665980
#define EQPlayerManager__GetSpawnByName_x                          0x665A30
#define EQPlayerManager__GetPlayerFromPartialName_x                0x665AC0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x629B30
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x629BB0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x629BF0
#define KeypressHandler__ClearCommandStateArray_x                  0x62B000
#define KeypressHandler__HandleKeyDown_x                           0x62B020
#define KeypressHandler__HandleKeyUp_x                             0x62B0C0
#define KeypressHandler__SaveKeymapping_x                          0x62B510

// MapViewMap 
#define MapViewMap__Clear_x                                        0x781DE0
#define MapViewMap__SaveEx_x                                       0x7851A0
#define MapViewMap__SetZoom_x                                      0x789860

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C9250

// StringTable 
#define StringTable__getString_x                                   0x8C4090

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x650660
#define PcZoneClient__RemovePetEffect_x                            0x650C90
#define PcZoneClient__HasAlternateAbility_x                        0x64AA10
#define PcZoneClient__GetCurrentMod_x                              0x4E4D90
#define PcZoneClient__GetModCap_x                                  0x4E4C90
#define PcZoneClient__CanEquipItem_x                               0x64B0E0
#define PcZoneClient__GetItemByID_x                                0x64DC30
#define PcZoneClient__GetItemByItemClass_x                         0x64DD80
#define PcZoneClient__RemoveBuffEffect_x                           0x650CB0
#define PcZoneClient__BandolierSwap_x                              0x64BD00
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64D760

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E1890

//IconCache
#define IconCache__GetIcon_x                                       0x722330

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x719E10
#define CContainerMgr__CloseContainer_x                            0x71A0E0
#define CContainerMgr__OpenExperimentContainer_x                   0x71AB60

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DA020

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61E620

//CLootWnd
#define CLootWnd__LootAll_x                                        0x778320
#define CLootWnd__RequestLootSlot_x                                0x777550

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57A8E0
#define EQ_Spell__SpellAffects_x                                   0x57AD50
#define EQ_Spell__SpellAffectBase_x                                0x57AB10
#define EQ_Spell__IsStackable_x                                    0x4C99E0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C98C0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B67F0
#define EQ_Spell__IsSPAStacking_x                                  0x57BBA0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57B0B0
#define EQ_Spell__IsNoRemove_x                                     0x4C99C0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57BBB0
#define __IsResEffectSpell_x                                       0x4C8D60

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACEE0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D3910

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x820D40
#define CTargetWnd__WndNotification_x                              0x8205D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8208A0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81F730

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x825340

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536BC0
#define CTaskManager__HandleMessage_x                              0x535050
#define CTaskManager__GetTaskStatus_x                              0x536C70
#define CTaskManager__GetElementDescription_x                      0x536CF0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575E50
#define EqSoundManager__PlayScriptMp3_x                            0x575FB0
#define EqSoundManager__SoundAssistPlay_x                          0x6887A0
#define EqSoundManager__WaveInstancePlay_x                         0x687D10

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52A910

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x957BA0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562650
#define CAltAbilityData__GetMercMaxRank_x                          0x5625E0
#define CAltAbilityData__GetMaxRank_x                              0x557BD0

//CTargetRing
#define CTargetRing__Cast_x                                        0x61C730

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C98A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x511A60
#define CharacterBase__CreateItemIndex_x                           0x624830
#define CharacterBase__GetItemPossession_x                         0x4FD870
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DBF20
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DBF80
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x700F20
#define CCastSpellWnd__IsBardSongPlaying_x                         0x701750
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x701800

//messages
#define msg_spell_worn_off_x                                       0x59FE50
#define msg_new_text_x                                             0x594BE0
#define __msgTokenTextParam_x                                      0x5A2380
#define msgTokenText_x                                             0x5A25D0

//SpellManager
#define SpellManager__vftable_x                                    0xAEE4E4
#define SpellManager__SpellManager_x                               0x68BAD0
#define Spellmanager__LoadTextSpells_x                             0x68C3C0
#define SpellManager__GetSpellByGroupAndRank_x                     0x68BCA0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99FD60

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5120B0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A6120
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63D070
#define ItemGlobalIndex__IsValidIndex_x                            0x512110

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D42B0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D4530

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x770B10

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71E530
#define CCursorAttachment__AttachToCursor1_x                       0x71E570
#define CCursorAttachment__Deactivate_x                            0x71F560

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94A980
#define CSidlManagerBase__CreatePageWnd_x                          0x94A170
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9463F0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x946380

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x967870
#define CEQSuiteTextureLoader__GetTexture_x                        0x967530

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F000
#define CFindItemWnd__WndNotification_x                            0x50FAE0
#define CFindItemWnd__Update_x                                     0x510650
#define CFindItemWnd__PickupSelectedItem_x                         0x50E840

//IString
#define IString__Append_x                                          0x4F0410

//Camera
#define CDisplay__cameraType_x                                     0xE020BC
#define EverQuest__Cameras_x                                       0xEC5A7C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517850
#define LootFiltersManager__GetItemFilterData_x                    0x517150
#define LootFiltersManager__RemoveItemLootFilter_x                 0x517180
#define LootFiltersManager__SetItemLootFilter_x                    0x5173A0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C7FC0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A5880
#define CResolutionHandler__GetWindowedStyle_x                     0x683130

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x716BC0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E9340
#define CDistillerInfo__Instance_x                                 0x8E92E0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x736C90
#define CGroupWnd__UpdateDisplay_x                                 0x735FE0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A9CA0
#define ItemBase__IsLoreEquipped_x                                 0x8A9D10

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DBB10
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DBC50
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DBCB0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678520
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67BE80

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505480

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1F50
#define FactionManagerClient__HandleFactionMessage_x               0x4F25C0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2B80
#define FactionManagerClient__GetMaxFaction_x                      0x4F2B9F
#define FactionManagerClient__GetMinFaction_x                      0x4F2B50

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD840

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92EFD0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BC90

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FDAC0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x561B10

//CTargetManager
#define CTargetManager__Get_x                                      0x68F320

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678520

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8BB0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AE630

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF63110

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
