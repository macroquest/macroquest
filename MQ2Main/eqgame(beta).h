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
#define __ExpectedVersionDate                                     "Dec  4 2019"
#define __ExpectedVersionTime                                     "04:23:08"
#define __ActualVersionDate_x                                      0xB0B34C
#define __ActualVersionTime_x                                      0xB0B340
#define __ActualVersionBuild_x                                     0xAF6FCC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62FB80
#define __MemChecker1_x                                            0x902EE0
#define __MemChecker2_x                                            0x6BE450
#define __MemChecker3_x                                            0x6BE3A0
#define __MemChecker4_x                                            0x859A20
#define __EncryptPad0_x                                            0xC413E8
#define __EncryptPad1_x                                            0xC9F5E8
#define __EncryptPad2_x                                            0xC51C80
#define __EncryptPad3_x                                            0xC51880
#define __EncryptPad4_x                                            0xC8FC00
#define __EncryptPad5_x                                            0xF6B1D0
#define __AC1_x                                                    0x8168A6
#define __AC2_x                                                    0x5E9ADF
#define __AC3_x                                                    0x5F11DF
#define __AC4_x                                                    0x5F51B0
#define __AC5_x                                                    0x5FB4BF
#define __AC6_x                                                    0x5FFAD6
#define __AC7_x                                                    0x5E9550
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191A2C

