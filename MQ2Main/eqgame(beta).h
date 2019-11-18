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
#define __ExpectedVersionDate                                     "Nov 18 2019"
#define __ExpectedVersionTime                                     "04:22:38"
#define __ActualVersionDate_x                                      0xB08280
#define __ActualVersionTime_x                                      0xB08274
#define __ActualVersionBuild_x                                     0xAF3F6C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62D6D0
#define __MemChecker1_x                                            0x9009C0
#define __MemChecker2_x                                            0x6BC1F0
#define __MemChecker3_x                                            0x6BC140
#define __MemChecker4_x                                            0x857D90
#define __EncryptPad0_x                                            0xC3E3E8
#define __EncryptPad1_x                                            0xC9C5A8
#define __EncryptPad2_x                                            0xC4EC80
#define __EncryptPad3_x                                            0xC4E880
#define __EncryptPad4_x                                            0xC8CC00
#define __EncryptPad5_x                                            0xF681A0
#define __AC1_x                                                    0x814A06
#define __AC2_x                                                    0x5E73FF
#define __AC3_x                                                    0x5EEAFF
#define __AC4_x                                                    0x5F2AD0
#define __AC5_x                                                    0x5F8DDF
#define __AC6_x                                                    0x5FD3F6
#define __AC7_x                                                    0x5E6E70
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19FA6C

