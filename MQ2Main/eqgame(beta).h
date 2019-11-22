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
#define __ExpectedVersionDate                                     "Nov 22 2019"
#define __ExpectedVersionTime                                     "04:23:56"
#define __ActualVersionDate_x                                      0xB092A4
#define __ActualVersionTime_x                                      0xB09298
#define __ActualVersionBuild_x                                     0xAF4F74

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62E760
#define __MemChecker1_x                                            0x9017D0
#define __MemChecker2_x                                            0x6BCA80
#define __MemChecker3_x                                            0x6BC9D0
#define __MemChecker4_x                                            0x8583A0
#define __EncryptPad0_x                                            0xC3F3E8
#define __EncryptPad1_x                                            0xC9D5E8
#define __EncryptPad2_x                                            0xC4FC80
#define __EncryptPad3_x                                            0xC4F880
#define __EncryptPad4_x                                            0xC8DC00
#define __EncryptPad5_x                                            0xF691E0
#define __AC1_x                                                    0x8150E6
#define __AC2_x                                                    0x5E874F
#define __AC3_x                                                    0x5EFE4F
#define __AC4_x                                                    0x5F3E20
#define __AC5_x                                                    0x5FA12F
#define __AC6_x                                                    0x5FE746
#define __AC7_x                                                    0x5E81C0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191DEC

