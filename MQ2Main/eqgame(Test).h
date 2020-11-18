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
#define __ExpectedVersionDate                                     "Nov 10 2020"
#define __ExpectedVersionTime                                     "10:49:04"
#define __ActualVersionDate_x                                      0xAF32BC
#define __ActualVersionTime_x                                      0xAF32B0
#define __ActualVersionBuild_x                                     0xAE12DC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x640BC0
#define __MemChecker1_x                                            0x8F3940
#define __MemChecker2_x                                            0x6B11A0
#define __MemChecker3_x                                            0x6B10F0
#define __MemChecker4_x                                            0x849F90
#define __EncryptPad0_x                                            0xC28500
#define __EncryptPad1_x                                            0xC85D38
#define __EncryptPad2_x                                            0xC388C8
#define __EncryptPad3_x                                            0xC384C8
#define __EncryptPad4_x                                            0xC762D8
#define __EncryptPad5_x                                            0xF480B8
#define __AC1_x                                                    0x808C26
#define __AC2_x                                                    0x5FA21F
#define __AC3_x                                                    0x601870
#define __AC4_x                                                    0x605820
#define __AC5_x                                                    0x60BB0F
#define __AC6_x                                                    0x60FFC6
#define __AC7_x                                                    0x5F9C90
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
#define __do_loot_x                                                0x5C5C50
#define __DrawHandler_x                                            0x15D7AA0
#define __GroupCount_x                                             0xE9C532
#define __Guilds_x                                                 0xEA0398
#define __gWorld_x                                                 0xE9C390
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
#define __ScreenMode_x                                             0xDE77D4
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
#define __gfMaxZoomCameraDistance_x                                0xAEAED8
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
#define pinstCamActor_x                                            0xDE77C4
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
#define pinstViewActor_x                                           0xDE77BC
#define pinstWorldData_x                                           0xE99E20
#define pinstZoneAddr_x                                            0xEA1970
#define pinstPlayerPath_x                                          0xF43410
#define pinstTargetIndicator_x                                     0xF44D78
#define EQObject_Top_x                                             0xE9A104
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE7B04
#define pinstCAchievementsWnd_x                                    0xDE775C
#define pinstCActionsWnd_x                                         0xDE7F98
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE781C
#define pinstCAdvancedLootWnd_x                                    0xDE77B4
#define pinstCAdventureLeaderboardWnd_x                            0xF52280
#define pinstCAdventureRequestWnd_x                                0xF52330
#define pinstCAdventureStatsWnd_x                                  0xF523E0
#define pinstCAggroMeterWnd_x                                      0xDE7804
#define pinstCAlarmWnd_x                                           0xDE7784
#define pinstCAlertHistoryWnd_x                                    0xDE7894
#define pinstCAlertStackWnd_x                                      0xDE77EC
#define pinstCAlertWnd_x                                           0xDE7800
#define pinstCAltStorageWnd_x                                      0xF52740
#define pinstCAudioTriggersWindow_x                                0xC9C2A8
#define pinstCAuraWnd_x                                            0xDE77B8
#define pinstCAvaZoneWnd_x                                         0xDE7868
#define pinstCBandolierWnd_x                                       0xDE7818
#define pinstCBankWnd_x                                            0xDE784C
#define pinstCBarterMerchantWnd_x                                  0xF53980
#define pinstCBarterSearchWnd_x                                    0xF53A30
#define pinstCBarterWnd_x                                          0xF53AE0
#define pinstCBazaarConfirmationWnd_x                              0xDE7798
#define pinstCBazaarSearchWnd_x                                    0xDE7B08
#define pinstCBazaarWnd_x                                          0xDE7768
#define pinstCBlockedBuffWnd_x                                     0xDE77E0
#define pinstCBlockedPetBuffWnd_x                                  0xDE7808
#define pinstCBodyTintWnd_x                                        0xDE7FAC
#define pinstCBookWnd_x                                            0xDE7844
#define pinstCBreathWnd_x                                          0xDE7B8C
#define pinstCBuffWindowNORMAL_x                                   0xDE77AC
#define pinstCBuffWindowSHORT_x                                    0xDE77B0
#define pinstCBugReportWnd_x                                       0xDE7848
#define pinstCButtonWnd_x                                          0x15D6ED0
#define pinstCCastingWnd_x                                         0xDE7838
#define pinstCCastSpellWnd_x                                       0xDE7B14
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE771C
#define pinstCChatWindowManager_x                                  0xF545A0
#define pinstCClaimWnd_x                                           0xF546F8
#define pinstCColorPickerWnd_x                                     0xDE7AB0
#define pinstCCombatAbilityWnd_x                                   0xDE7778
#define pinstCCombatSkillsSelectWnd_x                              0xDE7730
#define pinstCCompassWnd_x                                         0xDE7F9C
#define pinstCConfirmationDialog_x                                 0xF595F8
#define pinstCContainerMgr_x                                       0xDE7FA8
#define pinstCContextMenuManager_x                                 0x15D6C20
#define pinstCCursorAttachment_x                                   0xDE782C
#define pinstCDynamicZoneWnd_x                                     0xF54CC0
#define pinstCEditLabelWnd_x                                       0xDE77A8
#define pinstCEQMainWnd_x                                          0xF54F08
#define pinstCEventCalendarWnd_x                                   0xDE7B0C
#define pinstCExtendedTargetWnd_x                                  0xDE77E8
#define pinstCFacePick_x                                           0xDE7734
#define pinstCFactionWnd_x                                         0xDE7754
#define pinstCFellowshipWnd_x                                      0xF55108
#define pinstCFileSelectionWnd_x                                   0xDE7AAC
#define pinstCFindItemWnd_x                                        0xDE7744
#define pinstCFindLocationWnd_x                                    0xF55260
#define pinstCFriendsWnd_x                                         0xDE7748
#define pinstCGemsGameWnd_x                                        0xDE7750
#define pinstCGiveWnd_x                                            0xDE7788
#define pinstCGroupSearchFiltersWnd_x                              0xDE7820
#define pinstCGroupSearchWnd_x                                     0xF55658
#define pinstCGroupWnd_x                                           0xF55708
#define pinstCGuildBankWnd_x                                       0xEA27B8
#define pinstCGuildCreationWnd_x                                   0xF55868
#define pinstCGuildMgmtWnd_x                                       0xF55918
#define pinstCharacterCreation_x                                   0xDE773C
#define pinstCHelpWnd_x                                            0xDE778C
#define pinstCHeritageSelectionWnd_x                               0xDE7740
#define pinstCHotButtonWnd_x                                       0xF57A70
#define pinstCHotButtonWnd1_x                                      0xF57A70
#define pinstCHotButtonWnd2_x                                      0xF57A74
#define pinstCHotButtonWnd3_x                                      0xF57A78
#define pinstCHotButtonWnd4_x                                      0xF57A7C
#define pinstCIconSelectionWnd_x                                   0xDE7828
#define pinstCInspectWnd_x                                         0xDE780C
#define pinstCInventoryWnd_x                                       0xDE77C0
#define pinstCInvSlotMgr_x                                         0xDE7AF4
#define pinstCItemDisplayManager_x                                 0xF58000
#define pinstCItemExpTransferWnd_x                                 0xF58134
#define pinstCItemOverflowWnd_x                                    0xDE7B10
#define pinstCJournalCatWnd_x                                      0xDE7AC4
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE7880
#define pinstCKeyRingWnd_x                                         0xDE7834
#define pinstCLargeDialogWnd_x                                     0xF5A278
#define pinstCLayoutCopyWnd_x                                      0xF58480
#define pinstCLFGuildWnd_x                                         0xF58530
#define pinstCLoadskinWnd_x                                        0xDE776C
#define pinstCLootFiltersCopyWnd_x                                 0xCB8958
#define pinstCLootFiltersWnd_x                                     0xDE77F0
#define pinstCLootSettingsWnd_x                                    0xDE7814
#define pinstCLootWnd_x                                            0xDE7AC8
#define pinstCMailAddressBookWnd_x                                 0xDE7AFC
#define pinstCMailCompositionWnd_x                                 0xDE7AB8
#define pinstCMailIgnoreListWnd_x                                  0xDE7B00
#define pinstCMailWnd_x                                            0xDE7AA0
#define pinstCManageLootWnd_x                                      0xDE8E10
#define pinstCMapToolbarWnd_x                                      0xDE7794
#define pinstCMapViewWnd_x                                         0xDE7760
#define pinstCMarketplaceWnd_x                                     0xDE77F4
#define pinstCMerchantWnd_x                                        0xDE7AD4
#define pinstCMIZoneSelectWnd_x                                    0xF58D68
#define pinstCMusicPlayerWnd_x                                     0xDE7870
#define pinstCNameChangeMercWnd_x                                  0xDE7790
#define pinstCNameChangePetWnd_x                                   0xDE7764
#define pinstCNameChangeWnd_x                                      0xDE77A4
#define pinstCNoteWnd_x                                            0xDE7770
#define pinstCObjectPreviewWnd_x                                   0xDE7810
#define pinstCOptionsWnd_x                                         0xDE777C
#define pinstCPetInfoWnd_x                                         0xDE789C
#define pinstCPetitionQWnd_x                                       0xDE772C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE7FB0
#define pinstCPlayerWnd_x                                          0xDE788C
#define pinstCPopupWndManager_x                                    0xF595F8
#define pinstCProgressionSelectionWnd_x                            0xF596A8
#define pinstCPurchaseGroupWnd_x                                   0xDE7864
#define pinstCPurchaseWnd_x                                        0xDE783C
#define pinstCPvPLeaderboardWnd_x                                  0xF59758
#define pinstCPvPStatsWnd_x                                        0xF59808
#define pinstCQuantityWnd_x                                        0xDE787C
#define pinstCRaceChangeWnd_x                                      0xDE77D0
#define pinstCRaidOptionsWnd_x                                     0xDE7824
#define pinstCRaidWnd_x                                            0xDE7AD0
#define pinstCRealEstateItemsWnd_x                                 0xDE7758
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE7FA0
#define pinstCRealEstateManageWnd_x                                0xDE786C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE7888
#define pinstCRealEstatePlotSearchWnd_x                            0xDE7AA8
#define pinstCRealEstatePurchaseWnd_x                              0xDE7AC0
#define pinstCRespawnWnd_x                                         0xDE77FC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE7728
#define pinstCSendMoneyWnd_x                                       0xDE779C
#define pinstCServerListWnd_x                                      0xDE7ACC
#define pinstCSkillsSelectWnd_x                                    0xDE7724
#define pinstCSkillsWnd_x                                          0xDE7FA4
#define pinstCSocialEditWnd_x                                      0xDE7830
#define pinstCSocialWnd_x                                          0xDE7780
#define pinstCSpellBookWnd_x                                       0xDE7774
#define pinstCStoryWnd_x                                           0xDE7F94
#define pinstCTargetOfTargetWnd_x                                  0xF5B5B0
#define pinstCTargetWnd_x                                          0xDE77F8
#define pinstCTaskOverlayWnd_x                                     0xDE785C
#define pinstCTaskSelectWnd_x                                      0xF5B708
#define pinstCTaskManager_x                                        0xCB9298
#define pinstCTaskTemplateSelectWnd_x                              0xF5B7B8
#define pinstCTaskWnd_x                                            0xF5B868
#define pinstCTextEntryWnd_x                                       0xDE7840
#define pinstCTimeLeftWnd_x                                        0xDE7720
#define pinstCTipWndCONTEXT_x                                      0xF5BA6C
#define pinstCTipWndOFDAY_x                                        0xF5BA68
#define pinstCTitleWnd_x                                           0xF5BB18
#define pinstCTrackingWnd_x                                        0xDE77E4
#define pinstCTradeskillWnd_x                                      0xF5BC80
#define pinstCTradeWnd_x                                           0xDE7718
#define pinstCTrainWnd_x                                           0xDE7ABC
#define pinstCTributeBenefitWnd_x                                  0xF5BE80
#define pinstCTributeMasterWnd_x                                   0xF5BF30
#define pinstCTributeTrophyWnd_x                                   0xF5BFE0
#define pinstCVideoModesWnd_x                                      0xDE7890
#define pinstCVoiceMacroWnd_x                                      0xF45330
#define pinstCVoteResultsWnd_x                                     0xDE774C
#define pinstCVoteWnd_x                                            0xDE7738
#define pinstCWebManager_x                                         0xF459AC
#define pinstCZoneGuideWnd_x                                       0xDE7860
#define pinstCZonePathWnd_x                                        0xDE7878

