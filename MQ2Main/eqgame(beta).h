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
#define __ExpectedVersionDate                                     "Dec 13 2019"
#define __ExpectedVersionTime                                     "04:23:54"
#define __ActualVersionDate_x                                      0xB0B684
#define __ActualVersionTime_x                                      0xB0B678
#define __ActualVersionBuild_x                                     0xAF733C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6308E0
#define __MemChecker1_x                                            0x903AF0
#define __MemChecker2_x                                            0x6BFB80
#define __MemChecker3_x                                            0x6BFAD0
#define __MemChecker4_x                                            0x85A960
#define __EncryptPad0_x                                            0xC423E8
#define __EncryptPad1_x                                            0xCA05E8
#define __EncryptPad2_x                                            0xC52C80
#define __EncryptPad3_x                                            0xC52880
#define __EncryptPad4_x                                            0xC90C00
#define __EncryptPad5_x                                            0xF6C210
#define __AC1_x                                                    0x8173D6
#define __AC2_x                                                    0x5EA93F
#define __AC3_x                                                    0x5F203F
#define __AC4_x                                                    0x5F6010
#define __AC5_x                                                    0x5FC31F
#define __AC6_x                                                    0x600816
#define __AC7_x                                                    0x5EA3B0
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
#define __do_loot_x                                                0x5B62B0
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
#define __gpbCommandEvent_x                                        0xEB56C4
#define __NetStatusToggle_x                                        0xEC549D
#define __PCNames_x                                                0xEC6924
#define __RangeAttackReady_x                                       0xEC6618
#define __RMouseHeldTime_x                                         0xEC553C
#define __RunWalkState_x                                           0xEC5408
#define __ScreenMode_x                                             0xE030A4
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
#define __gfMaxZoomCameraDistance_x                                0xB00F98
#define __gfMaxCameraDistance_x                                    0xB2D334
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
#define EQObject_Top_x                                             0xEB56BC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE037E4
#define pinstCAchievementsWnd_x                                    0xE037E0
#define pinstCActionsWnd_x                                         0xE035A4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE0301C
#define pinstCAdvancedLootWnd_x                                    0xE02FD8
#define pinstCAdventureLeaderboardWnd_x                            0xF763B0
#define pinstCAdventureRequestWnd_x                                0xF76460
#define pinstCAdventureStatsWnd_x                                  0xF76510
#define pinstCAggroMeterWnd_x                                      0xE0313C
#define pinstCAlarmWnd_x                                           0xE03844
#define pinstCAlertHistoryWnd_x                                    0xE0303C
#define pinstCAlertStackWnd_x                                      0xE0384C
#define pinstCAlertWnd_x                                           0xE02FC0
#define pinstCAltStorageWnd_x                                      0xF76870
#define pinstCAudioTriggersWindow_x                                0xCB7BA8
#define pinstCAuraWnd_x                                            0xE03060
#define pinstCAvaZoneWnd_x                                         0xE02FF4
#define pinstCBandolierWnd_x                                       0xE03134
#define pinstCBankWnd_x                                            0xE0305C
#define pinstCBarterMerchantWnd_x                                  0xF77AB0
#define pinstCBarterSearchWnd_x                                    0xF77B60
#define pinstCBarterWnd_x                                          0xF77C10
#define pinstCBazaarConfirmationWnd_x                              0xE03810
#define pinstCBazaarSearchWnd_x                                    0xE03584
#define pinstCBazaarWnd_x                                          0xE03828
#define pinstCBlockedBuffWnd_x                                     0xE03064
#define pinstCBlockedPetBuffWnd_x                                  0xE030BC
#define pinstCBodyTintWnd_x                                        0xE037BC
#define pinstCBookWnd_x                                            0xE03560
#define pinstCBreathWnd_x                                          0xE037F8
#define pinstCBuffWindowNORMAL_x                                   0xE03040
#define pinstCBuffWindowSHORT_x                                    0xE03044
#define pinstCBugReportWnd_x                                       0xE03050
#define pinstCButtonWnd_x                                          0x15FB380
#define pinstCCastingWnd_x                                         0xE03554
#define pinstCCastSpellWnd_x                                       0xE037F0
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE03840
#define pinstCChatWindowManager_x                                  0xF786D0
#define pinstCClaimWnd_x                                           0xF78828
#define pinstCColorPickerWnd_x                                     0xE037B0
#define pinstCCombatAbilityWnd_x                                   0xE03838
#define pinstCCombatSkillsSelectWnd_x                              0xE02FC4
#define pinstCCompassWnd_x                                         0xE035AC
#define pinstCConfirmationDialog_x                                 0xF7D728
#define pinstCContainerMgr_x                                       0xE03834
#define pinstCContextMenuManager_x                                 0x15FB0D0
#define pinstCCursorAttachment_x                                   0xE03548
#define pinstCDynamicZoneWnd_x                                     0xF78DF0
#define pinstCEditLabelWnd_x                                       0xE03038
#define pinstCEQMainWnd_x                                          0xF79038
#define pinstCEventCalendarWnd_x                                   0xE0354C
#define pinstCExtendedTargetWnd_x                                  0xE030B0
#define pinstCFacePick_x                                           0xE02FDC
#define pinstCFactionWnd_x                                         0xE03820
#define pinstCFellowshipWnd_x                                      0xF79238
#define pinstCFileSelectionWnd_x                                   0xE03550
#define pinstCFindItemWnd_x                                        0xE0380C
#define pinstCFindLocationWnd_x                                    0xF79390
#define pinstCFriendsWnd_x                                         0xE02FD4
#define pinstCGemsGameWnd_x                                        0xE0381C
#define pinstCGiveWnd_x                                            0xE03848
#define pinstCGroupSearchFiltersWnd_x                              0xE03558
#define pinstCGroupSearchWnd_x                                     0xF79788
#define pinstCGroupWnd_x                                           0xF79838
#define pinstCGuildBankWnd_x                                       0xEC6774
#define pinstCGuildCreationWnd_x                                   0xF79998
#define pinstCGuildMgmtWnd_x                                       0xF79A48
#define pinstCharacterCreation_x                                   0xE02FCC
#define pinstCHelpWnd_x                                            0xE03010
#define pinstCHeritageSelectionWnd_x                               0xE02FEC
#define pinstCHotButtonWnd_x                                       0xF7BBA0
#define pinstCHotButtonWnd1_x                                      0xF7BBA0
#define pinstCHotButtonWnd2_x                                      0xF7BBA4
#define pinstCHotButtonWnd3_x                                      0xF7BBA8
#define pinstCHotButtonWnd4_x                                      0xF7BBAC
#define pinstCIconSelectionWnd_x                                   0xE03544
#define pinstCInspectWnd_x                                         0xE0300C
#define pinstCInventoryWnd_x                                       0xE02FE0
#define pinstCInvSlotMgr_x                                         0xE037F4
#define pinstCItemDisplayManager_x                                 0xF7C130
#define pinstCItemExpTransferWnd_x                                 0xF7C260
#define pinstCItemOverflowWnd_x                                    0xE03588
#define pinstCJournalCatWnd_x                                      0xE03564
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE030B4
#define pinstCKeyRingWnd_x                                         0xE0302C
#define pinstCLargeDialogWnd_x                                     0xF7E3A8
#define pinstCLayoutCopyWnd_x                                      0xF7C5B0
#define pinstCLFGuildWnd_x                                         0xF7C660
#define pinstCLoadskinWnd_x                                        0xE03824
#define pinstCLootFiltersCopyWnd_x                                 0xCD41F8
#define pinstCLootFiltersWnd_x                                     0xE03850
#define pinstCLootSettingsWnd_x                                    0xE02FD0
#define pinstCLootWnd_x                                            0xE03568
#define pinstCMailAddressBookWnd_x                                 0xE037FC
#define pinstCMailCompositionWnd_x                                 0xE037D8
#define pinstCMailIgnoreListWnd_x                                  0xE03800
#define pinstCMailWnd_x                                            0xE037B4
#define pinstCManageLootWnd_x                                      0xE046B0
#define pinstCMapToolbarWnd_x                                      0xE03018
#define pinstCMapViewWnd_x                                         0xE02FF0
#define pinstCMarketplaceWnd_x                                     0xE02FB8
#define pinstCMerchantWnd_x                                        0xE0356C
#define pinstCMIZoneSelectWnd_x                                    0xF7CE98
#define pinstCMusicPlayerWnd_x                                     0xE03574
#define pinstCNameChangeMercWnd_x                                  0xE03808
#define pinstCNameChangePetWnd_x                                   0xE037E8
#define pinstCNameChangeWnd_x                                      0xE03818
#define pinstCNoteWnd_x                                            0xE02FF8
#define pinstCObjectPreviewWnd_x                                   0xE02FC8
#define pinstCOptionsWnd_x                                         0xE02FFC
#define pinstCPetInfoWnd_x                                         0xE0358C
#define pinstCPetitionQWnd_x                                       0xE037D0
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE037C0
#define pinstCPlayerWnd_x                                          0xE03598
#define pinstCPopupWndManager_x                                    0xF7D728
#define pinstCProgressionSelectionWnd_x                            0xF7D7D8
#define pinstCPurchaseGroupWnd_x                                   0xE03004
#define pinstCPurchaseWnd_x                                        0xE02FE4
#define pinstCPvPLeaderboardWnd_x                                  0xF7D888
#define pinstCPvPStatsWnd_x                                        0xF7D938
#define pinstCQuantityWnd_x                                        0xE030B8
#define pinstCRaceChangeWnd_x                                      0xE0383C
#define pinstCRaidOptionsWnd_x                                     0xE0355C
#define pinstCRaidWnd_x                                            0xE037CC
#define pinstCRealEstateItemsWnd_x                                 0xE037DC
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE03570
#define pinstCRealEstateManageWnd_x                                0xE03014
#define pinstCRealEstateNeighborhoodWnd_x                          0xE03030
#define pinstCRealEstatePlotSearchWnd_x                            0xE03058
#define pinstCRealEstatePurchaseWnd_x                              0xE0309C
#define pinstCRespawnWnd_x                                         0xE0308C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE037EC
#define pinstCSendMoneyWnd_x                                       0xE02FBC
#define pinstCServerListWnd_x                                      0xE03138
#define pinstCSkillsSelectWnd_x                                    0xE0382C
#define pinstCSkillsWnd_x                                          0xE03814
#define pinstCSocialEditWnd_x                                      0xE03024
#define pinstCSocialWnd_x                                          0xE03804
#define pinstCSpellBookWnd_x                                       0xE03830
#define pinstCStoryWnd_x                                           0xE03594
#define pinstCTargetOfTargetWnd_x                                  0xF7F760
#define pinstCTargetWnd_x                                          0xE03088
#define pinstCTaskOverlayWnd_x                                     0xE03000
#define pinstCTaskSelectWnd_x                                      0xF7F8B8
#define pinstCTaskManager_x                                        0xCD4B38
#define pinstCTaskTemplateSelectWnd_x                              0xF7F968
#define pinstCTaskWnd_x                                            0xF7FA18
#define pinstCTextEntryWnd_x                                       0xE03048
#define pinstCTimeLeftWnd_x                                        0xE035A0
#define pinstCTipWndCONTEXT_x                                      0xF7FC1C
#define pinstCTipWndOFDAY_x                                        0xF7FC18
#define pinstCTitleWnd_x                                           0xF7FCC8
#define pinstCTrackingWnd_x                                        0xE02FE8
#define pinstCTradeskillWnd_x                                      0xF7FE30
#define pinstCTradeWnd_x                                           0xE037C8
#define pinstCTrainWnd_x                                           0xE037C4
#define pinstCTributeBenefitWnd_x                                  0xF80030
#define pinstCTributeMasterWnd_x                                   0xF800E0
#define pinstCTributeTrophyWnd_x                                   0xF80190
#define pinstCVideoModesWnd_x                                      0xE0359C
#define pinstCVoiceMacroWnd_x                                      0xF69488
#define pinstCVoteResultsWnd_x                                     0xE037D4
#define pinstCVoteWnd_x                                            0xE037B8
#define pinstCWebManager_x                                         0xF69B04
#define pinstCZoneGuideWnd_x                                       0xE03008
#define pinstCZonePathWnd_x                                        0xE03020

