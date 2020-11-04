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
#if defined(LIVE)
#include "eqgame-private(Live).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Oct 19 2020"
#define __ExpectedVersionTime                                     "13:40:42"
#define __ActualVersionDate_x                                      0xAF32BC
#define __ActualVersionTime_x                                      0xAF32B0
#define __ActualVersionBuild_x                                     0xAE12CC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x641780
#define __MemChecker1_x                                            0x8F4260
#define __MemChecker2_x                                            0x6B1EE0
#define __MemChecker3_x                                            0x6B1E30
#define __MemChecker4_x                                            0x84AB50
#define __EncryptPad0_x                                            0xC28500
#define __EncryptPad1_x                                            0xC85D38
#define __EncryptPad2_x                                            0xC388C8
#define __EncryptPad3_x                                            0xC384C8
#define __EncryptPad4_x                                            0xC762D8
#define __EncryptPad5_x                                            0xF480B8
#define __AC1_x                                                    0x809676
#define __AC2_x                                                    0x5FAD5F
#define __AC3_x                                                    0x6023B0
#define __AC4_x                                                    0x606360
#define __AC5_x                                                    0x60C64F
#define __AC6_x                                                    0x610B06
#define __AC7_x                                                    0x5FA7D0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19FCC4

// Direct Input
#define DI8__Main_x                                                0xF480D8
#define DI8__Keyboard_x                                            0xF480DC
#define DI8__Mouse_x                                               0xF480F4
#define DI8__Mouse_Copy_x                                          0xEA145C
#define DI8__Mouse_Check_x                                         0xF45C0C
#define __AutoSkillArray_x                                         0xEA2378
#define __Attack_x                                                 0xF4019B
#define __Autofire_x                                               0xF4019C
#define __BindList_x                                               0xC16F38
#define g_eqCommandStates_x                                        0xC17CB8
#define __Clicks_x                                                 0xEA1514
#define __CommandList_x                                            0xC18878
#define __CurrentMapLabel_x                                        0xF58AAC
#define __CurrentSocial_x                                          0xC007C8
#define __DoAbilityList_x                                          0xED7CBC
#define __do_loot_x                                                0x5C6860
#define __DrawHandler_x                                            0x15D7AA0
#define __GroupCount_x                                             0xE9C532
#define __Guilds_x                                                 0xEA0398
#define __gWorld_x                                                 0xE9C3AC
#define __HWnd_x                                                   0xF480F8
#define __heqmain_x                                                0xF480A0
#define __InChatMode_x                                             0xEA1444
#define __LastTell_x                                               0xEA33B8
#define __LMouseHeldTime_x                                         0xEA1580
#define __Mouse_x                                                  0xF480C4
#define __MouseLook_x                                              0xEA14DA
#define __MouseEventTime_x                                         0xF40C7C
#define __gpbCommandEvent_x                                        0xE99E30
#define __NetStatusToggle_x                                        0xEA14DD
#define __PCNames_x                                                0xEA2968
#define __RangeAttackReady_x                                       0xEA265C
#define __RMouseHeldTime_x                                         0xEA157C
#define __RunWalkState_x                                           0xEA1448
#define __ScreenMode_x                                             0xDE77C8
#define __ScreenX_x                                                0xEA13FC
#define __ScreenY_x                                                0xEA13F8
#define __ScreenXMax_x                                             0xEA1400
#define __ScreenYMax_x                                             0xEA1404
#define __ServerHost_x                                             0xE99FFB
#define __ServerName_x                                             0xED7C7C
#define __ShiftKeyDown_x                                           0xEA1AD8
#define __ShowNames_x                                              0xEA2818
#define EverQuestInfo__bSocialChanged_x                            0xED7D04
#define __Socials_x                                                0xED7D7C
#define __SubscriptionType_x                                       0xF9CD70
#define __TargetAggroHolder_x                                      0xF5B460
#define __ZoneType_x                                               0xEA18D8
#define __GroupAggro_x                                             0xF5B4A0
#define __LoginName_x                                              0xF48834
#define __Inviter_x                                                0xF40118
#define __AttackOnAssist_x                                         0xEA27D4
#define __UseTellWindows_x                                         0xEA2B00
#define __gfMaxZoomCameraDistance_x                                0xAEAEC8
#define __gfMaxCameraDistance_x                                    0xB13B48
#define __pulAutoRun_x                                             0xEA14F8
#define __pulForward_x                                             0xEA2B38
#define __pulBackward_x                                            0xEA2B3C
#define __pulTurnRight_x                                           0xEA2B40
#define __pulTurnLeft_x                                            0xEA2B44
#define __pulStrafeLeft_x                                          0xEA2B48
#define __pulStrafeRight_x                                         0xEA2B4C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9C730
#define instEQZoneInfo_x                                           0xEA16D0
#define pinstActiveBanker_x                                        0xE9A31C
#define pinstActiveCorpse_x                                        0xE9A314
#define pinstActiveGMaster_x                                       0xE9A318
#define pinstActiveMerchant_x                                      0xE9A310
#define pinstAltAdvManager_x                                       0xDE8960
#define pinstBandageTarget_x                                       0xE9A32C
#define pinstCamActor_x                                            0xDE77B8
#define pinstCDBStr_x                                              0xDE767C
#define pinstCDisplay_x                                            0xE9C384
#define pinstCEverQuest_x                                          0xF480F0
#define pinstEverQuestInfo_x                                       0xEA13F0
#define pinstCharData_x                                            0xE9C720
#define pinstCharSpawn_x                                           0xE9A364
#define pinstControlledMissile_x                                   0xE9A374
#define pinstControlledPlayer_x                                    0xE9A364
#define pinstCResolutionHandler_x                                  0x15D7CD0
#define pinstCSidlManager_x                                        0x15D6C68
#define pinstCXWndManager_x                                        0x15D6C64
#define instDynamicZone_x                                          0xEA0270
#define pinstDZMember_x                                            0xEA0380
#define pinstDZTimerInfo_x                                         0xEA0384
#define pinstEqLogin_x                                             0xF48180
#define instEQMisc_x                                               0xDE75C0
#define pinstEQSoundManager_x                                      0xDE9930
#define pinstEQSpellStrings_x                                      0xCA9F78
#define instExpeditionLeader_x                                     0xEA02BA
#define instExpeditionName_x                                       0xEA02FA
#define pinstGroup_x                                               0xE9C52E
#define pinstImeManager_x                                          0x15D6C60
#define pinstLocalPlayer_x                                         0xE9A30C
#define pinstMercenaryData_x                                       0xF42768
#define pinstMercenaryStats_x                                      0xF5B52C
#define pinstModelPlayer_x                                         0xE9A324
#define pinstPCData_x                                              0xE9C720
#define pinstSkillMgr_x                                            0xF448D0
#define pinstSpawnManager_x                                        0xF43378
#define pinstSpellManager_x                                        0xF44B10
#define pinstSpellSets_x                                           0xF38DC4
#define pinstStringTable_x                                         0xE9C728
#define pinstSwitchManager_x                                       0xE99CD0
#define pinstTarget_x                                              0xE9A360
#define pinstTargetObject_x                                        0xE9A36C
#define pinstTargetSwitch_x                                        0xE9A37C
#define pinstTaskMember_x                                          0xDE7450
#define pinstTrackTarget_x                                         0xE9A368
#define pinstTradeTarget_x                                         0xE9A320
#define instTributeActive_x                                        0xDE75E1
#define pinstViewActor_x                                           0xDE77B4
#define pinstWorldData_x                                           0xE99E20
#define pinstZoneAddr_x                                            0xEA1970
#define pinstPlayerPath_x                                          0xF43410
#define pinstTargetIndicator_x                                     0xF44D78
#define EQObject_Top_x                                             0xE9A104
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE7AFC
#define pinstCAchievementsWnd_x                                    0xDE7754
#define pinstCActionsWnd_x                                         0xDE7F90
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE7814
#define pinstCAdvancedLootWnd_x                                    0xDE77AC
#define pinstCAdventureLeaderboardWnd_x                            0xF52280
#define pinstCAdventureRequestWnd_x                                0xF52330
#define pinstCAdventureStatsWnd_x                                  0xF523E0
#define pinstCAggroMeterWnd_x                                      0xDE77FC
#define pinstCAlarmWnd_x                                           0xDE777C
#define pinstCAlertHistoryWnd_x                                    0xDE788C
#define pinstCAlertStackWnd_x                                      0xDE77E4
#define pinstCAlertWnd_x                                           0xDE77F8
#define pinstCAltStorageWnd_x                                      0xF52740
#define pinstCAudioTriggersWindow_x                                0xC9C2A8
#define pinstCAuraWnd_x                                            0xDE77B0
#define pinstCAvaZoneWnd_x                                         0xDE7860
#define pinstCBandolierWnd_x                                       0xDE7810
#define pinstCBankWnd_x                                            0xDE7844
#define pinstCBarterMerchantWnd_x                                  0xF53980
#define pinstCBarterSearchWnd_x                                    0xF53A30
#define pinstCBarterWnd_x                                          0xF53AE0
#define pinstCBazaarConfirmationWnd_x                              0xDE7790
#define pinstCBazaarSearchWnd_x                                    0xDE7B00
#define pinstCBazaarWnd_x                                          0xDE7760
#define pinstCBlockedBuffWnd_x                                     0xDE77D8
#define pinstCBlockedPetBuffWnd_x                                  0xDE7800
#define pinstCBodyTintWnd_x                                        0xDE7FA4
#define pinstCBookWnd_x                                            0xDE783C
#define pinstCBreathWnd_x                                          0xDE7B84
#define pinstCBuffWindowNORMAL_x                                   0xDE77A4
#define pinstCBuffWindowSHORT_x                                    0xDE77A8
#define pinstCBugReportWnd_x                                       0xDE7840
#define pinstCButtonWnd_x                                          0x15D6ED0
#define pinstCCastingWnd_x                                         0xDE7830
#define pinstCCastSpellWnd_x                                       0xDE7B0C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE7FB0
#define pinstCChatWindowManager_x                                  0xF545A0
#define pinstCClaimWnd_x                                           0xF546F8
#define pinstCColorPickerWnd_x                                     0xDE7AA8
#define pinstCCombatAbilityWnd_x                                   0xDE7770
#define pinstCCombatSkillsSelectWnd_x                              0xDE7728
#define pinstCCompassWnd_x                                         0xDE7F94
#define pinstCConfirmationDialog_x                                 0xF595F8
#define pinstCContainerMgr_x                                       0xDE7FA0
#define pinstCContextMenuManager_x                                 0x15D6C20
#define pinstCCursorAttachment_x                                   0xDE7824
#define pinstCDynamicZoneWnd_x                                     0xF54CC0
#define pinstCEditLabelWnd_x                                       0xDE77A0
#define pinstCEQMainWnd_x                                          0xF54F08
#define pinstCEventCalendarWnd_x                                   0xDE7B04
#define pinstCExtendedTargetWnd_x                                  0xDE77E0
#define pinstCFacePick_x                                           0xDE772C
#define pinstCFactionWnd_x                                         0xDE774C
#define pinstCFellowshipWnd_x                                      0xF55108
#define pinstCFileSelectionWnd_x                                   0xDE7AA4
#define pinstCFindItemWnd_x                                        0xDE773C
#define pinstCFindLocationWnd_x                                    0xF55260
#define pinstCFriendsWnd_x                                         0xDE7740
#define pinstCGemsGameWnd_x                                        0xDE7748
#define pinstCGiveWnd_x                                            0xDE7780
#define pinstCGroupSearchFiltersWnd_x                              0xDE7818
#define pinstCGroupSearchWnd_x                                     0xF55658
#define pinstCGroupWnd_x                                           0xF55708
#define pinstCGuildBankWnd_x                                       0xEA27B8
#define pinstCGuildCreationWnd_x                                   0xF55868
#define pinstCGuildMgmtWnd_x                                       0xF55918
#define pinstCharacterCreation_x                                   0xDE7734
#define pinstCHelpWnd_x                                            0xDE7784
#define pinstCHeritageSelectionWnd_x                               0xDE7738
#define pinstCHotButtonWnd_x                                       0xF57A70
#define pinstCHotButtonWnd1_x                                      0xF57A70
#define pinstCHotButtonWnd2_x                                      0xF57A74
#define pinstCHotButtonWnd3_x                                      0xF57A78
#define pinstCHotButtonWnd4_x                                      0xF57A7C
#define pinstCIconSelectionWnd_x                                   0xDE7820
#define pinstCInspectWnd_x                                         0xDE7804
#define pinstCInventoryWnd_x                                       0xDE77BC
#define pinstCInvSlotMgr_x                                         0xDE7AEC
#define pinstCItemDisplayManager_x                                 0xF58000
#define pinstCItemExpTransferWnd_x                                 0xF58130
#define pinstCItemOverflowWnd_x                                    0xDE7B08
#define pinstCJournalCatWnd_x                                      0xDE7ABC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE7878
#define pinstCKeyRingWnd_x                                         0xDE782C
#define pinstCLargeDialogWnd_x                                     0xF5A278
#define pinstCLayoutCopyWnd_x                                      0xF58480
#define pinstCLFGuildWnd_x                                         0xF58530
#define pinstCLoadskinWnd_x                                        0xDE7764
#define pinstCLootFiltersCopyWnd_x                                 0xCB8958
#define pinstCLootFiltersWnd_x                                     0xDE77E8
#define pinstCLootSettingsWnd_x                                    0xDE780C
#define pinstCLootWnd_x                                            0xDE7AC0
#define pinstCMailAddressBookWnd_x                                 0xDE7AF4
#define pinstCMailCompositionWnd_x                                 0xDE7AB0
#define pinstCMailIgnoreListWnd_x                                  0xDE7AF8
#define pinstCMailWnd_x                                            0xDE7A9C
#define pinstCManageLootWnd_x                                      0xDE8E10
#define pinstCMapToolbarWnd_x                                      0xDE778C
#define pinstCMapViewWnd_x                                         0xDE7758
#define pinstCMarketplaceWnd_x                                     0xDE77EC
#define pinstCMerchantWnd_x                                        0xDE7ACC
#define pinstCMIZoneSelectWnd_x                                    0xF58D68
#define pinstCMusicPlayerWnd_x                                     0xDE7A98
#define pinstCNameChangeMercWnd_x                                  0xDE7788
#define pinstCNameChangePetWnd_x                                   0xDE775C
#define pinstCNameChangeWnd_x                                      0xDE779C
#define pinstCNoteWnd_x                                            0xDE7768
#define pinstCObjectPreviewWnd_x                                   0xDE7808
#define pinstCOptionsWnd_x                                         0xDE7774
#define pinstCPetInfoWnd_x                                         0xDE7894
#define pinstCPetitionQWnd_x                                       0xDE7724
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE7FA8
#define pinstCPlayerWnd_x                                          0xDE7888
#define pinstCPopupWndManager_x                                    0xF595F8
#define pinstCProgressionSelectionWnd_x                            0xF596A8
#define pinstCPurchaseGroupWnd_x                                   0xDE785C
#define pinstCPurchaseWnd_x                                        0xDE7834
#define pinstCPvPLeaderboardWnd_x                                  0xF59758
#define pinstCPvPStatsWnd_x                                        0xF59808
#define pinstCQuantityWnd_x                                        0xDE7874
#define pinstCRaceChangeWnd_x                                      0xDE77D0
#define pinstCRaidOptionsWnd_x                                     0xDE781C
#define pinstCRaidWnd_x                                            0xDE7AC8
#define pinstCRealEstateItemsWnd_x                                 0xDE7750
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE7F98
#define pinstCRealEstateManageWnd_x                                0xDE7864
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE7880
#define pinstCRealEstatePlotSearchWnd_x                            0xDE7AA0
#define pinstCRealEstatePurchaseWnd_x                              0xDE7AB8
#define pinstCRespawnWnd_x                                         0xDE77F4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE7720
#define pinstCSendMoneyWnd_x                                       0xDE7794
#define pinstCServerListWnd_x                                      0xDE7AC4
#define pinstCSkillsSelectWnd_x                                    0xDE771C
#define pinstCSkillsWnd_x                                          0xDE7F9C
#define pinstCSocialEditWnd_x                                      0xDE7828
#define pinstCSocialWnd_x                                          0xDE7778
#define pinstCSpellBookWnd_x                                       0xDE776C
#define pinstCStoryWnd_x                                           0xDE7F8C
#define pinstCTargetOfTargetWnd_x                                  0xF5B5B0
#define pinstCTargetWnd_x                                          0xDE77F0
#define pinstCTaskOverlayWnd_x                                     0xDE7854
#define pinstCTaskSelectWnd_x                                      0xF5B708
#define pinstCTaskManager_x                                        0xCB9298
#define pinstCTaskTemplateSelectWnd_x                              0xF5B7B8
#define pinstCTaskWnd_x                                            0xF5B868
#define pinstCTextEntryWnd_x                                       0xDE7838
#define pinstCTimeLeftWnd_x                                        0xDE7718
#define pinstCTipWndCONTEXT_x                                      0xF5BA6C
#define pinstCTipWndOFDAY_x                                        0xF5BA68
#define pinstCTitleWnd_x                                           0xF5BB18
#define pinstCTrackingWnd_x                                        0xDE77DC
#define pinstCTradeskillWnd_x                                      0xF5BC80
#define pinstCTradeWnd_x                                           0xDE7FAC
#define pinstCTrainWnd_x                                           0xDE7AB4
#define pinstCTributeBenefitWnd_x                                  0xF5BE80
#define pinstCTributeMasterWnd_x                                   0xF5BF30
#define pinstCTributeTrophyWnd_x                                   0xF5BFE0
#define pinstCVideoModesWnd_x                                      0xDE7884
#define pinstCVoiceMacroWnd_x                                      0xF45330
#define pinstCVoteResultsWnd_x                                     0xDE7744
#define pinstCVoteWnd_x                                            0xDE7730
#define pinstCWebManager_x                                         0xF459AC
#define pinstCZoneGuideWnd_x                                       0xDE7858
#define pinstCZonePathWnd_x                                        0xDE7870