// Direct Input
#define DI8__Main_x                                                0xF681C8
#define DI8__Keyboard_x                                            0xF681CC
#define DI8__Mouse_x                                               0xF681AC
#define DI8__Mouse_Copy_x                                          0xEC13AC
#define DI8__Mouse_Check_x                                         0xF65CF4
#define __AutoSkillArray_x                                         0xEC22C4
#define __Attack_x                                                 0xF600EB
#define __Autofire_x                                               0xF600EC
#define __BindList_x                                               0xC2CE20
#define g_eqCommandStates_x                                        0xC2DBA0
#define __Clicks_x                                                 0xEC1464
#define __CommandList_x                                            0xC2E760
#define __CurrentMapLabel_x                                        0xF78B6C
#define __CurrentSocial_x                                          0xC167CC
#define __DoAbilityList_x                                          0xEF7C0C
#define __do_loot_x                                                0x5B37E0
#define __DrawHandler_x                                            0x15F7EE0
#define __GroupCount_x                                             0xEB3D62
#define __Guilds_x                                                 0xEB7BB8
#define __gWorld_x                                                 0xEB3BB0
#define __HWnd_x                                                   0xF681B0
#define __heqmain_x                                                0xF68188
#define __InChatMode_x                                             0xEC1394
#define __LastTell_x                                               0xEC3308
#define __LMouseHeldTime_x                                         0xEC14D0
#define __Mouse_x                                                  0xF681B4
#define __MouseLook_x                                              0xEC142A
#define __MouseEventTime_x                                         0xF60BCC
#define __gpbCommandEvent_x                                        0xEB1650
#define __NetStatusToggle_x                                        0xEC142D
#define __PCNames_x                                                0xEC28B4
#define __RangeAttackReady_x                                       0xEC25A8
#define __RMouseHeldTime_x                                         0xEC14CC
#define __RunWalkState_x                                           0xEC1398
#define __ScreenMode_x                                             0xDFF004
#define __ScreenX_x                                                0xEC134C
#define __ScreenY_x                                                0xEC1348
#define __ScreenXMax_x                                             0xEC1350
#define __ScreenYMax_x                                             0xEC1354
#define __ServerHost_x                                             0xEB1883
#define __ServerName_x                                             0xEF7BCC
#define __ShiftKeyDown_x                                           0xEC1A24
#define __ShowNames_x                                              0xEC2764
#define __Socials_x                                                0xEF7CCC
#define __SubscriptionType_x                                       0xFBD070
#define __TargetAggroHolder_x                                      0xF7B520
#define __ZoneType_x                                               0xEC1828
#define __GroupAggro_x                                             0xF7B560
#define __LoginName_x                                              0xF6891C
#define __Inviter_x                                                0xF60068
#define __AttackOnAssist_x                                         0xEC2720
#define __UseTellWindows_x                                         0xEC2A50
#define __gfMaxZoomCameraDistance_x                                0xAFDBE0
#define __gfMaxCameraDistance_x                                    0xB2A124
#define __pulAutoRun_x                                             0xEC1448
#define __pulForward_x                                             0xEC2A88
#define __pulBackward_x                                            0xEC2A8C
#define __pulTurnRight_x                                           0xEC2A90
#define __pulTurnLeft_x                                            0xEC2A94
#define __pulStrafeLeft_x                                          0xEC2A98
#define __pulStrafeRight_x                                         0xEC2A9C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB3F58
#define instEQZoneInfo_x                                           0xEC1620
#define pinstActiveBanker_x                                        0xEB1668
#define pinstActiveCorpse_x                                        0xEB1660
#define pinstActiveGMaster_x                                       0xEB1664
#define pinstActiveMerchant_x                                      0xEB165C
#define pinstAltAdvManager_x                                       0xE00188
#define pinstBandageTarget_x                                       0xEB1678
#define pinstCamActor_x                                            0xDFEFF8
#define pinstCDBStr_x                                              0xDFEEA4
#define pinstCDisplay_x                                            0xEB3BAC
#define pinstCEverQuest_x                                          0xF681E0
#define pinstEverQuestInfo_x                                       0xEC1340
#define pinstCharData_x                                            0xEB3D44
#define pinstCharSpawn_x                                           0xEB1730
#define pinstControlledMissile_x                                   0xEB1B9C
#define pinstControlledPlayer_x                                    0xEB1730
#define pinstCResolutionHandler_x                                  0x15F8110
#define pinstCSidlManager_x                                        0x15F70A8
#define pinstCXWndManager_x                                        0x15F70A4
#define instDynamicZone_x                                          0xEB7A90
#define pinstDZMember_x                                            0xEB7BA0
#define pinstDZTimerInfo_x                                         0xEB7BA4
#define pinstEqLogin_x                                             0xF68268
#define instEQMisc_x                                               0xDFEDE8
#define pinstEQSoundManager_x                                      0xE01158
#define pinstEQSpellStrings_x                                      0xCC1858
#define instExpeditionLeader_x                                     0xEB7ADA
#define instExpeditionName_x                                       0xEB7B1A
#define pinstGroup_x                                               0xEB3D5E
#define pinstImeManager_x                                          0x15F70A0
#define pinstLocalPlayer_x                                         0xEB1658
#define pinstMercenaryData_x                                       0xF626BC
#define pinstMercenaryStats_x                                      0xF7B66C
#define pinstModelPlayer_x                                         0xEB1670
#define pinstPCData_x                                              0xEB3D44
#define pinstSkillMgr_x                                            0xF64828
#define pinstSpawnManager_x                                        0xF632D0
#define pinstSpellManager_x                                        0xF64A48
#define pinstSpellSets_x                                           0xF58D14
#define pinstStringTable_x                                         0xEB3D48
#define pinstSwitchManager_x                                       0xEB14F8
#define pinstTarget_x                                              0xEB16AC
#define pinstTargetObject_x                                        0xEB1738
#define pinstTargetSwitch_x                                        0xEB1BA4
#define pinstTaskMember_x                                          0xDFEC78
#define pinstTrackTarget_x                                         0xEB1734
#define pinstTradeTarget_x                                         0xEB166C
#define instTributeActive_x                                        0xDFEE09
#define pinstViewActor_x                                           0xDFEFF4
#define pinstWorldData_x                                           0xEB1B98
#define pinstZoneAddr_x                                            0xEC18C0
#define pinstPlayerPath_x                                          0xF63368
#define pinstTargetIndicator_x                                     0xF64CB0
#define EQObject_Top_x                                             0xEB1654
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDFF76C
#define pinstCAchievementsWnd_x                                    0xDFF768
#define pinstCActionsWnd_x                                         0xDFF52C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFEF9C
#define pinstCAdvancedLootWnd_x                                    0xDFEF60
#define pinstCAdventureLeaderboardWnd_x                            0xF72340
#define pinstCAdventureRequestWnd_x                                0xF723F0
#define pinstCAdventureStatsWnd_x                                  0xF724A0
#define pinstCAggroMeterWnd_x                                      0xDFF04C
#define pinstCAlarmWnd_x                                           0xDFF7C8
#define pinstCAlertHistoryWnd_x                                    0xDFEFBC
#define pinstCAlertStackWnd_x                                      0xDFF7D0
#define pinstCAlertWnd_x                                           0xDFEF40
#define pinstCAltStorageWnd_x                                      0xF72800
#define pinstCAudioTriggersWindow_x                                0xCB3B88
#define pinstCAuraWnd_x                                            0xDFEFDC
#define pinstCAvaZoneWnd_x                                         0xDFEFA0
#define pinstCBandolierWnd_x                                       0xDFF034
#define pinstCBankWnd_x                                            0xDFEFD8
#define pinstCBarterMerchantWnd_x                                  0xF73A40
#define pinstCBarterSearchWnd_x                                    0xF73AF0
#define pinstCBarterWnd_x                                          0xF73BA0
#define pinstCBazaarConfirmationWnd_x                              0xDFF794
#define pinstCBazaarSearchWnd_x                                    0xDFF508
#define pinstCBazaarWnd_x                                          0xDFF7B0
#define pinstCBlockedBuffWnd_x                                     0xDFEFE0
#define pinstCBlockedPetBuffWnd_x                                  0xDFF020
#define pinstCBodyTintWnd_x                                        0xDFF740
#define pinstCBookWnd_x                                            0xDFF06C
#define pinstCBreathWnd_x                                          0xDFF784
#define pinstCBuffWindowNORMAL_x                                   0xDFEFC0
#define pinstCBuffWindowSHORT_x                                    0xDFEFC4
#define pinstCBugReportWnd_x                                       0xDFEFCC
#define pinstCButtonWnd_x                                          0x15F7310
#define pinstCCastingWnd_x                                         0xDFF060
#define pinstCCastSpellWnd_x                                       0xDFF780
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDFF7B4
#define pinstCChatWindowManager_x                                  0xF74660
#define pinstCClaimWnd_x                                           0xF747B8
#define pinstCColorPickerWnd_x                                     0xDFF738
#define pinstCCombatAbilityWnd_x                                   0xDFF7C0
#define pinstCCombatSkillsSelectWnd_x                              0xDFEF48
#define pinstCCompassWnd_x                                         0xDFF534
#define pinstCConfirmationDialog_x                                 0xF796B8
#define pinstCContainerMgr_x                                       0xDFF7A8
#define pinstCContextMenuManager_x                                 0x15F7060
#define pinstCCursorAttachment_x                                   0xDFF054
#define pinstCDynamicZoneWnd_x                                     0xF74D80
#define pinstCEditLabelWnd_x                                       0xDFEFB8
#define pinstCEQMainWnd_x                                          0xF74FC8
#define pinstCEventCalendarWnd_x                                   0xDFF058
#define pinstCExtendedTargetWnd_x                                  0xDFF014
#define pinstCFacePick_x                                           0xDFEF58
#define pinstCFactionWnd_x                                         0xDFF7A4
#define pinstCFellowshipWnd_x                                      0xF751C8
#define pinstCFileSelectionWnd_x                                   0xDFF05C
#define pinstCFindItemWnd_x                                        0xDFF790
#define pinstCFindLocationWnd_x                                    0xF75320
#define pinstCFriendsWnd_x                                         0xDFEF5C
#define pinstCGemsGameWnd_x                                        0xDFF7A0
#define pinstCGiveWnd_x                                            0xDFF7CC
#define pinstCGroupSearchFiltersWnd_x                              0xDFF064
#define pinstCGroupSearchWnd_x                                     0xF75718
#define pinstCGroupWnd_x                                           0xF757C8
#define pinstCGuildBankWnd_x                                       0xEC2704
#define pinstCGuildCreationWnd_x                                   0xF75928
#define pinstCGuildMgmtWnd_x                                       0xF759D8
#define pinstCharacterCreation_x                                   0xDFEF50
#define pinstCHelpWnd_x                                            0xDFEF94
#define pinstCHeritageSelectionWnd_x                               0xDFEF64
#define pinstCHotButtonWnd_x                                       0xF77B30
#define pinstCHotButtonWnd1_x                                      0xF77B30
#define pinstCHotButtonWnd2_x                                      0xF77B34
#define pinstCHotButtonWnd3_x                                      0xF77B38
#define pinstCHotButtonWnd4_x                                      0xF77B3C
#define pinstCIconSelectionWnd_x                                   0xDFF050
#define pinstCInspectWnd_x                                         0xDFEF90
#define pinstCInventoryWnd_x                                       0xDFEF68
#define pinstCInvSlotMgr_x                                         0xDFF764
#define pinstCItemDisplayManager_x                                 0xF780C0
#define pinstCItemExpTransferWnd_x                                 0xF781F0
#define pinstCItemOverflowWnd_x                                    0xDFF50C
#define pinstCJournalCatWnd_x                                      0xDFF0E4
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDFF018
#define pinstCKeyRingWnd_x                                         0xDFEFB4
#define pinstCLargeDialogWnd_x                                     0xF7A338
#define pinstCLayoutCopyWnd_x                                      0xF78540
#define pinstCLFGuildWnd_x                                         0xF785F0
#define pinstCLoadskinWnd_x                                        0xDFF7AC
#define pinstCLootFiltersCopyWnd_x                                 0xCD0180
#define pinstCLootFiltersWnd_x                                     0xDFF7D4
#define pinstCLootSettingsWnd_x                                    0xDFEF54
#define pinstCLootWnd_x                                            0xDFF4EC
#define pinstCMailAddressBookWnd_x                                 0xDFF774
#define pinstCMailCompositionWnd_x                                 0xDFF750
#define pinstCMailIgnoreListWnd_x                                  0xDFF778
#define pinstCMailWnd_x                                            0xDFF528
#define pinstCManageLootWnd_x                                      0xE00638
#define pinstCMapToolbarWnd_x                                      0xDFEF98
#define pinstCMapViewWnd_x                                         0xDFEF74
#define pinstCMarketplaceWnd_x                                     0xDFF7D8
#define pinstCMerchantWnd_x                                        0xDFF4F0
#define pinstCMIZoneSelectWnd_x                                    0xF78E28
#define pinstCMusicPlayerWnd_x                                     0xDFF4F8
#define pinstCNameChangeMercWnd_x                                  0xDFF78C
#define pinstCNameChangePetWnd_x                                   0xDFF770
#define pinstCNameChangeWnd_x                                      0xDFF79C
#define pinstCNoteWnd_x                                            0xDFEF78
#define pinstCObjectPreviewWnd_x                                   0xDFEF4C
#define pinstCOptionsWnd_x                                         0xDFEF80
#define pinstCPetInfoWnd_x                                         0xDFF510
#define pinstCPetitionQWnd_x                                       0xDFF75C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDFF744
#define pinstCPlayerWnd_x                                          0xDFF518
#define pinstCPopupWndManager_x                                    0xF796B8
#define pinstCProgressionSelectionWnd_x                            0xF79768
#define pinstCPurchaseGroupWnd_x                                   0xDFEF84
#define pinstCPurchaseWnd_x                                        0xDFEF6C
#define pinstCPvPLeaderboardWnd_x                                  0xF79818
#define pinstCPvPStatsWnd_x                                        0xF798C8
#define pinstCQuantityWnd_x                                        0xDFF01C
#define pinstCRaceChangeWnd_x                                      0xDFF7C4
#define pinstCRaidOptionsWnd_x                                     0xDFF068
#define pinstCRaidWnd_x                                            0xDFF758
#define pinstCRealEstateItemsWnd_x                                 0xDFF760
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDFF4F4
#define pinstCRealEstateManageWnd_x                                0xDFEF8C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFEFB0
#define pinstCRealEstatePlotSearchWnd_x                            0xDFEFD0
#define pinstCRealEstatePurchaseWnd_x                              0xDFEFF0
#define pinstCRespawnWnd_x                                         0xDFEFEC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDFF77C
#define pinstCSendMoneyWnd_x                                       0xDFEF44
#define pinstCServerListWnd_x                                      0xDFF048
#define pinstCSkillsSelectWnd_x                                    0xDFF7B8
#define pinstCSkillsWnd_x                                          0xDFF798
#define pinstCSocialEditWnd_x                                      0xDFEFAC
#define pinstCSocialWnd_x                                          0xDFF788
#define pinstCSpellBookWnd_x                                       0xDFF7BC
#define pinstCStoryWnd_x                                           0xDFF51C
#define pinstCTargetOfTargetWnd_x                                  0xF7B6F0
#define pinstCTargetWnd_x                                          0xDFEFE8
#define pinstCTaskOverlayWnd_x                                     0xDFEF7C
#define pinstCTaskSelectWnd_x                                      0xF7B848
#define pinstCTaskManager_x                                        0xCD0AC0
#define pinstCTaskTemplateSelectWnd_x                              0xF7B8F8
#define pinstCTaskWnd_x                                            0xF7B9A8
#define pinstCTextEntryWnd_x                                       0xDFEFC8
#define pinstCTimeLeftWnd_x                                        0xDFF524
#define pinstCTipWndCONTEXT_x                                      0xF7BBAC
#define pinstCTipWndOFDAY_x                                        0xF7BBA8
#define pinstCTitleWnd_x                                           0xF7BC58
#define pinstCTrackingWnd_x                                        0xDFEF70
#define pinstCTradeskillWnd_x                                      0xF7BDC0
#define pinstCTradeWnd_x                                           0xDFF74C
#define pinstCTrainWnd_x                                           0xDFF748
#define pinstCTributeBenefitWnd_x                                  0xF7BFC0
#define pinstCTributeMasterWnd_x                                   0xF7C070
#define pinstCTributeTrophyWnd_x                                   0xF7C120
#define pinstCVideoModesWnd_x                                      0xDFF520
#define pinstCVoiceMacroWnd_x                                      0xF65418
#define pinstCVoteResultsWnd_x                                     0xDFF754
#define pinstCVoteWnd_x                                            0xDFF73C
#define pinstCWebManager_x                                         0xF65A94
#define pinstCZoneGuideWnd_x                                       0xDFEF88
#define pinstCZonePathWnd_x                                        0xDFEFA4

