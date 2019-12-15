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
#define __ExpectedVersionDate                                     "Dec 15 2019"
#define __ExpectedVersionTime                                     "04:28:58"
#define __ActualVersionDate_x                                      0xB0B664
#define __ActualVersionTime_x                                      0xB0B658
#define __ActualVersionBuild_x                                     0xAF733C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x632160
#define __MemChecker1_x                                            0x9043E0
#define __MemChecker2_x                                            0x6C06A0
#define __MemChecker3_x                                            0x6C05F0
#define __MemChecker4_x                                            0x85AE80
#define __EncryptPad0_x                                            0xC413E8
#define __EncryptPad1_x                                            0xC9F5E8
#define __EncryptPad2_x                                            0xC51C80
#define __EncryptPad3_x                                            0xC51880
#define __EncryptPad4_x                                            0xC8FC00
#define __EncryptPad5_x                                            0xF6BCC8
#define __AC1_x                                                    0x817C36
#define __AC2_x                                                    0x5EBF9F
#define __AC3_x                                                    0x5F369F
#define __AC4_x                                                    0x5F7670
#define __AC5_x                                                    0x5FD97F
#define __AC6_x                                                    0x601F96
#define __AC7_x                                                    0x5EBA10
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19108C

// Direct Input
#define DI8__Main_x                                                0xF6BCF0
#define DI8__Keyboard_x                                            0xF6BCF4
#define DI8__Mouse_x                                               0xF6BCD4
#define DI8__Mouse_Copy_x                                          0xEC4424
#define DI8__Mouse_Check_x                                         0xF6981C
#define __AutoSkillArray_x                                         0xEC533C
#define __Attack_x                                                 0xF63163
#define __Autofire_x                                               0xF63164
#define __BindList_x                                               0xC2FE20
#define g_eqCommandStates_x                                        0xC30BA0
#define __Clicks_x                                                 0xEC44DC
#define __CommandList_x                                            0xC31760
#define __CurrentMapLabel_x                                        0xF7BC04
#define __CurrentSocial_x                                          0xC197C0
#define __DoAbilityList_x                                          0xEFAC84
#define __do_loot_x                                                0x5B7940
#define __DrawHandler_x                                            0x15FAF78
#define __GroupCount_x                                             0xEB46D2
#define __Guilds_x                                                 0xEBAC30
#define __gWorld_x                                                 0xEB4E18
#define __HWnd_x                                                   0xF6BCD8
#define __heqmain_x                                                0xF6BCB0
#define __InChatMode_x                                             0xEC440C
#define __LastTell_x                                               0xEC6380
#define __LMouseHeldTime_x                                         0xEC4548
#define __Mouse_x                                                  0xF6BCDC
#define __MouseLook_x                                              0xEC44A2
#define __MouseEventTime_x                                         0xF63C44
#define __gpbCommandEvent_x                                        0xEB48D0
#define __NetStatusToggle_x                                        0xEC44A5
#define __PCNames_x                                                0xEC592C
#define __RangeAttackReady_x                                       0xEC5620
#define __RMouseHeldTime_x                                         0xEC4544
#define __RunWalkState_x                                           0xEC4410
#define __ScreenMode_x                                             0xE02108
#define __ScreenX_x                                                0xEC43C4
#define __ScreenY_x                                                0xEC43C0
#define __ScreenXMax_x                                             0xEC43C8
#define __ScreenYMax_x                                             0xEC43CC
#define __ServerHost_x                                             0xEB4B03
#define __ServerName_x                                             0xEFAC44
#define __ShiftKeyDown_x                                           0xEC4A9C
#define __ShowNames_x                                              0xEC57DC
#define __Socials_x                                                0xEFAD44
#define __SubscriptionType_x                                       0xFC0108
#define __TargetAggroHolder_x                                      0xF7E5B8
#define __ZoneType_x                                               0xEC48A0
#define __GroupAggro_x                                             0xF7E5F8
#define __LoginName_x                                              0xF694AC
#define __Inviter_x                                                0xF630E0
#define __AttackOnAssist_x                                         0xEC5798
#define __UseTellWindows_x                                         0xEC5AC8
#define __gfMaxZoomCameraDistance_x                                0xB00FC8
#define __gfMaxCameraDistance_x                                    0xB2D374
#define __pulAutoRun_x                                             0xEC44C0
#define __pulForward_x                                             0xEC5B00
#define __pulBackward_x                                            0xEC5B04
#define __pulTurnRight_x                                           0xEC5B08
#define __pulTurnLeft_x                                            0xEC5B0C
#define __pulStrafeLeft_x                                          0xEC5B10
#define __pulStrafeRight_x                                         0xEC5B14

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB6FC8
#define instEQZoneInfo_x                                           0xEC4698
#define pinstActiveBanker_x                                        0xEB48E8
#define pinstActiveCorpse_x                                        0xEB48E0
#define pinstActiveGMaster_x                                       0xEB48E4
#define pinstActiveMerchant_x                                      0xEB48DC
#define pinstAltAdvManager_x                                       0xE03200
#define pinstBandageTarget_x                                       0xEB48F8
#define pinstCamActor_x                                            0xE020FC
#define pinstCDBStr_x                                              0xE01F1C
#define pinstCDisplay_x                                            0xEB6E94
#define pinstCEverQuest_x                                          0xF68D70
#define pinstEverQuestInfo_x                                       0xEC43B8
#define pinstCharData_x                                            0xEB6FC0
#define pinstCharSpawn_x                                           0xEB4930
#define pinstControlledMissile_x                                   0xEB4E14
#define pinstControlledPlayer_x                                    0xEB4930
#define pinstCResolutionHandler_x                                  0x15FB1A8
#define pinstCSidlManager_x                                        0x15FA140
#define pinstCXWndManager_x                                        0x15FA13C
#define instDynamicZone_x                                          0xEBAB08
#define pinstDZMember_x                                            0xEBAC18
#define pinstDZTimerInfo_x                                         0xEBAC1C
#define pinstEqLogin_x                                             0xF68DF8
#define instEQMisc_x                                               0xE01E60
#define pinstEQSoundManager_x                                      0xE041D0
#define pinstEQSpellStrings_x                                      0xCC4878
#define instExpeditionLeader_x                                     0xEBAB52
#define instExpeditionName_x                                       0xEBAB92
#define pinstGroup_x                                               0xEB46CE
#define pinstImeManager_x                                          0x15FA138
#define pinstLocalPlayer_x                                         0xEB48D8
#define pinstMercenaryData_x                                       0xF65734
#define pinstMercenaryStats_x                                      0xF7E704
#define pinstModelPlayer_x                                         0xEB48F0
#define pinstPCData_x                                              0xEB6FC0
#define pinstSkillMgr_x                                            0xF678A0
#define pinstSpawnManager_x                                        0xF66348
#define pinstSpellManager_x                                        0xF67AE0
#define pinstSpellSets_x                                           0xF5BD8C
#define pinstStringTable_x                                         0xEB46B8
#define pinstSwitchManager_x                                       0xEB4568
#define pinstTarget_x                                              0xEB492C
#define pinstTargetObject_x                                        0xEB49B8
#define pinstTargetSwitch_x                                        0xEB4E34
#define pinstTaskMember_x                                          0xE01CF0
#define pinstTrackTarget_x                                         0xEB4934
#define pinstTradeTarget_x                                         0xEB48EC
#define instTributeActive_x                                        0xE01E81
#define pinstViewActor_x                                           0xE020F8
#define pinstWorldData_x                                           0xEB48C8
#define pinstZoneAddr_x                                            0xEC4938
#define pinstPlayerPath_x                                          0xF663E0
#define pinstTargetIndicator_x                                     0xF67D48
#define EQObject_Top_x                                             0xEB48D4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE02848
#define pinstCAchievementsWnd_x                                    0xE02844
#define pinstCActionsWnd_x                                         0xE02608
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE02080
#define pinstCAdvancedLootWnd_x                                    0xE0203C
#define pinstCAdventureLeaderboardWnd_x                            0xF753D8
#define pinstCAdventureRequestWnd_x                                0xF75488
#define pinstCAdventureStatsWnd_x                                  0xF75538
#define pinstCAggroMeterWnd_x                                      0xE025A0
#define pinstCAlarmWnd_x                                           0xE0200C
#define pinstCAlertHistoryWnd_x                                    0xE020A0
#define pinstCAlertStackWnd_x                                      0xE02014
#define pinstCAlertWnd_x                                           0xE02024
#define pinstCAltStorageWnd_x                                      0xF75898
#define pinstCAudioTriggersWindow_x                                0xCB6BA8
#define pinstCAuraWnd_x                                            0xE020C4
#define pinstCAvaZoneWnd_x                                         0xE02058
#define pinstCBandolierWnd_x                                       0xE02134
#define pinstCBankWnd_x                                            0xE020C0
#define pinstCBarterMerchantWnd_x                                  0xF76AD8
#define pinstCBarterSearchWnd_x                                    0xF76B88
#define pinstCBarterWnd_x                                          0xF76C38
#define pinstCBazaarConfirmationWnd_x                              0xE01FD8
#define pinstCBazaarSearchWnd_x                                    0xE025E8
#define pinstCBazaarWnd_x                                          0xE01FF0
#define pinstCBlockedBuffWnd_x                                     0xE020C8
#define pinstCBlockedPetBuffWnd_x                                  0xE02120
#define pinstCBodyTintWnd_x                                        0xE02820
#define pinstCBookWnd_x                                            0xE025C4
#define pinstCBreathWnd_x                                          0xE01FC0
#define pinstCBuffWindowNORMAL_x                                   0xE020A4
#define pinstCBuffWindowSHORT_x                                    0xE020A8
#define pinstCBugReportWnd_x                                       0xE020B4
#define pinstCButtonWnd_x                                          0x15FA3A8
#define pinstCCastingWnd_x                                         0xE025B8
#define pinstCCastSpellWnd_x                                       0xE01FB8
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE02008
#define pinstCChatWindowManager_x                                  0xF776F8
#define pinstCClaimWnd_x                                           0xF77850
#define pinstCColorPickerWnd_x                                     0xE02614
#define pinstCCombatAbilityWnd_x                                   0xE02000
#define pinstCCombatSkillsSelectWnd_x                              0xE02028
#define pinstCCompassWnd_x                                         0xE02610
#define pinstCConfirmationDialog_x                                 0xF7C750
#define pinstCContainerMgr_x                                       0xE01FFC
#define pinstCContextMenuManager_x                                 0x15FA0F8
#define pinstCCursorAttachment_x                                   0xE025AC
#define pinstCDynamicZoneWnd_x                                     0xF77E18
#define pinstCEditLabelWnd_x                                       0xE0209C
#define pinstCEQMainWnd_x                                          0xF78060
#define pinstCEventCalendarWnd_x                                   0xE025B0
#define pinstCExtendedTargetWnd_x                                  0xE02114
#define pinstCFacePick_x                                           0xE02040
#define pinstCFactionWnd_x                                         0xE01FE8
#define pinstCFellowshipWnd_x                                      0xF78260
#define pinstCFileSelectionWnd_x                                   0xE025B4
#define pinstCFindItemWnd_x                                        0xE01FD4
#define pinstCFindLocationWnd_x                                    0xF783B8
#define pinstCFriendsWnd_x                                         0xE02038
#define pinstCGemsGameWnd_x                                        0xE01FE4
#define pinstCGiveWnd_x                                            0xE02010
#define pinstCGroupSearchFiltersWnd_x                              0xE025BC
#define pinstCGroupSearchWnd_x                                     0xF787B0
#define pinstCGroupWnd_x                                           0xF78860
#define pinstCGuildBankWnd_x                                       0xEC577C
#define pinstCGuildCreationWnd_x                                   0xF789C0
#define pinstCGuildMgmtWnd_x                                       0xF78A70
#define pinstCharacterCreation_x                                   0xE02030
#define pinstCHelpWnd_x                                            0xE02074
#define pinstCHeritageSelectionWnd_x                               0xE02050
#define pinstCHotButtonWnd_x                                       0xF7ABC8
#define pinstCHotButtonWnd1_x                                      0xF7ABC8
#define pinstCHotButtonWnd2_x                                      0xF7ABCC
#define pinstCHotButtonWnd3_x                                      0xF7ABD0
#define pinstCHotButtonWnd4_x                                      0xF7ABD4
#define pinstCIconSelectionWnd_x                                   0xE025A8
#define pinstCInspectWnd_x                                         0xE02070
#define pinstCInventoryWnd_x                                       0xE02044
#define pinstCInvSlotMgr_x                                         0xE01FBC
#define pinstCItemDisplayManager_x                                 0xF7B158
#define pinstCItemExpTransferWnd_x                                 0xF7B288
#define pinstCItemOverflowWnd_x                                    0xE025EC
#define pinstCJournalCatWnd_x                                      0xE025C8
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE02118
#define pinstCKeyRingWnd_x                                         0xE02090
#define pinstCLargeDialogWnd_x                                     0xF7D3D0
#define pinstCLayoutCopyWnd_x                                      0xF7B5D8
#define pinstCLFGuildWnd_x                                         0xF7B688
#define pinstCLoadskinWnd_x                                        0xE01FEC
#define pinstCLootFiltersCopyWnd_x                                 0xCD31F8
#define pinstCLootFiltersWnd_x                                     0xE02018
#define pinstCLootSettingsWnd_x                                    0xE02034
#define pinstCLootWnd_x                                            0xE025CC
#define pinstCMailAddressBookWnd_x                                 0xE01FC4
#define pinstCMailCompositionWnd_x                                 0xE0283C
#define pinstCMailIgnoreListWnd_x                                  0xE01FC8
#define pinstCMailWnd_x                                            0xE02818
#define pinstCManageLootWnd_x                                      0xE036B0
#define pinstCMapToolbarWnd_x                                      0xE0207C
#define pinstCMapViewWnd_x                                         0xE02054
#define pinstCMarketplaceWnd_x                                     0xE0201C
#define pinstCMerchantWnd_x                                        0xE025D0
#define pinstCMIZoneSelectWnd_x                                    0xF7BEC0
#define pinstCMusicPlayerWnd_x                                     0xE025D8
#define pinstCNameChangeMercWnd_x                                  0xE01FD0
#define pinstCNameChangePetWnd_x                                   0xE0284C
#define pinstCNameChangeWnd_x                                      0xE01FE0
#define pinstCNoteWnd_x                                            0xE0205C
#define pinstCObjectPreviewWnd_x                                   0xE0202C
#define pinstCOptionsWnd_x                                         0xE02060
#define pinstCPetInfoWnd_x                                         0xE025F0
#define pinstCPetitionQWnd_x                                       0xE02834
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE02824
#define pinstCPlayerWnd_x                                          0xE025FC
#define pinstCPopupWndManager_x                                    0xF7C750
#define pinstCProgressionSelectionWnd_x                            0xF7C800
#define pinstCPurchaseGroupWnd_x                                   0xE02068
#define pinstCPurchaseWnd_x                                        0xE02048
#define pinstCPvPLeaderboardWnd_x                                  0xF7C8B0
#define pinstCPvPStatsWnd_x                                        0xF7C960
#define pinstCQuantityWnd_x                                        0xE0211C
#define pinstCRaceChangeWnd_x                                      0xE02004
#define pinstCRaidOptionsWnd_x                                     0xE025C0
#define pinstCRaidWnd_x                                            0xE02830
#define pinstCRealEstateItemsWnd_x                                 0xE02840
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE025D4
#define pinstCRealEstateManageWnd_x                                0xE02078
#define pinstCRealEstateNeighborhoodWnd_x                          0xE02094
#define pinstCRealEstatePlotSearchWnd_x                            0xE020B8
#define pinstCRealEstatePurchaseWnd_x                              0xE020F4
#define pinstCRespawnWnd_x                                         0xE020F0
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE02850
#define pinstCSendMoneyWnd_x                                       0xE02020
#define pinstCServerListWnd_x                                      0xE0219C
#define pinstCSkillsSelectWnd_x                                    0xE01FF4
#define pinstCSkillsWnd_x                                          0xE01FDC
#define pinstCSocialEditWnd_x                                      0xE02088
#define pinstCSocialWnd_x                                          0xE01FCC
#define pinstCSpellBookWnd_x                                       0xE01FF8
#define pinstCStoryWnd_x                                           0xE025F8
#define pinstCTargetOfTargetWnd_x                                  0xF7E788
#define pinstCTargetWnd_x                                          0xE020EC
#define pinstCTaskOverlayWnd_x                                     0xE02064
#define pinstCTaskSelectWnd_x                                      0xF7E8E0
#define pinstCTaskManager_x                                        0xCD3B38
#define pinstCTaskTemplateSelectWnd_x                              0xF7E990
#define pinstCTaskWnd_x                                            0xF7EA40
#define pinstCTextEntryWnd_x                                       0xE020AC
#define pinstCTimeLeftWnd_x                                        0xE02600
#define pinstCTipWndCONTEXT_x                                      0xF7EC44
#define pinstCTipWndOFDAY_x                                        0xF7EC40
#define pinstCTitleWnd_x                                           0xF7ECF0
#define pinstCTrackingWnd_x                                        0xE0204C
#define pinstCTradeskillWnd_x                                      0xF7EE58
#define pinstCTradeWnd_x                                           0xE0282C
#define pinstCTrainWnd_x                                           0xE02828
#define pinstCTributeBenefitWnd_x                                  0xF7F058
#define pinstCTributeMasterWnd_x                                   0xF7F108
#define pinstCTributeTrophyWnd_x                                   0xF7F1B8
#define pinstCVideoModesWnd_x                                      0xE02604
#define pinstCVoiceMacroWnd_x                                      0xF684B0
#define pinstCVoteResultsWnd_x                                     0xE02838
#define pinstCVoteWnd_x                                            0xE0281C
#define pinstCWebManager_x                                         0xF68B2C
#define pinstCZoneGuideWnd_x                                       0xE0206C
#define pinstCZonePathWnd_x                                        0xE02084

