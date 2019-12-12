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
#define __ExpectedVersionDate                                     "Dec 12 2019"
#define __ExpectedVersionTime                                     "04:23:29"
#define __ActualVersionDate_x                                      0xB0C6BC
#define __ActualVersionTime_x                                      0xB0C6B0
#define __ActualVersionBuild_x                                     0xAF8334

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6303F0
#define __MemChecker1_x                                            0x903380
#define __MemChecker2_x                                            0x6BF0D0
#define __MemChecker3_x                                            0x6BF020
#define __MemChecker4_x                                            0x859E00
#define __EncryptPad0_x                                            0xC423E8
#define __EncryptPad1_x                                            0xCA05E8
#define __EncryptPad2_x                                            0xC52C80
#define __EncryptPad3_x                                            0xC52880
#define __EncryptPad4_x                                            0xC90C00
#define __EncryptPad5_x                                            0xF6C210
#define __AC1_x                                                    0x8169A6
#define __AC2_x                                                    0x5EA0FF
#define __AC3_x                                                    0x5F17FF
#define __AC4_x                                                    0x5F57D0
#define __AC5_x                                                    0x5FBADF
#define __AC6_x                                                    0x6000F6
#define __AC7_x                                                    0x5E9B70
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x197E2C

// Direct Input
#define DI8__Main_x                                                0xF6C238
#define DI8__Keyboard_x                                            0xF6C23C
#define DI8__Mouse_x                                               0xF6C21C
#define DI8__Mouse_Copy_x                                          0xEC541C
#define DI8__Mouse_Check_x                                         0xF69D64
#define __AutoSkillArray_x                                         0xEC6334
#define __Attack_x                                                 0xF6415B
#define __Autofire_x                                               0xF6415C
#define __BindList_x                                               0xC30E20
#define g_eqCommandStates_x                                        0xC31BA0
#define __Clicks_x                                                 0xEC54D4
#define __CommandList_x                                            0xC32760
#define __CurrentMapLabel_x                                        0xF7CBDC
#define __CurrentSocial_x                                          0xC1A7CC
#define __DoAbilityList_x                                          0xEFBC7C
#define __do_loot_x                                                0x5B5B80
#define __DrawHandler_x                                            0x15FBF50
#define __GroupCount_x                                             0xEB7DD2
#define __Guilds_x                                                 0xEBBC28
#define __gWorld_x                                                 0xEB7C88
#define __HWnd_x                                                   0xF6C220
#define __heqmain_x                                                0xF6C1F8
#define __InChatMode_x                                             0xEC5404
#define __LastTell_x                                               0xEC7378
#define __LMouseHeldTime_x                                         0xEC5540
#define __Mouse_x                                                  0xF6C224
#define __MouseLook_x                                              0xEC549A
#define __MouseEventTime_x                                         0xF64C3C
#define __gpbCommandEvent_x                                        0xEB56C0
#define __NetStatusToggle_x                                        0xEC549D
#define __PCNames_x                                                0xEC6924
#define __RangeAttackReady_x                                       0xEC6618
#define __RMouseHeldTime_x                                         0xEC553C
#define __RunWalkState_x                                           0xEC5408
#define __ScreenMode_x                                             0xE030A0
#define __ScreenX_x                                                0xEC53BC
#define __ScreenY_x                                                0xEC53B8
#define __ScreenXMax_x                                             0xEC53C0
#define __ScreenYMax_x                                             0xEC53C4
#define __ServerHost_x                                             0xEB58F3
#define __ServerName_x                                             0xEFBC3C
#define __ShiftKeyDown_x                                           0xEC5A94
#define __ShowNames_x                                              0xEC67D4
#define __Socials_x                                                0xEFBD3C
#define __SubscriptionType_x                                       0xFC10E0
#define __TargetAggroHolder_x                                      0xF7F590
#define __ZoneType_x                                               0xEC5898
#define __GroupAggro_x                                             0xF7F5D0
#define __LoginName_x                                              0xF6C98C
#define __Inviter_x                                                0xF640D8
#define __AttackOnAssist_x                                         0xEC6790
#define __UseTellWindows_x                                         0xEC6AC0
#define __gfMaxZoomCameraDistance_x                                0xB01FC8
#define __gfMaxCameraDistance_x                                    0xB2E374
#define __pulAutoRun_x                                             0xEC54B8
#define __pulForward_x                                             0xEC6AF8
#define __pulBackward_x                                            0xEC6AFC
#define __pulTurnRight_x                                           0xEC6B00
#define __pulTurnLeft_x                                            0xEC6B04
#define __pulStrafeLeft_x                                          0xEC6B08
#define __pulStrafeRight_x                                         0xEC6B0C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB7FC8
#define instEQZoneInfo_x                                           0xEC5690
#define pinstActiveBanker_x                                        0xEB56D8
#define pinstActiveCorpse_x                                        0xEB56D0
#define pinstActiveGMaster_x                                       0xEB56D4
#define pinstActiveMerchant_x                                      0xEB56CC
#define pinstAltAdvManager_x                                       0xE04200
#define pinstBandageTarget_x                                       0xEB56E8
#define pinstCamActor_x                                            0xE03094
#define pinstCDBStr_x                                              0xE02F1C
#define pinstCDisplay_x                                            0xEB7C84
#define pinstCEverQuest_x                                          0xF6C250
#define pinstEverQuestInfo_x                                       0xEC53B0
#define pinstCharData_x                                            0xEB7DB4
#define pinstCharSpawn_x                                           0xEB5720
#define pinstControlledMissile_x                                   0xEB5C0C
#define pinstControlledPlayer_x                                    0xEB5720
#define pinstCResolutionHandler_x                                  0x15FC180
#define pinstCSidlManager_x                                        0x15FB118
#define pinstCXWndManager_x                                        0x15FB114
#define instDynamicZone_x                                          0xEBBB00
#define pinstDZMember_x                                            0xEBBC10
#define pinstDZTimerInfo_x                                         0xEBBC14
#define pinstEqLogin_x                                             0xF6C2D8
#define instEQMisc_x                                               0xE02E60
#define pinstEQSoundManager_x                                      0xE051D0
#define pinstEQSpellStrings_x                                      0xCC5878
#define instExpeditionLeader_x                                     0xEBBB4A
#define instExpeditionName_x                                       0xEBBB8A
#define pinstGroup_x                                               0xEB7DCE
#define pinstImeManager_x                                          0x15FB110
#define pinstLocalPlayer_x                                         0xEB56C8
#define pinstMercenaryData_x                                       0xF6672C
#define pinstMercenaryStats_x                                      0xF7F6DC
#define pinstModelPlayer_x                                         0xEB56E0
#define pinstPCData_x                                              0xEB7DB4
#define pinstSkillMgr_x                                            0xF68898
#define pinstSpawnManager_x                                        0xF67340
#define pinstSpellManager_x                                        0xF68AB8
#define pinstSpellSets_x                                           0xF5CD84
#define pinstStringTable_x                                         0xEB7DB8
#define pinstSwitchManager_x                                       0xEB5568
#define pinstTarget_x                                              0xEB571C
#define pinstTargetObject_x                                        0xEB57A8
#define pinstTargetSwitch_x                                        0xEB7C28
#define pinstTaskMember_x                                          0xE02CF0
#define pinstTrackTarget_x                                         0xEB5724
#define pinstTradeTarget_x                                         0xEB56DC
#define instTributeActive_x                                        0xE02E81
#define pinstViewActor_x                                           0xE03090
#define pinstWorldData_x                                           0xEB5C08
#define pinstZoneAddr_x                                            0xEC5930
#define pinstPlayerPath_x                                          0xF673D8
#define pinstTargetIndicator_x                                     0xF68D20
#define EQObject_Top_x                                             0xEB56C4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE037E0
#define pinstCAchievementsWnd_x                                    0xE037DC
#define pinstCActionsWnd_x                                         0xE035A0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE03018
#define pinstCAdvancedLootWnd_x                                    0xE02FD4
#define pinstCAdventureLeaderboardWnd_x                            0xF763B0
#define pinstCAdventureRequestWnd_x                                0xF76460
#define pinstCAdventureStatsWnd_x                                  0xF76510
#define pinstCAggroMeterWnd_x                                      0xE03538
#define pinstCAlarmWnd_x                                           0xE03840
#define pinstCAlertHistoryWnd_x                                    0xE03038
#define pinstCAlertStackWnd_x                                      0xE03848
#define pinstCAlertWnd_x                                           0xE02FBC
#define pinstCAltStorageWnd_x                                      0xF76870
#define pinstCAudioTriggersWindow_x                                0xCB7BA8
#define pinstCAuraWnd_x                                            0xE0305C
#define pinstCAvaZoneWnd_x                                         0xE02FF0
#define pinstCBandolierWnd_x                                       0xE030CC
#define pinstCBankWnd_x                                            0xE03058
#define pinstCBarterMerchantWnd_x                                  0xF77AB0
#define pinstCBarterSearchWnd_x                                    0xF77B60
#define pinstCBarterWnd_x                                          0xF77C10
#define pinstCBazaarConfirmationWnd_x                              0xE0380C
#define pinstCBazaarSearchWnd_x                                    0xE03580
#define pinstCBazaarWnd_x                                          0xE03824
#define pinstCBlockedBuffWnd_x                                     0xE03060
#define pinstCBlockedPetBuffWnd_x                                  0xE030B8
#define pinstCBodyTintWnd_x                                        0xE037B8
#define pinstCBookWnd_x                                            0xE0355C
#define pinstCBreathWnd_x                                          0xE037F4
#define pinstCBuffWindowNORMAL_x                                   0xE0303C
#define pinstCBuffWindowSHORT_x                                    0xE03040
#define pinstCBugReportWnd_x                                       0xE0304C
#define pinstCButtonWnd_x                                          0x15FB380
#define pinstCCastingWnd_x                                         0xE03550
#define pinstCCastSpellWnd_x                                       0xE037EC
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE0383C
#define pinstCChatWindowManager_x                                  0xF786D0
#define pinstCClaimWnd_x                                           0xF78828
#define pinstCColorPickerWnd_x                                     0xE035AC
#define pinstCCombatAbilityWnd_x                                   0xE03834
#define pinstCCombatSkillsSelectWnd_x                              0xE02FC0
#define pinstCCompassWnd_x                                         0xE035A8
#define pinstCConfirmationDialog_x                                 0xF7D728
#define pinstCContainerMgr_x                                       0xE03830
#define pinstCContextMenuManager_x                                 0x15FB0D0
#define pinstCCursorAttachment_x                                   0xE03544
#define pinstCDynamicZoneWnd_x                                     0xF78DF0
#define pinstCEditLabelWnd_x                                       0xE03034
#define pinstCEQMainWnd_x                                          0xF79038
#define pinstCEventCalendarWnd_x                                   0xE03548
#define pinstCExtendedTargetWnd_x                                  0xE030AC
#define pinstCFacePick_x                                           0xE02FD8
#define pinstCFactionWnd_x                                         0xE0381C
#define pinstCFellowshipWnd_x                                      0xF79238
#define pinstCFileSelectionWnd_x                                   0xE0354C
#define pinstCFindItemWnd_x                                        0xE03808
#define pinstCFindLocationWnd_x                                    0xF79390
#define pinstCFriendsWnd_x                                         0xE02FD0
#define pinstCGemsGameWnd_x                                        0xE03818
#define pinstCGiveWnd_x                                            0xE03844
#define pinstCGroupSearchFiltersWnd_x                              0xE03554
#define pinstCGroupSearchWnd_x                                     0xF79788
#define pinstCGroupWnd_x                                           0xF79838
#define pinstCGuildBankWnd_x                                       0xEC6774
#define pinstCGuildCreationWnd_x                                   0xF79998
#define pinstCGuildMgmtWnd_x                                       0xF79A48
#define pinstCharacterCreation_x                                   0xE02FC8
#define pinstCHelpWnd_x                                            0xE0300C
#define pinstCHeritageSelectionWnd_x                               0xE02FE8
#define pinstCHotButtonWnd_x                                       0xF7BBA0
#define pinstCHotButtonWnd1_x                                      0xF7BBA0
#define pinstCHotButtonWnd2_x                                      0xF7BBA4
#define pinstCHotButtonWnd3_x                                      0xF7BBA8
#define pinstCHotButtonWnd4_x                                      0xF7BBAC
#define pinstCIconSelectionWnd_x                                   0xE03540
#define pinstCInspectWnd_x                                         0xE03008
#define pinstCInventoryWnd_x                                       0xE02FDC
#define pinstCInvSlotMgr_x                                         0xE037F0
#define pinstCItemDisplayManager_x                                 0xF7C130
#define pinstCItemExpTransferWnd_x                                 0xF7C260
#define pinstCItemOverflowWnd_x                                    0xE03584
#define pinstCJournalCatWnd_x                                      0xE03560
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE030B0
#define pinstCKeyRingWnd_x                                         0xE03028
#define pinstCLargeDialogWnd_x                                     0xF7E3A8
#define pinstCLayoutCopyWnd_x                                      0xF7C5B0
#define pinstCLFGuildWnd_x                                         0xF7C660
#define pinstCLoadskinWnd_x                                        0xE03820
#define pinstCLootFiltersCopyWnd_x                                 0xCD41F8
#define pinstCLootFiltersWnd_x                                     0xE0384C
#define pinstCLootSettingsWnd_x                                    0xE02FCC
#define pinstCLootWnd_x                                            0xE03564
#define pinstCMailAddressBookWnd_x                                 0xE037F8
#define pinstCMailCompositionWnd_x                                 0xE037D4
#define pinstCMailIgnoreListWnd_x                                  0xE037FC
#define pinstCMailWnd_x                                            0xE037B0
#define pinstCManageLootWnd_x                                      0xE046B0
#define pinstCMapToolbarWnd_x                                      0xE03014
#define pinstCMapViewWnd_x                                         0xE02FEC
#define pinstCMarketplaceWnd_x                                     0xE03850
#define pinstCMerchantWnd_x                                        0xE03568
#define pinstCMIZoneSelectWnd_x                                    0xF7CE98
#define pinstCMusicPlayerWnd_x                                     0xE03570
#define pinstCNameChangeMercWnd_x                                  0xE03804
#define pinstCNameChangePetWnd_x                                   0xE037E4
#define pinstCNameChangeWnd_x                                      0xE03814
#define pinstCNoteWnd_x                                            0xE02FF4
#define pinstCObjectPreviewWnd_x                                   0xE02FC4
#define pinstCOptionsWnd_x                                         0xE02FF8
#define pinstCPetInfoWnd_x                                         0xE03588
#define pinstCPetitionQWnd_x                                       0xE037CC
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE037BC
#define pinstCPlayerWnd_x                                          0xE03594
#define pinstCPopupWndManager_x                                    0xF7D728
#define pinstCProgressionSelectionWnd_x                            0xF7D7D8
#define pinstCPurchaseGroupWnd_x                                   0xE03000
#define pinstCPurchaseWnd_x                                        0xE02FE0
#define pinstCPvPLeaderboardWnd_x                                  0xF7D888
#define pinstCPvPStatsWnd_x                                        0xF7D938
#define pinstCQuantityWnd_x                                        0xE030B4
#define pinstCRaceChangeWnd_x                                      0xE03838
#define pinstCRaidOptionsWnd_x                                     0xE03558
#define pinstCRaidWnd_x                                            0xE037C8
#define pinstCRealEstateItemsWnd_x                                 0xE037D8
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE0356C
#define pinstCRealEstateManageWnd_x                                0xE03010
#define pinstCRealEstateNeighborhoodWnd_x                          0xE0302C
#define pinstCRealEstatePlotSearchWnd_x                            0xE03050
#define pinstCRealEstatePurchaseWnd_x                              0xE0308C
#define pinstCRespawnWnd_x                                         0xE03088
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE037E8
#define pinstCSendMoneyWnd_x                                       0xE02FB8
#define pinstCServerListWnd_x                                      0xE03134
#define pinstCSkillsSelectWnd_x                                    0xE03828
#define pinstCSkillsWnd_x                                          0xE03810
#define pinstCSocialEditWnd_x                                      0xE03020
#define pinstCSocialWnd_x                                          0xE03800
#define pinstCSpellBookWnd_x                                       0xE0382C
#define pinstCStoryWnd_x                                           0xE03590
#define pinstCTargetOfTargetWnd_x                                  0xF7F760
#define pinstCTargetWnd_x                                          0xE03084
#define pinstCTaskOverlayWnd_x                                     0xE02FFC
#define pinstCTaskSelectWnd_x                                      0xF7F8B8
#define pinstCTaskManager_x                                        0xCD4B38
#define pinstCTaskTemplateSelectWnd_x                              0xF7F968
#define pinstCTaskWnd_x                                            0xF7FA18
#define pinstCTextEntryWnd_x                                       0xE03044
#define pinstCTimeLeftWnd_x                                        0xE03598
#define pinstCTipWndCONTEXT_x                                      0xF7FC1C
#define pinstCTipWndOFDAY_x                                        0xF7FC18
#define pinstCTitleWnd_x                                           0xF7FCC8
#define pinstCTrackingWnd_x                                        0xE02FE4
#define pinstCTradeskillWnd_x                                      0xF7FE30
#define pinstCTradeWnd_x                                           0xE037C4
#define pinstCTrainWnd_x                                           0xE037C0
#define pinstCTributeBenefitWnd_x                                  0xF80030
#define pinstCTributeMasterWnd_x                                   0xF800E0
#define pinstCTributeTrophyWnd_x                                   0xF80190
#define pinstCVideoModesWnd_x                                      0xE0359C
#define pinstCVoiceMacroWnd_x                                      0xF69488
#define pinstCVoteResultsWnd_x                                     0xE037D0
#define pinstCVoteWnd_x                                            0xE037B4
#define pinstCWebManager_x                                         0xF69B04
#define pinstCZoneGuideWnd_x                                       0xE03004
#define pinstCZonePathWnd_x                                        0xE0301C

