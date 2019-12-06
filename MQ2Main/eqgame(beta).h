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
#define __ExpectedVersionDate                                     "Dec  6 2019"
#define __ExpectedVersionTime                                     "04:23:54"
#define __ActualVersionDate_x                                      0xB0B52C
#define __ActualVersionTime_x                                      0xB0B520
#define __ActualVersionBuild_x                                     0xAF71AC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6303A0
#define __MemChecker1_x                                            0x903EC0
#define __MemChecker2_x                                            0x6BEB40
#define __MemChecker3_x                                            0x6BEA90
#define __MemChecker4_x                                            0x85A590
#define __EncryptPad0_x                                            0xC423E8
#define __EncryptPad1_x                                            0xCA05E8
#define __EncryptPad2_x                                            0xC52C80
#define __EncryptPad3_x                                            0xC52880
#define __EncryptPad4_x                                            0xC90C00
#define __EncryptPad5_x                                            0xF6C1D8
#define __AC1_x                                                    0x8172C6
#define __AC2_x                                                    0x5EA07F
#define __AC3_x                                                    0x5F177F
#define __AC4_x                                                    0x5F5750
#define __AC5_x                                                    0x5FBA5F
#define __AC6_x                                                    0x600076
#define __AC7_x                                                    0x5E9AF0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x197DDC

