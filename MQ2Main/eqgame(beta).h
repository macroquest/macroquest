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
#define __ExpectedVersionDate                                     "Nov  8 2019"
#define __ExpectedVersionTime                                     "04:22:15"
#define __ActualVersionDate_x                                      0xB06184
#define __ActualVersionTime_x                                      0xB06178
#define __ActualVersionBuild_x                                     0xAF1E64

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62C3F0
#define __MemChecker1_x                                            0x8FEE20
#define __MemChecker2_x                                            0x6BA740
#define __MemChecker3_x                                            0x6BA690
#define __MemChecker4_x                                            0x8562C0
#define __EncryptPad0_x                                            0xC3C3E8
#define __EncryptPad1_x                                            0xC9A5A8
#define __EncryptPad2_x                                            0xC4CC80
#define __EncryptPad3_x                                            0xC4C880
#define __EncryptPad4_x                                            0xC8AC00
#define __EncryptPad5_x                                            0xF66228
#define __AC1_x                                                    0x812B76
#define __AC2_x                                                    0x5E625F
#define __AC3_x                                                    0x5ED95F
#define __AC4_x                                                    0x5F1930
#define __AC5_x                                                    0x5F7C3F
#define __AC6_x                                                    0x5FC256
#define __AC7_x                                                    0x5E5CD0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x193E7C