#define pinstEQSuiteTextureLoader_x                                0xC86658
#define pinstItemIconCache_x                                       0xF54EC0
#define pinstLootFiltersManager_x                                  0xCB8A08
#define pinstRewardSelectionWnd_x                                  0xF59F50

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C1F50
#define __CastRay2_x                                               0x5C1FA0
#define __ConvertItemTags_x                                        0x5DDB30
#define __CleanItemTags_x                                          0x47CC80
#define __DoesFileExist_x                                          0x8F7390
#define __EQGetTime_x                                              0x8F3E90
#define __ExecuteCmd_x                                             0x5BA8C0
#define __FixHeading_x                                             0x9893E0
#define __FlushDxKeyboard_x                                        0x6ADD80
#define __GameLoop_x                                               0x6B10B0
#define __get_bearing_x                                            0x5C1AB0
#define __get_melee_range_x                                        0x5C2190
#define __GetAnimationCache_x                                      0x716480
#define __GetGaugeValueFromEQ_x                                    0x807B20
#define __GetLabelFromEQ_x                                         0x809600
#define __GetXTargetType_x                                         0x98AEA0
#define __HandleMouseWheel_x                                       0x6B1F90
#define __HeadingDiff_x                                            0x989450
#define __HelpPath_x                                               0xF4086C
#define __LoadFrontEnd_x                                           0x6AE3C0
#define __NewUIINI_x                                               0x8077F0
#define __ProcessGameEvents_x                                      0x6229E0
#define __ProcessMouseEvent_x                                      0x622170
#define __SaveColors_x                                             0x55A910
#define __STMLToText_x                                             0x92C5D0
#define __ToggleKeyRingItem_x                                      0x519300
#define CMemoryMappedFile__SetFile_x                               0xA78670
#define CrashDetected_x                                            0x6AFE70
#define DrawNetStatus_x                                            0x64EBE0
#define Expansion_HoT_x                                            0xEA27C0
#define Teleport_Table_Size_x                                      0xE99EB8
#define Teleport_Table_x                                           0xE9A380
#define Util__FastTime_x                                           0x8F3A60
#define __CopyLayout_x                                             0x63CE60
#define __WndProc_x                                                0x6B0370
#define __ProcessKeyboardEvent_x                                   0x6AF910

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490060
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499050
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498E20
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4935F0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492A40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x562A80
#define AltAdvManager__IsAbilityReady_x                            0x561820
#define AltAdvManager__GetAAById_x                                 0x561BB0
#define AltAdvManager__CanTrainAbility_x                           0x561C20
#define AltAdvManager__CanSeeAbility_x                             0x561F80

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAB90
#define CharacterZoneClient__HasSkill_x                            0x4D5A10
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7130
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2470
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BB900
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9AF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9BD0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9CB0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4550
#define CharacterZoneClient__BardCastBard_x                        0x4C6F80
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF310
#define CharacterZoneClient__GetEffect_x                           0x4BB840
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C55C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5690
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C56E0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5830
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5A10
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B35F0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8090
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7B10

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D7C60
#define CBankWnd__WndNotification_x                                0x6D7A40

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E5710

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x929DB0
#define CButtonWnd__CButtonWnd_x                                   0x928980

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x705650
#define CChatManager__InitContextMenu_x                            0x6FE790
#define CChatManager__FreeChatWindow_x                             0x704190
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9590
#define CChatManager__SetLockedActiveChatWindow_x                  0x7052D0
#define CChatManager__CreateChatWindow_x                           0x7047D0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E96A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93CFB0
#define CContextMenu__dCContextMenu_x                              0x93D1E0
#define CContextMenu__AddMenuItem_x                                0x93D1F0
#define CContextMenu__RemoveMenuItem_x                             0x93D500
#define CContextMenu__RemoveAllMenuItems_x                         0x93D520
#define CContextMenu__CheckMenuItem_x                              0x93D5A0
#define CContextMenu__SetMenuItem_x                                0x93D420
#define CContextMenu__AddSeparator_x                               0x93D380

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93DB40
#define CContextMenuManager__RemoveMenu_x                          0x93DBB0
#define CContextMenuManager__PopupMenu_x                           0x93DC70
#define CContextMenuManager__Flush_x                               0x93DAE0
#define CContextMenuManager__GetMenu_x                             0x49B1F0
#define CContextMenuManager__CreateDefaultMenu_x                   0x710DE0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CED10
#define CChatService__GetFriendName_x                              0x8CED20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x705E80
#define CChatWindow__Clear_x                                       0x707140
#define CChatWindow__WndNotification_x                             0x7078D0
#define CChatWindow__AddHistory_x                                  0x706A00

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93A410
#define CComboWnd__Draw_x                                          0x939910
#define CComboWnd__GetCurChoice_x                                  0x93A250
#define CComboWnd__GetListRect_x                                   0x939DC0
#define CComboWnd__GetTextRect_x                                   0x93A480
#define CComboWnd__InsertChoice_x                                  0x939F50
#define CComboWnd__SetColors_x                                     0x939F20
#define CComboWnd__SetChoice_x                                     0x93A220
#define CComboWnd__GetItemCount_x                                  0x93A260
#define CComboWnd__GetCurChoiceText_x                              0x93A2A0
#define CComboWnd__GetChoiceText_x                                 0x93A270
#define CComboWnd__InsertChoiceAtIndex_x                           0x939FE0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70E810
#define CContainerWnd__vftable_x                                   0xAFC4AC
#define CContainerWnd__SetContainer_x                              0x70FD60

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5552C0
#define CDisplay__PreZoneMainUI_x                                  0x5552D0
#define CDisplay__CleanGameUI_x                                    0x55A6D0
#define CDisplay__GetClickedActor_x                                0x54D720
#define CDisplay__GetUserDefinedColor_x                            0x545D90
#define CDisplay__GetWorldFilePath_x                               0x54F190
#define CDisplay__is3dON_x                                         0x54A380
#define CDisplay__ReloadUI_x                                       0x5547D0
#define CDisplay__WriteTextHD2_x                                   0x54A170
#define CDisplay__TrueDistance_x                                   0x550E50
#define CDisplay__SetViewActor_x                                   0x54D040
#define CDisplay__GetFloorHeight_x                                 0x54A440
#define CDisplay__SetRenderWindow_x                                0x548DC0
#define CDisplay__ToggleScreenshotMode_x                           0x54CB10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95CEA0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9404B0
#define CEditWnd__EnsureCaretVisible_x                             0x942680
#define CEditWnd__GetCaretPt_x                                     0x941630
#define CEditWnd__GetCharIndexPt_x                                 0x9413E0
#define CEditWnd__GetDisplayString_x                               0x941280
#define CEditWnd__GetHorzOffset_x                                  0x93FB50
#define CEditWnd__GetLineForPrintableChar_x                        0x942580
#define CEditWnd__GetSelStartPt_x                                  0x941690
#define CEditWnd__GetSTMLSafeText_x                                0x9410A0
#define CEditWnd__PointFromPrintableChar_x                         0x9421B0
#define CEditWnd__SelectableCharFromPoint_x                        0x942320
#define CEditWnd__SetEditable_x                                    0x941760
#define CEditWnd__SetWindowTextA_x                                 0x940E20
#define CEditWnd__ReplaceSelection_x                               0x941E20
#define CEditWnd__ReplaceSelection1_x                              0x941DA0
// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60FFE0
#define CEverQuest__ClickedPlayer_x                                0x602190
#define CEverQuest__CreateTargetIndicator_x                        0x61FB50
#define CEverQuest__DeleteTargetIndicator_x                        0x61FBE0
#define CEverQuest__DoTellWindow_x                                 0x4E9780
#define CEverQuest__OutputTextToLog_x                              0x4E9A50
#define CEverQuest__DropHeldItemOnGround_x                         0x5F72E0
#define CEverQuest__dsp_chat_x                                     0x4E9DE0
#define CEverQuest__trimName_x                                     0x61BD00
#define CEverQuest__Emote_x                                        0x610840
#define CEverQuest__EnterZone_x                                    0x60A940
#define CEverQuest__GetBodyTypeDesc_x                              0x615290
#define CEverQuest__GetClassDesc_x                                 0x6158D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x615ED0
#define CEverQuest__GetDeityDesc_x                                 0x61E3A0
#define CEverQuest__GetLangDesc_x                                  0x616090
#define CEverQuest__GetRaceDesc_x                                  0x6158B0
#define CEverQuest__InterpretCmd_x                                 0x61E970
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FB480
#define CEverQuest__LMouseUp_x                                     0x5F9800
#define CEverQuest__RightClickedOnPlayer_x                         0x5FBD60
#define CEverQuest__RMouseUp_x                                     0x5FA790
#define CEverQuest__SetGameState_x                                 0x5F7070
#define CEverQuest__UPCNotificationFlush_x                         0x61BC00
#define CEverQuest__IssuePetCommand_x                              0x6174A0
#define CEverQuest__ReportSuccessfulHit_x                          0x611B90

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7203F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x720450
#define CGaugeWnd__Draw_x                                          0x71FA70

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF920
#define CGuild__GetGuildName_x                                     0x4AE3D0
#define CGuild__GetGuildIndex_x                                    0x4AE9D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73A010

