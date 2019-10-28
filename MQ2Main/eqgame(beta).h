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
#define __ExpectedVersionDate                                     "Oct 28 2019"
#define __ExpectedVersionTime                                     "04:21:57"
#define __ActualVersionDate_x                                      0xB01D80
#define __ActualVersionTime_x                                      0xB01D74
#define __ActualVersionBuild_x                                     0xAEDA5C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x628770
#define __MemChecker1_x                                            0x8FAC20
#define __MemChecker2_x                                            0x6B6FD0
#define __MemChecker3_x                                            0x6B6F20
#define __MemChecker4_x                                            0x852BD0
#define __EncryptPad0_x                                            0xC373F0
#define __EncryptPad1_x                                            0xC955B0
#define __EncryptPad2_x                                            0xC47C88
#define __EncryptPad3_x                                            0xC47888
#define __EncryptPad4_x                                            0xC85C08
#define __EncryptPad5_x                                            0xF5ECCC
#define __AC1_x                                                    0x80F836
#define __AC2_x                                                    0x5E25FF
#define __AC3_x                                                    0x5E9CFF
#define __AC4_x                                                    0x5EDCC0
#define __AC5_x                                                    0x5F3FCF
#define __AC6_x                                                    0x5F85E6
#define __AC7_x                                                    0x5E2070
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1AE778

