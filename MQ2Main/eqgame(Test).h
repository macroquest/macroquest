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
#define __ExpectedVersionDate                                     "Sep  8 2020"
#define __ExpectedVersionTime                                     "12:37:25"
#define __ActualVersionDate_x                                      0xAF32AC
#define __ActualVersionTime_x                                      0xAF32A0
#define __ActualVersionBuild_x                                     0xAE12D4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x640A20
#define __MemChecker1_x                                            0x8F3770
#define __MemChecker2_x                                            0x6B0EB0
#define __MemChecker3_x                                            0x6B0E00
#define __MemChecker4_x                                            0x849F20
#define __EncryptPad0_x                                            0xC284E8
#define __EncryptPad1_x                                            0xC85D28
#define __EncryptPad2_x                                            0xC388B8
#define __EncryptPad3_x                                            0xC384B8
#define __EncryptPad4_x                                            0xC762C8
#define __EncryptPad5_x                                            0xF480B0
#define __AC1_x                                                    0x808A06
#define __AC2_x                                                    0x5FA49F
#define __AC3_x                                                    0x601AF0
#define __AC4_x                                                    0x605AA0
#define __AC5_x                                                    0x60BD8F
#define __AC6_x                                                    0x610246
#define __AC7_x                                                    0x5F9F10
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19FCDC

