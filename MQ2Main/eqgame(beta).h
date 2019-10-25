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
#define __ExpectedVersionDate                                     "Oct 25 2019"
#define __ExpectedVersionTime                                     "04:22:02"
#define __ActualVersionDate_x                                      0xB00D20
#define __ActualVersionTime_x                                      0xB00D14
#define __ActualVersionBuild_x                                     0xAECA04

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x628150
#define __MemChecker1_x                                            0x8F9E70
#define __MemChecker2_x                                            0x6B63E0
#define __MemChecker3_x                                            0x6B6330
#define __MemChecker4_x                                            0x851D00
#define __EncryptPad0_x                                            0xC363F0
#define __EncryptPad1_x                                            0xC945B0
#define __EncryptPad2_x                                            0xC46C88
#define __EncryptPad3_x                                            0xC46888
#define __EncryptPad4_x                                            0xC84C08
#define __EncryptPad5_x                                            0xF5DCD0
#define __AC1_x                                                    0x80EDA6
#define __AC2_x                                                    0x5E20FF
#define __AC3_x                                                    0x5E97FF
#define __AC4_x                                                    0x5ED7C0
#define __AC5_x                                                    0x5F3ACF
#define __AC6_x                                                    0x5F80E6
#define __AC7_x                                                    0x5E1B70
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1B276C