#define pinstEQSuiteTextureLoader_x                                0xCA20C0
#define pinstItemIconCache_x                                       0xF78FF0
#define pinstLootFiltersManager_x                                  0xCD42A8
#define pinstRewardSelectionWnd_x                                  0xF7E080

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B1710
#define __CastRay2_x                                               0x5B1760
#define __ConvertItemTags_x                                        0x5CD2C0
#define __CleanItemTags_x                                          0x47D0D0
#define __DoesFileExist_x                                          0x906B20
#define __EQGetTime_x                                              0x9035C0
#define __ExecuteCmd_x                                             0x5A9F60
#define __FixHeading_x                                             0x99E6B0
#define __GameLoop_x                                               0x6BED70
#define __get_bearing_x                                            0x5B1280
#define __get_melee_range_x                                        0x5B1950
#define __GetAnimationCache_x                                      0x7240D0
#define __GetGaugeValueFromEQ_x                                    0x815880
#define __GetLabelFromEQ_x                                         0x817360
#define __GetXTargetType_x                                         0x9A0100
#define __HandleMouseWheel_x                                       0x6BFC30
#define __HeadingDiff_x                                            0x99E720
#define __HelpPath_x                                               0xF6482C
#define __LoadFrontEnd_x                                           0x6BC090
#define __NewUIINI_x                                               0x815550
#define __ProcessGameEvents_x                                      0x611FD0
#define __ProcessMouseEvent_x                                      0x611790
#define __SaveColors_x                                             0x553740
#define __STMLToText_x                                             0x9419F0
#define __ToggleKeyRingItem_x                                      0x5169E0
#define CMemoryMappedFile__SetFile_x                               0xA8D960
#define CrashDetected_x                                            0x6BDB30
#define DrawNetStatus_x                                            0x63DD90
#define Expansion_HoT_x                                            0xEC677C
#define Teleport_Table_Size_x                                      0xEB57B0
#define Teleport_Table_x                                           0xEB5C28
#define Util__FastTime_x                                           0x903190

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490300
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499210
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498FE0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4938A0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492CF0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55B340
#define AltAdvManager__IsAbilityReady_x                            0x55A270
#define AltAdvManager__GetAAById_x                                 0x55A470
#define AltAdvManager__CanTrainAbility_x                           0x55A4E0
#define AltAdvManager__CanSeeAbility_x                             0x55A840

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA110
#define CharacterZoneClient__HasSkill_x                            0x4D5000
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6720
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE360
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA960
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D90B0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9190
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9270
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3160
#define CharacterZoneClient__BardCastBard_x                        0x4C5CC0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA30
#define CharacterZoneClient__GetEffect_x                           0x4BA8A0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C41B0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4280
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C42D0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4420
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C45F0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B27F0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7680
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7100

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E5750
#define CBankWnd__WndNotification_x                                0x6E5530

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F2F80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x620770
#define CButtonWnd__CButtonWnd_x                                   0x93DDE0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x713190
#define CChatManager__InitContextMenu_x                            0x70C2E0
#define CChatManager__FreeChatWindow_x                             0x711CD0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8710
#define CChatManager__SetLockedActiveChatWindow_x                  0x712E10
#define CChatManager__CreateChatWindow_x                           0x712310

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8820

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x952380
#define CContextMenu__dCContextMenu_x                              0x9525C0
#define CContextMenu__AddMenuItem_x                                0x9525D0
#define CContextMenu__RemoveMenuItem_x                             0x9528E0
#define CContextMenu__RemoveAllMenuItems_x                         0x952900
#define CContextMenu__CheckMenuItem_x                              0x952980
#define CContextMenu__SetMenuItem_x                                0x952800
#define CContextMenu__AddSeparator_x                               0x952760

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x952F20
#define CContextMenuManager__RemoveMenu_x                          0x952F90
#define CContextMenuManager__PopupMenu_x                           0x953050
#define CContextMenuManager__Flush_x                               0x952EC0
#define CContextMenuManager__GetMenu_x                             0x49B3A0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71E820

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DEB60
#define CChatService__GetFriendName_x                              0x8DEB70

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x713A00
#define CChatWindow__Clear_x                                       0x714CC0
#define CChatWindow__WndNotification_x                             0x715450
#define CChatWindow__AddHistory_x                                  0x714580

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94F7E0
#define CComboWnd__Draw_x                                          0x94ECD0
#define CComboWnd__GetCurChoice_x                                  0x94F620
#define CComboWnd__GetListRect_x                                   0x94F180
#define CComboWnd__GetTextRect_x                                   0x94F850
#define CComboWnd__InsertChoice_x                                  0x94F310
#define CComboWnd__SetColors_x                                     0x94F2E0
#define CComboWnd__SetChoice_x                                     0x94F5F0
#define CComboWnd__GetItemCount_x                                  0x94F630
#define CComboWnd__GetCurChoiceText_x                              0x94F670
#define CComboWnd__GetChoiceText_x                                 0x94F640
#define CComboWnd__InsertChoiceAtIndex_x                           0x94F3B0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71C1F0
#define CContainerWnd__vftable_x                                   0xB14874
#define CContainerWnd__SetContainer_x                              0x71D760

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54E170
#define CDisplay__PreZoneMainUI_x                                  0x54E180
#define CDisplay__CleanGameUI_x                                    0x553500
#define CDisplay__GetClickedActor_x                                0x546490
#define CDisplay__GetUserDefinedColor_x                            0x53EB50
#define CDisplay__GetWorldFilePath_x                               0x547F00
#define CDisplay__is3dON_x                                         0x5430F0
#define CDisplay__ReloadUI_x                                       0x54D600
#define CDisplay__WriteTextHD2_x                                   0x542EE0
#define CDisplay__TrueDistance_x                                   0x549BC0
#define CDisplay__SetViewActor_x                                   0x545DB0
#define CDisplay__GetFloorHeight_x                                 0x5431B0
#define CDisplay__SetRenderWindow_x                                0x541B10
#define CDisplay__ToggleScreenshotMode_x                           0x545880

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9721C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x955900
#define CEditWnd__GetCharIndexPt_x                                 0x956820
#define CEditWnd__GetDisplayString_x                               0x9566D0
#define CEditWnd__GetHorzOffset_x                                  0x954F40
#define CEditWnd__GetLineForPrintableChar_x                        0x957990
#define CEditWnd__GetSelStartPt_x                                  0x956AD0
#define CEditWnd__GetSTMLSafeText_x                                0x9564F0
#define CEditWnd__PointFromPrintableChar_x                         0x9575D0
#define CEditWnd__SelectableCharFromPoint_x                        0x957740
#define CEditWnd__SetEditable_x                                    0x956B90
#define CEditWnd__SetWindowTextA_x                                 0x956270
#define CEditWnd__ReplaceSelection_x                               0x957250
#define CEditWnd__ReplaceSelection1_x                              0x9571D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FFCF0
#define CEverQuest__ClickedPlayer_x                                0x5F1E20
#define CEverQuest__CreateTargetIndicator_x                        0x60F260
#define CEverQuest__DeleteTargetIndicator_x                        0x60F2F0
#define CEverQuest__DoTellWindow_x                                 0x4E8900
#define CEverQuest__OutputTextToLog_x                              0x4E8B80
#define CEverQuest__DropHeldItemOnGround_x                         0x5E6E60
#define CEverQuest__dsp_chat_x                                     0x4E8F10
#define CEverQuest__trimName_x                                     0x60B550
#define CEverQuest__Emote_x                                        0x600550
#define CEverQuest__EnterZone_x                                    0x5FA5F0
#define CEverQuest__GetBodyTypeDesc_x                              0x604E10
#define CEverQuest__GetClassDesc_x                                 0x605450
#define CEverQuest__GetClassThreeLetterCode_x                      0x605A50
#define CEverQuest__GetDeityDesc_x                                 0x60DBA0
#define CEverQuest__GetLangDesc_x                                  0x605C10
#define CEverQuest__GetRaceDesc_x                                  0x605430
#define CEverQuest__InterpretCmd_x                                 0x60E170
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EB060
#define CEverQuest__LMouseUp_x                                     0x5E93F0
#define CEverQuest__RightClickedOnPlayer_x                         0x5EB940
#define CEverQuest__RMouseUp_x                                     0x5EA370
#define CEverQuest__SetGameState_x                                 0x5E6BF0
#define CEverQuest__UPCNotificationFlush_x                         0x60B450
#define CEverQuest__IssuePetCommand_x                              0x607010
#define CEverQuest__ReportSuccessfulHit_x                          0x6018A0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72E2A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72E300
#define CGaugeWnd__Draw_x                                          0x72D920

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF210
#define CGuild__GetGuildName_x                                     0x4AE280
#define CGuild__GetGuildIndex_x                                    0x4AE680

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7484B0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x620B30

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7554D0
#define CInvSlotMgr__MoveItem_x                                    0x7541E0
#define CInvSlotMgr__SelectSlot_x                                  0x7555A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x752A60
#define CInvSlot__SliderComplete_x                                 0x7507C0
#define CInvSlot__GetItemBase_x                                    0x750140
#define CInvSlot__UpdateItem_x                                     0x7502B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x757020
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7561C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x756BA0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x810C20
#define CItemDisplayWnd__UpdateStrings_x                           0x765800
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75F4C0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75F9F0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x765E00
#define CItemDisplayWnd__AboutToShow_x                             0x765440
#define CItemDisplayWnd__WndNotification_x                         0x766EF0
#define CItemDisplayWnd__RequestConvertItem_x                      0x7669B0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7644A0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x765260

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x849600

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76B400

