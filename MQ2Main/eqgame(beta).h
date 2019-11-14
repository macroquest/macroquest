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
#define __ExpectedVersionDate                                     "Nov 14 2019"
#define __ExpectedVersionTime                                     "04:22:38"
#define __ActualVersionDate_x                                      0xB08254
#define __ActualVersionTime_x                                      0xB08248
#define __ActualVersionBuild_x                                     0xAF3F44

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62E380
#define __MemChecker1_x                                            0x900D40
#define __MemChecker2_x                                            0x6BC8B0
#define __MemChecker3_x                                            0x6BC800
#define __MemChecker4_x                                            0x857F70
#define __EncryptPad0_x                                            0xC3E3E8
#define __EncryptPad1_x                                            0xC9C5A8
#define __EncryptPad2_x                                            0xC4EC80
#define __EncryptPad3_x                                            0xC4E880
#define __EncryptPad4_x                                            0xC8CC00
#define __EncryptPad5_x                                            0xF68BA8
#define __AC1_x                                                    0x814EA6
#define __AC2_x                                                    0x5E815F
#define __AC3_x                                                    0x5EF85F
#define __AC4_x                                                    0x5F3830
#define __AC5_x                                                    0x5F9B3F
#define __AC6_x                                                    0x5FE156
#define __AC7_x                                                    0x5E7BD0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19F064

