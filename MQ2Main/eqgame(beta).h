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
#define __ExpectedVersionDate                                     "Nov 29 2019"
#define __ExpectedVersionTime                                     "04:22:00"
#define __ActualVersionDate_x                                      0xB0C2B4
#define __ActualVersionTime_x                                      0xB0C2A8
#define __ActualVersionBuild_x                                     0xAF7F74

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62F610
#define __MemChecker1_x                                            0x902FD0
#define __MemChecker2_x                                            0x6BDEC0
#define __MemChecker3_x                                            0x6BDE10
#define __MemChecker4_x                                            0x859FE0
#define __EncryptPad0_x                                            0xC423E8
#define __EncryptPad1_x                                            0xCA05E8
#define __EncryptPad2_x                                            0xC52C80
#define __EncryptPad3_x                                            0xC52880
#define __EncryptPad4_x                                            0xC90C00
#define __EncryptPad5_x                                            0xF6C1C0
#define __AC1_x                                                    0x816C36
#define __AC2_x                                                    0x5E94EF
#define __AC3_x                                                    0x5F0BEF
#define __AC4_x                                                    0x5F4BC0
#define __AC5_x                                                    0x5FAECF
#define __AC6_x                                                    0x5FF4E6
#define __AC7_x                                                    0x5E8F60
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x197A2C