// Direct Input
#define DI8__Main_x                                                0xF6B1F8
#define DI8__Keyboard_x                                            0xF6B1FC
#define DI8__Mouse_x                                               0xF6B1DC
#define DI8__Mouse_Copy_x                                          0xEC43DC
#define DI8__Mouse_Check_x                                         0xF68D24
#define __AutoSkillArray_x                                         0xEC52F4
#define __Attack_x                                                 0xF6311B
#define __Autofire_x                                               0xF6311C
#define __BindList_x                                               0xC2FE20
#define g_eqCommandStates_x                                        0xC30BA0
#define __Clicks_x                                                 0xEC4494
#define __CommandList_x                                            0xC31760
#define __CurrentMapLabel_x                                        0xF7BB9C
#define __CurrentSocial_x                                          0xC197CC
#define __DoAbilityList_x                                          0xEFAC3C
#define __do_loot_x                                                0x5B53C0
#define __DrawHandler_x                                            0x15FAF10
#define __GroupCount_x                                             0xEB6D22
#define __Guilds_x                                                 0xEBABE8
#define __gWorld_x                                                 0xEB6BD8
#define __HWnd_x                                                   0xF6B1E0
#define __heqmain_x                                                0xF6B1B8
#define __InChatMode_x                                             0xEC43C4
#define __LastTell_x                                               0xEC6338
#define __LMouseHeldTime_x                                         0xEC4500
#define __Mouse_x                                                  0xF6B1E4
#define __MouseLook_x                                              0xEC445A
#define __MouseEventTime_x                                         0xF63BFC
#define __gpbCommandEvent_x                                        0xEB4678
#define __NetStatusToggle_x                                        0xEC445D
#define __PCNames_x                                                0xEC58E4
#define __RangeAttackReady_x                                       0xEC55D8
#define __RMouseHeldTime_x                                         0xEC44FC
#define __RunWalkState_x                                           0xEC43C8
#define __ScreenMode_x                                             0xE0242C
#define __ScreenX_x                                                0xEC437C
#define __ScreenY_x                                                0xEC4378
#define __ScreenXMax_x                                             0xEC4380
#define __ScreenYMax_x                                             0xEC4384
#define __ServerHost_x                                             0xEB48AB
#define __ServerName_x                                             0xEFABFC
#define __ShiftKeyDown_x                                           0xEC4A54
#define __ShowNames_x                                              0xEC5794
#define __Socials_x                                                0xEFACFC
#define __SubscriptionType_x                                       0xFC00A0
#define __TargetAggroHolder_x                                      0xF7E550
#define __ZoneType_x                                               0xEC4858
#define __GroupAggro_x                                             0xF7E590
#define __LoginName_x                                              0xF6B94C
#define __Inviter_x                                                0xF63098
#define __AttackOnAssist_x                                         0xEC5750
#define __UseTellWindows_x                                         0xEC5A80
#define __gfMaxZoomCameraDistance_x                                0xB00C60
#define __gfMaxCameraDistance_x                                    0xB2D1AC
#define __pulAutoRun_x                                             0xEC4478
#define __pulForward_x                                             0xEC5AB8
#define __pulBackward_x                                            0xEC5ABC
#define __pulTurnRight_x                                           0xEC5AC0
#define __pulTurnLeft_x                                            0xEC5AC4
#define __pulStrafeLeft_x                                          0xEC5AC8
#define __pulStrafeRight_x                                         0xEC5ACC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB6F80
#define instEQZoneInfo_x                                           0xEC4650
#define pinstActiveBanker_x                                        0xEB4690
#define pinstActiveCorpse_x                                        0xEB4688
#define pinstActiveGMaster_x                                       0xEB468C
#define pinstActiveMerchant_x                                      0xEB4684
#define pinstAltAdvManager_x                                       0xE031B8
#define pinstBandageTarget_x                                       0xEB46A0
#define pinstCamActor_x                                            0xE02420
#define pinstCDBStr_x                                              0xE01ED4
#define pinstCDisplay_x                                            0xEB6BD4
#define pinstCEverQuest_x                                          0xF6B210
#define pinstEverQuestInfo_x                                       0xEC4370
#define pinstCharData_x                                            0xEB6D04
#define pinstCharSpawn_x                                           0xEB46D8
#define pinstControlledMissile_x                                   0xEB4BC4
#define pinstControlledPlayer_x                                    0xEB46D8
#define pinstCResolutionHandler_x                                  0x15FB140
#define pinstCSidlManager_x                                        0x15FA0D8
#define pinstCXWndManager_x                                        0x15FA0D4
#define instDynamicZone_x                                          0xEBAAC0
#define pinstDZMember_x                                            0xEBABD0
#define pinstDZTimerInfo_x                                         0xEBABD4
#define pinstEqLogin_x                                             0xF6B298
#define instEQMisc_x                                               0xE01E18
#define pinstEQSoundManager_x                                      0xE04188
#define pinstEQSpellStrings_x                                      0xCC4878
#define instExpeditionLeader_x                                     0xEBAB0A
#define instExpeditionName_x                                       0xEBAB4A
#define pinstGroup_x                                               0xEB6D1E
#define pinstImeManager_x                                          0x15FA0D0
#define pinstLocalPlayer_x                                         0xEB4680
#define pinstMercenaryData_x                                       0xF656EC
#define pinstMercenaryStats_x                                      0xF7E69C
#define pinstModelPlayer_x                                         0xEB4698
#define pinstPCData_x                                              0xEB6D04
#define pinstSkillMgr_x                                            0xF67858
#define pinstSpawnManager_x                                        0xF66300
#define pinstSpellManager_x                                        0xF67A78
#define pinstSpellSets_x                                           0xF5BD44
#define pinstStringTable_x                                         0xEB6D08
#define pinstSwitchManager_x                                       0xEB4520
#define pinstTarget_x                                              0xEB46D4
#define pinstTargetObject_x                                        0xEB4760
#define pinstTargetSwitch_x                                        0xEB4BCC
#define pinstTaskMember_x                                          0xE01CA8
#define pinstTrackTarget_x                                         0xEB46DC
#define pinstTradeTarget_x                                         0xEB4694
#define instTributeActive_x                                        0xE01E39
#define pinstViewActor_x                                           0xE0241C
#define pinstWorldData_x                                           0xEB4BC0
#define pinstZoneAddr_x                                            0xEC48F0
#define pinstPlayerPath_x                                          0xF66398
#define pinstTargetIndicator_x                                     0xF67CE0
#define EQObject_Top_x                                             0xEB467C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE02708
#define pinstCAchievementsWnd_x                                    0xE02704
#define pinstCActionsWnd_x                                         0xE026C8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE023D8
#define pinstCAdvancedLootWnd_x                                    0xE0239C
#define pinstCAdventureLeaderboardWnd_x                            0xF75370
#define pinstCAdventureRequestWnd_x                                0xF75420
#define pinstCAdventureStatsWnd_x                                  0xF754D0
#define pinstCAggroMeterWnd_x                                      0xE0245C
#define pinstCAlarmWnd_x                                           0xE02800
#define pinstCAlertHistoryWnd_x                                    0xE023F4
#define pinstCAlertStackWnd_x                                      0xE02808
#define pinstCAlertWnd_x                                           0xE02380
#define pinstCAltStorageWnd_x                                      0xF75830
#define pinstCAudioTriggersWindow_x                                0xCB6BA8
#define pinstCAuraWnd_x                                            0xE02414
#define pinstCAvaZoneWnd_x                                         0xE026D8
#define pinstCBandolierWnd_x                                       0xE02454
#define pinstCBankWnd_x                                            0xE02410
#define pinstCBarterMerchantWnd_x                                  0xF76A70
#define pinstCBarterSearchWnd_x                                    0xF76B20
#define pinstCBarterWnd_x                                          0xF76BD0
#define pinstCBazaarConfirmationWnd_x                              0xE02738
#define pinstCBazaarSearchWnd_x                                    0xE024A0
#define pinstCBazaarWnd_x                                          0xE02774
#define pinstCBlockedBuffWnd_x                                     0xE02418
#define pinstCBlockedPetBuffWnd_x                                  0xE02450
#define pinstCBodyTintWnd_x                                        0xE026DC
#define pinstCBookWnd_x                                            0xE0247C
#define pinstCBreathWnd_x                                          0xE02724
#define pinstCBuffWindowNORMAL_x                                   0xE023F8
#define pinstCBuffWindowSHORT_x                                    0xE023FC
#define pinstCBugReportWnd_x                                       0xE02408
#define pinstCButtonWnd_x                                          0x15FA340
#define pinstCCastingWnd_x                                         0xE02470
#define pinstCCastSpellWnd_x                                       0xE02720
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE02778
#define pinstCChatWindowManager_x                                  0xF77690
#define pinstCClaimWnd_x                                           0xF777E8
#define pinstCColorPickerWnd_x                                     0xE026D0
#define pinstCCombatAbilityWnd_x                                   0xE02784
#define pinstCCombatSkillsSelectWnd_x                              0xE02384
#define pinstCCompassWnd_x                                         0xE026CC
#define pinstCConfirmationDialog_x                                 0xF7C6E8
#define pinstCContainerMgr_x                                       0xE0276C
#define pinstCContextMenuManager_x                                 0x15FA090
#define pinstCCursorAttachment_x                                   0xE02464
#define pinstCDynamicZoneWnd_x                                     0xF77DB0
#define pinstCEditLabelWnd_x                                       0xE023F0
#define pinstCEQMainWnd_x                                          0xF77FF8
#define pinstCEventCalendarWnd_x                                   0xE02468
#define pinstCExtendedTargetWnd_x                                  0xE02444
#define pinstCFacePick_x                                           0xE02394
#define pinstCFactionWnd_x                                         0xE02768
#define pinstCFellowshipWnd_x                                      0xF781F8
#define pinstCFileSelectionWnd_x                                   0xE0246C
#define pinstCFindItemWnd_x                                        0xE02734
#define pinstCFindLocationWnd_x                                    0xF78350
#define pinstCFriendsWnd_x                                         0xE02398
#define pinstCGemsGameWnd_x                                        0xE02764
#define pinstCGiveWnd_x                                            0xE02804
#define pinstCGroupSearchFiltersWnd_x                              0xE02474
#define pinstCGroupSearchWnd_x                                     0xF78748
#define pinstCGroupWnd_x                                           0xF787F8
#define pinstCGuildBankWnd_x                                       0xEC5734
#define pinstCGuildCreationWnd_x                                   0xF78958
#define pinstCGuildMgmtWnd_x                                       0xF78A08
#define pinstCharacterCreation_x                                   0xE0238C
#define pinstCHelpWnd_x                                            0xE023CC
#define pinstCHeritageSelectionWnd_x                               0xE023A0
#define pinstCHotButtonWnd_x                                       0xF7AB60
#define pinstCHotButtonWnd1_x                                      0xF7AB60
#define pinstCHotButtonWnd2_x                                      0xF7AB64
#define pinstCHotButtonWnd3_x                                      0xF7AB68
#define pinstCHotButtonWnd4_x                                      0xF7AB6C
#define pinstCIconSelectionWnd_x                                   0xE02460
#define pinstCInspectWnd_x                                         0xE023C8
#define pinstCInventoryWnd_x                                       0xE023A4
#define pinstCInvSlotMgr_x                                         0xE02700
#define pinstCItemDisplayManager_x                                 0xF7B0F0
#define pinstCItemExpTransferWnd_x                                 0xF7B220
#define pinstCItemOverflowWnd_x                                    0xE024A4
#define pinstCJournalCatWnd_x                                      0xE02480
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE02448
#define pinstCKeyRingWnd_x                                         0xE023E8
#define pinstCLargeDialogWnd_x                                     0xF7D368
#define pinstCLayoutCopyWnd_x                                      0xF7B570
#define pinstCLFGuildWnd_x                                         0xF7B620
#define pinstCLoadskinWnd_x                                        0xE02770
#define pinstCLootFiltersCopyWnd_x                                 0xCD31B0
#define pinstCLootFiltersWnd_x                                     0xE02374
#define pinstCLootSettingsWnd_x                                    0xE02390
#define pinstCLootWnd_x                                            0xE02484
#define pinstCMailAddressBookWnd_x                                 0xE0270C
#define pinstCMailCompositionWnd_x                                 0xE026EC
#define pinstCMailIgnoreListWnd_x                                  0xE02710
#define pinstCMailWnd_x                                            0xE026C4
#define pinstCManageLootWnd_x                                      0xE03668
#define pinstCMapToolbarWnd_x                                      0xE023D4
#define pinstCMapViewWnd_x                                         0xE023B0
#define pinstCMarketplaceWnd_x                                     0xE02378
#define pinstCMerchantWnd_x                                        0xE02488
#define pinstCMIZoneSelectWnd_x                                    0xF7BE58
#define pinstCMusicPlayerWnd_x                                     0xE02490
#define pinstCNameChangeMercWnd_x                                  0xE0272C
#define pinstCNameChangePetWnd_x                                   0xE02714
#define pinstCNameChangeWnd_x                                      0xE02760
#define pinstCNoteWnd_x                                            0xE023B4
#define pinstCObjectPreviewWnd_x                                   0xE02388
#define pinstCOptionsWnd_x                                         0xE023B8
#define pinstCPetInfoWnd_x                                         0xE024AC
#define pinstCPetitionQWnd_x                                       0xE026F4
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE026E0
#define pinstCPlayerWnd_x                                          0xE024B0
#define pinstCPopupWndManager_x                                    0xF7C6E8
#define pinstCProgressionSelectionWnd_x                            0xF7C798
#define pinstCPurchaseGroupWnd_x                                   0xE023C0
#define pinstCPurchaseWnd_x                                        0xE023A8
#define pinstCPvPLeaderboardWnd_x                                  0xF7C848
#define pinstCPvPStatsWnd_x                                        0xF7C8F8
#define pinstCQuantityWnd_x                                        0xE0244C
#define pinstCRaceChangeWnd_x                                      0xE027FC
#define pinstCRaidOptionsWnd_x                                     0xE02478
#define pinstCRaidWnd_x                                            0xE026F0
#define pinstCRealEstateItemsWnd_x                                 0xE026FC
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE0248C
#define pinstCRealEstateManageWnd_x                                0xE023D0
#define pinstCRealEstateNeighborhoodWnd_x                          0xE023EC
#define pinstCRealEstatePlotSearchWnd_x                            0xE0240C
#define pinstCRealEstatePurchaseWnd_x                              0xE02440
#define pinstCRespawnWnd_x                                         0xE0243C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE02718
#define pinstCSendMoneyWnd_x                                       0xE0237C
#define pinstCServerListWnd_x                                      0xE02458
#define pinstCSkillsSelectWnd_x                                    0xE0277C
#define pinstCSkillsWnd_x                                          0xE02748
#define pinstCSocialEditWnd_x                                      0xE023E0
#define pinstCSocialWnd_x                                          0xE02728
#define pinstCSpellBookWnd_x                                       0xE02780
#define pinstCStoryWnd_x                                           0xE024B4
#define pinstCTargetOfTargetWnd_x                                  0xF7E720
#define pinstCTargetWnd_x                                          0xE02438
#define pinstCTaskOverlayWnd_x                                     0xE023BC
#define pinstCTaskSelectWnd_x                                      0xF7E878
#define pinstCTaskManager_x                                        0xCD3AF0
#define pinstCTaskTemplateSelectWnd_x                              0xF7E928
#define pinstCTaskWnd_x                                            0xF7E9D8
#define pinstCTextEntryWnd_x                                       0xE02400
#define pinstCTimeLeftWnd_x                                        0xE026C0
#define pinstCTipWndCONTEXT_x                                      0xF7EBDC
#define pinstCTipWndOFDAY_x                                        0xF7EBD8
#define pinstCTitleWnd_x                                           0xF7EC88
#define pinstCTrackingWnd_x                                        0xE023AC
#define pinstCTradeskillWnd_x                                      0xF7EDF0
#define pinstCTradeWnd_x                                           0xE026E8
#define pinstCTrainWnd_x                                           0xE026E4
#define pinstCTributeBenefitWnd_x                                  0xF7EFF0
#define pinstCTributeMasterWnd_x                                   0xF7F0A0
#define pinstCTributeTrophyWnd_x                                   0xF7F150
#define pinstCVideoModesWnd_x                                      0xE024B8
#define pinstCVoiceMacroWnd_x                                      0xF68448
#define pinstCVoteResultsWnd_x                                     0xE026F8
#define pinstCVoteWnd_x                                            0xE026D4
#define pinstCWebManager_x                                         0xF68AC4
#define pinstCZoneGuideWnd_x                                       0xE023C4
#define pinstCZonePathWnd_x                                        0xE023DC

