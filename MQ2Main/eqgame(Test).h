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
#define __ExpectedVersionDate                                     "Nov 19 2018"
#define __ExpectedVersionTime                                     "14:50:40"
#define __ActualVersionDate_x                                      0xAC16D4
#define __ActualVersionTime_x                                      0xAC16C8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x60A380
#define __MemChecker1_x                                            0x8DD500
#define __MemChecker2_x                                            0x699250
#define __MemChecker3_x                                            0x6991A0
#define __MemChecker4_x                                            0x834ED0
#define __EncryptPad0_x                                            0xBF34C0
#define __EncryptPad1_x                                            0xC51198
#define __EncryptPad2_x                                            0xC04048
#define __EncryptPad3_x                                            0xC03C48
#define __EncryptPad4_x                                            0xC41F30
#define __EncryptPad5_x                                            0x101824C
#define __AC1_x                                                    0x7F1B86
#define __AC2_x                                                    0x5C561F
#define __AC3_x                                                    0x5CC4AF
#define __AC4_x                                                    0x5D0320
#define __AC5_x                                                    0x5D64DF
#define __AC6_x                                                    0x5DAA16
#define __AC7_x                                                    0x5C5090
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EB972C

// Direct Input
#define DI8__Main_x                                                0xF0D008
#define DI8__Keyboard_x                                            0xF0D00C
#define DI8__Mouse_x                                               0xF0D010
#define DI8__Mouse_Copy_x                                          0xE6AD64
#define DI8__Mouse_Check_x                                         0xF0DED8
#define __AutoSkillArray_x                                         0xE6BC7C
#define __Attack_x                                                 0xF09A7F
#define __Autofire_x                                               0xF09A80
#define __BindList_x                                               0xBE20C0
#define g_eqCommandStates_x                                        0xBE2E30
#define __Clicks_x                                                 0xE6AE1C
#define __CommandList_x                                            0xBE39E8
#define __CurrentMapLabel_x                                        0x101F62C
#define __CurrentSocial_x                                          0xBCD728
#define __DoAbilityList_x                                          0xEA15A0
#define __do_loot_x                                                0x592D80
#define __DrawHandler_x                                            0x169AB60
#define __GroupCount_x                                             0xE5B5F2
#define __Guilds_x                                                 0xE61570
#define __gWorld_x                                                 0xE5B7E0
#define __HWnd_x                                                   0xF0D014
#define __heqmain_x                                                0x1018234
#define __InChatMode_x                                             0xE6AD4C
#define __LastTell_x                                               0xE6CC9C
#define __LMouseHeldTime_x                                         0xE6AE88
#define __Mouse_x                                                  0x1018258
#define __MouseLook_x                                              0xE6ADE2
#define __MouseEventTime_x                                         0xF0A538
#define __gpbCommandEvent_x                                        0xE5B020
#define __NetStatusToggle_x                                        0xE6ADE5
#define __PCNames_x                                                0xE6C25C
#define __RangeAttackReady_x                                       0xE6BF60
#define __RMouseHeldTime_x                                         0xE6AE84
#define __RunWalkState_x                                           0xE6AD50
#define __ScreenMode_x                                             0xDA90B8
#define __ScreenX_x                                                0xE6AD04
#define __ScreenY_x                                                0xE6AD00
#define __ScreenXMax_x                                             0xE6AD08
#define __ScreenYMax_x                                             0xE6AD0C
#define __ServerHost_x                                             0xE5B25B
#define __ServerName_x                                             0xEA1560
#define __ShiftKeyDown_x                                           0xE6B3DC
#define __ShowNames_x                                              0xE6C11C
#define __Socials_x                                                0xEA1660
#define __SubscriptionType_x                                       0x10610F4
#define __TargetAggroHolder_x                                      0x1021FE4
#define __ZoneType_x                                               0xE6B1E0
#define __GroupAggro_x                                             0x1022024
#define __LoginName_x                                              0xF0D86C
#define __Inviter_x                                                0xF099FC
#define __AttackOnAssist_x                                         0xE6C0D8
#define __UseTellWindows_x                                         0xE6C3F4
#define __gfMaxZoomCameraDistance_x                                0xAB6B00
#define __gfMaxCameraDistance_x                                    0xAE40CC
#define __pulAutoRun_x                                             0xE6AE00
#define __pulForward_x                                             0xE6C42C
#define __pulBackward_x                                            0xE6C430
#define __pulTurnRight_x                                           0xE6C434
#define __pulTurnLeft_x                                            0xE6C438
#define __pulStrafeLeft_x                                          0xE6C43C
#define __pulStrafeRight_x                                         0xE6C440

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5D908
#define instEQZoneInfo_x                                           0xE6AFD8
#define instKeypressHandler_x                                      0xF0A4E8
#define pinstActiveBanker_x                                        0xE5B154
#define pinstActiveCorpse_x                                        0xE5B14C
#define pinstActiveGMaster_x                                       0xE5B150
#define pinstActiveMerchant_x                                      0xE5B148
#define pinstAggroInfo_x                                           0xC679B8
#define pinstAltAdvManager_x                                       0xDAA2B0
#define pinstAuraMgr_x                                             0xC786A0
#define pinstBandageTarget_x                                       0xE5B574
#define pinstCamActor_x                                            0xDA90AC
#define pinstCDBStr_x                                              0xDA8FEC
#define pinstCDisplay_x                                            0xE5B5B8
#define pinstCEverQuest_x                                          0xF0D130
#define pinstEverQuestInfo_x                                       0xE6ACF8
#define pinstCharData_x                                            0xE5B5C0
#define pinstCharSpawn_x                                           0xE5B5AC
#define pinstControlledMissile_x                                   0xE5B5C4
#define pinstControlledPlayer_x                                    0xE5B5AC
#define pinstCResolutionHandler_x                                  0x169AD90
#define pinstCSidlManager_x                                        0x1699C24
#define pinstCXWndManager_x                                        0x1699C18
#define instDynamicZone_x                                          0xE61448
#define pinstDZMember_x                                            0xE61558
#define pinstDZTimerInfo_x                                         0xE6155C
#define pinstEQItemList_x                                          0xE59AF8
#define pinstEQObjectList_x                                        0xE5ACE8
#define instEQMisc_x                                               0xDA8F28
#define pinstEQSoundManager_x                                      0xDAAB10
#define pinstEQSpellStrings_x                                      0xC75AF0
#define instExpeditionLeader_x                                     0xE61492
#define instExpeditionName_x                                       0xE614D2
#define pinstGroup_x                                               0xE5B5EE
#define pinstImeManager_x                                          0x1699C1C
#define pinstLocalPlayer_x                                         0xE5B144
#define pinstMercenaryData_x                                       0xF0ACE0
#define pinstMercenaryStats_x                                      0x1022130
#define pinstMercAltAbilities_x                                    0xDAA880
#define pinstModelPlayer_x                                         0xE5B56C
#define pinstPCData_x                                              0xE5B5C0
#define pinstRealEstateItems_x                                     0xF0C1C8
#define pinstSkillMgr_x                                            0xF0C298
#define pinstSpawnManager_x                                        0xF0B888
#define pinstSpellManager_x                                        0xF0C470
#define pinstSpellSets_x                                           0xF026A8
#define pinstStringTable_x                                         0xE5D7EC
#define pinstSwitchManager_x                                       0xE5AEA8
#define pinstTarget_x                                              0xE5B5A8
#define pinstTargetObject_x                                        0xE5B5B4
#define pinstTargetSwitch_x                                        0xE5B5CC
#define pinstTaskMember_x                                          0xDA8DBC
#define pinstTrackTarget_x                                         0xE5B5B0
#define pinstTradeTarget_x                                         0xE5B364
#define instTributeActive_x                                        0xDA8F4D
#define pinstViewActor_x                                           0xDA90A8
#define pinstWorldData_x                                           0xE5B5D4
#define pinstZoneAddr_x                                            0xE6B278
#define pinstPlayerPath_x                                          0xF0B920
#define pinstTargetIndicator_x                                     0xF0C6D8
#define pinstCTargetManager_x                                      0xF0C770
#define EQObject_Top_x                                             0xE5B140
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDA98D8
#define pinstCAchievementsWnd_x                                    0xDA9138
#define pinstCActionsWnd_x                                         0xDA90A4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDA98E0
#define pinstCAdvancedLootWnd_x                                    0xDA98B4
#define pinstCAdventureLeaderboardWnd_x                            0x1018E00
#define pinstCAdventureRequestWnd_x                                0x1018EB0
#define pinstCAdventureStatsWnd_x                                  0x1018F60
#define pinstCAggroMeterWnd_x                                      0xDA9148
#define pinstCAlarmWnd_x                                           0xDA9110
#define pinstCAlertHistoryWnd_x                                    0xDA90FC
#define pinstCAlertStackWnd_x                                      0xDA9904
#define pinstCAlertWnd_x                                           0xDA9914
#define pinstCAltStorageWnd_x                                      0x10192C0
#define pinstCAudioTriggersWindow_x                                0xC67E48
#define pinstCAuraWnd_x                                            0xDA9140
#define pinstCAvaZoneWnd_x                                         0xDA90E0
#define pinstCBandolierWnd_x                                       0xDA937C
#define pinstCBankWnd_x                                            0xDA987C
#define pinstCBarterMerchantWnd_x                                  0x101A500
#define pinstCBarterSearchWnd_x                                    0x101A5B0
#define pinstCBarterWnd_x                                          0x101A660
#define pinstCBazaarConfirmationWnd_x                              0xDA98FC
#define pinstCBazaarSearchWnd_x                                    0xDA90CC
#define pinstCBazaarWnd_x                                          0xDA9378
#define pinstCBlockedBuffWnd_x                                     0xDA9844
#define pinstCBlockedPetBuffWnd_x                                  0xDA988C
#define pinstCBodyTintWnd_x                                        0xDA9910
#define pinstCBookWnd_x                                            0xDA93A0
#define pinstCBreathWnd_x                                          0xDA98DC
#define pinstCBuffWindowNORMAL_x                                   0xDA93B0
#define pinstCBuffWindowSHORT_x                                    0xDA93B4
#define pinstCBugReportWnd_x                                       0xDA98D4
#define pinstCButtonWnd_x                                          0x1699E10
#define pinstCCastingWnd_x                                         0xDA98D0
#define pinstCCastSpellWnd_x                                       0xDA90E4
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDA98E8
#define pinstCChatWindowManager_x                                  0x101B120
#define pinstCClaimWnd_x                                           0x101B278
#define pinstCColorPickerWnd_x                                     0xDA9088
#define pinstCCombatAbilityWnd_x                                   0xDA9158
#define pinstCCombatSkillsSelectWnd_x                              0xDA90A0
#define pinstCCompassWnd_x                                         0xDA98F0
#define pinstCConfirmationDialog_x                                 0x1020178
#define pinstCContainerMgr_x                                       0xDA9374
#define pinstCContextMenuManager_x                                 0x1699BD8
#define pinstCCursorAttachment_x                                   0xDA98C4
#define pinstCDistillerInfo_x                                      0x101EB84
#define pinstCDynamicZoneWnd_x                                     0x101B840
#define pinstCEditLabelWnd_x                                       0xDA93A8
#define pinstCEQMainWnd_x                                          0x101BA88
#define pinstCEventCalendarWnd_x                                   0xDA9388
#define pinstCExtendedTargetWnd_x                                  0xDA9134
#define pinstCFacePick_x                                           0xDA9090
#define pinstCFellowshipWnd_x                                      0x101BC88
#define pinstCFileSelectionWnd_x                                   0xDA9894
#define pinstCFindItemWnd_x                                        0xDA9394
#define pinstCFindLocationWnd_x                                    0x101BDE0
#define pinstCFriendsWnd_x                                         0xDA90D0
#define pinstCGemsGameWnd_x                                        0xDA90E8
#define pinstCGiveWnd_x                                            0xDA939C
#define pinstCGroupSearchFiltersWnd_x                              0xDA9364
#define pinstCGroupSearchWnd_x                                     0x101C1D8
#define pinstCGroupWnd_x                                           0x101C288
#define pinstCGuildBankWnd_x                                       0xE6C0BC
#define pinstCGuildCreationWnd_x                                   0x101C3E8
#define pinstCGuildMgmtWnd_x                                       0x101C498
#define pinstCharacterCreation_x                                   0xDA9154
#define pinstCHelpWnd_x                                            0xDA9100
#define pinstCHeritageSelectionWnd_x                               0xDA9094
#define pinstCHotButtonWnd_x                                       0x101E5F0
#define pinstCHotButtonWnd1_x                                      0x101E5F0
#define pinstCHotButtonWnd2_x                                      0x101E5F4
#define pinstCHotButtonWnd3_x                                      0x101E5F8
#define pinstCHotButtonWnd4_x                                      0x101E5FC
#define pinstCIconSelectionWnd_x                                   0xDA9898
#define pinstCInspectWnd_x                                         0xDA9890
#define pinstCInventoryWnd_x                                       0xDA9384
#define pinstCInvSlotMgr_x                                         0xDA9118
#define pinstCItemDisplayManager_x                                 0x101EB80
#define pinstCItemExpTransferWnd_x                                 0x101ECB4
#define pinstCItemOverflowWnd_x                                    0xDA90D4
#define pinstCJournalCatWnd_x                                      0xDA98C0
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDA9850
#define pinstCKeyRingWnd_x                                         0xDA9434
#define pinstCLargeDialogWnd_x                                     0x1020DF8
#define pinstCLayoutCopyWnd_x                                      0x101F000
#define pinstCLFGuildWnd_x                                         0x101F0B0
#define pinstCLoadskinWnd_x                                        0xDA90F8
#define pinstCLootFiltersCopyWnd_x                                 0xC78E80
#define pinstCLootFiltersWnd_x                                     0xDA9098
#define pinstCLootSettingsWnd_x                                    0xDA90C4
#define pinstCLootWnd_x                                            0xDA9908
#define pinstCMailAddressBookWnd_x                                 0xDA98A0
#define pinstCMailCompositionWnd_x                                 0xDA9884
#define pinstCMailIgnoreListWnd_x                                  0xDA98A4
#define pinstCMailWnd_x                                            0xDA9840
#define pinstCManageLootWnd_x                                      0xDAA728
#define pinstCMapToolbarWnd_x                                      0xDA938C
#define pinstCMapViewWnd_x                                         0xDA936C
#define pinstCMarketplaceWnd_x                                     0xDA9398
#define pinstCMerchantWnd_x                                        0xDA909C
#define pinstCMIZoneSelectWnd_x                                    0x101F8E8
#define pinstCMusicPlayerWnd_x                                     0xDA9430
#define pinstCNameChangeMercWnd_x                                  0xDA98C8
#define pinstCNameChangePetWnd_x                                   0xDA98AC
#define pinstCNameChangeWnd_x                                      0xDA9370
#define pinstCNoteWnd_x                                            0xDA90F4
#define pinstCObjectPreviewWnd_x                                   0xDA942C
#define pinstCOptionsWnd_x                                         0xDA9390
#define pinstCPetInfoWnd_x                                         0xDA9858
#define pinstCPetitionQWnd_x                                       0xDA98CC
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDA990C
#define pinstCPlayerWnd_x                                          0xDA90D8
#define pinstCPopupWndManager_x                                    0x1020178
#define pinstCProgressionSelectionWnd_x                            0x1020228
#define pinstCPurchaseGroupWnd_x                                   0xDA9880
#define pinstCPurchaseWnd_x                                        0xDA983C
#define pinstCPvPLeaderboardWnd_x                                  0x10202D8
#define pinstCPvPStatsWnd_x                                        0x1020388
#define pinstCQuantityWnd_x                                        0xDA98B0
#define pinstCRaceChangeWnd_x                                      0xDA93A4
#define pinstCRaidOptionsWnd_x                                     0xDA9368
#define pinstCRaidWnd_x                                            0xDA98B8
#define pinstCRealEstateItemsWnd_x                                 0xDA9144
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA9380
#define pinstCRealEstateManageWnd_x                                0xDA90C8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDA90EC
#define pinstCRealEstatePlotSearchWnd_x                            0xDA9104
#define pinstCRealEstatePurchaseWnd_x                              0xDA9128
#define pinstCRespawnWnd_x                                         0xDA9360
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDA9130
#define pinstCSendMoneyWnd_x                                       0xDA93AC
#define pinstCServerListWnd_x                                      0xDA914C
#define pinstCSkillsSelectWnd_x                                    0xDA908C
#define pinstCSkillsWnd_x                                          0xDA9900
#define pinstCSocialEditWnd_x                                      0xDA98BC
#define pinstCSocialWnd_x                                          0xDA98E4
#define pinstCSpellBookWnd_x                                       0xDA912C
#define pinstCStoryWnd_x                                           0xDA98EC
#define pinstCTargetOfTargetWnd_x                                  0x10221B8
#define pinstCTargetWnd_x                                          0xDA9854
#define pinstCTaskOverlayWnd_x                                     0xDA9108
#define pinstCTaskSelectWnd_x                                      0x1022310
#define pinstCTaskManager_x                                        0xC79680
#define pinstCTaskTemplateSelectWnd_x                              0x10223C0
#define pinstCTaskWnd_x                                            0x1022470
#define pinstCTextEntryWnd_x                                       0xDA98F8
#define pinstCTextOverlay_x                                        0xC68158
#define pinstCTimeLeftWnd_x                                        0xDA989C
#define pinstCTipWndCONTEXT_x                                      0x1022674
#define pinstCTipWndOFDAY_x                                        0x1022670
#define pinstCTitleWnd_x                                           0x1022720
#define pinstCTrackingWnd_x                                        0xDA984C
#define pinstCTradeskillWnd_x                                      0x1022888
#define pinstCTradeWnd_x                                           0xDA910C
#define pinstCTrainWnd_x                                           0xDA98A8
#define pinstCTributeBenefitWnd_x                                  0x1022A88
#define pinstCTributeMasterWnd_x                                   0x1022B38
#define pinstCTributeTrophyWnd_x                                   0x1022BE8
#define pinstCVideoModesWnd_x                                      0xDA9114
#define pinstCVoiceMacroWnd_x                                      0xF0CCA0
#define pinstCVoteResultsWnd_x                                     0xDA9888
#define pinstCVoteWnd_x                                            0xDA9848
#define pinstCWebManager_x                                         0xF0CE04
#define pinstCZoneGuideWnd_x                                       0xDA90DC
#define pinstCZonePathWnd_x                                        0xDA90F0

