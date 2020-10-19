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
#define __ExpectedVersionDate                                     "Oct 19 2020"
#define __ExpectedVersionTime                                     "04:21:23"
#define __ActualVersionDate_x                                      0xAF22BC
#define __ActualVersionTime_x                                      0xAF22B0
#define __ActualVersionBuild_x                                     0xAE02DC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6403E0
#define __MemChecker1_x                                            0x8F3360
#define __MemChecker2_x                                            0x6B0B60
#define __MemChecker3_x                                            0x6B0AB0
#define __MemChecker4_x                                            0x849C90
#define __EncryptPad0_x                                            0xC27500
#define __EncryptPad1_x                                            0xC84D40
#define __EncryptPad2_x                                            0xC378C8
#define __EncryptPad3_x                                            0xC374C8
#define __EncryptPad4_x                                            0xC752D8
#define __EncryptPad5_x                                            0xF470B8
#define __AC1_x                                                    0x808596
#define __AC2_x                                                    0x5F9BAF
#define __AC3_x                                                    0x601200
#define __AC4_x                                                    0x6051B0
#define __AC5_x                                                    0x60B49F
#define __AC6_x                                                    0x60F956
#define __AC7_x                                                    0x5F9620
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
#define __do_loot_x                                                0x5C5630
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
#define __gfMaxZoomCameraDistance_x                                0xAE9ED8
#define __gfMaxCameraDistance_x                                    0xB12B50
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
#define __CastRay_x                                                0x5C0D20
#define __CastRay2_x                                               0x5C0D70
#define __ConvertItemTags_x                                        0x5DC910
#define __CleanItemTags_x                                          0x47CF10
#define __DoesFileExist_x                                          0x8F6390
#define __EQGetTime_x                                              0x8F2F90
#define __ExecuteCmd_x                                             0x5B96C0
#define __FixHeading_x                                             0x988230
#define __FlushDxKeyboard_x                                        0x6ACA00
#define __GameLoop_x                                               0x6AFD30
#define __get_bearing_x                                            0x5C0880
#define __get_melee_range_x                                        0x5C0F60
#define __GetAnimationCache_x                                      0x7150D0
#define __GetGaugeValueFromEQ_x                                    0x806A40
#define __GetLabelFromEQ_x                                         0x808520
#define __GetXTargetType_x                                         0x989CF0
#define __HandleMouseWheel_x                                       0x6B0C10
#define __HeadingDiff_x                                            0x9882A0
#define __HelpPath_x                                               0xF3F86C
#define __LoadFrontEnd_x                                           0x6AD040
#define __NewUIINI_x                                               0x806710
#define __ProcessGameEvents_x                                      0x621830
#define __ProcessMouseEvent_x                                      0x620FC0
#define __SaveColors_x                                             0x55AA80
#define __STMLToText_x                                             0x92B650
#define __ToggleKeyRingItem_x                                      0x519540
#define CMemoryMappedFile__SetFile_x                               0xA77590
#define CrashDetected_x                                            0x6AEAF0
#define DrawNetStatus_x                                            0x64D800
#define Expansion_HoT_x                                            0xEA17C0
#define Teleport_Table_Size_x                                      0xE98EB8
#define Teleport_Table_x                                           0xE99380
#define Util__FastTime_x                                           0x8F2B60
#define __CopyLayout_x                                             0x63BB00
#define __WndProc_x                                                0x6AEFF0
#define __ProcessKeyboardEvent_x                                   0x6AE590

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490360
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499350
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499120
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4938F0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x562BE0
#define AltAdvManager__IsAbilityReady_x                            0x561980
#define AltAdvManager__GetAAById_x                                 0x561D10
#define AltAdvManager__CanTrainAbility_x                           0x561D80
#define AltAdvManager__CanSeeAbility_x                             0x5620E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAF10
#define CharacterZoneClient__HasSkill_x                            0x4D5D90
#define CharacterZoneClient__MakeMeVisible_x                       0x4D74B0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2770
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBC10
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9E20
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9F00
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9FE0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4860
#define CharacterZoneClient__BardCastBard_x                        0x4C7290
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF620
#define CharacterZoneClient__GetEffect_x                           0x4BBB50
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C58D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C59A0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C59F0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5B40
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5D20
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B39A0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8410
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7E90

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D67D0
#define CBankWnd__WndNotification_x                                0x6D65B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E3F80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x928E40
#define CButtonWnd__CButtonWnd_x                                   0x927A10

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x704210
#define CChatManager__InitContextMenu_x                            0x6FD340
#define CChatManager__FreeChatWindow_x                             0x702D50
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9920
#define CChatManager__SetLockedActiveChatWindow_x                  0x703E90
#define CChatManager__CreateChatWindow_x                           0x703390

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9A30

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93BFB0
#define CContextMenu__dCContextMenu_x                              0x93C1F0
#define CContextMenu__AddMenuItem_x                                0x93C200
#define CContextMenu__RemoveMenuItem_x                             0x93C510
#define CContextMenu__RemoveAllMenuItems_x                         0x93C530
#define CContextMenu__CheckMenuItem_x                              0x93C5B0
#define CContextMenu__SetMenuItem_x                                0x93C430
#define CContextMenu__AddSeparator_x                               0x93C390

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93CB40
#define CContextMenuManager__RemoveMenu_x                          0x93CBB0
#define CContextMenuManager__PopupMenu_x                           0x93CC70
#define CContextMenuManager__Flush_x                               0x93CAE0
#define CContextMenuManager__GetMenu_x                             0x49B560
#define CContextMenuManager__CreateDefaultMenu_x                   0x70FA50

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CDB20
#define CChatService__GetFriendName_x                              0x8CDB30

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x704A80
#define CChatWindow__Clear_x                                       0x705D50
#define CChatWindow__WndNotification_x                             0x7064E0
#define CChatWindow__AddHistory_x                                  0x705610

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x939410
#define CComboWnd__Draw_x                                          0x938910
#define CComboWnd__GetCurChoice_x                                  0x939250
#define CComboWnd__GetListRect_x                                   0x938DB0
#define CComboWnd__GetTextRect_x                                   0x939480
#define CComboWnd__InsertChoice_x                                  0x938F40
#define CComboWnd__SetColors_x                                     0x938F10
#define CComboWnd__SetChoice_x                                     0x939220
#define CComboWnd__GetItemCount_x                                  0x939260
#define CComboWnd__GetCurChoiceText_x                              0x9392A0
#define CComboWnd__GetChoiceText_x                                 0x939270
#define CComboWnd__InsertChoiceAtIndex_x                           0x938FE0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70D460
#define CContainerWnd__vftable_x                                   0xAFB4B4
#define CContainerWnd__SetContainer_x                              0x70E9C0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x555430
#define CDisplay__PreZoneMainUI_x                                  0x555440
#define CDisplay__CleanGameUI_x                                    0x55A840
#define CDisplay__GetClickedActor_x                                0x54D890
#define CDisplay__GetUserDefinedColor_x                            0x545F10
#define CDisplay__GetWorldFilePath_x                               0x54F300
#define CDisplay__is3dON_x                                         0x54A4F0
#define CDisplay__ReloadUI_x                                       0x554940
#define CDisplay__WriteTextHD2_x                                   0x54A2E0
#define CDisplay__TrueDistance_x                                   0x550FC0
#define CDisplay__SetViewActor_x                                   0x54D1B0
#define CDisplay__GetFloorHeight_x                                 0x54A5B0
#define CDisplay__SetRenderWindow_x                                0x548F30
#define CDisplay__ToggleScreenshotMode_x                           0x54CC80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95BF40

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x93F4B0
#define CEditWnd__EnsureCaretVisible_x                             0x941680
#define CEditWnd__GetCaretPt_x                                     0x940630
#define CEditWnd__GetCharIndexPt_x                                 0x9403E0
#define CEditWnd__GetDisplayString_x                               0x940280
#define CEditWnd__GetHorzOffset_x                                  0x93EB50
#define CEditWnd__GetLineForPrintableChar_x                        0x941580
#define CEditWnd__GetSelStartPt_x                                  0x940690
#define CEditWnd__GetSTMLSafeText_x                                0x9400A0
#define CEditWnd__PointFromPrintableChar_x                         0x9411B0
#define CEditWnd__SelectableCharFromPoint_x                        0x941320
#define CEditWnd__SetEditable_x                                    0x940760
#define CEditWnd__SetWindowTextA_x                                 0x93FE20
#define CEditWnd__ReplaceSelection_x                               0x940E20
#define CEditWnd__ReplaceSelection1_x                              0x940DA0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60EE30
#define CEverQuest__ClickedPlayer_x                                0x600FE0
#define CEverQuest__CreateTargetIndicator_x                        0x61E9A0
#define CEverQuest__DeleteTargetIndicator_x                        0x61EA30
#define CEverQuest__DoTellWindow_x                                 0x4E9B10
#define CEverQuest__OutputTextToLog_x                              0x4E9DE0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F6140
#define CEverQuest__dsp_chat_x                                     0x4EA170
#define CEverQuest__trimName_x                                     0x61AB50
#define CEverQuest__Emote_x                                        0x60F690
#define CEverQuest__EnterZone_x                                    0x609790
#define CEverQuest__GetBodyTypeDesc_x                              0x6140E0
#define CEverQuest__GetClassDesc_x                                 0x614720
#define CEverQuest__GetClassThreeLetterCode_x                      0x614D20
#define CEverQuest__GetDeityDesc_x                                 0x61D1F0
#define CEverQuest__GetLangDesc_x                                  0x614EE0
#define CEverQuest__GetRaceDesc_x                                  0x614700
#define CEverQuest__InterpretCmd_x                                 0x61D7C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FA2D0
#define CEverQuest__LMouseUp_x                                     0x5F8660
#define CEverQuest__RightClickedOnPlayer_x                         0x5FABB0
#define CEverQuest__RMouseUp_x                                     0x5F95E0
#define CEverQuest__SetGameState_x                                 0x5F5ED0
#define CEverQuest__UPCNotificationFlush_x                         0x61AA50
#define CEverQuest__IssuePetCommand_x                              0x6162F0
#define CEverQuest__ReportSuccessfulHit_x                          0x6109E0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71F170
#define CGaugeWnd__CalcLinesFillRect_x                             0x71F1D0
#define CGaugeWnd__Draw_x                                          0x71E800

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFC90
#define CGuild__GetGuildName_x                                     0x4AE740
#define CGuild__GetGuildIndex_x                                    0x4AED40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x738E30

