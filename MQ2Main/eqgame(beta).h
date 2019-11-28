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
#define __ExpectedVersionDate                                     "Nov 28 2019"
#define __ExpectedVersionTime                                     "04:22:22"
#define __ActualVersionDate_x                                      0xB092B8
#define __ActualVersionTime_x                                      0xB092AC
#define __ActualVersionBuild_x                                     0xAF4F7C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62EAE0
#define __MemChecker1_x                                            0x901860
#define __MemChecker2_x                                            0x6BCBB0
#define __MemChecker3_x                                            0x6BCB00
#define __MemChecker4_x                                            0x8585F0
#define __EncryptPad0_x                                            0xC3F3E8
#define __EncryptPad1_x                                            0xC9D5E8
#define __EncryptPad2_x                                            0xC4FC80
#define __EncryptPad3_x                                            0xC4F880
#define __EncryptPad4_x                                            0xC8DC00
#define __EncryptPad5_x                                            0xF691C0
#define __AC1_x                                                    0x815436
#define __AC2_x                                                    0x5E8B9F
#define __AC3_x                                                    0x5F029F
#define __AC4_x                                                    0x5F4270
#define __AC5_x                                                    0x5FA57F
#define __AC6_x                                                    0x5FEB96
#define __AC7_x                                                    0x5E8610
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191A2C