#define pinstEQSuiteTextureLoader_x                                0xCA10C0
#define pinstItemIconCache_x                                       0xF77FB0
#define pinstLootFiltersManager_x                                  0xCD3260
#define pinstRewardSelectionWnd_x                                  0xF7D040

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B0820
#define __CastRay2_x                                               0x5B0870
#define __ConvertItemTags_x                                        0x5CC3C0
#define __CleanItemTags_x                                          0x47D0A0
#define __DoesFileExist_x                                          0x905FC0
#define __EQGetTime_x                                              0x9029B0
#define __ExecuteCmd_x                                             0x5A9020
#define __FixHeading_x                                             0x99DB50
#define __GameLoop_x                                               0x6BD640
#define __get_bearing_x                                            0x5B0390
#define __get_melee_range_x                                        0x5B0A60
#define __GetAnimationCache_x                                      0x7229F0
#define __GetGaugeValueFromEQ_x                                    0x814D50
#define __GetLabelFromEQ_x                                         0x816830
#define __GetXTargetType_x                                         0x99F530
#define __HandleMouseWheel_x                                       0x6BE500
#define __HeadingDiff_x                                            0x99DBC0
#define __HelpPath_x                                               0xF637EC
#define __LoadFrontEnd_x                                           0x6BA960
#define __NewUIINI_x                                               0x814A20
#define __ProcessGameEvents_x                                      0x611290
#define __ProcessMouseEvent_x                                      0x610A50
#define __SaveColors_x                                             0x552580
#define __STMLToText_x                                             0x940E00
#define __ToggleKeyRingItem_x                                      0x515B20
#define CMemoryMappedFile__SetFile_x                               0xA8CEC0
#define CrashDetected_x                                            0x6BC400
#define DrawNetStatus_x                                            0x63CEB0
#define Expansion_HoT_x                                            0xEC573C
#define Teleport_Table_Size_x                                      0xEB4768
#define Teleport_Table_x                                           0xEB4BD0
#define Util__FastTime_x                                           0x902580

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490380
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499280
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499050
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493910
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55A120
#define AltAdvManager__IsAbilityReady_x                            0x559050
#define AltAdvManager__GetAAById_x                                 0x559250
#define AltAdvManager__CanTrainAbility_x                           0x5592C0
#define AltAdvManager__CanSeeAbility_x                             0x559620

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA3B0
#define CharacterZoneClient__HasSkill_x                            0x4D52A0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D69C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE5D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BABD0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9340
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9420
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9500
#define CharacterZoneClient__FindAffectSlot_x                      0x4C33D0
#define CharacterZoneClient__BardCastBard_x                        0x4C5F30
#define CharacterZoneClient__GetMaxEffects_x                       0x4BACA0
#define CharacterZoneClient__GetEffect_x                           0x4BAB10
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4420
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C44F0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4540
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4690
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4860
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2AC0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7920
#define CharacterZoneClient__FindItemByRecord_x                    0x4D73A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E4110
#define CBankWnd__WndNotification_x                                0x6E3EF0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F1740

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61F9E0
#define CButtonWnd__CButtonWnd_x                                   0x93D1C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x711B40
#define CChatManager__InitContextMenu_x                            0x70AC90
#define CChatManager__FreeChatWindow_x                             0x710680
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8A00
#define CChatManager__SetLockedActiveChatWindow_x                  0x7117C0
#define CChatManager__CreateChatWindow_x                           0x710CC0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8B10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x951810
#define CContextMenu__dCContextMenu_x                              0x951A40
#define CContextMenu__AddMenuItem_x                                0x951A50
#define CContextMenu__RemoveMenuItem_x                             0x951D60
#define CContextMenu__RemoveAllMenuItems_x                         0x951D80
#define CContextMenu__CheckMenuItem_x                              0x951E00
#define CContextMenu__SetMenuItem_x                                0x951C80
#define CContextMenu__AddSeparator_x                               0x951BE0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9523A0
#define CContextMenuManager__RemoveMenu_x                          0x952410
#define CContextMenuManager__PopupMenu_x                           0x9524D0
#define CContextMenuManager__Flush_x                               0x952340
#define CContextMenuManager__GetMenu_x                             0x49B4B0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71D1F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DE0A0
#define CChatService__GetFriendName_x                              0x8DE0B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7123F0
#define CChatWindow__Clear_x                                       0x7136B0
#define CChatWindow__WndNotification_x                             0x713E40
#define CChatWindow__AddHistory_x                                  0x712F70

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94EC70
#define CComboWnd__Draw_x                                          0x94E170
#define CComboWnd__GetCurChoice_x                                  0x94EAB0
#define CComboWnd__GetListRect_x                                   0x94E620
#define CComboWnd__GetTextRect_x                                   0x94ECE0
#define CComboWnd__InsertChoice_x                                  0x94E7B0
#define CComboWnd__SetColors_x                                     0x94E780
#define CComboWnd__SetChoice_x                                     0x94EA80
#define CComboWnd__GetItemCount_x                                  0x94EAC0
#define CComboWnd__GetCurChoiceText_x                              0x94EB00
#define CComboWnd__GetChoiceText_x                                 0x94EAD0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94E840

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71ABD0
#define CContainerWnd__vftable_x                                   0xB14544
#define CContainerWnd__SetContainer_x                              0x71C140

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54CFB0
#define CDisplay__PreZoneMainUI_x                                  0x54CFC0
#define CDisplay__CleanGameUI_x                                    0x552340
#define CDisplay__GetClickedActor_x                                0x5452D0
#define CDisplay__GetUserDefinedColor_x                            0x53D990
#define CDisplay__GetWorldFilePath_x                               0x546D40
#define CDisplay__is3dON_x                                         0x541F30
#define CDisplay__ReloadUI_x                                       0x54C440
#define CDisplay__WriteTextHD2_x                                   0x541D20
#define CDisplay__TrueDistance_x                                   0x548A00
#define CDisplay__SetViewActor_x                                   0x544BF0
#define CDisplay__GetFloorHeight_x                                 0x541FF0
#define CDisplay__SetRenderWindow_x                                0x540950
#define CDisplay__ToggleScreenshotMode_x                           0x5446C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x971590

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x954D4F
#define CEditWnd__GetCharIndexPt_x                                 0x955C80
#define CEditWnd__GetDisplayString_x                               0x955B20
#define CEditWnd__GetHorzOffset_x                                  0x954390
#define CEditWnd__GetLineForPrintableChar_x                        0x956E20
#define CEditWnd__GetSelStartPt_x                                  0x955F30
#define CEditWnd__GetSTMLSafeText_x                                0x955940
#define CEditWnd__PointFromPrintableChar_x                         0x956A50
#define CEditWnd__SelectableCharFromPoint_x                        0x956BC0
#define CEditWnd__SetEditable_x                                    0x956000
#define CEditWnd__SetWindowTextA_x                                 0x9556C0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FEFB0
#define CEverQuest__ClickedPlayer_x                                0x5F0FC0
#define CEverQuest__CreateTargetIndicator_x                        0x60E530
#define CEverQuest__DeleteTargetIndicator_x                        0x60E5C0
#define CEverQuest__DoTellWindow_x                                 0x4E8BF0
#define CEverQuest__OutputTextToLog_x                              0x4E8E70
#define CEverQuest__DropHeldItemOnGround_x                         0x5E6000
#define CEverQuest__dsp_chat_x                                     0x4E9200
#define CEverQuest__trimName_x                                     0x60A820
#define CEverQuest__Emote_x                                        0x5FF810
#define CEverQuest__EnterZone_x                                    0x5F9790
#define CEverQuest__GetBodyTypeDesc_x                              0x6040E0
#define CEverQuest__GetClassDesc_x                                 0x604720
#define CEverQuest__GetClassThreeLetterCode_x                      0x604D20
#define CEverQuest__GetDeityDesc_x                                 0x60CE70
#define CEverQuest__GetLangDesc_x                                  0x604EE0
#define CEverQuest__GetRaceDesc_x                                  0x604700
#define CEverQuest__InterpretCmd_x                                 0x60D440
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EA200
#define CEverQuest__LMouseUp_x                                     0x5E8590
#define CEverQuest__RightClickedOnPlayer_x                         0x5EAAE0
#define CEverQuest__RMouseUp_x                                     0x5E9510
#define CEverQuest__SetGameState_x                                 0x5E5D90
#define CEverQuest__UPCNotificationFlush_x                         0x60A720
#define CEverQuest__IssuePetCommand_x                              0x6062E0
#define CEverQuest__ReportSuccessfulHit_x                          0x600B60

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72CAC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72CB20
#define CGaugeWnd__Draw_x                                          0x72C140

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF4F0
#define CGuild__GetGuildName_x                                     0x4AE5D0
#define CGuild__GetGuildIndex_x                                    0x4AE960

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x747F00

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61FDA0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x754EB0
#define CInvSlotMgr__MoveItem_x                                    0x753C10
#define CInvSlotMgr__SelectSlot_x                                  0x754F80

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x752490
#define CInvSlot__SliderComplete_x                                 0x7501F0
#define CInvSlot__GetItemBase_x                                    0x74FB80
#define CInvSlot__UpdateItem_x                                     0x74FCF0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x756A00
#define CInvSlotWnd__CInvSlotWnd_x                                 0x755BA0
#define CInvSlotWnd__HandleLButtonUp_x                             0x756580

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8100D0
#define CItemDisplayWnd__UpdateStrings_x                           0x765000
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75ED50
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75F270
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7655F0
#define CItemDisplayWnd__AboutToShow_x                             0x764C40
#define CItemDisplayWnd__WndNotification_x                         0x7666C0
#define CItemDisplayWnd__RequestConvertItem_x                      0x766190
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x763CB0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x764A60

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x848A40

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76ABD0