// CLabel 
#define CLabel__Draw_x                                             0x770E70

// CListWnd
#define CListWnd__CListWnd_x                                       0x927F30
#define CListWnd__dCListWnd_x                                      0x928250
#define CListWnd__AddColumn_x                                      0x92C6D0
#define CListWnd__AddColumn1_x                                     0x92C720
#define CListWnd__AddLine_x                                        0x92CAB0
#define CListWnd__AddString_x                                      0x92C8B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92C490
#define CListWnd__CalculateVSBRange_x                              0x92C280
#define CListWnd__ClearSel_x                                       0x92D290
#define CListWnd__ClearAllSel_x                                    0x92D2F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92DD00
#define CListWnd__Compare_x                                        0x92BBB0
#define CListWnd__Draw_x                                           0x928380
#define CListWnd__DrawColumnSeparators_x                           0x92AB80
#define CListWnd__DrawHeader_x                                     0x92AFF0
#define CListWnd__DrawItem_x                                       0x92B4F0
#define CListWnd__DrawLine_x                                       0x92ACF0
#define CListWnd__DrawSeparator_x                                  0x92AC20
#define CListWnd__EnableLine_x                                     0x92A450
#define CListWnd__EnsureVisible_x                                  0x92DC20
#define CListWnd__ExtendSel_x                                      0x92D1C0
#define CListWnd__GetColumnTooltip_x                               0x929F90
#define CListWnd__GetColumnMinWidth_x                              0x92A000
#define CListWnd__GetColumnWidth_x                                 0x929F00
#define CListWnd__GetCurSel_x                                      0x929890
#define CListWnd__GetItemAtPoint_x                                 0x92A6D0
#define CListWnd__GetItemAtPoint1_x                                0x92A740
#define CListWnd__GetItemData_x                                    0x929910
#define CListWnd__GetItemHeight_x                                  0x929CD0
#define CListWnd__GetItemIcon_x                                    0x929AA0
#define CListWnd__GetItemRect_x                                    0x92A540
#define CListWnd__GetItemText_x                                    0x929950
#define CListWnd__GetSelList_x                                     0x92D340
#define CListWnd__GetSeparatorRect_x                               0x92A980
#define CListWnd__InsertLine_x                                     0x92CEA0
#define CListWnd__RemoveLine_x                                     0x92CFF0
#define CListWnd__SetColors_x                                      0x92C250
#define CListWnd__SetColumnJustification_x                         0x92BF80
#define CListWnd__SetColumnWidth_x                                 0x92BEA0
#define CListWnd__SetCurSel_x                                      0x92D100
#define CListWnd__SetItemColor_x                                   0x92D8D0
#define CListWnd__SetItemData_x                                    0x92D890
#define CListWnd__SetItemText_x                                    0x92D4B0
#define CListWnd__ShiftColumnSeparator_x                           0x92C040
#define CListWnd__Sort_x                                           0x92BD30
#define CListWnd__ToggleSel_x                                      0x92D130
#define CListWnd__SetColumnsSizable_x                              0x92C0F0
#define CListWnd__SetItemWnd_x                                     0x92D760
#define CListWnd__GetItemWnd_x                                     0x929AF0
#define CListWnd__SetItemIcon_x                                    0x92D530
#define CListWnd__CalculateCustomWindowPositions_x                 0x92C590
#define CListWnd__SetVScrollPos_x                                  0x92BE80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7866C0
#define CMapViewWnd__GetWorldCoordinates_x                         0x784DD0
#define CMapViewWnd__HandleLButtonDown_x                           0x781E10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A67B0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A7090
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A75C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7AA550
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A5310
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B0110
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A63C0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AC6F0
#define CPacketScrambler__hton_x                                   0x8AC6E0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x947020
#define CSidlManager__FindScreenPieceTemplate_x                    0x947430
#define CSidlManager__FindScreenPieceTemplate1_x                   0x947220
#define CSidlManager__CreateLabel_x                                0x808050
#define CSidlManager__CreateXWndFromTemplate_x                     0x94A390
#define CSidlManager__CreateXWndFromTemplate1_x                    0x94A570
#define CSidlManager__CreateXWnd_x                                 0x807F80
#define CSidlManager__CreateHotButtonWnd_x                         0x808550

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x943B10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x943A10
#define CSidlScreenWnd__ConvertToRes_x                             0x969090
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9434A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x943190
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x943260
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x943330
#define CSidlScreenWnd__DrawSidlPiece_x                            0x943FB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x944480
#define CSidlScreenWnd__GetSidlPiece_x                             0x9441A0
#define CSidlScreenWnd__Init1_x                                    0x942D90
#define CSidlScreenWnd__LoadIniInfo_x                              0x9444D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x945000
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9421A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x944B80
#define CSidlScreenWnd__StoreIniVis_x                              0x944EE0
#define CSidlScreenWnd__WndNotification_x                          0x943EC0
#define CSidlScreenWnd__GetChildItem_x                             0x944400
#define CSidlScreenWnd__HandleLButtonUp_x                          0x933B70
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FAFA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x685890
#define CSkillMgr__GetSkillCap_x                                   0x685A70
#define CSkillMgr__GetNameToken_x                                  0x685010
#define CSkillMgr__IsActivatedSkill_x                              0x685150
#define CSkillMgr__IsCombatSkill_x                                 0x685090

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x953D10
#define CSliderWnd__SetValue_x                                     0x953B80
#define CSliderWnd__SetNumTicks_x                                  0x953BE0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80E0B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95C4F0
#define CStmlWnd__CalculateHSBRange_x                              0x95D660
#define CStmlWnd__CalculateVSBRange_x                              0x95D5E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x961990
#define CStmlWnd__FastForwardToEndOfTag_x                          0x962620
#define CStmlWnd__ForceParseNow_x                                  0x95CB30
#define CStmlWnd__GetNextTagPiece_x                                0x9618F0
#define CStmlWnd__GetSTMLText_x                                    0x5062F0
#define CStmlWnd__GetVisibleText_x                                 0x95CB50
#define CStmlWnd__InitializeWindowVariables_x                      0x962470
#define CStmlWnd__MakeStmlColorTag_x                               0x95BB60
#define CStmlWnd__MakeWndNotificationTag_x                         0x95BBD0
#define CStmlWnd__SetSTMLText_x                                    0x95AC10
#define CStmlWnd__StripFirstSTMLLines_x                            0x963720
#define CStmlWnd__UpdateHistoryString_x                            0x962830

