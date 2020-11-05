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
#define __ExpectedVersionDate                                     "Nov  4 2020"
#define __ExpectedVersionTime                                     "12:13:28"
#define __ActualVersionDate_x                                      0xAF22C0
#define __ActualVersionTime_x                                      0xAF22B4
#define __ActualVersionBuild_x                                     0xAE02E4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x6406E0
#define __MemChecker1_x                                            0x8F3240
#define __MemChecker2_x                                            0x6B0A30
#define __MemChecker3_x                                            0x6B0980
#define __MemChecker4_x                                            0x849C10
#define __EncryptPad0_x                                            0xC27500
#define __EncryptPad1_x                                            0xC84D38
#define __EncryptPad2_x                                            0xC378C8
#define __EncryptPad3_x                                            0xC374C8
#define __EncryptPad4_x                                            0xC752D8
#define __EncryptPad5_x                                            0xF470B8
#define __AC1_x                                                    0x808536
#define __AC2_x                                                    0x5F9CBF
#define __AC3_x                                                    0x601310
#define __AC4_x                                                    0x6052C0
#define __AC5_x                                                    0x60B5AF
#define __AC6_x                                                    0x60FA66
#define __AC7_x                                                    0x5F9730
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
#define __CurrentMapLabel_x                                        0xF57AAC
#define __CurrentSocial_x                                          0xBFF7C8
#define __DoAbilityList_x                                          0xED6CBC
#define __do_loot_x                                                0x5C5770
#define __DrawHandler_x                                            0x15D6AA0
#define __GroupCount_x                                             0xE9B532
#define __Guilds_x                                                 0xE9F398
#define __gWorld_x                                                 0xE9B3AC
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
#define __ScreenMode_x                                             0xDE67C8
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
#define __SubscriptionType_x                                       0xF9BD70
#define __TargetAggroHolder_x                                      0xF5A460
#define __ZoneType_x                                               0xEA08D8
#define __GroupAggro_x                                             0xF5A4A0
#define __LoginName_x                                              0xF47834
#define __Inviter_x                                                0xF3F118
#define __AttackOnAssist_x                                         0xEA17D4
#define __UseTellWindows_x                                         0xEA1B00
#define __gfMaxZoomCameraDistance_x                                0xAE9EE0
#define __gfMaxCameraDistance_x                                    0xB12B48
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
#define pinstCamActor_x                                            0xDE67B8
#define pinstCDBStr_x                                              0xDE667C
#define pinstCDisplay_x                                            0xE9B384
#define pinstCEverQuest_x                                          0xF470F0
#define pinstEverQuestInfo_x                                       0xEA03F0
#define pinstCharData_x                                            0xE9B720
#define pinstCharSpawn_x                                           0xE99364
#define pinstControlledMissile_x                                   0xE99374
#define pinstControlledPlayer_x                                    0xE99364
#define pinstCResolutionHandler_x                                  0x15D6CD0
#define pinstCSidlManager_x                                        0x15D5C68
#define pinstCXWndManager_x                                        0x15D5C64
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
#define pinstImeManager_x                                          0x15D5C60
#define pinstLocalPlayer_x                                         0xE9930C
#define pinstMercenaryData_x                                       0xF41768
#define pinstMercenaryStats_x                                      0xF5A52C
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
#define pinstViewActor_x                                           0xDE67B4
#define pinstWorldData_x                                           0xE98E20
#define pinstZoneAddr_x                                            0xEA0970
#define pinstPlayerPath_x                                          0xF42410
#define pinstTargetIndicator_x                                     0xF43D78
#define EQObject_Top_x                                             0xE99104
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE6AFC
#define pinstCAchievementsWnd_x                                    0xDE6754
#define pinstCActionsWnd_x                                         0xDE6F90
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE6814
#define pinstCAdvancedLootWnd_x                                    0xDE67AC
#define pinstCAdventureLeaderboardWnd_x                            0xF51280
#define pinstCAdventureRequestWnd_x                                0xF51330
#define pinstCAdventureStatsWnd_x                                  0xF513E0
#define pinstCAggroMeterWnd_x                                      0xDE67FC
#define pinstCAlarmWnd_x                                           0xDE677C
#define pinstCAlertHistoryWnd_x                                    0xDE688C
#define pinstCAlertStackWnd_x                                      0xDE67E4
#define pinstCAlertWnd_x                                           0xDE67F8
#define pinstCAltStorageWnd_x                                      0xF51740
#define pinstCAudioTriggersWindow_x                                0xC9B2A8
#define pinstCAuraWnd_x                                            0xDE67B0
#define pinstCAvaZoneWnd_x                                         0xDE6860
#define pinstCBandolierWnd_x                                       0xDE6810
#define pinstCBankWnd_x                                            0xDE6844
#define pinstCBarterMerchantWnd_x                                  0xF52980
#define pinstCBarterSearchWnd_x                                    0xF52A30
#define pinstCBarterWnd_x                                          0xF52AE0
#define pinstCBazaarConfirmationWnd_x                              0xDE6790
#define pinstCBazaarSearchWnd_x                                    0xDE6B00
#define pinstCBazaarWnd_x                                          0xDE6760
#define pinstCBlockedBuffWnd_x                                     0xDE67D8
#define pinstCBlockedPetBuffWnd_x                                  0xDE6800
#define pinstCBodyTintWnd_x                                        0xDE6FA4
#define pinstCBookWnd_x                                            0xDE683C
#define pinstCBreathWnd_x                                          0xDE6B84
#define pinstCBuffWindowNORMAL_x                                   0xDE67A4
#define pinstCBuffWindowSHORT_x                                    0xDE67A8
#define pinstCBugReportWnd_x                                       0xDE6840
#define pinstCButtonWnd_x                                          0x15D5ED0
#define pinstCCastingWnd_x                                         0xDE6830
#define pinstCCastSpellWnd_x                                       0xDE6B0C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE6FB0
#define pinstCChatWindowManager_x                                  0xF535A0
#define pinstCClaimWnd_x                                           0xF536F8
#define pinstCColorPickerWnd_x                                     0xDE6AA8
#define pinstCCombatAbilityWnd_x                                   0xDE6770
#define pinstCCombatSkillsSelectWnd_x                              0xDE6728
#define pinstCCompassWnd_x                                         0xDE6F94
#define pinstCConfirmationDialog_x                                 0xF585F8
#define pinstCContainerMgr_x                                       0xDE6FA0
#define pinstCContextMenuManager_x                                 0x15D5C20
#define pinstCCursorAttachment_x                                   0xDE6824
#define pinstCDynamicZoneWnd_x                                     0xF53CC0
#define pinstCEditLabelWnd_x                                       0xDE67A0
#define pinstCEQMainWnd_x                                          0xF53F08
#define pinstCEventCalendarWnd_x                                   0xDE6B04
#define pinstCExtendedTargetWnd_x                                  0xDE67E0
#define pinstCFacePick_x                                           0xDE672C
#define pinstCFactionWnd_x                                         0xDE674C
#define pinstCFellowshipWnd_x                                      0xF54108
#define pinstCFileSelectionWnd_x                                   0xDE6AA4
#define pinstCFindItemWnd_x                                        0xDE673C
#define pinstCFindLocationWnd_x                                    0xF54260
#define pinstCFriendsWnd_x                                         0xDE6740
#define pinstCGemsGameWnd_x                                        0xDE6748
#define pinstCGiveWnd_x                                            0xDE6780
#define pinstCGroupSearchFiltersWnd_x                              0xDE6818
#define pinstCGroupSearchWnd_x                                     0xF54658
#define pinstCGroupWnd_x                                           0xF54708
#define pinstCGuildBankWnd_x                                       0xEA17B8
#define pinstCGuildCreationWnd_x                                   0xF54868
#define pinstCGuildMgmtWnd_x                                       0xF54918
#define pinstCharacterCreation_x                                   0xDE6734
#define pinstCHelpWnd_x                                            0xDE6784
#define pinstCHeritageSelectionWnd_x                               0xDE6738
#define pinstCHotButtonWnd_x                                       0xF56A70
#define pinstCHotButtonWnd1_x                                      0xF56A70
#define pinstCHotButtonWnd2_x                                      0xF56A74
#define pinstCHotButtonWnd3_x                                      0xF56A78
#define pinstCHotButtonWnd4_x                                      0xF56A7C
#define pinstCIconSelectionWnd_x                                   0xDE6820
#define pinstCInspectWnd_x                                         0xDE6804
#define pinstCInventoryWnd_x                                       0xDE67BC
#define pinstCInvSlotMgr_x                                         0xDE6AEC
#define pinstCItemDisplayManager_x                                 0xF57000
#define pinstCItemExpTransferWnd_x                                 0xF57130
#define pinstCItemOverflowWnd_x                                    0xDE6B08
#define pinstCJournalCatWnd_x                                      0xDE6ABC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE6878
#define pinstCKeyRingWnd_x                                         0xDE682C
#define pinstCLargeDialogWnd_x                                     0xF59278
#define pinstCLayoutCopyWnd_x                                      0xF57480
#define pinstCLFGuildWnd_x                                         0xF57530
#define pinstCLoadskinWnd_x                                        0xDE6764
#define pinstCLootFiltersCopyWnd_x                                 0xCB7958
#define pinstCLootFiltersWnd_x                                     0xDE67E8
#define pinstCLootSettingsWnd_x                                    0xDE680C
#define pinstCLootWnd_x                                            0xDE6AC0
#define pinstCMailAddressBookWnd_x                                 0xDE6AF4
#define pinstCMailCompositionWnd_x                                 0xDE6AB0
#define pinstCMailIgnoreListWnd_x                                  0xDE6AF8
#define pinstCMailWnd_x                                            0xDE6A9C
#define pinstCManageLootWnd_x                                      0xDE7E10
#define pinstCMapToolbarWnd_x                                      0xDE678C
#define pinstCMapViewWnd_x                                         0xDE6758
#define pinstCMarketplaceWnd_x                                     0xDE67EC
#define pinstCMerchantWnd_x                                        0xDE6ACC
#define pinstCMIZoneSelectWnd_x                                    0xF57D68
#define pinstCMusicPlayerWnd_x                                     0xDE6A98
#define pinstCNameChangeMercWnd_x                                  0xDE6788
#define pinstCNameChangePetWnd_x                                   0xDE675C
#define pinstCNameChangeWnd_x                                      0xDE679C
#define pinstCNoteWnd_x                                            0xDE6768
#define pinstCObjectPreviewWnd_x                                   0xDE6808
#define pinstCOptionsWnd_x                                         0xDE6774
#define pinstCPetInfoWnd_x                                         0xDE6894
#define pinstCPetitionQWnd_x                                       0xDE6724
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE6FA8
#define pinstCPlayerWnd_x                                          0xDE6888
#define pinstCPopupWndManager_x                                    0xF585F8
#define pinstCProgressionSelectionWnd_x                            0xF586A8
#define pinstCPurchaseGroupWnd_x                                   0xDE685C
#define pinstCPurchaseWnd_x                                        0xDE6834
#define pinstCPvPLeaderboardWnd_x                                  0xF58758
#define pinstCPvPStatsWnd_x                                        0xF58808
#define pinstCQuantityWnd_x                                        0xDE6874
#define pinstCRaceChangeWnd_x                                      0xDE67D0
#define pinstCRaidOptionsWnd_x                                     0xDE681C
#define pinstCRaidWnd_x                                            0xDE6AC8
#define pinstCRealEstateItemsWnd_x                                 0xDE6750
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE6F98
#define pinstCRealEstateManageWnd_x                                0xDE6864
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE6880
#define pinstCRealEstatePlotSearchWnd_x                            0xDE6AA0
#define pinstCRealEstatePurchaseWnd_x                              0xDE6AB8
#define pinstCRespawnWnd_x                                         0xDE67F4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE6720
#define pinstCSendMoneyWnd_x                                       0xDE6794
#define pinstCServerListWnd_x                                      0xDE6AC4
#define pinstCSkillsSelectWnd_x                                    0xDE671C
#define pinstCSkillsWnd_x                                          0xDE6F9C
#define pinstCSocialEditWnd_x                                      0xDE6828
#define pinstCSocialWnd_x                                          0xDE6778
#define pinstCSpellBookWnd_x                                       0xDE676C
#define pinstCStoryWnd_x                                           0xDE6F8C
#define pinstCTargetOfTargetWnd_x                                  0xF5A5B0
#define pinstCTargetWnd_x                                          0xDE67F0
#define pinstCTaskOverlayWnd_x                                     0xDE6854
#define pinstCTaskSelectWnd_x                                      0xF5A708
#define pinstCTaskManager_x                                        0xCB8298
#define pinstCTaskTemplateSelectWnd_x                              0xF5A7B8
#define pinstCTaskWnd_x                                            0xF5A868
#define pinstCTextEntryWnd_x                                       0xDE6838
#define pinstCTimeLeftWnd_x                                        0xDE6718
#define pinstCTipWndCONTEXT_x                                      0xF5AA6C
#define pinstCTipWndOFDAY_x                                        0xF5AA68
#define pinstCTitleWnd_x                                           0xF5AB18
#define pinstCTrackingWnd_x                                        0xDE67DC
#define pinstCTradeskillWnd_x                                      0xF5AC80
#define pinstCTradeWnd_x                                           0xDE6FAC
#define pinstCTrainWnd_x                                           0xDE6AB4
#define pinstCTributeBenefitWnd_x                                  0xF5AE80
#define pinstCTributeMasterWnd_x                                   0xF5AF30
#define pinstCTributeTrophyWnd_x                                   0xF5AFE0
#define pinstCVideoModesWnd_x                                      0xDE6884
#define pinstCVoiceMacroWnd_x                                      0xF44330
#define pinstCVoteResultsWnd_x                                     0xDE6744
#define pinstCVoteWnd_x                                            0xDE6730
#define pinstCWebManager_x                                         0xF449AC
#define pinstCZoneGuideWnd_x                                       0xDE6858
#define pinstCZonePathWnd_x                                        0xDE6870