// CLabel 
#define CLabel__Draw_x                                             0x770640

// CListWnd
#define CListWnd__CListWnd_x                                       0x927470
#define CListWnd__dCListWnd_x                                      0x927790
#define CListWnd__AddColumn_x                                      0x92BC00
#define CListWnd__AddColumn1_x                                     0x92BC50
#define CListWnd__AddLine_x                                        0x92BFE0
#define CListWnd__AddString_x                                      0x92BDE0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92B9C0
#define CListWnd__CalculateVSBRange_x                              0x92B7A0
#define CListWnd__ClearSel_x                                       0x92C7C0
#define CListWnd__ClearAllSel_x                                    0x92C820
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92D240
#define CListWnd__Compare_x                                        0x92B0E0
#define CListWnd__Draw_x                                           0x9278C0
#define CListWnd__DrawColumnSeparators_x                           0x92A0B0
#define CListWnd__DrawHeader_x                                     0x92A520
#define CListWnd__DrawItem_x                                       0x92AA20
#define CListWnd__DrawLine_x                                       0x92A220
#define CListWnd__DrawSeparator_x                                  0x92A150
#define CListWnd__EnableLine_x                                     0x929980
#define CListWnd__EnsureVisible_x                                  0x92D160
#define CListWnd__ExtendSel_x                                      0x92C6F0
#define CListWnd__GetColumnTooltip_x                               0x9294C0
#define CListWnd__GetColumnMinWidth_x                              0x929530
#define CListWnd__GetColumnWidth_x                                 0x929430
#define CListWnd__GetCurSel_x                                      0x928DC0
#define CListWnd__GetItemAtPoint_x                                 0x929C00
#define CListWnd__GetItemAtPoint1_x                                0x929C70
#define CListWnd__GetItemData_x                                    0x928E40
#define CListWnd__GetItemHeight_x                                  0x929200
#define CListWnd__GetItemIcon_x                                    0x928FD0
#define CListWnd__GetItemRect_x                                    0x929A70
#define CListWnd__GetItemText_x                                    0x928E80
#define CListWnd__GetSelList_x                                     0x92C870
#define CListWnd__GetSeparatorRect_x                               0x929EB0
#define CListWnd__InsertLine_x                                     0x92C3D0
#define CListWnd__RemoveLine_x                                     0x92C520
#define CListWnd__SetColors_x                                      0x92B780
#define CListWnd__SetColumnJustification_x                         0x92B4B0
#define CListWnd__SetColumnWidth_x                                 0x92B3D0
#define CListWnd__SetCurSel_x                                      0x92C630
#define CListWnd__SetItemColor_x                                   0x92CE10
#define CListWnd__SetItemData_x                                    0x92CDD0
#define CListWnd__SetItemText_x                                    0x92C9E0
#define CListWnd__ShiftColumnSeparator_x                           0x92B570
#define CListWnd__Sort_x                                           0x92B260
#define CListWnd__ToggleSel_x                                      0x92C660
#define CListWnd__SetColumnsSizable_x                              0x92B620
#define CListWnd__SetItemWnd_x                                     0x92CC90
#define CListWnd__GetItemWnd_x                                     0x929020
#define CListWnd__SetItemIcon_x                                    0x92CA60
#define CListWnd__CalculateCustomWindowPositions_x                 0x92BAC0
#define CListWnd__SetVScrollPos_x                                  0x92B3B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x785CF0
#define CMapViewWnd__GetWorldCoordinates_x                         0x784400
#define CMapViewWnd__HandleLButtonDown_x                           0x781440

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A5DB0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A6690
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A6BC0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A9B40
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A4920
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AF700
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A59D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8ABCC0
#define CPacketScrambler__hton_x                                   0x8ABCB0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x946460
#define CSidlManager__FindScreenPieceTemplate_x                    0x946870
#define CSidlManager__FindScreenPieceTemplate1_x                   0x946660
#define CSidlManager__CreateLabel_x                                0x807510
#define CSidlManager__CreateXWndFromTemplate_x                     0x9497D0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9499B0
#define CSidlManager__CreateXWnd_x                                 0x807440
#define CSidlManager__CreateHotButtonWnd_x                         0x807A10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x942F30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x942E30
#define CSidlScreenWnd__ConvertToRes_x                             0x968570
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9428C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9425B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x942680
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x942750
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9433D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9438A0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9435C0
#define CSidlScreenWnd__Init1_x                                    0x9421B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9438F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x944440
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9415B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x943FC0
#define CSidlScreenWnd__StoreIniVis_x                              0x944320
#define CSidlScreenWnd__WndNotification_x                          0x9432E0
#define CSidlScreenWnd__GetChildItem_x                             0x943820
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9330A0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F9F60

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x684900
#define CSkillMgr__GetSkillCap_x                                   0x684AE0
#define CSkillMgr__GetNameToken_x                                  0x684080
#define CSkillMgr__IsActivatedSkill_x                              0x6841C0
#define CSkillMgr__IsCombatSkill_x                                 0x684100

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x953170
#define CSliderWnd__SetValue_x                                     0x952FE0
#define CSliderWnd__SetNumTicks_x                                  0x953040

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80D560

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95B970
#define CStmlWnd__CalculateHSBRange_x                              0x95CA50
#define CStmlWnd__CalculateVSBRange_x                              0x95C9C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x960D90
#define CStmlWnd__FastForwardToEndOfTag_x                          0x961A20
#define CStmlWnd__ForceParseNow_x                                  0x95BF10
#define CStmlWnd__GetNextTagPiece_x                                0x960CF0
#define CStmlWnd__GetSTMLText_x                                    0x505430
#define CStmlWnd__GetVisibleText_x                                 0x95BF30
#define CStmlWnd__InitializeWindowVariables_x                      0x961870
#define CStmlWnd__MakeStmlColorTag_x                               0x95AFE0
#define CStmlWnd__MakeWndNotificationTag_x                         0x95B050
#define CStmlWnd__SetSTMLText_x                                    0x95A090
#define CStmlWnd__StripFirstSTMLLines_x                            0x962B20
#define CStmlWnd__UpdateHistoryString_x                            0x961C30

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9591E0
#define CTabWnd__DrawCurrentPage_x                                 0x959910
#define CTabWnd__DrawTab_x                                         0x959630
#define CTabWnd__GetCurrentPage_x                                  0x9589E0
#define CTabWnd__GetPageInnerRect_x                                0x958C20
#define CTabWnd__GetTabInnerRect_x                                 0x958B60
#define CTabWnd__GetTabRect_x                                      0x958A10
#define CTabWnd__InsertPage_x                                      0x958E30
#define CTabWnd__SetPage_x                                         0x958CA0
#define CTabWnd__SetPageRect_x                                     0x959120
#define CTabWnd__UpdatePage_x                                      0x9594F0
#define CTabWnd__GetPageFromTabIndex_x                             0x959570
#define CTabWnd__GetCurrentTabIndex_x                              0x9589D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76AFA0
#define CPageWnd__SetTabText_x                                     0x958530

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A91C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92FF40
#define CTextureFont__GetTextExtent_x                              0x930100

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B77F0
#define CHtmlComponentWnd__ValidateUri_x                           0x7498F0
#define CHtmlWnd__SetClientCallbacks_x                             0x624E30
#define CHtmlWnd__AddObserver_x                                    0x624E50
#define CHtmlWnd__RemoveObserver_x                                 0x624EB0
#define Window__getProgress_x                                      0x860FE0
#define Window__getStatus_x                                        0x861000
#define Window__getURI_x                                           0x861010

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96E020

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91CFA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8840
#define CXStr__CXStr1_x                                            0x500500
#define CXStr__CXStr3_x                                            0x8FEAF0
#define CXStr__dCXStr_x                                            0x4786B0
#define CXStr__operator_equal_x                                    0x8FED20
#define CXStr__operator_equal1_x                                   0x8FED60
#define CXStr__operator_plus_equal1_x                              0x8FF7F0
#define CXStr__SetString_x                                         0x9016E0
#define CXStr__operator_char_p_x                                   0x8FF230
#define CXStr__GetChar_x                                           0x901030
#define CXStr__Delete_x                                            0x9008E0
#define CXStr__GetUnicode_x                                        0x9010A0
#define CXStr__GetLength_x                                         0x47D450
#define CXStr__Mid_x                                               0x47D460
#define CXStr__Insert_x                                            0x901100
#define CXStr__FindNext_x                                          0x900D50

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x951430
#define CXWnd__BringToTop_x                                        0x936820
#define CXWnd__Center_x                                            0x9363A0
#define CXWnd__ClrFocus_x                                          0x9361B0
#define CXWnd__Destroy_x                                           0x936260
#define CXWnd__DoAllDrawing_x                                      0x932830
#define CXWnd__DrawChildren_x                                      0x932800
#define CXWnd__DrawColoredRect_x                                   0x932C90
#define CXWnd__DrawTooltip_x                                       0x931350
#define CXWnd__DrawTooltipAtPoint_x                                0x931410
#define CXWnd__GetBorderFrame_x                                    0x932AF0
#define CXWnd__GetChildWndAt_x                                     0x9368C0
#define CXWnd__GetClientClipRect_x                                 0x934B00
#define CXWnd__GetScreenClipRect_x                                 0x934BD0
#define CXWnd__GetScreenRect_x                                     0x934D70
#define CXWnd__GetTooltipRect_x                                    0x932CE0
#define CXWnd__GetWindowTextA_x                                    0x49CC10
#define CXWnd__IsActive_x                                          0x933420
#define CXWnd__IsDescendantOf_x                                    0x935770
#define CXWnd__IsReallyVisible_x                                   0x9357A0
#define CXWnd__IsType_x                                            0x936F40
#define CXWnd__Move_x                                              0x935800
#define CXWnd__Move1_x                                             0x9358B0
#define CXWnd__ProcessTransition_x                                 0x936350
#define CXWnd__Refade_x                                            0x935B80
#define CXWnd__Resize_x                                            0x935E10
#define CXWnd__Right_x                                             0x9365E0
#define CXWnd__SetFocus_x                                          0x936170
#define CXWnd__SetFont_x                                           0x9361E0
#define CXWnd__SetKeyTooltip_x                                     0x936D50
#define CXWnd__SetMouseOver_x                                      0x933C50
#define CXWnd__StartFade_x                                         0x935650
#define CXWnd__GetChildItem_x                                      0x936A30
#define CXWnd__SetParent_x                                         0x935510
#define CXWnd__Minimize_x                                          0x935E70

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9695F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x939710
#define CXWndManager__DrawWindows_x                                0x939730
#define CXWndManager__GetKeyboardFlags_x                           0x93BE50
#define CXWndManager__HandleKeyboardMsg_x                          0x93BA00
#define CXWndManager__RemoveWnd_x                                  0x93C080
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93C600

