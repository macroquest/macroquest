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
#define __ExpectedVersionDate                                     "Nov  9 2019"
#define __ExpectedVersionTime                                     "04:26:15"
#define __ActualVersionDate_x                                      0xB0829C
#define __ActualVersionTime_x                                      0xB08290
#define __ActualVersionBuild_x                                     0xAF3F3C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62D520
#define __MemChecker1_x                                            0x900EA0
#define __MemChecker2_x                                            0x6BBF40
#define __MemChecker3_x                                            0x6BBE90
#define __MemChecker4_x                                            0x8580B0
#define __EncryptPad0_x                                            0xC3E3E8
#define __EncryptPad1_x                                            0xC9C5A8
#define __EncryptPad2_x                                            0xC4EC80
#define __EncryptPad3_x                                            0xC4E880
#define __EncryptPad4_x                                            0xC8CC00
#define __EncryptPad5_x                                            0xF68240
#define __AC1_x                                                    0x814B76
#define __AC2_x                                                    0x5E744F
#define __AC3_x                                                    0x5EEB4F
#define __AC4_x                                                    0x5F2B20
#define __AC5_x                                                    0x5F8E2F
#define __AC6_x                                                    0x5FD446
#define __AC7_x                                                    0x5E6EC0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19FE2C

// Direct Input
#define DI8__Main_x                                                0xF68268
#define DI8__Keyboard_x                                            0xF6826C
#define DI8__Mouse_x                                               0xF6824C
#define DI8__Mouse_Copy_x                                          0xEC144C
#define DI8__Mouse_Check_x                                         0xF65D94
#define __AutoSkillArray_x                                         0xEC2364
#define __Attack_x                                                 0xF6018B
#define __Autofire_x                                               0xF6018C
#define __BindList_x                                               0xC2CE20
#define g_eqCommandStates_x                                        0xC2DBA0
#define __Clicks_x                                                 0xEC1504
#define __CommandList_x                                            0xC2E760
#define __CurrentMapLabel_x                                        0xF78C0C
#define __CurrentSocial_x                                          0xC167CC
#define __DoAbilityList_x                                          0xEF7CAC
#define __do_loot_x                                                0x5B3740
#define __DrawHandler_x                                            0x15F7F80
#define __GroupCount_x                                             0xEB3E02
#define __Guilds_x                                                 0xEB7C58
#define __gWorld_x                                                 0xEB3C50
#define __HWnd_x                                                   0xF68250
#define __heqmain_x                                                0xF68228
#define __InChatMode_x                                             0xEC1434
#define __LastTell_x                                               0xEC33A8
#define __LMouseHeldTime_x                                         0xEC1570
#define __Mouse_x                                                  0xF68254
#define __MouseLook_x                                              0xEC14CA
#define __MouseEventTime_x                                         0xF60C6C
#define __gpbCommandEvent_x                                        0xEB16F0
#define __NetStatusToggle_x                                        0xEC14CD
#define __PCNames_x                                                0xEC2954
#define __RangeAttackReady_x                                       0xEC2648
#define __RMouseHeldTime_x                                         0xEC156C
#define __RunWalkState_x                                           0xEC1438
#define __ScreenMode_x                                             0xDFF0A4
#define __ScreenX_x                                                0xEC13EC
#define __ScreenY_x                                                0xEC13E8
#define __ScreenXMax_x                                             0xEC13F0
#define __ScreenYMax_x                                             0xEC13F4
#define __ServerHost_x                                             0xEB192B
#define __ServerName_x                                             0xEF7C6C
#define __ShiftKeyDown_x                                           0xEC1AC4
#define __ShowNames_x                                              0xEC2804
#define __Socials_x                                                0xEF7D6C
#define __SubscriptionType_x                                       0xFBD110
#define __TargetAggroHolder_x                                      0xF7B5C0
#define __ZoneType_x                                               0xEC18C8
#define __GroupAggro_x                                             0xF7B600
#define __LoginName_x                                              0xF689BC
#define __Inviter_x                                                0xF60108
#define __AttackOnAssist_x                                         0xEC27C0
#define __UseTellWindows_x                                         0xEC2AF0
#define __gfMaxZoomCameraDistance_x                                0xAFDBB0
#define __gfMaxCameraDistance_x                                    0xB2A0F4
#define __pulAutoRun_x                                             0xEC14E8
#define __pulForward_x                                             0xEC2B28
#define __pulBackward_x                                            0xEC2B2C
#define __pulTurnRight_x                                           0xEC2B30
#define __pulTurnLeft_x                                            0xEC2B34
#define __pulStrafeLeft_x                                          0xEC2B38
#define __pulStrafeRight_x                                         0xEC2B3C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB3FF8
#define instEQZoneInfo_x                                           0xEC16C0
#define pinstActiveBanker_x                                        0xEB1708
#define pinstActiveCorpse_x                                        0xEB1700
#define pinstActiveGMaster_x                                       0xEB1704
#define pinstActiveMerchant_x                                      0xEB16FC
#define pinstAltAdvManager_x                                       0xE00228
#define pinstBandageTarget_x                                       0xEB1718
#define pinstCamActor_x                                            0xDFF098
#define pinstCDBStr_x                                              0xDFEF44
#define pinstCDisplay_x                                            0xEB3C4C
#define pinstCEverQuest_x                                          0xF68280
#define pinstEverQuestInfo_x                                       0xEC13E0
#define pinstCharData_x                                            0xEB3DE4
#define pinstCharSpawn_x                                           0xEB17D0
#define pinstControlledMissile_x                                   0xEB1C3C
#define pinstControlledPlayer_x                                    0xEB17D0
#define pinstCResolutionHandler_x                                  0x15F81B0
#define pinstCSidlManager_x                                        0x15F7148
#define pinstCXWndManager_x                                        0x15F7144
#define instDynamicZone_x                                          0xEB7B30
#define pinstDZMember_x                                            0xEB7C40
#define pinstDZTimerInfo_x                                         0xEB7C44
#define pinstEqLogin_x                                             0xF68308
#define instEQMisc_x                                               0xDFEE88
#define pinstEQSoundManager_x                                      0xE011F8
#define pinstEQSpellStrings_x                                      0xCC18F8
#define instExpeditionLeader_x                                     0xEB7B7A
#define instExpeditionName_x                                       0xEB7BBA
#define pinstGroup_x                                               0xEB3DFE
#define pinstImeManager_x                                          0x15F7140
#define pinstLocalPlayer_x                                         0xEB16F8
#define pinstMercenaryData_x                                       0xF6275C
#define pinstMercenaryStats_x                                      0xF7B70C
#define pinstModelPlayer_x                                         0xEB1710
#define pinstPCData_x                                              0xEB3DE4
#define pinstSkillMgr_x                                            0xF648C8
#define pinstSpawnManager_x                                        0xF63370
#define pinstSpellManager_x                                        0xF64AE8
#define pinstSpellSets_x                                           0xF58DB4
#define pinstStringTable_x                                         0xEB3DE8
#define pinstSwitchManager_x                                       0xEB1598
#define pinstTarget_x                                              0xEB174C
#define pinstTargetObject_x                                        0xEB17D8
#define pinstTargetSwitch_x                                        0xEB1C44
#define pinstTaskMember_x                                          0xDFED18
#define pinstTrackTarget_x                                         0xEB17D4
#define pinstTradeTarget_x                                         0xEB170C
#define instTributeActive_x                                        0xDFEEA9
#define pinstViewActor_x                                           0xDFF094
#define pinstWorldData_x                                           0xEB1824
#define pinstZoneAddr_x                                            0xEC1960
#define pinstPlayerPath_x                                          0xF63408
#define pinstTargetIndicator_x                                     0xF64D50
#define EQObject_Top_x                                             0xEB16F4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDFF830
#define pinstCAchievementsWnd_x                                    0xDFF82C
#define pinstCActionsWnd_x                                         0xDFF7F4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFF064
#define pinstCAdvancedLootWnd_x                                    0xDFF024
#define pinstCAdventureLeaderboardWnd_x                            0xF723E0
#define pinstCAdventureRequestWnd_x                                0xF72490
#define pinstCAdventureStatsWnd_x                                  0xF72540
#define pinstCAggroMeterWnd_x                                      0xDFF110
#define pinstCAlarmWnd_x                                           0xDFEFF0
#define pinstCAlertHistoryWnd_x                                    0xDFF084
#define pinstCAlertStackWnd_x                                      0xDFEFF8
#define pinstCAlertWnd_x                                           0xDFF004
#define pinstCAltStorageWnd_x                                      0xF728A0
#define pinstCAudioTriggersWindow_x                                0xCB3C28
#define pinstCAuraWnd_x                                            0xDFF0BC
#define pinstCAvaZoneWnd_x                                         0xDFF060
#define pinstCBandolierWnd_x                                       0xDFF108
#define pinstCBankWnd_x                                            0xDFF0B8
#define pinstCBarterMerchantWnd_x                                  0xF73AE0
#define pinstCBarterSearchWnd_x                                    0xF73B90
#define pinstCBarterWnd_x                                          0xF73C40
#define pinstCBazaarConfirmationWnd_x                              0xDFF858
#define pinstCBazaarSearchWnd_x                                    0xDFF5D8
#define pinstCBazaarWnd_x                                          0xDFF874
#define pinstCBlockedBuffWnd_x                                     0xDFF0C4
#define pinstCBlockedPetBuffWnd_x                                  0xDFF0E4
#define pinstCBodyTintWnd_x                                        0xDFF804
#define pinstCBookWnd_x                                            0xDFF13C
#define pinstCBreathWnd_x                                          0xDFF848
#define pinstCBuffWindowNORMAL_x                                   0xDFF088
#define pinstCBuffWindowSHORT_x                                    0xDFF08C
#define pinstCBugReportWnd_x                                       0xDFF0B0
#define pinstCButtonWnd_x                                          0x15F73B0
#define pinstCCastingWnd_x                                         0xDFF124
#define pinstCCastSpellWnd_x                                       0xDFF844
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDFF878
#define pinstCChatWindowManager_x                                  0xF74700
#define pinstCClaimWnd_x                                           0xF74858
#define pinstCColorPickerWnd_x                                     0xDFF7FC
#define pinstCCombatAbilityWnd_x                                   0xDFEFE8
#define pinstCCombatSkillsSelectWnd_x                              0xDFF00C
#define pinstCCompassWnd_x                                         0xDFF7F8
#define pinstCConfirmationDialog_x                                 0xF79758
#define pinstCContainerMgr_x                                       0xDFF86C
#define pinstCContextMenuManager_x                                 0x15F7100
#define pinstCCursorAttachment_x                                   0xDFF118
#define pinstCDynamicZoneWnd_x                                     0xF74E20
#define pinstCEditLabelWnd_x                                       0xDFF080
#define pinstCEQMainWnd_x                                          0xF75068
#define pinstCEventCalendarWnd_x                                   0xDFF11C
#define pinstCExtendedTargetWnd_x                                  0xDFF0D8
#define pinstCFacePick_x                                           0xDFF01C
#define pinstCFactionWnd_x                                         0xDFF868
#define pinstCFellowshipWnd_x                                      0xF75268
#define pinstCFileSelectionWnd_x                                   0xDFF120
#define pinstCFindItemWnd_x                                        0xDFF854
#define pinstCFindLocationWnd_x                                    0xF753C0
#define pinstCFriendsWnd_x                                         0xDFF020
#define pinstCGemsGameWnd_x                                        0xDFF864
#define pinstCGiveWnd_x                                            0xDFEFF4
#define pinstCGroupSearchFiltersWnd_x                              0xDFF128
#define pinstCGroupSearchWnd_x                                     0xF757B8
#define pinstCGroupWnd_x                                           0xF75868
#define pinstCGuildBankWnd_x                                       0xEC27A4
#define pinstCGuildCreationWnd_x                                   0xF759C8
#define pinstCGuildMgmtWnd_x                                       0xF75A78
#define pinstCharacterCreation_x                                   0xDFF014
#define pinstCHelpWnd_x                                            0xDFF058
#define pinstCHeritageSelectionWnd_x                               0xDFF028
#define pinstCHotButtonWnd_x                                       0xF77BD0
#define pinstCHotButtonWnd1_x                                      0xF77BD0
#define pinstCHotButtonWnd2_x                                      0xF77BD4
#define pinstCHotButtonWnd3_x                                      0xF77BD8
#define pinstCHotButtonWnd4_x                                      0xF77BDC
#define pinstCIconSelectionWnd_x                                   0xDFF114
#define pinstCInspectWnd_x                                         0xDFF054
#define pinstCInventoryWnd_x                                       0xDFF02C
#define pinstCInvSlotMgr_x                                         0xDFF828
#define pinstCItemDisplayManager_x                                 0xF78160
#define pinstCItemExpTransferWnd_x                                 0xF78294
#define pinstCItemOverflowWnd_x                                    0xDFF5DC
#define pinstCJournalCatWnd_x                                      0xDFF5B8
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDFF0DC
#define pinstCKeyRingWnd_x                                         0xDFF07C
#define pinstCLargeDialogWnd_x                                     0xF7A3D8
#define pinstCLayoutCopyWnd_x                                      0xF785E0
#define pinstCLFGuildWnd_x                                         0xF78690
#define pinstCLoadskinWnd_x                                        0xDFF870
#define pinstCLootFiltersCopyWnd_x                                 0xCD0220
#define pinstCLootFiltersWnd_x                                     0xDFEFFC
#define pinstCLootSettingsWnd_x                                    0xDFF018
#define pinstCLootWnd_x                                            0xDFF5BC
#define pinstCMailAddressBookWnd_x                                 0xDFF838
#define pinstCMailCompositionWnd_x                                 0xDFF814
#define pinstCMailIgnoreListWnd_x                                  0xDFF83C
#define pinstCMailWnd_x                                            0xDFF7F0
#define pinstCManageLootWnd_x                                      0xE006D8
#define pinstCMapToolbarWnd_x                                      0xDFF05C
#define pinstCMapViewWnd_x                                         0xDFF038
#define pinstCMarketplaceWnd_x                                     0xDFF000
#define pinstCMerchantWnd_x                                        0xDFF5C0
#define pinstCMIZoneSelectWnd_x                                    0xF78EC8
#define pinstCMusicPlayerWnd_x                                     0xDFF5CC
#define pinstCNameChangeMercWnd_x                                  0xDFF850
#define pinstCNameChangePetWnd_x                                   0xDFF834
#define pinstCNameChangeWnd_x                                      0xDFF860
#define pinstCNoteWnd_x                                            0xDFF03C
#define pinstCObjectPreviewWnd_x                                   0xDFF010
#define pinstCOptionsWnd_x                                         0xDFF044
#define pinstCPetInfoWnd_x                                         0xDFF7E0
#define pinstCPetitionQWnd_x                                       0xDFF820
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDFF808
#define pinstCPlayerWnd_x                                          0xDFF7E4
#define pinstCPopupWndManager_x                                    0xF79758
#define pinstCProgressionSelectionWnd_x                            0xF79808
#define pinstCPurchaseGroupWnd_x                                   0xDFF048
#define pinstCPurchaseWnd_x                                        0xDFF030
#define pinstCPvPLeaderboardWnd_x                                  0xF798B8
#define pinstCPvPStatsWnd_x                                        0xF79968
#define pinstCQuantityWnd_x                                        0xDFF0E0
#define pinstCRaceChangeWnd_x                                      0xDFEFEC
#define pinstCRaidOptionsWnd_x                                     0xDFF130
#define pinstCRaidWnd_x                                            0xDFF81C
#define pinstCRealEstateItemsWnd_x                                 0xDFF824
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDFF5C4
#define pinstCRealEstateManageWnd_x                                0xDFF050
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFF078
#define pinstCRealEstatePlotSearchWnd_x                            0xDFF0B4
#define pinstCRealEstatePurchaseWnd_x                              0xDFF0F4
#define pinstCRespawnWnd_x                                         0xDFF0CC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDFF840
#define pinstCSendMoneyWnd_x                                       0xDFF008
#define pinstCServerListWnd_x                                      0xDFF10C
#define pinstCSkillsSelectWnd_x                                    0xDFEFE0
#define pinstCSkillsWnd_x                                          0xDFF85C
#define pinstCSocialEditWnd_x                                      0xDFF074
#define pinstCSocialWnd_x                                          0xDFF84C
#define pinstCSpellBookWnd_x                                       0xDFEFE4
#define pinstCStoryWnd_x                                           0xDFF7E8
#define pinstCTargetOfTargetWnd_x                                  0xF7B790
#define pinstCTargetWnd_x                                          0xDFF0C8
#define pinstCTaskOverlayWnd_x                                     0xDFF040
#define pinstCTaskSelectWnd_x                                      0xF7B8E8
#define pinstCTaskManager_x                                        0xCD0B60
#define pinstCTaskTemplateSelectWnd_x                              0xF7B998
#define pinstCTaskWnd_x                                            0xF7BA48
#define pinstCTextEntryWnd_x                                       0xDFF090
#define pinstCTimeLeftWnd_x                                        0xDFF7EC
#define pinstCTipWndCONTEXT_x                                      0xF7BC4C
#define pinstCTipWndOFDAY_x                                        0xF7BC48
#define pinstCTitleWnd_x                                           0xF7BCF8
#define pinstCTrackingWnd_x                                        0xDFF034
#define pinstCTradeskillWnd_x                                      0xF7BE60
#define pinstCTradeWnd_x                                           0xDFF810
#define pinstCTrainWnd_x                                           0xDFF80C
#define pinstCTributeBenefitWnd_x                                  0xF7C060
#define pinstCTributeMasterWnd_x                                   0xF7C110
#define pinstCTributeTrophyWnd_x                                   0xF7C1C0
#define pinstCVideoModesWnd_x                                      0xDFF5D0
#define pinstCVoiceMacroWnd_x                                      0xF654B8
#define pinstCVoteResultsWnd_x                                     0xDFF818
#define pinstCVoteWnd_x                                            0xDFF800
#define pinstCWebManager_x                                         0xF65B34
#define pinstCZoneGuideWnd_x                                       0xDFF04C
#define pinstCZonePathWnd_x                                        0xDFF06C