// Direct Input
#define DI8__Main_x                                                0xF6C1E8
#define DI8__Keyboard_x                                            0xF6C1EC
#define DI8__Mouse_x                                               0xF6C1CC
#define DI8__Mouse_Copy_x                                          0xEC53CC
#define DI8__Mouse_Check_x                                         0xF69D14
#define __AutoSkillArray_x                                         0xEC62E4
#define __Attack_x                                                 0xF6410B
#define __Autofire_x                                               0xF6410C
#define __BindList_x                                               0xC30E20
#define g_eqCommandStates_x                                        0xC31BA0
#define __Clicks_x                                                 0xEC5484
#define __CommandList_x                                            0xC32760
#define __CurrentMapLabel_x                                        0xF7CB8C
#define __CurrentSocial_x                                          0xC1A7CC
#define __DoAbilityList_x                                          0xEFBC2C
#define __do_loot_x                                                0x5B4F00
#define __DrawHandler_x                                            0x15FBF00
#define __GroupCount_x                                             0xEB7D82
#define __Guilds_x                                                 0xEBBBD8
#define __gWorld_x                                                 0xEB7BD0
#define __HWnd_x                                                   0xF6C1D0
#define __heqmain_x                                                0xF6C1A8
#define __InChatMode_x                                             0xEC53B4
#define __LastTell_x                                               0xEC7328
#define __LMouseHeldTime_x                                         0xEC54F0
#define __Mouse_x                                                  0xF6C1D4
#define __MouseLook_x                                              0xEC544A
#define __MouseEventTime_x                                         0xF64BEC
#define __gpbCommandEvent_x                                        0xEB5670
#define __NetStatusToggle_x                                        0xEC544D
#define __PCNames_x                                                0xEC68D4
#define __RangeAttackReady_x                                       0xEC65C8
#define __RMouseHeldTime_x                                         0xEC54EC
#define __RunWalkState_x                                           0xEC53B8
#define __ScreenMode_x                                             0xE03014
#define __ScreenX_x                                                0xEC536C
#define __ScreenY_x                                                0xEC5368
#define __ScreenXMax_x                                             0xEC5370
#define __ScreenYMax_x                                             0xEC5374
#define __ServerHost_x                                             0xEB58A3
#define __ServerName_x                                             0xEFBBEC
#define __ShiftKeyDown_x                                           0xEC5A44
#define __ShowNames_x                                              0xEC6784
#define __Socials_x                                                0xEFBCEC
#define __SubscriptionType_x                                       0xFC1090
#define __TargetAggroHolder_x                                      0xF7F540
#define __ZoneType_x                                               0xEC5848
#define __GroupAggro_x                                             0xF7F580
#define __LoginName_x                                              0xF6C93C
#define __Inviter_x                                                0xF64088
#define __AttackOnAssist_x                                         0xEC6740
#define __UseTellWindows_x                                         0xEC6A70
#define __gfMaxZoomCameraDistance_x                                0xB01C10
#define __gfMaxCameraDistance_x                                    0xB2E15C
#define __pulAutoRun_x                                             0xEC5468
#define __pulForward_x                                             0xEC6AA8
#define __pulBackward_x                                            0xEC6AAC
#define __pulTurnRight_x                                           0xEC6AB0
#define __pulTurnLeft_x                                            0xEC6AB4
#define __pulStrafeLeft_x                                          0xEC6AB8
#define __pulStrafeRight_x                                         0xEC6ABC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB7F78
#define instEQZoneInfo_x                                           0xEC5640
#define pinstActiveBanker_x                                        0xEB5688
#define pinstActiveCorpse_x                                        0xEB5680
#define pinstActiveGMaster_x                                       0xEB5684
#define pinstActiveMerchant_x                                      0xEB567C
#define pinstAltAdvManager_x                                       0xE041A8
#define pinstBandageTarget_x                                       0xEB5698
#define pinstCamActor_x                                            0xE03008
#define pinstCDBStr_x                                              0xE02EC4
#define pinstCDisplay_x                                            0xEB7BCC
#define pinstCEverQuest_x                                          0xF6C200
#define pinstEverQuestInfo_x                                       0xEC5360
#define pinstCharData_x                                            0xEB7D64
#define pinstCharSpawn_x                                           0xEB56D0
#define pinstControlledMissile_x                                   0xEB5BBC
#define pinstControlledPlayer_x                                    0xEB56D0
#define pinstCResolutionHandler_x                                  0x15FC130
#define pinstCSidlManager_x                                        0x15FB0C8
#define pinstCXWndManager_x                                        0x15FB0C4
#define instDynamicZone_x                                          0xEBBAB0
#define pinstDZMember_x                                            0xEBBBC0
#define pinstDZTimerInfo_x                                         0xEBBBC4
#define pinstEqLogin_x                                             0xF6C288
#define instEQMisc_x                                               0xE02E08
#define pinstEQSoundManager_x                                      0xE05178
#define pinstEQSpellStrings_x                                      0xCC5878
#define instExpeditionLeader_x                                     0xEBBAFA
#define instExpeditionName_x                                       0xEBBB3A
#define pinstGroup_x                                               0xEB7D7E
#define pinstImeManager_x                                          0x15FB0C0
#define pinstLocalPlayer_x                                         0xEB5678
#define pinstMercenaryData_x                                       0xF666DC
#define pinstMercenaryStats_x                                      0xF7F68C
#define pinstModelPlayer_x                                         0xEB5690
#define pinstPCData_x                                              0xEB7D64
#define pinstSkillMgr_x                                            0xF68848
#define pinstSpawnManager_x                                        0xF672F0
#define pinstSpellManager_x                                        0xF68A68
#define pinstSpellSets_x                                           0xF5CD34
#define pinstStringTable_x                                         0xEB7D68
#define pinstSwitchManager_x                                       0xEB5518
#define pinstTarget_x                                              0xEB56CC
#define pinstTargetObject_x                                        0xEB5758
#define pinstTargetSwitch_x                                        0xEB5BC4
#define pinstTaskMember_x                                          0xE02C98
#define pinstTrackTarget_x                                         0xEB56D4
#define pinstTradeTarget_x                                         0xEB568C
#define instTributeActive_x                                        0xE02E29
#define pinstViewActor_x                                           0xE03004
#define pinstWorldData_x                                           0xEB5BB8
#define pinstZoneAddr_x                                            0xEC58E0
#define pinstPlayerPath_x                                          0xF67388
#define pinstTargetIndicator_x                                     0xF68CD0
#define EQObject_Top_x                                             0xEB5674
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE03790
#define pinstCAchievementsWnd_x                                    0xE0378C
#define pinstCActionsWnd_x                                         0xE032DC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE02FC0
#define pinstCAdvancedLootWnd_x                                    0xE02F84
#define pinstCAdventureLeaderboardWnd_x                            0xF76360
#define pinstCAdventureRequestWnd_x                                0xF76410
#define pinstCAdventureStatsWnd_x                                  0xF764C0
#define pinstCAggroMeterWnd_x                                      0xE03044
#define pinstCAlarmWnd_x                                           0xE037EC
#define pinstCAlertHistoryWnd_x                                    0xE02FDC
#define pinstCAlertStackWnd_x                                      0xE037F4
#define pinstCAlertWnd_x                                           0xE02F64
#define pinstCAltStorageWnd_x                                      0xF76820
#define pinstCAudioTriggersWindow_x                                0xCB7BA8
#define pinstCAuraWnd_x                                            0xE02FFC
#define pinstCAvaZoneWnd_x                                         0xE03054
#define pinstCBandolierWnd_x                                       0xE0303C
#define pinstCBankWnd_x                                            0xE02FF8
#define pinstCBarterMerchantWnd_x                                  0xF77A60
#define pinstCBarterSearchWnd_x                                    0xF77B10
#define pinstCBarterWnd_x                                          0xF77BC0
#define pinstCBazaarConfirmationWnd_x                              0xE037B8
#define pinstCBazaarSearchWnd_x                                    0xE03090
#define pinstCBazaarWnd_x                                          0xE037D4
#define pinstCBlockedBuffWnd_x                                     0xE03000
#define pinstCBlockedPetBuffWnd_x                                  0xE03038
#define pinstCBodyTintWnd_x                                        0xE032EC
#define pinstCBookWnd_x                                            0xE03068
#define pinstCBreathWnd_x                                          0xE037A8
#define pinstCBuffWindowNORMAL_x                                   0xE02FE0
#define pinstCBuffWindowSHORT_x                                    0xE02FE4
#define pinstCBugReportWnd_x                                       0xE02FF0
#define pinstCButtonWnd_x                                          0x15FB330
#define pinstCCastingWnd_x                                         0xE0305C
#define pinstCCastSpellWnd_x                                       0xE037A4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE037D8
#define pinstCChatWindowManager_x                                  0xF78680
#define pinstCClaimWnd_x                                           0xF787D8
#define pinstCColorPickerWnd_x                                     0xE032E4
#define pinstCCombatAbilityWnd_x                                   0xE037E4
#define pinstCCombatSkillsSelectWnd_x                              0xE02F6C
#define pinstCCompassWnd_x                                         0xE032E0
#define pinstCConfirmationDialog_x                                 0xF7D6D8
#define pinstCContainerMgr_x                                       0xE037CC
#define pinstCContextMenuManager_x                                 0x15FB080
#define pinstCCursorAttachment_x                                   0xE0304C
#define pinstCDynamicZoneWnd_x                                     0xF78DA0
#define pinstCEditLabelWnd_x                                       0xE02FD8
#define pinstCEQMainWnd_x                                          0xF78FE8
#define pinstCEventCalendarWnd_x                                   0xE03050
#define pinstCExtendedTargetWnd_x                                  0xE0302C
#define pinstCFacePick_x                                           0xE02F7C
#define pinstCFactionWnd_x                                         0xE037C8
#define pinstCFellowshipWnd_x                                      0xF791E8
#define pinstCFileSelectionWnd_x                                   0xE03058
#define pinstCFindItemWnd_x                                        0xE037B4
#define pinstCFindLocationWnd_x                                    0xF79340
#define pinstCFriendsWnd_x                                         0xE02F80
#define pinstCGemsGameWnd_x                                        0xE037C4
#define pinstCGiveWnd_x                                            0xE037F0
#define pinstCGroupSearchFiltersWnd_x                              0xE03060
#define pinstCGroupSearchWnd_x                                     0xF79738
#define pinstCGroupWnd_x                                           0xF797E8
#define pinstCGuildBankWnd_x                                       0xEC6724
#define pinstCGuildCreationWnd_x                                   0xF79948
#define pinstCGuildMgmtWnd_x                                       0xF799F8
#define pinstCharacterCreation_x                                   0xE02F74
#define pinstCHelpWnd_x                                            0xE02FB8
#define pinstCHeritageSelectionWnd_x                               0xE02F88
#define pinstCHotButtonWnd_x                                       0xF7BB50
#define pinstCHotButtonWnd1_x                                      0xF7BB50
#define pinstCHotButtonWnd2_x                                      0xF7BB54
#define pinstCHotButtonWnd3_x                                      0xF7BB58
#define pinstCHotButtonWnd4_x                                      0xF7BB5C
#define pinstCIconSelectionWnd_x                                   0xE03048
#define pinstCInspectWnd_x                                         0xE02FB4
#define pinstCInventoryWnd_x                                       0xE02F8C
#define pinstCInvSlotMgr_x                                         0xE03788
#define pinstCItemDisplayManager_x                                 0xF7C0E0
#define pinstCItemExpTransferWnd_x                                 0xF7C210
#define pinstCItemOverflowWnd_x                                    0xE03094
#define pinstCJournalCatWnd_x                                      0xE0306C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE03030
#define pinstCKeyRingWnd_x                                         0xE02FD4
#define pinstCLargeDialogWnd_x                                     0xF7E358
#define pinstCLayoutCopyWnd_x                                      0xF7C560
#define pinstCLFGuildWnd_x                                         0xF7C610
#define pinstCLoadskinWnd_x                                        0xE037D0
#define pinstCLootFiltersCopyWnd_x                                 0xCD41A0
#define pinstCLootFiltersWnd_x                                     0xE037F8
#define pinstCLootSettingsWnd_x                                    0xE02F78
#define pinstCLootWnd_x                                            0xE03070
#define pinstCMailAddressBookWnd_x                                 0xE03798
#define pinstCMailCompositionWnd_x                                 0xE03304
#define pinstCMailIgnoreListWnd_x                                  0xE0379C
#define pinstCMailWnd_x                                            0xE032D8
#define pinstCManageLootWnd_x                                      0xE04658
#define pinstCMapToolbarWnd_x                                      0xE02FBC
#define pinstCMapViewWnd_x                                         0xE02F98
#define pinstCMarketplaceWnd_x                                     0xE02F60
#define pinstCMerchantWnd_x                                        0xE03074
#define pinstCMIZoneSelectWnd_x                                    0xF7CE48
#define pinstCMusicPlayerWnd_x                                     0xE0307C
#define pinstCNameChangeMercWnd_x                                  0xE037B0
#define pinstCNameChangePetWnd_x                                   0xE03794
#define pinstCNameChangeWnd_x                                      0xE037C0
#define pinstCNoteWnd_x                                            0xE02F9C
#define pinstCObjectPreviewWnd_x                                   0xE02F70
#define pinstCOptionsWnd_x                                         0xE02FA4
#define pinstCPetInfoWnd_x                                         0xE030A0
#define pinstCPetitionQWnd_x                                       0xE0337C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE032F0
#define pinstCPlayerWnd_x                                          0xE030A4
#define pinstCPopupWndManager_x                                    0xF7D6D8
#define pinstCProgressionSelectionWnd_x                            0xF7D788
#define pinstCPurchaseGroupWnd_x                                   0xE02FA8
#define pinstCPurchaseWnd_x                                        0xE02F90
#define pinstCPvPLeaderboardWnd_x                                  0xF7D838
#define pinstCPvPStatsWnd_x                                        0xF7D8E8
#define pinstCQuantityWnd_x                                        0xE03034
#define pinstCRaceChangeWnd_x                                      0xE037E8
#define pinstCRaidOptionsWnd_x                                     0xE03064
#define pinstCRaidWnd_x                                            0xE03378
#define pinstCRealEstateItemsWnd_x                                 0xE03784
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE03078
#define pinstCRealEstateManageWnd_x                                0xE02FB0
#define pinstCRealEstateNeighborhoodWnd_x                          0xE02FD0
#define pinstCRealEstatePlotSearchWnd_x                            0xE02FF4
#define pinstCRealEstatePurchaseWnd_x                              0xE03028
#define pinstCRespawnWnd_x                                         0xE03024
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE037A0
#define pinstCSendMoneyWnd_x                                       0xE02F68
#define pinstCServerListWnd_x                                      0xE03040
#define pinstCSkillsSelectWnd_x                                    0xE037DC
#define pinstCSkillsWnd_x                                          0xE037BC
#define pinstCSocialEditWnd_x                                      0xE02FCC
#define pinstCSocialWnd_x                                          0xE037AC
#define pinstCSpellBookWnd_x                                       0xE037E0
#define pinstCStoryWnd_x                                           0xE030A8
#define pinstCTargetOfTargetWnd_x                                  0xF7F710
#define pinstCTargetWnd_x                                          0xE03020
#define pinstCTaskOverlayWnd_x                                     0xE02FA0
#define pinstCTaskSelectWnd_x                                      0xF7F868
#define pinstCTaskManager_x                                        0xCD4AE0
#define pinstCTaskTemplateSelectWnd_x                              0xF7F918
#define pinstCTaskWnd_x                                            0xF7F9C8
#define pinstCTextEntryWnd_x                                       0xE02FE8
#define pinstCTimeLeftWnd_x                                        0xE030D4
#define pinstCTipWndCONTEXT_x                                      0xF7FBCC
#define pinstCTipWndOFDAY_x                                        0xF7FBC8
#define pinstCTitleWnd_x                                           0xF7FC78
#define pinstCTrackingWnd_x                                        0xE02F94
#define pinstCTradeskillWnd_x                                      0xF7FDE0
#define pinstCTradeWnd_x                                           0xE032F8
#define pinstCTrainWnd_x                                           0xE032F4
#define pinstCTributeBenefitWnd_x                                  0xF7FFE0
#define pinstCTributeMasterWnd_x                                   0xF80090
#define pinstCTributeTrophyWnd_x                                   0xF80140
#define pinstCVideoModesWnd_x                                      0xE030AC
#define pinstCVoiceMacroWnd_x                                      0xF69438
#define pinstCVoteResultsWnd_x                                     0xE03374
#define pinstCVoteWnd_x                                            0xE032E8
#define pinstCWebManager_x                                         0xF69AB4
#define pinstCZoneGuideWnd_x                                       0xE02FAC
#define pinstCZonePathWnd_x                                        0xE02FC4