#define pinstEQSuiteTextureLoader_x                                0xC85658
#define pinstItemIconCache_x                                       0xF53EC0
#define pinstLootFiltersManager_x                                  0xCB7A08
#define pinstRewardSelectionWnd_x                                  0xF58F50

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C0E60
#define __CastRay2_x                                               0x5C0EB0
#define __ConvertItemTags_x                                        0x5DCA40
#define __CleanItemTags_x                                          0x47CF10
#define __DoesFileExist_x                                          0x8F62C0
#define __EQGetTime_x                                              0x8F2E70
#define __ExecuteCmd_x                                             0x5B97C0
#define __FixHeading_x                                             0x988350
#define __FlushDxKeyboard_x                                        0x6AC8D0
#define __GameLoop_x                                               0x6AFC00
#define __get_bearing_x                                            0x5C09C0
#define __get_melee_range_x                                        0x5C10A0
#define __GetAnimationCache_x                                      0x715260
#define __GetGaugeValueFromEQ_x                                    0x8069E0
#define __GetLabelFromEQ_x                                         0x8084C0
#define __GetXTargetType_x                                         0x989E10
#define __HandleMouseWheel_x                                       0x6B0AE0
#define __HeadingDiff_x                                            0x9883C0
#define __HelpPath_x                                               0xF3F86C
#define __LoadFrontEnd_x                                           0x6ACF10
#define __NewUIINI_x                                               0x8066B0
#define __ProcessGameEvents_x                                      0x621940
#define __ProcessMouseEvent_x                                      0x6210D0
#define __SaveColors_x                                             0x55AE70
#define __STMLToText_x                                             0x92B700
#define __ToggleKeyRingItem_x                                      0x519870
#define CMemoryMappedFile__SetFile_x                               0xA77560
#define CrashDetected_x                                            0x6AE9C0
#define DrawNetStatus_x                                            0x64DB50
#define Expansion_HoT_x                                            0xEA17C0
#define Teleport_Table_Size_x                                      0xE98EB8
#define Teleport_Table_x                                           0xE99380
#define Util__FastTime_x                                           0x8F2A40
#define __CopyLayout_x                                             0x63BD50
#define __WndProc_x                                                0x6AEEC0
#define __ProcessKeyboardEvent_x                                   0x6AE460

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490150
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499140
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F10
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4936F0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492B40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x562FE0
#define AltAdvManager__IsAbilityReady_x                            0x561D80
#define AltAdvManager__GetAAById_x                                 0x562110
#define AltAdvManager__CanTrainAbility_x                           0x562180
#define AltAdvManager__CanSeeAbility_x                             0x5624E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAF70
#define CharacterZoneClient__HasSkill_x                            0x4D5DF0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7510
#define CharacterZoneClient__IsStackBlocked_x                      0x4C27A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBC30
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9EB0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9F90
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA070
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4890
#define CharacterZoneClient__BardCastBard_x                        0x4C72C0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF640
#define CharacterZoneClient__GetEffect_x                           0x4BBB70
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5900
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C59D0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5A20
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5B70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5D50
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3960
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8470
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7EF0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D6730
#define CBankWnd__WndNotification_x                                0x6D6510

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E3EB0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x928EF0
#define CButtonWnd__CButtonWnd_x                                   0x927AC0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7043D0
#define CChatManager__InitContextMenu_x                            0x6FD500
#define CChatManager__FreeChatWindow_x                             0x702F10
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9870
#define CChatManager__SetLockedActiveChatWindow_x                  0x704050
#define CChatManager__CreateChatWindow_x                           0x703550

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9980

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93C020
#define CContextMenu__dCContextMenu_x                              0x93C260
#define CContextMenu__AddMenuItem_x                                0x93C270
#define CContextMenu__RemoveMenuItem_x                             0x93C580
#define CContextMenu__RemoveAllMenuItems_x                         0x93C5A0
#define CContextMenu__CheckMenuItem_x                              0x93C620
#define CContextMenu__SetMenuItem_x                                0x93C4A0
#define CContextMenu__AddSeparator_x                               0x93C400

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93CBC0
#define CContextMenuManager__RemoveMenu_x                          0x93CC30
#define CContextMenuManager__PopupMenu_x                           0x93CCF0
#define CContextMenuManager__Flush_x                               0x93CB60
#define CContextMenuManager__GetMenu_x                             0x49B3E0
#define CContextMenuManager__CreateDefaultMenu_x                   0x70FB90

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CDA10
#define CChatService__GetFriendName_x                              0x8CDA20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x704C00
#define CChatWindow__Clear_x                                       0x705EC0
#define CChatWindow__WndNotification_x                             0x706650
#define CChatWindow__AddHistory_x                                  0x705780

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x939480
#define CComboWnd__Draw_x                                          0x938960
#define CComboWnd__GetCurChoice_x                                  0x9392C0
#define CComboWnd__GetListRect_x                                   0x938E20
#define CComboWnd__GetTextRect_x                                   0x9394F0
#define CComboWnd__InsertChoice_x                                  0x938FB0
#define CComboWnd__SetColors_x                                     0x938F80
#define CComboWnd__SetChoice_x                                     0x939290
#define CComboWnd__GetItemCount_x                                  0x9392D0
#define CComboWnd__GetCurChoiceText_x                              0x939310
#define CComboWnd__GetChoiceText_x                                 0x9392E0
#define CComboWnd__InsertChoiceAtIndex_x                           0x939050

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70D5B0
#define CContainerWnd__vftable_x                                   0xAFB4A4
#define CContainerWnd__SetContainer_x                              0x70EB10

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x555820
#define CDisplay__PreZoneMainUI_x                                  0x555830
#define CDisplay__CleanGameUI_x                                    0x55AC30
#define CDisplay__GetClickedActor_x                                0x54DC80
#define CDisplay__GetUserDefinedColor_x                            0x5462F0
#define CDisplay__GetWorldFilePath_x                               0x54F6F0
#define CDisplay__is3dON_x                                         0x54A8E0
#define CDisplay__ReloadUI_x                                       0x554D30
#define CDisplay__WriteTextHD2_x                                   0x54A6D0
#define CDisplay__TrueDistance_x                                   0x5513B0
#define CDisplay__SetViewActor_x                                   0x54D5A0
#define CDisplay__GetFloorHeight_x                                 0x54A9A0
#define CDisplay__SetRenderWindow_x                                0x549320
#define CDisplay__ToggleScreenshotMode_x                           0x54D070

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95BED0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x93F530
#define CEditWnd__EnsureCaretVisible_x                             0x941700
#define CEditWnd__GetCaretPt_x                                     0x9406B0
#define CEditWnd__GetCharIndexPt_x                                 0x940460
#define CEditWnd__GetDisplayString_x                               0x940300
#define CEditWnd__GetHorzOffset_x                                  0x93EBD0
#define CEditWnd__GetLineForPrintableChar_x                        0x941600
#define CEditWnd__GetSelStartPt_x                                  0x940710
#define CEditWnd__GetSTMLSafeText_x                                0x940120
#define CEditWnd__PointFromPrintableChar_x                         0x941230
#define CEditWnd__SelectableCharFromPoint_x                        0x9413A0
#define CEditWnd__SetEditable_x                                    0x9407E0
#define CEditWnd__SetWindowTextA_x                                 0x93FEA0
#define CEditWnd__ReplaceSelection_x                               0x940EA0
#define CEditWnd__ReplaceSelection1_x                              0x940E20

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60EF40
#define CEverQuest__ClickedPlayer_x                                0x6010F0
#define CEverQuest__CreateTargetIndicator_x                        0x61EAB0
#define CEverQuest__DeleteTargetIndicator_x                        0x61EB40
#define CEverQuest__DoTellWindow_x                                 0x4E9A60
#define CEverQuest__OutputTextToLog_x                              0x4E9D30
#define CEverQuest__DropHeldItemOnGround_x                         0x5F6240
#define CEverQuest__dsp_chat_x                                     0x4EA0C0
#define CEverQuest__trimName_x                                     0x61AC60
#define CEverQuest__Emote_x                                        0x60F7A0
#define CEverQuest__EnterZone_x                                    0x6098A0
#define CEverQuest__GetBodyTypeDesc_x                              0x6141F0
#define CEverQuest__GetClassDesc_x                                 0x614830
#define CEverQuest__GetClassThreeLetterCode_x                      0x614E30
#define CEverQuest__GetDeityDesc_x                                 0x61D300
#define CEverQuest__GetLangDesc_x                                  0x614FF0
#define CEverQuest__GetRaceDesc_x                                  0x614810
#define CEverQuest__InterpretCmd_x                                 0x61D8D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FA3E0
#define CEverQuest__LMouseUp_x                                     0x5F8760
#define CEverQuest__RightClickedOnPlayer_x                         0x5FACC0
#define CEverQuest__RMouseUp_x                                     0x5F96F0
#define CEverQuest__SetGameState_x                                 0x5F5FD0
#define CEverQuest__UPCNotificationFlush_x                         0x61AB60
#define CEverQuest__IssuePetCommand_x                              0x616400
#define CEverQuest__ReportSuccessfulHit_x                          0x610AF0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71F2B0
#define CGaugeWnd__CalcLinesFillRect_x                             0x71F310
#define CGaugeWnd__Draw_x                                          0x71E940

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFCC0
#define CGuild__GetGuildName_x                                     0x4AE770
#define CGuild__GetGuildIndex_x                                    0x4AED70

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x738F30