#define pinstEQSuiteTextureLoader_x                                0xCA10C0
#define pinstItemIconCache_x                                       0xF78018
#define pinstLootFiltersManager_x                                  0xCD32A8
#define pinstRewardSelectionWnd_x                                  0xF7D0A8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B2DA0
#define __CastRay2_x                                               0x5B2DF0
#define __ConvertItemTags_x                                        0x5CE950
#define __CleanItemTags_x                                          0x47CFF0
#define __DoesFileExist_x                                          0x907470
#define __EQGetTime_x                                              0x903EB0
#define __ExecuteCmd_x                                             0x5AB5D0
#define __FixHeading_x                                             0x99E590
#define __GameLoop_x                                               0x6BF890
#define __get_bearing_x                                            0x5B2910
#define __get_melee_range_x                                        0x5B2FE0
#define __GetAnimationCache_x                                      0x724A80
#define __GetGaugeValueFromEQ_x                                    0x8160E0
#define __GetLabelFromEQ_x                                         0x817BC0
#define __GetXTargetType_x                                         0x99FF70
#define __HandleMouseWheel_x                                       0x6C0750
#define __HeadingDiff_x                                            0x99E600
#define __HelpPath_x                                               0xF63834
#define __LoadFrontEnd_x                                           0x6BCBB0
#define __NewUIINI_x                                               0x815DB0
#define __ProcessGameEvents_x                                      0x613760
#define __ProcessMouseEvent_x                                      0x612F20
#define __SaveColors_x                                             0x5538F0
#define __STMLToText_x                                             0x941A80
#define __ToggleKeyRingItem_x                                      0x516720
#define CMemoryMappedFile__SetFile_x                               0xA8D980
#define CrashDetected_x                                            0x6BE650
#define DrawNetStatus_x                                            0x63F570
#define Expansion_HoT_x                                            0xEC5784
#define Teleport_Table_Size_x                                      0xEB49C0
#define Teleport_Table_x                                           0xEB4E38
#define Util__FastTime_x                                           0x903A80

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490290
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4991A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F70
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493830
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55B3E0
#define AltAdvManager__IsAbilityReady_x                            0x55A310
#define AltAdvManager__GetAAById_x                                 0x55A510
#define AltAdvManager__CanTrainAbility_x                           0x55A580
#define AltAdvManager__CanSeeAbility_x                             0x55A8E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA160
#define CharacterZoneClient__HasSkill_x                            0x4D5050
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6770
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE430
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAA30
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9100
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D91E0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D92C0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3230
#define CharacterZoneClient__BardCastBard_x                        0x4C5D90
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB00
#define CharacterZoneClient__GetEffect_x                           0x4BA970
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4280
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4350
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C43A0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C44F0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C46C0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2870
#define CharacterZoneClient__FindItemByGuid_x                      0x4D76D0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7150

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E62C0
#define CBankWnd__WndNotification_x                                0x6E60A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F3AD0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x621F90
#define CButtonWnd__CButtonWnd_x                                   0x93DE40

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x713BF0
#define CChatManager__InitContextMenu_x                            0x70CD50
#define CChatManager__FreeChatWindow_x                             0x712730
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8650
#define CChatManager__SetLockedActiveChatWindow_x                  0x713870
#define CChatManager__CreateChatWindow_x                           0x712D70

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8760

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9523B0
#define CContextMenu__dCContextMenu_x                              0x9525E0
#define CContextMenu__AddMenuItem_x                                0x9525F0
#define CContextMenu__RemoveMenuItem_x                             0x9528F0
#define CContextMenu__RemoveAllMenuItems_x                         0x952910
#define CContextMenu__CheckMenuItem_x                              0x952990
#define CContextMenu__SetMenuItem_x                                0x952820
#define CContextMenu__AddSeparator_x                               0x952780

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x952F30
#define CContextMenuManager__RemoveMenu_x                          0x952FA0
#define CContextMenuManager__PopupMenu_x                           0x953060
#define CContextMenuManager__Flush_x                               0x952ED0
#define CContextMenuManager__GetMenu_x                             0x49B360
#define CContextMenuManager__CreateDefaultMenu_x                   0x71F250

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DF560
#define CChatService__GetFriendName_x                              0x8DF570

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x714460
#define CChatWindow__Clear_x                                       0x715720
#define CChatWindow__WndNotification_x                             0x715EB0
#define CChatWindow__AddHistory_x                                  0x714FE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94F830
#define CComboWnd__Draw_x                                          0x94ED30
#define CComboWnd__GetCurChoice_x                                  0x94F670
#define CComboWnd__GetListRect_x                                   0x94F1E0
#define CComboWnd__GetTextRect_x                                   0x94F890
#define CComboWnd__InsertChoice_x                                  0x94F370
#define CComboWnd__SetColors_x                                     0x94F340
#define CComboWnd__SetChoice_x                                     0x94F640
#define CComboWnd__GetItemCount_x                                  0x94F680
#define CComboWnd__GetCurChoiceText_x                              0x94F6C0
#define CComboWnd__GetChoiceText_x                                 0x94F690
#define CComboWnd__InsertChoiceAtIndex_x                           0x94F400

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71CC40
#define CContainerWnd__vftable_x                                   0xB1485C
#define CContainerWnd__SetContainer_x                              0x71E1A0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54E320
#define CDisplay__PreZoneMainUI_x                                  0x54E330
#define CDisplay__CleanGameUI_x                                    0x5536B0
#define CDisplay__GetClickedActor_x                                0x546640
#define CDisplay__GetUserDefinedColor_x                            0x53ED00
#define CDisplay__GetWorldFilePath_x                               0x5480B0
#define CDisplay__is3dON_x                                         0x5432A0
#define CDisplay__ReloadUI_x                                       0x54D7B0
#define CDisplay__WriteTextHD2_x                                   0x543090
#define CDisplay__TrueDistance_x                                   0x549D70
#define CDisplay__SetViewActor_x                                   0x545F60
#define CDisplay__GetFloorHeight_x                                 0x543360
#define CDisplay__SetRenderWindow_x                                0x541CC0
#define CDisplay__ToggleScreenshotMode_x                           0x545A30

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9721A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9558F0
#define CEditWnd__GetCharIndexPt_x                                 0x956810
#define CEditWnd__GetDisplayString_x                               0x9566B0
#define CEditWnd__GetHorzOffset_x                                  0x954F20
#define CEditWnd__GetLineForPrintableChar_x                        0x9579B0
#define CEditWnd__GetSelStartPt_x                                  0x956AC0
#define CEditWnd__GetSTMLSafeText_x                                0x9564D0
#define CEditWnd__PointFromPrintableChar_x                         0x9575E0
#define CEditWnd__SelectableCharFromPoint_x                        0x957750
#define CEditWnd__SetEditable_x                                    0x956B90
#define CEditWnd__SetWindowTextA_x                                 0x956250
#define CEditWnd__ReplaceSelection_x                               0x957250
#define CEditWnd__ReplaceSelection1_x                              0x9571D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x601470
#define CEverQuest__ClickedPlayer_x                                0x5F3480
#define CEverQuest__CreateTargetIndicator_x                        0x6109F0
#define CEverQuest__DeleteTargetIndicator_x                        0x610A80
#define CEverQuest__DoTellWindow_x                                 0x4E8840
#define CEverQuest__OutputTextToLog_x                              0x4E8AC0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E84C0
#define CEverQuest__dsp_chat_x                                     0x4E8E50
#define CEverQuest__trimName_x                                     0x60CCD0
#define CEverQuest__Emote_x                                        0x601CD0
#define CEverQuest__EnterZone_x                                    0x5FBC50
#define CEverQuest__GetBodyTypeDesc_x                              0x606590
#define CEverQuest__GetClassDesc_x                                 0x606BD0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6071D0
#define CEverQuest__GetDeityDesc_x                                 0x60F330
#define CEverQuest__GetLangDesc_x                                  0x607390
#define CEverQuest__GetRaceDesc_x                                  0x606BB0
#define CEverQuest__InterpretCmd_x                                 0x60F900
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EC6C0
#define CEverQuest__LMouseUp_x                                     0x5EAA50
#define CEverQuest__RightClickedOnPlayer_x                         0x5ECFA0
#define CEverQuest__RMouseUp_x                                     0x5EB9D0
#define CEverQuest__SetGameState_x                                 0x5E8250
#define CEverQuest__UPCNotificationFlush_x                         0x60CBD0
#define CEverQuest__IssuePetCommand_x                              0x608790
#define CEverQuest__ReportSuccessfulHit_x                          0x603020

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72EBF0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72EC50
#define CGaugeWnd__Draw_x                                          0x72E270

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF350
#define CGuild__GetGuildName_x                                     0x4AE430
#define CGuild__GetGuildIndex_x                                    0x4AE7C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x748E40