// Direct Input
#define DI8__Main_x                                                0xF601AC
#define DI8__Keyboard_x                                            0xF601B0
#define DI8__Mouse_x                                               0xF601C8
#define DI8__Mouse_Copy_x                                          0xEB939C
#define DI8__Mouse_Check_x                                         0xF5DCF8
#define __AutoSkillArray_x                                         0xEBA2B4
#define __Attack_x                                                 0xF580DB
#define __Autofire_x                                               0xF580DC
#define __BindList_x                                               0xC24E20
#define g_eqCommandStates_x                                        0xC25BA0
#define __Clicks_x                                                 0xEB9454
#define __CommandList_x                                            0xC26760
#define __CurrentMapLabel_x                                        0xF70B5C
#define __CurrentSocial_x                                          0xC0E7CC
#define __DoAbilityList_x                                          0xEEFBFC
#define __do_loot_x                                                0x5AE3B0
#define __DrawHandler_x                                            0x15EFED0
#define __GroupCount_x                                             0xEAB792
#define __Guilds_x                                                 0xEAFBA8
#define __gWorld_x                                                 0xEAB644
#define __HWnd_x                                                   0xF601CC
#define __heqmain_x                                                0xF601A0
#define __InChatMode_x                                             0xEB9384
#define __LastTell_x                                               0xEBB2F8
#define __LMouseHeldTime_x                                         0xEB94C0
#define __Mouse_x                                                  0xF6018C
#define __MouseLook_x                                              0xEB941A
#define __MouseEventTime_x                                         0xF58BBC
#define __gpbCommandEvent_x                                        0xEAB9F4
#define __NetStatusToggle_x                                        0xEB941D
#define __PCNames_x                                                0xEBA8A4
#define __RangeAttackReady_x                                       0xEBA598
#define __RMouseHeldTime_x                                         0xEB94BC
#define __RunWalkState_x                                           0xEB9388
#define __ScreenMode_x                                             0xDF6F6C
#define __ScreenX_x                                                0xEB933C
#define __ScreenY_x                                                0xEB9338
#define __ScreenXMax_x                                             0xEB9340
#define __ScreenYMax_x                                             0xEB9344
#define __ServerHost_x                                             0xEABC2B
#define __ServerName_x                                             0xEEFBBC
#define __ShiftKeyDown_x                                           0xEB9A14
#define __ShowNames_x                                              0xEBA754
#define __Socials_x                                                0xEEFCBC
#define __SubscriptionType_x                                       0xFB5060
#define __TargetAggroHolder_x                                      0xF73510
#define __ZoneType_x                                               0xEB9818
#define __GroupAggro_x                                             0xF73550
#define __LoginName_x                                              0xF60904
#define __Inviter_x                                                0xF58058
#define __AttackOnAssist_x                                         0xEBA710
#define __UseTellWindows_x                                         0xEBAA40
#define __gfMaxZoomCameraDistance_x                                0xAF6678
#define __gfMaxCameraDistance_x                                    0xB22BEC
#define __pulAutoRun_x                                             0xEB9438
#define __pulForward_x                                             0xEBAA78
#define __pulBackward_x                                            0xEBAA7C
#define __pulTurnRight_x                                           0xEBAA80
#define __pulTurnLeft_x                                            0xEBAA84
#define __pulStrafeLeft_x                                          0xEBAA88
#define __pulStrafeRight_x                                         0xEBAA8C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEABF40
#define instEQZoneInfo_x                                           0xEB9610
#define pinstActiveBanker_x                                        0xEABA0C
#define pinstActiveCorpse_x                                        0xEABA04
#define pinstActiveGMaster_x                                       0xEABA08
#define pinstActiveMerchant_x                                      0xEABA00
#define pinstAltAdvManager_x                                       0xDF8170
#define pinstBandageTarget_x                                       0xEABA1C
#define pinstCamActor_x                                            0xDF6F60
#define pinstCDBStr_x                                              0xDF6E8C
#define pinstCDisplay_x                                            0xEAB648
#define pinstCEverQuest_x                                          0xF601C4
#define pinstEverQuestInfo_x                                       0xEB9330
#define pinstCharData_x                                            0xEAB774
#define pinstCharSpawn_x                                           0xEABAD4
#define pinstControlledMissile_x                                   0xEABD34
#define pinstControlledPlayer_x                                    0xEABAD4
#define pinstCResolutionHandler_x                                  0x15F0100
#define pinstCSidlManager_x                                        0x15EF098
#define pinstCXWndManager_x                                        0x15EF094
#define instDynamicZone_x                                          0xEAFA80
#define pinstDZMember_x                                            0xEAFB90
#define pinstDZTimerInfo_x                                         0xEAFB94
#define pinstEqLogin_x                                             0xF60250
#define instEQMisc_x                                               0xDF6DD0
#define pinstEQSoundManager_x                                      0xDF9140
#define pinstEQSpellStrings_x                                      0xCB9868
#define instExpeditionLeader_x                                     0xEAFACA
#define instExpeditionName_x                                       0xEAFB0A
#define pinstGroup_x                                               0xEAB78E
#define pinstImeManager_x                                          0x15EF090
#define pinstLocalPlayer_x                                         0xEAB9FC
#define pinstMercenaryData_x                                       0xF5A6B4
#define pinstMercenaryStats_x                                      0xF7365C
#define pinstModelPlayer_x                                         0xEABA14
#define pinstPCData_x                                              0xEAB774
#define pinstSkillMgr_x                                            0xF5C818
#define pinstSpawnManager_x                                        0xF5B2C0
#define pinstSpellManager_x                                        0xF5CA38
#define pinstSpellSets_x                                           0xF50D04
#define pinstStringTable_x                                         0xEAB778
#define pinstSwitchManager_x                                       0xEA94E0
#define pinstTarget_x                                              0xEABAD0
#define pinstTargetObject_x                                        0xEABADC
#define pinstTargetSwitch_x                                        0xEA963C
#define pinstTaskMember_x                                          0xDF6C60
#define pinstTrackTarget_x                                         0xEABAD8
#define pinstTradeTarget_x                                         0xEABA10
#define instTributeActive_x                                        0xDF6DF1
#define pinstViewActor_x                                           0xDF6F5C
#define pinstWorldData_x                                           0xEA9630
#define pinstZoneAddr_x                                            0xEB98B0
#define pinstPlayerPath_x                                          0xF5B358
#define pinstTargetIndicator_x                                     0xF5CCA0
#define EQObject_Top_x                                             0xEAB9F8
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDF722C
#define pinstCAchievementsWnd_x                                    0xDF6FB8
#define pinstCActionsWnd_x                                         0xDF6FE8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDF7794
#define pinstCAdvancedLootWnd_x                                    0xDF7764
#define pinstCAdventureLeaderboardWnd_x                            0xF6A330
#define pinstCAdventureRequestWnd_x                                0xF6A3E0
#define pinstCAdventureStatsWnd_x                                  0xF6A490
#define pinstCAggroMeterWnd_x                                      0xDF6F50
#define pinstCAlarmWnd_x                                           0xDF7728
#define pinstCAlertHistoryWnd_x                                    0xDF775C
#define pinstCAlertStackWnd_x                                      0xDF7240
#define pinstCAlertWnd_x                                           0xDF7274
#define pinstCAltStorageWnd_x                                      0xF6A7F0
#define pinstCAudioTriggersWindow_x                                0xCABB98
#define pinstCAuraWnd_x                                            0xDF77C0
#define pinstCAvaZoneWnd_x                                         0xDF6FC0
#define pinstCBandolierWnd_x                                       0xDF6F4C
#define pinstCBankWnd_x                                            0xDF77BC
#define pinstCBarterMerchantWnd_x                                  0xF6BA30
#define pinstCBarterSearchWnd_x                                    0xF6BAE0
#define pinstCBarterWnd_x                                          0xF6BB90
#define pinstCBazaarConfirmationWnd_x                              0xDF6FF8
#define pinstCBazaarSearchWnd_x                                    0xDF6FAC
#define pinstCBazaarWnd_x                                          0xDF7714
#define pinstCBlockedBuffWnd_x                                     0xDF6F28
#define pinstCBlockedPetBuffWnd_x                                  0xDF6F48
#define pinstCBodyTintWnd_x                                        0xDF6FFC
#define pinstCBookWnd_x                                            0xDF6F8C
#define pinstCBreathWnd_x                                          0xDF7264
#define pinstCBuffWindowNORMAL_x                                   0xDF77AC
#define pinstCBuffWindowSHORT_x                                    0xDF77B0
#define pinstCBugReportWnd_x                                       0xDF77B8
#define pinstCButtonWnd_x                                          0x15EF300
#define pinstCCastingWnd_x                                         0xDF6F7C
#define pinstCCastSpellWnd_x                                       0xDF7244
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDF7718
#define pinstCChatWindowManager_x                                  0xF6C650
#define pinstCClaimWnd_x                                           0xF6C7A8
#define pinstCColorPickerWnd_x                                     0xDF6FF0
#define pinstCCombatAbilityWnd_x                                   0xDF7724
#define pinstCCombatSkillsSelectWnd_x                              0xDF7744
#define pinstCCompassWnd_x                                         0xDF6FEC
#define pinstCConfirmationDialog_x                                 0xF716A8
#define pinstCContainerMgr_x                                       0xDF770C
#define pinstCContextMenuManager_x                                 0x15EF050
#define pinstCCursorAttachment_x                                   0xDF6F58
#define pinstCDynamicZoneWnd_x                                     0xF6CD70
#define pinstCEditLabelWnd_x                                       0xDF77A0
#define pinstCEQMainWnd_x                                          0xF6CFB8
#define pinstCEventCalendarWnd_x                                   0xDF77A8
#define pinstCExtendedTargetWnd_x                                  0xDF6F3C
#define pinstCFacePick_x                                           0xDF7754
#define pinstCFactionWnd_x                                         0xDF7300
#define pinstCFellowshipWnd_x                                      0xF6D1B8
#define pinstCFileSelectionWnd_x                                   0xDF6F78
#define pinstCFindItemWnd_x                                        0xDF7280
#define pinstCFindLocationWnd_x                                    0xF6D310
#define pinstCFriendsWnd_x                                         0xDF7760
#define pinstCGemsGameWnd_x                                        0xDF72FC
#define pinstCGiveWnd_x                                            0xDF772C
#define pinstCGroupSearchFiltersWnd_x                              0xDF6F84
#define pinstCGroupSearchWnd_x                                     0xF6D708
#define pinstCGroupWnd_x                                           0xF6D7B8
#define pinstCGuildBankWnd_x                                       0xEBA6F4
#define pinstCGuildCreationWnd_x                                   0xF6D918
#define pinstCGuildMgmtWnd_x                                       0xF6D9C8
#define pinstCharacterCreation_x                                   0xDF774C
#define pinstCHelpWnd_x                                            0xDF778C
#define pinstCHeritageSelectionWnd_x                               0xDF7768
#define pinstCHotButtonWnd_x                                       0xF6FB20
#define pinstCHotButtonWnd1_x                                      0xF6FB20
#define pinstCHotButtonWnd2_x                                      0xF6FB24
#define pinstCHotButtonWnd3_x                                      0xF6FB28
#define pinstCHotButtonWnd4_x                                      0xF6FB2C
#define pinstCIconSelectionWnd_x                                   0xDF6F54
#define pinstCInspectWnd_x                                         0xDF7788
#define pinstCInventoryWnd_x                                       0xDF776C
#define pinstCInvSlotMgr_x                                         0xDF7228
#define pinstCItemDisplayManager_x                                 0xF700B0
#define pinstCItemExpTransferWnd_x                                 0xF701E4
#define pinstCItemOverflowWnd_x                                    0xDF6FB4
#define pinstCJournalCatWnd_x                                      0xDF6F94
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDF6F40
#define pinstCKeyRingWnd_x                                         0xDF779C
#define pinstCLargeDialogWnd_x                                     0xF72328
#define pinstCLayoutCopyWnd_x                                      0xF70530
#define pinstCLFGuildWnd_x                                         0xF705E0
#define pinstCLoadskinWnd_x                                        0xDF7710
#define pinstCLootFiltersCopyWnd_x                                 0xCC8168
#define pinstCLootFiltersWnd_x                                     0xDF7248
#define pinstCLootSettingsWnd_x                                    0xDF727C
#define pinstCLootWnd_x                                            0xDF6F98
#define pinstCMailAddressBookWnd_x                                 0xDF7234
#define pinstCMailCompositionWnd_x                                 0xDF7014
#define pinstCMailIgnoreListWnd_x                                  0xDF7238
#define pinstCMailWnd_x                                            0xDF6FE4
#define pinstCManageLootWnd_x                                      0xDF8620
#define pinstCMapToolbarWnd_x                                      0xDF7790
#define pinstCMapViewWnd_x                                         0xDF7778
#define pinstCMarketplaceWnd_x                                     0xDF7270
#define pinstCMerchantWnd_x                                        0xDF6F9C
#define pinstCMIZoneSelectWnd_x                                    0xF70E18
#define pinstCMusicPlayerWnd_x                                     0xDF6FA4
#define pinstCNameChangeMercWnd_x                                  0xDF6FE0
#define pinstCNameChangePetWnd_x                                   0xDF6FBC
#define pinstCNameChangeWnd_x                                      0xDF7008
#define pinstCNoteWnd_x                                            0xDF777C
#define pinstCObjectPreviewWnd_x                                   0xDF7278
#define pinstCOptionsWnd_x                                         0xDF7780
#define pinstCPetInfoWnd_x                                         0xDF6FC4
#define pinstCPetitionQWnd_x                                       0xDF6FA8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDF7000
#define pinstCPlayerWnd_x                                          0xDF6FC8
#define pinstCPopupWndManager_x                                    0xF716A8
#define pinstCProgressionSelectionWnd_x                            0xF71758
#define pinstCPurchaseGroupWnd_x                                   0xDF7734
#define pinstCPurchaseWnd_x                                        0xDF7708
#define pinstCPvPLeaderboardWnd_x                                  0xF71808
#define pinstCPvPStatsWnd_x                                        0xF718B8
#define pinstCQuantityWnd_x                                        0xDF6F44
#define pinstCRaceChangeWnd_x                                      0xDF7230
#define pinstCRaidOptionsWnd_x                                     0xDF6F88
#define pinstCRaidWnd_x                                            0xDF701C
#define pinstCRealEstateItemsWnd_x                                 0xDF6FB0
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDF6F30
#define pinstCRealEstateManageWnd_x                                0xDF773C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDF7758
#define pinstCRealEstatePlotSearchWnd_x                            0xDF7770
#define pinstCRealEstatePurchaseWnd_x                              0xDF7784
#define pinstCRespawnWnd_x                                         0xDF6F34
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDF723C
#define pinstCSendMoneyWnd_x                                       0xDF7740
#define pinstCServerListWnd_x                                      0xDF77A4
#define pinstCSkillsSelectWnd_x                                    0xDF771C
#define pinstCSkillsWnd_x                                          0xDF7284
#define pinstCSocialEditWnd_x                                      0xDF7798
#define pinstCSocialWnd_x                                          0xDF6FDC
#define pinstCSpellBookWnd_x                                       0xDF7720
#define pinstCStoryWnd_x                                           0xDF6FCC
#define pinstCTargetOfTargetWnd_x                                  0xF736E0
#define pinstCTargetWnd_x                                          0xDF6F2C
#define pinstCTaskOverlayWnd_x                                     0xDF7730
#define pinstCTaskSelectWnd_x                                      0xF73838
#define pinstCTaskManager_x                                        0xCC8AA8
#define pinstCTaskTemplateSelectWnd_x                              0xF738E8
#define pinstCTaskWnd_x                                            0xF73998
#define pinstCTextEntryWnd_x                                       0xDF77B4
#define pinstCTimeLeftWnd_x                                        0xDF6F80
#define pinstCTipWndCONTEXT_x                                      0xF73B9C
#define pinstCTipWndOFDAY_x                                        0xF73B98
#define pinstCTitleWnd_x                                           0xF73C48
#define pinstCTrackingWnd_x                                        0xDF7774
#define pinstCTradeskillWnd_x                                      0xF73DB0
#define pinstCTradeWnd_x                                           0xDF700C
#define pinstCTrainWnd_x                                           0xDF7004
#define pinstCTributeBenefitWnd_x                                  0xF73FB0
#define pinstCTributeMasterWnd_x                                   0xF74060
#define pinstCTributeTrophyWnd_x                                   0xF74110
#define pinstCVideoModesWnd_x                                      0xDF7018
#define pinstCVoiceMacroWnd_x                                      0xF5D408
#define pinstCVoteResultsWnd_x                                     0xDF6FA0
#define pinstCVoteWnd_x                                            0xDF6F90
#define pinstCWebManager_x                                         0xF5DA84
#define pinstCZoneGuideWnd_x                                       0xDF7738
#define pinstCZonePathWnd_x                                        0xDF7748

