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
#define __ExpectedVersionDate                                     "Oct 20 2020"
#define __ExpectedVersionTime                                     "04:21:36"
#define __ActualVersionDate_x                                      0xAF22B4
#define __ActualVersionTime_x                                      0xAF22A8
#define __ActualVersionBuild_x                                     0xAE02CC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6417F0
#define __MemChecker1_x                                            0x8F4870
#define __MemChecker2_x                                            0x6B1E30
#define __MemChecker3_x                                            0x6B1D80
#define __MemChecker4_x                                            0x84AD20
#define __EncryptPad0_x                                            0xC27500
#define __EncryptPad1_x                                            0xC84D40
#define __EncryptPad2_x                                            0xC378C8
#define __EncryptPad3_x                                            0xC374C8
#define __EncryptPad4_x                                            0xC752D8
#define __EncryptPad5_x                                            0xF470B8
#define __AC1_x                                                    0x8099D6
#define __AC2_x                                                    0x5FAE6F
#define __AC3_x                                                    0x6024C0
#define __AC4_x                                                    0x606470
#define __AC5_x                                                    0x60C75F
#define __AC6_x                                                    0x610C16
#define __AC7_x                                                    0x5FA8E0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191CC4

// Direct Input
#define DI8__Main_x                                                0xF470D8
#define DI8__Keyboard_x                                            0xF470DC
#define DI8__Mouse_x                                               0xF470F4
#define DI8__Mouse_Copy_x                                          0xEA045C
#define DI8__Mouse_Check_x                                         0xF44C0C
#define __AutoSkillArray_x                                         0xEA1378
#define __Attack_x                                                 0xF3F19B
#define __Autofire_x                                               0xF3F19C
#define __BindList_x                                               0xC15F38
#define g_eqCommandStates_x                                        0xC16CB8
#define __Clicks_x                                                 0xEA0514
#define __CommandList_x                                            0xC17878
#define __CurrentMapLabel_x                                        0xF57BB4
#define __CurrentSocial_x                                          0xBFF7C8
#define __DoAbilityList_x                                          0xED6CBC
#define __do_loot_x                                                0x5C6A00
#define __DrawHandler_x                                            0x15D6BA8
#define __GroupCount_x                                             0xE9B532
#define __Guilds_x                                                 0xE9F398
#define __gWorld_x                                                 0xE9B3A4
#define __HWnd_x                                                   0xF470F8
#define __heqmain_x                                                0xF470A0
#define __InChatMode_x                                             0xEA0444
#define __LastTell_x                                               0xEA23B8
#define __LMouseHeldTime_x                                         0xEA0580
#define __Mouse_x                                                  0xF470C4
#define __MouseLook_x                                              0xEA04DA
#define __MouseEventTime_x                                         0xF3FC7C
#define __gpbCommandEvent_x                                        0xE98E30
#define __NetStatusToggle_x                                        0xEA04DD
#define __PCNames_x                                                0xEA1968
#define __RangeAttackReady_x                                       0xEA165C
#define __RMouseHeldTime_x                                         0xEA057C
#define __RunWalkState_x                                           0xEA0448
#define __ScreenMode_x                                             0xDE67CC
#define __ScreenX_x                                                0xEA03FC
#define __ScreenY_x                                                0xEA03F8
#define __ScreenXMax_x                                             0xEA0400
#define __ScreenYMax_x                                             0xEA0404
#define __ServerHost_x                                             0xE98FFB
#define __ServerName_x                                             0xED6C7C
#define __ShiftKeyDown_x                                           0xEA0AD8
#define __ShowNames_x                                              0xEA1818
#define EverQuestInfo__bSocialChanged_x                            0xED6D04
#define __Socials_x                                                0xED6D7C
#define __SubscriptionType_x                                       0xF9BE78
#define __TargetAggroHolder_x                                      0xF5A568
#define __ZoneType_x                                               0xEA08D8
#define __GroupAggro_x                                             0xF5A5A8
#define __LoginName_x                                              0xF47834
#define __Inviter_x                                                0xF3F118
#define __AttackOnAssist_x                                         0xEA17D4
#define __UseTellWindows_x                                         0xEA1B00
#define __gfMaxZoomCameraDistance_x                                0xAE9EC8
#define __gfMaxCameraDistance_x                                    0xB12B58
#define __pulAutoRun_x                                             0xEA04F8
#define __pulForward_x                                             0xEA1B38
#define __pulBackward_x                                            0xEA1B3C
#define __pulTurnRight_x                                           0xEA1B40
#define __pulTurnLeft_x                                            0xEA1B44
#define __pulStrafeLeft_x                                          0xEA1B48
#define __pulStrafeRight_x                                         0xEA1B4C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9B730
#define instEQZoneInfo_x                                           0xEA06D0
#define pinstActiveBanker_x                                        0xE9931C
#define pinstActiveCorpse_x                                        0xE99314
#define pinstActiveGMaster_x                                       0xE99318
#define pinstActiveMerchant_x                                      0xE99310
#define pinstAltAdvManager_x                                       0xDE7960
#define pinstBandageTarget_x                                       0xE9932C
#define pinstCamActor_x                                            0xDE67BC
#define pinstCDBStr_x                                              0xDE667C
#define pinstCDisplay_x                                            0xE9B384
#define pinstCEverQuest_x                                          0xF470F0
#define pinstEverQuestInfo_x                                       0xEA03F0
#define pinstCharData_x                                            0xE9B720
#define pinstCharSpawn_x                                           0xE99364
#define pinstControlledMissile_x                                   0xE99374
#define pinstControlledPlayer_x                                    0xE99364
#define pinstCResolutionHandler_x                                  0x15D6DD8
#define pinstCSidlManager_x                                        0x15D5D70
#define pinstCXWndManager_x                                        0x15D5D6C
#define instDynamicZone_x                                          0xE9F270
#define pinstDZMember_x                                            0xE9F380
#define pinstDZTimerInfo_x                                         0xE9F384
#define pinstEqLogin_x                                             0xF47180
#define instEQMisc_x                                               0xDE65C0
#define pinstEQSoundManager_x                                      0xDE8930
#define pinstEQSpellStrings_x                                      0xCA8F78
#define instExpeditionLeader_x                                     0xE9F2BA
#define instExpeditionName_x                                       0xE9F2FA
#define pinstGroup_x                                               0xE9B52E
#define pinstImeManager_x                                          0x15D5D68
#define pinstLocalPlayer_x                                         0xE9930C
#define pinstMercenaryData_x                                       0xF41768
#define pinstMercenaryStats_x                                      0xF5A634
#define pinstModelPlayer_x                                         0xE99324
#define pinstPCData_x                                              0xE9B720
#define pinstSkillMgr_x                                            0xF438D0
#define pinstSpawnManager_x                                        0xF42378
#define pinstSpellManager_x                                        0xF43B10
#define pinstSpellSets_x                                           0xF37DC4
#define pinstStringTable_x                                         0xE9B728
#define pinstSwitchManager_x                                       0xE98CD0
#define pinstTarget_x                                              0xE99360
#define pinstTargetObject_x                                        0xE9936C
#define pinstTargetSwitch_x                                        0xE9937C
#define pinstTaskMember_x                                          0xDE6450
#define pinstTrackTarget_x                                         0xE99368
#define pinstTradeTarget_x                                         0xE99320
#define instTributeActive_x                                        0xDE65E1
#define pinstViewActor_x                                           0xDE67B8
#define pinstWorldData_x                                           0xE98E20
#define pinstZoneAddr_x                                            0xEA0970
#define pinstPlayerPath_x                                          0xF42410
#define pinstTargetIndicator_x                                     0xF43D78
#define EQObject_Top_x                                             0xE99104
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE6B00
#define pinstCAchievementsWnd_x                                    0xDE6758
#define pinstCActionsWnd_x                                         0xDE6F94
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE6818
#define pinstCAdvancedLootWnd_x                                    0xDE67B0
#define pinstCAdventureLeaderboardWnd_x                            0xF51388
#define pinstCAdventureRequestWnd_x                                0xF51438
#define pinstCAdventureStatsWnd_x                                  0xF514E8
#define pinstCAggroMeterWnd_x                                      0xDE6800
#define pinstCAlarmWnd_x                                           0xDE6780
#define pinstCAlertHistoryWnd_x                                    0xDE6890
#define pinstCAlertStackWnd_x                                      0xDE67E8
#define pinstCAlertWnd_x                                           0xDE67FC
#define pinstCAltStorageWnd_x                                      0xF51848
#define pinstCAudioTriggersWindow_x                                0xC9B2A8
#define pinstCAuraWnd_x                                            0xDE67B4
#define pinstCAvaZoneWnd_x                                         0xDE6864
#define pinstCBandolierWnd_x                                       0xDE6814
#define pinstCBankWnd_x                                            0xDE6848
#define pinstCBarterMerchantWnd_x                                  0xF52A88
#define pinstCBarterSearchWnd_x                                    0xF52B38
#define pinstCBarterWnd_x                                          0xF52BE8
#define pinstCBazaarConfirmationWnd_x                              0xDE6794
#define pinstCBazaarSearchWnd_x                                    0xDE6B04
#define pinstCBazaarWnd_x                                          0xDE6764
#define pinstCBlockedBuffWnd_x                                     0xDE67DC
#define pinstCBlockedPetBuffWnd_x                                  0xDE6804
#define pinstCBodyTintWnd_x                                        0xDE6FA8
#define pinstCBookWnd_x                                            0xDE6840
#define pinstCBreathWnd_x                                          0xDE6B24
#define pinstCBuffWindowNORMAL_x                                   0xDE67A8
#define pinstCBuffWindowSHORT_x                                    0xDE67AC
#define pinstCBugReportWnd_x                                       0xDE6844
#define pinstCButtonWnd_x                                          0x15D5FD8
#define pinstCCastingWnd_x                                         0xDE6834
#define pinstCCastSpellWnd_x                                       0xDE6B10
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE6718
#define pinstCChatWindowManager_x                                  0xF536A8
#define pinstCClaimWnd_x                                           0xF53800
#define pinstCColorPickerWnd_x                                     0xDE6AAC
#define pinstCCombatAbilityWnd_x                                   0xDE6774
#define pinstCCombatSkillsSelectWnd_x                              0xDE672C
#define pinstCCompassWnd_x                                         0xDE6F98
#define pinstCConfirmationDialog_x                                 0xF58700
#define pinstCContainerMgr_x                                       0xDE6FA4
#define pinstCContextMenuManager_x                                 0x15D5D28
#define pinstCCursorAttachment_x                                   0xDE6828
#define pinstCDynamicZoneWnd_x                                     0xF53DC8
#define pinstCEditLabelWnd_x                                       0xDE67A4
#define pinstCEQMainWnd_x                                          0xF54010
#define pinstCEventCalendarWnd_x                                   0xDE6B08
#define pinstCExtendedTargetWnd_x                                  0xDE67E4
#define pinstCFacePick_x                                           0xDE6730
#define pinstCFactionWnd_x                                         0xDE6750
#define pinstCFellowshipWnd_x                                      0xF54210
#define pinstCFileSelectionWnd_x                                   0xDE6AA8
#define pinstCFindItemWnd_x                                        0xDE6740
#define pinstCFindLocationWnd_x                                    0xF54368
#define pinstCFriendsWnd_x                                         0xDE6744
#define pinstCGemsGameWnd_x                                        0xDE674C
#define pinstCGiveWnd_x                                            0xDE6784
#define pinstCGroupSearchFiltersWnd_x                              0xDE681C
#define pinstCGroupSearchWnd_x                                     0xF54760
#define pinstCGroupWnd_x                                           0xF54810
#define pinstCGuildBankWnd_x                                       0xEA17B8
#define pinstCGuildCreationWnd_x                                   0xF54970
#define pinstCGuildMgmtWnd_x                                       0xF54A20
#define pinstCharacterCreation_x                                   0xDE6738
#define pinstCHelpWnd_x                                            0xDE6788
#define pinstCHeritageSelectionWnd_x                               0xDE673C
#define pinstCHotButtonWnd_x                                       0xF56B78
#define pinstCHotButtonWnd1_x                                      0xF56B78
#define pinstCHotButtonWnd2_x                                      0xF56B7C
#define pinstCHotButtonWnd3_x                                      0xF56B80
#define pinstCHotButtonWnd4_x                                      0xF56B84
#define pinstCIconSelectionWnd_x                                   0xDE6824
#define pinstCInspectWnd_x                                         0xDE6808
#define pinstCInventoryWnd_x                                       0xDE67C0
#define pinstCInvSlotMgr_x                                         0xDE6AF0
#define pinstCItemDisplayManager_x                                 0xF57108
#define pinstCItemExpTransferWnd_x                                 0xF5723C
#define pinstCItemOverflowWnd_x                                    0xDE6B0C
#define pinstCJournalCatWnd_x                                      0xDE6AC0
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE687C
#define pinstCKeyRingWnd_x                                         0xDE6830
#define pinstCLargeDialogWnd_x                                     0xF59380
#define pinstCLayoutCopyWnd_x                                      0xF57588
#define pinstCLFGuildWnd_x                                         0xF57638
#define pinstCLoadskinWnd_x                                        0xDE6768
#define pinstCLootFiltersCopyWnd_x                                 0xCB7958
#define pinstCLootFiltersWnd_x                                     0xDE67EC
#define pinstCLootSettingsWnd_x                                    0xDE6810
#define pinstCLootWnd_x                                            0xDE6AC4
#define pinstCMailAddressBookWnd_x                                 0xDE6AF8
#define pinstCMailCompositionWnd_x                                 0xDE6AB4
#define pinstCMailIgnoreListWnd_x                                  0xDE6AFC
#define pinstCMailWnd_x                                            0xDE6AA0
#define pinstCManageLootWnd_x                                      0xDE7E10
#define pinstCMapToolbarWnd_x                                      0xDE6790
#define pinstCMapViewWnd_x                                         0xDE675C
#define pinstCMarketplaceWnd_x                                     0xDE67F0
#define pinstCMerchantWnd_x                                        0xDE6AD0
#define pinstCMIZoneSelectWnd_x                                    0xF57E70
#define pinstCMusicPlayerWnd_x                                     0xDE6A9C
#define pinstCNameChangeMercWnd_x                                  0xDE678C
#define pinstCNameChangePetWnd_x                                   0xDE6760
#define pinstCNameChangeWnd_x                                      0xDE67A0
#define pinstCNoteWnd_x                                            0xDE676C
#define pinstCObjectPreviewWnd_x                                   0xDE680C
#define pinstCOptionsWnd_x                                         0xDE6778
#define pinstCPetInfoWnd_x                                         0xDE6A98
#define pinstCPetitionQWnd_x                                       0xDE6728
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE6FAC
#define pinstCPlayerWnd_x                                          0xDE688C
#define pinstCPopupWndManager_x                                    0xF58700
#define pinstCProgressionSelectionWnd_x                            0xF587B0
#define pinstCPurchaseGroupWnd_x                                   0xDE6860
#define pinstCPurchaseWnd_x                                        0xDE6838
#define pinstCPvPLeaderboardWnd_x                                  0xF58860
#define pinstCPvPStatsWnd_x                                        0xF58910
#define pinstCQuantityWnd_x                                        0xDE6878
#define pinstCRaceChangeWnd_x                                      0xDE67D4
#define pinstCRaidOptionsWnd_x                                     0xDE6820
#define pinstCRaidWnd_x                                            0xDE6ACC
#define pinstCRealEstateItemsWnd_x                                 0xDE6754
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE6F9C
#define pinstCRealEstateManageWnd_x                                0xDE6868
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE6884
#define pinstCRealEstatePlotSearchWnd_x                            0xDE6AA4
#define pinstCRealEstatePurchaseWnd_x                              0xDE6ABC
#define pinstCRespawnWnd_x                                         0xDE67F8
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE6724
#define pinstCSendMoneyWnd_x                                       0xDE6798
#define pinstCServerListWnd_x                                      0xDE6AC8
#define pinstCSkillsSelectWnd_x                                    0xDE6720
#define pinstCSkillsWnd_x                                          0xDE6FA0
#define pinstCSocialEditWnd_x                                      0xDE682C
#define pinstCSocialWnd_x                                          0xDE677C
#define pinstCSpellBookWnd_x                                       0xDE6770
#define pinstCStoryWnd_x                                           0xDE6F90
#define pinstCTargetOfTargetWnd_x                                  0xF5A6B8
#define pinstCTargetWnd_x                                          0xDE67F4
#define pinstCTaskOverlayWnd_x                                     0xDE6858
#define pinstCTaskSelectWnd_x                                      0xF5A810
#define pinstCTaskManager_x                                        0xCB8298
#define pinstCTaskTemplateSelectWnd_x                              0xF5A8C0
#define pinstCTaskWnd_x                                            0xF5A970
#define pinstCTextEntryWnd_x                                       0xDE683C
#define pinstCTimeLeftWnd_x                                        0xDE671C
#define pinstCTipWndCONTEXT_x                                      0xF5AB74
#define pinstCTipWndOFDAY_x                                        0xF5AB70
#define pinstCTitleWnd_x                                           0xF5AC20
#define pinstCTrackingWnd_x                                        0xDE67E0
#define pinstCTradeskillWnd_x                                      0xF5AD88
#define pinstCTradeWnd_x                                           0xDE6FB0
#define pinstCTrainWnd_x                                           0xDE6AB8
#define pinstCTributeBenefitWnd_x                                  0xF5AF88
#define pinstCTributeMasterWnd_x                                   0xF5B038
#define pinstCTributeTrophyWnd_x                                   0xF5B0E8
#define pinstCVideoModesWnd_x                                      0xDE6888
#define pinstCVoiceMacroWnd_x                                      0xF44330
#define pinstCVoteResultsWnd_x                                     0xDE6748
#define pinstCVoteWnd_x                                            0xDE6734
#define pinstCWebManager_x                                         0xF449AC
#define pinstCZoneGuideWnd_x                                       0xDE685C
#define pinstCZonePathWnd_x                                        0xDE6874