// CTabWnd 
#define CTabWnd__Draw_x                                            0x959D60
#define CTabWnd__DrawCurrentPage_x                                 0x95A490
#define CTabWnd__DrawTab_x                                         0x95A1B0
#define CTabWnd__GetCurrentPage_x                                  0x959560
#define CTabWnd__GetPageInnerRect_x                                0x9597A0
#define CTabWnd__GetTabInnerRect_x                                 0x9596E0
#define CTabWnd__GetTabRect_x                                      0x959590
#define CTabWnd__InsertPage_x                                      0x9599B0
#define CTabWnd__SetPage_x                                         0x959820
#define CTabWnd__SetPageRect_x                                     0x959CA0
#define CTabWnd__UpdatePage_x                                      0x95A070
#define CTabWnd__GetPageFromTabIndex_x                             0x95A0F0
#define CTabWnd__GetCurrentTabIndex_x                              0x959550

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76B7D0
#define CPageWnd__SetTabText_x                                     0x9590A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8D10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9309F0
#define CTextureFont__GetTextExtent_x                              0x930BB0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B8C50
#define CHtmlComponentWnd__ValidateUri_x                           0x749EA0
#define CHtmlWnd__SetClientCallbacks_x                             0x625BC0
#define CHtmlWnd__AddObserver_x                                    0x625BE0
#define CHtmlWnd__RemoveObserver_x                                 0x625C40
#define Window__getProgress_x                                      0x861F40
#define Window__getStatus_x                                        0x861F60
#define Window__getURI_x                                           0x861F70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96EC40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91DB80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8450
#define CXStr__CXStr1_x                                            0x926590
#define CXStr__CXStr3_x                                            0x8FF6C0
#define CXStr__dCXStr_x                                            0x478770
#define CXStr__operator_equal_x                                    0x8FF8F0
#define CXStr__operator_equal1_x                                   0x8FF930
#define CXStr__operator_plus_equal1_x                              0x9003C0
#define CXStr__SetString_x                                         0x9022B0
#define CXStr__operator_char_p_x                                   0x8FFE30
#define CXStr__GetChar_x                                           0x901BE0
#define CXStr__Delete_x                                            0x9014B0
#define CXStr__GetUnicode_x                                        0x901C50
#define CXStr__GetLength_x                                         0x47D480
#define CXStr__Mid_x                                               0x47D490
#define CXStr__Insert_x                                            0x901CB0
#define CXStr__FindNext_x                                          0x901920

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x951FA0
#define CXWnd__BringToTop_x                                        0x937340
#define CXWnd__Center_x                                            0x936EC0
#define CXWnd__ClrFocus_x                                          0x936CD0
#define CXWnd__Destroy_x                                           0x936D80
#define CXWnd__DoAllDrawing_x                                      0x933300
#define CXWnd__DrawChildren_x                                      0x9332D0
#define CXWnd__DrawColoredRect_x                                   0x933760
#define CXWnd__DrawTooltip_x                                       0x931E20
#define CXWnd__DrawTooltipAtPoint_x                                0x931EE0
#define CXWnd__GetBorderFrame_x                                    0x9335C0
#define CXWnd__GetChildWndAt_x                                     0x9373E0
#define CXWnd__GetClientClipRect_x                                 0x9355D0
#define CXWnd__GetScreenClipRect_x                                 0x935670
#define CXWnd__GetScreenRect_x                                     0x935820
#define CXWnd__GetTooltipRect_x                                    0x9337B0
#define CXWnd__GetWindowTextA_x                                    0x49CAA0
#define CXWnd__IsActive_x                                          0x933EE0
#define CXWnd__IsDescendantOf_x                                    0x936230
#define CXWnd__IsReallyVisible_x                                   0x936260
#define CXWnd__IsType_x                                            0x937A60
#define CXWnd__Move_x                                              0x9362D0
#define CXWnd__Move1_x                                             0x936390
#define CXWnd__ProcessTransition_x                                 0x936E70
#define CXWnd__Refade_x                                            0x936670
#define CXWnd__Resize_x                                            0x9368F0
#define CXWnd__Right_x                                             0x937100
#define CXWnd__SetFocus_x                                          0x936C90
#define CXWnd__SetFont_x                                           0x936D00
#define CXWnd__SetKeyTooltip_x                                     0x937870
#define CXWnd__SetMouseOver_x                                      0x934720
#define CXWnd__StartFade_x                                         0x936110
#define CXWnd__GetChildItem_x                                      0x937550
#define CXWnd__SetParent_x                                         0x935FD0
#define CXWnd__Minimize_x                                          0x936960

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96A110

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x93A2D0
#define CXWndManager__DrawWindows_x                                0x93A2F0
#define CXWndManager__GetKeyboardFlags_x                           0x93CA90
#define CXWndManager__HandleKeyboardMsg_x                          0x93C640
#define CXWndManager__RemoveWnd_x                                  0x93CCB0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93D200