// Direct Input
#define DI8__Main_x                                                0xF480D0
#define DI8__Keyboard_x                                            0xF480D4
#define DI8__Mouse_x                                               0xF480EC
#define DI8__Mouse_Copy_x                                          0xEA144C
#define DI8__Mouse_Check_x                                         0xF45C04
#define __AutoSkillArray_x                                         0xEA2368
#define __Attack_x                                                 0xF4018B
#define __Autofire_x                                               0xF4018C
#define __BindList_x                                               0xC16F38
#define g_eqCommandStates_x                                        0xC17CB8
#define __Clicks_x                                                 0xEA1504
#define __CommandList_x                                            0xC18878
#define __CurrentMapLabel_x                                        0xF58AA4
#define __CurrentSocial_x                                          0xC007C8
#define __DoAbilityList_x                                          0xED7CAC
#define __do_loot_x                                                0x5C6100
#define __DrawHandler_x                                            0x15D7A98
#define __GroupCount_x                                             0xE9C522
#define __Guilds_x                                                 0xEA0388
#define __gWorld_x                                                 0xE9C4B4
#define __HWnd_x                                                   0xF480F0
#define __heqmain_x                                                0xF48098
#define __InChatMode_x                                             0xEA1434
#define __LastTell_x                                               0xEA33A8
#define __LMouseHeldTime_x                                         0xEA1570
#define __Mouse_x                                                  0xF480BC
#define __MouseLook_x                                              0xEA14CA
#define __MouseEventTime_x                                         0xF40C6C
#define __gpbCommandEvent_x                                        0xE99E20
#define __NetStatusToggle_x                                        0xEA14CD
#define __PCNames_x                                                0xEA2958
#define __RangeAttackReady_x                                       0xEA264C
#define __RMouseHeldTime_x                                         0xEA156C
#define __RunWalkState_x                                           0xEA1438
#define __ScreenMode_x                                             0xDE77B8
#define __ScreenX_x                                                0xEA13EC
#define __ScreenY_x                                                0xEA13E8
#define __ScreenXMax_x                                             0xEA13F0
#define __ScreenYMax_x                                             0xEA13F4
#define __ServerHost_x                                             0xE99FEB
#define __ServerName_x                                             0xED7C6C
#define __ShiftKeyDown_x                                           0xEA1AC8
#define __ShowNames_x                                              0xEA2808
#define EverQuestInfo__bSocialChanged_x                            0xED7CF4
#define __Socials_x                                                0xED7D6C
#define __SubscriptionType_x                                       0xF9CD68
#define __TargetAggroHolder_x                                      0xF5B458
#define __ZoneType_x                                               0xEA18C8
#define __GroupAggro_x                                             0xF5B498
#define __LoginName_x                                              0xF4882C
#define __Inviter_x                                                0xF40108
#define __AttackOnAssist_x                                         0xEA27C4
#define __UseTellWindows_x                                         0xEA2AF0
#define __gfMaxZoomCameraDistance_x                                0xAEAED0
#define __gfMaxCameraDistance_x                                    0xB13B40
#define __pulAutoRun_x                                             0xEA14E8
#define __pulForward_x                                             0xEA2B28
#define __pulBackward_x                                            0xEA2B2C
#define __pulTurnRight_x                                           0xEA2B30
#define __pulTurnLeft_x                                            0xEA2B34
#define __pulStrafeLeft_x                                          0xEA2B38
#define __pulStrafeRight_x                                         0xEA2B3C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9C720
#define instEQZoneInfo_x                                           0xEA16C0
#define pinstActiveBanker_x                                        0xE9A30C
#define pinstActiveCorpse_x                                        0xE9A304
#define pinstActiveGMaster_x                                       0xE9A308
#define pinstActiveMerchant_x                                      0xE9A300
#define pinstAltAdvManager_x                                       0xDE8950
#define pinstBandageTarget_x                                       0xE9A31C
#define pinstCamActor_x                                            0xDE77A8
#define pinstCDBStr_x                                              0xDE766C
#define pinstCDisplay_x                                            0xE9C374
#define pinstCEverQuest_x                                          0xF480E8
#define pinstEverQuestInfo_x                                       0xEA13E0
#define pinstCharData_x                                            0xE9C710
#define pinstCharSpawn_x                                           0xE9A354
#define pinstControlledMissile_x                                   0xE9A364
#define pinstControlledPlayer_x                                    0xE9A354
#define pinstCResolutionHandler_x                                  0x15D7CC8
#define pinstCSidlManager_x                                        0x15D6C60
#define pinstCXWndManager_x                                        0x15D6C5C
#define instDynamicZone_x                                          0xEA0260
#define pinstDZMember_x                                            0xEA0370
#define pinstDZTimerInfo_x                                         0xEA0374
#define pinstEqLogin_x                                             0xF48178
#define instEQMisc_x                                               0xDE75B0
#define pinstEQSoundManager_x                                      0xDE9920
#define pinstEQSpellStrings_x                                      0xCA9F68
#define instExpeditionLeader_x                                     0xEA02AA
#define instExpeditionName_x                                       0xEA02EA
#define pinstGroup_x                                               0xE9C51E
#define pinstImeManager_x                                          0x15D6C58
#define pinstLocalPlayer_x                                         0xE9A2FC
#define pinstMercenaryData_x                                       0xF42758
#define pinstMercenaryStats_x                                      0xF5B524
#define pinstModelPlayer_x                                         0xE9A314
#define pinstPCData_x                                              0xE9C710
#define pinstSkillMgr_x                                            0xF448C8
#define pinstSpawnManager_x                                        0xF43370
#define pinstSpellManager_x                                        0xF44B08
#define pinstSpellSets_x                                           0xF38DB4
#define pinstStringTable_x                                         0xE9C718
#define pinstSwitchManager_x                                       0xE99CC0
#define pinstTarget_x                                              0xE9A350
#define pinstTargetObject_x                                        0xE9A35C
#define pinstTargetSwitch_x                                        0xE9A36C
#define pinstTaskMember_x                                          0xDE7440
#define pinstTrackTarget_x                                         0xE9A358
#define pinstTradeTarget_x                                         0xE9A310
#define instTributeActive_x                                        0xDE75D1
#define pinstViewActor_x                                           0xDE77A4
#define pinstWorldData_x                                           0xE99E10
#define pinstZoneAddr_x                                            0xEA1960
#define pinstPlayerPath_x                                          0xF43408
#define pinstTargetIndicator_x                                     0xF44D70
#define EQObject_Top_x                                             0xE9A0F4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE7AEC
#define pinstCAchievementsWnd_x                                    0xDE7744
#define pinstCActionsWnd_x                                         0xDE7F80
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE7804
#define pinstCAdvancedLootWnd_x                                    0xDE779C
#define pinstCAdventureLeaderboardWnd_x                            0xF52278
#define pinstCAdventureRequestWnd_x                                0xF52328
#define pinstCAdventureStatsWnd_x                                  0xF523D8
#define pinstCAggroMeterWnd_x                                      0xDE77EC
#define pinstCAlarmWnd_x                                           0xDE776C
#define pinstCAlertHistoryWnd_x                                    0xDE787C
#define pinstCAlertStackWnd_x                                      0xDE77D4
#define pinstCAlertWnd_x                                           0xDE77E8
#define pinstCAltStorageWnd_x                                      0xF52738
#define pinstCAudioTriggersWindow_x                                0xC9C298
#define pinstCAuraWnd_x                                            0xDE77A0
#define pinstCAvaZoneWnd_x                                         0xDE7850
#define pinstCBandolierWnd_x                                       0xDE7800
#define pinstCBankWnd_x                                            0xDE7834
#define pinstCBarterMerchantWnd_x                                  0xF53978
#define pinstCBarterSearchWnd_x                                    0xF53A28
#define pinstCBarterWnd_x                                          0xF53AD8
#define pinstCBazaarConfirmationWnd_x                              0xDE7780
#define pinstCBazaarSearchWnd_x                                    0xDE7AF0
#define pinstCBazaarWnd_x                                          0xDE7750
#define pinstCBlockedBuffWnd_x                                     0xDE77C8
#define pinstCBlockedPetBuffWnd_x                                  0xDE77F0
#define pinstCBodyTintWnd_x                                        0xDE7F94
#define pinstCBookWnd_x                                            0xDE782C
#define pinstCBreathWnd_x                                          0xDE7B74
#define pinstCBuffWindowNORMAL_x                                   0xDE7794
#define pinstCBuffWindowSHORT_x                                    0xDE7798
#define pinstCBugReportWnd_x                                       0xDE7830
#define pinstCButtonWnd_x                                          0x15D6EC8
#define pinstCCastingWnd_x                                         0xDE7820
#define pinstCCastSpellWnd_x                                       0xDE7AFC
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE7FA0
#define pinstCChatWindowManager_x                                  0xF54598
#define pinstCClaimWnd_x                                           0xF546F0
#define pinstCColorPickerWnd_x                                     0xDE7A98
#define pinstCCombatAbilityWnd_x                                   0xDE7760
#define pinstCCombatSkillsSelectWnd_x                              0xDE7718
#define pinstCCompassWnd_x                                         0xDE7F84
#define pinstCConfirmationDialog_x                                 0xF595F0
#define pinstCContainerMgr_x                                       0xDE7F90
#define pinstCContextMenuManager_x                                 0x15D6C18
#define pinstCCursorAttachment_x                                   0xDE7814
#define pinstCDynamicZoneWnd_x                                     0xF54CB8
#define pinstCEditLabelWnd_x                                       0xDE7790
#define pinstCEQMainWnd_x                                          0xF54F00
#define pinstCEventCalendarWnd_x                                   0xDE7AF4
#define pinstCExtendedTargetWnd_x                                  0xDE77D0
#define pinstCFacePick_x                                           0xDE771C
#define pinstCFactionWnd_x                                         0xDE773C
#define pinstCFellowshipWnd_x                                      0xF55100
#define pinstCFileSelectionWnd_x                                   0xDE7A94
#define pinstCFindItemWnd_x                                        0xDE772C
#define pinstCFindLocationWnd_x                                    0xF55258
#define pinstCFriendsWnd_x                                         0xDE7730
#define pinstCGemsGameWnd_x                                        0xDE7738
#define pinstCGiveWnd_x                                            0xDE7770
#define pinstCGroupSearchFiltersWnd_x                              0xDE7808
#define pinstCGroupSearchWnd_x                                     0xF55650
#define pinstCGroupWnd_x                                           0xF55700
#define pinstCGuildBankWnd_x                                       0xEA27A8
#define pinstCGuildCreationWnd_x                                   0xF55860
#define pinstCGuildMgmtWnd_x                                       0xF55910
#define pinstCharacterCreation_x                                   0xDE7724
#define pinstCHelpWnd_x                                            0xDE7774
#define pinstCHeritageSelectionWnd_x                               0xDE7728
#define pinstCHotButtonWnd_x                                       0xF57A68
#define pinstCHotButtonWnd1_x                                      0xF57A68
#define pinstCHotButtonWnd2_x                                      0xF57A6C
#define pinstCHotButtonWnd3_x                                      0xF57A70
#define pinstCHotButtonWnd4_x                                      0xF57A74
#define pinstCIconSelectionWnd_x                                   0xDE7810
#define pinstCInspectWnd_x                                         0xDE77F4
#define pinstCInventoryWnd_x                                       0xDE77AC
#define pinstCInvSlotMgr_x                                         0xDE7ADC
#define pinstCItemDisplayManager_x                                 0xF57FF8
#define pinstCItemExpTransferWnd_x                                 0xF58128
#define pinstCItemOverflowWnd_x                                    0xDE7AF8
#define pinstCJournalCatWnd_x                                      0xDE7AAC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE7868
#define pinstCKeyRingWnd_x                                         0xDE781C
#define pinstCLargeDialogWnd_x                                     0xF5A270
#define pinstCLayoutCopyWnd_x                                      0xF58478
#define pinstCLFGuildWnd_x                                         0xF58528
#define pinstCLoadskinWnd_x                                        0xDE7754
#define pinstCLootFiltersCopyWnd_x                                 0xCB8948
#define pinstCLootFiltersWnd_x                                     0xDE77D8
#define pinstCLootSettingsWnd_x                                    0xDE77FC
#define pinstCLootWnd_x                                            0xDE7AB0
#define pinstCMailAddressBookWnd_x                                 0xDE7AE4
#define pinstCMailCompositionWnd_x                                 0xDE7AA0
#define pinstCMailIgnoreListWnd_x                                  0xDE7AE8
#define pinstCMailWnd_x                                            0xDE7A8C
#define pinstCManageLootWnd_x                                      0xDE8E00
#define pinstCMapToolbarWnd_x                                      0xDE777C
#define pinstCMapViewWnd_x                                         0xDE7748
#define pinstCMarketplaceWnd_x                                     0xDE77DC
#define pinstCMerchantWnd_x                                        0xDE7ABC
#define pinstCMIZoneSelectWnd_x                                    0xF58D60
#define pinstCMusicPlayerWnd_x                                     0xDE7A88
#define pinstCNameChangeMercWnd_x                                  0xDE7778
#define pinstCNameChangePetWnd_x                                   0xDE774C
#define pinstCNameChangeWnd_x                                      0xDE778C
#define pinstCNoteWnd_x                                            0xDE7758
#define pinstCObjectPreviewWnd_x                                   0xDE77F8
#define pinstCOptionsWnd_x                                         0xDE7764
#define pinstCPetInfoWnd_x                                         0xDE7884
#define pinstCPetitionQWnd_x                                       0xDE7714
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE7F98
#define pinstCPlayerWnd_x                                          0xDE7878
#define pinstCPopupWndManager_x                                    0xF595F0
#define pinstCProgressionSelectionWnd_x                            0xF596A0
#define pinstCPurchaseGroupWnd_x                                   0xDE784C
#define pinstCPurchaseWnd_x                                        0xDE7824
#define pinstCPvPLeaderboardWnd_x                                  0xF59750
#define pinstCPvPStatsWnd_x                                        0xF59800
#define pinstCQuantityWnd_x                                        0xDE7864
#define pinstCRaceChangeWnd_x                                      0xDE77BC
#define pinstCRaidOptionsWnd_x                                     0xDE780C
#define pinstCRaidWnd_x                                            0xDE7AB8
#define pinstCRealEstateItemsWnd_x                                 0xDE7740
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE7F88
#define pinstCRealEstateManageWnd_x                                0xDE7854
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE7870
#define pinstCRealEstatePlotSearchWnd_x                            0xDE7A90
#define pinstCRealEstatePurchaseWnd_x                              0xDE7AA8
#define pinstCRespawnWnd_x                                         0xDE77E4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE7710
#define pinstCSendMoneyWnd_x                                       0xDE7784
#define pinstCServerListWnd_x                                      0xDE7AB4
#define pinstCSkillsSelectWnd_x                                    0xDE770C
#define pinstCSkillsWnd_x                                          0xDE7F8C
#define pinstCSocialEditWnd_x                                      0xDE7818
#define pinstCSocialWnd_x                                          0xDE7768
#define pinstCSpellBookWnd_x                                       0xDE775C
#define pinstCStoryWnd_x                                           0xDE7F7C
#define pinstCTargetOfTargetWnd_x                                  0xF5B5A8
#define pinstCTargetWnd_x                                          0xDE77E0
#define pinstCTaskOverlayWnd_x                                     0xDE7844
#define pinstCTaskSelectWnd_x                                      0xF5B700
#define pinstCTaskManager_x                                        0xCB9288
#define pinstCTaskTemplateSelectWnd_x                              0xF5B7B0
#define pinstCTaskWnd_x                                            0xF5B860
#define pinstCTextEntryWnd_x                                       0xDE7828
#define pinstCTimeLeftWnd_x                                        0xDE7708
#define pinstCTipWndCONTEXT_x                                      0xF5BA64
#define pinstCTipWndOFDAY_x                                        0xF5BA60
#define pinstCTitleWnd_x                                           0xF5BB10
#define pinstCTrackingWnd_x                                        0xDE77CC
#define pinstCTradeskillWnd_x                                      0xF5BC78
#define pinstCTradeWnd_x                                           0xDE7F9C
#define pinstCTrainWnd_x                                           0xDE7AA4
#define pinstCTributeBenefitWnd_x                                  0xF5BE78
#define pinstCTributeMasterWnd_x                                   0xF5BF28
#define pinstCTributeTrophyWnd_x                                   0xF5BFD8
#define pinstCVideoModesWnd_x                                      0xDE7874
#define pinstCVoiceMacroWnd_x                                      0xF45328
#define pinstCVoteResultsWnd_x                                     0xDE7734
#define pinstCVoteWnd_x                                            0xDE7720
#define pinstCWebManager_x                                         0xF459A4
#define pinstCZoneGuideWnd_x                                       0xDE7848
#define pinstCZonePathWnd_x                                        0xDE7860