//CHotButton
#define CHotButton__SetCheck_x                                     0x630160
#define CHotButton__SetButtonSize_x                                0x630520

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x745FB0
#define CInvSlotMgr__MoveItem_x                                    0x744CC0
#define CInvSlotMgr__SelectSlot_x                                  0x746080

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7434F0
#define CInvSlot__SliderComplete_x                                 0x741230
#define CInvSlot__GetItemBase_x                                    0x740BC0
#define CInvSlot__UpdateItem_x                                     0x740D30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x747B00
#define CInvSlotWnd__CInvSlotWnd_x                                 0x746CA0
#define CInvSlotWnd__HandleLButtonUp_x                             0x747680

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x801D80
#define CItemDisplayWnd__UpdateStrings_x                           0x756230
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74FFA0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7504A0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x756840
#define CItemDisplayWnd__AboutToShow_x                             0x755E70
#define CItemDisplayWnd__WndNotification_x                         0x757A90
#define CItemDisplayWnd__RequestConvertItem_x                      0x7573E0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x754ED0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x755C90

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x832710

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75BFC0

// CLabel 
#define CLabel__Draw_x                                             0x761AF0

// CListWnd
#define CListWnd__CListWnd_x                                       0x911E00
#define CListWnd__dCListWnd_x                                      0x912120
#define CListWnd__AddColumn_x                                      0x9165A0
#define CListWnd__AddColumn1_x                                     0x9165F0
#define CListWnd__AddLine_x                                        0x916980
#define CListWnd__AddString_x                                      0x916780
#define CListWnd__CalculateFirstVisibleLine_x                      0x916360
#define CListWnd__CalculateVSBRange_x                              0x916140
#define CListWnd__ClearSel_x                                       0x917160
#define CListWnd__ClearAllSel_x                                    0x9171C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x917BE0
#define CListWnd__Compare_x                                        0x915A70
#define CListWnd__Draw_x                                           0x912250
#define CListWnd__DrawColumnSeparators_x                           0x914A40
#define CListWnd__DrawHeader_x                                     0x914EB0
#define CListWnd__DrawItem_x                                       0x9153B0
#define CListWnd__DrawLine_x                                       0x914BB0
#define CListWnd__DrawSeparator_x                                  0x914AE0
#define CListWnd__EnableLine_x                                     0x914310
#define CListWnd__EnsureVisible_x                                  0x917B00
#define CListWnd__ExtendSel_x                                      0x917090
#define CListWnd__GetColumnTooltip_x                               0x913E50
#define CListWnd__GetColumnMinWidth_x                              0x913EC0
#define CListWnd__GetColumnWidth_x                                 0x913DC0
#define CListWnd__GetCurSel_x                                      0x913750
#define CListWnd__GetItemAtPoint_x                                 0x914590
#define CListWnd__GetItemAtPoint1_x                                0x914600
#define CListWnd__GetItemData_x                                    0x9137D0
#define CListWnd__GetItemHeight_x                                  0x913B90
#define CListWnd__GetItemIcon_x                                    0x913960
#define CListWnd__GetItemRect_x                                    0x914400
#define CListWnd__GetItemText_x                                    0x913810
#define CListWnd__GetSelList_x                                     0x917210
#define CListWnd__GetSeparatorRect_x                               0x914840
#define CListWnd__InsertLine_x                                     0x916D70
#define CListWnd__RemoveLine_x                                     0x916EC0
#define CListWnd__SetColors_x                                      0x916110
#define CListWnd__SetColumnJustification_x                         0x915E40
#define CListWnd__SetColumnLabel_x                                 0x916720
#define CListWnd__SetColumnWidth_x                                 0x915D60
#define CListWnd__SetCurSel_x                                      0x916FD0
#define CListWnd__SetItemColor_x                                   0x9177B0
#define CListWnd__SetItemData_x                                    0x917770
#define CListWnd__SetItemText_x                                    0x917380
#define CListWnd__ShiftColumnSeparator_x                           0x915F00
#define CListWnd__Sort_x                                           0x915BF0
#define CListWnd__ToggleSel_x                                      0x917000
#define CListWnd__SetColumnsSizable_x                              0x915FB0
#define CListWnd__SetItemWnd_x                                     0x917630
#define CListWnd__GetItemWnd_x                                     0x9139B0
#define CListWnd__SetItemIcon_x                                    0x917400
#define CListWnd__CalculateCustomWindowPositions_x                 0x916460
#define CListWnd__SetVScrollPos_x                                  0x915D40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x777200
#define CMapViewWnd__GetWorldCoordinates_x                         0x775910
#define CMapViewWnd__HandleLButtonDown_x                           0x772950

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7974F0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x797DD0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x798300
#define CMerchantWnd__SelectRecoverySlot_x                         0x79B2B0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x796060
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A0E70
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x797110

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89B9F0
#define CPacketScrambler__hton_x                                   0x89B9E0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x930C90
#define CSidlManager__FindScreenPieceTemplate_x                    0x9310A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x930E90
#define CSidlManager__CreateLabel_x                                0x7F8F70
#define CSidlManager__CreateXWndFromTemplate_x                     0x934000
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9341E0
#define CSidlManager__CreateXWnd_x                                 0x7F8EA0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F9470

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92D790
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92D690
#define CSidlScreenWnd__ConvertToRes_x                             0x956970
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92D180
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92CE70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92CF40
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92D010
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92DC30
#define CSidlScreenWnd__EnableIniStorage_x                         0x92E100
#define CSidlScreenWnd__GetSidlPiece_x                             0x92DE20
#define CSidlScreenWnd__Init1_x                                    0x92CA90
#define CSidlScreenWnd__LoadIniInfo_x                              0x92E150
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92EC70
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92BEB0
#define CSidlScreenWnd__StoreIniInfo_x                             0x92E7F0
#define CSidlScreenWnd__StoreIniVis_x                              0x92EB50
#define CSidlScreenWnd__WndNotification_x                          0x92DB40
#define CSidlScreenWnd__GetChildItem_x                             0x92E080
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91D9B0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D5AF0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x695C20
#define CSkillMgr__GetSkillCap_x                                   0x695E00
#define CSkillMgr__GetNameToken_x                                  0x6953A0
#define CSkillMgr__IsActivatedSkill_x                              0x6954E0
#define CSkillMgr__IsCombatSkill_x                                 0x695420

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93D9A0
#define CSliderWnd__SetValue_x                                     0x93D810
#define CSliderWnd__SetNumTicks_x                                  0x93D870

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FF140

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x946300
#define CStmlWnd__ParseSTML_x                                      0x947610
#define CStmlWnd__CalculateHSBRange_x                              0x9473E0
#define CStmlWnd__CalculateVSBRange_x                              0x947350
#define CStmlWnd__CanBreakAtCharacter_x                            0x94B720
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94C3B0
#define CStmlWnd__ForceParseNow_x                                  0x9468A0
#define CStmlWnd__GetNextTagPiece_x                                0x94B680
#define CStmlWnd__GetSTMLText_x                                    0x50ADB0
#define CStmlWnd__GetVisibleText_x                                 0x9468C0
#define CStmlWnd__InitializeWindowVariables_x                      0x94C200
#define CStmlWnd__MakeStmlColorTag_x                               0x945970
#define CStmlWnd__MakeWndNotificationTag_x                         0x9459E0
#define CStmlWnd__SetSTMLText_x                                    0x944A20
#define CStmlWnd__StripFirstSTMLLines_x                            0x94D4B0
#define CStmlWnd__UpdateHistoryString_x                            0x94C5C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x943B70
#define CTabWnd__DrawCurrentPage_x                                 0x9442A0
#define CTabWnd__DrawTab_x                                         0x943FC0
#define CTabWnd__GetCurrentPage_x                                  0x943370
#define CTabWnd__GetPageInnerRect_x                                0x9435B0
#define CTabWnd__GetTabInnerRect_x                                 0x9434F0
#define CTabWnd__GetTabRect_x                                      0x9433A0
#define CTabWnd__InsertPage_x                                      0x9437C0
#define CTabWnd__RemovePage_x                                      0x943930
#define CTabWnd__SetPage_x                                         0x943630
#define CTabWnd__SetPageRect_x                                     0x943AB0
#define CTabWnd__UpdatePage_x                                      0x943E80
#define CTabWnd__GetPageFromTabIndex_x                             0x943F00
#define CTabWnd__GetCurrentTabIndex_x                              0x943360

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75C460
#define CPageWnd__SetTabText_x                                     0x942EB0
#define CPageWnd__FlashTab_x                                       0x942F10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8FD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91A830
#define CTextureFont__GetTextExtent_x                              0x91A9F0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A9D90
#define CHtmlComponentWnd__ValidateUri_x                           0x73A920
#define CHtmlWnd__SetClientCallbacks_x                             0x6355C0
#define CHtmlWnd__AddObserver_x                                    0x6355E0
#define CHtmlWnd__RemoveObserver_x                                 0x635640
#define Window__getProgress_x                                      0x8511C0
#define Window__getStatus_x                                        0x8511E0
#define Window__getURI_x                                           0x8511F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x953780

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x907A70

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E96B0
#define CXStr__CXStr1_x                                            0x910490
#define CXStr__CXStr3_x                                            0x8EEDF0
#define CXStr__dCXStr_x                                            0x477FE0
#define CXStr__operator_equal_x                                    0x8EF020
#define CXStr__operator_equal1_x                                   0x8EF060
#define CXStr__operator_plus_equal1_x                              0x8EFAF0
#define CXStr__SetString_x                                         0x8F19E0
#define CXStr__operator_char_p_x                                   0x8EF530
#define CXStr__GetChar_x                                           0x8F1310
#define CXStr__Delete_x                                            0x8F0BE0
#define CXStr__GetUnicode_x                                        0x8F1380
#define CXStr__GetLength_x                                         0x4A8D80
#define CXStr__Mid_x                                               0x47D2C0
#define CXStr__Insert_x                                            0x8F13E0
#define CXStr__FindNext_x                                          0x8F1050

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93BC40
#define CXWnd__BringToTop_x                                        0x921170
#define CXWnd__Center_x                                            0x920CF0
#define CXWnd__ClrFocus_x                                          0x920B00
#define CXWnd__Destroy_x                                           0x920BB0
#define CXWnd__DoAllDrawing_x                                      0x91D140
#define CXWnd__DrawChildren_x                                      0x91D110
#define CXWnd__DrawColoredRect_x                                   0x91D5A0
#define CXWnd__DrawTooltip_x                                       0x91BC50
#define CXWnd__DrawTooltipAtPoint_x                                0x91BD10
#define CXWnd__GetBorderFrame_x                                    0x91D400
#define CXWnd__GetChildWndAt_x                                     0x921210
#define CXWnd__GetClientClipRect_x                                 0x91F400
#define CXWnd__GetScreenClipRect_x                                 0x91F4D0
#define CXWnd__GetScreenRect_x                                     0x91F6A0
#define CXWnd__GetRelativeRect_x                                   0x91F760
#define CXWnd__GetTooltipRect_x                                    0x91D5F0
#define CXWnd__GetWindowTextA_x                                    0x49CB60
#define CXWnd__IsActive_x                                          0x91DD30
#define CXWnd__IsDescendantOf_x                                    0x920070
#define CXWnd__IsReallyVisible_x                                   0x9200A0
#define CXWnd__IsType_x                                            0x921880
#define CXWnd__Move_x                                              0x920110
#define CXWnd__Move1_x                                             0x9201C0
#define CXWnd__ProcessTransition_x                                 0x920CA0
#define CXWnd__Refade_x                                            0x920480
#define CXWnd__Resize_x                                            0x920750
#define CXWnd__Right_x                                             0x920F30
#define CXWnd__SetFocus_x                                          0x920AC0
#define CXWnd__SetFont_x                                           0x920B30
#define CXWnd__SetKeyTooltip_x                                     0x9216A0
#define CXWnd__SetMouseOver_x                                      0x91E570
#define CXWnd__StartFade_x                                         0x91FF50
#define CXWnd__GetChildItem_x                                      0x921380
#define CXWnd__SetParent_x                                         0x91FE10
#define CXWnd__Minimize_x                                          0x9207C0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9579F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x924060
#define CXWndManager__DrawWindows_x                                0x924080
#define CXWndManager__GetKeyboardFlags_x                           0x926750
#define CXWndManager__HandleKeyboardMsg_x                          0x926300
#define CXWndManager__RemoveWnd_x                                  0x926970
#define CXWndManager__RemovePendingDeletionWnd_x                   0x926EE0

