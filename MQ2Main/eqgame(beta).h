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
#define __ExpectedVersionDate                                     "Oct 22 2020"
#define __ExpectedVersionTime                                     "04:18:02"
#define __ActualVersionDate_x                                      0xAF22C4
#define __ActualVersionTime_x                                      0xAF22B8
#define __ActualVersionBuild_x                                     0xAE02D4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x641070
#define __MemChecker1_x                                            0x8F3600
#define __MemChecker2_x                                            0x6B1320
#define __MemChecker3_x                                            0x6B1270
#define __MemChecker4_x                                            0x84A270
#define __EncryptPad0_x                                            0xC27500
#define __EncryptPad1_x                                            0xC84D40
#define __EncryptPad2_x                                            0xC378C8
#define __EncryptPad3_x                                            0xC374C8
#define __EncryptPad4_x                                            0xC752D8
#define __EncryptPad5_x                                            0xF470B8
#define __AC1_x                                                    0x808B16
#define __AC2_x                                                    0x5FA59F
#define __AC3_x                                                    0x601BF0
#define __AC4_x                                                    0x605BA0
#define __AC5_x                                                    0x60BE8F
#define __AC6_x                                                    0x610346
#define __AC7_x                                                    0x5FA010
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
#define __do_loot_x                                                0x5C6060
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
#define __gfMaxZoomCameraDistance_x                                0xAE9ED0
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
#define __CastRay_x                                                0x5C1750
#define __CastRay2_x                                               0x5C17A0
#define __ConvertItemTags_x                                        0x5DD460
#define __CleanItemTags_x                                          0x47CE70
#define __DoesFileExist_x                                          0x8F6640
#define __EQGetTime_x                                              0x8F3230
#define __ExecuteCmd_x                                             0x5BA100
#define __FixHeading_x                                             0x988A00
#define __FlushDxKeyboard_x                                        0x6AD1C0
#define __GameLoop_x                                               0x6B04F0
#define __get_bearing_x                                            0x5C12B0
#define __get_melee_range_x                                        0x5C1990
#define __GetAnimationCache_x                                      0x715950
#define __GetGaugeValueFromEQ_x                                    0x806FC0
#define __GetLabelFromEQ_x                                         0x808AA0
#define __GetXTargetType_x                                         0x98A3E0
#define __HandleMouseWheel_x                                       0x6B13D0
#define __HeadingDiff_x                                            0x988A70
#define __HelpPath_x                                               0xF3F86C
#define __LoadFrontEnd_x                                           0x6AD800
#define __NewUIINI_x                                               0x806C90
#define __ProcessGameEvents_x                                      0x622220
#define __ProcessMouseEvent_x                                      0x6219B0
#define __SaveColors_x                                             0x55AFA0
#define __STMLToText_x                                             0x92BEB0
#define __ToggleKeyRingItem_x                                      0x5198B0
#define CMemoryMappedFile__SetFile_x                               0xA77E40
#define CrashDetected_x                                            0x6AF2B0
#define DrawNetStatus_x                                            0x64E330
#define Expansion_HoT_x                                            0xEA17C0
#define Teleport_Table_Size_x                                      0xE98EB8
#define Teleport_Table_x                                           0xE99380
#define Util__FastTime_x                                           0x8F2E00
#define __CopyLayout_x                                             0x63C720
#define __WndProc_x                                                0x6AF7B0
#define __ProcessKeyboardEvent_x                                   0x6AED50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4902A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499290
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499060
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493830
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x563130
#define AltAdvManager__IsAbilityReady_x                            0x561ED0
#define AltAdvManager__GetAAById_x                                 0x562260
#define AltAdvManager__CanTrainAbility_x                           0x5622D0
#define AltAdvManager__CanSeeAbility_x                             0x562630

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CADD0
#define CharacterZoneClient__HasSkill_x                            0x4D5C50
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7370
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2490
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BB920
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9CE0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9DC0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9EA0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4580
#define CharacterZoneClient__BardCastBard_x                        0x4C6FB0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF330
#define CharacterZoneClient__GetEffect_x                           0x4BB860
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C55F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C56C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5710
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5860
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5A40
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B38C0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D82D0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7D50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D6F70
#define CBankWnd__WndNotification_x                                0x6D6D50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E4760

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x929680
#define CButtonWnd__CButtonWnd_x                                   0x928250

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x704B60
#define CChatManager__InitContextMenu_x                            0x6FDC90
#define CChatManager__FreeChatWindow_x                             0x7036A0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E97B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x7047E0
#define CChatManager__CreateChatWindow_x                           0x703CE0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E98C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93C8D0
#define CContextMenu__dCContextMenu_x                              0x93CB10
#define CContextMenu__AddMenuItem_x                                0x93CB20
#define CContextMenu__RemoveMenuItem_x                             0x93CE30
#define CContextMenu__RemoveAllMenuItems_x                         0x93CE50
#define CContextMenu__CheckMenuItem_x                              0x93CED0
#define CContextMenu__SetMenuItem_x                                0x93CD50
#define CContextMenu__AddSeparator_x                               0x93CCB0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93D460
#define CContextMenuManager__RemoveMenu_x                          0x93D4D0
#define CContextMenuManager__PopupMenu_x                           0x93D590
#define CContextMenuManager__Flush_x                               0x93D400
#define CContextMenuManager__GetMenu_x                             0x49B460
#define CContextMenuManager__CreateDefaultMenu_x                   0x7102D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x898B60
#define CChatService__GetFriendName_x                              0x8CE060

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7053D0
#define CChatWindow__Clear_x                                       0x706690
#define CChatWindow__WndNotification_x                             0x706E20
#define CChatWindow__AddHistory_x                                  0x705F50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x939D10
#define CComboWnd__Draw_x                                          0x939210
#define CComboWnd__GetCurChoice_x                                  0x939B50
#define CComboWnd__GetListRect_x                                   0x9396B0
#define CComboWnd__GetTextRect_x                                   0x939D80
#define CComboWnd__InsertChoice_x                                  0x939840
#define CComboWnd__SetColors_x                                     0x939810
#define CComboWnd__SetChoice_x                                     0x939B20
#define CComboWnd__GetItemCount_x                                  0x939B60
#define CComboWnd__GetCurChoiceText_x                              0x939BA0
#define CComboWnd__GetChoiceText_x                                 0x939B70
#define CComboWnd__InsertChoiceAtIndex_x                           0x9398E0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70DCE0
#define CContainerWnd__vftable_x                                   0xAFB4B4
#define CContainerWnd__SetContainer_x                              0x70F240

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x555950
#define CDisplay__PreZoneMainUI_x                                  0x555960
#define CDisplay__CleanGameUI_x                                    0x55AD60
#define CDisplay__GetClickedActor_x                                0x54DDB0
#define CDisplay__GetUserDefinedColor_x                            0x546430
#define CDisplay__GetWorldFilePath_x                               0x54F820
#define CDisplay__is3dON_x                                         0x54AA10
#define CDisplay__ReloadUI_x                                       0x554E60
#define CDisplay__WriteTextHD2_x                                   0x54A800
#define CDisplay__TrueDistance_x                                   0x5514E0
#define CDisplay__SetViewActor_x                                   0x54D6D0
#define CDisplay__GetFloorHeight_x                                 0x54AAD0
#define CDisplay__SetRenderWindow_x                                0x549450
#define CDisplay__ToggleScreenshotMode_x                           0x54D1A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95C620

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x93FDC0
#define CEditWnd__EnsureCaretVisible_x                             0x941F90
#define CEditWnd__GetCaretPt_x                                     0x940F40
#define CEditWnd__GetCharIndexPt_x                                 0x940CF0
#define CEditWnd__GetDisplayString_x                               0x940B90
#define CEditWnd__GetHorzOffset_x                                  0x93F460
#define CEditWnd__GetLineForPrintableChar_x                        0x941E90
#define CEditWnd__GetSelStartPt_x                                  0x940FA0
#define CEditWnd__GetSTMLSafeText_x                                0x9409B0
#define CEditWnd__PointFromPrintableChar_x                         0x941AC0
#define CEditWnd__SelectableCharFromPoint_x                        0x941C30
#define CEditWnd__SetEditable_x                                    0x941070
#define CEditWnd__SetWindowTextA_x                                 0x940730
#define CEditWnd__ReplaceSelection_x                               0x941730
#define CEditWnd__ReplaceSelection1_x                              0x9416B0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60F820
#define CEverQuest__ClickedPlayer_x                                0x6019D0
#define CEverQuest__CreateTargetIndicator_x                        0x61F390
#define CEverQuest__DeleteTargetIndicator_x                        0x61F420
#define CEverQuest__DoTellWindow_x                                 0x4E99A0
#define CEverQuest__OutputTextToLog_x                              0x4E9C70
#define CEverQuest__DropHeldItemOnGround_x                         0x5F6B30
#define CEverQuest__dsp_chat_x                                     0x4EA000
#define CEverQuest__trimName_x                                     0x61B540
#define CEverQuest__Emote_x                                        0x610080
#define CEverQuest__EnterZone_x                                    0x60A180
#define CEverQuest__GetBodyTypeDesc_x                              0x614AD0
#define CEverQuest__GetClassDesc_x                                 0x615110
#define CEverQuest__GetClassThreeLetterCode_x                      0x615710
#define CEverQuest__GetDeityDesc_x                                 0x61DBE0
#define CEverQuest__GetLangDesc_x                                  0x6158D0
#define CEverQuest__GetRaceDesc_x                                  0x6150F0
#define CEverQuest__InterpretCmd_x                                 0x61E1B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FACC0
#define CEverQuest__LMouseUp_x                                     0x5F9050
#define CEverQuest__RightClickedOnPlayer_x                         0x5FB5A0
#define CEverQuest__RMouseUp_x                                     0x5F9FD0
#define CEverQuest__SetGameState_x                                 0x5F68C0
#define CEverQuest__UPCNotificationFlush_x                         0x61B440
#define CEverQuest__IssuePetCommand_x                              0x616CE0
#define CEverQuest__ReportSuccessfulHit_x                          0x6113D0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71FA30
#define CGaugeWnd__CalcLinesFillRect_x                             0x71FA90
#define CGaugeWnd__Draw_x                                          0x71F0B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFC20
#define CGuild__GetGuildName_x                                     0x4AE6D0
#define CGuild__GetGuildIndex_x                                    0x4AECD0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x739680