#define pinstEQSuiteTextureLoader_x                                0xC9E080
#define pinstItemIconCache_x                                       0xF74F80
#define pinstLootFiltersManager_x                                  0xCD0230
#define pinstRewardSelectionWnd_x                                  0xF7A010

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AEC40
#define __CastRay2_x                                               0x5AEC90
#define __ConvertItemTags_x                                        0x5CA7F0
#define __CleanItemTags_x                                          0x47D2B0
#define __DoesFileExist_x                                          0x903AA0
#define __EQGetTime_x                                              0x900490
#define __ExecuteCmd_x                                             0x5A7510
#define __FixHeading_x                                             0x99B300
#define __GameLoop_x                                               0x6BB3E0
#define __get_bearing_x                                            0x5AE7B0
#define __get_melee_range_x                                        0x5AEE80
#define __GetAnimationCache_x                                      0x720610
#define __GetGaugeValueFromEQ_x                                    0x812EB0
#define __GetLabelFromEQ_x                                         0x814990
#define __GetXTargetType_x                                         0x99CCE0
#define __HandleMouseWheel_x                                       0x6BC2A0
#define __HeadingDiff_x                                            0x99B370
#define __HelpPath_x                                               0xF607BC
#define __LoadFrontEnd_x                                           0x6B8700
#define __NewUIINI_x                                               0x812B80
#define __ProcessGameEvents_x                                      0x60EC70
#define __ProcessMouseEvent_x                                      0x60E430
#define __SaveColors_x                                             0x551790
#define __STMLToText_x                                             0x93E7E0
#define __ToggleKeyRingItem_x                                      0x514F60
#define CMemoryMappedFile__SetFile_x                               0xA8A720
#define CrashDetected_x                                            0x6BA1A0
#define DrawNetStatus_x                                            0x63AB40
#define Expansion_HoT_x                                            0xEC270C
#define Teleport_Table_Size_x                                      0xEB1740
#define Teleport_Table_x                                           0xEB1BA8
#define Util__FastTime_x                                           0x900060

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4993D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4991A0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A60
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492EB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559340
#define AltAdvManager__IsAbilityReady_x                            0x558270
#define AltAdvManager__GetAAById_x                                 0x558470
#define AltAdvManager__CanTrainAbility_x                           0x5584E0
#define AltAdvManager__CanSeeAbility_x                             0x558840

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA440
#define CharacterZoneClient__HasSkill_x                            0x4D5330
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6A50
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE6B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BACB0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9410
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D94F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D95D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C34B0
#define CharacterZoneClient__BardCastBard_x                        0x4C6010
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAD80
#define CharacterZoneClient__GetEffect_x                           0x4BABF0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4500
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C45D0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4620
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4770
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4940
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2B10
#define CharacterZoneClient__FindItemByGuid_x                      0x4D79B0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7430

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E1D80
#define CBankWnd__WndNotification_x                                0x6E1B60

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EF790

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61D380
#define CButtonWnd__CButtonWnd_x                                   0x93ABD0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70F740
#define CChatManager__InitContextMenu_x                            0x7088A0
#define CChatManager__FreeChatWindow_x                             0x70E280
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E89E0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70F3C0
#define CChatManager__CreateChatWindow_x                           0x70E8C0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8AF0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94F230
#define CContextMenu__dCContextMenu_x                              0x94F460
#define CContextMenu__AddMenuItem_x                                0x94F470
#define CContextMenu__RemoveMenuItem_x                             0x94F780
#define CContextMenu__RemoveAllMenuItems_x                         0x94F7A0
#define CContextMenu__CheckMenuItem_x                              0x94F820
#define CContextMenu__SetMenuItem_x                                0x94F6A0
#define CContextMenu__AddSeparator_x                               0x94F600

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94FDC0
#define CContextMenuManager__RemoveMenu_x                          0x94FE30
#define CContextMenuManager__PopupMenu_x                           0x94FEF0
#define CContextMenuManager__Flush_x                               0x94FD60
#define CContextMenuManager__GetMenu_x                             0x49B6C0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71AE10

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DC150
#define CChatService__GetFriendName_x                              0x8DC160

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70FF70
#define CChatWindow__Clear_x                                       0x711230
#define CChatWindow__WndNotification_x                             0x7119C0
#define CChatWindow__AddHistory_x                                  0x710AF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94C680
#define CComboWnd__Draw_x                                          0x94BB80
#define CComboWnd__GetCurChoice_x                                  0x94C4C0
#define CComboWnd__GetListRect_x                                   0x94C030
#define CComboWnd__GetTextRect_x                                   0x94C6F0
#define CComboWnd__InsertChoice_x                                  0x94C1C0
#define CComboWnd__SetColors_x                                     0x94C190
#define CComboWnd__SetChoice_x                                     0x94C490
#define CComboWnd__GetItemCount_x                                  0x94C4D0
#define CComboWnd__GetCurChoiceText_x                              0x94C510
#define CComboWnd__GetChoiceText_x                                 0x94C4E0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94C250

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x718810
#define CContainerWnd__vftable_x                                   0xB1146C
#define CContainerWnd__SetContainer_x                              0x719D70

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54C1D0
#define CDisplay__PreZoneMainUI_x                                  0x54C1E0
#define CDisplay__CleanGameUI_x                                    0x551550
#define CDisplay__GetClickedActor_x                                0x5444F0
#define CDisplay__GetUserDefinedColor_x                            0x53CBB0
#define CDisplay__GetWorldFilePath_x                               0x545F60
#define CDisplay__is3dON_x                                         0x541150
#define CDisplay__ReloadUI_x                                       0x54B660
#define CDisplay__WriteTextHD2_x                                   0x540F40
#define CDisplay__TrueDistance_x                                   0x547C20
#define CDisplay__SetViewActor_x                                   0x543E10
#define CDisplay__GetFloorHeight_x                                 0x541210
#define CDisplay__SetRenderWindow_x                                0x53FB70
#define CDisplay__ToggleScreenshotMode_x                           0x5438E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96EEE0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x95275F
#define CEditWnd__GetCharIndexPt_x                                 0x953690
#define CEditWnd__GetDisplayString_x                               0x953540
#define CEditWnd__GetHorzOffset_x                                  0x951DB0
#define CEditWnd__GetLineForPrintableChar_x                        0x954800
#define CEditWnd__GetSelStartPt_x                                  0x953940
#define CEditWnd__GetSTMLSafeText_x                                0x953360
#define CEditWnd__PointFromPrintableChar_x                         0x954440
#define CEditWnd__SelectableCharFromPoint_x                        0x9545B0
#define CEditWnd__SetEditable_x                                    0x953A00
#define CEditWnd__SetWindowTextA_x                                 0x9530E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FC8D0
#define CEverQuest__ClickedPlayer_x                                0x5EE8E0
#define CEverQuest__CreateTargetIndicator_x                        0x60BF00
#define CEverQuest__DeleteTargetIndicator_x                        0x60BF90
#define CEverQuest__DoTellWindow_x                                 0x4E8BD0
#define CEverQuest__OutputTextToLog_x                              0x4E8E50
#define CEverQuest__DropHeldItemOnGround_x                         0x5E3920
#define CEverQuest__dsp_chat_x                                     0x4E91E0
#define CEverQuest__trimName_x                                     0x6081E0
#define CEverQuest__Emote_x                                        0x5FD130
#define CEverQuest__EnterZone_x                                    0x5F70B0
#define CEverQuest__GetBodyTypeDesc_x                              0x601AA0
#define CEverQuest__GetClassDesc_x                                 0x6020E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6026E0
#define CEverQuest__GetDeityDesc_x                                 0x60A840
#define CEverQuest__GetLangDesc_x                                  0x6028A0
#define CEverQuest__GetRaceDesc_x                                  0x6020C0
#define CEverQuest__InterpretCmd_x                                 0x60AE10
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E7B20
#define CEverQuest__LMouseUp_x                                     0x5E5EB0
#define CEverQuest__RightClickedOnPlayer_x                         0x5E8400
#define CEverQuest__RMouseUp_x                                     0x5E6E30
#define CEverQuest__SetGameState_x                                 0x5E36B0
#define CEverQuest__UPCNotificationFlush_x                         0x6080E0
#define CEverQuest__IssuePetCommand_x                              0x603CA0
#define CEverQuest__ReportSuccessfulHit_x                          0x5FE520

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72A650
#define CGaugeWnd__CalcLinesFillRect_x                             0x72A6B0
#define CGaugeWnd__Draw_x                                          0x729CD0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF540
#define CGuild__GetGuildName_x                                     0x4AE620
#define CGuild__GetGuildIndex_x                                    0x4AE9B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x745AF0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61D740

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x752B20
#define CInvSlotMgr__MoveItem_x                                    0x751830
#define CInvSlotMgr__SelectSlot_x                                  0x752BF0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7500B0
#define CInvSlot__SliderComplete_x                                 0x74DE00
#define CInvSlot__GetItemBase_x                                    0x74D780
#define CInvSlot__UpdateItem_x                                     0x74D8F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x754670
#define CInvSlotWnd__CInvSlotWnd_x                                 0x753810
#define CInvSlotWnd__HandleLButtonUp_x                             0x7541F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80E1E0
#define CItemDisplayWnd__UpdateStrings_x                           0x762CE0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75CA60
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75CF70
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7632F0
#define CItemDisplayWnd__AboutToShow_x                             0x762930
#define CItemDisplayWnd__WndNotification_x                         0x7643E0
#define CItemDisplayWnd__RequestConvertItem_x                      0x763EA0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7619A0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x762750

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x846AB0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x768910

