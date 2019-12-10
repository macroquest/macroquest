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
#define __ExpectedVersionDate                                     "Dec  9 2019"
#define __ExpectedVersionTime                                     "12:04:23"
#define __ActualVersionDate_x                                      0xB0C674
#define __ActualVersionTime_x                                      0xB0C668
#define __ActualVersionBuild_x                                     0xAF833C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x630660
#define __MemChecker1_x                                            0x904190
#define __MemChecker2_x                                            0x6BECC0
#define __MemChecker3_x                                            0x6BEC10
#define __MemChecker4_x                                            0x85ADD0
#define __EncryptPad0_x                                            0xC433E8
#define __EncryptPad1_x                                            0xCA15E8
#define __EncryptPad2_x                                            0xC53C80
#define __EncryptPad3_x                                            0xC53880
#define __EncryptPad4_x                                            0xC91C00
#define __EncryptPad5_x                                            0xF6D210
#define __AC1_x                                                    0x8177E6
#define __AC2_x                                                    0x5EA3CF
#define __AC3_x                                                    0x5F1ACF
#define __AC4_x                                                    0x5F5AA0
#define __AC5_x                                                    0x5FBDAF
#define __AC6_x                                                    0x6003C6
#define __AC7_x                                                    0x5E9E40
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191E2C

