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
#define __ExpectedVersionDate                                     "Oct 29 2020"
#define __ExpectedVersionTime                                     "04:16:25"
#define __ActualVersionDate_x                                      0xAF455C
#define __ActualVersionTime_x                                      0xAF4550
#define __ActualVersionBuild_x                                     0xAE255C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642A30
#define __MemChecker1_x                                            0x8F56E0
#define __MemChecker2_x                                            0x6B3040
#define __MemChecker3_x                                            0x6B2F90
#define __MemChecker4_x                                            0x84BD40
#define __EncryptPad0_x                                            0xC299D0
#define __EncryptPad1_x                                            0xC87218
#define __EncryptPad2_x                                            0xC39D98
#define __EncryptPad3_x                                            0xC39998
#define __EncryptPad4_x                                            0xC777A8
#define __EncryptPad5_x                                            0xF49650
#define __AC1_x                                                    0x80A906
#define __AC2_x                                                    0x5FC1DF
#define __AC3_x                                                    0x603830
#define __AC4_x                                                    0x6077E0
#define __AC5_x                                                    0x60DADF
#define __AC6_x                                                    0x611F96
#define __AC7_x                                                    0x5FBC50
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x190458

// Direct Input
#define DI8__Main_x                                                0xF49670
#define DI8__Keyboard_x                                            0xF49674
#define DI8__Mouse_x                                               0xF49688
#define DI8__Mouse_Copy_x                                          0xEA29E4
#define DI8__Mouse_Check_x                                         0xF471A4
#define __AutoSkillArray_x                                         0xEA3900
#define __Attack_x                                                 0xF41727
#define __Autofire_x                                               0xF41728
#define __BindList_x                                               0xC18400
#define g_eqCommandStates_x                                        0xC19180
#define __Clicks_x                                                 0xEA2A9C
#define __CommandList_x                                            0xC19D40
#define __CurrentMapLabel_x                                        0xF5A14C
#define __CurrentSocial_x                                          0xC017C8
#define __DoAbilityList_x                                          0xED9248
#define __do_loot_x                                                0x5C7CC0
#define __DrawHandler_x                                            0x15D9140
#define __GroupCount_x                                             0xE9DA72
#define __Guilds_x                                                 0xEA1920
#define __gWorld_x                                                 0xE9D920
#define __HWnd_x                                                   0xF4968C
#define __heqmain_x                                                0xF49638
#define __InChatMode_x                                             0xEA29CC
#define __LastTell_x                                               0xEA4944
#define __LMouseHeldTime_x                                         0xEA2B08
#define __Mouse_x                                                  0xF4965C
#define __MouseLook_x                                              0xEA2A62
#define __MouseEventTime_x                                         0xF4220C
#define __gpbCommandEvent_x                                        0xE9B3C4
#define __NetStatusToggle_x                                        0xEA2A65
#define __PCNames_x                                                0xEA3EF0
#define __RangeAttackReady_x                                       0xEA3BE4
#define __RMouseHeldTime_x                                         0xEA2B04
#define __RunWalkState_x                                           0xEA29D0
#define __ScreenMode_x                                             0xDE8D70
#define __ScreenX_x                                                0xEA2984
#define __ScreenY_x                                                0xEA2980
#define __ScreenXMax_x                                             0xEA2988
#define __ScreenYMax_x                                             0xEA298C
#define __ServerHost_x                                             0xE9B593
#define __ServerName_x                                             0xED9208
#define __ShiftKeyDown_x                                           0xEA3060
#define __ShowNames_x                                              0xEA3DA0
#define EverQuestInfo__bSocialChanged_x                            0xED9290
#define __Socials_x                                                0xED9308
#define __SubscriptionType_x                                       0xF9E410
#define __TargetAggroHolder_x                                      0xF5CB00
#define __ZoneType_x                                               0xEA2E60
#define __GroupAggro_x                                             0xF5CB40
#define __LoginName_x                                              0xF49DCC
#define __Inviter_x                                                0xF416A4
#define __AttackOnAssist_x                                         0xEA3D5C
#define __UseTellWindows_x                                         0xEA4088
#define __gfMaxZoomCameraDistance_x                                0xAEC178
#define __gfMaxCameraDistance_x                                    0xB14DF8
#define __pulAutoRun_x                                             0xEA2A80
#define __pulForward_x                                             0xEA40C0
#define __pulBackward_x                                            0xEA40C4
#define __pulTurnRight_x                                           0xEA40C8
#define __pulTurnLeft_x                                            0xEA40CC
#define __pulStrafeLeft_x                                          0xEA40D0
#define __pulStrafeRight_x                                         0xEA40D4

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9DCC0
#define instEQZoneInfo_x                                           0xEA2C58
#define pinstActiveBanker_x                                        0xE9B8B0
#define pinstActiveCorpse_x                                        0xE9B8A8
#define pinstActiveGMaster_x                                       0xE9B8AC
#define pinstActiveMerchant_x                                      0xE9B8A4
#define pinstAltAdvManager_x                                       0xDE9EF0
#define pinstBandageTarget_x                                       0xE9B8C0
#define pinstCamActor_x                                            0xDE8D60
#define pinstCDBStr_x                                              0xDE8C0C
#define pinstCDisplay_x                                            0xE9D918
#define pinstCEverQuest_x                                          0xF49690
#define pinstEverQuestInfo_x                                       0xEA2978
#define pinstCharData_x                                            0xE9DCB4
#define pinstCharSpawn_x                                           0xE9B8F8
#define pinstControlledMissile_x                                   0xE9B908
#define pinstControlledPlayer_x                                    0xE9B8F8
#define pinstCResolutionHandler_x                                  0x15D9370
#define pinstCSidlManager_x                                        0x15D8308
#define pinstCXWndManager_x                                        0x15D8304
#define instDynamicZone_x                                          0xEA17F8
#define pinstDZMember_x                                            0xEA1908
#define pinstDZTimerInfo_x                                         0xEA190C
#define pinstEqLogin_x                                             0xF49718
#define instEQMisc_x                                               0xDE8B50
#define pinstEQSoundManager_x                                      0xDEAEC0
#define pinstEQSpellStrings_x                                      0xCAB458
#define instExpeditionLeader_x                                     0xEA1842
#define instExpeditionName_x                                       0xEA1882
#define pinstGroup_x                                               0xE9DA6E
#define pinstImeManager_x                                          0x15D8300
#define pinstLocalPlayer_x                                         0xE9B69C
#define pinstMercenaryData_x                                       0xF43D00
#define pinstMercenaryStats_x                                      0xF5CBCC
#define pinstModelPlayer_x                                         0xE9B8B8
#define pinstPCData_x                                              0xE9DCB4
#define pinstSkillMgr_x                                            0xF45E68
#define pinstSpawnManager_x                                        0xF44910
#define pinstSpellManager_x                                        0xF460A8
#define pinstSpellSets_x                                           0xF3A350
#define pinstStringTable_x                                         0xE9B3B0
#define pinstSwitchManager_x                                       0xE9B260
#define pinstTarget_x                                              0xE9B8F4
#define pinstTargetObject_x                                        0xE9B900
#define pinstTargetSwitch_x                                        0xE9D910
#define pinstTaskMember_x                                          0xDE89E0
#define pinstTrackTarget_x                                         0xE9B8FC
#define pinstTradeTarget_x                                         0xE9B8B4
#define instTributeActive_x                                        0xDE8B71
#define pinstViewActor_x                                           0xDE8D58
#define pinstWorldData_x                                           0xE9B3B4
#define pinstZoneAddr_x                                            0xEA2EF8
#define pinstPlayerPath_x                                          0xF449A8
#define pinstTargetIndicator_x                                     0xF46310
#define EQObject_Top_x                                             0xE9B48C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE9084
#define pinstCAchievementsWnd_x                                    0xDE8CF8
#define pinstCActionsWnd_x                                         0xDE90C0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE8DB8
#define pinstCAdvancedLootWnd_x                                    0xDE8D50
#define pinstCAdventureLeaderboardWnd_x                            0xF53920
#define pinstCAdventureRequestWnd_x                                0xF539D0
#define pinstCAdventureStatsWnd_x                                  0xF53A80
#define pinstCAggroMeterWnd_x                                      0xDE8DA0
#define pinstCAlarmWnd_x                                           0xDE8D20
#define pinstCAlertHistoryWnd_x                                    0xDE8E34
#define pinstCAlertStackWnd_x                                      0xDE8D88
#define pinstCAlertWnd_x                                           0xDE8D9C
#define pinstCAltStorageWnd_x                                      0xF53DE0
#define pinstCAudioTriggersWindow_x                                0xC9D788
#define pinstCAuraWnd_x                                            0xDE8D54
#define pinstCAvaZoneWnd_x                                         0xDE8E30
#define pinstCBandolierWnd_x                                       0xDE8DB4
#define pinstCBankWnd_x                                            0xDE8DE8
#define pinstCBarterMerchantWnd_x                                  0xF55020
#define pinstCBarterSearchWnd_x                                    0xF550D0
#define pinstCBarterWnd_x                                          0xF55180
#define pinstCBazaarConfirmationWnd_x                              0xDE8D34
#define pinstCBazaarSearchWnd_x                                    0xDE9088
#define pinstCBazaarWnd_x                                          0xDE8D04
#define pinstCBlockedBuffWnd_x                                     0xDE8D7C
#define pinstCBlockedPetBuffWnd_x                                  0xDE8DA4
#define pinstCBodyTintWnd_x                                        0xDE8CAC
#define pinstCBookWnd_x                                            0xDE8DE0
#define pinstCBreathWnd_x                                          0xDE9098
#define pinstCBuffWindowNORMAL_x                                   0xDE8D48
#define pinstCBuffWindowSHORT_x                                    0xDE8D4C
#define pinstCBugReportWnd_x                                       0xDE8DE4
#define pinstCButtonWnd_x                                          0x15D8570
#define pinstCCastingWnd_x                                         0xDE8DD4
#define pinstCCastSpellWnd_x                                       0xDE9094
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE8CB8
#define pinstCChatWindowManager_x                                  0xF55C40
#define pinstCClaimWnd_x                                           0xF55D98
#define pinstCColorPickerWnd_x                                     0xDE904C
#define pinstCCombatAbilityWnd_x                                   0xDE8D14
#define pinstCCombatSkillsSelectWnd_x                              0xDE8CCC
#define pinstCCompassWnd_x                                         0xDE90D4
#define pinstCConfirmationDialog_x                                 0xF5AC98
#define pinstCContainerMgr_x                                       0xDE8CA8
#define pinstCContextMenuManager_x                                 0x15D82C0
#define pinstCCursorAttachment_x                                   0xDE8DC8
#define pinstCDynamicZoneWnd_x                                     0xF56360
#define pinstCEditLabelWnd_x                                       0xDE8D44
#define pinstCEQMainWnd_x                                          0xF565A8
#define pinstCEventCalendarWnd_x                                   0xDE908C
#define pinstCExtendedTargetWnd_x                                  0xDE8D84
#define pinstCFacePick_x                                           0xDE8CD0
#define pinstCFactionWnd_x                                         0xDE8CF0
#define pinstCFellowshipWnd_x                                      0xF567A8
#define pinstCFileSelectionWnd_x                                   0xDE9048
#define pinstCFindItemWnd_x                                        0xDE8CE0
#define pinstCFindLocationWnd_x                                    0xF56900
#define pinstCFriendsWnd_x                                         0xDE8CE4
#define pinstCGemsGameWnd_x                                        0xDE8CEC
#define pinstCGiveWnd_x                                            0xDE8D24
#define pinstCGroupSearchFiltersWnd_x                              0xDE8DBC
#define pinstCGroupSearchWnd_x                                     0xF56CF8
#define pinstCGroupWnd_x                                           0xF56DA8
#define pinstCGuildBankWnd_x                                       0xEA3D40
#define pinstCGuildCreationWnd_x                                   0xF56F08
#define pinstCGuildMgmtWnd_x                                       0xF56FB8
#define pinstCharacterCreation_x                                   0xDE8CD8
#define pinstCHelpWnd_x                                            0xDE8D28
#define pinstCHeritageSelectionWnd_x                               0xDE8CDC
#define pinstCHotButtonWnd_x                                       0xF59110
#define pinstCHotButtonWnd1_x                                      0xF59110
#define pinstCHotButtonWnd2_x                                      0xF59114
#define pinstCHotButtonWnd3_x                                      0xF59118
#define pinstCHotButtonWnd4_x                                      0xF5911C
#define pinstCIconSelectionWnd_x                                   0xDE8DC4
#define pinstCInspectWnd_x                                         0xDE8DA8
#define pinstCInventoryWnd_x                                       0xDE8D5C
#define pinstCInvSlotMgr_x                                         0xDE9078
#define pinstCItemDisplayManager_x                                 0xF596A0
#define pinstCItemExpTransferWnd_x                                 0xF597D4
#define pinstCItemOverflowWnd_x                                    0xDE9090
#define pinstCJournalCatWnd_x                                      0xDE9064
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE8E1C
#define pinstCKeyRingWnd_x                                         0xDE8DD0
#define pinstCLargeDialogWnd_x                                     0xF5B918
#define pinstCLayoutCopyWnd_x                                      0xF59B20
#define pinstCLFGuildWnd_x                                         0xF59BD0
#define pinstCLoadskinWnd_x                                        0xDE8D08
#define pinstCLootFiltersCopyWnd_x                                 0xCB9EE8
#define pinstCLootFiltersWnd_x                                     0xDE8D8C
#define pinstCLootSettingsWnd_x                                    0xDE8DB0
#define pinstCLootWnd_x                                            0xDE9068
#define pinstCMailAddressBookWnd_x                                 0xDE907C
#define pinstCMailCompositionWnd_x                                 0xDE9054
#define pinstCMailIgnoreListWnd_x                                  0xDE9080
#define pinstCMailWnd_x                                            0xDE9058
#define pinstCManageLootWnd_x                                      0xDEA3A0
#define pinstCMapToolbarWnd_x                                      0xDE8D30
#define pinstCMapViewWnd_x                                         0xDE8CFC
#define pinstCMarketplaceWnd_x                                     0xDE8D90
#define pinstCMerchantWnd_x                                        0xDE9074
#define pinstCMIZoneSelectWnd_x                                    0xF5A408
#define pinstCMusicPlayerWnd_x                                     0xDE9040
#define pinstCNameChangeMercWnd_x                                  0xDE8D2C
#define pinstCNameChangePetWnd_x                                   0xDE8D00
#define pinstCNameChangeWnd_x                                      0xDE8D40
#define pinstCNoteWnd_x                                            0xDE8D0C
#define pinstCObjectPreviewWnd_x                                   0xDE8DAC
#define pinstCOptionsWnd_x                                         0xDE8D18
#define pinstCPetInfoWnd_x                                         0xDE8E3C
#define pinstCPetitionQWnd_x                                       0xDE8CC8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE8CB0
#define pinstCPlayerWnd_x                                          0xDE8E28
#define pinstCPopupWndManager_x                                    0xF5AC98
#define pinstCProgressionSelectionWnd_x                            0xF5AD48
#define pinstCPurchaseGroupWnd_x                                   0xDE8E00
#define pinstCPurchaseWnd_x                                        0xDE8DD8
#define pinstCPvPLeaderboardWnd_x                                  0xF5ADF8
#define pinstCPvPStatsWnd_x                                        0xF5AEA8
#define pinstCQuantityWnd_x                                        0xDE8E18
#define pinstCRaceChangeWnd_x                                      0xDE8D6C
#define pinstCRaidOptionsWnd_x                                     0xDE8DC0
#define pinstCRaidWnd_x                                            0xDE9070
#define pinstCRealEstateItemsWnd_x                                 0xDE8CF4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE913C
#define pinstCRealEstateManageWnd_x                                0xDE8E04
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE8E24
#define pinstCRealEstatePlotSearchWnd_x                            0xDE9044
#define pinstCRealEstatePurchaseWnd_x                              0xDE9060
#define pinstCRespawnWnd_x                                         0xDE8D98
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE8CC4
#define pinstCSendMoneyWnd_x                                       0xDE8D38
#define pinstCServerListWnd_x                                      0xDE906C
#define pinstCSkillsSelectWnd_x                                    0xDE8CC0
#define pinstCSkillsWnd_x                                          0xDE9140
#define pinstCSocialEditWnd_x                                      0xDE8DCC
#define pinstCSocialWnd_x                                          0xDE8D1C
#define pinstCSpellBookWnd_x                                       0xDE8D10
#define pinstCStoryWnd_x                                           0xDE90BC
#define pinstCTargetOfTargetWnd_x                                  0xF5CC50
#define pinstCTargetWnd_x                                          0xDE8D94
#define pinstCTaskOverlayWnd_x                                     0xDE8DF8
#define pinstCTaskSelectWnd_x                                      0xF5CDA8
#define pinstCTaskManager_x                                        0xCBA828
#define pinstCTaskTemplateSelectWnd_x                              0xF5CE58
#define pinstCTaskWnd_x                                            0xF5CF08
#define pinstCTextEntryWnd_x                                       0xDE8DDC
#define pinstCTimeLeftWnd_x                                        0xDE8CBC
#define pinstCTipWndCONTEXT_x                                      0xF5D10C
#define pinstCTipWndOFDAY_x                                        0xF5D108
#define pinstCTitleWnd_x                                           0xF5D1B8
#define pinstCTrackingWnd_x                                        0xDE8D80
#define pinstCTradeskillWnd_x                                      0xF5D320
#define pinstCTradeWnd_x                                           0xDE8CB4
#define pinstCTrainWnd_x                                           0xDE905C
#define pinstCTributeBenefitWnd_x                                  0xF5D520
#define pinstCTributeMasterWnd_x                                   0xF5D5D0
#define pinstCTributeTrophyWnd_x                                   0xF5D680
#define pinstCVideoModesWnd_x                                      0xDE8E2C
#define pinstCVoiceMacroWnd_x                                      0xF468C8
#define pinstCVoteResultsWnd_x                                     0xDE8CE8
#define pinstCVoteWnd_x                                            0xDE8CD4
#define pinstCWebManager_x                                         0xF46F44
#define pinstCZoneGuideWnd_x                                       0xDE8DFC
#define pinstCZonePathWnd_x                                        0xDE8E14