#define pinstEQSuiteTextureLoader_x                                0xC86658
#define pinstItemIconCache_x                                       0xF54EC0
#define pinstLootFiltersManager_x                                  0xCB8A08
#define pinstRewardSelectionWnd_x                                  0xF59F50

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C1340
#define __CastRay2_x                                               0x5C1390
#define __ConvertItemTags_x                                        0x5DD060
#define __CleanItemTags_x                                          0x47CD60
#define __DoesFileExist_x                                          0x8F6A70
#define __EQGetTime_x                                              0x8F3570
#define __ExecuteCmd_x                                             0x5B9CC0
#define __FixHeading_x                                             0x989750
#define __FlushDxKeyboard_x                                        0x6AD040
#define __GameLoop_x                                               0x6B0370
#define __get_bearing_x                                            0x5C0EA0
#define __get_melee_range_x                                        0x5C1580
#define __GetAnimationCache_x                                      0x7156B0
#define __GetGaugeValueFromEQ_x                                    0x8070D0
#define __GetLabelFromEQ_x                                         0x808BB0
#define __GetXTargetType_x                                         0x98B1A0
#define __HandleMouseWheel_x                                       0x6B1250
#define __HeadingDiff_x                                            0x9897C0
#define __HelpPath_x                                               0xF4086C
#define __LoadFrontEnd_x                                           0x6AD680
#define __NewUIINI_x                                               0x806DA0
#define __ProcessGameEvents_x                                      0x621EA0
#define __ProcessMouseEvent_x                                      0x621630
#define __SaveColors_x                                             0x55ABD0
#define __STMLToText_x                                             0x92CC90
#define __ToggleKeyRingItem_x                                      0x519370
#define CMemoryMappedFile__SetFile_x                               0xA78B60
#define CrashDetected_x                                            0x6AF130
#define DrawNetStatus_x                                            0x64E130
#define Expansion_HoT_x                                            0xEA27C0
#define Teleport_Table_Size_x                                      0xE99EB8
#define Teleport_Table_x                                           0xE9A380
#define Util__FastTime_x                                           0x8F3140
#define __CopyLayout_x                                             0x63C260
#define __WndProc_x                                                0x6AF630
#define __ProcessKeyboardEvent_x                                   0x6AEBD0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4900F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4990D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498EA0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493680
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492AD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x562D50
#define AltAdvManager__IsAbilityReady_x                            0x561AF0
#define AltAdvManager__GetAAById_x                                 0x561E80
#define AltAdvManager__CanTrainAbility_x                           0x561EF0
#define AltAdvManager__CanSeeAbility_x                             0x562250

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA9C0
#define CharacterZoneClient__HasSkill_x                            0x4D5840
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6F60
#define CharacterZoneClient__IsStackBlocked_x                      0x4C20B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BB540
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D98E0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D99C0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9AA0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C41A0
#define CharacterZoneClient__BardCastBard_x                        0x4C6BD0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BEF50
#define CharacterZoneClient__GetEffect_x                           0x4BB480
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5210
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C52E0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5330
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5480
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5660
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B34A0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7EC0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7940

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D6E90
#define CBankWnd__WndNotification_x                                0x6D6C70

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E4810

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92A470
#define CButtonWnd__CButtonWnd_x                                   0x929040

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7048C0
#define CChatManager__InitContextMenu_x                            0x6FD9F0
#define CChatManager__FreeChatWindow_x                             0x703400
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E93B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x704540
#define CChatManager__CreateChatWindow_x                           0x703A40

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E94C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93D620
#define CContextMenu__dCContextMenu_x                              0x93D850
#define CContextMenu__AddMenuItem_x                                0x93D860
#define CContextMenu__RemoveMenuItem_x                             0x93DB60
#define CContextMenu__RemoveAllMenuItems_x                         0x93DB80
#define CContextMenu__CheckMenuItem_x                              0x93DC00
#define CContextMenu__SetMenuItem_x                                0x93DA90
#define CContextMenu__AddSeparator_x                               0x93D9F0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93E1A0
#define CContextMenuManager__RemoveMenu_x                          0x93E210
#define CContextMenuManager__PopupMenu_x                           0x93E2D0
#define CContextMenuManager__Flush_x                               0x93E140
#define CContextMenuManager__GetMenu_x                             0x49B2B0
#define CContextMenuManager__CreateDefaultMenu_x                   0x710010

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CE1A0
#define CChatService__GetFriendName_x                              0x8CE1B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7050F0
#define CChatWindow__Clear_x                                       0x7063C0
#define CChatWindow__WndNotification_x                             0x706B50
#define CChatWindow__AddHistory_x                                  0x705C80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93AA80
#define CComboWnd__Draw_x                                          0x939F80
#define CComboWnd__GetCurChoice_x                                  0x93A8C0
#define CComboWnd__GetListRect_x                                   0x93A430
#define CComboWnd__GetTextRect_x                                   0x93AAE0
#define CComboWnd__InsertChoice_x                                  0x93A5C0
#define CComboWnd__SetColors_x                                     0x93A590
#define CComboWnd__SetChoice_x                                     0x93A890
#define CComboWnd__GetItemCount_x                                  0x93A8D0
#define CComboWnd__GetCurChoiceText_x                              0x93A910
#define CComboWnd__GetChoiceText_x                                 0x93A8E0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93A650

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70DA20
#define CContainerWnd__vftable_x                                   0xAFC4B4
#define CContainerWnd__SetContainer_x                              0x70EF80

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x555580
#define CDisplay__PreZoneMainUI_x                                  0x555590
#define CDisplay__CleanGameUI_x                                    0x55A990
#define CDisplay__GetClickedActor_x                                0x54D9E0
#define CDisplay__GetUserDefinedColor_x                            0x546050
#define CDisplay__GetWorldFilePath_x                               0x54F450
#define CDisplay__is3dON_x                                         0x54A640
#define CDisplay__ReloadUI_x                                       0x554A90
#define CDisplay__WriteTextHD2_x                                   0x54A430
#define CDisplay__TrueDistance_x                                   0x551110
#define CDisplay__SetViewActor_x                                   0x54D300
#define CDisplay__GetFloorHeight_x                                 0x54A700
#define CDisplay__SetRenderWindow_x                                0x549080
#define CDisplay__ToggleScreenshotMode_x                           0x54CDD0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95D2B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x940B00
#define CEditWnd__EnsureCaretVisible_x                             0x942CC0
#define CEditWnd__GetCaretPt_x                                     0x941C70
#define CEditWnd__GetCharIndexPt_x                                 0x941A20
#define CEditWnd__GetDisplayString_x                               0x9418C0
#define CEditWnd__GetHorzOffset_x                                  0x9401A0
#define CEditWnd__GetLineForPrintableChar_x                        0x942BC0
#define CEditWnd__GetSelStartPt_x                                  0x941CD0
#define CEditWnd__GetSTMLSafeText_x                                0x9416E0
#define CEditWnd__PointFromPrintableChar_x                         0x9427F0
#define CEditWnd__SelectableCharFromPoint_x                        0x942960
#define CEditWnd__SetEditable_x                                    0x941DA0
#define CEditWnd__SetWindowTextA_x                                 0x941460
#define CEditWnd__ReplaceSelection_x                               0x942460
#define CEditWnd__ReplaceSelection1_x                              0x9423E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60F4A0
#define CEverQuest__ClickedPlayer_x                                0x601650
#define CEverQuest__CreateTargetIndicator_x                        0x61F010
#define CEverQuest__DeleteTargetIndicator_x                        0x61F0A0
#define CEverQuest__DoTellWindow_x                                 0x4E95A0
#define CEverQuest__OutputTextToLog_x                              0x4E9870
#define CEverQuest__DropHeldItemOnGround_x                         0x5F67B0
#define CEverQuest__dsp_chat_x                                     0x4E9C00
#define CEverQuest__trimName_x                                     0x61B1C0
#define CEverQuest__Emote_x                                        0x60FD00
#define CEverQuest__EnterZone_x                                    0x609E00
#define CEverQuest__GetBodyTypeDesc_x                              0x614750
#define CEverQuest__GetClassDesc_x                                 0x614D90
#define CEverQuest__GetClassThreeLetterCode_x                      0x615390
#define CEverQuest__GetDeityDesc_x                                 0x61D860
#define CEverQuest__GetLangDesc_x                                  0x615550
#define CEverQuest__GetRaceDesc_x                                  0x614D70
#define CEverQuest__InterpretCmd_x                                 0x61DE30
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FA940
#define CEverQuest__LMouseUp_x                                     0x5F8CD0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FB220
#define CEverQuest__RMouseUp_x                                     0x5F9C50
#define CEverQuest__SetGameState_x                                 0x5F6540
#define CEverQuest__UPCNotificationFlush_x                         0x61B0C0
#define CEverQuest__IssuePetCommand_x                              0x616960
#define CEverQuest__ReportSuccessfulHit_x                          0x611050

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71F820
#define CGaugeWnd__CalcLinesFillRect_x                             0x71F880
#define CGaugeWnd__Draw_x                                          0x71EEA0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF7A0
#define CGuild__GetGuildName_x                                     0x4AE250
#define CGuild__GetGuildIndex_x                                    0x4AE850

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x739590