#define pinstEQSuiteTextureLoader_x                                0xC85660
#define pinstItemIconCache_x                                       0xF53FC8
#define pinstLootFiltersManager_x                                  0xCB7A08
#define pinstRewardSelectionWnd_x                                  0xF59058

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C20F0
#define __CastRay2_x                                               0x5C2140
#define __ConvertItemTags_x                                        0x5DDCD0
#define __CleanItemTags_x                                          0x47CDC0
#define __DoesFileExist_x                                          0x8F78A0
#define __EQGetTime_x                                              0x8F44A0
#define __ExecuteCmd_x                                             0x5BAA70
#define __FixHeading_x                                             0x988B60
#define __FlushDxKeyboard_x                                        0x6ADCD0
#define __GameLoop_x                                               0x6B1000
#define __get_bearing_x                                            0x5C1C50
#define __get_melee_range_x                                        0x5C2330
#define __GetAnimationCache_x                                      0x7163E0
#define __GetGaugeValueFromEQ_x                                    0x807E80
#define __GetLabelFromEQ_x                                         0x809960
#define __GetXTargetType_x                                         0x98A540
#define __HandleMouseWheel_x                                       0x6B1EE0
#define __HeadingDiff_x                                            0x988BD0
#define __HelpPath_x                                               0xF3F86C
#define __LoadFrontEnd_x                                           0x6AE310
#define __NewUIINI_x                                               0x807B50
#define __ProcessGameEvents_x                                      0x622AE0
#define __ProcessMouseEvent_x                                      0x622270
#define __SaveColors_x                                             0x55AD20
#define __STMLToText_x                                             0x92C180
#define __ToggleKeyRingItem_x                                      0x5196C0
#define CMemoryMappedFile__SetFile_x                               0xA77C80
#define CrashDetected_x                                            0x6AFDC0
#define DrawNetStatus_x                                            0x64EDB0
#define Expansion_HoT_x                                            0xEA17C0
#define Teleport_Table_Size_x                                      0xE98EB8
#define Teleport_Table_x                                           0xE99380
#define Util__FastTime_x                                           0x8F4070
#define __CopyLayout_x                                             0x63CEF0
#define __WndProc_x                                                0x6B02C0
#define __ProcessKeyboardEvent_x                                   0x6AF860

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48FFD0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x498FC0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498D90
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493570
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x4929C0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x562FE0
#define AltAdvManager__IsAbilityReady_x                            0x561D80
#define AltAdvManager__GetAAById_x                                 0x562110
#define AltAdvManager__CanTrainAbility_x                           0x562180
#define AltAdvManager__CanSeeAbility_x                             0x5624E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAEB0
#define CharacterZoneClient__HasSkill_x                            0x4D5D30
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7450
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2750
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBBE0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9E00
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9EE0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9FC0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4840
#define CharacterZoneClient__BardCastBard_x                        0x4C7270
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF5F0
#define CharacterZoneClient__GetEffect_x                           0x4BBB20
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C58B0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5980
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C59D0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5B20
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5D00
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B38E0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D83B0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7E30

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D7BB0
#define CBankWnd__WndNotification_x                                0x6D7990

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E5590

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x929950
#define CButtonWnd__CButtonWnd_x                                   0x928560

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7055C0
#define CChatManager__InitContextMenu_x                            0x6FE6F0
#define CChatManager__FreeChatWindow_x                             0x704100
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9870
#define CChatManager__SetLockedActiveChatWindow_x                  0x705240
#define CChatManager__CreateChatWindow_x                           0x704740

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9980

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93CB30
#define CContextMenu__dCContextMenu_x                              0x93CD70
#define CContextMenu__AddMenuItem_x                                0x93CD80
#define CContextMenu__RemoveMenuItem_x                             0x93D090
#define CContextMenu__RemoveAllMenuItems_x                         0x93D0B0
#define CContextMenu__CheckMenuItem_x                              0x93D130
#define CContextMenu__SetMenuItem_x                                0x93CFB0
#define CContextMenu__AddSeparator_x                               0x93CF10

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93D6D0
#define CContextMenuManager__RemoveMenu_x                          0x93D740
#define CContextMenuManager__PopupMenu_x                           0x93D800
#define CContextMenuManager__Flush_x                               0x93D670
#define CContextMenuManager__GetMenu_x                             0x49B190
#define CContextMenuManager__CreateDefaultMenu_x                   0x710D40

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CF230
#define CChatService__GetFriendName_x                              0x8CF240

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x705E30
#define CChatWindow__Clear_x                                       0x7070F0
#define CChatWindow__WndNotification_x                             0x707880
#define CChatWindow__AddHistory_x                                  0x7069B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x939F80
#define CComboWnd__Draw_x                                          0x939470
#define CComboWnd__GetCurChoice_x                                  0x939DC0
#define CComboWnd__GetListRect_x                                   0x939920
#define CComboWnd__GetTextRect_x                                   0x939FF0
#define CComboWnd__InsertChoice_x                                  0x939AB0
#define CComboWnd__SetColors_x                                     0x939A80
#define CComboWnd__SetChoice_x                                     0x939D90
#define CComboWnd__GetItemCount_x                                  0x939DD0
#define CComboWnd__GetCurChoiceText_x                              0x939E10
#define CComboWnd__GetChoiceText_x                                 0x939DE0
#define CComboWnd__InsertChoiceAtIndex_x                           0x939B50

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70E760
#define CContainerWnd__vftable_x                                   0xAFB4AC
#define CContainerWnd__SetContainer_x                              0x70FCC0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5556D0
#define CDisplay__PreZoneMainUI_x                                  0x5556E0
#define CDisplay__CleanGameUI_x                                    0x55AAE0
#define CDisplay__GetClickedActor_x                                0x54DB30
#define CDisplay__GetUserDefinedColor_x                            0x5461A0
#define CDisplay__GetWorldFilePath_x                               0x54F5A0
#define CDisplay__is3dON_x                                         0x54A790
#define CDisplay__ReloadUI_x                                       0x554BE0
#define CDisplay__WriteTextHD2_x                                   0x54A580
#define CDisplay__TrueDistance_x                                   0x551260
#define CDisplay__SetViewActor_x                                   0x54D450
#define CDisplay__GetFloorHeight_x                                 0x54A850
#define CDisplay__SetRenderWindow_x                                0x5491D0
#define CDisplay__ToggleScreenshotMode_x                           0x54CF20

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95C8E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x940020
#define CEditWnd__EnsureCaretVisible_x                             0x9421B0
#define CEditWnd__GetCaretPt_x                                     0x941190
#define CEditWnd__GetCharIndexPt_x                                 0x940F40
#define CEditWnd__GetDisplayString_x                               0x940DF0
#define CEditWnd__GetHorzOffset_x                                  0x93F6D0
#define CEditWnd__GetLineForPrintableChar_x                        0x9420B0
#define CEditWnd__GetSelStartPt_x                                  0x9411F0
#define CEditWnd__GetSTMLSafeText_x                                0x940C10
#define CEditWnd__PointFromPrintableChar_x                         0x941CF0
#define CEditWnd__SelectableCharFromPoint_x                        0x941E60
#define CEditWnd__SetEditable_x                                    0x9412B0
#define CEditWnd__SetWindowTextA_x                                 0x940990
#define CEditWnd__ReplaceSelection_x                               0x941970
#define CEditWnd__ReplaceSelection1_x                              0x9418F0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x6100F0
#define CEverQuest__ClickedPlayer_x                                0x6022A0
#define CEverQuest__CreateTargetIndicator_x                        0x61FC50
#define CEverQuest__DeleteTargetIndicator_x                        0x61FCE0
#define CEverQuest__DoTellWindow_x                                 0x4E9A60
#define CEverQuest__OutputTextToLog_x                              0x4E9D30
#define CEverQuest__DropHeldItemOnGround_x                         0x5F73F0
#define CEverQuest__dsp_chat_x                                     0x4EA0C0
#define CEverQuest__trimName_x                                     0x61BE00
#define CEverQuest__Emote_x                                        0x610950
#define CEverQuest__EnterZone_x                                    0x60AA50
#define CEverQuest__GetBodyTypeDesc_x                              0x6153A0
#define CEverQuest__GetClassDesc_x                                 0x6159E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x615FE0
#define CEverQuest__GetDeityDesc_x                                 0x61E4A0
#define CEverQuest__GetLangDesc_x                                  0x6161A0
#define CEverQuest__GetRaceDesc_x                                  0x6159C0
#define CEverQuest__InterpretCmd_x                                 0x61EA70
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FB590
#define CEverQuest__LMouseUp_x                                     0x5F9910
#define CEverQuest__RightClickedOnPlayer_x                         0x5FBE70
#define CEverQuest__RMouseUp_x                                     0x5FA8A0
#define CEverQuest__SetGameState_x                                 0x5F7180
#define CEverQuest__UPCNotificationFlush_x                         0x61BD00
#define CEverQuest__IssuePetCommand_x                              0x6175A0
#define CEverQuest__ReportSuccessfulHit_x                          0x611CA0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7203A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x720400
#define CGaugeWnd__Draw_x                                          0x71FA20

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFB50
#define CGuild__GetGuildName_x                                     0x4AE600
#define CGuild__GetGuildIndex_x                                    0x4AEC00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x739F80