// Direct Input
#define DI8__Main_x                                                0xF66250
#define DI8__Keyboard_x                                            0xF66254
#define DI8__Mouse_x                                               0xF66234
#define DI8__Mouse_Copy_x                                          0xEBF434
#define DI8__Mouse_Check_x                                         0xF63D7C
#define __AutoSkillArray_x                                         0xEC034C
#define __Attack_x                                                 0xF5E173
#define __Autofire_x                                               0xF5E174
#define __BindList_x                                               0xC2AE20
#define g_eqCommandStates_x                                        0xC2BBA0
#define __Clicks_x                                                 0xEBF4EC
#define __CommandList_x                                            0xC2C760
#define __CurrentMapLabel_x                                        0xF76BF4
#define __CurrentSocial_x                                          0xC147CC
#define __DoAbilityList_x                                          0xEF5C94
#define __do_loot_x                                                0x5B2740
#define __DrawHandler_x                                            0x15F5F68
#define __GroupCount_x                                             0xEB1DEA
#define __Guilds_x                                                 0xEB5C40
#define __gWorld_x                                                 0xEB1C4C
#define __HWnd_x                                                   0xF66238
#define __heqmain_x                                                0xF66210
#define __InChatMode_x                                             0xEBF41C
#define __LastTell_x                                               0xEC1390
#define __LMouseHeldTime_x                                         0xEBF558
#define __Mouse_x                                                  0xF6623C
#define __MouseLook_x                                              0xEBF4B2
#define __MouseEventTime_x                                         0xF5EC54
#define __gpbCommandEvent_x                                        0xEAF6D8
#define __NetStatusToggle_x                                        0xEBF4B5
#define __PCNames_x                                                0xEC093C
#define __RangeAttackReady_x                                       0xEC0630
#define __RMouseHeldTime_x                                         0xEBF554
#define __RunWalkState_x                                           0xEBF420
#define __ScreenMode_x                                             0xDFD084
#define __ScreenX_x                                                0xEBF3D4
#define __ScreenY_x                                                0xEBF3D0
#define __ScreenXMax_x                                             0xEBF3D8
#define __ScreenYMax_x                                             0xEBF3DC
#define __ServerHost_x                                             0xEAF90B
#define __ServerName_x                                             0xEF5C54
#define __ShiftKeyDown_x                                           0xEBFAAC
#define __ShowNames_x                                              0xEC07EC
#define __Socials_x                                                0xEF5D54
#define __SubscriptionType_x                                       0xFBB0F8
#define __TargetAggroHolder_x                                      0xF795A8
#define __ZoneType_x                                               0xEBF8B0
#define __GroupAggro_x                                             0xF795E8
#define __LoginName_x                                              0xF669A4
#define __Inviter_x                                                0xF5E0F0
#define __AttackOnAssist_x                                         0xEC07A8
#define __UseTellWindows_x                                         0xEC0AD8
#define __gfMaxZoomCameraDistance_x                                0xAFBAE0
#define __gfMaxCameraDistance_x                                    0xB28034
#define __pulAutoRun_x                                             0xEBF4D0
#define __pulForward_x                                             0xEC0B10
#define __pulBackward_x                                            0xEC0B14
#define __pulTurnRight_x                                           0xEC0B18
#define __pulTurnLeft_x                                            0xEC0B1C
#define __pulStrafeLeft_x                                          0xEC0B20
#define __pulStrafeRight_x                                         0xEC0B24

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB1FE0
#define instEQZoneInfo_x                                           0xEBF6A8
#define pinstActiveBanker_x                                        0xEAF6F0
#define pinstActiveCorpse_x                                        0xEAF6E8
#define pinstActiveGMaster_x                                       0xEAF6EC
#define pinstActiveMerchant_x                                      0xEAF6E4
#define pinstAltAdvManager_x                                       0xDFE210
#define pinstBandageTarget_x                                       0xEAF700
#define pinstCamActor_x                                            0xDFD078
#define pinstCDBStr_x                                              0xDFCF2C
#define pinstCDisplay_x                                            0xEB1C34
#define pinstCEverQuest_x                                          0xF66268
#define pinstEverQuestInfo_x                                       0xEBF3C8
#define pinstCharData_x                                            0xEB1DCC
#define pinstCharSpawn_x                                           0xEAF7B8
#define pinstControlledMissile_x                                   0xEAFC24
#define pinstControlledPlayer_x                                    0xEAF7B8
#define pinstCResolutionHandler_x                                  0x15F6198
#define pinstCSidlManager_x                                        0x15F5130
#define pinstCXWndManager_x                                        0x15F512C
#define instDynamicZone_x                                          0xEB5B18
#define pinstDZMember_x                                            0xEB5C28
#define pinstDZTimerInfo_x                                         0xEB5C2C
#define pinstEqLogin_x                                             0xF662F0
#define instEQMisc_x                                               0xDFCE70
#define pinstEQSoundManager_x                                      0xDFF1E0
#define pinstEQSpellStrings_x                                      0xCBF8D8
#define instExpeditionLeader_x                                     0xEB5B62
#define instExpeditionName_x                                       0xEB5BA2
#define pinstGroup_x                                               0xEB1DE6
#define pinstImeManager_x                                          0x15F5128
#define pinstLocalPlayer_x                                         0xEAF6E0
#define pinstMercenaryData_x                                       0xF60744
#define pinstMercenaryStats_x                                      0xF796F4
#define pinstModelPlayer_x                                         0xEAF6F8
#define pinstPCData_x                                              0xEB1DCC
#define pinstSkillMgr_x                                            0xF628B0
#define pinstSpawnManager_x                                        0xF61358
#define pinstSpellManager_x                                        0xF62AD0
#define pinstSpellSets_x                                           0xF56D9C
#define pinstStringTable_x                                         0xEB1DD0
#define pinstSwitchManager_x                                       0xEAF580
#define pinstTarget_x                                              0xEAF734
#define pinstTargetObject_x                                        0xEAF7C0
#define pinstTargetSwitch_x                                        0xEAFC2C
#define pinstTaskMember_x                                          0xDFCD00
#define pinstTrackTarget_x                                         0xEAF7BC
#define pinstTradeTarget_x                                         0xEAF6F4
#define instTributeActive_x                                        0xDFCE91
#define pinstViewActor_x                                           0xDFD074
#define pinstWorldData_x                                           0xEAFC20
#define pinstZoneAddr_x                                            0xEBF948
#define pinstPlayerPath_x                                          0xF613F0
#define pinstTargetIndicator_x                                     0xF62D38
#define EQObject_Top_x                                             0xEAF6DC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDFD7F8
#define pinstCAchievementsWnd_x                                    0xDFD7E8
#define pinstCActionsWnd_x                                         0xDFD7B8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFD034
#define pinstCAdvancedLootWnd_x                                    0xDFCFE8
#define pinstCAdventureLeaderboardWnd_x                            0xF703C8
#define pinstCAdventureRequestWnd_x                                0xF70478
#define pinstCAdventureStatsWnd_x                                  0xF70528
#define pinstCAggroMeterWnd_x                                      0xDFD0E4
#define pinstCAlarmWnd_x                                           0xDFD85C
#define pinstCAlertHistoryWnd_x                                    0xDFD030
#define pinstCAlertStackWnd_x                                      0xDFD83C
#define pinstCAlertWnd_x                                           0xDFD858
#define pinstCAltStorageWnd_x                                      0xF70888
#define pinstCAudioTriggersWindow_x                                0xCB1C08
#define pinstCAuraWnd_x                                            0xDFD068
#define pinstCAvaZoneWnd_x                                         0xDFD00C
#define pinstCBandolierWnd_x                                       0xDFD0D0
#define pinstCBankWnd_x                                            0xDFD064
#define pinstCBarterMerchantWnd_x                                  0xF71AC8
#define pinstCBarterSearchWnd_x                                    0xF71B78
#define pinstCBarterWnd_x                                          0xF71C28
#define pinstCBazaarConfirmationWnd_x                              0xDFD814
#define pinstCBazaarSearchWnd_x                                    0xDFD590
#define pinstCBazaarWnd_x                                          0xDFD838
#define pinstCBlockedBuffWnd_x                                     0xDFD070
#define pinstCBlockedPetBuffWnd_x                                  0xDFD0C8
#define pinstCBodyTintWnd_x                                        0xDFD7CC
#define pinstCBookWnd_x                                            0xDFD568
#define pinstCBreathWnd_x                                          0xDFD810
#define pinstCBuffWindowNORMAL_x                                   0xDFD050
#define pinstCBuffWindowSHORT_x                                    0xDFD054
#define pinstCBugReportWnd_x                                       0xDFD05C
#define pinstCButtonWnd_x                                          0x15F5398
#define pinstCCastingWnd_x                                         0xDFD55C
#define pinstCCastSpellWnd_x                                       0xDFD80C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDFD844
#define pinstCChatWindowManager_x                                  0xF726E8
#define pinstCClaimWnd_x                                           0xF72840
#define pinstCColorPickerWnd_x                                     0xDFD7C0
#define pinstCCombatAbilityWnd_x                                   0xDFD854
#define pinstCCombatSkillsSelectWnd_x                              0xDFCFD4
#define pinstCCompassWnd_x                                         0xDFD7BC
#define pinstCConfirmationDialog_x                                 0xF77740
#define pinstCContainerMgr_x                                       0xDFD830
#define pinstCContextMenuManager_x                                 0x15F50E8
#define pinstCCursorAttachment_x                                   0xDFD150
#define pinstCDynamicZoneWnd_x                                     0xF72E08
#define pinstCEditLabelWnd_x                                       0xDFD040
#define pinstCEQMainWnd_x                                          0xF73050
#define pinstCEventCalendarWnd_x                                   0xDFD0CC
#define pinstCExtendedTargetWnd_x                                  0xDFD0B8
#define pinstCFacePick_x                                           0xDFCFDC
#define pinstCFactionWnd_x                                         0xDFD828
#define pinstCFellowshipWnd_x                                      0xF73250
#define pinstCFileSelectionWnd_x                                   0xDFD558
#define pinstCFindItemWnd_x                                        0xDFD81C
#define pinstCFindLocationWnd_x                                    0xF733A8
#define pinstCFriendsWnd_x                                         0xDFCFE4
#define pinstCGemsGameWnd_x                                        0xDFD824
#define pinstCGiveWnd_x                                            0xDFD860
#define pinstCGroupSearchFiltersWnd_x                              0xDFD560
#define pinstCGroupSearchWnd_x                                     0xF737A0
#define pinstCGroupWnd_x                                           0xF73850
#define pinstCGuildBankWnd_x                                       0xEC078C
#define pinstCGuildCreationWnd_x                                   0xF739B0
#define pinstCGuildMgmtWnd_x                                       0xF73A60
#define pinstCharacterCreation_x                                   0xDFCFD8
#define pinstCHelpWnd_x                                            0xDFD020
#define pinstCHeritageSelectionWnd_x                               0xDFCFEC
#define pinstCHotButtonWnd_x                                       0xF75BB8
#define pinstCHotButtonWnd1_x                                      0xF75BB8
#define pinstCHotButtonWnd2_x                                      0xF75BBC
#define pinstCHotButtonWnd3_x                                      0xF75BC0
#define pinstCHotButtonWnd4_x                                      0xF75BC4
#define pinstCIconSelectionWnd_x                                   0xDFD14C
#define pinstCInspectWnd_x                                         0xDFD01C
#define pinstCInventoryWnd_x                                       0xDFCFF0
#define pinstCInvSlotMgr_x                                         0xDFD7F0
#define pinstCItemDisplayManager_x                                 0xF76148
#define pinstCItemExpTransferWnd_x                                 0xF76278
#define pinstCItemOverflowWnd_x                                    0xDFD594
#define pinstCJournalCatWnd_x                                      0xDFD570
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDFD0BC
#define pinstCKeyRingWnd_x                                         0xDFD03C
#define pinstCLargeDialogWnd_x                                     0xF783C0
#define pinstCLayoutCopyWnd_x                                      0xF765C8
#define pinstCLFGuildWnd_x                                         0xF76678
#define pinstCLoadskinWnd_x                                        0xDFD834
#define pinstCLootFiltersCopyWnd_x                                 0xCCE208
#define pinstCLootFiltersWnd_x                                     0xDFD840
#define pinstCLootSettingsWnd_x                                    0xDFCFCC
#define pinstCLootWnd_x                                            0xDFD574
#define pinstCMailAddressBookWnd_x                                 0xDFD7FC
#define pinstCMailCompositionWnd_x                                 0xDFD7E0
#define pinstCMailIgnoreListWnd_x                                  0xDFD800
#define pinstCMailWnd_x                                            0xDFD7B4
#define pinstCManageLootWnd_x                                      0xDFE6C0
#define pinstCMapToolbarWnd_x                                      0xDFD024
#define pinstCMapViewWnd_x                                         0xDFD004
#define pinstCMarketplaceWnd_x                                     0xDFD850
#define pinstCMerchantWnd_x                                        0xDFD584
#define pinstCMIZoneSelectWnd_x                                    0xF76EB0
#define pinstCMusicPlayerWnd_x                                     0xDFD588
#define pinstCNameChangeMercWnd_x                                  0xDFD804
#define pinstCNameChangePetWnd_x                                   0xDFD7EC
#define pinstCNameChangeWnd_x                                      0xDFD818
#define pinstCNoteWnd_x                                            0xDFD010
#define pinstCObjectPreviewWnd_x                                   0xDFCFC8
#define pinstCOptionsWnd_x                                         0xDFD014
#define pinstCPetInfoWnd_x                                         0xDFD5A0
#define pinstCPetitionQWnd_x                                       0xDFD7C8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDFD7D0
#define pinstCPlayerWnd_x                                          0xDFD5A4
#define pinstCPopupWndManager_x                                    0xF77740
#define pinstCProgressionSelectionWnd_x                            0xF777F0
#define pinstCPurchaseGroupWnd_x                                   0xDFCFFC
#define pinstCPurchaseWnd_x                                        0xDFCFE0
#define pinstCPvPLeaderboardWnd_x                                  0xF778A0
#define pinstCPvPStatsWnd_x                                        0xF77950
#define pinstCQuantityWnd_x                                        0xDFD0C0
#define pinstCRaceChangeWnd_x                                      0xDFD82C
#define pinstCRaidOptionsWnd_x                                     0xDFD564
#define pinstCRaidWnd_x                                            0xDFD7E4
#define pinstCRealEstateItemsWnd_x                                 0xDFD7DC
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDFD56C
#define pinstCRealEstateManageWnd_x                                0xDFD008
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFD02C
#define pinstCRealEstatePlotSearchWnd_x                            0xDFD044
#define pinstCRealEstatePurchaseWnd_x                              0xDFD09C
#define pinstCRespawnWnd_x                                         0xDFD0B4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDFD808
#define pinstCSendMoneyWnd_x                                       0xDFCFD0
#define pinstCServerListWnd_x                                      0xDFD0C4
#define pinstCSkillsSelectWnd_x                                    0xDFD848
#define pinstCSkillsWnd_x                                          0xDFD820
#define pinstCSocialEditWnd_x                                      0xDFD038
#define pinstCSocialWnd_x                                          0xDFD7F4
#define pinstCSpellBookWnd_x                                       0xDFD84C
#define pinstCStoryWnd_x                                           0xDFD5AC
#define pinstCTargetOfTargetWnd_x                                  0xF79778
#define pinstCTargetWnd_x                                          0xDFD0B0
#define pinstCTaskOverlayWnd_x                                     0xDFCFF8
#define pinstCTaskSelectWnd_x                                      0xF798D0
#define pinstCTaskManager_x                                        0xCCEB48
#define pinstCTaskTemplateSelectWnd_x                              0xF79980
#define pinstCTaskWnd_x                                            0xF79A30
#define pinstCTextEntryWnd_x                                       0xDFD058
#define pinstCTimeLeftWnd_x                                        0xDFD598
#define pinstCTipWndCONTEXT_x                                      0xF79C34
#define pinstCTipWndOFDAY_x                                        0xF79C30
#define pinstCTitleWnd_x                                           0xF79CE0
#define pinstCTrackingWnd_x                                        0xDFCFF4
#define pinstCTradeskillWnd_x                                      0xF79E48
#define pinstCTradeWnd_x                                           0xDFD7D8
#define pinstCTrainWnd_x                                           0xDFD7D4
#define pinstCTributeBenefitWnd_x                                  0xF7A048
#define pinstCTributeMasterWnd_x                                   0xF7A0F8
#define pinstCTributeTrophyWnd_x                                   0xF7A1A8
#define pinstCVideoModesWnd_x                                      0xDFD59C
#define pinstCVoiceMacroWnd_x                                      0xF634A0
#define pinstCVoteResultsWnd_x                                     0xDFD7C4
#define pinstCVoteWnd_x                                            0xDFD7B0
#define pinstCWebManager_x                                         0xF63B1C
#define pinstCZoneGuideWnd_x                                       0xDFD000
#define pinstCZonePathWnd_x                                        0xDFD018

