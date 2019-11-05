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
#define __ExpectedVersionDate                                     "Nov  5 2019"
#define __ExpectedVersionTime                                     "04:22:49"
#define __ActualVersionDate_x                                      0xB04F18
#define __ActualVersionTime_x                                      0xB04F0C
#define __ActualVersionBuild_x                                     0xAF0BE4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62B130
#define __MemChecker1_x                                            0x8FDAC0
#define __MemChecker2_x                                            0x6B98F0
#define __MemChecker3_x                                            0x6B9840
#define __MemChecker4_x                                            0x855510
#define __EncryptPad0_x                                            0xC3B3E0
#define __EncryptPad1_x                                            0xC995A0
#define __EncryptPad2_x                                            0xC4BC78
#define __EncryptPad3_x                                            0xC4B878
#define __EncryptPad4_x                                            0xC89BF8
#define __EncryptPad5_x                                            0xF62CDC
#define __AC1_x                                                    0x811F66
#define __AC2_x                                                    0x5E504F
#define __AC3_x                                                    0x5EC74F
#define __AC4_x                                                    0x5F0720
#define __AC5_x                                                    0x5F6A2F
#define __AC6_x                                                    0x5FB046
#define __AC7_x                                                    0x5E4AC0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x196718

// Direct Input
#define DI8__Main_x                                                0xF651B8
#define DI8__Keyboard_x                                            0xF651BC
#define DI8__Mouse_x                                               0xF651D0
#define DI8__Mouse_Copy_x                                          0xEBE3A4
#define DI8__Mouse_Check_x                                         0xF62D04
#define __AutoSkillArray_x                                         0xEBF2BC
#define __Attack_x                                                 0xF5D0E3
#define __Autofire_x                                               0xF5D0E4
#define __BindList_x                                               0xC29E18
#define g_eqCommandStates_x                                        0xC2AB98
#define __Clicks_x                                                 0xEBE45C
#define __CommandList_x                                            0xC2B758
#define __CurrentMapLabel_x                                        0xF75B64
#define __CurrentSocial_x                                          0xC137CC
#define __DoAbilityList_x                                          0xEF4C04
#define __do_loot_x                                                0x5B13D0
#define __DrawHandler_x                                            0x15F4ED8
#define __GroupCount_x                                             0xEB0C6A
#define __Guilds_x                                                 0xEB4BB0
#define __gWorld_x                                                 0xEB0B34
#define __HWnd_x                                                   0xF651D4
#define __heqmain_x                                                0xF651AC
#define __InChatMode_x                                             0xEBE38C
#define __LastTell_x                                               0xEC0300
#define __LMouseHeldTime_x                                         0xEBE4C8
#define __Mouse_x                                                  0xF65198
#define __MouseLook_x                                              0xEBE422
#define __MouseEventTime_x                                         0xF5DBC4
#define __gpbCommandEvent_x                                        0xEB0E5C
#define __NetStatusToggle_x                                        0xEBE425
#define __PCNames_x                                                0xEBF8AC
#define __RangeAttackReady_x                                       0xEBF5A0
#define __RMouseHeldTime_x                                         0xEBE4C4
#define __RunWalkState_x                                           0xEBE390
#define __ScreenMode_x                                             0xDFC470
#define __ScreenX_x                                                0xEBE344
#define __ScreenY_x                                                0xEBE340
#define __ScreenXMax_x                                             0xEBE348
#define __ScreenYMax_x                                             0xEBE34C
#define __ServerHost_x                                             0xEAE79B
#define __ServerName_x                                             0xEF4BC4
#define __ShiftKeyDown_x                                           0xEBEA1C
#define __ShowNames_x                                              0xEBF75C
#define __Socials_x                                                0xEF4CC4
#define __SubscriptionType_x                                       0xFBA068
#define __TargetAggroHolder_x                                      0xF78518
#define __ZoneType_x                                               0xEBE820
#define __GroupAggro_x                                             0xF78558
#define __LoginName_x                                              0xF65914
#define __Inviter_x                                                0xF5D060
#define __AttackOnAssist_x                                         0xEBF718
#define __UseTellWindows_x                                         0xEBFA48
#define __gfMaxZoomCameraDistance_x                                0xAFA858
#define __gfMaxCameraDistance_x                                    0xB26DB8
#define __pulAutoRun_x                                             0xEBE440
#define __pulForward_x                                             0xEBFA80
#define __pulBackward_x                                            0xEBFA84
#define __pulTurnRight_x                                           0xEBFA88
#define __pulTurnLeft_x                                            0xEBFA8C
#define __pulStrafeLeft_x                                          0xEBFA90
#define __pulStrafeRight_x                                         0xEBFA94

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB0F48
#define instEQZoneInfo_x                                           0xEBE618
#define pinstActiveBanker_x                                        0xEB0E74
#define pinstActiveCorpse_x                                        0xEB0E6C
#define pinstActiveGMaster_x                                       0xEB0E70
#define pinstActiveMerchant_x                                      0xEB0E68
#define pinstAltAdvManager_x                                       0xDFD180
#define pinstBandageTarget_x                                       0xEB0E84
#define pinstCamActor_x                                            0xDFC460
#define pinstCDBStr_x                                              0xDFBE9C
#define pinstCDisplay_x                                            0xEB0B18
#define pinstCEverQuest_x                                          0xF651D8
#define pinstEverQuestInfo_x                                       0xEBE338
#define pinstCharData_x                                            0xEB0C48
#define pinstCharSpawn_x                                           0xEB0F3C
#define pinstControlledMissile_x                                   0xEAEB00
#define pinstControlledPlayer_x                                    0xEB0F3C
#define pinstCResolutionHandler_x                                  0x15F5108
#define pinstCSidlManager_x                                        0x15F40A0
#define pinstCXWndManager_x                                        0x15F409C
#define instDynamicZone_x                                          0xEB4A88
#define pinstDZMember_x                                            0xEB4B98
#define pinstDZTimerInfo_x                                         0xEB4B9C
#define pinstEqLogin_x                                             0xF65260
#define instEQMisc_x                                               0xDFBDE0
#define pinstEQSoundManager_x                                      0xDFE150
#define pinstEQSpellStrings_x                                      0xCBE858
#define instExpeditionLeader_x                                     0xEB4AD2
#define instExpeditionName_x                                       0xEB4B12
#define pinstGroup_x                                               0xEB0C66
#define pinstImeManager_x                                          0x15F4098
#define pinstLocalPlayer_x                                         0xEB0E64
#define pinstMercenaryData_x                                       0xF5F6B4
#define pinstMercenaryStats_x                                      0xF78664
#define pinstModelPlayer_x                                         0xEB0E7C
#define pinstPCData_x                                              0xEB0C48
#define pinstSkillMgr_x                                            0xF61820
#define pinstSpawnManager_x                                        0xF602C8
#define pinstSpellManager_x                                        0xF61A40
#define pinstSpellSets_x                                           0xF55D0C
#define pinstStringTable_x                                         0xEB0C4C
#define pinstSwitchManager_x                                       0xEAE4E8
#define pinstTarget_x                                              0xEB0F38
#define pinstTargetObject_x                                        0xEAE638
#define pinstTargetSwitch_x                                        0xEB0B10
#define pinstTaskMember_x                                          0xDFBC70
#define pinstTrackTarget_x                                         0xEB0F40
#define pinstTradeTarget_x                                         0xEB0E78
#define instTributeActive_x                                        0xDFBE01
#define pinstViewActor_x                                           0xDFC45C
#define pinstWorldData_x                                           0xEAEB0C
#define pinstZoneAddr_x                                            0xEBE8B8
#define pinstPlayerPath_x                                          0xF60360
#define pinstTargetIndicator_x                                     0xF61CA8
#define EQObject_Top_x                                             0xEB0E60
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDFC724
#define pinstCAchievementsWnd_x                                    0xDFC4BC
#define pinstCActionsWnd_x                                         0xDFC4E8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFBF84
#define pinstCAdvancedLootWnd_x                                    0xDFC7C8
#define pinstCAdventureLeaderboardWnd_x                            0xF6F338
#define pinstCAdventureRequestWnd_x                                0xF6F3E8
#define pinstCAdventureStatsWnd_x                                  0xF6F498
#define pinstCAggroMeterWnd_x                                      0xDFC454
#define pinstCAlarmWnd_x                                           0xDFC788
#define pinstCAlertHistoryWnd_x                                    0xDFC7C0
#define pinstCAlertStackWnd_x                                      0xDFC738
#define pinstCAlertWnd_x                                           0xDFC74C
#define pinstCAltStorageWnd_x                                      0xF6F7F8
#define pinstCAudioTriggersWindow_x                                0xCB0B88
#define pinstCAuraWnd_x                                            0xDFC428
#define pinstCAvaZoneWnd_x                                         0xDFC78C
#define pinstCBandolierWnd_x                                       0xDFC450
#define pinstCBankWnd_x                                            0xDFC424
#define pinstCBarterMerchantWnd_x                                  0xF70A38
#define pinstCBarterSearchWnd_x                                    0xF70AE8
#define pinstCBarterWnd_x                                          0xF70B98
#define pinstCBazaarConfirmationWnd_x                              0xDFC4F8
#define pinstCBazaarSearchWnd_x                                    0xDFC4B0
#define pinstCBazaarWnd_x                                          0xDFC774
#define pinstCBlockedBuffWnd_x                                     0xDFC42C
#define pinstCBlockedPetBuffWnd_x                                  0xDFC44C
#define pinstCBodyTintWnd_x                                        0xDFC4FC
#define pinstCBookWnd_x                                            0xDFC490
#define pinstCBreathWnd_x                                          0xDFC744
#define pinstCBuffWindowNORMAL_x                                   0xDFC010
#define pinstCBuffWindowSHORT_x                                    0xDFC014
#define pinstCBugReportWnd_x                                       0xDFC420
#define pinstCButtonWnd_x                                          0x15F4308
#define pinstCCastingWnd_x                                         0xDFC480
#define pinstCCastSpellWnd_x                                       0xDFC73C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDFC778
#define pinstCChatWindowManager_x                                  0xF71658
#define pinstCClaimWnd_x                                           0xF717B0
#define pinstCColorPickerWnd_x                                     0xDFC4F0
#define pinstCCombatAbilityWnd_x                                   0xDFC784
#define pinstCCombatSkillsSelectWnd_x                              0xDFC7A8
#define pinstCCompassWnd_x                                         0xDFC4EC
#define pinstCConfirmationDialog_x                                 0xF766B0
#define pinstCContainerMgr_x                                       0xDFC76C
#define pinstCContextMenuManager_x                                 0x15F4058
#define pinstCCursorAttachment_x                                   0xDFC464
#define pinstCDynamicZoneWnd_x                                     0xF71D78
#define pinstCEditLabelWnd_x                                       0xDFBF90
#define pinstCEQMainWnd_x                                          0xF71FC0
#define pinstCEventCalendarWnd_x                                   0xDFC00C
#define pinstCExtendedTargetWnd_x                                  0xDFC440
#define pinstCFacePick_x                                           0xDFC7B8
#define pinstCFactionWnd_x                                         0xDFC764
#define pinstCFellowshipWnd_x                                      0xF721C0
#define pinstCFileSelectionWnd_x                                   0xDFC47C
#define pinstCFindItemWnd_x                                        0xDFC758
#define pinstCFindLocationWnd_x                                    0xF72318
#define pinstCFriendsWnd_x                                         0xDFC7C4
#define pinstCGemsGameWnd_x                                        0xDFC760
#define pinstCGiveWnd_x                                            0xDFC790
#define pinstCGroupSearchFiltersWnd_x                              0xDFC488
#define pinstCGroupSearchWnd_x                                     0xF72710
#define pinstCGroupWnd_x                                           0xF727C0
#define pinstCGuildBankWnd_x                                       0xEBF6FC
#define pinstCGuildCreationWnd_x                                   0xF72920
#define pinstCGuildMgmtWnd_x                                       0xF729D0
#define pinstCharacterCreation_x                                   0xDFC7B0
#define pinstCHelpWnd_x                                            0xDFBF7C
#define pinstCHeritageSelectionWnd_x                               0xDFC7D0
#define pinstCHotButtonWnd_x                                       0xF74B28
#define pinstCHotButtonWnd1_x                                      0xF74B28
#define pinstCHotButtonWnd2_x                                      0xF74B2C
#define pinstCHotButtonWnd3_x                                      0xF74B30
#define pinstCHotButtonWnd4_x                                      0xF74B34
#define pinstCIconSelectionWnd_x                                   0xDFC458
#define pinstCInspectWnd_x                                         0xDFBF78
#define pinstCInventoryWnd_x                                       0xDFBF38
#define pinstCInvSlotMgr_x                                         0xDFC720
#define pinstCItemDisplayManager_x                                 0xF750B8
#define pinstCItemExpTransferWnd_x                                 0xF751E8
#define pinstCItemOverflowWnd_x                                    0xDFC4B8
#define pinstCJournalCatWnd_x                                      0xDFC498
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDFC444
#define pinstCKeyRingWnd_x                                         0xDFBF8C
#define pinstCLargeDialogWnd_x                                     0xF77330
#define pinstCLayoutCopyWnd_x                                      0xF75538
#define pinstCLFGuildWnd_x                                         0xF755E8
#define pinstCLoadskinWnd_x                                        0xDFC770
#define pinstCLootFiltersCopyWnd_x                                 0xCCD178
#define pinstCLootFiltersWnd_x                                     0xDFC740
#define pinstCLootSettingsWnd_x                                    0xDFC754
#define pinstCLootWnd_x                                            0xDFC49C
#define pinstCMailAddressBookWnd_x                                 0xDFC72C
#define pinstCMailCompositionWnd_x                                 0xDFC510
#define pinstCMailIgnoreListWnd_x                                  0xDFC730
#define pinstCMailWnd_x                                            0xDFC4E4
#define pinstCManageLootWnd_x                                      0xDFD630
#define pinstCMapToolbarWnd_x                                      0xDFBF80
#define pinstCMapViewWnd_x                                         0xDFBF48
#define pinstCMarketplaceWnd_x                                     0xDFC748
#define pinstCMerchantWnd_x                                        0xDFC4A0
#define pinstCMIZoneSelectWnd_x                                    0xF75E20
#define pinstCMusicPlayerWnd_x                                     0xDFC4A8
#define pinstCNameChangeMercWnd_x                                  0xDFC4E0
#define pinstCNameChangePetWnd_x                                   0xDFC4C0
#define pinstCNameChangeWnd_x                                      0xDFC508
#define pinstCNoteWnd_x                                            0xDFBF4C
#define pinstCObjectPreviewWnd_x                                   0xDFC750
#define pinstCOptionsWnd_x                                         0xDFBF5C
#define pinstCPetInfoWnd_x                                         0xDFC4C4
#define pinstCPetitionQWnd_x                                       0xDFC4AC
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDFC500
#define pinstCPlayerWnd_x                                          0xDFC4C8
#define pinstCPopupWndManager_x                                    0xF766B0
#define pinstCProgressionSelectionWnd_x                            0xF76760
#define pinstCPurchaseGroupWnd_x                                   0xDFC798
#define pinstCPurchaseWnd_x                                        0xDFC768
#define pinstCPvPLeaderboardWnd_x                                  0xF76810
#define pinstCPvPStatsWnd_x                                        0xF768C0
#define pinstCQuantityWnd_x                                        0xDFC448
#define pinstCRaceChangeWnd_x                                      0xDFC728
#define pinstCRaidOptionsWnd_x                                     0xDFC48C
#define pinstCRaidWnd_x                                            0xDFC518
#define pinstCRealEstateItemsWnd_x                                 0xDFC4B4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDFC434
#define pinstCRealEstateManageWnd_x                                0xDFC7A0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFC7BC
#define pinstCRealEstatePlotSearchWnd_x                            0xDFBF3C
#define pinstCRealEstatePurchaseWnd_x                              0xDFBF74
#define pinstCRespawnWnd_x                                         0xDFC438
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDFC734
#define pinstCSendMoneyWnd_x                                       0xDFC7A4
#define pinstCServerListWnd_x                                      0xDFBF98
#define pinstCSkillsSelectWnd_x                                    0xDFC77C
#define pinstCSkillsWnd_x                                          0xDFC75C
#define pinstCSocialEditWnd_x                                      0xDFBF88
#define pinstCSocialWnd_x                                          0xDFC4DC
#define pinstCSpellBookWnd_x                                       0xDFC780
#define pinstCStoryWnd_x                                           0xDFC4CC
#define pinstCTargetOfTargetWnd_x                                  0xF786E8
#define pinstCTargetWnd_x                                          0xDFC430
#define pinstCTaskOverlayWnd_x                                     0xDFC794
#define pinstCTaskSelectWnd_x                                      0xF78840
#define pinstCTaskManager_x                                        0xCCDAB8
#define pinstCTaskTemplateSelectWnd_x                              0xF788F0
#define pinstCTaskWnd_x                                            0xF789A0
#define pinstCTextEntryWnd_x                                       0xDFC018
#define pinstCTimeLeftWnd_x                                        0xDFC484
#define pinstCTipWndCONTEXT_x                                      0xF78BA4
#define pinstCTipWndOFDAY_x                                        0xF78BA0
#define pinstCTitleWnd_x                                           0xF78C50
#define pinstCTrackingWnd_x                                        0xDFBF40
#define pinstCTradeskillWnd_x                                      0xF78DB8
#define pinstCTradeWnd_x                                           0xDFC50C
#define pinstCTrainWnd_x                                           0xDFC504
#define pinstCTributeBenefitWnd_x                                  0xF78FB8
#define pinstCTributeMasterWnd_x                                   0xF79068
#define pinstCTributeTrophyWnd_x                                   0xF79118
#define pinstCVideoModesWnd_x                                      0xDFC514
#define pinstCVoiceMacroWnd_x                                      0xF62410
#define pinstCVoteResultsWnd_x                                     0xDFC4A4
#define pinstCVoteWnd_x                                            0xDFC494
#define pinstCWebManager_x                                         0xF62A8C
#define pinstCZoneGuideWnd_x                                       0xDFC79C
#define pinstCZonePathWnd_x                                        0xDFC7AC

