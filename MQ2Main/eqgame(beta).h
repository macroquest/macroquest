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
#define __ExpectedVersionDate                                     "Oct 21 2020"
#define __ExpectedVersionTime                                     "04:21:45"
#define __ActualVersionDate_x                                      0xAF32BC
#define __ActualVersionTime_x                                      0xAF32B0
#define __ActualVersionBuild_x                                     0xAE12CC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x640E70
#define __MemChecker1_x                                            0x8F3E80
#define __MemChecker2_x                                            0x6B1480
#define __MemChecker3_x                                            0x6B13D0
#define __MemChecker4_x                                            0x84A960
#define __EncryptPad0_x                                            0xC28500
#define __EncryptPad1_x                                            0xC85D40
#define __EncryptPad2_x                                            0xC388C8
#define __EncryptPad3_x                                            0xC384C8
#define __EncryptPad4_x                                            0xC762D8
#define __EncryptPad5_x                                            0xF480B8
#define __AC1_x                                                    0x809076
#define __AC2_x                                                    0x5FA5FF
#define __AC3_x                                                    0x601C50
#define __AC4_x                                                    0x605C00
#define __AC5_x                                                    0x60BEEF
#define __AC6_x                                                    0x6103A6
#define __AC7_x                                                    0x5FA070
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
#define __CurrentMapLabel_x                                        0xF58BB4
#define __CurrentSocial_x                                          0xC007C8
#define __DoAbilityList_x                                          0xED7CBC
#define __do_loot_x                                                0x5C61D0
#define __DrawHandler_x                                            0x15D7BA8
#define __GroupCount_x                                             0xE9C532
#define __Guilds_x                                                 0xEA0398
#define __gWorld_x                                                 0xE9C3A4
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
#define __ScreenMode_x                                             0xDE77D0
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
#define __SubscriptionType_x                                       0xF9CE78
#define __TargetAggroHolder_x                                      0xF5B568
#define __ZoneType_x                                               0xEA18D8
#define __GroupAggro_x                                             0xF5B5A8
#define __LoginName_x                                              0xF48834
#define __Inviter_x                                                0xF40118
#define __AttackOnAssist_x                                         0xEA27D4
#define __UseTellWindows_x                                         0xEA2B00
#define __gfMaxZoomCameraDistance_x                                0xAEAEC8
#define __gfMaxCameraDistance_x                                    0xB13B50
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
#define pinstCamActor_x                                            0xDE77C0
#define pinstCDBStr_x                                              0xDE767C
#define pinstCDisplay_x                                            0xE9C384
#define pinstCEverQuest_x                                          0xF480F0
#define pinstEverQuestInfo_x                                       0xEA13F0
#define pinstCharData_x                                            0xE9C720
#define pinstCharSpawn_x                                           0xE9A364
#define pinstControlledMissile_x                                   0xE9A374
#define pinstControlledPlayer_x                                    0xE9A364
#define pinstCResolutionHandler_x                                  0x15D7DD8
#define pinstCSidlManager_x                                        0x15D6D70
#define pinstCXWndManager_x                                        0x15D6D6C
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
#define pinstImeManager_x                                          0x15D6D68
#define pinstLocalPlayer_x                                         0xE9A30C
#define pinstMercenaryData_x                                       0xF42768
#define pinstMercenaryStats_x                                      0xF5B634
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
#define pinstViewActor_x                                           0xDE77B8
#define pinstWorldData_x                                           0xE99E20
#define pinstZoneAddr_x                                            0xEA1970
#define pinstPlayerPath_x                                          0xF43410
#define pinstTargetIndicator_x                                     0xF44D78
#define EQObject_Top_x                                             0xE9A104
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE7B00
#define pinstCAchievementsWnd_x                                    0xDE7758
#define pinstCActionsWnd_x                                         0xDE7F94
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE7818
#define pinstCAdvancedLootWnd_x                                    0xDE77B0
#define pinstCAdventureLeaderboardWnd_x                            0xF52388
#define pinstCAdventureRequestWnd_x                                0xF52438
#define pinstCAdventureStatsWnd_x                                  0xF524E8
#define pinstCAggroMeterWnd_x                                      0xDE7800
#define pinstCAlarmWnd_x                                           0xDE7780
#define pinstCAlertHistoryWnd_x                                    0xDE7890
#define pinstCAlertStackWnd_x                                      0xDE77E8
#define pinstCAlertWnd_x                                           0xDE77FC
#define pinstCAltStorageWnd_x                                      0xF52848
#define pinstCAudioTriggersWindow_x                                0xC9C2A8
#define pinstCAuraWnd_x                                            0xDE77B4
#define pinstCAvaZoneWnd_x                                         0xDE7864
#define pinstCBandolierWnd_x                                       0xDE7814
#define pinstCBankWnd_x                                            0xDE7848
#define pinstCBarterMerchantWnd_x                                  0xF53A88
#define pinstCBarterSearchWnd_x                                    0xF53B38
#define pinstCBarterWnd_x                                          0xF53BE8
#define pinstCBazaarConfirmationWnd_x                              0xDE7794
#define pinstCBazaarSearchWnd_x                                    0xDE7B04
#define pinstCBazaarWnd_x                                          0xDE7764
#define pinstCBlockedBuffWnd_x                                     0xDE77DC
#define pinstCBlockedPetBuffWnd_x                                  0xDE7804
#define pinstCBodyTintWnd_x                                        0xDE7FA8
#define pinstCBookWnd_x                                            0xDE7840
#define pinstCBreathWnd_x                                          0xDE7B24
#define pinstCBuffWindowNORMAL_x                                   0xDE77A8
#define pinstCBuffWindowSHORT_x                                    0xDE77AC
#define pinstCBugReportWnd_x                                       0xDE7844
#define pinstCButtonWnd_x                                          0x15D6FD8
#define pinstCCastingWnd_x                                         0xDE7834
#define pinstCCastSpellWnd_x                                       0xDE7B10
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE7718
#define pinstCChatWindowManager_x                                  0xF546A8
#define pinstCClaimWnd_x                                           0xF54800
#define pinstCColorPickerWnd_x                                     0xDE7AAC
#define pinstCCombatAbilityWnd_x                                   0xDE7774
#define pinstCCombatSkillsSelectWnd_x                              0xDE772C
#define pinstCCompassWnd_x                                         0xDE7F98
#define pinstCConfirmationDialog_x                                 0xF59700
#define pinstCContainerMgr_x                                       0xDE7FA4
#define pinstCContextMenuManager_x                                 0x15D6D28
#define pinstCCursorAttachment_x                                   0xDE7828
#define pinstCDynamicZoneWnd_x                                     0xF54DC8
#define pinstCEditLabelWnd_x                                       0xDE77A4
#define pinstCEQMainWnd_x                                          0xF55010
#define pinstCEventCalendarWnd_x                                   0xDE7B08
#define pinstCExtendedTargetWnd_x                                  0xDE77E4
#define pinstCFacePick_x                                           0xDE7730
#define pinstCFactionWnd_x                                         0xDE7750
#define pinstCFellowshipWnd_x                                      0xF55210
#define pinstCFileSelectionWnd_x                                   0xDE7AA8
#define pinstCFindItemWnd_x                                        0xDE7740
#define pinstCFindLocationWnd_x                                    0xF55368
#define pinstCFriendsWnd_x                                         0xDE7744
#define pinstCGemsGameWnd_x                                        0xDE774C
#define pinstCGiveWnd_x                                            0xDE7784
#define pinstCGroupSearchFiltersWnd_x                              0xDE781C
#define pinstCGroupSearchWnd_x                                     0xF55760
#define pinstCGroupWnd_x                                           0xF55810
#define pinstCGuildBankWnd_x                                       0xEA27B8
#define pinstCGuildCreationWnd_x                                   0xF55970
#define pinstCGuildMgmtWnd_x                                       0xF55A20
#define pinstCharacterCreation_x                                   0xDE7738
#define pinstCHelpWnd_x                                            0xDE7788
#define pinstCHeritageSelectionWnd_x                               0xDE773C
#define pinstCHotButtonWnd_x                                       0xF57B78
#define pinstCHotButtonWnd1_x                                      0xF57B78
#define pinstCHotButtonWnd2_x                                      0xF57B7C
#define pinstCHotButtonWnd3_x                                      0xF57B80
#define pinstCHotButtonWnd4_x                                      0xF57B84
#define pinstCIconSelectionWnd_x                                   0xDE7824
#define pinstCInspectWnd_x                                         0xDE7808
#define pinstCInventoryWnd_x                                       0xDE77BC
#define pinstCInvSlotMgr_x                                         0xDE7AF0
#define pinstCItemDisplayManager_x                                 0xF58108
#define pinstCItemExpTransferWnd_x                                 0xF5823C
#define pinstCItemOverflowWnd_x                                    0xDE7B0C
#define pinstCJournalCatWnd_x                                      0xDE7AC0
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE787C
#define pinstCKeyRingWnd_x                                         0xDE7830
#define pinstCLargeDialogWnd_x                                     0xF5A380
#define pinstCLayoutCopyWnd_x                                      0xF58588
#define pinstCLFGuildWnd_x                                         0xF58638
#define pinstCLoadskinWnd_x                                        0xDE7768
#define pinstCLootFiltersCopyWnd_x                                 0xCB8958
#define pinstCLootFiltersWnd_x                                     0xDE77EC
#define pinstCLootSettingsWnd_x                                    0xDE7810
#define pinstCLootWnd_x                                            0xDE7AC4
#define pinstCMailAddressBookWnd_x                                 0xDE7AF8
#define pinstCMailCompositionWnd_x                                 0xDE7AB4
#define pinstCMailIgnoreListWnd_x                                  0xDE7AFC
#define pinstCMailWnd_x                                            0xDE7AA0
#define pinstCManageLootWnd_x                                      0xDE8E10
#define pinstCMapToolbarWnd_x                                      0xDE7790
#define pinstCMapViewWnd_x                                         0xDE775C
#define pinstCMarketplaceWnd_x                                     0xDE77F0
#define pinstCMerchantWnd_x                                        0xDE7AD0
#define pinstCMIZoneSelectWnd_x                                    0xF58E70
#define pinstCMusicPlayerWnd_x                                     0xDE7A9C
#define pinstCNameChangeMercWnd_x                                  0xDE778C
#define pinstCNameChangePetWnd_x                                   0xDE7760
#define pinstCNameChangeWnd_x                                      0xDE77A0
#define pinstCNoteWnd_x                                            0xDE776C
#define pinstCObjectPreviewWnd_x                                   0xDE780C
#define pinstCOptionsWnd_x                                         0xDE7778
#define pinstCPetInfoWnd_x                                         0xDE7A98
#define pinstCPetitionQWnd_x                                       0xDE7728
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE7FAC
#define pinstCPlayerWnd_x                                          0xDE7888
#define pinstCPopupWndManager_x                                    0xF59700
#define pinstCProgressionSelectionWnd_x                            0xF597B0
#define pinstCPurchaseGroupWnd_x                                   0xDE7860
#define pinstCPurchaseWnd_x                                        0xDE7838
#define pinstCPvPLeaderboardWnd_x                                  0xF59860
#define pinstCPvPStatsWnd_x                                        0xF59910
#define pinstCQuantityWnd_x                                        0xDE7878
#define pinstCRaceChangeWnd_x                                      0xDE77CC
#define pinstCRaidOptionsWnd_x                                     0xDE7820
#define pinstCRaidWnd_x                                            0xDE7ACC
#define pinstCRealEstateItemsWnd_x                                 0xDE7754
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE7F9C
#define pinstCRealEstateManageWnd_x                                0xDE7868
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE7884
#define pinstCRealEstatePlotSearchWnd_x                            0xDE7AA4
#define pinstCRealEstatePurchaseWnd_x                              0xDE7ABC
#define pinstCRespawnWnd_x                                         0xDE77F8
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE7724
#define pinstCSendMoneyWnd_x                                       0xDE7798
#define pinstCServerListWnd_x                                      0xDE7AC8
#define pinstCSkillsSelectWnd_x                                    0xDE7720
#define pinstCSkillsWnd_x                                          0xDE7FA0
#define pinstCSocialEditWnd_x                                      0xDE782C
#define pinstCSocialWnd_x                                          0xDE777C
#define pinstCSpellBookWnd_x                                       0xDE7770
#define pinstCStoryWnd_x                                           0xDE7F90
#define pinstCTargetOfTargetWnd_x                                  0xF5B6B8
#define pinstCTargetWnd_x                                          0xDE77F4
#define pinstCTaskOverlayWnd_x                                     0xDE7858
#define pinstCTaskSelectWnd_x                                      0xF5B810
#define pinstCTaskManager_x                                        0xCB9298
#define pinstCTaskTemplateSelectWnd_x                              0xF5B8C0
#define pinstCTaskWnd_x                                            0xF5B970
#define pinstCTextEntryWnd_x                                       0xDE783C
#define pinstCTimeLeftWnd_x                                        0xDE771C
#define pinstCTipWndCONTEXT_x                                      0xF5BB74
#define pinstCTipWndOFDAY_x                                        0xF5BB70
#define pinstCTitleWnd_x                                           0xF5BC20
#define pinstCTrackingWnd_x                                        0xDE77E0
#define pinstCTradeskillWnd_x                                      0xF5BD88
#define pinstCTradeWnd_x                                           0xDE7FB0
#define pinstCTrainWnd_x                                           0xDE7AB8
#define pinstCTributeBenefitWnd_x                                  0xF5BF88
#define pinstCTributeMasterWnd_x                                   0xF5C038
#define pinstCTributeTrophyWnd_x                                   0xF5C0E8
#define pinstCVideoModesWnd_x                                      0xDE788C
#define pinstCVoiceMacroWnd_x                                      0xF45330
#define pinstCVoteResultsWnd_x                                     0xDE7748
#define pinstCVoteWnd_x                                            0xDE7734
#define pinstCWebManager_x                                         0xF459AC
#define pinstCZoneGuideWnd_x                                       0xDE785C
#define pinstCZonePathWnd_x                                        0xDE7874