//CHotButton
#define CHotButton__SetCheck_x                                     0x630C80
#define CHotButton__SetButtonSize_x                                0x631040

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x746750
#define CInvSlotMgr__MoveItem_x                                    0x745420
#define CInvSlotMgr__SelectSlot_x                                  0x746820

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x743C10
#define CInvSlot__SliderComplete_x                                 0x741960
#define CInvSlot__GetItemBase_x                                    0x7412D0
#define CInvSlot__UpdateItem_x                                     0x741440

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x748290
#define CInvSlotWnd__CInvSlotWnd_x                                 0x747420
#define CInvSlotWnd__HandleLButtonUp_x                             0x747E10

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x802330
#define CItemDisplayWnd__UpdateStrings_x                           0x7569D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7506C0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x750BD0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x756FD0
#define CItemDisplayWnd__AboutToShow_x                             0x756630
#define CItemDisplayWnd__WndNotification_x                         0x758240
#define CItemDisplayWnd__RequestConvertItem_x                      0x757B80
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7556A0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x756450

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x832E30

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75C740

// CLabel 
#define CLabel__Draw_x                                             0x762150

// CListWnd
#define CListWnd__CListWnd_x                                       0x912640
#define CListWnd__dCListWnd_x                                      0x912960
#define CListWnd__AddColumn_x                                      0x916DE0
#define CListWnd__AddColumn1_x                                     0x916E30
#define CListWnd__AddLine_x                                        0x9171C0
#define CListWnd__AddString_x                                      0x916FC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x916BA0
#define CListWnd__CalculateVSBRange_x                              0x916980
#define CListWnd__ClearSel_x                                       0x9179A0
#define CListWnd__ClearAllSel_x                                    0x917A00
#define CListWnd__CloseAndUpdateEditWindow_x                       0x918410
#define CListWnd__Compare_x                                        0x9162B0
#define CListWnd__Draw_x                                           0x912A90
#define CListWnd__DrawColumnSeparators_x                           0x915280
#define CListWnd__DrawHeader_x                                     0x9156F0
#define CListWnd__DrawItem_x                                       0x915BF0
#define CListWnd__DrawLine_x                                       0x9153F0
#define CListWnd__DrawSeparator_x                                  0x915320
#define CListWnd__EnableLine_x                                     0x914B50
#define CListWnd__EnsureVisible_x                                  0x918330
#define CListWnd__ExtendSel_x                                      0x9178D0
#define CListWnd__GetColumnTooltip_x                               0x914690
#define CListWnd__GetColumnMinWidth_x                              0x914700
#define CListWnd__GetColumnWidth_x                                 0x914600
#define CListWnd__GetCurSel_x                                      0x913F90
#define CListWnd__GetItemAtPoint_x                                 0x914DD0
#define CListWnd__GetItemAtPoint1_x                                0x914E40
#define CListWnd__GetItemData_x                                    0x914010
#define CListWnd__GetItemHeight_x                                  0x9143D0
#define CListWnd__GetItemIcon_x                                    0x9141A0
#define CListWnd__GetItemRect_x                                    0x914C40
#define CListWnd__GetItemText_x                                    0x914050
#define CListWnd__GetSelList_x                                     0x917A50
#define CListWnd__GetSeparatorRect_x                               0x915080
#define CListWnd__InsertLine_x                                     0x9175B0
#define CListWnd__RemoveLine_x                                     0x917700
#define CListWnd__SetColors_x                                      0x916950
#define CListWnd__SetColumnJustification_x                         0x916680
#define CListWnd__SetColumnLabel_x                                 0x916F60
#define CListWnd__SetColumnWidth_x                                 0x9165A0
#define CListWnd__SetCurSel_x                                      0x917810
#define CListWnd__SetItemColor_x                                   0x917FE0
#define CListWnd__SetItemData_x                                    0x917FA0
#define CListWnd__SetItemText_x                                    0x917BC0
#define CListWnd__ShiftColumnSeparator_x                           0x916740
#define CListWnd__Sort_x                                           0x916430
#define CListWnd__ToggleSel_x                                      0x917840
#define CListWnd__SetColumnsSizable_x                              0x9167F0
#define CListWnd__SetItemWnd_x                                     0x917E70
#define CListWnd__GetItemWnd_x                                     0x9141F0
#define CListWnd__SetItemIcon_x                                    0x917C40
#define CListWnd__CalculateCustomWindowPositions_x                 0x916CA0
#define CListWnd__SetVScrollPos_x                                  0x916580

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x777770
#define CMapViewWnd__GetWorldCoordinates_x                         0x775E80
#define CMapViewWnd__HandleLButtonDown_x                           0x772EC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x797A90
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x798370
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7988A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79B840
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x796610
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A1400
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7976B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89BFC0
#define CPacketScrambler__hton_x                                   0x89BFB0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x931470
#define CSidlManager__FindScreenPieceTemplate_x                    0x931880
#define CSidlManager__FindScreenPieceTemplate1_x                   0x931670
#define CSidlManager__CreateLabel_x                                0x7F9560
#define CSidlManager__CreateXWndFromTemplate_x                     0x9347E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9349B0
#define CSidlManager__CreateXWnd_x                                 0x7F9490
#define CSidlManager__CreateHotButtonWnd_x                         0x7F9A60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92DF60
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92DE60
#define CSidlScreenWnd__ConvertToRes_x                             0x957170
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92D950
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92D640
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92D710
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92D7E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92E400
#define CSidlScreenWnd__EnableIniStorage_x                         0x92E8D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x92E5F0
#define CSidlScreenWnd__Init1_x                                    0x92D240
#define CSidlScreenWnd__LoadIniInfo_x                              0x92E920
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92F450
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92C660
#define CSidlScreenWnd__StoreIniInfo_x                             0x92EFD0
#define CSidlScreenWnd__StoreIniVis_x                              0x92F330
#define CSidlScreenWnd__WndNotification_x                          0x92E310
#define CSidlScreenWnd__GetChildItem_x                             0x92E850
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91E150
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D5BF8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6964B0
#define CSkillMgr__GetSkillCap_x                                   0x696690
#define CSkillMgr__GetNameToken_x                                  0x695C30
#define CSkillMgr__IsActivatedSkill_x                              0x695D70
#define CSkillMgr__IsCombatSkill_x                                 0x695CB0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93E240
#define CSliderWnd__SetValue_x                                     0x93E0B0
#define CSliderWnd__SetNumTicks_x                                  0x93E110

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FF6C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x946B90
#define CStmlWnd__ParseSTML_x                                      0x947EA0
#define CStmlWnd__CalculateHSBRange_x                              0x947C70
#define CStmlWnd__CalculateVSBRange_x                              0x947BE0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94BFB0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94CC40
#define CStmlWnd__ForceParseNow_x                                  0x947130
#define CStmlWnd__GetNextTagPiece_x                                0x94BF10
#define CStmlWnd__GetSTMLText_x                                    0x50AD40
#define CStmlWnd__GetVisibleText_x                                 0x947150
#define CStmlWnd__InitializeWindowVariables_x                      0x94CA90
#define CStmlWnd__MakeStmlColorTag_x                               0x946200
#define CStmlWnd__MakeWndNotificationTag_x                         0x946270
#define CStmlWnd__SetSTMLText_x                                    0x9452B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x94DD40
#define CStmlWnd__UpdateHistoryString_x                            0x94CE50

