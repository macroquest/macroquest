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
#define __ExpectedVersionDate                                     "Oct 23 2020"
#define __ExpectedVersionTime                                     "04:18:39"
#define __ActualVersionDate_x                                      0xAF22C0
#define __ActualVersionTime_x                                      0xAF22B4
#define __ActualVersionBuild_x                                     0xAE02DC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x640FD0
#define __MemChecker1_x                                            0x8F3920
#define __MemChecker2_x                                            0x6B1350
#define __MemChecker3_x                                            0x6B12A0
#define __MemChecker4_x                                            0x84A150
#define __EncryptPad0_x                                            0xC27500
#define __EncryptPad1_x                                            0xC84D40
#define __EncryptPad2_x                                            0xC378C8
#define __EncryptPad3_x                                            0xC374C8
#define __EncryptPad4_x                                            0xC752D8
#define __EncryptPad5_x                                            0xF470B8
#define __AC1_x                                                    0x808DE6
#define __AC2_x                                                    0x5FA74F
#define __AC3_x                                                    0x601DA0
#define __AC4_x                                                    0x605D50
#define __AC5_x                                                    0x60C03F
#define __AC6_x                                                    0x6104F6
#define __AC7_x                                                    0x5FA1C0
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
#define __do_loot_x                                                0x5C6210
#define __DrawHandler_x                                            0x15D6BA8
#define __GroupCount_x                                             0xE9B532
#define __Guilds_x                                                 0xE9F398
#define __gWorld_x                                                 0xE9B3A0
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
#define __ScreenMode_x                                             0xDE67D4
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
#define pinstCamActor_x                                            0xDE67C4
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
#define pinstViewActor_x                                           0xDE67BC
#define pinstWorldData_x                                           0xE98E20
#define pinstZoneAddr_x                                            0xEA0970
#define pinstPlayerPath_x                                          0xF42410
#define pinstTargetIndicator_x                                     0xF43D78
#define EQObject_Top_x                                             0xE99104
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE6B04
#define pinstCAchievementsWnd_x                                    0xDE675C
#define pinstCActionsWnd_x                                         0xDE6F98
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE681C
#define pinstCAdvancedLootWnd_x                                    0xDE67B4
#define pinstCAdventureLeaderboardWnd_x                            0xF51388
#define pinstCAdventureRequestWnd_x                                0xF51438
#define pinstCAdventureStatsWnd_x                                  0xF514E8
#define pinstCAggroMeterWnd_x                                      0xDE6804
#define pinstCAlarmWnd_x                                           0xDE6784
#define pinstCAlertHistoryWnd_x                                    0xDE6894
#define pinstCAlertStackWnd_x                                      0xDE67EC
#define pinstCAlertWnd_x                                           0xDE6800
#define pinstCAltStorageWnd_x                                      0xF51848
#define pinstCAudioTriggersWindow_x                                0xC9B2A8
#define pinstCAuraWnd_x                                            0xDE67B8
#define pinstCAvaZoneWnd_x                                         0xDE6868
#define pinstCBandolierWnd_x                                       0xDE6818
#define pinstCBankWnd_x                                            0xDE684C
#define pinstCBarterMerchantWnd_x                                  0xF52A88
#define pinstCBarterSearchWnd_x                                    0xF52B38
#define pinstCBarterWnd_x                                          0xF52BE8
#define pinstCBazaarConfirmationWnd_x                              0xDE6798
#define pinstCBazaarSearchWnd_x                                    0xDE6B08
#define pinstCBazaarWnd_x                                          0xDE6768
#define pinstCBlockedBuffWnd_x                                     0xDE67E0
#define pinstCBlockedPetBuffWnd_x                                  0xDE6808
#define pinstCBodyTintWnd_x                                        0xDE6FAC
#define pinstCBookWnd_x                                            0xDE6844
#define pinstCBreathWnd_x                                          0xDE6B8C
#define pinstCBuffWindowNORMAL_x                                   0xDE67AC
#define pinstCBuffWindowSHORT_x                                    0xDE67B0
#define pinstCBugReportWnd_x                                       0xDE6848
#define pinstCButtonWnd_x                                          0x15D5FD8
#define pinstCCastingWnd_x                                         0xDE6838
#define pinstCCastSpellWnd_x                                       0xDE6B14
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE671C
#define pinstCChatWindowManager_x                                  0xF536A8
#define pinstCClaimWnd_x                                           0xF53800
#define pinstCColorPickerWnd_x                                     0xDE6AB0
#define pinstCCombatAbilityWnd_x                                   0xDE6778
#define pinstCCombatSkillsSelectWnd_x                              0xDE6730
#define pinstCCompassWnd_x                                         0xDE6F9C
#define pinstCConfirmationDialog_x                                 0xF58700
#define pinstCContainerMgr_x                                       0xDE6FA8
#define pinstCContextMenuManager_x                                 0x15D5D28
#define pinstCCursorAttachment_x                                   0xDE682C
#define pinstCDynamicZoneWnd_x                                     0xF53DC8
#define pinstCEditLabelWnd_x                                       0xDE67A8
#define pinstCEQMainWnd_x                                          0xF54010
#define pinstCEventCalendarWnd_x                                   0xDE6B0C
#define pinstCExtendedTargetWnd_x                                  0xDE67E8
#define pinstCFacePick_x                                           0xDE6734
#define pinstCFactionWnd_x                                         0xDE6754
#define pinstCFellowshipWnd_x                                      0xF54210
#define pinstCFileSelectionWnd_x                                   0xDE6AAC
#define pinstCFindItemWnd_x                                        0xDE6744
#define pinstCFindLocationWnd_x                                    0xF54368
#define pinstCFriendsWnd_x                                         0xDE6748
#define pinstCGemsGameWnd_x                                        0xDE6750
#define pinstCGiveWnd_x                                            0xDE6788
#define pinstCGroupSearchFiltersWnd_x                              0xDE6820
#define pinstCGroupSearchWnd_x                                     0xF54760
#define pinstCGroupWnd_x                                           0xF54810
#define pinstCGuildBankWnd_x                                       0xEA17B8
#define pinstCGuildCreationWnd_x                                   0xF54970
#define pinstCGuildMgmtWnd_x                                       0xF54A20
#define pinstCharacterCreation_x                                   0xDE673C
#define pinstCHelpWnd_x                                            0xDE678C
#define pinstCHeritageSelectionWnd_x                               0xDE6740
#define pinstCHotButtonWnd_x                                       0xF56B78
#define pinstCHotButtonWnd1_x                                      0xF56B78
#define pinstCHotButtonWnd2_x                                      0xF56B7C
#define pinstCHotButtonWnd3_x                                      0xF56B80
#define pinstCHotButtonWnd4_x                                      0xF56B84
#define pinstCIconSelectionWnd_x                                   0xDE6828
#define pinstCInspectWnd_x                                         0xDE680C
#define pinstCInventoryWnd_x                                       0xDE67C0
#define pinstCInvSlotMgr_x                                         0xDE6AF4
#define pinstCItemDisplayManager_x                                 0xF57108
#define pinstCItemExpTransferWnd_x                                 0xF5723C
#define pinstCItemOverflowWnd_x                                    0xDE6B10
#define pinstCJournalCatWnd_x                                      0xDE6AC4
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE6880
#define pinstCKeyRingWnd_x                                         0xDE6834
#define pinstCLargeDialogWnd_x                                     0xF59380
#define pinstCLayoutCopyWnd_x                                      0xF57588
#define pinstCLFGuildWnd_x                                         0xF57638
#define pinstCLoadskinWnd_x                                        0xDE676C
#define pinstCLootFiltersCopyWnd_x                                 0xCB7958
#define pinstCLootFiltersWnd_x                                     0xDE67F0
#define pinstCLootSettingsWnd_x                                    0xDE6814
#define pinstCLootWnd_x                                            0xDE6AC8
#define pinstCMailAddressBookWnd_x                                 0xDE6AFC
#define pinstCMailCompositionWnd_x                                 0xDE6AB8
#define pinstCMailIgnoreListWnd_x                                  0xDE6B00
#define pinstCMailWnd_x                                            0xDE6AA4
#define pinstCManageLootWnd_x                                      0xDE7E10
#define pinstCMapToolbarWnd_x                                      0xDE6794
#define pinstCMapViewWnd_x                                         0xDE6760
#define pinstCMarketplaceWnd_x                                     0xDE67F4
#define pinstCMerchantWnd_x                                        0xDE6AD4
#define pinstCMIZoneSelectWnd_x                                    0xF57E70
#define pinstCMusicPlayerWnd_x                                     0xDE6AA0
#define pinstCNameChangeMercWnd_x                                  0xDE6790
#define pinstCNameChangePetWnd_x                                   0xDE6764
#define pinstCNameChangeWnd_x                                      0xDE67A4
#define pinstCNoteWnd_x                                            0xDE6770
#define pinstCObjectPreviewWnd_x                                   0xDE6810
#define pinstCOptionsWnd_x                                         0xDE677C
#define pinstCPetInfoWnd_x                                         0xDE689C
#define pinstCPetitionQWnd_x                                       0xDE672C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE6FB0
#define pinstCPlayerWnd_x                                          0xDE688C
#define pinstCPopupWndManager_x                                    0xF58700
#define pinstCProgressionSelectionWnd_x                            0xF587B0
#define pinstCPurchaseGroupWnd_x                                   0xDE6864
#define pinstCPurchaseWnd_x                                        0xDE683C
#define pinstCPvPLeaderboardWnd_x                                  0xF58860
#define pinstCPvPStatsWnd_x                                        0xF58910
#define pinstCQuantityWnd_x                                        0xDE687C
#define pinstCRaceChangeWnd_x                                      0xDE67D0
#define pinstCRaidOptionsWnd_x                                     0xDE6824
#define pinstCRaidWnd_x                                            0xDE6AD0
#define pinstCRealEstateItemsWnd_x                                 0xDE6758
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE6FA0
#define pinstCRealEstateManageWnd_x                                0xDE686C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE6888
#define pinstCRealEstatePlotSearchWnd_x                            0xDE6AA8
#define pinstCRealEstatePurchaseWnd_x                              0xDE6AC0
#define pinstCRespawnWnd_x                                         0xDE67FC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE6728
#define pinstCSendMoneyWnd_x                                       0xDE679C
#define pinstCServerListWnd_x                                      0xDE6ACC
#define pinstCSkillsSelectWnd_x                                    0xDE6724
#define pinstCSkillsWnd_x                                          0xDE6FA4
#define pinstCSocialEditWnd_x                                      0xDE6830
#define pinstCSocialWnd_x                                          0xDE6780
#define pinstCSpellBookWnd_x                                       0xDE6774
#define pinstCStoryWnd_x                                           0xDE6F94
#define pinstCTargetOfTargetWnd_x                                  0xF5A6B8
#define pinstCTargetWnd_x                                          0xDE67F8
#define pinstCTaskOverlayWnd_x                                     0xDE685C
#define pinstCTaskSelectWnd_x                                      0xF5A810
#define pinstCTaskManager_x                                        0xCB8298
#define pinstCTaskTemplateSelectWnd_x                              0xF5A8C0
#define pinstCTaskWnd_x                                            0xF5A970
#define pinstCTextEntryWnd_x                                       0xDE6840
#define pinstCTimeLeftWnd_x                                        0xDE6720
#define pinstCTipWndCONTEXT_x                                      0xF5AB74
#define pinstCTipWndOFDAY_x                                        0xF5AB70
#define pinstCTitleWnd_x                                           0xF5AC20
#define pinstCTrackingWnd_x                                        0xDE67E4
#define pinstCTradeskillWnd_x                                      0xF5AD88
#define pinstCTradeWnd_x                                           0xDE6718
#define pinstCTrainWnd_x                                           0xDE6ABC
#define pinstCTributeBenefitWnd_x                                  0xF5AF88
#define pinstCTributeMasterWnd_x                                   0xF5B038
#define pinstCTributeTrophyWnd_x                                   0xF5B0E8
#define pinstCVideoModesWnd_x                                      0xDE6890
#define pinstCVoiceMacroWnd_x                                      0xF44330
#define pinstCVoteResultsWnd_x                                     0xDE674C
#define pinstCVoteWnd_x                                            0xDE6738
#define pinstCWebManager_x                                         0xF449AC
#define pinstCZoneGuideWnd_x                                       0xDE6860
#define pinstCZonePathWnd_x                                        0xDE6878