// CDBStr
#define CDBStr__GetString_x                                        0x53C920

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBBB0
#define EQ_Character__Cur_HP_x                                     0x4D22E0
#define EQ_Character__Cur_Mana_x                                   0x4D9A00
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEC20
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2700
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2850
#define EQ_Character__GetHPRegen_x                                 0x4DF7A0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFDA0
#define EQ_Character__GetManaRegen_x                               0x4E01E0
#define EQ_Character__Max_Endurance_x                              0x64AE00
#define EQ_Character__Max_HP_x                                     0x4D2110
#define EQ_Character__Max_Mana_x                                   0x64AC00
#define EQ_Character__doCombatAbility_x                            0x64D260
#define EQ_Character__UseSkill_x                                   0x4E1FC0
#define EQ_Character__GetConLevel_x                                0x643E70
#define EQ_Character__IsExpansionFlag_x                            0x5A7800
#define EQ_Character__TotalEffect_x                                0x4C5670
#define EQ_Character__GetPCSpellAffect_x                           0x4BF970
#define EQ_Character__SpellDuration_x                              0x4BF4A0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5060
#define EQ_Character__GetBaseSkill_x                               0x4D6000
#define EQ_Character__CanUseItem_x                                 0x4D9D10

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CAEE0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x661740

//PcClient
#define PcClient__PcClient_x                                       0x6415A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9820
#define CCharacterListWnd__EnterWorld_x                            0x4B9260
#define CCharacterListWnd__Quit_x                                  0x4B8FB0
#define CCharacterListWnd__UpdateList_x                            0x4B93F0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x626090
#define EQ_Item__CreateItemTagString_x                             0x8A54F0
#define EQ_Item__IsStackable_x                                     0x8AA050
#define EQ_Item__GetImageNum_x                                     0x8A6F70
#define EQ_Item__CreateItemClient_x                                0x625250
#define EQ_Item__GetItemValue_x                                    0x8A8250
#define EQ_Item__ValueSellMerchant_x                               0x8AB890
#define EQ_Item__IsKeyRingItem_x                                   0x8A9950
#define EQ_Item__CanGoInBag_x                                      0x6261B0
#define EQ_Item__IsEmpty_x                                         0x8A94B0
#define EQ_Item__GetMaxItemCount_x                                 0x8A8670
#define EQ_Item__GetHeldItem_x                                     0x8A6E40
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A4E60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55ADF0
#define EQ_LoadingS__Array_x                                       0xC28B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64B760
#define EQ_PC__GetAlternateAbilityId_x                             0x8B4B60
#define EQ_PC__GetCombatAbility_x                                  0x8B51D0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B5240
#define EQ_PC__GetItemRecastTimer_x                                0x64D7E0
#define EQ_PC__HasLoreItem_x                                       0x644680
#define EQ_PC__AlertInventoryChanged_x                             0x6437A0
#define EQ_PC__GetPcZoneClient_x                                   0x670240
#define EQ_PC__RemoveMyAffect_x                                    0x650A20
#define EQ_PC__GetKeyRingItems_x                                   0x8B5AD0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B5860
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B5DD0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5ADD50
#define EQItemList__add_object_x                                   0x5DB7D0
#define EQItemList__add_item_x                                     0x5AE2B0
#define EQItemList__delete_item_x                                  0x5AE300
#define EQItemList__FreeItemList_x                                 0x5AE200

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x539440

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x662FC0
#define EQPlayer__dEQPlayer_x                                      0x655EF0
#define EQPlayer__DoAttack_x                                       0x66AED0
#define EQPlayer__EQPlayer_x                                       0x6565B0
#define EQPlayer__SetNameSpriteState_x                             0x65ACA0
#define EQPlayer__SetNameSpriteTint_x                              0x65BB70
#define PlayerBase__HasProperty_j_x                                0x99BF60
#define EQPlayer__IsTargetable_x                                   0x99C400
#define EQPlayer__CanSee_x                                         0x99C260
#define EQPlayer__CanSee1_x                                        0x99C330
#define PlayerBase__GetVisibilityLineSegment_x                     0x99C020

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66DCD0
#define PlayerZoneClient__GetLevel_x                               0x670280
#define PlayerZoneClient__IsValidTeleport_x                        0x5DC940
#define PlayerZoneClient__LegalPlayerRace_x                        0x554170

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x665D70
#define EQPlayerManager__GetSpawnByName_x                          0x665E20
#define EQPlayerManager__GetPlayerFromPartialName_x                0x665EB0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6296B0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x629730
#define KeypressHandler__AttachKeyToEqCommand_x                    0x629770
#define KeypressHandler__ClearCommandStateArray_x                  0x62AB80
#define KeypressHandler__HandleKeyDown_x                           0x62ABA0
#define KeypressHandler__HandleKeyUp_x                             0x62AC40
#define KeypressHandler__SaveKeymapping_x                          0x62B090