// Direct Input
#define DI8__Main_x                                                0xF68BD0
#define DI8__Keyboard_x                                            0xF68BD4
#define DI8__Mouse_x                                               0xF68BB4
#define DI8__Mouse_Copy_x                                          0xEC13AC
#define DI8__Mouse_Check_x                                         0xF666FC
#define __AutoSkillArray_x                                         0xEC22C4
#define __Attack_x                                                 0xF600EB
#define __Autofire_x                                               0xF600EC
#define __BindList_x                                               0xC2CE20
#define g_eqCommandStates_x                                        0xC2DBA0
#define __Clicks_x                                                 0xEC1464
#define __CommandList_x                                            0xC2E760
#define __CurrentMapLabel_x                                        0xF78B6C
#define __CurrentSocial_x                                          0xC167C0
#define __DoAbilityList_x                                          0xEF7C0C
#define __do_loot_x                                                0x5B43D0
#define __DrawHandler_x                                            0x15F7EE0
#define __GroupCount_x                                             0xEB3D62
#define __Guilds_x                                                 0xEB7BB8
#define __gWorld_x                                                 0xEB3BB0
#define __HWnd_x                                                   0xF68BB8
#define __heqmain_x                                                0xF68B90
#define __InChatMode_x                                             0xEC1394
#define __LastTell_x                                               0xEC3308
#define __LMouseHeldTime_x                                         0xEC14D0
#define __Mouse_x                                                  0xF68BBC
#define __MouseLook_x                                              0xEC142A
#define __MouseEventTime_x                                         0xF60BCC
#define __gpbCommandEvent_x                                        0xEB1650
#define __NetStatusToggle_x                                        0xEC142D
#define __PCNames_x                                                0xEC28B4
#define __RangeAttackReady_x                                       0xEC25A8
#define __RMouseHeldTime_x                                         0xEC14CC
#define __RunWalkState_x                                           0xEC1398
#define __ScreenMode_x                                             0xDFF008
#define __ScreenX_x                                                0xEC134C
#define __ScreenY_x                                                0xEC1348
#define __ScreenXMax_x                                             0xEC1350
#define __ScreenYMax_x                                             0xEC1354
#define __ServerHost_x                                             0xEB188B
#define __ServerName_x                                             0xEF7BCC
#define __ShiftKeyDown_x                                           0xEC1A24
#define __ShowNames_x                                              0xEC2764
#define __Socials_x                                                0xEF7CCC
#define __SubscriptionType_x                                       0xFBD070
#define __TargetAggroHolder_x                                      0xF7B520
#define __ZoneType_x                                               0xEC1828
#define __GroupAggro_x                                             0xF7B560
#define __LoginName_x                                              0xF6638C
#define __Inviter_x                                                0xF60068
#define __AttackOnAssist_x                                         0xEC2720
#define __UseTellWindows_x                                         0xEC2A50
#define __gfMaxZoomCameraDistance_x                                0xAFDBB8
#define __gfMaxCameraDistance_x                                    0xB2A104
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
#define pinstCamActor_x                                            0xDFEFFC
#define pinstCDBStr_x                                              0xDFEEA4
#define pinstCDisplay_x                                            0xEB3BAC
#define pinstCEverQuest_x                                          0xF68BE8
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
#define pinstEqLogin_x                                             0xF65CD8
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
#define pinstViewActor_x                                           0xDFEFF8
#define pinstWorldData_x                                           0xEB1784
#define pinstZoneAddr_x                                            0xEC18C0
#define pinstPlayerPath_x                                          0xF63368
#define pinstTargetIndicator_x                                     0xF64CB0
#define EQObject_Top_x                                             0xEB1654
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDFF7A0
#define pinstCAchievementsWnd_x                                    0xDFF79C
#define pinstCActionsWnd_x                                         0xDFF764
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFEFD8
#define pinstCAdvancedLootWnd_x                                    0xDFEF94
#define pinstCAdventureLeaderboardWnd_x                            0xF72340
#define pinstCAdventureRequestWnd_x                                0xF723F0
#define pinstCAdventureStatsWnd_x                                  0xF724A0
#define pinstCAggroMeterWnd_x                                      0xDFF080
#define pinstCAlarmWnd_x                                           0xDFEF60
#define pinstCAlertHistoryWnd_x                                    0xDFEFF4
#define pinstCAlertStackWnd_x                                      0xDFEF68
#define pinstCAlertWnd_x                                           0xDFEF74
#define pinstCAltStorageWnd_x                                      0xF72800
#define pinstCAudioTriggersWindow_x                                0xCB3B88
#define pinstCAuraWnd_x                                            0xDFF02C
#define pinstCAvaZoneWnd_x                                         0xDFEFD4
#define pinstCBandolierWnd_x                                       0xDFF078
#define pinstCBankWnd_x                                            0xDFF028
#define pinstCBarterMerchantWnd_x                                  0xF73A40
#define pinstCBarterSearchWnd_x                                    0xF73AF0
#define pinstCBarterWnd_x                                          0xF73BA0
#define pinstCBazaarConfirmationWnd_x                              0xDFF7C8
#define pinstCBazaarSearchWnd_x                                    0xDFF748
#define pinstCBazaarWnd_x                                          0xDFEF48
#define pinstCBlockedBuffWnd_x                                     0xDFF034
#define pinstCBlockedPetBuffWnd_x                                  0xDFF054
#define pinstCBodyTintWnd_x                                        0xDFF774
#define pinstCBookWnd_x                                            0xDFF0B4
#define pinstCBreathWnd_x                                          0xDFF7B8
#define pinstCBuffWindowNORMAL_x                                   0xDFF00C
#define pinstCBuffWindowSHORT_x                                    0xDFF018
#define pinstCBugReportWnd_x                                       0xDFF020
#define pinstCButtonWnd_x                                          0x15F7310
#define pinstCCastingWnd_x                                         0xDFF0A0
#define pinstCCastSpellWnd_x                                       0xDFF7B4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDFEF4C
#define pinstCChatWindowManager_x                                  0xF74660
#define pinstCClaimWnd_x                                           0xF747B8
#define pinstCColorPickerWnd_x                                     0xDFF76C
#define pinstCCombatAbilityWnd_x                                   0xDFEF58
#define pinstCCombatSkillsSelectWnd_x                              0xDFEF7C
#define pinstCCompassWnd_x                                         0xDFF768
#define pinstCConfirmationDialog_x                                 0xF796B8
#define pinstCContainerMgr_x                                       0xDFEF40
#define pinstCContextMenuManager_x                                 0x15F7060
#define pinstCCursorAttachment_x                                   0xDFF088
#define pinstCDynamicZoneWnd_x                                     0xF74D80
#define pinstCEditLabelWnd_x                                       0xDFEFF0
#define pinstCEQMainWnd_x                                          0xF74FC8
#define pinstCEventCalendarWnd_x                                   0xDFF08C
#define pinstCExtendedTargetWnd_x                                  0xDFF048
#define pinstCFacePick_x                                           0xDFEF8C
#define pinstCFactionWnd_x                                         0xDFF7D8
#define pinstCFellowshipWnd_x                                      0xF751C8
#define pinstCFileSelectionWnd_x                                   0xDFF090
#define pinstCFindItemWnd_x                                        0xDFF7C4
#define pinstCFindLocationWnd_x                                    0xF75320
#define pinstCFriendsWnd_x                                         0xDFEF90
#define pinstCGemsGameWnd_x                                        0xDFF7D4
#define pinstCGiveWnd_x                                            0xDFEF64
#define pinstCGroupSearchFiltersWnd_x                              0xDFF0A4
#define pinstCGroupSearchWnd_x                                     0xF75718
#define pinstCGroupWnd_x                                           0xF757C8
#define pinstCGuildBankWnd_x                                       0xEC2704
#define pinstCGuildCreationWnd_x                                   0xF75928
#define pinstCGuildMgmtWnd_x                                       0xF759D8
#define pinstCharacterCreation_x                                   0xDFEF84
#define pinstCHelpWnd_x                                            0xDFEFC8
#define pinstCHeritageSelectionWnd_x                               0xDFEF98
#define pinstCHotButtonWnd_x                                       0xF77B30
#define pinstCHotButtonWnd1_x                                      0xF77B30
#define pinstCHotButtonWnd2_x                                      0xF77B34
#define pinstCHotButtonWnd3_x                                      0xF77B38
#define pinstCHotButtonWnd4_x                                      0xF77B3C
#define pinstCIconSelectionWnd_x                                   0xDFF084
#define pinstCInspectWnd_x                                         0xDFEFC4
#define pinstCInventoryWnd_x                                       0xDFEF9C
#define pinstCInvSlotMgr_x                                         0xDFF798
#define pinstCItemDisplayManager_x                                 0xF780C0
#define pinstCItemExpTransferWnd_x                                 0xF781F0
#define pinstCItemOverflowWnd_x                                    0xDFF74C
#define pinstCJournalCatWnd_x                                      0xDFF52C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDFF04C
#define pinstCKeyRingWnd_x                                         0xDFEFEC
#define pinstCLargeDialogWnd_x                                     0xF7A338
#define pinstCLayoutCopyWnd_x                                      0xF78540
#define pinstCLFGuildWnd_x                                         0xF785F0
#define pinstCLoadskinWnd_x                                        0xDFEF44
#define pinstCLootFiltersCopyWnd_x                                 0xCD0180
#define pinstCLootFiltersWnd_x                                     0xDFEF6C
#define pinstCLootSettingsWnd_x                                    0xDFEF88
#define pinstCLootWnd_x                                            0xDFF530
#define pinstCMailAddressBookWnd_x                                 0xDFF7A8
#define pinstCMailCompositionWnd_x                                 0xDFF784
#define pinstCMailIgnoreListWnd_x                                  0xDFF7AC
#define pinstCMailWnd_x                                            0xDFF760
#define pinstCManageLootWnd_x                                      0xE00638
#define pinstCMapToolbarWnd_x                                      0xDFEFD0
#define pinstCMapViewWnd_x                                         0xDFEFA8
#define pinstCMarketplaceWnd_x                                     0xDFEF70
#define pinstCMerchantWnd_x                                        0xDFF534
#define pinstCMIZoneSelectWnd_x                                    0xF78E28
#define pinstCMusicPlayerWnd_x                                     0xDFF540
#define pinstCNameChangeMercWnd_x                                  0xDFF7C0
#define pinstCNameChangePetWnd_x                                   0xDFF7A4
#define pinstCNameChangeWnd_x                                      0xDFF7D0
#define pinstCNoteWnd_x                                            0xDFEFAC
#define pinstCObjectPreviewWnd_x                                   0xDFEF80
#define pinstCOptionsWnd_x                                         0xDFEFB4
#define pinstCPetInfoWnd_x                                         0xDFF750
#define pinstCPetitionQWnd_x                                       0xDFF790
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDFF778
#define pinstCPlayerWnd_x                                          0xDFF754
#define pinstCPopupWndManager_x                                    0xF796B8
#define pinstCProgressionSelectionWnd_x                            0xF79768
#define pinstCPurchaseGroupWnd_x                                   0xDFEFB8
#define pinstCPurchaseWnd_x                                        0xDFEFA0
#define pinstCPvPLeaderboardWnd_x                                  0xF79818
#define pinstCPvPStatsWnd_x                                        0xF798C8
#define pinstCQuantityWnd_x                                        0xDFF050
#define pinstCRaceChangeWnd_x                                      0xDFEF5C
#define pinstCRaidOptionsWnd_x                                     0xDFF0A8
#define pinstCRaidWnd_x                                            0xDFF78C
#define pinstCRealEstateItemsWnd_x                                 0xDFF794
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDFF538
#define pinstCRealEstateManageWnd_x                                0xDFEFC0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFEFE8
#define pinstCRealEstatePlotSearchWnd_x                            0xDFF024
#define pinstCRealEstatePurchaseWnd_x                              0xDFF064
#define pinstCRespawnWnd_x                                         0xDFF03C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDFF7B0
#define pinstCSendMoneyWnd_x                                       0xDFEF78
#define pinstCServerListWnd_x                                      0xDFF07C
#define pinstCSkillsSelectWnd_x                                    0xDFEF50
#define pinstCSkillsWnd_x                                          0xDFF7CC
#define pinstCSocialEditWnd_x                                      0xDFEFE4
#define pinstCSocialWnd_x                                          0xDFF7BC
#define pinstCSpellBookWnd_x                                       0xDFEF54
#define pinstCStoryWnd_x                                           0xDFF758
#define pinstCTargetOfTargetWnd_x                                  0xF7B6F0
#define pinstCTargetWnd_x                                          0xDFF038
#define pinstCTaskOverlayWnd_x                                     0xDFEFB0
#define pinstCTaskSelectWnd_x                                      0xF7B848
#define pinstCTaskManager_x                                        0xCD0AC0
#define pinstCTaskTemplateSelectWnd_x                              0xF7B8F8
#define pinstCTaskWnd_x                                            0xF7B9A8
#define pinstCTextEntryWnd_x                                       0xDFF01C
#define pinstCTimeLeftWnd_x                                        0xDFF75C
#define pinstCTipWndCONTEXT_x                                      0xF7BBAC
#define pinstCTipWndOFDAY_x                                        0xF7BBA8
#define pinstCTitleWnd_x                                           0xF7BC58
#define pinstCTrackingWnd_x                                        0xDFEFA4
#define pinstCTradeskillWnd_x                                      0xF7BDC0
#define pinstCTradeWnd_x                                           0xDFF780
#define pinstCTrainWnd_x                                           0xDFF77C
#define pinstCTributeBenefitWnd_x                                  0xF7BFC0
#define pinstCTributeMasterWnd_x                                   0xF7C070
#define pinstCTributeTrophyWnd_x                                   0xF7C120
#define pinstCVideoModesWnd_x                                      0xDFF53C
#define pinstCVoiceMacroWnd_x                                      0xF65418
#define pinstCVoteResultsWnd_x                                     0xDFF788
#define pinstCVoteWnd_x                                            0xDFF770
#define pinstCWebManager_x                                         0xF65A94
#define pinstCZoneGuideWnd_x                                       0xDFEFBC
#define pinstCZonePathWnd_x                                        0xDFEFDC