// Direct Input
#define DI8__Main_x                                                0xF611A8
#define DI8__Keyboard_x                                            0xF611AC
#define DI8__Mouse_x                                               0xF611C4
#define DI8__Mouse_Copy_x                                          0xEBA394
#define DI8__Mouse_Check_x                                         0xF5ECF4
#define __AutoSkillArray_x                                         0xEBB2AC
#define __Attack_x                                                 0xF590D3
#define __Autofire_x                                               0xF590D4
#define __BindList_x                                               0xC25E20
#define g_eqCommandStates_x                                        0xC26BA0
#define __Clicks_x                                                 0xEBA44C
#define __CommandList_x                                            0xC27760
#define __CurrentMapLabel_x                                        0xF71B54
#define __CurrentSocial_x                                          0xC0F7CC
#define __DoAbilityList_x                                          0xEF0BF4
#define __do_loot_x                                                0x5AE8D0
#define __DrawHandler_x                                            0x15F0EC8
#define __GroupCount_x                                             0xEAC78A
#define __Guilds_x                                                 0xEB0BA0
#define __gWorld_x                                                 0xEAC63C
#define __HWnd_x                                                   0xF611C8
#define __heqmain_x                                                0xF6119C
#define __InChatMode_x                                             0xEBA37C
#define __LastTell_x                                               0xEBC2F0
#define __LMouseHeldTime_x                                         0xEBA4B8
#define __Mouse_x                                                  0xF61188
#define __MouseLook_x                                              0xEBA412
#define __MouseEventTime_x                                         0xF59BB4
#define __gpbCommandEvent_x                                        0xEAC9EC
#define __NetStatusToggle_x                                        0xEBA415
#define __PCNames_x                                                0xEBB89C
#define __RangeAttackReady_x                                       0xEBB590
#define __RMouseHeldTime_x                                         0xEBA4B4
#define __RunWalkState_x                                           0xEBA380
#define __ScreenMode_x                                             0xDF7F6C
#define __ScreenX_x                                                0xEBA334
#define __ScreenY_x                                                0xEBA330
#define __ScreenXMax_x                                             0xEBA338
#define __ScreenYMax_x                                             0xEBA33C
#define __ServerHost_x                                             0xEACC23
#define __ServerName_x                                             0xEF0BB4
#define __ShiftKeyDown_x                                           0xEBAA0C
#define __ShowNames_x                                              0xEBB74C
#define __Socials_x                                                0xEF0CB4
#define __SubscriptionType_x                                       0xFB6058
#define __TargetAggroHolder_x                                      0xF74508
#define __ZoneType_x                                               0xEBA810
#define __GroupAggro_x                                             0xF74548
#define __LoginName_x                                              0xF61904
#define __Inviter_x                                                0xF59050
#define __AttackOnAssist_x                                         0xEBB708
#define __UseTellWindows_x                                         0xEBBA38
#define __gfMaxZoomCameraDistance_x                                0xAF76D0
#define __gfMaxCameraDistance_x                                    0xB23C44
#define __pulAutoRun_x                                             0xEBA430
#define __pulForward_x                                             0xEBBA70
#define __pulBackward_x                                            0xEBBA74
#define __pulTurnRight_x                                           0xEBBA78
#define __pulTurnLeft_x                                            0xEBBA7C
#define __pulStrafeLeft_x                                          0xEBBA80
#define __pulStrafeRight_x                                         0xEBBA84

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEACF38
#define instEQZoneInfo_x                                           0xEBA608
#define pinstActiveBanker_x                                        0xEACA04
#define pinstActiveCorpse_x                                        0xEAC9FC
#define pinstActiveGMaster_x                                       0xEACA00
#define pinstActiveMerchant_x                                      0xEAC9F8
#define pinstAltAdvManager_x                                       0xDF9168
#define pinstBandageTarget_x                                       0xEACA14
#define pinstCamActor_x                                            0xDF7F5C
#define pinstCDBStr_x                                              0xDF7E84
#define pinstCDisplay_x                                            0xEAC640
#define pinstCEverQuest_x                                          0xF611C0
#define pinstEverQuestInfo_x                                       0xEBA328
#define pinstCharData_x                                            0xEAC76C
#define pinstCharSpawn_x                                           0xEACACC
#define pinstControlledMissile_x                                   0xEACD2C
#define pinstControlledPlayer_x                                    0xEACACC
#define pinstCResolutionHandler_x                                  0x15F10F8
#define pinstCSidlManager_x                                        0x15F0090
#define pinstCXWndManager_x                                        0x15F008C
#define instDynamicZone_x                                          0xEB0A78
#define pinstDZMember_x                                            0xEB0B88
#define pinstDZTimerInfo_x                                         0xEB0B8C
#define pinstEqLogin_x                                             0xF61250
#define instEQMisc_x                                               0xDF7DC8
#define pinstEQSoundManager_x                                      0xDFA138
#define pinstEQSpellStrings_x                                      0xCBA868
#define instExpeditionLeader_x                                     0xEB0AC2
#define instExpeditionName_x                                       0xEB0B02
#define pinstGroup_x                                               0xEAC786
#define pinstImeManager_x                                          0x15F0088
#define pinstLocalPlayer_x                                         0xEAC9F4
#define pinstMercenaryData_x                                       0xF5B6AC
#define pinstMercenaryStats_x                                      0xF74654
#define pinstModelPlayer_x                                         0xEACA0C
#define pinstPCData_x                                              0xEAC76C
#define pinstSkillMgr_x                                            0xF5D810
#define pinstSpawnManager_x                                        0xF5C2B8
#define pinstSpellManager_x                                        0xF5DA30
#define pinstSpellSets_x                                           0xF51CFC
#define pinstStringTable_x                                         0xEAC770
#define pinstSwitchManager_x                                       0xEAA4D8
#define pinstTarget_x                                              0xEACAC8
#define pinstTargetObject_x                                        0xEACAD4
#define pinstTargetSwitch_x                                        0xEAA634
#define pinstTaskMember_x                                          0xDF7C58
#define pinstTrackTarget_x                                         0xEACAD0
#define pinstTradeTarget_x                                         0xEACA08
#define instTributeActive_x                                        0xDF7DE9
#define pinstViewActor_x                                           0xDF7F58
#define pinstWorldData_x                                           0xEAA628
#define pinstZoneAddr_x                                            0xEBA8A8
#define pinstPlayerPath_x                                          0xF5C350
#define pinstTargetIndicator_x                                     0xF5DC98
#define EQObject_Top_x                                             0xEAC9F0
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDF822C
#define pinstCAchievementsWnd_x                                    0xDF7FB8
#define pinstCActionsWnd_x                                         0xDF7FE8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDF8794
#define pinstCAdvancedLootWnd_x                                    0xDF8764
#define pinstCAdventureLeaderboardWnd_x                            0xF6B328
#define pinstCAdventureRequestWnd_x                                0xF6B3D8
#define pinstCAdventureStatsWnd_x                                  0xF6B488
#define pinstCAggroMeterWnd_x                                      0xDF7F50
#define pinstCAlarmWnd_x                                           0xDF8728
#define pinstCAlertHistoryWnd_x                                    0xDF875C
#define pinstCAlertStackWnd_x                                      0xDF8240
#define pinstCAlertWnd_x                                           0xDF8274
#define pinstCAltStorageWnd_x                                      0xF6B7E8
#define pinstCAudioTriggersWindow_x                                0xCACB98
#define pinstCAuraWnd_x                                            0xDF7F24
#define pinstCAvaZoneWnd_x                                         0xDF7FC0
#define pinstCBandolierWnd_x                                       0xDF7F4C
#define pinstCBankWnd_x                                            0xDF7F20
#define pinstCBarterMerchantWnd_x                                  0xF6CA28
#define pinstCBarterSearchWnd_x                                    0xF6CAD8
#define pinstCBarterWnd_x                                          0xF6CB88
#define pinstCBazaarConfirmationWnd_x                              0xDF7FF8
#define pinstCBazaarSearchWnd_x                                    0xDF7FAC
#define pinstCBazaarWnd_x                                          0xDF8714
#define pinstCBlockedBuffWnd_x                                     0xDF7F28
#define pinstCBlockedPetBuffWnd_x                                  0xDF7F48
#define pinstCBodyTintWnd_x                                        0xDF7FFC
#define pinstCBookWnd_x                                            0xDF7F8C
#define pinstCBreathWnd_x                                          0xDF826C
#define pinstCBuffWindowNORMAL_x                                   0xDF87AC
#define pinstCBuffWindowSHORT_x                                    0xDF87B0
#define pinstCBugReportWnd_x                                       0xDF87B8
#define pinstCButtonWnd_x                                          0x15F02F8
#define pinstCCastingWnd_x                                         0xDF7F7C
#define pinstCCastSpellWnd_x                                       0xDF8244
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDF8718
#define pinstCChatWindowManager_x                                  0xF6D648
#define pinstCClaimWnd_x                                           0xF6D7A0
#define pinstCColorPickerWnd_x                                     0xDF7FF0
#define pinstCCombatAbilityWnd_x                                   0xDF8724
#define pinstCCombatSkillsSelectWnd_x                              0xDF8744
#define pinstCCompassWnd_x                                         0xDF7FEC
#define pinstCConfirmationDialog_x                                 0xF726A0
#define pinstCContainerMgr_x                                       0xDF870C
#define pinstCContextMenuManager_x                                 0x15F0048
#define pinstCCursorAttachment_x                                   0xDF7F60
#define pinstCDynamicZoneWnd_x                                     0xF6DD68
#define pinstCEditLabelWnd_x                                       0xDF87A0
#define pinstCEQMainWnd_x                                          0xF6DFB0
#define pinstCEventCalendarWnd_x                                   0xDF87A8
#define pinstCExtendedTargetWnd_x                                  0xDF7F3C
#define pinstCFacePick_x                                           0xDF8754
#define pinstCFactionWnd_x                                         0xDF8300
#define pinstCFellowshipWnd_x                                      0xF6E1B0
#define pinstCFileSelectionWnd_x                                   0xDF7F78
#define pinstCFindItemWnd_x                                        0xDF8280
#define pinstCFindLocationWnd_x                                    0xF6E308
#define pinstCFriendsWnd_x                                         0xDF8760
#define pinstCGemsGameWnd_x                                        0xDF82FC
#define pinstCGiveWnd_x                                            0xDF872C
#define pinstCGroupSearchFiltersWnd_x                              0xDF7F84
#define pinstCGroupSearchWnd_x                                     0xF6E700
#define pinstCGroupWnd_x                                           0xF6E7B0
#define pinstCGuildBankWnd_x                                       0xEBB6EC
#define pinstCGuildCreationWnd_x                                   0xF6E910
#define pinstCGuildMgmtWnd_x                                       0xF6E9C0
#define pinstCharacterCreation_x                                   0xDF874C
#define pinstCHelpWnd_x                                            0xDF878C
#define pinstCHeritageSelectionWnd_x                               0xDF8768
#define pinstCHotButtonWnd_x                                       0xF70B18
#define pinstCHotButtonWnd1_x                                      0xF70B18
#define pinstCHotButtonWnd2_x                                      0xF70B1C
#define pinstCHotButtonWnd3_x                                      0xF70B20
#define pinstCHotButtonWnd4_x                                      0xF70B24
#define pinstCIconSelectionWnd_x                                   0xDF7F54
#define pinstCInspectWnd_x                                         0xDF8788
#define pinstCInventoryWnd_x                                       0xDF876C
#define pinstCInvSlotMgr_x                                         0xDF8228
#define pinstCItemDisplayManager_x                                 0xF710A8
#define pinstCItemExpTransferWnd_x                                 0xF711DC
#define pinstCItemOverflowWnd_x                                    0xDF7FB4
#define pinstCJournalCatWnd_x                                      0xDF7F94
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDF7F40
#define pinstCKeyRingWnd_x                                         0xDF879C
#define pinstCLargeDialogWnd_x                                     0xF73320
#define pinstCLayoutCopyWnd_x                                      0xF71528
#define pinstCLFGuildWnd_x                                         0xF715D8
#define pinstCLoadskinWnd_x                                        0xDF8710
#define pinstCLootFiltersCopyWnd_x                                 0xCC9160
#define pinstCLootFiltersWnd_x                                     0xDF8254
#define pinstCLootSettingsWnd_x                                    0xDF827C
#define pinstCLootWnd_x                                            0xDF7F98
#define pinstCMailAddressBookWnd_x                                 0xDF8234
#define pinstCMailCompositionWnd_x                                 0xDF8014
#define pinstCMailIgnoreListWnd_x                                  0xDF8238
#define pinstCMailWnd_x                                            0xDF7FE4
#define pinstCManageLootWnd_x                                      0xDF9618
#define pinstCMapToolbarWnd_x                                      0xDF8790
#define pinstCMapViewWnd_x                                         0xDF8778
#define pinstCMarketplaceWnd_x                                     0xDF8270
#define pinstCMerchantWnd_x                                        0xDF7F9C
#define pinstCMIZoneSelectWnd_x                                    0xF71E10
#define pinstCMusicPlayerWnd_x                                     0xDF7FA4
#define pinstCNameChangeMercWnd_x                                  0xDF7FE0
#define pinstCNameChangePetWnd_x                                   0xDF7FBC
#define pinstCNameChangeWnd_x                                      0xDF8008
#define pinstCNoteWnd_x                                            0xDF877C
#define pinstCObjectPreviewWnd_x                                   0xDF8278
#define pinstCOptionsWnd_x                                         0xDF8780
#define pinstCPetInfoWnd_x                                         0xDF7FC4
#define pinstCPetitionQWnd_x                                       0xDF7FA8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDF8000
#define pinstCPlayerWnd_x                                          0xDF7FC8
#define pinstCPopupWndManager_x                                    0xF726A0
#define pinstCProgressionSelectionWnd_x                            0xF72750
#define pinstCPurchaseGroupWnd_x                                   0xDF8734
#define pinstCPurchaseWnd_x                                        0xDF8708
#define pinstCPvPLeaderboardWnd_x                                  0xF72800
#define pinstCPvPStatsWnd_x                                        0xF728B0
#define pinstCQuantityWnd_x                                        0xDF7F44
#define pinstCRaceChangeWnd_x                                      0xDF8230
#define pinstCRaidOptionsWnd_x                                     0xDF7F88
#define pinstCRaidWnd_x                                            0xDF801C
#define pinstCRealEstateItemsWnd_x                                 0xDF7FB0
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDF7F30
#define pinstCRealEstateManageWnd_x                                0xDF873C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDF8758
#define pinstCRealEstatePlotSearchWnd_x                            0xDF8770
#define pinstCRealEstatePurchaseWnd_x                              0xDF8784
#define pinstCRespawnWnd_x                                         0xDF7F34
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDF823C
#define pinstCSendMoneyWnd_x                                       0xDF8740
#define pinstCServerListWnd_x                                      0xDF87A4
#define pinstCSkillsSelectWnd_x                                    0xDF871C
#define pinstCSkillsWnd_x                                          0xDF828C
#define pinstCSocialEditWnd_x                                      0xDF8798
#define pinstCSocialWnd_x                                          0xDF7FDC
#define pinstCSpellBookWnd_x                                       0xDF8720
#define pinstCStoryWnd_x                                           0xDF7FCC
#define pinstCTargetOfTargetWnd_x                                  0xF746D8
#define pinstCTargetWnd_x                                          0xDF7F2C
#define pinstCTaskOverlayWnd_x                                     0xDF8730
#define pinstCTaskSelectWnd_x                                      0xF74830
#define pinstCTaskManager_x                                        0xCC9AA0
#define pinstCTaskTemplateSelectWnd_x                              0xF748E0
#define pinstCTaskWnd_x                                            0xF74990
#define pinstCTextEntryWnd_x                                       0xDF87B4
#define pinstCTimeLeftWnd_x                                        0xDF7F80
#define pinstCTipWndCONTEXT_x                                      0xF74B94
#define pinstCTipWndOFDAY_x                                        0xF74B90
#define pinstCTitleWnd_x                                           0xF74C40
#define pinstCTrackingWnd_x                                        0xDF8774
#define pinstCTradeskillWnd_x                                      0xF74DA8
#define pinstCTradeWnd_x                                           0xDF800C
#define pinstCTrainWnd_x                                           0xDF8004
#define pinstCTributeBenefitWnd_x                                  0xF74FA8
#define pinstCTributeMasterWnd_x                                   0xF75058
#define pinstCTributeTrophyWnd_x                                   0xF75108
#define pinstCVideoModesWnd_x                                      0xDF8018
#define pinstCVoiceMacroWnd_x                                      0xF5E400
#define pinstCVoteResultsWnd_x                                     0xDF7FA0
#define pinstCVoteWnd_x                                            0xDF7F90
#define pinstCWebManager_x                                         0xF5EA7C
#define pinstCZoneGuideWnd_x                                       0xDF8738
#define pinstCZonePathWnd_x                                        0xDF8748