// CTabWnd 
#define CTabWnd__Draw_x                                            0x944400
#define CTabWnd__DrawCurrentPage_x                                 0x944B30
#define CTabWnd__DrawTab_x                                         0x944850
#define CTabWnd__GetCurrentPage_x                                  0x943C00
#define CTabWnd__GetPageInnerRect_x                                0x943E40
#define CTabWnd__GetTabInnerRect_x                                 0x943D80
#define CTabWnd__GetTabRect_x                                      0x943C30
#define CTabWnd__InsertPage_x                                      0x944050
#define CTabWnd__RemovePage_x                                      0x9441C0
#define CTabWnd__SetPage_x                                         0x943EC0
#define CTabWnd__SetPageRect_x                                     0x944340
#define CTabWnd__UpdatePage_x                                      0x944710
#define CTabWnd__GetPageFromTabIndex_x                             0x944790
#define CTabWnd__GetCurrentTabIndex_x                              0x943BF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75CB50
#define CPageWnd__SetTabText_x                                     0x943740
#define CPageWnd__FlashTab_x                                       0x9437A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8F10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91B060
#define CTextureFont__GetTextExtent_x                              0x91B220

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AA660
#define CHtmlComponentWnd__ValidateUri_x                           0x73B070
#define CHtmlWnd__SetClientCallbacks_x                             0x6360A0
#define CHtmlWnd__AddObserver_x                                    0x6360C0
#define CHtmlWnd__RemoveObserver_x                                 0x636120
#define Window__getProgress_x                                      0x851850
#define Window__getStatus_x                                        0x851870
#define Window__getURI_x                                           0x851880

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x953F80

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x908220

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E94C0
#define CXStr__CXStr1_x                                            0x505EE0
#define CXStr__CXStr3_x                                            0x8EF1F0
#define CXStr__dCXStr_x                                            0x477FA0
#define CXStr__operator_equal_x                                    0x8EF420
#define CXStr__operator_equal1_x                                   0x8EF460
#define CXStr__operator_plus_equal1_x                              0x8EFEF0
#define CXStr__SetString_x                                         0x8F1DE0
#define CXStr__operator_char_p_x                                   0x8EF930
#define CXStr__GetChar_x                                           0x8F1710
#define CXStr__Delete_x                                            0x8F0FE0
#define CXStr__GetUnicode_x                                        0x8F1780
#define CXStr__GetLength_x                                         0x47D220
#define CXStr__Mid_x                                               0x47D230
#define CXStr__Insert_x                                            0x8F17E0
#define CXStr__FindNext_x                                          0x8F1450

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93C4D0
#define CXWnd__BringToTop_x                                        0x921910
#define CXWnd__Center_x                                            0x921490
#define CXWnd__ClrFocus_x                                          0x9212A0
#define CXWnd__Destroy_x                                           0x921350
#define CXWnd__DoAllDrawing_x                                      0x91D900
#define CXWnd__DrawChildren_x                                      0x91D8D0
#define CXWnd__DrawColoredRect_x                                   0x91DD50
#define CXWnd__DrawTooltip_x                                       0x91C450
#define CXWnd__DrawTooltipAtPoint_x                                0x91C510
#define CXWnd__GetBorderFrame_x                                    0x91DBB0
#define CXWnd__GetChildWndAt_x                                     0x9219B0
#define CXWnd__GetClientClipRect_x                                 0x91FB70
#define CXWnd__GetScreenClipRect_x                                 0x91FC40
#define CXWnd__GetScreenRect_x                                     0x91FE00
#define CXWnd__GetRelativeRect_x                                   0x91FEC0
#define CXWnd__GetTooltipRect_x                                    0x91DDA0
#define CXWnd__GetWindowTextA_x                                    0x49CB40
#define CXWnd__IsActive_x                                          0x91E4D0
#define CXWnd__IsDescendantOf_x                                    0x9207F0
#define CXWnd__IsReallyVisible_x                                   0x920820
#define CXWnd__IsType_x                                            0x922020
#define CXWnd__Move_x                                              0x920890
#define CXWnd__Move1_x                                             0x920940
#define CXWnd__ProcessTransition_x                                 0x921440
#define CXWnd__Refade_x                                            0x920C10
#define CXWnd__Resize_x                                            0x920EB0
#define CXWnd__Right_x                                             0x9216D0
#define CXWnd__SetFocus_x                                          0x921260
#define CXWnd__SetFont_x                                           0x9212D0
#define CXWnd__SetKeyTooltip_x                                     0x921E40
#define CXWnd__SetMouseOver_x                                      0x91ED10
#define CXWnd__StartFade_x                                         0x9206E0
#define CXWnd__GetChildItem_x                                      0x921B20
#define CXWnd__SetParent_x                                         0x9205A0
#define CXWnd__Minimize_x                                          0x920F20

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9581F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9247F0
#define CXWndManager__DrawWindows_x                                0x924810
#define CXWndManager__GetKeyboardFlags_x                           0x926ED0
#define CXWndManager__HandleKeyboardMsg_x                          0x926A80
#define CXWndManager__RemoveWnd_x                                  0x927100
#define CXWndManager__RemovePendingDeletionWnd_x                   0x927670

