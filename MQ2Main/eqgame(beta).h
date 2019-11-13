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
#define __ExpectedVersionDate                                     "Nov 13 2019"
#define __ExpectedVersionTime                                     "10:32:05"
#define __ActualVersionDate_x                                      0xB0824C
#define __ActualVersionTime_x                                      0xB08240
#define __ActualVersionBuild_x                                     0xAF3F3C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62D720
#define __MemChecker1_x                                            0x900610
#define __MemChecker2_x                                            0x6BBD40
#define __MemChecker3_x                                            0x6BBC90
#define __MemChecker4_x                                            0x8575D0
#define __EncryptPad0_x                                            0xC3E3E8
#define __EncryptPad1_x                                            0xC9C5A8
#define __EncryptPad2_x                                            0xC4EC80
#define __EncryptPad3_x                                            0xC4E880
#define __EncryptPad4_x                                            0xC8CC00
#define __EncryptPad5_x                                            0xF68240
#define __AC1_x                                                    0x814656
#define __AC2_x                                                    0x5E769F
#define __AC3_x                                                    0x5EED9F
#define __AC4_x                                                    0x5F2D70
#define __AC5_x                                                    0x5F907F
#define __AC6_x                                                    0x5FD696
#define __AC7_x                                                    0x5E7110
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
#define __do_loot_x                                                0x5B3A50
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
#define __ScreenMode_x                                             0xDFF0A8
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
#define __gfMaxCameraDistance_x                                    0xB2A0EC
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
#define pinstCamActor_x                                            0xDFF09C
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
#define pinstViewActor_x                                           0xDFF098
#define pinstWorldData_x                                           0xEB1824
#define pinstZoneAddr_x                                            0xEC1960
#define pinstPlayerPath_x                                          0xF63408
#define pinstTargetIndicator_x                                     0xF64D50
#define EQObject_Top_x                                             0xEB16F4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDFF834
#define pinstCAchievementsWnd_x                                    0xDFF830
#define pinstCActionsWnd_x                                         0xDFF7F8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFF068
#define pinstCAdvancedLootWnd_x                                    0xDFF028
#define pinstCAdventureLeaderboardWnd_x                            0xF723E0
#define pinstCAdventureRequestWnd_x                                0xF72490
#define pinstCAdventureStatsWnd_x                                  0xF72540
#define pinstCAggroMeterWnd_x                                      0xDFF114
#define pinstCAlarmWnd_x                                           0xDFEFF4
#define pinstCAlertHistoryWnd_x                                    0xDFF088
#define pinstCAlertStackWnd_x                                      0xDFEFFC
#define pinstCAlertWnd_x                                           0xDFF008
#define pinstCAltStorageWnd_x                                      0xF728A0
#define pinstCAudioTriggersWindow_x                                0xCB3C28
#define pinstCAuraWnd_x                                            0xDFF0C0
#define pinstCAvaZoneWnd_x                                         0xDFF064
#define pinstCBandolierWnd_x                                       0xDFF10C
#define pinstCBankWnd_x                                            0xDFF0BC
#define pinstCBarterMerchantWnd_x                                  0xF73AE0
#define pinstCBarterSearchWnd_x                                    0xF73B90
#define pinstCBarterWnd_x                                          0xF73C40
#define pinstCBazaarConfirmationWnd_x                              0xDFF85C
#define pinstCBazaarSearchWnd_x                                    0xDFF5DC
#define pinstCBazaarWnd_x                                          0xDFF878
#define pinstCBlockedBuffWnd_x                                     0xDFF0C8
#define pinstCBlockedPetBuffWnd_x                                  0xDFF0E8
#define pinstCBodyTintWnd_x                                        0xDFF808
#define pinstCBookWnd_x                                            0xDFF13C
#define pinstCBreathWnd_x                                          0xDFF84C
#define pinstCBuffWindowNORMAL_x                                   0xDFF08C
#define pinstCBuffWindowSHORT_x                                    0xDFF090
#define pinstCBugReportWnd_x                                       0xDFF0B4
#define pinstCButtonWnd_x                                          0x15F73B0
#define pinstCCastingWnd_x                                         0xDFF128
#define pinstCCastSpellWnd_x                                       0xDFF848
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDFEFE0
#define pinstCChatWindowManager_x                                  0xF74700
#define pinstCClaimWnd_x                                           0xF74858
#define pinstCColorPickerWnd_x                                     0xDFF800
#define pinstCCombatAbilityWnd_x                                   0xDFEFEC
#define pinstCCombatSkillsSelectWnd_x                              0xDFF010
#define pinstCCompassWnd_x                                         0xDFF7FC
#define pinstCConfirmationDialog_x                                 0xF79758
#define pinstCContainerMgr_x                                       0xDFF870
#define pinstCContextMenuManager_x                                 0x15F7100
#define pinstCCursorAttachment_x                                   0xDFF11C
#define pinstCDynamicZoneWnd_x                                     0xF74E20
#define pinstCEditLabelWnd_x                                       0xDFF084
#define pinstCEQMainWnd_x                                          0xF75068
#define pinstCEventCalendarWnd_x                                   0xDFF120
#define pinstCExtendedTargetWnd_x                                  0xDFF0DC
#define pinstCFacePick_x                                           0xDFF020
#define pinstCFactionWnd_x                                         0xDFF86C
#define pinstCFellowshipWnd_x                                      0xF75268
#define pinstCFileSelectionWnd_x                                   0xDFF124
#define pinstCFindItemWnd_x                                        0xDFF858
#define pinstCFindLocationWnd_x                                    0xF753C0
#define pinstCFriendsWnd_x                                         0xDFF024
#define pinstCGemsGameWnd_x                                        0xDFF868
#define pinstCGiveWnd_x                                            0xDFEFF8
#define pinstCGroupSearchFiltersWnd_x                              0xDFF12C
#define pinstCGroupSearchWnd_x                                     0xF757B8
#define pinstCGroupWnd_x                                           0xF75868
#define pinstCGuildBankWnd_x                                       0xEC27A4
#define pinstCGuildCreationWnd_x                                   0xF759C8
#define pinstCGuildMgmtWnd_x                                       0xF75A78
#define pinstCharacterCreation_x                                   0xDFF018
#define pinstCHelpWnd_x                                            0xDFF05C
#define pinstCHeritageSelectionWnd_x                               0xDFF02C
#define pinstCHotButtonWnd_x                                       0xF77BD0
#define pinstCHotButtonWnd1_x                                      0xF77BD0
#define pinstCHotButtonWnd2_x                                      0xF77BD4
#define pinstCHotButtonWnd3_x                                      0xF77BD8
#define pinstCHotButtonWnd4_x                                      0xF77BDC
#define pinstCIconSelectionWnd_x                                   0xDFF118
#define pinstCInspectWnd_x                                         0xDFF058
#define pinstCInventoryWnd_x                                       0xDFF030
#define pinstCInvSlotMgr_x                                         0xDFF82C
#define pinstCItemDisplayManager_x                                 0xF78160
#define pinstCItemExpTransferWnd_x                                 0xF78294
#define pinstCItemOverflowWnd_x                                    0xDFF7E0
#define pinstCJournalCatWnd_x                                      0xDFF5BC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDFF0E0
#define pinstCKeyRingWnd_x                                         0xDFF080
#define pinstCLargeDialogWnd_x                                     0xF7A3D8
#define pinstCLayoutCopyWnd_x                                      0xF785E0
#define pinstCLFGuildWnd_x                                         0xF78690
#define pinstCLoadskinWnd_x                                        0xDFF874
#define pinstCLootFiltersCopyWnd_x                                 0xCD0220
#define pinstCLootFiltersWnd_x                                     0xDFF000
#define pinstCLootSettingsWnd_x                                    0xDFF01C
#define pinstCLootWnd_x                                            0xDFF5C0
#define pinstCMailAddressBookWnd_x                                 0xDFF83C
#define pinstCMailCompositionWnd_x                                 0xDFF818
#define pinstCMailIgnoreListWnd_x                                  0xDFF840
#define pinstCMailWnd_x                                            0xDFF7F4
#define pinstCManageLootWnd_x                                      0xE006D8
#define pinstCMapToolbarWnd_x                                      0xDFF060
#define pinstCMapViewWnd_x                                         0xDFF03C
#define pinstCMarketplaceWnd_x                                     0xDFF004
#define pinstCMerchantWnd_x                                        0xDFF5C4
#define pinstCMIZoneSelectWnd_x                                    0xF78EC8
#define pinstCMusicPlayerWnd_x                                     0xDFF5D0
#define pinstCNameChangeMercWnd_x                                  0xDFF854
#define pinstCNameChangePetWnd_x                                   0xDFF838
#define pinstCNameChangeWnd_x                                      0xDFF864
#define pinstCNoteWnd_x                                            0xDFF040
#define pinstCObjectPreviewWnd_x                                   0xDFF014
#define pinstCOptionsWnd_x                                         0xDFF048
#define pinstCPetInfoWnd_x                                         0xDFF7E4
#define pinstCPetitionQWnd_x                                       0xDFF824
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDFF80C
#define pinstCPlayerWnd_x                                          0xDFF7E8
#define pinstCPopupWndManager_x                                    0xF79758
#define pinstCProgressionSelectionWnd_x                            0xF79808
#define pinstCPurchaseGroupWnd_x                                   0xDFF04C
#define pinstCPurchaseWnd_x                                        0xDFF034
#define pinstCPvPLeaderboardWnd_x                                  0xF798B8
#define pinstCPvPStatsWnd_x                                        0xF79968
#define pinstCQuantityWnd_x                                        0xDFF0E4
#define pinstCRaceChangeWnd_x                                      0xDFEFF0
#define pinstCRaidOptionsWnd_x                                     0xDFF130
#define pinstCRaidWnd_x                                            0xDFF820
#define pinstCRealEstateItemsWnd_x                                 0xDFF828
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDFF5C8
#define pinstCRealEstateManageWnd_x                                0xDFF054
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFF07C
#define pinstCRealEstatePlotSearchWnd_x                            0xDFF0B8
#define pinstCRealEstatePurchaseWnd_x                              0xDFF0F8
#define pinstCRespawnWnd_x                                         0xDFF0D0
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDFF844
#define pinstCSendMoneyWnd_x                                       0xDFF00C
#define pinstCServerListWnd_x                                      0xDFF110
#define pinstCSkillsSelectWnd_x                                    0xDFEFE4
#define pinstCSkillsWnd_x                                          0xDFF860
#define pinstCSocialEditWnd_x                                      0xDFF078
#define pinstCSocialWnd_x                                          0xDFF850
#define pinstCSpellBookWnd_x                                       0xDFEFE8
#define pinstCStoryWnd_x                                           0xDFF7EC
#define pinstCTargetOfTargetWnd_x                                  0xF7B790
#define pinstCTargetWnd_x                                          0xDFF0CC
#define pinstCTaskOverlayWnd_x                                     0xDFF044
#define pinstCTaskSelectWnd_x                                      0xF7B8E8
#define pinstCTaskManager_x                                        0xCD0B60
#define pinstCTaskTemplateSelectWnd_x                              0xF7B998
#define pinstCTaskWnd_x                                            0xF7BA48
#define pinstCTextEntryWnd_x                                       0xDFF094
#define pinstCTimeLeftWnd_x                                        0xDFF7F0
#define pinstCTipWndCONTEXT_x                                      0xF7BC4C
#define pinstCTipWndOFDAY_x                                        0xF7BC48
#define pinstCTitleWnd_x                                           0xF7BCF8
#define pinstCTrackingWnd_x                                        0xDFF038
#define pinstCTradeskillWnd_x                                      0xF7BE60
#define pinstCTradeWnd_x                                           0xDFF814
#define pinstCTrainWnd_x                                           0xDFF810
#define pinstCTributeBenefitWnd_x                                  0xF7C060
#define pinstCTributeMasterWnd_x                                   0xF7C110
#define pinstCTributeTrophyWnd_x                                   0xF7C1C0
#define pinstCVideoModesWnd_x                                      0xDFF5D4
#define pinstCVoiceMacroWnd_x                                      0xF654B8
#define pinstCVoteResultsWnd_x                                     0xDFF81C
#define pinstCVoteWnd_x                                            0xDFF804
#define pinstCWebManager_x                                         0xF65B34
#define pinstCZoneGuideWnd_x                                       0xDFF050
#define pinstCZonePathWnd_x                                        0xDFF070