// Direct Input
#define DI8__Main_x                                                0xF69208
#define DI8__Keyboard_x                                            0xF6920C
#define DI8__Mouse_x                                               0xF691EC
#define DI8__Mouse_Copy_x                                          0xEC23EC
#define DI8__Mouse_Check_x                                         0xF66D34
#define __AutoSkillArray_x                                         0xEC3304
#define __Attack_x                                                 0xF6112B
#define __Autofire_x                                               0xF6112C
#define __BindList_x                                               0xC2DE20
#define g_eqCommandStates_x                                        0xC2EBA0
#define __Clicks_x                                                 0xEC24A4
#define __CommandList_x                                            0xC2F760
#define __CurrentMapLabel_x                                        0xF79BAC
#define __CurrentSocial_x                                          0xC177CC
#define __DoAbilityList_x                                          0xEF8C4C
#define __do_loot_x                                                0x5B4180
#define __DrawHandler_x                                            0x15F8F20
#define __GroupCount_x                                             0xEB4DA2
#define __Guilds_x                                                 0xEB8BF8
#define __gWorld_x                                                 0xEB4BF0
#define __HWnd_x                                                   0xF691F0
#define __heqmain_x                                                0xF691C8
#define __InChatMode_x                                             0xEC23D4
#define __LastTell_x                                               0xEC4348
#define __LMouseHeldTime_x                                         0xEC2510
#define __Mouse_x                                                  0xF691F4
#define __MouseLook_x                                              0xEC246A
#define __MouseEventTime_x                                         0xF61C0C
#define __gpbCommandEvent_x                                        0xEB2690
#define __NetStatusToggle_x                                        0xEC246D
#define __PCNames_x                                                0xEC38F4
#define __RangeAttackReady_x                                       0xEC35E8
#define __RMouseHeldTime_x                                         0xEC250C
#define __RunWalkState_x                                           0xEC23D8
#define __ScreenMode_x                                             0xE00034
#define __ScreenX_x                                                0xEC238C
#define __ScreenY_x                                                0xEC2388
#define __ScreenXMax_x                                             0xEC2390
#define __ScreenYMax_x                                             0xEC2394
#define __ServerHost_x                                             0xEB28C3
#define __ServerName_x                                             0xEF8C0C
#define __ShiftKeyDown_x                                           0xEC2A64
#define __ShowNames_x                                              0xEC37A4
#define __Socials_x                                                0xEF8D0C
#define __SubscriptionType_x                                       0xFBE0B0
#define __TargetAggroHolder_x                                      0xF7C560
#define __ZoneType_x                                               0xEC2868
#define __GroupAggro_x                                             0xF7C5A0
#define __LoginName_x                                              0xF6995C
#define __Inviter_x                                                0xF610A8
#define __AttackOnAssist_x                                         0xEC3760
#define __UseTellWindows_x                                         0xEC3A90
#define __gfMaxZoomCameraDistance_x                                0xAFEC08
#define __gfMaxCameraDistance_x                                    0xB2B154
#define __pulAutoRun_x                                             0xEC2488
#define __pulForward_x                                             0xEC3AC8
#define __pulBackward_x                                            0xEC3ACC
#define __pulTurnRight_x                                           0xEC3AD0
#define __pulTurnLeft_x                                            0xEC3AD4
#define __pulStrafeLeft_x                                          0xEC3AD8
#define __pulStrafeRight_x                                         0xEC3ADC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB4F98
#define instEQZoneInfo_x                                           0xEC2660
#define pinstActiveBanker_x                                        0xEB26A8
#define pinstActiveCorpse_x                                        0xEB26A0
#define pinstActiveGMaster_x                                       0xEB26A4
#define pinstActiveMerchant_x                                      0xEB269C
#define pinstAltAdvManager_x                                       0xE011C8
#define pinstBandageTarget_x                                       0xEB26B8
#define pinstCamActor_x                                            0xE00028
#define pinstCDBStr_x                                              0xDFFEE4
#define pinstCDisplay_x                                            0xEB4BEC
#define pinstCEverQuest_x                                          0xF69220
#define pinstEverQuestInfo_x                                       0xEC2380
#define pinstCharData_x                                            0xEB4D84
#define pinstCharSpawn_x                                           0xEB26F0
#define pinstControlledMissile_x                                   0xEB2BDC
#define pinstControlledPlayer_x                                    0xEB26F0
#define pinstCResolutionHandler_x                                  0x15F9150
#define pinstCSidlManager_x                                        0x15F80E8
#define pinstCXWndManager_x                                        0x15F80E4
#define instDynamicZone_x                                          0xEB8AD0
#define pinstDZMember_x                                            0xEB8BE0
#define pinstDZTimerInfo_x                                         0xEB8BE4
#define pinstEqLogin_x                                             0xF692A8
#define instEQMisc_x                                               0xDFFE28
#define pinstEQSoundManager_x                                      0xE02198
#define pinstEQSpellStrings_x                                      0xCC2898
#define instExpeditionLeader_x                                     0xEB8B1A
#define instExpeditionName_x                                       0xEB8B5A
#define pinstGroup_x                                               0xEB4D9E
#define pinstImeManager_x                                          0x15F80E0
#define pinstLocalPlayer_x                                         0xEB2698
#define pinstMercenaryData_x                                       0xF636FC
#define pinstMercenaryStats_x                                      0xF7C6AC
#define pinstModelPlayer_x                                         0xEB26B0
#define pinstPCData_x                                              0xEB4D84
#define pinstSkillMgr_x                                            0xF65868
#define pinstSpawnManager_x                                        0xF64310
#define pinstSpellManager_x                                        0xF65A88
#define pinstSpellSets_x                                           0xF59D54
#define pinstStringTable_x                                         0xEB4D88
#define pinstSwitchManager_x                                       0xEB2538
#define pinstTarget_x                                              0xEB26EC
#define pinstTargetObject_x                                        0xEB2778
#define pinstTargetSwitch_x                                        0xEB2BE4
#define pinstTaskMember_x                                          0xDFFCB8
#define pinstTrackTarget_x                                         0xEB26F4
#define pinstTradeTarget_x                                         0xEB26AC
#define instTributeActive_x                                        0xDFFE49
#define pinstViewActor_x                                           0xE00024
#define pinstWorldData_x                                           0xEB2BD8
#define pinstZoneAddr_x                                            0xEC2900
#define pinstPlayerPath_x                                          0xF643A8
#define pinstTargetIndicator_x                                     0xF65CF0
#define EQObject_Top_x                                             0xEB2694
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE007B0
#define pinstCAchievementsWnd_x                                    0xE007AC
#define pinstCActionsWnd_x                                         0xE002FC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFFFE0
#define pinstCAdvancedLootWnd_x                                    0xDFFFA4
#define pinstCAdventureLeaderboardWnd_x                            0xF73380
#define pinstCAdventureRequestWnd_x                                0xF73430
#define pinstCAdventureStatsWnd_x                                  0xF734E0
#define pinstCAggroMeterWnd_x                                      0xE00064
#define pinstCAlarmWnd_x                                           0xE0080C
#define pinstCAlertHistoryWnd_x                                    0xDFFFFC
#define pinstCAlertStackWnd_x                                      0xE00814
#define pinstCAlertWnd_x                                           0xDFFF84
#define pinstCAltStorageWnd_x                                      0xF73840
#define pinstCAudioTriggersWindow_x                                0xCB4BC8
#define pinstCAuraWnd_x                                            0xE0001C
#define pinstCAvaZoneWnd_x                                         0xE00070
#define pinstCBandolierWnd_x                                       0xE0005C
#define pinstCBankWnd_x                                            0xE00018
#define pinstCBarterMerchantWnd_x                                  0xF74A80
#define pinstCBarterSearchWnd_x                                    0xF74B30
#define pinstCBarterWnd_x                                          0xF74BE0
#define pinstCBazaarConfirmationWnd_x                              0xE007D8
#define pinstCBazaarSearchWnd_x                                    0xE000B0
#define pinstCBazaarWnd_x                                          0xE007F4
#define pinstCBlockedBuffWnd_x                                     0xE00020
#define pinstCBlockedPetBuffWnd_x                                  0xE00058
#define pinstCBodyTintWnd_x                                        0xE0030C
#define pinstCBookWnd_x                                            0xE00088
#define pinstCBreathWnd_x                                          0xE007C8
#define pinstCBuffWindowNORMAL_x                                   0xE00000
#define pinstCBuffWindowSHORT_x                                    0xE00004
#define pinstCBugReportWnd_x                                       0xE00010
#define pinstCButtonWnd_x                                          0x15F8350
#define pinstCCastingWnd_x                                         0xE0007C
#define pinstCCastSpellWnd_x                                       0xE007C4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE007F8
#define pinstCChatWindowManager_x                                  0xF756A0
#define pinstCClaimWnd_x                                           0xF757F8
#define pinstCColorPickerWnd_x                                     0xE00304
#define pinstCCombatAbilityWnd_x                                   0xE00804
#define pinstCCombatSkillsSelectWnd_x                              0xDFFF8C
#define pinstCCompassWnd_x                                         0xE00300
#define pinstCConfirmationDialog_x                                 0xF7A6F8
#define pinstCContainerMgr_x                                       0xE007EC
#define pinstCContextMenuManager_x                                 0x15F80A0
#define pinstCCursorAttachment_x                                   0xE0006C
#define pinstCDynamicZoneWnd_x                                     0xF75DC0
#define pinstCEditLabelWnd_x                                       0xDFFFF8
#define pinstCEQMainWnd_x                                          0xF76008
#define pinstCEventCalendarWnd_x                                   0xE00074
#define pinstCExtendedTargetWnd_x                                  0xE0004C
#define pinstCFacePick_x                                           0xDFFF9C
#define pinstCFactionWnd_x                                         0xE007E8
#define pinstCFellowshipWnd_x                                      0xF76208
#define pinstCFileSelectionWnd_x                                   0xE00078
#define pinstCFindItemWnd_x                                        0xE007D4
#define pinstCFindLocationWnd_x                                    0xF76360
#define pinstCFriendsWnd_x                                         0xDFFFA0
#define pinstCGemsGameWnd_x                                        0xE007E4
#define pinstCGiveWnd_x                                            0xE00810
#define pinstCGroupSearchFiltersWnd_x                              0xE00080
#define pinstCGroupSearchWnd_x                                     0xF76758
#define pinstCGroupWnd_x                                           0xF76808
#define pinstCGuildBankWnd_x                                       0xEC3744
#define pinstCGuildCreationWnd_x                                   0xF76968
#define pinstCGuildMgmtWnd_x                                       0xF76A18
#define pinstCharacterCreation_x                                   0xDFFF94
#define pinstCHelpWnd_x                                            0xDFFFD8
#define pinstCHeritageSelectionWnd_x                               0xDFFFA8
#define pinstCHotButtonWnd_x                                       0xF78B70
#define pinstCHotButtonWnd1_x                                      0xF78B70
#define pinstCHotButtonWnd2_x                                      0xF78B74
#define pinstCHotButtonWnd3_x                                      0xF78B78
#define pinstCHotButtonWnd4_x                                      0xF78B7C
#define pinstCIconSelectionWnd_x                                   0xE00068
#define pinstCInspectWnd_x                                         0xDFFFD4
#define pinstCInventoryWnd_x                                       0xDFFFAC
#define pinstCInvSlotMgr_x                                         0xE007A8
#define pinstCItemDisplayManager_x                                 0xF79100
#define pinstCItemExpTransferWnd_x                                 0xF79230
#define pinstCItemOverflowWnd_x                                    0xE000B8
#define pinstCJournalCatWnd_x                                      0xE0008C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE00050
#define pinstCKeyRingWnd_x                                         0xDFFFF4
#define pinstCLargeDialogWnd_x                                     0xF7B378
#define pinstCLayoutCopyWnd_x                                      0xF79580
#define pinstCLFGuildWnd_x                                         0xF79630
#define pinstCLoadskinWnd_x                                        0xE007F0
#define pinstCLootFiltersCopyWnd_x                                 0xCD11C0
#define pinstCLootFiltersWnd_x                                     0xE00818
#define pinstCLootSettingsWnd_x                                    0xDFFF98
#define pinstCLootWnd_x                                            0xE00090
#define pinstCMailAddressBookWnd_x                                 0xE007B8
#define pinstCMailCompositionWnd_x                                 0xE0032C
#define pinstCMailIgnoreListWnd_x                                  0xE007BC
#define pinstCMailWnd_x                                            0xE002F8
#define pinstCManageLootWnd_x                                      0xE01678
#define pinstCMapToolbarWnd_x                                      0xDFFFDC
#define pinstCMapViewWnd_x                                         0xDFFFB8
#define pinstCMarketplaceWnd_x                                     0xDFFF80
#define pinstCMerchantWnd_x                                        0xE00094
#define pinstCMIZoneSelectWnd_x                                    0xF79E68
#define pinstCMusicPlayerWnd_x                                     0xE0009C
#define pinstCNameChangeMercWnd_x                                  0xE007D0
#define pinstCNameChangePetWnd_x                                   0xE007B4
#define pinstCNameChangeWnd_x                                      0xE007E0
#define pinstCNoteWnd_x                                            0xDFFFBC
#define pinstCObjectPreviewWnd_x                                   0xDFFF90
#define pinstCOptionsWnd_x                                         0xDFFFC4
#define pinstCPetInfoWnd_x                                         0xE000C0
#define pinstCPetitionQWnd_x                                       0xE0039C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE00310
#define pinstCPlayerWnd_x                                          0xE000C4
#define pinstCPopupWndManager_x                                    0xF7A6F8
#define pinstCProgressionSelectionWnd_x                            0xF7A7A8
#define pinstCPurchaseGroupWnd_x                                   0xDFFFC8
#define pinstCPurchaseWnd_x                                        0xDFFFB0
#define pinstCPvPLeaderboardWnd_x                                  0xF7A858
#define pinstCPvPStatsWnd_x                                        0xF7A908
#define pinstCQuantityWnd_x                                        0xE00054
#define pinstCRaceChangeWnd_x                                      0xE00808
#define pinstCRaidOptionsWnd_x                                     0xE00084
#define pinstCRaidWnd_x                                            0xE00398
#define pinstCRealEstateItemsWnd_x                                 0xE007A4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE00098
#define pinstCRealEstateManageWnd_x                                0xDFFFD0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFFFF0
#define pinstCRealEstatePlotSearchWnd_x                            0xE00014
#define pinstCRealEstatePurchaseWnd_x                              0xE00048
#define pinstCRespawnWnd_x                                         0xE00044
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE007C0
#define pinstCSendMoneyWnd_x                                       0xDFFF88
#define pinstCServerListWnd_x                                      0xE00060
#define pinstCSkillsSelectWnd_x                                    0xE007FC
#define pinstCSkillsWnd_x                                          0xE007DC
#define pinstCSocialEditWnd_x                                      0xDFFFEC
#define pinstCSocialWnd_x                                          0xE007CC
#define pinstCSpellBookWnd_x                                       0xE00800
#define pinstCStoryWnd_x                                           0xE000D0
#define pinstCTargetOfTargetWnd_x                                  0xF7C730
#define pinstCTargetWnd_x                                          0xE00040
#define pinstCTaskOverlayWnd_x                                     0xDFFFC0
#define pinstCTaskSelectWnd_x                                      0xF7C888
#define pinstCTaskManager_x                                        0xCD1B00
#define pinstCTaskTemplateSelectWnd_x                              0xF7C938
#define pinstCTaskWnd_x                                            0xF7C9E8
#define pinstCTextEntryWnd_x                                       0xE00008
#define pinstCTimeLeftWnd_x                                        0xE000F4
#define pinstCTipWndCONTEXT_x                                      0xF7CBEC
#define pinstCTipWndOFDAY_x                                        0xF7CBE8
#define pinstCTitleWnd_x                                           0xF7CC98
#define pinstCTrackingWnd_x                                        0xDFFFB4
#define pinstCTradeskillWnd_x                                      0xF7CE00
#define pinstCTradeWnd_x                                           0xE0031C
#define pinstCTrainWnd_x                                           0xE00314
#define pinstCTributeBenefitWnd_x                                  0xF7D000
#define pinstCTributeMasterWnd_x                                   0xF7D0B0
#define pinstCTributeTrophyWnd_x                                   0xF7D160
#define pinstCVideoModesWnd_x                                      0xE000DC
#define pinstCVoiceMacroWnd_x                                      0xF66458
#define pinstCVoteResultsWnd_x                                     0xE00394
#define pinstCVoteWnd_x                                            0xE00308
#define pinstCWebManager_x                                         0xF66AD4
#define pinstCZoneGuideWnd_x                                       0xDFFFCC
#define pinstCZonePathWnd_x                                        0xDFFFE4