// CDBStr
#define CDBStr__GetString_x                                        0x5452A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFDA0
#define EQ_Character__Cur_HP_x                                     0x4D2E30
#define EQ_Character__Cur_Mana_x                                   0x4DA570
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2E10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B35A0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B36F0
#define EQ_Character__GetHPRegen_x                                 0x4E0470
#define EQ_Character__GetEnduranceRegen_x                          0x4E0A70
#define EQ_Character__GetManaRegen_x                               0x4E0EB0
#define EQ_Character__Max_Endurance_x                              0x65BF70
#define EQ_Character__Max_HP_x                                     0x4D2C60
#define EQ_Character__Max_Mana_x                                   0x65BD70
#define EQ_Character__doCombatAbility_x                            0x65E360
#define EQ_Character__UseSkill_x                                   0x4E2CC0
#define EQ_Character__GetConLevel_x                                0x654AC0
#define EQ_Character__IsExpansionFlag_x                            0x5B7F90
#define EQ_Character__TotalEffect_x                                0x4C6BB0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3B60
#define EQ_Character__SpellDuration_x                              0x4C3690
#define EQ_Character__MySpellDuration_x                            0x4B1ED0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5BB0
#define EQ_Character__GetBaseSkill_x                               0x4D6B50
#define EQ_Character__CanUseItem_x                                 0x4DA880

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BAA40

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x672260