#define pinstEQSuiteTextureLoader_x                                0xC97088
#define pinstItemIconCache_x                                       0xF6DF68
#define pinstLootFiltersManager_x                                  0xCC9210
#define pinstRewardSelectionWnd_x                                  0xF72FF8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5A9D30
#define __CastRay2_x                                               0x5A9D80
#define __ConvertItemTags_x                                        0x5C58D0
#define __CleanItemTags_x                                          0x47D130
#define __DoesFileExist_x                                          0x8FDCB0
#define __EQGetTime_x                                              0x8FA6F0
#define __ExecuteCmd_x                                             0x5A2610
#define __FixHeading_x                                             0x9951F0
#define __GameLoop_x                                               0x6B61C0
#define __get_bearing_x                                            0x5A98A0
#define __get_melee_range_x                                        0x5A9F70
#define __GetAnimationCache_x                                      0x71B620
#define __GetGaugeValueFromEQ_x                                    0x80DCE0
#define __GetLabelFromEQ_x                                         0x80F7C0
#define __GetXTargetType_x                                         0x996BD0
#define __HandleMouseWheel_x                                       0x6B7080
#define __HeadingDiff_x                                            0x995260
#define __HelpPath_x                                               0xF597A4
#define __LoadFrontEnd_x                                           0x6B34E0
#define __NewUIINI_x                                               0x80D9B0
#define __ProcessGameEvents_x                                      0x609E50
#define __ProcessMouseEvent_x                                      0x609610
#define __SaveColors_x                                             0x54EA50
#define __STMLToText_x                                             0x9386B0
#define __ToggleKeyRingItem_x                                      0x5122A0
#define CMemoryMappedFile__SetFile_x                               0xA844E0
#define CrashDetected_x                                            0x6B4F80
#define DrawNetStatus_x                                            0x635970
#define Expansion_HoT_x                                            0xEBB6F4
#define Teleport_Table_Size_x                                      0xEACADC
#define Teleport_Table_x                                           0xEAA638
#define Util__FastTime_x                                           0x8FA2C0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490380
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499280
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499050
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493910
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x556640
#define AltAdvManager__IsAbilityReady_x                            0x555570
#define AltAdvManager__GetAAById_x                                 0x555770
#define AltAdvManager__CanTrainAbility_x                           0x5557E0
#define AltAdvManager__CanSeeAbility_x                             0x555B40

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA260
#define CharacterZoneClient__HasSkill_x                            0x4D5150
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6870
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE590
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAB90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9200
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D92E0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D93C0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3380
#define CharacterZoneClient__BardCastBard_x                        0x4C5EE0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAC60
#define CharacterZoneClient__GetEffect_x                           0x4BAAD0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C43D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C44A0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C44F0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4640
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4810
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2A40
#define CharacterZoneClient__FindItemByGuid_x                      0x4D77D0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7250

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DCB10
#define CBankWnd__WndNotification_x                                0x6DC8F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EA1D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x618580
#define CButtonWnd__CButtonWnd_x                                   0x934A90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70A650
#define CChatManager__InitContextMenu_x                            0x7037A0
#define CChatManager__FreeChatWindow_x                             0x709190
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8860
#define CChatManager__SetLockedActiveChatWindow_x                  0x70A2D0
#define CChatManager__CreateChatWindow_x                           0x7097D0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8970

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x949140
#define CContextMenu__dCContextMenu_x                              0x949370
#define CContextMenu__AddMenuItem_x                                0x949380
#define CContextMenu__RemoveMenuItem_x                             0x949680
#define CContextMenu__RemoveAllMenuItems_x                         0x9496A0
#define CContextMenu__CheckMenuItem_x                              0x949720
#define CContextMenu__SetMenuItem_x                                0x9495B0
#define CContextMenu__AddSeparator_x                               0x949510

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x949CC0
#define CContextMenuManager__RemoveMenu_x                          0x949D30
#define CContextMenuManager__PopupMenu_x                           0x949DF0
#define CContextMenuManager__Flush_x                               0x949C60
#define CContextMenuManager__GetMenu_x                             0x49B480
#define CContextMenuManager__CreateDefaultMenu_x                   0x715E00

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D72B0
#define CChatService__GetFriendName_x                              0x8D72C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70AEC0
#define CChatWindow__Clear_x                                       0x70C180
#define CChatWindow__WndNotification_x                             0x70C910
#define CChatWindow__AddHistory_x                                  0x70BA40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9465B0
#define CComboWnd__Draw_x                                          0x945AB0
#define CComboWnd__GetCurChoice_x                                  0x9463F0
#define CComboWnd__GetListRect_x                                   0x945F60
#define CComboWnd__GetTextRect_x                                   0x946610
#define CComboWnd__InsertChoice_x                                  0x9460F0
#define CComboWnd__SetColors_x                                     0x9460C0
#define CComboWnd__SetChoice_x                                     0x9463C0
#define CComboWnd__GetItemCount_x                                  0x946400
#define CComboWnd__GetCurChoiceText_x                              0x946440
#define CComboWnd__GetChoiceText_x                                 0x946410
#define CComboWnd__InsertChoiceAtIndex_x                           0x946180

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7137E0
#define CContainerWnd__vftable_x                                   0xB0AF64
#define CContainerWnd__SetContainer_x                              0x714D40

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x549490
#define CDisplay__PreZoneMainUI_x                                  0x5494A0
#define CDisplay__CleanGameUI_x                                    0x54E810
#define CDisplay__GetClickedActor_x                                0x5417B0
#define CDisplay__GetUserDefinedColor_x                            0x539E70
#define CDisplay__GetWorldFilePath_x                               0x543220
#define CDisplay__is3dON_x                                         0x53E410
#define CDisplay__ReloadUI_x                                       0x548920
#define CDisplay__WriteTextHD2_x                                   0x53E200
#define CDisplay__TrueDistance_x                                   0x544EE0
#define CDisplay__SetViewActor_x                                   0x5410D0
#define CDisplay__GetFloorHeight_x                                 0x53E4D0
#define CDisplay__SetRenderWindow_x                                0x53CE30
#define CDisplay__ToggleScreenshotMode_x                           0x540BA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x968EB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x94C690
#define CEditWnd__GetCharIndexPt_x                                 0x94D5B0
#define CEditWnd__GetDisplayString_x                               0x94D450
#define CEditWnd__GetHorzOffset_x                                  0x94BCC0
#define CEditWnd__GetLineForPrintableChar_x                        0x94E740
#define CEditWnd__GetSelStartPt_x                                  0x94D850
#define CEditWnd__GetSTMLSafeText_x                                0x94D270
#define CEditWnd__PointFromPrintableChar_x                         0x94E370
#define CEditWnd__SelectableCharFromPoint_x                        0x94E4E0
#define CEditWnd__SetEditable_x                                    0x94D920
#define CEditWnd__SetWindowTextA_x                                 0x94CFF0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5F7AC0
#define CEverQuest__ClickedPlayer_x                                0x5E9AE0
#define CEverQuest__CreateTargetIndicator_x                        0x6070F0
#define CEverQuest__DeleteTargetIndicator_x                        0x607180
#define CEverQuest__DoTellWindow_x                                 0x4E8A50
#define CEverQuest__OutputTextToLog_x                              0x4E8CD0
#define CEverQuest__DropHeldItemOnGround_x                         0x5DEB20
#define CEverQuest__dsp_chat_x                                     0x4E9060
#define CEverQuest__trimName_x                                     0x6033D0
#define CEverQuest__Emote_x                                        0x5F8320
#define CEverQuest__EnterZone_x                                    0x5F22A0
#define CEverQuest__GetBodyTypeDesc_x                              0x5FCC90
#define CEverQuest__GetClassDesc_x                                 0x5FD2D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5FD8D0
#define CEverQuest__GetDeityDesc_x                                 0x605A30
#define CEverQuest__GetLangDesc_x                                  0x5FDA90
#define CEverQuest__GetRaceDesc_x                                  0x5FD2B0
#define CEverQuest__InterpretCmd_x                                 0x606000
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E2D20
#define CEverQuest__LMouseUp_x                                     0x5E10B0
#define CEverQuest__RightClickedOnPlayer_x                         0x5E3600
#define CEverQuest__RMouseUp_x                                     0x5E2030
#define CEverQuest__SetGameState_x                                 0x5DE8B0
#define CEverQuest__UPCNotificationFlush_x                         0x6032D0
#define CEverQuest__IssuePetCommand_x                              0x5FEE90
#define CEverQuest__ReportSuccessfulHit_x                          0x5F9710

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7257C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x725820
#define CGaugeWnd__Draw_x                                          0x724E40

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF460
#define CGuild__GetGuildName_x                                     0x4AE540
#define CGuild__GetGuildIndex_x                                    0x4AE8D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x740C10