#define pinstEQSuiteTextureLoader_x                                0xC9B078
#define pinstItemIconCache_x                                       0xF71F78
#define pinstLootFiltersManager_x                                  0xCCD228
#define pinstRewardSelectionWnd_x                                  0xF77008

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AC830
#define __CastRay2_x                                               0x5AC880
#define __ConvertItemTags_x                                        0x5C83C0
#define __CleanItemTags_x                                          0x47D230
#define __DoesFileExist_x                                          0x900B80
#define __EQGetTime_x                                              0x8FD590
#define __ExecuteCmd_x                                             0x5A50E0
#define __FixHeading_x                                             0x998810
#define __GameLoop_x                                               0x6B8AE0
#define __get_bearing_x                                            0x5AC3A0
#define __get_melee_range_x                                        0x5ACA70
#define __GetAnimationCache_x                                      0x71DE20
#define __GetGaugeValueFromEQ_x                                    0x810410
#define __GetLabelFromEQ_x                                         0x811EF0
#define __GetXTargetType_x                                         0x99A2D0
#define __HandleMouseWheel_x                                       0x6B99A0
#define __HeadingDiff_x                                            0x998880
#define __HelpPath_x                                               0xF5D7B4
#define __LoadFrontEnd_x                                           0x6B5E00
#define __NewUIINI_x                                               0x8100E0
#define __ProcessGameEvents_x                                      0x60C8B0
#define __ProcessMouseEvent_x                                      0x60C070
#define __SaveColors_x                                             0x54FBA0
#define __STMLToText_x                                             0x93BCC0
#define __ToggleKeyRingItem_x                                      0x512E50
#define CMemoryMappedFile__SetFile_x                               0xA87B30
#define CrashDetected_x                                            0x6B78A0
#define DrawNetStatus_x                                            0x638520
#define Expansion_HoT_x                                            0xEBF704
#define Teleport_Table_Size_x                                      0xEAE640
#define Teleport_Table_x                                           0xEAEB10
#define Util__FastTime_x                                           0x8FD160

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490490
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499390
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499160
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A10
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x557720
#define AltAdvManager__IsAbilityReady_x                            0x556650
#define AltAdvManager__GetAAById_x                                 0x556850
#define AltAdvManager__CanTrainAbility_x                           0x5568C0
#define AltAdvManager__CanSeeAbility_x                             0x556C20

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9F90
#define CharacterZoneClient__HasSkill_x                            0x4D4E80
#define CharacterZoneClient__MakeMeVisible_x                       0x4D65A0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE270
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA870
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8F50
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9030
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9110
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3060
#define CharacterZoneClient__BardCastBard_x                        0x4C5BC0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA940
#define CharacterZoneClient__GetEffect_x                           0x4BA7B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C40B0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4180
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C41D0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4320
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C44F0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2710
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7500
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6F80

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DF5B0
#define CBankWnd__WndNotification_x                                0x6DF390

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6ECD50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61AF50
#define CButtonWnd__CButtonWnd_x                                   0x938060

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70CFA0
#define CChatManager__InitContextMenu_x                            0x7060F0
#define CChatManager__FreeChatWindow_x                             0x70BAE0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E85D0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70CC20
#define CChatManager__CreateChatWindow_x                           0x70C120

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E86F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94C730
#define CContextMenu__dCContextMenu_x                              0x94C970
#define CContextMenu__AddMenuItem_x                                0x94C980
#define CContextMenu__RemoveMenuItem_x                             0x94CC90
#define CContextMenu__RemoveAllMenuItems_x                         0x94CCB0
#define CContextMenu__CheckMenuItem_x                              0x94CD30
#define CContextMenu__SetMenuItem_x                                0x94CBB0
#define CContextMenu__AddSeparator_x                               0x94CB10

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94D2D0
#define CContextMenuManager__RemoveMenu_x                          0x94D340
#define CContextMenuManager__PopupMenu_x                           0x94D400
#define CContextMenuManager__Flush_x                               0x94D270
#define CContextMenuManager__GetMenu_x                             0x49B550
#define CContextMenuManager__CreateDefaultMenu_x                   0x718620

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D9B00
#define CChatService__GetFriendName_x                              0x8D9B10

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70D810
#define CChatWindow__Clear_x                                       0x70EAE0
#define CChatWindow__WndNotification_x                             0x70F270
#define CChatWindow__AddHistory_x                                  0x70E3A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x949B90
#define CComboWnd__Draw_x                                          0x949080
#define CComboWnd__GetCurChoice_x                                  0x9499D0
#define CComboWnd__GetListRect_x                                   0x949530
#define CComboWnd__GetTextRect_x                                   0x949C00
#define CComboWnd__InsertChoice_x                                  0x9496C0
#define CComboWnd__SetColors_x                                     0x949690
#define CComboWnd__SetChoice_x                                     0x9499A0
#define CComboWnd__GetItemCount_x                                  0x9499E0
#define CComboWnd__GetCurChoiceText_x                              0x949A20
#define CComboWnd__GetChoiceText_x                                 0x9499F0
#define CComboWnd__InsertChoiceAtIndex_x                           0x949760

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x716010
#define CContainerWnd__vftable_x                                   0xB0E0FC
#define CContainerWnd__SetContainer_x                              0x717570

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54A5E0
#define CDisplay__PreZoneMainUI_x                                  0x54A5F0
#define CDisplay__CleanGameUI_x                                    0x54F960
#define CDisplay__GetClickedActor_x                                0x542900
#define CDisplay__GetUserDefinedColor_x                            0x53AFC0
#define CDisplay__GetWorldFilePath_x                               0x544370
#define CDisplay__is3dON_x                                         0x53F560
#define CDisplay__ReloadUI_x                                       0x549A70
#define CDisplay__WriteTextHD2_x                                   0x53F350
#define CDisplay__TrueDistance_x                                   0x546030
#define CDisplay__SetViewActor_x                                   0x542220
#define CDisplay__GetFloorHeight_x                                 0x53F620
#define CDisplay__SetRenderWindow_x                                0x53DF80
#define CDisplay__ToggleScreenshotMode_x                           0x541CF0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96C4F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x94FCA0
#define CEditWnd__GetCharIndexPt_x                                 0x950BD0
#define CEditWnd__GetDisplayString_x                               0x950A70
#define CEditWnd__GetHorzOffset_x                                  0x94F2D0
#define CEditWnd__GetLineForPrintableChar_x                        0x951D70
#define CEditWnd__GetSelStartPt_x                                  0x950E80
#define CEditWnd__GetSTMLSafeText_x                                0x950890
#define CEditWnd__PointFromPrintableChar_x                         0x9519A0
#define CEditWnd__SelectableCharFromPoint_x                        0x951B10
#define CEditWnd__SetEditable_x                                    0x950F50
#define CEditWnd__SetWindowTextA_x                                 0x950610

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FA520
#define CEverQuest__ClickedPlayer_x                                0x5EC530
#define CEverQuest__CreateTargetIndicator_x                        0x609B40
#define CEverQuest__DeleteTargetIndicator_x                        0x609BD0
#define CEverQuest__DoTellWindow_x                                 0x4E87D0
#define CEverQuest__OutputTextToLog_x                              0x4E8A50
#define CEverQuest__DropHeldItemOnGround_x                         0x5E1570
#define CEverQuest__dsp_chat_x                                     0x4E8DE0
#define CEverQuest__trimName_x                                     0x605E30
#define CEverQuest__Emote_x                                        0x5FAD80
#define CEverQuest__EnterZone_x                                    0x5F4D00
#define CEverQuest__GetBodyTypeDesc_x                              0x5FF6F0
#define CEverQuest__GetClassDesc_x                                 0x5FFD30
#define CEverQuest__GetClassThreeLetterCode_x                      0x600330
#define CEverQuest__GetDeityDesc_x                                 0x608480
#define CEverQuest__GetLangDesc_x                                  0x6004F0
#define CEverQuest__GetRaceDesc_x                                  0x5FFD10
#define CEverQuest__InterpretCmd_x                                 0x608A50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E5770
#define CEverQuest__LMouseUp_x                                     0x5E3B00
#define CEverQuest__RightClickedOnPlayer_x                         0x5E6050
#define CEverQuest__RMouseUp_x                                     0x5E4A80
#define CEverQuest__SetGameState_x                                 0x5E1300
#define CEverQuest__UPCNotificationFlush_x                         0x605D30
#define CEverQuest__IssuePetCommand_x                              0x6018F0
#define CEverQuest__ReportSuccessfulHit_x                          0x5FC170

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x727F70
#define CGaugeWnd__CalcLinesFillRect_x                             0x727FD0
#define CGaugeWnd__Draw_x                                          0x7275F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF200
#define CGuild__GetGuildName_x                                     0x4AE2E0
#define CGuild__GetGuildIndex_x                                    0x4AE670

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7433F0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61B310

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x750410
#define CInvSlotMgr__MoveItem_x                                    0x74F120
#define CInvSlotMgr__SelectSlot_x                                  0x7504E0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74D990
#define CInvSlot__SliderComplete_x                                 0x74B6E0
#define CInvSlot__GetItemBase_x                                    0x74B060
#define CInvSlot__UpdateItem_x                                     0x74B1D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x751F40
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7510E0
#define CInvSlotWnd__HandleLButtonUp_x                             0x751AC0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80B760
#define CItemDisplayWnd__UpdateStrings_x                           0x760590
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75A300
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75A810
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x760BA0
#define CItemDisplayWnd__AboutToShow_x                             0x7601E0
#define CItemDisplayWnd__WndNotification_x                         0x761C90
#define CItemDisplayWnd__RequestConvertItem_x                      0x761750
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75F240
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x760000

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x844210

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7661C0