#define pinstEQSuiteTextureLoader_x                                0xC52C50
#define pinstItemIconCache_x                                       0x101BA40
#define pinstLootFiltersManager_x                                  0xC78F30
#define pinstRewardSelectionWnd_x                                  0x1020AD0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC03C3C
#define __CastRay_x                                                0x58E2A0
#define __CastRay2_x                                               0x58E2F0
#define __ConvertItemTags_x                                        0x5A8EA0
#define __CrashHandler_x                                           0x83E8A0
#define __EQGetTime_x                                              0x8DCFE0
#define __ExecuteCmd_x                                             0x586C00
#define __FixHeading_x                                             0x96D7E0
#define __get_bearing_x                                            0x58DDE0
#define __get_melee_range_x                                        0x58E4E0
#define __GetAnimationCache_x                                      0x6FCE00
#define __GetGaugeValueFromEQ_x                                    0x7F03A0
#define __GetLabelFromEQ_x                                         0x7F1B10
#define __GetXTargetType_x                                         0x96F240
#define __HandleMouseWheel_x                                       0x699300
#define __HeadingDiff_x                                            0x96D850
#define __HelpPath_x                                               0xF0A154
#define __LoadFrontEnd_x                                           0x6950B0
#define __NewUIINI_x                                               0x7F0070
#define __pCrashHandler_x                                          0x103FF50
#define __ProcessGameEvents_x                                      0x5EBA90
#define __ProcessMouseEvent_x                                      0x5EB250
#define __SaveColors_x                                             0x538610
#define __STMLToText_x                                             0x910D60
#define __ToggleKeyRingItem_x                                      0x4FBB40
#define CrashDetected_x                                            0x696BA0
#define DrawNetStatus_x                                            0x617BE0
#define Expansion_HoT_x                                            0xE6C0C4
#define Teleport_Table_Size_x                                      0xE5B100
#define Teleport_Table_x                                           0xE5B7E8
#define Util__FastTime_x                                           0x8DCBA0
#define wwsCrashReportCheckForUploader_x                           0x83F720
#define wwsCrashReportPlatformLaunchUploader_x                     0x841E00

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A8C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4936A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493480

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53FF10
#define AltAdvManager__IsAbilityReady_x                            0x53EF90
#define AltAdvManager__GetAAById_x                                 0x53F190
#define AltAdvManager__CanTrainAbility_x                           0x53F200
#define AltAdvManager__CanSeeAbility_x                             0x53F430

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6280
#define CharacterZoneClient__HasSkill_x                            0x4D0E20
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2540
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA700
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B6E80
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4C80
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4D60
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D4E40
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF1E0
#define CharacterZoneClient__BardCastBard_x                        0x4C1E40
#define CharacterZoneClient__GetMaxEffects_x                       0x4B6F50
#define CharacterZoneClient__GetEffect_x                           0x4B6DC0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C01E0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C02B0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0300
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0450
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0620

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BF370

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CCAE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FA110
#define CButtonWnd__CButtonWnd_x                                   0x90D160

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EB840
#define CChatManager__InitContextMenu_x                            0x6E58E0
#define CChatManager__FreeChatWindow_x                             0x6EA750
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EF0F0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EB5E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x921950
#define CContextMenu__dCContextMenu_x                              0x921B80
#define CContextMenu__AddMenuItem_x                                0x921B90
#define CContextMenu__RemoveMenuItem_x                             0x921EA0
#define CContextMenu__RemoveAllMenuItems_x                         0x921EC0
#define CContextMenu__CheckMenuItem_x                              0x921F40
#define CContextMenu__SetMenuItem_x                                0x921DC0
#define CContextMenu__AddSeparator_x                               0x921D20

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9224E0
#define CContextMenuManager__RemoveMenu_x                          0x922550
#define CContextMenuManager__PopupMenu_x                           0x922610
#define CContextMenuManager__Flush_x                               0x922480
#define CContextMenuManager__GetMenu_x                             0x495880

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BDA90
#define CChatService__GetFriendName_x                              0x8BDAA0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EBDB0
#define CChatWindow__Clear_x                                       0x6ECE10
#define CChatWindow__WndNotification_x                             0x6ED380

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91EDE0
#define CComboWnd__Draw_x                                          0x91E2E0
#define CComboWnd__GetCurChoice_x                                  0x91EC20
#define CComboWnd__GetListRect_x                                   0x91E790
#define CComboWnd__GetTextRect_x                                   0x91EE50
#define CComboWnd__InsertChoice_x                                  0x91E920
#define CComboWnd__SetColors_x                                     0x91E8F0
#define CComboWnd__SetChoice_x                                     0x91EBF0
#define CComboWnd__GetItemCount_x                                  0x91EC30
#define CComboWnd__GetCurChoiceText_x                              0x91EC70

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F4FF0
#define CContainerWnd__vftable_x                                   0xACAAC0
#define CContainerWnd__SetContainer_x                              0x6F6560

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5383D0
#define CDisplay__GetClickedActor_x                                0x52B420
#define CDisplay__GetUserDefinedColor_x                            0x523B00
#define CDisplay__GetWorldFilePath_x                               0x52CE70
#define CDisplay__is3dON_x                                         0x5280F0
#define CDisplay__ReloadUI_x                                       0x532590
#define CDisplay__WriteTextHD2_x                                   0x527ED0
#define CDisplay__TrueDistance_x                                   0x52EAD0
#define CDisplay__SetViewActor_x                                   0x52AD70
#define CDisplay__GetFloorHeight_x                                 0x5281B0
#define CDisplay__SetRenderWindow_x                                0x526AE0
#define CDisplay__ToggleScreenshotMode_x                           0x52A840

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x940EA0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x926050
#define CEditWnd__GetCharIndexPt_x                                 0x926F40
#define CEditWnd__GetDisplayString_x                               0x926DE0
#define CEditWnd__GetHorzOffset_x                                  0x925690
#define CEditWnd__GetLineForPrintableChar_x                        0x928050
#define CEditWnd__GetSelStartPt_x                                  0x9271F0
#define CEditWnd__GetSTMLSafeText_x                                0x926C00
#define CEditWnd__PointFromPrintableChar_x                         0x927C90
#define CEditWnd__SelectableCharFromPoint_x                        0x927E00
#define CEditWnd__SetEditable_x                                    0x9272B0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5D9F40
#define CEverQuest__ClickedPlayer_x                                0x5CC290
#define CEverQuest__CreateTargetIndicator_x                        0x5E8D70
#define CEverQuest__DeleteTargetIndicator_x                        0x5E8E00
#define CEverQuest__DoTellWindow_x                                 0x4E15C0
#define CEverQuest__OutputTextToLog_x                              0x4E17F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C1B50
#define CEverQuest__dsp_chat_x                                     0x4E1B80
#define CEverQuest__trimName_x                                     0x5E52F0
#define CEverQuest__Emote_x                                        0x5DA750
#define CEverQuest__EnterZone_x                                    0x5D4930
#define CEverQuest__GetBodyTypeDesc_x                              0x5DEB90
#define CEverQuest__GetClassDesc_x                                 0x5DF1D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DF7D0
#define CEverQuest__GetDeityDesc_x                                 0x5E76C0
#define CEverQuest__GetLangDesc_x                                  0x5DF990
#define CEverQuest__GetRaceDesc_x                                  0x5DF1B0
#define CEverQuest__InterpretCmd_x                                 0x5E7C90
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C5D40
#define CEverQuest__LMouseUp_x                                     0x5C40C0
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6620
#define CEverQuest__RMouseUp_x                                     0x5C5050
#define CEverQuest__SetGameState_x                                 0x5C18E0
#define CEverQuest__UPCNotificationFlush_x                         0x5E51F0
#define CEverQuest__IssuePetCommand_x                              0x5E0D90
#define CEverQuest__ReportSuccessfulHit_x                          0x5DB470

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x706ED0
#define CGaugeWnd__CalcLinesFillRect_x                             0x706F30
#define CGaugeWnd__Draw_x                                          0x7065C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABD40
#define CGuild__GetGuildName_x                                     0x4AAE20
#define CGuild__GetGuildIndex_x                                    0x4AB1B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7222D0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FA4D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72F250
#define CInvSlotMgr__MoveItem_x                                    0x72DFB0
#define CInvSlotMgr__SelectSlot_x                                  0x72F320

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72C860
#define CInvSlot__SliderComplete_x                                 0x72A5C0
#define CInvSlot__GetItemBase_x                                    0x729F40
#define CInvSlot__UpdateItem_x                                     0x72A0B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x730C70
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72FF40
#define CInvSlotWnd__HandleLButtonUp_x                             0x7307F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EC560
#define CItemDisplayWnd__UpdateStrings_x                           0x73E810
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x738A30
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x738F30
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73ED90
#define CItemDisplayWnd__AboutToShow_x                             0x73E480
#define CItemDisplayWnd__WndNotification_x                         0x7400A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x823E60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x744180