//CHotButton
#define CHotButton__SetButtonSize_x                                0x618940

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74DBE0
#define CInvSlotMgr__MoveItem_x                                    0x74C950
#define CInvSlotMgr__SelectSlot_x                                  0x74DCB0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74B1D0
#define CInvSlot__SliderComplete_x                                 0x748F30
#define CInvSlot__GetItemBase_x                                    0x7488C0
#define CInvSlot__UpdateItem_x                                     0x748A30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74F720
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74E8D0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74F2A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x809030
#define CItemDisplayWnd__UpdateStrings_x                           0x75DE10
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x757B90
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7580B0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75E410
#define CItemDisplayWnd__AboutToShow_x                             0x75DA70
#define CItemDisplayWnd__WndNotification_x                         0x75F4F0
#define CItemDisplayWnd__RequestConvertItem_x                      0x75EFB0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75CAE0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75D890

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x841B60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x763A00

// CLabel 
#define CLabel__Draw_x                                             0x769470

// CListWnd
#define CListWnd__CListWnd_x                                       0x91ED70
#define CListWnd__dCListWnd_x                                      0x91F090
#define CListWnd__AddColumn_x                                      0x9234C0
#define CListWnd__AddColumn1_x                                     0x923510
#define CListWnd__AddLine_x                                        0x9238A0
#define CListWnd__AddString_x                                      0x9236A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x923290
#define CListWnd__CalculateVSBRange_x                              0x923080
#define CListWnd__ClearSel_x                                       0x924080
#define CListWnd__ClearAllSel_x                                    0x9240E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x924AD0
#define CListWnd__Compare_x                                        0x9229B0
#define CListWnd__Draw_x                                           0x91F1C0
#define CListWnd__DrawColumnSeparators_x                           0x9219A0
#define CListWnd__DrawHeader_x                                     0x921E00
#define CListWnd__DrawItem_x                                       0x9222F0
#define CListWnd__DrawLine_x                                       0x921B00
#define CListWnd__DrawSeparator_x                                  0x921A40
#define CListWnd__EnableLine_x                                     0x921280
#define CListWnd__EnsureVisible_x                                  0x924A10
#define CListWnd__ExtendSel_x                                      0x923FB0
#define CListWnd__GetColumnTooltip_x                               0x920DC0
#define CListWnd__GetColumnMinWidth_x                              0x920E30
#define CListWnd__GetColumnWidth_x                                 0x920D30
#define CListWnd__GetCurSel_x                                      0x9206C0
#define CListWnd__GetItemAtPoint_x                                 0x9214F0
#define CListWnd__GetItemAtPoint1_x                                0x921560
#define CListWnd__GetItemData_x                                    0x920740
#define CListWnd__GetItemHeight_x                                  0x920B00
#define CListWnd__GetItemIcon_x                                    0x9208D0
#define CListWnd__GetItemRect_x                                    0x921370
#define CListWnd__GetItemText_x                                    0x920780
#define CListWnd__GetSelList_x                                     0x924130
#define CListWnd__GetSeparatorRect_x                               0x9217A0
#define CListWnd__InsertLine_x                                     0x923C90
#define CListWnd__RemoveLine_x                                     0x923DE0
#define CListWnd__SetColors_x                                      0x923050
#define CListWnd__SetColumnJustification_x                         0x922D80
#define CListWnd__SetColumnWidth_x                                 0x922CA0
#define CListWnd__SetCurSel_x                                      0x923EF0
#define CListWnd__SetItemColor_x                                   0x9246D0
#define CListWnd__SetItemData_x                                    0x924690
#define CListWnd__SetItemText_x                                    0x9242A0
#define CListWnd__ShiftColumnSeparator_x                           0x922E40
#define CListWnd__Sort_x                                           0x922B30
#define CListWnd__ToggleSel_x                                      0x923F20
#define CListWnd__SetColumnsSizable_x                              0x922EF0
#define CListWnd__SetItemWnd_x                                     0x924550
#define CListWnd__GetItemWnd_x                                     0x920920
#define CListWnd__SetItemIcon_x                                    0x924320
#define CListWnd__CalculateCustomWindowPositions_x                 0x923380
#define CListWnd__SetVScrollPos_x                                  0x922C80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77EB70
#define CMapViewWnd__GetWorldCoordinates_x                         0x77D280
#define CMapViewWnd__HandleLButtonDown_x                           0x77A2C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79EC70
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79F550
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79FA80
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A2A00
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79D7E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A85B0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79E880

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A4BB0
#define CPacketScrambler__hton_x                                   0x8A4BA0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x93DCD0
#define CSidlManager__FindScreenPieceTemplate_x                    0x93E0E0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x93DED0
#define CSidlManager__CreateLabel_x                                0x800460
#define CSidlManager__CreateXWndFromTemplate_x                     0x941040
#define CSidlManager__CreateXWndFromTemplate1_x                    0x941220
#define CSidlManager__CreateXWnd_x                                 0x800390
#define CSidlManager__CreateHotButtonWnd_x                         0x800960

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93A7D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93A6E0
#define CSidlScreenWnd__ConvertToRes_x                             0x95FE50
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93A170
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x939E60
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x939F30
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93A000
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93AC60
#define CSidlScreenWnd__EnableIniStorage_x                         0x93B130
#define CSidlScreenWnd__GetSidlPiece_x                             0x93AE50
#define CSidlScreenWnd__Init1_x                                    0x939A60
#define CSidlScreenWnd__LoadIniInfo_x                              0x93B180
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93BCB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x938E60
#define CSidlScreenWnd__StoreIniInfo_x                             0x93B830
#define CSidlScreenWnd__StoreIniVis_x                              0x93BB90
#define CSidlScreenWnd__WndNotification_x                          0x93AB70
#define CSidlScreenWnd__GetChildItem_x                             0x93B0B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92A840
#define CSidlScreenWnd__m_layoutCopy_x                             0x15EFF18

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x67CB90
#define CSkillMgr__GetSkillCap_x                                   0x67CD70
#define CSkillMgr__GetNameToken_x                                  0x67C310
#define CSkillMgr__IsActivatedSkill_x                              0x67C450
#define CSkillMgr__IsCombatSkill_x                                 0x67C390

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94AAA0
#define CSliderWnd__SetValue_x                                     0x94A910
#define CSliderWnd__SetNumTicks_x                                  0x94A970

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8064C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x953270
#define CStmlWnd__CalculateHSBRange_x                              0x9543C0
#define CStmlWnd__CalculateVSBRange_x                              0x954340
#define CStmlWnd__CanBreakAtCharacter_x                            0x958700
#define CStmlWnd__FastForwardToEndOfTag_x                          0x959390
#define CStmlWnd__ForceParseNow_x                                  0x9538A0
#define CStmlWnd__GetNextTagPiece_x                                0x958660
#define CStmlWnd__GetSTMLText_x                                    0x501820
#define CStmlWnd__GetVisibleText_x                                 0x9538C0
#define CStmlWnd__InitializeWindowVariables_x                      0x9591E0
#define CStmlWnd__MakeStmlColorTag_x                               0x9528E0
#define CStmlWnd__MakeWndNotificationTag_x                         0x952950
#define CStmlWnd__SetSTMLText_x                                    0x951990
#define CStmlWnd__StripFirstSTMLLines_x                            0x95A450
#define CStmlWnd__UpdateHistoryString_x                            0x9595A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x950AE0
#define CTabWnd__DrawCurrentPage_x                                 0x951210
#define CTabWnd__DrawTab_x                                         0x950F30
#define CTabWnd__GetCurrentPage_x                                  0x9502E0
#define CTabWnd__GetPageInnerRect_x                                0x950520
#define CTabWnd__GetTabInnerRect_x                                 0x950460
#define CTabWnd__GetTabRect_x                                      0x950310
#define CTabWnd__InsertPage_x                                      0x950730
#define CTabWnd__SetPage_x                                         0x9505A0
#define CTabWnd__SetPageRect_x                                     0x950A20
#define CTabWnd__UpdatePage_x                                      0x950DF0
#define CTabWnd__GetPageFromTabIndex_x                             0x950E70
#define CTabWnd__GetCurrentTabIndex_x                              0x9502D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x763DF0
#define CPageWnd__SetTabText_x                                     0x94FE30

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A90E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x927710
#define CTextureFont__GetTextExtent_x                              0x9278D0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B00A0
#define CHtmlComponentWnd__ValidateUri_x                           0x742620
#define CHtmlWnd__SetClientCallbacks_x                             0x61D9B0
#define CHtmlWnd__AddObserver_x                                    0x61D9D0
#define CHtmlWnd__RemoveObserver_x                                 0x61DA30
#define Window__getProgress_x                                      0x85A1A0
#define Window__getStatus_x                                        0x85A1C0
#define Window__getURI_x                                           0x85A1D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x965940

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x9148A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E86A0
#define CXStr__CXStr1_x                                            0x4FC890
#define CXStr__CXStr3_x                                            0x8F6830
#define CXStr__dCXStr_x                                            0x4786B0
#define CXStr__operator_equal_x                                    0x8F6A60
#define CXStr__operator_equal1_x                                   0x8F6AA0
#define CXStr__operator_plus_equal1_x                              0x8F7530
#define CXStr__SetString_x                                         0x8F9420
#define CXStr__operator_char_p_x                                   0x8F6FA0
#define CXStr__GetChar_x                                           0x8F8D70
#define CXStr__Delete_x                                            0x8F8620
#define CXStr__GetUnicode_x                                        0x8F8DE0
#define CXStr__GetLength_x                                         0x47D4E0
#define CXStr__Mid_x                                               0x47D4F0
#define CXStr__Insert_x                                            0x8F8E40
#define CXStr__FindNext_x                                          0x8F8A90

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x948D60
#define CXWnd__BringToTop_x                                        0x92DFF0
#define CXWnd__Center_x                                            0x92DB70
#define CXWnd__ClrFocus_x                                          0x92D990
#define CXWnd__Destroy_x                                           0x92DA30
#define CXWnd__DoAllDrawing_x                                      0x92A000
#define CXWnd__DrawChildren_x                                      0x929FD0
#define CXWnd__DrawColoredRect_x                                   0x92A450
#define CXWnd__DrawTooltip_x                                       0x928B20
#define CXWnd__DrawTooltipAtPoint_x                                0x928BE0
#define CXWnd__GetBorderFrame_x                                    0x92A2B0
#define CXWnd__GetChildWndAt_x                                     0x92E090
#define CXWnd__GetClientClipRect_x                                 0x92C260
#define CXWnd__GetScreenClipRect_x                                 0x92C330
#define CXWnd__GetScreenRect_x                                     0x92C500
#define CXWnd__GetTooltipRect_x                                    0x92A4A0
#define CXWnd__GetWindowTextA_x                                    0x49CB90
#define CXWnd__IsActive_x                                          0x92ABB0
#define CXWnd__IsDescendantOf_x                                    0x92CEE0
#define CXWnd__IsReallyVisible_x                                   0x92CF10
#define CXWnd__IsType_x                                            0x92E6F0
#define CXWnd__Move_x                                              0x92CF80
#define CXWnd__Move1_x                                             0x92D040
#define CXWnd__ProcessTransition_x                                 0x92DB20
#define CXWnd__Refade_x                                            0x92D320
#define CXWnd__Resize_x                                            0x92D5E0
#define CXWnd__Right_x                                             0x92DDB0
#define CXWnd__SetFocus_x                                          0x92D950
#define CXWnd__SetFont_x                                           0x92D9C0
#define CXWnd__SetKeyTooltip_x                                     0x92E500
#define CXWnd__SetMouseOver_x                                      0x92B3D0
#define CXWnd__StartFade_x                                         0x92CDC0
#define CXWnd__GetChildItem_x                                      0x92E200
#define CXWnd__SetParent_x                                         0x92CCB0
#define CXWnd__Minimize_x                                          0x92D640

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x960ED0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x930F90
#define CXWndManager__DrawWindows_x                                0x930FB0
#define CXWndManager__GetKeyboardFlags_x                           0x933720
#define CXWndManager__HandleKeyboardMsg_x                          0x9332D0
#define CXWndManager__RemoveWnd_x                                  0x933960
#define CXWndManager__RemovePendingDeletionWnd_x                   0x933EB0