#define pinstEQSuiteTextureLoader_x                                0xC96088
#define pinstItemIconCache_x                                       0xF6CF70
#define pinstLootFiltersManager_x                                  0xCC8218
#define pinstRewardSelectionWnd_x                                  0xF72000

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5A9810
#define __CastRay2_x                                               0x5A9860
#define __ConvertItemTags_x                                        0x5C53C0
#define __CleanItemTags_x                                          0x47D120
#define __DoesFileExist_x                                          0x8FCF50
#define __EQGetTime_x                                              0x8F9940
#define __ExecuteCmd_x                                             0x5A20C0
#define __FixHeading_x                                             0x9949B0
#define __GameLoop_x                                               0x6B55D0
#define __get_bearing_x                                            0x5A9380
#define __get_melee_range_x                                        0x5A9A50
#define __GetAnimationCache_x                                      0x71A9B0
#define __GetGaugeValueFromEQ_x                                    0x80D250
#define __GetLabelFromEQ_x                                         0x80ED30
#define __GetXTargetType_x                                         0x996530
#define __HandleMouseWheel_x                                       0x6B6490
#define __HeadingDiff_x                                            0x994A20
#define __HelpPath_x                                               0xF587AC
#define __LoadFrontEnd_x                                           0x6B28F0
#define __NewUIINI_x                                               0x80CF20
#define __ProcessGameEvents_x                                      0x609950
#define __ProcessMouseEvent_x                                      0x609110
#define __SaveColors_x                                             0x54EE70
#define __STMLToText_x                                             0x938000
#define __ToggleKeyRingItem_x                                      0x512180
#define CMemoryMappedFile__SetFile_x                               0xA83D80
#define CrashDetected_x                                            0x6B4390
#define DrawNetStatus_x                                            0x635600
#define Expansion_HoT_x                                            0xEBA6FC
#define Teleport_Table_Size_x                                      0xEABAE4
#define Teleport_Table_x                                           0xEA9640
#define Util__FastTime_x                                           0x8F9510

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490440
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499350
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499120
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4939E0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E30

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x556A30
#define AltAdvManager__IsAbilityReady_x                            0x5559A0
#define AltAdvManager__GetAAById_x                                 0x555BA0
#define AltAdvManager__CanTrainAbility_x                           0x555C10
#define AltAdvManager__CanSeeAbility_x                             0x555F70

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA010
#define CharacterZoneClient__HasSkill_x                            0x4D4F00
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6620
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE3B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA9C0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8FC0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D90A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9180
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3060
#define CharacterZoneClient__BardCastBard_x                        0x4C5BC0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA90
#define CharacterZoneClient__GetEffect_x                           0x4BA900
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C40B0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4180
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C41D0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4320
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C44F0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2880
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7580
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7000

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DC1E0
#define CBankWnd__WndNotification_x                                0x6DBFC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E9AF0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x617F50
#define CButtonWnd__CButtonWnd_x                                   0x9343B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x709B00
#define CChatManager__InitContextMenu_x                            0x702C50
#define CChatManager__FreeChatWindow_x                             0x708640
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8650
#define CChatManager__SetLockedActiveChatWindow_x                  0x709780
#define CChatManager__CreateChatWindow_x                           0x708C80

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8760

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9489D0
#define CContextMenu__dCContextMenu_x                              0x948C00
#define CContextMenu__AddMenuItem_x                                0x948C10
#define CContextMenu__RemoveMenuItem_x                             0x948F20
#define CContextMenu__RemoveAllMenuItems_x                         0x948F40
#define CContextMenu__CheckMenuItem_x                              0x948FC0
#define CContextMenu__SetMenuItem_x                                0x948E40
#define CContextMenu__AddSeparator_x                               0x948DA0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x949560
#define CContextMenuManager__RemoveMenu_x                          0x9495D0
#define CContextMenuManager__PopupMenu_x                           0x949690
#define CContextMenuManager__Flush_x                               0x949500
#define CContextMenuManager__GetMenu_x                             0x49B4A0
#define CContextMenuManager__CreateDefaultMenu_x                   0x7151B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D6450
#define CChatService__GetFriendName_x                              0x8D6460

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70A3C0
#define CChatWindow__Clear_x                                       0x70B680
#define CChatWindow__WndNotification_x                             0x70BE10
#define CChatWindow__AddHistory_x                                  0x70AF40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x945E30
#define CComboWnd__Draw_x                                          0x945330
#define CComboWnd__GetCurChoice_x                                  0x945C70
#define CComboWnd__GetListRect_x                                   0x9457E0
#define CComboWnd__GetTextRect_x                                   0x945EA0
#define CComboWnd__InsertChoice_x                                  0x945970
#define CComboWnd__SetColors_x                                     0x945940
#define CComboWnd__SetChoice_x                                     0x945C40
#define CComboWnd__GetItemCount_x                                  0x945C80
#define CComboWnd__GetCurChoiceText_x                              0x945CC0
#define CComboWnd__GetChoiceText_x                                 0x945C90
#define CComboWnd__InsertChoiceAtIndex_x                           0x945A00

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x712B90
#define CContainerWnd__vftable_x                                   0xB09F14
#define CContainerWnd__SetContainer_x                              0x7140F0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5498B0
#define CDisplay__PreZoneMainUI_x                                  0x5498C0
#define CDisplay__CleanGameUI_x                                    0x54EC30
#define CDisplay__GetClickedActor_x                                0x541BD0
#define CDisplay__GetUserDefinedColor_x                            0x53A290
#define CDisplay__GetWorldFilePath_x                               0x543640
#define CDisplay__is3dON_x                                         0x53E830
#define CDisplay__ReloadUI_x                                       0x548D40
#define CDisplay__WriteTextHD2_x                                   0x53E620
#define CDisplay__TrueDistance_x                                   0x545300
#define CDisplay__SetViewActor_x                                   0x5414F0
#define CDisplay__GetFloorHeight_x                                 0x53E8F0
#define CDisplay__SetRenderWindow_x                                0x53D250
#define CDisplay__ToggleScreenshotMode_x                           0x540FC0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x968560

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x94BF30
#define CEditWnd__GetCharIndexPt_x                                 0x94CE60
#define CEditWnd__GetDisplayString_x                               0x94CD00
#define CEditWnd__GetHorzOffset_x                                  0x94B570
#define CEditWnd__GetLineForPrintableChar_x                        0x94E000
#define CEditWnd__GetSelStartPt_x                                  0x94D110
#define CEditWnd__GetSTMLSafeText_x                                0x94CB20
#define CEditWnd__PointFromPrintableChar_x                         0x94DC30
#define CEditWnd__SelectableCharFromPoint_x                        0x94DDA0
#define CEditWnd__SetEditable_x                                    0x94D1E0
#define CEditWnd__SetWindowTextA_x                                 0x94C8A0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5F75C0
#define CEverQuest__ClickedPlayer_x                                0x5E95E0
#define CEverQuest__CreateTargetIndicator_x                        0x606BE0
#define CEverQuest__DeleteTargetIndicator_x                        0x606C70
#define CEverQuest__DoTellWindow_x                                 0x4E8840
#define CEverQuest__OutputTextToLog_x                              0x4E8AC0
#define CEverQuest__DropHeldItemOnGround_x                         0x5DE620
#define CEverQuest__dsp_chat_x                                     0x4E8E50
#define CEverQuest__trimName_x                                     0x602EC0
#define CEverQuest__Emote_x                                        0x5F7E20
#define CEverQuest__EnterZone_x                                    0x5F1DA0
#define CEverQuest__GetBodyTypeDesc_x                              0x5FC790
#define CEverQuest__GetClassDesc_x                                 0x5FCDD0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5FD3D0
#define CEverQuest__GetDeityDesc_x                                 0x605520
#define CEverQuest__GetLangDesc_x                                  0x5FD590
#define CEverQuest__GetRaceDesc_x                                  0x5FCDB0
#define CEverQuest__InterpretCmd_x                                 0x605AF0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E2820
#define CEverQuest__LMouseUp_x                                     0x5E0BB0
#define CEverQuest__RightClickedOnPlayer_x                         0x5E3100
#define CEverQuest__RMouseUp_x                                     0x5E1B30
#define CEverQuest__SetGameState_x                                 0x5DE3B0
#define CEverQuest__UPCNotificationFlush_x                         0x602DC0
#define CEverQuest__IssuePetCommand_x                              0x5FE990
#define CEverQuest__ReportSuccessfulHit_x                          0x5F9210

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x724AD0
#define CGaugeWnd__CalcLinesFillRect_x                             0x724B30
#define CGaugeWnd__Draw_x                                          0x724150

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF290
#define CGuild__GetGuildName_x                                     0x4AE370
#define CGuild__GetGuildIndex_x                                    0x4AE700

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73FF30