#define pinstEQSuiteTextureLoader_x                                0xC9E080
#define pinstItemIconCache_x                                       0xF75020
#define pinstLootFiltersManager_x                                  0xCD02D0
#define pinstRewardSelectionWnd_x                                  0xF7A0B0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AEBA0
#define __CastRay2_x                                               0x5AEBF0
#define __ConvertItemTags_x                                        0x5CA750
#define __CleanItemTags_x                                          0x47D180
#define __DoesFileExist_x                                          0x903F80
#define __EQGetTime_x                                              0x900970
#define __ExecuteCmd_x                                             0x5A7440
#define __FixHeading_x                                             0x99AFF0
#define __GameLoop_x                                               0x6BB130
#define __get_bearing_x                                            0x5AE710
#define __get_melee_range_x                                        0x5AEDE0
#define __GetAnimationCache_x                                      0x7203E0
#define __GetGaugeValueFromEQ_x                                    0x813020
#define __GetLabelFromEQ_x                                         0x814B00
#define __GetXTargetType_x                                         0x99CA20
#define __HandleMouseWheel_x                                       0x6BBFF0
#define __HeadingDiff_x                                            0x99B060
#define __HelpPath_x                                               0xF6085C
#define __LoadFrontEnd_x                                           0x6B8450
#define __NewUIINI_x                                               0x812CF0
#define __ProcessGameEvents_x                                      0x60ECB0
#define __ProcessMouseEvent_x                                      0x60E470
#define __SaveColors_x                                             0x551680
#define __STMLToText_x                                             0x93E470
#define __ToggleKeyRingItem_x                                      0x514DF0
#define CMemoryMappedFile__SetFile_x                               0xA8A2D0
#define CrashDetected_x                                            0x6B9EF0
#define DrawNetStatus_x                                            0x63A830
#define Expansion_HoT_x                                            0xEC27AC
#define Teleport_Table_Size_x                                      0xEB17E0
#define Teleport_Table_x                                           0xEB1C48
#define Util__FastTime_x                                           0x900540

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490440
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499360
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499130
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4939E0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E30

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559230
#define AltAdvManager__IsAbilityReady_x                            0x558160
#define AltAdvManager__GetAAById_x                                 0x558360
#define AltAdvManager__CanTrainAbility_x                           0x5583D0
#define AltAdvManager__CanSeeAbility_x                             0x558730

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA210
#define CharacterZoneClient__HasSkill_x                            0x4D5100
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6820
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE4C0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAAC0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D91C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D92A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9380
#define CharacterZoneClient__FindAffectSlot_x                      0x4C32B0
#define CharacterZoneClient__BardCastBard_x                        0x4C5E10
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB90
#define CharacterZoneClient__GetEffect_x                           0x4BAA00
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4300
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C43D0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4420
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4570
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4740
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2970
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7780
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7200

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E1B50
#define CBankWnd__WndNotification_x                                0x6E1930

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EF5E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61D3B0
#define CButtonWnd__CButtonWnd_x                                   0x93A860

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70F550
#define CChatManager__InitContextMenu_x                            0x7086A0
#define CChatManager__FreeChatWindow_x                             0x70E090
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E87C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70F1D0
#define CChatManager__CreateChatWindow_x                           0x70E6D0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E88D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94EFC0
#define CContextMenu__dCContextMenu_x                              0x94F200
#define CContextMenu__AddMenuItem_x                                0x94F210
#define CContextMenu__RemoveMenuItem_x                             0x94F520
#define CContextMenu__RemoveAllMenuItems_x                         0x94F540
#define CContextMenu__CheckMenuItem_x                              0x94F5C0
#define CContextMenu__SetMenuItem_x                                0x94F440
#define CContextMenu__AddSeparator_x                               0x94F3A0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94FB50
#define CContextMenuManager__RemoveMenu_x                          0x94FBC0
#define CContextMenuManager__PopupMenu_x                           0x94FC80
#define CContextMenuManager__Flush_x                               0x94FAF0
#define CContextMenuManager__GetMenu_x                             0x49B500
#define CContextMenuManager__CreateDefaultMenu_x                   0x71ABF0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DC650
#define CChatService__GetFriendName_x                              0x8DC660

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70FDC0
#define CChatWindow__Clear_x                                       0x711090
#define CChatWindow__WndNotification_x                             0x711820
#define CChatWindow__AddHistory_x                                  0x710950

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94C420
#define CComboWnd__Draw_x                                          0x94B910
#define CComboWnd__GetCurChoice_x                                  0x94C260
#define CComboWnd__GetListRect_x                                   0x94BDC0
#define CComboWnd__GetTextRect_x                                   0x94C490
#define CComboWnd__InsertChoice_x                                  0x94BF50
#define CComboWnd__SetColors_x                                     0x94BF20
#define CComboWnd__SetChoice_x                                     0x94C230
#define CComboWnd__GetItemCount_x                                  0x94C270
#define CComboWnd__GetCurChoiceText_x                              0x94C2B0
#define CComboWnd__GetChoiceText_x                                 0x94C280
#define CComboWnd__InsertChoiceAtIndex_x                           0x94BFF0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7185C0
#define CContainerWnd__vftable_x                                   0xB1148C
#define CContainerWnd__SetContainer_x                              0x719B30

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54C0C0
#define CDisplay__PreZoneMainUI_x                                  0x54C0D0
#define CDisplay__CleanGameUI_x                                    0x551440
#define CDisplay__GetClickedActor_x                                0x5443E0
#define CDisplay__GetUserDefinedColor_x                            0x53CAA0
#define CDisplay__GetWorldFilePath_x                               0x545E50
#define CDisplay__is3dON_x                                         0x541040
#define CDisplay__ReloadUI_x                                       0x54B550
#define CDisplay__WriteTextHD2_x                                   0x540E30
#define CDisplay__TrueDistance_x                                   0x547B10
#define CDisplay__SetViewActor_x                                   0x543D00
#define CDisplay__GetFloorHeight_x                                 0x541100
#define CDisplay__SetRenderWindow_x                                0x53FA60
#define CDisplay__ToggleScreenshotMode_x                           0x5437D0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96EC10

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x952520
#define CEditWnd__GetCharIndexPt_x                                 0x953440
#define CEditWnd__GetDisplayString_x                               0x9532F0
#define CEditWnd__GetHorzOffset_x                                  0x951B60
#define CEditWnd__GetLineForPrintableChar_x                        0x9545B0
#define CEditWnd__GetSelStartPt_x                                  0x9536F0
#define CEditWnd__GetSTMLSafeText_x                                0x953110
#define CEditWnd__PointFromPrintableChar_x                         0x9541F0
#define CEditWnd__SelectableCharFromPoint_x                        0x954360
#define CEditWnd__SetEditable_x                                    0x9537B0
#define CEditWnd__SetWindowTextA_x                                 0x952E90

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FC920
#define CEverQuest__ClickedPlayer_x                                0x5EE930
#define CEverQuest__CreateTargetIndicator_x                        0x60BF40
#define CEverQuest__DeleteTargetIndicator_x                        0x60BFD0
#define CEverQuest__DoTellWindow_x                                 0x4E89B0
#define CEverQuest__OutputTextToLog_x                              0x4E8C30
#define CEverQuest__DropHeldItemOnGround_x                         0x5E3970
#define CEverQuest__dsp_chat_x                                     0x4E8FC0
#define CEverQuest__trimName_x                                     0x608230
#define CEverQuest__Emote_x                                        0x5FD180
#define CEverQuest__EnterZone_x                                    0x5F7100
#define CEverQuest__GetBodyTypeDesc_x                              0x601AF0
#define CEverQuest__GetClassDesc_x                                 0x602130
#define CEverQuest__GetClassThreeLetterCode_x                      0x602730
#define CEverQuest__GetDeityDesc_x                                 0x60A880
#define CEverQuest__GetLangDesc_x                                  0x6028F0
#define CEverQuest__GetRaceDesc_x                                  0x602110
#define CEverQuest__InterpretCmd_x                                 0x60AE50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E7B70
#define CEverQuest__LMouseUp_x                                     0x5E5F00
#define CEverQuest__RightClickedOnPlayer_x                         0x5E8450
#define CEverQuest__RMouseUp_x                                     0x5E6E80
#define CEverQuest__SetGameState_x                                 0x5E3700
#define CEverQuest__UPCNotificationFlush_x                         0x608130
#define CEverQuest__IssuePetCommand_x                              0x603CF0
#define CEverQuest__ReportSuccessfulHit_x                          0x5FE570

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72A610
#define CGaugeWnd__CalcLinesFillRect_x                             0x72A670
#define CGaugeWnd__Draw_x                                          0x729C90

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF490
#define CGuild__GetGuildName_x                                     0x4AE570
#define CGuild__GetGuildIndex_x                                    0x4AE900

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x745A60

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61D770

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x752AB0
#define CInvSlotMgr__MoveItem_x                                    0x7517C0
#define CInvSlotMgr__SelectSlot_x                                  0x752B80

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x750040
#define CInvSlot__SliderComplete_x                                 0x74DD90
#define CInvSlot__GetItemBase_x                                    0x74D700
#define CInvSlot__UpdateItem_x                                     0x74D870

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x754600
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7537A0
#define CInvSlotWnd__HandleLButtonUp_x                             0x754180

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80E2F0
#define CItemDisplayWnd__UpdateStrings_x                           0x762D50
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75CAA0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75CFB0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x763360
#define CItemDisplayWnd__AboutToShow_x                             0x7629A0
#define CItemDisplayWnd__WndNotification_x                         0x764450
#define CItemDisplayWnd__RequestConvertItem_x                      0x763F10
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x761A00
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7627C0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x846DB0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x768990