// Direct Input
#define DI8__Main_x                                                0xF6C200
#define DI8__Keyboard_x                                            0xF6C204
#define DI8__Mouse_x                                               0xF6C1E4
#define DI8__Mouse_Copy_x                                          0xEC53E4
#define DI8__Mouse_Check_x                                         0xF69D2C
#define __AutoSkillArray_x                                         0xEC62FC
#define __Attack_x                                                 0xF64123
#define __Autofire_x                                               0xF64124
#define __BindList_x                                               0xC30E20
#define g_eqCommandStates_x                                        0xC31BA0
#define __Clicks_x                                                 0xEC549C
#define __CommandList_x                                            0xC32760
#define __CurrentMapLabel_x                                        0xF7CBA4
#define __CurrentSocial_x                                          0xC1A7CC
#define __DoAbilityList_x                                          0xEFBC44
#define __do_loot_x                                                0x5B5A50
#define __DrawHandler_x                                            0x15FBF18
#define __GroupCount_x                                             0xEB7D9A
#define __Guilds_x                                                 0xEBBBF0
#define __gWorld_x                                                 0xEB7C50
#define __HWnd_x                                                   0xF6C1E8
#define __heqmain_x                                                0xF6C1C0
#define __InChatMode_x                                             0xEC53CC
#define __LastTell_x                                               0xEC7340
#define __LMouseHeldTime_x                                         0xEC5508
#define __Mouse_x                                                  0xF6C1EC
#define __MouseLook_x                                              0xEC5462
#define __MouseEventTime_x                                         0xF64C04
#define __gpbCommandEvent_x                                        0xEB5688
#define __NetStatusToggle_x                                        0xEC5465
#define __PCNames_x                                                0xEC68EC
#define __RangeAttackReady_x                                       0xEC65E0
#define __RMouseHeldTime_x                                         0xEC5504
#define __RunWalkState_x                                           0xEC53D0
#define __ScreenMode_x                                             0xE034D8
#define __ScreenX_x                                                0xEC5384
#define __ScreenY_x                                                0xEC5380
#define __ScreenXMax_x                                             0xEC5388
#define __ScreenYMax_x                                             0xEC538C
#define __ServerHost_x                                             0xEB5923
#define __ServerName_x                                             0xEFBC04
#define __ShiftKeyDown_x                                           0xEC5A5C
#define __ShowNames_x                                              0xEC679C
#define __Socials_x                                                0xEFBD04
#define __SubscriptionType_x                                       0xFC10A8
#define __TargetAggroHolder_x                                      0xF7F558
#define __ZoneType_x                                               0xEC5860
#define __GroupAggro_x                                             0xF7F598
#define __LoginName_x                                              0xF6C954
#define __Inviter_x                                                0xF640A0
#define __AttackOnAssist_x                                         0xEC6758
#define __UseTellWindows_x                                         0xEC6A88
#define __gfMaxZoomCameraDistance_x                                0xB00E40
#define __gfMaxCameraDistance_x                                    0xB2D384
#define __pulAutoRun_x                                             0xEC5480
#define __pulForward_x                                             0xEC6AC0
#define __pulBackward_x                                            0xEC6AC4
#define __pulTurnRight_x                                           0xEC6AC8
#define __pulTurnLeft_x                                            0xEC6ACC
#define __pulStrafeLeft_x                                          0xEC6AD0
#define __pulStrafeRight_x                                         0xEC6AD4

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB7F90
#define instEQZoneInfo_x                                           0xEC5658
#define pinstActiveBanker_x                                        0xEB56A4
#define pinstActiveCorpse_x                                        0xEB5698
#define pinstActiveGMaster_x                                       0xEB56A0
#define pinstActiveMerchant_x                                      0xEB5694
#define pinstAltAdvManager_x                                       0xE041C8
#define pinstBandageTarget_x                                       0xEB56C4
#define pinstCamActor_x                                            0xE034CC
#define pinstCDBStr_x                                              0xE02EE4
#define pinstCDisplay_x                                            0xEB7C4C
#define pinstCEverQuest_x                                          0xF6C218
#define pinstEverQuestInfo_x                                       0xEC5378
#define pinstCharData_x                                            0xEB7D7C
#define pinstCharSpawn_x                                           0xEB56FC
#define pinstControlledMissile_x                                   0xEB5C3C
#define pinstControlledPlayer_x                                    0xEB56FC
#define pinstCResolutionHandler_x                                  0x15FC148
#define pinstCSidlManager_x                                        0x15FB0E0
#define pinstCXWndManager_x                                        0x15FB0DC
#define instDynamicZone_x                                          0xEBBAC8
#define pinstDZMember_x                                            0xEBBBD8
#define pinstDZTimerInfo_x                                         0xEBBBDC
#define pinstEqLogin_x                                             0xF6C2A0
#define instEQMisc_x                                               0xE02E28
#define pinstEQSoundManager_x                                      0xE05198
#define pinstEQSpellStrings_x                                      0xCC5878
#define instExpeditionLeader_x                                     0xEBBB12
#define instExpeditionName_x                                       0xEBBB52
#define pinstGroup_x                                               0xEB7D96
#define pinstImeManager_x                                          0x15FB0D8
#define pinstLocalPlayer_x                                         0xEB5690
#define pinstMercenaryData_x                                       0xF666F4
#define pinstMercenaryStats_x                                      0xF7F6A4
#define pinstModelPlayer_x                                         0xEB56BC
#define pinstPCData_x                                              0xEB7D7C
#define pinstSkillMgr_x                                            0xF68860
#define pinstSpawnManager_x                                        0xF67308
#define pinstSpellManager_x                                        0xF68A80
#define pinstSpellSets_x                                           0xF5CD4C
#define pinstStringTable_x                                         0xEB7D80
#define pinstSwitchManager_x                                       0xEB5530
#define pinstTarget_x                                              0xEB56F8
#define pinstTargetObject_x                                        0xEB5704
#define pinstTargetSwitch_x                                        0xEB5C44
#define pinstTaskMember_x                                          0xE02CB8
#define pinstTrackTarget_x                                         0xEB5700
#define pinstTradeTarget_x                                         0xEB56A8
#define instTributeActive_x                                        0xE02E49
#define pinstViewActor_x                                           0xE034C8
#define pinstWorldData_x                                           0xEB5C38
#define pinstZoneAddr_x                                            0xEC58F8
#define pinstPlayerPath_x                                          0xF673A0
#define pinstTargetIndicator_x                                     0xF68CE8
#define EQObject_Top_x                                             0xEB568C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE037B0
#define pinstCAchievementsWnd_x                                    0xE037AC
#define pinstCActionsWnd_x                                         0xE03774
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE03484
#define pinstCAdvancedLootWnd_x                                    0xE02FB0
#define pinstCAdventureLeaderboardWnd_x                            0xF76378
#define pinstCAdventureRequestWnd_x                                0xF76428
#define pinstCAdventureStatsWnd_x                                  0xF764D8
#define pinstCAggroMeterWnd_x                                      0xE03508
#define pinstCAlarmWnd_x                                           0xE03810
#define pinstCAlertHistoryWnd_x                                    0xE034A0
#define pinstCAlertStackWnd_x                                      0xE03818
#define pinstCAlertWnd_x                                           0xE02F90
#define pinstCAltStorageWnd_x                                      0xF76838
#define pinstCAudioTriggersWindow_x                                0xCB7BA8
#define pinstCAuraWnd_x                                            0xE034C0
#define pinstCAvaZoneWnd_x                                         0xE037E4
#define pinstCBandolierWnd_x                                       0xE03500
#define pinstCBankWnd_x                                            0xE034BC
#define pinstCBarterMerchantWnd_x                                  0xF77A78
#define pinstCBarterSearchWnd_x                                    0xF77B28
#define pinstCBarterWnd_x                                          0xF77BD8
#define pinstCBazaarConfirmationWnd_x                              0xE037D8
#define pinstCBazaarSearchWnd_x                                    0xE0354C
#define pinstCBazaarWnd_x                                          0xE037F8
#define pinstCBlockedBuffWnd_x                                     0xE034C4
#define pinstCBlockedPetBuffWnd_x                                  0xE034FC
#define pinstCBodyTintWnd_x                                        0xE03784
#define pinstCBookWnd_x                                            0xE03528
#define pinstCBreathWnd_x                                          0xE037C8
#define pinstCBuffWindowNORMAL_x                                   0xE034A4
#define pinstCBuffWindowSHORT_x                                    0xE034A8
#define pinstCBugReportWnd_x                                       0xE034B4
#define pinstCButtonWnd_x                                          0x15FB348
#define pinstCCastingWnd_x                                         0xE0351C
#define pinstCCastSpellWnd_x                                       0xE037C4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE037FC
#define pinstCChatWindowManager_x                                  0xF78698
#define pinstCClaimWnd_x                                           0xF787F0
#define pinstCColorPickerWnd_x                                     0xE0377C
#define pinstCCombatAbilityWnd_x                                   0xE03808
#define pinstCCombatSkillsSelectWnd_x                              0xE02F94
#define pinstCCompassWnd_x                                         0xE03778
#define pinstCConfirmationDialog_x                                 0xF7D6F0
#define pinstCContainerMgr_x                                       0xE037F0
#define pinstCContextMenuManager_x                                 0x15FB098
#define pinstCCursorAttachment_x                                   0xE03510
#define pinstCDynamicZoneWnd_x                                     0xF78DB8
#define pinstCEditLabelWnd_x                                       0xE0349C
#define pinstCEQMainWnd_x                                          0xF79000
#define pinstCEventCalendarWnd_x                                   0xE03514
#define pinstCExtendedTargetWnd_x                                  0xE034F0
#define pinstCFacePick_x                                           0xE02FA8
#define pinstCFactionWnd_x                                         0xE037EC
#define pinstCFellowshipWnd_x                                      0xF79200
#define pinstCFileSelectionWnd_x                                   0xE03518
#define pinstCFindItemWnd_x                                        0xE037D4
#define pinstCFindLocationWnd_x                                    0xF79358
#define pinstCFriendsWnd_x                                         0xE02FAC
#define pinstCGemsGameWnd_x                                        0xE037E8
#define pinstCGiveWnd_x                                            0xE03814
#define pinstCGroupSearchFiltersWnd_x                              0xE03520
#define pinstCGroupSearchWnd_x                                     0xF79750
#define pinstCGroupWnd_x                                           0xF79800
#define pinstCGuildBankWnd_x                                       0xEC673C
#define pinstCGuildCreationWnd_x                                   0xF79960
#define pinstCGuildMgmtWnd_x                                       0xF79A10
#define pinstCharacterCreation_x                                   0xE02F9C
#define pinstCHelpWnd_x                                            0xE03074
#define pinstCHeritageSelectionWnd_x                               0xE02FC0
#define pinstCHotButtonWnd_x                                       0xF7BB68
#define pinstCHotButtonWnd1_x                                      0xF7BB68
#define pinstCHotButtonWnd2_x                                      0xF7BB6C
#define pinstCHotButtonWnd3_x                                      0xF7BB70
#define pinstCHotButtonWnd4_x                                      0xF7BB74
#define pinstCIconSelectionWnd_x                                   0xE0350C
#define pinstCInspectWnd_x                                         0xE03070
#define pinstCInventoryWnd_x                                       0xE02FD8
#define pinstCInvSlotMgr_x                                         0xE037A8
#define pinstCItemDisplayManager_x                                 0xF7C0F8
#define pinstCItemExpTransferWnd_x                                 0xF7C228
#define pinstCItemOverflowWnd_x                                    0xE03550
#define pinstCJournalCatWnd_x                                      0xE0352C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE034F4
#define pinstCKeyRingWnd_x                                         0xE03494
#define pinstCLargeDialogWnd_x                                     0xF7E370
#define pinstCLayoutCopyWnd_x                                      0xF7C578
#define pinstCLFGuildWnd_x                                         0xF7C628
#define pinstCLoadskinWnd_x                                        0xE037F4
#define pinstCLootFiltersCopyWnd_x                                 0xCD41C0
#define pinstCLootFiltersWnd_x                                     0xE02F80
#define pinstCLootSettingsWnd_x                                    0xE02FA0
#define pinstCLootWnd_x                                            0xE03530
#define pinstCMailAddressBookWnd_x                                 0xE037B4
#define pinstCMailCompositionWnd_x                                 0xE03794
#define pinstCMailIgnoreListWnd_x                                  0xE037B8
#define pinstCMailWnd_x                                            0xE03770
#define pinstCManageLootWnd_x                                      0xE04678
#define pinstCMapToolbarWnd_x                                      0xE0307C
#define pinstCMapViewWnd_x                                         0xE02FE4
#define pinstCMarketplaceWnd_x                                     0xE02F84
#define pinstCMerchantWnd_x                                        0xE03534
#define pinstCMIZoneSelectWnd_x                                    0xF7CE60
#define pinstCMusicPlayerWnd_x                                     0xE0353C
#define pinstCNameChangeMercWnd_x                                  0xE037D0
#define pinstCNameChangePetWnd_x                                   0xE037BC
#define pinstCNameChangeWnd_x                                      0xE037E0
#define pinstCNoteWnd_x                                            0xE02FE8
#define pinstCObjectPreviewWnd_x                                   0xE02F98
#define pinstCOptionsWnd_x                                         0xE02FEC
#define pinstCPetInfoWnd_x                                         0xE03558
#define pinstCPetitionQWnd_x                                       0xE0379C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE03788
#define pinstCPlayerWnd_x                                          0xE0355C
#define pinstCPopupWndManager_x                                    0xF7D6F0
#define pinstCProgressionSelectionWnd_x                            0xF7D7A0
#define pinstCPurchaseGroupWnd_x                                   0xE03004
#define pinstCPurchaseWnd_x                                        0xE02FDC
#define pinstCPvPLeaderboardWnd_x                                  0xF7D850
#define pinstCPvPStatsWnd_x                                        0xF7D900
#define pinstCQuantityWnd_x                                        0xE034F8
#define pinstCRaceChangeWnd_x                                      0xE0380C
#define pinstCRaidOptionsWnd_x                                     0xE03524
#define pinstCRaidWnd_x                                            0xE03798
#define pinstCRealEstateItemsWnd_x                                 0xE037A4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE03538
#define pinstCRealEstateManageWnd_x                                0xE03078
#define pinstCRealEstateNeighborhoodWnd_x                          0xE03498
#define pinstCRealEstatePlotSearchWnd_x                            0xE034B8
#define pinstCRealEstatePurchaseWnd_x                              0xE034EC
#define pinstCRespawnWnd_x                                         0xE034E8
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE037C0
#define pinstCSendMoneyWnd_x                                       0xE02F8C
#define pinstCServerListWnd_x                                      0xE03504
#define pinstCSkillsSelectWnd_x                                    0xE03800
#define pinstCSkillsWnd_x                                          0xE037DC
#define pinstCSocialEditWnd_x                                      0xE0348C
#define pinstCSocialWnd_x                                          0xE037CC
#define pinstCSpellBookWnd_x                                       0xE03804
#define pinstCStoryWnd_x                                           0xE03560
#define pinstCTargetOfTargetWnd_x                                  0xF7F728
#define pinstCTargetWnd_x                                          0xE034E4
#define pinstCTaskOverlayWnd_x                                     0xE02FF0
#define pinstCTaskSelectWnd_x                                      0xF7F880
#define pinstCTaskManager_x                                        0xCD4B00
#define pinstCTaskTemplateSelectWnd_x                              0xF7F930
#define pinstCTaskWnd_x                                            0xF7F9E0
#define pinstCTextEntryWnd_x                                       0xE034AC
#define pinstCTimeLeftWnd_x                                        0xE0356C
#define pinstCTipWndCONTEXT_x                                      0xF7FBE4
#define pinstCTipWndOFDAY_x                                        0xF7FBE0
#define pinstCTitleWnd_x                                           0xF7FC90
#define pinstCTrackingWnd_x                                        0xE02FE0
#define pinstCTradeskillWnd_x                                      0xF7FDF8
#define pinstCTradeWnd_x                                           0xE03790
#define pinstCTrainWnd_x                                           0xE0378C
#define pinstCTributeBenefitWnd_x                                  0xF7FFF8
#define pinstCTributeMasterWnd_x                                   0xF800A8
#define pinstCTributeTrophyWnd_x                                   0xF80158
#define pinstCVideoModesWnd_x                                      0xE03564
#define pinstCVoiceMacroWnd_x                                      0xF69450
#define pinstCVoteResultsWnd_x                                     0xE037A0
#define pinstCVoteWnd_x                                            0xE03780
#define pinstCWebManager_x                                         0xF69ACC
#define pinstCZoneGuideWnd_x                                       0xE0306C
#define pinstCZonePathWnd_x                                        0xE03488