#define pinstEQSuiteTextureLoader_x                                0xC85660
#define pinstItemIconCache_x                                       0xF53FC8
#define pinstLootFiltersManager_x                                  0xCB7A08
#define pinstRewardSelectionWnd_x                                  0xF59058

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C1900
#define __CastRay2_x                                               0x5C1950
#define __ConvertItemTags_x                                        0x5DD620
#define __CleanItemTags_x                                          0x47CF60
#define __DoesFileExist_x                                          0x8F6A00
#define __EQGetTime_x                                              0x8F3550
#define __ExecuteCmd_x                                             0x5BA290
#define __FixHeading_x                                             0x988DE0
#define __FlushDxKeyboard_x                                        0x6AD1F0
#define __GameLoop_x                                               0x6B0520
#define __get_bearing_x                                            0x5C1460
#define __get_melee_range_x                                        0x5C1B40
#define __GetAnimationCache_x                                      0x715820
#define __GetGaugeValueFromEQ_x                                    0x807290
#define __GetLabelFromEQ_x                                         0x808D70
#define __GetXTargetType_x                                         0x98A8A0
#define __HandleMouseWheel_x                                       0x6B1400
#define __HeadingDiff_x                                            0x988E50
#define __HelpPath_x                                               0xF3F86C
#define __LoadFrontEnd_x                                           0x6AD830
#define __NewUIINI_x                                               0x806F60
#define __ProcessGameEvents_x                                      0x6223D0
#define __ProcessMouseEvent_x                                      0x621B60
#define __SaveColors_x                                             0x55AE30
#define __STMLToText_x                                             0x92BF60
#define __ToggleKeyRingItem_x                                      0x519650
#define CMemoryMappedFile__SetFile_x                               0xA781F0
#define CrashDetected_x                                            0x6AF2E0
#define DrawNetStatus_x                                            0x64E290
#define Expansion_HoT_x                                            0xEA17C0
#define Teleport_Table_Size_x                                      0xE98EB8
#define Teleport_Table_x                                           0xE99380
#define Util__FastTime_x                                           0x8F3120
#define __CopyLayout_x                                             0x63C660
#define __WndProc_x                                                0x6AF7E0
#define __ProcessKeyboardEvent_x                                   0x6AED80

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4901E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4991E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498FB0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493780
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492BD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x563050
#define AltAdvManager__IsAbilityReady_x                            0x561DF0
#define AltAdvManager__GetAAById_x                                 0x562180
#define AltAdvManager__CanTrainAbility_x                           0x5621F0
#define AltAdvManager__CanSeeAbility_x                             0x562550

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAEE0
#define CharacterZoneClient__HasSkill_x                            0x4D5D60
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7480
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2660
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBAF0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9E30
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9F10
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9FF0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4750
#define CharacterZoneClient__BardCastBard_x                        0x4C7180
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF500
#define CharacterZoneClient__GetEffect_x                           0x4BBA30
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C57C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5890
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C58E0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5A30
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5C10
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B39C0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D83E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7E60

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D6F00
#define CBankWnd__WndNotification_x                                0x6D6CE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E4A70

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x929760
#define CButtonWnd__CButtonWnd_x                                   0x928380

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x704960
#define CChatManager__InitContextMenu_x                            0x6FDA90
#define CChatManager__FreeChatWindow_x                             0x7034A0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E97E0
#define CChatManager__SetLockedActiveChatWindow_x                  0x7045E0
#define CChatManager__CreateChatWindow_x                           0x703AE0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E98F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93C940
#define CContextMenu__dCContextMenu_x                              0x93CB80
#define CContextMenu__AddMenuItem_x                                0x93CB90
#define CContextMenu__RemoveMenuItem_x                             0x93CEA0
#define CContextMenu__RemoveAllMenuItems_x                         0x93CEC0
#define CContextMenu__CheckMenuItem_x                              0x93CF40
#define CContextMenu__SetMenuItem_x                                0x93CDC0
#define CContextMenu__AddSeparator_x                               0x93CD20

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93D4E0
#define CContextMenuManager__RemoveMenu_x                          0x93D550
#define CContextMenuManager__PopupMenu_x                           0x93D610
#define CContextMenuManager__Flush_x                               0x93D480
#define CContextMenuManager__GetMenu_x                             0x49B480
#define CContextMenuManager__CreateDefaultMenu_x                   0x710180

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CE450
#define CChatService__GetFriendName_x                              0x8CE460

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7051D0
#define CChatWindow__Clear_x                                       0x706490
#define CChatWindow__WndNotification_x                             0x706C20
#define CChatWindow__AddHistory_x                                  0x705D50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x939DA0
#define CComboWnd__Draw_x                                          0x939290
#define CComboWnd__GetCurChoice_x                                  0x939BE0
#define CComboWnd__GetListRect_x                                   0x939740
#define CComboWnd__GetTextRect_x                                   0x939E10
#define CComboWnd__InsertChoice_x                                  0x9398D0
#define CComboWnd__SetColors_x                                     0x9398A0
#define CComboWnd__SetChoice_x                                     0x939BB0
#define CComboWnd__GetItemCount_x                                  0x939BF0
#define CComboWnd__GetCurChoiceText_x                              0x939C30
#define CComboWnd__GetChoiceText_x                                 0x939C00
#define CComboWnd__InsertChoiceAtIndex_x                           0x939970

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70DB90
#define CContainerWnd__vftable_x                                   0xAFB4B4
#define CContainerWnd__SetContainer_x                              0x70F0E0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5557E0
#define CDisplay__PreZoneMainUI_x                                  0x5557F0
#define CDisplay__CleanGameUI_x                                    0x55ABF0
#define CDisplay__GetClickedActor_x                                0x54DC40
#define CDisplay__GetUserDefinedColor_x                            0x5462B0
#define CDisplay__GetWorldFilePath_x                               0x54F6B0
#define CDisplay__is3dON_x                                         0x54A8A0
#define CDisplay__ReloadUI_x                                       0x554CF0
#define CDisplay__WriteTextHD2_x                                   0x54A690
#define CDisplay__TrueDistance_x                                   0x551370
#define CDisplay__SetViewActor_x                                   0x54D560
#define CDisplay__GetFloorHeight_x                                 0x54A960
#define CDisplay__SetRenderWindow_x                                0x5492E0
#define CDisplay__ToggleScreenshotMode_x                           0x54D030

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95C880

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x93FE40
#define CEditWnd__EnsureCaretVisible_x                             0x942010
#define CEditWnd__GetCaretPt_x                                     0x940FC0
#define CEditWnd__GetCharIndexPt_x                                 0x940D70
#define CEditWnd__GetDisplayString_x                               0x940C10
#define CEditWnd__GetHorzOffset_x                                  0x93F4E0
#define CEditWnd__GetLineForPrintableChar_x                        0x941F10
#define CEditWnd__GetSelStartPt_x                                  0x941020
#define CEditWnd__GetSTMLSafeText_x                                0x940A30
#define CEditWnd__PointFromPrintableChar_x                         0x941B40
#define CEditWnd__SelectableCharFromPoint_x                        0x941CB0
#define CEditWnd__SetEditable_x                                    0x9410F0
#define CEditWnd__SetWindowTextA_x                                 0x9407B0
#define CEditWnd__ReplaceSelection_x                               0x9417B0
#define CEditWnd__ReplaceSelection1_x                              0x941730

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60F9D0
#define CEverQuest__ClickedPlayer_x                                0x601B80
#define CEverQuest__CreateTargetIndicator_x                        0x61F540
#define CEverQuest__DeleteTargetIndicator_x                        0x61F5D0
#define CEverQuest__DoTellWindow_x                                 0x4E99D0
#define CEverQuest__OutputTextToLog_x                              0x4E9CA0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F6CD0
#define CEverQuest__dsp_chat_x                                     0x4EA030
#define CEverQuest__trimName_x                                     0x61B6F0
#define CEverQuest__Emote_x                                        0x610230
#define CEverQuest__EnterZone_x                                    0x60A330
#define CEverQuest__GetBodyTypeDesc_x                              0x614C80
#define CEverQuest__GetClassDesc_x                                 0x6152C0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6158C0
#define CEverQuest__GetDeityDesc_x                                 0x61DD90
#define CEverQuest__GetLangDesc_x                                  0x615A80
#define CEverQuest__GetRaceDesc_x                                  0x6152A0
#define CEverQuest__InterpretCmd_x                                 0x61E360
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FAE70
#define CEverQuest__LMouseUp_x                                     0x5F91F0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FB750
#define CEverQuest__RMouseUp_x                                     0x5FA180
#define CEverQuest__SetGameState_x                                 0x5F6A60
#define CEverQuest__UPCNotificationFlush_x                         0x61B5F0
#define CEverQuest__IssuePetCommand_x                              0x616E90
#define CEverQuest__ReportSuccessfulHit_x                          0x611580

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71F8F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x71F950
#define CGaugeWnd__Draw_x                                          0x71EF80

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFC60
#define CGuild__GetGuildName_x                                     0x4AE710
#define CGuild__GetGuildIndex_x                                    0x4AED10

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x739550