//CHotButton
#define CHotButton__SetCheck_x                                     0x6313E0
#define CHotButton__SetButtonSize_x                                0x6317A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x747060
#define CInvSlotMgr__MoveItem_x                                    0x745D70
#define CInvSlotMgr__SelectSlot_x                                  0x747130

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x744560
#define CInvSlot__SliderComplete_x                                 0x7422A0
#define CInvSlot__GetItemBase_x                                    0x741C20
#define CInvSlot__UpdateItem_x                                     0x741D90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x748BC0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x747D50
#define CInvSlotWnd__HandleLButtonUp_x                             0x748740

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8031E0
#define CItemDisplayWnd__UpdateStrings_x                           0x757340
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x751070
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x751570
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x757950
#define CItemDisplayWnd__AboutToShow_x                             0x756F80
#define CItemDisplayWnd__WndNotification_x                         0x758BA0
#define CItemDisplayWnd__RequestConvertItem_x                      0x7584F0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x755FE0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x756DA0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x833C70

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75D0E0

// CLabel 
#define CLabel__Draw_x                                             0x762B10

// CListWnd
#define CListWnd__CListWnd_x                                       0x912710
#define CListWnd__dCListWnd_x                                      0x912A30
#define CListWnd__AddColumn_x                                      0x916E90
#define CListWnd__AddColumn1_x                                     0x916EE0
#define CListWnd__AddLine_x                                        0x917270
#define CListWnd__AddString_x                                      0x917070
#define CListWnd__CalculateFirstVisibleLine_x                      0x916C50
#define CListWnd__CalculateVSBRange_x                              0x916A30
#define CListWnd__ClearSel_x                                       0x917A50
#define CListWnd__ClearAllSel_x                                    0x917AB0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9184D0
#define CListWnd__Compare_x                                        0x916360
#define CListWnd__Draw_x                                           0x912B60
#define CListWnd__DrawColumnSeparators_x                           0x915340
#define CListWnd__DrawHeader_x                                     0x9157A0
#define CListWnd__DrawItem_x                                       0x915CA0
#define CListWnd__DrawLine_x                                       0x9154A0
#define CListWnd__DrawSeparator_x                                  0x9153E0
#define CListWnd__EnableLine_x                                     0x914C20
#define CListWnd__EnsureVisible_x                                  0x9183F0
#define CListWnd__ExtendSel_x                                      0x917980
#define CListWnd__GetColumnTooltip_x                               0x914760
#define CListWnd__GetColumnMinWidth_x                              0x9147D0
#define CListWnd__GetColumnWidth_x                                 0x9146D0
#define CListWnd__GetCurSel_x                                      0x914060
#define CListWnd__GetItemAtPoint_x                                 0x914E90
#define CListWnd__GetItemAtPoint1_x                                0x914F00
#define CListWnd__GetItemData_x                                    0x9140E0
#define CListWnd__GetItemHeight_x                                  0x9144A0
#define CListWnd__GetItemIcon_x                                    0x914270
#define CListWnd__GetItemRect_x                                    0x914D10
#define CListWnd__GetItemText_x                                    0x914120
#define CListWnd__GetSelList_x                                     0x917B00
#define CListWnd__GetSeparatorRect_x                               0x915140
#define CListWnd__InsertLine_x                                     0x917660
#define CListWnd__RemoveLine_x                                     0x9177B0
#define CListWnd__SetColors_x                                      0x916A00
#define CListWnd__SetColumnJustification_x                         0x916730
#define CListWnd__SetColumnLabel_x                                 0x917010
#define CListWnd__SetColumnWidth_x                                 0x916650
#define CListWnd__SetCurSel_x                                      0x9178C0
#define CListWnd__SetItemColor_x                                   0x9180A0
#define CListWnd__SetItemData_x                                    0x918060
#define CListWnd__SetItemText_x                                    0x917C70
#define CListWnd__ShiftColumnSeparator_x                           0x9167F0
#define CListWnd__Sort_x                                           0x9164E0
#define CListWnd__ToggleSel_x                                      0x9178F0
#define CListWnd__SetColumnsSizable_x                              0x9168A0
#define CListWnd__SetItemWnd_x                                     0x917F20
#define CListWnd__GetItemWnd_x                                     0x9142C0
#define CListWnd__SetItemIcon_x                                    0x917CF0
#define CListWnd__CalculateCustomWindowPositions_x                 0x916D50
#define CListWnd__SetVScrollPos_x                                  0x916630

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7781A0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7768B0
#define CMapViewWnd__HandleLButtonDown_x                           0x7738F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7985A0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x798E80
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7993B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79C360
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x797110
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A1F20
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7981C0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89D0E0
#define CPacketScrambler__hton_x                                   0x89D0D0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x931730
#define CSidlManager__FindScreenPieceTemplate_x                    0x931B40
#define CSidlManager__FindScreenPieceTemplate1_x                   0x931930
#define CSidlManager__CreateLabel_x                                0x7FA270
#define CSidlManager__CreateXWndFromTemplate_x                     0x934AA0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x934C80
#define CSidlManager__CreateXWnd_x                                 0x7FA1A0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FA770

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92E210
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92E110
#define CSidlScreenWnd__ConvertToRes_x                             0x9573D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92DC00
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92D8F0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92D9C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92DA90
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92E6B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x92EB80
#define CSidlScreenWnd__GetSidlPiece_x                             0x92E8A0
#define CSidlScreenWnd__Init1_x                                    0x92D510
#define CSidlScreenWnd__LoadIniInfo_x                              0x92EBD0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92F710
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92C930
#define CSidlScreenWnd__StoreIniInfo_x                             0x92F290
#define CSidlScreenWnd__StoreIniVis_x                              0x92F5F0
#define CSidlScreenWnd__WndNotification_x                          0x92E5C0
#define CSidlScreenWnd__GetChildItem_x                             0x92EB00
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91E410
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D5BF8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x696FD0
#define CSkillMgr__GetSkillCap_x                                   0x6971B0
#define CSkillMgr__GetNameToken_x                                  0x696750
#define CSkillMgr__IsActivatedSkill_x                              0x696890
#define CSkillMgr__IsCombatSkill_x                                 0x6967D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93E4B0
#define CSliderWnd__SetValue_x                                     0x93E320
#define CSliderWnd__SetNumTicks_x                                  0x93E380

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8004F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x946DB0
#define CStmlWnd__ParseSTML_x                                      0x9480F0
#define CStmlWnd__CalculateHSBRange_x                              0x947ED0
#define CStmlWnd__CalculateVSBRange_x                              0x947E40
#define CStmlWnd__CanBreakAtCharacter_x                            0x94C200
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94CE90
#define CStmlWnd__ForceParseNow_x                                  0x9473A0
#define CStmlWnd__GetNextTagPiece_x                                0x94C160
#define CStmlWnd__GetSTMLText_x                                    0x50ABC0
#define CStmlWnd__GetVisibleText_x                                 0x9473C0
#define CStmlWnd__InitializeWindowVariables_x                      0x94CCE0
#define CStmlWnd__MakeStmlColorTag_x                               0x946420
#define CStmlWnd__MakeWndNotificationTag_x                         0x946490
#define CStmlWnd__SetSTMLText_x                                    0x9454D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x94DF60
#define CStmlWnd__UpdateHistoryString_x                            0x94D0A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x944620
#define CTabWnd__DrawCurrentPage_x                                 0x944D50
#define CTabWnd__DrawTab_x                                         0x944A70
#define CTabWnd__GetCurrentPage_x                                  0x943E20
#define CTabWnd__GetPageInnerRect_x                                0x944060
#define CTabWnd__GetTabInnerRect_x                                 0x943FA0
#define CTabWnd__GetTabRect_x                                      0x943E50
#define CTabWnd__InsertPage_x                                      0x944270
#define CTabWnd__RemovePage_x                                      0x9443E0
#define CTabWnd__SetPage_x                                         0x9440E0
#define CTabWnd__SetPageRect_x                                     0x944560
#define CTabWnd__UpdatePage_x                                      0x944930
#define CTabWnd__GetPageFromTabIndex_x                             0x9449B0
#define CTabWnd__GetCurrentTabIndex_x                              0x943E10

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75D510
#define CPageWnd__SetTabText_x                                     0x943960
#define CPageWnd__FlashTab_x                                       0x9439C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8E30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91B270
#define CTextureFont__GetTextExtent_x                              0x91B430

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AB190
#define CHtmlComponentWnd__ValidateUri_x                           0x73B990
#define CHtmlWnd__SetClientCallbacks_x                             0x636830
#define CHtmlWnd__AddObserver_x                                    0x636850
#define CHtmlWnd__RemoveObserver_x                                 0x6368B0
#define Window__getProgress_x                                      0x852300
#define Window__getStatus_x                                        0x852320
#define Window__getURI_x                                           0x852330

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9541E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x9081D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9760
#define CXStr__CXStr1_x                                            0x910BE0
#define CXStr__CXStr3_x                                            0x8F0460
#define CXStr__dCXStr_x                                            0x477FE0
#define CXStr__operator_equal_x                                    0x8F0690
#define CXStr__operator_equal1_x                                   0x8F06D0
#define CXStr__operator_plus_equal1_x                              0x8F1160
#define CXStr__SetString_x                                         0x8F3050
#define CXStr__operator_char_p_x                                   0x8F0BA0
#define CXStr__GetChar_x                                           0x8F2980
#define CXStr__Delete_x                                            0x8F2250
#define CXStr__GetUnicode_x                                        0x8F29F0
#define CXStr__GetLength_x                                         0x4A8BE0
#define CXStr__Mid_x                                               0x47D170
#define CXStr__Insert_x                                            0x8F2A50
#define CXStr__FindNext_x                                          0x8F26C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93C740
#define CXWnd__BringToTop_x                                        0x921B70
#define CXWnd__Center_x                                            0x9216F0
#define CXWnd__ClrFocus_x                                          0x921500
#define CXWnd__Destroy_x                                           0x9215B0
#define CXWnd__DoAllDrawing_x                                      0x91DBA0
#define CXWnd__DrawChildren_x                                      0x91DB70
#define CXWnd__DrawColoredRect_x                                   0x91E000
#define CXWnd__DrawTooltip_x                                       0x91C6B0
#define CXWnd__DrawTooltipAtPoint_x                                0x91C770
#define CXWnd__GetBorderFrame_x                                    0x91DE60
#define CXWnd__GetChildWndAt_x                                     0x921C10
#define CXWnd__GetClientClipRect_x                                 0x91FE00
#define CXWnd__GetScreenClipRect_x                                 0x91FED0
#define CXWnd__GetScreenRect_x                                     0x920090
#define CXWnd__GetRelativeRect_x                                   0x920150
#define CXWnd__GetTooltipRect_x                                    0x91E050
#define CXWnd__GetWindowTextA_x                                    0x49C920
#define CXWnd__IsActive_x                                          0x91E780
#define CXWnd__IsDescendantOf_x                                    0x920A90
#define CXWnd__IsReallyVisible_x                                   0x920AC0
#define CXWnd__IsType_x                                            0x922280
#define CXWnd__Move_x                                              0x920B20
#define CXWnd__Move1_x                                             0x920BD0
#define CXWnd__ProcessTransition_x                                 0x9216A0
#define CXWnd__Refade_x                                            0x920EA0
#define CXWnd__Resize_x                                            0x921120
#define CXWnd__Right_x                                             0x921930
#define CXWnd__SetFocus_x                                          0x9214C0
#define CXWnd__SetFont_x                                           0x921530
#define CXWnd__SetKeyTooltip_x                                     0x9220A0
#define CXWnd__SetMouseOver_x                                      0x91EF70
#define CXWnd__StartFade_x                                         0x920970
#define CXWnd__GetChildItem_x                                      0x921D80
#define CXWnd__SetParent_x                                         0x920830
#define CXWnd__Minimize_x                                          0x921190

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x958450

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x924AB0
#define CXWndManager__DrawWindows_x                                0x924AD0
#define CXWndManager__GetKeyboardFlags_x                           0x9271D0
#define CXWndManager__HandleKeyboardMsg_x                          0x926D80
#define CXWndManager__RemoveWnd_x                                  0x927400
#define CXWndManager__RemovePendingDeletionWnd_x                   0x927980