// CDBStr
#define CDBStr__GetString_x                                        0x538D30

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBB70
#define EQ_Character__Cur_HP_x                                     0x4D2190
#define EQ_Character__Cur_Mana_x                                   0x4D98C0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEBE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2680
#define EQ_Character__GetFocusRangeModifier_x                      0x4B27D0
#define EQ_Character__GetHPRegen_x                                 0x4DF670
#define EQ_Character__GetEnduranceRegen_x                          0x4DFC70
#define EQ_Character__GetManaRegen_x                               0x4E00B0
#define EQ_Character__Max_Endurance_x                              0x643A90
#define EQ_Character__Max_HP_x                                     0x4D1FC0
#define EQ_Character__Max_Mana_x                                   0x643890
#define EQ_Character__doCombatAbility_x                            0x645EE0
#define EQ_Character__UseSkill_x                                   0x4E1E80
#define EQ_Character__GetConLevel_x                                0x63C8D0
#define EQ_Character__IsExpansionFlag_x                            0x5A0DD0
#define EQ_Character__TotalEffect_x                                0x4C5620
#define EQ_Character__GetPCSpellAffect_x                           0x4BF930
#define EQ_Character__SpellDuration_x                              0x4BF460
#define EQ_Character__GetAdjustedSkill_x                           0x4D4F10
#define EQ_Character__GetBaseSkill_x                               0x4D5EB0
#define EQ_Character__CanUseItem_x                                 0x4D9BD0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C4110

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x659FD0