// CDBStr
#define CDBStr__GetString_x                                        0x53DAE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB940
#define EQ_Character__Cur_HP_x                                     0x4D2040
#define EQ_Character__Cur_Mana_x                                   0x4D9770
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE9B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2430
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2580
#define EQ_Character__GetHPRegen_x                                 0x4DF510
#define EQ_Character__GetEnduranceRegen_x                          0x4DFB10
#define EQ_Character__GetManaRegen_x                               0x4DFF50
#define EQ_Character__Max_Endurance_x                              0x64B9A0
#define EQ_Character__Max_HP_x                                     0x4D1E70
#define EQ_Character__Max_Mana_x                                   0x64B7A0
#define EQ_Character__doCombatAbility_x                            0x64DE00
#define EQ_Character__UseSkill_x                                   0x4E1D30
#define EQ_Character__GetConLevel_x                                0x644CD0
#define EQ_Character__IsExpansionFlag_x                            0x5A8730
#define EQ_Character__TotalEffect_x                                0x4C5400
#define EQ_Character__GetPCSpellAffect_x                           0x4BF700
#define EQ_Character__SpellDuration_x                              0x4BF230
#define EQ_Character__GetAdjustedSkill_x                           0x4D4DC0
#define EQ_Character__GetBaseSkill_x                               0x4D5D60
#define EQ_Character__CanUseItem_x                                 0x4D9A80

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CB9B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x662340