//CHotButton
#define CHotButton__SetCheck_x                                     0x631370
#define CHotButton__SetButtonSize_x                                0x631730

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x747060
#define CInvSlotMgr__MoveItem_x                                    0x745D70
#define CInvSlotMgr__SelectSlot_x                                  0x747130

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7445A0
#define CInvSlot__SliderComplete_x                                 0x7422E0
#define CInvSlot__GetItemBase_x                                    0x741C80
#define CInvSlot__UpdateItem_x                                     0x741DF0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x748BB0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x747D50
#define CInvSlotWnd__HandleLButtonUp_x                             0x748730

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x802EB0
#define CItemDisplayWnd__UpdateStrings_x                           0x7572A0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x751000
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x751500
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7578B0
#define CItemDisplayWnd__AboutToShow_x                             0x756EE0
#define CItemDisplayWnd__WndNotification_x                         0x758B10
#define CItemDisplayWnd__RequestConvertItem_x                      0x758450
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x755F40
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x756D00

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x833950

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75D040

// CLabel 
#define CLabel__Draw_x                                             0x762A50

// CListWnd
#define CListWnd__CListWnd_x                                       0x912C00
#define CListWnd__dCListWnd_x                                      0x912F20
#define CListWnd__AddColumn_x                                      0x9173A0
#define CListWnd__AddColumn1_x                                     0x9173F0
#define CListWnd__AddLine_x                                        0x917780
#define CListWnd__AddString_x                                      0x917580
#define CListWnd__CalculateFirstVisibleLine_x                      0x917160
#define CListWnd__CalculateVSBRange_x                              0x916F50
#define CListWnd__ClearSel_x                                       0x917F60
#define CListWnd__ClearAllSel_x                                    0x917FC0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9189D0
#define CListWnd__Compare_x                                        0x916880
#define CListWnd__Draw_x                                           0x913050
#define CListWnd__DrawColumnSeparators_x                           0x915850
#define CListWnd__DrawHeader_x                                     0x915CC0
#define CListWnd__DrawItem_x                                       0x9161C0
#define CListWnd__DrawLine_x                                       0x9159C0
#define CListWnd__DrawSeparator_x                                  0x9158F0
#define CListWnd__EnableLine_x                                     0x915120
#define CListWnd__EnsureVisible_x                                  0x9188F0
#define CListWnd__ExtendSel_x                                      0x917E90
#define CListWnd__GetColumnTooltip_x                               0x914C60
#define CListWnd__GetColumnMinWidth_x                              0x914CD0
#define CListWnd__GetColumnWidth_x                                 0x914BD0
#define CListWnd__GetCurSel_x                                      0x914560
#define CListWnd__GetItemAtPoint_x                                 0x9153A0
#define CListWnd__GetItemAtPoint1_x                                0x915410
#define CListWnd__GetItemData_x                                    0x9145E0
#define CListWnd__GetItemHeight_x                                  0x9149A0
#define CListWnd__GetItemIcon_x                                    0x914770
#define CListWnd__GetItemRect_x                                    0x915210
#define CListWnd__GetItemText_x                                    0x914620
#define CListWnd__GetSelList_x                                     0x918010
#define CListWnd__GetSeparatorRect_x                               0x915650
#define CListWnd__InsertLine_x                                     0x917B70
#define CListWnd__RemoveLine_x                                     0x917CC0
#define CListWnd__SetColors_x                                      0x916F20
#define CListWnd__SetColumnJustification_x                         0x916C50
#define CListWnd__SetColumnLabel_x                                 0x917520
#define CListWnd__SetColumnWidth_x                                 0x916B70
#define CListWnd__SetCurSel_x                                      0x917DD0
#define CListWnd__SetItemColor_x                                   0x9185A0
#define CListWnd__SetItemData_x                                    0x918560
#define CListWnd__SetItemText_x                                    0x918180
#define CListWnd__ShiftColumnSeparator_x                           0x916D10
#define CListWnd__Sort_x                                           0x916A00
#define CListWnd__ToggleSel_x                                      0x917E00
#define CListWnd__SetColumnsSizable_x                              0x916DC0
#define CListWnd__SetItemWnd_x                                     0x918430
#define CListWnd__GetItemWnd_x                                     0x9147C0
#define CListWnd__SetItemIcon_x                                    0x918200
#define CListWnd__CalculateCustomWindowPositions_x                 0x917260
#define CListWnd__SetVScrollPos_x                                  0x916B50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7780A0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7767B0
#define CMapViewWnd__HandleLButtonDown_x                           0x7737F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x798310
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x798BF0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x799120
#define CMerchantWnd__SelectRecoverySlot_x                         0x79C0D0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x796E70
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A1C90
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x797F20

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89CDF0
#define CPacketScrambler__hton_x                                   0x89CDE0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x931BB0
#define CSidlManager__FindScreenPieceTemplate_x                    0x931FC0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x931DB0
#define CSidlManager__CreateLabel_x                                0x7FA0E0
#define CSidlManager__CreateXWndFromTemplate_x                     0x934F20
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9350F0
#define CSidlManager__CreateXWnd_x                                 0x7FA010
#define CSidlManager__CreateHotButtonWnd_x                         0x7FA5C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92E680
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92E580
#define CSidlScreenWnd__ConvertToRes_x                             0x9579F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92E080
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92DD70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92DE40
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92DF10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92EB20
#define CSidlScreenWnd__EnableIniStorage_x                         0x92EFF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x92ED10
#define CSidlScreenWnd__Init1_x                                    0x92D970
#define CSidlScreenWnd__LoadIniInfo_x                              0x92F040
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92FB90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92CD80
#define CSidlScreenWnd__StoreIniInfo_x                             0x92F710
#define CSidlScreenWnd__StoreIniVis_x                              0x92FA70
#define CSidlScreenWnd__WndNotification_x                          0x92EA30
#define CSidlScreenWnd__GetChildItem_x                             0x92EF70
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91E790
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D6AF0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x696E00
#define CSkillMgr__GetSkillCap_x                                   0x696FE0
#define CSkillMgr__GetNameToken_x                                  0x696580
#define CSkillMgr__IsActivatedSkill_x                              0x6966C0
#define CSkillMgr__IsCombatSkill_x                                 0x696600

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93E920
#define CSliderWnd__SetValue_x                                     0x93E790
#define CSliderWnd__SetNumTicks_x                                  0x93E7F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x800270

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x947260
#define CStmlWnd__ParseSTML_x                                      0x948560
#define CStmlWnd__CalculateHSBRange_x                              0x948340
#define CStmlWnd__CalculateVSBRange_x                              0x9482B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94C670
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94D300
#define CStmlWnd__ForceParseNow_x                                  0x947800
#define CStmlWnd__GetNextTagPiece_x                                0x94C5D0
#define CStmlWnd__GetSTMLText_x                                    0x50A6F0
#define CStmlWnd__GetVisibleText_x                                 0x947820
#define CStmlWnd__InitializeWindowVariables_x                      0x94D150
#define CStmlWnd__MakeStmlColorTag_x                               0x9468D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x946940
#define CStmlWnd__SetSTMLText_x                                    0x945980
#define CStmlWnd__StripFirstSTMLLines_x                            0x94E400
#define CStmlWnd__UpdateHistoryString_x                            0x94D510