//CHotButton
#define CHotButton__SetCheck_x                                     0x6300C0
#define CHotButton__SetButtonSize_x                                0x630480

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x745EE0
#define CInvSlotMgr__MoveItem_x                                    0x744BA0
#define CInvSlotMgr__SelectSlot_x                                  0x745FB0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7433D0
#define CInvSlot__SliderComplete_x                                 0x741120
#define CInvSlot__GetItemBase_x                                    0x740AA0
#define CInvSlot__UpdateItem_x                                     0x740C10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x747A20
#define CInvSlotWnd__CInvSlotWnd_x                                 0x746BC0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7475A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x801DB0
#define CItemDisplayWnd__UpdateStrings_x                           0x756230
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74FEB0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7503E0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x756830
#define CItemDisplayWnd__AboutToShow_x                             0x755E90
#define CItemDisplayWnd__WndNotification_x                         0x757AB0
#define CItemDisplayWnd__RequestConvertItem_x                      0x7573E0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x754EF0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x755CB0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8328D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75BFC0

// CLabel 
#define CLabel__Draw_x                                             0x7619D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x911C60
#define CListWnd__dCListWnd_x                                      0x911F80
#define CListWnd__AddColumn_x                                      0x916400
#define CListWnd__AddColumn1_x                                     0x916450
#define CListWnd__AddLine_x                                        0x9167E0
#define CListWnd__AddString_x                                      0x9165E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9161C0
#define CListWnd__CalculateVSBRange_x                              0x915FB0
#define CListWnd__ClearSel_x                                       0x916FC0
#define CListWnd__ClearAllSel_x                                    0x917020
#define CListWnd__CloseAndUpdateEditWindow_x                       0x917A40
#define CListWnd__Compare_x                                        0x9158E0
#define CListWnd__Draw_x                                           0x9120B0
#define CListWnd__DrawColumnSeparators_x                           0x9148B0
#define CListWnd__DrawHeader_x                                     0x914D20
#define CListWnd__DrawItem_x                                       0x915220
#define CListWnd__DrawLine_x                                       0x914A20
#define CListWnd__DrawSeparator_x                                  0x914950
#define CListWnd__EnableLine_x                                     0x914180
#define CListWnd__EnsureVisible_x                                  0x917960
#define CListWnd__ExtendSel_x                                      0x916EF0
#define CListWnd__GetColumnTooltip_x                               0x913CC0
#define CListWnd__GetColumnMinWidth_x                              0x913D30
#define CListWnd__GetColumnWidth_x                                 0x913C30
#define CListWnd__GetCurSel_x                                      0x9135C0
#define CListWnd__GetItemAtPoint_x                                 0x914400
#define CListWnd__GetItemAtPoint1_x                                0x914470
#define CListWnd__GetItemData_x                                    0x913640
#define CListWnd__GetItemHeight_x                                  0x913A00
#define CListWnd__GetItemIcon_x                                    0x9137D0
#define CListWnd__GetItemRect_x                                    0x914270
#define CListWnd__GetItemText_x                                    0x913680
#define CListWnd__GetSelList_x                                     0x917070
#define CListWnd__GetSeparatorRect_x                               0x9146B0
#define CListWnd__InsertLine_x                                     0x916BD0
#define CListWnd__RemoveLine_x                                     0x916D20
#define CListWnd__SetColors_x                                      0x915F80
#define CListWnd__SetColumnJustification_x                         0x915CB0
#define CListWnd__SetColumnLabel_x                                 0x916580
#define CListWnd__SetColumnWidth_x                                 0x915BD0
#define CListWnd__SetCurSel_x                                      0x916E30
#define CListWnd__SetItemColor_x                                   0x917610
#define CListWnd__SetItemData_x                                    0x9175D0
#define CListWnd__SetItemText_x                                    0x9171E0
#define CListWnd__ShiftColumnSeparator_x                           0x915D70
#define CListWnd__Sort_x                                           0x915A60
#define CListWnd__ToggleSel_x                                      0x916E60
#define CListWnd__SetColumnsSizable_x                              0x915E20
#define CListWnd__SetItemWnd_x                                     0x917490
#define CListWnd__GetItemWnd_x                                     0x913820
#define CListWnd__SetItemIcon_x                                    0x917260
#define CListWnd__CalculateCustomWindowPositions_x                 0x9162C0
#define CListWnd__SetVScrollPos_x                                  0x915BB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x777040
#define CMapViewWnd__GetWorldCoordinates_x                         0x775750
#define CMapViewWnd__HandleLButtonDown_x                           0x772790

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7973D0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x797CB0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7981E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79B1A0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x795F30
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A0D70
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x796FE0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89BB60
#define CPacketScrambler__hton_x                                   0x89BB50

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x930C20
#define CSidlManager__FindScreenPieceTemplate_x                    0x931030
#define CSidlManager__FindScreenPieceTemplate1_x                   0x930E20
#define CSidlManager__CreateLabel_x                                0x7F8F50
#define CSidlManager__CreateXWndFromTemplate_x                     0x933F90
#define CSidlManager__CreateXWndFromTemplate1_x                    0x934170
#define CSidlManager__CreateXWnd_x                                 0x7F8E80
#define CSidlManager__CreateHotButtonWnd_x                         0x7F9450

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92D720
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92D620
#define CSidlScreenWnd__ConvertToRes_x                             0x956A70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92D110
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92CE00
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92CED0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92CFA0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92DBC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x92E090
#define CSidlScreenWnd__GetSidlPiece_x                             0x92DDB0
#define CSidlScreenWnd__Init1_x                                    0x92CA00
#define CSidlScreenWnd__LoadIniInfo_x                              0x92E0E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92EC00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92BE00
#define CSidlScreenWnd__StoreIniInfo_x                             0x92E780
#define CSidlScreenWnd__StoreIniVis_x                              0x92EAE0
#define CSidlScreenWnd__WndNotification_x                          0x92DAD0
#define CSidlScreenWnd__GetChildItem_x                             0x92E010
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91D7F0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D5BF8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x695A50
#define CSkillMgr__GetSkillCap_x                                   0x695C30
#define CSkillMgr__GetNameToken_x                                  0x6951D0
#define CSkillMgr__IsActivatedSkill_x                              0x695310
#define CSkillMgr__IsCombatSkill_x                                 0x695250

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93D920
#define CSliderWnd__SetValue_x                                     0x93D790
#define CSliderWnd__SetNumTicks_x                                  0x93D7F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FF180

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x946280
#define CStmlWnd__ParseSTML_x                                      0x9475D0
#define CStmlWnd__CalculateHSBRange_x                              0x9473B0
#define CStmlWnd__CalculateVSBRange_x                              0x947320
#define CStmlWnd__CanBreakAtCharacter_x                            0x94B6E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94C370
#define CStmlWnd__ForceParseNow_x                                  0x946870
#define CStmlWnd__GetNextTagPiece_x                                0x94B640
#define CStmlWnd__GetSTMLText_x                                    0x50A9C0
#define CStmlWnd__GetVisibleText_x                                 0x946890
#define CStmlWnd__InitializeWindowVariables_x                      0x94C1C0
#define CStmlWnd__MakeStmlColorTag_x                               0x9458F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x945960
#define CStmlWnd__SetSTMLText_x                                    0x9449A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x94D470
#define CStmlWnd__UpdateHistoryString_x                            0x94C580

