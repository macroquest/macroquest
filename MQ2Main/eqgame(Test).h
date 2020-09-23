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
#define __ExpectedVersionDate                                     "Sep 22 2020"
#define __ExpectedVersionTime                                     "12:12:35"
#define __ActualVersionDate_x                                      0xAF22BC
#define __ActualVersionTime_x                                      0xAF22B0
#define __ActualVersionBuild_x                                     0xAE02DC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x640870
#define __MemChecker1_x                                            0x8F33C0
#define __MemChecker2_x                                            0x6B0C50
#define __MemChecker3_x                                            0x6B0BA0
#define __MemChecker4_x                                            0x849D00
#define __EncryptPad0_x                                            0xC274E8
#define __EncryptPad1_x                                            0xC84D28
#define __EncryptPad2_x                                            0xC378B8
#define __EncryptPad3_x                                            0xC374B8
#define __EncryptPad4_x                                            0xC752C8
#define __EncryptPad5_x                                            0xF470B0
#define __AC1_x                                                    0x8088D6
#define __AC2_x                                                    0x5FA03F
#define __AC3_x                                                    0x601690
#define __AC4_x                                                    0x605640
#define __AC5_x                                                    0x60B92F
#define __AC6_x                                                    0x60FDE6
#define __AC7_x                                                    0x5F9AB0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191CDC