//CHotButton
#define CHotButton__SetCheck_x                                     0x630760
#define CHotButton__SetButtonSize_x                                0x630B20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7465E0
#define CInvSlotMgr__MoveItem_x                                    0x745300
#define CInvSlotMgr__SelectSlot_x                                  0x7466B0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x743B20
#define CInvSlot__SliderComplete_x                                 0x741870
#define CInvSlot__GetItemBase_x                                    0x741210
#define CInvSlot__UpdateItem_x                                     0x741380

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x748130
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7472D0
#define CInvSlotWnd__HandleLButtonUp_x                             0x747CB0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x802440
#define CItemDisplayWnd__UpdateStrings_x                           0x7568A0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x750590
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x750AA0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x756EA0
#define CItemDisplayWnd__AboutToShow_x                             0x7564E0
#define CItemDisplayWnd__WndNotification_x                         0x758100
#define CItemDisplayWnd__RequestConvertItem_x                      0x757A40
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x755540
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x756300

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x832EB0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75C610

// CLabel 
#define CLabel__Draw_x                                             0x7620F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9132A0
#define CListWnd__dCListWnd_x                                      0x9135C0
#define CListWnd__AddColumn_x                                      0x917A20
#define CListWnd__AddColumn1_x                                     0x917A70
#define CListWnd__AddLine_x                                        0x917E00
#define CListWnd__AddString_x                                      0x917C00
#define CListWnd__CalculateFirstVisibleLine_x                      0x9177E0
#define CListWnd__CalculateVSBRange_x                              0x9175C0
#define CListWnd__ClearSel_x                                       0x9185E0
#define CListWnd__ClearAllSel_x                                    0x918640
#define CListWnd__CloseAndUpdateEditWindow_x                       0x919040
#define CListWnd__Compare_x                                        0x916EF0
#define CListWnd__Draw_x                                           0x9136F0
#define CListWnd__DrawColumnSeparators_x                           0x915EC0
#define CListWnd__DrawHeader_x                                     0x916330
#define CListWnd__DrawItem_x                                       0x916830
#define CListWnd__DrawLine_x                                       0x916030
#define CListWnd__DrawSeparator_x                                  0x915F60
#define CListWnd__EnableLine_x                                     0x9157A0
#define CListWnd__EnsureVisible_x                                  0x918F70
#define CListWnd__ExtendSel_x                                      0x918510
#define CListWnd__GetColumnTooltip_x                               0x9152E0
#define CListWnd__GetColumnMinWidth_x                              0x915350
#define CListWnd__GetColumnWidth_x                                 0x915250
#define CListWnd__GetCurSel_x                                      0x914BE0
#define CListWnd__GetItemAtPoint_x                                 0x915A10
#define CListWnd__GetItemAtPoint1_x                                0x915A80
#define CListWnd__GetItemData_x                                    0x914C60
#define CListWnd__GetItemHeight_x                                  0x915020
#define CListWnd__GetItemIcon_x                                    0x914DF0
#define CListWnd__GetItemRect_x                                    0x915890
#define CListWnd__GetItemText_x                                    0x914CA0
#define CListWnd__GetSelList_x                                     0x918690
#define CListWnd__GetSeparatorRect_x                               0x915CC0
#define CListWnd__InsertLine_x                                     0x9181F0
#define CListWnd__RemoveLine_x                                     0x918340
#define CListWnd__SetColors_x                                      0x917590
#define CListWnd__SetColumnJustification_x                         0x9172C0
#define CListWnd__SetColumnLabel_x                                 0x917BA0
#define CListWnd__SetColumnWidth_x                                 0x9171E0
#define CListWnd__SetCurSel_x                                      0x918450
#define CListWnd__SetItemColor_x                                   0x918C30
#define CListWnd__SetItemData_x                                    0x918BF0
#define CListWnd__SetItemText_x                                    0x918800
#define CListWnd__ShiftColumnSeparator_x                           0x917380
#define CListWnd__Sort_x                                           0x917070
#define CListWnd__ToggleSel_x                                      0x918480
#define CListWnd__SetColumnsSizable_x                              0x917430
#define CListWnd__SetItemWnd_x                                     0x918AB0
#define CListWnd__GetItemWnd_x                                     0x914E40
#define CListWnd__SetItemIcon_x                                    0x918880
#define CListWnd__CalculateCustomWindowPositions_x                 0x9178E0
#define CListWnd__SetVScrollPos_x                                  0x9171C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7778D0
#define CMapViewWnd__GetWorldCoordinates_x                         0x775FE0
#define CMapViewWnd__HandleLButtonDown_x                           0x773020

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x797BC0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7984A0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7989D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79B980
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x796730
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A1540
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7977D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89C1C0
#define CPacketScrambler__hton_x                                   0x89C1B0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x932240
#define CSidlManager__FindScreenPieceTemplate_x                    0x932650
#define CSidlManager__FindScreenPieceTemplate1_x                   0x932440
#define CSidlManager__CreateLabel_x                                0x7F9690
#define CSidlManager__CreateXWndFromTemplate_x                     0x9355B0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x935790
#define CSidlManager__CreateXWnd_x                                 0x7F95C0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F9B90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92ED20
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92EC20
#define CSidlScreenWnd__ConvertToRes_x                             0x957E00
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92E710
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92E400
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92E4D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92E5A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92F1C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x92F690
#define CSidlScreenWnd__GetSidlPiece_x                             0x92F3B0
#define CSidlScreenWnd__Init1_x                                    0x92E020
#define CSidlScreenWnd__LoadIniInfo_x                              0x92F6E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x930220
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92D440
#define CSidlScreenWnd__StoreIniInfo_x                             0x92FDA0
#define CSidlScreenWnd__StoreIniVis_x                              0x930100
#define CSidlScreenWnd__WndNotification_x                          0x92F0D0
#define CSidlScreenWnd__GetChildItem_x                             0x92F610
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91EE40
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D6AF0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x696350
#define CSkillMgr__GetSkillCap_x                                   0x696530
#define CSkillMgr__GetNameToken_x                                  0x695AD0
#define CSkillMgr__IsActivatedSkill_x                              0x695C10
#define CSkillMgr__IsCombatSkill_x                                 0x695B50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93EF80
#define CSliderWnd__SetValue_x                                     0x93EDF0
#define CSliderWnd__SetNumTicks_x                                  0x93EE50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FF810

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9478B0
#define CStmlWnd__ParseSTML_x                                      0x948C00
#define CStmlWnd__CalculateHSBRange_x                              0x9489D0
#define CStmlWnd__CalculateVSBRange_x                              0x948950
#define CStmlWnd__CanBreakAtCharacter_x                            0x94CD20
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94D9B0
#define CStmlWnd__ForceParseNow_x                                  0x947EA0
#define CStmlWnd__GetNextTagPiece_x                                0x94CC80
#define CStmlWnd__GetSTMLText_x                                    0x50A840
#define CStmlWnd__GetVisibleText_x                                 0x947EC0
#define CStmlWnd__InitializeWindowVariables_x                      0x94D800
#define CStmlWnd__MakeStmlColorTag_x                               0x946F20
#define CStmlWnd__MakeWndNotificationTag_x                         0x946F90
#define CStmlWnd__SetSTMLText_x                                    0x945FD0
#define CStmlWnd__StripFirstSTMLLines_x                            0x94EAB0
#define CStmlWnd__UpdateHistoryString_x                            0x94DBC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x945120
#define CTabWnd__DrawCurrentPage_x                                 0x945850
#define CTabWnd__DrawTab_x                                         0x945570
#define CTabWnd__GetCurrentPage_x                                  0x944920
#define CTabWnd__GetPageInnerRect_x                                0x944B60
#define CTabWnd__GetTabInnerRect_x                                 0x944AA0
#define CTabWnd__GetTabRect_x                                      0x944950
#define CTabWnd__InsertPage_x                                      0x944D70
#define CTabWnd__RemovePage_x                                      0x944EE0
#define CTabWnd__SetPage_x                                         0x944BE0
#define CTabWnd__SetPageRect_x                                     0x945060
#define CTabWnd__UpdatePage_x                                      0x945430
#define CTabWnd__GetPageFromTabIndex_x                             0x9454B0
#define CTabWnd__GetCurrentTabIndex_x                              0x944910

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75CA60
#define CPageWnd__SetTabText_x                                     0x944470
#define CPageWnd__FlashTab_x                                       0x9444D0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8B80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91BD30
#define CTextureFont__GetTextExtent_x                              0x91BEF0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AA510
#define CHtmlComponentWnd__ValidateUri_x                           0x73AF80
#define CHtmlWnd__SetClientCallbacks_x                             0x635BA0
#define CHtmlWnd__AddObserver_x                                    0x635BC0
#define CHtmlWnd__RemoveObserver_x                                 0x635C20
#define Window__getProgress_x                                      0x8515A0
#define Window__getStatus_x                                        0x8515C0
#define Window__getURI_x                                           0x8515D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x954C10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x908E90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E90F0
#define CXStr__CXStr1_x                                            0x5058A0
#define CXStr__CXStr3_x                                            0x8EF530
#define CXStr__dCXStr_x                                            0x477F60
#define CXStr__operator_equal_x                                    0x8EF760
#define CXStr__operator_equal1_x                                   0x8EF7A0
#define CXStr__operator_plus_equal1_x                              0x8F0230
#define CXStr__SetString_x                                         0x8F2120
#define CXStr__operator_char_p_x                                   0x8EFC70
#define CXStr__GetChar_x                                           0x8F1A70
#define CXStr__Delete_x                                            0x8F1320
#define CXStr__GetUnicode_x                                        0x8F1AE0
#define CXStr__GetLength_x                                         0x4A8930
#define CXStr__Mid_x                                               0x47D110
#define CXStr__Insert_x                                            0x8F1B40
#define CXStr__FindNext_x                                          0x8F1790

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93D230
#define CXWnd__BringToTop_x                                        0x922680
#define CXWnd__Center_x                                            0x922200
#define CXWnd__ClrFocus_x                                          0x922020
#define CXWnd__Destroy_x                                           0x9220C0
#define CXWnd__DoAllDrawing_x                                      0x91E5F0
#define CXWnd__DrawChildren_x                                      0x91E5C0
#define CXWnd__DrawColoredRect_x                                   0x91EA50
#define CXWnd__DrawTooltip_x                                       0x91D120
#define CXWnd__DrawTooltipAtPoint_x                                0x91D1E0
#define CXWnd__GetBorderFrame_x                                    0x91E8B0
#define CXWnd__GetChildWndAt_x                                     0x922720
#define CXWnd__GetClientClipRect_x                                 0x9208B0
#define CXWnd__GetScreenClipRect_x                                 0x920960
#define CXWnd__GetScreenRect_x                                     0x920B10
#define CXWnd__GetRelativeRect_x                                   0x920BE0
#define CXWnd__GetTooltipRect_x                                    0x91EAA0
#define CXWnd__GetWindowTextA_x                                    0x49C9A0
#define CXWnd__IsActive_x                                          0x91F1B0
#define CXWnd__IsDescendantOf_x                                    0x921530
#define CXWnd__IsReallyVisible_x                                   0x921560
#define CXWnd__IsType_x                                            0x922D80
#define CXWnd__Move_x                                              0x9215D0
#define CXWnd__Move1_x                                             0x921690
#define CXWnd__ProcessTransition_x                                 0x9221B0
#define CXWnd__Refade_x                                            0x921970
#define CXWnd__Resize_x                                            0x921C40
#define CXWnd__Right_x                                             0x922440
#define CXWnd__SetFocus_x                                          0x921FE0
#define CXWnd__SetFont_x                                           0x922050
#define CXWnd__SetKeyTooltip_x                                     0x922BA0
#define CXWnd__SetMouseOver_x                                      0x91FA00
#define CXWnd__StartFade_x                                         0x921410
#define CXWnd__GetChildItem_x                                      0x922890
#define CXWnd__SetParent_x                                         0x9212D0
#define CXWnd__Minimize_x                                          0x921CB0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x958E80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9255C0
#define CXWndManager__DrawWindows_x                                0x9255E0
#define CXWndManager__GetKeyboardFlags_x                           0x927CE0
#define CXWndManager__HandleKeyboardMsg_x                          0x927890
#define CXWndManager__RemoveWnd_x                                  0x927F00
#define CXWndManager__RemovePendingDeletionWnd_x                   0x928460