// CTabWnd 
#define CTabWnd__Draw_x                                            0x943AF0
#define CTabWnd__DrawCurrentPage_x                                 0x944220
#define CTabWnd__DrawTab_x                                         0x943F40
#define CTabWnd__GetCurrentPage_x                                  0x9432F0
#define CTabWnd__GetPageInnerRect_x                                0x943530
#define CTabWnd__GetTabInnerRect_x                                 0x943470
#define CTabWnd__GetTabRect_x                                      0x943320
#define CTabWnd__InsertPage_x                                      0x943740
#define CTabWnd__RemovePage_x                                      0x9438B0
#define CTabWnd__SetPage_x                                         0x9435B0
#define CTabWnd__SetPageRect_x                                     0x943A30
#define CTabWnd__UpdatePage_x                                      0x943E00
#define CTabWnd__GetPageFromTabIndex_x                             0x943E80
#define CTabWnd__GetCurrentTabIndex_x                              0x9432E0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75C3D0
#define CPageWnd__SetTabText_x                                     0x942E30
#define CPageWnd__FlashTab_x                                       0x942E90

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9020

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91A6C0
#define CTextureFont__GetTextExtent_x                              0x91A880

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A9BE0
#define CHtmlComponentWnd__ValidateUri_x                           0x73A820
#define CHtmlWnd__SetClientCallbacks_x                             0x635510
#define CHtmlWnd__AddObserver_x                                    0x635530
#define CHtmlWnd__RemoveObserver_x                                 0x635590
#define Window__getProgress_x                                      0x851240
#define Window__getStatus_x                                        0x851260
#define Window__getURI_x                                           0x851270

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x953880

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x9077C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9760
#define CXStr__CXStr1_x                                            0x4813F0
#define CXStr__CXStr3_x                                            0x8EEF10
#define CXStr__dCXStr_x                                            0x477F90
#define CXStr__operator_equal_x                                    0x8EF140
#define CXStr__operator_equal1_x                                   0x8EF180
#define CXStr__operator_plus_equal1_x                              0x8EFC10
#define CXStr__SetString_x                                         0x8F1B00
#define CXStr__operator_char_p_x                                   0x8EF650
#define CXStr__GetChar_x                                           0x8F1430
#define CXStr__Delete_x                                            0x8F0D00
#define CXStr__GetUnicode_x                                        0x8F14A0
#define CXStr__GetLength_x                                         0x4A8DD0
#define CXStr__Mid_x                                               0x47D2C0
#define CXStr__Insert_x                                            0x8F1500
#define CXStr__FindNext_x                                          0x8F1170

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93BBD0
#define CXWnd__BringToTop_x                                        0x920ED0
#define CXWnd__Center_x                                            0x920A50
#define CXWnd__ClrFocus_x                                          0x920860
#define CXWnd__Destroy_x                                           0x920910
#define CXWnd__DoAllDrawing_x                                      0x91CF90
#define CXWnd__DrawChildren_x                                      0x91CF60
#define CXWnd__DrawColoredRect_x                                   0x91D3E0
#define CXWnd__DrawTooltip_x                                       0x91BAB0
#define CXWnd__DrawTooltipAtPoint_x                                0x91BB70
#define CXWnd__GetBorderFrame_x                                    0x91D240
#define CXWnd__GetChildWndAt_x                                     0x920F70
#define CXWnd__GetClientClipRect_x                                 0x91F1E0
#define CXWnd__GetScreenClipRect_x                                 0x91F290
#define CXWnd__GetScreenRect_x                                     0x91F440
#define CXWnd__GetRelativeRect_x                                   0x91F500
#define CXWnd__GetTooltipRect_x                                    0x91D430
#define CXWnd__GetWindowTextA_x                                    0x49CC60
#define CXWnd__IsActive_x                                          0x91DB70
#define CXWnd__IsDescendantOf_x                                    0x91FE00
#define CXWnd__IsReallyVisible_x                                   0x91FE30
#define CXWnd__IsType_x                                            0x9215F0
#define CXWnd__Move_x                                              0x91FEB0
#define CXWnd__Move1_x                                             0x91FF60
#define CXWnd__ProcessTransition_x                                 0x920A00
#define CXWnd__Refade_x                                            0x920210
#define CXWnd__Resize_x                                            0x920490
#define CXWnd__Right_x                                             0x920C90
#define CXWnd__SetFocus_x                                          0x920820
#define CXWnd__SetFont_x                                           0x920890
#define CXWnd__SetKeyTooltip_x                                     0x921400
#define CXWnd__SetMouseOver_x                                      0x91E370
#define CXWnd__StartFade_x                                         0x91FCF0
#define CXWnd__GetChildItem_x                                      0x9210E0
#define CXWnd__SetParent_x                                         0x91FBA0
#define CXWnd__Minimize_x                                          0x920500

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x957B00

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x923DE0
#define CXWndManager__DrawWindows_x                                0x923E00
#define CXWndManager__GetKeyboardFlags_x                           0x926600
#define CXWndManager__HandleKeyboardMsg_x                          0x9261B0
#define CXWndManager__RemoveWnd_x                                  0x926830
#define CXWndManager__RemovePendingDeletionWnd_x                   0x926D80