#define pinstEQSuiteTextureLoader_x                                0xC9E080
#define pinstItemIconCache_x                                       0xF74F80
#define pinstLootFiltersManager_x                                  0xCD0230
#define pinstRewardSelectionWnd_x                                  0xF7A010

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AF830
#define __CastRay2_x                                               0x5AF880
#define __ConvertItemTags_x                                        0x5CB3E0
#define __CleanItemTags_x                                          0x47D010
#define __DoesFileExist_x                                          0x903DD0
#define __EQGetTime_x                                              0x900810
#define __ExecuteCmd_x                                             0x5A8120
#define __FixHeading_x                                             0x99B5C0
#define __GameLoop_x                                               0x6BBAA0
#define __get_bearing_x                                            0x5AF3A0
#define __get_melee_range_x                                        0x5AFA70
#define __GetAnimationCache_x                                      0x720D90
#define __GetGaugeValueFromEQ_x                                    0x813350
#define __GetLabelFromEQ_x                                         0x814E30
#define __GetXTargetType_x                                         0x99CFA0
#define __HandleMouseWheel_x                                       0x6BC960
#define __HeadingDiff_x                                            0x99B630
#define __HelpPath_x                                               0xF607BC
#define __LoadFrontEnd_x                                           0x6B8DC0
#define __NewUIINI_x                                               0x813020
#define __ProcessGameEvents_x                                      0x60F9D0
#define __ProcessMouseEvent_x                                      0x60F190
#define __SaveColors_x                                             0x5518E0
#define __STMLToText_x                                             0x93EA40
#define __ToggleKeyRingItem_x                                      0x514B80
#define CMemoryMappedFile__SetFile_x                               0xA8A7E0
#define CrashDetected_x                                            0x6BA860
#define DrawNetStatus_x                                            0x63B7D0
#define Expansion_HoT_x                                            0xEC270C
#define Teleport_Table_Size_x                                      0xEB1740
#define Teleport_Table_x                                           0xEB1BA8
#define Util__FastTime_x                                           0x9003E0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4903B0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4992C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499090
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493950
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492DA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5593E0
#define AltAdvManager__IsAbilityReady_x                            0x558310
#define AltAdvManager__GetAAById_x                                 0x558510
#define AltAdvManager__CanTrainAbility_x                           0x558580
#define AltAdvManager__CanSeeAbility_x                             0x5588E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA160
#define CharacterZoneClient__HasSkill_x                            0x4D5050
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6770
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE480
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAA80
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9120
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9200
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D92E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3270
#define CharacterZoneClient__BardCastBard_x                        0x4C5DD0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB50
#define CharacterZoneClient__GetEffect_x                           0x4BA9C0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C42C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4390
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C43E0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4530
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4700
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B28C0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D76D0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7150

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E24F0
#define CBankWnd__WndNotification_x                                0x6E22D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EFD00

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61E180
#define CButtonWnd__CButtonWnd_x                                   0x93ADF0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70FE30
#define CChatManager__InitContextMenu_x                            0x708F80
#define CChatManager__FreeChatWindow_x                             0x70E970
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E87D0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70FAB0
#define CChatManager__CreateChatWindow_x                           0x70EFB0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E88E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94F4C0
#define CContextMenu__dCContextMenu_x                              0x94F700
#define CContextMenu__AddMenuItem_x                                0x94F710
#define CContextMenu__RemoveMenuItem_x                             0x94FA20
#define CContextMenu__RemoveAllMenuItems_x                         0x94FA40
#define CContextMenu__CheckMenuItem_x                              0x94FAC0
#define CContextMenu__SetMenuItem_x                                0x94F940
#define CContextMenu__AddSeparator_x                               0x94F8A0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x950050
#define CContextMenuManager__RemoveMenu_x                          0x9500C0
#define CContextMenuManager__PopupMenu_x                           0x950180
#define CContextMenuManager__Flush_x                               0x94FFF0
#define CContextMenuManager__GetMenu_x                             0x49B3F0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71B560

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DC7E0
#define CChatService__GetFriendName_x                              0x8DC7F0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7106B0
#define CChatWindow__Clear_x                                       0x711980
#define CChatWindow__WndNotification_x                             0x712110
#define CChatWindow__AddHistory_x                                  0x711240

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94C910
#define CComboWnd__Draw_x                                          0x94BE00
#define CComboWnd__GetCurChoice_x                                  0x94C750
#define CComboWnd__GetListRect_x                                   0x94C2B0
#define CComboWnd__GetTextRect_x                                   0x94C980
#define CComboWnd__InsertChoice_x                                  0x94C440
#define CComboWnd__SetColors_x                                     0x94C410
#define CComboWnd__SetChoice_x                                     0x94C720
#define CComboWnd__GetItemCount_x                                  0x94C760
#define CComboWnd__GetCurChoiceText_x                              0x94C7A0
#define CComboWnd__GetChoiceText_x                                 0x94C770
#define CComboWnd__InsertChoiceAtIndex_x                           0x94C4E0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x718F50
#define CContainerWnd__vftable_x                                   0xB11444
#define CContainerWnd__SetContainer_x                              0x71A4B0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54C320
#define CDisplay__PreZoneMainUI_x                                  0x54C330
#define CDisplay__CleanGameUI_x                                    0x5516A0
#define CDisplay__GetClickedActor_x                                0x544640
#define CDisplay__GetUserDefinedColor_x                            0x53CD00
#define CDisplay__GetWorldFilePath_x                               0x5460B0
#define CDisplay__is3dON_x                                         0x5412A0
#define CDisplay__ReloadUI_x                                       0x54B7B0
#define CDisplay__WriteTextHD2_x                                   0x541090
#define CDisplay__TrueDistance_x                                   0x547D70
#define CDisplay__SetViewActor_x                                   0x543F60
#define CDisplay__GetFloorHeight_x                                 0x541360
#define CDisplay__SetRenderWindow_x                                0x53FCC0
#define CDisplay__ToggleScreenshotMode_x                           0x543A30

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96F280

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x952A20
#define CEditWnd__GetCharIndexPt_x                                 0x953950
#define CEditWnd__GetDisplayString_x                               0x9537F0
#define CEditWnd__GetHorzOffset_x                                  0x952050
#define CEditWnd__GetLineForPrintableChar_x                        0x954AF0
#define CEditWnd__GetSelStartPt_x                                  0x953C00
#define CEditWnd__GetSTMLSafeText_x                                0x953610
#define CEditWnd__PointFromPrintableChar_x                         0x954720
#define CEditWnd__SelectableCharFromPoint_x                        0x954890
#define CEditWnd__SetEditable_x                                    0x953CD0
#define CEditWnd__SetWindowTextA_x                                 0x953390

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FD630
#define CEverQuest__ClickedPlayer_x                                0x5EF640
#define CEverQuest__CreateTargetIndicator_x                        0x60CC60
#define CEverQuest__DeleteTargetIndicator_x                        0x60CCF0
#define CEverQuest__DoTellWindow_x                                 0x4E89C0
#define CEverQuest__OutputTextToLog_x                              0x4E8C40
#define CEverQuest__DropHeldItemOnGround_x                         0x5E4680
#define CEverQuest__dsp_chat_x                                     0x4E8FD0
#define CEverQuest__trimName_x                                     0x608F40
#define CEverQuest__Emote_x                                        0x5FDE90
#define CEverQuest__EnterZone_x                                    0x5F7E10
#define CEverQuest__GetBodyTypeDesc_x                              0x602800
#define CEverQuest__GetClassDesc_x                                 0x602E40
#define CEverQuest__GetClassThreeLetterCode_x                      0x603440
#define CEverQuest__GetDeityDesc_x                                 0x60B5A0
#define CEverQuest__GetLangDesc_x                                  0x603600
#define CEverQuest__GetRaceDesc_x                                  0x602E20
#define CEverQuest__InterpretCmd_x                                 0x60BB70
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E8880
#define CEverQuest__LMouseUp_x                                     0x5E6C10
#define CEverQuest__RightClickedOnPlayer_x                         0x5E9160
#define CEverQuest__RMouseUp_x                                     0x5E7B90
#define CEverQuest__SetGameState_x                                 0x5E4410
#define CEverQuest__UPCNotificationFlush_x                         0x608E40
#define CEverQuest__IssuePetCommand_x                              0x604A00
#define CEverQuest__ReportSuccessfulHit_x                          0x5FF280

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72ADC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72AE20
#define CGaugeWnd__Draw_x                                          0x72A440

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF300
#define CGuild__GetGuildName_x                                     0x4AE3E0
#define CGuild__GetGuildIndex_x                                    0x4AE770

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x746260

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61E540

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x753260
#define CInvSlotMgr__MoveItem_x                                    0x751F80
#define CInvSlotMgr__SelectSlot_x                                  0x753330

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x750800
#define CInvSlot__SliderComplete_x                                 0x74E550
#define CInvSlot__GetItemBase_x                                    0x74DEE0
#define CInvSlot__UpdateItem_x                                     0x74E050

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x754DB0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x753F50
#define CInvSlotWnd__HandleLButtonUp_x                             0x754930

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80E640
#define CItemDisplayWnd__UpdateStrings_x                           0x7633E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75D150
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75D660
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7639F0
#define CItemDisplayWnd__AboutToShow_x                             0x763020
#define CItemDisplayWnd__WndNotification_x                         0x764AE0
#define CItemDisplayWnd__RequestConvertItem_x                      0x7645A0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x762080
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x762E40

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x847110

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x769010