#define pinstEQSuiteTextureLoader_x                                0xC9F0C0
#define pinstItemIconCache_x                                       0xF75FC0
#define pinstLootFiltersManager_x                                  0xCD1270
#define pinstRewardSelectionWnd_x                                  0xF7B050

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AF5E0
#define __CastRay2_x                                               0x5AF630
#define __ConvertItemTags_x                                        0x5CB180
#define __CleanItemTags_x                                          0x47D170
#define __DoesFileExist_x                                          0x904880
#define __EQGetTime_x                                              0x9012A0
#define __ExecuteCmd_x                                             0x5A7E50
#define __FixHeading_x                                             0x99BE90
#define __GameLoop_x                                               0x6BBC70
#define __get_bearing_x                                            0x5AF150
#define __get_melee_range_x                                        0x5AF820
#define __GetAnimationCache_x                                      0x720F00
#define __GetGaugeValueFromEQ_x                                    0x813590
#define __GetLabelFromEQ_x                                         0x815070
#define __GetXTargetType_x                                         0x99D870
#define __HandleMouseWheel_x                                       0x6BCB30
#define __HeadingDiff_x                                            0x99BF00
#define __HelpPath_x                                               0xF617FC
#define __LoadFrontEnd_x                                           0x6B8F90
#define __NewUIINI_x                                               0x813260
#define __ProcessGameEvents_x                                      0x60FFB0
#define __ProcessMouseEvent_x                                      0x60F770
#define __SaveColors_x                                             0x551F00
#define __STMLToText_x                                             0x93F220
#define __ToggleKeyRingItem_x                                      0x5150E0
#define CMemoryMappedFile__SetFile_x                               0xA8B270
#define CrashDetected_x                                            0x6BAA30
#define DrawNetStatus_x                                            0x63BBE0
#define Expansion_HoT_x                                            0xEC374C
#define Teleport_Table_Size_x                                      0xEB2780
#define Teleport_Table_x                                           0xEB2BE8
#define Util__FastTime_x                                           0x900E70

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
#define AltAdvManager__GetCalculatedTimer_x                        0x559B60
#define AltAdvManager__IsAbilityReady_x                            0x558A90
#define AltAdvManager__GetAAById_x                                 0x558C90
#define AltAdvManager__CanTrainAbility_x                           0x558D00
#define AltAdvManager__CanSeeAbility_x                             0x559060

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9F90
#define CharacterZoneClient__HasSkill_x                            0x4D4E80
#define CharacterZoneClient__MakeMeVisible_x                       0x4D65A0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE320
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA920
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8F10
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8FF0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D90D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3120
#define CharacterZoneClient__BardCastBard_x                        0x4C5C80
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA9F0
#define CharacterZoneClient__GetEffect_x                           0x4BA860
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4170
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4240
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4290
#define CharacterZoneClient__CalcAffectChange_x                    0x4C43E0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C45B0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2760
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7500
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6F80

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E2630
#define CBankWnd__WndNotification_x                                0x6E2410

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EFDA0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61E5D0
#define CButtonWnd__CButtonWnd_x                                   0x93B5E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70FF40
#define CChatManager__InitContextMenu_x                            0x7090A0
#define CChatManager__FreeChatWindow_x                             0x70EA80
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8590
#define CChatManager__SetLockedActiveChatWindow_x                  0x70FBC0
#define CChatManager__CreateChatWindow_x                           0x70F0C0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E86A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94FC40
#define CContextMenu__dCContextMenu_x                              0x94FE70
#define CContextMenu__AddMenuItem_x                                0x94FE80
#define CContextMenu__RemoveMenuItem_x                             0x950190
#define CContextMenu__RemoveAllMenuItems_x                         0x9501B0
#define CContextMenu__CheckMenuItem_x                              0x950230
#define CContextMenu__SetMenuItem_x                                0x9500B0
#define CContextMenu__AddSeparator_x                               0x950010

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9507D0
#define CContextMenuManager__RemoveMenu_x                          0x950840
#define CContextMenuManager__PopupMenu_x                           0x950900
#define CContextMenuManager__Flush_x                               0x950770
#define CContextMenuManager__GetMenu_x                             0x49B4B0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71B710

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DC9D0
#define CChatService__GetFriendName_x                              0x8DC9E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7107F0
#define CChatWindow__Clear_x                                       0x711AB0
#define CChatWindow__WndNotification_x                             0x712240
#define CChatWindow__AddHistory_x                                  0x711370

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94D0B0
#define CComboWnd__Draw_x                                          0x94C5B0
#define CComboWnd__GetCurChoice_x                                  0x94CEF0
#define CComboWnd__GetListRect_x                                   0x94CA60
#define CComboWnd__GetTextRect_x                                   0x94D120
#define CComboWnd__InsertChoice_x                                  0x94CBF0
#define CComboWnd__SetColors_x                                     0x94CBC0
#define CComboWnd__SetChoice_x                                     0x94CEC0
#define CComboWnd__GetItemCount_x                                  0x94CF00
#define CComboWnd__GetCurChoiceText_x                              0x94CF40
#define CComboWnd__GetChoiceText_x                                 0x94CF10
#define CComboWnd__InsertChoiceAtIndex_x                           0x94CC80

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x719100
#define CContainerWnd__vftable_x                                   0xB12494
#define CContainerWnd__SetContainer_x                              0x71A660

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54C940
#define CDisplay__PreZoneMainUI_x                                  0x54C950
#define CDisplay__CleanGameUI_x                                    0x551CC0
#define CDisplay__GetClickedActor_x                                0x544C60
#define CDisplay__GetUserDefinedColor_x                            0x53D320
#define CDisplay__GetWorldFilePath_x                               0x5466D0
#define CDisplay__is3dON_x                                         0x5418C0
#define CDisplay__ReloadUI_x                                       0x54BDD0
#define CDisplay__WriteTextHD2_x                                   0x5416B0
#define CDisplay__TrueDistance_x                                   0x548390
#define CDisplay__SetViewActor_x                                   0x544580
#define CDisplay__GetFloorHeight_x                                 0x541980
#define CDisplay__SetRenderWindow_x                                0x5402E0
#define CDisplay__ToggleScreenshotMode_x                           0x544050

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96FA30

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x95319F
#define CEditWnd__GetCharIndexPt_x                                 0x9540E0
#define CEditWnd__GetDisplayString_x                               0x953F80
#define CEditWnd__GetHorzOffset_x                                  0x9527E0
#define CEditWnd__GetLineForPrintableChar_x                        0x955280
#define CEditWnd__GetSelStartPt_x                                  0x954390
#define CEditWnd__GetSTMLSafeText_x                                0x953DA0
#define CEditWnd__PointFromPrintableChar_x                         0x954EB0
#define CEditWnd__SelectableCharFromPoint_x                        0x955020
#define CEditWnd__SetEditable_x                                    0x954460
#define CEditWnd__SetWindowTextA_x                                 0x953B20

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FDC20
#define CEverQuest__ClickedPlayer_x                                0x5EFC30
#define CEverQuest__CreateTargetIndicator_x                        0x60D250
#define CEverQuest__DeleteTargetIndicator_x                        0x60D2E0
#define CEverQuest__DoTellWindow_x                                 0x4E8780
#define CEverQuest__OutputTextToLog_x                              0x4E8A00
#define CEverQuest__DropHeldItemOnGround_x                         0x5E4C70
#define CEverQuest__dsp_chat_x                                     0x4E8D90
#define CEverQuest__trimName_x                                     0x609530
#define CEverQuest__Emote_x                                        0x5FE480
#define CEverQuest__EnterZone_x                                    0x5F8400
#define CEverQuest__GetBodyTypeDesc_x                              0x602DF0
#define CEverQuest__GetClassDesc_x                                 0x603430
#define CEverQuest__GetClassThreeLetterCode_x                      0x603A30
#define CEverQuest__GetDeityDesc_x                                 0x60BB90
#define CEverQuest__GetLangDesc_x                                  0x603BF0
#define CEverQuest__GetRaceDesc_x                                  0x603410
#define CEverQuest__InterpretCmd_x                                 0x60C160
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E8E70
#define CEverQuest__LMouseUp_x                                     0x5E7200
#define CEverQuest__RightClickedOnPlayer_x                         0x5E9750
#define CEverQuest__RMouseUp_x                                     0x5E8180
#define CEverQuest__SetGameState_x                                 0x5E4A00
#define CEverQuest__UPCNotificationFlush_x                         0x609430
#define CEverQuest__IssuePetCommand_x                              0x604FF0
#define CEverQuest__ReportSuccessfulHit_x                          0x5FF870

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72B100
#define CGaugeWnd__CalcLinesFillRect_x                             0x72B160
#define CGaugeWnd__Draw_x                                          0x72A790

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF280
#define CGuild__GetGuildName_x                                     0x4AE360
#define CGuild__GetGuildIndex_x                                    0x4AE6F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x746510

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61E990

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x753470
#define CInvSlotMgr__MoveItem_x                                    0x7521E0
#define CInvSlotMgr__SelectSlot_x                                  0x753540

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x750A60
#define CInvSlot__SliderComplete_x                                 0x74E7D0
#define CInvSlot__GetItemBase_x                                    0x74E170
#define CInvSlot__UpdateItem_x                                     0x74E2E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x754FA0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x754140
#define CInvSlotWnd__HandleLButtonUp_x                             0x754B20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80E940
#define CItemDisplayWnd__UpdateStrings_x                           0x763550
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75D330
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75D830
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x763B50
#define CItemDisplayWnd__AboutToShow_x                             0x7631A0
#define CItemDisplayWnd__WndNotification_x                         0x764C20
#define CItemDisplayWnd__RequestConvertItem_x                      0x7646F0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x762200
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x762FC0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8474D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x769120