// CLabel 
#define CLabel__Draw_x                                             0x76E3B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x924E70
#define CListWnd__dCListWnd_x                                      0x925190
#define CListWnd__AddColumn_x                                      0x9295E0
#define CListWnd__AddColumn1_x                                     0x929630
#define CListWnd__AddLine_x                                        0x9299C0
#define CListWnd__AddString_x                                      0x9297C0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9293B0
#define CListWnd__CalculateVSBRange_x                              0x9291A0
#define CListWnd__ClearSel_x                                       0x92A1A0
#define CListWnd__ClearAllSel_x                                    0x92A200
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92AC00
#define CListWnd__Compare_x                                        0x928AD0
#define CListWnd__Draw_x                                           0x9252C0
#define CListWnd__DrawColumnSeparators_x                           0x927AA0
#define CListWnd__DrawHeader_x                                     0x927F10
#define CListWnd__DrawItem_x                                       0x928410
#define CListWnd__DrawLine_x                                       0x927C10
#define CListWnd__DrawSeparator_x                                  0x927B40
#define CListWnd__EnableLine_x                                     0x927380
#define CListWnd__EnsureVisible_x                                  0x92AB30
#define CListWnd__ExtendSel_x                                      0x92A0D0
#define CListWnd__GetColumnTooltip_x                               0x926EC0
#define CListWnd__GetColumnMinWidth_x                              0x926F30
#define CListWnd__GetColumnWidth_x                                 0x926E30
#define CListWnd__GetCurSel_x                                      0x9267C0
#define CListWnd__GetItemAtPoint_x                                 0x9275F0
#define CListWnd__GetItemAtPoint1_x                                0x927660
#define CListWnd__GetItemData_x                                    0x926840
#define CListWnd__GetItemHeight_x                                  0x926C00
#define CListWnd__GetItemIcon_x                                    0x9269D0
#define CListWnd__GetItemRect_x                                    0x927470
#define CListWnd__GetItemText_x                                    0x926880
#define CListWnd__GetSelList_x                                     0x92A250
#define CListWnd__GetSeparatorRect_x                               0x9278A0
#define CListWnd__InsertLine_x                                     0x929DB0
#define CListWnd__RemoveLine_x                                     0x929F00
#define CListWnd__SetColors_x                                      0x929170
#define CListWnd__SetColumnJustification_x                         0x928EA0
#define CListWnd__SetColumnWidth_x                                 0x928DC0
#define CListWnd__SetCurSel_x                                      0x92A010
#define CListWnd__SetItemColor_x                                   0x92A7F0
#define CListWnd__SetItemData_x                                    0x92A7B0
#define CListWnd__SetItemText_x                                    0x92A3C0
#define CListWnd__ShiftColumnSeparator_x                           0x928F60
#define CListWnd__Sort_x                                           0x928C50
#define CListWnd__ToggleSel_x                                      0x92A040
#define CListWnd__SetColumnsSizable_x                              0x929010
#define CListWnd__SetItemWnd_x                                     0x92A670
#define CListWnd__GetItemWnd_x                                     0x926A20
#define CListWnd__SetItemIcon_x                                    0x92A440
#define CListWnd__CalculateCustomWindowPositions_x                 0x9294A0
#define CListWnd__SetVScrollPos_x                                  0x928DA0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x783BC0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7822D0
#define CMapViewWnd__HandleLButtonDown_x                           0x77F310

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A3C30
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A4510
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A4A40
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A79C0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A2790
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AD570
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A3840

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A9C10
#define CPacketScrambler__hton_x                                   0x8A9C00

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x943E10
#define CSidlManager__FindScreenPieceTemplate_x                    0x944220
#define CSidlManager__FindScreenPieceTemplate1_x                   0x944010
#define CSidlManager__CreateLabel_x                                0x805680
#define CSidlManager__CreateXWndFromTemplate_x                     0x947180
#define CSidlManager__CreateXWndFromTemplate1_x                    0x947360
#define CSidlManager__CreateXWnd_x                                 0x8055B0
#define CSidlManager__CreateHotButtonWnd_x                         0x805B70

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x940900
#define CSidlScreenWnd__CalculateVSBRange_x                        0x940800
#define CSidlScreenWnd__ConvertToRes_x                             0x965ED0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9402A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93FF90
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x940060
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x940130
#define CSidlScreenWnd__DrawSidlPiece_x                            0x940D90
#define CSidlScreenWnd__EnableIniStorage_x                         0x941260
#define CSidlScreenWnd__GetSidlPiece_x                             0x940F80
#define CSidlScreenWnd__Init1_x                                    0x93FB90
#define CSidlScreenWnd__LoadIniInfo_x                              0x9412B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x941DF0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93EF90
#define CSidlScreenWnd__StoreIniInfo_x                             0x941970
#define CSidlScreenWnd__StoreIniVis_x                              0x941CD0
#define CSidlScreenWnd__WndNotification_x                          0x940CA0
#define CSidlScreenWnd__GetChildItem_x                             0x9411E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x930A50
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F6F30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x681FF0
#define CSkillMgr__GetSkillCap_x                                   0x6821D0
#define CSkillMgr__GetNameToken_x                                  0x681770
#define CSkillMgr__IsActivatedSkill_x                              0x6818B0
#define CSkillMgr__IsCombatSkill_x                                 0x6817F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x950B90
#define CSliderWnd__SetValue_x                                     0x950A00
#define CSliderWnd__SetNumTicks_x                                  0x950A60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80B680

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x959320
#define CStmlWnd__CalculateHSBRange_x                              0x95A430
#define CStmlWnd__CalculateVSBRange_x                              0x95A3B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x95E760
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95F3F0
#define CStmlWnd__ForceParseNow_x                                  0x959910
#define CStmlWnd__GetNextTagPiece_x                                0x95E6C0
#define CStmlWnd__GetSTMLText_x                                    0x504950
#define CStmlWnd__GetVisibleText_x                                 0x959930
#define CStmlWnd__InitializeWindowVariables_x                      0x95F240
#define CStmlWnd__MakeStmlColorTag_x                               0x958990
#define CStmlWnd__MakeWndNotificationTag_x                         0x958A00
#define CStmlWnd__SetSTMLText_x                                    0x957A40
#define CStmlWnd__StripFirstSTMLLines_x                            0x9604E0
#define CStmlWnd__UpdateHistoryString_x                            0x95F600