#define pinstEQSuiteTextureLoader_x                                0xC87B38
#define pinstItemIconCache_x                                       0xF56560
#define pinstLootFiltersManager_x                                  0xCB9F98
#define pinstRewardSelectionWnd_x                                  0xF5B5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C33B0
#define __CastRay2_x                                               0x5C3400
#define __ConvertItemTags_x                                        0x5DF0B0
#define __CleanItemTags_x                                          0x47D380
#define __DoesFileExist_x                                          0x8F8710
#define __EQGetTime_x                                              0x8F5310
#define __ExecuteCmd_x                                             0x5BBCD0
#define __FixHeading_x                                             0x98A100
#define __FlushDxKeyboard_x                                        0x6AEEE0
#define __GameLoop_x                                               0x6B2210
#define __get_bearing_x                                            0x5C2F10
#define __get_melee_range_x                                        0x5C35F0
#define __GetAnimationCache_x                                      0x7173E0
#define __GetGaugeValueFromEQ_x                                    0x808DB0
#define __GetLabelFromEQ_x                                         0x80A890
#define __GetXTargetType_x                                         0x98BAE0
#define __HandleMouseWheel_x                                       0x6B30F0
#define __HeadingDiff_x                                            0x98A170
#define __HelpPath_x                                               0xF41DFC
#define __LoadFrontEnd_x                                           0x6AF520
#define __NewUIINI_x                                               0x808A80
#define __ProcessGameEvents_x                                      0x623E70
#define __ProcessMouseEvent_x                                      0x623600
#define __SaveColors_x                                             0x55CBD0
#define __STMLToText_x                                             0x92D690
#define __ToggleKeyRingItem_x                                      0x51B3A0
#define CMemoryMappedFile__SetFile_x                               0xA79430
#define CrashDetected_x                                            0x6B0FD0
#define DrawNetStatus_x                                            0x64FFC0
#define Expansion_HoT_x                                            0xEA3D48
#define Teleport_Table_Size_x                                      0xE9B44C
#define Teleport_Table_x                                           0xE9B910
#define Util__FastTime_x                                           0x8F4EE0
#define __CopyLayout_x                                             0x63E180
#define __WndProc_x                                                0x6B14D0
#define __ProcessKeyboardEvent_x                                   0x6B0A70

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490630
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499620
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4993F0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493BD0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493020

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564D40
#define AltAdvManager__IsAbilityReady_x                            0x563AE0
#define AltAdvManager__GetAAById_x                                 0x563E70
#define AltAdvManager__CanTrainAbility_x                           0x563EE0
#define AltAdvManager__CanSeeAbility_x                             0x564240

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB2F0
#define CharacterZoneClient__HasSkill_x                            0x4D6170
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7890
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2990
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBE20
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA210
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA2F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA3D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4A80
#define CharacterZoneClient__BardCastBard_x                        0x4C74B0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF830
#define CharacterZoneClient__GetEffect_x                           0x4BBD60
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5AF0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5BC0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5C10
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5D60
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5F40
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3D00
#define CharacterZoneClient__FindItemByGuid_x                      0x4D87F0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8270

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8BB0
#define CBankWnd__WndNotification_x                                0x6D8990

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E64A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92AE70
#define CButtonWnd__CButtonWnd_x                                   0x929A70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706580
#define CChatManager__InitContextMenu_x                            0x6FF6C0
#define CChatManager__FreeChatWindow_x                             0x7050C0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9B80
#define CChatManager__SetLockedActiveChatWindow_x                  0x706200
#define CChatManager__CreateChatWindow_x                           0x705700

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9C90

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93DFE0
#define CContextMenu__dCContextMenu_x                              0x93E210
#define CContextMenu__AddMenuItem_x                                0x93E220
#define CContextMenu__RemoveMenuItem_x                             0x93E520
#define CContextMenu__RemoveAllMenuItems_x                         0x93E540
#define CContextMenu__CheckMenuItem_x                              0x93E5C0
#define CContextMenu__SetMenuItem_x                                0x93E450
#define CContextMenu__AddSeparator_x                               0x93E3B0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93EB60
#define CContextMenuManager__RemoveMenu_x                          0x93EBD0
#define CContextMenuManager__PopupMenu_x                           0x93EC90
#define CContextMenuManager__Flush_x                               0x93EB00
#define CContextMenuManager__GetMenu_x                             0x49B900
#define CContextMenuManager__CreateDefaultMenu_x                   0x711D30

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D0080
#define CChatService__GetFriendName_x                              0x8D0090

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x706DB0
#define CChatWindow__Clear_x                                       0x708070
#define CChatWindow__WndNotification_x                             0x708800
#define CChatWindow__AddHistory_x                                  0x707930

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93B460
#define CComboWnd__Draw_x                                          0x93A960
#define CComboWnd__GetCurChoice_x                                  0x93B2A0
#define CComboWnd__GetListRect_x                                   0x93AE10
#define CComboWnd__GetTextRect_x                                   0x93B4C0
#define CComboWnd__InsertChoice_x                                  0x93AFA0
#define CComboWnd__SetColors_x                                     0x93AF70
#define CComboWnd__SetChoice_x                                     0x93B270
#define CComboWnd__GetItemCount_x                                  0x93B2B0
#define CComboWnd__GetCurChoiceText_x                              0x93B2F0
#define CComboWnd__GetChoiceText_x                                 0x93B2C0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93B030

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70F760
#define CContainerWnd__vftable_x                                   0xAFD754
#define CContainerWnd__SetContainer_x                              0x710CB0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x557530
#define CDisplay__PreZoneMainUI_x                                  0x557540
#define CDisplay__CleanGameUI_x                                    0x55C990
#define CDisplay__GetClickedActor_x                                0x54F990
#define CDisplay__GetUserDefinedColor_x                            0x548000
#define CDisplay__GetWorldFilePath_x                               0x551400
#define CDisplay__is3dON_x                                         0x54C5F0
#define CDisplay__ReloadUI_x                                       0x556A40
#define CDisplay__WriteTextHD2_x                                   0x54C3E0
#define CDisplay__TrueDistance_x                                   0x5530C0
#define CDisplay__SetViewActor_x                                   0x54F2B0
#define CDisplay__GetFloorHeight_x                                 0x54C6B0
#define CDisplay__SetRenderWindow_x                                0x54B030
#define CDisplay__ToggleScreenshotMode_x                           0x54ED80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95DDC0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9414B0
#define CEditWnd__EnsureCaretVisible_x                             0x943620
#define CEditWnd__GetCaretPt_x                                     0x942600
#define CEditWnd__GetCharIndexPt_x                                 0x9423C0
#define CEditWnd__GetDisplayString_x                               0x942270
#define CEditWnd__GetHorzOffset_x                                  0x940B70
#define CEditWnd__GetLineForPrintableChar_x                        0x943520
#define CEditWnd__GetSelStartPt_x                                  0x942660
#define CEditWnd__GetSTMLSafeText_x                                0x942090
#define CEditWnd__PointFromPrintableChar_x                         0x943160
#define CEditWnd__SelectableCharFromPoint_x                        0x9432D0
#define CEditWnd__SetEditable_x                                    0x942720
#define CEditWnd__SetWindowTextA_x                                 0x941E10
#define CEditWnd__ReplaceSelection_x                               0x942DE0
#define CEditWnd__ReplaceSelection1_x                              0x942D60

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611470
#define CEverQuest__ClickedPlayer_x                                0x603610
#define CEverQuest__CreateTargetIndicator_x                        0x620FE0
#define CEverQuest__DeleteTargetIndicator_x                        0x621070
#define CEverQuest__DoTellWindow_x                                 0x4E9D70
#define CEverQuest__OutputTextToLog_x                              0x4EA040
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8770
#define CEverQuest__dsp_chat_x                                     0x4EA3D0
#define CEverQuest__trimName_x                                     0x61D190
#define CEverQuest__Emote_x                                        0x611CD0
#define CEverQuest__EnterZone_x                                    0x60BDD0
#define CEverQuest__GetBodyTypeDesc_x                              0x616720
#define CEverQuest__GetClassDesc_x                                 0x616D60
#define CEverQuest__GetClassThreeLetterCode_x                      0x617360
#define CEverQuest__GetDeityDesc_x                                 0x61F830
#define CEverQuest__GetLangDesc_x                                  0x617520
#define CEverQuest__GetRaceDesc_x                                  0x616D40
#define CEverQuest__InterpretCmd_x                                 0x61FE00
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FC900
#define CEverQuest__LMouseUp_x                                     0x5FAC90
#define CEverQuest__RightClickedOnPlayer_x                         0x5FD1E0
#define CEverQuest__RMouseUp_x                                     0x5FBC10
#define CEverQuest__SetGameState_x                                 0x5F8500
#define CEverQuest__UPCNotificationFlush_x                         0x61D090
#define CEverQuest__IssuePetCommand_x                              0x618930
#define CEverQuest__ReportSuccessfulHit_x                          0x613020

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x721540
#define CGaugeWnd__CalcLinesFillRect_x                             0x7215A0
#define CGaugeWnd__Draw_x                                          0x720BC0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B0090
#define CGuild__GetGuildName_x                                     0x4AEB40
#define CGuild__GetGuildIndex_x                                    0x4AF140

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B1B0