// CTabWnd 
#define CTabWnd__Draw_x                                            0x944AD0
#define CTabWnd__DrawCurrentPage_x                                 0x945200
#define CTabWnd__DrawTab_x                                         0x944F20
#define CTabWnd__GetCurrentPage_x                                  0x9442E0
#define CTabWnd__GetPageInnerRect_x                                0x944520
#define CTabWnd__GetTabInnerRect_x                                 0x944460
#define CTabWnd__GetTabRect_x                                      0x944310
#define CTabWnd__InsertPage_x                                      0x944730
#define CTabWnd__RemovePage_x                                      0x9448A0
#define CTabWnd__SetPage_x                                         0x9445A0
#define CTabWnd__SetPageRect_x                                     0x944A10
#define CTabWnd__UpdatePage_x                                      0x944DE0
#define CTabWnd__GetPageFromTabIndex_x                             0x944E60
#define CTabWnd__GetCurrentTabIndex_x                              0x9442D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75D450
#define CPageWnd__SetTabText_x                                     0x943E30
#define CPageWnd__FlashTab_x                                       0x943E90

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8C40

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91B640
#define CTextureFont__GetTextExtent_x                              0x91B800

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AAF50
#define CHtmlComponentWnd__ValidateUri_x                           0x73BA00
#define CHtmlWnd__SetClientCallbacks_x                             0x6367D0
#define CHtmlWnd__AddObserver_x                                    0x6367F0
#define CHtmlWnd__RemoveObserver_x                                 0x636850
#define Window__getProgress_x                                      0x852120
#define Window__getStatus_x                                        0x852140
#define Window__getURI_x                                           0x852150

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x954800

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x908890

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E93D0
#define CXStr__CXStr1_x                                            0x9DFB30
#define CXStr__CXStr3_x                                            0x8EFE10
#define CXStr__dCXStr_x                                            0x477EF0
#define CXStr__operator_equal_x                                    0x8F0040
#define CXStr__operator_equal1_x                                   0x8F0080
#define CXStr__operator_plus_equal1_x                              0x8F0B10
#define CXStr__SetString_x                                         0x8F2A00
#define CXStr__operator_char_p_x                                   0x8F0550
#define CXStr__GetChar_x                                           0x8F2350
#define CXStr__Delete_x                                            0x8F1C00
#define CXStr__GetUnicode_x                                        0x8F23C0
#define CXStr__GetLength_x                                         0x47D030
#define CXStr__Mid_x                                               0x47D040
#define CXStr__Insert_x                                            0x8F2420
#define CXStr__FindNext_x                                          0x8F2070

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93CBC0
#define CXWnd__BringToTop_x                                        0x921EC0
#define CXWnd__Center_x                                            0x921A40
#define CXWnd__ClrFocus_x                                          0x921860
#define CXWnd__Destroy_x                                           0x921900
#define CXWnd__DoAllDrawing_x                                      0x91DF30
#define CXWnd__DrawChildren_x                                      0x91DF00
#define CXWnd__DrawColoredRect_x                                   0x91E380
#define CXWnd__DrawTooltip_x                                       0x91CA50
#define CXWnd__DrawTooltipAtPoint_x                                0x91CB10
#define CXWnd__GetBorderFrame_x                                    0x91E1E0
#define CXWnd__GetChildWndAt_x                                     0x921F60
#define CXWnd__GetClientClipRect_x                                 0x9201D0
#define CXWnd__GetScreenClipRect_x                                 0x9202A0
#define CXWnd__GetScreenRect_x                                     0x920460
#define CXWnd__GetRelativeRect_x                                   0x920520
#define CXWnd__GetTooltipRect_x                                    0x91E3D0
#define CXWnd__GetWindowTextA_x                                    0x49C8F0
#define CXWnd__IsActive_x                                          0x91EB00
#define CXWnd__IsDescendantOf_x                                    0x920E50
#define CXWnd__IsReallyVisible_x                                   0x920E80
#define CXWnd__IsType_x                                            0x9225C0
#define CXWnd__Move_x                                              0x920EF0
#define CXWnd__Move1_x                                             0x920FA0
#define CXWnd__ProcessTransition_x                                 0x9219F0
#define CXWnd__Refade_x                                            0x921260
#define CXWnd__Resize_x                                            0x9214B0
#define CXWnd__Right_x                                             0x921C80
#define CXWnd__SetFocus_x                                          0x921820
#define CXWnd__SetFont_x                                           0x921890
#define CXWnd__SetKeyTooltip_x                                     0x9223F0
#define CXWnd__SetMouseOver_x                                      0x91F340
#define CXWnd__StartFade_x                                         0x920D30
#define CXWnd__GetChildItem_x                                      0x9220D0
#define CXWnd__SetParent_x                                         0x920BF0
#define CXWnd__Minimize_x                                          0x921510

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x958A70

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x924E00
#define CXWndManager__DrawWindows_x                                0x924E20
#define CXWndManager__GetKeyboardFlags_x                           0x927600
#define CXWndManager__HandleKeyboardMsg_x                          0x9271C0
#define CXWndManager__RemoveWnd_x                                  0x927830
#define CXWndManager__RemovePendingDeletionWnd_x                   0x927DB0