// CTabWnd 
#define CTabWnd__Draw_x                                            0x956B90
#define CTabWnd__DrawCurrentPage_x                                 0x9572C0
#define CTabWnd__DrawTab_x                                         0x956FE0
#define CTabWnd__GetCurrentPage_x                                  0x9563A0
#define CTabWnd__GetPageInnerRect_x                                0x9565E0
#define CTabWnd__GetTabInnerRect_x                                 0x956520
#define CTabWnd__GetTabRect_x                                      0x9563D0
#define CTabWnd__InsertPage_x                                      0x9567F0
#define CTabWnd__SetPage_x                                         0x956660
#define CTabWnd__SetPageRect_x                                     0x956AD0
#define CTabWnd__UpdatePage_x                                      0x956EA0
#define CTabWnd__GetPageFromTabIndex_x                             0x956F20
#define CTabWnd__GetCurrentTabIndex_x                              0x956390

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x768D40
#define CPageWnd__SetTabText_x                                     0x955EF0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A91B0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92D910
#define CTextureFont__GetTextExtent_x                              0x92DAD0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B52D0
#define CHtmlComponentWnd__ValidateUri_x                           0x7474E0
#define CHtmlWnd__SetClientCallbacks_x                             0x6227E0
#define CHtmlWnd__AddObserver_x                                    0x622800
#define CHtmlWnd__RemoveObserver_x                                 0x622860
#define Window__getProgress_x                                      0x85F390
#define Window__getStatus_x                                        0x85F3B0
#define Window__getURI_x                                           0x85F3C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96B970

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91A980

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8820
#define CXStr__CXStr1_x                                            0x4FF9B0
#define CXStr__CXStr3_x                                            0x8FC5D0
#define CXStr__dCXStr_x                                            0x4787B0
#define CXStr__operator_equal_x                                    0x8FC800
#define CXStr__operator_equal1_x                                   0x8FC840
#define CXStr__operator_plus_equal1_x                              0x8FD2D0
#define CXStr__SetString_x                                         0x8FF1C0
#define CXStr__operator_char_p_x                                   0x8FCD40
#define CXStr__GetChar_x                                           0x8FEB10
#define CXStr__Delete_x                                            0x8FE3C0
#define CXStr__GetUnicode_x                                        0x8FEB80
#define CXStr__GetLength_x                                         0x47D660
#define CXStr__Mid_x                                               0x47D670
#define CXStr__Insert_x                                            0x8FEBE0
#define CXStr__FindNext_x                                          0x8FE830

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94EE40
#define CXWnd__BringToTop_x                                        0x934200
#define CXWnd__Center_x                                            0x933D80
#define CXWnd__ClrFocus_x                                          0x933B90
#define CXWnd__Destroy_x                                           0x933C40
#define CXWnd__DoAllDrawing_x                                      0x930200
#define CXWnd__DrawChildren_x                                      0x9301D0
#define CXWnd__DrawColoredRect_x                                   0x930640
#define CXWnd__DrawTooltip_x                                       0x92ED20
#define CXWnd__DrawTooltipAtPoint_x                                0x92EDE0
#define CXWnd__GetBorderFrame_x                                    0x9304A0
#define CXWnd__GetChildWndAt_x                                     0x9342A0
#define CXWnd__GetClientClipRect_x                                 0x932490
#define CXWnd__GetScreenClipRect_x                                 0x932540
#define CXWnd__GetScreenRect_x                                     0x9326F0
#define CXWnd__GetTooltipRect_x                                    0x930690
#define CXWnd__GetWindowTextA_x                                    0x49CDB0
#define CXWnd__IsActive_x                                          0x930DC0
#define CXWnd__IsDescendantOf_x                                    0x933100
#define CXWnd__IsReallyVisible_x                                   0x933130
#define CXWnd__IsType_x                                            0x934910
#define CXWnd__Move_x                                              0x9331A0
#define CXWnd__Move1_x                                             0x933250
#define CXWnd__ProcessTransition_x                                 0x933D30
#define CXWnd__Refade_x                                            0x933520
#define CXWnd__Resize_x                                            0x9337B0
#define CXWnd__Right_x                                             0x933FC0
#define CXWnd__SetFocus_x                                          0x933B50
#define CXWnd__SetFont_x                                           0x933BC0
#define CXWnd__SetKeyTooltip_x                                     0x934720
#define CXWnd__SetMouseOver_x                                      0x931600
#define CXWnd__StartFade_x                                         0x932FE0
#define CXWnd__GetChildItem_x                                      0x934410
#define CXWnd__SetParent_x                                         0x932E90
#define CXWnd__Minimize_x                                          0x933820

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x966F50

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x937170
#define CXWndManager__DrawWindows_x                                0x937190
#define CXWndManager__GetKeyboardFlags_x                           0x939880
#define CXWndManager__HandleKeyboardMsg_x                          0x939440
#define CXWndManager__RemoveWnd_x                                  0x939AA0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93A000

