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
#define __ExpectedVersionDate                                     "Nov 10 2019"
#define __ExpectedVersionTime                                     "04:43:48"
#define __ActualVersionDate_x                                      0xB08234
#define __ActualVersionTime_x                                      0xB08228
#define __ActualVersionBuild_x                                     0xAF3F24

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62D810
#define __MemChecker1_x                                            0x900880
#define __MemChecker2_x                                            0x6BBC70
#define __MemChecker3_x                                            0x6BBBC0
#define __MemChecker4_x                                            0x857B60
#define __EncryptPad0_x                                            0xC3E3E8
#define __EncryptPad1_x                                            0xC9C5A8
#define __EncryptPad2_x                                            0xC4EC80
#define __EncryptPad3_x                                            0xC4E880
#define __EncryptPad4_x                                            0xC8CC00
#define __EncryptPad5_x                                            0xF68240
#define __AC1_x                                                    0x814836
#define __AC2_x                                                    0x5E777F
#define __AC3_x                                                    0x5EEE7F
#define __AC4_x                                                    0x5F2E50
#define __AC5_x                                                    0x5F915F
#define __AC6_x                                                    0x5FD776
#define __AC7_x                                                    0x5E71F0
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
#define __do_loot_x                                                0x5B3B40
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
#define __gfMaxZoomCameraDistance_x                                0xAFDB98
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
#define __CastRay_x                                                0x5AEFB0
#define __CastRay2_x                                               0x5AF000
#define __ConvertItemTags_x                                        0x5CAB50
#define __CleanItemTags_x                                          0x47D120
#define __DoesFileExist_x                                          0x9039C0
#define __EQGetTime_x                                              0x900350
#define __ExecuteCmd_x                                             0x5A7890
#define __FixHeading_x                                             0x99AEC0
#define __GameLoop_x                                               0x6BAE60
#define __get_bearing_x                                            0x5AEB20
#define __get_melee_range_x                                        0x5AF1F0
#define __GetAnimationCache_x                                      0x7203D0
#define __GetGaugeValueFromEQ_x                                    0x812CE0
#define __GetLabelFromEQ_x                                         0x8147C0
#define __GetXTargetType_x                                         0x99C8A0
#define __HandleMouseWheel_x                                       0x6BBD20
#define __HeadingDiff_x                                            0x99AF30
#define __HelpPath_x                                               0xF6085C
#define __LoadFrontEnd_x                                           0x6B8180
#define __NewUIINI_x                                               0x8129B0
#define __ProcessGameEvents_x                                      0x60EFF0
#define __ProcessMouseEvent_x                                      0x60E7B0
#define __SaveColors_x                                             0x551A50
#define __STMLToText_x                                             0x93E430
#define __ToggleKeyRingItem_x                                      0x514D00
#define CMemoryMappedFile__SetFile_x                               0xA8A300
#define CrashDetected_x                                            0x6B9C20
#define DrawNetStatus_x                                            0x63ABC0
#define Expansion_HoT_x                                            0xEC27AC
#define Teleport_Table_Size_x                                      0xEB17E0
#define Teleport_Table_x                                           0xEB1C48
#define Util__FastTime_x                                           0x8FFF10

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
#define AltAdvManager__GetCalculatedTimer_x                        0x559650
#define AltAdvManager__IsAbilityReady_x                            0x558580
#define AltAdvManager__GetAAById_x                                 0x558780
#define AltAdvManager__CanTrainAbility_x                           0x5587F0
#define AltAdvManager__CanSeeAbility_x                             0x558B50

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA320
#define CharacterZoneClient__HasSkill_x                            0x4D5210
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6930
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE5E0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BABE0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D92E0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D93C0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D94A0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C33D0
#define CharacterZoneClient__BardCastBard_x                        0x4C5F30
#define CharacterZoneClient__GetMaxEffects_x                       0x4BACB0
#define CharacterZoneClient__GetEffect_x                           0x4BAB20
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4420
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C44F0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4540
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4690
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4860
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2A70
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7890
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7310

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E1980
#define CBankWnd__WndNotification_x                                0x6E1760

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EF0F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61D680
#define CButtonWnd__CButtonWnd_x                                   0x93A7E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70F3F0
#define CChatManager__InitContextMenu_x                            0x708540
#define CChatManager__FreeChatWindow_x                             0x70DF30
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E89D0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70F070
#define CChatManager__CreateChatWindow_x                           0x70E570

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8AF0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94EF00
#define CContextMenu__dCContextMenu_x                              0x94F140
#define CContextMenu__AddMenuItem_x                                0x94F150
#define CContextMenu__RemoveMenuItem_x                             0x94F460
#define CContextMenu__RemoveAllMenuItems_x                         0x94F480
#define CContextMenu__CheckMenuItem_x                              0x94F500
#define CContextMenu__SetMenuItem_x                                0x94F380
#define CContextMenu__AddSeparator_x                               0x94F2E0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94FAA0
#define CContextMenuManager__RemoveMenu_x                          0x94FB10
#define CContextMenuManager__PopupMenu_x                           0x94FBD0
#define CContextMenuManager__Flush_x                               0x94FA40
#define CContextMenuManager__GetMenu_x                             0x49B580
#define CContextMenuManager__CreateDefaultMenu_x                   0x71ABD0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8A66F0
#define CChatService__GetFriendName_x                              0x8DC3D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70FD20
#define CChatWindow__Clear_x                                       0x710FE0
#define CChatWindow__WndNotification_x                             0x711770
#define CChatWindow__AddHistory_x                                  0x7108A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94C350
#define CComboWnd__Draw_x                                          0x94B830
#define CComboWnd__GetCurChoice_x                                  0x94C190
#define CComboWnd__GetListRect_x                                   0x94BCF0
#define CComboWnd__GetTextRect_x                                   0x94C3C0
#define CComboWnd__InsertChoice_x                                  0x94BE80
#define CComboWnd__SetColors_x                                     0x94BE50
#define CComboWnd__SetChoice_x                                     0x94C160
#define CComboWnd__GetItemCount_x                                  0x94C1A0
#define CComboWnd__GetCurChoiceText_x                              0x94C1E0
#define CComboWnd__GetChoiceText_x                                 0x94C1B0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94BF20

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7185C0
#define CContainerWnd__vftable_x                                   0xB11434
#define CContainerWnd__SetContainer_x                              0x719B20

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54C490
#define CDisplay__PreZoneMainUI_x                                  0x54C4A0
#define CDisplay__CleanGameUI_x                                    0x551810
#define CDisplay__GetClickedActor_x                                0x5447B0
#define CDisplay__GetUserDefinedColor_x                            0x53CE70
#define CDisplay__GetWorldFilePath_x                               0x546220
#define CDisplay__is3dON_x                                         0x541410
#define CDisplay__ReloadUI_x                                       0x54B920
#define CDisplay__WriteTextHD2_x                                   0x541200
#define CDisplay__TrueDistance_x                                   0x547EE0
#define CDisplay__SetViewActor_x                                   0x5440D0
#define CDisplay__GetFloorHeight_x                                 0x5414D0
#define CDisplay__SetRenderWindow_x                                0x53FE30
#define CDisplay__ToggleScreenshotMode_x                           0x543BA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96EB40

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x952470
#define CEditWnd__GetCharIndexPt_x                                 0x9533A0
#define CEditWnd__GetDisplayString_x                               0x953240
#define CEditWnd__GetHorzOffset_x                                  0x951AA0
#define CEditWnd__GetLineForPrintableChar_x                        0x954540
#define CEditWnd__GetSelStartPt_x                                  0x953650
#define CEditWnd__GetSTMLSafeText_x                                0x953060
#define CEditWnd__PointFromPrintableChar_x                         0x954170
#define CEditWnd__SelectableCharFromPoint_x                        0x9542E0
#define CEditWnd__SetEditable_x                                    0x953720
#define CEditWnd__SetWindowTextA_x                                 0x952DE0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FCC50
#define CEverQuest__ClickedPlayer_x                                0x5EEC60
#define CEverQuest__CreateTargetIndicator_x                        0x60C280
#define CEverQuest__DeleteTargetIndicator_x                        0x60C310
#define CEverQuest__DoTellWindow_x                                 0x4E8BD0
#define CEverQuest__OutputTextToLog_x                              0x4E8E50
#define CEverQuest__DropHeldItemOnGround_x                         0x5E3CA0
#define CEverQuest__dsp_chat_x                                     0x4E91E0
#define CEverQuest__trimName_x                                     0x608560
#define CEverQuest__Emote_x                                        0x5FD4B0
#define CEverQuest__EnterZone_x                                    0x5F7430
#define CEverQuest__GetBodyTypeDesc_x                              0x601E20
#define CEverQuest__GetClassDesc_x                                 0x602460
#define CEverQuest__GetClassThreeLetterCode_x                      0x602A60
#define CEverQuest__GetDeityDesc_x                                 0x60ABC0
#define CEverQuest__GetLangDesc_x                                  0x602C20
#define CEverQuest__GetRaceDesc_x                                  0x602440
#define CEverQuest__InterpretCmd_x                                 0x60B190
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E7EA0
#define CEverQuest__LMouseUp_x                                     0x5E6230
#define CEverQuest__RightClickedOnPlayer_x                         0x5E8780
#define CEverQuest__RMouseUp_x                                     0x5E71B0
#define CEverQuest__SetGameState_x                                 0x5E3A30
#define CEverQuest__UPCNotificationFlush_x                         0x608460
#define CEverQuest__IssuePetCommand_x                              0x604020
#define CEverQuest__ReportSuccessfulHit_x                          0x5FE8A0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72A570
#define CGaugeWnd__CalcLinesFillRect_x                             0x72A5D0
#define CGaugeWnd__Draw_x                                          0x729BF0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF590
#define CGuild__GetGuildName_x                                     0x4AE670
#define CGuild__GetGuildIndex_x                                    0x4AEA00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7459E0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61DA40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7529F0
#define CInvSlotMgr__MoveItem_x                                    0x751710
#define CInvSlotMgr__SelectSlot_x                                  0x752AC0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74FF90
#define CInvSlot__SliderComplete_x                                 0x74DCE0
#define CInvSlot__GetItemBase_x                                    0x74D660
#define CInvSlot__UpdateItem_x                                     0x74D7D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x754540
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7536E0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7540C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80DFF0
#define CItemDisplayWnd__UpdateStrings_x                           0x762BA0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75C900
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75CE10
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7631B0
#define CItemDisplayWnd__AboutToShow_x                             0x7627E0
#define CItemDisplayWnd__WndNotification_x                         0x7642A0
#define CItemDisplayWnd__RequestConvertItem_x                      0x763D60
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x761840
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x762600

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x846AD0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7687D0