//PcClient
#define PcClient__vftable_x                                        0xAEEF3C
#define PcClient__PcClient_x                                       0x652220

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA7E0
#define CCharacterListWnd__EnterWorld_x                            0x4BA1B0
#define CCharacterListWnd__Quit_x                                  0x4B9F00
#define CCharacterListWnd__UpdateList_x                            0x4BA3A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6367A0
#define EQ_Item__CreateItemTagString_x                             0x894FA0
#define EQ_Item__IsStackable_x                                     0x899C70
#define EQ_Item__GetImageNum_x                                     0x896B40
#define EQ_Item__CreateItemClient_x                                0x6359E0
#define EQ_Item__GetItemValue_x                                    0x897E60
#define EQ_Item__ValueSellMerchant_x                               0x89B5D0
#define EQ_Item__IsKeyRingItem_x                                   0x899590
#define EQ_Item__CanGoInBag_x                                      0x6368C0
#define EQ_Item__IsEmpty_x                                         0x8990D0
#define EQ_Item__GetMaxItemCount_x                                 0x898270
#define EQ_Item__GetHeldItem_x                                     0x896A10
#define EQ_Item__GetAugmentFitBySlot_x                             0x894800

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x563CE0
#define EQ_LoadingS__Array_x                                       0xC0EC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65C870
#define EQ_PC__GetAlternateAbilityId_x                             0x8A45F0
#define EQ_PC__GetCombatAbility_x                                  0x8A4C60
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A4CD0
#define EQ_PC__GetItemRecastTimer_x                                0x65E8E0
#define EQ_PC__HasLoreItem_x                                       0x6552D0
#define EQ_PC__AlertInventoryChanged_x                             0x6543F0
#define EQ_PC__GetPcZoneClient_x                                   0x681310
#define EQ_PC__RemoveMyAffect_x                                    0x661B20
#define EQ_PC__GetKeyRingItems_x                                   0x8A5560
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A52F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A5860

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BE3C0
#define EQItemList__add_object_x                                   0x5EB8D0
#define EQItemList__add_item_x                                     0x5BE920
#define EQItemList__delete_item_x                                  0x5BE970
#define EQItemList__FreeItemList_x                                 0x5BE870

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x541E20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x673B60
#define EQPlayer__dEQPlayer_x                                      0x666EE0
#define EQPlayer__DoAttack_x                                       0x67BAA0
#define EQPlayer__EQPlayer_x                                       0x6675A0
#define EQPlayer__SetNameSpriteState_x                             0x66B870
#define EQPlayer__SetNameSpriteTint_x                              0x66C750
#define PlayerBase__HasProperty_j_x                                0x986750
#define EQPlayer__IsTargetable_x                                   0x986BF0
#define EQPlayer__CanSee_x                                         0x986A50
#define EQPlayer__CanSee1_x                                        0x986B20
#define PlayerBase__GetVisibilityLineSegment_x                     0x986810

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67EDA0
#define PlayerZoneClient__GetLevel_x                               0x681350
#define PlayerZoneClient__IsValidTeleport_x                        0x5ECA50
#define PlayerZoneClient__LegalPlayerRace_x                        0x55CAC0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6769C0
#define EQPlayerManager__GetSpawnByName_x                          0x676A70
#define EQPlayerManager__GetPlayerFromPartialName_x                0x676B00

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x639FA0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63A020
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63A060
#define KeypressHandler__ClearCommandStateArray_x                  0x63B450
#define KeypressHandler__HandleKeyDown_x                           0x63B470
#define KeypressHandler__HandleKeyUp_x                             0x63B510
#define KeypressHandler__SaveKeymapping_x                          0x63B960