// Direct Input
#define DI8__Main_x                                                0xF691E8
#define DI8__Keyboard_x                                            0xF691EC
#define DI8__Mouse_x                                               0xF691CC
#define DI8__Mouse_Copy_x                                          0xEC23CC
#define DI8__Mouse_Check_x                                         0xF66D14
#define __AutoSkillArray_x                                         0xEC32E4
#define __Attack_x                                                 0xF6110B
#define __Autofire_x                                               0xF6110C
#define __BindList_x                                               0xC2DE20
#define g_eqCommandStates_x                                        0xC2EBA0
#define __Clicks_x                                                 0xEC2484
#define __CommandList_x                                            0xC2F760
#define __CurrentMapLabel_x                                        0xF79B8C
#define __CurrentSocial_x                                          0xC177CC
#define __DoAbilityList_x                                          0xEF8C2C
#define __do_loot_x                                                0x5B4540
#define __DrawHandler_x                                            0x15F8F00
#define __GroupCount_x                                             0xEB4D82
#define __Guilds_x                                                 0xEB8BD8
#define __gWorld_x                                                 0xEB4BD0
#define __HWnd_x                                                   0xF691D0
#define __heqmain_x                                                0xF691A8
#define __InChatMode_x                                             0xEC23B4
#define __LastTell_x                                               0xEC4328
#define __LMouseHeldTime_x                                         0xEC24F0
#define __Mouse_x                                                  0xF691D4
#define __MouseLook_x                                              0xEC244A
#define __MouseEventTime_x                                         0xF61BEC
#define __gpbCommandEvent_x                                        0xEB2670
#define __NetStatusToggle_x                                        0xEC244D
#define __PCNames_x                                                0xEC38D4
#define __RangeAttackReady_x                                       0xEC35C8
#define __RMouseHeldTime_x                                         0xEC24EC
#define __RunWalkState_x                                           0xEC23B8
#define __ScreenMode_x                                             0xE00014
#define __ScreenX_x                                                0xEC236C
#define __ScreenY_x                                                0xEC2368
#define __ScreenXMax_x                                             0xEC2370
#define __ScreenYMax_x                                             0xEC2374
#define __ServerHost_x                                             0xEB28A3
#define __ServerName_x                                             0xEF8BEC
#define __ShiftKeyDown_x                                           0xEC2A44
#define __ShowNames_x                                              0xEC3784
#define __Socials_x                                                0xEF8CEC
#define __SubscriptionType_x                                       0xFBE090
#define __TargetAggroHolder_x                                      0xF7C540
#define __ZoneType_x                                               0xEC2848
#define __GroupAggro_x                                             0xF7C580
#define __LoginName_x                                              0xF6993C
#define __Inviter_x                                                0xF61088
#define __AttackOnAssist_x                                         0xEC3740
#define __UseTellWindows_x                                         0xEC3A70
#define __gfMaxZoomCameraDistance_x                                0xAFEC18
#define __gfMaxCameraDistance_x                                    0xB2B154
#define __pulAutoRun_x                                             0xEC2468
#define __pulForward_x                                             0xEC3AA8
#define __pulBackward_x                                            0xEC3AAC
#define __pulTurnRight_x                                           0xEC3AB0
#define __pulTurnLeft_x                                            0xEC3AB4
#define __pulStrafeLeft_x                                          0xEC3AB8
#define __pulStrafeRight_x                                         0xEC3ABC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB4F78
#define instEQZoneInfo_x                                           0xEC2640
#define pinstActiveBanker_x                                        0xEB2688
#define pinstActiveCorpse_x                                        0xEB2680
#define pinstActiveGMaster_x                                       0xEB2684
#define pinstActiveMerchant_x                                      0xEB267C
#define pinstAltAdvManager_x                                       0xE011A8
#define pinstBandageTarget_x                                       0xEB2698
#define pinstCamActor_x                                            0xE00008
#define pinstCDBStr_x                                              0xDFFEC4
#define pinstCDisplay_x                                            0xEB4BCC
#define pinstCEverQuest_x                                          0xF69200
#define pinstEverQuestInfo_x                                       0xEC2360
#define pinstCharData_x                                            0xEB4D64
#define pinstCharSpawn_x                                           0xEB26D0
#define pinstControlledMissile_x                                   0xEB2BBC
#define pinstControlledPlayer_x                                    0xEB26D0
#define pinstCResolutionHandler_x                                  0x15F9130
#define pinstCSidlManager_x                                        0x15F80C8
#define pinstCXWndManager_x                                        0x15F80C4
#define instDynamicZone_x                                          0xEB8AB0
#define pinstDZMember_x                                            0xEB8BC0
#define pinstDZTimerInfo_x                                         0xEB8BC4
#define pinstEqLogin_x                                             0xF69288
#define instEQMisc_x                                               0xDFFE08
#define pinstEQSoundManager_x                                      0xE02178
#define pinstEQSpellStrings_x                                      0xCC2878
#define instExpeditionLeader_x                                     0xEB8AFA
#define instExpeditionName_x                                       0xEB8B3A
#define pinstGroup_x                                               0xEB4D7E
#define pinstImeManager_x                                          0x15F80C0
#define pinstLocalPlayer_x                                         0xEB2678
#define pinstMercenaryData_x                                       0xF636DC
#define pinstMercenaryStats_x                                      0xF7C68C
#define pinstModelPlayer_x                                         0xEB2690
#define pinstPCData_x                                              0xEB4D64
#define pinstSkillMgr_x                                            0xF65848
#define pinstSpawnManager_x                                        0xF642F0
#define pinstSpellManager_x                                        0xF65A68
#define pinstSpellSets_x                                           0xF59D34
#define pinstStringTable_x                                         0xEB4D68
#define pinstSwitchManager_x                                       0xEB2518
#define pinstTarget_x                                              0xEB26CC
#define pinstTargetObject_x                                        0xEB2758
#define pinstTargetSwitch_x                                        0xEB2BC4
#define pinstTaskMember_x                                          0xDFFC98
#define pinstTrackTarget_x                                         0xEB26D4
#define pinstTradeTarget_x                                         0xEB268C
#define instTributeActive_x                                        0xDFFE29
#define pinstViewActor_x                                           0xE00004
#define pinstWorldData_x                                           0xEB2BB8
#define pinstZoneAddr_x                                            0xEC28E0
#define pinstPlayerPath_x                                          0xF64388
#define pinstTargetIndicator_x                                     0xF65CD0
#define EQObject_Top_x                                             0xEB2674
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE00790
#define pinstCAchievementsWnd_x                                    0xE0078C
#define pinstCActionsWnd_x                                         0xE002DC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFFFC0
#define pinstCAdvancedLootWnd_x                                    0xDFFF84
#define pinstCAdventureLeaderboardWnd_x                            0xF73360
#define pinstCAdventureRequestWnd_x                                0xF73410
#define pinstCAdventureStatsWnd_x                                  0xF734C0
#define pinstCAggroMeterWnd_x                                      0xE00044
#define pinstCAlarmWnd_x                                           0xE007EC
#define pinstCAlertHistoryWnd_x                                    0xDFFFDC
#define pinstCAlertStackWnd_x                                      0xE007F4
#define pinstCAlertWnd_x                                           0xDFFF64
#define pinstCAltStorageWnd_x                                      0xF73820
#define pinstCAudioTriggersWindow_x                                0xCB4BA8
#define pinstCAuraWnd_x                                            0xDFFFFC
#define pinstCAvaZoneWnd_x                                         0xE00054
#define pinstCBandolierWnd_x                                       0xE0003C
#define pinstCBankWnd_x                                            0xDFFFF8
#define pinstCBarterMerchantWnd_x                                  0xF74A60
#define pinstCBarterSearchWnd_x                                    0xF74B10
#define pinstCBarterWnd_x                                          0xF74BC0
#define pinstCBazaarConfirmationWnd_x                              0xE007B8
#define pinstCBazaarSearchWnd_x                                    0xE00090
#define pinstCBazaarWnd_x                                          0xE007D4
#define pinstCBlockedBuffWnd_x                                     0xE00000
#define pinstCBlockedPetBuffWnd_x                                  0xE00038
#define pinstCBodyTintWnd_x                                        0xE002EC
#define pinstCBookWnd_x                                            0xE00068
#define pinstCBreathWnd_x                                          0xE007A8
#define pinstCBuffWindowNORMAL_x                                   0xDFFFE0
#define pinstCBuffWindowSHORT_x                                    0xDFFFE4
#define pinstCBugReportWnd_x                                       0xDFFFF0
#define pinstCButtonWnd_x                                          0x15F8330
#define pinstCCastingWnd_x                                         0xE0005C
#define pinstCCastSpellWnd_x                                       0xE007A4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE007D8
#define pinstCChatWindowManager_x                                  0xF75680
#define pinstCClaimWnd_x                                           0xF757D8
#define pinstCColorPickerWnd_x                                     0xE002E4
#define pinstCCombatAbilityWnd_x                                   0xE007E4
#define pinstCCombatSkillsSelectWnd_x                              0xDFFF6C
#define pinstCCompassWnd_x                                         0xE002E0
#define pinstCConfirmationDialog_x                                 0xF7A6D8
#define pinstCContainerMgr_x                                       0xE007CC
#define pinstCContextMenuManager_x                                 0x15F8080
#define pinstCCursorAttachment_x                                   0xE0004C
#define pinstCDynamicZoneWnd_x                                     0xF75DA0
#define pinstCEditLabelWnd_x                                       0xDFFFD8
#define pinstCEQMainWnd_x                                          0xF75FE8
#define pinstCEventCalendarWnd_x                                   0xE00050
#define pinstCExtendedTargetWnd_x                                  0xE0002C
#define pinstCFacePick_x                                           0xDFFF7C
#define pinstCFactionWnd_x                                         0xE007C8
#define pinstCFellowshipWnd_x                                      0xF761E8
#define pinstCFileSelectionWnd_x                                   0xE00058
#define pinstCFindItemWnd_x                                        0xE007B4
#define pinstCFindLocationWnd_x                                    0xF76340
#define pinstCFriendsWnd_x                                         0xDFFF80
#define pinstCGemsGameWnd_x                                        0xE007C4
#define pinstCGiveWnd_x                                            0xE007F0
#define pinstCGroupSearchFiltersWnd_x                              0xE00060
#define pinstCGroupSearchWnd_x                                     0xF76738
#define pinstCGroupWnd_x                                           0xF767E8
#define pinstCGuildBankWnd_x                                       0xEC3724
#define pinstCGuildCreationWnd_x                                   0xF76948
#define pinstCGuildMgmtWnd_x                                       0xF769F8
#define pinstCharacterCreation_x                                   0xDFFF74
#define pinstCHelpWnd_x                                            0xDFFFB8
#define pinstCHeritageSelectionWnd_x                               0xDFFF88
#define pinstCHotButtonWnd_x                                       0xF78B50
#define pinstCHotButtonWnd1_x                                      0xF78B50
#define pinstCHotButtonWnd2_x                                      0xF78B54
#define pinstCHotButtonWnd3_x                                      0xF78B58
#define pinstCHotButtonWnd4_x                                      0xF78B5C
#define pinstCIconSelectionWnd_x                                   0xE00048
#define pinstCInspectWnd_x                                         0xDFFFB4
#define pinstCInventoryWnd_x                                       0xDFFF8C
#define pinstCInvSlotMgr_x                                         0xE00788
#define pinstCItemDisplayManager_x                                 0xF790E0
#define pinstCItemExpTransferWnd_x                                 0xF79210
#define pinstCItemOverflowWnd_x                                    0xE00094
#define pinstCJournalCatWnd_x                                      0xE0006C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE00030
#define pinstCKeyRingWnd_x                                         0xDFFFD4
#define pinstCLargeDialogWnd_x                                     0xF7B358
#define pinstCLayoutCopyWnd_x                                      0xF79560
#define pinstCLFGuildWnd_x                                         0xF79610
#define pinstCLoadskinWnd_x                                        0xE007D0
#define pinstCLootFiltersCopyWnd_x                                 0xCD11A0
#define pinstCLootFiltersWnd_x                                     0xE007F8
#define pinstCLootSettingsWnd_x                                    0xDFFF78
#define pinstCLootWnd_x                                            0xE00070
#define pinstCMailAddressBookWnd_x                                 0xE00798
#define pinstCMailCompositionWnd_x                                 0xE00304
#define pinstCMailIgnoreListWnd_x                                  0xE0079C
#define pinstCMailWnd_x                                            0xE002D8
#define pinstCManageLootWnd_x                                      0xE01658
#define pinstCMapToolbarWnd_x                                      0xDFFFBC
#define pinstCMapViewWnd_x                                         0xDFFF98
#define pinstCMarketplaceWnd_x                                     0xDFFF60
#define pinstCMerchantWnd_x                                        0xE00074
#define pinstCMIZoneSelectWnd_x                                    0xF79E48
#define pinstCMusicPlayerWnd_x                                     0xE0007C
#define pinstCNameChangeMercWnd_x                                  0xE007B0
#define pinstCNameChangePetWnd_x                                   0xE00794
#define pinstCNameChangeWnd_x                                      0xE007C0
#define pinstCNoteWnd_x                                            0xDFFF9C
#define pinstCObjectPreviewWnd_x                                   0xDFFF70
#define pinstCOptionsWnd_x                                         0xDFFFA4
#define pinstCPetInfoWnd_x                                         0xE000A0
#define pinstCPetitionQWnd_x                                       0xE0037C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE002F0
#define pinstCPlayerWnd_x                                          0xE000A4
#define pinstCPopupWndManager_x                                    0xF7A6D8
#define pinstCProgressionSelectionWnd_x                            0xF7A788
#define pinstCPurchaseGroupWnd_x                                   0xDFFFA8
#define pinstCPurchaseWnd_x                                        0xDFFF90
#define pinstCPvPLeaderboardWnd_x                                  0xF7A838
#define pinstCPvPStatsWnd_x                                        0xF7A8E8
#define pinstCQuantityWnd_x                                        0xE00034
#define pinstCRaceChangeWnd_x                                      0xE007E8
#define pinstCRaidOptionsWnd_x                                     0xE00064
#define pinstCRaidWnd_x                                            0xE00378
#define pinstCRealEstateItemsWnd_x                                 0xE00784
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE00078
#define pinstCRealEstateManageWnd_x                                0xDFFFB0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFFFD0
#define pinstCRealEstatePlotSearchWnd_x                            0xDFFFF4
#define pinstCRealEstatePurchaseWnd_x                              0xE00028
#define pinstCRespawnWnd_x                                         0xE00024
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE007A0
#define pinstCSendMoneyWnd_x                                       0xDFFF68
#define pinstCServerListWnd_x                                      0xE00040
#define pinstCSkillsSelectWnd_x                                    0xE007DC
#define pinstCSkillsWnd_x                                          0xE007BC
#define pinstCSocialEditWnd_x                                      0xDFFFCC
#define pinstCSocialWnd_x                                          0xE007AC
#define pinstCSpellBookWnd_x                                       0xE007E0
#define pinstCStoryWnd_x                                           0xE000A8
#define pinstCTargetOfTargetWnd_x                                  0xF7C710
#define pinstCTargetWnd_x                                          0xE00020
#define pinstCTaskOverlayWnd_x                                     0xDFFFA0
#define pinstCTaskSelectWnd_x                                      0xF7C868
#define pinstCTaskManager_x                                        0xCD1AE0
#define pinstCTaskTemplateSelectWnd_x                              0xF7C918
#define pinstCTaskWnd_x                                            0xF7C9C8
#define pinstCTextEntryWnd_x                                       0xDFFFE8
#define pinstCTimeLeftWnd_x                                        0xE000D4
#define pinstCTipWndCONTEXT_x                                      0xF7CBCC
#define pinstCTipWndOFDAY_x                                        0xF7CBC8
#define pinstCTitleWnd_x                                           0xF7CC78
#define pinstCTrackingWnd_x                                        0xDFFF94
#define pinstCTradeskillWnd_x                                      0xF7CDE0
#define pinstCTradeWnd_x                                           0xE002F8
#define pinstCTrainWnd_x                                           0xE002F4
#define pinstCTributeBenefitWnd_x                                  0xF7CFE0
#define pinstCTributeMasterWnd_x                                   0xF7D090
#define pinstCTributeTrophyWnd_x                                   0xF7D140
#define pinstCVideoModesWnd_x                                      0xE000AC
#define pinstCVoiceMacroWnd_x                                      0xF66438
#define pinstCVoteResultsWnd_x                                     0xE00374
#define pinstCVoteWnd_x                                            0xE002E8
#define pinstCWebManager_x                                         0xF66AB4
#define pinstCZoneGuideWnd_x                                       0xDFFFAC
#define pinstCZonePathWnd_x                                        0xDFFFC4