//CHotButton
#define CHotButton__SetButtonSize_x                                0x618310

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74CF50
#define CInvSlotMgr__MoveItem_x                                    0x74BC60
#define CInvSlotMgr__SelectSlot_x                                  0x74D020

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74A4E0
#define CInvSlot__SliderComplete_x                                 0x748230
#define CInvSlot__GetItemBase_x                                    0x747BB0
#define CInvSlot__UpdateItem_x                                     0x747D20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74EA90
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74DC40
#define CInvSlotWnd__HandleLButtonUp_x                             0x74E610

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8085A0
#define CItemDisplayWnd__UpdateStrings_x                           0x75D160
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x756E30
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x757360
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75D760
#define CItemDisplayWnd__AboutToShow_x                             0x75CDA0
#define CItemDisplayWnd__WndNotification_x                         0x75E850
#define CItemDisplayWnd__RequestConvertItem_x                      0x75E310
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75BE00
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75CBC0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x840DD0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x762D90

// CLabel 
#define CLabel__Draw_x                                             0x768760

// CListWnd
#define CListWnd__CListWnd_x                                       0x91E460
#define CListWnd__dCListWnd_x                                      0x91E780
#define CListWnd__AddColumn_x                                      0x922BE0
#define CListWnd__AddColumn1_x                                     0x922C30
#define CListWnd__AddLine_x                                        0x922FC0
#define CListWnd__AddString_x                                      0x922DC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9229A0
#define CListWnd__CalculateVSBRange_x                              0x922790
#define CListWnd__ClearSel_x                                       0x9237A0
#define CListWnd__ClearAllSel_x                                    0x923800
#define CListWnd__CloseAndUpdateEditWindow_x                       0x924220
#define CListWnd__Compare_x                                        0x9220D0
#define CListWnd__Draw_x                                           0x91E8B0
#define CListWnd__DrawColumnSeparators_x                           0x9210A0
#define CListWnd__DrawHeader_x                                     0x921510
#define CListWnd__DrawItem_x                                       0x921A10
#define CListWnd__DrawLine_x                                       0x921210
#define CListWnd__DrawSeparator_x                                  0x921140
#define CListWnd__EnableLine_x                                     0x920970
#define CListWnd__EnsureVisible_x                                  0x924140
#define CListWnd__ExtendSel_x                                      0x9236D0
#define CListWnd__GetColumnTooltip_x                               0x9204B0
#define CListWnd__GetColumnMinWidth_x                              0x920520
#define CListWnd__GetColumnWidth_x                                 0x920420
#define CListWnd__GetCurSel_x                                      0x91FDB0
#define CListWnd__GetItemAtPoint_x                                 0x920BF0
#define CListWnd__GetItemAtPoint1_x                                0x920C60
#define CListWnd__GetItemData_x                                    0x91FE30
#define CListWnd__GetItemHeight_x                                  0x9201F0
#define CListWnd__GetItemIcon_x                                    0x91FFC0
#define CListWnd__GetItemRect_x                                    0x920A60
#define CListWnd__GetItemText_x                                    0x91FE70
#define CListWnd__GetSelList_x                                     0x923850
#define CListWnd__GetSeparatorRect_x                               0x920EA0
#define CListWnd__InsertLine_x                                     0x9233B0
#define CListWnd__RemoveLine_x                                     0x923500
#define CListWnd__SetColors_x                                      0x922770
#define CListWnd__SetColumnJustification_x                         0x9224A0
#define CListWnd__SetColumnWidth_x                                 0x9223C0
#define CListWnd__SetCurSel_x                                      0x923610
#define CListWnd__SetItemColor_x                                   0x923DF0
#define CListWnd__SetItemData_x                                    0x923DB0
#define CListWnd__SetItemText_x                                    0x9239C0
#define CListWnd__ShiftColumnSeparator_x                           0x922560
#define CListWnd__Sort_x                                           0x922250
#define CListWnd__ToggleSel_x                                      0x923640
#define CListWnd__SetColumnsSizable_x                              0x922610
#define CListWnd__SetItemWnd_x                                     0x923C70
#define CListWnd__GetItemWnd_x                                     0x920010
#define CListWnd__SetItemIcon_x                                    0x923A40
#define CListWnd__CalculateCustomWindowPositions_x                 0x922AA0
#define CListWnd__SetVScrollPos_x                                  0x9223A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77DE60
#define CMapViewWnd__GetWorldCoordinates_x                         0x77C570
#define CMapViewWnd__HandleLButtonDown_x                           0x7795B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79DE40
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79E720
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79EC50
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A1BE0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79C9A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A7790
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79DA50

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A3E10
#define CPacketScrambler__hton_x                                   0x8A3E00

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x93D660
#define CSidlManager__FindScreenPieceTemplate_x                    0x93DA70
#define CSidlManager__FindScreenPieceTemplate1_x                   0x93D860
#define CSidlManager__CreateLabel_x                                0x7FF9A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9409D0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x940BA0
#define CSidlManager__CreateXWnd_x                                 0x7FF8D0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FFE90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93A120
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93A020
#define CSidlScreenWnd__ConvertToRes_x                             0x95F5B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x939AB0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9397A0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x939870
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x939940
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93A5C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x93AA90
#define CSidlScreenWnd__GetSidlPiece_x                             0x93A7B0
#define CSidlScreenWnd__Init1_x                                    0x9393A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x93AAE0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93B640
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9387B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x93B1B0
#define CSidlScreenWnd__StoreIniVis_x                              0x93B520
#define CSidlScreenWnd__WndNotification_x                          0x93A4D0
#define CSidlScreenWnd__GetChildItem_x                             0x93AA10
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92A010
#define CSidlScreenWnd__m_layoutCopy_x                             0x15EEF20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x67CA20
#define CSkillMgr__GetSkillCap_x                                   0x67CC00
#define CSkillMgr__GetNameToken_x                                  0x67C1A0
#define CSkillMgr__IsActivatedSkill_x                              0x67C2E0
#define CSkillMgr__IsCombatSkill_x                                 0x67C220

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94A350
#define CSliderWnd__SetValue_x                                     0x94A1C0
#define CSliderWnd__SetNumTicks_x                                  0x94A220

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x805A30

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x952B60
#define CStmlWnd__CalculateHSBRange_x                              0x953C90
#define CStmlWnd__CalculateVSBRange_x                              0x953C00
#define CStmlWnd__CanBreakAtCharacter_x                            0x957FC0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x958C50
#define CStmlWnd__ForceParseNow_x                                  0x953150
#define CStmlWnd__GetNextTagPiece_x                                0x957F20
#define CStmlWnd__GetSTMLText_x                                    0x501AC0
#define CStmlWnd__GetVisibleText_x                                 0x953170
#define CStmlWnd__InitializeWindowVariables_x                      0x958AA0
#define CStmlWnd__MakeStmlColorTag_x                               0x9521D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x952240
#define CStmlWnd__SetSTMLText_x                                    0x951280
#define CStmlWnd__StripFirstSTMLLines_x                            0x959D50
#define CStmlWnd__UpdateHistoryString_x                            0x958E60

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9503D0
#define CTabWnd__DrawCurrentPage_x                                 0x950B00
#define CTabWnd__DrawTab_x                                         0x950820
#define CTabWnd__GetCurrentPage_x                                  0x94FBD0
#define CTabWnd__GetPageInnerRect_x                                0x94FE10
#define CTabWnd__GetTabInnerRect_x                                 0x94FD50
#define CTabWnd__GetTabRect_x                                      0x94FC00
#define CTabWnd__InsertPage_x                                      0x950020
#define CTabWnd__SetPage_x                                         0x94FE90
#define CTabWnd__SetPageRect_x                                     0x950310
#define CTabWnd__UpdatePage_x                                      0x9506E0
#define CTabWnd__GetPageFromTabIndex_x                             0x950760
#define CTabWnd__GetCurrentTabIndex_x                              0x94FBC0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x763160
#define CPageWnd__SetTabText_x                                     0x94F710

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8F30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x926E80
#define CTextureFont__GetTextExtent_x                              0x927040

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AF7A0
#define CHtmlComponentWnd__ValidateUri_x                           0x741920
#define CHtmlWnd__SetClientCallbacks_x                             0x61D390
#define CHtmlWnd__AddObserver_x                                    0x61D3B0
#define CHtmlWnd__RemoveObserver_x                                 0x61D410
#define Window__getProgress_x                                      0x859330
#define Window__getStatus_x                                        0x859350
#define Window__getURI_x                                           0x859360

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x964FF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x913EC0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8490
#define CXStr__CXStr1_x                                            0x481600
#define CXStr__CXStr3_x                                            0x8F5A40
#define CXStr__dCXStr_x                                            0x478750
#define CXStr__operator_equal_x                                    0x8F5C70
#define CXStr__operator_equal1_x                                   0x8F5CB0
#define CXStr__operator_plus_equal1_x                              0x8F6740
#define CXStr__SetString_x                                         0x8F8630
#define CXStr__operator_char_p_x                                   0x8F6180
#define CXStr__GetChar_x                                           0x8F7F80
#define CXStr__Delete_x                                            0x8F7830
#define CXStr__GetUnicode_x                                        0x8F7FF0
#define CXStr__GetLength_x                                         0x4A8CD0
#define CXStr__Mid_x                                               0x47D4D0
#define CXStr__Insert_x                                            0x8F8050
#define CXStr__FindNext_x                                          0x8F7CA0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9485F0
#define CXWnd__BringToTop_x                                        0x92D7D0
#define CXWnd__Center_x                                            0x92D350
#define CXWnd__ClrFocus_x                                          0x92D160
#define CXWnd__Destroy_x                                           0x92D210
#define CXWnd__DoAllDrawing_x                                      0x9297A0
#define CXWnd__DrawChildren_x                                      0x929770
#define CXWnd__DrawColoredRect_x                                   0x929C00
#define CXWnd__DrawTooltip_x                                       0x9282B0
#define CXWnd__DrawTooltipAtPoint_x                                0x928370
#define CXWnd__GetBorderFrame_x                                    0x929A60
#define CXWnd__GetChildWndAt_x                                     0x92D870
#define CXWnd__GetClientClipRect_x                                 0x92BA20
#define CXWnd__GetScreenClipRect_x                                 0x92BAF0
#define CXWnd__GetScreenRect_x                                     0x92BCB0
#define CXWnd__GetTooltipRect_x                                    0x929C50
#define CXWnd__GetWindowTextA_x                                    0x49CBB0
#define CXWnd__IsActive_x                                          0x92A390
#define CXWnd__IsDescendantOf_x                                    0x92C680
#define CXWnd__IsReallyVisible_x                                   0x92C6B0
#define CXWnd__IsType_x                                            0x92DEC0
#define CXWnd__Move_x                                              0x92C710
#define CXWnd__Move1_x                                             0x92C7C0
#define CXWnd__ProcessTransition_x                                 0x92D300
#define CXWnd__Refade_x                                            0x92CAA0
#define CXWnd__Resize_x                                            0x92CD70
#define CXWnd__Right_x                                             0x92D590
#define CXWnd__SetFocus_x                                          0x92D120
#define CXWnd__SetFont_x                                           0x92D190
#define CXWnd__SetKeyTooltip_x                                     0x92DCF0
#define CXWnd__SetMouseOver_x                                      0x92ABC0
#define CXWnd__StartFade_x                                         0x92C560
#define CXWnd__GetChildItem_x                                      0x92D9E0
#define CXWnd__SetParent_x                                         0x92C460
#define CXWnd__Minimize_x                                          0x92CDE0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x960630

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9307A0
#define CXWndManager__DrawWindows_x                                0x9307C0
#define CXWndManager__GetKeyboardFlags_x                           0x932F80
#define CXWndManager__HandleKeyboardMsg_x                          0x932B30
#define CXWndManager__RemoveWnd_x                                  0x9331D0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x933720