// Direct Input
#define DI8__Main_x                                                0xF6D238
#define DI8__Keyboard_x                                            0xF6D23C
#define DI8__Mouse_x                                               0xF6D21C
#define DI8__Mouse_Copy_x                                          0xEC641C
#define DI8__Mouse_Check_x                                         0xF6AD64
#define __AutoSkillArray_x                                         0xEC7334
#define __Attack_x                                                 0xF6515B
#define __Autofire_x                                               0xF6515C
#define __BindList_x                                               0xC31E20
#define g_eqCommandStates_x                                        0xC32BA0
#define __Clicks_x                                                 0xEC64D4
#define __CommandList_x                                            0xC33760
#define __CurrentMapLabel_x                                        0xF7DBDC
#define __CurrentSocial_x                                          0xC1B7CC
#define __DoAbilityList_x                                          0xEFCC7C
#define __do_loot_x                                                0x5B5D90
#define __DrawHandler_x                                            0x15FCF50
#define __GroupCount_x                                             0xEB8DD2
#define __Guilds_x                                                 0xEBCC28
#define __gWorld_x                                                 0xEB8C88
#define __HWnd_x                                                   0xF6D220
#define __heqmain_x                                                0xF6D1F8
#define __InChatMode_x                                             0xEC6404
#define __LastTell_x                                               0xEC8378
#define __LMouseHeldTime_x                                         0xEC6540
#define __Mouse_x                                                  0xF6D224
#define __MouseLook_x                                              0xEC649A
#define __MouseEventTime_x                                         0xF65C3C
#define __gpbCommandEvent_x                                        0xEB66C0
#define __NetStatusToggle_x                                        0xEC649D
#define __PCNames_x                                                0xEC7924
#define __RangeAttackReady_x                                       0xEC7618
#define __RMouseHeldTime_x                                         0xEC653C
#define __RunWalkState_x                                           0xEC6408
#define __ScreenMode_x                                             0xE0409C
#define __ScreenX_x                                                0xEC63BC
#define __ScreenY_x                                                0xEC63B8
#define __ScreenXMax_x                                             0xEC63C0
#define __ScreenYMax_x                                             0xEC63C4
#define __ServerHost_x                                             0xEB68F3
#define __ServerName_x                                             0xEFCC3C
#define __ShiftKeyDown_x                                           0xEC6A94
#define __ShowNames_x                                              0xEC77D4
#define __Socials_x                                                0xEFCD3C
#define __SubscriptionType_x                                       0xFC20E0
#define __TargetAggroHolder_x                                      0xF80590
#define __ZoneType_x                                               0xEC6898
#define __GroupAggro_x                                             0xF805D0
#define __LoginName_x                                              0xF6D98C
#define __Inviter_x                                                0xF650D8
#define __AttackOnAssist_x                                         0xEC7790
#define __UseTellWindows_x                                         0xEC7AC0
#define __gfMaxZoomCameraDistance_x                                0xB01FD0
#define __gfMaxCameraDistance_x                                    0xB2E524
#define __pulAutoRun_x                                             0xEC64B8
#define __pulForward_x                                             0xEC7AF8
#define __pulBackward_x                                            0xEC7AFC
#define __pulTurnRight_x                                           0xEC7B00
#define __pulTurnLeft_x                                            0xEC7B04
#define __pulStrafeLeft_x                                          0xEC7B08
#define __pulStrafeRight_x                                         0xEC7B0C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB8FC8
#define instEQZoneInfo_x                                           0xEC6690
#define pinstActiveBanker_x                                        0xEB66D8
#define pinstActiveCorpse_x                                        0xEB66D0
#define pinstActiveGMaster_x                                       0xEB66D4
#define pinstActiveMerchant_x                                      0xEB66CC
#define pinstAltAdvManager_x                                       0xE05200
#define pinstBandageTarget_x                                       0xEB66E8
#define pinstCamActor_x                                            0xE04090
#define pinstCDBStr_x                                              0xE03F1C
#define pinstCDisplay_x                                            0xEB8C84
#define pinstCEverQuest_x                                          0xF6D250
#define pinstEverQuestInfo_x                                       0xEC63B0
#define pinstCharData_x                                            0xEB8DB4
#define pinstCharSpawn_x                                           0xEB6720
#define pinstControlledMissile_x                                   0xEB6C0C
#define pinstControlledPlayer_x                                    0xEB6720
#define pinstCResolutionHandler_x                                  0x15FD180
#define pinstCSidlManager_x                                        0x15FC118
#define pinstCXWndManager_x                                        0x15FC114
#define instDynamicZone_x                                          0xEBCB00
#define pinstDZMember_x                                            0xEBCC10
#define pinstDZTimerInfo_x                                         0xEBCC14
#define pinstEqLogin_x                                             0xF6D2D8
#define instEQMisc_x                                               0xE03E60
#define pinstEQSoundManager_x                                      0xE061D0
#define pinstEQSpellStrings_x                                      0xCC6878
#define instExpeditionLeader_x                                     0xEBCB4A
#define instExpeditionName_x                                       0xEBCB8A
#define pinstGroup_x                                               0xEB8DCE
#define pinstImeManager_x                                          0x15FC110
#define pinstLocalPlayer_x                                         0xEB66C8
#define pinstMercenaryData_x                                       0xF6772C
#define pinstMercenaryStats_x                                      0xF806DC
#define pinstModelPlayer_x                                         0xEB66E0
#define pinstPCData_x                                              0xEB8DB4
#define pinstSkillMgr_x                                            0xF69898
#define pinstSpawnManager_x                                        0xF68340
#define pinstSpellManager_x                                        0xF69AB8
#define pinstSpellSets_x                                           0xF5DD84
#define pinstStringTable_x                                         0xEB8DB8
#define pinstSwitchManager_x                                       0xEB6568
#define pinstTarget_x                                              0xEB671C
#define pinstTargetObject_x                                        0xEB67A8
#define pinstTargetSwitch_x                                        0xEB8C28
#define pinstTaskMember_x                                          0xE03CF0
#define pinstTrackTarget_x                                         0xEB6724
#define pinstTradeTarget_x                                         0xEB66DC
#define instTributeActive_x                                        0xE03E81
#define pinstViewActor_x                                           0xE0408C
#define pinstWorldData_x                                           0xEB6C08
#define pinstZoneAddr_x                                            0xEC6930
#define pinstPlayerPath_x                                          0xF683D8
#define pinstTargetIndicator_x                                     0xF69D20
#define EQObject_Top_x                                             0xEB66C4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE047EC
#define pinstCAchievementsWnd_x                                    0xE047E8
#define pinstCActionsWnd_x                                         0xE047B0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE04020
#define pinstCAdvancedLootWnd_x                                    0xE03FE0
#define pinstCAdventureLeaderboardWnd_x                            0xF773B0
#define pinstCAdventureRequestWnd_x                                0xF77460
#define pinstCAdventureStatsWnd_x                                  0xF77510
#define pinstCAggroMeterWnd_x                                      0xE04540
#define pinstCAlarmWnd_x                                           0xE04848
#define pinstCAlertHistoryWnd_x                                    0xE04040
#define pinstCAlertStackWnd_x                                      0xE04850
#define pinstCAlertWnd_x                                           0xE03FC4
#define pinstCAltStorageWnd_x                                      0xF77870
#define pinstCAudioTriggersWindow_x                                0xCB8BA8
#define pinstCAuraWnd_x                                            0xE04064
#define pinstCAvaZoneWnd_x                                         0xE03FF8
#define pinstCBandolierWnd_x                                       0xE040D4
#define pinstCBankWnd_x                                            0xE04060
#define pinstCBarterMerchantWnd_x                                  0xF78AB0
#define pinstCBarterSearchWnd_x                                    0xF78B60
#define pinstCBarterWnd_x                                          0xF78C10
#define pinstCBazaarConfirmationWnd_x                              0xE04814
#define pinstCBazaarSearchWnd_x                                    0xE04588
#define pinstCBazaarWnd_x                                          0xE04830
#define pinstCBlockedBuffWnd_x                                     0xE04068
#define pinstCBlockedPetBuffWnd_x                                  0xE040C0
#define pinstCBodyTintWnd_x                                        0xE047C0
#define pinstCBookWnd_x                                            0xE04564
#define pinstCBreathWnd_x                                          0xE04804
#define pinstCBuffWindowNORMAL_x                                   0xE04044
#define pinstCBuffWindowSHORT_x                                    0xE04048
#define pinstCBugReportWnd_x                                       0xE04058
#define pinstCButtonWnd_x                                          0x15FC380
#define pinstCCastingWnd_x                                         0xE04558
#define pinstCCastSpellWnd_x                                       0xE04800
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE04834
#define pinstCChatWindowManager_x                                  0xF796D0
#define pinstCClaimWnd_x                                           0xF79828
#define pinstCColorPickerWnd_x                                     0xE047B8
#define pinstCCombatAbilityWnd_x                                   0xE04840
#define pinstCCombatSkillsSelectWnd_x                              0xE03FC8
#define pinstCCompassWnd_x                                         0xE047B4
#define pinstCConfirmationDialog_x                                 0xF7E728
#define pinstCContainerMgr_x                                       0xE04828
#define pinstCContextMenuManager_x                                 0x15FC0D0
#define pinstCCursorAttachment_x                                   0xE0454C
#define pinstCDynamicZoneWnd_x                                     0xF79DF0
#define pinstCEditLabelWnd_x                                       0xE0403C
#define pinstCEQMainWnd_x                                          0xF7A038
#define pinstCEventCalendarWnd_x                                   0xE04550
#define pinstCExtendedTargetWnd_x                                  0xE040B4
#define pinstCFacePick_x                                           0xE03FD8
#define pinstCFactionWnd_x                                         0xE04824
#define pinstCFellowshipWnd_x                                      0xF7A238
#define pinstCFileSelectionWnd_x                                   0xE04554
#define pinstCFindItemWnd_x                                        0xE04810
#define pinstCFindLocationWnd_x                                    0xF7A390
#define pinstCFriendsWnd_x                                         0xE03FDC
#define pinstCGemsGameWnd_x                                        0xE04820
#define pinstCGiveWnd_x                                            0xE0484C
#define pinstCGroupSearchFiltersWnd_x                              0xE0455C
#define pinstCGroupSearchWnd_x                                     0xF7A788
#define pinstCGroupWnd_x                                           0xF7A838
#define pinstCGuildBankWnd_x                                       0xEC7774
#define pinstCGuildCreationWnd_x                                   0xF7A998
#define pinstCGuildMgmtWnd_x                                       0xF7AA48
#define pinstCharacterCreation_x                                   0xE03FD0
#define pinstCHelpWnd_x                                            0xE04014
#define pinstCHeritageSelectionWnd_x                               0xE03FE4
#define pinstCHotButtonWnd_x                                       0xF7CBA0
#define pinstCHotButtonWnd1_x                                      0xF7CBA0
#define pinstCHotButtonWnd2_x                                      0xF7CBA4
#define pinstCHotButtonWnd3_x                                      0xF7CBA8
#define pinstCHotButtonWnd4_x                                      0xF7CBAC
#define pinstCIconSelectionWnd_x                                   0xE04544
#define pinstCInspectWnd_x                                         0xE04010
#define pinstCInventoryWnd_x                                       0xE03FE8
#define pinstCInvSlotMgr_x                                         0xE047E4
#define pinstCItemDisplayManager_x                                 0xF7D130
#define pinstCItemExpTransferWnd_x                                 0xF7D260
#define pinstCItemOverflowWnd_x                                    0xE0458C
#define pinstCJournalCatWnd_x                                      0xE04568
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE040B8
#define pinstCKeyRingWnd_x                                         0xE04030
#define pinstCLargeDialogWnd_x                                     0xF7F3A8
#define pinstCLayoutCopyWnd_x                                      0xF7D5B0
#define pinstCLFGuildWnd_x                                         0xF7D660
#define pinstCLoadskinWnd_x                                        0xE0482C
#define pinstCLootFiltersCopyWnd_x                                 0xCD51F8
#define pinstCLootFiltersWnd_x                                     0xE03FB8
#define pinstCLootSettingsWnd_x                                    0xE03FD4
#define pinstCLootWnd_x                                            0xE0456C
#define pinstCMailAddressBookWnd_x                                 0xE047F0
#define pinstCMailCompositionWnd_x                                 0xE047D0
#define pinstCMailIgnoreListWnd_x                                  0xE047F4
#define pinstCMailWnd_x                                            0xE047AC
#define pinstCManageLootWnd_x                                      0xE056B0
#define pinstCMapToolbarWnd_x                                      0xE0401C
#define pinstCMapViewWnd_x                                         0xE03FF4
#define pinstCMarketplaceWnd_x                                     0xE03FBC
#define pinstCMerchantWnd_x                                        0xE04570
#define pinstCMIZoneSelectWnd_x                                    0xF7DE98
#define pinstCMusicPlayerWnd_x                                     0xE04584
#define pinstCNameChangeMercWnd_x                                  0xE0480C
#define pinstCNameChangePetWnd_x                                   0xE047F8
#define pinstCNameChangeWnd_x                                      0xE0481C
#define pinstCNoteWnd_x                                            0xE03FFC
#define pinstCObjectPreviewWnd_x                                   0xE03FCC
#define pinstCOptionsWnd_x                                         0xE04000
#define pinstCPetInfoWnd_x                                         0xE04594
#define pinstCPetitionQWnd_x                                       0xE047D8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE047C4
#define pinstCPlayerWnd_x                                          0xE04598
#define pinstCPopupWndManager_x                                    0xF7E728
#define pinstCProgressionSelectionWnd_x                            0xF7E7D8
#define pinstCPurchaseGroupWnd_x                                   0xE04008
#define pinstCPurchaseWnd_x                                        0xE03FEC
#define pinstCPvPLeaderboardWnd_x                                  0xF7E888
#define pinstCPvPStatsWnd_x                                        0xF7E938
#define pinstCQuantityWnd_x                                        0xE040BC
#define pinstCRaceChangeWnd_x                                      0xE04844
#define pinstCRaidOptionsWnd_x                                     0xE04560
#define pinstCRaidWnd_x                                            0xE047D4
#define pinstCRealEstateItemsWnd_x                                 0xE047E0
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE04574
#define pinstCRealEstateManageWnd_x                                0xE04018
#define pinstCRealEstateNeighborhoodWnd_x                          0xE04034
#define pinstCRealEstatePlotSearchWnd_x                            0xE0405C
#define pinstCRealEstatePurchaseWnd_x                              0xE040B0
#define pinstCRespawnWnd_x                                         0xE040AC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE047FC
#define pinstCSendMoneyWnd_x                                       0xE03FC0
#define pinstCServerListWnd_x                                      0xE0413C
#define pinstCSkillsSelectWnd_x                                    0xE04838
#define pinstCSkillsWnd_x                                          0xE04818
#define pinstCSocialEditWnd_x                                      0xE04028
#define pinstCSocialWnd_x                                          0xE04808
#define pinstCSpellBookWnd_x                                       0xE0483C
#define pinstCStoryWnd_x                                           0xE0459C
#define pinstCTargetOfTargetWnd_x                                  0xF80760
#define pinstCTargetWnd_x                                          0xE040A8
#define pinstCTaskOverlayWnd_x                                     0xE04004
#define pinstCTaskSelectWnd_x                                      0xF808B8
#define pinstCTaskManager_x                                        0xCD5B38
#define pinstCTaskTemplateSelectWnd_x                              0xF80968
#define pinstCTaskWnd_x                                            0xF80A18
#define pinstCTextEntryWnd_x                                       0xE0404C
#define pinstCTimeLeftWnd_x                                        0xE047A8
#define pinstCTipWndCONTEXT_x                                      0xF80C1C
#define pinstCTipWndOFDAY_x                                        0xF80C18
#define pinstCTitleWnd_x                                           0xF80CC8
#define pinstCTrackingWnd_x                                        0xE03FF0
#define pinstCTradeskillWnd_x                                      0xF80E30
#define pinstCTradeWnd_x                                           0xE047CC
#define pinstCTrainWnd_x                                           0xE047C8
#define pinstCTributeBenefitWnd_x                                  0xF81030
#define pinstCTributeMasterWnd_x                                   0xF810E0
#define pinstCTributeTrophyWnd_x                                   0xF81190
#define pinstCVideoModesWnd_x                                      0xE045A0
#define pinstCVoiceMacroWnd_x                                      0xF6A488
#define pinstCVoteResultsWnd_x                                     0xE047DC
#define pinstCVoteWnd_x                                            0xE047BC
#define pinstCWebManager_x                                         0xF6AB04
#define pinstCZoneGuideWnd_x                                       0xE0400C
#define pinstCZonePathWnd_x                                        0xE04024