//CHotButton
#define CHotButton__SetCheck_x                                     0x630BD0
#define CHotButton__SetButtonSize_x                                0x630F90

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x746600
#define CInvSlotMgr__MoveItem_x                                    0x745320
#define CInvSlotMgr__SelectSlot_x                                  0x7466D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x743B10
#define CInvSlot__SliderComplete_x                                 0x741850
#define CInvSlot__GetItemBase_x                                    0x7411E0
#define CInvSlot__UpdateItem_x                                     0x741350

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x748160
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7472F0
#define CInvSlotWnd__HandleLButtonUp_x                             0x747CE0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x802640
#define CItemDisplayWnd__UpdateStrings_x                           0x756920
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7505E0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x750B00
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x756F30
#define CItemDisplayWnd__AboutToShow_x                             0x756560
#define CItemDisplayWnd__WndNotification_x                         0x758190
#define CItemDisplayWnd__RequestConvertItem_x                      0x757AD0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7555C0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x756380

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x833090

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75C6D0

// CLabel 
#define CLabel__Draw_x                                             0x7621A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x912690
#define CListWnd__dCListWnd_x                                      0x9129B0
#define CListWnd__AddColumn_x                                      0x916E40
#define CListWnd__AddColumn1_x                                     0x916E90
#define CListWnd__AddLine_x                                        0x917220
#define CListWnd__AddString_x                                      0x917020
#define CListWnd__CalculateFirstVisibleLine_x                      0x916C00
#define CListWnd__CalculateVSBRange_x                              0x9169E0
#define CListWnd__ClearSel_x                                       0x917A00
#define CListWnd__ClearAllSel_x                                    0x917A60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x918480
#define CListWnd__Compare_x                                        0x916310
#define CListWnd__Draw_x                                           0x912AE0
#define CListWnd__DrawColumnSeparators_x                           0x9152E0
#define CListWnd__DrawHeader_x                                     0x915750
#define CListWnd__DrawItem_x                                       0x915C50
#define CListWnd__DrawLine_x                                       0x915450
#define CListWnd__DrawSeparator_x                                  0x915380
#define CListWnd__EnableLine_x                                     0x914BB0
#define CListWnd__EnsureVisible_x                                  0x9183A0
#define CListWnd__ExtendSel_x                                      0x917930
#define CListWnd__GetColumnTooltip_x                               0x9146F0
#define CListWnd__GetColumnMinWidth_x                              0x914760
#define CListWnd__GetColumnWidth_x                                 0x914660
#define CListWnd__GetCurSel_x                                      0x913FF0
#define CListWnd__GetItemAtPoint_x                                 0x914E30
#define CListWnd__GetItemAtPoint1_x                                0x914EA0
#define CListWnd__GetItemData_x                                    0x914070
#define CListWnd__GetItemHeight_x                                  0x914430
#define CListWnd__GetItemIcon_x                                    0x914200
#define CListWnd__GetItemRect_x                                    0x914CA0
#define CListWnd__GetItemText_x                                    0x9140B0
#define CListWnd__GetSelList_x                                     0x917AB0
#define CListWnd__GetSeparatorRect_x                               0x9150E0
#define CListWnd__InsertLine_x                                     0x917610
#define CListWnd__RemoveLine_x                                     0x917760
#define CListWnd__SetColors_x                                      0x9169B0
#define CListWnd__SetColumnJustification_x                         0x9166E0
#define CListWnd__SetColumnLabel_x                                 0x916FC0
#define CListWnd__SetColumnWidth_x                                 0x916600
#define CListWnd__SetCurSel_x                                      0x917870
#define CListWnd__SetItemColor_x                                   0x918050
#define CListWnd__SetItemData_x                                    0x918010
#define CListWnd__SetItemText_x                                    0x917C20
#define CListWnd__ShiftColumnSeparator_x                           0x9167A0
#define CListWnd__Sort_x                                           0x916490
#define CListWnd__ToggleSel_x                                      0x9178A0
#define CListWnd__SetColumnsSizable_x                              0x916850
#define CListWnd__SetItemWnd_x                                     0x917ED0
#define CListWnd__GetItemWnd_x                                     0x914250
#define CListWnd__SetItemIcon_x                                    0x917CA0
#define CListWnd__CalculateCustomWindowPositions_x                 0x916D00
#define CListWnd__SetVScrollPos_x                                  0x9165E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x777840
#define CMapViewWnd__GetWorldCoordinates_x                         0x775F50
#define CMapViewWnd__HandleLButtonDown_x                           0x772F90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x797AF0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7983D0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x798900
#define CMerchantWnd__SelectRecoverySlot_x                         0x79B8B0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x796660
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A1480
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x797700

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89C410
#define CPacketScrambler__hton_x                                   0x89C400

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x931530
#define CSidlManager__FindScreenPieceTemplate_x                    0x931940
#define CSidlManager__FindScreenPieceTemplate1_x                   0x931730
#define CSidlManager__CreateLabel_x                                0x7F9870
#define CSidlManager__CreateXWndFromTemplate_x                     0x9348A0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x934A80
#define CSidlManager__CreateXWnd_x                                 0x7F97A0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F9D70

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92E030
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92DF30
#define CSidlScreenWnd__ConvertToRes_x                             0x9573D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92DA20
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92D710
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92D7E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92D8B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92E4D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x92E9A0
#define CSidlScreenWnd__GetSidlPiece_x                             0x92E6C0
#define CSidlScreenWnd__Init1_x                                    0x92D310
#define CSidlScreenWnd__LoadIniInfo_x                              0x92E9F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92F510
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92C710
#define CSidlScreenWnd__StoreIniInfo_x                             0x92F090
#define CSidlScreenWnd__StoreIniVis_x                              0x92F3F0
#define CSidlScreenWnd__WndNotification_x                          0x92E3E0
#define CSidlScreenWnd__GetChildItem_x                             0x92E920
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91E230
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D5BF8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x696490
#define CSkillMgr__GetSkillCap_x                                   0x696670
#define CSkillMgr__GetNameToken_x                                  0x695C10
#define CSkillMgr__IsActivatedSkill_x                              0x695D50
#define CSkillMgr__IsCombatSkill_x                                 0x695C90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93E2C0
#define CSliderWnd__SetValue_x                                     0x93E130
#define CSliderWnd__SetNumTicks_x                                  0x93E190

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FF9D0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x946C20
#define CStmlWnd__ParseSTML_x                                      0x947F30
#define CStmlWnd__CalculateHSBRange_x                              0x947D00
#define CStmlWnd__CalculateVSBRange_x                              0x947C70
#define CStmlWnd__CanBreakAtCharacter_x                            0x94C040
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94CCD0
#define CStmlWnd__ForceParseNow_x                                  0x9471C0
#define CStmlWnd__GetNextTagPiece_x                                0x94BFA0
#define CStmlWnd__GetSTMLText_x                                    0x50AB20
#define CStmlWnd__GetVisibleText_x                                 0x9471E0
#define CStmlWnd__InitializeWindowVariables_x                      0x94CB20
#define CStmlWnd__MakeStmlColorTag_x                               0x946290
#define CStmlWnd__MakeWndNotificationTag_x                         0x946300
#define CStmlWnd__SetSTMLText_x                                    0x945340
#define CStmlWnd__StripFirstSTMLLines_x                            0x94DDD0
#define CStmlWnd__UpdateHistoryString_x                            0x94CEE0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x944480
#define CTabWnd__DrawCurrentPage_x                                 0x944BB0
#define CTabWnd__DrawTab_x                                         0x9448D0
#define CTabWnd__GetCurrentPage_x                                  0x943C80
#define CTabWnd__GetPageInnerRect_x                                0x943EC0
#define CTabWnd__GetTabInnerRect_x                                 0x943E00
#define CTabWnd__GetTabRect_x                                      0x943CB0
#define CTabWnd__InsertPage_x                                      0x9440D0
#define CTabWnd__RemovePage_x                                      0x944240
#define CTabWnd__SetPage_x                                         0x943F40
#define CTabWnd__SetPageRect_x                                     0x9443C0
#define CTabWnd__UpdatePage_x                                      0x944790
#define CTabWnd__GetPageFromTabIndex_x                             0x944810
#define CTabWnd__GetCurrentTabIndex_x                              0x943C70

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75CAE0
#define CPageWnd__SetTabText_x                                     0x9437C0
#define CPageWnd__FlashTab_x                                       0x943820

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8F30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91B0D0
#define CTextureFont__GetTextExtent_x                              0x91B290

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AA670
#define CHtmlComponentWnd__ValidateUri_x                           0x73AF40
#define CHtmlWnd__SetClientCallbacks_x                             0x636030
#define CHtmlWnd__AddObserver_x                                    0x636050
#define CHtmlWnd__RemoveObserver_x                                 0x6360B0
#define Window__getProgress_x                                      0x851760
#define Window__getStatus_x                                        0x851780
#define Window__getURI_x                                           0x851790

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9541E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x908300

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9620
#define CXStr__CXStr1_x                                            0x505D20
#define CXStr__CXStr3_x                                            0x8EF4D0
#define CXStr__dCXStr_x                                            0x477F00
#define CXStr__operator_equal_x                                    0x8EF700
#define CXStr__operator_equal1_x                                   0x8EF740
#define CXStr__operator_plus_equal1_x                              0x8F01D0
#define CXStr__SetString_x                                         0x8F20C0
#define CXStr__operator_char_p_x                                   0x8EFC40
#define CXStr__GetChar_x                                           0x8F19F0
#define CXStr__Delete_x                                            0x8F12C0
#define CXStr__GetUnicode_x                                        0x8F1A60
#define CXStr__GetLength_x                                         0x47D310
#define CXStr__Mid_x                                               0x47D320
#define CXStr__Insert_x                                            0x8F1AC0
#define CXStr__FindNext_x                                          0x8F1730

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93C560
#define CXWnd__BringToTop_x                                        0x921920
#define CXWnd__Center_x                                            0x9214A0
#define CXWnd__ClrFocus_x                                          0x9212C0
#define CXWnd__Destroy_x                                           0x921360
#define CXWnd__DoAllDrawing_x                                      0x91D9D0
#define CXWnd__DrawChildren_x                                      0x91D9A0
#define CXWnd__DrawColoredRect_x                                   0x91DE20
#define CXWnd__DrawTooltip_x                                       0x91C4E0
#define CXWnd__DrawTooltipAtPoint_x                                0x91C5A0
#define CXWnd__GetBorderFrame_x                                    0x91DC80
#define CXWnd__GetChildWndAt_x                                     0x9219C0
#define CXWnd__GetClientClipRect_x                                 0x91FC60
#define CXWnd__GetScreenClipRect_x                                 0x91FD30
#define CXWnd__GetScreenRect_x                                     0x91FED0
#define CXWnd__GetRelativeRect_x                                   0x91FF90
#define CXWnd__GetTooltipRect_x                                    0x91DE70
#define CXWnd__GetWindowTextA_x                                    0x49CB70
#define CXWnd__IsActive_x                                          0x91E5B0
#define CXWnd__IsDescendantOf_x                                    0x920880
#define CXWnd__IsReallyVisible_x                                   0x9208B0
#define CXWnd__IsType_x                                            0x922040
#define CXWnd__Move_x                                              0x920920
#define CXWnd__Move1_x                                             0x9209D0
#define CXWnd__ProcessTransition_x                                 0x921450
#define CXWnd__Refade_x                                            0x920C80
#define CXWnd__Resize_x                                            0x920F10
#define CXWnd__Right_x                                             0x9216E0
#define CXWnd__SetFocus_x                                          0x921280
#define CXWnd__SetFont_x                                           0x9212F0
#define CXWnd__SetKeyTooltip_x                                     0x921E50
#define CXWnd__SetMouseOver_x                                      0x91EDC0
#define CXWnd__StartFade_x                                         0x920770
#define CXWnd__GetChildItem_x                                      0x921B30
#define CXWnd__SetParent_x                                         0x920630
#define CXWnd__Minimize_x                                          0x920F80

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x958450

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9247F0
#define CXWndManager__DrawWindows_x                                0x924810
#define CXWndManager__GetKeyboardFlags_x                           0x927010
#define CXWndManager__HandleKeyboardMsg_x                          0x926BC0
#define CXWndManager__RemoveWnd_x                                  0x927240
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9277A0