#define pinstEQSuiteTextureLoader_x                                0xC86660
#define pinstItemIconCache_x                                       0xF54FC8
#define pinstLootFiltersManager_x                                  0xCB8A08
#define pinstRewardSelectionWnd_x                                  0xF5A058

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C18C0
#define __CastRay2_x                                               0x5C1910
#define __ConvertItemTags_x                                        0x5DD4A0
#define __CleanItemTags_x                                          0x47CDA0
#define __DoesFileExist_x                                          0x8F6EB0
#define __EQGetTime_x                                              0x8F3AB0
#define __ExecuteCmd_x                                             0x5BA220
#define __FixHeading_x                                             0x9899C0
#define __FlushDxKeyboard_x                                        0x6AD320
#define __GameLoop_x                                               0x6B0650
#define __get_bearing_x                                            0x5C1420
#define __get_melee_range_x                                        0x5C1B00
#define __GetAnimationCache_x                                      0x715B10
#define __GetGaugeValueFromEQ_x                                    0x807520
#define __GetLabelFromEQ_x                                         0x809000
#define __GetXTargetType_x                                         0x98B410
#define __HandleMouseWheel_x                                       0x6B1530
#define __HeadingDiff_x                                            0x989A30
#define __HelpPath_x                                               0xF4086C
#define __LoadFrontEnd_x                                           0x6AD960
#define __NewUIINI_x                                               0x8071F0
#define __ProcessGameEvents_x                                      0x622280
#define __ProcessMouseEvent_x                                      0x621A10
#define __SaveColors_x                                             0x55AC90
#define __STMLToText_x                                             0x92CC20
#define __ToggleKeyRingItem_x                                      0x519710
#define CMemoryMappedFile__SetFile_x                               0xA78CA0
#define CrashDetected_x                                            0x6AF410
#define DrawNetStatus_x                                            0x64E4B0
#define Expansion_HoT_x                                            0xEA27C0
#define Teleport_Table_Size_x                                      0xE99EB8
#define Teleport_Table_x                                           0xE9A380
#define Util__FastTime_x                                           0x8F3680
#define __CopyLayout_x                                             0x63C540
#define __WndProc_x                                                0x6AF910
#define __ProcessKeyboardEvent_x                                   0x6AEEB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4901C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4991B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F80
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493750
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492BA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x562DD0
#define AltAdvManager__IsAbilityReady_x                            0x561B70
#define AltAdvManager__GetAAById_x                                 0x561F00
#define AltAdvManager__CanTrainAbility_x                           0x561F70
#define AltAdvManager__CanSeeAbility_x                             0x5622D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB090
#define CharacterZoneClient__HasSkill_x                            0x4D5F10
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7630
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2730
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBBD0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9FC0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA0A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA180
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4820
#define CharacterZoneClient__BardCastBard_x                        0x4C7250
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF5E0
#define CharacterZoneClient__GetEffect_x                           0x4BBB10
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5890
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5960
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C59B0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5B00
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5CE0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3B00
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8590
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8010

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D71E0
#define CBankWnd__WndNotification_x                                0x6D6FC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E4A30

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92A3F0
#define CButtonWnd__CButtonWnd_x                                   0x928FC0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x704D10
#define CChatManager__InitContextMenu_x                            0x6FDE40
#define CChatManager__FreeChatWindow_x                             0x703850
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9A10
#define CChatManager__SetLockedActiveChatWindow_x                  0x704990
#define CChatManager__CreateChatWindow_x                           0x703E90

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9B20

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93D520
#define CContextMenu__dCContextMenu_x                              0x93D760
#define CContextMenu__AddMenuItem_x                                0x93D770
#define CContextMenu__RemoveMenuItem_x                             0x93DA80
#define CContextMenu__RemoveAllMenuItems_x                         0x93DAA0
#define CContextMenu__CheckMenuItem_x                              0x93DB20
#define CContextMenu__SetMenuItem_x                                0x93D9A0
#define CContextMenu__AddSeparator_x                               0x93D900

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93E0C0
#define CContextMenuManager__RemoveMenu_x                          0x93E130
#define CContextMenuManager__PopupMenu_x                           0x93E1F0
#define CContextMenuManager__Flush_x                               0x93E060
#define CContextMenuManager__GetMenu_x                             0x49B420
#define CContextMenuManager__CreateDefaultMenu_x                   0x710470

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CE5C0
#define CChatService__GetFriendName_x                              0x8CE5D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x705580
#define CChatWindow__Clear_x                                       0x706840
#define CChatWindow__WndNotification_x                             0x706FD0
#define CChatWindow__AddHistory_x                                  0x706100

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93A980
#define CComboWnd__Draw_x                                          0x939E80
#define CComboWnd__GetCurChoice_x                                  0x93A7C0
#define CComboWnd__GetListRect_x                                   0x93A330
#define CComboWnd__GetTextRect_x                                   0x93A9F0
#define CComboWnd__InsertChoice_x                                  0x93A4C0
#define CComboWnd__SetColors_x                                     0x93A490
#define CComboWnd__SetChoice_x                                     0x93A790
#define CComboWnd__GetItemCount_x                                  0x93A7D0
#define CComboWnd__GetCurChoiceText_x                              0x93A810
#define CComboWnd__GetChoiceText_x                                 0x93A7E0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93A550

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70DE90
#define CContainerWnd__vftable_x                                   0xAFC4B4
#define CContainerWnd__SetContainer_x                              0x70F3E0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x555640
#define CDisplay__PreZoneMainUI_x                                  0x555650
#define CDisplay__CleanGameUI_x                                    0x55AA50
#define CDisplay__GetClickedActor_x                                0x54DAA0
#define CDisplay__GetUserDefinedColor_x                            0x546110
#define CDisplay__GetWorldFilePath_x                               0x54F510
#define CDisplay__is3dON_x                                         0x54A700
#define CDisplay__ReloadUI_x                                       0x554B50
#define CDisplay__WriteTextHD2_x                                   0x54A4F0
#define CDisplay__TrueDistance_x                                   0x5511D0
#define CDisplay__SetViewActor_x                                   0x54D3C0
#define CDisplay__GetFloorHeight_x                                 0x54A7C0
#define CDisplay__SetRenderWindow_x                                0x549140
#define CDisplay__ToggleScreenshotMode_x                           0x54CE90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95D470

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x940A20
#define CEditWnd__EnsureCaretVisible_x                             0x942BF0
#define CEditWnd__GetCaretPt_x                                     0x941BA0
#define CEditWnd__GetCharIndexPt_x                                 0x941950
#define CEditWnd__GetDisplayString_x                               0x9417F0
#define CEditWnd__GetHorzOffset_x                                  0x9400D0
#define CEditWnd__GetLineForPrintableChar_x                        0x942AF0
#define CEditWnd__GetSelStartPt_x                                  0x941C00
#define CEditWnd__GetSTMLSafeText_x                                0x941610
#define CEditWnd__PointFromPrintableChar_x                         0x942720
#define CEditWnd__SelectableCharFromPoint_x                        0x942890
#define CEditWnd__SetEditable_x                                    0x941CD0
#define CEditWnd__SetWindowTextA_x                                 0x941390
#define CEditWnd__ReplaceSelection_x                               0x942390
#define CEditWnd__ReplaceSelection1_x                              0x942310

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60F880
#define CEverQuest__ClickedPlayer_x                                0x601A30
#define CEverQuest__CreateTargetIndicator_x                        0x61F3F0
#define CEverQuest__DeleteTargetIndicator_x                        0x61F480
#define CEverQuest__DoTellWindow_x                                 0x4E9C00
#define CEverQuest__OutputTextToLog_x                              0x4E9ED0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F6B80
#define CEverQuest__dsp_chat_x                                     0x4EA260
#define CEverQuest__trimName_x                                     0x61B5A0
#define CEverQuest__Emote_x                                        0x6100E0
#define CEverQuest__EnterZone_x                                    0x60A1E0
#define CEverQuest__GetBodyTypeDesc_x                              0x614B30
#define CEverQuest__GetClassDesc_x                                 0x615170
#define CEverQuest__GetClassThreeLetterCode_x                      0x615770
#define CEverQuest__GetDeityDesc_x                                 0x61DC40
#define CEverQuest__GetLangDesc_x                                  0x615930
#define CEverQuest__GetRaceDesc_x                                  0x615150
#define CEverQuest__InterpretCmd_x                                 0x61E210
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FAD20
#define CEverQuest__LMouseUp_x                                     0x5F90A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FB600
#define CEverQuest__RMouseUp_x                                     0x5FA030
#define CEverQuest__SetGameState_x                                 0x5F6910
#define CEverQuest__UPCNotificationFlush_x                         0x61B4A0
#define CEverQuest__IssuePetCommand_x                              0x616D40
#define CEverQuest__ReportSuccessfulHit_x                          0x611430

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71FB30
#define CGaugeWnd__CalcLinesFillRect_x                             0x71FB90
#define CGaugeWnd__Draw_x                                          0x71F1B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFDA0
#define CGuild__GetGuildName_x                                     0x4AE850
#define CGuild__GetGuildIndex_x                                    0x4AEE50

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x739780