// CDBStr
#define CDBStr__GetString_x                                        0x53BB60

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBC90
#define EQ_Character__Cur_HP_x                                     0x4D2370
#define EQ_Character__Cur_Mana_x                                   0x4D9AD0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BED00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2750
#define EQ_Character__GetFocusRangeModifier_x                      0x4B28A0
#define EQ_Character__GetHPRegen_x                                 0x4DF8A0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFEA0
#define EQ_Character__GetManaRegen_x                               0x4E02E0
#define EQ_Character__Max_Endurance_x                              0x6488B0
#define EQ_Character__Max_HP_x                                     0x4D21A0
#define EQ_Character__Max_Mana_x                                   0x6486B0
#define EQ_Character__doCombatAbility_x                            0x64AD10
#define EQ_Character__UseSkill_x                                   0x4E20C0
#define EQ_Character__GetConLevel_x                                0x641A90
#define EQ_Character__IsExpansionFlag_x                            0x5A5C90
#define EQ_Character__TotalEffect_x                                0x4C5750
#define EQ_Character__GetPCSpellAffect_x                           0x4BFA50
#define EQ_Character__SpellDuration_x                              0x4BF580
#define EQ_Character__GetAdjustedSkill_x                           0x4D50F0
#define EQ_Character__GetBaseSkill_x                               0x4D6090
#define EQ_Character__CanUseItem_x                                 0x4D9DE0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C8FB0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65EDE0