// CLabel 
#define CLabel__Draw_x                                             0x749C70

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F7470
#define CListWnd__dCListWnd_x                                      0x8F7790
#define CListWnd__AddColumn_x                                      0x8FBA80
#define CListWnd__AddColumn1_x                                     0x8FBAD0
#define CListWnd__AddLine_x                                        0x8FBE60
#define CListWnd__AddString_x                                      0x8FBC60
#define CListWnd__CalculateFirstVisibleLine_x                      0x8FB850
#define CListWnd__CalculateVSBRange_x                              0x8FB630
#define CListWnd__ClearSel_x                                       0x8FC640
#define CListWnd__ClearAllSel_x                                    0x8FC6A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FD090
#define CListWnd__Compare_x                                        0x8FAF80
#define CListWnd__Draw_x                                           0x8F7890
#define CListWnd__DrawColumnSeparators_x                           0x8FA050
#define CListWnd__DrawHeader_x                                     0x8FA4C0
#define CListWnd__DrawItem_x                                       0x8FA8C0
#define CListWnd__DrawLine_x                                       0x8FA1C0
#define CListWnd__DrawSeparator_x                                  0x8FA0F0
#define CListWnd__EnableLine_x                                     0x8F9940
#define CListWnd__EnsureVisible_x                                  0x8FCFC0
#define CListWnd__ExtendSel_x                                      0x8FC570
#define CListWnd__GetColumnMinWidth_x                              0x8F9480
#define CListWnd__GetColumnWidth_x                                 0x8F93F0
#define CListWnd__GetCurSel_x                                      0x8F8D80
#define CListWnd__GetItemAtPoint_x                                 0x8F9BB0
#define CListWnd__GetItemAtPoint1_x                                0x8F9C20
#define CListWnd__GetItemData_x                                    0x8F8E00
#define CListWnd__GetItemHeight_x                                  0x8F91C0
#define CListWnd__GetItemIcon_x                                    0x8F8F90
#define CListWnd__GetItemRect_x                                    0x8F9A30
#define CListWnd__GetItemText_x                                    0x8F8E40
#define CListWnd__GetSelList_x                                     0x8FC6F0
#define CListWnd__GetSeparatorRect_x                               0x8F9E60
#define CListWnd__InsertLine_x                                     0x8FC250
#define CListWnd__RemoveLine_x                                     0x8FC3A0
#define CListWnd__SetColors_x                                      0x8FB610
#define CListWnd__SetColumnJustification_x                         0x8FB340
#define CListWnd__SetColumnWidth_x                                 0x8FB260
#define CListWnd__SetCurSel_x                                      0x8FC4B0
#define CListWnd__SetItemColor_x                                   0x8FCC80
#define CListWnd__SetItemData_x                                    0x8FCC40
#define CListWnd__SetItemText_x                                    0x8FC870
#define CListWnd__ShiftColumnSeparator_x                           0x8FB400
#define CListWnd__Sort_x                                           0x8FB100
#define CListWnd__ToggleSel_x                                      0x8FC4E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75F2E0
#define CMapViewWnd__GetWorldCoordinates_x                         0x75D9F0
#define CMapViewWnd__HandleLButtonDown_x                           0x75AA50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x782390
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x782C70
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7831A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x785FC0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x780D80
#define CMerchantWnd__SelectBuySellSlot_x                          0x78BB50
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x781FD0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88B760
#define CPacketScrambler__hton_x                                   0x88B750

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x916300
#define CSidlManager__FindScreenPieceTemplate_x                    0x916710
#define CSidlManager__FindScreenPieceTemplate1_x                   0x916500
#define CSidlManager__CreateLabel_x                                0x7E3950
#define CSidlManager__CreateXWndFromTemplate_x                     0x9197E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9199C0
#define CSidlManager__CreateXWnd_x                                 0x7E3880
#define CSidlManager__CreateHotButtonWnd_x                         0x7E3E50

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x912E90
#define CSidlScreenWnd__CalculateVSBRange_x                        0x912DA0
#define CSidlScreenWnd__ConvertToRes_x                             0x937740
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x912830
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x912520
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9125F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9126C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x913320
#define CSidlScreenWnd__EnableIniStorage_x                         0x9137F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x913510
#define CSidlScreenWnd__Init1_x                                    0x912130
#define CSidlScreenWnd__LoadIniInfo_x                              0x913840
#define CSidlScreenWnd__LoadIniListWnd_x                           0x914370
#define CSidlScreenWnd__LoadSidlScreen_x                           0x911540
#define CSidlScreenWnd__StoreIniInfo_x                             0x913EF0
#define CSidlScreenWnd__StoreIniVis_x                              0x914250
#define CSidlScreenWnd__WndNotification_x                          0x913230
#define CSidlScreenWnd__GetChildItem_x                             0x913770
#define CSidlScreenWnd__HandleLButtonUp_x                          0x902F50
#define CSidlScreenWnd__m_layoutCopy_x                             0x1699AA8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65E7A0
#define CSkillMgr__GetSkillCap_x                                   0x65E980
#define CSkillMgr__GetNameToken_x                                  0x65DF30

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9232D0
#define CSliderWnd__SetValue_x                                     0x923140
#define CSliderWnd__SetNumTicks_x                                  0x9231A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E97E0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x929EE0
#define CStmlWnd__CalculateHSBRange_x                              0x92AF90
#define CStmlWnd__CalculateVSBRange_x                              0x92AF10
#define CStmlWnd__CanBreakAtCharacter_x                            0x92F2D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92FEC0
#define CStmlWnd__ForceParseNow_x                                  0x92A4D0
#define CStmlWnd__GetNextTagPiece_x                                0x92F230
#define CStmlWnd__GetSTMLText_x                                    0x4EFA20
#define CStmlWnd__GetVisibleText_x                                 0x92A4F0
#define CStmlWnd__InitializeWindowVariables_x                      0x92FD10
#define CStmlWnd__MakeStmlColorTag_x                               0x929670
#define CStmlWnd__MakeWndNotificationTag_x                         0x9296E0
#define CStmlWnd__SetSTMLText_x                                    0x928740
#define CStmlWnd__StripFirstSTMLLines_x                            0x931010
#define CStmlWnd__UpdateHistoryString_x                            0x9300D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x934710
#define CTabWnd__DrawCurrentPage_x                                 0x934D30
#define CTabWnd__DrawTab_x                                         0x934B00
#define CTabWnd__GetCurrentPage_x                                  0x933F70
#define CTabWnd__GetPageInnerRect_x                                0x9341B0
#define CTabWnd__GetTabInnerRect_x                                 0x9340F0
#define CTabWnd__GetTabRect_x                                      0x933FA0
#define CTabWnd__InsertPage_x                                      0x9343A0
#define CTabWnd__SetPage_x                                         0x934230
#define CTabWnd__SetPageRect_x                                     0x934650
#define CTabWnd__UpdatePage_x                                      0x9349C0
#define CTabWnd__GetPageFromTabIndex_x                             0x934A40
#define CTabWnd__GetCurrentTabIndex_x                              0x933F60

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7445E0
#define CPageWnd__SetTabText_x                                     0x9412B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5880

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FFDC0
#define CTextureFont__GetTextExtent_x                              0x8FFF80

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x691F00
#define CHtmlComponentWnd__ValidateUri_x                           0x723CC0
#define CHtmlWnd__SetClientCallbacks_x                             0x5FF4D0
#define CHtmlWnd__AddObserver_x                                    0x5FF4F0
#define CHtmlWnd__RemoveObserver_x                                 0x5FF550
#define Window__getProgress_x                                      0x83C510
#define Window__getStatus_x                                        0x83C530
#define Window__getURI_x                                           0x83C540

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93D830

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8ECDE0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD0A0
#define CXStr__CXStr1_x                                            0x9AF460
#define CXStr__CXStr3_x                                            0x8D9110
#define CXStr__dCXStr_x                                            0x472270
#define CXStr__operator_equal_x                                    0x8D9340
#define CXStr__operator_equal1_x                                   0x8D9380
#define CXStr__operator_plus_equal1_x                              0x8D9E10

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x921570
#define CXWnd__BringToTop_x                                        0x9066D0
#define CXWnd__Center_x                                            0x906250
#define CXWnd__ClrFocus_x                                          0x906080
#define CXWnd__Destroy_x                                           0x906130
#define CXWnd__DoAllDrawing_x                                      0x9026E0
#define CXWnd__DrawChildren_x                                      0x9026B0
#define CXWnd__DrawColoredRect_x                                   0x902B40
#define CXWnd__DrawTooltip_x                                       0x901210
#define CXWnd__DrawTooltipAtPoint_x                                0x9012D0
#define CXWnd__GetBorderFrame_x                                    0x9029A0
#define CXWnd__GetChildWndAt_x                                     0x906770
#define CXWnd__GetClientClipRect_x                                 0x904940
#define CXWnd__GetScreenClipRect_x                                 0x904A10
#define CXWnd__GetScreenRect_x                                     0x904BE0
#define CXWnd__GetTooltipRect_x                                    0x902B90
#define CXWnd__GetWindowTextA_x                                    0x496F40
#define CXWnd__IsActive_x                                          0x909660
#define CXWnd__IsDescendantOf_x                                    0x9055E0
#define CXWnd__IsReallyVisible_x                                   0x905610
#define CXWnd__IsType_x                                            0x906DD0
#define CXWnd__Move_x                                              0x905670
#define CXWnd__Move1_x                                             0x905730
#define CXWnd__ProcessTransition_x                                 0x906200
#define CXWnd__Refade_x                                            0x905A00
#define CXWnd__Resize_x                                            0x905C90
#define CXWnd__Right_x                                             0x906490
#define CXWnd__SetFocus_x                                          0x906040
#define CXWnd__SetFont_x                                           0x9060B0
#define CXWnd__SetKeyTooltip_x                                     0x906BF0
#define CXWnd__SetMouseOver_x                                      0x903AE0
#define CXWnd__StartFade_x                                         0x9054B0
#define CXWnd__GetChildItem_x                                      0x9068E0
#define CXWnd__SetParent_x                                         0x905380

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x938810

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9096A0
#define CXWndManager__DrawWindows_x                                0x9096C0
#define CXWndManager__GetKeyboardFlags_x                           0x90BE30
#define CXWndManager__HandleKeyboardMsg_x                          0x90BA30
#define CXWndManager__RemoveWnd_x                                  0x90C080
#define CXWndManager__RemovePendingDeletionWnd_x                   0x90C5D0