// CDBStr
#define CDBStr__GetString_x                                        0x545260

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFC60
#define EQ_Character__Cur_HP_x                                     0x4D2DA0
#define EQ_Character__Cur_Mana_x                                   0x4DA4F0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2CD0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3600
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3750
#define EQ_Character__GetHPRegen_x                                 0x4E03F0
#define EQ_Character__GetEnduranceRegen_x                          0x4E09F0
#define EQ_Character__GetManaRegen_x                               0x4E0E30
#define EQ_Character__Max_Endurance_x                              0x65CBA0
#define EQ_Character__Max_HP_x                                     0x4D2BD0
#define EQ_Character__Max_Mana_x                                   0x65C9A0
#define EQ_Character__doCombatAbility_x                            0x65EF90
#define EQ_Character__UseSkill_x                                   0x4E2C30
#define EQ_Character__GetConLevel_x                                0x6551A0
#define EQ_Character__IsExpansionFlag_x                            0x5B8A10
#define EQ_Character__TotalEffect_x                                0x4C6A70
#define EQ_Character__GetPCSpellAffect_x                           0x4C3A20
#define EQ_Character__SpellDuration_x                              0x4C3550
#define EQ_Character__MySpellDuration_x                            0x4B1F30
#define EQ_Character__GetAdjustedSkill_x                           0x4D5B20
#define EQ_Character__GetBaseSkill_x                               0x4D6AC0
#define EQ_Character__CanUseItem_x                                 0x4DA800

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BB3F0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x672E80