//CHotButton
#define CHotButton__SetButtonSize_x                                0x622350

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x755E70
#define CInvSlotMgr__MoveItem_x                                    0x754B80
#define CInvSlotMgr__SelectSlot_x                                  0x755F40

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x753400
#define CInvSlot__SliderComplete_x                                 0x751160
#define CInvSlot__GetItemBase_x                                    0x750AE0
#define CInvSlot__UpdateItem_x                                     0x750C50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7579C0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x756B60
#define CInvSlotWnd__HandleLButtonUp_x                             0x757540

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x811450
#define CItemDisplayWnd__UpdateStrings_x                           0x766150
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75FE40
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x760370
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x766750
#define CItemDisplayWnd__AboutToShow_x                             0x765DA0
#define CItemDisplayWnd__WndNotification_x                         0x767840
#define CItemDisplayWnd__RequestConvertItem_x                      0x767300
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x764E10
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x765BC0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x84A0A0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76BD40

// CLabel 
#define CLabel__Draw_x                                             0x771790

// CListWnd
#define CListWnd__CListWnd_x                                       0x9281C0
#define CListWnd__dCListWnd_x                                      0x9284E0
#define CListWnd__AddColumn_x                                      0x92C940
#define CListWnd__AddColumn1_x                                     0x92C990
#define CListWnd__AddLine_x                                        0x92CD20
#define CListWnd__AddString_x                                      0x92CB20
#define CListWnd__CalculateFirstVisibleLine_x                      0x92C700
#define CListWnd__CalculateVSBRange_x                              0x92C4F0
#define CListWnd__ClearSel_x                                       0x92D500
#define CListWnd__ClearAllSel_x                                    0x92D560
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92DF50
#define CListWnd__Compare_x                                        0x92BE20
#define CListWnd__Draw_x                                           0x928610
#define CListWnd__DrawColumnSeparators_x                           0x92ADF0
#define CListWnd__DrawHeader_x                                     0x92B260
#define CListWnd__DrawItem_x                                       0x92B760
#define CListWnd__DrawLine_x                                       0x92AF60
#define CListWnd__DrawSeparator_x                                  0x92AE90
#define CListWnd__EnableLine_x                                     0x92A6D0
#define CListWnd__EnsureVisible_x                                  0x92DE80
#define CListWnd__ExtendSel_x                                      0x92D430
#define CListWnd__GetColumnTooltip_x                               0x92A210
#define CListWnd__GetColumnMinWidth_x                              0x92A280
#define CListWnd__GetColumnWidth_x                                 0x92A180
#define CListWnd__GetCurSel_x                                      0x929B10
#define CListWnd__GetItemAtPoint_x                                 0x92A940
#define CListWnd__GetItemAtPoint1_x                                0x92A9B0
#define CListWnd__GetItemData_x                                    0x929B90
#define CListWnd__GetItemHeight_x                                  0x929F50
#define CListWnd__GetItemIcon_x                                    0x929D20
#define CListWnd__GetItemRect_x                                    0x92A7C0
#define CListWnd__GetItemText_x                                    0x929BD0
#define CListWnd__GetSelList_x                                     0x92D5B0
#define CListWnd__GetSeparatorRect_x                               0x92ABF0
#define CListWnd__InsertLine_x                                     0x92D110
#define CListWnd__RemoveLine_x                                     0x92D260
#define CListWnd__SetColors_x                                      0x92C4C0
#define CListWnd__SetColumnJustification_x                         0x92C1F0
#define CListWnd__SetColumnWidth_x                                 0x92C110
#define CListWnd__SetCurSel_x                                      0x92D370
#define CListWnd__SetItemColor_x                                   0x92DB40
#define CListWnd__SetItemData_x                                    0x92DB00
#define CListWnd__SetItemText_x                                    0x92D720
#define CListWnd__ShiftColumnSeparator_x                           0x92C2B0
#define CListWnd__Sort_x                                           0x92BFA0
#define CListWnd__ToggleSel_x                                      0x92D3A0
#define CListWnd__SetColumnsSizable_x                              0x92C360
#define CListWnd__SetItemWnd_x                                     0x92D9D0
#define CListWnd__GetItemWnd_x                                     0x929D70
#define CListWnd__SetItemIcon_x                                    0x92D7A0
#define CListWnd__CalculateCustomWindowPositions_x                 0x92C800
#define CListWnd__SetVScrollPos_x                                  0x92C0F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x786E30
#define CMapViewWnd__GetWorldCoordinates_x                         0x785540
#define CMapViewWnd__HandleLButtonDown_x                           0x782580

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A6EF0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A77D0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A7D00
#define CMerchantWnd__SelectRecoverySlot_x                         0x7AAC90
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A5A50
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B0850
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A6B00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AD180
#define CPacketScrambler__hton_x                                   0x8AD170

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x947080
#define CSidlManager__FindScreenPieceTemplate_x                    0x947490
#define CSidlManager__FindScreenPieceTemplate1_x                   0x947280
#define CSidlManager__CreateLabel_x                                0x8088D0
#define CSidlManager__CreateXWndFromTemplate_x                     0x94A3F0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x94A5C0
#define CSidlManager__CreateXWnd_x                                 0x808800
#define CSidlManager__CreateHotButtonWnd_x                         0x808DB0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x943B70
#define CSidlScreenWnd__CalculateVSBRange_x                        0x943A70
#define CSidlScreenWnd__ConvertToRes_x                             0x969190
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x943510
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x943200
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9432D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9433A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x944010
#define CSidlScreenWnd__EnableIniStorage_x                         0x9444E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x944200
#define CSidlScreenWnd__Init1_x                                    0x942E10
#define CSidlScreenWnd__LoadIniInfo_x                              0x944530
#define CSidlScreenWnd__LoadIniListWnd_x                           0x945060
#define CSidlScreenWnd__LoadSidlScreen_x                           0x942230
#define CSidlScreenWnd__StoreIniInfo_x                             0x944BE0
#define CSidlScreenWnd__StoreIniVis_x                              0x944F40
#define CSidlScreenWnd__WndNotification_x                          0x943F20
#define CSidlScreenWnd__GetChildItem_x                             0x944460
#define CSidlScreenWnd__HandleLButtonUp_x                          0x933D30
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F9FC8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x686BE0
#define CSkillMgr__GetSkillCap_x                                   0x686DC0
#define CSkillMgr__GetNameToken_x                                  0x686360
#define CSkillMgr__IsActivatedSkill_x                              0x6864A0
#define CSkillMgr__IsCombatSkill_x                                 0x6863E0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x953D00
#define CSliderWnd__SetValue_x                                     0x953B70
#define CSliderWnd__SetNumTicks_x                                  0x953BD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80E8F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95C4F0
#define CStmlWnd__CalculateHSBRange_x                              0x95D620
#define CStmlWnd__CalculateVSBRange_x                              0x95D590
#define CStmlWnd__CanBreakAtCharacter_x                            0x961950
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9625E0
#define CStmlWnd__ForceParseNow_x                                  0x95CAE0
#define CStmlWnd__GetNextTagPiece_x                                0x9618B0
#define CStmlWnd__GetSTMLText_x                                    0x505FD0
#define CStmlWnd__GetVisibleText_x                                 0x95CB00
#define CStmlWnd__InitializeWindowVariables_x                      0x962430
#define CStmlWnd__MakeStmlColorTag_x                               0x95BB60
#define CStmlWnd__MakeWndNotificationTag_x                         0x95BBD0
#define CStmlWnd__SetSTMLText_x                                    0x95AC10
#define CStmlWnd__StripFirstSTMLLines_x                            0x9636E0
#define CStmlWnd__UpdateHistoryString_x                            0x9627F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x959D60
#define CTabWnd__DrawCurrentPage_x                                 0x95A490
#define CTabWnd__DrawTab_x                                         0x95A1B0
#define CTabWnd__GetCurrentPage_x                                  0x959570
#define CTabWnd__GetPageInnerRect_x                                0x9597B0
#define CTabWnd__GetTabInnerRect_x                                 0x9596F0
#define CTabWnd__GetTabRect_x                                      0x9595A0
#define CTabWnd__InsertPage_x                                      0x9599C0
#define CTabWnd__SetPage_x                                         0x959830
#define CTabWnd__SetPageRect_x                                     0x959CA0
#define CTabWnd__UpdatePage_x                                      0x95A070
#define CTabWnd__GetPageFromTabIndex_x                             0x95A0F0
#define CTabWnd__GetCurrentTabIndex_x                              0x959560

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76C180
#define CPageWnd__SetTabText_x                                     0x9590C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8FC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x930C40
#define CTextureFont__GetTextExtent_x                              0x930E00

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B9A00
#define CHtmlComponentWnd__ValidateUri_x                           0x74A850
#define CHtmlWnd__SetClientCallbacks_x                             0x6273C0
#define CHtmlWnd__AddObserver_x                                    0x6273E0
#define CHtmlWnd__RemoveObserver_x                                 0x627440
#define Window__getProgress_x                                      0x862460
#define Window__getStatus_x                                        0x862480
#define Window__getURI_x                                           0x862490

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96EC30

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91DD60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8490
#define CXStr__CXStr1_x                                            0x4814D0
#define CXStr__CXStr3_x                                            0x8FFFF0
#define CXStr__dCXStr_x                                            0x478670
#define CXStr__operator_equal_x                                    0x900220
#define CXStr__operator_equal1_x                                   0x900260
#define CXStr__operator_plus_equal1_x                              0x900CF0
#define CXStr__SetString_x                                         0x902BE0
#define CXStr__operator_char_p_x                                   0x900760
#define CXStr__GetChar_x                                           0x902530
#define CXStr__Delete_x                                            0x901DE0
#define CXStr__GetUnicode_x                                        0x9025A0
#define CXStr__GetLength_x                                         0x4A8D70
#define CXStr__Mid_x                                               0x47D3A0
#define CXStr__Insert_x                                            0x902600
#define CXStr__FindNext_x                                          0x902250

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x951FD0
#define CXWnd__BringToTop_x                                        0x9374B0
#define CXWnd__Center_x                                            0x937030
#define CXWnd__ClrFocus_x                                          0x936E50
#define CXWnd__Destroy_x                                           0x936EF0
#define CXWnd__DoAllDrawing_x                                      0x9334E0
#define CXWnd__DrawChildren_x                                      0x9334B0
#define CXWnd__DrawColoredRect_x                                   0x933920
#define CXWnd__DrawTooltip_x                                       0x932020
#define CXWnd__DrawTooltipAtPoint_x                                0x9320E0
#define CXWnd__GetBorderFrame_x                                    0x933780
#define CXWnd__GetChildWndAt_x                                     0x937550
#define CXWnd__GetClientClipRect_x                                 0x935740
#define CXWnd__GetScreenClipRect_x                                 0x935810
#define CXWnd__GetScreenRect_x                                     0x9359D0
#define CXWnd__GetTooltipRect_x                                    0x933970
#define CXWnd__GetWindowTextA_x                                    0x49CAE0
#define CXWnd__IsActive_x                                          0x9340A0
#define CXWnd__IsDescendantOf_x                                    0x9363C0
#define CXWnd__IsReallyVisible_x                                   0x9363F0
#define CXWnd__IsType_x                                            0x937BA0
#define CXWnd__Move_x                                              0x936460
#define CXWnd__Move1_x                                             0x936510
#define CXWnd__ProcessTransition_x                                 0x936FE0
#define CXWnd__Refade_x                                            0x9367E0
#define CXWnd__Resize_x                                            0x936A60
#define CXWnd__Right_x                                             0x937270
#define CXWnd__SetFocus_x                                          0x936E10
#define CXWnd__SetFont_x                                           0x936E80
#define CXWnd__SetKeyTooltip_x                                     0x9379D0
#define CXWnd__SetMouseOver_x                                      0x9348C0
#define CXWnd__StartFade_x                                         0x9362A0
#define CXWnd__GetChildItem_x                                      0x9376B0
#define CXWnd__SetParent_x                                         0x936170
#define CXWnd__Minimize_x                                          0x936AD0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96A210

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x93A3F0
#define CXWndManager__DrawWindows_x                                0x93A410
#define CXWndManager__GetKeyboardFlags_x                           0x93CAF0
#define CXWndManager__HandleKeyboardMsg_x                          0x93C6B0
#define CXWndManager__RemoveWnd_x                                  0x93CD10
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93D280