#define pinstEQSuiteTextureLoader_x                                0xCA20C0
#define pinstItemIconCache_x                                       0xF78FB8
#define pinstLootFiltersManager_x                                  0xCD4270
#define pinstRewardSelectionWnd_x                                  0xF7E048

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B0EB0
#define __CastRay2_x                                               0x5B0F00
#define __ConvertItemTags_x                                        0x5CCA50
#define __CleanItemTags_x                                          0x47D050
#define __DoesFileExist_x                                          0x906FA0
#define __EQGetTime_x                                              0x903990
#define __ExecuteCmd_x                                             0x5A96B0
#define __FixHeading_x                                             0x99E370
#define __GameLoop_x                                               0x6BDD30
#define __get_bearing_x                                            0x5B0A20
#define __get_melee_range_x                                        0x5B10F0
#define __GetAnimationCache_x                                      0x7231F0
#define __GetGaugeValueFromEQ_x                                    0x815770
#define __GetLabelFromEQ_x                                         0x817250
#define __GetXTargetType_x                                         0x99FDC0
#define __HandleMouseWheel_x                                       0x6BEBF0
#define __HeadingDiff_x                                            0x99E3E0
#define __HelpPath_x                                               0xF647F4
#define __LoadFrontEnd_x                                           0x6BB050
#define __NewUIINI_x                                               0x815440
#define __ProcessGameEvents_x                                      0x611850
#define __ProcessMouseEvent_x                                      0x611010
#define __SaveColors_x                                             0x552A20
#define __STMLToText_x                                             0x941A10
#define __ToggleKeyRingItem_x                                      0x515D30
#define CMemoryMappedFile__SetFile_x                               0xA8D560
#define CrashDetected_x                                            0x6BCAF0
#define DrawNetStatus_x                                            0x63D6D0
#define Expansion_HoT_x                                            0xEC6744
#define Teleport_Table_Size_x                                      0xEB5794
#define Teleport_Table_x                                           0xEB5C48
#define Util__FastTime_x                                           0x903560

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490370
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499290
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499060
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493910
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55A5E0
#define AltAdvManager__IsAbilityReady_x                            0x559510
#define AltAdvManager__GetAAById_x                                 0x559710
#define AltAdvManager__CanTrainAbility_x                           0x559780
#define AltAdvManager__CanSeeAbility_x                             0x559AE0

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
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2730
#define CharacterZoneClient__FindItemByGuid_x                      0x4D75E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7060

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E49A0
#define CBankWnd__WndNotification_x                                0x6E4780

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F2170

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6200E0
#define CButtonWnd__CButtonWnd_x                                   0x93DDD0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x712370
#define CChatManager__InitContextMenu_x                            0x70B4C0
#define CChatManager__FreeChatWindow_x                             0x710EB0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E86D0
#define CChatManager__SetLockedActiveChatWindow_x                  0x711FF0
#define CChatManager__CreateChatWindow_x                           0x7114F0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E87E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x952480
#define CContextMenu__dCContextMenu_x                              0x9526B0
#define CContextMenu__AddMenuItem_x                                0x9526C0
#define CContextMenu__RemoveMenuItem_x                             0x9529C0
#define CContextMenu__RemoveAllMenuItems_x                         0x9529E0
#define CContextMenu__CheckMenuItem_x                              0x952A60
#define CContextMenu__SetMenuItem_x                                0x9528F0
#define CContextMenu__AddSeparator_x                               0x952850

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x952FF0
#define CContextMenuManager__RemoveMenu_x                          0x953060
#define CContextMenuManager__PopupMenu_x                           0x953120
#define CContextMenuManager__Flush_x                               0x952F90
#define CContextMenuManager__GetMenu_x                             0x49B390
#define CContextMenuManager__CreateDefaultMenu_x                   0x71D9E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DF100
#define CChatService__GetFriendName_x                              0x8DF110

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x712BE0
#define CChatWindow__Clear_x                                       0x713EA0
#define CChatWindow__WndNotification_x                             0x714630
#define CChatWindow__AddHistory_x                                  0x713760

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94F8F0
#define CComboWnd__Draw_x                                          0x94EE00
#define CComboWnd__GetCurChoice_x                                  0x94F730
#define CComboWnd__GetListRect_x                                   0x94F2A0
#define CComboWnd__GetTextRect_x                                   0x94F950
#define CComboWnd__InsertChoice_x                                  0x94F430
#define CComboWnd__SetColors_x                                     0x94F400
#define CComboWnd__SetChoice_x                                     0x94F700
#define CComboWnd__GetItemCount_x                                  0x94F740
#define CComboWnd__GetCurChoiceText_x                              0x94F780
#define CComboWnd__GetChoiceText_x                                 0x94F750
#define CComboWnd__InsertChoiceAtIndex_x                           0x94F4C0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71B3D0
#define CContainerWnd__vftable_x                                   0xB14714
#define CContainerWnd__SetContainer_x                              0x71C930

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54D450
#define CDisplay__PreZoneMainUI_x                                  0x54D460
#define CDisplay__CleanGameUI_x                                    0x5527E0
#define CDisplay__GetClickedActor_x                                0x545770
#define CDisplay__GetUserDefinedColor_x                            0x53DE30
#define CDisplay__GetWorldFilePath_x                               0x5471E0
#define CDisplay__is3dON_x                                         0x5423D0
#define CDisplay__ReloadUI_x                                       0x54C8E0
#define CDisplay__WriteTextHD2_x                                   0x5421C0
#define CDisplay__TrueDistance_x                                   0x548EA0
#define CDisplay__SetViewActor_x                                   0x545090
#define CDisplay__GetFloorHeight_x                                 0x542490
#define CDisplay__SetRenderWindow_x                                0x540DF0
#define CDisplay__ToggleScreenshotMode_x                           0x544B60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x972060

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9559D0
#define CEditWnd__GetCharIndexPt_x                                 0x9568F0
#define CEditWnd__GetDisplayString_x                               0x956790
#define CEditWnd__GetHorzOffset_x                                  0x955010
#define CEditWnd__GetLineForPrintableChar_x                        0x957A90
#define CEditWnd__GetSelStartPt_x                                  0x956BA0
#define CEditWnd__GetSTMLSafeText_x                                0x9565B0
#define CEditWnd__PointFromPrintableChar_x                         0x9576C0
#define CEditWnd__SelectableCharFromPoint_x                        0x957830
#define CEditWnd__SetEditable_x                                    0x956C70
#define CEditWnd__SetWindowTextA_x                                 0x956330

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FF550
#define CEverQuest__ClickedPlayer_x                                0x5F1560
#define CEverQuest__CreateTargetIndicator_x                        0x60EAE0
#define CEverQuest__DeleteTargetIndicator_x                        0x60EB70
#define CEverQuest__DoTellWindow_x                                 0x4E88C0
#define CEverQuest__OutputTextToLog_x                              0x4E8B40
#define CEverQuest__DropHeldItemOnGround_x                         0x5E65A0
#define CEverQuest__dsp_chat_x                                     0x4E8ED0
#define CEverQuest__trimName_x                                     0x60ADC0
#define CEverQuest__Emote_x                                        0x5FFDB0
#define CEverQuest__EnterZone_x                                    0x5F9D30
#define CEverQuest__GetBodyTypeDesc_x                              0x604680
#define CEverQuest__GetClassDesc_x                                 0x604CC0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6052C0
#define CEverQuest__GetDeityDesc_x                                 0x60D420
#define CEverQuest__GetLangDesc_x                                  0x605480
#define CEverQuest__GetRaceDesc_x                                  0x604CA0
#define CEverQuest__InterpretCmd_x                                 0x60D9F0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EA7A0
#define CEverQuest__LMouseUp_x                                     0x5E8B30
#define CEverQuest__RightClickedOnPlayer_x                         0x5EB080
#define CEverQuest__RMouseUp_x                                     0x5E9AB0
#define CEverQuest__SetGameState_x                                 0x5E6330
#define CEverQuest__UPCNotificationFlush_x                         0x60ACC0
#define CEverQuest__IssuePetCommand_x                              0x606880
#define CEverQuest__ReportSuccessfulHit_x                          0x601100

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72D240
#define CGaugeWnd__CalcLinesFillRect_x                             0x72D2A0
#define CGaugeWnd__Draw_x                                          0x72C8C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF200
#define CGuild__GetGuildName_x                                     0x4AE2E0
#define CGuild__GetGuildIndex_x                                    0x4AE670

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x748670

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6204A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7556A0
#define CInvSlotMgr__MoveItem_x                                    0x7543C0
#define CInvSlotMgr__SelectSlot_x                                  0x755770

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x752C30
#define CInvSlot__SliderComplete_x                                 0x750980
#define CInvSlot__GetItemBase_x                                    0x750300
#define CInvSlot__UpdateItem_x                                     0x750470

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7571F0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x756390
#define CInvSlotWnd__HandleLButtonUp_x                             0x756D70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x810AC0
#define CItemDisplayWnd__UpdateStrings_x                           0x765890
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75F540
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75FA70
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x765E90
#define CItemDisplayWnd__AboutToShow_x                             0x7654D0
#define CItemDisplayWnd__WndNotification_x                         0x766F80
#define CItemDisplayWnd__RequestConvertItem_x                      0x766A40
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x764530
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7652F0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x849590

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76B4D0

