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
#define __ExpectedVersionDate                                     "Oct 24 2020"
#define __ExpectedVersionTime                                     "04:17:45"
#define __ActualVersionDate_x                                      0xAF459C
#define __ActualVersionTime_x                                      0xAF4590
#define __ActualVersionBuild_x                                     0xAE259C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x643190
#define __MemChecker1_x                                            0x8F5680
#define __MemChecker2_x                                            0x6B34C0
#define __MemChecker3_x                                            0x6B3410
#define __MemChecker4_x                                            0x84C0A0
#define __EncryptPad0_x                                            0xC299D0
#define __EncryptPad1_x                                            0xC87210
#define __EncryptPad2_x                                            0xC39D98
#define __EncryptPad3_x                                            0xC39998
#define __EncryptPad4_x                                            0xC777A8
#define __EncryptPad5_x                                            0xF49648
#define __AC1_x                                                    0x80AA66
#define __AC2_x                                                    0x5FC73F
#define __AC3_x                                                    0x603D90
#define __AC4_x                                                    0x607D40
#define __AC5_x                                                    0x60E03F
#define __AC6_x                                                    0x6124F6
#define __AC7_x                                                    0x5FC1B0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x190448

// Direct Input
#define DI8__Main_x                                                0xF49668
#define DI8__Keyboard_x                                            0xF4966C
#define DI8__Mouse_x                                               0xF49684
#define DI8__Mouse_Copy_x                                          0xEA29DC
#define DI8__Mouse_Check_x                                         0xF4719C
#define __AutoSkillArray_x                                         0xEA38F8
#define __Attack_x                                                 0xF4171F
#define __Autofire_x                                               0xF41720
#define __BindList_x                                               0xC18400
#define g_eqCommandStates_x                                        0xC19180
#define __Clicks_x                                                 0xEA2A94
#define __CommandList_x                                            0xC19D40
#define __CurrentMapLabel_x                                        0xF5A144
#define __CurrentSocial_x                                          0xC017C8
#define __DoAbilityList_x                                          0xED9240
#define __do_loot_x                                                0x5C81A0
#define __DrawHandler_x                                            0x15D9138
#define __GroupCount_x                                             0xE9DA62
#define __Guilds_x                                                 0xEA1918
#define __gWorld_x                                                 0xE9D90C
#define __HWnd_x                                                   0xF49688
#define __heqmain_x                                                0xF49630
#define __InChatMode_x                                             0xEA29C4
#define __LastTell_x                                               0xEA493C
#define __LMouseHeldTime_x                                         0xEA2B00
#define __Mouse_x                                                  0xF49654
#define __MouseLook_x                                              0xEA2A5A
#define __MouseEventTime_x                                         0xF42204
#define __gpbCommandEvent_x                                        0xE9B3B0
#define __NetStatusToggle_x                                        0xEA2A5D
#define __PCNames_x                                                0xEA3EE8
#define __RangeAttackReady_x                                       0xEA3BDC
#define __RMouseHeldTime_x                                         0xEA2AFC
#define __RunWalkState_x                                           0xEA29C8
#define __ScreenMode_x                                             0xDE8D54
#define __ScreenX_x                                                0xEA297C
#define __ScreenY_x                                                0xEA2978
#define __ScreenXMax_x                                             0xEA2980
#define __ScreenYMax_x                                             0xEA2984
#define __ServerHost_x                                             0xE9B57B
#define __ServerName_x                                             0xED9200
#define __ShiftKeyDown_x                                           0xEA3058
#define __ShowNames_x                                              0xEA3D98
#define EverQuestInfo__bSocialChanged_x                            0xED9288
#define __Socials_x                                                0xED9300
#define __SubscriptionType_x                                       0xF9E408
#define __TargetAggroHolder_x                                      0xF5CAF8
#define __ZoneType_x                                               0xEA2E58
#define __GroupAggro_x                                             0xF5CB38
#define __LoginName_x                                              0xF49DC4
#define __Inviter_x                                                0xF4169C
#define __AttackOnAssist_x                                         0xEA3D54
#define __UseTellWindows_x                                         0xEA4080
#define __gfMaxZoomCameraDistance_x                                0xAEC1B8
#define __gfMaxCameraDistance_x                                    0xB14E28
#define __pulAutoRun_x                                             0xEA2A78
#define __pulForward_x                                             0xEA40B8
#define __pulBackward_x                                            0xEA40BC
#define __pulTurnRight_x                                           0xEA40C0
#define __pulTurnLeft_x                                            0xEA40C4
#define __pulStrafeLeft_x                                          0xEA40C8
#define __pulStrafeRight_x                                         0xEA40CC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9DCB0
#define instEQZoneInfo_x                                           0xEA2C50
#define pinstActiveBanker_x                                        0xE9B89C
#define pinstActiveCorpse_x                                        0xE9B894
#define pinstActiveGMaster_x                                       0xE9B898
#define pinstActiveMerchant_x                                      0xE9B890
#define pinstAltAdvManager_x                                       0xDE9EE0
#define pinstBandageTarget_x                                       0xE9B8AC
#define pinstCamActor_x                                            0xDE8D44
#define pinstCDBStr_x                                              0xDE8BFC
#define pinstCDisplay_x                                            0xE9D904
#define pinstCEverQuest_x                                          0xF49680
#define pinstEverQuestInfo_x                                       0xEA2970
#define pinstCharData_x                                            0xE9DCA0
#define pinstCharSpawn_x                                           0xE9B8E4
#define pinstControlledMissile_x                                   0xE9B8F4
#define pinstControlledPlayer_x                                    0xE9B8E4
#define pinstCResolutionHandler_x                                  0x15D9368
#define pinstCSidlManager_x                                        0x15D8300
#define pinstCXWndManager_x                                        0x15D82FC
#define instDynamicZone_x                                          0xEA17F0
#define pinstDZMember_x                                            0xEA1900
#define pinstDZTimerInfo_x                                         0xEA1904
#define pinstEqLogin_x                                             0xF49710
#define instEQMisc_x                                               0xDE8B40
#define pinstEQSoundManager_x                                      0xDEAEB0
#define pinstEQSpellStrings_x                                      0xCAB448
#define instExpeditionLeader_x                                     0xEA183A
#define instExpeditionName_x                                       0xEA187A
#define pinstGroup_x                                               0xE9DA5E
#define pinstImeManager_x                                          0x15D82F8
#define pinstLocalPlayer_x                                         0xE9B88C
#define pinstMercenaryData_x                                       0xF43CF8
#define pinstMercenaryStats_x                                      0xF5CBC4
#define pinstModelPlayer_x                                         0xE9B8A4
#define pinstPCData_x                                              0xE9DCA0
#define pinstSkillMgr_x                                            0xF45E60
#define pinstSpawnManager_x                                        0xF44908
#define pinstSpellManager_x                                        0xF460A0
#define pinstSpellSets_x                                           0xF3A348
#define pinstStringTable_x                                         0xE9DCA8
#define pinstSwitchManager_x                                       0xE9B250
#define pinstTarget_x                                              0xE9B8E0
#define pinstTargetObject_x                                        0xE9B8EC
#define pinstTargetSwitch_x                                        0xE9B8FC
#define pinstTaskMember_x                                          0xDE89D0
#define pinstTrackTarget_x                                         0xE9B8E8
#define pinstTradeTarget_x                                         0xE9B8A0
#define instTributeActive_x                                        0xDE8B61
#define pinstViewActor_x                                           0xDE8D3C
#define pinstWorldData_x                                           0xE9B3A0
#define pinstZoneAddr_x                                            0xEA2EF0
#define pinstPlayerPath_x                                          0xF449A0
#define pinstTargetIndicator_x                                     0xF46308
#define EQObject_Top_x                                             0xE9B684
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE9068
#define pinstCAchievementsWnd_x                                    0xDE8CDC
#define pinstCActionsWnd_x                                         0xDE90A4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE8D9C
#define pinstCAdvancedLootWnd_x                                    0xDE8D34
#define pinstCAdventureLeaderboardWnd_x                            0xF53918
#define pinstCAdventureRequestWnd_x                                0xF539C8
#define pinstCAdventureStatsWnd_x                                  0xF53A78
#define pinstCAggroMeterWnd_x                                      0xDE8D84
#define pinstCAlarmWnd_x                                           0xDE8D04
#define pinstCAlertHistoryWnd_x                                    0xDE8E18
#define pinstCAlertStackWnd_x                                      0xDE8D6C
#define pinstCAlertWnd_x                                           0xDE8D80
#define pinstCAltStorageWnd_x                                      0xF53DD8
#define pinstCAudioTriggersWindow_x                                0xC9D778
#define pinstCAuraWnd_x                                            0xDE8D38
#define pinstCAvaZoneWnd_x                                         0xDE8E14
#define pinstCBandolierWnd_x                                       0xDE8D98
#define pinstCBankWnd_x                                            0xDE8DCC
#define pinstCBarterMerchantWnd_x                                  0xF55018
#define pinstCBarterSearchWnd_x                                    0xF550C8
#define pinstCBarterWnd_x                                          0xF55178
#define pinstCBazaarConfirmationWnd_x                              0xDE8D18
#define pinstCBazaarSearchWnd_x                                    0xDE906C
#define pinstCBazaarWnd_x                                          0xDE8CE8
#define pinstCBlockedBuffWnd_x                                     0xDE8D60
#define pinstCBlockedPetBuffWnd_x                                  0xDE8D88
#define pinstCBodyTintWnd_x                                        0xDE9530
#define pinstCBookWnd_x                                            0xDE8DC4
#define pinstCBreathWnd_x                                          0xDE907C
#define pinstCBuffWindowNORMAL_x                                   0xDE8D2C
#define pinstCBuffWindowSHORT_x                                    0xDE8D30
#define pinstCBugReportWnd_x                                       0xDE8DC8
#define pinstCButtonWnd_x                                          0x15D8568
#define pinstCCastingWnd_x                                         0xDE8DB8
#define pinstCCastSpellWnd_x                                       0xDE9078
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE8C9C
#define pinstCChatWindowManager_x                                  0xF55C38
#define pinstCClaimWnd_x                                           0xF55D90
#define pinstCColorPickerWnd_x                                     0xDE9030
#define pinstCCombatAbilityWnd_x                                   0xDE8CF8
#define pinstCCombatSkillsSelectWnd_x                              0xDE8CB0
#define pinstCCompassWnd_x                                         0xDE911C
#define pinstCConfirmationDialog_x                                 0xF5AC90
#define pinstCContainerMgr_x                                       0xDE952C
#define pinstCContextMenuManager_x                                 0x15D82B8
#define pinstCCursorAttachment_x                                   0xDE8DAC
#define pinstCDynamicZoneWnd_x                                     0xF56358
#define pinstCEditLabelWnd_x                                       0xDE8D28
#define pinstCEQMainWnd_x                                          0xF565A0
#define pinstCEventCalendarWnd_x                                   0xDE9070
#define pinstCExtendedTargetWnd_x                                  0xDE8D68
#define pinstCFacePick_x                                           0xDE8CB4
#define pinstCFactionWnd_x                                         0xDE8CD4
#define pinstCFellowshipWnd_x                                      0xF567A0
#define pinstCFileSelectionWnd_x                                   0xDE902C
#define pinstCFindItemWnd_x                                        0xDE8CC4
#define pinstCFindLocationWnd_x                                    0xF568F8
#define pinstCFriendsWnd_x                                         0xDE8CC8
#define pinstCGemsGameWnd_x                                        0xDE8CD0
#define pinstCGiveWnd_x                                            0xDE8D08
#define pinstCGroupSearchFiltersWnd_x                              0xDE8DA0
#define pinstCGroupSearchWnd_x                                     0xF56CF0
#define pinstCGroupWnd_x                                           0xF56DA0
#define pinstCGuildBankWnd_x                                       0xEA3D38
#define pinstCGuildCreationWnd_x                                   0xF56F00
#define pinstCGuildMgmtWnd_x                                       0xF56FB0
#define pinstCharacterCreation_x                                   0xDE8CBC
#define pinstCHelpWnd_x                                            0xDE8D0C
#define pinstCHeritageSelectionWnd_x                               0xDE8CC0
#define pinstCHotButtonWnd_x                                       0xF59108
#define pinstCHotButtonWnd1_x                                      0xF59108
#define pinstCHotButtonWnd2_x                                      0xF5910C
#define pinstCHotButtonWnd3_x                                      0xF59110
#define pinstCHotButtonWnd4_x                                      0xF59114
#define pinstCIconSelectionWnd_x                                   0xDE8DA8
#define pinstCInspectWnd_x                                         0xDE8D8C
#define pinstCInventoryWnd_x                                       0xDE8D40
#define pinstCInvSlotMgr_x                                         0xDE905C
#define pinstCItemDisplayManager_x                                 0xF59698
#define pinstCItemExpTransferWnd_x                                 0xF597CC
#define pinstCItemOverflowWnd_x                                    0xDE9074
#define pinstCJournalCatWnd_x                                      0xDE9048
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE8E00
#define pinstCKeyRingWnd_x                                         0xDE8DB4
#define pinstCLargeDialogWnd_x                                     0xF5B910
#define pinstCLayoutCopyWnd_x                                      0xF59B18
#define pinstCLFGuildWnd_x                                         0xF59BC8
#define pinstCLoadskinWnd_x                                        0xDE8CEC
#define pinstCLootFiltersCopyWnd_x                                 0xCB9ED8
#define pinstCLootFiltersWnd_x                                     0xDE8D70
#define pinstCLootSettingsWnd_x                                    0xDE8D94
#define pinstCLootWnd_x                                            0xDE904C
#define pinstCMailAddressBookWnd_x                                 0xDE9060
#define pinstCMailCompositionWnd_x                                 0xDE9038
#define pinstCMailIgnoreListWnd_x                                  0xDE9064
#define pinstCMailWnd_x                                            0xDE903C
#define pinstCManageLootWnd_x                                      0xDEA390
#define pinstCMapToolbarWnd_x                                      0xDE8D14
#define pinstCMapViewWnd_x                                         0xDE8CE0
#define pinstCMarketplaceWnd_x                                     0xDE8D74
#define pinstCMerchantWnd_x                                        0xDE9058
#define pinstCMIZoneSelectWnd_x                                    0xF5A400
#define pinstCMusicPlayerWnd_x                                     0xDE9024
#define pinstCNameChangeMercWnd_x                                  0xDE8D10
#define pinstCNameChangePetWnd_x                                   0xDE8CE4
#define pinstCNameChangeWnd_x                                      0xDE8D24
#define pinstCNoteWnd_x                                            0xDE8CF0
#define pinstCObjectPreviewWnd_x                                   0xDE8D90
#define pinstCOptionsWnd_x                                         0xDE8CFC
#define pinstCPetInfoWnd_x                                         0xDE9020
#define pinstCPetitionQWnd_x                                       0xDE8CAC
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE9534
#define pinstCPlayerWnd_x                                          0xDE8E0C
#define pinstCPopupWndManager_x                                    0xF5AC90
#define pinstCProgressionSelectionWnd_x                            0xF5AD40
#define pinstCPurchaseGroupWnd_x                                   0xDE8DE4
#define pinstCPurchaseWnd_x                                        0xDE8DBC
#define pinstCPvPLeaderboardWnd_x                                  0xF5ADF0
#define pinstCPvPStatsWnd_x                                        0xF5AEA0
#define pinstCQuantityWnd_x                                        0xDE8DFC
#define pinstCRaceChangeWnd_x                                      0xDE8D50
#define pinstCRaidOptionsWnd_x                                     0xDE8DA4
#define pinstCRaidWnd_x                                            0xDE9054
#define pinstCRealEstateItemsWnd_x                                 0xDE8CD8
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE9120
#define pinstCRealEstateManageWnd_x                                0xDE8DE8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE8E08
#define pinstCRealEstatePlotSearchWnd_x                            0xDE9028
#define pinstCRealEstatePurchaseWnd_x                              0xDE9044
#define pinstCRespawnWnd_x                                         0xDE8D7C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE8CA8
#define pinstCSendMoneyWnd_x                                       0xDE8D1C
#define pinstCServerListWnd_x                                      0xDE9050
#define pinstCSkillsSelectWnd_x                                    0xDE8CA4
#define pinstCSkillsWnd_x                                          0xDE9124
#define pinstCSocialEditWnd_x                                      0xDE8DB0
#define pinstCSocialWnd_x                                          0xDE8D00
#define pinstCSpellBookWnd_x                                       0xDE8CF4
#define pinstCStoryWnd_x                                           0xDE90A0
#define pinstCTargetOfTargetWnd_x                                  0xF5CC48
#define pinstCTargetWnd_x                                          0xDE8D78
#define pinstCTaskOverlayWnd_x                                     0xDE8DDC
#define pinstCTaskSelectWnd_x                                      0xF5CDA0
#define pinstCTaskManager_x                                        0xCBA818
#define pinstCTaskTemplateSelectWnd_x                              0xF5CE50
#define pinstCTaskWnd_x                                            0xF5CF00
#define pinstCTextEntryWnd_x                                       0xDE8DC0
#define pinstCTimeLeftWnd_x                                        0xDE8CA0
#define pinstCTipWndCONTEXT_x                                      0xF5D104
#define pinstCTipWndOFDAY_x                                        0xF5D100
#define pinstCTitleWnd_x                                           0xF5D1B0
#define pinstCTrackingWnd_x                                        0xDE8D64
#define pinstCTradeskillWnd_x                                      0xF5D318
#define pinstCTradeWnd_x                                           0xDE8C98
#define pinstCTrainWnd_x                                           0xDE9040
#define pinstCTributeBenefitWnd_x                                  0xF5D518
#define pinstCTributeMasterWnd_x                                   0xF5D5C8
#define pinstCTributeTrophyWnd_x                                   0xF5D678
#define pinstCVideoModesWnd_x                                      0xDE8E10
#define pinstCVoiceMacroWnd_x                                      0xF468C0
#define pinstCVoteResultsWnd_x                                     0xDE8CCC
#define pinstCVoteWnd_x                                            0xDE8CB8
#define pinstCWebManager_x                                         0xF46F3C
#define pinstCZoneGuideWnd_x                                       0xDE8DE0
#define pinstCZonePathWnd_x                                        0xDE8DF8