// CDBStr
#define CDBStr__GetString_x                                        0x539240

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB9A0
#define EQ_Character__Cur_HP_x                                     0x4D1F40
#define EQ_Character__Cur_Mana_x                                   0x4D9680
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEA00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B24C0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2610
#define EQ_Character__GetHPRegen_x                                 0x4DF450
#define EQ_Character__GetEnduranceRegen_x                          0x4DFA50
#define EQ_Character__GetManaRegen_x                               0x4DFE90
#define EQ_Character__Max_Endurance_x                              0x643690
#define EQ_Character__Max_HP_x                                     0x4D1D70
#define EQ_Character__Max_Mana_x                                   0x643490
#define EQ_Character__doCombatAbility_x                            0x645AF0
#define EQ_Character__UseSkill_x                                   0x4E1C70
#define EQ_Character__GetConLevel_x                                0x63C520
#define EQ_Character__IsExpansionFlag_x                            0x5A0880
#define EQ_Character__TotalEffect_x                                0x4C5300
#define EQ_Character__GetPCSpellAffect_x                           0x4BF610
#define EQ_Character__SpellDuration_x                              0x4BF140
#define EQ_Character__GetAdjustedSkill_x                           0x4D4CC0
#define EQ_Character__GetBaseSkill_x                               0x4D5C60
#define EQ_Character__CanUseItem_x                                 0x4D9990

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C3270

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x659C30