#define pinstEQSuiteTextureLoader_x                                0xC9F0C0
#define pinstItemIconCache_x                                       0xF75FA0
#define pinstLootFiltersManager_x                                  0xCD1250
#define pinstRewardSelectionWnd_x                                  0xF7B030

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AF9A0
#define __CastRay2_x                                               0x5AF9F0
#define __ConvertItemTags_x                                        0x5CB540
#define __CleanItemTags_x                                          0x47D060
#define __DoesFileExist_x                                          0x9048F0
#define __EQGetTime_x                                              0x901330
#define __ExecuteCmd_x                                             0x5A8230
#define __FixHeading_x                                             0x99C410
#define __GameLoop_x                                               0x6BBDA0
#define __get_bearing_x                                            0x5AF510
#define __get_melee_range_x                                        0x5AFBE0
#define __GetAnimationCache_x                                      0x721120
#define __GetGaugeValueFromEQ_x                                    0x8138E0
#define __GetLabelFromEQ_x                                         0x8153C0
#define __GetXTargetType_x                                         0x99DE60
#define __HandleMouseWheel_x                                       0x6BCC60
#define __HeadingDiff_x                                            0x99C480
#define __HelpPath_x                                               0xF617DC
#define __LoadFrontEnd_x                                           0x6B90C0
#define __NewUIINI_x                                               0x8135B0
#define __ProcessGameEvents_x                                      0x610400
#define __ProcessMouseEvent_x                                      0x60FBC0
#define __SaveColors_x                                             0x552580
#define __STMLToText_x                                             0x93F8A0
#define __ToggleKeyRingItem_x                                      0x515590
#define CMemoryMappedFile__SetFile_x                               0xA8B680
#define CrashDetected_x                                            0x6BAB60
#define DrawNetStatus_x                                            0x63BD80
#define Expansion_HoT_x                                            0xEC372C
#define Teleport_Table_Size_x                                      0xEB2760
#define Teleport_Table_x                                           0xEB2BC8
#define Util__FastTime_x                                           0x900F00

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490330
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499230
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499000
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4938C0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55A0E0
#define AltAdvManager__IsAbilityReady_x                            0x559010
#define AltAdvManager__GetAAById_x                                 0x559210
#define AltAdvManager__CanTrainAbility_x                           0x559280
#define AltAdvManager__CanSeeAbility_x                             0x5595E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA100
#define CharacterZoneClient__HasSkill_x                            0x4D4FF0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6710
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE370
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA970
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9090
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9170
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9250
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3170
#define CharacterZoneClient__BardCastBard_x                        0x4C5CD0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA40
#define CharacterZoneClient__GetEffect_x                           0x4BA8B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C41C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4290
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C42E0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4430
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4600
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2850
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7670
#define CharacterZoneClient__FindItemByRecord_x                    0x4D70F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E2880
#define CBankWnd__WndNotification_x                                0x6E2660

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F01F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61E9A0
#define CButtonWnd__CButtonWnd_x                                   0x93BC70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7102A0
#define CChatManager__InitContextMenu_x                            0x7093F0
#define CChatManager__FreeChatWindow_x                             0x70EDE0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8620
#define CChatManager__SetLockedActiveChatWindow_x                  0x70FF20
#define CChatManager__CreateChatWindow_x                           0x70F420

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8730

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x950300
#define CContextMenu__dCContextMenu_x                              0x950540
#define CContextMenu__AddMenuItem_x                                0x950550
#define CContextMenu__RemoveMenuItem_x                             0x950860
#define CContextMenu__RemoveAllMenuItems_x                         0x950880
#define CContextMenu__CheckMenuItem_x                              0x950900
#define CContextMenu__SetMenuItem_x                                0x950780
#define CContextMenu__AddSeparator_x                               0x9506E0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x950EA0
#define CContextMenuManager__RemoveMenu_x                          0x950F10
#define CContextMenuManager__PopupMenu_x                           0x950FD0
#define CContextMenuManager__Flush_x                               0x950E40
#define CContextMenuManager__GetMenu_x                             0x49B420
#define CContextMenuManager__CreateDefaultMenu_x                   0x71B900

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DCC10
#define CChatService__GetFriendName_x                              0x8DCC20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x710B10
#define CChatWindow__Clear_x                                       0x711DD0
#define CChatWindow__WndNotification_x                             0x712560
#define CChatWindow__AddHistory_x                                  0x711690

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94D760
#define CComboWnd__Draw_x                                          0x94CC60
#define CComboWnd__GetCurChoice_x                                  0x94D5A0
#define CComboWnd__GetListRect_x                                   0x94D110
#define CComboWnd__GetTextRect_x                                   0x94D7D0
#define CComboWnd__InsertChoice_x                                  0x94D2A0
#define CComboWnd__SetColors_x                                     0x94D270
#define CComboWnd__SetChoice_x                                     0x94D570
#define CComboWnd__GetItemCount_x                                  0x94D5B0
#define CComboWnd__GetCurChoiceText_x                              0x94D5F0
#define CComboWnd__GetChoiceText_x                                 0x94D5C0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94D330

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7192E0
#define CContainerWnd__vftable_x                                   0xB1249C
#define CContainerWnd__SetContainer_x                              0x71A840

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54CFB0
#define CDisplay__PreZoneMainUI_x                                  0x54CFC0
#define CDisplay__CleanGameUI_x                                    0x552340
#define CDisplay__GetClickedActor_x                                0x5452D0
#define CDisplay__GetUserDefinedColor_x                            0x53D990
#define CDisplay__GetWorldFilePath_x                               0x546D40
#define CDisplay__is3dON_x                                         0x541F30
#define CDisplay__ReloadUI_x                                       0x54C440
#define CDisplay__WriteTextHD2_x                                   0x541D20
#define CDisplay__TrueDistance_x                                   0x548A00
#define CDisplay__SetViewActor_x                                   0x544BF0
#define CDisplay__GetFloorHeight_x                                 0x541FF0
#define CDisplay__SetRenderWindow_x                                0x540950
#define CDisplay__ToggleScreenshotMode_x                           0x5446C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96FEC0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x95386F
#define CEditWnd__GetCharIndexPt_x                                 0x9547A0
#define CEditWnd__GetDisplayString_x                               0x954640
#define CEditWnd__GetHorzOffset_x                                  0x952EB0
#define CEditWnd__GetLineForPrintableChar_x                        0x955940
#define CEditWnd__GetSelStartPt_x                                  0x954A50
#define CEditWnd__GetSTMLSafeText_x                                0x954460
#define CEditWnd__PointFromPrintableChar_x                         0x955570
#define CEditWnd__SelectableCharFromPoint_x                        0x9556E0
#define CEditWnd__SetEditable_x                                    0x954B20
#define CEditWnd__SetWindowTextA_x                                 0x9541E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FE070
#define CEverQuest__ClickedPlayer_x                                0x5F0080
#define CEverQuest__CreateTargetIndicator_x                        0x60D6A0
#define CEverQuest__DeleteTargetIndicator_x                        0x60D730
#define CEverQuest__DoTellWindow_x                                 0x4E8810
#define CEverQuest__OutputTextToLog_x                              0x4E8A90
#define CEverQuest__DropHeldItemOnGround_x                         0x5E50C0
#define CEverQuest__dsp_chat_x                                     0x4E8E20
#define CEverQuest__trimName_x                                     0x609980
#define CEverQuest__Emote_x                                        0x5FE8D0
#define CEverQuest__EnterZone_x                                    0x5F8850
#define CEverQuest__GetBodyTypeDesc_x                              0x603240
#define CEverQuest__GetClassDesc_x                                 0x603880
#define CEverQuest__GetClassThreeLetterCode_x                      0x603E80
#define CEverQuest__GetDeityDesc_x                                 0x60BFE0
#define CEverQuest__GetLangDesc_x                                  0x604040
#define CEverQuest__GetRaceDesc_x                                  0x603860
#define CEverQuest__InterpretCmd_x                                 0x60C5B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E92C0
#define CEverQuest__LMouseUp_x                                     0x5E7650
#define CEverQuest__RightClickedOnPlayer_x                         0x5E9BA0
#define CEverQuest__RMouseUp_x                                     0x5E85D0
#define CEverQuest__SetGameState_x                                 0x5E4E50
#define CEverQuest__UPCNotificationFlush_x                         0x609880
#define CEverQuest__IssuePetCommand_x                              0x605440
#define CEverQuest__ReportSuccessfulHit_x                          0x5FFCC0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72B1C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72B220
#define CGaugeWnd__Draw_x                                          0x72A850

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF370
#define CGuild__GetGuildName_x                                     0x4AE450
#define CGuild__GetGuildIndex_x                                    0x4AE7E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x746610

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61ED60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7535A0
#define CInvSlotMgr__MoveItem_x                                    0x752300
#define CInvSlotMgr__SelectSlot_x                                  0x753670

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x750B80
#define CInvSlot__SliderComplete_x                                 0x74E8E0
#define CInvSlot__GetItemBase_x                                    0x74E270
#define CInvSlot__UpdateItem_x                                     0x74E3E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7550D0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x754270
#define CInvSlotWnd__HandleLButtonUp_x                             0x754C50

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80EC90
#define CItemDisplayWnd__UpdateStrings_x                           0x7636E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75D440
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75D960
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x763CD0
#define CItemDisplayWnd__AboutToShow_x                             0x763340
#define CItemDisplayWnd__WndNotification_x                         0x764DA0
#define CItemDisplayWnd__RequestConvertItem_x                      0x764870
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7623A0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x763160

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x847590

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7692A0