// CLabel 
#define CLabel__Draw_x                                             0x76EA60

// CListWnd
#define CListWnd__CListWnd_x                                       0x924F20
#define CListWnd__dCListWnd_x                                      0x925240
#define CListWnd__AddColumn_x                                      0x9296B0
#define CListWnd__AddColumn1_x                                     0x929700
#define CListWnd__AddLine_x                                        0x929A90
#define CListWnd__AddString_x                                      0x929890
#define CListWnd__CalculateFirstVisibleLine_x                      0x929470
#define CListWnd__CalculateVSBRange_x                              0x929250
#define CListWnd__ClearSel_x                                       0x92A270
#define CListWnd__ClearAllSel_x                                    0x92A2D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92ACE0
#define CListWnd__Compare_x                                        0x928B80
#define CListWnd__Draw_x                                           0x925370
#define CListWnd__DrawColumnSeparators_x                           0x927B60
#define CListWnd__DrawHeader_x                                     0x927FC0
#define CListWnd__DrawItem_x                                       0x9284C0
#define CListWnd__DrawLine_x                                       0x927CC0
#define CListWnd__DrawSeparator_x                                  0x927C00
#define CListWnd__EnableLine_x                                     0x927440
#define CListWnd__EnsureVisible_x                                  0x92AC00
#define CListWnd__ExtendSel_x                                      0x92A1A0
#define CListWnd__GetColumnTooltip_x                               0x926F80
#define CListWnd__GetColumnMinWidth_x                              0x926FF0
#define CListWnd__GetColumnWidth_x                                 0x926EF0
#define CListWnd__GetCurSel_x                                      0x926880
#define CListWnd__GetItemAtPoint_x                                 0x9276B0
#define CListWnd__GetItemAtPoint1_x                                0x927720
#define CListWnd__GetItemData_x                                    0x926900
#define CListWnd__GetItemHeight_x                                  0x926CC0
#define CListWnd__GetItemIcon_x                                    0x926A90
#define CListWnd__GetItemRect_x                                    0x927530
#define CListWnd__GetItemText_x                                    0x926940
#define CListWnd__GetSelList_x                                     0x92A320
#define CListWnd__GetSeparatorRect_x                               0x927960
#define CListWnd__InsertLine_x                                     0x929E80
#define CListWnd__RemoveLine_x                                     0x929FD0
#define CListWnd__SetColors_x                                      0x929220
#define CListWnd__SetColumnJustification_x                         0x928F50
#define CListWnd__SetColumnWidth_x                                 0x928E70
#define CListWnd__SetCurSel_x                                      0x92A0E0
#define CListWnd__SetItemColor_x                                   0x92A8B0
#define CListWnd__SetItemData_x                                    0x92A870
#define CListWnd__SetItemText_x                                    0x92A490
#define CListWnd__ShiftColumnSeparator_x                           0x929010
#define CListWnd__Sort_x                                           0x928D00
#define CListWnd__ToggleSel_x                                      0x92A110
#define CListWnd__SetColumnsSizable_x                              0x9290C0
#define CListWnd__SetItemWnd_x                                     0x92A740
#define CListWnd__GetItemWnd_x                                     0x926AE0
#define CListWnd__SetItemIcon_x                                    0x92A510
#define CListWnd__CalculateCustomWindowPositions_x                 0x929570
#define CListWnd__SetVScrollPos_x                                  0x928E50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7842F0
#define CMapViewWnd__GetWorldCoordinates_x                         0x782A00
#define CMapViewWnd__HandleLButtonDown_x                           0x77FA40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A4410
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A4CF0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A5220
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A8190
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A2F80
#define CMerchantWnd__SelectBuySellSlot_x                          0x7ADD40
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A4020

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AA3A0
#define CPacketScrambler__hton_x                                   0x8AA390

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9440C0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9444D0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9442C0
#define CSidlManager__CreateLabel_x                                0x805B00
#define CSidlManager__CreateXWndFromTemplate_x                     0x947430
#define CSidlManager__CreateXWndFromTemplate1_x                    0x947610
#define CSidlManager__CreateXWnd_x                                 0x805A30
#define CSidlManager__CreateHotButtonWnd_x                         0x805FF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x940B80
#define CSidlScreenWnd__CalculateVSBRange_x                        0x940A80
#define CSidlScreenWnd__ConvertToRes_x                             0x966270
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x940510
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x940200
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9402D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9403A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x941020
#define CSidlScreenWnd__EnableIniStorage_x                         0x9414F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x941210
#define CSidlScreenWnd__Init1_x                                    0x93FE00
#define CSidlScreenWnd__LoadIniInfo_x                              0x941540
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9420A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93F200
#define CSidlScreenWnd__StoreIniInfo_x                             0x941C10
#define CSidlScreenWnd__StoreIniVis_x                              0x941F80
#define CSidlScreenWnd__WndNotification_x                          0x940F30
#define CSidlScreenWnd__GetChildItem_x                             0x941470
#define CSidlScreenWnd__HandleLButtonUp_x                          0x930B60
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F6F30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x682D50
#define CSkillMgr__GetSkillCap_x                                   0x682F30
#define CSkillMgr__GetNameToken_x                                  0x6824D0
#define CSkillMgr__IsActivatedSkill_x                              0x682610
#define CSkillMgr__IsCombatSkill_x                                 0x682550

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x950E30
#define CSliderWnd__SetValue_x                                     0x950CA0
#define CSliderWnd__SetNumTicks_x                                  0x950D00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80BAD0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x959700
#define CStmlWnd__CalculateHSBRange_x                              0x95A820
#define CStmlWnd__CalculateVSBRange_x                              0x95A790
#define CStmlWnd__CanBreakAtCharacter_x                            0x95EB50
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95F7E0
#define CStmlWnd__ForceParseNow_x                                  0x959CF0
#define CStmlWnd__GetNextTagPiece_x                                0x95EAB0
#define CStmlWnd__GetSTMLText_x                                    0x5044D0
#define CStmlWnd__GetVisibleText_x                                 0x959D10
#define CStmlWnd__InitializeWindowVariables_x                      0x95F630
#define CStmlWnd__MakeStmlColorTag_x                               0x958D70
#define CStmlWnd__MakeWndNotificationTag_x                         0x958DE0
#define CStmlWnd__SetSTMLText_x                                    0x957E20
#define CStmlWnd__StripFirstSTMLLines_x                            0x9608B0
#define CStmlWnd__UpdateHistoryString_x                            0x95F9F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x956EC0
#define CTabWnd__DrawCurrentPage_x                                 0x9575F0
#define CTabWnd__DrawTab_x                                         0x957310
#define CTabWnd__GetCurrentPage_x                                  0x9566C0
#define CTabWnd__GetPageInnerRect_x                                0x956900
#define CTabWnd__GetTabInnerRect_x                                 0x956840
#define CTabWnd__GetTabRect_x                                      0x9566F0
#define CTabWnd__InsertPage_x                                      0x956B10
#define CTabWnd__SetPage_x                                         0x956980
#define CTabWnd__SetPageRect_x                                     0x956E00
#define CTabWnd__UpdatePage_x                                      0x9571D0
#define CTabWnd__GetPageFromTabIndex_x                             0x957250
#define CTabWnd__GetCurrentTabIndex_x                              0x9566B0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7693E0
#define CPageWnd__SetTabText_x                                     0x956210

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8FA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92DA50
#define CTextureFont__GetTextExtent_x                              0x92DC10

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B5970
#define CHtmlComponentWnd__ValidateUri_x                           0x747C50
#define CHtmlWnd__SetClientCallbacks_x                             0x6235B0
#define CHtmlWnd__AddObserver_x                                    0x6235D0
#define CHtmlWnd__RemoveObserver_x                                 0x623630
#define Window__getProgress_x                                      0x85F530
#define Window__getStatus_x                                        0x85F550
#define Window__getURI_x                                           0x85F560

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96BD10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91AB30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8610
#define CXStr__CXStr1_x                                            0x4FF660
#define CXStr__CXStr3_x                                            0x8FC910
#define CXStr__dCXStr_x                                            0x4786F0
#define CXStr__operator_equal_x                                    0x8FCB40
#define CXStr__operator_equal1_x                                   0x8FCB80
#define CXStr__operator_plus_equal1_x                              0x8FD610
#define CXStr__SetString_x                                         0x8FF500
#define CXStr__operator_char_p_x                                   0x8FD050
#define CXStr__GetChar_x                                           0x8FEE30
#define CXStr__Delete_x                                            0x8FE700
#define CXStr__GetUnicode_x                                        0x8FEEA0
#define CXStr__GetLength_x                                         0x4A8D50
#define CXStr__Mid_x                                               0x47D3C0
#define CXStr__Insert_x                                            0x8FEF00
#define CXStr__FindNext_x                                          0x8FEB70

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94F0E0
#define CXWnd__BringToTop_x                                        0x934330
#define CXWnd__Center_x                                            0x933EB0
#define CXWnd__ClrFocus_x                                          0x933CC0
#define CXWnd__Destroy_x                                           0x933D70
#define CXWnd__DoAllDrawing_x                                      0x9302F0
#define CXWnd__DrawChildren_x                                      0x9302C0
#define CXWnd__DrawColoredRect_x                                   0x930750
#define CXWnd__DrawTooltip_x                                       0x92EE40
#define CXWnd__DrawTooltipAtPoint_x                                0x92EF00
#define CXWnd__GetBorderFrame_x                                    0x9305B0
#define CXWnd__GetChildWndAt_x                                     0x9343D0
#define CXWnd__GetClientClipRect_x                                 0x932560
#define CXWnd__GetScreenClipRect_x                                 0x932630
#define CXWnd__GetScreenRect_x                                     0x9327F0
#define CXWnd__GetTooltipRect_x                                    0x9307A0
#define CXWnd__GetWindowTextA_x                                    0x49CB60
#define CXWnd__IsActive_x                                          0x930EE0
#define CXWnd__IsDescendantOf_x                                    0x933200
#define CXWnd__IsReallyVisible_x                                   0x933230
#define CXWnd__IsType_x                                            0x934A40
#define CXWnd__Move_x                                              0x9332A0
#define CXWnd__Move1_x                                             0x933350
#define CXWnd__ProcessTransition_x                                 0x933E60
#define CXWnd__Refade_x                                            0x933630
#define CXWnd__Resize_x                                            0x9338D0
#define CXWnd__Right_x                                             0x9340F0
#define CXWnd__SetFocus_x                                          0x933C80
#define CXWnd__SetFont_x                                           0x933CF0
#define CXWnd__SetKeyTooltip_x                                     0x934850
#define CXWnd__SetMouseOver_x                                      0x931710
#define CXWnd__StartFade_x                                         0x9330E0
#define CXWnd__GetChildItem_x                                      0x934540
#define CXWnd__SetParent_x                                         0x932F90
#define CXWnd__Minimize_x                                          0x933940

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9672F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x937270
#define CXWndManager__DrawWindows_x                                0x937290
#define CXWndManager__GetKeyboardFlags_x                           0x939A80
#define CXWndManager__HandleKeyboardMsg_x                          0x939630
#define CXWndManager__RemoveWnd_x                                  0x939CB0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93A230