//CHotButton
#define CHotButton__SetCheck_x                                     0x6325A0
#define CHotButton__SetButtonSize_x                                0x632960

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7482B0
#define CInvSlotMgr__MoveItem_x                                    0x746F80
#define CInvSlotMgr__SelectSlot_x                                  0x748380

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x745770
#define CInvSlot__SliderComplete_x                                 0x7434C0
#define CInvSlot__GetItemBase_x                                    0x742E30
#define CInvSlot__UpdateItem_x                                     0x742FA0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x749E10
#define CInvSlotWnd__CInvSlotWnd_x                                 0x748FA0
#define CInvSlotWnd__HandleLButtonUp_x                             0x749990

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x804150
#define CItemDisplayWnd__UpdateStrings_x                           0x7585A0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752270
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752780
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x758BA0
#define CItemDisplayWnd__AboutToShow_x                             0x7581E0
#define CItemDisplayWnd__WndNotification_x                         0x759E20
#define CItemDisplayWnd__RequestConvertItem_x                      0x759750
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x757240
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x758000

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834C20

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E310

// CLabel 
#define CLabel__Draw_x                                             0x763D20

// CListWnd
#define CListWnd__CListWnd_x                                       0x913DC0
#define CListWnd__dCListWnd_x                                      0x9140E0
#define CListWnd__AddColumn_x                                      0x918510
#define CListWnd__AddColumn1_x                                     0x918560
#define CListWnd__AddLine_x                                        0x9188F0
#define CListWnd__AddString_x                                      0x9186F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9182D0
#define CListWnd__CalculateVSBRange_x                              0x9180C0
#define CListWnd__ClearSel_x                                       0x9190D0
#define CListWnd__ClearAllSel_x                                    0x919130
#define CListWnd__CloseAndUpdateEditWindow_x                       0x919B30
#define CListWnd__Compare_x                                        0x9179F0
#define CListWnd__Draw_x                                           0x914210
#define CListWnd__DrawColumnSeparators_x                           0x9169E0
#define CListWnd__DrawHeader_x                                     0x916E40
#define CListWnd__DrawItem_x                                       0x917330
#define CListWnd__DrawLine_x                                       0x916B40
#define CListWnd__DrawSeparator_x                                  0x916A80
#define CListWnd__EnableLine_x                                     0x9162C0
#define CListWnd__EnsureVisible_x                                  0x919A60
#define CListWnd__ExtendSel_x                                      0x919000
#define CListWnd__GetColumnTooltip_x                               0x915E00
#define CListWnd__GetColumnMinWidth_x                              0x915E70
#define CListWnd__GetColumnWidth_x                                 0x915D70
#define CListWnd__GetCurSel_x                                      0x915700
#define CListWnd__GetItemAtPoint_x                                 0x916530
#define CListWnd__GetItemAtPoint1_x                                0x9165A0
#define CListWnd__GetItemData_x                                    0x915780
#define CListWnd__GetItemHeight_x                                  0x915B40
#define CListWnd__GetItemIcon_x                                    0x915910
#define CListWnd__GetItemRect_x                                    0x9163B0
#define CListWnd__GetItemText_x                                    0x9157C0
#define CListWnd__GetSelList_x                                     0x919180
#define CListWnd__GetSeparatorRect_x                               0x9167E0
#define CListWnd__InsertLine_x                                     0x918CE0
#define CListWnd__RemoveLine_x                                     0x918E30
#define CListWnd__SetColors_x                                      0x918090
#define CListWnd__SetColumnJustification_x                         0x917DC0
#define CListWnd__SetColumnLabel_x                                 0x918690
#define CListWnd__SetColumnWidth_x                                 0x917CE0
#define CListWnd__SetCurSel_x                                      0x918F40
#define CListWnd__SetItemColor_x                                   0x919720
#define CListWnd__SetItemData_x                                    0x9196E0
#define CListWnd__SetItemText_x                                    0x9192F0
#define CListWnd__ShiftColumnSeparator_x                           0x917E80
#define CListWnd__Sort_x                                           0x917B70
#define CListWnd__ToggleSel_x                                      0x918F70
#define CListWnd__SetColumnsSizable_x                              0x917F30
#define CListWnd__SetItemWnd_x                                     0x9195A0
#define CListWnd__GetItemWnd_x                                     0x915960
#define CListWnd__SetItemIcon_x                                    0x919370
#define CListWnd__CalculateCustomWindowPositions_x                 0x9183D0
#define CListWnd__SetVScrollPos_x                                  0x917CC0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779470
#define CMapViewWnd__GetWorldCoordinates_x                         0x777B80
#define CMapViewWnd__HandleLButtonDown_x                           0x774BC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799860
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A140
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79A670
#define CMerchantWnd__SelectRecoverySlot_x                         0x79D610
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7983D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A31D0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799470

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E0C0
#define CPacketScrambler__hton_x                                   0x89E0B0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x932C90
#define CSidlManager__FindScreenPieceTemplate_x                    0x9330A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x932E90
#define CSidlManager__CreateLabel_x                                0x7FB2C0
#define CSidlManager__CreateXWndFromTemplate_x                     0x936000
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9361E0
#define CSidlManager__CreateXWnd_x                                 0x7FB1F0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FB7A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92F730
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92F630
#define CSidlScreenWnd__ConvertToRes_x                             0x9588B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92F130
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92EE20
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92EEF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92EFC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92FBC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x930090
#define CSidlScreenWnd__GetSidlPiece_x                             0x92FDB0
#define CSidlScreenWnd__Init1_x                                    0x92EA40
#define CSidlScreenWnd__LoadIniInfo_x                              0x9300E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x930C40
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92DE40
#define CSidlScreenWnd__StoreIniInfo_x                             0x9307B0
#define CSidlScreenWnd__StoreIniVis_x                              0x930B20
#define CSidlScreenWnd__WndNotification_x                          0x92FAD0
#define CSidlScreenWnd__GetChildItem_x                             0x930010
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91F8A0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D8190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6981F0
#define CSkillMgr__GetSkillCap_x                                   0x6983D0
#define CSkillMgr__GetNameToken_x                                  0x697970
#define CSkillMgr__IsActivatedSkill_x                              0x697AB0
#define CSkillMgr__IsCombatSkill_x                                 0x6979F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93F940
#define CSliderWnd__SetValue_x                                     0x93F7B0
#define CSliderWnd__SetNumTicks_x                                  0x93F810

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801520

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x948210
#define CStmlWnd__ParseSTML_x                                      0x949540
#define CStmlWnd__CalculateHSBRange_x                              0x949330
#define CStmlWnd__CalculateVSBRange_x                              0x9492A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94D660
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94E2F0
#define CStmlWnd__ForceParseNow_x                                  0x948800
#define CStmlWnd__GetNextTagPiece_x                                0x94D5C0
#define CStmlWnd__GetSTMLText_x                                    0x50C7B0
#define CStmlWnd__GetVisibleText_x                                 0x948820
#define CStmlWnd__InitializeWindowVariables_x                      0x94E140
#define CStmlWnd__MakeStmlColorTag_x                               0x947880
#define CStmlWnd__MakeWndNotificationTag_x                         0x9478F0
#define CStmlWnd__SetSTMLText_x                                    0x946930
#define CStmlWnd__StripFirstSTMLLines_x                            0x94F3C0
#define CStmlWnd__UpdateHistoryString_x                            0x94E500