// CLabel 
#define CLabel__Draw_x                                             0x76BC20

// CListWnd
#define CListWnd__CListWnd_x                                       0x922120
#define CListWnd__dCListWnd_x                                      0x922440
#define CListWnd__AddColumn_x                                      0x9268D0
#define CListWnd__AddColumn1_x                                     0x926920
#define CListWnd__AddLine_x                                        0x926CB0
#define CListWnd__AddString_x                                      0x926AB0
#define CListWnd__CalculateFirstVisibleLine_x                      0x926690
#define CListWnd__CalculateVSBRange_x                              0x926470
#define CListWnd__ClearSel_x                                       0x927490
#define CListWnd__ClearAllSel_x                                    0x9274F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x927F10
#define CListWnd__Compare_x                                        0x925DA0
#define CListWnd__Draw_x                                           0x922570
#define CListWnd__DrawColumnSeparators_x                           0x924D70
#define CListWnd__DrawHeader_x                                     0x9251E0
#define CListWnd__DrawItem_x                                       0x9256E0
#define CListWnd__DrawLine_x                                       0x924EE0
#define CListWnd__DrawSeparator_x                                  0x924E10
#define CListWnd__EnableLine_x                                     0x924640
#define CListWnd__EnsureVisible_x                                  0x927E30
#define CListWnd__ExtendSel_x                                      0x9273C0
#define CListWnd__GetColumnTooltip_x                               0x924180
#define CListWnd__GetColumnMinWidth_x                              0x9241F0
#define CListWnd__GetColumnWidth_x                                 0x9240F0
#define CListWnd__GetCurSel_x                                      0x923A80
#define CListWnd__GetItemAtPoint_x                                 0x9248C0
#define CListWnd__GetItemAtPoint1_x                                0x924930
#define CListWnd__GetItemData_x                                    0x923B00
#define CListWnd__GetItemHeight_x                                  0x923EC0
#define CListWnd__GetItemIcon_x                                    0x923C90
#define CListWnd__GetItemRect_x                                    0x924730
#define CListWnd__GetItemText_x                                    0x923B40
#define CListWnd__GetSelList_x                                     0x927540
#define CListWnd__GetSeparatorRect_x                               0x924B70
#define CListWnd__InsertLine_x                                     0x9270A0
#define CListWnd__RemoveLine_x                                     0x9271F0
#define CListWnd__SetColors_x                                      0x926440
#define CListWnd__SetColumnJustification_x                         0x926170
#define CListWnd__SetColumnWidth_x                                 0x926090
#define CListWnd__SetCurSel_x                                      0x927300
#define CListWnd__SetItemColor_x                                   0x927AE0
#define CListWnd__SetItemData_x                                    0x927AA0
#define CListWnd__SetItemText_x                                    0x9276B0
#define CListWnd__ShiftColumnSeparator_x                           0x926230
#define CListWnd__Sort_x                                           0x925F20
#define CListWnd__ToggleSel_x                                      0x927330
#define CListWnd__SetColumnsSizable_x                              0x9262E0
#define CListWnd__SetItemWnd_x                                     0x927960
#define CListWnd__GetItemWnd_x                                     0x923CE0
#define CListWnd__SetItemIcon_x                                    0x927730
#define CListWnd__CalculateCustomWindowPositions_x                 0x926790
#define CListWnd__SetVScrollPos_x                                  0x926070

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x781360
#define CMapViewWnd__GetWorldCoordinates_x                         0x77FA70
#define CMapViewWnd__HandleLButtonDown_x                           0x77CAB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A12E0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A1BC0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A20F0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A5080
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79FE50
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AAC30
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A0F00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A73D0
#define CPacketScrambler__hton_x                                   0x8A73C0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x941340
#define CSidlManager__FindScreenPieceTemplate_x                    0x941750
#define CSidlManager__FindScreenPieceTemplate1_x                   0x941540
#define CSidlManager__CreateLabel_x                                0x802B70
#define CSidlManager__CreateXWndFromTemplate_x                     0x9446B0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x944890
#define CSidlManager__CreateXWnd_x                                 0x802AA0
#define CSidlManager__CreateHotButtonWnd_x                         0x803070

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93DE00
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93DD00
#define CSidlScreenWnd__ConvertToRes_x                             0x963490
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93D790
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93D480
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93D550
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93D620
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93E2A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x93E770
#define CSidlScreenWnd__GetSidlPiece_x                             0x93E490
#define CSidlScreenWnd__Init1_x                                    0x93D080
#define CSidlScreenWnd__LoadIniInfo_x                              0x93E7C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93F320
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93C480
#define CSidlScreenWnd__StoreIniInfo_x                             0x93EE90
#define CSidlScreenWnd__StoreIniVis_x                              0x93F200
#define CSidlScreenWnd__WndNotification_x                          0x93E1B0
#define CSidlScreenWnd__GetChildItem_x                             0x93E6F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92DD90
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F3F28

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x67FA40
#define CSkillMgr__GetSkillCap_x                                   0x67FC20
#define CSkillMgr__GetNameToken_x                                  0x67F1C0
#define CSkillMgr__IsActivatedSkill_x                              0x67F300
#define CSkillMgr__IsCombatSkill_x                                 0x67F240

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94E0B0
#define CSliderWnd__SetValue_x                                     0x94DF20
#define CSliderWnd__SetNumTicks_x                                  0x94DF80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x808BF0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9568D0
#define CStmlWnd__CalculateHSBRange_x                              0x9579B0
#define CStmlWnd__CalculateVSBRange_x                              0x957920
#define CStmlWnd__CanBreakAtCharacter_x                            0x95BCF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95C980
#define CStmlWnd__ForceParseNow_x                                  0x956E70
#define CStmlWnd__GetNextTagPiece_x                                0x95BC50
#define CStmlWnd__GetSTMLText_x                                    0x502600
#define CStmlWnd__GetVisibleText_x                                 0x956E90
#define CStmlWnd__InitializeWindowVariables_x                      0x95C7D0
#define CStmlWnd__MakeStmlColorTag_x                               0x955F40
#define CStmlWnd__MakeWndNotificationTag_x                         0x955FB0
#define CStmlWnd__SetSTMLText_x                                    0x954FF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x95DA80
#define CStmlWnd__UpdateHistoryString_x                            0x95CB90