// Direct Input
#define DI8__Main_x                                                0xF470D0
#define DI8__Keyboard_x                                            0xF470D4
#define DI8__Mouse_x                                               0xF470EC
#define DI8__Mouse_Copy_x                                          0xEA044C
#define DI8__Mouse_Check_x                                         0xF44C04
#define __AutoSkillArray_x                                         0xEA1368
#define __Attack_x                                                 0xF3F18B
#define __Autofire_x                                               0xF3F18C
#define __BindList_x                                               0xC15F38
#define g_eqCommandStates_x                                        0xC16CB8
#define __Clicks_x                                                 0xEA0504
#define __CommandList_x                                            0xC17878
#define __CurrentMapLabel_x                                        0xF57AA4
#define __CurrentSocial_x                                          0xBFF7C8
#define __DoAbilityList_x                                          0xED6CAC
#define __do_loot_x                                                0x5C5D10
#define __DrawHandler_x                                            0x15D6A98
#define __GroupCount_x                                             0xE9B522
#define __Guilds_x                                                 0xE9F388
#define __gWorld_x                                                 0xE9B4B4
#define __HWnd_x                                                   0xF470F0
#define __heqmain_x                                                0xF47098
#define __InChatMode_x                                             0xEA0434
#define __LastTell_x                                               0xEA23A8
#define __LMouseHeldTime_x                                         0xEA0570
#define __Mouse_x                                                  0xF470BC
#define __MouseLook_x                                              0xEA04CA
#define __MouseEventTime_x                                         0xF3FC6C
#define __gpbCommandEvent_x                                        0xE98E20
#define __NetStatusToggle_x                                        0xEA04CD
#define __PCNames_x                                                0xEA1958
#define __RangeAttackReady_x                                       0xEA164C
#define __RMouseHeldTime_x                                         0xEA056C
#define __RunWalkState_x                                           0xEA0438
#define __ScreenMode_x                                             0xDE67B8
#define __ScreenX_x                                                0xEA03EC
#define __ScreenY_x                                                0xEA03E8
#define __ScreenXMax_x                                             0xEA03F0
#define __ScreenYMax_x                                             0xEA03F4
#define __ServerHost_x                                             0xE98FEB
#define __ServerName_x                                             0xED6C6C
#define __ShiftKeyDown_x                                           0xEA0AC8
#define __ShowNames_x                                              0xEA1808
#define EverQuestInfo__bSocialChanged_x                            0xED6CF4
#define __Socials_x                                                0xED6D6C
#define __SubscriptionType_x                                       0xF9BD68
#define __TargetAggroHolder_x                                      0xF5A458
#define __ZoneType_x                                               0xEA08C8
#define __GroupAggro_x                                             0xF5A498
#define __LoginName_x                                              0xF4782C
#define __Inviter_x                                                0xF3F108
#define __AttackOnAssist_x                                         0xEA17C4
#define __UseTellWindows_x                                         0xEA1AF0
#define __gfMaxZoomCameraDistance_x                                0xAE9ED8
#define __gfMaxCameraDistance_x                                    0xB12B50
#define __pulAutoRun_x                                             0xEA04E8
#define __pulForward_x                                             0xEA1B28
#define __pulBackward_x                                            0xEA1B2C
#define __pulTurnRight_x                                           0xEA1B30
#define __pulTurnLeft_x                                            0xEA1B34
#define __pulStrafeLeft_x                                          0xEA1B38
#define __pulStrafeRight_x                                         0xEA1B3C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9B720
#define instEQZoneInfo_x                                           0xEA06C0
#define pinstActiveBanker_x                                        0xE9930C
#define pinstActiveCorpse_x                                        0xE99304
#define pinstActiveGMaster_x                                       0xE99308
#define pinstActiveMerchant_x                                      0xE99300
#define pinstAltAdvManager_x                                       0xDE7950
#define pinstBandageTarget_x                                       0xE9931C
#define pinstCamActor_x                                            0xDE67A8
#define pinstCDBStr_x                                              0xDE666C
#define pinstCDisplay_x                                            0xE9B374
#define pinstCEverQuest_x                                          0xF470E8
#define pinstEverQuestInfo_x                                       0xEA03E0
#define pinstCharData_x                                            0xE9B710
#define pinstCharSpawn_x                                           0xE99354
#define pinstControlledMissile_x                                   0xE99364
#define pinstControlledPlayer_x                                    0xE99354
#define pinstCResolutionHandler_x                                  0x15D6CC8
#define pinstCSidlManager_x                                        0x15D5C60
#define pinstCXWndManager_x                                        0x15D5C5C
#define instDynamicZone_x                                          0xE9F260
#define pinstDZMember_x                                            0xE9F370
#define pinstDZTimerInfo_x                                         0xE9F374
#define pinstEqLogin_x                                             0xF47178
#define instEQMisc_x                                               0xDE65B0
#define pinstEQSoundManager_x                                      0xDE8920
#define pinstEQSpellStrings_x                                      0xCA8F68
#define instExpeditionLeader_x                                     0xE9F2AA
#define instExpeditionName_x                                       0xE9F2EA
#define pinstGroup_x                                               0xE9B51E
#define pinstImeManager_x                                          0x15D5C58
#define pinstLocalPlayer_x                                         0xE992FC
#define pinstMercenaryData_x                                       0xF41758
#define pinstMercenaryStats_x                                      0xF5A524
#define pinstModelPlayer_x                                         0xE99314
#define pinstPCData_x                                              0xE9B710
#define pinstSkillMgr_x                                            0xF438C8
#define pinstSpawnManager_x                                        0xF42370
#define pinstSpellManager_x                                        0xF43B08
#define pinstSpellSets_x                                           0xF37DB4
#define pinstStringTable_x                                         0xE9B718
#define pinstSwitchManager_x                                       0xE98CC0
#define pinstTarget_x                                              0xE99350
#define pinstTargetObject_x                                        0xE9935C
#define pinstTargetSwitch_x                                        0xE9936C
#define pinstTaskMember_x                                          0xDE6440
#define pinstTrackTarget_x                                         0xE99358
#define pinstTradeTarget_x                                         0xE99310
#define instTributeActive_x                                        0xDE65D1
#define pinstViewActor_x                                           0xDE67A4
#define pinstWorldData_x                                           0xE98E10
#define pinstZoneAddr_x                                            0xEA0960
#define pinstPlayerPath_x                                          0xF42408
#define pinstTargetIndicator_x                                     0xF43D70
#define EQObject_Top_x                                             0xE990F4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE6AEC
#define pinstCAchievementsWnd_x                                    0xDE6744
#define pinstCActionsWnd_x                                         0xDE6F80
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE6804
#define pinstCAdvancedLootWnd_x                                    0xDE679C
#define pinstCAdventureLeaderboardWnd_x                            0xF51278
#define pinstCAdventureRequestWnd_x                                0xF51328
#define pinstCAdventureStatsWnd_x                                  0xF513D8
#define pinstCAggroMeterWnd_x                                      0xDE67EC
#define pinstCAlarmWnd_x                                           0xDE676C
#define pinstCAlertHistoryWnd_x                                    0xDE687C
#define pinstCAlertStackWnd_x                                      0xDE67D4
#define pinstCAlertWnd_x                                           0xDE67E8
#define pinstCAltStorageWnd_x                                      0xF51738
#define pinstCAudioTriggersWindow_x                                0xC9B298
#define pinstCAuraWnd_x                                            0xDE67A0
#define pinstCAvaZoneWnd_x                                         0xDE6850
#define pinstCBandolierWnd_x                                       0xDE6800
#define pinstCBankWnd_x                                            0xDE6834
#define pinstCBarterMerchantWnd_x                                  0xF52978
#define pinstCBarterSearchWnd_x                                    0xF52A28
#define pinstCBarterWnd_x                                          0xF52AD8
#define pinstCBazaarConfirmationWnd_x                              0xDE6780
#define pinstCBazaarSearchWnd_x                                    0xDE6AF0
#define pinstCBazaarWnd_x                                          0xDE6750
#define pinstCBlockedBuffWnd_x                                     0xDE67C8
#define pinstCBlockedPetBuffWnd_x                                  0xDE67F0
#define pinstCBodyTintWnd_x                                        0xDE6F94
#define pinstCBookWnd_x                                            0xDE682C
#define pinstCBreathWnd_x                                          0xDE6B74
#define pinstCBuffWindowNORMAL_x                                   0xDE6794
#define pinstCBuffWindowSHORT_x                                    0xDE6798
#define pinstCBugReportWnd_x                                       0xDE6830
#define pinstCButtonWnd_x                                          0x15D5EC8
#define pinstCCastingWnd_x                                         0xDE6820
#define pinstCCastSpellWnd_x                                       0xDE6AFC
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE6FA0
#define pinstCChatWindowManager_x                                  0xF53598
#define pinstCClaimWnd_x                                           0xF536F0
#define pinstCColorPickerWnd_x                                     0xDE6A98
#define pinstCCombatAbilityWnd_x                                   0xDE6760
#define pinstCCombatSkillsSelectWnd_x                              0xDE6718
#define pinstCCompassWnd_x                                         0xDE6F84
#define pinstCConfirmationDialog_x                                 0xF585F0
#define pinstCContainerMgr_x                                       0xDE6F90
#define pinstCContextMenuManager_x                                 0x15D5C18
#define pinstCCursorAttachment_x                                   0xDE6814
#define pinstCDynamicZoneWnd_x                                     0xF53CB8
#define pinstCEditLabelWnd_x                                       0xDE6790
#define pinstCEQMainWnd_x                                          0xF53F00
#define pinstCEventCalendarWnd_x                                   0xDE6AF4
#define pinstCExtendedTargetWnd_x                                  0xDE67D0
#define pinstCFacePick_x                                           0xDE671C
#define pinstCFactionWnd_x                                         0xDE673C
#define pinstCFellowshipWnd_x                                      0xF54100
#define pinstCFileSelectionWnd_x                                   0xDE6A94
#define pinstCFindItemWnd_x                                        0xDE672C
#define pinstCFindLocationWnd_x                                    0xF54258
#define pinstCFriendsWnd_x                                         0xDE6730
#define pinstCGemsGameWnd_x                                        0xDE6738
#define pinstCGiveWnd_x                                            0xDE6770
#define pinstCGroupSearchFiltersWnd_x                              0xDE6808
#define pinstCGroupSearchWnd_x                                     0xF54650
#define pinstCGroupWnd_x                                           0xF54700
#define pinstCGuildBankWnd_x                                       0xEA17A8
#define pinstCGuildCreationWnd_x                                   0xF54860
#define pinstCGuildMgmtWnd_x                                       0xF54910
#define pinstCharacterCreation_x                                   0xDE6724
#define pinstCHelpWnd_x                                            0xDE6774
#define pinstCHeritageSelectionWnd_x                               0xDE6728
#define pinstCHotButtonWnd_x                                       0xF56A68
#define pinstCHotButtonWnd1_x                                      0xF56A68
#define pinstCHotButtonWnd2_x                                      0xF56A6C
#define pinstCHotButtonWnd3_x                                      0xF56A70
#define pinstCHotButtonWnd4_x                                      0xF56A74
#define pinstCIconSelectionWnd_x                                   0xDE6810
#define pinstCInspectWnd_x                                         0xDE67F4
#define pinstCInventoryWnd_x                                       0xDE67AC
#define pinstCInvSlotMgr_x                                         0xDE6ADC
#define pinstCItemDisplayManager_x                                 0xF56FF8
#define pinstCItemExpTransferWnd_x                                 0xF57128
#define pinstCItemOverflowWnd_x                                    0xDE6AF8
#define pinstCJournalCatWnd_x                                      0xDE6AAC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE6868
#define pinstCKeyRingWnd_x                                         0xDE681C
#define pinstCLargeDialogWnd_x                                     0xF59270
#define pinstCLayoutCopyWnd_x                                      0xF57478
#define pinstCLFGuildWnd_x                                         0xF57528
#define pinstCLoadskinWnd_x                                        0xDE6754
#define pinstCLootFiltersCopyWnd_x                                 0xCB7948
#define pinstCLootFiltersWnd_x                                     0xDE67D8
#define pinstCLootSettingsWnd_x                                    0xDE67FC
#define pinstCLootWnd_x                                            0xDE6AB0
#define pinstCMailAddressBookWnd_x                                 0xDE6AE4
#define pinstCMailCompositionWnd_x                                 0xDE6AA0
#define pinstCMailIgnoreListWnd_x                                  0xDE6AE8
#define pinstCMailWnd_x                                            0xDE6A8C
#define pinstCManageLootWnd_x                                      0xDE7E00
#define pinstCMapToolbarWnd_x                                      0xDE677C
#define pinstCMapViewWnd_x                                         0xDE6748
#define pinstCMarketplaceWnd_x                                     0xDE67DC
#define pinstCMerchantWnd_x                                        0xDE6ABC
#define pinstCMIZoneSelectWnd_x                                    0xF57D60
#define pinstCMusicPlayerWnd_x                                     0xDE6A88
#define pinstCNameChangeMercWnd_x                                  0xDE6778
#define pinstCNameChangePetWnd_x                                   0xDE674C
#define pinstCNameChangeWnd_x                                      0xDE678C
#define pinstCNoteWnd_x                                            0xDE6758
#define pinstCObjectPreviewWnd_x                                   0xDE67F8
#define pinstCOptionsWnd_x                                         0xDE6764
#define pinstCPetInfoWnd_x                                         0xDE6884
#define pinstCPetitionQWnd_x                                       0xDE6714
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE6F98
#define pinstCPlayerWnd_x                                          0xDE6878
#define pinstCPopupWndManager_x                                    0xF585F0
#define pinstCProgressionSelectionWnd_x                            0xF586A0
#define pinstCPurchaseGroupWnd_x                                   0xDE684C
#define pinstCPurchaseWnd_x                                        0xDE6824
#define pinstCPvPLeaderboardWnd_x                                  0xF58750
#define pinstCPvPStatsWnd_x                                        0xF58800
#define pinstCQuantityWnd_x                                        0xDE6864
#define pinstCRaceChangeWnd_x                                      0xDE67BC
#define pinstCRaidOptionsWnd_x                                     0xDE680C
#define pinstCRaidWnd_x                                            0xDE6AB8
#define pinstCRealEstateItemsWnd_x                                 0xDE6740
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE6F88
#define pinstCRealEstateManageWnd_x                                0xDE6854
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE6870
#define pinstCRealEstatePlotSearchWnd_x                            0xDE6A90
#define pinstCRealEstatePurchaseWnd_x                              0xDE6AA8
#define pinstCRespawnWnd_x                                         0xDE67E4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE6710
#define pinstCSendMoneyWnd_x                                       0xDE6784
#define pinstCServerListWnd_x                                      0xDE6AB4
#define pinstCSkillsSelectWnd_x                                    0xDE670C
#define pinstCSkillsWnd_x                                          0xDE6F8C
#define pinstCSocialEditWnd_x                                      0xDE6818
#define pinstCSocialWnd_x                                          0xDE6768
#define pinstCSpellBookWnd_x                                       0xDE675C
#define pinstCStoryWnd_x                                           0xDE6F7C
#define pinstCTargetOfTargetWnd_x                                  0xF5A5A8
#define pinstCTargetWnd_x                                          0xDE67E0
#define pinstCTaskOverlayWnd_x                                     0xDE6844
#define pinstCTaskSelectWnd_x                                      0xF5A700
#define pinstCTaskManager_x                                        0xCB8288
#define pinstCTaskTemplateSelectWnd_x                              0xF5A7B0
#define pinstCTaskWnd_x                                            0xF5A860
#define pinstCTextEntryWnd_x                                       0xDE6828
#define pinstCTimeLeftWnd_x                                        0xDE6708
#define pinstCTipWndCONTEXT_x                                      0xF5AA64
#define pinstCTipWndOFDAY_x                                        0xF5AA60
#define pinstCTitleWnd_x                                           0xF5AB10
#define pinstCTrackingWnd_x                                        0xDE67CC
#define pinstCTradeskillWnd_x                                      0xF5AC78
#define pinstCTradeWnd_x                                           0xDE6F9C
#define pinstCTrainWnd_x                                           0xDE6AA4
#define pinstCTributeBenefitWnd_x                                  0xF5AE78
#define pinstCTributeMasterWnd_x                                   0xF5AF28
#define pinstCTributeTrophyWnd_x                                   0xF5AFD8
#define pinstCVideoModesWnd_x                                      0xDE6874
#define pinstCVoiceMacroWnd_x                                      0xF44328
#define pinstCVoteResultsWnd_x                                     0xDE6734
#define pinstCVoteWnd_x                                            0xDE6720
#define pinstCWebManager_x                                         0xF449A4
#define pinstCZoneGuideWnd_x                                       0xDE6848
#define pinstCZonePathWnd_x                                        0xDE6860