#define pinstEQSuiteTextureLoader_x                                0xCA30C0
#define pinstItemIconCache_x                                       0xF79FF0
#define pinstLootFiltersManager_x                                  0xCD52A8
#define pinstRewardSelectionWnd_x                                  0xF7F080

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B11F0
#define __CastRay2_x                                               0x5B1240
#define __ConvertItemTags_x                                        0x5CCDA0
#define __CleanItemTags_x                                          0x47CF70
#define __DoesFileExist_x                                          0x907220
#define __EQGetTime_x                                              0x903C60
#define __ExecuteCmd_x                                             0x5A9A20
#define __FixHeading_x                                             0x99E870
#define __GameLoop_x                                               0x6BDEB0
#define __get_bearing_x                                            0x5B0D60
#define __get_melee_range_x                                        0x5B1430
#define __GetAnimationCache_x                                      0x723110
#define __GetGaugeValueFromEQ_x                                    0x815C90
#define __GetLabelFromEQ_x                                         0x817770
#define __GetXTargetType_x                                         0x9A0250
#define __HandleMouseWheel_x                                       0x6BED70
#define __HeadingDiff_x                                            0x99E8E0
#define __HelpPath_x                                               0xF6582C
#define __LoadFrontEnd_x                                           0x6BB1D0
#define __NewUIINI_x                                               0x815960
#define __ProcessGameEvents_x                                      0x611B80
#define __ProcessMouseEvent_x                                      0x611340
#define __SaveColors_x                                             0x5530A0
#define __STMLToText_x                                             0x941F60
#define __ToggleKeyRingItem_x                                      0x516810
#define CMemoryMappedFile__SetFile_x                               0xA8DBC0
#define CrashDetected_x                                            0x6BCC70
#define DrawNetStatus_x                                            0x63D880
#define Expansion_HoT_x                                            0xEC777C
#define Teleport_Table_Size_x                                      0xEB67B0
#define Teleport_Table_x                                           0xEB6C28
#define Util__FastTime_x                                           0x903830

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4901E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4990F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498EC0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493780
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492BD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55ACB0
#define AltAdvManager__IsAbilityReady_x                            0x559BE0
#define AltAdvManager__GetAAById_x                                 0x559DE0
#define AltAdvManager__CanTrainAbility_x                           0x559E50
#define AltAdvManager__CanSeeAbility_x                             0x55A1B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9DE0
#define CharacterZoneClient__HasSkill_x                            0x4D4CD0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D63F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE190
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA790
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8DA0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8E80
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8F60
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2F90
#define CharacterZoneClient__BardCastBard_x                        0x4C5AF0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA860
#define CharacterZoneClient__GetEffect_x                           0x4BA6D0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3FE0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C40B0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4100
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4250
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4420
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B25B0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7350
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6DD0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E4980
#define CBankWnd__WndNotification_x                                0x6E4760

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F2260

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6203D0
#define CButtonWnd__CButtonWnd_x                                   0x93E330

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7122D0
#define CChatManager__InitContextMenu_x                            0x70B430
#define CChatManager__FreeChatWindow_x                             0x710E10
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8350
#define CChatManager__SetLockedActiveChatWindow_x                  0x711F50
#define CChatManager__CreateChatWindow_x                           0x711450

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8460

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x952970
#define CContextMenu__dCContextMenu_x                              0x952BA0
#define CContextMenu__AddMenuItem_x                                0x952BB0
#define CContextMenu__RemoveMenuItem_x                             0x952EC0
#define CContextMenu__RemoveAllMenuItems_x                         0x952EE0
#define CContextMenu__CheckMenuItem_x                              0x952F60
#define CContextMenu__SetMenuItem_x                                0x952DE0
#define CContextMenu__AddSeparator_x                               0x952D40

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x953500
#define CContextMenuManager__RemoveMenu_x                          0x953570
#define CContextMenuManager__PopupMenu_x                           0x953630
#define CContextMenuManager__Flush_x                               0x9534A0
#define CContextMenuManager__GetMenu_x                             0x49B340
#define CContextMenuManager__CreateDefaultMenu_x                   0x71D910

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DF010
#define CChatService__GetFriendName_x                              0x8DF020

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x712B40
#define CChatWindow__Clear_x                                       0x713DF0
#define CChatWindow__WndNotification_x                             0x714580
#define CChatWindow__AddHistory_x                                  0x7136B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94FDE0
#define CComboWnd__Draw_x                                          0x94F2E0
#define CComboWnd__GetCurChoice_x                                  0x94FC20
#define CComboWnd__GetListRect_x                                   0x94F790
#define CComboWnd__GetTextRect_x                                   0x94FE50
#define CComboWnd__InsertChoice_x                                  0x94F920
#define CComboWnd__SetColors_x                                     0x94F8F0
#define CComboWnd__SetChoice_x                                     0x94FBF0
#define CComboWnd__GetItemCount_x                                  0x94FC30
#define CComboWnd__GetCurChoiceText_x                              0x94FC70
#define CComboWnd__GetChoiceText_x                                 0x94FC40
#define CComboWnd__InsertChoiceAtIndex_x                           0x94F9B0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71B310
#define CContainerWnd__vftable_x                                   0xB15864
#define CContainerWnd__SetContainer_x                              0x71C870

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54DAD0
#define CDisplay__PreZoneMainUI_x                                  0x54DAE0
#define CDisplay__CleanGameUI_x                                    0x552E60
#define CDisplay__GetClickedActor_x                                0x545DF0
#define CDisplay__GetUserDefinedColor_x                            0x53E4B0
#define CDisplay__GetWorldFilePath_x                               0x547860
#define CDisplay__is3dON_x                                         0x542A50
#define CDisplay__ReloadUI_x                                       0x54CF60
#define CDisplay__WriteTextHD2_x                                   0x542840
#define CDisplay__TrueDistance_x                                   0x549520
#define CDisplay__SetViewActor_x                                   0x545710
#define CDisplay__GetFloorHeight_x                                 0x542B10
#define CDisplay__SetRenderWindow_x                                0x541470
#define CDisplay__ToggleScreenshotMode_x                           0x5451E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9725A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x955EB0
#define CEditWnd__GetCharIndexPt_x                                 0x956DD0
#define CEditWnd__GetDisplayString_x                               0x956C80
#define CEditWnd__GetHorzOffset_x                                  0x955500
#define CEditWnd__GetLineForPrintableChar_x                        0x957F40
#define CEditWnd__GetSelStartPt_x                                  0x957080
#define CEditWnd__GetSTMLSafeText_x                                0x956AA0
#define CEditWnd__PointFromPrintableChar_x                         0x957B80
#define CEditWnd__SelectableCharFromPoint_x                        0x957CF0
#define CEditWnd__SetEditable_x                                    0x957140
#define CEditWnd__SetWindowTextA_x                                 0x956820

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FF8A0
#define CEverQuest__ClickedPlayer_x                                0x5F18B0
#define CEverQuest__CreateTargetIndicator_x                        0x60EE10
#define CEverQuest__DeleteTargetIndicator_x                        0x60EEA0
#define CEverQuest__DoTellWindow_x                                 0x4E8540
#define CEverQuest__OutputTextToLog_x                              0x4E87C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E68F0
#define CEverQuest__dsp_chat_x                                     0x4E8B50
#define CEverQuest__trimName_x                                     0x60B100
#define CEverQuest__Emote_x                                        0x600100
#define CEverQuest__EnterZone_x                                    0x5FA080
#define CEverQuest__GetBodyTypeDesc_x                              0x6049D0
#define CEverQuest__GetClassDesc_x                                 0x605010
#define CEverQuest__GetClassThreeLetterCode_x                      0x605610
#define CEverQuest__GetDeityDesc_x                                 0x60D750
#define CEverQuest__GetLangDesc_x                                  0x6057D0
#define CEverQuest__GetRaceDesc_x                                  0x604FF0
#define CEverQuest__InterpretCmd_x                                 0x60DD20
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EAAF0
#define CEverQuest__LMouseUp_x                                     0x5E8E80
#define CEverQuest__RightClickedOnPlayer_x                         0x5EB3D0
#define CEverQuest__RMouseUp_x                                     0x5E9E00
#define CEverQuest__SetGameState_x                                 0x5E6680
#define CEverQuest__UPCNotificationFlush_x                         0x60B000
#define CEverQuest__IssuePetCommand_x                              0x606BD0
#define CEverQuest__ReportSuccessfulHit_x                          0x601450

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72D2B0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72D310
#define CGaugeWnd__Draw_x                                          0x72C930

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF090
#define CGuild__GetGuildName_x                                     0x4AE170
#define CGuild__GetGuildIndex_x                                    0x4AE500

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7486F0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x620790

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x755710
#define CInvSlotMgr__MoveItem_x                                    0x754430
#define CInvSlotMgr__SelectSlot_x                                  0x7557E0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x752CB0
#define CInvSlot__SliderComplete_x                                 0x750A00
#define CInvSlot__GetItemBase_x                                    0x750380
#define CInvSlot__UpdateItem_x                                     0x7504F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x757260
#define CInvSlotWnd__CInvSlotWnd_x                                 0x756400
#define CInvSlotWnd__HandleLButtonUp_x                             0x756DE0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x810FF0
#define CItemDisplayWnd__UpdateStrings_x                           0x765950
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75F610
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75FB40
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x765F50
#define CItemDisplayWnd__AboutToShow_x                             0x765590
#define CItemDisplayWnd__WndNotification_x                         0x767040
#define CItemDisplayWnd__RequestConvertItem_x                      0x766B00
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7645F0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7653B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x849C70

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76B590