#define pinstEQSuiteTextureLoader_x                                0xC9C080
#define pinstItemIconCache_x                                       0xF73008
#define pinstLootFiltersManager_x                                  0xCCE2B8
#define pinstRewardSelectionWnd_x                                  0xF78098

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5ADBA0
#define __CastRay2_x                                               0x5ADBF0
#define __ConvertItemTags_x                                        0x5C9730
#define __CleanItemTags_x                                          0x47D1B0
#define __DoesFileExist_x                                          0x901EB0
#define __EQGetTime_x                                              0x8FE8F0
#define __ExecuteCmd_x                                             0x5A6450
#define __FixHeading_x                                             0x998CD0
#define __GameLoop_x                                               0x6B9930
#define __get_bearing_x                                            0x5AD710
#define __get_melee_range_x                                        0x5ADDE0
#define __GetAnimationCache_x                                      0x71EC40
#define __GetGaugeValueFromEQ_x                                    0x811020
#define __GetLabelFromEQ_x                                         0x812B00
#define __GetXTargetType_x                                         0x99A720
#define __HandleMouseWheel_x                                       0x6BA7F0
#define __HeadingDiff_x                                            0x998D40
#define __HelpPath_x                                               0xF5E844
#define __LoadFrontEnd_x                                           0x6B6C50
#define __NewUIINI_x                                               0x810CF0
#define __ProcessGameEvents_x                                      0x60DAA0
#define __ProcessMouseEvent_x                                      0x60D260
#define __SaveColors_x                                             0x550AC0
#define __STMLToText_x                                             0x93BED0
#define __ToggleKeyRingItem_x                                      0x5141E0
#define CMemoryMappedFile__SetFile_x                               0xA87FF0
#define CrashDetected_x                                            0x6B86F0
#define DrawNetStatus_x                                            0x6394E0
#define Expansion_HoT_x                                            0xEC0794
#define Teleport_Table_Size_x                                      0xEAF7C8
#define Teleport_Table_x                                           0xEAFC30
#define Util__FastTime_x                                           0x8FE4C0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904B0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4993B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499180
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A40
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5586C0
#define AltAdvManager__IsAbilityReady_x                            0x5575F0
#define AltAdvManager__GetAAById_x                                 0x5577F0
#define AltAdvManager__CanTrainAbility_x                           0x557860
#define AltAdvManager__CanSeeAbility_x                             0x557BC0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA2F0
#define CharacterZoneClient__HasSkill_x                            0x4D51E0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6900
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE590
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAB90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9270
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9350
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9430
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3380
#define CharacterZoneClient__BardCastBard_x                        0x4C5EE0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAC60
#define CharacterZoneClient__GetEffect_x                           0x4BAAD0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C43D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C44A0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C44F0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4640
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4810
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2980
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7860
#define CharacterZoneClient__FindItemByRecord_x                    0x4D72E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E04F0
#define CBankWnd__WndNotification_x                                0x6E02D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EDD40

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61C220
#define CButtonWnd__CButtonWnd_x                                   0x9382A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70DE00
#define CChatManager__InitContextMenu_x                            0x706F50
#define CChatManager__FreeChatWindow_x                             0x70C940
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E87B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70DA80
#define CChatManager__CreateChatWindow_x                           0x70CF80

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E88C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94C8F0
#define CContextMenu__dCContextMenu_x                              0x94CB30
#define CContextMenu__AddMenuItem_x                                0x94CB40
#define CContextMenu__RemoveMenuItem_x                             0x94CE50
#define CContextMenu__RemoveAllMenuItems_x                         0x94CE70
#define CContextMenu__CheckMenuItem_x                              0x94CEF0
#define CContextMenu__SetMenuItem_x                                0x94CD70
#define CContextMenu__AddSeparator_x                               0x94CCD0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94D490
#define CContextMenuManager__RemoveMenu_x                          0x94D500
#define CContextMenuManager__PopupMenu_x                           0x94D5C0
#define CContextMenuManager__Flush_x                               0x94D430
#define CContextMenuManager__GetMenu_x                             0x49B5A0
#define CContextMenuManager__CreateDefaultMenu_x                   0x719470

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DA7C0
#define CChatService__GetFriendName_x                              0x8DA7D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70E670
#define CChatWindow__Clear_x                                       0x70F930
#define CChatWindow__WndNotification_x                             0x7100C0
#define CChatWindow__AddHistory_x                                  0x70F1F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x949D50
#define CComboWnd__Draw_x                                          0x949250
#define CComboWnd__GetCurChoice_x                                  0x949B90
#define CComboWnd__GetListRect_x                                   0x949700
#define CComboWnd__GetTextRect_x                                   0x949DC0
#define CComboWnd__InsertChoice_x                                  0x949890
#define CComboWnd__SetColors_x                                     0x949860
#define CComboWnd__SetChoice_x                                     0x949B60
#define CComboWnd__GetItemCount_x                                  0x949BA0
#define CComboWnd__GetCurChoiceText_x                              0x949BE0
#define CComboWnd__GetChoiceText_x                                 0x949BB0
#define CComboWnd__InsertChoiceAtIndex_x                           0x949920

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x716E50
#define CContainerWnd__vftable_x                                   0xB0F374
#define CContainerWnd__SetContainer_x                              0x7183B0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54B500
#define CDisplay__PreZoneMainUI_x                                  0x54B510
#define CDisplay__CleanGameUI_x                                    0x550880
#define CDisplay__GetClickedActor_x                                0x543820
#define CDisplay__GetUserDefinedColor_x                            0x53BEE0
#define CDisplay__GetWorldFilePath_x                               0x545290
#define CDisplay__is3dON_x                                         0x540480
#define CDisplay__ReloadUI_x                                       0x54A990
#define CDisplay__WriteTextHD2_x                                   0x540270
#define CDisplay__TrueDistance_x                                   0x546F50
#define CDisplay__SetViewActor_x                                   0x543140
#define CDisplay__GetFloorHeight_x                                 0x540540
#define CDisplay__SetRenderWindow_x                                0x53EEA0
#define CDisplay__ToggleScreenshotMode_x                           0x542C10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96C800

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x94FE50
#define CEditWnd__GetCharIndexPt_x                                 0x950D70
#define CEditWnd__GetDisplayString_x                               0x950C20
#define CEditWnd__GetHorzOffset_x                                  0x94F4A0
#define CEditWnd__GetLineForPrintableChar_x                        0x951EE0
#define CEditWnd__GetSelStartPt_x                                  0x951020
#define CEditWnd__GetSTMLSafeText_x                                0x950A40
#define CEditWnd__PointFromPrintableChar_x                         0x951B20
#define CEditWnd__SelectableCharFromPoint_x                        0x951C90
#define CEditWnd__SetEditable_x                                    0x9510E0
#define CEditWnd__SetWindowTextA_x                                 0x9507C0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FB730
#define CEverQuest__ClickedPlayer_x                                0x5ED740
#define CEverQuest__CreateTargetIndicator_x                        0x60AD40
#define CEverQuest__DeleteTargetIndicator_x                        0x60ADD0
#define CEverQuest__DoTellWindow_x                                 0x4E89A0
#define CEverQuest__OutputTextToLog_x                              0x4E8C20
#define CEverQuest__DropHeldItemOnGround_x                         0x5E2780
#define CEverQuest__dsp_chat_x                                     0x4E8FB0
#define CEverQuest__trimName_x                                     0x607030
#define CEverQuest__Emote_x                                        0x5FBF90
#define CEverQuest__EnterZone_x                                    0x5F5F10
#define CEverQuest__GetBodyTypeDesc_x                              0x600900
#define CEverQuest__GetClassDesc_x                                 0x600F40
#define CEverQuest__GetClassThreeLetterCode_x                      0x601540
#define CEverQuest__GetDeityDesc_x                                 0x609680
#define CEverQuest__GetLangDesc_x                                  0x601700
#define CEverQuest__GetRaceDesc_x                                  0x600F20
#define CEverQuest__InterpretCmd_x                                 0x609C50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E6980
#define CEverQuest__LMouseUp_x                                     0x5E4D10
#define CEverQuest__RightClickedOnPlayer_x                         0x5E7260
#define CEverQuest__RMouseUp_x                                     0x5E5C90
#define CEverQuest__SetGameState_x                                 0x5E2510
#define CEverQuest__UPCNotificationFlush_x                         0x606F30
#define CEverQuest__IssuePetCommand_x                              0x602B00
#define CEverQuest__ReportSuccessfulHit_x                          0x5FD380

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x728C90
#define CGaugeWnd__CalcLinesFillRect_x                             0x728CF0
#define CGaugeWnd__Draw_x                                          0x728310

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF470
#define CGuild__GetGuildName_x                                     0x4AE550
#define CGuild__GetGuildIndex_x                                    0x4AE8E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7440F0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61C5E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x751080
#define CInvSlotMgr__MoveItem_x                                    0x74FDF0
#define CInvSlotMgr__SelectSlot_x                                  0x751150

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74E660
#define CInvSlot__SliderComplete_x                                 0x74C3D0
#define CInvSlot__GetItemBase_x                                    0x74BD60
#define CInvSlot__UpdateItem_x                                     0x74BED0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x752BB0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x751D50
#define CInvSlotWnd__HandleLButtonUp_x                             0x752730

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80C330
#define CItemDisplayWnd__UpdateStrings_x                           0x761140
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75AEB0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75B3C0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x761730
#define CItemDisplayWnd__AboutToShow_x                             0x760DA0
#define CItemDisplayWnd__WndNotification_x                         0x762800
#define CItemDisplayWnd__RequestConvertItem_x                      0x7622D0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75FE00
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x760BC0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x844F60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x766D10

