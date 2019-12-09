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
#define __ExpectedVersionDate                                     "Dec  9 2019"
#define __ExpectedVersionTime                                     "04:22:11"
#define __ActualVersionDate_x                                      0xB0B6BC
#define __ActualVersionTime_x                                      0xB0B6B0
#define __ActualVersionBuild_x                                     0xAF7334

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x630060
#define __MemChecker1_x                                            0x903A90
#define __MemChecker2_x                                            0x6BEB20
#define __MemChecker3_x                                            0x6BEA70
#define __MemChecker4_x                                            0x85A860
#define __EncryptPad0_x                                            0xC423E8
#define __EncryptPad1_x                                            0xCA05E8
#define __EncryptPad2_x                                            0xC52C80
#define __EncryptPad3_x                                            0xC52880
#define __EncryptPad4_x                                            0xC90C00
#define __EncryptPad5_x                                            0xF6C210
#define __AC1_x                                                    0x817206
#define __AC2_x                                                    0x5E9E7F
#define __AC3_x                                                    0x5F157F
#define __AC4_x                                                    0x5F5550
#define __AC5_x                                                    0x5FB85F
#define __AC6_x                                                    0x5FFE76
#define __AC7_x                                                    0x5E98F0
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
#define __do_loot_x                                                0x5B5940
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
#define __ScreenMode_x                                             0xE0309C
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
#define __gfMaxZoomCameraDistance_x                                0xB00FC8
#define __gfMaxCameraDistance_x                                    0xB2D51C
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
#define pinstCamActor_x                                            0xE03090
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
#define pinstViewActor_x                                           0xE0308C
#define pinstWorldData_x                                           0xEB5C08
#define pinstZoneAddr_x                                            0xEC5930
#define pinstPlayerPath_x                                          0xF673D8
#define pinstTargetIndicator_x                                     0xF68D20
#define EQObject_Top_x                                             0xEB56C4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE037EC
#define pinstCAchievementsWnd_x                                    0xE037E8
#define pinstCActionsWnd_x                                         0xE037B0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE03020
#define pinstCAdvancedLootWnd_x                                    0xE02FE0
#define pinstCAdventureLeaderboardWnd_x                            0xF763B0
#define pinstCAdventureRequestWnd_x                                0xF76460
#define pinstCAdventureStatsWnd_x                                  0xF76510
#define pinstCAggroMeterWnd_x                                      0xE03540
#define pinstCAlarmWnd_x                                           0xE03848
#define pinstCAlertHistoryWnd_x                                    0xE03040
#define pinstCAlertStackWnd_x                                      0xE03850
#define pinstCAlertWnd_x                                           0xE02FC4
#define pinstCAltStorageWnd_x                                      0xF76870
#define pinstCAudioTriggersWindow_x                                0xCB7BA8
#define pinstCAuraWnd_x                                            0xE03064
#define pinstCAvaZoneWnd_x                                         0xE02FF8
#define pinstCBandolierWnd_x                                       0xE030D4
#define pinstCBankWnd_x                                            0xE03060
#define pinstCBarterMerchantWnd_x                                  0xF77AB0
#define pinstCBarterSearchWnd_x                                    0xF77B60
#define pinstCBarterWnd_x                                          0xF77C10
#define pinstCBazaarConfirmationWnd_x                              0xE03814
#define pinstCBazaarSearchWnd_x                                    0xE03588
#define pinstCBazaarWnd_x                                          0xE03830
#define pinstCBlockedBuffWnd_x                                     0xE03068
#define pinstCBlockedPetBuffWnd_x                                  0xE030C0
#define pinstCBodyTintWnd_x                                        0xE037C0
#define pinstCBookWnd_x                                            0xE03564
#define pinstCBreathWnd_x                                          0xE03804
#define pinstCBuffWindowNORMAL_x                                   0xE03044
#define pinstCBuffWindowSHORT_x                                    0xE03048
#define pinstCBugReportWnd_x                                       0xE03058
#define pinstCButtonWnd_x                                          0x15FB380
#define pinstCCastingWnd_x                                         0xE03558
#define pinstCCastSpellWnd_x                                       0xE03800
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE03834
#define pinstCChatWindowManager_x                                  0xF786D0
#define pinstCClaimWnd_x                                           0xF78828
#define pinstCColorPickerWnd_x                                     0xE037B8
#define pinstCCombatAbilityWnd_x                                   0xE03840
#define pinstCCombatSkillsSelectWnd_x                              0xE02FC8
#define pinstCCompassWnd_x                                         0xE037B4
#define pinstCConfirmationDialog_x                                 0xF7D728
#define pinstCContainerMgr_x                                       0xE03828
#define pinstCContextMenuManager_x                                 0x15FB0D0
#define pinstCCursorAttachment_x                                   0xE0354C
#define pinstCDynamicZoneWnd_x                                     0xF78DF0
#define pinstCEditLabelWnd_x                                       0xE03038
#define pinstCEQMainWnd_x                                          0xF79038
#define pinstCEventCalendarWnd_x                                   0xE03550
#define pinstCExtendedTargetWnd_x                                  0xE030B4
#define pinstCFacePick_x                                           0xE02FD8
#define pinstCFactionWnd_x                                         0xE03824
#define pinstCFellowshipWnd_x                                      0xF79238
#define pinstCFileSelectionWnd_x                                   0xE03554
#define pinstCFindItemWnd_x                                        0xE03810
#define pinstCFindLocationWnd_x                                    0xF79390
#define pinstCFriendsWnd_x                                         0xE02FDC
#define pinstCGemsGameWnd_x                                        0xE03820
#define pinstCGiveWnd_x                                            0xE0384C
#define pinstCGroupSearchFiltersWnd_x                              0xE0355C
#define pinstCGroupSearchWnd_x                                     0xF79788
#define pinstCGroupWnd_x                                           0xF79838
#define pinstCGuildBankWnd_x                                       0xEC6774
#define pinstCGuildCreationWnd_x                                   0xF79998
#define pinstCGuildMgmtWnd_x                                       0xF79A48
#define pinstCharacterCreation_x                                   0xE02FD0
#define pinstCHelpWnd_x                                            0xE03014
#define pinstCHeritageSelectionWnd_x                               0xE02FE4
#define pinstCHotButtonWnd_x                                       0xF7BBA0
#define pinstCHotButtonWnd1_x                                      0xF7BBA0
#define pinstCHotButtonWnd2_x                                      0xF7BBA4
#define pinstCHotButtonWnd3_x                                      0xF7BBA8
#define pinstCHotButtonWnd4_x                                      0xF7BBAC
#define pinstCIconSelectionWnd_x                                   0xE03548
#define pinstCInspectWnd_x                                         0xE03010
#define pinstCInventoryWnd_x                                       0xE02FE8
#define pinstCInvSlotMgr_x                                         0xE037E4
#define pinstCItemDisplayManager_x                                 0xF7C130
#define pinstCItemExpTransferWnd_x                                 0xF7C260
#define pinstCItemOverflowWnd_x                                    0xE0358C
#define pinstCJournalCatWnd_x                                      0xE03568
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE030B8
#define pinstCKeyRingWnd_x                                         0xE03030
#define pinstCLargeDialogWnd_x                                     0xF7E3A8
#define pinstCLayoutCopyWnd_x                                      0xF7C5B0
#define pinstCLFGuildWnd_x                                         0xF7C660
#define pinstCLoadskinWnd_x                                        0xE0382C
#define pinstCLootFiltersCopyWnd_x                                 0xCD41F8
#define pinstCLootFiltersWnd_x                                     0xE02FB8
#define pinstCLootSettingsWnd_x                                    0xE02FD4
#define pinstCLootWnd_x                                            0xE0356C
#define pinstCMailAddressBookWnd_x                                 0xE037F0
#define pinstCMailCompositionWnd_x                                 0xE037D0
#define pinstCMailIgnoreListWnd_x                                  0xE037F4
#define pinstCMailWnd_x                                            0xE037AC
#define pinstCManageLootWnd_x                                      0xE046B0
#define pinstCMapToolbarWnd_x                                      0xE0301C
#define pinstCMapViewWnd_x                                         0xE02FF4
#define pinstCMarketplaceWnd_x                                     0xE02FBC
#define pinstCMerchantWnd_x                                        0xE03570
#define pinstCMIZoneSelectWnd_x                                    0xF7CE98
#define pinstCMusicPlayerWnd_x                                     0xE03578
#define pinstCNameChangeMercWnd_x                                  0xE0380C
#define pinstCNameChangePetWnd_x                                   0xE037F8
#define pinstCNameChangeWnd_x                                      0xE0381C
#define pinstCNoteWnd_x                                            0xE02FFC
#define pinstCObjectPreviewWnd_x                                   0xE02FCC
#define pinstCOptionsWnd_x                                         0xE03000
#define pinstCPetInfoWnd_x                                         0xE03594
#define pinstCPetitionQWnd_x                                       0xE037D8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE037C4
#define pinstCPlayerWnd_x                                          0xE03598
#define pinstCPopupWndManager_x                                    0xF7D728
#define pinstCProgressionSelectionWnd_x                            0xF7D7D8
#define pinstCPurchaseGroupWnd_x                                   0xE03008
#define pinstCPurchaseWnd_x                                        0xE02FEC
#define pinstCPvPLeaderboardWnd_x                                  0xF7D888
#define pinstCPvPStatsWnd_x                                        0xF7D938
#define pinstCQuantityWnd_x                                        0xE030BC
#define pinstCRaceChangeWnd_x                                      0xE03844
#define pinstCRaidOptionsWnd_x                                     0xE03560
#define pinstCRaidWnd_x                                            0xE037D4
#define pinstCRealEstateItemsWnd_x                                 0xE037E0
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE03574
#define pinstCRealEstateManageWnd_x                                0xE03018
#define pinstCRealEstateNeighborhoodWnd_x                          0xE03034
#define pinstCRealEstatePlotSearchWnd_x                            0xE0305C
#define pinstCRealEstatePurchaseWnd_x                              0xE030B0
#define pinstCRespawnWnd_x                                         0xE030AC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE037FC
#define pinstCSendMoneyWnd_x                                       0xE02FC0
#define pinstCServerListWnd_x                                      0xE0313C
#define pinstCSkillsSelectWnd_x                                    0xE03838
#define pinstCSkillsWnd_x                                          0xE03818
#define pinstCSocialEditWnd_x                                      0xE03028
#define pinstCSocialWnd_x                                          0xE03808
#define pinstCSpellBookWnd_x                                       0xE0383C
#define pinstCStoryWnd_x                                           0xE0359C
#define pinstCTargetOfTargetWnd_x                                  0xF7F760
#define pinstCTargetWnd_x                                          0xE030A8
#define pinstCTaskOverlayWnd_x                                     0xE03004
#define pinstCTaskSelectWnd_x                                      0xF7F8B8
#define pinstCTaskManager_x                                        0xCD4B38
#define pinstCTaskTemplateSelectWnd_x                              0xF7F968
#define pinstCTaskWnd_x                                            0xF7FA18
#define pinstCTextEntryWnd_x                                       0xE0304C
#define pinstCTimeLeftWnd_x                                        0xE037A8
#define pinstCTipWndCONTEXT_x                                      0xF7FC1C
#define pinstCTipWndOFDAY_x                                        0xF7FC18
#define pinstCTitleWnd_x                                           0xF7FCC8
#define pinstCTrackingWnd_x                                        0xE02FF0
#define pinstCTradeskillWnd_x                                      0xF7FE30
#define pinstCTradeWnd_x                                           0xE037CC
#define pinstCTrainWnd_x                                           0xE037C8
#define pinstCTributeBenefitWnd_x                                  0xF80030
#define pinstCTributeMasterWnd_x                                   0xF800E0
#define pinstCTributeTrophyWnd_x                                   0xF80190
#define pinstCVideoModesWnd_x                                      0xE035A0
#define pinstCVoiceMacroWnd_x                                      0xF69488
#define pinstCVoteResultsWnd_x                                     0xE037DC
#define pinstCVoteWnd_x                                            0xE037BC
#define pinstCWebManager_x                                         0xF69B04
#define pinstCZoneGuideWnd_x                                       0xE0300C
#define pinstCZonePathWnd_x                                        0xE03024