#define pinstEQSuiteTextureLoader_x                                0xC86648
#define pinstItemIconCache_x                                       0xF54EB8
#define pinstLootFiltersManager_x                                  0xCB89F8
#define pinstRewardSelectionWnd_x                                  0xF59F48

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C1800
#define __CastRay2_x                                               0x5C1850
#define __ConvertItemTags_x                                        0x5DD350
#define __CleanItemTags_x                                          0x47CE40
#define __DoesFileExist_x                                          0x8F67A0
#define __EQGetTime_x                                              0x8F33A0
#define __ExecuteCmd_x                                             0x5BA160
#define __FixHeading_x                                             0x989200
#define __FlushDxKeyboard_x                                        0x6ACD50
#define __GameLoop_x                                               0x6B0080
#define __get_bearing_x                                            0x5C1360
#define __get_melee_range_x                                        0x5C1A40
#define __GetAnimationCache_x                                      0x7154B0
#define __GetGaugeValueFromEQ_x                                    0x806EB0
#define __GetLabelFromEQ_x                                         0x808990
#define __GetXTargetType_x                                         0x98AC50
#define __HandleMouseWheel_x                                       0x6B0F60
#define __HeadingDiff_x                                            0x989270
#define __HelpPath_x                                               0xF4085C
#define __LoadFrontEnd_x                                           0x6AD390
#define __NewUIINI_x                                               0x806B80
#define __ProcessGameEvents_x                                      0x621E90
#define __ProcessMouseEvent_x                                      0x621620
#define __SaveColors_x                                             0x55A960
#define __STMLToText_x                                             0x92C410
#define __ToggleKeyRingItem_x                                      0x519390
#define CMemoryMappedFile__SetFile_x                               0xA784F0
#define CrashDetected_x                                            0x6AEE40
#define DrawNetStatus_x                                            0x64DDC0
#define Expansion_HoT_x                                            0xEA27B0
#define Teleport_Table_Size_x                                      0xE99EA8
#define Teleport_Table_x                                           0xE9A370
#define Util__FastTime_x                                           0x8F2F70
#define __CopyLayout_x                                             0x63C190
#define __WndProc_x                                                0x6AF340
#define __ProcessKeyboardEvent_x                                   0x6AE8E0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490200
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499200
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498FD0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4937A0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492BF0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x562AC0
#define AltAdvManager__IsAbilityReady_x                            0x561860
#define AltAdvManager__GetAAById_x                                 0x561BF0
#define AltAdvManager__CanTrainAbility_x                           0x561C60
#define AltAdvManager__CanSeeAbility_x                             0x561FC0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CADD0
#define CharacterZoneClient__HasSkill_x                            0x4D5C50
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7370
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2610
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBAA0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9D20
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9E00
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9EE0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4700
#define CharacterZoneClient__BardCastBard_x                        0x4C7130
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF4B0
#define CharacterZoneClient__GetEffect_x                           0x4BB9E0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5770
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5840
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5890
#define CharacterZoneClient__CalcAffectChange_x                    0x4C59E0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5BC0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3820
#define CharacterZoneClient__FindItemByGuid_x                      0x4D82D0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7D50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D6A40
#define CBankWnd__WndNotification_x                                0x6D6820

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E4290

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x929BF0
#define CButtonWnd__CButtonWnd_x                                   0x9287F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x704630
#define CChatManager__InitContextMenu_x                            0x6FD760
#define CChatManager__FreeChatWindow_x                             0x703170
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9710
#define CChatManager__SetLockedActiveChatWindow_x                  0x7042B0
#define CChatManager__CreateChatWindow_x                           0x7037B0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9820

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93CEA0
#define CContextMenu__dCContextMenu_x                              0x93D0E0
#define CContextMenu__AddMenuItem_x                                0x93D0F0
#define CContextMenu__RemoveMenuItem_x                             0x93D400
#define CContextMenu__RemoveAllMenuItems_x                         0x93D420
#define CContextMenu__CheckMenuItem_x                              0x93D4A0
#define CContextMenu__SetMenuItem_x                                0x93D320
#define CContextMenu__AddSeparator_x                               0x93D280

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93DA40
#define CContextMenuManager__RemoveMenu_x                          0x93DAB0
#define CContextMenuManager__PopupMenu_x                           0x93DB70
#define CContextMenuManager__Flush_x                               0x93D9E0
#define CContextMenuManager__GetMenu_x                             0x49B420
#define CContextMenuManager__CreateDefaultMenu_x                   0x70FDD0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CDFD0
#define CChatService__GetFriendName_x                              0x8CDFE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x704EA0
#define CChatWindow__Clear_x                                       0x706170
#define CChatWindow__WndNotification_x                             0x706900
#define CChatWindow__AddHistory_x                                  0x705A30

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93A2F0
#define CComboWnd__Draw_x                                          0x9397E0
#define CComboWnd__GetCurChoice_x                                  0x93A130
#define CComboWnd__GetListRect_x                                   0x939C90
#define CComboWnd__GetTextRect_x                                   0x93A360
#define CComboWnd__InsertChoice_x                                  0x939E20
#define CComboWnd__SetColors_x                                     0x939DF0
#define CComboWnd__SetChoice_x                                     0x93A100
#define CComboWnd__GetItemCount_x                                  0x93A140
#define CComboWnd__GetCurChoiceText_x                              0x93A180
#define CComboWnd__GetChoiceText_x                                 0x93A150
#define CComboWnd__InsertChoiceAtIndex_x                           0x939EC0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70D7E0
#define CContainerWnd__vftable_x                                   0xAFC49C
#define CContainerWnd__SetContainer_x                              0x70ED30

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x555310
#define CDisplay__PreZoneMainUI_x                                  0x555320
#define CDisplay__CleanGameUI_x                                    0x55A720
#define CDisplay__GetClickedActor_x                                0x54D770
#define CDisplay__GetUserDefinedColor_x                            0x545DE0
#define CDisplay__GetWorldFilePath_x                               0x54F1E0
#define CDisplay__is3dON_x                                         0x54A3D0
#define CDisplay__ReloadUI_x                                       0x554820
#define CDisplay__WriteTextHD2_x                                   0x54A1C0
#define CDisplay__TrueDistance_x                                   0x550EA0
#define CDisplay__SetViewActor_x                                   0x54D090
#define CDisplay__GetFloorHeight_x                                 0x54A490
#define CDisplay__SetRenderWindow_x                                0x548E10
#define CDisplay__ToggleScreenshotMode_x                           0x54CB60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95CEA0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9403A0
#define CEditWnd__EnsureCaretVisible_x                             0x942570
#define CEditWnd__GetCaretPt_x                                     0x941520
#define CEditWnd__GetCharIndexPt_x                                 0x9412D0
#define CEditWnd__GetDisplayString_x                               0x941170
#define CEditWnd__GetHorzOffset_x                                  0x93FA40
#define CEditWnd__GetLineForPrintableChar_x                        0x942470
#define CEditWnd__GetSelStartPt_x                                  0x941580
#define CEditWnd__GetSTMLSafeText_x                                0x940F90
#define CEditWnd__PointFromPrintableChar_x                         0x9420A0
#define CEditWnd__SelectableCharFromPoint_x                        0x942210
#define CEditWnd__SetEditable_x                                    0x941650
#define CEditWnd__SetWindowTextA_x                                 0x940D10
#define CEditWnd__ReplaceSelection_x                               0x941D10
#define CEditWnd__ReplaceSelection1_x                              0x941C90

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60F720
#define CEverQuest__ClickedPlayer_x                                0x6018D0
#define CEverQuest__CreateTargetIndicator_x                        0x61F000
#define CEverQuest__DeleteTargetIndicator_x                        0x61F090
#define CEverQuest__DoTellWindow_x                                 0x4E9900
#define CEverQuest__OutputTextToLog_x                              0x4E9BD0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F6A20
#define CEverQuest__dsp_chat_x                                     0x4E9F60
#define CEverQuest__trimName_x                                     0x61B1F0
#define CEverQuest__Emote_x                                        0x60FF80
#define CEverQuest__EnterZone_x                                    0x60A080
#define CEverQuest__GetBodyTypeDesc_x                              0x614780
#define CEverQuest__GetClassDesc_x                                 0x614DC0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6153C0
#define CEverQuest__GetDeityDesc_x                                 0x61D850
#define CEverQuest__GetLangDesc_x                                  0x615580
#define CEverQuest__GetRaceDesc_x                                  0x614DA0
#define CEverQuest__InterpretCmd_x                                 0x61DE20
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FABC0
#define CEverQuest__LMouseUp_x                                     0x5F8F40
#define CEverQuest__RightClickedOnPlayer_x                         0x5FB4A0
#define CEverQuest__RMouseUp_x                                     0x5F9ED0
#define CEverQuest__SetGameState_x                                 0x5F67B0
#define CEverQuest__UPCNotificationFlush_x                         0x61B0F0
#define CEverQuest__IssuePetCommand_x                              0x616990
#define CEverQuest__ReportSuccessfulHit_x                          0x6112D0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71F560
#define CGaugeWnd__CalcLinesFillRect_x                             0x71F5C0
#define CGaugeWnd__Draw_x                                          0x71EBE0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFBB0
#define CGuild__GetGuildName_x                                     0x4AE660
#define CGuild__GetGuildIndex_x                                    0x4AEC60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x739250