#define pinstEQSuiteTextureLoader_x                                0xC87B30
#define pinstItemIconCache_x                                       0xF56558
#define pinstLootFiltersManager_x                                  0xCB9F88
#define pinstRewardSelectionWnd_x                                  0xF5B5E8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C3890
#define __CastRay2_x                                               0x5C38E0
#define __ConvertItemTags_x                                        0x5DF5A0
#define __CleanItemTags_x                                          0x47D3A0
#define __DoesFileExist_x                                          0x8F8700
#define __EQGetTime_x                                              0x8F52B0
#define __ExecuteCmd_x                                             0x5BC1D0
#define __FixHeading_x                                             0x98A000
#define __FlushDxKeyboard_x                                        0x6AF360
#define __GameLoop_x                                               0x6B2690
#define __get_bearing_x                                            0x5C33F0
#define __get_melee_range_x                                        0x5C3AD0
#define __GetAnimationCache_x                                      0x717870
#define __GetGaugeValueFromEQ_x                                    0x808F10
#define __GetLabelFromEQ_x                                         0x80A9F0
#define __GetXTargetType_x                                         0x98B9E0
#define __HandleMouseWheel_x                                       0x6B3570
#define __HeadingDiff_x                                            0x98A070
#define __HelpPath_x                                               0xF41DF4
#define __LoadFrontEnd_x                                           0x6AF9A0
#define __NewUIINI_x                                               0x808BE0
#define __ProcessGameEvents_x                                      0x6243D0
#define __ProcessMouseEvent_x                                      0x623B60
#define __SaveColors_x                                             0x55CC70
#define __STMLToText_x                                             0x92D510
#define __ToggleKeyRingItem_x                                      0x51B460
#define CMemoryMappedFile__SetFile_x                               0xA792A0
#define CrashDetected_x                                            0x6B1450
#define DrawNetStatus_x                                            0x6505C0
#define Expansion_HoT_x                                            0xEA3D40
#define Teleport_Table_Size_x                                      0xE9B438
#define Teleport_Table_x                                           0xE9B900
#define Util__FastTime_x                                           0x8F4E80
#define __CopyLayout_x                                             0x63E860
#define __WndProc_x                                                0x6B1950
#define __ProcessKeyboardEvent_x                                   0x6B0EF0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490690
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499680
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499450
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493C20
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493070

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564DB0
#define AltAdvManager__IsAbilityReady_x                            0x563B50
#define AltAdvManager__GetAAById_x                                 0x563EE0
#define AltAdvManager__CanTrainAbility_x                           0x563F50
#define AltAdvManager__CanSeeAbility_x                             0x5642B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB260
#define CharacterZoneClient__HasSkill_x                            0x4D60E0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7800
#define CharacterZoneClient__IsStackBlocked_x                      0x4C28D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBD60
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA1B0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA290
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA370
#define CharacterZoneClient__FindAffectSlot_x                      0x4C49C0
#define CharacterZoneClient__BardCastBard_x                        0x4C73F0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF770
#define CharacterZoneClient__GetEffect_x                           0x4BBCA0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5A30
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5B00
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5B50
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5CA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5E80
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3C90
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8760
#define CharacterZoneClient__FindItemByRecord_x                    0x4D81E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D9140
#define CBankWnd__WndNotification_x                                0x6D8F20

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6A50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92ACF0
#define CButtonWnd__CButtonWnd_x                                   0x9298F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706AF0
#define CChatManager__InitContextMenu_x                            0x6FFC20
#define CChatManager__FreeChatWindow_x                             0x705630
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9BC0
#define CChatManager__SetLockedActiveChatWindow_x                  0x706770
#define CChatManager__CreateChatWindow_x                           0x705C70

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9CD0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93DF50
#define CContextMenu__dCContextMenu_x                              0x93E180
#define CContextMenu__AddMenuItem_x                                0x93E190
#define CContextMenu__RemoveMenuItem_x                             0x93E490
#define CContextMenu__RemoveAllMenuItems_x                         0x93E4B0
#define CContextMenu__CheckMenuItem_x                              0x93E530
#define CContextMenu__SetMenuItem_x                                0x93E3C0
#define CContextMenu__AddSeparator_x                               0x93E320

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93EAC0
#define CContextMenuManager__RemoveMenu_x                          0x93EB30
#define CContextMenuManager__PopupMenu_x                           0x93EBF0
#define CContextMenuManager__Flush_x                               0x93EA60
#define CContextMenuManager__GetMenu_x                             0x49B970
#define CContextMenuManager__CreateDefaultMenu_x                   0x712200

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D0010
#define CChatService__GetFriendName_x                              0x8D0020

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x707320
#define CChatWindow__Clear_x                                       0x7085E0
#define CChatWindow__WndNotification_x                             0x708D70
#define CChatWindow__AddHistory_x                                  0x707EA0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93B3C0
#define CComboWnd__Draw_x                                          0x93A8D0
#define CComboWnd__GetCurChoice_x                                  0x93B200
#define CComboWnd__GetListRect_x                                   0x93AD70
#define CComboWnd__GetTextRect_x                                   0x93B420
#define CComboWnd__InsertChoice_x                                  0x93AF00
#define CComboWnd__SetColors_x                                     0x93AED0
#define CComboWnd__SetChoice_x                                     0x93B1D0
#define CComboWnd__GetItemCount_x                                  0x93B210
#define CComboWnd__GetCurChoiceText_x                              0x93B250
#define CComboWnd__GetChoiceText_x                                 0x93B220
#define CComboWnd__InsertChoiceAtIndex_x                           0x93AF90

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70FC20
#define CContainerWnd__vftable_x                                   0xAFD78C
#define CContainerWnd__SetContainer_x                              0x711170

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5575D0
#define CDisplay__PreZoneMainUI_x                                  0x5575E0
#define CDisplay__CleanGameUI_x                                    0x55CA30
#define CDisplay__GetClickedActor_x                                0x54FA30
#define CDisplay__GetUserDefinedColor_x                            0x5480B0
#define CDisplay__GetWorldFilePath_x                               0x5514A0
#define CDisplay__is3dON_x                                         0x54C690
#define CDisplay__ReloadUI_x                                       0x556AE0
#define CDisplay__WriteTextHD2_x                                   0x54C480
#define CDisplay__TrueDistance_x                                   0x553160
#define CDisplay__SetViewActor_x                                   0x54F350
#define CDisplay__GetFloorHeight_x                                 0x54C750
#define CDisplay__SetRenderWindow_x                                0x54B0D0
#define CDisplay__ToggleScreenshotMode_x                           0x54EE20

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95DCA0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x941400
#define CEditWnd__EnsureCaretVisible_x                             0x943570
#define CEditWnd__GetCaretPt_x                                     0x942550
#define CEditWnd__GetCharIndexPt_x                                 0x942310
#define CEditWnd__GetDisplayString_x                               0x9421C0
#define CEditWnd__GetHorzOffset_x                                  0x940AC0
#define CEditWnd__GetLineForPrintableChar_x                        0x943470
#define CEditWnd__GetSelStartPt_x                                  0x9425B0
#define CEditWnd__GetSTMLSafeText_x                                0x941FE0
#define CEditWnd__PointFromPrintableChar_x                         0x9430B0
#define CEditWnd__SelectableCharFromPoint_x                        0x943220
#define CEditWnd__SetEditable_x                                    0x942670
#define CEditWnd__SetWindowTextA_x                                 0x941D60
#define CEditWnd__ReplaceSelection_x                               0x942D30
#define CEditWnd__ReplaceSelection1_x                              0x942CB0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x6119D0
#define CEverQuest__ClickedPlayer_x                                0x603B70
#define CEverQuest__CreateTargetIndicator_x                        0x621540
#define CEverQuest__DeleteTargetIndicator_x                        0x6215D0
#define CEverQuest__DoTellWindow_x                                 0x4E9DB0
#define CEverQuest__OutputTextToLog_x                              0x4EA080
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8CC0
#define CEverQuest__dsp_chat_x                                     0x4EA410
#define CEverQuest__trimName_x                                     0x61D6F0
#define CEverQuest__Emote_x                                        0x612230
#define CEverQuest__EnterZone_x                                    0x60C330
#define CEverQuest__GetBodyTypeDesc_x                              0x616C80
#define CEverQuest__GetClassDesc_x                                 0x6172C0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6178C0
#define CEverQuest__GetDeityDesc_x                                 0x61FD90
#define CEverQuest__GetLangDesc_x                                  0x617A80
#define CEverQuest__GetRaceDesc_x                                  0x6172A0
#define CEverQuest__InterpretCmd_x                                 0x620360
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FCE60
#define CEverQuest__LMouseUp_x                                     0x5FB1E0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FD740
#define CEverQuest__RMouseUp_x                                     0x5FC170
#define CEverQuest__SetGameState_x                                 0x5F8A50
#define CEverQuest__UPCNotificationFlush_x                         0x61D5F0
#define CEverQuest__IssuePetCommand_x                              0x618E90
#define CEverQuest__ReportSuccessfulHit_x                          0x613580

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7217C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x721820
#define CGaugeWnd__Draw_x                                          0x720E40

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFFE0
#define CGuild__GetGuildName_x                                     0x4AEA90
#define CGuild__GetGuildIndex_x                                    0x4AF090

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B430