// CDBStr
#define CDBStr__GetString_x                                        0x522AD0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7E30
#define EQ_Character__Cur_HP_x                                     0x4CDEA0
#define EQ_Character__Cur_Mana_x                                   0x4D5340
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BAD40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AEC80
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEDD0
#define EQ_Character__GetHPRegen_x                                 0x4DACF0
#define EQ_Character__GetEnduranceRegen_x                          0x4DB300
#define EQ_Character__GetManaRegen_x                               0x4DB740
#define EQ_Character__Max_Endurance_x                              0x625430
#define EQ_Character__Max_HP_x                                     0x4CDCD0
#define EQ_Character__Max_Mana_x                                   0x625230
#define EQ_Character__doCombatAbility_x                            0x6275E0
#define EQ_Character__UseSkill_x                                   0x4DD550
#define EQ_Character__GetConLevel_x                                0x61E970
#define EQ_Character__IsExpansionFlag_x                            0x5853C0
#define EQ_Character__TotalEffect_x                                0x4C13C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BB930
#define EQ_Character__SpellDuration_x                              0x4BB460
#define EQ_Character__FindItemByRecord_x                           0x4D34B0
#define EQ_Character__GetAdjustedSkill_x                           0x4D0BE0
#define EQ_Character__GetBaseSkill_x                               0x4D1B80
#define EQ_Character__CanUseItem_x                                 0x4D5650

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8AA860

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63B310