// MapViewMap 
#define MapViewMap__Clear_x                                        0x781B60
#define MapViewMap__SaveEx_x                                       0x784F20
#define MapViewMap__SetZoom_x                                      0x7895E0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C8E00

// StringTable 
#define StringTable__getString_x                                   0x8C3C80

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x650690
#define PcZoneClient__RemovePetEffect_x                            0x650CC0
#define PcZoneClient__HasAlternateAbility_x                        0x64AA30
#define PcZoneClient__GetCurrentMod_x                              0x4E5080
#define PcZoneClient__GetModCap_x                                  0x4E4F80
#define PcZoneClient__CanEquipItem_x                               0x64B100
#define PcZoneClient__GetItemByID_x                                0x64DC60
#define PcZoneClient__GetItemByItemClass_x                         0x64DDB0
#define PcZoneClient__RemoveBuffEffect_x                           0x650CE0
#define PcZoneClient__BandolierSwap_x                              0x64BD20
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64D780

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E13F0

//IconCache
#define IconCache__GetIcon_x                                       0x722290

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x719D70
#define CContainerMgr__CloseContainer_x                            0x71A040
#define CContainerMgr__OpenExperimentContainer_x                   0x71AAC0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D9C80

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61E1C0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x778110
#define CLootWnd__RequestLootSlot_x                                0x777340

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57AF20
#define EQ_Spell__SpellAffects_x                                   0x57B390
#define EQ_Spell__SpellAffectBase_x                                0x57B150
#define EQ_Spell__IsStackable_x                                    0x4C9D10
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9B60
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6BD0
#define EQ_Spell__IsSPAStacking_x                                  0x57C1E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57B6F0
#define EQ_Spell__IsNoRemove_x                                     0x4C9CF0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57C1F0
#define __IsResEffectSpell_x                                       0x4C9090

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD220

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D3520

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x820830
#define CTargetWnd__WndNotification_x                              0x8200C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x820390
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81F230

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x824E30

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536E80
#define CTaskManager__HandleMessage_x                              0x535320
#define CTaskManager__GetTaskStatus_x                              0x536F30
#define CTaskManager__GetElementDescription_x                      0x536FB0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x576470
#define EqSoundManager__PlayScriptMp3_x                            0x5765D0
#define EqSoundManager__SoundAssistPlay_x                          0x688850
#define EqSoundManager__WaveInstancePlay_x                         0x687DC0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52AC20

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x957A40

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562820
#define CAltAbilityData__GetMercMaxRank_x                          0x5627B0
#define CAltAbilityData__GetMaxRank_x                              0x557ED0