//PcClient
#define PcClient__vftable_x                                        0xAEEF40
#define PcClient__PcClient_x                                       0x652910

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA690
#define CCharacterListWnd__EnterWorld_x                            0x4BA060
#define CCharacterListWnd__Quit_x                                  0x4B9DB0
#define CCharacterListWnd__UpdateList_x                            0x4BA250

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x637220
#define EQ_Item__CreateItemTagString_x                             0x895950
#define EQ_Item__IsStackable_x                                     0x89A640
#define EQ_Item__GetImageNum_x                                     0x8974E0
#define EQ_Item__CreateItemClient_x                                0x636450
#define EQ_Item__GetItemValue_x                                    0x8987F0
#define EQ_Item__ValueSellMerchant_x                               0x89BFF0
#define EQ_Item__IsKeyRingItem_x                                   0x899F60
#define EQ_Item__CanGoInBag_x                                      0x637340
#define EQ_Item__IsEmpty_x                                         0x899AA0
#define EQ_Item__GetMaxItemCount_x                                 0x898C00
#define EQ_Item__GetHeldItem_x                                     0x8973B0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8951A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x563D50
#define EQ_LoadingS__Array_x                                       0xC0EC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65D4A0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A5020
#define EQ_PC__GetCombatAbility_x                                  0x8A5690
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A5700
#define EQ_PC__GetItemRecastTimer_x                                0x65F510
#define EQ_PC__HasLoreItem_x                                       0x6559B0
#define EQ_PC__AlertInventoryChanged_x                             0x654AE0
#define EQ_PC__GetPcZoneClient_x                                   0x681F10
#define EQ_PC__RemoveMyAffect_x                                    0x662740
#define EQ_PC__GetKeyRingItems_x                                   0x8A5F90
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A5D20
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A6290

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BEE90
#define EQItemList__add_object_x                                   0x5EC4F0
#define EQItemList__add_item_x                                     0x5BF3F0
#define EQItemList__delete_item_x                                  0x5BF440
#define EQItemList__FreeItemList_x                                 0x5BF340

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x541CF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x674780
#define EQPlayer__dEQPlayer_x                                      0x667AF0
#define EQPlayer__DoAttack_x                                       0x67C6B0
#define EQPlayer__EQPlayer_x                                       0x6681B0
#define EQPlayer__SetNameSpriteState_x                             0x66C490
#define EQPlayer__SetNameSpriteTint_x                              0x66D370
#define PlayerBase__HasProperty_j_x                                0x9871F0
#define EQPlayer__IsTargetable_x                                   0x987690
#define EQPlayer__CanSee_x                                         0x9874F0
#define EQPlayer__CanSee1_x                                        0x9875C0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9872B0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67F9B0
#define PlayerZoneClient__GetLevel_x                               0x681F50
#define PlayerZoneClient__IsValidTeleport_x                        0x5ED660
#define PlayerZoneClient__LegalPlayerRace_x                        0x55CAB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6775D0
#define EQPlayerManager__GetSpawnByName_x                          0x677680
#define EQPlayerManager__GetPlayerFromPartialName_x                0x677710

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63A8C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63A940
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63A980
#define KeypressHandler__ClearCommandStateArray_x                  0x63BD70
#define KeypressHandler__HandleKeyDown_x                           0x63BD90
#define KeypressHandler__HandleKeyUp_x                             0x63BE30
#define KeypressHandler__SaveKeymapping_x                          0x63C280

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7736B0
#define MapViewMap__SaveEx_x                                       0x776A70
#define MapViewMap__SetZoom_x                                      0x77B130

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B9450