// CLabel 
#define CLabel__Draw_x                                             0x76C7E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9224D0
#define CListWnd__dCListWnd_x                                      0x9227F0
#define CListWnd__AddColumn_x                                      0x926C40
#define CListWnd__AddColumn1_x                                     0x926C90
#define CListWnd__AddLine_x                                        0x927020
#define CListWnd__AddString_x                                      0x926E20
#define CListWnd__CalculateFirstVisibleLine_x                      0x926A00
#define CListWnd__CalculateVSBRange_x                              0x9267F0
#define CListWnd__ClearSel_x                                       0x927800
#define CListWnd__ClearAllSel_x                                    0x927860
#define CListWnd__CloseAndUpdateEditWindow_x                       0x928280
#define CListWnd__Compare_x                                        0x926130
#define CListWnd__Draw_x                                           0x922920
#define CListWnd__DrawColumnSeparators_x                           0x925100
#define CListWnd__DrawHeader_x                                     0x925570
#define CListWnd__DrawItem_x                                       0x925A70
#define CListWnd__DrawLine_x                                       0x925270
#define CListWnd__DrawSeparator_x                                  0x9251A0
#define CListWnd__EnableLine_x                                     0x9249E0
#define CListWnd__EnsureVisible_x                                  0x9281A0
#define CListWnd__ExtendSel_x                                      0x927730
#define CListWnd__GetColumnTooltip_x                               0x924520
#define CListWnd__GetColumnMinWidth_x                              0x924590
#define CListWnd__GetColumnWidth_x                                 0x924490
#define CListWnd__GetCurSel_x                                      0x923E20
#define CListWnd__GetItemAtPoint_x                                 0x924C60
#define CListWnd__GetItemAtPoint1_x                                0x924CD0
#define CListWnd__GetItemData_x                                    0x923EA0
#define CListWnd__GetItemHeight_x                                  0x924260
#define CListWnd__GetItemIcon_x                                    0x924030
#define CListWnd__GetItemRect_x                                    0x924AD0
#define CListWnd__GetItemText_x                                    0x923EE0
#define CListWnd__GetSelList_x                                     0x9278B0
#define CListWnd__GetSeparatorRect_x                               0x924F10
#define CListWnd__InsertLine_x                                     0x927410
#define CListWnd__RemoveLine_x                                     0x927560
#define CListWnd__SetColors_x                                      0x9267D0
#define CListWnd__SetColumnJustification_x                         0x926500
#define CListWnd__SetColumnWidth_x                                 0x926420
#define CListWnd__SetCurSel_x                                      0x927670
#define CListWnd__SetItemColor_x                                   0x927E50
#define CListWnd__SetItemData_x                                    0x927E10
#define CListWnd__SetItemText_x                                    0x927A20
#define CListWnd__ShiftColumnSeparator_x                           0x9265C0
#define CListWnd__Sort_x                                           0x9262B0
#define CListWnd__ToggleSel_x                                      0x9276A0
#define CListWnd__SetColumnsSizable_x                              0x926670
#define CListWnd__SetItemWnd_x                                     0x927CD0
#define CListWnd__GetItemWnd_x                                     0x924080
#define CListWnd__SetItemIcon_x                                    0x927AA0
#define CListWnd__CalculateCustomWindowPositions_x                 0x926B00
#define CListWnd__SetVScrollPos_x                                  0x926400

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x781F70
#define CMapViewWnd__GetWorldCoordinates_x                         0x780680
#define CMapViewWnd__HandleLButtonDown_x                           0x77D6C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A1FE0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A28C0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A2DF0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A5D70
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A0B60
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AB920
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A1C00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A80E0
#define CPacketScrambler__hton_x                                   0x8A80D0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9414F0
#define CSidlManager__FindScreenPieceTemplate_x                    0x941900
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9416F0
#define CSidlManager__CreateLabel_x                                0x803710
#define CSidlManager__CreateXWndFromTemplate_x                     0x944860
#define CSidlManager__CreateXWndFromTemplate1_x                    0x944A30
#define CSidlManager__CreateXWnd_x                                 0x803640
#define CSidlManager__CreateHotButtonWnd_x                         0x803C10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93DFE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93DEE0
#define CSidlScreenWnd__ConvertToRes_x                             0x9637F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93D970
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93D660
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93D730
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93D800
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93E470
#define CSidlScreenWnd__EnableIniStorage_x                         0x93E940
#define CSidlScreenWnd__GetSidlPiece_x                             0x93E660
#define CSidlScreenWnd__Init1_x                                    0x93D260
#define CSidlScreenWnd__LoadIniInfo_x                              0x93E990
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93F4D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93C680
#define CSidlScreenWnd__StoreIniInfo_x                             0x93F050
#define CSidlScreenWnd__StoreIniVis_x                              0x93F3B0
#define CSidlScreenWnd__WndNotification_x                          0x93E380
#define CSidlScreenWnd__GetChildItem_x                             0x93E8C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92E0F0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F4FB8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x680940
#define CSkillMgr__GetSkillCap_x                                   0x680B20
#define CSkillMgr__GetNameToken_x                                  0x6800C0
#define CSkillMgr__IsActivatedSkill_x                              0x680200
#define CSkillMgr__IsCombatSkill_x                                 0x680140

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94E280
#define CSliderWnd__SetValue_x                                     0x94E0F0
#define CSliderWnd__SetNumTicks_x                                  0x94E150

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x809780

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x956A70
#define CStmlWnd__CalculateHSBRange_x                              0x957BA0
#define CStmlWnd__CalculateVSBRange_x                              0x957B10
#define CStmlWnd__CanBreakAtCharacter_x                            0x95BED0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95CB60
#define CStmlWnd__ForceParseNow_x                                  0x957060
#define CStmlWnd__GetNextTagPiece_x                                0x95BE30
#define CStmlWnd__GetSTMLText_x                                    0x503C50
#define CStmlWnd__GetVisibleText_x                                 0x957080
#define CStmlWnd__InitializeWindowVariables_x                      0x95C9B0
#define CStmlWnd__MakeStmlColorTag_x                               0x9560E0
#define CStmlWnd__MakeWndNotificationTag_x                         0x956150
#define CStmlWnd__SetSTMLText_x                                    0x955190
#define CStmlWnd__StripFirstSTMLLines_x                            0x95DC60
#define CStmlWnd__UpdateHistoryString_x                            0x95CD70

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9542B0
#define CTabWnd__DrawCurrentPage_x                                 0x9549E0
#define CTabWnd__DrawTab_x                                         0x954700
#define CTabWnd__GetCurrentPage_x                                  0x953AB0
#define CTabWnd__GetPageInnerRect_x                                0x953CF0
#define CTabWnd__GetTabInnerRect_x                                 0x953C30
#define CTabWnd__GetTabRect_x                                      0x953AE0
#define CTabWnd__InsertPage_x                                      0x953F00
#define CTabWnd__SetPage_x                                         0x953D70
#define CTabWnd__SetPageRect_x                                     0x9541F0
#define CTabWnd__UpdatePage_x                                      0x9545C0
#define CTabWnd__GetPageFromTabIndex_x                             0x954640
#define CTabWnd__GetCurrentTabIndex_x                              0x953AA0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x767170
#define CPageWnd__SetTabText_x                                     0x9535F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9160

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92AF70
#define CTextureFont__GetTextExtent_x                              0x92B130

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B3B00
#define CHtmlComponentWnd__ValidateUri_x                           0x745AE0
#define CHtmlWnd__SetClientCallbacks_x                             0x621640
#define CHtmlWnd__AddObserver_x                                    0x621660
#define CHtmlWnd__RemoveObserver_x                                 0x6216C0
#define Window__getProgress_x                                      0x85D8F0
#define Window__getStatus_x                                        0x85D910
#define Window__getURI_x                                           0x85D920

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x969290

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x918100

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E85F0
#define CXStr__CXStr1_x                                            0x4FED10
#define CXStr__CXStr3_x                                            0x8FAA30
#define CXStr__dCXStr_x                                            0x478830
#define CXStr__operator_equal_x                                    0x8FAC60
#define CXStr__operator_equal1_x                                   0x8FACA0
#define CXStr__operator_plus_equal1_x                              0x8FB730
#define CXStr__SetString_x                                         0x8FD620
#define CXStr__operator_char_p_x                                   0x8FB1A0
#define CXStr__GetChar_x                                           0x8FCF50
#define CXStr__Delete_x                                            0x8FC820
#define CXStr__GetUnicode_x                                        0x8FCFC0
#define CXStr__GetLength_x                                         0x4A8F10
#define CXStr__Mid_x                                               0x47D560
#define CXStr__Insert_x                                            0x8FD020
#define CXStr__FindNext_x                                          0x8FCC90

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94C510
#define CXWnd__BringToTop_x                                        0x9317E0
#define CXWnd__Center_x                                            0x931360
#define CXWnd__ClrFocus_x                                          0x931180
#define CXWnd__Destroy_x                                           0x931220
#define CXWnd__DoAllDrawing_x                                      0x92D880
#define CXWnd__DrawChildren_x                                      0x92D850
#define CXWnd__DrawColoredRect_x                                   0x92DCE0
#define CXWnd__DrawTooltip_x                                       0x92C390
#define CXWnd__DrawTooltipAtPoint_x                                0x92C450
#define CXWnd__GetBorderFrame_x                                    0x92DB40
#define CXWnd__GetChildWndAt_x                                     0x931880
#define CXWnd__GetClientClipRect_x                                 0x92FA90
#define CXWnd__GetScreenClipRect_x                                 0x92FB40
#define CXWnd__GetScreenRect_x                                     0x92FCF0
#define CXWnd__GetTooltipRect_x                                    0x92DD30
#define CXWnd__GetWindowTextA_x                                    0x948BF0
#define CXWnd__IsActive_x                                          0x92E470
#define CXWnd__IsDescendantOf_x                                    0x9306C0
#define CXWnd__IsReallyVisible_x                                   0x9306F0
#define CXWnd__IsType_x                                            0x931EF0
#define CXWnd__Move_x                                              0x930750
#define CXWnd__Move1_x                                             0x930800
#define CXWnd__ProcessTransition_x                                 0x931310
#define CXWnd__Refade_x                                            0x930AE0
#define CXWnd__Resize_x                                            0x930DB0
#define CXWnd__Right_x                                             0x9315A0
#define CXWnd__SetFocus_x                                          0x931140
#define CXWnd__SetFont_x                                           0x9311B0
#define CXWnd__SetKeyTooltip_x                                     0x931D10
#define CXWnd__SetMouseOver_x                                      0x92EC70
#define CXWnd__StartFade_x                                         0x9305A0
#define CXWnd__GetChildItem_x                                      0x9319F0
#define CXWnd__SetParent_x                                         0x9304A0
#define CXWnd__Minimize_x                                          0x930E20

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x964870

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x934750
#define CXWndManager__DrawWindows_x                                0x934770
#define CXWndManager__GetKeyboardFlags_x                           0x936F30
#define CXWndManager__HandleKeyboardMsg_x                          0x936AE0
#define CXWndManager__RemoveWnd_x                                  0x937180
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9376C0