// CLabel 
#define CLabel__Draw_x                                             0x76ECC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x925F20
#define CListWnd__dCListWnd_x                                      0x926240
#define CListWnd__AddColumn_x                                      0x92A6B0
#define CListWnd__AddColumn1_x                                     0x92A700
#define CListWnd__AddLine_x                                        0x92AA90
#define CListWnd__AddString_x                                      0x92A890
#define CListWnd__CalculateFirstVisibleLine_x                      0x92A470
#define CListWnd__CalculateVSBRange_x                              0x92A250
#define CListWnd__ClearSel_x                                       0x92B270
#define CListWnd__ClearAllSel_x                                    0x92B2D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92BCF0
#define CListWnd__Compare_x                                        0x929B90
#define CListWnd__Draw_x                                           0x926370
#define CListWnd__DrawColumnSeparators_x                           0x928B60
#define CListWnd__DrawHeader_x                                     0x928FD0
#define CListWnd__DrawItem_x                                       0x9294D0
#define CListWnd__DrawLine_x                                       0x928CD0
#define CListWnd__DrawSeparator_x                                  0x928C00
#define CListWnd__EnableLine_x                                     0x928430
#define CListWnd__EnsureVisible_x                                  0x92BC10
#define CListWnd__ExtendSel_x                                      0x92B1A0
#define CListWnd__GetColumnTooltip_x                               0x927F70
#define CListWnd__GetColumnMinWidth_x                              0x927FE0
#define CListWnd__GetColumnWidth_x                                 0x927EE0
#define CListWnd__GetCurSel_x                                      0x927870
#define CListWnd__GetItemAtPoint_x                                 0x9286B0
#define CListWnd__GetItemAtPoint1_x                                0x928720
#define CListWnd__GetItemData_x                                    0x9278F0
#define CListWnd__GetItemHeight_x                                  0x927CB0
#define CListWnd__GetItemIcon_x                                    0x927A80
#define CListWnd__GetItemRect_x                                    0x928520
#define CListWnd__GetItemText_x                                    0x927930
#define CListWnd__GetSelList_x                                     0x92B320
#define CListWnd__GetSeparatorRect_x                               0x928960
#define CListWnd__InsertLine_x                                     0x92AE80
#define CListWnd__RemoveLine_x                                     0x92AFD0
#define CListWnd__SetColors_x                                      0x92A230
#define CListWnd__SetColumnJustification_x                         0x929F60
#define CListWnd__SetColumnWidth_x                                 0x929E80
#define CListWnd__SetCurSel_x                                      0x92B0E0
#define CListWnd__SetItemColor_x                                   0x92B8C0
#define CListWnd__SetItemData_x                                    0x92B880
#define CListWnd__SetItemText_x                                    0x92B490
#define CListWnd__ShiftColumnSeparator_x                           0x92A020
#define CListWnd__Sort_x                                           0x929D10
#define CListWnd__ToggleSel_x                                      0x92B110
#define CListWnd__SetColumnsSizable_x                              0x92A0D0
#define CListWnd__SetItemWnd_x                                     0x92B740
#define CListWnd__GetItemWnd_x                                     0x927AD0
#define CListWnd__SetItemIcon_x                                    0x92B510
#define CListWnd__CalculateCustomWindowPositions_x                 0x92A570
#define CListWnd__SetVScrollPos_x                                  0x929E60

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7843F0
#define CMapViewWnd__GetWorldCoordinates_x                         0x782B00
#define CMapViewWnd__HandleLButtonDown_x                           0x77FB40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A45E0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A4EC0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A53F0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A8370
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A3150
#define CMerchantWnd__SelectBuySellSlot_x                          0x7ADF30
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A4200

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AA720
#define CPacketScrambler__hton_x                                   0x8AA710

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x944ED0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9452E0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9450D0
#define CSidlManager__CreateLabel_x                                0x806060
#define CSidlManager__CreateXWndFromTemplate_x                     0x948240
#define CSidlManager__CreateXWndFromTemplate1_x                    0x948420
#define CSidlManager__CreateXWnd_x                                 0x805F90
#define CSidlManager__CreateHotButtonWnd_x                         0x806550

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9419D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9418D0
#define CSidlScreenWnd__ConvertToRes_x                             0x966F10
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x941360
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x941050
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x941120
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9411F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x941E70
#define CSidlScreenWnd__EnableIniStorage_x                         0x942340
#define CSidlScreenWnd__GetSidlPiece_x                             0x942060
#define CSidlScreenWnd__Init1_x                                    0x940C50
#define CSidlScreenWnd__LoadIniInfo_x                              0x942390
#define CSidlScreenWnd__LoadIniListWnd_x                           0x942EB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x940050
#define CSidlScreenWnd__StoreIniInfo_x                             0x942A30
#define CSidlScreenWnd__StoreIniVis_x                              0x942D90
#define CSidlScreenWnd__WndNotification_x                          0x941D80
#define CSidlScreenWnd__GetChildItem_x                             0x9422C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x931B50
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F7F50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x683200
#define CSkillMgr__GetSkillCap_x                                   0x6833E0
#define CSkillMgr__GetNameToken_x                                  0x682980
#define CSkillMgr__IsActivatedSkill_x                              0x682AC0
#define CSkillMgr__IsCombatSkill_x                                 0x682A00

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x951C80
#define CSliderWnd__SetValue_x                                     0x951AF0
#define CSliderWnd__SetNumTicks_x                                  0x951B50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80C120

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95A4C0
#define CStmlWnd__CalculateHSBRange_x                              0x95B5A0
#define CStmlWnd__CalculateVSBRange_x                              0x95B510
#define CStmlWnd__CanBreakAtCharacter_x                            0x95F8E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x960570
#define CStmlWnd__ForceParseNow_x                                  0x95AA60
#define CStmlWnd__GetNextTagPiece_x                                0x95F840
#define CStmlWnd__GetSTMLText_x                                    0x504F10
#define CStmlWnd__GetVisibleText_x                                 0x95AA80
#define CStmlWnd__InitializeWindowVariables_x                      0x9603C0
#define CStmlWnd__MakeStmlColorTag_x                               0x959B30
#define CStmlWnd__MakeWndNotificationTag_x                         0x959BA0
#define CStmlWnd__SetSTMLText_x                                    0x958BE0
#define CStmlWnd__StripFirstSTMLLines_x                            0x961670
#define CStmlWnd__UpdateHistoryString_x                            0x960780