//CTargetRing
#define CTargetRing__Cast_x                                        0x61C2E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9B40
#define CharacterBase__CreateItemGlobalIndex_x                     0x512180
#define CharacterBase__CreateItemIndex_x                           0x6243D0
#define CharacterBase__GetItemPossession_x                         0x4FDDF0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DBB30
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DBB90
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x700E80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x7016B0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x701760

//messages
#define msg_spell_worn_off_x                                       0x59FA50
#define msg_new_text_x                                             0x5947F0
#define __msgTokenTextParam_x                                      0x5A1F80
#define msgTokenText_x                                             0x5A21D0

//SpellManager
#define SpellManager__vftable_x                                    0xAEE4EC
#define SpellManager__SpellManager_x                               0x68BB80
#define Spellmanager__LoadTextSpells_x                             0x68C470
#define SpellManager__GetSpellByGroupAndRank_x                     0x68BD50

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99FE20

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5127D0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A5D10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63CD10
#define ItemGlobalIndex__IsValidIndex_x                            0x512830

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D3EC0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D4140

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x770980

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71E490
#define CCursorAttachment__AttachToCursor1_x                       0x71E4D0
#define CCursorAttachment__Deactivate_x                            0x71F4C0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94A810
#define CSidlManagerBase__CreatePageWnd_x                          0x94A000
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x946280
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x946210

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x967680
#define CEQSuiteTextureLoader__GetTexture_x                        0x967340

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F720
#define CFindItemWnd__WndNotification_x                            0x510200
#define CFindItemWnd__Update_x                                     0x510D70
#define CFindItemWnd__PickupSelectedItem_x                         0x50EF60