// CLabel 
#define CLabel__Draw_x                                             0x76EB70

// CListWnd
#define CListWnd__CListWnd_x                                       0x925A00
#define CListWnd__dCListWnd_x                                      0x925D20
#define CListWnd__AddColumn_x                                      0x92A1A0
#define CListWnd__AddColumn1_x                                     0x92A1F0
#define CListWnd__AddLine_x                                        0x92A580
#define CListWnd__AddString_x                                      0x92A380
#define CListWnd__CalculateFirstVisibleLine_x                      0x929F60
#define CListWnd__CalculateVSBRange_x                              0x929D50
#define CListWnd__ClearSel_x                                       0x92AD60
#define CListWnd__ClearAllSel_x                                    0x92ADC0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92B7D0
#define CListWnd__Compare_x                                        0x929680
#define CListWnd__Draw_x                                           0x925E50
#define CListWnd__DrawColumnSeparators_x                           0x928650
#define CListWnd__DrawHeader_x                                     0x928AC0
#define CListWnd__DrawItem_x                                       0x928FC0
#define CListWnd__DrawLine_x                                       0x9287C0
#define CListWnd__DrawSeparator_x                                  0x9286F0
#define CListWnd__EnableLine_x                                     0x927F20
#define CListWnd__EnsureVisible_x                                  0x92B6F0
#define CListWnd__ExtendSel_x                                      0x92AC90
#define CListWnd__GetColumnTooltip_x                               0x927A60
#define CListWnd__GetColumnMinWidth_x                              0x927AD0
#define CListWnd__GetColumnWidth_x                                 0x9279D0
#define CListWnd__GetCurSel_x                                      0x927360
#define CListWnd__GetItemAtPoint_x                                 0x9281A0
#define CListWnd__GetItemAtPoint1_x                                0x928210
#define CListWnd__GetItemData_x                                    0x9273E0
#define CListWnd__GetItemHeight_x                                  0x9277A0
#define CListWnd__GetItemIcon_x                                    0x927570
#define CListWnd__GetItemRect_x                                    0x928010
#define CListWnd__GetItemText_x                                    0x927420
#define CListWnd__GetSelList_x                                     0x92AE10
#define CListWnd__GetSeparatorRect_x                               0x928450
#define CListWnd__InsertLine_x                                     0x92A970
#define CListWnd__RemoveLine_x                                     0x92AAC0
#define CListWnd__SetColors_x                                      0x929D20
#define CListWnd__SetColumnJustification_x                         0x929A50
#define CListWnd__SetColumnWidth_x                                 0x929970
#define CListWnd__SetCurSel_x                                      0x92ABD0
#define CListWnd__SetItemColor_x                                   0x92B3A0
#define CListWnd__SetItemData_x                                    0x92B360
#define CListWnd__SetItemText_x                                    0x92AF80
#define CListWnd__ShiftColumnSeparator_x                           0x929B10
#define CListWnd__Sort_x                                           0x929800
#define CListWnd__ToggleSel_x                                      0x92AC00
#define CListWnd__SetColumnsSizable_x                              0x929BC0
#define CListWnd__SetItemWnd_x                                     0x92B230
#define CListWnd__GetItemWnd_x                                     0x9275C0
#define CListWnd__SetItemIcon_x                                    0x92B000
#define CListWnd__CalculateCustomWindowPositions_x                 0x92A060
#define CListWnd__SetVScrollPos_x                                  0x929950

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x784290
#define CMapViewWnd__GetWorldCoordinates_x                         0x7829A0
#define CMapViewWnd__HandleLButtonDown_x                           0x77F9E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A43D0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A4CB0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A51D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A8140
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A2F50
#define CMerchantWnd__SelectBuySellSlot_x                          0x7ADCF0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A3FF0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AA500
#define CPacketScrambler__hton_x                                   0x8AA4F0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x944850
#define CSidlManager__FindScreenPieceTemplate_x                    0x944C60
#define CSidlManager__FindScreenPieceTemplate1_x                   0x944A50
#define CSidlManager__CreateLabel_x                                0x805D80
#define CSidlManager__CreateXWndFromTemplate_x                     0x947BC0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x947D90
#define CSidlManager__CreateXWnd_x                                 0x805CB0
#define CSidlManager__CreateHotButtonWnd_x                         0x806270

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x941340
#define CSidlScreenWnd__CalculateVSBRange_x                        0x941240
#define CSidlScreenWnd__ConvertToRes_x                             0x966A70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x940CE0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9409D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x940AA0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x940B70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9417E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x941CB0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9419D0
#define CSidlScreenWnd__Init1_x                                    0x9405D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x941D00
#define CSidlScreenWnd__LoadIniListWnd_x                           0x942830
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93F9D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9423B0
#define CSidlScreenWnd__StoreIniVis_x                              0x942710
#define CSidlScreenWnd__WndNotification_x                          0x9416F0
#define CSidlScreenWnd__GetChildItem_x                             0x941C30
#define CSidlScreenWnd__HandleLButtonUp_x                          0x931500
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F7F70

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x683000
#define CSkillMgr__GetSkillCap_x                                   0x6831E0
#define CSkillMgr__GetNameToken_x                                  0x682780
#define CSkillMgr__IsActivatedSkill_x                              0x6828C0
#define CSkillMgr__IsCombatSkill_x                                 0x682800

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9515C0
#define CSliderWnd__SetValue_x                                     0x951430
#define CSliderWnd__SetNumTicks_x                                  0x951490

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80BDD0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x959DC0
#define CStmlWnd__CalculateHSBRange_x                              0x95AEA0
#define CStmlWnd__CalculateVSBRange_x                              0x95AE10
#define CStmlWnd__CanBreakAtCharacter_x                            0x95F1D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95FE60
#define CStmlWnd__ForceParseNow_x                                  0x95A360
#define CStmlWnd__GetNextTagPiece_x                                0x95F130
#define CStmlWnd__GetSTMLText_x                                    0x504A60
#define CStmlWnd__GetVisibleText_x                                 0x95A380
#define CStmlWnd__InitializeWindowVariables_x                      0x95FCB0
#define CStmlWnd__MakeStmlColorTag_x                               0x959430
#define CStmlWnd__MakeWndNotificationTag_x                         0x9594A0
#define CStmlWnd__SetSTMLText_x                                    0x9584E0
#define CStmlWnd__StripFirstSTMLLines_x                            0x960F60
#define CStmlWnd__UpdateHistoryString_x                            0x960070