// CDBStr
#define CDBStr__GetString_x                                        0x545170

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFD50
#define EQ_Character__Cur_HP_x                                     0x4D2D70
#define EQ_Character__Cur_Mana_x                                   0x4DA4C0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2DC0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3520
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3670
#define EQ_Character__GetHPRegen_x                                 0x4E03C0
#define EQ_Character__GetEnduranceRegen_x                          0x4E09C0
#define EQ_Character__GetManaRegen_x                               0x4E0E00
#define EQ_Character__Max_Endurance_x                              0x65D270
#define EQ_Character__Max_HP_x                                     0x4D2BA0
#define EQ_Character__Max_Mana_x                                   0x65D070
#define EQ_Character__doCombatAbility_x                            0x65F660
#define EQ_Character__UseSkill_x                                   0x4E2C10
#define EQ_Character__GetConLevel_x                                0x655D30
#define EQ_Character__IsExpansionFlag_x                            0x5B9230
#define EQ_Character__TotalEffect_x                                0x4C6B60
#define EQ_Character__GetPCSpellAffect_x                           0x4C3B10
#define EQ_Character__SpellDuration_x                              0x4C3640
#define EQ_Character__MySpellDuration_x                            0x4B1E50
#define EQ_Character__GetAdjustedSkill_x                           0x4D5AF0
#define EQ_Character__GetBaseSkill_x                               0x4D6A90
#define EQ_Character__CanUseItem_x                                 0x4DA7D0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BC1F0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x673580