#define pinstEQSuiteTextureLoader_x                                0xC85648
#define pinstItemIconCache_x                                       0xF53EB8
#define pinstLootFiltersManager_x                                  0xCB79F8
#define pinstRewardSelectionWnd_x                                  0xF58F48

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C1410
#define __CastRay2_x                                               0x5C1460
#define __ConvertItemTags_x                                        0x5DCF60
#define __CleanItemTags_x                                          0x47CEB0
#define __DoesFileExist_x                                          0x8F6440
#define __EQGetTime_x                                              0x8F2FF0
#define __ExecuteCmd_x                                             0x5B9D90
#define __FixHeading_x                                             0x988520
#define __FlushDxKeyboard_x                                        0x6ACAF0
#define __GameLoop_x                                               0x6AFE20
#define __get_bearing_x                                            0x5C0F70
#define __get_melee_range_x                                        0x5C1650
#define __GetAnimationCache_x                                      0x7153D0
#define __GetGaugeValueFromEQ_x                                    0x806D80
#define __GetLabelFromEQ_x                                         0x808860
#define __GetXTargetType_x                                         0x98A0B0
#define __HandleMouseWheel_x                                       0x6B0D00
#define __HeadingDiff_x                                            0x988590
#define __HelpPath_x                                               0xF3F85C
#define __LoadFrontEnd_x                                           0x6AD130
#define __NewUIINI_x                                               0x806A50
#define __ProcessGameEvents_x                                      0x621A30
#define __ProcessMouseEvent_x                                      0x6211C0
#define __SaveColors_x                                             0x55A9B0
#define __STMLToText_x                                             0x92B780
#define __ToggleKeyRingItem_x                                      0x519420
#define CMemoryMappedFile__SetFile_x                               0xA77A20
#define CrashDetected_x                                            0x6AEBE0
#define DrawNetStatus_x                                            0x64DBA0
#define Expansion_HoT_x                                            0xEA17B0
#define Teleport_Table_Size_x                                      0xE98EA8
#define Teleport_Table_x                                           0xE99370
#define Util__FastTime_x                                           0x8F2BC0
#define __CopyLayout_x                                             0x63BFC0
#define __WndProc_x                                                0x6AF0E0
#define __ProcessKeyboardEvent_x                                   0x6AE680

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4902D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4992D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4990A0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493870
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492CC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x562A90
#define AltAdvManager__IsAbilityReady_x                            0x561830
#define AltAdvManager__GetAAById_x                                 0x561BC0
#define AltAdvManager__CanTrainAbility_x                           0x561C30
#define AltAdvManager__CanSeeAbility_x                             0x561F90

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAFB0
#define CharacterZoneClient__HasSkill_x                            0x4D5E30
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7550
#define CharacterZoneClient__IsStackBlocked_x                      0x4C27D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBC60
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9F00
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9FE0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA0C0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C48C0
#define CharacterZoneClient__BardCastBard_x                        0x4C72F0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF670
#define CharacterZoneClient__GetEffect_x                           0x4BBBA0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5930
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5A00
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5A50
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5BA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5D80
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B39E0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D84B0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7F30

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D6820
#define CBankWnd__WndNotification_x                                0x6D6600

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E4190

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x928F60
#define CButtonWnd__CButtonWnd_x                                   0x927B60

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7044F0
#define CChatManager__InitContextMenu_x                            0x6FD620
#define CChatManager__FreeChatWindow_x                             0x703030
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9770
#define CChatManager__SetLockedActiveChatWindow_x                  0x704170
#define CChatManager__CreateChatWindow_x                           0x703670

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9880

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93C1A0
#define CContextMenu__dCContextMenu_x                              0x93C3E0
#define CContextMenu__AddMenuItem_x                                0x93C3F0
#define CContextMenu__RemoveMenuItem_x                             0x93C700
#define CContextMenu__RemoveAllMenuItems_x                         0x93C720
#define CContextMenu__CheckMenuItem_x                              0x93C7A0
#define CContextMenu__SetMenuItem_x                                0x93C620
#define CContextMenu__AddSeparator_x                               0x93C580

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93CD40
#define CContextMenuManager__RemoveMenu_x                          0x93CDB0
#define CContextMenuManager__PopupMenu_x                           0x93CE70
#define CContextMenuManager__Flush_x                               0x93CCE0
#define CContextMenuManager__GetMenu_x                             0x49B5D0
#define CContextMenuManager__CreateDefaultMenu_x                   0x70FCF0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CDEB0
#define CChatService__GetFriendName_x                              0x8CDEC0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x704D60
#define CChatWindow__Clear_x                                       0x706030
#define CChatWindow__WndNotification_x                             0x7067C0
#define CChatWindow__AddHistory_x                                  0x7058F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9395F0
#define CComboWnd__Draw_x                                          0x938AE0
#define CComboWnd__GetCurChoice_x                                  0x939430
#define CComboWnd__GetListRect_x                                   0x938F90
#define CComboWnd__GetTextRect_x                                   0x939660
#define CComboWnd__InsertChoice_x                                  0x939120
#define CComboWnd__SetColors_x                                     0x9390F0
#define CComboWnd__SetChoice_x                                     0x939400
#define CComboWnd__GetItemCount_x                                  0x939440
#define CComboWnd__GetCurChoiceText_x                              0x939480
#define CComboWnd__GetChoiceText_x                                 0x939450
#define CComboWnd__InsertChoiceAtIndex_x                           0x9391C0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70D710
#define CContainerWnd__vftable_x                                   0xAFB4AC
#define CContainerWnd__SetContainer_x                              0x70EC60

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x555360
#define CDisplay__PreZoneMainUI_x                                  0x555370
#define CDisplay__CleanGameUI_x                                    0x55A770
#define CDisplay__GetClickedActor_x                                0x54D7C0
#define CDisplay__GetUserDefinedColor_x                            0x545E30
#define CDisplay__GetWorldFilePath_x                               0x54F230
#define CDisplay__is3dON_x                                         0x54A420
#define CDisplay__ReloadUI_x                                       0x554870
#define CDisplay__WriteTextHD2_x                                   0x54A210
#define CDisplay__TrueDistance_x                                   0x550EF0
#define CDisplay__SetViewActor_x                                   0x54D0E0
#define CDisplay__GetFloorHeight_x                                 0x54A4E0
#define CDisplay__SetRenderWindow_x                                0x548E60
#define CDisplay__ToggleScreenshotMode_x                           0x54CBB0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95C140

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x93F6A0
#define CEditWnd__EnsureCaretVisible_x                             0x941870
#define CEditWnd__GetCaretPt_x                                     0x940820
#define CEditWnd__GetCharIndexPt_x                                 0x9405D0
#define CEditWnd__GetDisplayString_x                               0x940470
#define CEditWnd__GetHorzOffset_x                                  0x93ED40
#define CEditWnd__GetLineForPrintableChar_x                        0x941770
#define CEditWnd__GetSelStartPt_x                                  0x940880
#define CEditWnd__GetSTMLSafeText_x                                0x940290
#define CEditWnd__PointFromPrintableChar_x                         0x9413A0
#define CEditWnd__SelectableCharFromPoint_x                        0x941510
#define CEditWnd__SetEditable_x                                    0x940950
#define CEditWnd__SetWindowTextA_x                                 0x940010
#define CEditWnd__ReplaceSelection_x                               0x941010
#define CEditWnd__ReplaceSelection1_x                              0x940F90

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60F2C0
#define CEverQuest__ClickedPlayer_x                                0x601470
#define CEverQuest__CreateTargetIndicator_x                        0x61EBA0
#define CEverQuest__DeleteTargetIndicator_x                        0x61EC30
#define CEverQuest__DoTellWindow_x                                 0x4E9960
#define CEverQuest__OutputTextToLog_x                              0x4E9C30
#define CEverQuest__DropHeldItemOnGround_x                         0x5F65C0
#define CEverQuest__dsp_chat_x                                     0x4E9FC0
#define CEverQuest__trimName_x                                     0x61AD90
#define CEverQuest__Emote_x                                        0x60FB20
#define CEverQuest__EnterZone_x                                    0x609C20
#define CEverQuest__GetBodyTypeDesc_x                              0x614320
#define CEverQuest__GetClassDesc_x                                 0x614960
#define CEverQuest__GetClassThreeLetterCode_x                      0x614F60
#define CEverQuest__GetDeityDesc_x                                 0x61D3F0
#define CEverQuest__GetLangDesc_x                                  0x615120
#define CEverQuest__GetRaceDesc_x                                  0x614940
#define CEverQuest__InterpretCmd_x                                 0x61D9C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FA760
#define CEverQuest__LMouseUp_x                                     0x5F8AE0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FB040
#define CEverQuest__RMouseUp_x                                     0x5F9A70
#define CEverQuest__SetGameState_x                                 0x5F6350
#define CEverQuest__UPCNotificationFlush_x                         0x61AC90
#define CEverQuest__IssuePetCommand_x                              0x616530
#define CEverQuest__ReportSuccessfulHit_x                          0x610E70

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71F490
#define CGaugeWnd__CalcLinesFillRect_x                             0x71F4F0
#define CGaugeWnd__Draw_x                                          0x71EB10

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFCB0
#define CGuild__GetGuildName_x                                     0x4AE760
#define CGuild__GetGuildIndex_x                                    0x4AED60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x739120