// CDBStr
#define CDBStr__GetString_x                                        0x5453F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFA90
#define EQ_Character__Cur_HP_x                                     0x4D2C90
#define EQ_Character__Cur_Mana_x                                   0x4DA3A0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2B00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3500
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3650
#define EQ_Character__GetHPRegen_x                                 0x4E0270
#define EQ_Character__GetEnduranceRegen_x                          0x4E0870
#define EQ_Character__GetManaRegen_x                               0x4E0CB0
#define EQ_Character__Max_Endurance_x                              0x65C9A0
#define EQ_Character__Max_HP_x                                     0x4D2AC0
#define EQ_Character__Max_Mana_x                                   0x65C7A0
#define EQ_Character__doCombatAbility_x                            0x65ED90
#define EQ_Character__UseSkill_x                                   0x4E2AB0
#define EQ_Character__GetConLevel_x                                0x6552C0
#define EQ_Character__IsExpansionFlag_x                            0x5B88F0
#define EQ_Character__TotalEffect_x                                0x4C68A0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3850
#define EQ_Character__SpellDuration_x                              0x4C3380
#define EQ_Character__MySpellDuration_x                            0x4B1E30
#define EQ_Character__GetAdjustedSkill_x                           0x4D5A10
#define EQ_Character__GetBaseSkill_x                               0x4D69B0
#define EQ_Character__CanUseItem_x                                 0x4DA6B0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BAFD0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x672D60

