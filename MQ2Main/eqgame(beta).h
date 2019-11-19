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
#define __ExpectedVersionDate                                     "Nov 19 2019"
#define __ExpectedVersionTime                                     "04:23:25"
#define __ActualVersionDate_x                                      0xB082B8
#define __ActualVersionTime_x                                      0xB082AC
#define __ActualVersionBuild_x                                     0xAF3F64

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62D5A0
#define __MemChecker1_x                                            0x900360
#define __MemChecker2_x                                            0x6BB8F0
#define __MemChecker3_x                                            0x6BB840
#define __MemChecker4_x                                            0x857380
#define __EncryptPad0_x                                            0xC3E3E8
#define __EncryptPad1_x                                            0xC9C5A8
#define __EncryptPad2_x                                            0xC4EC80
#define __EncryptPad3_x                                            0xC4E880
#define __EncryptPad4_x                                            0xC8CC00
#define __EncryptPad5_x                                            0xF681A0
#define __AC1_x                                                    0x813FD6
#define __AC2_x                                                    0x5E75AF
#define __AC3_x                                                    0x5EECAF
#define __AC4_x                                                    0x5F2C80
#define __AC5_x                                                    0x5F8F8F
#define __AC6_x                                                    0x5FD5A6
#define __AC7_x                                                    0x5E7020
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
#define __do_loot_x                                                0x5B3A10
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
#define __gfMaxZoomCameraDistance_x                                0xAFDBD8
#define __gfMaxCameraDistance_x                                    0xB2A11C
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
#define __CastRay_x                                                0x5AEE70
#define __CastRay2_x                                               0x5AEEC0
#define __ConvertItemTags_x                                        0x5CAA20
#define __CleanItemTags_x                                          0x47D150
#define __DoesFileExist_x                                          0x9033F0
#define __EQGetTime_x                                              0x8FFE30
#define __ExecuteCmd_x                                             0x5A7750
#define __FixHeading_x                                             0x99AA90
#define __GameLoop_x                                               0x6BAAE0
#define __get_bearing_x                                            0x5AE9E0
#define __get_melee_range_x                                        0x5AF0B0
#define __GetAnimationCache_x                                      0x71FC60
#define __GetGaugeValueFromEQ_x                                    0x812480
#define __GetLabelFromEQ_x                                         0x813F60
#define __GetXTargetType_x                                         0x99C550
#define __HandleMouseWheel_x                                       0x6BB9A0
#define __HeadingDiff_x                                            0x99AB00
#define __HelpPath_x                                               0xF607BC
#define __LoadFrontEnd_x                                           0x6B7E00
#define __NewUIINI_x                                               0x812150
#define __ProcessGameEvents_x                                      0x60EE20
#define __ProcessMouseEvent_x                                      0x60E5E0
#define __SaveColors_x                                             0x551A80
#define __STMLToText_x                                             0x93DF70
#define __ToggleKeyRingItem_x                                      0x514CB0
#define CMemoryMappedFile__SetFile_x                               0xA89D30
#define CrashDetected_x                                            0x6B98A0
#define DrawNetStatus_x                                            0x63A8F0
#define Expansion_HoT_x                                            0xEC270C
#define Teleport_Table_Size_x                                      0xEB1740
#define Teleport_Table_x                                           0xEB1BA8
#define Util__FastTime_x                                           0x8FFA00

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490440
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499330
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499100
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4939D0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E20

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559700
#define AltAdvManager__IsAbilityReady_x                            0x558630
#define AltAdvManager__GetAAById_x                                 0x558830
#define AltAdvManager__CanTrainAbility_x                           0x5588A0
#define AltAdvManager__CanSeeAbility_x                             0x558C00

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA080
#define CharacterZoneClient__HasSkill_x                            0x4D4F70
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6690
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE2F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA8F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8FF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D90D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D91B0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C30F0
#define CharacterZoneClient__BardCastBard_x                        0x4C5C50
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA9C0
#define CharacterZoneClient__GetEffect_x                           0x4BA830
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4140
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4210
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4260
#define CharacterZoneClient__CalcAffectChange_x                    0x4C43B0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4580
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2740
#define CharacterZoneClient__FindItemByGuid_x                      0x4D75F0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7070

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E1430
#define CBankWnd__WndNotification_x                                0x6E1210

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EEB80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61D440
#define CButtonWnd__CButtonWnd_x                                   0x93A330

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70ED70
#define CChatManager__InitContextMenu_x                            0x707EC0
#define CChatManager__FreeChatWindow_x                             0x70D8B0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8530
#define CChatManager__SetLockedActiveChatWindow_x                  0x70E9F0
#define CChatManager__CreateChatWindow_x                           0x70DEF0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8640

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94EA60
#define CContextMenu__dCContextMenu_x                              0x94ECA0
#define CContextMenu__AddMenuItem_x                                0x94ECB0
#define CContextMenu__RemoveMenuItem_x                             0x94EFC0
#define CContextMenu__RemoveAllMenuItems_x                         0x94EFE0
#define CContextMenu__CheckMenuItem_x                              0x94F060
#define CContextMenu__SetMenuItem_x                                0x94EEE0
#define CContextMenu__AddSeparator_x                               0x94EE40

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94F5F0
#define CContextMenuManager__RemoveMenu_x                          0x94F660
#define CContextMenuManager__PopupMenu_x                           0x94F720
#define CContextMenuManager__Flush_x                               0x94F590
#define CContextMenuManager__GetMenu_x                             0x49B450
#define CContextMenuManager__CreateDefaultMenu_x                   0x71A480

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DB990
#define CChatService__GetFriendName_x                              0x8DB9A0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70F5E0
#define CChatWindow__Clear_x                                       0x7108A0
#define CChatWindow__WndNotification_x                             0x711030
#define CChatWindow__AddHistory_x                                  0x710160

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94BEB0
#define CComboWnd__Draw_x                                          0x94B3B0
#define CComboWnd__GetCurChoice_x                                  0x94BCF0
#define CComboWnd__GetListRect_x                                   0x94B850
#define CComboWnd__GetTextRect_x                                   0x94BF20
#define CComboWnd__InsertChoice_x                                  0x94B9E0
#define CComboWnd__SetColors_x                                     0x94B9B0
#define CComboWnd__SetChoice_x                                     0x94BCC0
#define CComboWnd__GetItemCount_x                                  0x94BD00
#define CComboWnd__GetCurChoiceText_x                              0x94BD40
#define CComboWnd__GetChoiceText_x                                 0x94BD10
#define CComboWnd__InsertChoiceAtIndex_x                           0x94BA80

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x717E70
#define CContainerWnd__vftable_x                                   0xB114AC
#define CContainerWnd__SetContainer_x                              0x7193D0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54C4C0
#define CDisplay__PreZoneMainUI_x                                  0x54C4D0
#define CDisplay__CleanGameUI_x                                    0x551840
#define CDisplay__GetClickedActor_x                                0x5447E0
#define CDisplay__GetUserDefinedColor_x                            0x53CEA0
#define CDisplay__GetWorldFilePath_x                               0x546250
#define CDisplay__is3dON_x                                         0x541440
#define CDisplay__ReloadUI_x                                       0x54B950
#define CDisplay__WriteTextHD2_x                                   0x541230
#define CDisplay__TrueDistance_x                                   0x547F10
#define CDisplay__SetViewActor_x                                   0x544100
#define CDisplay__GetFloorHeight_x                                 0x541500
#define CDisplay__SetRenderWindow_x                                0x53FE60
#define CDisplay__ToggleScreenshotMode_x                           0x543BD0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96E7B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x951F9F
#define CEditWnd__GetCharIndexPt_x                                 0x952EE0
#define CEditWnd__GetDisplayString_x                               0x952D80
#define CEditWnd__GetHorzOffset_x                                  0x9515E0
#define CEditWnd__GetLineForPrintableChar_x                        0x954080
#define CEditWnd__GetSelStartPt_x                                  0x953190
#define CEditWnd__GetSTMLSafeText_x                                0x952BA0
#define CEditWnd__PointFromPrintableChar_x                         0x953CB0
#define CEditWnd__SelectableCharFromPoint_x                        0x953E20
#define CEditWnd__SetEditable_x                                    0x953260
#define CEditWnd__SetWindowTextA_x                                 0x952920

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FCA80
#define CEverQuest__ClickedPlayer_x                                0x5EEA90
#define CEverQuest__CreateTargetIndicator_x                        0x60C0B0
#define CEverQuest__DeleteTargetIndicator_x                        0x60C140
#define CEverQuest__DoTellWindow_x                                 0x4E8720
#define CEverQuest__OutputTextToLog_x                              0x4E89A0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E3AD0
#define CEverQuest__dsp_chat_x                                     0x4E8D30
#define CEverQuest__trimName_x                                     0x608390
#define CEverQuest__Emote_x                                        0x5FD2E0
#define CEverQuest__EnterZone_x                                    0x5F7260
#define CEverQuest__GetBodyTypeDesc_x                              0x601C50
#define CEverQuest__GetClassDesc_x                                 0x602290
#define CEverQuest__GetClassThreeLetterCode_x                      0x602890
#define CEverQuest__GetDeityDesc_x                                 0x60A9F0
#define CEverQuest__GetLangDesc_x                                  0x602A50
#define CEverQuest__GetRaceDesc_x                                  0x602270
#define CEverQuest__InterpretCmd_x                                 0x60AFC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E7CD0
#define CEverQuest__LMouseUp_x                                     0x5E6060
#define CEverQuest__RightClickedOnPlayer_x                         0x5E85B0
#define CEverQuest__RMouseUp_x                                     0x5E6FE0
#define CEverQuest__SetGameState_x                                 0x5E3860
#define CEverQuest__UPCNotificationFlush_x                         0x608290
#define CEverQuest__IssuePetCommand_x                              0x603E50
#define CEverQuest__ReportSuccessfulHit_x                          0x5FE6D0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x729EC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x729F20
#define CGaugeWnd__Draw_x                                          0x729540

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF200
#define CGuild__GetGuildName_x                                     0x4AE2E0
#define CGuild__GetGuildIndex_x                                    0x4AE670

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x745330

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61D800

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x752330
#define CInvSlotMgr__MoveItem_x                                    0x751050
#define CInvSlotMgr__SelectSlot_x                                  0x752400

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74F8D0
#define CInvSlot__SliderComplete_x                                 0x74D630
#define CInvSlot__GetItemBase_x                                    0x74CFB0
#define CInvSlot__UpdateItem_x                                     0x74D120

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x753E60
#define CInvSlotWnd__CInvSlotWnd_x                                 0x753000
#define CInvSlotWnd__HandleLButtonUp_x                             0x7539E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80D7D0
#define CItemDisplayWnd__UpdateStrings_x                           0x762550
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75C2C0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75C7D0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x762B50
#define CItemDisplayWnd__AboutToShow_x                             0x7621A0
#define CItemDisplayWnd__WndNotification_x                         0x763C40
#define CItemDisplayWnd__RequestConvertItem_x                      0x763700
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x761200
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x761FC0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8462C0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x768130