#define pinstEQSuiteTextureLoader_x                                0xC9E080
#define pinstItemIconCache_x                                       0xF75020
#define pinstLootFiltersManager_x                                  0xCD02D0
#define pinstRewardSelectionWnd_x                                  0xF7A0B0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AEEB0
#define __CastRay2_x                                               0x5AEF00
#define __ConvertItemTags_x                                        0x5CAA50
#define __CleanItemTags_x                                          0x47D140
#define __DoesFileExist_x                                          0x9036F0
#define __EQGetTime_x                                              0x9000E0
#define __ExecuteCmd_x                                             0x5A77D0
#define __FixHeading_x                                             0x99B400
#define __GameLoop_x                                               0x6BAF30
#define __get_bearing_x                                            0x5AEA20
#define __get_melee_range_x                                        0x5AF0F0
#define __GetAnimationCache_x                                      0x720190
#define __GetGaugeValueFromEQ_x                                    0x812B00
#define __GetLabelFromEQ_x                                         0x8145E0
#define __GetXTargetType_x                                         0x99CE50
#define __HandleMouseWheel_x                                       0x6BBDF0
#define __HeadingDiff_x                                            0x99B470
#define __HelpPath_x                                               0xF6085C
#define __LoadFrontEnd_x                                           0x6B8250
#define __NewUIINI_x                                               0x8127D0
#define __ProcessGameEvents_x                                      0x60EF10
#define __ProcessMouseEvent_x                                      0x60E6D0
#define __SaveColors_x                                             0x551910
#define __STMLToText_x                                             0x93E840
#define __ToggleKeyRingItem_x                                      0x514C70
#define CMemoryMappedFile__SetFile_x                               0xA8A770
#define CrashDetected_x                                            0x6B9CF0
#define DrawNetStatus_x                                            0x63AA90
#define Expansion_HoT_x                                            0xEC27AC
#define Teleport_Table_Size_x                                      0xEB17E0
#define Teleport_Table_x                                           0xEB1C48
#define Util__FastTime_x                                           0x8FFCB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4903F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4992E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4990B0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493970
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492DC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559530
#define AltAdvManager__IsAbilityReady_x                            0x558460
#define AltAdvManager__GetAAById_x                                 0x558660
#define AltAdvManager__CanTrainAbility_x                           0x5586D0
#define AltAdvManager__CanSeeAbility_x                             0x558A30

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA290
#define CharacterZoneClient__HasSkill_x                            0x4D5180
#define CharacterZoneClient__MakeMeVisible_x                       0x4D68A0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE4A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAAA0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9220
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9300
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D93E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3290
#define CharacterZoneClient__BardCastBard_x                        0x4C5DF0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB70
#define CharacterZoneClient__GetEffect_x                           0x4BA9E0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C42E0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C43B0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4400
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4550
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4720
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B29A0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7800
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7280

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E1960
#define CBankWnd__WndNotification_x                                0x6E1740

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EF2E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61D4B0
#define CButtonWnd__CButtonWnd_x                                   0x93ABF0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70F260
#define CChatManager__InitContextMenu_x                            0x7083C0
#define CChatManager__FreeChatWindow_x                             0x70DDA0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E87D0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70EEE0
#define CChatManager__CreateChatWindow_x                           0x70E3E0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E88E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94F230
#define CContextMenu__dCContextMenu_x                              0x94F460
#define CContextMenu__AddMenuItem_x                                0x94F470
#define CContextMenu__RemoveMenuItem_x                             0x94F770
#define CContextMenu__RemoveAllMenuItems_x                         0x94F790
#define CContextMenu__CheckMenuItem_x                              0x94F810
#define CContextMenu__SetMenuItem_x                                0x94F6A0
#define CContextMenu__AddSeparator_x                               0x94F600

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94FDB0
#define CContextMenuManager__RemoveMenu_x                          0x94FE20
#define CContextMenuManager__PopupMenu_x                           0x94FEE0
#define CContextMenuManager__Flush_x                               0x94FD50
#define CContextMenuManager__GetMenu_x                             0x49B500
#define CContextMenuManager__CreateDefaultMenu_x                   0x71A9A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DBFD0
#define CChatService__GetFriendName_x                              0x8DBFE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70FAF0
#define CChatWindow__Clear_x                                       0x710DB0
#define CChatWindow__WndNotification_x                             0x711540
#define CChatWindow__AddHistory_x                                  0x710670

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94C6B0
#define CComboWnd__Draw_x                                          0x94BBB0
#define CComboWnd__GetCurChoice_x                                  0x94C4F0
#define CComboWnd__GetListRect_x                                   0x94C060
#define CComboWnd__GetTextRect_x                                   0x94C710
#define CComboWnd__InsertChoice_x                                  0x94C1F0
#define CComboWnd__SetColors_x                                     0x94C1C0
#define CComboWnd__SetChoice_x                                     0x94C4C0
#define CComboWnd__GetItemCount_x                                  0x94C500
#define CComboWnd__GetCurChoiceText_x                              0x94C540
#define CComboWnd__GetChoiceText_x                                 0x94C510
#define CComboWnd__InsertChoiceAtIndex_x                           0x94C280

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x718380
#define CContainerWnd__vftable_x                                   0xB11434
#define CContainerWnd__SetContainer_x                              0x7198F0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54C350
#define CDisplay__PreZoneMainUI_x                                  0x54C360
#define CDisplay__CleanGameUI_x                                    0x5516D0
#define CDisplay__GetClickedActor_x                                0x544670
#define CDisplay__GetUserDefinedColor_x                            0x53CD30
#define CDisplay__GetWorldFilePath_x                               0x5460E0
#define CDisplay__is3dON_x                                         0x5412D0
#define CDisplay__ReloadUI_x                                       0x54B7E0
#define CDisplay__WriteTextHD2_x                                   0x5410C0
#define CDisplay__TrueDistance_x                                   0x547DA0
#define CDisplay__SetViewActor_x                                   0x543F90
#define CDisplay__GetFloorHeight_x                                 0x541390
#define CDisplay__SetRenderWindow_x                                0x53FCF0
#define CDisplay__ToggleScreenshotMode_x                           0x543A60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96EFE0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x952780
#define CEditWnd__GetCharIndexPt_x                                 0x9536A0
#define CEditWnd__GetDisplayString_x                               0x953540
#define CEditWnd__GetHorzOffset_x                                  0x951DB0
#define CEditWnd__GetLineForPrintableChar_x                        0x954840
#define CEditWnd__GetSelStartPt_x                                  0x953950
#define CEditWnd__GetSTMLSafeText_x                                0x953360
#define CEditWnd__PointFromPrintableChar_x                         0x954470
#define CEditWnd__SelectableCharFromPoint_x                        0x9545E0
#define CEditWnd__SetEditable_x                                    0x953A20
#define CEditWnd__SetWindowTextA_x                                 0x9530E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FCB70
#define CEverQuest__ClickedPlayer_x                                0x5EEB80
#define CEverQuest__CreateTargetIndicator_x                        0x60C1A0
#define CEverQuest__DeleteTargetIndicator_x                        0x60C230
#define CEverQuest__DoTellWindow_x                                 0x4E89C0
#define CEverQuest__OutputTextToLog_x                              0x4E8C40
#define CEverQuest__DropHeldItemOnGround_x                         0x5E3BC0
#define CEverQuest__dsp_chat_x                                     0x4E8FD0
#define CEverQuest__trimName_x                                     0x608480
#define CEverQuest__Emote_x                                        0x5FD3D0
#define CEverQuest__EnterZone_x                                    0x5F7350
#define CEverQuest__GetBodyTypeDesc_x                              0x601D40
#define CEverQuest__GetClassDesc_x                                 0x602380
#define CEverQuest__GetClassThreeLetterCode_x                      0x602980
#define CEverQuest__GetDeityDesc_x                                 0x60AAE0
#define CEverQuest__GetLangDesc_x                                  0x602B40
#define CEverQuest__GetRaceDesc_x                                  0x602360
#define CEverQuest__InterpretCmd_x                                 0x60B0B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E7DC0
#define CEverQuest__LMouseUp_x                                     0x5E6150
#define CEverQuest__RightClickedOnPlayer_x                         0x5E86A0
#define CEverQuest__RMouseUp_x                                     0x5E70D0
#define CEverQuest__SetGameState_x                                 0x5E3950
#define CEverQuest__UPCNotificationFlush_x                         0x608380
#define CEverQuest__IssuePetCommand_x                              0x603F40
#define CEverQuest__ReportSuccessfulHit_x                          0x5FE7C0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72A2C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72A320
#define CGaugeWnd__Draw_x                                          0x729940

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF470
#define CGuild__GetGuildName_x                                     0x4AE550
#define CGuild__GetGuildIndex_x                                    0x4AE8E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x745760

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61D870

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x752750
#define CInvSlotMgr__MoveItem_x                                    0x751460
#define CInvSlotMgr__SelectSlot_x                                  0x752820

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74FCE0
#define CInvSlot__SliderComplete_x                                 0x74DA40
#define CInvSlot__GetItemBase_x                                    0x74D3C0
#define CInvSlot__UpdateItem_x                                     0x74D530

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x754280
#define CInvSlotWnd__CInvSlotWnd_x                                 0x753420
#define CInvSlotWnd__HandleLButtonUp_x                             0x753E00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80DE20
#define CItemDisplayWnd__UpdateStrings_x                           0x762990
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75C6F0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75CC00
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x762F90
#define CItemDisplayWnd__AboutToShow_x                             0x7625F0
#define CItemDisplayWnd__WndNotification_x                         0x764080
#define CItemDisplayWnd__RequestConvertItem_x                      0x763B40
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x761650
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x762410

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x846730

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x768580