// CTabWnd 
#define CTabWnd__Draw_x                                            0x957D10
#define CTabWnd__DrawCurrentPage_x                                 0x958440
#define CTabWnd__DrawTab_x                                         0x958160
#define CTabWnd__GetCurrentPage_x                                  0x957510
#define CTabWnd__GetPageInnerRect_x                                0x957750
#define CTabWnd__GetTabInnerRect_x                                 0x957690
#define CTabWnd__GetTabRect_x                                      0x957540
#define CTabWnd__InsertPage_x                                      0x957960
#define CTabWnd__SetPage_x                                         0x9577D0
#define CTabWnd__SetPageRect_x                                     0x957C50
#define CTabWnd__UpdatePage_x                                      0x958020
#define CTabWnd__GetPageFromTabIndex_x                             0x9580A0
#define CTabWnd__GetCurrentTabIndex_x                              0x957500

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7696B0
#define CPageWnd__SetTabText_x                                     0x957050

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8F90

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92EA10
#define CTextureFont__GetTextExtent_x                              0x92EBD0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B5F40
#define CHtmlComponentWnd__ValidateUri_x                           0x748000
#define CHtmlWnd__SetClientCallbacks_x                             0x623DD0
#define CHtmlWnd__AddObserver_x                                    0x623DF0
#define CHtmlWnd__RemoveObserver_x                                 0x623E50
#define Window__getProgress_x                                      0x85FBB0
#define Window__getStatus_x                                        0x85FBD0
#define Window__getURI_x                                           0x85FBE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96C950

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91BB40

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8460
#define CXStr__CXStr1_x                                            0x924550
#define CXStr__CXStr3_x                                            0x8FD470
#define CXStr__dCXStr_x                                            0x478780
#define CXStr__operator_equal_x                                    0x8FD6A0
#define CXStr__operator_equal1_x                                   0x8FD6E0
#define CXStr__operator_plus_equal1_x                              0x8FE170
#define CXStr__SetString_x                                         0x900060
#define CXStr__operator_char_p_x                                   0x8FDBB0
#define CXStr__GetChar_x                                           0x8FF990
#define CXStr__Delete_x                                            0x8FF260
#define CXStr__GetUnicode_x                                        0x8FFA00
#define CXStr__GetLength_x                                         0x47D410
#define CXStr__Mid_x                                               0x47D420
#define CXStr__Insert_x                                            0x8FFA60
#define CXStr__FindNext_x                                          0x8FF6D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94FF20
#define CXWnd__BringToTop_x                                        0x935270
#define CXWnd__Center_x                                            0x934DF0
#define CXWnd__ClrFocus_x                                          0x934C10
#define CXWnd__Destroy_x                                           0x934CB0
#define CXWnd__DoAllDrawing_x                                      0x931310
#define CXWnd__DrawChildren_x                                      0x9312E0
#define CXWnd__DrawColoredRect_x                                   0x931760
#define CXWnd__DrawTooltip_x                                       0x92FE10
#define CXWnd__DrawTooltipAtPoint_x                                0x92FED0
#define CXWnd__GetBorderFrame_x                                    0x9315C0
#define CXWnd__GetChildWndAt_x                                     0x935310
#define CXWnd__GetClientClipRect_x                                 0x933570
#define CXWnd__GetScreenClipRect_x                                 0x933640
#define CXWnd__GetScreenRect_x                                     0x9337E0
#define CXWnd__GetTooltipRect_x                                    0x9317B0
#define CXWnd__GetWindowTextA_x                                    0x49CB80
#define CXWnd__IsActive_x                                          0x931ED0
#define CXWnd__IsDescendantOf_x                                    0x9341B0
#define CXWnd__IsReallyVisible_x                                   0x9341E0
#define CXWnd__IsType_x                                            0x935990
#define CXWnd__Move_x                                              0x934260
#define CXWnd__Move1_x                                             0x934310
#define CXWnd__ProcessTransition_x                                 0x934DA0
#define CXWnd__Refade_x                                            0x9345C0
#define CXWnd__Resize_x                                            0x934840
#define CXWnd__Right_x                                             0x935030
#define CXWnd__SetFocus_x                                          0x934BD0
#define CXWnd__SetFont_x                                           0x934C40
#define CXWnd__SetKeyTooltip_x                                     0x9357A0
#define CXWnd__SetMouseOver_x                                      0x9326C0
#define CXWnd__StartFade_x                                         0x934090
#define CXWnd__GetChildItem_x                                      0x935480
#define CXWnd__SetParent_x                                         0x933F50
#define CXWnd__Minimize_x                                          0x9348B0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x967F90

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9381A0
#define CXWndManager__DrawWindows_x                                0x9381C0
#define CXWndManager__GetKeyboardFlags_x                           0x93A8E0
#define CXWndManager__HandleKeyboardMsg_x                          0x93A490
#define CXWndManager__RemoveWnd_x                                  0x93AB10
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93B090