//CHotButton
#define CHotButton__SetCheck_x                                     0x632D60
#define CHotButton__SetButtonSize_x                                0x633120

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748530
#define CInvSlotMgr__MoveItem_x                                    0x7471F0
#define CInvSlotMgr__SelectSlot_x                                  0x748600

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7459D0
#define CInvSlot__SliderComplete_x                                 0x743710
#define CInvSlot__GetItemBase_x                                    0x743090
#define CInvSlot__UpdateItem_x                                     0x743200

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74A070
#define CInvSlotWnd__CInvSlotWnd_x                                 0x749200
#define CInvSlotWnd__HandleLButtonUp_x                             0x749BF0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x804230
#define CItemDisplayWnd__UpdateStrings_x                           0x758730
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752400
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752910
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x758D30
#define CItemDisplayWnd__AboutToShow_x                             0x758380
#define CItemDisplayWnd__WndNotification_x                         0x759FA0
#define CItemDisplayWnd__RequestConvertItem_x                      0x7598E0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7573E0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7581A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834C90

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E4D0

// CLabel 
#define CLabel__Draw_x                                             0x763EE0

// CListWnd
#define CListWnd__CListWnd_x                                       0x913DC0
#define CListWnd__dCListWnd_x                                      0x9140E0
#define CListWnd__AddColumn_x                                      0x918520
#define CListWnd__AddColumn1_x                                     0x918570
#define CListWnd__AddLine_x                                        0x918900
#define CListWnd__AddString_x                                      0x918700
#define CListWnd__CalculateFirstVisibleLine_x                      0x9182E0
#define CListWnd__CalculateVSBRange_x                              0x9180C0
#define CListWnd__ClearSel_x                                       0x9190E0
#define CListWnd__ClearAllSel_x                                    0x919140
#define CListWnd__CloseAndUpdateEditWindow_x                       0x919B40
#define CListWnd__Compare_x                                        0x917A00
#define CListWnd__Draw_x                                           0x914210
#define CListWnd__DrawColumnSeparators_x                           0x9169D0
#define CListWnd__DrawHeader_x                                     0x916E40
#define CListWnd__DrawItem_x                                       0x917340
#define CListWnd__DrawLine_x                                       0x916B40
#define CListWnd__DrawSeparator_x                                  0x916A70
#define CListWnd__EnableLine_x                                     0x9162C0
#define CListWnd__EnsureVisible_x                                  0x919A70
#define CListWnd__ExtendSel_x                                      0x919010
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
#define CListWnd__GetSelList_x                                     0x919190
#define CListWnd__GetSeparatorRect_x                               0x9167E0
#define CListWnd__InsertLine_x                                     0x918CF0
#define CListWnd__RemoveLine_x                                     0x918E40
#define CListWnd__SetColors_x                                      0x9180A0
#define CListWnd__SetColumnJustification_x                         0x917DD0
#define CListWnd__SetColumnLabel_x                                 0x9186A0
#define CListWnd__SetColumnWidth_x                                 0x917CF0
#define CListWnd__SetCurSel_x                                      0x918F50
#define CListWnd__SetItemColor_x                                   0x919730
#define CListWnd__SetItemData_x                                    0x9196F0
#define CListWnd__SetItemText_x                                    0x919300
#define CListWnd__ShiftColumnSeparator_x                           0x917E90
#define CListWnd__Sort_x                                           0x917B80
#define CListWnd__ToggleSel_x                                      0x918F80
#define CListWnd__SetColumnsSizable_x                              0x917F40
#define CListWnd__SetItemWnd_x                                     0x9195B0
#define CListWnd__GetItemWnd_x                                     0x915960
#define CListWnd__SetItemIcon_x                                    0x919380
#define CListWnd__CalculateCustomWindowPositions_x                 0x9183E0
#define CListWnd__SetVScrollPos_x                                  0x917CD0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779670
#define CMapViewWnd__GetWorldCoordinates_x                         0x777D80
#define CMapViewWnd__HandleLButtonDown_x                           0x774DC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799A20
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A300
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79A830
#define CMerchantWnd__SelectRecoverySlot_x                         0x79D7F0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x798590
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A33B0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799640

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89DE50
#define CPacketScrambler__hton_x                                   0x89DE40

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x932AE0
#define CSidlManager__FindScreenPieceTemplate_x                    0x932EF0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x932CE0
#define CSidlManager__CreateLabel_x                                0x7FB560
#define CSidlManager__CreateXWndFromTemplate_x                     0x935E50
#define CSidlManager__CreateXWndFromTemplate1_x                    0x936020
#define CSidlManager__CreateXWnd_x                                 0x7FB490
#define CSidlManager__CreateHotButtonWnd_x                         0x7FBA50

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92F5D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92F4D0
#define CSidlScreenWnd__ConvertToRes_x                             0x958780
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92EFC0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92ECB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92ED80
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92EE50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92FA70
#define CSidlScreenWnd__EnableIniStorage_x                         0x92FF40
#define CSidlScreenWnd__GetSidlPiece_x                             0x92FC60
#define CSidlScreenWnd__Init1_x                                    0x92E8B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x92FF90
#define CSidlScreenWnd__LoadIniListWnd_x                           0x930AC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92DCD0
#define CSidlScreenWnd__StoreIniInfo_x                             0x930640
#define CSidlScreenWnd__StoreIniVis_x                              0x9309A0
#define CSidlScreenWnd__WndNotification_x                          0x92F980
#define CSidlScreenWnd__GetChildItem_x                             0x92FEC0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91F8E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D8188

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x698740
#define CSkillMgr__GetSkillCap_x                                   0x698920
#define CSkillMgr__GetNameToken_x                                  0x697EC0
#define CSkillMgr__IsActivatedSkill_x                              0x698000
#define CSkillMgr__IsCombatSkill_x                                 0x697F40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93F8A0
#define CSliderWnd__SetValue_x                                     0x93F710
#define CSliderWnd__SetNumTicks_x                                  0x93F770

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801600

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x948160
#define CStmlWnd__ParseSTML_x                                      0x949470
#define CStmlWnd__CalculateHSBRange_x                              0x949240
#define CStmlWnd__CalculateVSBRange_x                              0x9491B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94D580
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94E210
#define CStmlWnd__ForceParseNow_x                                  0x948700
#define CStmlWnd__GetNextTagPiece_x                                0x94D4E0
#define CStmlWnd__GetSTMLText_x                                    0x50CC00
#define CStmlWnd__GetVisibleText_x                                 0x948720
#define CStmlWnd__InitializeWindowVariables_x                      0x94E060
#define CStmlWnd__MakeStmlColorTag_x                               0x9477D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x947840
#define CStmlWnd__SetSTMLText_x                                    0x946880
#define CStmlWnd__StripFirstSTMLLines_x                            0x94F310
#define CStmlWnd__UpdateHistoryString_x                            0x94E420

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9459D0
#define CTabWnd__DrawCurrentPage_x                                 0x946100
#define CTabWnd__DrawTab_x                                         0x945E20
#define CTabWnd__GetCurrentPage_x                                  0x9451D0
#define CTabWnd__GetPageInnerRect_x                                0x945410
#define CTabWnd__GetTabInnerRect_x                                 0x945350
#define CTabWnd__GetTabRect_x                                      0x945200
#define CTabWnd__InsertPage_x                                      0x945620
#define CTabWnd__RemovePage_x                                      0x945790
#define CTabWnd__SetPage_x                                         0x945490
#define CTabWnd__SetPageRect_x                                     0x945910
#define CTabWnd__UpdatePage_x                                      0x945CE0
#define CTabWnd__GetPageFromTabIndex_x                             0x945D60
#define CTabWnd__GetCurrentTabIndex_x                              0x9451C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75E8E0
#define CPageWnd__SetTabText_x                                     0x944D20
#define CPageWnd__FlashTab_x                                       0x944D80

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9390

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91C830
#define CTextureFont__GetTextExtent_x                              0x91C9F0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC810
#define CHtmlComponentWnd__ValidateUri_x                           0x73CE20
#define CHtmlWnd__SetClientCallbacks_x                             0x6381A0
#define CHtmlWnd__AddObserver_x                                    0x6381C0
#define CHtmlWnd__RemoveObserver_x                                 0x638220
#define Window__getProgress_x                                      0x853660
#define Window__getStatus_x                                        0x853680
#define Window__getURI_x                                           0x853690

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x955590

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x909800

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9A00
#define CXStr__CXStr1_x                                            0x843DD0
#define CXStr__CXStr3_x                                            0x8F1270
#define CXStr__dCXStr_x                                            0x4784F0
#define CXStr__operator_equal_x                                    0x8F14A0
#define CXStr__operator_equal1_x                                   0x8F14E0
#define CXStr__operator_plus_equal1_x                              0x8F1F70
#define CXStr__SetString_x                                         0x8F3E60
#define CXStr__operator_char_p_x                                   0x8F19B0
#define CXStr__GetChar_x                                           0x8F37B0
#define CXStr__Delete_x                                            0x8F3060
#define CXStr__GetUnicode_x                                        0x8F3820
#define CXStr__GetLength_x                                         0x4A9140
#define CXStr__Mid_x                                               0x47D750
#define CXStr__Insert_x                                            0x8F3880
#define CXStr__FindNext_x                                          0x8F34D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93DB70
#define CXWnd__BringToTop_x                                        0x922FA0
#define CXWnd__Center_x                                            0x922B20
#define CXWnd__ClrFocus_x                                          0x922940
#define CXWnd__Destroy_x                                           0x9229E0
#define CXWnd__DoAllDrawing_x                                      0x91F0A0
#define CXWnd__DrawChildren_x                                      0x91F070
#define CXWnd__DrawColoredRect_x                                   0x91F4F0
#define CXWnd__DrawTooltip_x                                       0x91DBF0
#define CXWnd__DrawTooltipAtPoint_x                                0x91DCB0
#define CXWnd__GetBorderFrame_x                                    0x91F350
#define CXWnd__GetChildWndAt_x                                     0x923040
#define CXWnd__GetClientClipRect_x                                 0x921250
#define CXWnd__GetScreenClipRect_x                                 0x921320
#define CXWnd__GetScreenRect_x                                     0x9214F0
#define CXWnd__GetRelativeRect_x                                   0x9215C0
#define CXWnd__GetTooltipRect_x                                    0x91F540
#define CXWnd__GetWindowTextA_x                                    0x49D090
#define CXWnd__IsActive_x                                          0x91FC60
#define CXWnd__IsDescendantOf_x                                    0x921EF0
#define CXWnd__IsReallyVisible_x                                   0x921F20
#define CXWnd__IsType_x                                            0x9236B0
#define CXWnd__Move_x                                              0x921F90
#define CXWnd__Move1_x                                             0x922040
#define CXWnd__ProcessTransition_x                                 0x922AD0
#define CXWnd__Refade_x                                            0x922310
#define CXWnd__Resize_x                                            0x922570
#define CXWnd__Right_x                                             0x922D60
#define CXWnd__SetFocus_x                                          0x922900
#define CXWnd__SetFont_x                                           0x922970
#define CXWnd__SetKeyTooltip_x                                     0x9234D0
#define CXWnd__SetMouseOver_x                                      0x920460
#define CXWnd__StartFade_x                                         0x921DF0
#define CXWnd__GetChildItem_x                                      0x9231B0
#define CXWnd__SetParent_x                                         0x921CA0
#define CXWnd__Minimize_x                                          0x9225E0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x959800

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x925E90
#define CXWndManager__DrawWindows_x                                0x925EB0
#define CXWndManager__GetKeyboardFlags_x                           0x928590
#define CXWndManager__HandleKeyboardMsg_x                          0x928140
#define CXWndManager__RemoveWnd_x                                  0x9287C0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x928D10