//PcClient
#define PcClient__vftable_x                                        0xAEEF2C
#define PcClient__PcClient_x                                       0x652A20

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA500
#define CCharacterListWnd__EnterWorld_x                            0x4B9ED0
#define CCharacterListWnd__Quit_x                                  0x4B9C20
#define CCharacterListWnd__UpdateList_x                            0x4BA0C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x637290
#define EQ_Item__CreateItemTagString_x                             0x895540
#define EQ_Item__IsStackable_x                                     0x89A220
#define EQ_Item__GetImageNum_x                                     0x8970F0
#define EQ_Item__CreateItemClient_x                                0x6364C0
#define EQ_Item__GetItemValue_x                                    0x8983E0
#define EQ_Item__ValueSellMerchant_x                               0x89BBA0
#define EQ_Item__IsKeyRingItem_x                                   0x899B20
#define EQ_Item__CanGoInBag_x                                      0x6373B0
#define EQ_Item__IsEmpty_x                                         0x899690
#define EQ_Item__GetMaxItemCount_x                                 0x898800
#define EQ_Item__GetHeldItem_x                                     0x896FC0
#define EQ_Item__GetAugmentFitBySlot_x                             0x894D90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x563E00
#define EQ_LoadingS__Array_x                                       0xC0EC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65D2A0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A4B90
#define EQ_PC__GetCombatAbility_x                                  0x8A5200
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A5270
#define EQ_PC__GetItemRecastTimer_x                                0x65F310
#define EQ_PC__HasLoreItem_x                                       0x655AD0
#define EQ_PC__AlertInventoryChanged_x                             0x654BF0
#define EQ_PC__GetPcZoneClient_x                                   0x681E50
#define EQ_PC__RemoveMyAffect_x                                    0x662550
#define EQ_PC__GetKeyRingItems_x                                   0x8A5B00
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A5890
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A5E00

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BECD0
#define EQItemList__add_object_x                                   0x5EC300
#define EQItemList__add_item_x                                     0x5BF230
#define EQItemList__delete_item_x                                  0x5BF280
#define EQItemList__FreeItemList_x                                 0x5BF180

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x541FE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x674660
#define EQPlayer__dEQPlayer_x                                      0x6679E0
#define EQPlayer__DoAttack_x                                       0x67C5F0
#define EQPlayer__EQPlayer_x                                       0x6680A0
#define EQPlayer__SetNameSpriteState_x                             0x66C370
#define EQPlayer__SetNameSpriteTint_x                              0x66D250
#define PlayerBase__HasProperty_j_x                                0x986DF0
#define EQPlayer__IsTargetable_x                                   0x987290
#define EQPlayer__CanSee_x                                         0x9870F0
#define EQPlayer__CanSee1_x                                        0x9871C0
#define PlayerBase__GetVisibilityLineSegment_x                     0x986EB0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67F8F0
#define PlayerZoneClient__GetLevel_x                               0x681E90
#define PlayerZoneClient__IsValidTeleport_x                        0x5ED470
#define PlayerZoneClient__LegalPlayerRace_x                        0x55CBF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6774C0
#define EQPlayerManager__GetSpawnByName_x                          0x677570
#define EQPlayerManager__GetPlayerFromPartialName_x                0x677600

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63A980
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63AA00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63AA40
#define KeypressHandler__ClearCommandStateArray_x                  0x63BE30
#define KeypressHandler__HandleKeyDown_x                           0x63BE50
#define KeypressHandler__HandleKeyUp_x                             0x63BEF0
#define KeypressHandler__SaveKeymapping_x                          0x63C340

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7735E0
#define MapViewMap__SaveEx_x                                       0x7769A0
#define MapViewMap__SetZoom_x                                      0x77B060

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B9040