// CTabWnd 
#define CTabWnd__Draw_x                                            0x945A80
#define CTabWnd__DrawCurrentPage_x                                 0x9461B0
#define CTabWnd__DrawTab_x                                         0x945ED0
#define CTabWnd__GetCurrentPage_x                                  0x945290
#define CTabWnd__GetPageInnerRect_x                                0x9454D0
#define CTabWnd__GetTabInnerRect_x                                 0x945410
#define CTabWnd__GetTabRect_x                                      0x9452C0
#define CTabWnd__InsertPage_x                                      0x9456E0
#define CTabWnd__RemovePage_x                                      0x945850
#define CTabWnd__SetPage_x                                         0x945550
#define CTabWnd__SetPageRect_x                                     0x9459C0
#define CTabWnd__UpdatePage_x                                      0x945D90
#define CTabWnd__GetPageFromTabIndex_x                             0x945E10
#define CTabWnd__GetCurrentTabIndex_x                              0x945280

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75E720
#define CPageWnd__SetTabText_x                                     0x944DD0
#define CPageWnd__FlashTab_x                                       0x944E30

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9360

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91C780
#define CTextureFont__GetTextExtent_x                              0x91C940

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC390
#define CHtmlComponentWnd__ValidateUri_x                           0x73CBA0
#define CHtmlWnd__SetClientCallbacks_x                             0x6379E0
#define CHtmlWnd__AddObserver_x                                    0x637A00
#define CHtmlWnd__RemoveObserver_x                                 0x637A60
#define Window__getProgress_x                                      0x853300
#define Window__getStatus_x                                        0x853320
#define Window__getURI_x                                           0x853330

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9556C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x909910

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E99C0
#define CXStr__CXStr1_x                                            0x4B7570
#define CXStr__CXStr3_x                                            0x8F1290
#define CXStr__dCXStr_x                                            0x4784C0
#define CXStr__operator_equal_x                                    0x8F14C0
#define CXStr__operator_equal1_x                                   0x8F1500
#define CXStr__operator_plus_equal1_x                              0x8F1F90
#define CXStr__SetString_x                                         0x8F3E80
#define CXStr__operator_char_p_x                                   0x8F19D0
#define CXStr__GetChar_x                                           0x8F37D0
#define CXStr__Delete_x                                            0x8F3080
#define CXStr__GetUnicode_x                                        0x8F3840
#define CXStr__GetLength_x                                         0x47D730
#define CXStr__Mid_x                                               0x47D740
#define CXStr__Insert_x                                            0x8F38A0
#define CXStr__FindNext_x                                          0x8F34F0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93DC00
#define CXWnd__BringToTop_x                                        0x923020
#define CXWnd__Center_x                                            0x922BA0
#define CXWnd__ClrFocus_x                                          0x9229C0
#define CXWnd__Destroy_x                                           0x922A60
#define CXWnd__DoAllDrawing_x                                      0x91F040
#define CXWnd__DrawChildren_x                                      0x91F010
#define CXWnd__DrawColoredRect_x                                   0x91F490
#define CXWnd__DrawTooltip_x                                       0x91DB70
#define CXWnd__DrawTooltipAtPoint_x                                0x91DC30
#define CXWnd__GetBorderFrame_x                                    0x91F2F0
#define CXWnd__GetChildWndAt_x                                     0x9230C0
#define CXWnd__GetClientClipRect_x                                 0x9212B0
#define CXWnd__GetScreenClipRect_x                                 0x921360
#define CXWnd__GetScreenRect_x                                     0x9214F0
#define CXWnd__GetRelativeRect_x                                   0x9215B0
#define CXWnd__GetTooltipRect_x                                    0x91F4E0
#define CXWnd__GetWindowTextA_x                                    0x49CFF0
#define CXWnd__IsActive_x                                          0x91FC10
#define CXWnd__IsDescendantOf_x                                    0x921EF0
#define CXWnd__IsReallyVisible_x                                   0x921F20
#define CXWnd__IsType_x                                            0x923730
#define CXWnd__Move_x                                              0x921F90
#define CXWnd__Move1_x                                             0x922040
#define CXWnd__ProcessTransition_x                                 0x922B50
#define CXWnd__Refade_x                                            0x922310
#define CXWnd__Resize_x                                            0x9225E0
#define CXWnd__Right_x                                             0x922DE0
#define CXWnd__SetFocus_x                                          0x922980
#define CXWnd__SetFont_x                                           0x9229F0
#define CXWnd__SetKeyTooltip_x                                     0x923540
#define CXWnd__SetMouseOver_x                                      0x920430
#define CXWnd__StartFade_x                                         0x921DD0
#define CXWnd__GetChildItem_x                                      0x923220
#define CXWnd__SetParent_x                                         0x921C90
#define CXWnd__Minimize_x                                          0x922650

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x959930

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x925F70
#define CXWndManager__DrawWindows_x                                0x925F90
#define CXWndManager__GetKeyboardFlags_x                           0x9286A0
#define CXWndManager__HandleKeyboardMsg_x                          0x928260
#define CXWndManager__RemoveWnd_x                                  0x9288D0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x928E50