// CLabel 
#define CLabel__Draw_x                                             0x76E360

// CListWnd
#define CListWnd__CListWnd_x                                       0x924BB0
#define CListWnd__dCListWnd_x                                      0x924ED0
#define CListWnd__AddColumn_x                                      0x929360
#define CListWnd__AddColumn1_x                                     0x9293B0
#define CListWnd__AddLine_x                                        0x929740
#define CListWnd__AddString_x                                      0x929540
#define CListWnd__CalculateFirstVisibleLine_x                      0x929120
#define CListWnd__CalculateVSBRange_x                              0x928F00
#define CListWnd__ClearSel_x                                       0x929F20
#define CListWnd__ClearAllSel_x                                    0x929F80
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92A9A0
#define CListWnd__Compare_x                                        0x928830
#define CListWnd__Draw_x                                           0x925000
#define CListWnd__DrawColumnSeparators_x                           0x927800
#define CListWnd__DrawHeader_x                                     0x927C70
#define CListWnd__DrawItem_x                                       0x928170
#define CListWnd__DrawLine_x                                       0x927970
#define CListWnd__DrawSeparator_x                                  0x9278A0
#define CListWnd__EnableLine_x                                     0x9270D0
#define CListWnd__EnsureVisible_x                                  0x92A8C0
#define CListWnd__ExtendSel_x                                      0x929E50
#define CListWnd__GetColumnTooltip_x                               0x926C10
#define CListWnd__GetColumnMinWidth_x                              0x926C80
#define CListWnd__GetColumnWidth_x                                 0x926B80
#define CListWnd__GetCurSel_x                                      0x926510
#define CListWnd__GetItemAtPoint_x                                 0x927350
#define CListWnd__GetItemAtPoint1_x                                0x9273C0
#define CListWnd__GetItemData_x                                    0x926590
#define CListWnd__GetItemHeight_x                                  0x926950
#define CListWnd__GetItemIcon_x                                    0x926720
#define CListWnd__GetItemRect_x                                    0x9271C0
#define CListWnd__GetItemText_x                                    0x9265D0
#define CListWnd__GetSelList_x                                     0x929FD0
#define CListWnd__GetSeparatorRect_x                               0x927600
#define CListWnd__InsertLine_x                                     0x929B30
#define CListWnd__RemoveLine_x                                     0x929C80
#define CListWnd__SetColors_x                                      0x928ED0
#define CListWnd__SetColumnJustification_x                         0x928C00
#define CListWnd__SetColumnWidth_x                                 0x928B20
#define CListWnd__SetCurSel_x                                      0x929D90
#define CListWnd__SetItemColor_x                                   0x92A570
#define CListWnd__SetItemData_x                                    0x92A530
#define CListWnd__SetItemText_x                                    0x92A140
#define CListWnd__ShiftColumnSeparator_x                           0x928CC0
#define CListWnd__Sort_x                                           0x9289B0
#define CListWnd__ToggleSel_x                                      0x929DC0
#define CListWnd__SetColumnsSizable_x                              0x928D70
#define CListWnd__SetItemWnd_x                                     0x92A3F0
#define CListWnd__GetItemWnd_x                                     0x926770
#define CListWnd__SetItemIcon_x                                    0x92A1C0
#define CListWnd__CalculateCustomWindowPositions_x                 0x929220
#define CListWnd__SetVScrollPos_x                                  0x928B00

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x783BE0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7822F0
#define CMapViewWnd__HandleLButtonDown_x                           0x77F330

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A3C60
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A4540
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A4A70
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A7A00
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A27C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AD5A0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A3870

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A9F90
#define CPacketScrambler__hton_x                                   0x8A9F80

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x943AE0
#define CSidlManager__FindScreenPieceTemplate_x                    0x943EF0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x943CE0
#define CSidlManager__CreateLabel_x                                0x805710
#define CSidlManager__CreateXWndFromTemplate_x                     0x946E50
#define CSidlManager__CreateXWndFromTemplate1_x                    0x947030
#define CSidlManager__CreateXWnd_x                                 0x805640
#define CSidlManager__CreateHotButtonWnd_x                         0x805C10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9405A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9404A0
#define CSidlScreenWnd__ConvertToRes_x                             0x965BC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93FF30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93FC20
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93FCF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93FDC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x940A40
#define CSidlScreenWnd__EnableIniStorage_x                         0x940F10
#define CSidlScreenWnd__GetSidlPiece_x                             0x940C30
#define CSidlScreenWnd__Init1_x                                    0x93F820
#define CSidlScreenWnd__LoadIniInfo_x                              0x940F60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x941AC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93EC20
#define CSidlScreenWnd__StoreIniInfo_x                             0x941630
#define CSidlScreenWnd__StoreIniVis_x                              0x9419A0
#define CSidlScreenWnd__WndNotification_x                          0x940950
#define CSidlScreenWnd__GetChildItem_x                             0x940E90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x930750
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F6FD0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x681F00
#define CSkillMgr__GetSkillCap_x                                   0x6820E0
#define CSkillMgr__GetNameToken_x                                  0x681680
#define CSkillMgr__IsActivatedSkill_x                              0x6817C0
#define CSkillMgr__IsCombatSkill_x                                 0x681700

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x950930
#define CSliderWnd__SetValue_x                                     0x9507A0
#define CSliderWnd__SetNumTicks_x                                  0x950800

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80B780

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x959100
#define CStmlWnd__CalculateHSBRange_x                              0x95A1E0
#define CStmlWnd__CalculateVSBRange_x                              0x95A150
#define CStmlWnd__CanBreakAtCharacter_x                            0x95E520
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95F1B0
#define CStmlWnd__ForceParseNow_x                                  0x9596A0
#define CStmlWnd__GetNextTagPiece_x                                0x95E480
#define CStmlWnd__GetSTMLText_x                                    0x5045B0
#define CStmlWnd__GetVisibleText_x                                 0x9596C0
#define CStmlWnd__InitializeWindowVariables_x                      0x95F000
#define CStmlWnd__MakeStmlColorTag_x                               0x958770
#define CStmlWnd__MakeWndNotificationTag_x                         0x9587E0
#define CStmlWnd__SetSTMLText_x                                    0x957820
#define CStmlWnd__StripFirstSTMLLines_x                            0x9602B0
#define CStmlWnd__UpdateHistoryString_x                            0x95F3C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x956970
#define CTabWnd__DrawCurrentPage_x                                 0x9570A0
#define CTabWnd__DrawTab_x                                         0x956DC0
#define CTabWnd__GetCurrentPage_x                                  0x956170
#define CTabWnd__GetPageInnerRect_x                                0x9563B0
#define CTabWnd__GetTabInnerRect_x                                 0x9562F0
#define CTabWnd__GetTabRect_x                                      0x9561A0
#define CTabWnd__InsertPage_x                                      0x9565C0
#define CTabWnd__SetPage_x                                         0x956430
#define CTabWnd__SetPageRect_x                                     0x9568B0
#define CTabWnd__UpdatePage_x                                      0x956C80
#define CTabWnd__GetPageFromTabIndex_x                             0x956D00
#define CTabWnd__GetCurrentTabIndex_x                              0x956160

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x768D60
#define CPageWnd__SetTabText_x                                     0x955CC0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9100

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92D5F0
#define CTextureFont__GetTextExtent_x                              0x92D7B0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B52D0
#define CHtmlComponentWnd__ValidateUri_x                           0x747460
#define CHtmlWnd__SetClientCallbacks_x                             0x622810
#define CHtmlWnd__AddObserver_x                                    0x622830
#define CHtmlWnd__RemoveObserver_x                                 0x622890
#define Window__getProgress_x                                      0x85F670
#define Window__getStatus_x                                        0x85F690
#define Window__getURI_x                                           0x85F6A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96B660

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91A800

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E85D0
#define CXStr__CXStr1_x                                            0x4B63D0
#define CXStr__CXStr3_x                                            0x8FCAB0
#define CXStr__dCXStr_x                                            0x478740
#define CXStr__operator_equal_x                                    0x8FCCE0
#define CXStr__operator_equal1_x                                   0x8FCD20
#define CXStr__operator_plus_equal1_x                              0x8FD7B0
#define CXStr__SetString_x                                         0x8FF6A0
#define CXStr__operator_char_p_x                                   0x8FD220
#define CXStr__GetChar_x                                           0x8FEFD0
#define CXStr__Delete_x                                            0x8FE8A0
#define CXStr__GetUnicode_x                                        0x8FF040
#define CXStr__GetLength_x                                         0x47D530
#define CXStr__Mid_x                                               0x47D540
#define CXStr__Insert_x                                            0x8FF0A0
#define CXStr__FindNext_x                                          0x8FED10

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94EBE0
#define CXWnd__BringToTop_x                                        0x933E40
#define CXWnd__Center_x                                            0x9339C0
#define CXWnd__ClrFocus_x                                          0x9337D0
#define CXWnd__Destroy_x                                           0x933880
#define CXWnd__DoAllDrawing_x                                      0x92FF00
#define CXWnd__DrawChildren_x                                      0x92FED0
#define CXWnd__DrawColoredRect_x                                   0x930360
#define CXWnd__DrawTooltip_x                                       0x92EA30
#define CXWnd__DrawTooltipAtPoint_x                                0x92EAF0
#define CXWnd__GetBorderFrame_x                                    0x9301C0
#define CXWnd__GetChildWndAt_x                                     0x933EE0
#define CXWnd__GetClientClipRect_x                                 0x932130
#define CXWnd__GetScreenClipRect_x                                 0x932200
#define CXWnd__GetScreenRect_x                                     0x9323C0
#define CXWnd__GetTooltipRect_x                                    0x9303B0
#define CXWnd__GetWindowTextA_x                                    0x49CC10
#define CXWnd__IsActive_x                                          0x930AD0
#define CXWnd__IsDescendantOf_x                                    0x932D60
#define CXWnd__IsReallyVisible_x                                   0x932D90
#define CXWnd__IsType_x                                            0x934560
#define CXWnd__Move_x                                              0x932DF0
#define CXWnd__Move1_x                                             0x932EA0
#define CXWnd__ProcessTransition_x                                 0x933970
#define CXWnd__Refade_x                                            0x933170
#define CXWnd__Resize_x                                            0x9333F0
#define CXWnd__Right_x                                             0x933C00
#define CXWnd__SetFocus_x                                          0x933790
#define CXWnd__SetFont_x                                           0x933800
#define CXWnd__SetKeyTooltip_x                                     0x934370
#define CXWnd__SetMouseOver_x                                      0x9312F0
#define CXWnd__StartFade_x                                         0x932C50
#define CXWnd__GetChildItem_x                                      0x934050
#define CXWnd__SetParent_x                                         0x932B60
#define CXWnd__Minimize_x                                          0x933460

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x966C40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x936DB0
#define CXWndManager__DrawWindows_x                                0x936DD0
#define CXWndManager__GetKeyboardFlags_x                           0x9394F0
#define CXWndManager__HandleKeyboardMsg_x                          0x9390A0
#define CXWndManager__RemoveWnd_x                                  0x939740
#define CXWndManager__RemovePendingDeletionWnd_x                   0x939CA0