//PcClient
#define PcClient__PcClient_x                                       0x63A020

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B97E0
#define CCharacterListWnd__EnterWorld_x                            0x4B9220
#define CCharacterListWnd__Quit_x                                  0x4B8F70
#define CCharacterListWnd__UpdateList_x                            0x4B93B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x61EC00
#define EQ_Item__CreateItemTagString_x                             0x89E420
#define EQ_Item__IsStackable_x                                     0x8A2F80
#define EQ_Item__GetImageNum_x                                     0x89FE80
#define EQ_Item__CreateItemClient_x                                0x61DDD0
#define EQ_Item__GetItemValue_x                                    0x8A1190
#define EQ_Item__ValueSellMerchant_x                               0x8A4790
#define EQ_Item__IsKeyRingItem_x                                   0x8A28B0
#define EQ_Item__CanGoInBag_x                                      0x61ED20
#define EQ_Item__IsEmpty_x                                         0x8A23F0
#define EQ_Item__GetMaxItemCount_x                                 0x8A15A0
#define EQ_Item__GetHeldItem_x                                     0x89FD50
#define EQ_Item__GetAugmentFitBySlot_x                             0x89DDA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x557320
#define EQ_LoadingS__Array_x                                       0xC1EB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6443F0
#define EQ_PC__GetAlternateAbilityId_x                             0x8ADA50
#define EQ_PC__GetCombatAbility_x                                  0x8AE0C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AE130
#define EQ_PC__GetItemRecastTimer_x                                0x646460
#define EQ_PC__HasLoreItem_x                                       0x63D090
#define EQ_PC__AlertInventoryChanged_x                             0x63C220
#define EQ_PC__GetPcZoneClient_x                                   0x668A50
#define EQ_PC__RemoveMyAffect_x                                    0x649690
#define EQ_PC__GetKeyRingItems_x                                   0x8AE9C0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AE750
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AECC0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A7340
#define EQItemList__add_object_x                                   0x5D4310
#define EQItemList__add_item_x                                     0x5A78A0
#define EQItemList__delete_item_x                                  0x5A78F0
#define EQItemList__FreeItemList_x                                 0x5A77F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x535840

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65B850
#define EQPlayer__dEQPlayer_x                                      0x64EBB0
#define EQPlayer__DoAttack_x                                       0x663720
#define EQPlayer__EQPlayer_x                                       0x64F270
#define EQPlayer__SetNameSpriteState_x                             0x653530
#define EQPlayer__SetNameSpriteTint_x                              0x654400
#define PlayerBase__HasProperty_j_x                                0x9935D0
#define EQPlayer__IsTargetable_x                                   0x993A70
#define EQPlayer__CanSee_x                                         0x9938D0
#define EQPlayer__CanSee1_x                                        0x9939A0
#define PlayerBase__GetVisibilityLineSegment_x                     0x993690

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6664F0
#define PlayerZoneClient__GetLevel_x                               0x668A90
#define PlayerZoneClient__IsValidTeleport_x                        0x5D5480
#define PlayerZoneClient__LegalPlayerRace_x                        0x550670

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x65E620
#define EQPlayerManager__GetSpawnByName_x                          0x65E6D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x65E760

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6222F0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x622370
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6223B0
#define KeypressHandler__ClearCommandStateArray_x                  0x6237C0
#define KeypressHandler__HandleKeyDown_x                           0x6237E0
#define KeypressHandler__HandleKeyUp_x                             0x623880
#define KeypressHandler__SaveKeymapping_x                          0x623CD0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77A9E0
#define MapViewMap__SaveEx_x                                       0x77DDA0
#define MapViewMap__SetZoom_x                                      0x782460

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C2030