// CDBStr
#define CDBStr__GetString_x                                        0x53AE80

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBB70
#define EQ_Character__Cur_HP_x                                     0x4D2220
#define EQ_Character__Cur_Mana_x                                   0x4D9930
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEBE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B25C0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2710
#define EQ_Character__GetHPRegen_x                                 0x4DF6D0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFCD0
#define EQ_Character__GetManaRegen_x                               0x4E0110
#define EQ_Character__Max_Endurance_x                              0x647000
#define EQ_Character__Max_HP_x                                     0x4D2050
#define EQ_Character__Max_Mana_x                                   0x646E00
#define EQ_Character__doCombatAbility_x                            0x649450
#define EQ_Character__UseSkill_x                                   0x4E1EE0
#define EQ_Character__GetConLevel_x                                0x6403C0
#define EQ_Character__IsExpansionFlag_x                            0x5A4C30
#define EQ_Character__TotalEffect_x                                0x4C5620
#define EQ_Character__GetPCSpellAffect_x                           0x4BF930
#define EQ_Character__SpellDuration_x                              0x4BF460
#define EQ_Character__GetAdjustedSkill_x                           0x4D4FA0
#define EQ_Character__GetBaseSkill_x                               0x4D5F40
#define EQ_Character__CanUseItem_x                                 0x4D9C40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C75C0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65D590