//CHotButton
#define CHotButton__SetCheck_x                                     0x6303E0
#define CHotButton__SetButtonSize_x                                0x6307A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x746270
#define CInvSlotMgr__MoveItem_x                                    0x744F40
#define CInvSlotMgr__SelectSlot_x                                  0x746340

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x743730
#define CInvSlot__SliderComplete_x                                 0x741470
#define CInvSlot__GetItemBase_x                                    0x740DE0
#define CInvSlot__UpdateItem_x                                     0x740F50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x747DD0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x746F60
#define CInvSlotWnd__HandleLButtonUp_x                             0x747950

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8020D0
#define CItemDisplayWnd__UpdateStrings_x                           0x7565E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x750250
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x750780
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x756BF0
#define CItemDisplayWnd__AboutToShow_x                             0x756230
#define CItemDisplayWnd__WndNotification_x                         0x757E70
#define CItemDisplayWnd__RequestConvertItem_x                      0x7577A0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x755290
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x756050

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x832BD0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75C3B0

// CLabel 
#define CLabel__Draw_x                                             0x761E60

// CListWnd
#define CListWnd__CListWnd_x                                       0x911D30
#define CListWnd__dCListWnd_x                                      0x912050
#define CListWnd__AddColumn_x                                      0x9164C0
#define CListWnd__AddColumn1_x                                     0x916510
#define CListWnd__AddLine_x                                        0x9168A0
#define CListWnd__AddString_x                                      0x9166A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x916280
#define CListWnd__CalculateVSBRange_x                              0x916070
#define CListWnd__ClearSel_x                                       0x917080
#define CListWnd__ClearAllSel_x                                    0x9170E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x917B00
#define CListWnd__Compare_x                                        0x9159A0
#define CListWnd__Draw_x                                           0x912180
#define CListWnd__DrawColumnSeparators_x                           0x914970
#define CListWnd__DrawHeader_x                                     0x914DE0
#define CListWnd__DrawItem_x                                       0x9152E0
#define CListWnd__DrawLine_x                                       0x914AE0
#define CListWnd__DrawSeparator_x                                  0x914A10
#define CListWnd__EnableLine_x                                     0x914250
#define CListWnd__EnsureVisible_x                                  0x917A20
#define CListWnd__ExtendSel_x                                      0x916FB0
#define CListWnd__GetColumnTooltip_x                               0x913D90
#define CListWnd__GetColumnMinWidth_x                              0x913E00
#define CListWnd__GetColumnWidth_x                                 0x913D00
#define CListWnd__GetCurSel_x                                      0x913690
#define CListWnd__GetItemAtPoint_x                                 0x9144D0
#define CListWnd__GetItemAtPoint1_x                                0x914540
#define CListWnd__GetItemData_x                                    0x913710
#define CListWnd__GetItemHeight_x                                  0x913AD0
#define CListWnd__GetItemIcon_x                                    0x9138A0
#define CListWnd__GetItemRect_x                                    0x914340
#define CListWnd__GetItemText_x                                    0x913750
#define CListWnd__GetSelList_x                                     0x917130
#define CListWnd__GetSeparatorRect_x                               0x914780
#define CListWnd__InsertLine_x                                     0x916C90
#define CListWnd__RemoveLine_x                                     0x916DE0
#define CListWnd__SetColors_x                                      0x916040
#define CListWnd__SetColumnJustification_x                         0x915D70
#define CListWnd__SetColumnLabel_x                                 0x916640
#define CListWnd__SetColumnWidth_x                                 0x915C90
#define CListWnd__SetCurSel_x                                      0x916EF0
#define CListWnd__SetItemColor_x                                   0x9176D0
#define CListWnd__SetItemData_x                                    0x917690
#define CListWnd__SetItemText_x                                    0x9172A0
#define CListWnd__ShiftColumnSeparator_x                           0x915E30
#define CListWnd__Sort_x                                           0x915B20
#define CListWnd__ToggleSel_x                                      0x916F20
#define CListWnd__SetColumnsSizable_x                              0x915EE0
#define CListWnd__SetItemWnd_x                                     0x917550
#define CListWnd__GetItemWnd_x                                     0x9138F0
#define CListWnd__SetItemIcon_x                                    0x917320
#define CListWnd__CalculateCustomWindowPositions_x                 0x916380
#define CListWnd__SetVScrollPos_x                                  0x915C70

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x777570
#define CMapViewWnd__GetWorldCoordinates_x                         0x775C80
#define CMapViewWnd__HandleLButtonDown_x                           0x772CC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7978D0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7981B0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7986E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79B690
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x796440
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A1260
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7974E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89BE80
#define CPacketScrambler__hton_x                                   0x89BE70

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x930D50
#define CSidlManager__FindScreenPieceTemplate_x                    0x931160
#define CSidlManager__FindScreenPieceTemplate1_x                   0x930F50
#define CSidlManager__CreateLabel_x                                0x7F9370
#define CSidlManager__CreateXWndFromTemplate_x                     0x9340C0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x934290
#define CSidlManager__CreateXWnd_x                                 0x7F92A0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F9860

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92D830
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92D730
#define CSidlScreenWnd__ConvertToRes_x                             0x956C20
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92D220
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92CF10
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92CFE0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92D0B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92DCD0
#define CSidlScreenWnd__EnableIniStorage_x                         0x92E1A0
#define CSidlScreenWnd__GetSidlPiece_x                             0x92DEC0
#define CSidlScreenWnd__Init1_x                                    0x92CB10
#define CSidlScreenWnd__LoadIniInfo_x                              0x92E1F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92ED30
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92BF30
#define CSidlScreenWnd__StoreIniInfo_x                             0x92E8B0
#define CSidlScreenWnd__StoreIniVis_x                              0x92EC10
#define CSidlScreenWnd__WndNotification_x                          0x92DBE0
#define CSidlScreenWnd__GetChildItem_x                             0x92E120
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91D8C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D5AE8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x695D40
#define CSkillMgr__GetSkillCap_x                                   0x695F20
#define CSkillMgr__GetNameToken_x                                  0x6954C0
#define CSkillMgr__IsActivatedSkill_x                              0x695600
#define CSkillMgr__IsCombatSkill_x                                 0x695540

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93DB20
#define CSliderWnd__SetValue_x                                     0x93D990
#define CSliderWnd__SetNumTicks_x                                  0x93D9F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FF450

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x946480
#define CStmlWnd__ParseSTML_x                                      0x9477D0
#define CStmlWnd__CalculateHSBRange_x                              0x9475B0
#define CStmlWnd__CalculateVSBRange_x                              0x947520
#define CStmlWnd__CanBreakAtCharacter_x                            0x94B8E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94C570
#define CStmlWnd__ForceParseNow_x                                  0x946A70
#define CStmlWnd__GetNextTagPiece_x                                0x94B840
#define CStmlWnd__GetSTMLText_x                                    0x50A8D0
#define CStmlWnd__GetVisibleText_x                                 0x946A90
#define CStmlWnd__InitializeWindowVariables_x                      0x94C3C0
#define CStmlWnd__MakeStmlColorTag_x                               0x945AF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x945B60
#define CStmlWnd__SetSTMLText_x                                    0x944BA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x94D670
#define CStmlWnd__UpdateHistoryString_x                            0x94C780