// CDBStr
#define CDBStr__GetString_x                                        0x544EA0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFD80
#define EQ_Character__Cur_HP_x                                     0x4D2DD0
#define EQ_Character__Cur_Mana_x                                   0x4DA4E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2DE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B35E0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3730
#define EQ_Character__GetHPRegen_x                                 0x4E03B0
#define EQ_Character__GetEnduranceRegen_x                          0x4E09B0
#define EQ_Character__GetManaRegen_x                               0x4E0DF0
#define EQ_Character__Max_Endurance_x                              0x65BD40
#define EQ_Character__Max_HP_x                                     0x4D2C00
#define EQ_Character__Max_Mana_x                                   0x65BB40
#define EQ_Character__doCombatAbility_x                            0x65E130
#define EQ_Character__UseSkill_x                                   0x4E2C00
#define EQ_Character__GetConLevel_x                                0x654730
#define EQ_Character__IsExpansionFlag_x                            0x5B7E60
#define EQ_Character__TotalEffect_x                                0x4C6B80
#define EQ_Character__GetPCSpellAffect_x                           0x4C3B30
#define EQ_Character__SpellDuration_x                              0x4C3660
#define EQ_Character__MySpellDuration_x                            0x4B1F10
#define EQ_Character__GetAdjustedSkill_x                           0x4D5B50
#define EQ_Character__GetBaseSkill_x                               0x4D6AF0
#define EQ_Character__CanUseItem_x                                 0x4DA7F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BAA90

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x672060

