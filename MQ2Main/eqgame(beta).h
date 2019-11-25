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
#define __ExpectedVersionDate                                     "Nov 25 2019"
#define __ExpectedVersionTime                                     "04:22:20"
#define __ActualVersionDate_x                                      0xB0B2A4
#define __ActualVersionTime_x                                      0xB0B298
#define __ActualVersionBuild_x                                     0xAF6F64

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x630320
#define __MemChecker1_x                                            0x903410
#define __MemChecker2_x                                            0x6BE530
#define __MemChecker3_x                                            0x6BE480
#define __MemChecker4_x                                            0x85A2E0
#define __EncryptPad0_x                                            0xC413E8
#define __EncryptPad1_x                                            0xC9F5E8
#define __EncryptPad2_x                                            0xC51C80
#define __EncryptPad3_x                                            0xC51880
#define __EncryptPad4_x                                            0xC8FC00
#define __EncryptPad5_x                                            0xF6B1C0
#define __AC1_x                                                    0x816D66
#define __AC2_x                                                    0x5EA25F
#define __AC3_x                                                    0x5F195F
#define __AC4_x                                                    0x5F5930
#define __AC5_x                                                    0x5FBC2F
#define __AC6_x                                                    0x600246
#define __AC7_x                                                    0x5E9CD0
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
#define __do_loot_x                                                0x5B5C20
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
#define __gfMaxZoomCameraDistance_x                                0xB00BF8
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
#define pinstCAvaZoneWnd_x                                         0xE02050
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
#define pinstCEventCalendarWnd_x                                   0xE02054
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
#define pinstCItemOverflowWnd_x                                    0xE02098
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
#define pinstCMailCompositionWnd_x                                 0xE0230C
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
#define pinstCStoryWnd_x                                           0xE020B0
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
#define pinstCTradeWnd_x                                           0xE022FC
#define pinstCTrainWnd_x                                           0xE022F4
#define pinstCTributeBenefitWnd_x                                  0xF7EFE0
#define pinstCTributeMasterWnd_x                                   0xF7F090
#define pinstCTributeTrophyWnd_x                                   0xF7F140
#define pinstCVideoModesWnd_x                                      0xE020BC
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
#define __CastRay_x                                                0x5B1090
#define __CastRay2_x                                               0x5B10E0
#define __ConvertItemTags_x                                        0x5CCC20
#define __CleanItemTags_x                                          0x47D190
#define __DoesFileExist_x                                          0x9064F0
#define __EQGetTime_x                                              0x902EE0
#define __ExecuteCmd_x                                             0x5A98B0
#define __FixHeading_x                                             0x99DAB0
#define __GameLoop_x                                               0x6BD720
#define __get_bearing_x                                            0x5B0C00
#define __get_melee_range_x                                        0x5B12D0
#define __GetAnimationCache_x                                      0x7229A0
#define __GetGaugeValueFromEQ_x                                    0x815210
#define __GetLabelFromEQ_x                                         0x816CF0
#define __GetXTargetType_x                                         0x99F500
#define __HandleMouseWheel_x                                       0x6BE5E0
#define __HeadingDiff_x                                            0x99DB20
#define __HelpPath_x                                               0xF637DC
#define __LoadFrontEnd_x                                           0x6BAA40
#define __NewUIINI_x                                               0x814EE0
#define __ProcessGameEvents_x                                      0x611AB0
#define __ProcessMouseEvent_x                                      0x611270
#define __SaveColors_x                                             0x5522B0
#define __STMLToText_x                                             0x940EB0
#define __ToggleKeyRingItem_x                                      0x515550
#define CMemoryMappedFile__SetFile_x                               0xA8CE20
#define CrashDetected_x                                            0x6BC4E0
#define DrawNetStatus_x                                            0x63D4A0
#define Expansion_HoT_x                                            0xEC572C
#define Teleport_Table_Size_x                                      0xEB4760
#define Teleport_Table_x                                           0xEB4BC8
#define Util__FastTime_x                                           0x902AB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490470
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499370
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499140
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A10
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559F70
#define AltAdvManager__IsAbilityReady_x                            0x558EA0
#define AltAdvManager__GetAAById_x                                 0x5590A0
#define AltAdvManager__CanTrainAbility_x                           0x559110
#define AltAdvManager__CanSeeAbility_x                             0x559470

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA010
#define CharacterZoneClient__HasSkill_x                            0x4D4F00
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6620
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE2B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA8B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8FD0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D90B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9190
#define CharacterZoneClient__FindAffectSlot_x                      0x4C30B0
#define CharacterZoneClient__BardCastBard_x                        0x4C5C10
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA980
#define CharacterZoneClient__GetEffect_x                           0x4BA7F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4100
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C41D0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4220
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4370
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4540
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B27A0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7580
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7000

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E4150
#define CBankWnd__WndNotification_x                                0x6E3F30

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F19E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6200F0
#define CButtonWnd__CButtonWnd_x                                   0x93D250

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x711B10
#define CChatManager__InitContextMenu_x                            0x70AC60
#define CChatManager__FreeChatWindow_x                             0x710650
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E86D0
#define CChatManager__SetLockedActiveChatWindow_x                  0x711790
#define CChatManager__CreateChatWindow_x                           0x710C90

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E87E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x951900
#define CContextMenu__dCContextMenu_x                              0x951B40
#define CContextMenu__AddMenuItem_x                                0x951B50
#define CContextMenu__RemoveMenuItem_x                             0x951E60
#define CContextMenu__RemoveAllMenuItems_x                         0x951E80
#define CContextMenu__CheckMenuItem_x                              0x951F00
#define CContextMenu__SetMenuItem_x                                0x951D80
#define CContextMenu__AddSeparator_x                               0x951CE0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x952490
#define CContextMenuManager__RemoveMenu_x                          0x952500
#define CContextMenuManager__PopupMenu_x                           0x9525C0
#define CContextMenuManager__Flush_x                               0x952430
#define CContextMenuManager__GetMenu_x                             0x49B490
#define CContextMenuManager__CreateDefaultMenu_x                   0x71D1A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DE710
#define CChatService__GetFriendName_x                              0x8DE720

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x712380
#define CChatWindow__Clear_x                                       0x713650
#define CChatWindow__WndNotification_x                             0x713DE0
#define CChatWindow__AddHistory_x                                  0x712F10

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94ED50
#define CComboWnd__Draw_x                                          0x94E240
#define CComboWnd__GetCurChoice_x                                  0x94EB90
#define CComboWnd__GetListRect_x                                   0x94E6F0
#define CComboWnd__GetTextRect_x                                   0x94EDC0
#define CComboWnd__InsertChoice_x                                  0x94E880
#define CComboWnd__SetColors_x                                     0x94E850
#define CComboWnd__SetChoice_x                                     0x94EB60
#define CComboWnd__GetItemCount_x                                  0x94EBA0
#define CComboWnd__GetCurChoiceText_x                              0x94EBE0
#define CComboWnd__GetChoiceText_x                                 0x94EBB0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94E920

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71AB90
#define CContainerWnd__vftable_x                                   0xB14494
#define CContainerWnd__SetContainer_x                              0x71C100

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54CCF0
#define CDisplay__PreZoneMainUI_x                                  0x54CD00
#define CDisplay__CleanGameUI_x                                    0x552070
#define CDisplay__GetClickedActor_x                                0x545010
#define CDisplay__GetUserDefinedColor_x                            0x53D6D0
#define CDisplay__GetWorldFilePath_x                               0x546A80
#define CDisplay__is3dON_x                                         0x541C70
#define CDisplay__ReloadUI_x                                       0x54C180
#define CDisplay__WriteTextHD2_x                                   0x541A60
#define CDisplay__TrueDistance_x                                   0x548740
#define CDisplay__SetViewActor_x                                   0x544930
#define CDisplay__GetFloorHeight_x                                 0x541D30
#define CDisplay__SetRenderWindow_x                                0x540690
#define CDisplay__ToggleScreenshotMode_x                           0x544400

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x971530

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x954E7F
#define CEditWnd__GetCharIndexPt_x                                 0x955DC0
#define CEditWnd__GetDisplayString_x                               0x955C60
#define CEditWnd__GetHorzOffset_x                                  0x9544B0
#define CEditWnd__GetLineForPrintableChar_x                        0x956F60
#define CEditWnd__GetSelStartPt_x                                  0x956070
#define CEditWnd__GetSTMLSafeText_x                                0x955A80
#define CEditWnd__PointFromPrintableChar_x                         0x956B90
#define CEditWnd__SelectableCharFromPoint_x                        0x956D00
#define CEditWnd__SetEditable_x                                    0x956140
#define CEditWnd__SetWindowTextA_x                                 0x955800

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FF720
#define CEverQuest__ClickedPlayer_x                                0x5F1740
#define CEverQuest__CreateTargetIndicator_x                        0x60ED50
#define CEverQuest__DeleteTargetIndicator_x                        0x60EDE0
#define CEverQuest__DoTellWindow_x                                 0x4E88C0
#define CEverQuest__OutputTextToLog_x                              0x4E8B40
#define CEverQuest__DropHeldItemOnGround_x                         0x5E6780
#define CEverQuest__dsp_chat_x                                     0x4E8ED0
#define CEverQuest__trimName_x                                     0x60B030
#define CEverQuest__Emote_x                                        0x5FFF80
#define CEverQuest__EnterZone_x                                    0x5F9F10
#define CEverQuest__GetBodyTypeDesc_x                              0x6048F0
#define CEverQuest__GetClassDesc_x                                 0x604F30
#define CEverQuest__GetClassThreeLetterCode_x                      0x605530
#define CEverQuest__GetDeityDesc_x                                 0x60D690
#define CEverQuest__GetLangDesc_x                                  0x6056F0
#define CEverQuest__GetRaceDesc_x                                  0x604F10
#define CEverQuest__InterpretCmd_x                                 0x60DC60
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EA980
#define CEverQuest__LMouseUp_x                                     0x5E8D10
#define CEverQuest__RightClickedOnPlayer_x                         0x5EB260
#define CEverQuest__RMouseUp_x                                     0x5E9C90
#define CEverQuest__SetGameState_x                                 0x5E6510
#define CEverQuest__UPCNotificationFlush_x                         0x60AF30
#define CEverQuest__IssuePetCommand_x                              0x606AF0
#define CEverQuest__ReportSuccessfulHit_x                          0x601370

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72CA30
#define CGaugeWnd__CalcLinesFillRect_x                             0x72CA90
#define CGaugeWnd__Draw_x                                          0x72C0B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF260
#define CGuild__GetGuildName_x                                     0x4AE340
#define CGuild__GetGuildIndex_x                                    0x4AE6D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x747EA0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6204B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x754E60
#define CInvSlotMgr__MoveItem_x                                    0x753BC0
#define CInvSlotMgr__SelectSlot_x                                  0x754F30

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x752440
#define CInvSlot__SliderComplete_x                                 0x750190
#define CInvSlot__GetItemBase_x                                    0x74FB20
#define CInvSlot__UpdateItem_x                                     0x74FC90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7569B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x755B50
#define CInvSlotWnd__HandleLButtonUp_x                             0x756530

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x810590
#define CItemDisplayWnd__UpdateStrings_x                           0x765110
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75EE60
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75F380
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x765720
#define CItemDisplayWnd__AboutToShow_x                             0x764D60
#define CItemDisplayWnd__WndNotification_x                         0x7667F0
#define CItemDisplayWnd__RequestConvertItem_x                      0x7662C0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x763DC0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x764B80

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x848EA0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76AD40