// CTabWnd 
#define CTabWnd__Draw_x                                            0x943CE0
#define CTabWnd__DrawCurrentPage_x                                 0x944410
#define CTabWnd__DrawTab_x                                         0x944130
#define CTabWnd__GetCurrentPage_x                                  0x9434E0
#define CTabWnd__GetPageInnerRect_x                                0x943720
#define CTabWnd__GetTabInnerRect_x                                 0x943660
#define CTabWnd__GetTabRect_x                                      0x943510
#define CTabWnd__InsertPage_x                                      0x943930
#define CTabWnd__RemovePage_x                                      0x943AA0
#define CTabWnd__SetPage_x                                         0x9437A0
#define CTabWnd__SetPageRect_x                                     0x943C20
#define CTabWnd__UpdatePage_x                                      0x943FF0
#define CTabWnd__GetPageFromTabIndex_x                             0x944070
#define CTabWnd__GetCurrentTabIndex_x                              0x9434D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75C7C0
#define CPageWnd__SetTabText_x                                     0x943020
#define CPageWnd__FlashTab_x                                       0x943080

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8F60

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91A780
#define CTextureFont__GetTextExtent_x                              0x91A940

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A9FA0
#define CHtmlComponentWnd__ValidateUri_x                           0x73AB20
#define CHtmlWnd__SetClientCallbacks_x                             0x635840
#define CHtmlWnd__AddObserver_x                                    0x635860
#define CHtmlWnd__RemoveObserver_x                                 0x6358C0
#define Window__getProgress_x                                      0x851330
#define Window__getStatus_x                                        0x851350
#define Window__getURI_x                                           0x851360

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x953A30

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x907890

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9630
#define CXStr__CXStr1_x                                            0x481390
#define CXStr__CXStr3_x                                            0x8EEFB0
#define CXStr__dCXStr_x                                            0x478030
#define CXStr__operator_equal_x                                    0x8EF1E0
#define CXStr__operator_equal1_x                                   0x8EF220
#define CXStr__operator_plus_equal1_x                              0x8EFCB0
#define CXStr__SetString_x                                         0x8F1BA0
#define CXStr__operator_char_p_x                                   0x8EF6F0
#define CXStr__GetChar_x                                           0x8F14F0
#define CXStr__Delete_x                                            0x8F0DA0
#define CXStr__GetUnicode_x                                        0x8F1560
#define CXStr__GetLength_x                                         0x4A8D10
#define CXStr__Mid_x                                               0x47D260
#define CXStr__Insert_x                                            0x8F15C0
#define CXStr__FindNext_x                                          0x8F1210

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93BDB0
#define CXWnd__BringToTop_x                                        0x9210A0
#define CXWnd__Center_x                                            0x920C20
#define CXWnd__ClrFocus_x                                          0x920A40
#define CXWnd__Destroy_x                                           0x920AE0
#define CXWnd__DoAllDrawing_x                                      0x91D050
#define CXWnd__DrawChildren_x                                      0x91D020
#define CXWnd__DrawColoredRect_x                                   0x91D4B0
#define CXWnd__DrawTooltip_x                                       0x91BB60
#define CXWnd__DrawTooltipAtPoint_x                                0x91BC20
#define CXWnd__GetBorderFrame_x                                    0x91D310
#define CXWnd__GetChildWndAt_x                                     0x921140
#define CXWnd__GetClientClipRect_x                                 0x91F2C0
#define CXWnd__GetScreenClipRect_x                                 0x91F390
#define CXWnd__GetScreenRect_x                                     0x91F560
#define CXWnd__GetRelativeRect_x                                   0x91F630
#define CXWnd__GetTooltipRect_x                                    0x91D500
#define CXWnd__GetWindowTextA_x                                    0x49CCC0
#define CXWnd__IsActive_x                                          0x91DC40
#define CXWnd__IsDescendantOf_x                                    0x91FF90
#define CXWnd__IsReallyVisible_x                                   0x91FFC0
#define CXWnd__IsType_x                                            0x9217B0
#define CXWnd__Move_x                                              0x920020
#define CXWnd__Move1_x                                             0x9200D0
#define CXWnd__ProcessTransition_x                                 0x920BD0
#define CXWnd__Refade_x                                            0x9203B0
#define CXWnd__Resize_x                                            0x920650
#define CXWnd__Right_x                                             0x920E60
#define CXWnd__SetFocus_x                                          0x920A00
#define CXWnd__SetFont_x                                           0x920A70
#define CXWnd__SetKeyTooltip_x                                     0x9215D0
#define CXWnd__SetMouseOver_x                                      0x91E480
#define CXWnd__StartFade_x                                         0x91FE70
#define CXWnd__GetChildItem_x                                      0x9212B0
#define CXWnd__SetParent_x                                         0x91FD20
#define CXWnd__Minimize_x                                          0x9206C0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x957CA0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x924040
#define CXWndManager__DrawWindows_x                                0x924060
#define CXWndManager__GetKeyboardFlags_x                           0x926780
#define CXWndManager__HandleKeyboardMsg_x                          0x926330
#define CXWndManager__RemoveWnd_x                                  0x9269B0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x926F30