//CHotButton
#define CHotButton__SetCheck_x                                     0x6306D0
#define CHotButton__SetButtonSize_x                                0x630A90

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x746350
#define CInvSlotMgr__MoveItem_x                                    0x745020
#define CInvSlotMgr__SelectSlot_x                                  0x746420

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x743810
#define CInvSlot__SliderComplete_x                                 0x741550
#define CInvSlot__GetItemBase_x                                    0x740EC0
#define CInvSlot__UpdateItem_x                                     0x741030

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x747EB0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x747040
#define CInvSlotWnd__HandleLButtonUp_x                             0x747A30

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x802250
#define CItemDisplayWnd__UpdateStrings_x                           0x7566D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x750340
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x750870
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x756CE0
#define CItemDisplayWnd__AboutToShow_x                             0x756320
#define CItemDisplayWnd__WndNotification_x                         0x757F60
#define CItemDisplayWnd__RequestConvertItem_x                      0x757890
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x755380
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x756140

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x832D60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75C4A0

// CLabel 
#define CLabel__Draw_x                                             0x761EC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x912970
#define CListWnd__dCListWnd_x                                      0x912C90
#define CListWnd__AddColumn_x                                      0x917100
#define CListWnd__AddColumn1_x                                     0x917150
#define CListWnd__AddLine_x                                        0x9174E0
#define CListWnd__AddString_x                                      0x9172E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x916EC0
#define CListWnd__CalculateVSBRange_x                              0x916CB0
#define CListWnd__ClearSel_x                                       0x917CC0
#define CListWnd__ClearAllSel_x                                    0x917D20
#define CListWnd__CloseAndUpdateEditWindow_x                       0x918740
#define CListWnd__Compare_x                                        0x9165E0
#define CListWnd__Draw_x                                           0x912DC0
#define CListWnd__DrawColumnSeparators_x                           0x9155B0
#define CListWnd__DrawHeader_x                                     0x915A20
#define CListWnd__DrawItem_x                                       0x915F20
#define CListWnd__DrawLine_x                                       0x915720
#define CListWnd__DrawSeparator_x                                  0x915650
#define CListWnd__EnableLine_x                                     0x914E90
#define CListWnd__EnsureVisible_x                                  0x918660
#define CListWnd__ExtendSel_x                                      0x917BF0
#define CListWnd__GetColumnTooltip_x                               0x9149D0
#define CListWnd__GetColumnMinWidth_x                              0x914A40
#define CListWnd__GetColumnWidth_x                                 0x914940
#define CListWnd__GetCurSel_x                                      0x9142D0
#define CListWnd__GetItemAtPoint_x                                 0x915110
#define CListWnd__GetItemAtPoint1_x                                0x915180
#define CListWnd__GetItemData_x                                    0x914350
#define CListWnd__GetItemHeight_x                                  0x914710
#define CListWnd__GetItemIcon_x                                    0x9144E0
#define CListWnd__GetItemRect_x                                    0x914F80
#define CListWnd__GetItemText_x                                    0x914390
#define CListWnd__GetSelList_x                                     0x917D70
#define CListWnd__GetSeparatorRect_x                               0x9153C0
#define CListWnd__InsertLine_x                                     0x9178D0
#define CListWnd__RemoveLine_x                                     0x917A20
#define CListWnd__SetColors_x                                      0x916C80
#define CListWnd__SetColumnJustification_x                         0x9169B0
#define CListWnd__SetColumnLabel_x                                 0x917280
#define CListWnd__SetColumnWidth_x                                 0x9168D0
#define CListWnd__SetCurSel_x                                      0x917B30
#define CListWnd__SetItemColor_x                                   0x918310
#define CListWnd__SetItemData_x                                    0x9182D0
#define CListWnd__SetItemText_x                                    0x917EE0
#define CListWnd__ShiftColumnSeparator_x                           0x916A70
#define CListWnd__Sort_x                                           0x916760
#define CListWnd__ToggleSel_x                                      0x917B60
#define CListWnd__SetColumnsSizable_x                              0x916B20
#define CListWnd__SetItemWnd_x                                     0x918190
#define CListWnd__GetItemWnd_x                                     0x914530
#define CListWnd__SetItemIcon_x                                    0x917F60
#define CListWnd__CalculateCustomWindowPositions_x                 0x916FC0
#define CListWnd__SetVScrollPos_x                                  0x9168B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7774E0
#define CMapViewWnd__GetWorldCoordinates_x                         0x775BF0
#define CMapViewWnd__HandleLButtonDown_x                           0x772C30

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x797930
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x798210
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x798740
#define CMerchantWnd__SelectRecoverySlot_x                         0x79B6F0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7964A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A12C0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x797540

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89BFC0
#define CPacketScrambler__hton_x                                   0x89BFB0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9319E0
#define CSidlManager__FindScreenPieceTemplate_x                    0x931DF0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x931BE0
#define CSidlManager__CreateLabel_x                                0x7F94E0
#define CSidlManager__CreateXWndFromTemplate_x                     0x934D50
#define CSidlManager__CreateXWndFromTemplate1_x                    0x934F20
#define CSidlManager__CreateXWnd_x                                 0x7F9410
#define CSidlManager__CreateHotButtonWnd_x                         0x7F99D0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92E4C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92E3C0
#define CSidlScreenWnd__ConvertToRes_x                             0x9579F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92DEB0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92DBA0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92DC70
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92DD40
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92E960
#define CSidlScreenWnd__EnableIniStorage_x                         0x92EE30
#define CSidlScreenWnd__GetSidlPiece_x                             0x92EB50
#define CSidlScreenWnd__Init1_x                                    0x92D7A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x92EE80
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92F9C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92CBC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x92F540
#define CSidlScreenWnd__StoreIniVis_x                              0x92F8A0
#define CSidlScreenWnd__WndNotification_x                          0x92E870
#define CSidlScreenWnd__GetChildItem_x                             0x92EDB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91E5A0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D6AE8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x695D30
#define CSkillMgr__GetSkillCap_x                                   0x695F10
#define CSkillMgr__GetNameToken_x                                  0x6954B0
#define CSkillMgr__IsActivatedSkill_x                              0x6955F0
#define CSkillMgr__IsCombatSkill_x                                 0x695530

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93E820
#define CSliderWnd__SetValue_x                                     0x93E690
#define CSliderWnd__SetNumTicks_x                                  0x93E6F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FF620

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x947170
#define CStmlWnd__ParseSTML_x                                      0x9484C0
#define CStmlWnd__CalculateHSBRange_x                              0x9482A0
#define CStmlWnd__CalculateVSBRange_x                              0x948210
#define CStmlWnd__CanBreakAtCharacter_x                            0x94C5D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94D260
#define CStmlWnd__ForceParseNow_x                                  0x947760
#define CStmlWnd__GetNextTagPiece_x                                0x94C530
#define CStmlWnd__GetSTMLText_x                                    0x50A7A0
#define CStmlWnd__GetVisibleText_x                                 0x947780
#define CStmlWnd__InitializeWindowVariables_x                      0x94D0B0
#define CStmlWnd__MakeStmlColorTag_x                               0x9467E0
#define CStmlWnd__MakeWndNotificationTag_x                         0x946850
#define CStmlWnd__SetSTMLText_x                                    0x945890
#define CStmlWnd__StripFirstSTMLLines_x                            0x94E360
#define CStmlWnd__UpdateHistoryString_x                            0x94D470

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9449E0
#define CTabWnd__DrawCurrentPage_x                                 0x945110
#define CTabWnd__DrawTab_x                                         0x944E30
#define CTabWnd__GetCurrentPage_x                                  0x9441E0
#define CTabWnd__GetPageInnerRect_x                                0x944420
#define CTabWnd__GetTabInnerRect_x                                 0x944360
#define CTabWnd__GetTabRect_x                                      0x944210
#define CTabWnd__InsertPage_x                                      0x944630
#define CTabWnd__RemovePage_x                                      0x9447A0
#define CTabWnd__SetPage_x                                         0x9444A0
#define CTabWnd__SetPageRect_x                                     0x944920
#define CTabWnd__UpdatePage_x                                      0x944CF0
#define CTabWnd__GetPageFromTabIndex_x                             0x944D70
#define CTabWnd__GetCurrentTabIndex_x                              0x9441D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75C8B0
#define CPageWnd__SetTabText_x                                     0x943D20
#define CPageWnd__FlashTab_x                                       0x943D80

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8F10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91B460
#define CTextureFont__GetTextExtent_x                              0x91B620

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A9F00
#define CHtmlComponentWnd__ValidateUri_x                           0x73AC40
#define CHtmlWnd__SetClientCallbacks_x                             0x635B30
#define CHtmlWnd__AddObserver_x                                    0x635B50
#define CHtmlWnd__RemoveObserver_x                                 0x635BB0
#define Window__getProgress_x                                      0x851530
#define Window__getStatus_x                                        0x851550
#define Window__getURI_x                                           0x851560

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x954800

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x908380

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9550
#define CXStr__CXStr1_x                                            0x910DA0
#define CXStr__CXStr3_x                                            0x8EF320
#define CXStr__dCXStr_x                                            0x477FF0
#define CXStr__operator_equal_x                                    0x8EF550
#define CXStr__operator_equal1_x                                   0x8EF590
#define CXStr__operator_plus_equal1_x                              0x8F0020
#define CXStr__SetString_x                                         0x8F1F10
#define CXStr__operator_char_p_x                                   0x8EFA90
#define CXStr__GetChar_x                                           0x8F1860
#define CXStr__Delete_x                                            0x8F1110
#define CXStr__GetUnicode_x                                        0x8F18D0
#define CXStr__GetLength_x                                         0x4A8CC0
#define CXStr__Mid_x                                               0x47D1F0
#define CXStr__Insert_x                                            0x8F1930
#define CXStr__FindNext_x                                          0x8F1580

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93CAB0
#define CXWnd__BringToTop_x                                        0x921D80
#define CXWnd__Center_x                                            0x921900
#define CXWnd__ClrFocus_x                                          0x921720
#define CXWnd__Destroy_x                                           0x9217C0
#define CXWnd__DoAllDrawing_x                                      0x91DD30
#define CXWnd__DrawChildren_x                                      0x91DD00
#define CXWnd__DrawColoredRect_x                                   0x91E190
#define CXWnd__DrawTooltip_x                                       0x91C840
#define CXWnd__DrawTooltipAtPoint_x                                0x91C900
#define CXWnd__GetBorderFrame_x                                    0x91DFF0
#define CXWnd__GetChildWndAt_x                                     0x921E20
#define CXWnd__GetClientClipRect_x                                 0x91FFA0
#define CXWnd__GetScreenClipRect_x                                 0x920070
#define CXWnd__GetScreenRect_x                                     0x920240
#define CXWnd__GetRelativeRect_x                                   0x920310
#define CXWnd__GetTooltipRect_x                                    0x91E1E0
#define CXWnd__GetWindowTextA_x                                    0x49CB40
#define CXWnd__IsActive_x                                          0x91E920
#define CXWnd__IsDescendantOf_x                                    0x920C70
#define CXWnd__IsReallyVisible_x                                   0x920CA0
#define CXWnd__IsType_x                                            0x922490
#define CXWnd__Move_x                                              0x920D00
#define CXWnd__Move1_x                                             0x920DB0
#define CXWnd__ProcessTransition_x                                 0x9218B0
#define CXWnd__Refade_x                                            0x921090
#define CXWnd__Resize_x                                            0x921330
#define CXWnd__Right_x                                             0x921B40
#define CXWnd__SetFocus_x                                          0x9216E0
#define CXWnd__SetFont_x                                           0x921750
#define CXWnd__SetKeyTooltip_x                                     0x9222B0
#define CXWnd__SetMouseOver_x                                      0x91F160
#define CXWnd__StartFade_x                                         0x920B50
#define CXWnd__GetChildItem_x                                      0x921F90
#define CXWnd__SetParent_x                                         0x920A00
#define CXWnd__Minimize_x                                          0x9213A0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x958A70

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x924CD0
#define CXWndManager__DrawWindows_x                                0x924CF0
#define CXWndManager__GetKeyboardFlags_x                           0x927410
#define CXWndManager__HandleKeyboardMsg_x                          0x926FC0
#define CXWndManager__RemoveWnd_x                                  0x927640
#define CXWndManager__RemovePendingDeletionWnd_x                   0x927BC0