//PcClient
#define PcClient__PcClient_x                                       0x63DB00

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B97B0
#define CCharacterListWnd__EnterWorld_x                            0x4B91F0
#define CCharacterListWnd__Quit_x                                  0x4B8F40
#define CCharacterListWnd__UpdateList_x                            0x4B9380

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x622880
#define EQ_Item__CreateItemTagString_x                             0x8A1980
#define EQ_Item__IsStackable_x                                     0x8A64A0
#define EQ_Item__GetImageNum_x                                     0x8A33A0
#define EQ_Item__CreateItemClient_x                                0x621A60
#define EQ_Item__GetItemValue_x                                    0x8A4690
#define EQ_Item__ValueSellMerchant_x                               0x8A7CB0
#define EQ_Item__IsKeyRingItem_x                                   0x8A5DA0
#define EQ_Item__CanGoInBag_x                                      0x6229A0
#define EQ_Item__IsEmpty_x                                         0x8A5900
#define EQ_Item__GetMaxItemCount_x                                 0x8A4AB0
#define EQ_Item__GetHeldItem_x                                     0x8A3270
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A1300

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5593E0
#define EQ_LoadingS__Array_x                                       0xC23B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x647960
#define EQ_PC__GetAlternateAbilityId_x                             0x8B0ED0
#define EQ_PC__GetCombatAbility_x                                  0x8B1540
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B15B0
#define EQ_PC__GetItemRecastTimer_x                                0x6499D0
#define EQ_PC__HasLoreItem_x                                       0x640B80
#define EQ_PC__AlertInventoryChanged_x                             0x63FD00
#define EQ_PC__GetPcZoneClient_x                                   0x66BFB0
#define EQ_PC__RemoveMyAffect_x                                    0x64CC10
#define EQ_PC__GetKeyRingItems_x                                   0x8B1E40
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B1BD0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B2140

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AB160
#define EQItemList__add_object_x                                   0x5D7FC0
#define EQItemList__add_item_x                                     0x5AB6C0
#define EQItemList__delete_item_x                                  0x5AB710
#define EQItemList__FreeItemList_x                                 0x5AB610

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x537990

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65EE10
#define EQPlayer__dEQPlayer_x                                      0x652180
#define EQPlayer__DoAttack_x                                       0x666C70
#define EQPlayer__EQPlayer_x                                       0x652840
#define EQPlayer__SetNameSpriteState_x                             0x656B00
#define EQPlayer__SetNameSpriteTint_x                              0x6579C0
#define PlayerBase__HasProperty_j_x                                0x9970C0
#define EQPlayer__IsTargetable_x                                   0x997560
#define EQPlayer__CanSee_x                                         0x9973C0
#define EQPlayer__CanSee1_x                                        0x997490
#define PlayerBase__GetVisibilityLineSegment_x                     0x997180

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x669A50
#define PlayerZoneClient__GetLevel_x                               0x66BFF0
#define PlayerZoneClient__IsValidTeleport_x                        0x5D9130
#define PlayerZoneClient__LegalPlayerRace_x                        0x5526B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x661B60
#define EQPlayerManager__GetSpawnByName_x                          0x661C10
#define EQPlayerManager__GetPlayerFromPartialName_x                0x661CA0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x625EC0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x625F40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x625F80
#define KeypressHandler__ClearCommandStateArray_x                  0x627390
#define KeypressHandler__HandleKeyDown_x                           0x6273B0
#define KeypressHandler__HandleKeyUp_x                             0x627450
#define KeypressHandler__SaveKeymapping_x                          0x6278A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77DDE0
#define MapViewMap__SaveEx_x                                       0x7811A0
#define MapViewMap__SetZoom_x                                      0x785860

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C54E0