// StringTable 
#define StringTable__getString_x                                   0x8BCC30

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x649300
#define PcZoneClient__RemovePetEffect_x                            0x649930
#define PcZoneClient__HasAlternateAbility_x                        0x6436C0
#define PcZoneClient__GetCurrentMod_x                              0x4E4F40
#define PcZoneClient__GetModCap_x                                  0x4E4E40
#define PcZoneClient__CanEquipItem_x                               0x643D90
#define PcZoneClient__GetItemByID_x                                0x6468D0
#define PcZoneClient__GetItemByItemClass_x                         0x646A20
#define PcZoneClient__RemoveBuffEffect_x                           0x649950
#define PcZoneClient__BandolierSwap_x                              0x6449A0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x646400

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DA000

//IconCache
#define IconCache__GetIcon_x                                       0x71AEC0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7128D0
#define CContainerMgr__CloseContainer_x                            0x712BA0
#define CContainerMgr__OpenExperimentContainer_x                   0x713620

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D2B00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x616D60

//CLootWnd
#define CLootWnd__LootAll_x                                        0x770F50
#define CLootWnd__RequestLootSlot_x                                0x770180

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x574510
#define EQ_Spell__SpellAffects_x                                   0x574980
#define EQ_Spell__SpellAffectBase_x                                0x574740
#define EQ_Spell__IsStackable_x                                    0x4C9BE0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9A90
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6B30
#define EQ_Spell__IsSPAStacking_x                                  0x5757D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x574CE0
#define EQ_Spell__IsNoRemove_x                                     0x4C9BC0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5757E0
#define __IsResEffectSpell_x                                       0x4C9040

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD1A0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CC750

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8197F0
#define CTargetWnd__WndNotification_x                              0x819080
#define CTargetWnd__RefreshTargetBuffs_x                           0x819350
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8181F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81DE00

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x533260
#define CTaskManager__HandleMessage_x                              0x531710
#define CTaskManager__GetTaskStatus_x                              0x533310
#define CTaskManager__GetElementDescription_x                      0x533390

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x56FA60
#define EqSoundManager__PlayScriptMp3_x                            0x56FBC0
#define EqSoundManager__SoundAssistPlay_x                          0x680A80
#define EqSoundManager__WaveInstancePlay_x                         0x67FFF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x527010

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x94F340

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55ED20
#define CAltAbilityData__GetMercMaxRank_x                          0x55ECB0
#define CAltAbilityData__GetMaxRank_x                              0x5543F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x614E70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9A70
#define CharacterBase__CreateItemGlobalIndex_x                     0x50E840
#define CharacterBase__CreateItemIndex_x                           0x61CF60
#define CharacterBase__GetItemPossession_x                         0x4FA1A0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D4D40
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D4DA0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F98D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FA100
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FA1B0