#define pinstEQSuiteTextureLoader_x                                0xCA20C0
#define pinstItemIconCache_x                                       0xF78FF0
#define pinstLootFiltersManager_x                                  0xCD42A8
#define pinstRewardSelectionWnd_x                                  0xF7E080

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B0FE0
#define __CastRay2_x                                               0x5B1030
#define __ConvertItemTags_x                                        0x5CCB90
#define __CleanItemTags_x                                          0x47D0E0
#define __DoesFileExist_x                                          0x906460
#define __EQGetTime_x                                              0x902E50
#define __ExecuteCmd_x                                             0x5A9840
#define __FixHeading_x                                             0x99EB90
#define __GameLoop_x                                               0x6BE2C0
#define __get_bearing_x                                            0x5B0B50
#define __get_melee_range_x                                        0x5B1220
#define __GetAnimationCache_x                                      0x7236D0
#define __GetGaugeValueFromEQ_x                                    0x814E50
#define __GetLabelFromEQ_x                                         0x816930
#define __GetXTargetType_x                                         0x9A0570
#define __HandleMouseWheel_x                                       0x6BF180
#define __HeadingDiff_x                                            0x99EC00
#define __HelpPath_x                                               0xF6482C
#define __LoadFrontEnd_x                                           0x6BB5E0
#define __NewUIINI_x                                               0x814B20
#define __ProcessGameEvents_x                                      0x6118B0
#define __ProcessMouseEvent_x                                      0x611070
#define __SaveColors_x                                             0x5534B0
#define __STMLToText_x                                             0x941ED0
#define __ToggleKeyRingItem_x                                      0x5167E0
#define CMemoryMappedFile__SetFile_x                               0xA8DD70
#define CrashDetected_x                                            0x6BD080
#define DrawNetStatus_x                                            0x63D8F0
#define Expansion_HoT_x                                            0xEC677C
#define Teleport_Table_Size_x                                      0xEB57B0
#define Teleport_Table_x                                           0xEB5C28
#define Util__FastTime_x                                           0x902A20

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
#define AltAdvManager__GetCalculatedTimer_x                        0x55AFE0
#define AltAdvManager__IsAbilityReady_x                            0x559F10
#define AltAdvManager__GetAAById_x                                 0x55A110
#define AltAdvManager__CanTrainAbility_x                           0x55A180
#define AltAdvManager__CanSeeAbility_x                             0x55A4E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA0D0
#define CharacterZoneClient__HasSkill_x                            0x4D4FC0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D66E0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE360
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA960
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9080
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9160
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9240
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3160
#define CharacterZoneClient__BardCastBard_x                        0x4C5CC0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA30
#define CharacterZoneClient__GetEffect_x                           0x4BA8A0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C41B0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4280
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C42D0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4420
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C45F0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2810
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7640
#define CharacterZoneClient__FindItemByRecord_x                    0x4D70C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E4E50
#define CBankWnd__WndNotification_x                                0x6E4C30

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F2550

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x620100
#define CButtonWnd__CButtonWnd_x                                   0x93E2A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x712870
#define CChatManager__InitContextMenu_x                            0x70B9C0
#define CChatManager__FreeChatWindow_x                             0x7113B0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8680
#define CChatManager__SetLockedActiveChatWindow_x                  0x7124F0
#define CChatManager__CreateChatWindow_x                           0x7119F0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8790

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x952900
#define CContextMenu__dCContextMenu_x                              0x952B40
#define CContextMenu__AddMenuItem_x                                0x952B50
#define CContextMenu__RemoveMenuItem_x                             0x952E60
#define CContextMenu__RemoveAllMenuItems_x                         0x952E80
#define CContextMenu__CheckMenuItem_x                              0x952F00
#define CContextMenu__SetMenuItem_x                                0x952D80
#define CContextMenu__AddSeparator_x                               0x952CE0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9534A0
#define CContextMenuManager__RemoveMenu_x                          0x953510
#define CContextMenuManager__PopupMenu_x                           0x9535D0
#define CContextMenuManager__Flush_x                               0x953440
#define CContextMenuManager__GetMenu_x                             0x49B320
#define CContextMenuManager__CreateDefaultMenu_x                   0x71DEE0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DE500
#define CChatService__GetFriendName_x                              0x8DE510

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7130E0
#define CChatWindow__Clear_x                                       0x7143A0
#define CChatWindow__WndNotification_x                             0x714B30
#define CChatWindow__AddHistory_x                                  0x713C60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94FD60
#define CComboWnd__Draw_x                                          0x94F240
#define CComboWnd__GetCurChoice_x                                  0x94FBA0
#define CComboWnd__GetListRect_x                                   0x94F700
#define CComboWnd__GetTextRect_x                                   0x94FDD0
#define CComboWnd__InsertChoice_x                                  0x94F890
#define CComboWnd__SetColors_x                                     0x94F860
#define CComboWnd__SetChoice_x                                     0x94FB70
#define CComboWnd__GetItemCount_x                                  0x94FBB0
#define CComboWnd__GetCurChoiceText_x                              0x94FBF0
#define CComboWnd__GetChoiceText_x                                 0x94FBC0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94F930

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71B8D0
#define CContainerWnd__vftable_x                                   0xB158B4
#define CContainerWnd__SetContainer_x                              0x71CE30

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54DEE0
#define CDisplay__PreZoneMainUI_x                                  0x54DEF0
#define CDisplay__CleanGameUI_x                                    0x553270
#define CDisplay__GetClickedActor_x                                0x546200
#define CDisplay__GetUserDefinedColor_x                            0x53E8C0
#define CDisplay__GetWorldFilePath_x                               0x547C70
#define CDisplay__is3dON_x                                         0x542E60
#define CDisplay__ReloadUI_x                                       0x54D370
#define CDisplay__WriteTextHD2_x                                   0x542C50
#define CDisplay__TrueDistance_x                                   0x549930
#define CDisplay__SetViewActor_x                                   0x545B20
#define CDisplay__GetFloorHeight_x                                 0x542F20
#define CDisplay__SetRenderWindow_x                                0x541880
#define CDisplay__ToggleScreenshotMode_x                           0x5455F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x972850

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x955E80
#define CEditWnd__GetCharIndexPt_x                                 0x956DA0
#define CEditWnd__GetDisplayString_x                               0x956C50
#define CEditWnd__GetHorzOffset_x                                  0x9554C0
#define CEditWnd__GetLineForPrintableChar_x                        0x957F10
#define CEditWnd__GetSelStartPt_x                                  0x957050
#define CEditWnd__GetSTMLSafeText_x                                0x956A70
#define CEditWnd__PointFromPrintableChar_x                         0x957B50
#define CEditWnd__SelectableCharFromPoint_x                        0x957CC0
#define CEditWnd__SetEditable_x                                    0x957110
#define CEditWnd__SetWindowTextA_x                                 0x9567F0
#define CEditWnd__ReplaceSelection_x                               0x9577D0
#define CEditWnd__ReplaceSelection1_x                              0x957750

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FF5D0
#define CEverQuest__ClickedPlayer_x                                0x5F15E0
#define CEverQuest__CreateTargetIndicator_x                        0x60EB50
#define CEverQuest__DeleteTargetIndicator_x                        0x60EBE0
#define CEverQuest__DoTellWindow_x                                 0x4E8870
#define CEverQuest__OutputTextToLog_x                              0x4E8AF0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E6620
#define CEverQuest__dsp_chat_x                                     0x4E8E80
#define CEverQuest__trimName_x                                     0x60AE30
#define CEverQuest__Emote_x                                        0x5FFE30
#define CEverQuest__EnterZone_x                                    0x5F9DB0
#define CEverQuest__GetBodyTypeDesc_x                              0x6046F0
#define CEverQuest__GetClassDesc_x                                 0x604D30
#define CEverQuest__GetClassThreeLetterCode_x                      0x605330
#define CEverQuest__GetDeityDesc_x                                 0x60D490
#define CEverQuest__GetLangDesc_x                                  0x6054F0
#define CEverQuest__GetRaceDesc_x                                  0x604D10
#define CEverQuest__InterpretCmd_x                                 0x60DA60
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EA820
#define CEverQuest__LMouseUp_x                                     0x5E8BB0
#define CEverQuest__RightClickedOnPlayer_x                         0x5EB100
#define CEverQuest__RMouseUp_x                                     0x5E9B30
#define CEverQuest__SetGameState_x                                 0x5E63B0
#define CEverQuest__UPCNotificationFlush_x                         0x60AD30
#define CEverQuest__IssuePetCommand_x                              0x6068F0
#define CEverQuest__ReportSuccessfulHit_x                          0x601180

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72D760
#define CGaugeWnd__CalcLinesFillRect_x                             0x72D7C0
#define CGaugeWnd__Draw_x                                          0x72CDE0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF260
#define CGuild__GetGuildName_x                                     0x4AE340
#define CGuild__GetGuildIndex_x                                    0x4AE6D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x747990

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6204C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x754960
#define CInvSlotMgr__MoveItem_x                                    0x7536C0
#define CInvSlotMgr__SelectSlot_x                                  0x754A30

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x751F40
#define CInvSlot__SliderComplete_x                                 0x74FC90
#define CInvSlot__GetItemBase_x                                    0x74F620
#define CInvSlot__UpdateItem_x                                     0x74F790

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7564B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x755650
#define CInvSlotWnd__HandleLButtonUp_x                             0x756030

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8101D0
#define CItemDisplayWnd__UpdateStrings_x                           0x764BF0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75E940
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75EE60
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x765200
#define CItemDisplayWnd__AboutToShow_x                             0x764830
#define CItemDisplayWnd__WndNotification_x                         0x7662E0
#define CItemDisplayWnd__RequestConvertItem_x                      0x765DA0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x763890
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x764650

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x848EC0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76A820