// CDBStr
#define CDBStr__GetString_x                                        0x544DE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFDD0
#define EQ_Character__Cur_HP_x                                     0x4D2E70
#define EQ_Character__Cur_Mana_x                                   0x4DA5C0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2E40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3620
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3770
#define EQ_Character__GetHPRegen_x                                 0x4E0400
#define EQ_Character__GetEnduranceRegen_x                          0x4E0A00
#define EQ_Character__GetManaRegen_x                               0x4E0E40
#define EQ_Character__Max_Endurance_x                              0x65C140
#define EQ_Character__Max_HP_x                                     0x4D2CA0
#define EQ_Character__Max_Mana_x                                   0x65BF40
#define EQ_Character__doCombatAbility_x                            0x65E520
#define EQ_Character__UseSkill_x                                   0x4E2C40
#define EQ_Character__GetConLevel_x                                0x654AC0
#define EQ_Character__IsExpansionFlag_x                            0x5B8570
#define EQ_Character__TotalEffect_x                                0x4C6BE0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3B90
#define EQ_Character__SpellDuration_x                              0x4C36C0
#define EQ_Character__MySpellDuration_x                            0x4B1F50
#define EQ_Character__GetAdjustedSkill_x                           0x4D5BF0
#define EQ_Character__GetBaseSkill_x                               0x4D6B90
#define EQ_Character__CanUseItem_x                                 0x4DA8D0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BAEB0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6724E0