// CLabel 
#define CLabel__Draw_x                                             0x770F30

// CListWnd
#define CListWnd__CListWnd_x                                       0x928110
#define CListWnd__dCListWnd_x                                      0x928430
#define CListWnd__AddColumn_x                                      0x92C880
#define CListWnd__AddColumn1_x                                     0x92C8D0
#define CListWnd__AddLine_x                                        0x92CC60
#define CListWnd__AddString_x                                      0x92CA60
#define CListWnd__CalculateFirstVisibleLine_x                      0x92C640
#define CListWnd__CalculateVSBRange_x                              0x92C430
#define CListWnd__ClearSel_x                                       0x92D440
#define CListWnd__ClearAllSel_x                                    0x92D4A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92DE90
#define CListWnd__Compare_x                                        0x92BD70
#define CListWnd__Draw_x                                           0x928560
#define CListWnd__DrawColumnSeparators_x                           0x92AD40
#define CListWnd__DrawHeader_x                                     0x92B1B0
#define CListWnd__DrawItem_x                                       0x92B6B0
#define CListWnd__DrawLine_x                                       0x92AEB0
#define CListWnd__DrawSeparator_x                                  0x92ADE0
#define CListWnd__EnableLine_x                                     0x92A620
#define CListWnd__EnsureVisible_x                                  0x92DDC0
#define CListWnd__ExtendSel_x                                      0x92D370
#define CListWnd__GetColumnTooltip_x                               0x92A160
#define CListWnd__GetColumnMinWidth_x                              0x92A1D0
#define CListWnd__GetColumnWidth_x                                 0x92A0D0
#define CListWnd__GetCurSel_x                                      0x929A60
#define CListWnd__GetItemAtPoint_x                                 0x92A890
#define CListWnd__GetItemAtPoint1_x                                0x92A900
#define CListWnd__GetItemData_x                                    0x929AE0
#define CListWnd__GetItemHeight_x                                  0x929EA0
#define CListWnd__GetItemIcon_x                                    0x929C70
#define CListWnd__GetItemRect_x                                    0x92A710
#define CListWnd__GetItemText_x                                    0x929B20
#define CListWnd__GetSelList_x                                     0x92D4F0
#define CListWnd__GetSeparatorRect_x                               0x92AB40
#define CListWnd__InsertLine_x                                     0x92D050
#define CListWnd__RemoveLine_x                                     0x92D1A0
#define CListWnd__SetColors_x                                      0x92C410
#define CListWnd__SetColumnJustification_x                         0x92C140
#define CListWnd__SetColumnWidth_x                                 0x92C060
#define CListWnd__SetCurSel_x                                      0x92D2B0
#define CListWnd__SetItemColor_x                                   0x92DA80
#define CListWnd__SetItemData_x                                    0x92DA40
#define CListWnd__SetItemText_x                                    0x92D660
#define CListWnd__ShiftColumnSeparator_x                           0x92C200
#define CListWnd__Sort_x                                           0x92BEF0
#define CListWnd__ToggleSel_x                                      0x92D2E0
#define CListWnd__SetColumnsSizable_x                              0x92C2B0
#define CListWnd__SetItemWnd_x                                     0x92D910
#define CListWnd__GetItemWnd_x                                     0x929CC0
#define CListWnd__SetItemIcon_x                                    0x92D6E0
#define CListWnd__CalculateCustomWindowPositions_x                 0x92C740
#define CListWnd__SetVScrollPos_x                                  0x92C040

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x786690
#define CMapViewWnd__GetWorldCoordinates_x                         0x784DA0
#define CMapViewWnd__HandleLButtonDown_x                           0x781DE0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A6770
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A7050
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A7580
#define CMerchantWnd__SelectRecoverySlot_x                         0x7AA500
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A52E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B00C0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A6380

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8ACAF0
#define CPacketScrambler__hton_x                                   0x8ACAE0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x947080
#define CSidlManager__FindScreenPieceTemplate_x                    0x947490
#define CSidlManager__FindScreenPieceTemplate1_x                   0x947280
#define CSidlManager__CreateLabel_x                                0x807F10
#define CSidlManager__CreateXWndFromTemplate_x                     0x94A3F0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x94A5C0
#define CSidlManager__CreateXWnd_x                                 0x807E40
#define CSidlManager__CreateHotButtonWnd_x                         0x808400

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x943B40
#define CSidlScreenWnd__CalculateVSBRange_x                        0x943A40
#define CSidlScreenWnd__ConvertToRes_x                             0x9690A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9434D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9431C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x943290
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x943360
#define CSidlScreenWnd__DrawSidlPiece_x                            0x943FE0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9444B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9441D0
#define CSidlScreenWnd__Init1_x                                    0x942DC0
#define CSidlScreenWnd__LoadIniInfo_x                              0x944500
#define CSidlScreenWnd__LoadIniListWnd_x                           0x945060
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9421C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x944BD0
#define CSidlScreenWnd__StoreIniVis_x                              0x944F40
#define CSidlScreenWnd__WndNotification_x                          0x943EF0
#define CSidlScreenWnd__GetChildItem_x                             0x944430
#define CSidlScreenWnd__HandleLButtonUp_x                          0x933C90
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FAF68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x684AD0
#define CSkillMgr__GetSkillCap_x                                   0x684CB0
#define CSkillMgr__GetNameToken_x                                  0x684250
#define CSkillMgr__IsActivatedSkill_x                              0x684390
#define CSkillMgr__IsCombatSkill_x                                 0x6842D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x953DE0
#define CSliderWnd__SetValue_x                                     0x953C50
#define CSliderWnd__SetNumTicks_x                                  0x953CB0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80DF50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95C5E0
#define CStmlWnd__CalculateHSBRange_x                              0x95D710
#define CStmlWnd__CalculateVSBRange_x                              0x95D680
#define CStmlWnd__CanBreakAtCharacter_x                            0x961A40
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9626D0
#define CStmlWnd__ForceParseNow_x                                  0x95CBD0
#define CStmlWnd__GetNextTagPiece_x                                0x9619A0
#define CStmlWnd__GetSTMLText_x                                    0x505710
#define CStmlWnd__GetVisibleText_x                                 0x95CBF0
#define CStmlWnd__InitializeWindowVariables_x                      0x962520
#define CStmlWnd__MakeStmlColorTag_x                               0x95BC50
#define CStmlWnd__MakeWndNotificationTag_x                         0x95BCC0
#define CStmlWnd__SetSTMLText_x                                    0x95AD00
#define CStmlWnd__StripFirstSTMLLines_x                            0x9637D0
#define CStmlWnd__UpdateHistoryString_x                            0x9628E0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x959E50
#define CTabWnd__DrawCurrentPage_x                                 0x95A580
#define CTabWnd__DrawTab_x                                         0x95A2A0
#define CTabWnd__GetCurrentPage_x                                  0x959650
#define CTabWnd__GetPageInnerRect_x                                0x959890
#define CTabWnd__GetTabInnerRect_x                                 0x9597D0
#define CTabWnd__GetTabRect_x                                      0x959680
#define CTabWnd__InsertPage_x                                      0x959AA0
#define CTabWnd__SetPage_x                                         0x959910
#define CTabWnd__SetPageRect_x                                     0x959D90
#define CTabWnd__UpdatePage_x                                      0x95A160
#define CTabWnd__GetPageFromTabIndex_x                             0x95A1E0
#define CTabWnd__GetCurrentTabIndex_x                              0x959640

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76B8A0
#define CPageWnd__SetTabText_x                                     0x9591A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8E50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x930B80
#define CTextureFont__GetTextExtent_x                              0x930D40

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B7C10
#define CHtmlComponentWnd__ValidateUri_x                           0x74A060
#define CHtmlWnd__SetClientCallbacks_x                             0x625530
#define CHtmlWnd__AddObserver_x                                    0x625550
#define CHtmlWnd__RemoveObserver_x                                 0x6255B0
#define Window__getProgress_x                                      0x861BB0
#define Window__getStatus_x                                        0x861BD0
#define Window__getURI_x                                           0x861BE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96EAF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91DD70

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8410
#define CXStr__CXStr1_x                                            0x8524C0
#define CXStr__CXStr3_x                                            0x8FFAD0
#define CXStr__dCXStr_x                                            0x478680
#define CXStr__operator_equal_x                                    0x8FFD00
#define CXStr__operator_equal1_x                                   0x8FFD40
#define CXStr__operator_plus_equal1_x                              0x9007D0
#define CXStr__SetString_x                                         0x9026C0
#define CXStr__operator_char_p_x                                   0x900210
#define CXStr__GetChar_x                                           0x901FF0
#define CXStr__Delete_x                                            0x9018C0
#define CXStr__GetUnicode_x                                        0x902060
#define CXStr__GetLength_x                                         0x47D400
#define CXStr__Mid_x                                               0x47D410
#define CXStr__Insert_x                                            0x9020C0
#define CXStr__FindNext_x                                          0x901D30

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9520A0
#define CXWnd__BringToTop_x                                        0x937440
#define CXWnd__Center_x                                            0x936FC0
#define CXWnd__ClrFocus_x                                          0x936DE0
#define CXWnd__Destroy_x                                           0x936E80
#define CXWnd__DoAllDrawing_x                                      0x933440
#define CXWnd__DrawChildren_x                                      0x933410
#define CXWnd__DrawColoredRect_x                                   0x9338A0
#define CXWnd__DrawTooltip_x                                       0x931F80
#define CXWnd__DrawTooltipAtPoint_x                                0x932040
#define CXWnd__GetBorderFrame_x                                    0x933700
#define CXWnd__GetChildWndAt_x                                     0x9374E0
#define CXWnd__GetClientClipRect_x                                 0x9356B0
#define CXWnd__GetScreenClipRect_x                                 0x935780
#define CXWnd__GetScreenRect_x                                     0x935940
#define CXWnd__GetTooltipRect_x                                    0x9338F0
#define CXWnd__GetWindowTextA_x                                    0x49CAB0
#define CXWnd__IsActive_x                                          0x934010
#define CXWnd__IsDescendantOf_x                                    0x936340
#define CXWnd__IsReallyVisible_x                                   0x936370
#define CXWnd__IsType_x                                            0x937B50
#define CXWnd__Move_x                                              0x9363E0
#define CXWnd__Move1_x                                             0x936490
#define CXWnd__ProcessTransition_x                                 0x936F70
#define CXWnd__Refade_x                                            0x936760
#define CXWnd__Resize_x                                            0x9369F0
#define CXWnd__Right_x                                             0x937200
#define CXWnd__SetFocus_x                                          0x936DA0
#define CXWnd__SetFont_x                                           0x936E10
#define CXWnd__SetKeyTooltip_x                                     0x937960
#define CXWnd__SetMouseOver_x                                      0x934840
#define CXWnd__StartFade_x                                         0x936230
#define CXWnd__GetChildItem_x                                      0x937650
#define CXWnd__SetParent_x                                         0x9360F0
#define CXWnd__Minimize_x                                          0x936A60

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96A120

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x93A360
#define CXWndManager__DrawWindows_x                                0x93A380
#define CXWndManager__GetKeyboardFlags_x                           0x93CA70
#define CXWndManager__HandleKeyboardMsg_x                          0x93C620
#define CXWndManager__RemoveWnd_x                                  0x93CC90
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93D1F0