// StringTable 
#define StringTable__getString_x                                   0x8B4260

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6623B0
#define PcZoneClient__RemovePetEffect_x                            0x6629E0
#define PcZoneClient__HasAlternateAbility_x                        0x65C7D0
#define PcZoneClient__GetCurrentMod_x                              0x4E5D50
#define PcZoneClient__GetModCap_x                                  0x4E5C50
#define PcZoneClient__CanEquipItem_x                               0x65CE80
#define PcZoneClient__GetItemByID_x                                0x65F980
#define PcZoneClient__GetItemByItemClass_x                         0x65FAD0
#define PcZoneClient__RemoveBuffEffect_x                           0x662A00
#define PcZoneClient__BandolierSwap_x                              0x65DA60
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65F4B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F2220

//IconCache
#define IconCache__GetIcon_x                                       0x715220

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70CD30
#define CContainerMgr__CloseContainer_x                            0x70D000
#define CContainerMgr__OpenExperimentContainer_x                   0x70DA80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CBE50

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62F370

//CLootWnd
#define CLootWnd__LootAll_x                                        0x769C20
#define CLootWnd__RequestLootSlot_x                                0x768F00

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58B810
#define EQ_Spell__SpellAffects_x                                   0x58BC80
#define EQ_Spell__SpellAffectBase_x                                0x58BA40
#define EQ_Spell__IsStackable_x                                    0x4CA7F0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA670
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B78E0
#define EQ_Spell__IsSPAStacking_x                                  0x58CAD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58BFE0
#define EQ_Spell__IsNoRemove_x                                     0x4CA7D0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58CAE0
#define __IsResEffectSpell_x                                       0x4C9AA0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD180

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C3AF0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x812CF0
#define CTargetWnd__WndNotification_x                              0x812530
#define CTargetWnd__RefreshTargetBuffs_x                           0x812800
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8116A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x817360
#define CTaskWnd__ConfirmAbandonTask_x                             0x819FA0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F6F0
#define CTaskManager__HandleMessage_x                              0x53DB70
#define CTaskManager__GetTaskStatus_x                              0x53F7A0
#define CTaskManager__GetElementDescription_x                      0x53F820

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x586940
#define EqSoundManager__PlayScriptMp3_x                            0x586C00
#define EqSoundManager__SoundAssistPlay_x                          0x69A380
#define EqSoundManager__WaveInstancePlay_x                         0x6998F0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530AD0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x942CD0
#define CTextureAnimation__Draw_x                                  0x942ED0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93EC20

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B800
#define CAltAbilityData__GetMercMaxRank_x                          0x56B790
#define CAltAbilityData__GetMaxRank_x                              0x560C60