//IString
#define IString__Append_x                                          0x4F0A00

//Camera
#define CDisplay__cameraType_x                                     0xE024BC
#define EverQuest__Cameras_x                                       0xEC5A8C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517EB0
#define LootFiltersManager__GetItemFilterData_x                    0x5177C0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5177F0
#define LootFiltersManager__SetItemLootFilter_x                    0x517A10

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C7C60

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A5A40
#define CResolutionHandler__GetWindowedStyle_x                     0x683310

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x716B50

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E90E0
#define CDistillerInfo__Instance_x                                 0x8E9080

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x736CE0
#define CGroupWnd__UpdateDisplay_x                                 0x736040

//ItemBase
#define ItemBase__IsLore_x                                         0x8A9A00
#define ItemBase__IsLoreEquipped_x                                 0x8A9A80

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DB730
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DB870
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DB8D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6789C0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67C330

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505A70

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2630
#define FactionManagerClient__HandleFactionMessage_x               0x4F2CA0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F32A0
#define FactionManagerClient__GetMaxFaction_x                      0x4F32BF
#define FactionManagerClient__GetMinFaction_x                      0x4F3270

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FDDC0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92EEE0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BF20

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FE070

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x561CC0

//CTargetManager
#define CTargetManager__Get_x                                      0x68F3E0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6789C0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8F80

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AE1A0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF63120

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