// CDBStr
#define CDBStr__GetString_x                                        0x53CDC0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB880
#define EQ_Character__Cur_HP_x                                     0x4D1FA0
#define EQ_Character__Cur_Mana_x                                   0x4D96F0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE8F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2370
#define EQ_Character__GetFocusRangeModifier_x                      0x4B24C0
#define EQ_Character__GetHPRegen_x                                 0x4DF4C0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFAC0
#define EQ_Character__GetManaRegen_x                               0x4DFF00
#define EQ_Character__Max_Endurance_x                              0x64B7F0
#define EQ_Character__Max_HP_x                                     0x4D1DD0
#define EQ_Character__Max_Mana_x                                   0x64B5F0
#define EQ_Character__doCombatAbility_x                            0x64DC40
#define EQ_Character__UseSkill_x                                   0x4E1CD0
#define EQ_Character__GetConLevel_x                                0x644600
#define EQ_Character__IsExpansionFlag_x                            0x5A7E80
#define EQ_Character__TotalEffect_x                                0x4C5340
#define EQ_Character__GetPCSpellAffect_x                           0x4BF640
#define EQ_Character__SpellDuration_x                              0x4BF170
#define EQ_Character__GetAdjustedSkill_x                           0x4D4D20
#define EQ_Character__GetBaseSkill_x                               0x4D5CC0
#define EQ_Character__CanUseItem_x                                 0x4D9A00

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CBE70

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x661CE0