// CDBStr
#define CDBStr__GetString_x                                        0x53BC90

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBA60
#define EQ_Character__Cur_HP_x                                     0x4D2090
#define EQ_Character__Cur_Mana_x                                   0x4D97E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEAD0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2500
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2650
#define EQ_Character__GetHPRegen_x                                 0x4DF5B0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFBB0
#define EQ_Character__GetManaRegen_x                               0x4DFFF0
#define EQ_Character__Max_Endurance_x                              0x6496F0
#define EQ_Character__Max_HP_x                                     0x4D1EC0
#define EQ_Character__Max_Mana_x                                   0x6494F0
#define EQ_Character__doCombatAbility_x                            0x64BB40
#define EQ_Character__UseSkill_x                                   0x4E1DC0
#define EQ_Character__GetConLevel_x                                0x642780
#define EQ_Character__IsExpansionFlag_x                            0x5A68F0
#define EQ_Character__TotalEffect_x                                0x4C5510
#define EQ_Character__GetPCSpellAffect_x                           0x4BF820
#define EQ_Character__SpellDuration_x                              0x4BF350
#define EQ_Character__GetAdjustedSkill_x                           0x4D4E10
#define EQ_Character__GetBaseSkill_x                               0x4D5DB0
#define EQ_Character__CanUseItem_x                                 0x4D9AF0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C9760

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65FBF0