//PcClient
#define PcClient__vftable_x                                        0xAEEF3C
#define PcClient__PcClient_x                                       0x651EA0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA7F0
#define CCharacterListWnd__EnterWorld_x                            0x4BA1C0
#define CCharacterListWnd__Quit_x                                  0x4B9F10
#define CCharacterListWnd__UpdateList_x                            0x4BA3B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6366F0
#define EQ_Item__CreateItemTagString_x                             0x895110
#define EQ_Item__IsStackable_x                                     0x899DC0
#define EQ_Item__GetImageNum_x                                     0x896CB0
#define EQ_Item__CreateItemClient_x                                0x635930
#define EQ_Item__GetItemValue_x                                    0x897FA0
#define EQ_Item__ValueSellMerchant_x                               0x89B740
#define EQ_Item__IsKeyRingItem_x                                   0x8996C0
#define EQ_Item__CanGoInBag_x                                      0x636810
#define EQ_Item__IsEmpty_x                                         0x899230
#define EQ_Item__GetMaxItemCount_x                                 0x8983C0
#define EQ_Item__GetHeldItem_x                                     0x896B80
#define EQ_Item__GetAugmentFitBySlot_x                             0x894960

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5638C0
#define EQ_LoadingS__Array_x                                       0xC0EC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65C640
#define EQ_PC__GetAlternateAbilityId_x                             0x8A4830
#define EQ_PC__GetCombatAbility_x                                  0x8A4EA0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A4F10
#define EQ_PC__GetItemRecastTimer_x                                0x65E6B0
#define EQ_PC__HasLoreItem_x                                       0x654F40
#define EQ_PC__AlertInventoryChanged_x                             0x654070
#define EQ_PC__GetPcZoneClient_x                                   0x6811A0
#define EQ_PC__RemoveMyAffect_x                                    0x6618E0
#define EQ_PC__GetKeyRingItems_x                                   0x8A57A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A5530
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A5AA0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BE290
#define EQItemList__add_object_x                                   0x5EB780
#define EQItemList__add_item_x                                     0x5BE7F0
#define EQItemList__delete_item_x                                  0x5BE840
#define EQItemList__FreeItemList_x                                 0x5BE740

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x541980

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x673960
#define EQPlayer__dEQPlayer_x                                      0x666CE0
#define EQPlayer__DoAttack_x                                       0x67B930
#define EQPlayer__EQPlayer_x                                       0x6673A0
#define EQPlayer__SetNameSpriteState_x                             0x66B670
#define EQPlayer__SetNameSpriteTint_x                              0x66C550
#define PlayerBase__HasProperty_j_x                                0x986640
#define EQPlayer__IsTargetable_x                                   0x986AE0
#define EQPlayer__CanSee_x                                         0x986940
#define EQPlayer__CanSee1_x                                        0x986A10
#define PlayerBase__GetVisibilityLineSegment_x                     0x986700

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67EC30
#define PlayerZoneClient__GetLevel_x                               0x6811E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EC8F0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55C6D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6767C0
#define EQPlayerManager__GetSpawnByName_x                          0x676870
#define EQPlayerManager__GetPlayerFromPartialName_x                0x676900

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x639D60
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x639DE0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x639E20
#define KeypressHandler__ClearCommandStateArray_x                  0x63B210
#define KeypressHandler__HandleKeyDown_x                           0x63B230
#define KeypressHandler__HandleKeyUp_x                             0x63B2D0
#define KeypressHandler__SaveKeymapping_x                          0x63B720