//PcClient
#define PcClient__PcClient_x                                       0x639C60

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95E0
#define CCharacterListWnd__EnterWorld_x                            0x4B9020
#define CCharacterListWnd__Quit_x                                  0x4B8D70
#define CCharacterListWnd__UpdateList_x                            0x4B91B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x61E5E0
#define EQ_Item__CreateItemTagString_x                             0x89D6A0
#define EQ_Item__IsStackable_x                                     0x8A2210
#define EQ_Item__GetImageNum_x                                     0x89F130
#define EQ_Item__CreateItemClient_x                                0x61D7B0
#define EQ_Item__GetItemValue_x                                    0x8A0450
#define EQ_Item__ValueSellMerchant_x                               0x8A39F0
#define EQ_Item__IsKeyRingItem_x                                   0x8A1B40
#define EQ_Item__CanGoInBag_x                                      0x61E700
#define EQ_Item__IsEmpty_x                                         0x8A1680
#define EQ_Item__GetMaxItemCount_x                                 0x8A0860
#define EQ_Item__GetHeldItem_x                                     0x89F000
#define EQ_Item__GetAugmentFitBySlot_x                             0x89D020

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5577B0
#define EQ_LoadingS__Array_x                                       0xC1DB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x643FF0
#define EQ_PC__GetAlternateAbilityId_x                             0x8ACBF0
#define EQ_PC__GetCombatAbility_x                                  0x8AD260
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AD2D0
#define EQ_PC__GetItemRecastTimer_x                                0x646070
#define EQ_PC__HasLoreItem_x                                       0x63CD30
#define EQ_PC__AlertInventoryChanged_x                             0x63BE60
#define EQ_PC__GetPcZoneClient_x                                   0x668750
#define EQ_PC__RemoveMyAffect_x                                    0x6492A0
#define EQ_PC__GetKeyRingItems_x                                   0x8ADB60
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AD8F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8ADE60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A6DF0
#define EQItemList__add_object_x                                   0x5D3D90
#define EQItemList__add_item_x                                     0x5A7350
#define EQItemList__delete_item_x                                  0x5A73A0
#define EQItemList__FreeItemList_x                                 0x5A72A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x535D80

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65B4B0
#define EQPlayer__dEQPlayer_x                                      0x64E7F0
#define EQPlayer__DoAttack_x                                       0x663410
#define EQPlayer__EQPlayer_x                                       0x64EEB0
#define EQPlayer__SetNameSpriteState_x                             0x653190
#define EQPlayer__SetNameSpriteTint_x                              0x654060
#define PlayerBase__HasProperty_j_x                                0x992D90
#define EQPlayer__IsTargetable_x                                   0x993230
#define EQPlayer__CanSee_x                                         0x993090
#define EQPlayer__CanSee1_x                                        0x993160
#define PlayerBase__GetVisibilityLineSegment_x                     0x992E50

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6661E0
#define PlayerZoneClient__GetLevel_x                               0x668790
#define PlayerZoneClient__IsValidTeleport_x                        0x5D4F10
#define PlayerZoneClient__LegalPlayerRace_x                        0x550AF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x65E310
#define EQPlayerManager__GetSpawnByName_x                          0x65E3C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x65E450

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x621CC0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x621D40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x621D80
#define KeypressHandler__ClearCommandStateArray_x                  0x623190
#define KeypressHandler__HandleKeyDown_x                           0x6231B0
#define KeypressHandler__HandleKeyUp_x                             0x623250
#define KeypressHandler__SaveKeymapping_x                          0x6236A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x779CD0
#define MapViewMap__SaveEx_x                                       0x77D090
#define MapViewMap__SetZoom_x                                      0x781750

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C1190