// CTabWnd 
#define CTabWnd__Draw_x                                            0x957630
#define CTabWnd__DrawCurrentPage_x                                 0x957D60
#define CTabWnd__DrawTab_x                                         0x957A80
#define CTabWnd__GetCurrentPage_x                                  0x956E40
#define CTabWnd__GetPageInnerRect_x                                0x957080
#define CTabWnd__GetTabInnerRect_x                                 0x956FC0
#define CTabWnd__GetTabRect_x                                      0x956E70
#define CTabWnd__InsertPage_x                                      0x957290
#define CTabWnd__SetPage_x                                         0x957100
#define CTabWnd__SetPageRect_x                                     0x957570
#define CTabWnd__UpdatePage_x                                      0x957940
#define CTabWnd__GetPageFromTabIndex_x                             0x9579C0
#define CTabWnd__GetCurrentTabIndex_x                              0x956E30

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7694F0
#define CPageWnd__SetTabText_x                                     0x956990

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8F00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92E3F0
#define CTextureFont__GetTextExtent_x                              0x92E5B0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B5E10
#define CHtmlComponentWnd__ValidateUri_x                           0x747F00
#define CHtmlWnd__SetClientCallbacks_x                             0x6239F0
#define CHtmlWnd__AddObserver_x                                    0x623A10
#define CHtmlWnd__RemoveObserver_x                                 0x623A70
#define Window__getProgress_x                                      0x85F980
#define Window__getStatus_x                                        0x85F9A0
#define Window__getURI_x                                           0x85F9B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96C4C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91B620

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E83D0
#define CXStr__CXStr1_x                                            0x924050
#define CXStr__CXStr3_x                                            0x8FD3A0
#define CXStr__dCXStr_x                                            0x478740
#define CXStr__operator_equal_x                                    0x8FD5D0
#define CXStr__operator_equal1_x                                   0x8FD610
#define CXStr__operator_plus_equal1_x                              0x8FE0A0
#define CXStr__SetString_x                                         0x8FFF90
#define CXStr__operator_char_p_x                                   0x8FDB10
#define CXStr__GetChar_x                                           0x8FF8E0
#define CXStr__Delete_x                                            0x8FF190
#define CXStr__GetUnicode_x                                        0x8FF950
#define CXStr__GetLength_x                                         0x47D520
#define CXStr__Mid_x                                               0x47D530
#define CXStr__Insert_x                                            0x8FF9B0
#define CXStr__FindNext_x                                          0x8FF600

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94F850
#define CXWnd__BringToTop_x                                        0x934BE0
#define CXWnd__Center_x                                            0x934760
#define CXWnd__ClrFocus_x                                          0x934580
#define CXWnd__Destroy_x                                           0x934620
#define CXWnd__DoAllDrawing_x                                      0x930CB0
#define CXWnd__DrawChildren_x                                      0x930C80
#define CXWnd__DrawColoredRect_x                                   0x9310F0
#define CXWnd__DrawTooltip_x                                       0x92F7E0
#define CXWnd__DrawTooltipAtPoint_x                                0x92F8A0
#define CXWnd__GetBorderFrame_x                                    0x930F50
#define CXWnd__GetChildWndAt_x                                     0x934C80
#define CXWnd__GetClientClipRect_x                                 0x932F10
#define CXWnd__GetScreenClipRect_x                                 0x932FE0
#define CXWnd__GetScreenRect_x                                     0x933170
#define CXWnd__GetTooltipRect_x                                    0x931140
#define CXWnd__GetWindowTextA_x                                    0x49CBB0
#define CXWnd__IsActive_x                                          0x931870
#define CXWnd__IsDescendantOf_x                                    0x933B20
#define CXWnd__IsReallyVisible_x                                   0x933B50
#define CXWnd__IsType_x                                            0x9352F0
#define CXWnd__Move_x                                              0x933BD0
#define CXWnd__Move1_x                                             0x933C80
#define CXWnd__ProcessTransition_x                                 0x934710
#define CXWnd__Refade_x                                            0x933F30
#define CXWnd__Resize_x                                            0x9341D0
#define CXWnd__Right_x                                             0x9349A0
#define CXWnd__SetFocus_x                                          0x934540
#define CXWnd__SetFont_x                                           0x9345B0
#define CXWnd__SetKeyTooltip_x                                     0x935100
#define CXWnd__SetMouseOver_x                                      0x932080
#define CXWnd__StartFade_x                                         0x933A00
#define CXWnd__GetChildItem_x                                      0x934DE0
#define CXWnd__SetParent_x                                         0x9338C0
#define CXWnd__Minimize_x                                          0x934240

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x967B00

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x937AC0
#define CXWndManager__DrawWindows_x                                0x937AE0
#define CXWndManager__GetKeyboardFlags_x                           0x93A280
#define CXWndManager__HandleKeyboardMsg_x                          0x939E40
#define CXWndManager__RemoveWnd_x                                  0x93A4A0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93AA10