// CLabel 
#define CLabel__Draw_x                                             0x770730

// CListWnd
#define CListWnd__CListWnd_x                                       0x9274B0
#define CListWnd__dCListWnd_x                                      0x9277E0
#define CListWnd__AddColumn_x                                      0x92BC10
#define CListWnd__AddColumn1_x                                     0x92BC60
#define CListWnd__AddLine_x                                        0x92BFF0
#define CListWnd__AddString_x                                      0x92BDF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92B9D0
#define CListWnd__CalculateVSBRange_x                              0x92B7D0
#define CListWnd__ClearSel_x                                       0x92C7D0
#define CListWnd__ClearAllSel_x                                    0x92C830
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92D250
#define CListWnd__Compare_x                                        0x92B100
#define CListWnd__Draw_x                                           0x927910
#define CListWnd__DrawColumnSeparators_x                           0x92A0E0
#define CListWnd__DrawHeader_x                                     0x92A540
#define CListWnd__DrawItem_x                                       0x92AA40
#define CListWnd__DrawLine_x                                       0x92A240
#define CListWnd__DrawSeparator_x                                  0x92A180
#define CListWnd__EnableLine_x                                     0x9299D0
#define CListWnd__EnsureVisible_x                                  0x92D170
#define CListWnd__ExtendSel_x                                      0x92C700
#define CListWnd__GetColumnTooltip_x                               0x929510
#define CListWnd__GetColumnMinWidth_x                              0x929580
#define CListWnd__GetColumnWidth_x                                 0x929480
#define CListWnd__GetCurSel_x                                      0x928E10
#define CListWnd__GetItemAtPoint_x                                 0x929C40
#define CListWnd__GetItemAtPoint1_x                                0x929CB0
#define CListWnd__GetItemData_x                                    0x928E90
#define CListWnd__GetItemHeight_x                                  0x929250
#define CListWnd__GetItemIcon_x                                    0x929020
#define CListWnd__GetItemRect_x                                    0x929AC0
#define CListWnd__GetItemText_x                                    0x928ED0
#define CListWnd__GetSelList_x                                     0x92C880
#define CListWnd__GetSeparatorRect_x                               0x929EF0
#define CListWnd__InsertLine_x                                     0x92C3E0
#define CListWnd__RemoveLine_x                                     0x92C530
#define CListWnd__SetColors_x                                      0x92B7A0
#define CListWnd__SetColumnJustification_x                         0x92B4D0
#define CListWnd__SetColumnWidth_x                                 0x92B3F0
#define CListWnd__SetCurSel_x                                      0x92C640
#define CListWnd__SetItemColor_x                                   0x92CE20
#define CListWnd__SetItemData_x                                    0x92CDE0
#define CListWnd__SetItemText_x                                    0x92C9F0
#define CListWnd__ShiftColumnSeparator_x                           0x92B590
#define CListWnd__Sort_x                                           0x92B280
#define CListWnd__ToggleSel_x                                      0x92C670
#define CListWnd__SetColumnsSizable_x                              0x92B640
#define CListWnd__SetItemWnd_x                                     0x92CCA0
#define CListWnd__GetItemWnd_x                                     0x929070
#define CListWnd__SetItemIcon_x                                    0x92CA70
#define CListWnd__CalculateCustomWindowPositions_x                 0x92BAD0
#define CListWnd__SetVScrollPos_x                                  0x92B3D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x785DB0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7844C0
#define CMapViewWnd__HandleLButtonDown_x                           0x781500

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A5E30
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A6710
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A6C40
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A9BC0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A49A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AF780
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A5A50

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AC130
#define CPacketScrambler__hton_x                                   0x8AC120

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x946490
#define CSidlManager__FindScreenPieceTemplate_x                    0x9468A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x946690
#define CSidlManager__CreateLabel_x                                0x8079B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x949800
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9499E0
#define CSidlManager__CreateXWnd_x                                 0x8078E0
#define CSidlManager__CreateHotButtonWnd_x                         0x807EA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x942FA0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x942EA0
#define CSidlScreenWnd__ConvertToRes_x                             0x968510
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x942930
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x942620
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9426F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9427C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x943420
#define CSidlScreenWnd__EnableIniStorage_x                         0x9438F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x943610
#define CSidlScreenWnd__Init1_x                                    0x942240
#define CSidlScreenWnd__LoadIniInfo_x                              0x943940
#define CSidlScreenWnd__LoadIniListWnd_x                           0x944470
#define CSidlScreenWnd__LoadSidlScreen_x                           0x941660
#define CSidlScreenWnd__StoreIniInfo_x                             0x943FF0
#define CSidlScreenWnd__StoreIniVis_x                              0x944350
#define CSidlScreenWnd__WndNotification_x                          0x943330
#define CSidlScreenWnd__GetChildItem_x                             0x943870
#define CSidlScreenWnd__HandleLButtonUp_x                          0x933080
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F9F50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6849F0
#define CSkillMgr__GetSkillCap_x                                   0x684BD0
#define CSkillMgr__GetNameToken_x                                  0x684170
#define CSkillMgr__IsActivatedSkill_x                              0x6842B0
#define CSkillMgr__IsCombatSkill_x                                 0x6841F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x953290
#define CSliderWnd__SetValue_x                                     0x953100
#define CSliderWnd__SetNumTicks_x                                  0x953160

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80DA20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95BAC0
#define CStmlWnd__CalculateHSBRange_x                              0x95CBE0
#define CStmlWnd__CalculateVSBRange_x                              0x95CB50
#define CStmlWnd__CanBreakAtCharacter_x                            0x960F10
#define CStmlWnd__FastForwardToEndOfTag_x                          0x961BA0
#define CStmlWnd__ForceParseNow_x                                  0x95C0B0
#define CStmlWnd__GetNextTagPiece_x                                0x960E70
#define CStmlWnd__GetSTMLText_x                                    0x504D70
#define CStmlWnd__GetVisibleText_x                                 0x95C0D0
#define CStmlWnd__InitializeWindowVariables_x                      0x9619F0
#define CStmlWnd__MakeStmlColorTag_x                               0x95B130
#define CStmlWnd__MakeWndNotificationTag_x                         0x95B1A0
#define CStmlWnd__SetSTMLText_x                                    0x95A1E0
#define CStmlWnd__StripFirstSTMLLines_x                            0x962C70
#define CStmlWnd__UpdateHistoryString_x                            0x961DB0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x959330
#define CTabWnd__DrawCurrentPage_x                                 0x959A60
#define CTabWnd__DrawTab_x                                         0x959780
#define CTabWnd__GetCurrentPage_x                                  0x958B30
#define CTabWnd__GetPageInnerRect_x                                0x958D70
#define CTabWnd__GetTabInnerRect_x                                 0x958CB0
#define CTabWnd__GetTabRect_x                                      0x958B60
#define CTabWnd__InsertPage_x                                      0x958F80
#define CTabWnd__SetPage_x                                         0x958DF0
#define CTabWnd__SetPageRect_x                                     0x959270
#define CTabWnd__UpdatePage_x                                      0x959640
#define CTabWnd__GetPageFromTabIndex_x                             0x9596C0
#define CTabWnd__GetCurrentTabIndex_x                              0x958B20

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76B110
#define CPageWnd__SetTabText_x                                     0x958670

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8EE0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92FF40
#define CTextureFont__GetTextExtent_x                              0x930100

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B78C0
#define CHtmlComponentWnd__ValidateUri_x                           0x749890
#define CHtmlWnd__SetClientCallbacks_x                             0x625540
#define CHtmlWnd__AddObserver_x                                    0x625560
#define CHtmlWnd__RemoveObserver_x                                 0x6255C0
#define Window__getProgress_x                                      0x861920
#define Window__getStatus_x                                        0x861940
#define Window__getURI_x                                           0x861950

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96DFC0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91D1A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8510
#define CXStr__CXStr1_x                                            0x9F42F0
#define CXStr__CXStr3_x                                            0x8FF020
#define CXStr__dCXStr_x                                            0x478780
#define CXStr__operator_equal_x                                    0x8FF250
#define CXStr__operator_equal1_x                                   0x8FF290
#define CXStr__operator_plus_equal1_x                              0x8FFD20
#define CXStr__SetString_x                                         0x901C10
#define CXStr__operator_char_p_x                                   0x8FF790
#define CXStr__GetChar_x                                           0x901540
#define CXStr__Delete_x                                            0x900E10
#define CXStr__GetUnicode_x                                        0x9015B0
#define CXStr__GetLength_x                                         0x47D540
#define CXStr__Mid_x                                               0x47D550
#define CXStr__Insert_x                                            0x901610
#define CXStr__FindNext_x                                          0x901280

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x951510
#define CXWnd__BringToTop_x                                        0x9367B0
#define CXWnd__Center_x                                            0x936330
#define CXWnd__ClrFocus_x                                          0x936140
#define CXWnd__Destroy_x                                           0x9361F0
#define CXWnd__DoAllDrawing_x                                      0x932810
#define CXWnd__DrawChildren_x                                      0x9327E0
#define CXWnd__DrawColoredRect_x                                   0x932C70
#define CXWnd__DrawTooltip_x                                       0x931330
#define CXWnd__DrawTooltipAtPoint_x                                0x9313F0
#define CXWnd__GetBorderFrame_x                                    0x932AD0
#define CXWnd__GetChildWndAt_x                                     0x936850
#define CXWnd__GetClientClipRect_x                                 0x934A20
#define CXWnd__GetScreenClipRect_x                                 0x934AF0
#define CXWnd__GetScreenRect_x                                     0x934CB0
#define CXWnd__GetTooltipRect_x                                    0x932CC0
#define CXWnd__GetWindowTextA_x                                    0x49CC00
#define CXWnd__IsActive_x                                          0x933400
#define CXWnd__IsDescendantOf_x                                    0x9356B0
#define CXWnd__IsReallyVisible_x                                   0x9356E0
#define CXWnd__IsType_x                                            0x936EB0
#define CXWnd__Move_x                                              0x935740
#define CXWnd__Move1_x                                             0x9357F0
#define CXWnd__ProcessTransition_x                                 0x9362E0
#define CXWnd__Refade_x                                            0x935AC0
#define CXWnd__Resize_x                                            0x935D50
#define CXWnd__Right_x                                             0x936570
#define CXWnd__SetFocus_x                                          0x936100
#define CXWnd__SetFont_x                                           0x936170
#define CXWnd__SetKeyTooltip_x                                     0x936CD0
#define CXWnd__SetMouseOver_x                                      0x933C20
#define CXWnd__StartFade_x                                         0x935590
#define CXWnd__GetChildItem_x                                      0x9369C0
#define CXWnd__SetParent_x                                         0x935450
#define CXWnd__Minimize_x                                          0x935DC0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9695A0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9396A0
#define CXWndManager__DrawWindows_x                                0x9396C0
#define CXWndManager__GetKeyboardFlags_x                           0x93BEB0
#define CXWndManager__HandleKeyboardMsg_x                          0x93BA60
#define CXWndManager__RemoveWnd_x                                  0x93C0D0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93C620