// CLabel 
#define CLabel__Draw_x                                             0x76DC10

// CListWnd
#define CListWnd__CListWnd_x                                       0x9245E0
#define CListWnd__dCListWnd_x                                      0x924900
#define CListWnd__AddColumn_x                                      0x928D80
#define CListWnd__AddColumn1_x                                     0x928DD0
#define CListWnd__AddLine_x                                        0x929160
#define CListWnd__AddString_x                                      0x928F60
#define CListWnd__CalculateFirstVisibleLine_x                      0x928B40
#define CListWnd__CalculateVSBRange_x                              0x928920
#define CListWnd__ClearSel_x                                       0x929940
#define CListWnd__ClearAllSel_x                                    0x9299A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92A3C0
#define CListWnd__Compare_x                                        0x928250
#define CListWnd__Draw_x                                           0x924A30
#define CListWnd__DrawColumnSeparators_x                           0x927220
#define CListWnd__DrawHeader_x                                     0x927690
#define CListWnd__DrawItem_x                                       0x927B90
#define CListWnd__DrawLine_x                                       0x927390
#define CListWnd__DrawSeparator_x                                  0x9272C0
#define CListWnd__EnableLine_x                                     0x926AF0
#define CListWnd__EnsureVisible_x                                  0x92A2E0
#define CListWnd__ExtendSel_x                                      0x929870
#define CListWnd__GetColumnTooltip_x                               0x926630
#define CListWnd__GetColumnMinWidth_x                              0x9266A0
#define CListWnd__GetColumnWidth_x                                 0x9265A0
#define CListWnd__GetCurSel_x                                      0x925F30
#define CListWnd__GetItemAtPoint_x                                 0x926D70
#define CListWnd__GetItemAtPoint1_x                                0x926DE0
#define CListWnd__GetItemData_x                                    0x925FB0
#define CListWnd__GetItemHeight_x                                  0x926370
#define CListWnd__GetItemIcon_x                                    0x926140
#define CListWnd__GetItemRect_x                                    0x926BE0
#define CListWnd__GetItemText_x                                    0x925FF0
#define CListWnd__GetSelList_x                                     0x9299F0
#define CListWnd__GetSeparatorRect_x                               0x927020
#define CListWnd__InsertLine_x                                     0x929550
#define CListWnd__RemoveLine_x                                     0x9296A0
#define CListWnd__SetColors_x                                      0x9288F0
#define CListWnd__SetColumnJustification_x                         0x928620
#define CListWnd__SetColumnWidth_x                                 0x928540
#define CListWnd__SetCurSel_x                                      0x9297B0
#define CListWnd__SetItemColor_x                                   0x929F90
#define CListWnd__SetItemData_x                                    0x929F50
#define CListWnd__SetItemText_x                                    0x929B60
#define CListWnd__ShiftColumnSeparator_x                           0x9286E0
#define CListWnd__Sort_x                                           0x9283D0
#define CListWnd__ToggleSel_x                                      0x9297E0
#define CListWnd__SetColumnsSizable_x                              0x928790
#define CListWnd__SetItemWnd_x                                     0x929E10
#define CListWnd__GetItemWnd_x                                     0x926190
#define CListWnd__SetItemIcon_x                                    0x929BE0
#define CListWnd__CalculateCustomWindowPositions_x                 0x928C40
#define CListWnd__SetVScrollPos_x                                  0x928520

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7832D0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7819E0
#define CMapViewWnd__HandleLButtonDown_x                           0x77EA20

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A3360
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A3C40
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A4170
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A70E0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A1ED0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7ACC80
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A2F70

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A9500
#define CPacketScrambler__hton_x                                   0x8A94F0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9435A0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9439B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9437A0
#define CSidlManager__CreateLabel_x                                0x804B90
#define CSidlManager__CreateXWndFromTemplate_x                     0x946910
#define CSidlManager__CreateXWndFromTemplate1_x                    0x946AF0
#define CSidlManager__CreateXWnd_x                                 0x804AC0
#define CSidlManager__CreateHotButtonWnd_x                         0x805090

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x940080
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93FF80
#define CSidlScreenWnd__ConvertToRes_x                             0x9657A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93FA10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93F700
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93F7D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93F8A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x940520
#define CSidlScreenWnd__EnableIniStorage_x                         0x9409F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x940710
#define CSidlScreenWnd__Init1_x                                    0x93F320
#define CSidlScreenWnd__LoadIniInfo_x                              0x940A40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x941580
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93E720
#define CSidlScreenWnd__StoreIniInfo_x                             0x941100
#define CSidlScreenWnd__StoreIniVis_x                              0x941460
#define CSidlScreenWnd__WndNotification_x                          0x940430
#define CSidlScreenWnd__GetChildItem_x                             0x940970
#define CSidlScreenWnd__HandleLButtonUp_x                          0x930160
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F6F30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x681E30
#define CSkillMgr__GetSkillCap_x                                   0x682010
#define CSkillMgr__GetNameToken_x                                  0x6815B0
#define CSkillMgr__IsActivatedSkill_x                              0x6816F0
#define CSkillMgr__IsCombatSkill_x                                 0x681630

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9503C0
#define CSliderWnd__SetValue_x                                     0x950230
#define CSliderWnd__SetNumTicks_x                                  0x950290

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80AC60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x958BD0
#define CStmlWnd__CalculateHSBRange_x                              0x959CB0
#define CStmlWnd__CalculateVSBRange_x                              0x959C20
#define CStmlWnd__CanBreakAtCharacter_x                            0x95DFF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95EC80
#define CStmlWnd__ForceParseNow_x                                  0x959170
#define CStmlWnd__GetNextTagPiece_x                                0x95DF50
#define CStmlWnd__GetSTMLText_x                                    0x5044A0
#define CStmlWnd__GetVisibleText_x                                 0x959190
#define CStmlWnd__InitializeWindowVariables_x                      0x95EAD0
#define CStmlWnd__MakeStmlColorTag_x                               0x958240
#define CStmlWnd__MakeWndNotificationTag_x                         0x9582B0
#define CStmlWnd__SetSTMLText_x                                    0x9572F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x95FD80
#define CStmlWnd__UpdateHistoryString_x                            0x95EE90