// CLabel 
#define CLabel__Draw_x                                             0x76DFC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x924E80
#define CListWnd__dCListWnd_x                                      0x9251A0
#define CListWnd__AddColumn_x                                      0x929600
#define CListWnd__AddColumn1_x                                     0x929650
#define CListWnd__AddLine_x                                        0x9299E0
#define CListWnd__AddString_x                                      0x9297E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9293C0
#define CListWnd__CalculateVSBRange_x                              0x9291B0
#define CListWnd__ClearSel_x                                       0x92A1C0
#define CListWnd__ClearAllSel_x                                    0x92A220
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92AC20
#define CListWnd__Compare_x                                        0x928AE0
#define CListWnd__Draw_x                                           0x9252D0
#define CListWnd__DrawColumnSeparators_x                           0x927AB0
#define CListWnd__DrawHeader_x                                     0x927F20
#define CListWnd__DrawItem_x                                       0x928420
#define CListWnd__DrawLine_x                                       0x927C20
#define CListWnd__DrawSeparator_x                                  0x927B50
#define CListWnd__EnableLine_x                                     0x927390
#define CListWnd__EnsureVisible_x                                  0x92AB50
#define CListWnd__ExtendSel_x                                      0x92A0F0
#define CListWnd__GetColumnTooltip_x                               0x926ED0
#define CListWnd__GetColumnMinWidth_x                              0x926F40
#define CListWnd__GetColumnWidth_x                                 0x926E40
#define CListWnd__GetCurSel_x                                      0x9267D0
#define CListWnd__GetItemAtPoint_x                                 0x927600
#define CListWnd__GetItemAtPoint1_x                                0x927670
#define CListWnd__GetItemData_x                                    0x926850
#define CListWnd__GetItemHeight_x                                  0x926C10
#define CListWnd__GetItemIcon_x                                    0x9269E0
#define CListWnd__GetItemRect_x                                    0x927480
#define CListWnd__GetItemText_x                                    0x926890
#define CListWnd__GetSelList_x                                     0x92A270
#define CListWnd__GetSeparatorRect_x                               0x9278B0
#define CListWnd__InsertLine_x                                     0x929DD0
#define CListWnd__RemoveLine_x                                     0x929F20
#define CListWnd__SetColors_x                                      0x929180
#define CListWnd__SetColumnJustification_x                         0x928EB0
#define CListWnd__SetColumnWidth_x                                 0x928DD0
#define CListWnd__SetCurSel_x                                      0x92A030
#define CListWnd__SetItemColor_x                                   0x92A810
#define CListWnd__SetItemData_x                                    0x92A7D0
#define CListWnd__SetItemText_x                                    0x92A3E0
#define CListWnd__ShiftColumnSeparator_x                           0x928F70
#define CListWnd__Sort_x                                           0x928C60
#define CListWnd__ToggleSel_x                                      0x92A060
#define CListWnd__SetColumnsSizable_x                              0x929020
#define CListWnd__SetItemWnd_x                                     0x92A690
#define CListWnd__GetItemWnd_x                                     0x926A30
#define CListWnd__SetItemIcon_x                                    0x92A460
#define CListWnd__CalculateCustomWindowPositions_x                 0x9294C0
#define CListWnd__SetVScrollPos_x                                  0x928DB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x783770
#define CMapViewWnd__GetWorldCoordinates_x                         0x781E80
#define CMapViewWnd__HandleLButtonDown_x                           0x77EEC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A3860
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A4140
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A4660
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A75F0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A23D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AD190
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A3480

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A9880
#define CPacketScrambler__hton_x                                   0x8A9870

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x943E90
#define CSidlManager__FindScreenPieceTemplate_x                    0x9442A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x944090
#define CSidlManager__CreateLabel_x                                0x805250
#define CSidlManager__CreateXWndFromTemplate_x                     0x947200
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9473E0
#define CSidlManager__CreateXWnd_x                                 0x805180
#define CSidlManager__CreateHotButtonWnd_x                         0x805740

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x940970
#define CSidlScreenWnd__CalculateVSBRange_x                        0x940870
#define CSidlScreenWnd__ConvertToRes_x                             0x966030
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x940310
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x940000
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9400D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9401A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x940E10
#define CSidlScreenWnd__EnableIniStorage_x                         0x9412E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x941000
#define CSidlScreenWnd__Init1_x                                    0x93FC00
#define CSidlScreenWnd__LoadIniInfo_x                              0x941330
#define CSidlScreenWnd__LoadIniListWnd_x                           0x941E70
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93F000
#define CSidlScreenWnd__StoreIniInfo_x                             0x9419F0
#define CSidlScreenWnd__StoreIniVis_x                              0x941D50
#define CSidlScreenWnd__WndNotification_x                          0x940D20
#define CSidlScreenWnd__GetChildItem_x                             0x941260
#define CSidlScreenWnd__HandleLButtonUp_x                          0x930A40
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F6FD0

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
#define CSpellBookWnd__MemorizeSet_x                               0x80B2B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x959430
#define CStmlWnd__CalculateHSBRange_x                              0x95A550
#define CStmlWnd__CalculateVSBRange_x                              0x95A4D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x95E890
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95F520
#define CStmlWnd__ForceParseNow_x                                  0x959A20
#define CStmlWnd__GetNextTagPiece_x                                0x95E7F0
#define CStmlWnd__GetSTMLText_x                                    0x5042B0
#define CStmlWnd__GetVisibleText_x                                 0x959A40
#define CStmlWnd__InitializeWindowVariables_x                      0x95F370
#define CStmlWnd__MakeStmlColorTag_x                               0x958AA0
#define CStmlWnd__MakeWndNotificationTag_x                         0x958B10
#define CStmlWnd__SetSTMLText_x                                    0x957B50
#define CStmlWnd__StripFirstSTMLLines_x                            0x960620
#define CStmlWnd__UpdateHistoryString_x                            0x95F730