// CDBStr
#define CDBStr__GetString_x                                        0x53C670

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB890
#define EQ_Character__Cur_HP_x                                     0x4D1F40
#define EQ_Character__Cur_Mana_x                                   0x4D9690
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE900
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B23E0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2530
#define EQ_Character__GetHPRegen_x                                 0x4DF460
#define EQ_Character__GetEnduranceRegen_x                          0x4DFA60
#define EQ_Character__GetManaRegen_x                               0x4DFEA0
#define EQ_Character__Max_Endurance_x                              0x64B220
#define EQ_Character__Max_HP_x                                     0x4D1D70
#define EQ_Character__Max_Mana_x                                   0x64B020
#define EQ_Character__doCombatAbility_x                            0x64D680
#define EQ_Character__UseSkill_x                                   0x4E1C80
#define EQ_Character__GetConLevel_x                                0x644410
#define EQ_Character__IsExpansionFlag_x                            0x5A8050
#define EQ_Character__TotalEffect_x                                0x4C5350
#define EQ_Character__GetPCSpellAffect_x                           0x4BF650
#define EQ_Character__SpellDuration_x                              0x4BF180
#define EQ_Character__GetAdjustedSkill_x                           0x4D4CC0
#define EQ_Character__GetBaseSkill_x                               0x4D5C60
#define EQ_Character__CanUseItem_x                                 0x4D99A0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CB560

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x661790