//CHotButton
#define CHotButton__SetCheck_x                                     0x630A50
#define CHotButton__SetButtonSize_x                                0x630E10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x746850
#define CInvSlotMgr__MoveItem_x                                    0x745510
#define CInvSlotMgr__SelectSlot_x                                  0x746920

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x743D40
#define CInvSlot__SliderComplete_x                                 0x741A80
#define CInvSlot__GetItemBase_x                                    0x741400
#define CInvSlot__UpdateItem_x                                     0x741570

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7483A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x747540
#define CInvSlotWnd__HandleLButtonUp_x                             0x747F20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8028B0
#define CItemDisplayWnd__UpdateStrings_x                           0x756B00
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x750790
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x750CC0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x757100
#define CItemDisplayWnd__AboutToShow_x                             0x756750
#define CItemDisplayWnd__WndNotification_x                         0x758370
#define CItemDisplayWnd__RequestConvertItem_x                      0x757CB0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7557B0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x756570

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8334D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75C8B0

// CLabel 
#define CLabel__Draw_x                                             0x762330

// CListWnd
#define CListWnd__CListWnd_x                                       0x913110
#define CListWnd__dCListWnd_x                                      0x913430
#define CListWnd__AddColumn_x                                      0x917880
#define CListWnd__AddColumn1_x                                     0x9178D0
#define CListWnd__AddLine_x                                        0x917C60
#define CListWnd__AddString_x                                      0x917A60
#define CListWnd__CalculateFirstVisibleLine_x                      0x917650
#define CListWnd__CalculateVSBRange_x                              0x917430
#define CListWnd__ClearSel_x                                       0x918440
#define CListWnd__ClearAllSel_x                                    0x9184A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x918EA0
#define CListWnd__Compare_x                                        0x916D70
#define CListWnd__Draw_x                                           0x913560
#define CListWnd__DrawColumnSeparators_x                           0x915D40
#define CListWnd__DrawHeader_x                                     0x9161B0
#define CListWnd__DrawItem_x                                       0x9166B0
#define CListWnd__DrawLine_x                                       0x915EB0
#define CListWnd__DrawSeparator_x                                  0x915DE0
#define CListWnd__EnableLine_x                                     0x915620
#define CListWnd__EnsureVisible_x                                  0x918DD0
#define CListWnd__ExtendSel_x                                      0x918370
#define CListWnd__GetColumnTooltip_x                               0x915160
#define CListWnd__GetColumnMinWidth_x                              0x9151D0
#define CListWnd__GetColumnWidth_x                                 0x9150D0
#define CListWnd__GetCurSel_x                                      0x914A60
#define CListWnd__GetItemAtPoint_x                                 0x915890
#define CListWnd__GetItemAtPoint1_x                                0x915900
#define CListWnd__GetItemData_x                                    0x914AE0
#define CListWnd__GetItemHeight_x                                  0x914EA0
#define CListWnd__GetItemIcon_x                                    0x914C70
#define CListWnd__GetItemRect_x                                    0x915710
#define CListWnd__GetItemText_x                                    0x914B20
#define CListWnd__GetSelList_x                                     0x9184F0
#define CListWnd__GetSeparatorRect_x                               0x915B40
#define CListWnd__InsertLine_x                                     0x918050
#define CListWnd__RemoveLine_x                                     0x9181A0
#define CListWnd__SetColors_x                                      0x917410
#define CListWnd__SetColumnJustification_x                         0x917140
#define CListWnd__SetColumnLabel_x                                 0x917A00
#define CListWnd__SetColumnWidth_x                                 0x917060
#define CListWnd__SetCurSel_x                                      0x9182B0
#define CListWnd__SetItemColor_x                                   0x918A90
#define CListWnd__SetItemData_x                                    0x918A50
#define CListWnd__SetItemText_x                                    0x918660
#define CListWnd__ShiftColumnSeparator_x                           0x917200
#define CListWnd__Sort_x                                           0x916EF0
#define CListWnd__ToggleSel_x                                      0x9182E0
#define CListWnd__SetColumnsSizable_x                              0x9172B0
#define CListWnd__SetItemWnd_x                                     0x918910
#define CListWnd__GetItemWnd_x                                     0x914CC0
#define CListWnd__SetItemIcon_x                                    0x9186E0
#define CListWnd__CalculateCustomWindowPositions_x                 0x917740
#define CListWnd__SetVScrollPos_x                                  0x917040

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x777A90
#define CMapViewWnd__GetWorldCoordinates_x                         0x7761A0
#define CMapViewWnd__HandleLButtonDown_x                           0x7731E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x797EA0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x798780
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x798CB0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79BC70
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x796A10
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A1840
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x797AC0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89C620
#define CPacketScrambler__hton_x                                   0x89C610

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x932210
#define CSidlManager__FindScreenPieceTemplate_x                    0x932620
#define CSidlManager__FindScreenPieceTemplate1_x                   0x932410
#define CSidlManager__CreateLabel_x                                0x7F9B80
#define CSidlManager__CreateXWndFromTemplate_x                     0x935580
#define CSidlManager__CreateXWndFromTemplate1_x                    0x935760
#define CSidlManager__CreateXWnd_x                                 0x7F9AB0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FA080

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92ECF0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92EBF0
#define CSidlScreenWnd__ConvertToRes_x                             0x957FC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92E6E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92E3D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92E4A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92E570
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92F190
#define CSidlScreenWnd__EnableIniStorage_x                         0x92F660
#define CSidlScreenWnd__GetSidlPiece_x                             0x92F380
#define CSidlScreenWnd__Init1_x                                    0x92DFD0
#define CSidlScreenWnd__LoadIniInfo_x                              0x92F6B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9301F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92D3D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x92FD70
#define CSidlScreenWnd__StoreIniVis_x                              0x9300D0
#define CSidlScreenWnd__WndNotification_x                          0x92F0A0
#define CSidlScreenWnd__GetChildItem_x                             0x92F5E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91ED70
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D6BF8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x696590
#define CSkillMgr__GetSkillCap_x                                   0x696770
#define CSkillMgr__GetNameToken_x                                  0x695D10
#define CSkillMgr__IsActivatedSkill_x                              0x695E50
#define CSkillMgr__IsCombatSkill_x                                 0x695D90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93EEB0
#define CSliderWnd__SetValue_x                                     0x93ED20
#define CSliderWnd__SetNumTicks_x                                  0x93ED80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FFC70

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9478A0
#define CStmlWnd__ParseSTML_x                                      0x948BE0
#define CStmlWnd__CalculateHSBRange_x                              0x9489B0
#define CStmlWnd__CalculateVSBRange_x                              0x948930
#define CStmlWnd__CanBreakAtCharacter_x                            0x94CCF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94D980
#define CStmlWnd__ForceParseNow_x                                  0x947E90
#define CStmlWnd__GetNextTagPiece_x                                0x94CC50
#define CStmlWnd__GetSTMLText_x                                    0x50AA30
#define CStmlWnd__GetVisibleText_x                                 0x947EB0
#define CStmlWnd__InitializeWindowVariables_x                      0x94D7D0
#define CStmlWnd__MakeStmlColorTag_x                               0x946F10
#define CStmlWnd__MakeWndNotificationTag_x                         0x946F80
#define CStmlWnd__SetSTMLText_x                                    0x945FC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x94EA70
#define CStmlWnd__UpdateHistoryString_x                            0x94DB90