// CDBStr
#define CDBStr__GetString_x                                        0x544D70

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFC10
#define EQ_Character__Cur_HP_x                                     0x4D2C90
#define EQ_Character__Cur_Mana_x                                   0x4DA3E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2C80
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3460
#define EQ_Character__GetFocusRangeModifier_x                      0x4B35B0
#define EQ_Character__GetHPRegen_x                                 0x4E0220
#define EQ_Character__GetEnduranceRegen_x                          0x4E0820
#define EQ_Character__GetManaRegen_x                               0x4E0C60
#define EQ_Character__Max_Endurance_x                              0x65C2C0
#define EQ_Character__Max_HP_x                                     0x4D2AC0
#define EQ_Character__Max_Mana_x                                   0x65C0C0
#define EQ_Character__doCombatAbility_x                            0x65E6A0
#define EQ_Character__UseSkill_x                                   0x4E2A60
#define EQ_Character__GetConLevel_x                                0x654D70
#define EQ_Character__IsExpansionFlag_x                            0x5B8950
#define EQ_Character__TotalEffect_x                                0x4C6A20
#define EQ_Character__GetPCSpellAffect_x                           0x4C39D0
#define EQ_Character__SpellDuration_x                              0x4C3500
#define EQ_Character__MySpellDuration_x                            0x4B1D90
#define EQ_Character__GetAdjustedSkill_x                           0x4D5A10
#define EQ_Character__GetBaseSkill_x                               0x4D69B0
#define EQ_Character__CanUseItem_x                                 0x4DA6F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BB090

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x672650