//PcClient
#define PcClient__PcClient_x                                       0x63FEC0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B96D0
#define CCharacterListWnd__EnterWorld_x                            0x4B9110
#define CCharacterListWnd__Quit_x                                  0x4B8E60
#define CCharacterListWnd__UpdateList_x                            0x4B92A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6247D0
#define EQ_Item__CreateItemTagString_x                             0x8A3BC0
#define EQ_Item__IsStackable_x                                     0x8A8770
#define EQ_Item__GetImageNum_x                                     0x8A5620
#define EQ_Item__CreateItemClient_x                                0x6239B0
#define EQ_Item__GetItemValue_x                                    0x8A6950
#define EQ_Item__ValueSellMerchant_x                               0x8A9F80
#define EQ_Item__IsKeyRingItem_x                                   0x8A8090
#define EQ_Item__CanGoInBag_x                                      0x6248F0
#define EQ_Item__IsEmpty_x                                         0x8A7BD0
#define EQ_Item__GetMaxItemCount_x                                 0x8A6D60
#define EQ_Item__GetHeldItem_x                                     0x8A54F0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A3530

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55A0F0
#define EQ_LoadingS__Array_x                                       0xC25B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64A050
#define EQ_PC__GetAlternateAbilityId_x                             0x8B3230
#define EQ_PC__GetCombatAbility_x                                  0x8B38A0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B3910
#define EQ_PC__GetItemRecastTimer_x                                0x64C0C0
#define EQ_PC__HasLoreItem_x                                       0x642F90
#define EQ_PC__AlertInventoryChanged_x                             0x6420C0
#define EQ_PC__GetPcZoneClient_x                                   0x66E660
#define EQ_PC__RemoveMyAffect_x                                    0x64F2F0
#define EQ_PC__GetKeyRingItems_x                                   0x8B41A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B3F30
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B44A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5ACE50
#define EQItemList__add_object_x                                   0x5D9CC0
#define EQItemList__add_item_x                                     0x5AD3B0
#define EQItemList__delete_item_x                                  0x5AD400
#define EQItemList__FreeItemList_x                                 0x5AD300

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5387B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x661470
#define EQPlayer__dEQPlayer_x                                      0x6547B0
#define EQPlayer__DoAttack_x                                       0x669320
#define EQPlayer__EQPlayer_x                                       0x654E70
#define EQPlayer__SetNameSpriteState_x                             0x659150
#define EQPlayer__SetNameSpriteTint_x                              0x65A020
#define PlayerBase__HasProperty_j_x                                0x9999B0
#define EQPlayer__IsTargetable_x                                   0x999E50
#define EQPlayer__CanSee_x                                         0x999CB0
#define EQPlayer__CanSee1_x                                        0x999D80
#define PlayerBase__GetVisibilityLineSegment_x                     0x999A70

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66C100
#define PlayerZoneClient__GetLevel_x                               0x66E6A0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DAE30
#define PlayerZoneClient__LegalPlayerRace_x                        0x5534D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6641C0
#define EQPlayerManager__GetSpawnByName_x                          0x664270
#define EQPlayerManager__GetPlayerFromPartialName_x                0x664300

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x627F30
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x627FB0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x627FF0
#define KeypressHandler__ClearCommandStateArray_x                  0x629400
#define KeypressHandler__HandleKeyDown_x                           0x629420
#define KeypressHandler__HandleKeyUp_x                             0x6294C0
#define KeypressHandler__SaveKeymapping_x                          0x629910