//PcClient
#define PcClient__PcClient_x                                       0x641B50

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9500
#define CCharacterListWnd__EnterWorld_x                            0x4B8F40
#define CCharacterListWnd__Quit_x                                  0x4B8C90
#define CCharacterListWnd__UpdateList_x                            0x4B90D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6267A0
#define EQ_Item__CreateItemTagString_x                             0x8A5930
#define EQ_Item__IsStackable_x                                     0x8AA4D0
#define EQ_Item__GetImageNum_x                                     0x8A73C0
#define EQ_Item__CreateItemClient_x                                0x625960
#define EQ_Item__GetItemValue_x                                    0x8A86C0
#define EQ_Item__ValueSellMerchant_x                               0x8ABD10
#define EQ_Item__IsKeyRingItem_x                                   0x8A9DD0
#define EQ_Item__CanGoInBag_x                                      0x6268C0
#define EQ_Item__IsEmpty_x                                         0x8A9920
#define EQ_Item__GetMaxItemCount_x                                 0x8A8AE0
#define EQ_Item__GetHeldItem_x                                     0x8A7290
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A52A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55AC40
#define EQ_LoadingS__Array_x                                       0xC28B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64BB80
#define EQ_PC__GetAlternateAbilityId_x                             0x8B4F10
#define EQ_PC__GetCombatAbility_x                                  0x8B5580
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B55F0
#define EQ_PC__GetItemRecastTimer_x                                0x64DC00
#define EQ_PC__HasLoreItem_x                                       0x644BD0
#define EQ_PC__AlertInventoryChanged_x                             0x643D50
#define EQ_PC__GetPcZoneClient_x                                   0x6702C0
#define EQ_PC__RemoveMyAffect_x                                    0x650E30
#define EQ_PC__GetKeyRingItems_x                                   0x8B5E80
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B5C10
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B6180

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AE5E0
#define EQItemList__add_object_x                                   0x5DBF10
#define EQItemList__add_item_x                                     0x5AEB40
#define EQItemList__delete_item_x                                  0x5AEB90
#define EQItemList__FreeItemList_x                                 0x5AEA90

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x539120

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x663010
#define EQPlayer__dEQPlayer_x                                      0x656370
#define EQPlayer__DoAttack_x                                       0x66AF50
#define EQPlayer__EQPlayer_x                                       0x656A30
#define EQPlayer__SetNameSpriteState_x                             0x65ACF0
#define EQPlayer__SetNameSpriteTint_x                              0x65BBC0
#define PlayerBase__HasProperty_j_x                                0x99BEA0
#define EQPlayer__IsTargetable_x                                   0x99C340
#define EQPlayer__CanSee_x                                         0x99C1A0
#define EQPlayer__CanSee1_x                                        0x99C270
#define PlayerBase__GetVisibilityLineSegment_x                     0x99BF60

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66DD50
#define PlayerZoneClient__GetLevel_x                               0x670300
#define PlayerZoneClient__IsValidTeleport_x                        0x5DD080
#define PlayerZoneClient__LegalPlayerRace_x                        0x553F20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x665E60
#define EQPlayerManager__GetSpawnByName_x                          0x665F10
#define EQPlayerManager__GetPlayerFromPartialName_x                0x665FA0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x629DF0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x629E70
#define KeypressHandler__AttachKeyToEqCommand_x                    0x629EB0
#define KeypressHandler__ClearCommandStateArray_x                  0x62B2C0
#define KeypressHandler__HandleKeyDown_x                           0x62B2E0
#define KeypressHandler__HandleKeyUp_x                             0x62B380
#define KeypressHandler__SaveKeymapping_x                          0x62B7D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x781C20
#define MapViewMap__SaveEx_x                                       0x784FE0
#define MapViewMap__SetZoom_x                                      0x7896A0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C93D0