#define pinstEQSuiteTextureLoader_x                                0xCA20C0
#define pinstItemIconCache_x                                       0xF78FA0
#define pinstLootFiltersManager_x                                  0xCD4250
#define pinstRewardSelectionWnd_x                                  0xF7E030

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B0360
#define __CastRay2_x                                               0x5B03B0
#define __ConvertItemTags_x                                        0x5CBF10
#define __CleanItemTags_x                                          0x47D110
#define __DoesFileExist_x                                          0x906110
#define __EQGetTime_x                                              0x902AA0
#define __ExecuteCmd_x                                             0x5A8BA0
#define __FixHeading_x                                             0x99EA10
#define __GameLoop_x                                               0x6BD0B0
#define __get_bearing_x                                            0x5AFED0
#define __get_melee_range_x                                        0x5B05A0
#define __GetAnimationCache_x                                      0x722310
#define __GetGaugeValueFromEQ_x                                    0x8150E0
#define __GetLabelFromEQ_x                                         0x816BC0
#define __GetXTargetType_x                                         0x9A0470
#define __HandleMouseWheel_x                                       0x6BDF70
#define __HeadingDiff_x                                            0x99EA80
#define __HelpPath_x                                               0xF647DC
#define __LoadFrontEnd_x                                           0x6BA3D0
#define __NewUIINI_x                                               0x814DB0
#define __ProcessGameEvents_x                                      0x610D50
#define __ProcessMouseEvent_x                                      0x610510
#define __SaveColors_x                                             0x551DC0
#define __STMLToText_x                                             0x941CD0
#define __ToggleKeyRingItem_x                                      0x515640
#define CMemoryMappedFile__SetFile_x                               0xA8DE30
#define CrashDetected_x                                            0x6BBE70
#define DrawNetStatus_x                                            0x63C980
#define Expansion_HoT_x                                            0xEC672C
#define Teleport_Table_Size_x                                      0xEB5760
#define Teleport_Table_x                                           0xEB5BC8
#define Util__FastTime_x                                           0x902670

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490480
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499380
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499150
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A10
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5598F0
#define AltAdvManager__IsAbilityReady_x                            0x558820
#define AltAdvManager__GetAAById_x                                 0x558A20
#define AltAdvManager__CanTrainAbility_x                           0x558A90
#define AltAdvManager__CanSeeAbility_x                             0x558DF0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA210
#define CharacterZoneClient__HasSkill_x                            0x4D5100
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6820
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE550
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAB60
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D91C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D92A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9380
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3350
#define CharacterZoneClient__BardCastBard_x                        0x4C5EB0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAC30
#define CharacterZoneClient__GetEffect_x                           0x4BAAA0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C43A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4470
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C44C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4610
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C47E0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2910
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7780
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7200

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E3A40
#define CBankWnd__WndNotification_x                                0x6E3820

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F1280

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61F410
#define CButtonWnd__CButtonWnd_x                                   0x93E0B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7113F0
#define CChatManager__InitContextMenu_x                            0x70A540
#define CChatManager__FreeChatWindow_x                             0x70FF30
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8890
#define CChatManager__SetLockedActiveChatWindow_x                  0x711070
#define CChatManager__CreateChatWindow_x                           0x710570

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E89A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x952740
#define CContextMenu__dCContextMenu_x                              0x952980
#define CContextMenu__AddMenuItem_x                                0x952990
#define CContextMenu__RemoveMenuItem_x                             0x952CA0
#define CContextMenu__RemoveAllMenuItems_x                         0x952CC0
#define CContextMenu__CheckMenuItem_x                              0x952D40
#define CContextMenu__SetMenuItem_x                                0x952BC0
#define CContextMenu__AddSeparator_x                               0x952B20

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9532E0
#define CContextMenuManager__RemoveMenu_x                          0x953350
#define CContextMenuManager__PopupMenu_x                           0x953410
#define CContextMenuManager__Flush_x                               0x953280
#define CContextMenuManager__GetMenu_x                             0x49B5A0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71CB20

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DE330
#define CChatService__GetFriendName_x                              0x8DE340

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x711C80
#define CChatWindow__Clear_x                                       0x712F50
#define CChatWindow__WndNotification_x                             0x7136E0
#define CChatWindow__AddHistory_x                                  0x712810

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94FBA0
#define CComboWnd__Draw_x                                          0x94F080
#define CComboWnd__GetCurChoice_x                                  0x94F9E0
#define CComboWnd__GetListRect_x                                   0x94F540
#define CComboWnd__GetTextRect_x                                   0x94FC10
#define CComboWnd__InsertChoice_x                                  0x94F6D0
#define CComboWnd__SetColors_x                                     0x94F6A0
#define CComboWnd__SetChoice_x                                     0x94F9B0
#define CComboWnd__GetItemCount_x                                  0x94F9F0
#define CComboWnd__GetCurChoiceText_x                              0x94FA30
#define CComboWnd__GetChoiceText_x                                 0x94FA00
#define CComboWnd__InsertChoiceAtIndex_x                           0x94F770

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71A510
#define CContainerWnd__vftable_x                                   0xB154A4
#define CContainerWnd__SetContainer_x                              0x71BA70

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54C7F0
#define CDisplay__PreZoneMainUI_x                                  0x54C800
#define CDisplay__CleanGameUI_x                                    0x551B80
#define CDisplay__GetClickedActor_x                                0x544B10
#define CDisplay__GetUserDefinedColor_x                            0x53D1D0
#define CDisplay__GetWorldFilePath_x                               0x546580
#define CDisplay__is3dON_x                                         0x541770
#define CDisplay__ReloadUI_x                                       0x54BC80
#define CDisplay__WriteTextHD2_x                                   0x541560
#define CDisplay__TrueDistance_x                                   0x548240
#define CDisplay__SetViewActor_x                                   0x544430
#define CDisplay__GetFloorHeight_x                                 0x541830
#define CDisplay__SetRenderWindow_x                                0x540190
#define CDisplay__ToggleScreenshotMode_x                           0x543F00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x972570

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x955CAF
#define CEditWnd__GetCharIndexPt_x                                 0x956BE0
#define CEditWnd__GetDisplayString_x                               0x956A90
#define CEditWnd__GetHorzOffset_x                                  0x955300
#define CEditWnd__GetLineForPrintableChar_x                        0x957D50
#define CEditWnd__GetSelStartPt_x                                  0x956E90
#define CEditWnd__GetSTMLSafeText_x                                0x9568B0
#define CEditWnd__PointFromPrintableChar_x                         0x957990
#define CEditWnd__SelectableCharFromPoint_x                        0x957B00
#define CEditWnd__SetEditable_x                                    0x956F50
#define CEditWnd__SetWindowTextA_x                                 0x956630

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FE9C0
#define CEverQuest__ClickedPlayer_x                                0x5F09D0
#define CEverQuest__CreateTargetIndicator_x                        0x60DFE0
#define CEverQuest__DeleteTargetIndicator_x                        0x60E070
#define CEverQuest__DoTellWindow_x                                 0x4E8A80
#define CEverQuest__OutputTextToLog_x                              0x4E8D00
#define CEverQuest__DropHeldItemOnGround_x                         0x5E5A10
#define CEverQuest__dsp_chat_x                                     0x4E9090
#define CEverQuest__trimName_x                                     0x60A2C0
#define CEverQuest__Emote_x                                        0x5FF220
#define CEverQuest__EnterZone_x                                    0x5F91A0
#define CEverQuest__GetBodyTypeDesc_x                              0x603B90
#define CEverQuest__GetClassDesc_x                                 0x6041D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6047D0
#define CEverQuest__GetDeityDesc_x                                 0x60C920
#define CEverQuest__GetLangDesc_x                                  0x604990
#define CEverQuest__GetRaceDesc_x                                  0x6041B0
#define CEverQuest__InterpretCmd_x                                 0x60CEF0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E9C10
#define CEverQuest__LMouseUp_x                                     0x5E7FA0
#define CEverQuest__RightClickedOnPlayer_x                         0x5EA4F0
#define CEverQuest__RMouseUp_x                                     0x5E8F20
#define CEverQuest__SetGameState_x                                 0x5E57A0
#define CEverQuest__UPCNotificationFlush_x                         0x60A1C0
#define CEverQuest__IssuePetCommand_x                              0x605D90
#define CEverQuest__ReportSuccessfulHit_x                          0x600610

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72C500
#define CGaugeWnd__CalcLinesFillRect_x                             0x72C560
#define CGaugeWnd__Draw_x                                          0x72BB80

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF340
#define CGuild__GetGuildName_x                                     0x4AE420
#define CGuild__GetGuildIndex_x                                    0x4AE7B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7479C0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61F7D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x754A10
#define CInvSlotMgr__MoveItem_x                                    0x753720
#define CInvSlotMgr__SelectSlot_x                                  0x754AE0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x751F90
#define CInvSlot__SliderComplete_x                                 0x74FCE0
#define CInvSlot__GetItemBase_x                                    0x74F650
#define CInvSlot__UpdateItem_x                                     0x74F7C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x756560
#define CInvSlotWnd__CInvSlotWnd_x                                 0x755700
#define CInvSlotWnd__HandleLButtonUp_x                             0x7560E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x810440
#define CItemDisplayWnd__UpdateStrings_x                           0x764D00
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75E9F0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75EF20
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x765310
#define CItemDisplayWnd__AboutToShow_x                             0x764950
#define CItemDisplayWnd__WndNotification_x                         0x766400
#define CItemDisplayWnd__RequestConvertItem_x                      0x765EC0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7639C0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x764770

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x848E80

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76A940