// CDBStr
#define CDBStr__GetString_x                                        0x53BA70

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBAA0
#define EQ_Character__Cur_HP_x                                     0x4D2140
#define EQ_Character__Cur_Mana_x                                   0x4D9880
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEB10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B25B0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2700
#define EQ_Character__GetHPRegen_x                                 0x4DF650
#define EQ_Character__GetEnduranceRegen_x                          0x4DFC50
#define EQ_Character__GetManaRegen_x                               0x4E0090
#define EQ_Character__Max_Endurance_x                              0x6483F0
#define EQ_Character__Max_HP_x                                     0x4D1F70
#define EQ_Character__Max_Mana_x                                   0x6481F0
#define EQ_Character__doCombatAbility_x                            0x64A850
#define EQ_Character__UseSkill_x                                   0x4E1E70
#define EQ_Character__GetConLevel_x                                0x6417B0
#define EQ_Character__IsExpansionFlag_x                            0x5A5C00
#define EQ_Character__TotalEffect_x                                0x4C5550
#define EQ_Character__GetPCSpellAffect_x                           0x4BF860
#define EQ_Character__SpellDuration_x                              0x4BF390
#define EQ_Character__GetAdjustedSkill_x                           0x4D4EC0
#define EQ_Character__GetBaseSkill_x                               0x4D5E60
#define EQ_Character__CanUseItem_x                                 0x4D9B90

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C9530

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65ED90