// StringTable 
#define StringTable__getString_x                                   0x8C4210

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x650AA0
#define PcZoneClient__RemovePetEffect_x                            0x6510D0
#define PcZoneClient__HasAlternateAbility_x                        0x64AE50
#define PcZoneClient__GetCurrentMod_x                              0x4E4D40
#define PcZoneClient__GetModCap_x                                  0x4E4C40
#define PcZoneClient__CanEquipItem_x                               0x64B520
#define PcZoneClient__GetItemByID_x                                0x64E070
#define PcZoneClient__GetItemByItemClass_x                         0x64E1C0
#define PcZoneClient__RemoveBuffEffect_x                           0x6510F0
#define PcZoneClient__BandolierSwap_x                              0x64C140
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64DBA0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E1C70

//IconCache
#define IconCache__GetIcon_x                                       0x722240

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x719D30
#define CContainerMgr__CloseContainer_x                            0x71A000
#define CContainerMgr__OpenExperimentContainer_x                   0x71AA80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D9D70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61E8B0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x778210
#define CLootWnd__RequestLootSlot_x                                0x777440

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57AAE0
#define EQ_Spell__SpellAffects_x                                   0x57AF50
#define EQ_Spell__SpellAffectBase_x                                0x57AD10
#define EQ_Spell__IsStackable_x                                    0x4C9980
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C97D0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B68B0
#define EQ_Spell__IsSPAStacking_x                                  0x57BDA0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57B2B0
#define EQ_Spell__IsNoRemove_x                                     0x4C9960
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57BDB0
#define __IsResEffectSpell_x                                       0x4C8D70

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACF90

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D3B90

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x820D20
#define CTargetWnd__WndNotification_x                              0x8205B0
#define CTargetWnd__RefreshTargetBuffs_x                           0x820880
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81F710

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x825320

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536B20
#define CTaskManager__HandleMessage_x                              0x534FC0
#define CTaskManager__GetTaskStatus_x                              0x536BD0
#define CTaskManager__GetElementDescription_x                      0x536C50

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575F90
#define EqSoundManager__PlayScriptMp3_x                            0x5760F0
#define EqSoundManager__SoundAssistPlay_x                          0x6888E0
#define EqSoundManager__WaveInstancePlay_x                         0x687E50

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52A8C0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x957B80

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562600
#define CAltAbilityData__GetMercMaxRank_x                          0x562590
#define CAltAbilityData__GetMaxRank_x                              0x557D20