#define pinstEQSuiteTextureLoader_x                                0xCA20C0
#define pinstItemIconCache_x                                       0xF78FF0
#define pinstLootFiltersManager_x                                  0xCD42A8
#define pinstRewardSelectionWnd_x                                  0xF7E080

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B0DA0
#define __CastRay2_x                                               0x5B0DF0
#define __ConvertItemTags_x                                        0x5CC940
#define __CleanItemTags_x                                          0x47D010
#define __DoesFileExist_x                                          0x906BD0
#define __EQGetTime_x                                              0x903560
#define __ExecuteCmd_x                                             0x5A9610
#define __FixHeading_x                                             0x99D880
#define __GameLoop_x                                               0x6BDD10
#define __get_bearing_x                                            0x5B0910
#define __get_melee_range_x                                        0x5B0FE0
#define __GetAnimationCache_x                                      0x722F70
#define __GetGaugeValueFromEQ_x                                    0x8156B0
#define __GetLabelFromEQ_x                                         0x817190
#define __GetXTargetType_x                                         0x99F340
#define __HandleMouseWheel_x                                       0x6BEBD0
#define __HeadingDiff_x                                            0x99D8F0
#define __HelpPath_x                                               0xF6482C
#define __LoadFrontEnd_x                                           0x6BB030
#define __NewUIINI_x                                               0x815380
#define __ProcessGameEvents_x                                      0x611640
#define __ProcessMouseEvent_x                                      0x610E00
#define __SaveColors_x                                             0x552D60
#define __STMLToText_x                                             0x940D40
#define __ToggleKeyRingItem_x                                      0x5166F0
#define CMemoryMappedFile__SetFile_x                               0xA8CB50
#define CrashDetected_x                                            0x6BCAD0
#define DrawNetStatus_x                                            0x63D230
#define Expansion_HoT_x                                            0xEC677C
#define Teleport_Table_Size_x                                      0xEB57B0
#define Teleport_Table_x                                           0xEB5C28
#define Util__FastTime_x                                           0x903130

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490290
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499190
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F60
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493830
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55A8A0
#define AltAdvManager__IsAbilityReady_x                            0x5597D0
#define AltAdvManager__GetAAById_x                                 0x5599D0
#define AltAdvManager__CanTrainAbility_x                           0x559A40
#define AltAdvManager__CanSeeAbility_x                             0x559DA0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9FF0
#define CharacterZoneClient__HasSkill_x                            0x4D4EE0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6600
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE220
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA820
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8F70
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9050
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9130
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3020
#define CharacterZoneClient__BardCastBard_x                        0x4C5B80
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA8F0
#define CharacterZoneClient__GetEffect_x                           0x4BA760
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4070
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4140
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4190
#define CharacterZoneClient__CalcAffectChange_x                    0x4C42E0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C44B0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2700
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7560
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6FE0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E4790
#define CBankWnd__WndNotification_x                                0x6E4570

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F1F20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61FE60
#define CButtonWnd__CButtonWnd_x                                   0x93D0F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7120F0
#define CChatManager__InitContextMenu_x                            0x70B250
#define CChatManager__FreeChatWindow_x                             0x710C30
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8520
#define CChatManager__SetLockedActiveChatWindow_x                  0x711D70
#define CChatManager__CreateChatWindow_x                           0x711270

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8630

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x951730
#define CContextMenu__dCContextMenu_x                              0x951960
#define CContextMenu__AddMenuItem_x                                0x951970
#define CContextMenu__RemoveMenuItem_x                             0x951C80
#define CContextMenu__RemoveAllMenuItems_x                         0x951CA0
#define CContextMenu__CheckMenuItem_x                              0x951D20
#define CContextMenu__SetMenuItem_x                                0x951BA0
#define CContextMenu__AddSeparator_x                               0x951B00

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9522B0
#define CContextMenuManager__RemoveMenu_x                          0x952320
#define CContextMenuManager__PopupMenu_x                           0x9523E0
#define CContextMenuManager__Flush_x                               0x952250
#define CContextMenuManager__GetMenu_x                             0x49B360
#define CContextMenuManager__CreateDefaultMenu_x                   0x71D740

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DEBB0
#define CChatService__GetFriendName_x                              0x8DEBC0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x712960
#define CChatWindow__Clear_x                                       0x713C20
#define CChatWindow__WndNotification_x                             0x7143B0
#define CChatWindow__AddHistory_x                                  0x7134E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94EB90
#define CComboWnd__Draw_x                                          0x94E090
#define CComboWnd__GetCurChoice_x                                  0x94E9D0
#define CComboWnd__GetListRect_x                                   0x94E540
#define CComboWnd__GetTextRect_x                                   0x94EC00
#define CComboWnd__InsertChoice_x                                  0x94E6D0
#define CComboWnd__SetColors_x                                     0x94E6A0
#define CComboWnd__SetChoice_x                                     0x94E9A0
#define CComboWnd__GetItemCount_x                                  0x94E9E0
#define CComboWnd__GetCurChoiceText_x                              0x94EA20
#define CComboWnd__GetChoiceText_x                                 0x94E9F0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94E760

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71B140
#define CContainerWnd__vftable_x                                   0xB148A4
#define CContainerWnd__SetContainer_x                              0x71C6A0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54D790
#define CDisplay__PreZoneMainUI_x                                  0x54D7A0
#define CDisplay__CleanGameUI_x                                    0x552B20
#define CDisplay__GetClickedActor_x                                0x545AB0
#define CDisplay__GetUserDefinedColor_x                            0x53E170
#define CDisplay__GetWorldFilePath_x                               0x547520
#define CDisplay__is3dON_x                                         0x542710
#define CDisplay__ReloadUI_x                                       0x54CC20
#define CDisplay__WriteTextHD2_x                                   0x542500
#define CDisplay__TrueDistance_x                                   0x5491E0
#define CDisplay__SetViewActor_x                                   0x5453D0
#define CDisplay__GetFloorHeight_x                                 0x5427D0
#define CDisplay__SetRenderWindow_x                                0x541130
#define CDisplay__ToggleScreenshotMode_x                           0x544EA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9713C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x954C80
#define CEditWnd__GetCharIndexPt_x                                 0x955BB0
#define CEditWnd__GetDisplayString_x                               0x955A50
#define CEditWnd__GetHorzOffset_x                                  0x9542B0
#define CEditWnd__GetLineForPrintableChar_x                        0x956D50
#define CEditWnd__GetSelStartPt_x                                  0x955E60
#define CEditWnd__GetSTMLSafeText_x                                0x955870
#define CEditWnd__PointFromPrintableChar_x                         0x956980
#define CEditWnd__SelectableCharFromPoint_x                        0x956AF0
#define CEditWnd__SetEditable_x                                    0x955F30
#define CEditWnd__SetWindowTextA_x                                 0x9555F0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FF350
#define CEverQuest__ClickedPlayer_x                                0x5F1360
#define CEverQuest__CreateTargetIndicator_x                        0x60E8D0
#define CEverQuest__DeleteTargetIndicator_x                        0x60E960
#define CEverQuest__DoTellWindow_x                                 0x4E8710
#define CEverQuest__OutputTextToLog_x                              0x4E8990
#define CEverQuest__DropHeldItemOnGround_x                         0x5E63A0
#define CEverQuest__dsp_chat_x                                     0x4E8D20
#define CEverQuest__trimName_x                                     0x60ABB0
#define CEverQuest__Emote_x                                        0x5FFBB0
#define CEverQuest__EnterZone_x                                    0x5F9B30
#define CEverQuest__GetBodyTypeDesc_x                              0x604480
#define CEverQuest__GetClassDesc_x                                 0x604AC0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6050C0
#define CEverQuest__GetDeityDesc_x                                 0x60D210
#define CEverQuest__GetLangDesc_x                                  0x605280
#define CEverQuest__GetRaceDesc_x                                  0x604AA0
#define CEverQuest__InterpretCmd_x                                 0x60D7E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EA5A0
#define CEverQuest__LMouseUp_x                                     0x5E8930
#define CEverQuest__RightClickedOnPlayer_x                         0x5EAE80
#define CEverQuest__RMouseUp_x                                     0x5E98B0
#define CEverQuest__SetGameState_x                                 0x5E6130
#define CEverQuest__UPCNotificationFlush_x                         0x60AAB0
#define CEverQuest__IssuePetCommand_x                              0x606670
#define CEverQuest__ReportSuccessfulHit_x                          0x600F00

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72CFB0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72D010
#define CGaugeWnd__Draw_x                                          0x72C630

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF110
#define CGuild__GetGuildName_x                                     0x4AE1F0
#define CGuild__GetGuildIndex_x                                    0x4AE580

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7483E0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x620220

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7553F0
#define CInvSlotMgr__MoveItem_x                                    0x754110
#define CInvSlotMgr__SelectSlot_x                                  0x7554C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x752990
#define CInvSlot__SliderComplete_x                                 0x750700
#define CInvSlot__GetItemBase_x                                    0x750080
#define CInvSlot__UpdateItem_x                                     0x7501F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x756F40
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7560E0
#define CInvSlotWnd__HandleLButtonUp_x                             0x756AC0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x810A20
#define CItemDisplayWnd__UpdateStrings_x                           0x765670
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75F360
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75F890
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x765C70
#define CItemDisplayWnd__AboutToShow_x                             0x7652C0
#define CItemDisplayWnd__WndNotification_x                         0x766D60
#define CItemDisplayWnd__RequestConvertItem_x                      0x766820
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x764330
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7650E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x849580

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76B260