// CDBStr
#define CDBStr__GetString_x                                        0x545020

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BF6B0
#define EQ_Character__Cur_HP_x                                     0x4D2880
#define EQ_Character__Cur_Mana_x                                   0x4D9FA0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2720
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B30E0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3230
#define EQ_Character__GetHPRegen_x                                 0x4DFE70
#define EQ_Character__GetEnduranceRegen_x                          0x4E0470
#define EQ_Character__GetManaRegen_x                               0x4E08B0
#define EQ_Character__Max_Endurance_x                              0x65C870
#define EQ_Character__Max_HP_x                                     0x4D26B0
#define EQ_Character__Max_Mana_x                                   0x65C670
#define EQ_Character__doCombatAbility_x                            0x65EC60
#define EQ_Character__UseSkill_x                                   0x4E26B0
#define EQ_Character__GetConLevel_x                                0x655040
#define EQ_Character__IsExpansionFlag_x                            0x5B84A0
#define EQ_Character__TotalEffect_x                                0x4C64C0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3470
#define EQ_Character__SpellDuration_x                              0x4C2FA0
#define EQ_Character__MySpellDuration_x                            0x4B1A10
#define EQ_Character__GetAdjustedSkill_x                           0x4D5600
#define EQ_Character__GetBaseSkill_x                               0x4D65A0
#define EQ_Character__CanUseItem_x                                 0x4DA2B0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BB150

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x672BB0