//PcClient
#define PcClient__PcClient_x                                       0x63EEF0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9710
#define CCharacterListWnd__EnterWorld_x                            0x4B9150
#define CCharacterListWnd__Quit_x                                  0x4B8EA0
#define CCharacterListWnd__UpdateList_x                            0x4B92E0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x623A50
#define EQ_Item__CreateItemTagString_x                             0x8A37F0
#define EQ_Item__IsStackable_x                                     0x8A8370
#define EQ_Item__GetImageNum_x                                     0x8A5270
#define EQ_Item__CreateItemClient_x                                0x622C30
#define EQ_Item__GetItemValue_x                                    0x8A6560
#define EQ_Item__ValueSellMerchant_x                               0x8A9B70
#define EQ_Item__IsKeyRingItem_x                                   0x8A7C70
#define EQ_Item__CanGoInBag_x                                      0x623B70
#define EQ_Item__IsEmpty_x                                         0x8A77C0
#define EQ_Item__GetMaxItemCount_x                                 0x8A6980
#define EQ_Item__GetHeldItem_x                                     0x8A5140
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A3140

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x559F00
#define EQ_LoadingS__Array_x                                       0xC25B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x648D50
#define EQ_PC__GetAlternateAbilityId_x                             0x8B2DB0
#define EQ_PC__GetCombatAbility_x                                  0x8B3420
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B3490
#define EQ_PC__GetItemRecastTimer_x                                0x64ADD0
#define EQ_PC__HasLoreItem_x                                       0x641F70
#define EQ_PC__AlertInventoryChanged_x                             0x6410F0
#define EQ_PC__GetPcZoneClient_x                                   0x66D800
#define EQ_PC__RemoveMyAffect_x                                    0x64E000
#define EQ_PC__GetKeyRingItems_x                                   0x8B3D20
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B3AB0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B4020

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AC170
#define EQItemList__add_object_x                                   0x5D9130
#define EQItemList__add_item_x                                     0x5AC6D0
#define EQItemList__delete_item_x                                  0x5AC720
#define EQItemList__FreeItemList_x                                 0x5AC620

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538590

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x660610
#define EQPlayer__dEQPlayer_x                                      0x653520
#define EQPlayer__DoAttack_x                                       0x6684B0
#define EQPlayer__EQPlayer_x                                       0x653BE0
#define EQPlayer__SetNameSpriteState_x                             0x6582F0
#define EQPlayer__SetNameSpriteTint_x                              0x6591C0
#define PlayerBase__HasProperty_j_x                                0x9993E0
#define EQPlayer__IsTargetable_x                                   0x999880
#define EQPlayer__CanSee_x                                         0x9996E0
#define EQPlayer__CanSee1_x                                        0x9997B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9994A0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66B290
#define PlayerZoneClient__GetLevel_x                               0x66D840
#define PlayerZoneClient__IsValidTeleport_x                        0x5DA2A0
#define PlayerZoneClient__LegalPlayerRace_x                        0x5532A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6633C0
#define EQPlayerManager__GetSpawnByName_x                          0x663470
#define EQPlayerManager__GetPlayerFromPartialName_x                0x663500

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x627070
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6270F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x627130
#define KeypressHandler__ClearCommandStateArray_x                  0x628540
#define KeypressHandler__HandleKeyDown_x                           0x628560
#define KeypressHandler__HandleKeyUp_x                             0x628600
#define KeypressHandler__SaveKeymapping_x                          0x628A50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77FA50
#define MapViewMap__SaveEx_x                                       0x782E10
#define MapViewMap__SetZoom_x                                      0x7874D0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C7450