//CTargetRing
#define CTargetRing__Cast_x                                        0x62D490

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA650
#define CharacterBase__CreateItemGlobalIndex_x                     0x517830
#define CharacterBase__CreateItemIndex_x                           0x6355E0
#define CharacterBase__GetItemPossession_x                         0x503530
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CC140
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CC1A0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F3CF0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F4520
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F45D0

//messages
#define msg_spell_worn_off_x                                       0x5B09C0
#define msg_new_text_x                                             0x5A5340
#define __msgTokenTextParam_x                                      0x5B2C60
#define msgTokenText_x                                             0x5B2EB0

//SpellManager
#define SpellManager__vftable_x                                    0xAD72D4
#define SpellManager__SpellManager_x                               0x69D6B0
#define Spellmanager__LoadTextSpells_x                             0x69DFA0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69D880

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98B190

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517EB0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B6E30
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64E0F0
#define ItemGlobalIndex__IsValidIndex_x                            0x517F40

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C4490
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C4710

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7624E0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x711420
#define CCursorAttachment__AttachToCursor1_x                       0x711460
#define CCursorAttachment__Deactivate_x                            0x712450

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9358E0
#define CSidlManagerBase__CreatePageWnd_x                          0x9350D0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x931350
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9312E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x952D20
#define CEQSuiteTextureLoader__GetTexture_x                        0x9529E0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514DE0
#define CFindItemWnd__WndNotification_x                            0x5158C0
#define CFindItemWnd__Update_x                                     0x516430
#define CFindItemWnd__PickupSelectedItem_x                         0x514600