//PcClient
#define PcClient__vftable_x                                        0xAEFF3C
#define PcClient__PcClient_x                                       0x6527A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA0F0
#define CCharacterListWnd__EnterWorld_x                            0x4B9AC0
#define CCharacterListWnd__Quit_x                                  0x4B9810
#define CCharacterListWnd__UpdateList_x                            0x4B9CB0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x636D60
#define EQ_Item__CreateItemTagString_x                             0x895790
#define EQ_Item__IsStackable_x                                     0x89A410
#define EQ_Item__GetImageNum_x                                     0x897300
#define EQ_Item__CreateItemClient_x                                0x635FA0
#define EQ_Item__GetItemValue_x                                    0x8985D0
#define EQ_Item__ValueSellMerchant_x                               0x89BDA0
#define EQ_Item__IsKeyRingItem_x                                   0x899D10
#define EQ_Item__CanGoInBag_x                                      0x636E80
#define EQ_Item__IsEmpty_x                                         0x899880
#define EQ_Item__GetMaxItemCount_x                                 0x8989F0
#define EQ_Item__GetHeldItem_x                                     0x8971D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x894FE0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x563A20
#define EQ_LoadingS__Array_x                                       0xC0FC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65D170
#define EQ_PC__GetAlternateAbilityId_x                             0x8A4DD0
#define EQ_PC__GetCombatAbility_x                                  0x8A5440
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A54B0
#define EQ_PC__GetItemRecastTimer_x                                0x65F1E0
#define EQ_PC__HasLoreItem_x                                       0x655850
#define EQ_PC__AlertInventoryChanged_x                             0x654970
#define EQ_PC__GetPcZoneClient_x                                   0x681BB0
#define EQ_PC__RemoveMyAffect_x                                    0x662420
#define EQ_PC__GetKeyRingItems_x                                   0x8A5D40
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A5AD0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A6040

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BE8C0
#define EQItemList__add_object_x                                   0x5EBF10
#define EQItemList__add_item_x                                     0x5BEE20
#define EQItemList__delete_item_x                                  0x5BEE70
#define EQItemList__FreeItemList_x                                 0x5BED70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x541B70

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6744B0
#define EQPlayer__dEQPlayer_x                                      0x667820
#define EQPlayer__DoAttack_x                                       0x67C350
#define EQPlayer__EQPlayer_x                                       0x667EE0
#define EQPlayer__SetNameSpriteState_x                             0x66C1C0
#define EQPlayer__SetNameSpriteTint_x                              0x66D0A0
#define PlayerBase__HasProperty_j_x                                0x987B40
#define EQPlayer__IsTargetable_x                                   0x987FE0
#define EQPlayer__CanSee_x                                         0x987E40
#define EQPlayer__CanSee1_x                                        0x987F10
#define PlayerBase__GetVisibilityLineSegment_x                     0x987C00

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67F650
#define PlayerZoneClient__GetLevel_x                               0x681BF0
#define PlayerZoneClient__IsValidTeleport_x                        0x5ED080
#define PlayerZoneClient__LegalPlayerRace_x                        0x55C820

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x677200
#define EQPlayerManager__GetSpawnByName_x                          0x6772B0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x677340

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63A4C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63A540
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63A580
#define KeypressHandler__ClearCommandStateArray_x                  0x63B970
#define KeypressHandler__HandleKeyDown_x                           0x63B990
#define KeypressHandler__HandleKeyUp_x                             0x63BA30
#define KeypressHandler__SaveKeymapping_x                          0x63BE80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x773740
#define MapViewMap__SaveEx_x                                       0x776B00
#define MapViewMap__SetZoom_x                                      0x77B1C0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B91C0