// MapViewMap 
#define MapViewMap__Clear_x                                        0x780160
#define MapViewMap__SaveEx_x                                       0x783520
#define MapViewMap__SetZoom_x                                      0x787BE0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C7680

// StringTable 
#define StringTable__getString_x                                   0x8C24C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64EF60
#define PcZoneClient__RemovePetEffect_x                            0x64F590
#define PcZoneClient__HasAlternateAbility_x                        0x649320
#define PcZoneClient__GetCurrentMod_x                              0x4E4E80
#define PcZoneClient__GetModCap_x                                  0x4E4D80
#define PcZoneClient__CanEquipItem_x                               0x6499F0
#define PcZoneClient__GetItemByID_x                                0x64C530
#define PcZoneClient__GetItemByItemClass_x                         0x64C680
#define PcZoneClient__RemoveBuffEffect_x                           0x64F5B0
#define PcZoneClient__BandolierSwap_x                              0x64A600
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64C060

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DFA30

//IconCache
#define IconCache__GetIcon_x                                       0x720630

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7180F0
#define CContainerMgr__CloseContainer_x                            0x7183C0
#define CContainerMgr__OpenExperimentContainer_x                   0x718E40

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D8180

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61C950

//CLootWnd
#define CLootWnd__LootAll_x                                        0x776530
#define CLootWnd__RequestLootSlot_x                                0x775760

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x579C30
#define EQ_Spell__SpellAffects_x                                   0x57A0A0
#define EQ_Spell__SpellAffectBase_x                                0x579E60
#define EQ_Spell__IsStackable_x                                    0x4C9AD0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9980
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B69D0
#define EQ_Spell__IsSPAStacking_x                                  0x57AEF0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A400
#define EQ_Spell__IsNoRemove_x                                     0x4C9AB0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57AF00
#define __IsResEffectSpell_x                                       0x4C8F50

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD020

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D1CC0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81EDC0
#define CTargetWnd__WndNotification_x                              0x81E650
#define CTargetWnd__RefreshTargetBuffs_x                           0x81E920
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81D7B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8233B0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5361C0
#define CTaskManager__HandleMessage_x                              0x534660
#define CTaskManager__GetTaskStatus_x                              0x536270
#define CTaskManager__GetElementDescription_x                      0x5362F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575100
#define EqSoundManager__PlayScriptMp3_x                            0x575260
#define EqSoundManager__SoundAssistPlay_x                          0x686C40
#define EqSoundManager__WaveInstancePlay_x                         0x6861B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x529F50

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x955710

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x561BB0
#define CAltAbilityData__GetMercMaxRank_x                          0x561B40
#define CAltAbilityData__GetMaxRank_x                              0x557190