// CLabel 
#define CLabel__Draw_x                                             0x770CB0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9274F0
#define CListWnd__dCListWnd_x                                      0x927810
#define CListWnd__AddColumn_x                                      0x92BC80
#define CListWnd__AddColumn1_x                                     0x92BCD0
#define CListWnd__AddLine_x                                        0x92C060
#define CListWnd__AddString_x                                      0x92BE60
#define CListWnd__CalculateFirstVisibleLine_x                      0x92BA40
#define CListWnd__CalculateVSBRange_x                              0x92B830
#define CListWnd__ClearSel_x                                       0x92C840
#define CListWnd__ClearAllSel_x                                    0x92C8A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92D2C0
#define CListWnd__Compare_x                                        0x92B160
#define CListWnd__Draw_x                                           0x927940
#define CListWnd__DrawColumnSeparators_x                           0x92A130
#define CListWnd__DrawHeader_x                                     0x92A5A0
#define CListWnd__DrawItem_x                                       0x92AAA0
#define CListWnd__DrawLine_x                                       0x92A2A0
#define CListWnd__DrawSeparator_x                                  0x92A1D0
#define CListWnd__EnableLine_x                                     0x929A00
#define CListWnd__EnsureVisible_x                                  0x92D1E0
#define CListWnd__ExtendSel_x                                      0x92C770
#define CListWnd__GetColumnTooltip_x                               0x929540
#define CListWnd__GetColumnMinWidth_x                              0x9295B0
#define CListWnd__GetColumnWidth_x                                 0x9294B0
#define CListWnd__GetCurSel_x                                      0x928E40
#define CListWnd__GetItemAtPoint_x                                 0x929C80
#define CListWnd__GetItemAtPoint1_x                                0x929CF0
#define CListWnd__GetItemData_x                                    0x928EC0
#define CListWnd__GetItemHeight_x                                  0x929280
#define CListWnd__GetItemIcon_x                                    0x929050
#define CListWnd__GetItemRect_x                                    0x929AF0
#define CListWnd__GetItemText_x                                    0x928F00
#define CListWnd__GetSelList_x                                     0x92C8F0
#define CListWnd__GetSeparatorRect_x                               0x929F30
#define CListWnd__InsertLine_x                                     0x92C450
#define CListWnd__RemoveLine_x                                     0x92C5A0
#define CListWnd__SetColors_x                                      0x92B800
#define CListWnd__SetColumnJustification_x                         0x92B530
#define CListWnd__SetColumnWidth_x                                 0x92B450
#define CListWnd__SetCurSel_x                                      0x92C6B0
#define CListWnd__SetItemColor_x                                   0x92CE90
#define CListWnd__SetItemData_x                                    0x92CE50
#define CListWnd__SetItemText_x                                    0x92CA60
#define CListWnd__ShiftColumnSeparator_x                           0x92B5F0
#define CListWnd__Sort_x                                           0x92B2E0
#define CListWnd__ToggleSel_x                                      0x92C6E0
#define CListWnd__SetColumnsSizable_x                              0x92B6A0
#define CListWnd__SetItemWnd_x                                     0x92CD10
#define CListWnd__GetItemWnd_x                                     0x9290A0
#define CListWnd__SetItemIcon_x                                    0x92CAE0
#define CListWnd__CalculateCustomWindowPositions_x                 0x92BB40
#define CListWnd__SetVScrollPos_x                                  0x92B430

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7863C0
#define CMapViewWnd__GetWorldCoordinates_x                         0x784AD0
#define CMapViewWnd__HandleLButtonDown_x                           0x781B10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A6480
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A6D60
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A7290
#define CMerchantWnd__SelectRecoverySlot_x                         0x7AA210
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A5000
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AFDC0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A60A0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AC6D0
#define CPacketScrambler__hton_x                                   0x8AC6C0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x946360
#define CSidlManager__FindScreenPieceTemplate_x                    0x946770
#define CSidlManager__FindScreenPieceTemplate1_x                   0x946560
#define CSidlManager__CreateLabel_x                                0x807E20
#define CSidlManager__CreateXWndFromTemplate_x                     0x9496D0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9498A0
#define CSidlManager__CreateXWnd_x                                 0x807D50
#define CSidlManager__CreateHotButtonWnd_x                         0x808300

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x942E30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x942D30
#define CSidlScreenWnd__ConvertToRes_x                             0x968410
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9427D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9424C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x942590
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x942660
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9432D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9437A0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9434C0
#define CSidlScreenWnd__Init1_x                                    0x9420E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9437F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x944310
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9414F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x943E90
#define CSidlScreenWnd__StoreIniVis_x                              0x9441F0
#define CSidlScreenWnd__WndNotification_x                          0x9431E0
#define CSidlScreenWnd__GetChildItem_x                             0x943720
#define CSidlScreenWnd__HandleLButtonUp_x                          0x932FA0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FAFA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x684B10
#define CSkillMgr__GetSkillCap_x                                   0x684CF0
#define CSkillMgr__GetNameToken_x                                  0x684290
#define CSkillMgr__IsActivatedSkill_x                              0x6843D0
#define CSkillMgr__IsCombatSkill_x                                 0x684310

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x953080
#define CSliderWnd__SetValue_x                                     0x952EF0
#define CSliderWnd__SetNumTicks_x                                  0x952F50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80DEC0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95B8A0
#define CStmlWnd__CalculateHSBRange_x                              0x95C980
#define CStmlWnd__CalculateVSBRange_x                              0x95C8F0
#define CStmlWnd__CanBreakAtCharacter_x                            0x960CB0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x961940
#define CStmlWnd__ForceParseNow_x                                  0x95BE40
#define CStmlWnd__GetNextTagPiece_x                                0x960C10
#define CStmlWnd__GetSTMLText_x                                    0x506000
#define CStmlWnd__GetVisibleText_x                                 0x95BE60
#define CStmlWnd__InitializeWindowVariables_x                      0x961790
#define CStmlWnd__MakeStmlColorTag_x                               0x95AF10
#define CStmlWnd__MakeWndNotificationTag_x                         0x95AF80
#define CStmlWnd__SetSTMLText_x                                    0x959FC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x962A40
#define CStmlWnd__UpdateHistoryString_x                            0x961B50