// CTabWnd 
#define CTabWnd__Draw_x                                            0x956BF0
#define CTabWnd__DrawCurrentPage_x                                 0x957320
#define CTabWnd__DrawTab_x                                         0x957040
#define CTabWnd__GetCurrentPage_x                                  0x956400
#define CTabWnd__GetPageInnerRect_x                                0x956640
#define CTabWnd__GetTabInnerRect_x                                 0x956580
#define CTabWnd__GetTabRect_x                                      0x956430
#define CTabWnd__InsertPage_x                                      0x956850
#define CTabWnd__SetPage_x                                         0x9566C0
#define CTabWnd__SetPageRect_x                                     0x956B30
#define CTabWnd__UpdatePage_x                                      0x956F00
#define CTabWnd__GetPageFromTabIndex_x                             0x956F80
#define CTabWnd__GetCurrentTabIndex_x                              0x9563F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x768950
#define CPageWnd__SetTabText_x                                     0x955F50

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A91A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92D940
#define CTextureFont__GetTextExtent_x                              0x92DB00

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B4E00
#define CHtmlComponentWnd__ValidateUri_x                           0x747150
#define CHtmlWnd__SetClientCallbacks_x                             0x6228E0
#define CHtmlWnd__AddObserver_x                                    0x622900
#define CHtmlWnd__RemoveObserver_x                                 0x622960
#define Window__getProgress_x                                      0x85EC20
#define Window__getStatus_x                                        0x85EC40
#define Window__getURI_x                                           0x85EC50

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96BA70

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91AA30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8610
#define CXStr__CXStr1_x                                            0x9F1AE0
#define CXStr__CXStr3_x                                            0x8FC1E0
#define CXStr__dCXStr_x                                            0x478800
#define CXStr__operator_equal_x                                    0x8FC410
#define CXStr__operator_equal1_x                                   0x8FC450
#define CXStr__operator_plus_equal1_x                              0x8FCEE0
#define CXStr__SetString_x                                         0x8FEDD0
#define CXStr__operator_char_p_x                                   0x8FC950
#define CXStr__GetChar_x                                           0x8FE720
#define CXStr__Delete_x                                            0x8FDFD0
#define CXStr__GetUnicode_x                                        0x8FE790
#define CXStr__GetLength_x                                         0x4A8F50
#define CXStr__Mid_x                                               0x47D4F0
#define CXStr__Insert_x                                            0x8FE7F0
#define CXStr__FindNext_x                                          0x8FE440

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94EE40
#define CXWnd__BringToTop_x                                        0x934170
#define CXWnd__Center_x                                            0x933CF0
#define CXWnd__ClrFocus_x                                          0x933B10
#define CXWnd__Destroy_x                                           0x933BB0
#define CXWnd__DoAllDrawing_x                                      0x9301F0
#define CXWnd__DrawChildren_x                                      0x9301C0
#define CXWnd__DrawColoredRect_x                                   0x930630
#define CXWnd__DrawTooltip_x                                       0x92ED30
#define CXWnd__DrawTooltipAtPoint_x                                0x92EDF0
#define CXWnd__GetBorderFrame_x                                    0x930490
#define CXWnd__GetChildWndAt_x                                     0x934210
#define CXWnd__GetClientClipRect_x                                 0x932470
#define CXWnd__GetScreenClipRect_x                                 0x932540
#define CXWnd__GetScreenRect_x                                     0x932700
#define CXWnd__GetTooltipRect_x                                    0x930680
#define CXWnd__GetWindowTextA_x                                    0x49CBE0
#define CXWnd__IsActive_x                                          0x930DB0
#define CXWnd__IsDescendantOf_x                                    0x9330E0
#define CXWnd__IsReallyVisible_x                                   0x933110
#define CXWnd__IsType_x                                            0x934870
#define CXWnd__Move_x                                              0x933190
#define CXWnd__Move1_x                                             0x933240
#define CXWnd__ProcessTransition_x                                 0x933CA0
#define CXWnd__Refade_x                                            0x933500
#define CXWnd__Resize_x                                            0x933760
#define CXWnd__Right_x                                             0x933F30
#define CXWnd__SetFocus_x                                          0x933AD0
#define CXWnd__SetFont_x                                           0x933B40
#define CXWnd__SetKeyTooltip_x                                     0x934680
#define CXWnd__SetMouseOver_x                                      0x9315F0
#define CXWnd__StartFade_x                                         0x932FC0
#define CXWnd__GetChildItem_x                                      0x934370
#define CXWnd__SetParent_x                                         0x932E90
#define CXWnd__Minimize_x                                          0x9337C0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9670B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x937090
#define CXWndManager__DrawWindows_x                                0x9370B0
#define CXWndManager__GetKeyboardFlags_x                           0x939880
#define CXWndManager__HandleKeyboardMsg_x                          0x939440
#define CXWndManager__RemoveWnd_x                                  0x939AA0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93A010