//PcClient
#define PcClient__vftable_x                                        0xAEFF2C
#define PcClient__PcClient_x                                       0x6524D0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA680
#define CCharacterListWnd__EnterWorld_x                            0x4BA050
#define CCharacterListWnd__Quit_x                                  0x4B9DA0
#define CCharacterListWnd__UpdateList_x                            0x4BA240

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x636CF0
#define EQ_Item__CreateItemTagString_x                             0x8955A0
#define EQ_Item__IsStackable_x                                     0x89A250
#define EQ_Item__GetImageNum_x                                     0x897120
#define EQ_Item__CreateItemClient_x                                0x635F30
#define EQ_Item__GetItemValue_x                                    0x898420
#define EQ_Item__ValueSellMerchant_x                               0x89BBA0
#define EQ_Item__IsKeyRingItem_x                                   0x899B70
#define EQ_Item__CanGoInBag_x                                      0x636E10
#define EQ_Item__IsEmpty_x                                         0x8996B0
#define EQ_Item__GetMaxItemCount_x                                 0x898830
#define EQ_Item__GetHeldItem_x                                     0x896FF0
#define EQ_Item__GetAugmentFitBySlot_x                             0x894E00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5637C0
#define EQ_LoadingS__Array_x                                       0xC0FC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65CBC0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A4BE0
#define EQ_PC__GetCombatAbility_x                                  0x8A5250
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A52C0
#define EQ_PC__GetItemRecastTimer_x                                0x65EC20
#define EQ_PC__HasLoreItem_x                                       0x655580
#define EQ_PC__AlertInventoryChanged_x                             0x6546A0
#define EQ_PC__GetPcZoneClient_x                                   0x681630
#define EQ_PC__RemoveMyAffect_x                                    0x661E50
#define EQ_PC__GetKeyRingItems_x                                   0x8A5B50
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A58E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A5E50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BED60
#define EQItemList__add_object_x                                   0x5EC1F0
#define EQItemList__add_item_x                                     0x5BF2C0
#define EQItemList__delete_item_x                                  0x5BF310
#define EQItemList__FreeItemList_x                                 0x5BF210

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5418A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x673F50
#define EQPlayer__dEQPlayer_x                                      0x6672D0
#define EQPlayer__DoAttack_x                                       0x67BDD0
#define EQPlayer__EQPlayer_x                                       0x667990
#define EQPlayer__SetNameSpriteState_x                             0x66BC60
#define EQPlayer__SetNameSpriteTint_x                              0x66CB40
#define PlayerBase__HasProperty_j_x                                0x987610
#define EQPlayer__IsTargetable_x                                   0x987AB0
#define EQPlayer__CanSee_x                                         0x987910
#define EQPlayer__CanSee1_x                                        0x9879E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9876D0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67F0D0
#define PlayerZoneClient__GetLevel_x                               0x681670
#define PlayerZoneClient__IsValidTeleport_x                        0x5ED360
#define PlayerZoneClient__LegalPlayerRace_x                        0x55C5C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x676CF0
#define EQPlayerManager__GetSpawnByName_x                          0x676DA0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x676E30

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63A3F0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63A470
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63A4B0
#define KeypressHandler__ClearCommandStateArray_x                  0x63B8A0
#define KeypressHandler__HandleKeyDown_x                           0x63B8C0
#define KeypressHandler__HandleKeyUp_x                             0x63B960
#define KeypressHandler__SaveKeymapping_x                          0x63BDB0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x773350
#define MapViewMap__SaveEx_x                                       0x776710
#define MapViewMap__SetZoom_x                                      0x77ADD0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B9040