// MapViewMap 
#define MapViewMap__Clear_x                                        0x773070
#define MapViewMap__SaveEx_x                                       0x776430
#define MapViewMap__SetZoom_x                                      0x77AAF0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B8AB0

// StringTable 
#define StringTable__getString_x                                   0x8B3960

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x661790
#define PcZoneClient__RemovePetEffect_x                            0x661DC0
#define PcZoneClient__HasAlternateAbility_x                        0x65BBA0
#define PcZoneClient__GetCurrentMod_x                              0x4E5DE0
#define PcZoneClient__GetModCap_x                                  0x4E5CE0
#define PcZoneClient__CanEquipItem_x                               0x65C250
#define PcZoneClient__GetItemByID_x                                0x65ED60
#define PcZoneClient__GetItemByItemClass_x                         0x65EEB0
#define PcZoneClient__RemoveBuffEffect_x                           0x661DE0
#define PcZoneClient__BandolierSwap_x                              0x65CE30
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65E880

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F1640

//IconCache
#define IconCache__GetIcon_x                                       0x714C60

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70C750
#define CContainerMgr__CloseContainer_x                            0x70CA20
#define CContainerMgr__OpenExperimentContainer_x                   0x70D4A0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CB630

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62E920

//CLootWnd
#define CLootWnd__LootAll_x                                        0x769590
#define CLootWnd__RequestLootSlot_x                                0x768860

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58B310
#define EQ_Spell__SpellAffects_x                                   0x58B780
#define EQ_Spell__SpellAffectBase_x                                0x58B540
#define EQ_Spell__IsStackable_x                                    0x4CA890
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA6B0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7A90
#define EQ_Spell__IsSPAStacking_x                                  0x58C5D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58BAE0
#define EQ_Spell__IsNoRemove_x                                     0x4CA870
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58C5E0
#define __IsResEffectSpell_x                                       0x4C9AE0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD240

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C2FC0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x812480
#define CTargetWnd__WndNotification_x                              0x811CC0
#define CTargetWnd__RefreshTargetBuffs_x                           0x811F90
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x810E20

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x816AF0
#define CTaskWnd__ConfirmAbandonTask_x                             0x819730

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F860
#define CTaskManager__HandleMessage_x                              0x53DCD0
#define CTaskManager__GetTaskStatus_x                              0x53F910
#define CTaskManager__GetElementDescription_x                      0x53F990

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5864B0
#define EqSoundManager__PlayScriptMp3_x                            0x586770
#define EqSoundManager__SoundAssistPlay_x                          0x699B60
#define EqSoundManager__WaveInstancePlay_x                         0x6990D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530E00

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9423C0
#define CTextureAnimation__Draw_x                                  0x9425C0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93E310

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B770
#define CAltAbilityData__GetMercMaxRank_x                          0x56B700
#define CAltAbilityData__GetMaxRank_x                              0x560C00