// StringTable 
#define StringTable__getString_x                                   0x8BBE40

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x648F10
#define PcZoneClient__RemovePetEffect_x                            0x649540
#define PcZoneClient__HasAlternateAbility_x                        0x6432C0
#define PcZoneClient__GetCurrentMod_x                              0x4E4D30
#define PcZoneClient__GetModCap_x                                  0x4E4C30
#define PcZoneClient__CanEquipItem_x                               0x643990
#define PcZoneClient__GetItemByID_x                                0x6464E0
#define PcZoneClient__GetItemByItemClass_x                         0x646630
#define PcZoneClient__RemoveBuffEffect_x                           0x649560
#define PcZoneClient__BandolierSwap_x                              0x6445B0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x646010

//Doors
#define EQSwitch__UseSwitch_x                                      0x5D9AD0

//IconCache
#define IconCache__GetIcon_x                                       0x71A250

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x711D30
#define CContainerMgr__CloseContainer_x                            0x712000
#define CContainerMgr__OpenExperimentContainer_x                   0x712A80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D1E80

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x616720

//CLootWnd
#define CLootWnd__LootAll_x                                        0x770230
#define CLootWnd__RequestLootSlot_x                                0x76F460

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x574530
#define EQ_Spell__SpellAffects_x                                   0x5749A0
#define EQ_Spell__SpellAffectBase_x                                0x574760
#define EQ_Spell__IsStackable_x                                    0x4C9960
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C97B0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6990
#define EQ_Spell__IsSPAStacking_x                                  0x5757F0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x574D00
#define EQ_Spell__IsNoRemove_x                                     0x4C9940
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x575800
#define __IsResEffectSpell_x                                       0x4C8D40

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD000

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CB900

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x818CB0
#define CTargetWnd__WndNotification_x                              0x818540
#define CTargetWnd__RefreshTargetBuffs_x                           0x818810
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8176A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81D2D0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x533760
#define CTaskManager__HandleMessage_x                              0x531C10
#define CTaskManager__GetTaskStatus_x                              0x533810
#define CTaskManager__GetElementDescription_x                      0x533890

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x56FAA0
#define EqSoundManager__PlayScriptMp3_x                            0x56FC00
#define EqSoundManager__SoundAssistPlay_x                          0x680950
#define EqSoundManager__WaveInstancePlay_x                         0x67FEC0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x527500

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x94EC20

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55F120
#define CAltAbilityData__GetMercMaxRank_x                          0x55F0B0
#define CAltAbilityData__GetMaxRank_x                              0x554860