//PcClient
#define PcClient__PcClient_x                                       0x641D40

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B94E0
#define CCharacterListWnd__EnterWorld_x                            0x4B8F20
#define CCharacterListWnd__Quit_x                                  0x4B8C70
#define CCharacterListWnd__UpdateList_x                            0x4B90B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x626770
#define EQ_Item__CreateItemTagString_x                             0x8A6290
#define EQ_Item__IsStackable_x                                     0x8AAE90
#define EQ_Item__GetImageNum_x                                     0x8A7D50
#define EQ_Item__CreateItemClient_x                                0x625930
#define EQ_Item__GetItemValue_x                                    0x8A9040
#define EQ_Item__ValueSellMerchant_x                               0x8AC6D0
#define EQ_Item__IsKeyRingItem_x                                   0x8AA790
#define EQ_Item__CanGoInBag_x                                      0x626890
#define EQ_Item__IsEmpty_x                                         0x8AA2F0
#define EQ_Item__GetMaxItemCount_x                                 0x8A9460
#define EQ_Item__GetHeldItem_x                                     0x8A7C20
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A5BE0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55B2B0
#define EQ_LoadingS__Array_x                                       0xC29B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64C150
#define EQ_PC__GetAlternateAbilityId_x                             0x8B59C0
#define EQ_PC__GetCombatAbility_x                                  0x8B6030
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B60A0
#define EQ_PC__GetItemRecastTimer_x                                0x64E1C0
#define EQ_PC__HasLoreItem_x                                       0x644E10
#define EQ_PC__AlertInventoryChanged_x                             0x643F40
#define EQ_PC__GetPcZoneClient_x                                   0x670780
#define EQ_PC__RemoveMyAffect_x                                    0x651400
#define EQ_PC__GetKeyRingItems_x                                   0x8B6930
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B66C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B6C30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AE3E0
#define EQItemList__add_object_x                                   0x5DBDA0
#define EQItemList__add_item_x                                     0x5AE940
#define EQItemList__delete_item_x                                  0x5AE990
#define EQItemList__FreeItemList_x                                 0x5AE890

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5398D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x663560
#define EQPlayer__dEQPlayer_x                                      0x6568C0
#define EQPlayer__DoAttack_x                                       0x66B420
#define EQPlayer__EQPlayer_x                                       0x656F80
#define EQPlayer__SetNameSpriteState_x                             0x65B240
#define EQPlayer__SetNameSpriteTint_x                              0x65C110
#define PlayerBase__HasProperty_j_x                                0x99C780
#define EQPlayer__IsTargetable_x                                   0x99CC20
#define EQPlayer__CanSee_x                                         0x99CA80
#define EQPlayer__CanSee1_x                                        0x99CB50
#define PlayerBase__GetVisibilityLineSegment_x                     0x99C840

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66E220
#define PlayerZoneClient__GetLevel_x                               0x6707C0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DCF10
#define PlayerZoneClient__LegalPlayerRace_x                        0x554670

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x666340
#define EQPlayerManager__GetSpawnByName_x                          0x6663F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x666480

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x629E90
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x629F10
#define KeypressHandler__AttachKeyToEqCommand_x                    0x629F50
#define KeypressHandler__ClearCommandStateArray_x                  0x62B360
#define KeypressHandler__HandleKeyDown_x                           0x62B380
#define KeypressHandler__HandleKeyUp_x                             0x62B420
#define KeypressHandler__SaveKeymapping_x                          0x62B870