// CTabWnd 
#define CTabWnd__Draw_x                                            0x945050
#define CTabWnd__DrawCurrentPage_x                                 0x945780
#define CTabWnd__DrawTab_x                                         0x9454A0
#define CTabWnd__GetCurrentPage_x                                  0x944850
#define CTabWnd__GetPageInnerRect_x                                0x944A90
#define CTabWnd__GetTabInnerRect_x                                 0x9449D0
#define CTabWnd__GetTabRect_x                                      0x944880
#define CTabWnd__InsertPage_x                                      0x944CA0
#define CTabWnd__RemovePage_x                                      0x944E10
#define CTabWnd__SetPage_x                                         0x944B10
#define CTabWnd__SetPageRect_x                                     0x944F90
#define CTabWnd__UpdatePage_x                                      0x945360
#define CTabWnd__GetPageFromTabIndex_x                             0x9453E0
#define CTabWnd__GetCurrentTabIndex_x                              0x944840

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75CCC0
#define CPageWnd__SetTabText_x                                     0x944390
#define CPageWnd__FlashTab_x                                       0x9443F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9050

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91BBD0
#define CTextureFont__GetTextExtent_x                              0x91BD90

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AA7F0
#define CHtmlComponentWnd__ValidateUri_x                           0x73B170
#define CHtmlWnd__SetClientCallbacks_x                             0x635EA0
#define CHtmlWnd__AddObserver_x                                    0x635EC0
#define CHtmlWnd__RemoveObserver_x                                 0x635F20
#define Window__getProgress_x                                      0x851F70
#define Window__getStatus_x                                        0x851F90
#define Window__getURI_x                                           0x851FA0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x954DD0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x908C70

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9900
#define CXStr__CXStr1_x                                            0x505B30
#define CXStr__CXStr3_x                                            0x8EFA30
#define CXStr__dCXStr_x                                            0x477F10
#define CXStr__operator_equal_x                                    0x8EFC60
#define CXStr__operator_equal1_x                                   0x8EFCA0
#define CXStr__operator_plus_equal1_x                              0x8F0730
#define CXStr__SetString_x                                         0x8F2620
#define CXStr__operator_char_p_x                                   0x8F01A0
#define CXStr__GetChar_x                                           0x8F1F50
#define CXStr__Delete_x                                            0x8F1820
#define CXStr__GetUnicode_x                                        0x8F1FC0
#define CXStr__GetLength_x                                         0x4A8E00
#define CXStr__Mid_x                                               0x47D150
#define CXStr__Insert_x                                            0x8F2020
#define CXStr__FindNext_x                                          0x8F1C90

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93D140
#define CXWnd__BringToTop_x                                        0x922520
#define CXWnd__Center_x                                            0x9220A0
#define CXWnd__ClrFocus_x                                          0x921EB0
#define CXWnd__Destroy_x                                           0x921F60
#define CXWnd__DoAllDrawing_x                                      0x91E500
#define CXWnd__DrawChildren_x                                      0x91E4D0
#define CXWnd__DrawColoredRect_x                                   0x91E960
#define CXWnd__DrawTooltip_x                                       0x91D000
#define CXWnd__DrawTooltipAtPoint_x                                0x91D0C0
#define CXWnd__GetBorderFrame_x                                    0x91E7C0
#define CXWnd__GetChildWndAt_x                                     0x9225C0
#define CXWnd__GetClientClipRect_x                                 0x9207F0
#define CXWnd__GetScreenClipRect_x                                 0x9208C0
#define CXWnd__GetScreenRect_x                                     0x920A50
#define CXWnd__GetRelativeRect_x                                   0x920B10
#define CXWnd__GetTooltipRect_x                                    0x91E9B0
#define CXWnd__GetWindowTextA_x                                    0x49CB10
#define CXWnd__IsActive_x                                          0x91F0F0
#define CXWnd__IsDescendantOf_x                                    0x921450
#define CXWnd__IsReallyVisible_x                                   0x921480
#define CXWnd__IsType_x                                            0x922C30
#define CXWnd__Move_x                                              0x9214E0
#define CXWnd__Move1_x                                             0x921590
#define CXWnd__ProcessTransition_x                                 0x922050
#define CXWnd__Refade_x                                            0x921870
#define CXWnd__Resize_x                                            0x921B10
#define CXWnd__Right_x                                             0x9222E0
#define CXWnd__SetFocus_x                                          0x921E70
#define CXWnd__SetFont_x                                           0x921EE0
#define CXWnd__SetKeyTooltip_x                                     0x922A50
#define CXWnd__SetMouseOver_x                                      0x91F960
#define CXWnd__StartFade_x                                         0x921330
#define CXWnd__GetChildItem_x                                      0x922730
#define CXWnd__SetParent_x                                         0x9211F0
#define CXWnd__Minimize_x                                          0x921B70

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x959040

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x925420
#define CXWndManager__DrawWindows_x                                0x925440
#define CXWndManager__GetKeyboardFlags_x                           0x927C40
#define CXWndManager__HandleKeyboardMsg_x                          0x9277F0
#define CXWndManager__RemoveWnd_x                                  0x927E70
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9283E0