// CLabel 
#define CLabel__Draw_x                                             0x770310

// CListWnd
#define CListWnd__CListWnd_x                                       0x9281C0
#define CListWnd__dCListWnd_x                                      0x9284E0
#define CListWnd__AddColumn_x                                      0x92C970
#define CListWnd__AddColumn1_x                                     0x92C9C0
#define CListWnd__AddLine_x                                        0x92CD50
#define CListWnd__AddString_x                                      0x92CB50
#define CListWnd__CalculateFirstVisibleLine_x                      0x92C730
#define CListWnd__CalculateVSBRange_x                              0x92C510
#define CListWnd__ClearSel_x                                       0x92D530
#define CListWnd__ClearAllSel_x                                    0x92D590
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92DFB0
#define CListWnd__Compare_x                                        0x92BE40
#define CListWnd__Draw_x                                           0x928610
#define CListWnd__DrawColumnSeparators_x                           0x92AE10
#define CListWnd__DrawHeader_x                                     0x92B280
#define CListWnd__DrawItem_x                                       0x92B780
#define CListWnd__DrawLine_x                                       0x92AF80
#define CListWnd__DrawSeparator_x                                  0x92AEB0
#define CListWnd__EnableLine_x                                     0x92A6E0
#define CListWnd__EnsureVisible_x                                  0x92DED0
#define CListWnd__ExtendSel_x                                      0x92D460
#define CListWnd__GetColumnTooltip_x                               0x92A220
#define CListWnd__GetColumnMinWidth_x                              0x92A290
#define CListWnd__GetColumnWidth_x                                 0x92A190
#define CListWnd__GetCurSel_x                                      0x929B20
#define CListWnd__GetItemAtPoint_x                                 0x92A960
#define CListWnd__GetItemAtPoint1_x                                0x92A9D0
#define CListWnd__GetItemData_x                                    0x929BA0
#define CListWnd__GetItemHeight_x                                  0x929F60
#define CListWnd__GetItemIcon_x                                    0x929D30
#define CListWnd__GetItemRect_x                                    0x92A7D0
#define CListWnd__GetItemText_x                                    0x929BE0
#define CListWnd__GetSelList_x                                     0x92D5E0
#define CListWnd__GetSeparatorRect_x                               0x92AC10
#define CListWnd__InsertLine_x                                     0x92D140
#define CListWnd__RemoveLine_x                                     0x92D290
#define CListWnd__SetColors_x                                      0x92C4E0
#define CListWnd__SetColumnJustification_x                         0x92C210
#define CListWnd__SetColumnWidth_x                                 0x92C130
#define CListWnd__SetCurSel_x                                      0x92D3A0
#define CListWnd__SetItemColor_x                                   0x92DB80
#define CListWnd__SetItemData_x                                    0x92DB40
#define CListWnd__SetItemText_x                                    0x92D750
#define CListWnd__ShiftColumnSeparator_x                           0x92C2D0
#define CListWnd__Sort_x                                           0x92BFC0
#define CListWnd__ToggleSel_x                                      0x92D3D0
#define CListWnd__SetColumnsSizable_x                              0x92C380
#define CListWnd__SetItemWnd_x                                     0x92DA00
#define CListWnd__GetItemWnd_x                                     0x929D80
#define CListWnd__SetItemIcon_x                                    0x92D7D0
#define CListWnd__CalculateCustomWindowPositions_x                 0x92C830
#define CListWnd__SetVScrollPos_x                                  0x92C110

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x785AC0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7841D0
#define CMapViewWnd__HandleLButtonDown_x                           0x781210

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A5CC0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A65A0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A6AD0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A9A60
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A4820
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AF610
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A58D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8ABE60
#define CPacketScrambler__hton_x                                   0x8ABE50

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x947330
#define CSidlManager__FindScreenPieceTemplate_x                    0x947740
#define CSidlManager__FindScreenPieceTemplate1_x                   0x947530
#define CSidlManager__CreateLabel_x                                0x807860
#define CSidlManager__CreateXWndFromTemplate_x                     0x94A6A0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x94A880
#define CSidlManager__CreateXWnd_x                                 0x807790
#define CSidlManager__CreateHotButtonWnd_x                         0x807D60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x943E10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x943D10
#define CSidlScreenWnd__ConvertToRes_x                             0x9695C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9437A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x943490
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x943560
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x943630
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9442B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x944780
#define CSidlScreenWnd__GetSidlPiece_x                             0x9444A0
#define CSidlScreenWnd__Init1_x                                    0x943090
#define CSidlScreenWnd__LoadIniInfo_x                              0x9447D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x945310
#define CSidlScreenWnd__LoadSidlScreen_x                           0x942490
#define CSidlScreenWnd__StoreIniInfo_x                             0x944E90
#define CSidlScreenWnd__StoreIniVis_x                              0x9451F0
#define CSidlScreenWnd__WndNotification_x                          0x9441C0
#define CSidlScreenWnd__GetChildItem_x                             0x944700
#define CSidlScreenWnd__HandleLButtonUp_x                          0x933DF0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FAF50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x683D70
#define CSkillMgr__GetSkillCap_x                                   0x683F50
#define CSkillMgr__GetNameToken_x                                  0x6834F0
#define CSkillMgr__IsActivatedSkill_x                              0x683630
#define CSkillMgr__IsCombatSkill_x                                 0x683570

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9540D0
#define CSliderWnd__SetValue_x                                     0x953F40
#define CSliderWnd__SetNumTicks_x                                  0x953FA0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80D8C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95C970
#define CStmlWnd__CalculateHSBRange_x                              0x95DA50
#define CStmlWnd__CalculateVSBRange_x                              0x95D9C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x961D90
#define CStmlWnd__FastForwardToEndOfTag_x                          0x962A20
#define CStmlWnd__ForceParseNow_x                                  0x95CF10
#define CStmlWnd__GetNextTagPiece_x                                0x961CF0
#define CStmlWnd__GetSTMLText_x                                    0x504F20
#define CStmlWnd__GetVisibleText_x                                 0x95CF30
#define CStmlWnd__InitializeWindowVariables_x                      0x962870
#define CStmlWnd__MakeStmlColorTag_x                               0x95BFE0
#define CStmlWnd__MakeWndNotificationTag_x                         0x95C050
#define CStmlWnd__SetSTMLText_x                                    0x95B090
#define CStmlWnd__StripFirstSTMLLines_x                            0x963B20
#define CStmlWnd__UpdateHistoryString_x                            0x962C30