// MapViewMap 
#define MapViewMap__Clear_x                                        0x782500
#define MapViewMap__SaveEx_x                                       0x7858C0
#define MapViewMap__SetZoom_x                                      0x789F80

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C9D90

// StringTable 
#define StringTable__getString_x                                   0x8C4C70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x651070
#define PcZoneClient__RemovePetEffect_x                            0x6516A0
#define PcZoneClient__HasAlternateAbility_x                        0x64B420
#define PcZoneClient__GetCurrentMod_x                              0x4E4D90
#define PcZoneClient__GetModCap_x                                  0x4E4C90
#define PcZoneClient__CanEquipItem_x                               0x64BAF0
#define PcZoneClient__GetItemByID_x                                0x64E640
#define PcZoneClient__GetItemByItemClass_x                         0x64E790
#define PcZoneClient__RemoveBuffEffect_x                           0x6516C0
#define PcZoneClient__BandolierSwap_x                              0x64C700
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64E160

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E1A90

//IconCache
#define IconCache__GetIcon_x                                       0x722A90

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71A560
#define CContainerMgr__CloseContainer_x                            0x71A830
#define CContainerMgr__OpenExperimentContainer_x                   0x71B2B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DA5A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61E8B0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x778A00
#define CLootWnd__RequestLootSlot_x                                0x777C30

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57B810
#define EQ_Spell__SpellAffects_x                                   0x57BC80
#define EQ_Spell__SpellAffectBase_x                                0x57BA40
#define EQ_Spell__IsStackable_x                                    0x4C99D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9850
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6860
#define EQ_Spell__IsSPAStacking_x                                  0x57CAD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57BFE0
#define EQ_Spell__IsNoRemove_x                                     0x4C99B0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57CAE0
#define __IsResEffectSpell_x                                       0x4C8D80

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACF00

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D44D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x821270
#define CTargetWnd__WndNotification_x                              0x820B00
#define CTargetWnd__RefreshTargetBuffs_x                           0x820DD0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81FC60

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x825870

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x537310
#define CTaskManager__HandleMessage_x                              0x5357A0
#define CTaskManager__GetTaskStatus_x                              0x5373C0
#define CTaskManager__GetElementDescription_x                      0x537440

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x576D50
#define EqSoundManager__PlayScriptMp3_x                            0x576EB0
#define EqSoundManager__SoundAssistPlay_x                          0x688A10
#define EqSoundManager__WaveInstancePlay_x                         0x687F80

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52B0F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9586B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562D20
#define CAltAbilityData__GetMercMaxRank_x                          0x562CB0
#define CAltAbilityData__GetMaxRank_x                              0x558390