// CDBStr
#define CDBStr__GetString_x                                        0x546FA0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFF90
#define EQ_Character__Cur_HP_x                                     0x4D31B0
#define EQ_Character__Cur_Mana_x                                   0x4DA8D0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C3000
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3940
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3A90
#define EQ_Character__GetHPRegen_x                                 0x4E07A0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0DA0
#define EQ_Character__GetManaRegen_x                               0x4E11E0
#define EQ_Character__Max_Endurance_x                              0x65E640
#define EQ_Character__Max_HP_x                                     0x4D2FE0
#define EQ_Character__Max_Mana_x                                   0x65E440
#define EQ_Character__doCombatAbility_x                            0x660A30
#define EQ_Character__UseSkill_x                                   0x4E2FE0
#define EQ_Character__GetConLevel_x                                0x656F60
#define EQ_Character__IsExpansionFlag_x                            0x5BA4D0
#define EQ_Character__TotalEffect_x                                0x4C6DA0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3D50
#define EQ_Character__SpellDuration_x                              0x4C3880
#define EQ_Character__MySpellDuration_x                            0x4B2270
#define EQ_Character__GetAdjustedSkill_x                           0x4D5F30
#define EQ_Character__GetBaseSkill_x                               0x4D6ED0
#define EQ_Character__CanUseItem_x                                 0x4DABE0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BCFC0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x674970