// StringTable 
#define StringTable__getString_x                                   0x8C21C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64DC70
#define PcZoneClient__RemovePetEffect_x                            0x64E2A0
#define PcZoneClient__HasAlternateAbility_x                        0x648020
#define PcZoneClient__GetCurrentMod_x                              0x4E4F30
#define PcZoneClient__GetModCap_x                                  0x4E4E30
#define PcZoneClient__CanEquipItem_x                               0x6486F0
#define PcZoneClient__GetItemByID_x                                0x64B240
#define PcZoneClient__GetItemByItemClass_x                         0x64B390
#define PcZoneClient__RemoveBuffEffect_x                           0x64E2C0
#define PcZoneClient__BandolierSwap_x                              0x649310
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64AD70

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DEE80

//IconCache
#define IconCache__GetIcon_x                                       0x71FC80

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x717760
#define CContainerMgr__CloseContainer_x                            0x717A30
#define CContainerMgr__OpenExperimentContainer_x                   0x7184B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D7B50

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61BB50

//CLootWnd
#define CLootWnd__LootAll_x                                        0x775E40
#define CLootWnd__RequestLootSlot_x                                0x775070

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x579B10
#define EQ_Spell__SpellAffects_x                                   0x579F80
#define EQ_Spell__SpellAffectBase_x                                0x579D40
#define EQ_Spell__IsStackable_x                                    0x4C9B70
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C99F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6A90
#define EQ_Spell__IsSPAStacking_x                                  0x57ADD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A2E0
#define EQ_Spell__IsNoRemove_x                                     0x4C9B50
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57ADE0
#define __IsResEffectSpell_x                                       0x4C8F90

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD1C0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D1AC0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81EAC0
#define CTargetWnd__WndNotification_x                              0x81E350
#define CTargetWnd__RefreshTargetBuffs_x                           0x81E620
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81D4B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8230C0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536000
#define CTaskManager__HandleMessage_x                              0x534470
#define CTaskManager__GetTaskStatus_x                              0x5360B0
#define CTaskManager__GetElementDescription_x                      0x536130

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575060
#define EqSoundManager__PlayScriptMp3_x                            0x5751C0
#define EqSoundManager__SoundAssistPlay_x                          0x685E90
#define EqSoundManager__WaveInstancePlay_x                         0x685400

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x529D10

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9551D0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x561980
#define CAltAbilityData__GetMercMaxRank_x                          0x561910
#define CAltAbilityData__GetMaxRank_x                              0x556FE0