//CTargetRing
#define CTargetRing__Cast_x                                        0x614840

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9790
#define CharacterBase__CreateItemGlobalIndex_x                     0x50E760
#define CharacterBase__CreateItemIndex_x                           0x61C940
#define CharacterBase__GetItemPossession_x                         0x4FA490
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D3F20
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D3F80
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F8F10
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F9740
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F97F0

//messages
#define msg_spell_worn_off_x                                       0x598A10
#define msg_new_text_x                                             0x58D7A0
#define __msgTokenTextParam_x                                      0x59AF40
#define msgTokenText_x                                             0x59B190

//SpellManager
#define SpellManager__vftable_x                                    0xAE416C
#define SpellManager__SpellManager_x                               0x683C80
#define Spellmanager__LoadTextSpells_x                             0x684570
#define SpellManager__GetSpellByGroupAndRank_x                     0x683E50

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x996E20

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50EE10
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x59ED00
#define ItemGlobalIndex__IsEquippedLocation_x                      0x635460
#define ItemGlobalIndex__IsValidIndex_x                            0x50EE70

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CC2A0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CC520

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x768AA0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x716450
#define CCursorAttachment__AttachToCursor1_x                       0x716490
#define CCursorAttachment__Deactivate_x                            0x717480

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9419E0
#define CSidlManagerBase__CreatePageWnd_x                          0x9411E0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x93D480
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x93D410

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x95E8F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x95E5B0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50BD00
#define CFindItemWnd__WndNotification_x                            0x50C7E0
#define CFindItemWnd__Update_x                                     0x50D320
#define CFindItemWnd__PickupSelectedItem_x                         0x50B540

//IString
#define IString__Append_x                                          0x4FBD50

//Camera
#define CDisplay__cameraType_x                                     0xDF7020
#define EverQuest__Cameras_x                                       0xEBAA4C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x514520
#define LootFiltersManager__GetItemFilterData_x                    0x513E20
#define LootFiltersManager__RemoveItemLootFilter_x                 0x513E50
#define LootFiltersManager__SetItemLootFilter_x                    0x514070

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BFEC0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x99C980
#define CResolutionHandler__GetWindowedStyle_x                     0x67B370

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70EB10

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DFF70
#define CDistillerInfo__Instance_x                                 0x8DFF10

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72ECF0
#define CGroupWnd__UpdateDisplay_x                                 0x72E050

//ItemBase
#define ItemBase__IsLore_x                                         0x8A1BE0
#define ItemBase__IsLoreEquipped_x                                 0x8A1C50

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D3CF0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D3E30
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D3E90

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x670E70
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x674820

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x502110

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F0A40
#define FactionManagerClient__HandleFactionMessage_x               0x4F10B0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F1670
#define FactionManagerClient__GetMaxFaction_x                      0x4F168F
#define FactionManagerClient__GetMinFaction_x                      0x4F1640

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FA460

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x925EC0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE90

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FA760

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55E5E0

//CTargetManager
#define CTargetManager__Get_x                                      0x687490

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x670E70

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8CF0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A7240

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF580E0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