// CTabWnd 
#define CTabWnd__Draw_x                                            0x954140
#define CTabWnd__DrawCurrentPage_x                                 0x954870
#define CTabWnd__DrawTab_x                                         0x954590
#define CTabWnd__GetCurrentPage_x                                  0x953940
#define CTabWnd__GetPageInnerRect_x                                0x953B80
#define CTabWnd__GetTabInnerRect_x                                 0x953AC0
#define CTabWnd__GetTabRect_x                                      0x953970
#define CTabWnd__InsertPage_x                                      0x953D90
#define CTabWnd__SetPage_x                                         0x953C00
#define CTabWnd__SetPageRect_x                                     0x954080
#define CTabWnd__UpdatePage_x                                      0x954450
#define CTabWnd__GetPageFromTabIndex_x                             0x9544D0
#define CTabWnd__GetCurrentTabIndex_x                              0x953930

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x766620
#define CPageWnd__SetTabText_x                                     0x953480

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8EE0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92AC30
#define CTextureFont__GetTextExtent_x                              0x92ADF0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B2CD0
#define CHtmlComponentWnd__ValidateUri_x                           0x744DE0
#define CHtmlWnd__SetClientCallbacks_x                             0x620390
#define CHtmlWnd__AddObserver_x                                    0x6203B0
#define CHtmlWnd__RemoveObserver_x                                 0x620410
#define Window__getProgress_x                                      0x85CB30
#define Window__getStatus_x                                        0x85CB50
#define Window__getURI_x                                           0x85CB60

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x968F80

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x917CF0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8410
#define CXStr__CXStr1_x                                            0x84D140
#define CXStr__CXStr3_x                                            0x8F9690
#define CXStr__dCXStr_x                                            0x478750
#define CXStr__operator_equal_x                                    0x8F98C0
#define CXStr__operator_equal1_x                                   0x8F9900
#define CXStr__operator_plus_equal1_x                              0x8FA390
#define CXStr__SetString_x                                         0x8FC280
#define CXStr__operator_char_p_x                                   0x8F9DD0
#define CXStr__GetChar_x                                           0x8FBBB0
#define CXStr__Delete_x                                            0x8FB480
#define CXStr__GetUnicode_x                                        0x8FBC20
#define CXStr__GetLength_x                                         0x4A8C90
#define CXStr__Mid_x                                               0x47D5E0
#define CXStr__Insert_x                                            0x8FBC80
#define CXStr__FindNext_x                                          0x8FB8F0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94C350
#define CXWnd__BringToTop_x                                        0x931570
#define CXWnd__Center_x                                            0x9310F0
#define CXWnd__ClrFocus_x                                          0x930F10
#define CXWnd__Destroy_x                                           0x930FB0
#define CXWnd__DoAllDrawing_x                                      0x92D520
#define CXWnd__DrawChildren_x                                      0x92D4F0
#define CXWnd__DrawColoredRect_x                                   0x92D980
#define CXWnd__DrawTooltip_x                                       0x92C050
#define CXWnd__DrawTooltipAtPoint_x                                0x92C110
#define CXWnd__GetBorderFrame_x                                    0x92D7E0
#define CXWnd__GetChildWndAt_x                                     0x931610
#define CXWnd__GetClientClipRect_x                                 0x92F7F0
#define CXWnd__GetScreenClipRect_x                                 0x92F8C0
#define CXWnd__GetScreenRect_x                                     0x92FA60
#define CXWnd__GetTooltipRect_x                                    0x92D9D0
#define CXWnd__GetWindowTextA_x                                    0x49CC30
#define CXWnd__IsActive_x                                          0x92E110
#define CXWnd__IsDescendantOf_x                                    0x930450
#define CXWnd__IsReallyVisible_x                                   0x930480
#define CXWnd__IsType_x                                            0x931C90
#define CXWnd__Move_x                                              0x930500
#define CXWnd__Move1_x                                             0x9305C0
#define CXWnd__ProcessTransition_x                                 0x9310A0
#define CXWnd__Refade_x                                            0x9308A0
#define CXWnd__Resize_x                                            0x930B70
#define CXWnd__Right_x                                             0x931330
#define CXWnd__SetFocus_x                                          0x930ED0
#define CXWnd__SetFont_x                                           0x930F40
#define CXWnd__SetKeyTooltip_x                                     0x931AA0
#define CXWnd__SetMouseOver_x                                      0x92E960
#define CXWnd__StartFade_x                                         0x930330
#define CXWnd__GetChildItem_x                                      0x931780
#define CXWnd__SetParent_x                                         0x930220
#define CXWnd__Minimize_x                                          0x930BD0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x964510

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9344E0
#define CXWndManager__DrawWindows_x                                0x934500
#define CXWndManager__GetKeyboardFlags_x                           0x936CF0
#define CXWndManager__HandleKeyboardMsg_x                          0x9368A0
#define CXWndManager__RemoveWnd_x                                  0x936F40
#define CXWndManager__RemovePendingDeletionWnd_x                   0x937480