// CDBStr
#define CDBStr__GetString_x                                        0x5450B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFD40
#define EQ_Character__Cur_HP_x                                     0x4D2F50
#define EQ_Character__Cur_Mana_x                                   0x4DA680
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2DA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3740
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3890
#define EQ_Character__GetHPRegen_x                                 0x4E0580
#define EQ_Character__GetEnduranceRegen_x                          0x4E0B80
#define EQ_Character__GetManaRegen_x                               0x4E0FC0
#define EQ_Character__Max_Endurance_x                              0x65C8C0
#define EQ_Character__Max_HP_x                                     0x4D2D80
#define EQ_Character__Max_Mana_x                                   0x65C6C0
#define EQ_Character__doCombatAbility_x                            0x65ECB0
#define EQ_Character__UseSkill_x                                   0x4E2DD0
#define EQ_Character__GetConLevel_x                                0x655410
#define EQ_Character__IsExpansionFlag_x                            0x5B8A20
#define EQ_Character__TotalEffect_x                                0x4C6B40
#define EQ_Character__GetPCSpellAffect_x                           0x4C3AF0
#define EQ_Character__SpellDuration_x                              0x4C3620
#define EQ_Character__MySpellDuration_x                            0x4B2070
#define EQ_Character__GetAdjustedSkill_x                           0x4D5CD0
#define EQ_Character__GetBaseSkill_x                               0x4D6C70
#define EQ_Character__CanUseItem_x                                 0x4DA990

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BB500

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x672C60