//PcClient
#define PcClient__vftable_x                                        0xAF11E0
#define PcClient__PcClient_x                                       0x6546C0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA9A0
#define CCharacterListWnd__EnterWorld_x                            0x4BA370
#define CCharacterListWnd__Quit_x                                  0x4BA0C0
#define CCharacterListWnd__UpdateList_x                            0x4BA560

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x638BD0
#define EQ_Item__CreateItemTagString_x                             0x897640
#define EQ_Item__IsStackable_x                                     0x89C2F0
#define EQ_Item__GetImageNum_x                                     0x899190
#define EQ_Item__CreateItemClient_x                                0x637E00
#define EQ_Item__GetItemValue_x                                    0x89A4A0
#define EQ_Item__ValueSellMerchant_x                               0x89DCA0
#define EQ_Item__IsKeyRingItem_x                                   0x89BC10
#define EQ_Item__CanGoInBag_x                                      0x638CF0
#define EQ_Item__IsEmpty_x                                         0x89B760
#define EQ_Item__GetMaxItemCount_x                                 0x89A8B0
#define EQ_Item__GetHeldItem_x                                     0x899060
#define EQ_Item__GetAugmentFitBySlot_x                             0x896EA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565A90
#define EQ_LoadingS__Array_x                                       0xC11130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65EF40
#define EQ_PC__GetAlternateAbilityId_x                             0x8A6CE0
#define EQ_PC__GetCombatAbility_x                                  0x8A7350
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A73C0
#define EQ_PC__GetItemRecastTimer_x                                0x660FB0
#define EQ_PC__HasLoreItem_x                                       0x657770
#define EQ_PC__AlertInventoryChanged_x                             0x656890
#define EQ_PC__GetPcZoneClient_x                                   0x683A50
#define EQ_PC__RemoveMyAffect_x                                    0x6641E0
#define EQ_PC__GetKeyRingItems_x                                   0x8A7C50
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A79E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A7F50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C0930
#define EQItemList__add_object_x                                   0x5EDF70
#define EQItemList__add_item_x                                     0x5C0E90
#define EQItemList__delete_item_x                                  0x5C0EE0
#define EQItemList__FreeItemList_x                                 0x5C0DE0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543B10

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x676270
#define EQPlayer__dEQPlayer_x                                      0x6695E0
#define EQPlayer__DoAttack_x                                       0x67E1F0
#define EQPlayer__EQPlayer_x                                       0x669CA0
#define EQPlayer__SetNameSpriteState_x                             0x66DF80
#define EQPlayer__SetNameSpriteTint_x                              0x66EE60
#define PlayerBase__HasProperty_j_x                                0x988510
#define EQPlayer__IsTargetable_x                                   0x9889B0
#define EQPlayer__CanSee_x                                         0x988810
#define EQPlayer__CanSee1_x                                        0x9888E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9885D0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6814F0
#define PlayerZoneClient__GetLevel_x                               0x683A90
#define PlayerZoneClient__IsValidTeleport_x                        0x5EF0E0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E7C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6790E0
#define EQPlayerManager__GetSpawnByName_x                          0x679190
#define EQPlayerManager__GetPlayerFromPartialName_x                0x679220

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C3E0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C460
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C4A0
#define KeypressHandler__ClearCommandStateArray_x                  0x63D890
#define KeypressHandler__HandleKeyDown_x                           0x63D8B0
#define KeypressHandler__HandleKeyUp_x                             0x63D950
#define KeypressHandler__SaveKeymapping_x                          0x63DDA0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7752E0
#define MapViewMap__SaveEx_x                                       0x7786A0
#define MapViewMap__SetZoom_x                                      0x77CD60

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB030