// CDBStr
#define CDBStr__GetString_x                                        0x53C2B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB900
#define EQ_Character__Cur_HP_x                                     0x4D1EC0
#define EQ_Character__Cur_Mana_x                                   0x4D95D0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE970
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B23A0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B24F0
#define EQ_Character__GetHPRegen_x                                 0x4DF370
#define EQ_Character__GetEnduranceRegen_x                          0x4DF970
#define EQ_Character__GetManaRegen_x                               0x4DFDB0
#define EQ_Character__Max_Endurance_x                              0x649A50
#define EQ_Character__Max_HP_x                                     0x4D1CF0
#define EQ_Character__Max_Mana_x                                   0x649850
#define EQ_Character__doCombatAbility_x                            0x64BEA0
#define EQ_Character__UseSkill_x                                   0x4E1B80
#define EQ_Character__GetConLevel_x                                0x642B60
#define EQ_Character__IsExpansionFlag_x                            0x5A6630
#define EQ_Character__TotalEffect_x                                0x4C53C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF6C0
#define EQ_Character__SpellDuration_x                              0x4BF1F0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4C40
#define EQ_Character__GetBaseSkill_x                               0x4D5BE0
#define EQ_Character__CanUseItem_x                                 0x4D98E0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C9880

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65FF40

//PcClient
#define PcClient__PcClient_x                                       0x6402A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9560
#define CCharacterListWnd__EnterWorld_x                            0x4B8FA0
#define CCharacterListWnd__Quit_x                                  0x4B8CF0
#define CCharacterListWnd__UpdateList_x                            0x4B9130

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x624C40
#define EQ_Item__CreateItemTagString_x                             0x8A3CE0
#define EQ_Item__IsStackable_x                                     0x8A8880
#define EQ_Item__GetImageNum_x                                     0x8A5750
#define EQ_Item__CreateItemClient_x                                0x623E10
#define EQ_Item__GetItemValue_x                                    0x8A6A40
#define EQ_Item__ValueSellMerchant_x                               0x8AA0D0
#define EQ_Item__IsKeyRingItem_x                                   0x8A8180
#define EQ_Item__CanGoInBag_x                                      0x624D60
#define EQ_Item__IsEmpty_x                                         0x8A7CE0
#define EQ_Item__GetMaxItemCount_x                                 0x8A6E60
#define EQ_Item__GetHeldItem_x                                     0x8A5620
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A3660

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55A830
#define EQ_LoadingS__Array_x                                       0xC26B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64A3B0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B3320
#define EQ_PC__GetCombatAbility_x                                  0x8B3990
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B3A00
#define EQ_PC__GetItemRecastTimer_x                                0x64C420
#define EQ_PC__HasLoreItem_x                                       0x643370
#define EQ_PC__AlertInventoryChanged_x                             0x6424A0
#define EQ_PC__GetPcZoneClient_x                                   0x66E9E0
#define EQ_PC__RemoveMyAffect_x                                    0x64F660
#define EQ_PC__GetKeyRingItems_x                                   0x8B4290
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B4020
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B4590

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5ACB60
#define EQItemList__add_object_x                                   0x5DA450
#define EQItemList__add_item_x                                     0x5AD0C0
#define EQItemList__delete_item_x                                  0x5AD110
#define EQItemList__FreeItemList_x                                 0x5AD010

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538E40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6617C0
#define EQPlayer__dEQPlayer_x                                      0x654B10
#define EQPlayer__DoAttack_x                                       0x669680
#define EQPlayer__EQPlayer_x                                       0x6551D0
#define EQPlayer__SetNameSpriteState_x                             0x6594B0
#define EQPlayer__SetNameSpriteTint_x                              0x65A370
#define PlayerBase__HasProperty_j_x                                0x99A280
#define EQPlayer__IsTargetable_x                                   0x99A720
#define EQPlayer__CanSee_x                                         0x99A580
#define EQPlayer__CanSee1_x                                        0x99A650
#define PlayerBase__GetVisibilityLineSegment_x                     0x99A340

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66C480
#define PlayerZoneClient__GetLevel_x                               0x66EA20
#define PlayerZoneClient__IsValidTeleport_x                        0x5DB5C0
#define PlayerZoneClient__LegalPlayerRace_x                        0x553B80

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x664590
#define EQPlayerManager__GetSpawnByName_x                          0x664640
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6646D0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x628290
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x628310
#define KeypressHandler__AttachKeyToEqCommand_x                    0x628350
#define KeypressHandler__ClearCommandStateArray_x                  0x629760
#define KeypressHandler__HandleKeyDown_x                           0x629780
#define KeypressHandler__HandleKeyUp_x                             0x629820
#define KeypressHandler__SaveKeymapping_x                          0x629C70