// StringTable 
#define StringTable__getString_x                                   0x8B40D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x662090
#define PcZoneClient__RemovePetEffect_x                            0x6626C0
#define PcZoneClient__HasAlternateAbility_x                        0x65C4A0
#define PcZoneClient__GetCurrentMod_x                              0x4E57D0
#define PcZoneClient__GetModCap_x                                  0x4E56D0
#define PcZoneClient__CanEquipItem_x                               0x65CB50
#define PcZoneClient__GetItemByID_x                                0x65F660
#define PcZoneClient__GetItemByItemClass_x                         0x65F7B0
#define PcZoneClient__RemoveBuffEffect_x                           0x6626E0
#define PcZoneClient__BandolierSwap_x                              0x65D730
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65F180

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F1C60

//IconCache
#define IconCache__GetIcon_x                                       0x7150B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70CBC0
#define CContainerMgr__CloseContainer_x                            0x70CE90
#define CContainerMgr__OpenExperimentContainer_x                   0x70D910

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CBEA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62EF40

//CLootWnd
#define CLootWnd__LootAll_x                                        0x769B90
#define CLootWnd__RequestLootSlot_x                                0x768E70

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58B250
#define EQ_Spell__SpellAffects_x                                   0x58B6C0
#define EQ_Spell__SpellAffectBase_x                                0x58B480
#define EQ_Spell__IsStackable_x                                    0x4CA2A0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA0C0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B73A0
#define EQ_Spell__IsSPAStacking_x                                  0x58C510
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58BA20
#define EQ_Spell__IsNoRemove_x                                     0x4CA280
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58C520
#define __IsResEffectSpell_x                                       0x4C94F0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACD40

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C3700

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x812B50
#define CTargetWnd__WndNotification_x                              0x812390
#define CTargetWnd__RefreshTargetBuffs_x                           0x812660
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8114F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8171C0
#define CTaskWnd__ConfirmAbandonTask_x                             0x819E00

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F580
#define CTaskManager__HandleMessage_x                              0x53D9F0
#define CTaskManager__GetTaskStatus_x                              0x53F630
#define CTaskManager__GetElementDescription_x                      0x53F6B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x586310
#define EqSoundManager__PlayScriptMp3_x                            0x5865D0
#define EqSoundManager__SoundAssistPlay_x                          0x69A270
#define EqSoundManager__WaveInstancePlay_x                         0x6997E0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530910

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x943980
#define CTextureAnimation__Draw_x                                  0x943B80

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93F8E0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B500
#define CAltAbilityData__GetMercMaxRank_x                          0x56B490
#define CAltAbilityData__GetMaxRank_x                              0x560970