//PcClient
#define PcClient__vftable_x                                        0xAEEF34
#define PcClient__PcClient_x                                       0x652220

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA810
#define CCharacterListWnd__EnterWorld_x                            0x4BA1E0
#define CCharacterListWnd__Quit_x                                  0x4B9F30
#define CCharacterListWnd__UpdateList_x                            0x4BA3D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x636A00
#define EQ_Item__CreateItemTagString_x                             0x895470
#define EQ_Item__IsStackable_x                                     0x89A110
#define EQ_Item__GetImageNum_x                                     0x896FF0
#define EQ_Item__CreateItemClient_x                                0x635C40
#define EQ_Item__GetItemValue_x                                    0x8982F0
#define EQ_Item__ValueSellMerchant_x                               0x89BA60
#define EQ_Item__IsKeyRingItem_x                                   0x899A30
#define EQ_Item__CanGoInBag_x                                      0x636B20
#define EQ_Item__IsEmpty_x                                         0x899570
#define EQ_Item__GetMaxItemCount_x                                 0x898700
#define EQ_Item__GetHeldItem_x                                     0x896EC0
#define EQ_Item__GetAugmentFitBySlot_x                             0x894CD0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x563770
#define EQ_LoadingS__Array_x                                       0xC0EC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65CA40
#define EQ_PC__GetAlternateAbilityId_x                             0x8A4A90
#define EQ_PC__GetCombatAbility_x                                  0x8A5100
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A5170
#define EQ_PC__GetItemRecastTimer_x                                0x65EAA0
#define EQ_PC__HasLoreItem_x                                       0x6552D0
#define EQ_PC__AlertInventoryChanged_x                             0x6543F0
#define EQ_PC__GetPcZoneClient_x                                   0x681450
#define EQ_PC__RemoveMyAffect_x                                    0x661CD0
#define EQ_PC__GetKeyRingItems_x                                   0x8A5A00
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A5790
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A5D00

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BE990
#define EQItemList__add_object_x                                   0x5EBE20
#define EQItemList__add_item_x                                     0x5BEEF0
#define EQItemList__delete_item_x                                  0x5BEF40
#define EQItemList__FreeItemList_x                                 0x5BEE40

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5419B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x673DE0
#define EQPlayer__dEQPlayer_x                                      0x667160
#define EQPlayer__DoAttack_x                                       0x67BBF0
#define EQPlayer__EQPlayer_x                                       0x667820
#define EQPlayer__SetNameSpriteState_x                             0x66BAF0
#define EQPlayer__SetNameSpriteTint_x                              0x66C9D0
#define PlayerBase__HasProperty_j_x                                0x986930
#define EQPlayer__IsTargetable_x                                   0x986DD0
#define EQPlayer__CanSee_x                                         0x986C30
#define EQPlayer__CanSee1_x                                        0x986D00
#define PlayerBase__GetVisibilityLineSegment_x                     0x9869F0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67EEF0
#define PlayerZoneClient__GetLevel_x                               0x681490
#define PlayerZoneClient__IsValidTeleport_x                        0x5ECF90
#define PlayerZoneClient__LegalPlayerRace_x                        0x55C5A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x676B10
#define EQPlayerManager__GetSpawnByName_x                          0x676BC0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x676C50

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63A220
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63A2A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63A2E0
#define KeypressHandler__ClearCommandStateArray_x                  0x63B6D0
#define KeypressHandler__HandleKeyDown_x                           0x63B6F0
#define KeypressHandler__HandleKeyUp_x                             0x63B790
#define KeypressHandler__SaveKeymapping_x                          0x63BBE0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7733E0
#define MapViewMap__SaveEx_x                                       0x7767A0
#define MapViewMap__SetZoom_x                                      0x77AE60

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B8F20