// StringTable 
#define StringTable__getString_x                                   0x8C01C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64C880
#define PcZoneClient__RemovePetEffect_x                            0x64CEB0
#define PcZoneClient__HasAlternateAbility_x                        0x646C30
#define PcZoneClient__GetCurrentMod_x                              0x4E4F90
#define PcZoneClient__GetModCap_x                                  0x4E4E90
#define PcZoneClient__CanEquipItem_x                               0x647300
#define PcZoneClient__GetItemByID_x                                0x649E50
#define PcZoneClient__GetItemByItemClass_x                         0x649FA0
#define PcZoneClient__RemoveBuffEffect_x                           0x64CED0
#define PcZoneClient__BandolierSwap_x                              0x647F10
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x649970

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DDBE0

//IconCache
#define IconCache__GetIcon_x                                       0x71E4E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x715FF0
#define CContainerMgr__CloseContainer_x                            0x7162C0
#define CContainerMgr__OpenExperimentContainer_x                   0x716D40

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D5DA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61AA10

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7742B0
#define CLootWnd__RequestLootSlot_x                                0x7734E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x578DA0
#define EQ_Spell__SpellAffects_x                                   0x579210
#define EQ_Spell__SpellAffectBase_x                                0x578FD0
#define EQ_Spell__IsStackable_x                                    0x4C9C60
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9B40
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6A90
#define EQ_Spell__IsSPAStacking_x                                  0x57A060
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x579570
#define EQ_Spell__IsNoRemove_x                                     0x4C9C40
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57A070
#define __IsResEffectSpell_x                                       0x4C9040

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD1A0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CFB70

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81CB10
#define CTargetWnd__WndNotification_x                              0x81C3A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x81C670
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81B510

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x821100

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5353E0
#define CTaskManager__HandleMessage_x                              0x533860
#define CTaskManager__GetTaskStatus_x                              0x535490
#define CTaskManager__GetElementDescription_x                      0x535510

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x574300
#define EqSoundManager__PlayScriptMp3_x                            0x574460
#define EqSoundManager__SoundAssistPlay_x                          0x684910
#define EqSoundManager__WaveInstancePlay_x                         0x683E80

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x529120

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x952B00

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x560DC0
#define CAltAbilityData__GetMercMaxRank_x                          0x560D50
#define CAltAbilityData__GetMaxRank_x                              0x556470