//CTargetRing
#define CTargetRing__Cast_x                                        0x62CA40

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA690
#define CharacterBase__CreateItemGlobalIndex_x                     0x517A70
#define CharacterBase__CreateItemIndex_x                           0x634B70
#define CharacterBase__GetItemPossession_x                         0x5036D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CB630
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CB690
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F3640
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F3E70
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F3F20

//messages
#define msg_spell_worn_off_x                                       0x5AFEA0
#define msg_new_text_x                                             0x5A4840
#define __msgTokenTextParam_x                                      0x5B2140
#define msgTokenText_x                                             0x5B2390

//SpellManager
#define SpellManager__vftable_x                                    0xAD72E4
#define SpellManager__SpellManager_x                               0x69CE80
#define Spellmanager__LoadTextSpells_x                             0x69D770
#define SpellManager__GetSpellByGroupAndRank_x                     0x69D050

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98A700

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5180C0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B6320
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64D9B0
#define ItemGlobalIndex__IsValidIndex_x                            0x518150

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C3960
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C3BE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x761E30

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x710E30
#define CCursorAttachment__AttachToCursor1_x                       0x710E70
#define CCursorAttachment__Deactivate_x                            0x711E60

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x935040
#define CSidlManagerBase__CreatePageWnd_x                          0x934830
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x930AB0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x930A40

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9524F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9521B0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514FF0
#define CFindItemWnd__WndNotification_x                            0x515AD0
#define CFindItemWnd__Update_x                                     0x516640
#define CFindItemWnd__PickupSelectedItem_x                         0x514820