// CLabel 
#define CLabel__Draw_x                                             0x770250

// CListWnd
#define CListWnd__CListWnd_x                                       0x928400
#define CListWnd__dCListWnd_x                                      0x928720
#define CListWnd__AddColumn_x                                      0x92CBB0
#define CListWnd__AddColumn1_x                                     0x92CC00
#define CListWnd__AddLine_x                                        0x92CF90
#define CListWnd__AddString_x                                      0x92CD90
#define CListWnd__CalculateFirstVisibleLine_x                      0x92C970
#define CListWnd__CalculateVSBRange_x                              0x92C750
#define CListWnd__ClearSel_x                                       0x92D770
#define CListWnd__ClearAllSel_x                                    0x92D7D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92E1F0
#define CListWnd__Compare_x                                        0x92C080
#define CListWnd__Draw_x                                           0x928850
#define CListWnd__DrawColumnSeparators_x                           0x92B050
#define CListWnd__DrawHeader_x                                     0x92B4C0
#define CListWnd__DrawItem_x                                       0x92B9C0
#define CListWnd__DrawLine_x                                       0x92B1C0
#define CListWnd__DrawSeparator_x                                  0x92B0F0
#define CListWnd__EnableLine_x                                     0x92A920
#define CListWnd__EnsureVisible_x                                  0x92E110
#define CListWnd__ExtendSel_x                                      0x92D6A0
#define CListWnd__GetColumnTooltip_x                               0x92A460
#define CListWnd__GetColumnMinWidth_x                              0x92A4D0
#define CListWnd__GetColumnWidth_x                                 0x92A3D0
#define CListWnd__GetCurSel_x                                      0x929D60
#define CListWnd__GetItemAtPoint_x                                 0x92ABA0
#define CListWnd__GetItemAtPoint1_x                                0x92AC10
#define CListWnd__GetItemData_x                                    0x929DE0
#define CListWnd__GetItemHeight_x                                  0x92A1A0
#define CListWnd__GetItemIcon_x                                    0x929F70
#define CListWnd__GetItemRect_x                                    0x92AA10
#define CListWnd__GetItemText_x                                    0x929E20
#define CListWnd__GetSelList_x                                     0x92D820
#define CListWnd__GetSeparatorRect_x                               0x92AE50
#define CListWnd__InsertLine_x                                     0x92D380
#define CListWnd__RemoveLine_x                                     0x92D4D0
#define CListWnd__SetColors_x                                      0x92C720
#define CListWnd__SetColumnJustification_x                         0x92C450
#define CListWnd__SetColumnWidth_x                                 0x92C370
#define CListWnd__SetCurSel_x                                      0x92D5E0
#define CListWnd__SetItemColor_x                                   0x92DDC0
#define CListWnd__SetItemData_x                                    0x92DD80
#define CListWnd__SetItemText_x                                    0x92D990
#define CListWnd__ShiftColumnSeparator_x                           0x92C510
#define CListWnd__Sort_x                                           0x92C200
#define CListWnd__ToggleSel_x                                      0x92D610
#define CListWnd__SetColumnsSizable_x                              0x92C5C0
#define CListWnd__SetItemWnd_x                                     0x92DC40
#define CListWnd__GetItemWnd_x                                     0x929FC0
#define CListWnd__SetItemIcon_x                                    0x92DA10
#define CListWnd__CalculateCustomWindowPositions_x                 0x92CA70
#define CListWnd__SetVScrollPos_x                                  0x92C350

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x785990
#define CMapViewWnd__GetWorldCoordinates_x                         0x7840A0
#define CMapViewWnd__HandleLButtonDown_x                           0x7810E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A5C20
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A6500
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A6A30
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A99B0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A4780
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AF570
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A5830

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AC000
#define CPacketScrambler__hton_x                                   0x8ABFF0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x947540
#define CSidlManager__FindScreenPieceTemplate_x                    0x947950
#define CSidlManager__FindScreenPieceTemplate1_x                   0x947740
#define CSidlManager__CreateLabel_x                                0x8075B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x94A8B0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x94AA90
#define CSidlManager__CreateXWnd_x                                 0x8074E0
#define CSidlManager__CreateHotButtonWnd_x                         0x807AA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x944000
#define CSidlScreenWnd__CalculateVSBRange_x                        0x943F00
#define CSidlScreenWnd__ConvertToRes_x                             0x969840
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x943990
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x943680
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x943750
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x943820
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9444A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x944970
#define CSidlScreenWnd__GetSidlPiece_x                             0x944690
#define CSidlScreenWnd__Init1_x                                    0x943280
#define CSidlScreenWnd__LoadIniInfo_x                              0x9449C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x945520
#define CSidlScreenWnd__LoadSidlScreen_x                           0x942680
#define CSidlScreenWnd__StoreIniInfo_x                             0x945090
#define CSidlScreenWnd__StoreIniVis_x                              0x945400
#define CSidlScreenWnd__WndNotification_x                          0x9443B0
#define CSidlScreenWnd__GetChildItem_x                             0x9448F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x934070
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FAFA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6850A0
#define CSkillMgr__GetSkillCap_x                                   0x685280
#define CSkillMgr__GetNameToken_x                                  0x684820
#define CSkillMgr__IsActivatedSkill_x                              0x684960
#define CSkillMgr__IsCombatSkill_x                                 0x6848A0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9542A0
#define CSliderWnd__SetValue_x                                     0x954110
#define CSliderWnd__SetNumTicks_x                                  0x954170

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80D600

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95CB20
#define CStmlWnd__CalculateHSBRange_x                              0x95DC40
#define CStmlWnd__CalculateVSBRange_x                              0x95DBC0
#define CStmlWnd__CanBreakAtCharacter_x                            0x961F80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x962C10
#define CStmlWnd__ForceParseNow_x                                  0x95D110
#define CStmlWnd__GetNextTagPiece_x                                0x961EE0
#define CStmlWnd__GetSTMLText_x                                    0x506090
#define CStmlWnd__GetVisibleText_x                                 0x95D130
#define CStmlWnd__InitializeWindowVariables_x                      0x962A60
#define CStmlWnd__MakeStmlColorTag_x                               0x95C190
#define CStmlWnd__MakeWndNotificationTag_x                         0x95C200
#define CStmlWnd__SetSTMLText_x                                    0x95B240
#define CStmlWnd__StripFirstSTMLLines_x                            0x963D10
#define CStmlWnd__UpdateHistoryString_x                            0x962E20