// CTabWnd 
#define CTabWnd__Draw_x                                            0x95A110
#define CTabWnd__DrawCurrentPage_x                                 0x95A840
#define CTabWnd__DrawTab_x                                         0x95A560
#define CTabWnd__GetCurrentPage_x                                  0x959910
#define CTabWnd__GetPageInnerRect_x                                0x959B50
#define CTabWnd__GetTabInnerRect_x                                 0x959A90
#define CTabWnd__GetTabRect_x                                      0x959940
#define CTabWnd__InsertPage_x                                      0x959D60
#define CTabWnd__SetPage_x                                         0x959BD0
#define CTabWnd__SetPageRect_x                                     0x95A050
#define CTabWnd__UpdatePage_x                                      0x95A420
#define CTabWnd__GetPageFromTabIndex_x                             0x95A4A0
#define CTabWnd__GetCurrentTabIndex_x                              0x959900

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76AD10
#define CPageWnd__SetTabText_x                                     0x959460

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8FC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x930C60
#define CTextureFont__GetTextExtent_x                              0x930E20

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B7280
#define CHtmlComponentWnd__ValidateUri_x                           0x7493B0
#define CHtmlWnd__SetClientCallbacks_x                             0x624870
#define CHtmlWnd__AddObserver_x                                    0x624890
#define CHtmlWnd__RemoveObserver_x                                 0x6248F0
#define Window__getProgress_x                                      0x8615E0
#define Window__getStatus_x                                        0x861600
#define Window__getURI_x                                           0x861610

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96F000

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91DE60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E85D0
#define CXStr__CXStr1_x                                            0x4B6390
#define CXStr__CXStr3_x                                            0x8FEBE0
#define CXStr__dCXStr_x                                            0x4787C0
#define CXStr__operator_equal_x                                    0x8FEE10
#define CXStr__operator_equal1_x                                   0x8FEE50
#define CXStr__operator_plus_equal1_x                              0x8FF8E0
#define CXStr__SetString_x                                         0x9017D0
#define CXStr__operator_char_p_x                                   0x8FF320
#define CXStr__GetChar_x                                           0x901100
#define CXStr__Delete_x                                            0x9009D0
#define CXStr__GetUnicode_x                                        0x901170
#define CXStr__GetLength_x                                         0x4A8D70
#define CXStr__Mid_x                                               0x47D4C0
#define CXStr__Insert_x                                            0x9011D0
#define CXStr__FindNext_x                                          0x900E40

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x952360
#define CXWnd__BringToTop_x                                        0x937610
#define CXWnd__Center_x                                            0x937190
#define CXWnd__ClrFocus_x                                          0x936FA0
#define CXWnd__Destroy_x                                           0x937050
#define CXWnd__DoAllDrawing_x                                      0x933580
#define CXWnd__DrawChildren_x                                      0x933550
#define CXWnd__DrawColoredRect_x                                   0x9339E0
#define CXWnd__DrawTooltip_x                                       0x932090
#define CXWnd__DrawTooltipAtPoint_x                                0x932150
#define CXWnd__GetBorderFrame_x                                    0x933840
#define CXWnd__GetChildWndAt_x                                     0x9376B0
#define CXWnd__GetClientClipRect_x                                 0x935870
#define CXWnd__GetScreenClipRect_x                                 0x935940
#define CXWnd__GetScreenRect_x                                     0x935B10
#define CXWnd__GetTooltipRect_x                                    0x933A30
#define CXWnd__GetWindowTextA_x                                    0x49CD10
#define CXWnd__IsActive_x                                          0x934170
#define CXWnd__IsDescendantOf_x                                    0x936530
#define CXWnd__IsReallyVisible_x                                   0x936560
#define CXWnd__IsType_x                                            0x937D30
#define CXWnd__Move_x                                              0x9365D0
#define CXWnd__Move1_x                                             0x936690
#define CXWnd__ProcessTransition_x                                 0x937140
#define CXWnd__Refade_x                                            0x936970
#define CXWnd__Resize_x                                            0x936C00
#define CXWnd__Right_x                                             0x9373D0
#define CXWnd__SetFocus_x                                          0x936F60
#define CXWnd__SetFont_x                                           0x936FD0
#define CXWnd__SetKeyTooltip_x                                     0x937B40
#define CXWnd__SetMouseOver_x                                      0x9349C0
#define CXWnd__StartFade_x                                         0x936410
#define CXWnd__GetChildItem_x                                      0x937820
#define CXWnd__SetParent_x                                         0x9362C0
#define CXWnd__Minimize_x                                          0x936C60

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96A640

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x93A550
#define CXWndManager__DrawWindows_x                                0x93A570
#define CXWndManager__GetKeyboardFlags_x                           0x93CD60
#define CXWndManager__HandleKeyboardMsg_x                          0x93C910
#define CXWndManager__RemoveWnd_x                                  0x93CF90
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93D4F0