//CTargetRing
#define CTargetRing__Cast_x                                        0x61C9C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C97B0
#define CharacterBase__CreateItemGlobalIndex_x                     0x511B30
#define CharacterBase__CreateItemIndex_x                           0x624AF0
#define CharacterBase__GetItemPossession_x                         0x4FD750
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DC1A0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DC200
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x700EF0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x701720
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x7017D0

//messages
#define msg_spell_worn_off_x                                       0x5A0140
#define msg_new_text_x                                             0x594ED0
#define __msgTokenTextParam_x                                      0x5A2670
#define msgTokenText_x                                             0x5A28C0

//SpellManager
#define SpellManager__vftable_x                                    0xAEE4DC
#define SpellManager__SpellManager_x                               0x68BC10
#define Spellmanager__LoadTextSpells_x                             0x68C500
#define SpellManager__GetSpellByGroupAndRank_x                     0x68BDE0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99FDF0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x512180
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A6440
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63D300
#define ItemGlobalIndex__IsValidIndex_x                            0x5121E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D4530
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D47B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x770A70

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71E440
#define CCursorAttachment__AttachToCursor1_x                       0x71E480
#define CCursorAttachment__Deactivate_x                            0x71F470

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94A830
#define CSidlManagerBase__CreatePageWnd_x                          0x94A030
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9462B0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x946240

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x967850
#define CEQSuiteTextureLoader__GetTexture_x                        0x967510

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F0D0
#define CFindItemWnd__WndNotification_x                            0x50FBB0
#define CFindItemWnd__Update_x                                     0x510720
#define CFindItemWnd__PickupSelectedItem_x                         0x50E910