// MapViewMap 
#define MapViewMap__Clear_x                                        0x772EB0
#define MapViewMap__SaveEx_x                                       0x776270
#define MapViewMap__SetZoom_x                                      0x77A930

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B8B00

// StringTable 
#define StringTable__getString_x                                   0x8B38E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x661550
#define PcZoneClient__RemovePetEffect_x                            0x661B80
#define PcZoneClient__HasAlternateAbility_x                        0x65B970
#define PcZoneClient__GetCurrentMod_x                              0x4E5D10
#define PcZoneClient__GetModCap_x                                  0x4E5C10
#define PcZoneClient__CanEquipItem_x                               0x65C020
#define PcZoneClient__GetItemByID_x                                0x65EB20
#define PcZoneClient__GetItemByItemClass_x                         0x65EC70
#define PcZoneClient__RemoveBuffEffect_x                           0x661BA0
#define PcZoneClient__BandolierSwap_x                              0x65CC00
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65E650

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F14F0

//IconCache
#define IconCache__GetIcon_x                                       0x714AD0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70C600
#define CContainerMgr__CloseContainer_x                            0x70C8D0
#define CContainerMgr__OpenExperimentContainer_x                   0x70D350

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CB6A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62E8A0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x769450
#define CLootWnd__RequestLootSlot_x                                0x768720

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58B370
#define EQ_Spell__SpellAffects_x                                   0x58B7E0
#define EQ_Spell__SpellAffectBase_x                                0x58B5A0
#define EQ_Spell__IsStackable_x                                    0x4CA820
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA640
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7AB0
#define EQ_Spell__IsSPAStacking_x                                  0x58C630
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58BB40
#define EQ_Spell__IsNoRemove_x                                     0x4CA800
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58C640
#define __IsResEffectSpell_x                                       0x4C9AD0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD200

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C31A0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x812500
#define CTargetWnd__WndNotification_x                              0x811D40
#define CTargetWnd__RefreshTargetBuffs_x                           0x812010
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x810EB0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x816B60
#define CTaskWnd__ConfirmAbandonTask_x                             0x819790

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F390
#define CTaskManager__HandleMessage_x                              0x53D810
#define CTaskManager__GetTaskStatus_x                              0x53F440
#define CTaskManager__GetElementDescription_x                      0x53F4C0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5864F0
#define EqSoundManager__PlayScriptMp3_x                            0x5867B0
#define EqSoundManager__SoundAssistPlay_x                          0x6999B0
#define EqSoundManager__WaveInstancePlay_x                         0x698F20

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530970

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x942340
#define CTextureAnimation__Draw_x                                  0x942540

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93E290

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B390
#define CAltAbilityData__GetMercMaxRank_x                          0x56B320
#define CAltAbilityData__GetMaxRank_x                              0x560800