//CTargetRing
#define CTargetRing__Cast_x                                        0x618B20

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9B20
#define CharacterBase__CreateItemGlobalIndex_x                     0x510850
#define CharacterBase__CreateItemIndex_x                           0x620BF0
#define CharacterBase__GetItemPossession_x                         0x4FC510
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D8160
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D81C0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FD1E0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FDA10
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FDAC0

//messages
#define msg_spell_worn_off_x                                       0x59CEF0
#define msg_new_text_x                                             0x591C90
#define __msgTokenTextParam_x                                      0x59F420
#define msgTokenText_x                                             0x59F670

//SpellManager
#define SpellManager__vftable_x                                    0xAE93D0
#define SpellManager__SpellManager_x                               0x687C30
#define Spellmanager__LoadTextSpells_x                             0x688520
#define SpellManager__GetSpellByGroupAndRank_x                     0x687E00

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99B010

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x510EA0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A31E0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x639340
#define ItemGlobalIndex__IsValidIndex_x                            0x510F00

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D0510
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D0790

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76CB20

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71A700
#define CCursorAttachment__AttachToCursor1_x                       0x71A740
#define CCursorAttachment__Deactivate_x                            0x71B720

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x945890
#define CSidlManagerBase__CreatePageWnd_x                          0x945080
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x941310
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9412A0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x962870
#define CEQSuiteTextureLoader__GetTexture_x                        0x962530

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50DDC0
#define CFindItemWnd__WndNotification_x                            0x50E8A0
#define CFindItemWnd__Update_x                                     0x50F410
#define CFindItemWnd__PickupSelectedItem_x                         0x50D600

//IString
#define IString__Append_x                                          0x4FDE20

//Camera
#define CDisplay__cameraType_x                                     0xDFD5A8
#define EverQuest__Cameras_x                                       0xEC0AE4

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x516570
#define LootFiltersManager__GetItemFilterData_x                    0x515E80
#define LootFiltersManager__RemoveItemLootFilter_x                 0x515EB0
#define LootFiltersManager__SetItemLootFilter_x                    0x5160D0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C3DB0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A0CE0
#define CResolutionHandler__GetWindowedStyle_x                     0x67F410

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x712DE0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E4EA0
#define CDistillerInfo__Instance_x                                 0x8E4E40

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x732EC0
#define CGroupWnd__UpdateDisplay_x                                 0x732220

//ItemBase
#define ItemBase__IsLore_x                                         0x8A5E50
#define ItemBase__IsLoreEquipped_x                                 0x8A5ED0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D7F20
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D8060
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D80C0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x674690
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x678020

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x5042A0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1FD0
#define FactionManagerClient__HandleFactionMessage_x               0x4F2640
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2C40
#define FactionManagerClient__GetMaxFaction_x                      0x4F2C5F
#define FactionManagerClient__GetMinFaction_x                      0x4F2C10

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FC4E0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x929F20

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BFA0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FC830

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x560280

//CTargetManager
#define CTargetManager__Get_x                                      0x68B480

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x674690

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8F20

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AB5B0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF5E178

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