// CTabWnd 
#define CTabWnd__Draw_x                                            0x956440
#define CTabWnd__DrawCurrentPage_x                                 0x956B70
#define CTabWnd__DrawTab_x                                         0x956890
#define CTabWnd__GetCurrentPage_x                                  0x955C40
#define CTabWnd__GetPageInnerRect_x                                0x955E80
#define CTabWnd__GetTabInnerRect_x                                 0x955DC0
#define CTabWnd__GetTabRect_x                                      0x955C70
#define CTabWnd__InsertPage_x                                      0x956090
#define CTabWnd__SetPage_x                                         0x955F00
#define CTabWnd__SetPageRect_x                                     0x956380
#define CTabWnd__UpdatePage_x                                      0x956750
#define CTabWnd__GetPageFromTabIndex_x                             0x9567D0
#define CTabWnd__GetCurrentTabIndex_x                              0x955C30

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x768590
#define CPageWnd__SetTabText_x                                     0x955790

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8F50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92D010
#define CTextureFont__GetTextExtent_x                              0x92D1D0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B4C90
#define CHtmlComponentWnd__ValidateUri_x                           0x746D20
#define CHtmlWnd__SetClientCallbacks_x                             0x622870
#define CHtmlWnd__AddObserver_x                                    0x622890
#define CHtmlWnd__RemoveObserver_x                                 0x6228F0
#define Window__getProgress_x                                      0x85E920
#define Window__getStatus_x                                        0x85E940
#define Window__getURI_x                                           0x85E950

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96B240

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91A230

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8370
#define CXStr__CXStr1_x                                            0x481640
#define CXStr__CXStr3_x                                            0x8FBF70
#define CXStr__dCXStr_x                                            0x478750
#define CXStr__operator_equal_x                                    0x8FC1A0
#define CXStr__operator_equal1_x                                   0x8FC1E0
#define CXStr__operator_plus_equal1_x                              0x8FCC70
#define CXStr__SetString_x                                         0x8FEB60
#define CXStr__operator_char_p_x                                   0x8FC6E0
#define CXStr__GetChar_x                                           0x8FE490
#define CXStr__Delete_x                                            0x8FDD60
#define CXStr__GetUnicode_x                                        0x8FE500
#define CXStr__GetLength_x                                         0x4A8D00
#define CXStr__Mid_x                                               0x47D500
#define CXStr__Insert_x                                            0x8FE560
#define CXStr__FindNext_x                                          0x8FE1D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94E670
#define CXWnd__BringToTop_x                                        0x933980
#define CXWnd__Center_x                                            0x933500
#define CXWnd__ClrFocus_x                                          0x933310
#define CXWnd__Destroy_x                                           0x9333C0
#define CXWnd__DoAllDrawing_x                                      0x92F8F0
#define CXWnd__DrawChildren_x                                      0x92F8C0
#define CXWnd__DrawColoredRect_x                                   0x92FD50
#define CXWnd__DrawTooltip_x                                       0x92E420
#define CXWnd__DrawTooltipAtPoint_x                                0x92E4E0
#define CXWnd__GetBorderFrame_x                                    0x92FBB0
#define CXWnd__GetChildWndAt_x                                     0x933A20
#define CXWnd__GetClientClipRect_x                                 0x931B70
#define CXWnd__GetScreenClipRect_x                                 0x931C40
#define CXWnd__GetScreenRect_x                                     0x931E00
#define CXWnd__GetTooltipRect_x                                    0x92FDA0
#define CXWnd__GetWindowTextA_x                                    0x49CB70
#define CXWnd__IsActive_x                                          0x9304E0
#define CXWnd__IsDescendantOf_x                                    0x932820
#define CXWnd__IsReallyVisible_x                                   0x932850
#define CXWnd__IsType_x                                            0x9340A0
#define CXWnd__Move_x                                              0x9328D0
#define CXWnd__Move1_x                                             0x932990
#define CXWnd__ProcessTransition_x                                 0x9334B0
#define CXWnd__Refade_x                                            0x932C70
#define CXWnd__Resize_x                                            0x932F30
#define CXWnd__Right_x                                             0x933740
#define CXWnd__SetFocus_x                                          0x9332D0
#define CXWnd__SetFont_x                                           0x933340
#define CXWnd__SetKeyTooltip_x                                     0x933EB0
#define CXWnd__SetMouseOver_x                                      0x930CF0
#define CXWnd__StartFade_x                                         0x932700
#define CXWnd__GetChildItem_x                                      0x933B90
#define CXWnd__SetParent_x                                         0x9325C0
#define CXWnd__Minimize_x                                          0x932FA0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x966820

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9368B0
#define CXWndManager__DrawWindows_x                                0x9368D0
#define CXWndManager__GetKeyboardFlags_x                           0x938FC0
#define CXWndManager__HandleKeyboardMsg_x                          0x938B70
#define CXWndManager__RemoveWnd_x                                  0x9391F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x939770