// CTabWnd 
#define CTabWnd__Draw_x                                            0x959100
#define CTabWnd__DrawCurrentPage_x                                 0x959830
#define CTabWnd__DrawTab_x                                         0x959550
#define CTabWnd__GetCurrentPage_x                                  0x958910
#define CTabWnd__GetPageInnerRect_x                                0x958B50
#define CTabWnd__GetTabInnerRect_x                                 0x958A90
#define CTabWnd__GetTabRect_x                                      0x958940
#define CTabWnd__InsertPage_x                                      0x958D60
#define CTabWnd__SetPage_x                                         0x958BD0
#define CTabWnd__SetPageRect_x                                     0x959040
#define CTabWnd__UpdatePage_x                                      0x959410
#define CTabWnd__GetPageFromTabIndex_x                             0x959490
#define CTabWnd__GetCurrentTabIndex_x                              0x958900

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76B630
#define CPageWnd__SetTabText_x                                     0x958460

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8DA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92FEE0
#define CTextureFont__GetTextExtent_x                              0x9300A0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B7EC0
#define CHtmlComponentWnd__ValidateUri_x                           0x749DD0
#define CHtmlWnd__SetClientCallbacks_x                             0x625260
#define CHtmlWnd__AddObserver_x                                    0x625280
#define CHtmlWnd__RemoveObserver_x                                 0x6252E0
#define Window__getProgress_x                                      0x861E00
#define Window__getStatus_x                                        0x861E20
#define Window__getURI_x                                           0x861E30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96DE50

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91D070

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8360
#define CXStr__CXStr1_x                                            0x481500
#define CXStr__CXStr3_x                                            0x8FF6A0
#define CXStr__dCXStr_x                                            0x478670
#define CXStr__operator_equal_x                                    0x8FF8D0
#define CXStr__operator_equal1_x                                   0x8FF910
#define CXStr__operator_plus_equal1_x                              0x9003A0
#define CXStr__SetString_x                                         0x902290
#define CXStr__operator_char_p_x                                   0x8FFDE0
#define CXStr__GetChar_x                                           0x901BC0
#define CXStr__Delete_x                                            0x901490
#define CXStr__GetUnicode_x                                        0x901C30
#define CXStr__GetLength_x                                         0x4A8B50
#define CXStr__Mid_x                                               0x47D3C0
#define CXStr__Insert_x                                            0x901C90
#define CXStr__FindNext_x                                          0x901900

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x951340
#define CXWnd__BringToTop_x                                        0x9366B0
#define CXWnd__Center_x                                            0x936230
#define CXWnd__ClrFocus_x                                          0x936040
#define CXWnd__Destroy_x                                           0x9360F0
#define CXWnd__DoAllDrawing_x                                      0x932770
#define CXWnd__DrawChildren_x                                      0x932740
#define CXWnd__DrawColoredRect_x                                   0x932B90
#define CXWnd__DrawTooltip_x                                       0x9312B0
#define CXWnd__DrawTooltipAtPoint_x                                0x931370
#define CXWnd__GetBorderFrame_x                                    0x932A00
#define CXWnd__GetChildWndAt_x                                     0x936750
#define CXWnd__GetClientClipRect_x                                 0x9349A0
#define CXWnd__GetScreenClipRect_x                                 0x934A70
#define CXWnd__GetScreenRect_x                                     0x934C30
#define CXWnd__GetTooltipRect_x                                    0x932BE0
#define CXWnd__GetWindowTextA_x                                    0x49CA50
#define CXWnd__IsActive_x                                          0x933310
#define CXWnd__IsDescendantOf_x                                    0x9355F0
#define CXWnd__IsReallyVisible_x                                   0x935620
#define CXWnd__IsType_x                                            0x936DB0
#define CXWnd__Move_x                                              0x935680
#define CXWnd__Move1_x                                             0x935730
#define CXWnd__ProcessTransition_x                                 0x9361E0
#define CXWnd__Refade_x                                            0x9359F0
#define CXWnd__Resize_x                                            0x935C70
#define CXWnd__Right_x                                             0x936470
#define CXWnd__SetFocus_x                                          0x936000
#define CXWnd__SetFont_x                                           0x936070
#define CXWnd__SetKeyTooltip_x                                     0x936BE0
#define CXWnd__SetMouseOver_x                                      0x933B40
#define CXWnd__StartFade_x                                         0x9354E0
#define CXWnd__GetChildItem_x                                      0x9368C0
#define CXWnd__SetParent_x                                         0x9353A0
#define CXWnd__Minimize_x                                          0x935CE0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x969490

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x939580
#define CXWndManager__DrawWindows_x                                0x9395A0
#define CXWndManager__GetKeyboardFlags_x                           0x93BD80
#define CXWndManager__HandleKeyboardMsg_x                          0x93B940
#define CXWndManager__RemoveWnd_x                                  0x93BFB0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93C520