//CTargetRing
#define CTargetRing__Cast_x                                        0x619C80

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C99D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x511300
#define CharacterBase__CreateItemIndex_x                           0x621DC0
#define CharacterBase__GetItemPossession_x                         0x4FCFF0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DA0D0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DA130
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FE8D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FF100
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FF1B0

//messages
#define msg_spell_worn_off_x                                       0x59DEA0
#define msg_new_text_x                                             0x592C40
#define __msgTokenTextParam_x                                      0x5A03C0
#define msgTokenText_x                                             0x5A0610

//SpellManager
#define SpellManager__vftable_x                                    0xAEB488
#define SpellManager__SpellManager_x                               0x6891C0
#define Spellmanager__LoadTextSpells_x                             0x689AB0
#define SpellManager__GetSpellByGroupAndRank_x                     0x689390

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99D310

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x511980
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A4190
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63A690
#define ItemGlobalIndex__IsValidIndex_x                            0x5119E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D2460
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D26E0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76E6A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71BE90
#define CCursorAttachment__AttachToCursor1_x                       0x71BED0
#define CCursorAttachment__Deactivate_x                            0x71CEB0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x947E90
#define CSidlManagerBase__CreatePageWnd_x                          0x947680
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x943900
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x943890

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x964E30
#define CEQSuiteTextureLoader__GetTexture_x                        0x964AF0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50E870
#define CFindItemWnd__WndNotification_x                            0x50F350
#define CFindItemWnd__Update_x                                     0x50FEC0
#define CFindItemWnd__PickupSelectedItem_x                         0x50E0C0