// CLabel 
#define CLabel__Draw_x                                             0x76E210

// CListWnd
#define CListWnd__CListWnd_x                                       0x924940
#define CListWnd__dCListWnd_x                                      0x924C60
#define CListWnd__AddColumn_x                                      0x9290F0
#define CListWnd__AddColumn1_x                                     0x929140
#define CListWnd__AddLine_x                                        0x9294D0
#define CListWnd__AddString_x                                      0x9292D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x928EB0
#define CListWnd__CalculateVSBRange_x                              0x928C90
#define CListWnd__ClearSel_x                                       0x929CB0
#define CListWnd__ClearAllSel_x                                    0x929D10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92A730
#define CListWnd__Compare_x                                        0x9285C0
#define CListWnd__Draw_x                                           0x924D90
#define CListWnd__DrawColumnSeparators_x                           0x927590
#define CListWnd__DrawHeader_x                                     0x927A00
#define CListWnd__DrawItem_x                                       0x927F00
#define CListWnd__DrawLine_x                                       0x927700
#define CListWnd__DrawSeparator_x                                  0x927630
#define CListWnd__EnableLine_x                                     0x926E60
#define CListWnd__EnsureVisible_x                                  0x92A650
#define CListWnd__ExtendSel_x                                      0x929BE0
#define CListWnd__GetColumnTooltip_x                               0x9269A0
#define CListWnd__GetColumnMinWidth_x                              0x926A10
#define CListWnd__GetColumnWidth_x                                 0x926910
#define CListWnd__GetCurSel_x                                      0x9262A0
#define CListWnd__GetItemAtPoint_x                                 0x9270E0
#define CListWnd__GetItemAtPoint1_x                                0x927150
#define CListWnd__GetItemData_x                                    0x926320
#define CListWnd__GetItemHeight_x                                  0x9266E0
#define CListWnd__GetItemIcon_x                                    0x9264B0
#define CListWnd__GetItemRect_x                                    0x926F50
#define CListWnd__GetItemText_x                                    0x926360
#define CListWnd__GetSelList_x                                     0x929D60
#define CListWnd__GetSeparatorRect_x                               0x927390
#define CListWnd__InsertLine_x                                     0x9298C0
#define CListWnd__RemoveLine_x                                     0x929A10
#define CListWnd__SetColors_x                                      0x928C60
#define CListWnd__SetColumnJustification_x                         0x928990
#define CListWnd__SetColumnWidth_x                                 0x9288B0
#define CListWnd__SetCurSel_x                                      0x929B20
#define CListWnd__SetItemColor_x                                   0x92A300
#define CListWnd__SetItemData_x                                    0x92A2C0
#define CListWnd__SetItemText_x                                    0x929ED0
#define CListWnd__ShiftColumnSeparator_x                           0x928A50
#define CListWnd__Sort_x                                           0x928740
#define CListWnd__ToggleSel_x                                      0x929B50
#define CListWnd__SetColumnsSizable_x                              0x928B00
#define CListWnd__SetItemWnd_x                                     0x92A180
#define CListWnd__GetItemWnd_x                                     0x926500
#define CListWnd__SetItemIcon_x                                    0x929F50
#define CListWnd__CalculateCustomWindowPositions_x                 0x928FB0
#define CListWnd__SetVScrollPos_x                                  0x928890

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x783920
#define CMapViewWnd__GetWorldCoordinates_x                         0x782030
#define CMapViewWnd__HandleLButtonDown_x                           0x77F070

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A3980
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A4260
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A4790
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A7700
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A24F0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AD2B0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A3590

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A9D10
#define CPacketScrambler__hton_x                                   0x8A9D00

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x943A80
#define CSidlManager__FindScreenPieceTemplate_x                    0x943E90
#define CSidlManager__FindScreenPieceTemplate1_x                   0x943C80
#define CSidlManager__CreateLabel_x                                0x805350
#define CSidlManager__CreateXWndFromTemplate_x                     0x946DF0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x946FD0
#define CSidlManager__CreateXWnd_x                                 0x805280
#define CSidlManager__CreateHotButtonWnd_x                         0x805840

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x940560
#define CSidlScreenWnd__CalculateVSBRange_x                        0x940460
#define CSidlScreenWnd__ConvertToRes_x                             0x965B90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93FEF0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93FBE0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93FCB0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93FD80
#define CSidlScreenWnd__DrawSidlPiece_x                            0x940A00
#define CSidlScreenWnd__EnableIniStorage_x                         0x940ED0
#define CSidlScreenWnd__GetSidlPiece_x                             0x940BF0
#define CSidlScreenWnd__Init1_x                                    0x93F7E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x940F20
#define CSidlScreenWnd__LoadIniListWnd_x                           0x941A60
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93EBE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9415E0
#define CSidlScreenWnd__StoreIniVis_x                              0x941940
#define CSidlScreenWnd__WndNotification_x                          0x940910
#define CSidlScreenWnd__GetChildItem_x                             0x940E50
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9305B0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F6FD0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x682140
#define CSkillMgr__GetSkillCap_x                                   0x682320
#define CSkillMgr__GetNameToken_x                                  0x6818C0
#define CSkillMgr__IsActivatedSkill_x                              0x681A00
#define CSkillMgr__IsCombatSkill_x                                 0x681940

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x950880
#define CSliderWnd__SetValue_x                                     0x9506F0
#define CSliderWnd__SetNumTicks_x                                  0x950750

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80B480

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9590B0
#define CStmlWnd__CalculateHSBRange_x                              0x95A1D0
#define CStmlWnd__CalculateVSBRange_x                              0x95A150
#define CStmlWnd__CanBreakAtCharacter_x                            0x95E510
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95F1A0
#define CStmlWnd__ForceParseNow_x                                  0x9596A0
#define CStmlWnd__GetNextTagPiece_x                                0x95E470
#define CStmlWnd__GetSTMLText_x                                    0x5047D0
#define CStmlWnd__GetVisibleText_x                                 0x9596C0
#define CStmlWnd__InitializeWindowVariables_x                      0x95EFF0
#define CStmlWnd__MakeStmlColorTag_x                               0x958720
#define CStmlWnd__MakeWndNotificationTag_x                         0x958790
#define CStmlWnd__SetSTMLText_x                                    0x9577D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x9602A0
#define CStmlWnd__UpdateHistoryString_x                            0x95F3B0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x956910
#define CTabWnd__DrawCurrentPage_x                                 0x957040
#define CTabWnd__DrawTab_x                                         0x956D60
#define CTabWnd__GetCurrentPage_x                                  0x956110
#define CTabWnd__GetPageInnerRect_x                                0x956350
#define CTabWnd__GetTabInnerRect_x                                 0x956290
#define CTabWnd__GetTabRect_x                                      0x956140
#define CTabWnd__InsertPage_x                                      0x956560
#define CTabWnd__SetPage_x                                         0x9563D0
#define CTabWnd__SetPageRect_x                                     0x956850
#define CTabWnd__UpdatePage_x                                      0x956C20
#define CTabWnd__GetPageFromTabIndex_x                             0x956CA0
#define CTabWnd__GetCurrentTabIndex_x                              0x956100

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x768BA0
#define CPageWnd__SetTabText_x                                     0x955C50

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A91A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92D420
#define CTextureFont__GetTextExtent_x                              0x92D5E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B5030
#define CHtmlComponentWnd__ValidateUri_x                           0x7473D0
#define CHtmlWnd__SetClientCallbacks_x                             0x622AD0
#define CHtmlWnd__AddObserver_x                                    0x622AF0
#define CHtmlWnd__RemoveObserver_x                                 0x622B50
#define Window__getProgress_x                                      0x85F190
#define Window__getStatus_x                                        0x85F1B0
#define Window__getURI_x                                           0x85F1C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96B5D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91A560

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8810
#define CXStr__CXStr1_x                                            0x84FB10
#define CXStr__CXStr3_x                                            0x8FC440
#define CXStr__dCXStr_x                                            0x478780
#define CXStr__operator_equal_x                                    0x8FC670
#define CXStr__operator_equal1_x                                   0x8FC6B0
#define CXStr__operator_plus_equal1_x                              0x8FD140
#define CXStr__SetString_x                                         0x8FF030
#define CXStr__operator_char_p_x                                   0x8FCBB0
#define CXStr__GetChar_x                                           0x8FE980
#define CXStr__Delete_x                                            0x8FE230
#define CXStr__GetUnicode_x                                        0x8FE9F0
#define CXStr__GetLength_x                                         0x47D4D0
#define CXStr__Mid_x                                               0x47D4E0
#define CXStr__Insert_x                                            0x8FEA50
#define CXStr__FindNext_x                                          0x8FE6A0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94EB10
#define CXWnd__BringToTop_x                                        0x933D40
#define CXWnd__Center_x                                            0x9338C0
#define CXWnd__ClrFocus_x                                          0x9336D0
#define CXWnd__Destroy_x                                           0x933780
#define CXWnd__DoAllDrawing_x                                      0x92FD40
#define CXWnd__DrawChildren_x                                      0x92FD10
#define CXWnd__DrawColoredRect_x                                   0x9301A0
#define CXWnd__DrawTooltip_x                                       0x92E860
#define CXWnd__DrawTooltipAtPoint_x                                0x92E920
#define CXWnd__GetBorderFrame_x                                    0x930000
#define CXWnd__GetChildWndAt_x                                     0x933DE0
#define CXWnd__GetClientClipRect_x                                 0x931FC0
#define CXWnd__GetScreenClipRect_x                                 0x932090
#define CXWnd__GetScreenRect_x                                     0x932240
#define CXWnd__GetTooltipRect_x                                    0x9301F0
#define CXWnd__GetWindowTextA_x                                    0x49CCA0
#define CXWnd__IsActive_x                                          0x930920
#define CXWnd__IsDescendantOf_x                                    0x932C10
#define CXWnd__IsReallyVisible_x                                   0x932C40
#define CXWnd__IsType_x                                            0x934460
#define CXWnd__Move_x                                              0x932CB0
#define CXWnd__Move1_x                                             0x932D60
#define CXWnd__ProcessTransition_x                                 0x933870
#define CXWnd__Refade_x                                            0x933040
#define CXWnd__Resize_x                                            0x9332E0
#define CXWnd__Right_x                                             0x933B00
#define CXWnd__SetFocus_x                                          0x933690
#define CXWnd__SetFont_x                                           0x933700
#define CXWnd__SetKeyTooltip_x                                     0x934270
#define CXWnd__SetMouseOver_x                                      0x931160
#define CXWnd__StartFade_x                                         0x932AF0
#define CXWnd__GetChildItem_x                                      0x933F50
#define CXWnd__SetParent_x                                         0x9329F0
#define CXWnd__Minimize_x                                          0x933350

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x966C10

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x936D40
#define CXWndManager__DrawWindows_x                                0x936D60
#define CXWndManager__GetKeyboardFlags_x                           0x939440
#define CXWndManager__HandleKeyboardMsg_x                          0x938FF0
#define CXWndManager__RemoveWnd_x                                  0x939690
#define CXWndManager__RemovePendingDeletionWnd_x                   0x939BF0