//IString
#define IString__Append_x                                          0x504E30

//Camera
#define CDisplay__cameraType_x                                     0xDE6898
#define EverQuest__Cameras_x                                       0xEA1B0C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D7F0
#define LootFiltersManager__GetItemFilterData_x                    0x51D0F0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51D120
#define LootFiltersManager__SetItemLootFilter_x                    0x51D340

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B9C50

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x990DA0
#define CResolutionHandler__GetWindowedStyle_x                     0x694F00

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x709940

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9A40
#define CDistillerInfo__Instance_x                                 0x8D99E0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7288C0
#define CGroupWnd__UpdateDisplay_x                                 0x727C10

//ItemBase
#define ItemBase__IsLore_x                                         0x89A010
#define ItemBase__IsLoreEquipped_x                                 0x89A080

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EC450
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EC590
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EC5F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68A630
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68DFF0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50B120

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F7410
#define FactionManagerClient__HandleFactionMessage_x               0x4F7A80
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F8040
#define FactionManagerClient__GetMaxFaction_x                      0x4F805F
#define FactionManagerClient__GetMinFaction_x                      0x4F8010

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x503500

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91A120

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE80

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x503840

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56ACC0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A0F10

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68A630

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8CF0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BF2E0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3F1A0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BD6D0
#define CAAWnd__UpdateSelected_x                                   0x6B9F40
#define CAAWnd__Update_x                                           0x6BC9F0

//CXRect
#define CXRect__operator_and_x                                     0x71F9B0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x482F80

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