// CDBStr
#define CDBStr__GetString_x                                        0x53BE60

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB8D0
#define EQ_Character__Cur_HP_x                                     0x4D1FB0
#define EQ_Character__Cur_Mana_x                                   0x4D96B0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE940
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2380
#define EQ_Character__GetFocusRangeModifier_x                      0x4B24D0
#define EQ_Character__GetHPRegen_x                                 0x4DF450
#define EQ_Character__GetEnduranceRegen_x                          0x4DFA50
#define EQ_Character__GetManaRegen_x                               0x4DFE90
#define EQ_Character__Max_Endurance_x                              0x648440
#define EQ_Character__Max_HP_x                                     0x4D1DE0
#define EQ_Character__Max_Mana_x                                   0x648240
#define EQ_Character__doCombatAbility_x                            0x64A890
#define EQ_Character__UseSkill_x                                   0x4E1C60
#define EQ_Character__GetConLevel_x                                0x641810
#define EQ_Character__IsExpansionFlag_x                            0x5A5F20
#define EQ_Character__TotalEffect_x                                0x4C5390
#define EQ_Character__GetPCSpellAffect_x                           0x4BF690
#define EQ_Character__SpellDuration_x                              0x4BF1C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4D30
#define EQ_Character__GetBaseSkill_x                               0x4D5CD0
#define EQ_Character__CanUseItem_x                                 0x4D99C0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C87A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65E950