//PcClient
#define PcClient__PcClient_x                                       0x61C240

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5C10
#define CCharacterListWnd__EnterWorld_x                            0x4B5650
#define CCharacterListWnd__Quit_x                                  0x4B5360
#define CCharacterListWnd__UpdateList_x                            0x4B57E0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6006F0
#define EQ_Item__CreateItemTagString_x                             0x885640
#define EQ_Item__IsStackable_x                                     0x889C50
#define EQ_Item__GetImageNum_x                                     0x886F60
#define EQ_Item__CreateItemClient_x                                0x5FF8B0
#define EQ_Item__GetItemValue_x                                    0x888030
#define EQ_Item__ValueSellMerchant_x                               0x88B300
#define EQ_Item__IsKeyRingItem_x                                   0x8895B0
#define EQ_Item__CanGoInBag_x                                      0x600810
#define EQ_Item__GetMaxItemCount_x                                 0x888340
#define EQ_Item__GetHeldItem_x                                     0x886E30
#define EQ_Item__GetAugmentFitBySlot_x                             0x8850B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x540C40
#define EQ_LoadingS__Array_x                                       0xBDB2D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x625D90
#define EQ_PC__GetAlternateAbilityId_x                             0x894500
#define EQ_PC__GetCombatAbility_x                                  0x894B70
#define EQ_PC__GetCombatAbilityTimer_x                             0x894BE0
#define EQ_PC__GetItemRecastTimer_x                                0x627B60
#define EQ_PC__HasLoreItem_x                                       0x61F0E0
#define EQ_PC__AlertInventoryChanged_x                             0x61E440
#define EQ_PC__GetPcZoneClient_x                                   0x649B00
#define EQ_PC__RemoveMyAffect_x                                    0x62AC90
#define EQ_PC__GetKeyRingItems_x                                   0x895480
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x895200
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x895770

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58B810
#define EQItemList__add_object_x                                   0x5B7190
#define EQItemList__add_item_x                                     0x58BE20
#define EQItemList__delete_item_x                                  0x58BE70
#define EQItemList__FreeItemList_x                                 0x58BD70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x520110

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63CB90
#define EQPlayer__dEQPlayer_x                                      0x6302A0
#define EQPlayer__DoAttack_x                                       0x6447E0
#define EQPlayer__EQPlayer_x                                       0x630950
#define EQPlayer__SetNameSpriteState_x                             0x634BC0
#define EQPlayer__SetNameSpriteTint_x                              0x635A90
#define PlayerBase__HasProperty_j_x                                0x96BBC0
#define EQPlayer__IsTargetable_x                                   0x96C060
#define EQPlayer__CanSee_x                                         0x96BEC0
#define EQPlayer__CanSee1_x                                        0x96BF90
#define PlayerBase__GetVisibilityLineSegment_x                     0x96BC80

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6475B0
#define PlayerZoneClient__GetLevel_x                               0x649B40
#define PlayerZoneClient__IsValidTeleport_x                        0x5B82E0
#define PlayerZoneClient__LegalPlayerRace_x                        0x53A1B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63F910
#define EQPlayerManager__GetSpawnByName_x                          0x63F930
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63F9C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x603FA0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x603FE0
#define KeypressHandler__ClearCommandStateArray_x                  0x6053D0
#define KeypressHandler__HandleKeyDown_x                           0x6053F0
#define KeypressHandler__HandleKeyUp_x                             0x605490
#define KeypressHandler__SaveKeymapping_x                          0x605870

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75B170
#define MapViewMap__SaveEx_x                                       0x75E510
#define MapViewMap__SetZoom_x                                      0x762BE0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A8750