// CDBStr
#define CDBStr__GetString_x                                        0x53C190

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBB40
#define EQ_Character__Cur_HP_x                                     0x4D2140
#define EQ_Character__Cur_Mana_x                                   0x4D9880
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEBA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2550
#define EQ_Character__GetFocusRangeModifier_x                      0x4B26A0
#define EQ_Character__GetHPRegen_x                                 0x4DF650
#define EQ_Character__GetEnduranceRegen_x                          0x4DFC50
#define EQ_Character__GetManaRegen_x                               0x4E0090
#define EQ_Character__Max_Endurance_x                              0x64AA70
#define EQ_Character__Max_HP_x                                     0x4D1F70
#define EQ_Character__Max_Mana_x                                   0x64A870
#define EQ_Character__doCombatAbility_x                            0x64CED0
#define EQ_Character__UseSkill_x                                   0x4E1E70
#define EQ_Character__GetConLevel_x                                0x643910
#define EQ_Character__IsExpansionFlag_x                            0x5A7360
#define EQ_Character__TotalEffect_x                                0x4C55F0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF8F0
#define EQ_Character__SpellDuration_x                              0x4BF420
#define EQ_Character__GetAdjustedSkill_x                           0x4D4EC0
#define EQ_Character__GetBaseSkill_x                               0x4D5E60
#define EQ_Character__CanUseItem_x                                 0x4D9B90

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CB180

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x660F90