//PcClient
#define PcClient__PcClient_x                                       0x63EF40

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9540
#define CCharacterListWnd__EnterWorld_x                            0x4B8F80
#define CCharacterListWnd__Quit_x                                  0x4B8CD0
#define CCharacterListWnd__UpdateList_x                            0x4B9110

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x623AC0
#define EQ_Item__CreateItemTagString_x                             0x8A2D80
#define EQ_Item__IsStackable_x                                     0x8A78C0
#define EQ_Item__GetImageNum_x                                     0x8A47B0
#define EQ_Item__CreateItemClient_x                                0x622C90
#define EQ_Item__GetItemValue_x                                    0x8A5AB0
#define EQ_Item__ValueSellMerchant_x                               0x8A90E0
#define EQ_Item__IsKeyRingItem_x                                   0x8A71E0
#define EQ_Item__CanGoInBag_x                                      0x623BE0
#define EQ_Item__IsEmpty_x                                         0x8A6D30
#define EQ_Item__GetMaxItemCount_x                                 0x8A5EC0
#define EQ_Item__GetHeldItem_x                                     0x8A4680
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A26F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55A3D0
#define EQ_LoadingS__Array_x                                       0xC25B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x648DA0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B2310
#define EQ_PC__GetCombatAbility_x                                  0x8B2980
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B29F0
#define EQ_PC__GetItemRecastTimer_x                                0x64AE10
#define EQ_PC__HasLoreItem_x                                       0x642020
#define EQ_PC__AlertInventoryChanged_x                             0x641140
#define EQ_PC__GetPcZoneClient_x                                   0x66D480
#define EQ_PC__RemoveMyAffect_x                                    0x64E040
#define EQ_PC__GetKeyRingItems_x                                   0x8B3280
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B3010
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B3580

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AC460
#define EQItemList__add_object_x                                   0x5D9300
#define EQItemList__add_item_x                                     0x5AC9C0
#define EQItemList__delete_item_x                                  0x5ACA10
#define EQItemList__FreeItemList_x                                 0x5AC910

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538980

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6601D0
#define EQPlayer__dEQPlayer_x                                      0x6534F0
#define EQPlayer__DoAttack_x                                       0x668120
#define EQPlayer__EQPlayer_x                                       0x653BB0
#define EQPlayer__SetNameSpriteState_x                             0x657EC0
#define EQPlayer__SetNameSpriteTint_x                              0x658D80
#define PlayerBase__HasProperty_j_x                                0x998E70
#define EQPlayer__IsTargetable_x                                   0x999310
#define EQPlayer__CanSee_x                                         0x999170
#define EQPlayer__CanSee1_x                                        0x999240
#define PlayerBase__GetVisibilityLineSegment_x                     0x998F30

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66AF20
#define PlayerZoneClient__GetLevel_x                               0x66D4C0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DA470
#define PlayerZoneClient__LegalPlayerRace_x                        0x5536A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x662F90
#define EQPlayerManager__GetSpawnByName_x                          0x663040
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6630D0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6270D0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x627150
#define KeypressHandler__AttachKeyToEqCommand_x                    0x627190
#define KeypressHandler__ClearCommandStateArray_x                  0x6285A0
#define KeypressHandler__HandleKeyDown_x                           0x6285C0
#define KeypressHandler__HandleKeyUp_x                             0x628660
#define KeypressHandler__SaveKeymapping_x                          0x628AB0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77F140
#define MapViewMap__SaveEx_x                                       0x782500
#define MapViewMap__SetZoom_x                                      0x786BC0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C6610