// StringTable 
#define StringTable__getString_x                                   0x8B3E60

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x661AC0
#define PcZoneClient__RemovePetEffect_x                            0x6620F0
#define PcZoneClient__HasAlternateAbility_x                        0x65BEF0
#define PcZoneClient__GetCurrentMod_x                              0x4E5B80
#define PcZoneClient__GetModCap_x                                  0x4E5A80
#define PcZoneClient__CanEquipItem_x                               0x65C5A0
#define PcZoneClient__GetItemByID_x                                0x65F090
#define PcZoneClient__GetItemByItemClass_x                         0x65F1E0
#define PcZoneClient__RemoveBuffEffect_x                           0x662110
#define PcZoneClient__BandolierSwap_x                              0x65D170
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65EBC0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F1ED0

//IconCache
#define IconCache__GetIcon_x                                       0x714EB0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70C980
#define CContainerMgr__CloseContainer_x                            0x70CC50
#define CContainerMgr__OpenExperimentContainer_x                   0x70D6D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CBAF0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62EE90

//CLootWnd
#define CLootWnd__LootAll_x                                        0x769970
#define CLootWnd__RequestLootSlot_x                                0x768C50

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58B430
#define EQ_Spell__SpellAffects_x                                   0x58B8A0
#define EQ_Spell__SpellAffectBase_x                                0x58B660
#define EQ_Spell__IsStackable_x                                    0x4CA6C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA4E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7930
#define EQ_Spell__IsSPAStacking_x                                  0x58C6F0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58BC00
#define EQ_Spell__IsNoRemove_x                                     0x4CA6A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58C700
#define __IsResEffectSpell_x                                       0x4C9960

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD0E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C3670

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x812910
#define CTargetWnd__WndNotification_x                              0x812150
#define CTargetWnd__RefreshTargetBuffs_x                           0x812420
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8112B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x816F50
#define CTaskWnd__ConfirmAbandonTask_x                             0x819B90

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F2F0
#define CTaskManager__HandleMessage_x                              0x53D770
#define CTaskManager__GetTaskStatus_x                              0x53F3A0
#define CTaskManager__GetElementDescription_x                      0x53F420

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5864A0
#define EqSoundManager__PlayScriptMp3_x                            0x586760
#define EqSoundManager__SoundAssistPlay_x                          0x699C90
#define EqSoundManager__WaveInstancePlay_x                         0x699200

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530890

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x943230
#define CTextureAnimation__Draw_x                                  0x943430

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93F180

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B380
#define CAltAbilityData__GetMercMaxRank_x                          0x56B310
#define CAltAbilityData__GetMaxRank_x                              0x5606E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62CFB0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA4C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x517570
#define CharacterBase__CreateItemIndex_x                           0x6350E0
#define CharacterBase__GetItemPossession_x                         0x503380
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CBCC0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CBD20
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F3880
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F40B0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F4160