// StringTable 
#define StringTable__getString_x                                   0x8B3DA0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6621C0
#define PcZoneClient__RemovePetEffect_x                            0x6627F0
#define PcZoneClient__HasAlternateAbility_x                        0x65C5D0
#define PcZoneClient__GetCurrentMod_x                              0x4E5BC0
#define PcZoneClient__GetModCap_x                                  0x4E5AC0
#define PcZoneClient__CanEquipItem_x                               0x65CC80
#define PcZoneClient__GetItemByID_x                                0x65F790
#define PcZoneClient__GetItemByItemClass_x                         0x65F8E0
#define PcZoneClient__RemoveBuffEffect_x                           0x662810
#define PcZoneClient__BandolierSwap_x                              0x65D860
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65F2B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F2040

//IconCache
#define IconCache__GetIcon_x                                       0x715350

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70CE80
#define CContainerMgr__CloseContainer_x                            0x70D150
#define CContainerMgr__OpenExperimentContainer_x                   0x70DBD0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CBB60

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62F470

//CLootWnd
#define CLootWnd__LootAll_x                                        0x769BC0
#define CLootWnd__RequestLootSlot_x                                0x768EA0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58B880
#define EQ_Spell__SpellAffects_x                                   0x58BCF0
#define EQ_Spell__SpellAffectBase_x                                0x58BAB0
#define EQ_Spell__IsStackable_x                                    0x4CA6D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA4C0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B77E0
#define EQ_Spell__IsSPAStacking_x                                  0x58CB40
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58C050
#define EQ_Spell__IsNoRemove_x                                     0x4CA6B0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58CB50
#define __IsResEffectSpell_x                                       0x4C98F0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD150

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C36D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x812A60
#define CTargetWnd__WndNotification_x                              0x8122A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x812570
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x811410

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8170E0
#define CTaskWnd__ConfirmAbandonTask_x                             0x819D10

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F9F0
#define CTaskManager__HandleMessage_x                              0x53DE60
#define CTaskManager__GetTaskStatus_x                              0x53FAA0
#define CTaskManager__GetElementDescription_x                      0x53FB20

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x586970
#define EqSoundManager__PlayScriptMp3_x                            0x586C30
#define EqSoundManager__SoundAssistPlay_x                          0x69A420
#define EqSoundManager__WaveInstancePlay_x                         0x699990

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530DB0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x942C50
#define CTextureAnimation__Draw_x                                  0x942E50

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93EBA0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B9F0
#define CAltAbilityData__GetMercMaxRank_x                          0x56B980
#define CAltAbilityData__GetMaxRank_x                              0x560D50