// CDBStr
#define CDBStr__GetString_x                                        0x53DBD0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBA10
#define EQ_Character__Cur_HP_x                                     0x4D2090
#define EQ_Character__Cur_Mana_x                                   0x4D97C0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEA80
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B24B0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2600
#define EQ_Character__GetHPRegen_x                                 0x4DF560
#define EQ_Character__GetEnduranceRegen_x                          0x4DFB60
#define EQ_Character__GetManaRegen_x                               0x4DFFA0
#define EQ_Character__Max_Endurance_x                              0x64D340
#define EQ_Character__Max_HP_x                                     0x4D1EC0
#define EQ_Character__Max_Mana_x                                   0x64D140
#define EQ_Character__doCombatAbility_x                            0x64F7A0
#define EQ_Character__UseSkill_x                                   0x4E1D80
#define EQ_Character__GetConLevel_x                                0x6464E0
#define EQ_Character__IsExpansionFlag_x                            0x5A9DA0
#define EQ_Character__TotalEffect_x                                0x4C54D0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF7D0
#define EQ_Character__SpellDuration_x                              0x4BF300
#define EQ_Character__GetAdjustedSkill_x                           0x4D4E10
#define EQ_Character__GetBaseSkill_x                               0x4D5DB0
#define EQ_Character__CanUseItem_x                                 0x4D9AD0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CC3D0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x663860