// CDBStr
#define CDBStr__GetString_x                                        0x53D120

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB800
#define EQ_Character__Cur_HP_x                                     0x4D1F20
#define EQ_Character__Cur_Mana_x                                   0x4D9630
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE870
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2340
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2490
#define EQ_Character__GetHPRegen_x                                 0x4DF3D0
#define EQ_Character__GetEnduranceRegen_x                          0x4DF9D0
#define EQ_Character__GetManaRegen_x                               0x4DFE10
#define EQ_Character__Max_Endurance_x                              0x64AE70
#define EQ_Character__Max_HP_x                                     0x4D1D50
#define EQ_Character__Max_Mana_x                                   0x64AC70
#define EQ_Character__doCombatAbility_x                            0x64D2C0
#define EQ_Character__UseSkill_x                                   0x4E1BE0
#define EQ_Character__GetConLevel_x                                0x644150
#define EQ_Character__IsExpansionFlag_x                            0x5A7DB0
#define EQ_Character__TotalEffect_x                                0x4C52C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF5C0
#define EQ_Character__SpellDuration_x                              0x4BF0F0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4CA0
#define EQ_Character__GetBaseSkill_x                               0x4D5C40
#define EQ_Character__CanUseItem_x                                 0x4D9940

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CBB00

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6613F0