//PcClient
#define PcClient__vftable_x                                        0xAEEF30
#define PcClient__PcClient_x                                       0x6534A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA790
#define CCharacterListWnd__EnterWorld_x                            0x4BA160
#define CCharacterListWnd__Quit_x                                  0x4B9EB0
#define CCharacterListWnd__UpdateList_x                            0x4BA350

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x637A00
#define EQ_Item__CreateItemTagString_x                             0x896620
#define EQ_Item__IsStackable_x                                     0x89B300
#define EQ_Item__GetImageNum_x                                     0x8981D0
#define EQ_Item__CreateItemClient_x                                0x636C30
#define EQ_Item__GetItemValue_x                                    0x8994D0
#define EQ_Item__ValueSellMerchant_x                               0x89CCB0
#define EQ_Item__IsKeyRingItem_x                                   0x89AC00
#define EQ_Item__CanGoInBag_x                                      0x637B20
#define EQ_Item__IsEmpty_x                                         0x89A750
#define EQ_Item__GetMaxItemCount_x                                 0x8998F0
#define EQ_Item__GetHeldItem_x                                     0x8980A0
#define EQ_Item__GetAugmentFitBySlot_x                             0x895E70

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x563CE0
#define EQ_LoadingS__Array_x                                       0xC0EC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65DB70
#define EQ_PC__GetAlternateAbilityId_x                             0x8A5D10
#define EQ_PC__GetCombatAbility_x                                  0x8A6380
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A63F0
#define EQ_PC__GetItemRecastTimer_x                                0x65FBE0
#define EQ_PC__HasLoreItem_x                                       0x656540
#define EQ_PC__AlertInventoryChanged_x                             0x655670
#define EQ_PC__GetPcZoneClient_x                                   0x6826A0
#define EQ_PC__RemoveMyAffect_x                                    0x662E10
#define EQ_PC__GetKeyRingItems_x                                   0x8A6C80
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A6A10
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A6F80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BF670
#define EQItemList__add_object_x                                   0x5ECB80
#define EQItemList__add_item_x                                     0x5BFBD0
#define EQItemList__delete_item_x                                  0x5BFC20
#define EQItemList__FreeItemList_x                                 0x5BFB20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x541D40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x674E80
#define EQPlayer__dEQPlayer_x                                      0x6681F0
#define EQPlayer__DoAttack_x                                       0x67CE30
#define EQPlayer__EQPlayer_x                                       0x6688B0
#define EQPlayer__SetNameSpriteState_x                             0x66CB90
#define EQPlayer__SetNameSpriteTint_x                              0x66DA70
#define PlayerBase__HasProperty_j_x                                0x986F70
#define EQPlayer__IsTargetable_x                                   0x987410
#define EQPlayer__CanSee_x                                         0x987270
#define EQPlayer__CanSee1_x                                        0x987340
#define PlayerBase__GetVisibilityLineSegment_x                     0x987030

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x680130
#define PlayerZoneClient__GetLevel_x                               0x6826E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EDCF0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55C970

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x677CF0
#define EQPlayerManager__GetSpawnByName_x                          0x677DA0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x677E30

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63B150
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63B1D0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63B210
#define KeypressHandler__ClearCommandStateArray_x                  0x63C600
#define KeypressHandler__HandleKeyDown_x                           0x63C620
#define KeypressHandler__HandleKeyUp_x                             0x63C6C0
#define KeypressHandler__SaveKeymapping_x                          0x63CB10