// CDBStr
#define CDBStr__GetString_x                                        0x53BD00

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBA80
#define EQ_Character__Cur_HP_x                                     0x4D21C0
#define EQ_Character__Cur_Mana_x                                   0x4D98E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEAF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B25E0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2730
#define EQ_Character__GetHPRegen_x                                 0x4DF680
#define EQ_Character__GetEnduranceRegen_x                          0x4DFC80
#define EQ_Character__GetManaRegen_x                               0x4E00C0
#define EQ_Character__Max_Endurance_x                              0x648910
#define EQ_Character__Max_HP_x                                     0x4D1FF0
#define EQ_Character__Max_Mana_x                                   0x648710
#define EQ_Character__doCombatAbility_x                            0x64AD70
#define EQ_Character__UseSkill_x                                   0x4E1EA0
#define EQ_Character__GetConLevel_x                                0x6419F0
#define EQ_Character__IsExpansionFlag_x                            0x5A5F70
#define EQ_Character__TotalEffect_x                                0x4C5530
#define EQ_Character__GetPCSpellAffect_x                           0x4BF840
#define EQ_Character__SpellDuration_x                              0x4BF370
#define EQ_Character__GetAdjustedSkill_x                           0x4D4F40
#define EQ_Character__GetBaseSkill_x                               0x4D5EE0
#define EQ_Character__CanUseItem_x                                 0x4D9BF0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C8E60

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65EE90