// StringTable 
#define StringTable__getString_x                                   0x8C14A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64DCB0
#define PcZoneClient__RemovePetEffect_x                            0x64E2E0
#define PcZoneClient__HasAlternateAbility_x                        0x648070
#define PcZoneClient__GetCurrentMod_x                              0x4E4D10
#define PcZoneClient__GetModCap_x                                  0x4E4C10
#define PcZoneClient__CanEquipItem_x                               0x648740
#define PcZoneClient__GetItemByID_x                                0x64B280
#define PcZoneClient__GetItemByItemClass_x                         0x64B3D0
#define PcZoneClient__RemoveBuffEffect_x                           0x64E300
#define PcZoneClient__BandolierSwap_x                              0x649350
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64ADB0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DEF10

//IconCache
#define IconCache__GetIcon_x                                       0x71F500

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x717010
#define CContainerMgr__CloseContainer_x                            0x7172E0
#define CContainerMgr__OpenExperimentContainer_x                   0x717D60

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D71B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61BC20

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7756D0
#define CLootWnd__RequestLootSlot_x                                0x774900

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x579EF0
#define EQ_Spell__SpellAffects_x                                   0x57A360
#define EQ_Spell__SpellAffectBase_x                                0x57A120
#define EQ_Spell__IsStackable_x                                    0x4C99F0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C98A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6850
#define EQ_Spell__IsSPAStacking_x                                  0x57B1B0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A6C0
#define EQ_Spell__IsNoRemove_x                                     0x4C99D0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57B1C0
#define __IsResEffectSpell_x                                       0x4C8DD0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACF70

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D0E40

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81DF90
#define CTargetWnd__WndNotification_x                              0x81D820
#define CTargetWnd__RefreshTargetBuffs_x                           0x81DAF0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81C990

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x822590

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5363C0
#define CTaskManager__HandleMessage_x                              0x534860
#define CTaskManager__GetTaskStatus_x                              0x536470
#define CTaskManager__GetElementDescription_x                      0x5364F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575440
#define EqSoundManager__PlayScriptMp3_x                            0x5755A0
#define EqSoundManager__SoundAssistPlay_x                          0x685D60
#define EqSoundManager__WaveInstancePlay_x                         0x6852D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52A150

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x954CA0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x561D90
#define CAltAbilityData__GetMercMaxRank_x                          0x561D20
#define CAltAbilityData__GetMaxRank_x                              0x5574B0