//CTargetRing
#define CTargetRing__Cast_x                                        0x62D590

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA4A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x517970
#define CharacterBase__CreateItemIndex_x                           0x635650
#define CharacterBase__GetItemPossession_x                         0x503750
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CBD10
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CBD70
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F3C90
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F44C0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F4570

//messages
#define msg_spell_worn_off_x                                       0x5B0970
#define msg_new_text_x                                             0x5A5310
#define __msgTokenTextParam_x                                      0x5B2C10
#define msgTokenText_x                                             0x5B2E60

//SpellManager
#define SpellManager__vftable_x                                    0xAD72D4
#define SpellManager__SpellManager_x                               0x69D750
#define Spellmanager__LoadTextSpells_x                             0x69E040
#define SpellManager__GetSpellByGroupAndRank_x                     0x69D920

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98ACD0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517FF0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B6DC0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64E190
#define ItemGlobalIndex__IsValidIndex_x                            0x518080

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C4070
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C42F0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x762490

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x711560
#define CCursorAttachment__AttachToCursor1_x                       0x7115A0
#define CCursorAttachment__Deactivate_x                            0x712590

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x935810
#define CSidlManagerBase__CreatePageWnd_x                          0x935000
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x931290
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x931220

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9529F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9526B0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514EF0
#define CFindItemWnd__WndNotification_x                            0x5159D0
#define CFindItemWnd__Update_x                                     0x516540
#define CFindItemWnd__PickupSelectedItem_x                         0x514720