// CDBStr
#define CDBStr__GetString_x                                        0x547070

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFED0
#define EQ_Character__Cur_HP_x                                     0x4D3120
#define EQ_Character__Cur_Mana_x                                   0x4DA870
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2F40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B38D0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3A20
#define EQ_Character__GetHPRegen_x                                 0x4E0770
#define EQ_Character__GetEnduranceRegen_x                          0x4E0D70
#define EQ_Character__GetManaRegen_x                               0x4E11B0
#define EQ_Character__Max_Endurance_x                              0x65EC90
#define EQ_Character__Max_HP_x                                     0x4D2F50
#define EQ_Character__Max_Mana_x                                   0x65EA90
#define EQ_Character__doCombatAbility_x                            0x661080
#define EQ_Character__UseSkill_x                                   0x4E2FC0
#define EQ_Character__GetConLevel_x                                0x657530
#define EQ_Character__IsExpansionFlag_x                            0x5BA970
#define EQ_Character__TotalEffect_x                                0x4C6CE0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3C90
#define EQ_Character__SpellDuration_x                              0x4C37C0
#define EQ_Character__MySpellDuration_x                            0x4B2200
#define EQ_Character__GetAdjustedSkill_x                           0x4D5EA0
#define EQ_Character__GetBaseSkill_x                               0x4D6E40
#define EQ_Character__CanUseItem_x                                 0x4DAB80

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BCE60

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x674FC0