// CLabel 
#define CLabel__Draw_x                                             0x771040

// CListWnd
#define CListWnd__CListWnd_x                                       0x928640
#define CListWnd__dCListWnd_x                                      0x928960
#define CListWnd__AddColumn_x                                      0x92CDC0
#define CListWnd__AddColumn1_x                                     0x92CE10
#define CListWnd__AddLine_x                                        0x92D1A0
#define CListWnd__AddString_x                                      0x92CFA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92CB80
#define CListWnd__CalculateVSBRange_x                              0x92C970
#define CListWnd__ClearSel_x                                       0x92D980
#define CListWnd__ClearAllSel_x                                    0x92D9E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92E400
#define CListWnd__Compare_x                                        0x92C2B0
#define CListWnd__Draw_x                                           0x928A90
#define CListWnd__DrawColumnSeparators_x                           0x92B280
#define CListWnd__DrawHeader_x                                     0x92B6F0
#define CListWnd__DrawItem_x                                       0x92BBF0
#define CListWnd__DrawLine_x                                       0x92B3F0
#define CListWnd__DrawSeparator_x                                  0x92B320
#define CListWnd__EnableLine_x                                     0x92AB50
#define CListWnd__EnsureVisible_x                                  0x92E320
#define CListWnd__ExtendSel_x                                      0x92D8B0
#define CListWnd__GetColumnTooltip_x                               0x92A690
#define CListWnd__GetColumnMinWidth_x                              0x92A700
#define CListWnd__GetColumnWidth_x                                 0x92A600
#define CListWnd__GetCurSel_x                                      0x929F90
#define CListWnd__GetItemAtPoint_x                                 0x92ADD0
#define CListWnd__GetItemAtPoint1_x                                0x92AE40
#define CListWnd__GetItemData_x                                    0x92A010
#define CListWnd__GetItemHeight_x                                  0x92A3D0
#define CListWnd__GetItemIcon_x                                    0x92A1A0
#define CListWnd__GetItemRect_x                                    0x92AC40
#define CListWnd__GetItemText_x                                    0x92A050
#define CListWnd__GetSelList_x                                     0x92DA30
#define CListWnd__GetSeparatorRect_x                               0x92B080
#define CListWnd__InsertLine_x                                     0x92D590
#define CListWnd__RemoveLine_x                                     0x92D6E0
#define CListWnd__SetColors_x                                      0x92C950
#define CListWnd__SetColumnJustification_x                         0x92C680
#define CListWnd__SetColumnWidth_x                                 0x92C5A0
#define CListWnd__SetCurSel_x                                      0x92D7F0
#define CListWnd__SetItemColor_x                                   0x92DFD0
#define CListWnd__SetItemData_x                                    0x92DF90
#define CListWnd__SetItemText_x                                    0x92DBA0
#define CListWnd__ShiftColumnSeparator_x                           0x92C740
#define CListWnd__Sort_x                                           0x92C430
#define CListWnd__ToggleSel_x                                      0x92D820
#define CListWnd__SetColumnsSizable_x                              0x92C7F0
#define CListWnd__SetItemWnd_x                                     0x92DE50
#define CListWnd__GetItemWnd_x                                     0x92A1F0
#define CListWnd__SetItemIcon_x                                    0x92DC20
#define CListWnd__CalculateCustomWindowPositions_x                 0x92CC80
#define CListWnd__SetVScrollPos_x                                  0x92C580

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7867C0
#define CMapViewWnd__GetWorldCoordinates_x                         0x784ED0
#define CMapViewWnd__HandleLButtonDown_x                           0x781F10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A6940
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A7220
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A7750
#define CMerchantWnd__SelectRecoverySlot_x                         0x7AA6D0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A54B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B0290
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A6550

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8ACCD0
#define CPacketScrambler__hton_x                                   0x8ACCC0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9475A0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9479B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9477A0
#define CSidlManager__CreateLabel_x                                0x8083F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x94A910
#define CSidlManager__CreateXWndFromTemplate1_x                    0x94AAF0
#define CSidlManager__CreateXWnd_x                                 0x808320
#define CSidlManager__CreateHotButtonWnd_x                         0x8088E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x944080
#define CSidlScreenWnd__CalculateVSBRange_x                        0x943F80
#define CSidlScreenWnd__ConvertToRes_x                             0x969550
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x943A20
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x943710
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9437E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9438B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x944520
#define CSidlScreenWnd__EnableIniStorage_x                         0x9449F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x944710
#define CSidlScreenWnd__Init1_x                                    0x943310
#define CSidlScreenWnd__LoadIniInfo_x                              0x944A40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x945580
#define CSidlScreenWnd__LoadSidlScreen_x                           0x942710
#define CSidlScreenWnd__StoreIniInfo_x                             0x945100
#define CSidlScreenWnd__StoreIniVis_x                              0x945460
#define CSidlScreenWnd__WndNotification_x                          0x944430
#define CSidlScreenWnd__GetChildItem_x                             0x944970
#define CSidlScreenWnd__HandleLButtonUp_x                          0x934110
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FBFA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x684CB0
#define CSkillMgr__GetSkillCap_x                                   0x684E90
#define CSkillMgr__GetNameToken_x                                  0x684430
#define CSkillMgr__IsActivatedSkill_x                              0x684570
#define CSkillMgr__IsCombatSkill_x                                 0x6844B0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9542E0
#define CSliderWnd__SetValue_x                                     0x954150
#define CSliderWnd__SetNumTicks_x                                  0x9541B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80E440

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95CA80
#define CStmlWnd__CalculateHSBRange_x                              0x95DB60
#define CStmlWnd__CalculateVSBRange_x                              0x95DAD0
#define CStmlWnd__CanBreakAtCharacter_x                            0x961E90
#define CStmlWnd__FastForwardToEndOfTag_x                          0x962B20
#define CStmlWnd__ForceParseNow_x                                  0x95D020
#define CStmlWnd__GetNextTagPiece_x                                0x961DF0
#define CStmlWnd__GetSTMLText_x                                    0x505FC0
#define CStmlWnd__GetVisibleText_x                                 0x95D040
#define CStmlWnd__InitializeWindowVariables_x                      0x962970
#define CStmlWnd__MakeStmlColorTag_x                               0x95C0F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x95C160
#define CStmlWnd__SetSTMLText_x                                    0x95B1A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x963C20
#define CStmlWnd__UpdateHistoryString_x                            0x962D30