//PcClient
#define PcClient__PcClient_x                                       0x643C20

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9680
#define CCharacterListWnd__EnterWorld_x                            0x4B90C0
#define CCharacterListWnd__Quit_x                                  0x4B8E10
#define CCharacterListWnd__UpdateList_x                            0x4B9250

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x628610
#define EQ_Item__CreateItemTagString_x                             0x8A69F0
#define EQ_Item__IsStackable_x                                     0x8AB550
#define EQ_Item__GetImageNum_x                                     0x8A8460
#define EQ_Item__CreateItemClient_x                                0x6277E0
#define EQ_Item__GetItemValue_x                                    0x8A9790
#define EQ_Item__ValueSellMerchant_x                               0x8ACD60
#define EQ_Item__IsKeyRingItem_x                                   0x8AAE70
#define EQ_Item__CanGoInBag_x                                      0x628730
#define EQ_Item__IsEmpty_x                                         0x8AA9C0
#define EQ_Item__GetMaxItemCount_x                                 0x8A9BA0
#define EQ_Item__GetHeldItem_x                                     0x8A8330
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A6380

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55C0B0
#define EQ_LoadingS__Array_x                                       0xC28B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64DCA0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B5FB0
#define EQ_PC__GetCombatAbility_x                                  0x8B6620
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B6690
#define EQ_PC__GetItemRecastTimer_x                                0x64FD20
#define EQ_PC__HasLoreItem_x                                       0x646CA0
#define EQ_PC__AlertInventoryChanged_x                             0x645E20
#define EQ_PC__GetPcZoneClient_x                                   0x672460
#define EQ_PC__RemoveMyAffect_x                                    0x652F50
#define EQ_PC__GetKeyRingItems_x                                   0x8B6F20
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B6CB0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B7220

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5B0300
#define EQItemList__add_object_x                                   0x5DDC70
#define EQItemList__add_item_x                                     0x5B0860
#define EQItemList__delete_item_x                                  0x5B08B0
#define EQItemList__FreeItemList_x                                 0x5B07B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A790

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6650E0
#define EQPlayer__dEQPlayer_x                                      0x658430
#define EQPlayer__DoAttack_x                                       0x66D0F0
#define EQPlayer__EQPlayer_x                                       0x658AF0
#define EQPlayer__SetNameSpriteState_x                             0x65CDC0
#define EQPlayer__SetNameSpriteTint_x                              0x65DC90
#define PlayerBase__HasProperty_j_x                                0x99C9A0
#define EQPlayer__IsTargetable_x                                   0x99CE40
#define EQPlayer__CanSee_x                                         0x99CCA0
#define EQPlayer__CanSee1_x                                        0x99CD70
#define PlayerBase__GetVisibilityLineSegment_x                     0x99CA60

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66FEF0
#define PlayerZoneClient__GetLevel_x                               0x6724A0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DEDE0
#define PlayerZoneClient__LegalPlayerRace_x                        0x5554E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x667FE0
#define EQPlayerManager__GetSpawnByName_x                          0x668090
#define EQPlayerManager__GetPlayerFromPartialName_x                0x668120

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62BC80
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62BD00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62BD40
#define KeypressHandler__ClearCommandStateArray_x                  0x62D150
#define KeypressHandler__HandleKeyDown_x                           0x62D170
#define KeypressHandler__HandleKeyUp_x                             0x62D210
#define KeypressHandler__SaveKeymapping_x                          0x62D660