//PcClient
#define PcClient__PcClient_x                                       0x641040

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9770
#define CCharacterListWnd__EnterWorld_x                            0x4B91B0
#define CCharacterListWnd__Quit_x                                  0x4B8F00
#define CCharacterListWnd__UpdateList_x                            0x4B9340

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x625AB0
#define EQ_Item__CreateItemTagString_x                             0x8A5720
#define EQ_Item__IsStackable_x                                     0x8AA280
#define EQ_Item__GetImageNum_x                                     0x8A71B0
#define EQ_Item__CreateItemClient_x                                0x624C90
#define EQ_Item__GetItemValue_x                                    0x8A84B0
#define EQ_Item__ValueSellMerchant_x                               0x8ABA40
#define EQ_Item__IsKeyRingItem_x                                   0x8A9BA0
#define EQ_Item__CanGoInBag_x                                      0x625BD0
#define EQ_Item__IsEmpty_x                                         0x8A96E0
#define EQ_Item__GetMaxItemCount_x                                 0x8A88C0
#define EQ_Item__GetHeldItem_x                                     0x8A7080
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A50A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55A600
#define EQ_LoadingS__Array_x                                       0xC29B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64B3D0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B4C60
#define EQ_PC__GetCombatAbility_x                                  0x8B52D0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B5340
#define EQ_PC__GetItemRecastTimer_x                                0x64D450
#define EQ_PC__HasLoreItem_x                                       0x6440D0
#define EQ_PC__AlertInventoryChanged_x                             0x643240
#define EQ_PC__GetPcZoneClient_x                                   0x66FAB0
#define EQ_PC__RemoveMyAffect_x                                    0x650680
#define EQ_PC__GetKeyRingItems_x                                   0x8B5BD0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B5960
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B5ED0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AD8D0
#define EQItemList__add_object_x                                   0x5DB200
#define EQItemList__add_item_x                                     0x5ADE30
#define EQItemList__delete_item_x                                  0x5ADE80
#define EQItemList__FreeItemList_x                                 0x5ADD80

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538C90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x662810
#define EQPlayer__dEQPlayer_x                                      0x655B50
#define EQPlayer__DoAttack_x                                       0x66A740
#define EQPlayer__EQPlayer_x                                       0x656210
#define EQPlayer__SetNameSpriteState_x                             0x65A4F0
#define EQPlayer__SetNameSpriteTint_x                              0x65B3C0
#define PlayerBase__HasProperty_j_x                                0x99CDB0
#define EQPlayer__IsTargetable_x                                   0x99D250
#define EQPlayer__CanSee_x                                         0x99D0B0
#define EQPlayer__CanSee1_x                                        0x99D180
#define PlayerBase__GetVisibilityLineSegment_x                     0x99CE70

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66D540
#define PlayerZoneClient__GetLevel_x                               0x66FAF0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DC380
#define PlayerZoneClient__LegalPlayerRace_x                        0x553A10

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x665660
#define EQPlayerManager__GetSpawnByName_x                          0x665710
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6657A0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6290C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x629140
#define KeypressHandler__AttachKeyToEqCommand_x                    0x629180
#define KeypressHandler__ClearCommandStateArray_x                  0x62A590
#define KeypressHandler__HandleKeyDown_x                           0x62A5B0
#define KeypressHandler__HandleKeyUp_x                             0x62A650
#define KeypressHandler__SaveKeymapping_x                          0x62AAA0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x781930
#define MapViewMap__SaveEx_x                                       0x784CF0
#define MapViewMap__SetZoom_x                                      0x7893B0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C90A0