// CDBStr
#define CDBStr__GetString_x                                        0x544D40

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFA70
#define EQ_Character__Cur_HP_x                                     0x4D2A50
#define EQ_Character__Cur_Mana_x                                   0x4DA1B0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2AE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3230
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3380
#define EQ_Character__GetHPRegen_x                                 0x4E00B0
#define EQ_Character__GetEnduranceRegen_x                          0x4E06B0
#define EQ_Character__GetManaRegen_x                               0x4E0AF0
#define EQ_Character__Max_Endurance_x                              0x65D560
#define EQ_Character__Max_HP_x                                     0x4D2880
#define EQ_Character__Max_Mana_x                                   0x65D360
#define EQ_Character__doCombatAbility_x                            0x65F950
#define EQ_Character__UseSkill_x                                   0x4E28F0
#define EQ_Character__GetConLevel_x                                0x655BB0
#define EQ_Character__IsExpansionFlag_x                            0x5B90D0
#define EQ_Character__TotalEffect_x                                0x4C6870
#define EQ_Character__GetPCSpellAffect_x                           0x4C3830
#define EQ_Character__SpellDuration_x                              0x4C3360
#define EQ_Character__MySpellDuration_x                            0x4B1B60
#define EQ_Character__GetAdjustedSkill_x                           0x4D57D0
#define EQ_Character__GetBaseSkill_x                               0x4D6770
#define EQ_Character__CanUseItem_x                                 0x4DA4C0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BBE20

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x673940