// CTabWnd 
#define CTabWnd__Draw_x                                            0x95A2E0
#define CTabWnd__DrawCurrentPage_x                                 0x95AA10
#define CTabWnd__DrawTab_x                                         0x95A730
#define CTabWnd__GetCurrentPage_x                                  0x959AE0
#define CTabWnd__GetPageInnerRect_x                                0x959D20
#define CTabWnd__GetTabInnerRect_x                                 0x959C60
#define CTabWnd__GetTabRect_x                                      0x959B10
#define CTabWnd__InsertPage_x                                      0x959F30
#define CTabWnd__SetPage_x                                         0x959DA0
#define CTabWnd__SetPageRect_x                                     0x95A220
#define CTabWnd__UpdatePage_x                                      0x95A5F0
#define CTabWnd__GetPageFromTabIndex_x                             0x95A670
#define CTabWnd__GetCurrentTabIndex_x                              0x959AD0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76AC50
#define CPageWnd__SetTabText_x                                     0x959620

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8E60

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x930F30
#define CTextureFont__GetTextExtent_x                              0x9310F0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B8470
#define CHtmlComponentWnd__ValidateUri_x                           0x749380
#define CHtmlWnd__SetClientCallbacks_x                             0x625570
#define CHtmlWnd__AddObserver_x                                    0x625590
#define CHtmlWnd__RemoveObserver_x                                 0x6255F0
#define Window__getProgress_x                                      0x861420
#define Window__getStatus_x                                        0x861440
#define Window__getURI_x                                           0x861450

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96F2E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91E030

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8490
#define CXStr__CXStr1_x                                            0x4B6290
#define CXStr__CXStr3_x                                            0x8FEF50
#define CXStr__dCXStr_x                                            0x4787E0
#define CXStr__operator_equal_x                                    0x8FF180
#define CXStr__operator_equal1_x                                   0x8FF1C0
#define CXStr__operator_plus_equal1_x                              0x8FFC50
#define CXStr__SetString_x                                         0x901B40
#define CXStr__operator_char_p_x                                   0x8FF690
#define CXStr__GetChar_x                                           0x901470
#define CXStr__Delete_x                                            0x900D40
#define CXStr__GetUnicode_x                                        0x9014E0
#define CXStr__GetLength_x                                         0x47D490
#define CXStr__Mid_x                                               0x47D4A0
#define CXStr__Insert_x                                            0x901540
#define CXStr__FindNext_x                                          0x9011B0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x952520
#define CXWnd__BringToTop_x                                        0x937860
#define CXWnd__Center_x                                            0x9373E0
#define CXWnd__ClrFocus_x                                          0x9371F0
#define CXWnd__Destroy_x                                           0x9372A0
#define CXWnd__DoAllDrawing_x                                      0x933820
#define CXWnd__DrawChildren_x                                      0x9337F0
#define CXWnd__DrawColoredRect_x                                   0x933C80
#define CXWnd__DrawTooltip_x                                       0x932330
#define CXWnd__DrawTooltipAtPoint_x                                0x9323F0
#define CXWnd__GetBorderFrame_x                                    0x933AE0
#define CXWnd__GetChildWndAt_x                                     0x937900
#define CXWnd__GetClientClipRect_x                                 0x935AB0
#define CXWnd__GetScreenClipRect_x                                 0x935B50
#define CXWnd__GetScreenRect_x                                     0x935D00
#define CXWnd__GetTooltipRect_x                                    0x933CD0
#define CXWnd__GetWindowTextA_x                                    0x49CA30
#define CXWnd__IsActive_x                                          0x9343E0
#define CXWnd__IsDescendantOf_x                                    0x936710
#define CXWnd__IsReallyVisible_x                                   0x936740
#define CXWnd__IsType_x                                            0x937F70
#define CXWnd__Move_x                                              0x9367A0
#define CXWnd__Move1_x                                             0x936850
#define CXWnd__ProcessTransition_x                                 0x937390
#define CXWnd__Refade_x                                            0x936B30
#define CXWnd__Resize_x                                            0x936E00
#define CXWnd__Right_x                                             0x937620
#define CXWnd__SetFocus_x                                          0x9371B0
#define CXWnd__SetFont_x                                           0x937220
#define CXWnd__SetKeyTooltip_x                                     0x937D90
#define CXWnd__SetMouseOver_x                                      0x934C20
#define CXWnd__StartFade_x                                         0x9365F0
#define CXWnd__GetChildItem_x                                      0x937A70
#define CXWnd__SetParent_x                                         0x9364B0
#define CXWnd__Minimize_x                                          0x936E70

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96A8C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x93A7B0
#define CXWndManager__DrawWindows_x                                0x93A7D0
#define CXWndManager__GetKeyboardFlags_x                           0x93CEC0
#define CXWndManager__HandleKeyboardMsg_x                          0x93CA70
#define CXWndManager__RemoveWnd_x                                  0x93D0F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93D670