//CTargetRing
#define CTargetRing__Cast_x                                        0x61C9C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9830
#define CharacterBase__CreateItemGlobalIndex_x                     0x5123B0
#define CharacterBase__CreateItemIndex_x                           0x624AE0
#define CharacterBase__GetItemPossession_x                         0x4FE1C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DCAC0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DCB20
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x701700
#define CCastSpellWnd__IsBardSongPlaying_x                         0x701F30
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x701FE0

//messages
#define msg_spell_worn_off_x                                       0x5A0070
#define msg_new_text_x                                             0x594E00
#define __msgTokenTextParam_x                                      0x5A25A0
#define msgTokenText_x                                             0x5A27F0

//SpellManager
#define SpellManager__vftable_x                                    0xAEE4E4
#define SpellManager__SpellManager_x                               0x68BD40
#define Spellmanager__LoadTextSpells_x                             0x68C630
#define SpellManager__GetSpellByGroupAndRank_x                     0x68BF10

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A06B0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x512A00
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A6360
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63D530
#define ItemGlobalIndex__IsValidIndex_x                            0x512A60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D4E70
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D50F0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x771270

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71EC80
#define CCursorAttachment__AttachToCursor1_x                       0x71ECC0
#define CCursorAttachment__Deactivate_x                            0x71FCB0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94B400
#define CSidlManagerBase__CreatePageWnd_x                          0x94AC00
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x946EA0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x946E30

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x968460
#define CEQSuiteTextureLoader__GetTexture_x                        0x968120

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F920
#define CFindItemWnd__WndNotification_x                            0x510400
#define CFindItemWnd__Update_x                                     0x510F70
#define CFindItemWnd__PickupSelectedItem_x                         0x50F160

//IString
#define IString__Append_x                                          0x4F0AF0

//Camera
#define CDisplay__cameraType_x                                     0xE03568
#define EverQuest__Cameras_x                                       0xEC6A94

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5180D0
#define LootFiltersManager__GetItemFilterData_x                    0x5179D0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x517A00
#define LootFiltersManager__SetItemLootFilter_x                    0x517C20

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C85B0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A6270
#define CResolutionHandler__GetWindowedStyle_x                     0x683590

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x717340

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8EA170
#define CDistillerInfo__Instance_x                                 0x8EA110

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x737460
#define CGroupWnd__UpdateDisplay_x                                 0x7367C0

//ItemBase
#define ItemBase__IsLore_x                                         0x8AA840
#define ItemBase__IsLoreEquipped_x                                 0x8AA8C0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DBD00
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DBE40
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DBEA0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678F00
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67C860

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505D60

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2840
#define FactionManagerClient__HandleFactionMessage_x               0x4F2EB0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3470
#define FactionManagerClient__GetMaxFaction_x                      0x4F348F
#define FactionManagerClient__GetMinFaction_x                      0x4F3440

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FE190

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92FB30

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD90

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FE410

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5621C0

//CTargetManager
#define CTargetManager__Get_x                                      0x68F590

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678F00

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8C10

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AE830

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF64128

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