//PcClient
#define PcClient__PcClient_x                                       0x63F1D0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B98C0
#define CCharacterListWnd__EnterWorld_x                            0x4B9300
#define CCharacterListWnd__Quit_x                                  0x4B9050
#define CCharacterListWnd__UpdateList_x                            0x4B9490

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x623A30
#define EQ_Item__CreateItemTagString_x                             0x8A33F0
#define EQ_Item__IsStackable_x                                     0x8A7FC0
#define EQ_Item__GetImageNum_x                                     0x8A4EA0
#define EQ_Item__CreateItemClient_x                                0x622C00
#define EQ_Item__GetItemValue_x                                    0x8A61D0
#define EQ_Item__ValueSellMerchant_x                               0x8A97F0
#define EQ_Item__IsKeyRingItem_x                                   0x8A78E0
#define EQ_Item__CanGoInBag_x                                      0x623B50
#define EQ_Item__IsEmpty_x                                         0x8A7410
#define EQ_Item__GetMaxItemCount_x                                 0x8A65E0
#define EQ_Item__GetHeldItem_x                                     0x8A4D70
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A2D60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55A010
#define EQ_LoadingS__Array_x                                       0xC25B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x649210
#define EQ_PC__GetAlternateAbilityId_x                             0x8B2A10
#define EQ_PC__GetCombatAbility_x                                  0x8B3080
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B30F0
#define EQ_PC__GetItemRecastTimer_x                                0x64B290
#define EQ_PC__HasLoreItem_x                                       0x642250
#define EQ_PC__AlertInventoryChanged_x                             0x6413D0
#define EQ_PC__GetPcZoneClient_x                                   0x66D840
#define EQ_PC__RemoveMyAffect_x                                    0x64E4C0
#define EQ_PC__GetKeyRingItems_x                                   0x8B3980
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B3710
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B3C80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AC240
#define EQItemList__add_object_x                                   0x5D9130
#define EQItemList__add_item_x                                     0x5AC7A0
#define EQItemList__delete_item_x                                  0x5AC7F0
#define EQItemList__FreeItemList_x                                 0x5AC6F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538650

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x660660
#define EQPlayer__dEQPlayer_x                                      0x6539A0
#define EQPlayer__DoAttack_x                                       0x6684D0
#define EQPlayer__EQPlayer_x                                       0x654060
#define EQPlayer__SetNameSpriteState_x                             0x658340
#define EQPlayer__SetNameSpriteTint_x                              0x659210
#define PlayerBase__HasProperty_j_x                                0x9996F0
#define EQPlayer__IsTargetable_x                                   0x999B90
#define EQPlayer__CanSee_x                                         0x9999F0
#define EQPlayer__CanSee1_x                                        0x999AC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9997B0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66B2D0
#define PlayerZoneClient__GetLevel_x                               0x66D880
#define PlayerZoneClient__IsValidTeleport_x                        0x5DA2A0
#define PlayerZoneClient__LegalPlayerRace_x                        0x5533B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6633B0
#define EQPlayerManager__GetSpawnByName_x                          0x663460
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6634F0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6271A0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x627220
#define KeypressHandler__AttachKeyToEqCommand_x                    0x627260
#define KeypressHandler__ClearCommandStateArray_x                  0x628670
#define KeypressHandler__HandleKeyDown_x                           0x628690
#define KeypressHandler__HandleKeyUp_x                             0x628730
#define KeypressHandler__SaveKeymapping_x                          0x628B80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77FA30
#define MapViewMap__SaveEx_x                                       0x782DF0
#define MapViewMap__SetZoom_x                                      0x7874B0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C6EA0