//PcClient
#define PcClient__PcClient_x                                       0x642400

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95B0
#define CCharacterListWnd__EnterWorld_x                            0x4B8FF0
#define CCharacterListWnd__Quit_x                                  0x4B8D40
#define CCharacterListWnd__UpdateList_x                            0x4B9180

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x626E10
#define EQ_Item__CreateItemTagString_x                             0x8A5F80
#define EQ_Item__IsStackable_x                                     0x8AAAC0
#define EQ_Item__GetImageNum_x                                     0x8A79F0
#define EQ_Item__CreateItemClient_x                                0x625FE0
#define EQ_Item__GetItemValue_x                                    0x8A8CF0
#define EQ_Item__ValueSellMerchant_x                               0x8AC2D0
#define EQ_Item__IsKeyRingItem_x                                   0x8AA3C0
#define EQ_Item__CanGoInBag_x                                      0x626F30
#define EQ_Item__IsEmpty_x                                         0x8A9F30
#define EQ_Item__GetMaxItemCount_x                                 0x8A9110
#define EQ_Item__GetHeldItem_x                                     0x8A78C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A58F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55C080
#define EQ_LoadingS__Array_x                                       0xC29B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64C300
#define EQ_PC__GetAlternateAbilityId_x                             0x8B55E0
#define EQ_PC__GetCombatAbility_x                                  0x8B5C50
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B5CC0
#define EQ_PC__GetItemRecastTimer_x                                0x64E380
#define EQ_PC__HasLoreItem_x                                       0x6454E0
#define EQ_PC__AlertInventoryChanged_x                             0x644600
#define EQ_PC__GetPcZoneClient_x                                   0x670E70
#define EQ_PC__RemoveMyAffect_x                                    0x6515C0
#define EQ_PC__GetKeyRingItems_x                                   0x8B6550
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B62E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B6850

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AEC90
#define EQItemList__add_object_x                                   0x5DC620
#define EQItemList__add_item_x                                     0x5AF1F0
#define EQItemList__delete_item_x                                  0x5AF240
#define EQItemList__FreeItemList_x                                 0x5AF140

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A660

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x663BC0
#define EQPlayer__dEQPlayer_x                                      0x656AD0
#define EQPlayer__DoAttack_x                                       0x66BB00
#define EQPlayer__EQPlayer_x                                       0x657190
#define EQPlayer__SetNameSpriteState_x                             0x65B8A0
#define EQPlayer__SetNameSpriteTint_x                              0x65C770
#define PlayerBase__HasProperty_j_x                                0x99CAC0
#define EQPlayer__IsTargetable_x                                   0x99CF60
#define EQPlayer__CanSee_x                                         0x99CDC0
#define EQPlayer__CanSee1_x                                        0x99CE90
#define PlayerBase__GetVisibilityLineSegment_x                     0x99CB80

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66E900
#define PlayerZoneClient__GetLevel_x                               0x670EB0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DD790
#define PlayerZoneClient__LegalPlayerRace_x                        0x555360

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x666990
#define EQPlayerManager__GetSpawnByName_x                          0x666A40
#define EQPlayerManager__GetPlayerFromPartialName_x                0x666AD0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62A430
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62A4B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62A4F0
#define KeypressHandler__ClearCommandStateArray_x                  0x62B900
#define KeypressHandler__HandleKeyDown_x                           0x62B920
#define KeypressHandler__HandleKeyUp_x                             0x62B9C0
#define KeypressHandler__SaveKeymapping_x                          0x62BE10