//PcClient
#define PcClient__PcClient_x                                       0x641890

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9460
#define CCharacterListWnd__EnterWorld_x                            0x4B8EA0
#define CCharacterListWnd__Quit_x                                  0x4B8BF0
#define CCharacterListWnd__UpdateList_x                            0x4B9030

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6264B0
#define EQ_Item__CreateItemTagString_x                             0x8A5F10
#define EQ_Item__IsStackable_x                                     0x8AAAB0
#define EQ_Item__GetImageNum_x                                     0x8A7960
#define EQ_Item__CreateItemClient_x                                0x625680
#define EQ_Item__GetItemValue_x                                    0x8A8CA0
#define EQ_Item__ValueSellMerchant_x                               0x8AC2B0
#define EQ_Item__IsKeyRingItem_x                                   0x8AA3D0
#define EQ_Item__CanGoInBag_x                                      0x6265D0
#define EQ_Item__IsEmpty_x                                         0x8A9F10
#define EQ_Item__GetMaxItemCount_x                                 0x8A90B0
#define EQ_Item__GetHeldItem_x                                     0x8A7830
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A5890

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55B5A0
#define EQ_LoadingS__Array_x                                       0xC29B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64B7D0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B5540
#define EQ_PC__GetCombatAbility_x                                  0x8B5BB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B5C20
#define EQ_PC__GetItemRecastTimer_x                                0x64D840
#define EQ_PC__HasLoreItem_x                                       0x644960
#define EQ_PC__AlertInventoryChanged_x                             0x643A90
#define EQ_PC__GetPcZoneClient_x                                   0x66FF30
#define EQ_PC__RemoveMyAffect_x                                    0x650A70
#define EQ_PC__GetKeyRingItems_x                                   0x8B64B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B6240
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B67B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AE340
#define EQItemList__add_object_x                                   0x5DBC90
#define EQItemList__add_item_x                                     0x5AE8A0
#define EQItemList__delete_item_x                                  0x5AE8F0
#define EQItemList__FreeItemList_x                                 0x5AE7F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x539C20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x662C70
#define EQPlayer__dEQPlayer_x                                      0x655FB0
#define EQPlayer__DoAttack_x                                       0x66ABD0
#define EQPlayer__EQPlayer_x                                       0x656670
#define EQPlayer__SetNameSpriteState_x                             0x65A950
#define EQPlayer__SetNameSpriteTint_x                              0x65B820
#define PlayerBase__HasProperty_j_x                                0x99BC90
#define EQPlayer__IsTargetable_x                                   0x99C130
#define EQPlayer__CanSee_x                                         0x99BF90
#define EQPlayer__CanSee1_x                                        0x99C060
#define PlayerBase__GetVisibilityLineSegment_x                     0x99BD50

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66D9D0
#define PlayerZoneClient__GetLevel_x                               0x66FF70
#define PlayerZoneClient__IsValidTeleport_x                        0x5DCE00
#define PlayerZoneClient__LegalPlayerRace_x                        0x5549B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x665AC0
#define EQPlayerManager__GetSpawnByName_x                          0x665B70
#define EQPlayerManager__GetPlayerFromPartialName_x                0x665C00

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x629B90
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x629C10
#define KeypressHandler__AttachKeyToEqCommand_x                    0x629C50
#define KeypressHandler__ClearCommandStateArray_x                  0x62B060
#define KeypressHandler__HandleKeyDown_x                           0x62B080
#define KeypressHandler__HandleKeyUp_x                             0x62B120
#define KeypressHandler__SaveKeymapping_x                          0x62B570