// MapViewMap 
#define MapViewMap__Clear_x                                        0x782CA0
#define MapViewMap__SaveEx_x                                       0x786060
#define MapViewMap__SetZoom_x                                      0x78A720

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8CA2F0

// StringTable 
#define StringTable__getString_x                                   0x8C5210

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x652BC0
#define PcZoneClient__RemovePetEffect_x                            0x6531F0
#define PcZoneClient__HasAlternateAbility_x                        0x64CF70
#define PcZoneClient__GetCurrentMod_x                              0x4E4E40
#define PcZoneClient__GetModCap_x                                  0x4E4D40
#define PcZoneClient__CanEquipItem_x                               0x64D640
#define PcZoneClient__GetItemByID_x                                0x650190
#define PcZoneClient__GetItemByItemClass_x                         0x6502E0
#define PcZoneClient__RemoveBuffEffect_x                           0x653210
#define PcZoneClient__BandolierSwap_x                              0x64E260
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64FCC0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E3900

//IconCache
#define IconCache__GetIcon_x                                       0x724320

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71BDE0
#define CContainerMgr__CloseContainer_x                            0x71C0B0
#define CContainerMgr__OpenExperimentContainer_x                   0x71CB30

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DACF0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x620790

//CLootWnd
#define CLootWnd__LootAll_x                                        0x779260
#define CLootWnd__RequestLootSlot_x                                0x778490

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57CA10
#define EQ_Spell__SpellAffects_x                                   0x57CE80
#define EQ_Spell__SpellAffectBase_x                                0x57CC40
#define EQ_Spell__IsStackable_x                                    0x4C9AC0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C99A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B69A0
#define EQ_Spell__IsSPAStacking_x                                  0x57DCD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57D1E0
#define EQ_Spell__IsNoRemove_x                                     0x4C9AA0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57DCE0
#define __IsResEffectSpell_x                                       0x4C8F10

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACFF0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D4910

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x821BE0
#define CTargetWnd__WndNotification_x                              0x821470
#define CTargetWnd__RefreshTargetBuffs_x                           0x821740
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8205F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x826200

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x538180
#define CTaskManager__HandleMessage_x                              0x536600
#define CTaskManager__GetTaskStatus_x                              0x538230
#define CTaskManager__GetElementDescription_x                      0x5382B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x577B10
#define EqSoundManager__PlayScriptMp3_x                            0x577DD0
#define EqSoundManager__SoundAssistPlay_x                          0x68AAD0
#define EqSoundManager__WaveInstancePlay_x                         0x68A040

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52BA30

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9585D0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x563B80
#define CAltAbilityData__GetMercMaxRank_x                          0x563B10
#define CAltAbilityData__GetMaxRank_x                              0x559180