// CDBStr
#define CDBStr__GetString_x                                        0x53C910

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB950
#define EQ_Character__Cur_HP_x                                     0x4D2030
#define EQ_Character__Cur_Mana_x                                   0x4D9750
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE9C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2490
#define EQ_Character__GetFocusRangeModifier_x                      0x4B25E0
#define EQ_Character__GetHPRegen_x                                 0x4DF4F0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFAF0
#define EQ_Character__GetManaRegen_x                               0x4DFF30
#define EQ_Character__Max_Endurance_x                              0x649940
#define EQ_Character__Max_HP_x                                     0x4D1E60
#define EQ_Character__Max_Mana_x                                   0x649740
#define EQ_Character__doCombatAbility_x                            0x64BDA0
#define EQ_Character__UseSkill_x                                   0x4E1D10
#define EQ_Character__GetConLevel_x                                0x642D00
#define EQ_Character__IsExpansionFlag_x                            0x5A6A00
#define EQ_Character__TotalEffect_x                                0x4C5410
#define EQ_Character__GetPCSpellAffect_x                           0x4BF710
#define EQ_Character__SpellDuration_x                              0x4BF240
#define EQ_Character__GetAdjustedSkill_x                           0x4D4DB0
#define EQ_Character__GetBaseSkill_x                               0x4D5D50
#define EQ_Character__CanUseItem_x                                 0x4D9A60

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C9A60

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65FE30