// MapViewMap 
#define MapViewMap__Clear_x                                        0x782530
#define MapViewMap__SaveEx_x                                       0x7858F0
#define MapViewMap__SetZoom_x                                      0x789FB0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C98D0

// StringTable 
#define StringTable__getString_x                                   0x8C4770

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x651230
#define PcZoneClient__RemovePetEffect_x                            0x651860
#define PcZoneClient__HasAlternateAbility_x                        0x64B5D0
#define PcZoneClient__GetCurrentMod_x                              0x4E4DF0
#define PcZoneClient__GetModCap_x                                  0x4E4CF0
#define PcZoneClient__CanEquipItem_x                               0x64BCA0
#define PcZoneClient__GetItemByID_x                                0x64E800
#define PcZoneClient__GetItemByItemClass_x                         0x64E950
#define PcZoneClient__RemoveBuffEffect_x                           0x651880
#define PcZoneClient__BandolierSwap_x                              0x64C8C0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64E320

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E2370

//IconCache
#define IconCache__GetIcon_x                                       0x723970

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71B390
#define CContainerMgr__CloseContainer_x                            0x71B660
#define CContainerMgr__OpenExperimentContainer_x                   0x71C0E0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DA6E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61EF60

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7789F0
#define CLootWnd__RequestLootSlot_x                                0x777C20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57C120
#define EQ_Spell__SpellAffects_x                                   0x57C590
#define EQ_Spell__SpellAffectBase_x                                0x57C350
#define EQ_Spell__IsStackable_x                                    0x4C9A90
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C98E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6900
#define EQ_Spell__IsSPAStacking_x                                  0x57D3E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57C8F0
#define EQ_Spell__IsNoRemove_x                                     0x4C9A70
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57D3F0
#define __IsResEffectSpell_x                                       0x4C8E40

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACDE0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D4010

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8212F0
#define CTargetWnd__WndNotification_x                              0x820B80
#define CTargetWnd__RefreshTargetBuffs_x                           0x820E50
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81FCF0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x825900

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x538090
#define CTaskManager__HandleMessage_x                              0x536530
#define CTaskManager__GetTaskStatus_x                              0x538140
#define CTaskManager__GetElementDescription_x                      0x5381C0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x577690
#define EqSoundManager__PlayScriptMp3_x                            0x5777F0
#define EqSoundManager__SoundAssistPlay_x                          0x6897D0
#define EqSoundManager__WaveInstancePlay_x                         0x688D40

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52B960

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9585B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x563A50
#define CAltAbilityData__GetMercMaxRank_x                          0x5639E0
#define CAltAbilityData__GetMaxRank_x                              0x5590F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x61D080

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C98C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x513070
#define CharacterBase__CreateItemIndex_x                           0x625170
#define CharacterBase__GetItemPossession_x                         0x4FEC30
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DC620
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DC680
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x7024D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x702D00
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x702DB0