// StringTable 
#define StringTable__getString_x                                   0x8A3700

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62A900
#define PcZoneClient__RemovePetEffect_x                            0x62AF30
#define PcZoneClient__HasAlternateAbility_x                        0x625070
#define PcZoneClient__GetCurrentMod_x                              0x4E04C0
#define PcZoneClient__GetModCap_x                                  0x4E03C0
#define PcZoneClient__CanEquipItem_x                               0x625720
#define PcZoneClient__GetItemByID_x                                0x627FD0
#define PcZoneClient__GetItemByItemClass_x                         0x628060
#define PcZoneClient__RemoveBuffEffect_x                           0x62AF50
#define PcZoneClient__BandolierSwap_x                              0x626350

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BCFA0

//IconCache
#define IconCache__GetIcon_x                                       0x6FC690

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F4190
#define CContainerMgr__CloseContainer_x                            0x6F4460
#define CContainerMgr__OpenExperimentContainer_x                   0x6F4EE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B6090

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F88F0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x751550
#define CLootWnd__RequestLootSlot_x                                0x750900

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5590D0
#define EQ_Spell__SpellAffects_x                                   0x559540
#define EQ_Spell__SpellAffectBase_x                                0x559300
#define EQ_Spell__IsStackable_x                                    0x4C5BA0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5A20
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3190
#define EQ_Spell__IsSPAStacking_x                                  0x55A370
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x559890
#define EQ_Spell__IsNoRemove_x                                     0x4C5B80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55A380
#define __IsResEffectSpell_x                                       0x4C4F00

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9A50

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B2E20

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FB8B0
#define CTargetWnd__WndNotification_x                              0x7FB140
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FB410
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FA2A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FFF80

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x51DA50
 #define CTaskManager__HandleMessage_x                             0x51C1B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x554670