// CDBStr
#define CDBStr__GetString_x                                        0x53D850

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB940
#define EQ_Character__Cur_HP_x                                     0x4D2000
#define EQ_Character__Cur_Mana_x                                   0x4D9740
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE9B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2450
#define EQ_Character__GetFocusRangeModifier_x                      0x4B25A0
#define EQ_Character__GetHPRegen_x                                 0x4DF510
#define EQ_Character__GetEnduranceRegen_x                          0x4DFB10
#define EQ_Character__GetManaRegen_x                               0x4DFF50
#define EQ_Character__Max_Endurance_x                              0x64B540
#define EQ_Character__Max_HP_x                                     0x4D1E30
#define EQ_Character__Max_Mana_x                                   0x64B340
#define EQ_Character__doCombatAbility_x                            0x64D9A0
#define EQ_Character__UseSkill_x                                   0x4E1D30
#define EQ_Character__GetConLevel_x                                0x644890
#define EQ_Character__IsExpansionFlag_x                            0x5A8010
#define EQ_Character__TotalEffect_x                                0x4C5400
#define EQ_Character__GetPCSpellAffect_x                           0x4BF700
#define EQ_Character__SpellDuration_x                              0x4BF230
#define EQ_Character__GetAdjustedSkill_x                           0x4D4D80
#define EQ_Character__GetBaseSkill_x                               0x4D5D20
#define EQ_Character__CanUseItem_x                                 0x4D9A50

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CB390

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x661B20