// StringTable 
#define StringTable__getString_x                                   0x8C3E70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6502F0
#define PcZoneClient__RemovePetEffect_x                            0x650920
#define PcZoneClient__HasAlternateAbility_x                        0x64A6A0
#define PcZoneClient__GetCurrentMod_x                              0x4E4F30
#define PcZoneClient__GetModCap_x                                  0x4E4E30
#define PcZoneClient__CanEquipItem_x                               0x64AD70
#define PcZoneClient__GetItemByID_x                                0x64D8C0
#define PcZoneClient__GetItemByItemClass_x                         0x64DA10
#define PcZoneClient__RemoveBuffEffect_x                           0x650940
#define PcZoneClient__BandolierSwap_x                              0x64B990
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64D3F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E0F10

//IconCache
#define IconCache__GetIcon_x                                       0x721BB0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7196B0
#define CContainerMgr__CloseContainer_x                            0x719980
#define CContainerMgr__OpenExperimentContainer_x                   0x71A400

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D9C50

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61DBD0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x777DE0
#define CLootWnd__RequestLootSlot_x                                0x777010

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57A3E0
#define EQ_Spell__SpellAffects_x                                   0x57A850
#define EQ_Spell__SpellAffectBase_x                                0x57A610
#define EQ_Spell__IsStackable_x                                    0x4C9B50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9A30
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6A30
#define EQ_Spell__IsSPAStacking_x                                  0x57B6A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57ABB0
#define EQ_Spell__IsNoRemove_x                                     0x4C9B30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57B6B0
#define __IsResEffectSpell_x                                       0x4C9030

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD080

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D37B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x820BB0
#define CTargetWnd__WndNotification_x                              0x820440
#define CTargetWnd__RefreshTargetBuffs_x                           0x820710
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81F5C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8251B0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5366D0
#define CTaskManager__HandleMessage_x                              0x534B90
#define CTaskManager__GetTaskStatus_x                              0x536780
#define CTaskManager__GetElementDescription_x                      0x536800

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575950
#define EqSoundManager__PlayScriptMp3_x                            0x575AB0
#define EqSoundManager__SoundAssistPlay_x                          0x687CD0
#define EqSoundManager__WaveInstancePlay_x                         0x687240

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52A460

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x958970

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562080
#define CAltAbilityData__GetMercMaxRank_x                          0x562010
#define CAltAbilityData__GetMaxRank_x                              0x5576A0

//CTargetRing
#define CTargetRing__Cast_x                                        0x61BCF0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9A10
#define CharacterBase__CreateItemGlobalIndex_x                     0x511CD0
#define CharacterBase__CreateItemIndex_x                           0x623E20
#define CharacterBase__GetItemPossession_x                         0x4FDA40
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DBDC0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DBE20
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x700790
#define CCastSpellWnd__IsBardSongPlaying_x                         0x700FC0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x701070

//messages
#define msg_spell_worn_off_x                                       0x59F630
#define msg_new_text_x                                             0x5943D0
#define __msgTokenTextParam_x                                      0x5A1B60
#define msgTokenText_x                                             0x5A1DB0

//SpellManager
#define SpellManager__vftable_x                                    0xAEF4DC
#define SpellManager__SpellManager_x                               0x68B000
#define Spellmanager__LoadTextSpells_x                             0x68B8F0
#define SpellManager__GetSpellByGroupAndRank_x                     0x68B1D0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A0D60

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x512320
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A5910
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63C7E0
#define ItemGlobalIndex__IsValidIndex_x                            0x512380

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D4150
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D43D0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x770650

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71DDC0
#define CCursorAttachment__AttachToCursor1_x                       0x71DE00
#define CCursorAttachment__Deactivate_x                            0x71EDE0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94B6E0
#define CSidlManagerBase__CreatePageWnd_x                          0x94AED0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x947150
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9470E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x968850
#define CEQSuiteTextureLoader__GetTexture_x                        0x968510

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F270
#define CFindItemWnd__WndNotification_x                            0x50FD50
#define CFindItemWnd__Update_x                                     0x5108C0
#define CFindItemWnd__PickupSelectedItem_x                         0x50EAB0

//IString
#define IString__Append_x                                          0x4F0700

//Camera
#define CDisplay__cameraType_x                                     0xE030BC
#define EverQuest__Cameras_x                                       0xEC6A7C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5179E0
#define LootFiltersManager__GetItemFilterData_x                    0x5172E0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x517310
#define LootFiltersManager__SetItemLootFilter_x                    0x517530

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C7C10

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A6A40
#define CResolutionHandler__GetWindowedStyle_x                     0x682860

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x716400

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E9110
#define CDistillerInfo__Instance_x                                 0x8E90B0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x736760
#define CGroupWnd__UpdateDisplay_x                                 0x735AB0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A9C50
#define ItemBase__IsLoreEquipped_x                                 0x8A9CC0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DB160
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DB2A0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DB300

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678240
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67BBD0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505590

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2230
#define FactionManagerClient__HandleFactionMessage_x               0x4F28A0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2EA0
#define FactionManagerClient__GetMaxFaction_x                      0x4F2EBF
#define FactionManagerClient__GetMinFaction_x                      0x4F2E70

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FDA10

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92FC80

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C020

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FDD20

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x561520

//CTargetManager
#define CTargetManager__Get_x                                      0x68E870

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678240

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D80

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5ADD20

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF64110

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