//PcClient
#define PcClient__vftable_x                                        0xAF121C
#define PcClient__PcClient_x                                       0x654C90

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA910
#define CCharacterListWnd__EnterWorld_x                            0x4BA2E0
#define CCharacterListWnd__Quit_x                                  0x4BA030
#define CCharacterListWnd__UpdateList_x                            0x4BA4D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x639380
#define EQ_Item__CreateItemTagString_x                             0x897430
#define EQ_Item__IsStackable_x                                     0x89C0D0
#define EQ_Item__GetImageNum_x                                     0x898FC0
#define EQ_Item__CreateItemClient_x                                0x6385C0
#define EQ_Item__GetItemValue_x                                    0x89A2D0
#define EQ_Item__ValueSellMerchant_x                               0x89DA30
#define EQ_Item__IsKeyRingItem_x                                   0x89B9F0
#define EQ_Item__CanGoInBag_x                                      0x6394A0
#define EQ_Item__IsEmpty_x                                         0x89B530
#define EQ_Item__GetMaxItemCount_x                                 0x89A6E0
#define EQ_Item__GetHeldItem_x                                     0x898E90
#define EQ_Item__GetAugmentFitBySlot_x                             0x896C90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565B50
#define EQ_LoadingS__Array_x                                       0xC11130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65F590
#define EQ_PC__GetAlternateAbilityId_x                             0x8A69F0
#define EQ_PC__GetCombatAbility_x                                  0x8A7060
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A70D0
#define EQ_PC__GetItemRecastTimer_x                                0x661600
#define EQ_PC__HasLoreItem_x                                       0x657D40
#define EQ_PC__AlertInventoryChanged_x                             0x656E60
#define EQ_PC__GetPcZoneClient_x                                   0x683F90
#define EQ_PC__RemoveMyAffect_x                                    0x664830
#define EQ_PC__GetKeyRingItems_x                                   0x8A7960
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A76F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A7C60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C0E10
#define EQItemList__add_object_x                                   0x5EE490
#define EQItemList__add_item_x                                     0x5C1370
#define EQItemList__delete_item_x                                  0x5C13C0
#define EQItemList__FreeItemList_x                                 0x5C12C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543C00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6768C0
#define EQPlayer__dEQPlayer_x                                      0x669C40
#define EQPlayer__DoAttack_x                                       0x67E720
#define EQPlayer__EQPlayer_x                                       0x66A300
#define EQPlayer__SetNameSpriteState_x                             0x66E5D0
#define EQPlayer__SetNameSpriteTint_x                              0x66F4B0
#define PlayerBase__HasProperty_j_x                                0x988410
#define EQPlayer__IsTargetable_x                                   0x9888B0
#define EQPlayer__CanSee_x                                         0x988710
#define EQPlayer__CanSee1_x                                        0x9887E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9884D0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x681A20
#define PlayerZoneClient__GetLevel_x                               0x683FD0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EF600
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E860

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x679610
#define EQPlayerManager__GetSpawnByName_x                          0x6796C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x679750

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63CAC0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63CB40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63CB80
#define KeypressHandler__ClearCommandStateArray_x                  0x63DF70
#define KeypressHandler__HandleKeyDown_x                           0x63DF90
#define KeypressHandler__HandleKeyUp_x                             0x63E030
#define KeypressHandler__SaveKeymapping_x                          0x63E480

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7754E0
#define MapViewMap__SaveEx_x                                       0x7788A0
#define MapViewMap__SetZoom_x                                      0x77CF70

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BAE10