// CDBStr
#define CDBStr__GetString_x                                        0x539F80

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB850
#define EQ_Character__Cur_HP_x                                     0x4D1EC0
#define EQ_Character__Cur_Mana_x                                   0x4D9610
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE8C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2350
#define EQ_Character__GetFocusRangeModifier_x                      0x4B24A0
#define EQ_Character__GetHPRegen_x                                 0x4DF3E0
#define EQ_Character__GetEnduranceRegen_x                          0x4DF9E0
#define EQ_Character__GetManaRegen_x                               0x4DFE20
#define EQ_Character__Max_Endurance_x                              0x6460D0
#define EQ_Character__Max_HP_x                                     0x4D1CF0
#define EQ_Character__Max_Mana_x                                   0x645ED0
#define EQ_Character__doCombatAbility_x                            0x648520
#define EQ_Character__UseSkill_x                                   0x4E1C00
#define EQ_Character__GetConLevel_x                                0x63F440
#define EQ_Character__IsExpansionFlag_x                            0x5A38A0
#define EQ_Character__TotalEffect_x                                0x4C5300
#define EQ_Character__GetPCSpellAffect_x                           0x4BF610
#define EQ_Character__SpellDuration_x                              0x4BF140
#define EQ_Character__GetAdjustedSkill_x                           0x4D4C40
#define EQ_Character__GetBaseSkill_x                               0x4D5BE0
#define EQ_Character__CanUseItem_x                                 0x4D9920

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C6990

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65C670