// CDBStr
#define CDBStr__GetString_x                                        0x53BE20

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBBC0
#define EQ_Character__Cur_HP_x                                     0x4D2250
#define EQ_Character__Cur_Mana_x                                   0x4D99A0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEC30
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B26B0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2800
#define EQ_Character__GetHPRegen_x                                 0x4DF770
#define EQ_Character__GetEnduranceRegen_x                          0x4DFD70
#define EQ_Character__GetManaRegen_x                               0x4E01B0
#define EQ_Character__Max_Endurance_x                              0x648840
#define EQ_Character__Max_HP_x                                     0x4D2080
#define EQ_Character__Max_Mana_x                                   0x648640
#define EQ_Character__doCombatAbility_x                            0x64AC90
#define EQ_Character__UseSkill_x                                   0x4E1F80
#define EQ_Character__GetConLevel_x                                0x641BB0
#define EQ_Character__IsExpansionFlag_x                            0x5A6050
#define EQ_Character__TotalEffect_x                                0x4C5670
#define EQ_Character__GetPCSpellAffect_x                           0x4BF980
#define EQ_Character__SpellDuration_x                              0x4BF4B0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4FD0
#define EQ_Character__GetBaseSkill_x                               0x4D5F70
#define EQ_Character__CanUseItem_x                                 0x4D9CB0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C9280

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65EDB0