//PcClient
#define PcClient__vftable_x                                        0xAEFF30
#define PcClient__PcClient_x                                       0x652B70

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA750
#define CCharacterListWnd__EnterWorld_x                            0x4BA120
#define CCharacterListWnd__Quit_x                                  0x4B9E70
#define CCharacterListWnd__UpdateList_x                            0x4BA310

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x637080
#define EQ_Item__CreateItemTagString_x                             0x895C10
#define EQ_Item__IsStackable_x                                     0x89A890
#define EQ_Item__GetImageNum_x                                     0x897790
#define EQ_Item__CreateItemClient_x                                0x6362C0
#define EQ_Item__GetItemValue_x                                    0x898AA0
#define EQ_Item__ValueSellMerchant_x                               0x89C200
#define EQ_Item__IsKeyRingItem_x                                   0x89A1B0
#define EQ_Item__CanGoInBag_x                                      0x6371A0
#define EQ_Item__IsEmpty_x                                         0x899CF0
#define EQ_Item__GetMaxItemCount_x                                 0x898EB0
#define EQ_Item__GetHeldItem_x                                     0x897660
#define EQ_Item__GetAugmentFitBySlot_x                             0x895470

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x563AA0
#define EQ_LoadingS__Array_x                                       0xC0FC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65D1C0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A5210
#define EQ_PC__GetCombatAbility_x                                  0x8A5880
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A58F0
#define EQ_PC__GetItemRecastTimer_x                                0x65F230
#define EQ_PC__HasLoreItem_x                                       0x655C20
#define EQ_PC__AlertInventoryChanged_x                             0x654D40
#define EQ_PC__GetPcZoneClient_x                                   0x681C40
#define EQ_PC__RemoveMyAffect_x                                    0x662460
#define EQ_PC__GetKeyRingItems_x                                   0x8A6180
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A5F10
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A6480

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BEE20
#define EQItemList__add_object_x                                   0x5EC300
#define EQItemList__add_item_x                                     0x5BF380
#define EQItemList__delete_item_x                                  0x5BF3D0
#define EQItemList__FreeItemList_x                                 0x5BF2D0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x541C10

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x674560
#define EQPlayer__dEQPlayer_x                                      0x6678E0
#define EQPlayer__DoAttack_x                                       0x67C3D0
#define EQPlayer__EQPlayer_x                                       0x667FA0
#define EQPlayer__SetNameSpriteState_x                             0x66C270
#define EQPlayer__SetNameSpriteTint_x                              0x66D150
#define PlayerBase__HasProperty_j_x                                0x987DD0
#define EQPlayer__IsTargetable_x                                   0x988270
#define EQPlayer__CanSee_x                                         0x9880D0
#define EQPlayer__CanSee1_x                                        0x9881A0
#define PlayerBase__GetVisibilityLineSegment_x                     0x987E90

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67F6D0
#define PlayerZoneClient__GetLevel_x                               0x681C80
#define PlayerZoneClient__IsValidTeleport_x                        0x5ED470
#define PlayerZoneClient__LegalPlayerRace_x                        0x55C8E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6772D0
#define EQPlayerManager__GetSpawnByName_x                          0x677380
#define EQPlayerManager__GetPlayerFromPartialName_x                0x677410

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63A7A0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63A820
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63A860
#define KeypressHandler__ClearCommandStateArray_x                  0x63BC50
#define KeypressHandler__HandleKeyDown_x                           0x63BC70
#define KeypressHandler__HandleKeyUp_x                             0x63BD10
#define KeypressHandler__SaveKeymapping_x                          0x63C160