//PcClient
#define PcClient__vftable_x                                        0xAEFF2C
#define PcClient__PcClient_x                                       0x653320

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA4B0
#define CCharacterListWnd__EnterWorld_x                            0x4B9E80
#define CCharacterListWnd__Quit_x                                  0x4B9BD0
#define CCharacterListWnd__UpdateList_x                            0x4BA070

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6379B0
#define EQ_Item__CreateItemTagString_x                             0x896380
#define EQ_Item__IsStackable_x                                     0x89B040
#define EQ_Item__GetImageNum_x                                     0x897F40
#define EQ_Item__CreateItemClient_x                                0x636BF0
#define EQ_Item__GetItemValue_x                                    0x899230
#define EQ_Item__ValueSellMerchant_x                               0x89C9D0
#define EQ_Item__IsKeyRingItem_x                                   0x89A960
#define EQ_Item__CanGoInBag_x                                      0x637AD0
#define EQ_Item__IsEmpty_x                                         0x89A490
#define EQ_Item__GetMaxItemCount_x                                 0x899640
#define EQ_Item__GetHeldItem_x                                     0x897E10
#define EQ_Item__GetAugmentFitBySlot_x                             0x895BE0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5637D0
#define EQ_LoadingS__Array_x                                       0xC0FC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65DE60
#define EQ_PC__GetAlternateAbilityId_x                             0x8A59E0
#define EQ_PC__GetCombatAbility_x                                  0x8A6050
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A60C0
#define EQ_PC__GetItemRecastTimer_x                                0x65FED0
#define EQ_PC__HasLoreItem_x                                       0x6563C0
#define EQ_PC__AlertInventoryChanged_x                             0x6554F0
#define EQ_PC__GetPcZoneClient_x                                   0x682980
#define EQ_PC__RemoveMyAffect_x                                    0x663100
#define EQ_PC__GetKeyRingItems_x                                   0x8A6950
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A66E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A6C50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BF4C0
#define EQItemList__add_object_x                                   0x5ECA70
#define EQItemList__add_item_x                                     0x5BFA20
#define EQItemList__delete_item_x                                  0x5BFA70
#define EQItemList__FreeItemList_x                                 0x5BF970

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5418D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x675240
#define EQPlayer__dEQPlayer_x                                      0x6685C0
#define EQPlayer__DoAttack_x                                       0x67D110
#define EQPlayer__EQPlayer_x                                       0x668C80
#define EQPlayer__SetNameSpriteState_x                             0x66CF50
#define EQPlayer__SetNameSpriteTint_x                              0x66DE30
#define PlayerBase__HasProperty_j_x                                0x9877F0
#define EQPlayer__IsTargetable_x                                   0x987C90
#define EQPlayer__CanSee_x                                         0x987AF0
#define EQPlayer__CanSee1_x                                        0x987BC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9878B0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x680410
#define PlayerZoneClient__GetLevel_x                               0x6829C0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EDC00
#define PlayerZoneClient__LegalPlayerRace_x                        0x55C560

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x678010
#define EQPlayerManager__GetSpawnByName_x                          0x6780C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x678150

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63B0C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63B140
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63B180
#define KeypressHandler__ClearCommandStateArray_x                  0x63C570
#define KeypressHandler__HandleKeyDown_x                           0x63C590
#define KeypressHandler__HandleKeyUp_x                             0x63C630
#define KeypressHandler__SaveKeymapping_x                          0x63CA80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x773F10
#define MapViewMap__SaveEx_x                                       0x7772D0
#define MapViewMap__SetZoom_x                                      0x77B990

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B9E80