//messages
#define msg_spell_worn_off_x                                       0x599030
#define msg_new_text_x                                             0x58DDE0
#define __msgTokenTextParam_x                                      0x59B560
#define msgTokenText_x                                             0x59B7B0

//SpellManager
#define SpellManager__vftable_x                                    0xAE516C
#define SpellManager__SpellManager_x                               0x683DA0
#define Spellmanager__LoadTextSpells_x                             0x684690
#define SpellManager__GetSpellByGroupAndRank_x                     0x683F70

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9974C0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50EEC0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x59F310
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6357D0
#define ItemGlobalIndex__IsValidIndex_x                            0x50EF20

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CD0F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CD370

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7697B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7170C0
#define CCursorAttachment__AttachToCursor1_x                       0x717100
#define CCursorAttachment__Deactivate_x                            0x7180F0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x942080
#define CSidlManagerBase__CreatePageWnd_x                          0x941870
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x93DAF0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x93DA80

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x95F430
#define CEQSuiteTextureLoader__GetTexture_x                        0x95F0F0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50BDB0
#define CFindItemWnd__WndNotification_x                            0x50C890
#define CFindItemWnd__Update_x                                     0x50D400
#define CFindItemWnd__PickupSelectedItem_x                         0x50B5F0

//IString
#define IString__Append_x                                          0x4FB9A0

//Camera
#define CDisplay__cameraType_x                                     0xDF8020
#define EverQuest__Cameras_x                                       0xEBBA44

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x514640
#define LootFiltersManager__GetItemFilterData_x                    0x513F40
#define LootFiltersManager__RemoveItemLootFilter_x                 0x513F70
#define LootFiltersManager__SetItemLootFilter_x                    0x514190

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C0A30

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x99D0D0
#define CResolutionHandler__GetWindowedStyle_x                     0x67B750

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70F620

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E0D60
#define CDistillerInfo__Instance_x                                 0x8E0D00

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72F9F0
#define CGroupWnd__UpdateDisplay_x                                 0x72ED40

//ItemBase
#define ItemBase__IsLore_x                                         0x8A2950
#define ItemBase__IsLoreEquipped_x                                 0x8A29C0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D4270
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D43B0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D4410

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x671150
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x674AF0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x502090

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F0BF0
#define FactionManagerClient__HandleFactionMessage_x               0x4F1260
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F1820
#define FactionManagerClient__GetMaxFaction_x                      0x4F183F
#define FactionManagerClient__GetMinFaction_x                      0x4F17F0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FA170

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x926770

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE70

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FA3B0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55E1E0

//CTargetManager
#define CTargetManager__Get_x                                      0x687600

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x671150

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8EA0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A7790

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF590D8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