// CTabWnd 
#define CTabWnd__Draw_x                                            0x95A2F0
#define CTabWnd__DrawCurrentPage_x                                 0x95AA20
#define CTabWnd__DrawTab_x                                         0x95A740
#define CTabWnd__GetCurrentPage_x                                  0x959B00
#define CTabWnd__GetPageInnerRect_x                                0x959D40
#define CTabWnd__GetTabInnerRect_x                                 0x959C80
#define CTabWnd__GetTabRect_x                                      0x959B30
#define CTabWnd__InsertPage_x                                      0x959F50
#define CTabWnd__SetPage_x                                         0x959DC0
#define CTabWnd__SetPageRect_x                                     0x95A230
#define CTabWnd__UpdatePage_x                                      0x95A600
#define CTabWnd__GetPageFromTabIndex_x                             0x95A680
#define CTabWnd__GetCurrentTabIndex_x                              0x959AF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76B9D0
#define CPageWnd__SetTabText_x                                     0x959650

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8DB0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x931020
#define CTextureFont__GetTextExtent_x                              0x9311E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B8050
#define CHtmlComponentWnd__ValidateUri_x                           0x74A0E0
#define CHtmlWnd__SetClientCallbacks_x                             0x625820
#define CHtmlWnd__AddObserver_x                                    0x625840
#define CHtmlWnd__RemoveObserver_x                                 0x6258A0
#define Window__getProgress_x                                      0x8623D0
#define Window__getStatus_x                                        0x8623F0
#define Window__getURI_x                                           0x862400

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96EFF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91E290

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8190
#define CXStr__CXStr1_x                                            0x500FE0
#define CXStr__CXStr3_x                                            0x8FFD60
#define CXStr__dCXStr_x                                            0x478680
#define CXStr__operator_equal_x                                    0x8FFF90
#define CXStr__operator_equal1_x                                   0x8FFFD0
#define CXStr__operator_plus_equal1_x                              0x900A60
#define CXStr__SetString_x                                         0x902950
#define CXStr__operator_char_p_x                                   0x9004A0
#define CXStr__GetChar_x                                           0x9022A0
#define CXStr__Delete_x                                            0x901B50
#define CXStr__GetUnicode_x                                        0x902310
#define CXStr__GetLength_x                                         0x4A8B60
#define CXStr__Mid_x                                               0x47D320
#define CXStr__Insert_x                                            0x902370
#define CXStr__FindNext_x                                          0x901FC0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x952590
#define CXWnd__BringToTop_x                                        0x937820
#define CXWnd__Center_x                                            0x9373A0
#define CXWnd__ClrFocus_x                                          0x9371C0
#define CXWnd__Destroy_x                                           0x937260
#define CXWnd__DoAllDrawing_x                                      0x9338D0
#define CXWnd__DrawChildren_x                                      0x9338A0
#define CXWnd__DrawColoredRect_x                                   0x933D10
#define CXWnd__DrawTooltip_x                                       0x932410
#define CXWnd__DrawTooltipAtPoint_x                                0x9324D0
#define CXWnd__GetBorderFrame_x                                    0x933B70
#define CXWnd__GetChildWndAt_x                                     0x9378C0
#define CXWnd__GetClientClipRect_x                                 0x935B00
#define CXWnd__GetScreenClipRect_x                                 0x935BD0
#define CXWnd__GetScreenRect_x                                     0x935D90
#define CXWnd__GetTooltipRect_x                                    0x933D60
#define CXWnd__GetWindowTextA_x                                    0x49CAE0
#define CXWnd__IsActive_x                                          0x934480
#define CXWnd__IsDescendantOf_x                                    0x936780
#define CXWnd__IsReallyVisible_x                                   0x9367B0
#define CXWnd__IsType_x                                            0x937F40
#define CXWnd__Move_x                                              0x936810
#define CXWnd__Move1_x                                             0x9368C0
#define CXWnd__ProcessTransition_x                                 0x937350
#define CXWnd__Refade_x                                            0x936B80
#define CXWnd__Resize_x                                            0x936DE0
#define CXWnd__Right_x                                             0x9375E0
#define CXWnd__SetFocus_x                                          0x937180
#define CXWnd__SetFont_x                                           0x9371F0
#define CXWnd__SetKeyTooltip_x                                     0x937D50
#define CXWnd__SetMouseOver_x                                      0x934CA0
#define CXWnd__StartFade_x                                         0x936660
#define CXWnd__GetChildItem_x                                      0x937A30
#define CXWnd__SetParent_x                                         0x936520
#define CXWnd__Minimize_x                                          0x936E50

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96A5D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x93A730
#define CXWndManager__DrawWindows_x                                0x93A750
#define CXWndManager__GetKeyboardFlags_x                           0x93CF00
#define CXWndManager__HandleKeyboardMsg_x                          0x93CAC0
#define CXWndManager__RemoveWnd_x                                  0x93D130
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93D6B0