//messages
#define msg_spell_worn_off_x                                       0x5A08C0
#define msg_new_text_x                                             0x595640
#define __msgTokenTextParam_x                                      0x5A2DF0
#define msgTokenText_x                                             0x5A3040

//SpellManager
#define SpellManager__vftable_x                                    0xAEE694
#define SpellManager__SpellManager_x                               0x68CB00
#define Spellmanager__LoadTextSpells_x                             0x68D3F0
#define SpellManager__GetSpellByGroupAndRank_x                     0x68CCD0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A09F0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5136C0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A6BA0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63DBF0
#define ItemGlobalIndex__IsValidIndex_x                            0x513720

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D49B0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D4C30

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7711B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71FAC0
#define CCursorAttachment__AttachToCursor1_x                       0x71FB00
#define CCursorAttachment__Deactivate_x                            0x720AE0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94B3D0
#define CSidlManagerBase__CreatePageWnd_x                          0x94ABC0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x946E40
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x946DD0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9682E0
#define CEQSuiteTextureLoader__GetTexture_x                        0x967FA0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x510610
#define CFindItemWnd__WndNotification_x                            0x5110F0
#define CFindItemWnd__Update_x                                     0x511C60
#define CFindItemWnd__PickupSelectedItem_x                         0x50FE50

//IString
#define IString__Append_x                                          0x4F1490

//Camera
#define CDisplay__cameraType_x                                     0xE035A8
#define EverQuest__Cameras_x                                       0xEC6ACC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x518D80
#define LootFiltersManager__GetItemFilterData_x                    0x518680
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5186B0
#define LootFiltersManager__SetItemLootFilter_x                    0x5188D0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C8680

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A6570
#define CResolutionHandler__GetWindowedStyle_x                     0x684330

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x718160

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E9CA0
#define CDistillerInfo__Instance_x                                 0x8E9C40

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x737270
#define CGroupWnd__UpdateDisplay_x                                 0x7365C0

//ItemBase
#define ItemBase__IsLore_x                                         0x8AA470
#define ItemBase__IsLoreEquipped_x                                 0x8AA4F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DC580
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DC6C0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DC720

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x679580
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67CF10

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x506970

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F3390
#define FactionManagerClient__HandleFactionMessage_x               0x4F3A00
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3FC0
#define FactionManagerClient__GetMaxFaction_x                      0x4F3FDF
#define FactionManagerClient__GetMinFaction_x                      0x4F3F90

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FEC00

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92F9A0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BDB0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FEF80

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562F00

//CTargetManager
#define CTargetManager__Get_x                                      0x690330

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x679580

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8AD0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AF0E0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF64160

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