// StringTable 
#define StringTable__getString_x                                   0x8B5E10

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x663E50
#define PcZoneClient__RemovePetEffect_x                            0x664480
#define PcZoneClient__HasAlternateAbility_x                        0x65E270
#define PcZoneClient__GetCurrentMod_x                              0x4E6100
#define PcZoneClient__GetModCap_x                                  0x4E6000
#define PcZoneClient__CanEquipItem_x                               0x65E920
#define PcZoneClient__GetItemByID_x                                0x661420
#define PcZoneClient__GetItemByItemClass_x                         0x661570
#define PcZoneClient__RemoveBuffEffect_x                           0x6644A0
#define PcZoneClient__BandolierSwap_x                              0x65F500
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x660F50

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F3CB0

//IconCache
#define IconCache__GetIcon_x                                       0x716DE0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70E900
#define CContainerMgr__CloseContainer_x                            0x70EBD0
#define CContainerMgr__OpenExperimentContainer_x                   0x70F650

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CDA20

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x630D90

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76B7A0
#define CLootWnd__RequestLootSlot_x                                0x76AA80

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D3C0
#define EQ_Spell__SpellAffects_x                                   0x58D830
#define EQ_Spell__SpellAffectBase_x                                0x58D5F0
#define EQ_Spell__IsStackable_x                                    0x4CABF0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAA10
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7C50
#define EQ_Spell__IsSPAStacking_x                                  0x58E680
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DB90
#define EQ_Spell__IsNoRemove_x                                     0x4CABD0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E690
#define __IsResEffectSpell_x                                       0x4C9DF0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD5E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5730

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814820
#define CTargetWnd__WndNotification_x                              0x814060
#define CTargetWnd__RefreshTargetBuffs_x                           0x814330
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8131D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x818EA0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81BAE0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x541530
#define CTaskManager__HandleMessage_x                              0x53F9B0
#define CTaskManager__GetTaskStatus_x                              0x5415E0
#define CTaskManager__GetElementDescription_x                      0x541660

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x588500
#define EqSoundManager__PlayScriptMp3_x                            0x5887C0
#define EqSoundManager__SoundAssistPlay_x                          0x69C130
#define EqSoundManager__WaveInstancePlay_x                         0x69B6A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532910

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9442E0
#define CTextureAnimation__Draw_x                                  0x9444E0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9402B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D690
#define CAltAbilityData__GetMercMaxRank_x                          0x56D620
#define CAltAbilityData__GetMaxRank_x                              0x562960