//PcClient
#define PcClient__PcClient_x                                       0x641FD0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95B0
#define CCharacterListWnd__EnterWorld_x                            0x4B8FF0
#define CCharacterListWnd__Quit_x                                  0x4B8D40
#define CCharacterListWnd__UpdateList_x                            0x4B9180

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6267C0
#define EQ_Item__CreateItemTagString_x                             0x8A5820
#define EQ_Item__IsStackable_x                                     0x8AA3C0
#define EQ_Item__GetImageNum_x                                     0x8A72D0
#define EQ_Item__CreateItemClient_x                                0x625990
#define EQ_Item__GetItemValue_x                                    0x8A85E0
#define EQ_Item__ValueSellMerchant_x                               0x8ABBE0
#define EQ_Item__IsKeyRingItem_x                                   0x8A9CE0
#define EQ_Item__CanGoInBag_x                                      0x6268E0
#define EQ_Item__IsEmpty_x                                         0x8A9820
#define EQ_Item__GetMaxItemCount_x                                 0x8A89F0
#define EQ_Item__GetHeldItem_x                                     0x8A71A0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A5190

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55BCB0
#define EQ_LoadingS__Array_x                                       0xC29B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64BEA0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B4E80
#define EQ_PC__GetCombatAbility_x                                  0x8B54F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B5560
#define EQ_PC__GetItemRecastTimer_x                                0x64DF20
#define EQ_PC__HasLoreItem_x                                       0x645050
#define EQ_PC__AlertInventoryChanged_x                             0x6441D0
#define EQ_PC__GetPcZoneClient_x                                   0x6705B0
#define EQ_PC__RemoveMyAffect_x                                    0x651150
#define EQ_PC__GetKeyRingItems_x                                   0x8B5DF0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B5B80
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B60F0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AE570
#define EQItemList__add_object_x                                   0x5DBEF0
#define EQItemList__add_item_x                                     0x5AEAD0
#define EQItemList__delete_item_x                                  0x5AEB20
#define EQItemList__FreeItemList_x                                 0x5AEA20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A310

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6633A0
#define EQPlayer__dEQPlayer_x                                      0x6566E0
#define EQPlayer__DoAttack_x                                       0x66B240
#define EQPlayer__EQPlayer_x                                       0x656DA0
#define EQPlayer__SetNameSpriteState_x                             0x65B080
#define EQPlayer__SetNameSpriteTint_x                              0x65BF50
#define PlayerBase__HasProperty_j_x                                0x99CFA0
#define EQPlayer__IsTargetable_x                                   0x99D440
#define EQPlayer__CanSee_x                                         0x99D2A0
#define EQPlayer__CanSee1_x                                        0x99D370
#define PlayerBase__GetVisibilityLineSegment_x                     0x99D060

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66E040
#define PlayerZoneClient__GetLevel_x                               0x6705F0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DD060
#define PlayerZoneClient__LegalPlayerRace_x                        0x5550D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x666160
#define EQPlayerManager__GetSpawnByName_x                          0x666210
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6662A0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x629F30
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x629FB0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x629FF0
#define KeypressHandler__ClearCommandStateArray_x                  0x62B400
#define KeypressHandler__HandleKeyDown_x                           0x62B420
#define KeypressHandler__HandleKeyUp_x                             0x62B4C0
#define KeypressHandler__SaveKeymapping_x                          0x62B910