//PcClient
#define PcClient__PcClient_x                                       0x63CB80

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B94C0
#define CCharacterListWnd__EnterWorld_x                            0x4B8F00
#define CCharacterListWnd__Quit_x                                  0x4B8C50
#define CCharacterListWnd__UpdateList_x                            0x4B9090

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6215B0
#define EQ_Item__CreateItemTagString_x                             0x8A0C80
#define EQ_Item__IsStackable_x                                     0x8A57C0
#define EQ_Item__GetImageNum_x                                     0x8A2710
#define EQ_Item__CreateItemClient_x                                0x620790
#define EQ_Item__GetItemValue_x                                    0x8A3A20
#define EQ_Item__ValueSellMerchant_x                               0x8A6FB0
#define EQ_Item__IsKeyRingItem_x                                   0x8A50F0
#define EQ_Item__CanGoInBag_x                                      0x6216D0
#define EQ_Item__IsEmpty_x                                         0x8A4C30
#define EQ_Item__GetMaxItemCount_x                                 0x8A3E30
#define EQ_Item__GetHeldItem_x                                     0x8A25E0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A0600

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5584B0
#define EQ_LoadingS__Array_x                                       0xC22B58

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x646A30
#define EQ_PC__GetAlternateAbilityId_x                             0x8B0250
#define EQ_PC__GetCombatAbility_x                                  0x8B08C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B0930
#define EQ_PC__GetItemRecastTimer_x                                0x648AA0
#define EQ_PC__HasLoreItem_x                                       0x63FC50
#define EQ_PC__AlertInventoryChanged_x                             0x63ED80
#define EQ_PC__GetPcZoneClient_x                                   0x66B070
#define EQ_PC__RemoveMyAffect_x                                    0x64BCD0
#define EQ_PC__GetKeyRingItems_x                                   0x8B11C0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B0F50
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B14C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A9DF0
#define EQItemList__add_object_x                                   0x5D6D90
#define EQItemList__add_item_x                                     0x5AA350
#define EQItemList__delete_item_x                                  0x5AA3A0
#define EQItemList__FreeItemList_x                                 0x5AA2A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x536A90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65DEF0
#define EQPlayer__dEQPlayer_x                                      0x651260
#define EQPlayer__DoAttack_x                                       0x665D20
#define EQPlayer__EQPlayer_x                                       0x651920
#define EQPlayer__SetNameSpriteState_x                             0x655BE0
#define EQPlayer__SetNameSpriteTint_x                              0x656AA0
#define PlayerBase__HasProperty_j_x                                0x996BF0
#define EQPlayer__IsTargetable_x                                   0x997090
#define EQPlayer__CanSee_x                                         0x996EF0
#define EQPlayer__CanSee1_x                                        0x996FC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x996CB0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x668B00
#define PlayerZoneClient__GetLevel_x                               0x66B0B0
#define PlayerZoneClient__IsValidTeleport_x                        0x5D7F10
#define PlayerZoneClient__LegalPlayerRace_x                        0x5517F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x660C30
#define EQPlayerManager__GetSpawnByName_x                          0x660CE0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x660D70

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x624C20
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x624CA0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x624CE0
#define KeypressHandler__ClearCommandStateArray_x                  0x6260F0
#define KeypressHandler__HandleKeyDown_x                           0x626110
#define KeypressHandler__HandleKeyUp_x                             0x6261B0
#define KeypressHandler__SaveKeymapping_x                          0x626600

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77D1D0
#define MapViewMap__SaveEx_x                                       0x780590
#define MapViewMap__SetZoom_x                                      0x784C50

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C48B0