// CDBStr
#define CDBStr__GetString_x                                        0x53D440

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB770
#define EQ_Character__Cur_HP_x                                     0x4D1D10
#define EQ_Character__Cur_Mana_x                                   0x4D9460
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE7E0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B21F0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2340
#define EQ_Character__GetHPRegen_x                                 0x4DF230
#define EQ_Character__GetEnduranceRegen_x                          0x4DF830
#define EQ_Character__GetManaRegen_x                               0x4DFC70
#define EQ_Character__Max_Endurance_x                              0x64B770
#define EQ_Character__Max_HP_x                                     0x4D1B40
#define EQ_Character__Max_Mana_x                                   0x64B570
#define EQ_Character__doCombatAbility_x                            0x64DBC0
#define EQ_Character__UseSkill_x                                   0x4E1A40
#define EQ_Character__GetConLevel_x                                0x6447E0
#define EQ_Character__IsExpansionFlag_x                            0x5A81F0
#define EQ_Character__TotalEffect_x                                0x4C5230
#define EQ_Character__GetPCSpellAffect_x                           0x4BF530
#define EQ_Character__SpellDuration_x                              0x4BF060
#define EQ_Character__GetAdjustedSkill_x                           0x4D4A90
#define EQ_Character__GetBaseSkill_x                               0x4D5A30
#define EQ_Character__CanUseItem_x                                 0x4D9770

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CBF40

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x661D10