// MapViewMap 
#define MapViewMap__Clear_x                                        0x774010
#define MapViewMap__SaveEx_x                                       0x7773D0
#define MapViewMap__SetZoom_x                                      0x77BA90

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BA250

// StringTable 
#define StringTable__getString_x                                   0x8B4FE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x662A80
#define PcZoneClient__RemovePetEffect_x                            0x6630B0
#define PcZoneClient__HasAlternateAbility_x                        0x65CEA0
#define PcZoneClient__GetCurrentMod_x                              0x4E5D30
#define PcZoneClient__GetModCap_x                                  0x4E5C30
#define PcZoneClient__CanEquipItem_x                               0x65D550
#define PcZoneClient__GetItemByID_x                                0x660050
#define PcZoneClient__GetItemByItemClass_x                         0x6601A0
#define PcZoneClient__RemoveBuffEffect_x                           0x6630D0
#define PcZoneClient__BandolierSwap_x                              0x65E130
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65FB80

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F2930

//IconCache
#define IconCache__GetIcon_x                                       0x715DE0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70D900
#define CContainerMgr__CloseContainer_x                            0x70DBD0
#define CContainerMgr__OpenExperimentContainer_x                   0x70E650

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CC8C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62FB90

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76A5D0
#define CLootWnd__RequestLootSlot_x                                0x7698A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58B590
#define EQ_Spell__SpellAffects_x                                   0x58BA00
#define EQ_Spell__SpellAffectBase_x                                0x58B7C0
#define EQ_Spell__IsStackable_x                                    0x4CA7C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA610
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7A10
#define EQ_Spell__IsSPAStacking_x                                  0x58C850
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58BD60
#define EQ_Spell__IsNoRemove_x                                     0x4CA7A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58C860
#define __IsResEffectSpell_x                                       0x4C9A90

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD080

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C4880

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x813910
#define CTargetWnd__WndNotification_x                              0x813150
#define CTargetWnd__RefreshTargetBuffs_x                           0x813420
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8122C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x817F90
#define CTaskWnd__ConfirmAbandonTask_x                             0x81ABD0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F730
#define CTaskManager__HandleMessage_x                              0x53DBA0
#define CTaskManager__GetTaskStatus_x                              0x53F7E0
#define CTaskManager__GetElementDescription_x                      0x53F860

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x586680
#define EqSoundManager__PlayScriptMp3_x                            0x586940
#define EqSoundManager__SoundAssistPlay_x                          0x69AF70
#define EqSoundManager__WaveInstancePlay_x                         0x69A4E0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530CF0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x942E70
#define CTextureAnimation__Draw_x                                  0x943070

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93EE10

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B7E0
#define CAltAbilityData__GetMercMaxRank_x                          0x56B770
#define CAltAbilityData__GetMaxRank_x                              0x560C00