//PcClient
#define PcClient__PcClient_x                                       0x63F120

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B96F0
#define CCharacterListWnd__EnterWorld_x                            0x4B9130
#define CCharacterListWnd__Quit_x                                  0x4B8E80
#define CCharacterListWnd__UpdateList_x                            0x4B92C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x623B40
#define EQ_Item__CreateItemTagString_x                             0x8A3090
#define EQ_Item__IsStackable_x                                     0x8A7C10
#define EQ_Item__GetImageNum_x                                     0x8A4B10
#define EQ_Item__CreateItemClient_x                                0x622D00
#define EQ_Item__GetItemValue_x                                    0x8A5E10
#define EQ_Item__ValueSellMerchant_x                               0x8A9460
#define EQ_Item__IsKeyRingItem_x                                   0x8A7510
#define EQ_Item__CanGoInBag_x                                      0x623C60
#define EQ_Item__IsEmpty_x                                         0x8A7070
#define EQ_Item__GetMaxItemCount_x                                 0x8A6230
#define EQ_Item__GetHeldItem_x                                     0x8A49E0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A2A00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55A200
#define EQ_LoadingS__Array_x                                       0xC25B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x649270
#define EQ_PC__GetAlternateAbilityId_x                             0x8B26A0
#define EQ_PC__GetCombatAbility_x                                  0x8B2D10
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B2D80
#define EQ_PC__GetItemRecastTimer_x                                0x64B2F0
#define EQ_PC__HasLoreItem_x                                       0x642200
#define EQ_PC__AlertInventoryChanged_x                             0x641320
#define EQ_PC__GetPcZoneClient_x                                   0x66D9B0
#define EQ_PC__RemoveMyAffect_x                                    0x64E520
#define EQ_PC__GetKeyRingItems_x                                   0x8B3610
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B33A0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B3910

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AC4D0
#define EQItemList__add_object_x                                   0x5D9340
#define EQItemList__add_item_x                                     0x5ACA30
#define EQItemList__delete_item_x                                  0x5ACA80
#define EQItemList__FreeItemList_x                                 0x5AC980

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5387E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x660710
#define EQPlayer__dEQPlayer_x                                      0x653A70
#define EQPlayer__DoAttack_x                                       0x668660
#define EQPlayer__EQPlayer_x                                       0x654130
#define EQPlayer__SetNameSpriteState_x                             0x658400
#define EQPlayer__SetNameSpriteTint_x                              0x6592C0
#define PlayerBase__HasProperty_j_x                                0x9997F0
#define EQPlayer__IsTargetable_x                                   0x999C90
#define EQPlayer__CanSee_x                                         0x999AF0
#define EQPlayer__CanSee1_x                                        0x999BC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9998B0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66B440
#define PlayerZoneClient__GetLevel_x                               0x66D9F0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DA4B0
#define PlayerZoneClient__LegalPlayerRace_x                        0x553590

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x663500
#define EQPlayerManager__GetSpawnByName_x                          0x6635B0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x663640

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x627230
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6272B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6272F0
#define KeypressHandler__ClearCommandStateArray_x                  0x628700
#define KeypressHandler__HandleKeyDown_x                           0x628720
#define KeypressHandler__HandleKeyUp_x                             0x6287C0
#define KeypressHandler__SaveKeymapping_x                          0x628C10

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77F5E0
#define MapViewMap__SaveEx_x                                       0x7829A0
#define MapViewMap__SetZoom_x                                      0x787060

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C6D80