#define EqSoundManager__PlayScriptMp3_x                            0x5547D0
#define EqSoundManager__SoundAssistPlay_x                          0x662240
#define EqSoundManager__WaveInstancePlay_x                         0x6617B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5119E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x924CC0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5488C0
#define CAltAbilityData__GetMercMaxRank_x                          0x548860
#define CAltAbilityData__GetMaxRank_x                              0x53DE40

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F6A00

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5A00
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7FD0
#define CharacterBase__CreateItemIndex_x                           0x5FEAE0
#define CharacterBase__GetItemPossession_x                         0x4B3040
#define CharacterBase__GetItemByGlobalIndex_x                      0x8BB4B0
#define CharacterBase__GetEffectId_x                               0x4C59B0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DC2B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DCAD0

//messages
#define msg_spell_worn_off_x                                       0x57D980
#define msg_new_text_x                                             0x572B00
#define __msgTokenTextParam_x                                      0x57FFD0
#define msgTokenText_x                                             0x580220

//SpellManager
#define SpellManager__vftable_x                                    0xAA5838
#define SpellManager__SpellManager_x                               0x665570
#define Spellmanager__LoadTextSpells_x                             0x665E40
#define SpellManager__GetSpellByGroupAndRank_x                     0x665740

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96FB30

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F86C0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5839E0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x617A40
#define ItemGlobalIndex__IsValidIndex_x                            0x4F8720

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B3760
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B39E0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x749FB0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F88E0
#define CCursorAttachment__Deactivate_x                            0x6F98B0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x936D70
#define CEQSuiteTextureLoader__GetTexture_x                        0x936A30

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F5680

//IString
#define IString__Append_x                                          0x4E99E0

//Camera
#define CDisplay__cameraType_x                                     0xDA915C
#define EverQuest__Cameras_x                                       0xE6C400

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FDDD0
#define LootFiltersManager__GetItemFilterData_x                    0x4FD6C0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FD6F0
#define LootFiltersManager__SetItemLootFilter_x                    0x4FD910

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A40D0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x975860
#define CResolutionHandler__GetWindowedStyle_x                     0x65D2F0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F0F60

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8C59A0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7110B0
#define CGroupWnd__UpdateDisplay_x                                 0x710410

//ItemBase
#define ItemBase__IsLore_x                                         0x889610
#define ItemBase__IsLoreEquipped_x                                 0x889680

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5B7080
#define EQPlacedItemManager__GetItemByGuid_x                       0x5B7230
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5B7290

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6526F0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x656360

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