// MapViewMap 
#define MapViewMap__Clear_x                                        0x773900
#define MapViewMap__SaveEx_x                                       0x776CC0
#define MapViewMap__SetZoom_x                                      0x77B380

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B9560

// StringTable 
#define StringTable__getString_x                                   0x8B4380

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6620D0
#define PcZoneClient__RemovePetEffect_x                            0x662700
#define PcZoneClient__HasAlternateAbility_x                        0x65C4F0
#define PcZoneClient__GetCurrentMod_x                              0x4E5EF0
#define PcZoneClient__GetModCap_x                                  0x4E5DF0
#define PcZoneClient__CanEquipItem_x                               0x65CBA0
#define PcZoneClient__GetItemByID_x                                0x65F6A0
#define PcZoneClient__GetItemByItemClass_x                         0x65F7F0
#define PcZoneClient__RemoveBuffEffect_x                           0x662720
#define PcZoneClient__BandolierSwap_x                              0x65D780
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65F1D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F1FF0

//IconCache
#define IconCache__GetIcon_x                                       0x715510

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70D030
#define CContainerMgr__CloseContainer_x                            0x70D300
#define CContainerMgr__OpenExperimentContainer_x                   0x70DD80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CC1B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62F210

//CLootWnd
#define CLootWnd__LootAll_x                                        0x769DC0
#define CLootWnd__RequestLootSlot_x                                0x769090

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58B330
#define EQ_Spell__SpellAffects_x                                   0x58B7A0
#define EQ_Spell__SpellAffectBase_x                                0x58B560
#define EQ_Spell__IsStackable_x                                    0x4CA9B0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA7D0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7A00
#define EQ_Spell__IsSPAStacking_x                                  0x58C5F0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58BB00
#define EQ_Spell__IsNoRemove_x                                     0x4CA990
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58C600
#define __IsResEffectSpell_x                                       0x4C9B90

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD2D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C3C20

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x812FC0
#define CTargetWnd__WndNotification_x                              0x812800
#define CTargetWnd__RefreshTargetBuffs_x                           0x812AD0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x811960

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x817630
#define CTaskWnd__ConfirmAbandonTask_x                             0x81A270

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F630
#define CTaskManager__HandleMessage_x                              0x53DAA0
#define CTaskManager__GetTaskStatus_x                              0x53F6E0
#define CTaskManager__GetElementDescription_x                      0x53F760

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x586470
#define EqSoundManager__PlayScriptMp3_x                            0x586730
#define EqSoundManager__SoundAssistPlay_x                          0x69A510
#define EqSoundManager__WaveInstancePlay_x                         0x699A80

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530BC0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9438A0
#define CTextureAnimation__Draw_x                                  0x943AA0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93F810

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B590
#define CAltAbilityData__GetMercMaxRank_x                          0x56B520
#define CAltAbilityData__GetMaxRank_x                              0x5609F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62D330

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA7B0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5178F0
#define CharacterBase__CreateItemIndex_x                           0x635450
#define CharacterBase__GetItemPossession_x                         0x503420
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CC290
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CC2F0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F4080
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F48B0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F4960