// StringTable 
#define StringTable__getString_x                                   0x8B4CA0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x662D70
#define PcZoneClient__RemovePetEffect_x                            0x6633A0
#define PcZoneClient__HasAlternateAbility_x                        0x65D190
#define PcZoneClient__GetCurrentMod_x                              0x4E5A10
#define PcZoneClient__GetModCap_x                                  0x4E5910
#define PcZoneClient__CanEquipItem_x                               0x65D840
#define PcZoneClient__GetItemByID_x                                0x660340
#define PcZoneClient__GetItemByItemClass_x                         0x660490
#define PcZoneClient__RemoveBuffEffect_x                           0x6633C0
#define PcZoneClient__BandolierSwap_x                              0x65E420
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65FE70

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F2780

//IconCache
#define IconCache__GetIcon_x                                       0x715E80

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70D9B0
#define CContainerMgr__CloseContainer_x                            0x70DC80
#define CContainerMgr__OpenExperimentContainer_x                   0x70E700

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CC6F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62FB50

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76A4E0
#define CLootWnd__RequestLootSlot_x                                0x7697B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58B320
#define EQ_Spell__SpellAffects_x                                   0x58B790
#define EQ_Spell__SpellAffectBase_x                                0x58B550
#define EQ_Spell__IsStackable_x                                    0x4CA490
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA310
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7700
#define EQ_Spell__IsSPAStacking_x                                  0x58C5E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58BAF0
#define EQ_Spell__IsNoRemove_x                                     0x4CA470
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58C5F0
#define __IsResEffectSpell_x                                       0x4C97A0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACE30

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C43B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8135E0
#define CTargetWnd__WndNotification_x                              0x812E20
#define CTargetWnd__RefreshTargetBuffs_x                           0x8130F0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x811F90

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x817C50
#define CTaskWnd__ConfirmAbandonTask_x                             0x81A890

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F310
#define CTaskManager__HandleMessage_x                              0x53D770
#define CTaskManager__GetTaskStatus_x                              0x53F3C0
#define CTaskManager__GetElementDescription_x                      0x53F440

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5863F0
#define EqSoundManager__PlayScriptMp3_x                            0x5866B0
#define EqSoundManager__SoundAssistPlay_x                          0x69AD30
#define EqSoundManager__WaveInstancePlay_x                         0x69A2A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5308D0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x943340
#define CTextureAnimation__Draw_x                                  0x943540

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93F290

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B320
#define CAltAbilityData__GetMercMaxRank_x                          0x56B2B0
#define CAltAbilityData__GetMaxRank_x                              0x5606A0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62DC70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA2F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5174B0
#define CharacterBase__CreateItemIndex_x                           0x635D80
#define CharacterBase__GetItemPossession_x                         0x5032B0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CCA00
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CCA60
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F4A10
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F5240
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F52F0