// MapViewMap 
#define MapViewMap__Clear_x                                        0x781800
#define MapViewMap__SaveEx_x                                       0x784BC0
#define MapViewMap__SetZoom_x                                      0x789280

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C92B0

// StringTable 
#define StringTable__getString_x                                   0x8C4080

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x650DC0
#define PcZoneClient__RemovePetEffect_x                            0x6513F0
#define PcZoneClient__HasAlternateAbility_x                        0x64B170
#define PcZoneClient__GetCurrentMod_x                              0x4E4DF0
#define PcZoneClient__GetModCap_x                                  0x4E4CF0
#define PcZoneClient__CanEquipItem_x                               0x64B840
#define PcZoneClient__GetItemByID_x                                0x64E390
#define PcZoneClient__GetItemByItemClass_x                         0x64E4E0
#define PcZoneClient__RemoveBuffEffect_x                           0x651410
#define PcZoneClient__BandolierSwap_x                              0x64C460
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64DEC0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E1B20

//IconCache
#define IconCache__GetIcon_x                                       0x722F70

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71AA70
#define CContainerMgr__CloseContainer_x                            0x71AD40
#define CContainerMgr__OpenExperimentContainer_x                   0x71B7C0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D9A90

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61E8C0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x777D20
#define CLootWnd__RequestLootSlot_x                                0x776F50

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57BE40
#define EQ_Spell__SpellAffects_x                                   0x57C2B0
#define EQ_Spell__SpellAffectBase_x                                0x57C070
#define EQ_Spell__IsStackable_x                                    0x4C9A50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C98D0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6930
#define EQ_Spell__IsSPAStacking_x                                  0x57D100
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57C610
#define EQ_Spell__IsNoRemove_x                                     0x4C9A30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57D110
#define __IsResEffectSpell_x                                       0x4C8E20

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACF50

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D39C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x820940
#define CTargetWnd__WndNotification_x                              0x8201D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8204A0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81F330

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x824F40

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x537D40
#define CTaskManager__HandleMessage_x                              0x5361F0
#define CTaskManager__GetTaskStatus_x                              0x537DF0
#define CTaskManager__GetElementDescription_x                      0x537E70

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5773B0
#define EqSoundManager__PlayScriptMp3_x                            0x577510
#define EqSoundManager__SoundAssistPlay_x                          0x688FE0
#define EqSoundManager__WaveInstancePlay_x                         0x688550

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52B650

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x958B30

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x563760
#define CAltAbilityData__GetMercMaxRank_x                          0x5636F0
#define CAltAbilityData__GetMaxRank_x                              0x558D90