// StringTable 
#define StringTable__getString_x                                   0x8B5C70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6644A0
#define PcZoneClient__RemovePetEffect_x                            0x664AD0
#define PcZoneClient__HasAlternateAbility_x                        0x65E8C0
#define PcZoneClient__GetCurrentMod_x                              0x4E60D0
#define PcZoneClient__GetModCap_x                                  0x4E5FD0
#define PcZoneClient__CanEquipItem_x                               0x65EF70
#define PcZoneClient__GetItemByID_x                                0x661A70
#define PcZoneClient__GetItemByItemClass_x                         0x661BC0
#define PcZoneClient__RemoveBuffEffect_x                           0x664AF0
#define PcZoneClient__BandolierSwap_x                              0x65FB50
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6615A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F4180

//IconCache
#define IconCache__GetIcon_x                                       0x717270

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70EDB0
#define CContainerMgr__CloseContainer_x                            0x70F080
#define CContainerMgr__OpenExperimentContainer_x                   0x70FB00

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CDB40

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631520

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76B960
#define CLootWnd__RequestLootSlot_x                                0x76AC30

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D640
#define EQ_Spell__SpellAffects_x                                   0x58DAB0
#define EQ_Spell__SpellAffectBase_x                                0x58D870
#define EQ_Spell__IsStackable_x                                    0x4CAB90
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA9B0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7BD0
#define EQ_Spell__IsSPAStacking_x                                  0x58E900
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DE10
#define EQ_Spell__IsNoRemove_x                                     0x4CAB70
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E910
#define __IsResEffectSpell_x                                       0x4C9D30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD560

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5590

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8149C0
#define CTargetWnd__WndNotification_x                              0x814200
#define CTargetWnd__RefreshTargetBuffs_x                           0x8144D0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813360

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x819030
#define CTaskWnd__ConfirmAbandonTask_x                             0x81BC60

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x541610
#define CTaskManager__HandleMessage_x                              0x53FA60
#define CTaskManager__GetTaskStatus_x                              0x5416C0
#define CTaskManager__GetElementDescription_x                      0x541740

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x588760
#define EqSoundManager__PlayScriptMp3_x                            0x588A20
#define EqSoundManager__SoundAssistPlay_x                          0x69C620
#define EqSoundManager__WaveInstancePlay_x                         0x69BB90

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5329E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x944230
#define CTextureAnimation__Draw_x                                  0x944430

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x940200

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D720
#define CAltAbilityData__GetMercMaxRank_x                          0x56D6B0
#define CAltAbilityData__GetMaxRank_x                              0x5629D0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62F630

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA990
#define CharacterBase__CreateItemGlobalIndex_x                     0x519640
#define CharacterBase__CreateItemIndex_x                           0x637750
#define CharacterBase__GetItemPossession_x                         0x5056E0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CDBF0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CDC50
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5ED0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6700
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F67B0