// StringTable 
#define StringTable__getString_x                                   0x8BF450

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64B940
#define PcZoneClient__RemovePetEffect_x                            0x64BF70
#define PcZoneClient__HasAlternateAbility_x                        0x645D00
#define PcZoneClient__GetCurrentMod_x                              0x4E4CB0
#define PcZoneClient__GetModCap_x                                  0x4E4BB0
#define PcZoneClient__CanEquipItem_x                               0x6463D0
#define PcZoneClient__GetItemByID_x                                0x648F10
#define PcZoneClient__GetItemByItemClass_x                         0x649060
#define PcZoneClient__RemoveBuffEffect_x                           0x64BF90
#define PcZoneClient__BandolierSwap_x                              0x646FE0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x648A40

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DC9C0

//IconCache
#define IconCache__GetIcon_x                                       0x71D6C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7151B0
#define CContainerMgr__CloseContainer_x                            0x715480
#define CContainerMgr__OpenExperimentContainer_x                   0x715F00

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D5160

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x619720

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7736E0
#define CLootWnd__RequestLootSlot_x                                0x772910

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5772B0
#define EQ_Spell__SpellAffects_x                                   0x577720
#define EQ_Spell__SpellAffectBase_x                                0x5774E0
#define EQ_Spell__IsStackable_x                                    0x4C98F0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9770
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6800
#define EQ_Spell__IsSPAStacking_x                                  0x578570
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x577A80
#define EQ_Spell__IsNoRemove_x                                     0x4C98D0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x578580
#define __IsResEffectSpell_x                                       0x4C8D40

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACF10

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CEFC0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81BEB0
#define CTargetWnd__WndNotification_x                              0x81B740
#define CTargetWnd__RefreshTargetBuffs_x                           0x81BA10
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81A8A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8204C0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5344E0
#define CTaskManager__HandleMessage_x                              0x532990
#define CTaskManager__GetTaskStatus_x                              0x534590
#define CTaskManager__GetElementDescription_x                      0x534610

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x572820
#define EqSoundManager__PlayScriptMp3_x                            0x572980
#define EqSoundManager__SoundAssistPlay_x                          0x683970
#define EqSoundManager__WaveInstancePlay_x                         0x682EE0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x528230

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x952990

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55FF50
#define CAltAbilityData__GetMercMaxRank_x                          0x55FEE0
#define CAltAbilityData__GetMaxRank_x                              0x5554D0