//CTargetRing
#define CTargetRing__Cast_x                                        0x61C9E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C98B0
#define CharacterBase__CreateItemGlobalIndex_x                     0x512E30
#define CharacterBase__CreateItemIndex_x                           0x624B20
#define CharacterBase__GetItemPossession_x                         0x4FEC40
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DBFD0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DC030
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x701BD0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x702400
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x7024B0

//messages
#define msg_spell_worn_off_x                                       0x5A02E0
#define msg_new_text_x                                             0x595080
#define __msgTokenTextParam_x                                      0x5A2810
#define msgTokenText_x                                             0x5A2A60

//SpellManager
#define SpellManager__vftable_x                                    0xAEF68C
#define SpellManager__SpellManager_x                               0x68C310
#define Spellmanager__LoadTextSpells_x                             0x68CC00
#define SpellManager__GetSpellByGroupAndRank_x                     0x68C4E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A0E60

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x513480
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A65D0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63D740
#define ItemGlobalIndex__IsValidIndex_x                            0x5134E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D4360
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D45E0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x770590

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71F180
#define CCursorAttachment__AttachToCursor1_x                       0x71F1C0
#define CCursorAttachment__Deactivate_x                            0x7201A0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94B8E0
#define CSidlManagerBase__CreatePageWnd_x                          0x94B0E0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x947360
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9472F0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x968E50
#define CEQSuiteTextureLoader__GetTexture_x                        0x968B10

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5103A0
#define CFindItemWnd__WndNotification_x                            0x510E80
#define CFindItemWnd__Update_x                                     0x5119F0
#define CFindItemWnd__PickupSelectedItem_x                         0x50FBE0

//IString
#define IString__Append_x                                          0x4F13A0

//Camera
#define CDisplay__cameraType_x                                     0xE035A4
#define EverQuest__Cameras_x                                       0xEC6ACC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x518B80
#define LootFiltersManager__GetItemFilterData_x                    0x518480
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5184B0
#define LootFiltersManager__SetItemLootFilter_x                    0x5186D0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C7A30

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A69E0
#define CResolutionHandler__GetWindowedStyle_x                     0x683B00

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x717840

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E9520
#define CDistillerInfo__Instance_x                                 0x8E94C0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x736740
#define CGroupWnd__UpdateDisplay_x                                 0x735A90

//ItemBase
#define ItemBase__IsLore_x                                         0x8A9D90
#define ItemBase__IsLoreEquipped_x                                 0x8A9E00

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DBE50
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DBF90
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DBFF0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678E00
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67C750

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x5066E0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F3280
#define FactionManagerClient__HandleFactionMessage_x               0x4F38F0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3EF0
#define FactionManagerClient__GetMaxFaction_x                      0x4F3F0F
#define FactionManagerClient__GetMinFaction_x                      0x4F3EC0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FEC10

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92FEE0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD10

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FEE90

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562C20

//CTargetManager
#define CTargetManager__Get_x                                      0x68FB50

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678E00

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8C20

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AE9C0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF64160

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