//PcClient
#define PcClient__PcClient_x                                       0x640430

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95C0
#define CCharacterListWnd__EnterWorld_x                            0x4B9000
#define CCharacterListWnd__Quit_x                                  0x4B8D50
#define CCharacterListWnd__UpdateList_x                            0x4B9190

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x625000
#define EQ_Item__CreateItemTagString_x                             0x8A3F90
#define EQ_Item__IsStackable_x                                     0x8A8AE0
#define EQ_Item__GetImageNum_x                                     0x8A5A00
#define EQ_Item__CreateItemClient_x                                0x6241D0
#define EQ_Item__GetItemValue_x                                    0x8A6D20
#define EQ_Item__ValueSellMerchant_x                               0x8AA300
#define EQ_Item__IsKeyRingItem_x                                   0x8A8400
#define EQ_Item__CanGoInBag_x                                      0x625120
#define EQ_Item__IsEmpty_x                                         0x8A7F40
#define EQ_Item__GetMaxItemCount_x                                 0x8A7130
#define EQ_Item__GetHeldItem_x                                     0x8A58D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A3910

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55ADF0
#define EQ_LoadingS__Array_x                                       0xC26B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64A2A0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B3540
#define EQ_PC__GetCombatAbility_x                                  0x8B3BB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B3C20
#define EQ_PC__GetItemRecastTimer_x                                0x64C320
#define EQ_PC__HasLoreItem_x                                       0x6434C0
#define EQ_PC__AlertInventoryChanged_x                             0x642630
#define EQ_PC__GetPcZoneClient_x                                   0x66E960
#define EQ_PC__RemoveMyAffect_x                                    0x64F550
#define EQ_PC__GetKeyRingItems_x                                   0x8B44B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B4240
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B47B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5ACF40
#define EQItemList__add_object_x                                   0x5DA8F0
#define EQItemList__add_item_x                                     0x5AD4A0
#define EQItemList__delete_item_x                                  0x5AD4F0
#define EQItemList__FreeItemList_x                                 0x5AD3F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x539380

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6616B0
#define EQPlayer__dEQPlayer_x                                      0x654A00
#define EQPlayer__DoAttack_x                                       0x6695F0
#define EQPlayer__EQPlayer_x                                       0x6550C0
#define EQPlayer__SetNameSpriteState_x                             0x6593A0
#define EQPlayer__SetNameSpriteTint_x                              0x65A260
#define PlayerBase__HasProperty_j_x                                0x99A820
#define EQPlayer__IsTargetable_x                                   0x99ACC0
#define EQPlayer__CanSee_x                                         0x99AB20
#define EQPlayer__CanSee1_x                                        0x99ABF0
#define PlayerBase__GetVisibilityLineSegment_x                     0x99A8E0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66C3F0
#define PlayerZoneClient__GetLevel_x                               0x66E9A0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DBA60
#define PlayerZoneClient__LegalPlayerRace_x                        0x5541F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x664510
#define EQPlayerManager__GetSpawnByName_x                          0x6645C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x664650

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x628610
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x628690
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6286D0
#define KeypressHandler__ClearCommandStateArray_x                  0x629AE0
#define KeypressHandler__HandleKeyDown_x                           0x629B00
#define KeypressHandler__HandleKeyUp_x                             0x629BA0
#define KeypressHandler__SaveKeymapping_x                          0x629FF0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x780260
#define MapViewMap__SaveEx_x                                       0x783620
#define MapViewMap__SetZoom_x                                      0x787CE0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C7980