//CTargetRing
#define CTargetRing__Cast_x                                        0x62C9C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA620
#define CharacterBase__CreateItemGlobalIndex_x                     0x517720
#define CharacterBase__CreateItemIndex_x                           0x634AC0
#define CharacterBase__GetItemPossession_x                         0x5034D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CB810
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CB870
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F3550
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F3D80
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F3E30

//messages
#define msg_spell_worn_off_x                                       0x5AFF40
#define msg_new_text_x                                             0x5A48C0
#define __msgTokenTextParam_x                                      0x5B21E0
#define msgTokenText_x                                             0x5B2430

//SpellManager
#define SpellManager__vftable_x                                    0xAD72DC
#define SpellManager__SpellManager_x                               0x69CCE0
#define Spellmanager__LoadTextSpells_x                             0x69D5D0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69CEB0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98A5E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517DA0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B63C0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64D660
#define ItemGlobalIndex__IsValidIndex_x                            0x517E30

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C3B40
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C3DC0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x761D10

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x710CE0
#define CCursorAttachment__AttachToCursor1_x                       0x710D20
#define CCursorAttachment__Deactivate_x                            0x711D10

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x934FD0
#define CSidlManagerBase__CreatePageWnd_x                          0x9347C0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x930A40
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9309D0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9520E0
#define CEQSuiteTextureLoader__GetTexture_x                        0x951DA0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514CA0
#define CFindItemWnd__WndNotification_x                            0x515780
#define CFindItemWnd__Update_x                                     0x5162F0
#define CFindItemWnd__PickupSelectedItem_x                         0x5144D0