//IString
#define IString__Append_x                                          0x504F30

//Camera
#define CDisplay__cameraType_x                                     0xDE6890
#define EverQuest__Cameras_x                                       0xEA1B0C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D9D0
#define LootFiltersManager__GetItemFilterData_x                    0x51D2E0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51D310
#define LootFiltersManager__SetItemLootFilter_x                    0x51D530

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B9470

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9902B0
#define CResolutionHandler__GetWindowedStyle_x                     0x694700

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x709370

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9070
#define CDistillerInfo__Instance_x                                 0x8D9010

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x728290
#define CGroupWnd__UpdateDisplay_x                                 0x7275E0

//ItemBase
#define ItemBase__IsLore_x                                         0x899640
#define ItemBase__IsLoreEquipped_x                                 0x8996B0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EB830
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EB970
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EB9D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x689A30
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68D380

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50B3B0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F75F0
#define FactionManagerClient__HandleFactionMessage_x               0x4F7C60
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F8260
#define FactionManagerClient__GetMaxFaction_x                      0x4F827F
#define FactionManagerClient__GetMinFaction_x                      0x4F8230

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5036A0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x919880

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE70

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x503940

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56AC20

//CTargetManager
#define CTargetManager__Get_x                                      0x6A06D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x689A30

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D90

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BE810

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3F1A0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BCE60
#define CAAWnd__UpdateSelected_x                                   0x6B96D0
#define CAAWnd__Update_x                                           0x6BC180

//CXRect
#define CXRect__operator_and_x                                     0x71F370

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