//IString
#define IString__Append_x                                          0x4F0450

//Camera
#define CDisplay__cameraType_x                                     0xE020D0
#define EverQuest__Cameras_x                                       0xEC5A7C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5178E0
#define LootFiltersManager__GetItemFilterData_x                    0x5171F0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x517220
#define LootFiltersManager__SetItemLootFilter_x                    0x517440

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C7D50

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A5990
#define CResolutionHandler__GetWindowedStyle_x                     0x683450

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x716AF0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E95E0
#define CDistillerInfo__Instance_x                                 0x8E9580

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x736C60
#define CGroupWnd__UpdateDisplay_x                                 0x735FB0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A9E80
#define ItemBase__IsLoreEquipped_x                                 0x8A9F00

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DBE70
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DBFB0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DC010

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678A50
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67C3C0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x5054C0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1F20
#define FactionManagerClient__HandleFactionMessage_x               0x4F2590
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2B90
#define FactionManagerClient__GetMaxFaction_x                      0x4F2BAF
#define FactionManagerClient__GetMinFaction_x                      0x4F2B60

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD720

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92EEF0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BF10

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FDA70

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x561AC0

//CTargetManager
#define CTargetManager__Get_x                                      0x68F430

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678A50

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8CA0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AEA30

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF63110

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