//PcClient
#define PcClient__PcClient_x                                       0x641F10

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B93C0
#define CCharacterListWnd__EnterWorld_x                            0x4B8E00
#define CCharacterListWnd__Quit_x                                  0x4B8B50
#define CCharacterListWnd__UpdateList_x                            0x4B8F90

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x626A50
#define EQ_Item__CreateItemTagString_x                             0x8A6500
#define EQ_Item__IsStackable_x                                     0x8AB080
#define EQ_Item__GetImageNum_x                                     0x8A7F70
#define EQ_Item__CreateItemClient_x                                0x625C20
#define EQ_Item__GetItemValue_x                                    0x8A9250
#define EQ_Item__ValueSellMerchant_x                               0x8AC8A0
#define EQ_Item__IsKeyRingItem_x                                   0x8AA980
#define EQ_Item__CanGoInBag_x                                      0x626B70
#define EQ_Item__IsEmpty_x                                         0x8AA4D0
#define EQ_Item__GetMaxItemCount_x                                 0x8A9670
#define EQ_Item__GetHeldItem_x                                     0x8A7E40
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A5E60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55B9F0
#define EQ_LoadingS__Array_x                                       0xC2AB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64C0D0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B5AD0
#define EQ_PC__GetCombatAbility_x                                  0x8B6140
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B61B0
#define EQ_PC__GetItemRecastTimer_x                                0x64E140
#define EQ_PC__HasLoreItem_x                                       0x644FA0
#define EQ_PC__AlertInventoryChanged_x                             0x644110
#define EQ_PC__GetPcZoneClient_x                                   0x6707A0
#define EQ_PC__RemoveMyAffect_x                                    0x651380
#define EQ_PC__GetKeyRingItems_x                                   0x8B6A40
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B67D0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B6D40

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AE750
#define EQItemList__add_object_x                                   0x5DC0A0
#define EQItemList__add_item_x                                     0x5AECB0
#define EQItemList__delete_item_x                                  0x5AED00
#define EQItemList__FreeItemList_x                                 0x5AEC00

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x539F20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x663590
#define EQPlayer__dEQPlayer_x                                      0x6568E0
#define EQPlayer__DoAttack_x                                       0x66B440
#define EQPlayer__EQPlayer_x                                       0x656FA0
#define EQPlayer__SetNameSpriteState_x                             0x65B270
#define EQPlayer__SetNameSpriteTint_x                              0x65C140
#define PlayerBase__HasProperty_j_x                                0x99CC80
#define EQPlayer__IsTargetable_x                                   0x99D120
#define EQPlayer__CanSee_x                                         0x99CF80
#define EQPlayer__CanSee1_x                                        0x99D050
#define PlayerBase__GetVisibilityLineSegment_x                     0x99CD40

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66E240
#define PlayerZoneClient__GetLevel_x                               0x6707E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DD210
#define PlayerZoneClient__LegalPlayerRace_x                        0x554C90

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6662E0
#define EQPlayerManager__GetSpawnByName_x                          0x666390
#define EQPlayerManager__GetPlayerFromPartialName_x                0x666420

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62A150
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62A1D0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62A210
#define KeypressHandler__ClearCommandStateArray_x                  0x62B620
#define KeypressHandler__HandleKeyDown_x                           0x62B640
#define KeypressHandler__HandleKeyUp_x                             0x62B6E0
#define KeypressHandler__SaveKeymapping_x                          0x62BB30