//CTargetRing
#define CTargetRing__Cast_x                                        0x62DC90

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA5F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x517880
#define CharacterBase__CreateItemIndex_x                           0x635DE0
#define CharacterBase__GetItemPossession_x                         0x503380
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CCEE0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CCF40
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F4980
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F51B0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F5260

//messages
#define msg_spell_worn_off_x                                       0x5B11F0
#define msg_new_text_x                                             0x5A5B60
#define __msgTokenTextParam_x                                      0x5B3490
#define msgTokenText_x                                             0x5B36E0

//SpellManager
#define SpellManager__vftable_x                                    0xAD72AC
#define SpellManager__SpellManager_x                               0x69E290
#define Spellmanager__LoadTextSpells_x                             0x69EB80
#define SpellManager__GetSpellByGroupAndRank_x                     0x69E460

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98AE30

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517ED0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B7660
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64EC10
#define ItemGlobalIndex__IsValidIndex_x                            0x517F60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C5220
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C54A0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x762E50

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x711FE0
#define CCursorAttachment__AttachToCursor1_x                       0x712020
#define CCursorAttachment__Deactivate_x                            0x713000

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x935AE0
#define CSidlManagerBase__CreatePageWnd_x                          0x9352D0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x931550
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9314E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x952ED0
#define CEQSuiteTextureLoader__GetTexture_x                        0x952B90

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514E00
#define CFindItemWnd__WndNotification_x                            0x5158E0
#define CFindItemWnd__Update_x                                     0x516450
#define CFindItemWnd__PickupSelectedItem_x                         0x514630