//CTargetRing
#define CTargetRing__Cast_x                                        0x62D060

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA0A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x517540
#define CharacterBase__CreateItemIndex_x                           0x635150
#define CharacterBase__GetItemPossession_x                         0x503160
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CBD60
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CBDC0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F3C50
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F4480
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F4530

//messages
#define msg_spell_worn_off_x                                       0x5B0400
#define msg_new_text_x                                             0x5A4D90
#define __msgTokenTextParam_x                                      0x5B26A0
#define msgTokenText_x                                             0x5B28F0

//SpellManager
#define SpellManager__vftable_x                                    0xAD82BC
#define SpellManager__SpellManager_x                               0x69D5A0
#define Spellmanager__LoadTextSpells_x                             0x69DE90
#define SpellManager__GetSpellByGroupAndRank_x                     0x69D770

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98BA90

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517B90
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B6840
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64DF90
#define ItemGlobalIndex__IsValidIndex_x                            0x517C20

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C40A0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C4320

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x762430

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7112B0
#define CCursorAttachment__AttachToCursor1_x                       0x7112F0
#define CCursorAttachment__Deactivate_x                            0x7122E0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9365F0
#define CSidlManagerBase__CreatePageWnd_x                          0x935DE0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x932060
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x931FF0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9537C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x953480

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514A90
#define CFindItemWnd__WndNotification_x                            0x515570
#define CFindItemWnd__Update_x                                     0x5160E0
#define CFindItemWnd__PickupSelectedItem_x                         0x5142C0