//CTargetRing
#define CTargetRing__Cast_x                                        0x61AA70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9960
#define CharacterBase__CreateItemGlobalIndex_x                     0x5111D0
#define CharacterBase__CreateItemIndex_x                           0x622B60
#define CharacterBase__GetItemPossession_x                         0x4FCE10
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DA2B0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DA310
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FF1D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FFA00
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FFAB0

//messages
#define msg_spell_worn_off_x                                       0x59EAE0
#define msg_new_text_x                                             0x593890
#define __msgTokenTextParam_x                                      0x5A1010
#define msgTokenText_x                                             0x5A1260

//SpellManager
#define SpellManager__vftable_x                                    0xAEB4A0
#define SpellManager__SpellManager_x                               0x689F70
#define Spellmanager__LoadTextSpells_x                             0x68A860
#define SpellManager__GetSpellByGroupAndRank_x                     0x68A140

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99D890

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x511850
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A4DF0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63B630
#define ItemGlobalIndex__IsValidIndex_x                            0x5118B0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D2660
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D28E0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76EDA0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71C800
#define CCursorAttachment__AttachToCursor1_x                       0x71C840
#define CCursorAttachment__Deactivate_x                            0x71D830

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x948460
#define CSidlManagerBase__CreatePageWnd_x                          0x947C60
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x943EE0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x943E70

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9658C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x965580

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50E7A0
#define CFindItemWnd__WndNotification_x                            0x50F280
#define CFindItemWnd__Update_x                                     0x50FDC0
#define CFindItemWnd__PickupSelectedItem_x                         0x50DFF0

//IString
#define IString__Append_x                                          0x4FE6F0

//Camera
#define CDisplay__cameraType_x                                     0xDFF544
#define EverQuest__Cameras_x                                       0xEC2A5C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x516F20
#define LootFiltersManager__GetItemFilterData_x                    0x516820
#define LootFiltersManager__RemoveItemLootFilter_x                 0x516850
#define LootFiltersManager__SetItemLootFilter_x                    0x516A70

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C6130

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A3450
#define CResolutionHandler__GetWindowedStyle_x                     0x6816A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x714E10

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E6F40
#define CDistillerInfo__Instance_x                                 0x8E6EE0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x734FE0
#define CGroupWnd__UpdateDisplay_x                                 0x734330

//ItemBase
#define ItemBase__IsLore_x                                         0x8A8140
#define ItemBase__IsLoreEquipped_x                                 0x8A81B0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D9C20
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D9D60
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D9DC0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x676D80
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67A6E0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x504AD0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1F00
#define FactionManagerClient__HandleFactionMessage_x               0x4F2570
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2B30
#define FactionManagerClient__GetMaxFaction_x                      0x4F2B4F
#define FactionManagerClient__GetMinFaction_x                      0x4F2B00

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FCDE0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92C9D0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE70

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD100

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x561080

//CTargetManager
#define CTargetManager__Get_x                                      0x68D7F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x676D80

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D60

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AD2A0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF600F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