//messages
#define msg_spell_worn_off_x                                       0x5B0AB0
#define msg_new_text_x                                             0x5A5440
#define __msgTokenTextParam_x                                      0x5B2D50
#define msgTokenText_x                                             0x5B2FA0

//SpellManager
#define SpellManager__vftable_x                                    0xAD82BC
#define SpellManager__SpellManager_x                               0x69D860
#define Spellmanager__LoadTextSpells_x                             0x69E150
#define SpellManager__GetSpellByGroupAndRank_x                     0x69DA30

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98BD00

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517F70
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B6F30
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64E310
#define ItemGlobalIndex__IsValidIndex_x                            0x518000

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C45C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C4840

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x762670

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x711710
#define CCursorAttachment__AttachToCursor1_x                       0x711750
#define CCursorAttachment__Deactivate_x                            0x712740

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9365C0
#define CSidlManagerBase__CreatePageWnd_x                          0x935DB0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x932030
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x931FC0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9537C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x953480

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514E70
#define CFindItemWnd__WndNotification_x                            0x515950
#define CFindItemWnd__Update_x                                     0x5164C0
#define CFindItemWnd__PickupSelectedItem_x                         0x514690

//IString
#define IString__Append_x                                          0x504C40

//Camera
#define CDisplay__cameraType_x                                     0xDE7894
#define EverQuest__Cameras_x                                       0xEA2B0C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D880
#define LootFiltersManager__GetItemFilterData_x                    0x51D190
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51D1C0
#define LootFiltersManager__SetItemLootFilter_x                    0x51D3E0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B9FE0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x991930
#define CResolutionHandler__GetWindowedStyle_x                     0x695080

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x709CF0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9C30
#define CDistillerInfo__Instance_x                                 0x8D9BD0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x728B10
#define CGroupWnd__UpdateDisplay_x                                 0x727E70

//ItemBase
#define ItemBase__IsLore_x                                         0x89A260
#define ItemBase__IsLoreEquipped_x                                 0x89A2D0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EC260
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EC3A0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EC400

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68A360
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68DCD0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50B250

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F7640
#define FactionManagerClient__HandleFactionMessage_x               0x4F7CB0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F82B0
#define FactionManagerClient__GetMaxFaction_x                      0x4F82CF
#define FactionManagerClient__GetMinFaction_x                      0x4F8280

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5033F0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91AB90

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE20

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x503650

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56AA30

//CTargetManager
#define CTargetManager__Get_x                                      0x6A1140

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68A360

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E10

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BF270

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF401A0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BD8C0
#define CAAWnd__UpdateSelected_x                                   0x6BA130
#define CAAWnd__Update_x                                           0x6BCBE0

//CXRect
#define CXRect__operator_and_x                                     0x71FBF0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x482E50

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