//messages
#define msg_spell_worn_off_x                                       0x5B1100
#define msg_new_text_x                                             0x5A5A80
#define __msgTokenTextParam_x                                      0x5B3390
#define msgTokenText_x                                             0x5B35E0

//SpellManager
#define SpellManager__vftable_x                                    0xAD82C4
#define SpellManager__SpellManager_x                               0x69E060
#define Spellmanager__LoadTextSpells_x                             0x69E950
#define SpellManager__GetSpellByGroupAndRank_x                     0x69E230

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98B790

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517B30
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B7540
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64EA40
#define ItemGlobalIndex__IsValidIndex_x                            0x517BC0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C4D50
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C4FD0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x762D90

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x712080
#define CCursorAttachment__AttachToCursor1_x                       0x7120C0
#define CCursorAttachment__Deactivate_x                            0x7130B0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x935F10
#define CSidlManagerBase__CreatePageWnd_x                          0x935720
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9319D0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x931960

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x953540
#define CEQSuiteTextureLoader__GetTexture_x                        0x953200

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514A30
#define CFindItemWnd__WndNotification_x                            0x515510
#define CFindItemWnd__Update_x                                     0x516050
#define CFindItemWnd__PickupSelectedItem_x                         0x514260

//IString
#define IString__Append_x                                          0x504AE0

//Camera
#define CDisplay__cameraType_x                                     0xDE7890
#define EverQuest__Cameras_x                                       0xEA2B0C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D490
#define LootFiltersManager__GetItemFilterData_x                    0x51CD90
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51CDC0
#define LootFiltersManager__SetItemLootFilter_x                    0x51CFE0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BA4A0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x991400
#define CResolutionHandler__GetWindowedStyle_x                     0x695860

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70A5E0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DA2D0
#define CDistillerInfo__Instance_x                                 0x8DA270

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x729350
#define CGroupWnd__UpdateDisplay_x                                 0x7286B0

//ItemBase
#define ItemBase__IsLore_x                                         0x89AA10
#define ItemBase__IsLoreEquipped_x                                 0x89AA80

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EC9D0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5ECB10
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5ECB70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68B0B0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68EA20

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50AD60

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F7110
#define FactionManagerClient__HandleFactionMessage_x               0x4F7780
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F7D40
#define FactionManagerClient__GetMaxFaction_x                      0x4F7D5F
#define FactionManagerClient__GetMinFaction_x                      0x4F7D10

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x503280

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91A690

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BC00

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5034E0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56A7D0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A18C0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68B0B0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8A00

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BF910

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF401A0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BE2A0
#define CAAWnd__UpdateSelected_x                                   0x6BAB10
#define CAAWnd__Update_x                                           0x6BD5C0

//CXRect
#define CXRect__operator_and_x                                     0x7204B0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x482C30

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