//IString
#define IString__Append_x                                          0x4FE890

//Camera
#define CDisplay__cameraType_x                                     0xDFF5D4
#define EverQuest__Cameras_x                                       0xEC2AFC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517190
#define LootFiltersManager__GetItemFilterData_x                    0x516A90
#define LootFiltersManager__RemoveItemLootFilter_x                 0x516AC0
#define LootFiltersManager__SetItemLootFilter_x                    0x516CE0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C5B10

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A2F40
#define CResolutionHandler__GetWindowedStyle_x                     0x680AC0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x714530

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E6F20
#define CDistillerInfo__Instance_x                                 0x8E6EC0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x734840
#define CGroupWnd__UpdateDisplay_x                                 0x733B90

//ItemBase
#define ItemBase__IsLore_x                                         0x8A7D20
#define ItemBase__IsLoreEquipped_x                                 0x8A7DA0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D9090
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D91D0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D9230

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x675F10
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6798A0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x504BB0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2000
#define FactionManagerClient__HandleFactionMessage_x               0x4F2670
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2C70
#define FactionManagerClient__GetMaxFaction_x                      0x4F2C8F
#define FactionManagerClient__GetMinFaction_x                      0x4F2C40

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FCFC0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92C610

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BEF0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD2A0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x560E20

//CTargetManager
#define CTargetManager__Get_x                                      0x68C9E0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x675F10

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8EC0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AC5C0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF60190

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