// StringTable 
#define StringTable__getString_x                                   0x8C1CC0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64E130
#define PcZoneClient__RemovePetEffect_x                            0x64E760
#define PcZoneClient__HasAlternateAbility_x                        0x6484E0
#define PcZoneClient__GetCurrentMod_x                              0x4E5180
#define PcZoneClient__GetModCap_x                                  0x4E5080
#define PcZoneClient__CanEquipItem_x                               0x648BB0
#define PcZoneClient__GetItemByID_x                                0x64B700
#define PcZoneClient__GetItemByItemClass_x                         0x64B850
#define PcZoneClient__RemoveBuffEffect_x                           0x64E780
#define PcZoneClient__BandolierSwap_x                              0x6497D0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64B230

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DEE20

//IconCache
#define IconCache__GetIcon_x                                       0x71FEB0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7179B0
#define CContainerMgr__CloseContainer_x                            0x717C80
#define CContainerMgr__OpenExperimentContainer_x                   0x718700

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D7BA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61BB10

//CLootWnd
#define CLootWnd__LootAll_x                                        0x775E80
#define CLootWnd__RequestLootSlot_x                                0x7750B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x579B20
#define EQ_Spell__SpellAffects_x                                   0x579F90
#define EQ_Spell__SpellAffectBase_x                                0x579D50
#define EQ_Spell__IsStackable_x                                    0x4C9DC0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9C40
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6C40
#define EQ_Spell__IsSPAStacking_x                                  0x57ADE0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A2F0
#define EQ_Spell__IsNoRemove_x                                     0x4C9DA0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57ADF0
#define __IsResEffectSpell_x                                       0x4C9190

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD270

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D1510

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81E9B0
#define CTargetWnd__WndNotification_x                              0x81E240
#define CTargetWnd__RefreshTargetBuffs_x                           0x81E510
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81D3B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x822FB0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536050
#define CTaskManager__HandleMessage_x                              0x534500
#define CTaskManager__GetTaskStatus_x                              0x536100
#define CTaskManager__GetElementDescription_x                      0x536180

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575010
#define EqSoundManager__PlayScriptMp3_x                            0x575170
#define EqSoundManager__SoundAssistPlay_x                          0x685F20
#define EqSoundManager__WaveInstancePlay_x                         0x685490

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x529DF0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x955400

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x561AC0
#define CAltAbilityData__GetMercMaxRank_x                          0x561A50
#define CAltAbilityData__GetMaxRank_x                              0x5570F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x619C30

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9C20
#define CharacterBase__CreateItemGlobalIndex_x                     0x5115B0
#define CharacterBase__CreateItemIndex_x                           0x621D90
#define CharacterBase__GetItemPossession_x                         0x4FD1F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D9B10
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D9B70
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FEAC0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FF2F0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FF3A0

//messages
#define msg_spell_worn_off_x                                       0x59DE90
#define msg_new_text_x                                             0x592C20
#define __msgTokenTextParam_x                                      0x5A03C0
#define msgTokenText_x                                             0x5A0610

//SpellManager
#define SpellManager__vftable_x                                    0xAEB4C0
#define SpellManager__SpellManager_x                               0x689250
#define Spellmanager__LoadTextSpells_x                             0x689B40
#define SpellManager__GetSpellByGroupAndRank_x                     0x689420

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99D5D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x511C40
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A41B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63A9A0
#define ItemGlobalIndex__IsValidIndex_x                            0x511CA0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D1EB0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D2130

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76E6F0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71C0C0
#define CCursorAttachment__AttachToCursor1_x                       0x71C100
#define CCursorAttachment__Deactivate_x                            0x71D0E0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9481B0
#define CSidlManagerBase__CreatePageWnd_x                          0x9479B0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x943C30
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x943BC0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x965550
#define CEQSuiteTextureLoader__GetTexture_x                        0x965210

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50EB50
#define CFindItemWnd__WndNotification_x                            0x50F630
#define CFindItemWnd__Update_x                                     0x5101A0
#define CFindItemWnd__PickupSelectedItem_x                         0x50E3A0

//IString
#define IString__Append_x                                          0x4F0790

//Camera
#define CDisplay__cameraType_x                                     0xDFF530
#define EverQuest__Cameras_x                                       0xEC2A5C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517300
#define LootFiltersManager__GetItemFilterData_x                    0x516C00
#define LootFiltersManager__RemoveItemLootFilter_x                 0x516C30
#define LootFiltersManager__SetItemLootFilter_x                    0x516E50

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C5B70

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A3240
#define CResolutionHandler__GetWindowedStyle_x                     0x680A50

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7146D0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E6B90
#define CDistillerInfo__Instance_x                                 0x8E6B30

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7348B0
#define CGroupWnd__UpdateDisplay_x                                 0x733C10

//ItemBase
#define ItemBase__IsLore_x                                         0x8A7990
#define ItemBase__IsLoreEquipped_x                                 0x8A7A00

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D9090
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D91D0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D9230

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x675F50
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6798D0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x504F50

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2300
#define FactionManagerClient__HandleFactionMessage_x               0x4F2970
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2F30
#define FactionManagerClient__GetMaxFaction_x                      0x4F2F4F
#define FactionManagerClient__GetMinFaction_x                      0x4F2F00

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD1C0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92C8C0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C0C0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD4E0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x560F70

//CTargetManager
#define CTargetManager__Get_x                                      0x68CAB0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x675F50

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8F70

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AC690

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF600F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