// StringTable 
#define StringTable__getString_x                                   0x8B3DC0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x661940
#define PcZoneClient__RemovePetEffect_x                            0x661F70
#define PcZoneClient__HasAlternateAbility_x                        0x65BD70
#define PcZoneClient__GetCurrentMod_x                              0x4E5D60
#define PcZoneClient__GetModCap_x                                  0x4E5C60
#define PcZoneClient__CanEquipItem_x                               0x65C420
#define PcZoneClient__GetItemByID_x                                0x65EF10
#define PcZoneClient__GetItemByItemClass_x                         0x65F060
#define PcZoneClient__RemoveBuffEffect_x                           0x661F90
#define PcZoneClient__BandolierSwap_x                              0x65CFF0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65EA40

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F1B10

//IconCache
#define IconCache__GetIcon_x                                       0x714DD0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70C8B0
#define CContainerMgr__CloseContainer_x                            0x70CB80
#define CContainerMgr__OpenExperimentContainer_x                   0x70D600

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CBB00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62EBA0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x769910
#define CLootWnd__RequestLootSlot_x                                0x768BF0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58B060
#define EQ_Spell__SpellAffects_x                                   0x58B4D0
#define EQ_Spell__SpellAffectBase_x                                0x58B290
#define EQ_Spell__IsStackable_x                                    0x4CA8C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA6B0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7AF0
#define EQ_Spell__IsSPAStacking_x                                  0x58C320
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58B830
#define EQ_Spell__IsNoRemove_x                                     0x4CA8A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58C330
#define __IsResEffectSpell_x                                       0x4C9B20

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD200

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C3440

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8127F0
#define CTargetWnd__WndNotification_x                              0x812030
#define CTargetWnd__RefreshTargetBuffs_x                           0x812300
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x811190

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x816E40
#define CTaskWnd__ConfirmAbandonTask_x                             0x819A80

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F3E0
#define CTaskManager__HandleMessage_x                              0x53D860
#define CTaskManager__GetTaskStatus_x                              0x53F490
#define CTaskManager__GetElementDescription_x                      0x53F510

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5861A0
#define EqSoundManager__PlayScriptMp3_x                            0x586460
#define EqSoundManager__SoundAssistPlay_x                          0x699CE0
#define EqSoundManager__WaveInstancePlay_x                         0x699250

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5309F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x942530
#define CTextureAnimation__Draw_x                                  0x942730

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93E480

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B240
#define CAltAbilityData__GetMercMaxRank_x                          0x56B1D0
#define CAltAbilityData__GetMaxRank_x                              0x5606B0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62CCB0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA690
#define CharacterBase__CreateItemGlobalIndex_x                     0x517600
#define CharacterBase__CreateItemIndex_x                           0x634DF0
#define CharacterBase__GetItemPossession_x                         0x503250
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CBA90
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CBAF0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F3670
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F3EA0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F3F50

//messages
#define msg_spell_worn_off_x                                       0x5B0600
#define msg_new_text_x                                             0x5A4F90
#define __msgTokenTextParam_x                                      0x5B28A0
#define msgTokenText_x                                             0x5B2AF0

//SpellManager
#define SpellManager__vftable_x                                    0xAD72CC
#define SpellManager__SpellManager_x                               0x69D010
#define Spellmanager__LoadTextSpells_x                             0x69D900
#define SpellManager__GetSpellByGroupAndRank_x                     0x69D1E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98A9A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517C80
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B6A50
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64DA00
#define ItemGlobalIndex__IsValidIndex_x                            0x517D10

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C3DE0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C4060

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7621A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x710F90
#define CCursorAttachment__AttachToCursor1_x                       0x710FD0
#define CCursorAttachment__Deactivate_x                            0x711FC0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9350E0
#define CSidlManagerBase__CreatePageWnd_x                          0x9348E0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x930B70
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x930B00

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x952200
#define CEQSuiteTextureLoader__GetTexture_x                        0x951EC0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514B80
#define CFindItemWnd__WndNotification_x                            0x515660
#define CFindItemWnd__Update_x                                     0x5161D0
#define CFindItemWnd__PickupSelectedItem_x                         0x5143A0

//IString
#define IString__Append_x                                          0x504AE0

//Camera
#define CDisplay__cameraType_x                                     0xDE6880
#define EverQuest__Cameras_x                                       0xEA1AFC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D5C0
#define LootFiltersManager__GetItemFilterData_x                    0x51CEC0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51CEF0
#define LootFiltersManager__SetItemLootFilter_x                    0x51D110

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B9920

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9905F0
#define CResolutionHandler__GetWindowedStyle_x                     0x6946B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7094E0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D94D0
#define CDistillerInfo__Instance_x                                 0x8D9470

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x728470
#define CGroupWnd__UpdateDisplay_x                                 0x7277C0

//ItemBase
#define ItemBase__IsLore_x                                         0x899AE0
#define ItemBase__IsLoreEquipped_x                                 0x899B50

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EBD80
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EBEC0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EBF20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x689B70
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68D4D0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50AED0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F7140
#define FactionManagerClient__HandleFactionMessage_x               0x4F77B0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F7DB0
#define FactionManagerClient__GetMaxFaction_x                      0x4F7DCF
#define FactionManagerClient__GetMinFaction_x                      0x4F7D80

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x503220

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x9197A0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BFD0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5034E0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56A6C0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A0880

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x689B70

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D20

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BEDE0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3F190

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BD010
#define CAAWnd__UpdateSelected_x                                   0x6B9880
#define CAAWnd__Update_x                                           0x6BC330

//CXRect
#define CXRect__operator_and_x                                     0x71F550

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x482E90

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

//__eqgraphics_fopen
//Jan 09 2020 EQGraphicsDX9.dll
//IDA Style Sig: E8 ? ? ? ? 83 C4 08 89 45 A0
//#define __eqgraphics_fopen_x                                       0x101473C8
static PBYTE efPattern = (PBYTE)"\xE8\x00\x00\x00\x00\x83\xC4\x08\x89\x45\xA0";
static char efMask[] = "x????xxxxxx";