//PcClient
#define PcClient__PcClient_x                                       0x63F300

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9830
#define CCharacterListWnd__EnterWorld_x                            0x4B9270
#define CCharacterListWnd__Quit_x                                  0x4B8FC0
#define CCharacterListWnd__UpdateList_x                            0x4B9400

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x623D20
#define EQ_Item__CreateItemTagString_x                             0x8A3500
#define EQ_Item__IsStackable_x                                     0x8A80D0
#define EQ_Item__GetImageNum_x                                     0x8A4F90
#define EQ_Item__CreateItemClient_x                                0x622EF0
#define EQ_Item__GetItemValue_x                                    0x8A62B0
#define EQ_Item__ValueSellMerchant_x                               0x8A98F0
#define EQ_Item__IsKeyRingItem_x                                   0x8A79F0
#define EQ_Item__CanGoInBag_x                                      0x623E40
#define EQ_Item__IsEmpty_x                                         0x8A7520
#define EQ_Item__GetMaxItemCount_x                                 0x8A66C0
#define EQ_Item__GetHeldItem_x                                     0x8A4E60
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A2E70

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55A320
#define EQ_LoadingS__Array_x                                       0xC25B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6491A0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B2B00
#define EQ_PC__GetCombatAbility_x                                  0x8B3170
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B31E0
#define EQ_PC__GetItemRecastTimer_x                                0x64B210
#define EQ_PC__HasLoreItem_x                                       0x642370
#define EQ_PC__AlertInventoryChanged_x                             0x641500
#define EQ_PC__GetPcZoneClient_x                                   0x66D9A0
#define EQ_PC__RemoveMyAffect_x                                    0x64E440
#define EQ_PC__GetKeyRingItems_x                                   0x8B3A70
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B3800
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B3D70

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AC5C0
#define EQItemList__add_object_x                                   0x5D9490
#define EQItemList__add_item_x                                     0x5ACB20
#define EQItemList__delete_item_x                                  0x5ACB70
#define EQItemList__FreeItemList_x                                 0x5ACA70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538860

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x660630
#define EQPlayer__dEQPlayer_x                                      0x653970
#define EQPlayer__DoAttack_x                                       0x668660
#define EQPlayer__EQPlayer_x                                       0x654030
#define EQPlayer__SetNameSpriteState_x                             0x658310
#define EQPlayer__SetNameSpriteTint_x                              0x6591E0
#define PlayerBase__HasProperty_j_x                                0x9992B0
#define EQPlayer__IsTargetable_x                                   0x999750
#define EQPlayer__CanSee_x                                         0x9995B0
#define EQPlayer__CanSee1_x                                        0x999680
#define PlayerBase__GetVisibilityLineSegment_x                     0x999370

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66B440
#define PlayerZoneClient__GetLevel_x                               0x66D9E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DA600
#define PlayerZoneClient__LegalPlayerRace_x                        0x5536A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x663480
#define EQPlayerManager__GetSpawnByName_x                          0x663530
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6635C0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x627360
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6273E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x627420
#define KeypressHandler__ClearCommandStateArray_x                  0x628830
#define KeypressHandler__HandleKeyDown_x                           0x628850
#define KeypressHandler__HandleKeyUp_x                             0x6288F0
#define KeypressHandler__SaveKeymapping_x                          0x628D40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77F790
#define MapViewMap__SaveEx_x                                       0x782B50
#define MapViewMap__SetZoom_x                                      0x787210

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C71A0