// StringTable 
#define StringTable__getString_x                                   0x8C18C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64E190
#define PcZoneClient__RemovePetEffect_x                            0x64E7C0
#define PcZoneClient__HasAlternateAbility_x                        0x648540
#define PcZoneClient__GetCurrentMod_x                              0x4E4F50
#define PcZoneClient__GetModCap_x                                  0x4E4E50
#define PcZoneClient__CanEquipItem_x                               0x648C10
#define PcZoneClient__GetItemByID_x                                0x64B760
#define PcZoneClient__GetItemByItemClass_x                         0x64B8B0
#define PcZoneClient__RemoveBuffEffect_x                           0x64E7E0
#define PcZoneClient__BandolierSwap_x                              0x649830
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64B290

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DF020

//IconCache
#define IconCache__GetIcon_x                                       0x71FA30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x717520
#define CContainerMgr__CloseContainer_x                            0x7177F0
#define CContainerMgr__OpenExperimentContainer_x                   0x718270

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D7760

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61BCA0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x775AF0
#define CLootWnd__RequestLootSlot_x                                0x774D20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x579D30
#define EQ_Spell__SpellAffects_x                                   0x57A1A0
#define EQ_Spell__SpellAffectBase_x                                0x579F60
#define EQ_Spell__IsStackable_x                                    0x4C9BF0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9A40
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6AB0
#define EQ_Spell__IsSPAStacking_x                                  0x57AFF0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A500
#define EQ_Spell__IsNoRemove_x                                     0x4C9BD0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57B000
#define __IsResEffectSpell_x                                       0x4C8F70

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD1D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D1490

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81E560
#define CTargetWnd__WndNotification_x                              0x81DDF0
#define CTargetWnd__RefreshTargetBuffs_x                           0x81E0C0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81CF70

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x822B50

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536210
#define CTaskManager__HandleMessage_x                              0x5346B0
#define CTaskManager__GetTaskStatus_x                              0x5362C0
#define CTaskManager__GetElementDescription_x                      0x536340

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5752A0
#define EqSoundManager__PlayScriptMp3_x                            0x575400
#define EqSoundManager__SoundAssistPlay_x                          0x685F60
#define EqSoundManager__WaveInstancePlay_x                         0x6854D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x529F60

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x955460

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x561BB0
#define CAltAbilityData__GetMercMaxRank_x                          0x561B40
#define CAltAbilityData__GetMaxRank_x                              0x5572E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x619DC0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9A20
#define CharacterBase__CreateItemGlobalIndex_x                     0x511320
#define CharacterBase__CreateItemIndex_x                           0x621E90
#define CharacterBase__GetItemPossession_x                         0x4FCA50
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D9AA0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D9B00
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FE630
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FEE60
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FEF10