//messages
#define msg_spell_worn_off_x                                       0x5B2870
#define msg_new_text_x                                             0x5A71D0
#define __msgTokenTextParam_x                                      0x5B4B00
#define msgTokenText_x                                             0x5B4D50

//SpellManager
#define SpellManager__vftable_x                                    0xAD959C
#define SpellManager__SpellManager_x                               0x69F950
#define Spellmanager__LoadTextSpells_x                             0x6A0240
#define SpellManager__GetSpellByGroupAndRank_x                     0x69FB20

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98C2D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519C90
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8CF0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x650420
#define ItemGlobalIndex__IsValidIndex_x                            0x519D20

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C5F30
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C61B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764220

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x713490
#define CCursorAttachment__AttachToCursor1_x                       0x7134D0
#define CCursorAttachment__Deactivate_x                            0x7144B0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x936E60
#define CSidlManagerBase__CreatePageWnd_x                          0x936660
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x932900
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x932890

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x954220
#define CEQSuiteTextureLoader__GetTexture_x                        0x953EE0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516C20
#define CFindItemWnd__WndNotification_x                            0x517700
#define CFindItemWnd__Update_x                                     0x518240
#define CFindItemWnd__PickupSelectedItem_x                         0x516450

//IString
#define IString__Append_x                                          0x506F00