//CTargetRing
#define CTargetRing__Cast_x                                        0x62EEB0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA9F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x519540
#define CharacterBase__CreateItemIndex_x                           0x636F90
#define CharacterBase__GetItemPossession_x                         0x5052D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CDD70
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CDDD0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5960
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6190
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6240

//messages
#define msg_spell_worn_off_x                                       0x5B23C0
#define msg_new_text_x                                             0x5A6D50
#define __msgTokenTextParam_x                                      0x5B4660
#define msgTokenText_x                                             0x5B48B0

//SpellManager
#define SpellManager__vftable_x                                    0xAD9574
#define SpellManager__SpellManager_x                               0x69F450
#define Spellmanager__LoadTextSpells_x                             0x69FD40
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F620

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98C3D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519BC0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8840
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64FE20
#define ItemGlobalIndex__IsValidIndex_x                            0x519C50

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C60D0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6350

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764060

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x712FE0
#define CCursorAttachment__AttachToCursor1_x                       0x713020
#define CCursorAttachment__Deactivate_x                            0x714000

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x937000
#define CSidlManagerBase__CreatePageWnd_x                          0x936810
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x932AB0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x932A40

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x953F80
#define CEQSuiteTextureLoader__GetTexture_x                        0x953C40

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516AC0
#define CFindItemWnd__WndNotification_x                            0x5175A0
#define CFindItemWnd__Update_x                                     0x518110
#define CFindItemWnd__PickupSelectedItem_x                         0x5162F0

//IString
#define IString__Append_x                                          0x506B00

//Camera
#define CDisplay__cameraType_x                                     0xDE8E38
#define EverQuest__Cameras_x                                       0xEA4094

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F520
#define LootFiltersManager__GetItemFilterData_x                    0x51EE20
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51EE50
#define LootFiltersManager__SetItemLootFilter_x                    0x51F070

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BB7D0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x992100
#define CResolutionHandler__GetWindowedStyle_x                     0x696BB0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70B520

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DB700
#define CDistillerInfo__Instance_x                                 0x8DB6A0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A510
#define CGroupWnd__UpdateDisplay_x                                 0x729870

//ItemBase
#define ItemBase__IsLore_x                                         0x89BCC0
#define ItemBase__IsLoreEquipped_x                                 0x89BD30

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EDED0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EE010
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EE070

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C170
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68FAF0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D1C0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F93A0
#define FactionManagerClient__HandleFactionMessage_x               0x4F9A10
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F9FD0
#define FactionManagerClient__GetMaxFaction_x                      0x4F9FEF
#define FactionManagerClient__GetMinFaction_x                      0x4F9FA0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5052A0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91B7D0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C300

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x505510

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CB20

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2C80

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C170

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9120

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C0D80

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF4172C

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF3A0
#define CAAWnd__UpdateSelected_x                                   0x6BBC10
#define CAAWnd__Update_x                                           0x6BE6C0

//CXRect
#define CXRect__operator_and_x                                     0x721600

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4833A0

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