//messages
#define msg_spell_worn_off_x                                       0x59E240
#define msg_new_text_x                                             0x592FD0
#define __msgTokenTextParam_x                                      0x5A0770
#define msgTokenText_x                                             0x5A09C0

//SpellManager
#define SpellManager__vftable_x                                    0xAEB498
#define SpellManager__SpellManager_x                               0x689280
#define Spellmanager__LoadTextSpells_x                             0x689B70
#define SpellManager__GetSpellByGroupAndRank_x                     0x689450

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99D740

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x511970
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A4540
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63A8F0
#define ItemGlobalIndex__IsValidIndex_x                            0x5119D0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D1E30
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D20B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76E300

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71BC30
#define CCursorAttachment__AttachToCursor1_x                       0x71BC70
#define CCursorAttachment__Deactivate_x                            0x71CC60

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x948230
#define CSidlManagerBase__CreatePageWnd_x                          0x947A30
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x943CB0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x943C40

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x965320
#define CEQSuiteTextureLoader__GetTexture_x                        0x964FE0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50E890
#define CFindItemWnd__WndNotification_x                            0x50F370
#define CFindItemWnd__Update_x                                     0x50FEE0
#define CFindItemWnd__PickupSelectedItem_x                         0x50E0E0

//IString
#define IString__Append_x                                          0x4FE450

//Camera
#define CDisplay__cameraType_x                                     0xDFF5D8
#define EverQuest__Cameras_x                                       0xEC2AFC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517000
#define LootFiltersManager__GetItemFilterData_x                    0x516910
#define LootFiltersManager__RemoveItemLootFilter_x                 0x516940
#define LootFiltersManager__SetItemLootFilter_x                    0x516B60

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C5730

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A32E0
#define CResolutionHandler__GetWindowedStyle_x                     0x680AB0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x714250

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E6770
#define CDistillerInfo__Instance_x                                 0x8E6710

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7344E0
#define CGroupWnd__UpdateDisplay_x                                 0x733840

//ItemBase
#define ItemBase__IsLore_x                                         0x8A75C0
#define ItemBase__IsLoreEquipped_x                                 0x8A7640

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D92A0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D93E0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D9440

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6760B0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x679A30

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x504C50

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1F00
#define FactionManagerClient__HandleFactionMessage_x               0x4F2570
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2B30
#define FactionManagerClient__GetMaxFaction_x                      0x4F2B4F
#define FactionManagerClient__GetMinFaction_x                      0x4F2B00

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FCA20

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92C8C0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BEF0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FCE60

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x561050

//CTargetManager
#define CTargetManager__Get_x                                      0x68CAE0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6760B0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8F60

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AC920

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF60190

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