// StringTable 
#define StringTable__getString_x                                   0x8C1E00

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64E0B0
#define PcZoneClient__RemovePetEffect_x                            0x64E6E0
#define PcZoneClient__HasAlternateAbility_x                        0x648470
#define PcZoneClient__GetCurrentMod_x                              0x4E5040
#define PcZoneClient__GetModCap_x                                  0x4E4F40
#define PcZoneClient__CanEquipItem_x                               0x648B40
#define PcZoneClient__GetItemByID_x                                0x64B680
#define PcZoneClient__GetItemByItemClass_x                         0x64B7D0
#define PcZoneClient__RemoveBuffEffect_x                           0x64E700
#define PcZoneClient__BandolierSwap_x                              0x649750
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64B1B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DF180

//IconCache
#define IconCache__GetIcon_x                                       0x71FC70

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x717760
#define CContainerMgr__CloseContainer_x                            0x717A30
#define CContainerMgr__OpenExperimentContainer_x                   0x7184B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D7950

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61BE40

//CLootWnd
#define CLootWnd__LootAll_x                                        0x775CE0
#define CLootWnd__RequestLootSlot_x                                0x774F10

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x579B80
#define EQ_Spell__SpellAffects_x                                   0x579FF0
#define EQ_Spell__SpellAffectBase_x                                0x579DB0
#define EQ_Spell__IsStackable_x                                    0x4C9C90
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9B10
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6B60
#define EQ_Spell__IsSPAStacking_x                                  0x57AE40
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A350
#define EQ_Spell__IsNoRemove_x                                     0x4C9C70
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57AE50
#define __IsResEffectSpell_x                                       0x4C90B0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD2C0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D17F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81E7C0
#define CTargetWnd__WndNotification_x                              0x81E050
#define CTargetWnd__RefreshTargetBuffs_x                           0x81E320
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81D1B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x822DC0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5362A0
#define CTaskManager__HandleMessage_x                              0x534730
#define CTaskManager__GetTaskStatus_x                              0x536350
#define CTaskManager__GetElementDescription_x                      0x5363D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5750F0
#define EqSoundManager__PlayScriptMp3_x                            0x575250
#define EqSoundManager__SoundAssistPlay_x                          0x686030
#define EqSoundManager__WaveInstancePlay_x                         0x6855A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x529FF0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x955160

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x561D20
#define CAltAbilityData__GetMercMaxRank_x                          0x561CB0
#define CAltAbilityData__GetMaxRank_x                              0x557400