//IString
#define IString__Append_x                                          0x504D40

//Camera
#define CDisplay__cameraType_x                                     0xDE6894
#define EverQuest__Cameras_x                                       0xEA1B0C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D6D0
#define LootFiltersManager__GetItemFilterData_x                    0x51CFD0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51D000
#define LootFiltersManager__SetItemLootFilter_x                    0x51D220

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B94E0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9901F0
#define CResolutionHandler__GetWindowedStyle_x                     0x6944C0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x709200

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9100
#define CDistillerInfo__Instance_x                                 0x8D90A0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x728140
#define CGroupWnd__UpdateDisplay_x                                 0x727490

//ItemBase
#define ItemBase__IsLore_x                                         0x899770
#define ItemBase__IsLoreEquipped_x                                 0x8997F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EB6E0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EB820
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EB880

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x689940
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68D2C0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50B030

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F7500
#define FactionManagerClient__HandleFactionMessage_x               0x4F7B70
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F8130
#define FactionManagerClient__GetMaxFaction_x                      0x4F814F
#define FactionManagerClient__GetMinFaction_x                      0x4F8100

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5034A0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x9196B0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BF70

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x503750

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56A830

//CTargetManager
#define CTargetManager__Get_x                                      0x6A0540

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x689940

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8DE0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BE6E0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3F1A0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BCF50
#define CAAWnd__UpdateSelected_x                                   0x6B97C0
#define CAAWnd__Update_x                                           0x6BC270

//CXRect
#define CXRect__operator_and_x                                     0x71F230

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x482FA0

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