//CTargetRing
#define CTargetRing__Cast_x                                        0x61E8A0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9980
#define CharacterBase__CreateItemGlobalIndex_x                     0x512DC0
#define CharacterBase__CreateItemIndex_x                           0x626980
#define CharacterBase__GetItemPossession_x                         0x4FE9D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DCF20
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DCF80
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x702F70
#define CCastSpellWnd__IsBardSongPlaying_x                         0x7037A0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x703850

//messages
#define msg_spell_worn_off_x                                       0x5A2000
#define msg_new_text_x                                             0x596D90
#define __msgTokenTextParam_x                                      0x5A4530
#define msgTokenText_x                                             0x5A4780

//SpellManager
#define SpellManager__vftable_x                                    0xAEE674
#define SpellManager__SpellManager_x                               0x68DE00
#define Spellmanager__LoadTextSpells_x                             0x68E6F0
#define SpellManager__GetSpellByGroupAndRank_x                     0x68DFD0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A0860

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x513410
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A8300
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63F3D0
#define ItemGlobalIndex__IsValidIndex_x                            0x513470

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D52B0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D5530

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x771AD0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7204F0
#define CCursorAttachment__AttachToCursor1_x                       0x720530
#define CCursorAttachment__Deactivate_x                            0x721520

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94B3E0
#define CSidlManagerBase__CreatePageWnd_x                          0x94ABF0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x946EA0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x946E30

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9685D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x968290

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x510330
#define CFindItemWnd__WndNotification_x                            0x510E10
#define CFindItemWnd__Update_x                                     0x511950
#define CFindItemWnd__PickupSelectedItem_x                         0x50FB70