// MapViewMap 
#define MapViewMap__Clear_x                                        0x782230
#define MapViewMap__SaveEx_x                                       0x7855F0
#define MapViewMap__SetZoom_x                                      0x789CB0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C9A20

// StringTable 
#define StringTable__getString_x                                   0x8C4860

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6506E0
#define PcZoneClient__RemovePetEffect_x                            0x650D10
#define PcZoneClient__HasAlternateAbility_x                        0x64AAA0
#define PcZoneClient__GetCurrentMod_x                              0x4E4CA0
#define PcZoneClient__GetModCap_x                                  0x4E4BA0
#define PcZoneClient__CanEquipItem_x                               0x64B170
#define PcZoneClient__GetItemByID_x                                0x64DCB0
#define PcZoneClient__GetItemByItemClass_x                         0x64DE00
#define PcZoneClient__RemoveBuffEffect_x                           0x650D30
#define PcZoneClient__BandolierSwap_x                              0x64BD80
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64D7E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E18B0

//IconCache
#define IconCache__GetIcon_x                                       0x722810

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71A2E0
#define CContainerMgr__CloseContainer_x                            0x71A5B0
#define CContainerMgr__OpenExperimentContainer_x                   0x71B030

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DA3E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61E650

//CLootWnd
#define CLootWnd__LootAll_x                                        0x778780
#define CLootWnd__RequestLootSlot_x                                0x7779B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57B8A0
#define EQ_Spell__SpellAffects_x                                   0x57BD10
#define EQ_Spell__SpellAffectBase_x                                0x57BAD0
#define EQ_Spell__IsStackable_x                                    0x4C9970
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C97C0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6810
#define EQ_Spell__IsSPAStacking_x                                  0x57CB60
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57C070
#define EQ_Spell__IsNoRemove_x                                     0x4C9950
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57CB70
#define __IsResEffectSpell_x                                       0x4C8D00

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACE50

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D4050

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x821180
#define CTargetWnd__WndNotification_x                              0x820A10
#define CTargetWnd__RefreshTargetBuffs_x                           0x820CE0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81FB80

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x825790

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x537690
#define CTaskManager__HandleMessage_x                              0x535B20
#define CTaskManager__GetTaskStatus_x                              0x537740
#define CTaskManager__GetElementDescription_x                      0x5377C0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x576E10
#define EqSoundManager__PlayScriptMp3_x                            0x576F70
#define EqSoundManager__SoundAssistPlay_x                          0x688A70
#define EqSoundManager__WaveInstancePlay_x                         0x687FE0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52B450

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x957970

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562FB0
#define CAltAbilityData__GetMercMaxRank_x                          0x562F40
#define CAltAbilityData__GetMaxRank_x                              0x558650