// MapViewMap 
#define MapViewMap__Clear_x                                        0x782630
#define MapViewMap__SaveEx_x                                       0x7859F0
#define MapViewMap__SetZoom_x                                      0x78A0B0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C9E60

// StringTable 
#define StringTable__getString_x                                   0x8C4D70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x650FF0
#define PcZoneClient__RemovePetEffect_x                            0x651620
#define PcZoneClient__HasAlternateAbility_x                        0x64B3A0
#define PcZoneClient__GetCurrentMod_x                              0x4E4B00
#define PcZoneClient__GetModCap_x                                  0x4E4A00
#define PcZoneClient__CanEquipItem_x                               0x64BA70
#define PcZoneClient__GetItemByID_x                                0x64E5C0
#define PcZoneClient__GetItemByItemClass_x                         0x64E710
#define PcZoneClient__RemoveBuffEffect_x                           0x651640
#define PcZoneClient__BandolierSwap_x                              0x64C680
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64E0E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E1D30

//IconCache
#define IconCache__GetIcon_x                                       0x7229B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71A4B0
#define CContainerMgr__CloseContainer_x                            0x71A780
#define CContainerMgr__OpenExperimentContainer_x                   0x71B200

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DA8A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61EBA0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x778B10
#define CLootWnd__RequestLootSlot_x                                0x777D40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57BDC0
#define EQ_Spell__SpellAffects_x                                   0x57C230
#define EQ_Spell__SpellAffectBase_x                                0x57BFF0
#define EQ_Spell__IsStackable_x                                    0x4C9760
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9640
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B66E0
#define EQ_Spell__IsSPAStacking_x                                  0x57D080
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57C590
#define EQ_Spell__IsNoRemove_x                                     0x4C9740
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57D090
#define __IsResEffectSpell_x                                       0x4C8C70

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACDE0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D44F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x821770
#define CTargetWnd__WndNotification_x                              0x821000
#define CTargetWnd__RefreshTargetBuffs_x                           0x8212D0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x820180

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x825D70

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x537970
#define CTaskManager__HandleMessage_x                              0x535E00
#define CTaskManager__GetTaskStatus_x                              0x537A20
#define CTaskManager__GetElementDescription_x                      0x537AA0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x577290
#define EqSoundManager__PlayScriptMp3_x                            0x5773F0
#define EqSoundManager__SoundAssistPlay_x                          0x688C90
#define EqSoundManager__WaveInstancePlay_x                         0x688200

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52B780

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x958B60

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5633E0
#define CAltAbilityData__GetMercMaxRank_x                          0x563370
#define CAltAbilityData__GetMaxRank_x                              0x558A60

//CTargetRing
#define CTargetRing__Cast_x                                        0x61CCC0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9620
#define CharacterBase__CreateItemGlobalIndex_x                     0x512DC0
#define CharacterBase__CreateItemIndex_x                           0x624DD0
#define CharacterBase__GetItemPossession_x                         0x4FE8D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DCAE0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DCB40
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x701690
#define CCastSpellWnd__IsBardSongPlaying_x                         0x701EC0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x701F70

//messages
#define msg_spell_worn_off_x                                       0x5A04B0
#define msg_new_text_x                                             0x595250
#define __msgTokenTextParam_x                                      0x5A29E0
#define msgTokenText_x                                             0x5A2C30

//SpellManager
#define SpellManager__vftable_x                                    0xAEF684
#define SpellManager__SpellManager_x                               0x68BFC0
#define Spellmanager__LoadTextSpells_x                             0x68C8B0
#define SpellManager__GetSpellByGroupAndRank_x                     0x68C190

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A0B40

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x513410
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A67B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63D6E0
#define ItemGlobalIndex__IsValidIndex_x                            0x513470

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D4E90
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D5110

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x771380

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71EBB0
#define CCursorAttachment__AttachToCursor1_x                       0x71EBF0
#define CCursorAttachment__Deactivate_x                            0x71FBD0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94B930
#define CSidlManagerBase__CreatePageWnd_x                          0x94B130
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9473C0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x947350

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9689E0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9686A0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x510330
#define CFindItemWnd__WndNotification_x                            0x510E10
#define CFindItemWnd__Update_x                                     0x511980
#define CFindItemWnd__PickupSelectedItem_x                         0x50FB70

//IString
#define IString__Append_x                                          0x4F1210

//Camera
#define CDisplay__cameraType_x                                     0xE045A4
#define EverQuest__Cameras_x                                       0xEC7ACC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x518BB0
#define LootFiltersManager__GetItemFilterData_x                    0x5184B0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5184E0
#define LootFiltersManager__SetItemLootFilter_x                    0x518700

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C87D0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A6870
#define CResolutionHandler__GetWindowedStyle_x                     0x6837E0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x717290

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8EA230
#define CDistillerInfo__Instance_x                                 0x8EA1D0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7374C0
#define CGroupWnd__UpdateDisplay_x                                 0x736830

//ItemBase
#define ItemBase__IsLore_x                                         0x8AAA30
#define ItemBase__IsLoreEquipped_x                                 0x8AAAB0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DC000
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DC140
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DC1A0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678F30
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67C890

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x506650

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F3090
#define FactionManagerClient__HandleFactionMessage_x               0x4F3700
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3D00
#define FactionManagerClient__GetMaxFaction_x                      0x4F3D1F
#define FactionManagerClient__GetMinFaction_x                      0x4F3CD0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FE8A0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x930070

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BDC0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FEB50

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562890

//CTargetManager
#define CTargetManager__Get_x                                      0x68F830

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678F30

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8B70

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AEBA0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF65160

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