//CTargetRing
#define CTargetRing__Cast_x                                        0x619F60

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9AF0
#define CharacterBase__CreateItemGlobalIndex_x                     0x511340
#define CharacterBase__CreateItemIndex_x                           0x622080
#define CharacterBase__GetItemPossession_x                         0x4FD150
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D9DD0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D9E30
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FE6F0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FEF20
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FEFD0

//messages
#define msg_spell_worn_off_x                                       0x59E180
#define msg_new_text_x                                             0x592F20
#define __msgTokenTextParam_x                                      0x5A06B0
#define msgTokenText_x                                             0x5A0900

//SpellManager
#define SpellManager__vftable_x                                    0xAEB490
#define SpellManager__SpellManager_x                               0x689360
#define Spellmanager__LoadTextSpells_x                             0x689C50
#define SpellManager__GetSpellByGroupAndRank_x                     0x689530

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99D190

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x511990
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A4470
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63AA20
#define ItemGlobalIndex__IsValidIndex_x                            0x5119F0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D2190
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D2410

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76E550

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71BE70
#define CCursorAttachment__AttachToCursor1_x                       0x71BEB0
#define CCursorAttachment__Deactivate_x                            0x71CEA0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x947E20
#define CSidlManagerBase__CreatePageWnd_x                          0x947620
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9438A0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x943830

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x964F80
#define CEQSuiteTextureLoader__GetTexture_x                        0x964C40

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50E8E0
#define CFindItemWnd__WndNotification_x                            0x50F3C0
#define CFindItemWnd__Update_x                                     0x50FF30
#define CFindItemWnd__PickupSelectedItem_x                         0x50E130