//Camera
#define CDisplay__cameraType_x                                     0xDE8E1C
#define EverQuest__Cameras_x                                       0xEA408C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F5D0
#define LootFiltersManager__GetItemFilterData_x                    0x51EEE0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51EF10
#define LootFiltersManager__SetItemLootFilter_x                    0x51F130

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BB9D0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x991EC0
#define CResolutionHandler__GetWindowedStyle_x                     0x697260

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70BA80

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DB5F0
#define CDistillerInfo__Instance_x                                 0x8DB590

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A790
#define CGroupWnd__UpdateDisplay_x                                 0x729AF0

//ItemBase
#define ItemBase__IsLore_x                                         0x89BAA0
#define ItemBase__IsLoreEquipped_x                                 0x89BB10

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EE3F0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EE530
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EE590

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C720
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6900A0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D360

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F96A0
#define FactionManagerClient__HandleFactionMessage_x               0x4F9D10
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FA310
#define FactionManagerClient__GetMaxFaction_x                      0x4FA32F
#define FactionManagerClient__GetMinFaction_x                      0x4FA2E0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5056B0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91B7E0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C370

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x505910

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CBD0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A3180

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C720

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9150

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1260

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF41724

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF840
#define CAAWnd__UpdateSelected_x                                   0x6BC0B0
#define CAAWnd__Update_x                                           0x6BEB60

//CXRect
#define CXRect__operator_and_x                                     0x721880

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