//IString
#define IString__Append_x                                          0x504C40

//Camera
#define CDisplay__cameraType_x                                     0xDE6894
#define EverQuest__Cameras_x                                       0xEA1B0C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D820
#define LootFiltersManager__GetItemFilterData_x                    0x51D130
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51D160
#define LootFiltersManager__SetItemLootFilter_x                    0x51D380

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BA6A0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x990960
#define CResolutionHandler__GetWindowedStyle_x                     0x6959F0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70A5A0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DA880
#define CDistillerInfo__Instance_x                                 0x8DA820

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x729330
#define CGroupWnd__UpdateDisplay_x                                 0x728680

//ItemBase
#define ItemBase__IsLore_x                                         0x89ACB0
#define ItemBase__IsLoreEquipped_x                                 0x89AD30

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5ECAE0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5ECC20
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5ECC80

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68AE20
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68E7A0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50B1C0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F7210
#define FactionManagerClient__HandleFactionMessage_x               0x4F7880
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F7E40
#define FactionManagerClient__GetMaxFaction_x                      0x4F7E5F
#define FactionManagerClient__GetMinFaction_x                      0x4F7E10

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x503350

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91A170

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BC20

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x503650

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56AC70

//CTargetManager
#define CTargetManager__Get_x                                      0x6A1B20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68AE20

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8BF0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BFAC0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3F1A0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BE290
#define CAAWnd__UpdateSelected_x                                   0x6BAB00
#define CAAWnd__Update_x                                           0x6BD5B0

//CXRect
#define CXRect__operator_and_x                                     0x720460

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x482D60

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