//IString
#define IString__Append_x                                          0x5049B0

//Camera
#define CDisplay__cameraType_x                                     0xDE7898
#define EverQuest__Cameras_x                                       0xEA2B0C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D500
#define LootFiltersManager__GetItemFilterData_x                    0x51CE00
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51CE30
#define LootFiltersManager__SetItemLootFilter_x                    0x51D050

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B9C10

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9917C0
#define CResolutionHandler__GetWindowedStyle_x                     0x694D70

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x709870

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D97A0
#define CDistillerInfo__Instance_x                                 0x8D9740

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x728800
#define CGroupWnd__UpdateDisplay_x                                 0x727B50

//ItemBase
#define ItemBase__IsLore_x                                         0x899DC0
#define ItemBase__IsLoreEquipped_x                                 0x899E40

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EBE70
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EBFB0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EC010

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68A2C0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68DC30

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50AE40

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F6F50
#define FactionManagerClient__HandleFactionMessage_x               0x4F75C0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F7B80
#define FactionManagerClient__GetMaxFaction_x                      0x4F7B9F
#define FactionManagerClient__GetMinFaction_x                      0x4F7B50

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x503130

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91ACE0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BCB0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5033C0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56A9B0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A0E30

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68A2C0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8940

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BED10

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF401A0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BD5E0
#define CAAWnd__UpdateSelected_x                                   0x6B9E50
#define CAAWnd__Update_x                                           0x6BC900

//CXRect
#define CXRect__operator_and_x                                     0x71F8E0

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