//CTargetRing
#define CTargetRing__Cast_x                                        0x61C770

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C97A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x512CD0
#define CharacterBase__CreateItemIndex_x                           0x624820
#define CharacterBase__GetItemPossession_x                         0x4FE980
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DC640
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DC6A0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x701460
#define CCastSpellWnd__IsBardSongPlaying_x                         0x701C90
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x701D40

//messages
#define msg_spell_worn_off_x                                       0x59FFD0
#define msg_new_text_x                                             0x594D80
#define __msgTokenTextParam_x                                      0x5A2500
#define msgTokenText_x                                             0x5A2750

//SpellManager
#define SpellManager__vftable_x                                    0xAEE67C
#define SpellManager__SpellManager_x                               0x68BDA0
#define Spellmanager__LoadTextSpells_x                             0x68C690
#define SpellManager__GetSpellByGroupAndRank_x                     0x68BF70

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99FC30

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x513320
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A62D0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63D090
#define ItemGlobalIndex__IsValidIndex_x                            0x513380

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D49F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D4C70

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x770FF0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71E9E0
#define CCursorAttachment__AttachToCursor1_x                       0x71EA20
#define CCursorAttachment__Deactivate_x                            0x71FA10

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94A6C0
#define CSidlManagerBase__CreatePageWnd_x                          0x949ED0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x946180
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x946110

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9676B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x967370

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x510270
#define CFindItemWnd__WndNotification_x                            0x510D50
#define CFindItemWnd__Update_x                                     0x511890
#define CFindItemWnd__PickupSelectedItem_x                         0x50FAB0

//IString
#define IString__Append_x                                          0x4F1220

//Camera
#define CDisplay__cameraType_x                                     0xE035A4
#define EverQuest__Cameras_x                                       0xEC6ACC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x518A80
#define LootFiltersManager__GetItemFilterData_x                    0x518390
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5183C0
#define LootFiltersManager__SetItemLootFilter_x                    0x5185E0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C8380

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A5880
#define CResolutionHandler__GetWindowedStyle_x                     0x6835B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7170B0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E9BE0
#define CDistillerInfo__Instance_x                                 0x8E9B80

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7371C0
#define CGroupWnd__UpdateDisplay_x                                 0x736520

//ItemBase
#define ItemBase__IsLore_x                                         0x8AA480
#define ItemBase__IsLoreEquipped_x                                 0x8AA4F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DBBF0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DBD30
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DBD90

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6786A0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67C060

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x506640

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F3110
#define FactionManagerClient__HandleFactionMessage_x               0x4F3780
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3D80
#define FactionManagerClient__GetMaxFaction_x                      0x4F3D9F
#define FactionManagerClient__GetMinFaction_x                      0x4F3D50

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FE950

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92EF30

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD60

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FEC30

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562450

//CTargetManager
#define CTargetManager__Get_x                                      0x68F5F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6786A0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8B60

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AE790

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF64160

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