// MapViewMap 
#define MapViewMap__Clear_x                                        0x780100
#define MapViewMap__SaveEx_x                                       0x7834C0
#define MapViewMap__SetZoom_x                                      0x787B80

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C76F0

// StringTable 
#define StringTable__getString_x                                   0x8C2500

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64F2D0
#define PcZoneClient__RemovePetEffect_x                            0x64F900
#define PcZoneClient__HasAlternateAbility_x                        0x649680
#define PcZoneClient__GetCurrentMod_x                              0x4E4C30
#define PcZoneClient__GetModCap_x                                  0x4E4B30
#define PcZoneClient__CanEquipItem_x                               0x649D50
#define PcZoneClient__GetItemByID_x                                0x64C8A0
#define PcZoneClient__GetItemByItemClass_x                         0x64C9F0
#define PcZoneClient__RemoveBuffEffect_x                           0x64F920
#define PcZoneClient__BandolierSwap_x                              0x64A960
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64C3C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E0150

//IconCache
#define IconCache__GetIcon_x                                       0x7207A0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7182A0
#define CContainerMgr__CloseContainer_x                            0x718570
#define CContainerMgr__OpenExperimentContainer_x                   0x718FF0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D8280

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61CDD0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x776640
#define CLootWnd__RequestLootSlot_x                                0x775870

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57A420
#define EQ_Spell__SpellAffects_x                                   0x57A890
#define EQ_Spell__SpellAffectBase_x                                0x57A650
#define EQ_Spell__IsStackable_x                                    0x4C9900
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C97E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6890
#define EQ_Spell__IsSPAStacking_x                                  0x57B6E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57ABF0
#define EQ_Spell__IsNoRemove_x                                     0x4C98E0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57B6F0
#define __IsResEffectSpell_x                                       0x4C8DE0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACFC0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D1EA0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81F070
#define CTargetWnd__WndNotification_x                              0x81E900
#define CTargetWnd__RefreshTargetBuffs_x                           0x81EBD0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81DA70

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x823670

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536850
#define CTaskManager__HandleMessage_x                              0x534CE0
#define CTaskManager__GetTaskStatus_x                              0x536900
#define CTaskManager__GetElementDescription_x                      0x536980

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5758F0
#define EqSoundManager__PlayScriptMp3_x                            0x575A50
#define EqSoundManager__SoundAssistPlay_x                          0x686F70
#define EqSoundManager__WaveInstancePlay_x                         0x6864E0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52A4E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x955EA0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562210
#define CAltAbilityData__GetMercMaxRank_x                          0x5621A0
#define CAltAbilityData__GetMaxRank_x                              0x557910