//CTargetRing
#define CTargetRing__Cast_x                                        0x617840

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9750
#define CharacterBase__CreateItemGlobalIndex_x                     0x50F3E0
#define CharacterBase__CreateItemIndex_x                           0x61F940
#define CharacterBase__GetItemPossession_x                         0x4FAF70
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D75D0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D7630
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FC320
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FCB50
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FCC00

//messages
#define msg_spell_worn_off_x                                       0x59BB20
#define msg_new_text_x                                             0x5908A0
#define __msgTokenTextParam_x                                      0x59E040
#define msgTokenText_x                                             0x59E290

//SpellManager
#define SpellManager__vftable_x                                    0xAE821C
#define SpellManager__SpellManager_x                               0x686CA0
#define Spellmanager__LoadTextSpells_x                             0x687590
#define SpellManager__GetSpellByGroupAndRank_x                     0x686E70

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99ABC0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50FA60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A1E00
#define ItemGlobalIndex__IsEquippedLocation_x                      0x638380
#define ItemGlobalIndex__IsValidIndex_x                            0x50FAC0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CF960
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CFBE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76BF60

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7198C0
#define CCursorAttachment__AttachToCursor1_x                       0x719900
#define CCursorAttachment__Deactivate_x                            0x71A8F0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9456F0
#define CSidlManagerBase__CreatePageWnd_x                          0x944EE0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x941160
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9410F0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9626A0
#define CEQSuiteTextureLoader__GetTexture_x                        0x962360

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50C950
#define CFindItemWnd__WndNotification_x                            0x50D430
#define CFindItemWnd__Update_x                                     0x50DFA0
#define CFindItemWnd__PickupSelectedItem_x                         0x50C1A0

//IString
#define IString__Append_x                                          0x4FC7C0

//Camera
#define CDisplay__cameraType_x                                     0xDFC51C
#define EverQuest__Cameras_x                                       0xEBFA54

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5151E0
#define LootFiltersManager__GetItemFilterData_x                    0x514AF0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x514B20
#define LootFiltersManager__SetItemLootFilter_x                    0x514D40

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C3130

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A0690
#define CResolutionHandler__GetWindowedStyle_x                     0x67E2C0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x711F80

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E3D30
#define CDistillerInfo__Instance_x                                 0x8E3CD0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x732190
#define CGroupWnd__UpdateDisplay_x                                 0x7314E0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A5190
#define ItemBase__IsLoreEquipped_x                                 0x8A5200

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D6CF0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D6E30
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D6E90

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x673810
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x677180

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x502D50

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1940
#define FactionManagerClient__HandleFactionMessage_x               0x4F1FB0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2570
#define FactionManagerClient__GetMaxFaction_x                      0x4F258F
#define FactionManagerClient__GetMinFaction_x                      0x4F2540

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FAF40

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x929BB0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BF40

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FB1D0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55F3F0

//CTargetManager
#define CTargetManager__Get_x                                      0x68A500

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x673810

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8CA0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AA240

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF5D0E8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