//CTargetRing
#define CTargetRing__Cast_x                                        0x619D50

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9880
#define CharacterBase__CreateItemGlobalIndex_x                     0x511310
#define CharacterBase__CreateItemIndex_x                           0x621E20
#define CharacterBase__GetItemPossession_x                         0x4FCDA0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D9420
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D9480
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FE0E0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FE910
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FE9C0

//messages
#define msg_spell_worn_off_x                                       0x59E0E0
#define msg_new_text_x                                             0x592EB0
#define __msgTokenTextParam_x                                      0x5A0610
#define msgTokenText_x                                             0x5A0860

//SpellManager
#define SpellManager__vftable_x                                    0xAEB4D0
#define SpellManager__SpellManager_x                               0x689090
#define Spellmanager__LoadTextSpells_x                             0x689980
#define SpellManager__GetSpellByGroupAndRank_x                     0x689260

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99CE40

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x511960
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A43B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63A740
#define ItemGlobalIndex__IsValidIndex_x                            0x5119C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D17E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D1A60

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76DF50

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71B710
#define CCursorAttachment__AttachToCursor1_x                       0x71B750
#define CCursorAttachment__Deactivate_x                            0x71C740

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x947950
#define CSidlManagerBase__CreatePageWnd_x                          0x947140
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9433C0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x943350

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9648C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x964580

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50E880
#define CFindItemWnd__WndNotification_x                            0x50F360
#define CFindItemWnd__Update_x                                     0x50FED0
#define CFindItemWnd__PickupSelectedItem_x                         0x50E0D0