//CTargetRing
#define CTargetRing__Cast_x                                        0x61AEF0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C97C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x511650
#define CharacterBase__CreateItemIndex_x                           0x622FA0
#define CharacterBase__GetItemPossession_x                         0x4FD460
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DA490
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DA4F0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FF350
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FFB80
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FFC30

//messages
#define msg_spell_worn_off_x                                       0x59E910
#define msg_new_text_x                                             0x5936D0
#define __msgTokenTextParam_x                                      0x5A0E30
#define msgTokenText_x                                             0x5A1080

//SpellManager
#define SpellManager__vftable_x                                    0xAEC4DC
#define SpellManager__SpellManager_x                               0x68A2A0
#define Spellmanager__LoadTextSpells_x                             0x68AB90
#define SpellManager__GetSpellByGroupAndRank_x                     0x68A470

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99E160

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x511CD0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A4BF0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63BA40
#define ItemGlobalIndex__IsValidIndex_x                            0x511D30

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D2840
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D2AC0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76EEB0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71C9A0
#define CCursorAttachment__AttachToCursor1_x                       0x71C9E0
#define CCursorAttachment__Deactivate_x                            0x71D9D0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x948BE0
#define CSidlManagerBase__CreatePageWnd_x                          0x9483E0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x944670
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x944600

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x965BE0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9658A0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50EBF0
#define CFindItemWnd__WndNotification_x                            0x50F6D0
#define CFindItemWnd__Update_x                                     0x510240
#define CFindItemWnd__PickupSelectedItem_x                         0x50E440

//IString
#define IString__Append_x                                          0x4F01D0

//Camera
#define CDisplay__cameraType_x                                     0xE000F0
#define EverQuest__Cameras_x                                       0xEC3A9C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517470
#define LootFiltersManager__GetItemFilterData_x                    0x516D80
#define LootFiltersManager__RemoveItemLootFilter_x                 0x516DB0
#define LootFiltersManager__SetItemLootFilter_x                    0x516FD0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C6270

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A3DE0
#define CResolutionHandler__GetWindowedStyle_x                     0x681BF0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x714F50

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E77E0
#define CDistillerInfo__Instance_x                                 0x8E7780

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x735300
#define CGroupWnd__UpdateDisplay_x                                 0x734660

//ItemBase
#define ItemBase__IsLore_x                                         0x8A8230
#define ItemBase__IsLoreEquipped_x                                 0x8A82B0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DA3B0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DA4F0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DA550

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6770E0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67AA20

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505060

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1DA0
#define FactionManagerClient__HandleFactionMessage_x               0x4F2410
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2A10
#define FactionManagerClient__GetMaxFaction_x                      0x4F2A2F
#define FactionManagerClient__GetMinFaction_x                      0x4F29E0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD430

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92D440

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE90

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD6B0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5616D0

//CTargetManager
#define CTargetManager__Get_x                                      0x68DAC0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6770E0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8CC0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5ACFB0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF61130

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