//IString
#define IString__Append_x                                          0x4F1410

//Camera
#define CDisplay__cameraType_x                                     0xE0260C
#define EverQuest__Cameras_x                                       0xEC5AD4

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x518AC0
#define LootFiltersManager__GetItemFilterData_x                    0x5183C0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5183F0
#define LootFiltersManager__SetItemLootFilter_x                    0x518610

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C8CC0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A6500
#define CResolutionHandler__GetWindowedStyle_x                     0x6856A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x718BB0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8EA680
#define CDistillerInfo__Instance_x                                 0x8EA620

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x737C10
#define CGroupWnd__UpdateDisplay_x                                 0x736F70

//ItemBase
#define ItemBase__IsLore_x                                         0x8AAF20
#define ItemBase__IsLoreEquipped_x                                 0x8AAF90

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DDBD0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DDD10
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DDD70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x67AB80
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67E4E0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x506640

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F32F0
#define FactionManagerClient__HandleFactionMessage_x               0x4F3960
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3F20
#define FactionManagerClient__GetMaxFaction_x                      0x4F3F3F
#define FactionManagerClient__GetMinFaction_x                      0x4F3EF0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FE9A0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92FBF0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BDF0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FEC50

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x563040

//CTargetManager
#define CTargetManager__Get_x                                      0x691630

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x67AB80

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D80

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5B0750

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF63168

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