//IString
#define IString__Append_x                                          0x4FEA00

//Camera
#define CDisplay__cameraType_x                                     0xDFF5D4
#define EverQuest__Cameras_x                                       0xEC2AFC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5170A0
#define LootFiltersManager__GetItemFilterData_x                    0x5169A0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5169D0
#define LootFiltersManager__SetItemLootFilter_x                    0x516BF0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C58F0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A2D80
#define CResolutionHandler__GetWindowedStyle_x                     0x680BA0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x714480

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E6B20
#define CDistillerInfo__Instance_x                                 0x8E6AC0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x734790
#define CGroupWnd__UpdateDisplay_x                                 0x733AE0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A7AA0
#define ItemBase__IsLoreEquipped_x                                 0x8A7B10

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D93F0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D9530
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D9590

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6760B0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x679A20

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x504DD0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2180
#define FactionManagerClient__HandleFactionMessage_x               0x4F27F0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2DF0
#define FactionManagerClient__GetMaxFaction_x                      0x4F2E0F
#define FactionManagerClient__GetMinFaction_x                      0x4F2DC0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD120

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92C3D0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BF80

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD410

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5611C0

//CTargetManager
#define CTargetManager__Get_x                                      0x68CBD0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6760B0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8F60

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5ACA10

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF60190

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