// StringTable 
#define StringTable__getString_x                                   0x8C2860

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64F1C0
#define PcZoneClient__RemovePetEffect_x                            0x64F7F0
#define PcZoneClient__HasAlternateAbility_x                        0x649570
#define PcZoneClient__GetCurrentMod_x                              0x4E4DC0
#define PcZoneClient__GetModCap_x                                  0x4E4CC0
#define PcZoneClient__CanEquipItem_x                               0x649C40
#define PcZoneClient__GetItemByID_x                                0x64C790
#define PcZoneClient__GetItemByItemClass_x                         0x64C8E0
#define PcZoneClient__RemoveBuffEffect_x                           0x64F810
#define PcZoneClient__BandolierSwap_x                              0x64A860
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64C2C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E05D0

//IconCache
#define IconCache__GetIcon_x                                       0x7209C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x718480
#define CContainerMgr__CloseContainer_x                            0x718750
#define CContainerMgr__OpenExperimentContainer_x                   0x7191D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D8520

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61D180

//CLootWnd
#define CLootWnd__LootAll_x                                        0x776780
#define CLootWnd__RequestLootSlot_x                                0x7759B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57ABA0
#define EQ_Spell__SpellAffects_x                                   0x57B010
#define EQ_Spell__SpellAffectBase_x                                0x57ADD0
#define EQ_Spell__IsStackable_x                                    0x4C9A60
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C98B0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6980
#define EQ_Spell__IsSPAStacking_x                                  0x57BE60
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57B370
#define EQ_Spell__IsNoRemove_x                                     0x4C9A40
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57BE70
#define __IsResEffectSpell_x                                       0x4C8E30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD0B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D1FB0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81F360
#define CTargetWnd__WndNotification_x                              0x81EBF0
#define CTargetWnd__RefreshTargetBuffs_x                           0x81EEC0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81DD60

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x823950

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536DA0
#define CTaskManager__HandleMessage_x                              0x535240
#define CTaskManager__GetTaskStatus_x                              0x536E50
#define CTaskManager__GetElementDescription_x                      0x536ED0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5760F0
#define EqSoundManager__PlayScriptMp3_x                            0x576250
#define EqSoundManager__SoundAssistPlay_x                          0x687130
#define EqSoundManager__WaveInstancePlay_x                         0x6866A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52AB10

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x956560

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562880
#define CAltAbilityData__GetMercMaxRank_x                          0x562810
#define CAltAbilityData__GetMaxRank_x                              0x557E90

//CTargetRing
#define CTargetRing__Cast_x                                        0x61B290

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9890
#define CharacterBase__CreateItemGlobalIndex_x                     0x511C30
#define CharacterBase__CreateItemIndex_x                           0x623380
#define CharacterBase__GetItemPossession_x                         0x4FD8E0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DA5D0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DA630
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FF5E0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FFE10
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FFEC0

//messages
#define msg_spell_worn_off_x                                       0x59ECF0
#define msg_new_text_x                                             0x593A70
#define __msgTokenTextParam_x                                      0x5A1220
#define msgTokenText_x                                             0x5A1470

//SpellManager
#define SpellManager__vftable_x                                    0xAEC4C4
#define SpellManager__SpellManager_x                               0x68A460
#define Spellmanager__LoadTextSpells_x                             0x68AD50
#define SpellManager__GetSpellByGroupAndRank_x                     0x68A630

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99E750

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x512280
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A4FC0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63BBE0
#define ItemGlobalIndex__IsValidIndex_x                            0x5122E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D2950
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D2BD0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76F000

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71CB90
#define CCursorAttachment__AttachToCursor1_x                       0x71CBD0
#define CCursorAttachment__Deactivate_x                            0x71DBC0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x949260
#define CSidlManagerBase__CreatePageWnd_x                          0x948A60
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x944CF0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x944C80

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9662D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x965F90

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F1D0
#define CFindItemWnd__WndNotification_x                            0x50FCB0
#define CFindItemWnd__Update_x                                     0x510820
#define CFindItemWnd__PickupSelectedItem_x                         0x50EA10

//IString
#define IString__Append_x                                          0x4F0380

//Camera
#define CDisplay__cameraType_x                                     0xE000BC
#define EverQuest__Cameras_x                                       0xEC3A7C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517930
#define LootFiltersManager__GetItemFilterData_x                    0x517240
#define LootFiltersManager__RemoveItemLootFilter_x                 0x517270
#define LootFiltersManager__SetItemLootFilter_x                    0x517490

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C6530

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A4340
#define CResolutionHandler__GetWindowedStyle_x                     0x681DD0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x715270

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E7A40
#define CDistillerInfo__Instance_x                                 0x8E79E0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7353E0
#define CGroupWnd__UpdateDisplay_x                                 0x734740

//ItemBase
#define ItemBase__IsLore_x                                         0x8A84B0
#define ItemBase__IsLoreEquipped_x                                 0x8A8520

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DA850
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DA990
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DA9F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6770E0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67AA70

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505670

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1F80
#define FactionManagerClient__HandleFactionMessage_x               0x4F25F0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2BF0
#define FactionManagerClient__GetMaxFaction_x                      0x4F2C0F
#define FactionManagerClient__GetMinFaction_x                      0x4F2BC0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD8B0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92D990

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE90

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FDB80

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x561D10

//CTargetManager
#define CTargetManager__Get_x                                      0x68DCE0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6770E0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D50

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AD390

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF61110

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