//IString
#define IString__Append_x                                          0x4F04A0

//Camera
#define CDisplay__cameraType_x                                     0xDFF530
#define EverQuest__Cameras_x                                       0xEC2A5C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517050
#define LootFiltersManager__GetItemFilterData_x                    0x516950
#define LootFiltersManager__RemoveItemLootFilter_x                 0x516980
#define LootFiltersManager__SetItemLootFilter_x                    0x516BA0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C5180

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A29D0
#define CResolutionHandler__GetWindowedStyle_x                     0x680850

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x713D40

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E63D0
#define CDistillerInfo__Instance_x                                 0x8E6370

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x734100
#define CGroupWnd__UpdateDisplay_x                                 0x733450

//ItemBase
#define ItemBase__IsLore_x                                         0x8A7290
#define ItemBase__IsLoreEquipped_x                                 0x8A7300

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D9260
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D93A0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D9400

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x675BE0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x679590

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x504CD0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1FD0
#define FactionManagerClient__HandleFactionMessage_x               0x4F2640
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2C40
#define FactionManagerClient__GetMaxFaction_x                      0x4F2C5F
#define FactionManagerClient__GetMinFaction_x                      0x4F2C10

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FCD70

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92C030

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE50

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD080

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x561230

//CTargetManager
#define CTargetManager__Get_x                                      0x68C8B0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x675BE0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D10

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AC8B0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF600F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