//IString
#define IString__Append_x                                          0x504FF0

//Camera
#define CDisplay__cameraType_x                                     0xDE6898
#define EverQuest__Cameras_x                                       0xEA1B0C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51DA10
#define LootFiltersManager__GetItemFilterData_x                    0x51D320
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51D350
#define LootFiltersManager__SetItemLootFilter_x                    0x51D570

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B99A0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9909B0
#define CResolutionHandler__GetWindowedStyle_x                     0x694F20

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x709B40

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9610
#define CDistillerInfo__Instance_x                                 0x8D95B0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x728A00
#define CGroupWnd__UpdateDisplay_x                                 0x727D50

//ItemBase
#define ItemBase__IsLore_x                                         0x899BD0
#define ItemBase__IsLoreEquipped_x                                 0x899C50

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EC260
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EC3A0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EC400

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68A5C0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68DEF0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50B340

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F75D0
#define FactionManagerClient__HandleFactionMessage_x               0x4F7C40
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F8240
#define FactionManagerClient__GetMaxFaction_x                      0x4F825F
#define FactionManagerClient__GetMinFaction_x                      0x4F8210

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x503720

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91A0B0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE50

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x503A00

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56AE70

//CTargetManager
#define CTargetManager__Get_x                                      0x6A0FA0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68A5C0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8CD0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BF120

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3F1A0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BD680
#define CAAWnd__UpdateSelected_x                                   0x6B9EF0
#define CAAWnd__Update_x                                           0x6BC9A0

//CXRect
#define CXRect__operator_and_x                                     0x71FAF0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x482EB0

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