//messages
#define msg_spell_worn_off_x                                       0x5B09C0
#define msg_new_text_x                                             0x5A5350
#define __msgTokenTextParam_x                                      0x5B2C60
#define msgTokenText_x                                             0x5B2EB0

//SpellManager
#define SpellManager__vftable_x                                    0xAD82CC
#define SpellManager__SpellManager_x                               0x69CFB0
#define Spellmanager__LoadTextSpells_x                             0x69D8A0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69D180

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98B540

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517BF0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B6E20
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64DC20
#define ItemGlobalIndex__IsValidIndex_x                            0x517C80

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C4010
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C4290

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x762200

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x711080
#define CCursorAttachment__AttachToCursor1_x                       0x7110C0
#define CCursorAttachment__Deactivate_x                            0x7120B0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x935D70
#define CSidlManagerBase__CreatePageWnd_x                          0x935570
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x931800
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x931790

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x953230
#define CEQSuiteTextureLoader__GetTexture_x                        0x952EF0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514AC0
#define CFindItemWnd__WndNotification_x                            0x5155A0
#define CFindItemWnd__Update_x                                     0x516110
#define CFindItemWnd__PickupSelectedItem_x                         0x5142E0

//IString
#define IString__Append_x                                          0x504BB0

//Camera
#define CDisplay__cameraType_x                                     0xDE7880
#define EverQuest__Cameras_x                                       0xEA2AFC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D530
#define LootFiltersManager__GetItemFilterData_x                    0x51CE30
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51CE60
#define LootFiltersManager__SetItemLootFilter_x                    0x51D080

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B9930

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9911C0
#define CResolutionHandler__GetWindowedStyle_x                     0x6948D0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x709620

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9590
#define CDistillerInfo__Instance_x                                 0x8D9530

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x728550
#define CGroupWnd__UpdateDisplay_x                                 0x7278A0

//ItemBase
#define ItemBase__IsLore_x                                         0x899C20
#define ItemBase__IsLoreEquipped_x                                 0x899C90

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EC150
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EC290
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EC2F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x689D50
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68D6B0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50ADE0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F73A0
#define FactionManagerClient__HandleFactionMessage_x               0x4F7A10
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F8010
#define FactionManagerClient__GetMaxFaction_x                      0x4F802F
#define FactionManagerClient__GetMinFaction_x                      0x4F7FE0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x503350

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91A3E0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE50

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5035B0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56A800

//CTargetManager
#define CTargetManager__Get_x                                      0x6A07E0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x689D50

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8CD0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BF1B0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF40190

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BD1F0
#define CAAWnd__UpdateSelected_x                                   0x6B9A60
#define CAAWnd__Update_x                                           0x6BC510

//CXRect
#define CXRect__operator_and_x                                     0x71F620

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
