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
#define __ExpectedVersionDate                                     "Nov 24 2019"
#define __ExpectedVersionTime                                     "04:42:19"
#define __ActualVersionDate_x                                      0xB092AC
#define __ActualVersionTime_x                                      0xB092A0
#define __ActualVersionBuild_x                                     0xAF4F6C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62F190
#define __MemChecker1_x                                            0x902570
#define __MemChecker2_x                                            0x6BD600
#define __MemChecker3_x                                            0x6BD550
#define __MemChecker4_x                                            0x859460
#define __EncryptPad0_x                                            0xC3F3E8
#define __EncryptPad1_x                                            0xC9D5E8
#define __EncryptPad2_x                                            0xC4FC80
#define __EncryptPad3_x                                            0xC4F880
#define __EncryptPad4_x                                            0xC8DC00
#define __EncryptPad5_x                                            0xF691C0
#define __AC1_x                                                    0x815D66
#define __AC2_x                                                    0x5E902F
#define __AC3_x                                                    0x5F072F
#define __AC4_x                                                    0x5F4700
#define __AC5_x                                                    0x5FAA0F
#define __AC6_x                                                    0x5FF026
#define __AC7_x                                                    0x5E8AA0
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
#define __do_loot_x                                                0x5B4A80
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
#define __gfMaxZoomCameraDistance_x                                0xAFEC00
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
#define pinstCAvaZoneWnd_x                                         0xE00050
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
#define pinstCEventCalendarWnd_x                                   0xE00054
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
#define pinstCItemOverflowWnd_x                                    0xE00098
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
#define pinstCMailCompositionWnd_x                                 0xE0030C
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
#define pinstCStoryWnd_x                                           0xE000B0
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
#define pinstCTradeWnd_x                                           0xE002FC
#define pinstCTrainWnd_x                                           0xE002F4
#define pinstCTributeBenefitWnd_x                                  0xF7CFE0
#define pinstCTributeMasterWnd_x                                   0xF7D090
#define pinstCTributeTrophyWnd_x                                   0xF7D140
#define pinstCVideoModesWnd_x                                      0xE000BC
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
#define __CastRay_x                                                0x5AFEE0
#define __CastRay2_x                                               0x5AFF30
#define __ConvertItemTags_x                                        0x5CBA80
#define __CleanItemTags_x                                          0x47D120
#define __DoesFileExist_x                                          0x905600
#define __EQGetTime_x                                              0x902040
#define __ExecuteCmd_x                                             0x5A8740
#define __FixHeading_x                                             0x99C860
#define __GameLoop_x                                               0x6BC7F0
#define __get_bearing_x                                            0x5AFA50
#define __get_melee_range_x                                        0x5B0120
#define __GetAnimationCache_x                                      0x721A90
#define __GetGaugeValueFromEQ_x                                    0x814210
#define __GetLabelFromEQ_x                                         0x815CF0
#define __GetXTargetType_x                                         0x99E240
#define __HandleMouseWheel_x                                       0x6BD6B0
#define __HeadingDiff_x                                            0x99C8D0
#define __HelpPath_x                                               0xF617DC
#define __LoadFrontEnd_x                                           0x6B9B10
#define __NewUIINI_x                                               0x813EE0
#define __ProcessGameEvents_x                                      0x6108A0
#define __ProcessMouseEvent_x                                      0x610060
#define __SaveColors_x                                             0x552650
#define __STMLToText_x                                             0x93FDB0
#define __ToggleKeyRingItem_x                                      0x515870
#define CMemoryMappedFile__SetFile_x                               0xA8B9A0
#define CrashDetected_x                                            0x6BB5B0
#define DrawNetStatus_x                                            0x63C520
#define Expansion_HoT_x                                            0xEC372C
#define Teleport_Table_Size_x                                      0xEB2760
#define Teleport_Table_x                                           0xEB2BC8
#define Util__FastTime_x                                           0x901C00

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499400
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4991D0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A90
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492EE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55A130
#define AltAdvManager__IsAbilityReady_x                            0x559060
#define AltAdvManager__GetAAById_x                                 0x559260
#define AltAdvManager__CanTrainAbility_x                           0x5592D0
#define AltAdvManager__CanSeeAbility_x                             0x559630

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA210
#define CharacterZoneClient__HasSkill_x                            0x4D5100
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6820
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE3F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA9F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D91A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9280
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9360
#define CharacterZoneClient__FindAffectSlot_x                      0x4C31F0
#define CharacterZoneClient__BardCastBard_x                        0x4C5D50
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAAC0
#define CharacterZoneClient__GetEffect_x                           0x4BA930
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4240
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4310
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4360
#define CharacterZoneClient__CalcAffectChange_x                    0x4C44B0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4680
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B28A0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7780
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7200

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E31E0
#define CBankWnd__WndNotification_x                                0x6E2FC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F08E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61F020
#define CButtonWnd__CButtonWnd_x                                   0x93C180

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x710C10
#define CChatManager__InitContextMenu_x                            0x709D70
#define CChatManager__FreeChatWindow_x                             0x70F750
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8800
#define CChatManager__SetLockedActiveChatWindow_x                  0x710890
#define CChatManager__CreateChatWindow_x                           0x70FD90

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8910

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x950760
#define CContextMenu__dCContextMenu_x                              0x950990
#define CContextMenu__AddMenuItem_x                                0x9509A0
#define CContextMenu__RemoveMenuItem_x                             0x950CB0
#define CContextMenu__RemoveAllMenuItems_x                         0x950CD0
#define CContextMenu__CheckMenuItem_x                              0x950D50
#define CContextMenu__SetMenuItem_x                                0x950BD0
#define CContextMenu__AddSeparator_x                               0x950B30

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9512F0
#define CContextMenuManager__RemoveMenu_x                          0x951360
#define CContextMenuManager__PopupMenu_x                           0x951420
#define CContextMenuManager__Flush_x                               0x951290
#define CContextMenuManager__GetMenu_x                             0x49B4B0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71C280

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DD770
#define CChatService__GetFriendName_x                              0x8DD780

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x711480
#define CChatWindow__Clear_x                                       0x712740
#define CChatWindow__WndNotification_x                             0x712ED0
#define CChatWindow__AddHistory_x                                  0x712000

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94DBD0
#define CComboWnd__Draw_x                                          0x94D0C0
#define CComboWnd__GetCurChoice_x                                  0x94DA10
#define CComboWnd__GetListRect_x                                   0x94D580
#define CComboWnd__GetTextRect_x                                   0x94DC40
#define CComboWnd__InsertChoice_x                                  0x94D710
#define CComboWnd__SetColors_x                                     0x94D6E0
#define CComboWnd__SetChoice_x                                     0x94D9E0
#define CComboWnd__GetItemCount_x                                  0x94DA20
#define CComboWnd__GetCurChoiceText_x                              0x94DA60
#define CComboWnd__GetChoiceText_x                                 0x94DA30
#define CComboWnd__InsertChoiceAtIndex_x                           0x94D7A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x719C70
#define CContainerWnd__vftable_x                                   0xB1249C
#define CContainerWnd__SetContainer_x                              0x71B1E0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54D090
#define CDisplay__PreZoneMainUI_x                                  0x54D0A0
#define CDisplay__CleanGameUI_x                                    0x552410
#define CDisplay__GetClickedActor_x                                0x5453B0
#define CDisplay__GetUserDefinedColor_x                            0x53DA70
#define CDisplay__GetWorldFilePath_x                               0x546E20
#define CDisplay__is3dON_x                                         0x542010
#define CDisplay__ReloadUI_x                                       0x54C520
#define CDisplay__WriteTextHD2_x                                   0x541E00
#define CDisplay__TrueDistance_x                                   0x548AE0
#define CDisplay__SetViewActor_x                                   0x544CD0
#define CDisplay__GetFloorHeight_x                                 0x5420D0
#define CDisplay__SetRenderWindow_x                                0x540A30
#define CDisplay__ToggleScreenshotMode_x                           0x5447A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x970360

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x953C9F
#define CEditWnd__GetCharIndexPt_x                                 0x954BD0
#define CEditWnd__GetDisplayString_x                               0x954A80
#define CEditWnd__GetHorzOffset_x                                  0x9532F0
#define CEditWnd__GetLineForPrintableChar_x                        0x955D40
#define CEditWnd__GetSelStartPt_x                                  0x954E80
#define CEditWnd__GetSTMLSafeText_x                                0x9548A0
#define CEditWnd__PointFromPrintableChar_x                         0x955980
#define CEditWnd__SelectableCharFromPoint_x                        0x955AF0
#define CEditWnd__SetEditable_x                                    0x954F40
#define CEditWnd__SetWindowTextA_x                                 0x954620

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FE500
#define CEverQuest__ClickedPlayer_x                                0x5F0510
#define CEverQuest__CreateTargetIndicator_x                        0x60DB30
#define CEverQuest__DeleteTargetIndicator_x                        0x60DBC0
#define CEverQuest__DoTellWindow_x                                 0x4E89F0
#define CEverQuest__OutputTextToLog_x                              0x4E8C70
#define CEverQuest__DropHeldItemOnGround_x                         0x5E5550
#define CEverQuest__dsp_chat_x                                     0x4E9000
#define CEverQuest__trimName_x                                     0x609E10
#define CEverQuest__Emote_x                                        0x5FED60
#define CEverQuest__EnterZone_x                                    0x5F8CE0
#define CEverQuest__GetBodyTypeDesc_x                              0x6036D0
#define CEverQuest__GetClassDesc_x                                 0x603D10
#define CEverQuest__GetClassThreeLetterCode_x                      0x604310
#define CEverQuest__GetDeityDesc_x                                 0x60C470
#define CEverQuest__GetLangDesc_x                                  0x6044D0
#define CEverQuest__GetRaceDesc_x                                  0x603CF0
#define CEverQuest__InterpretCmd_x                                 0x60CA40
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E9750
#define CEverQuest__LMouseUp_x                                     0x5E7AE0
#define CEverQuest__RightClickedOnPlayer_x                         0x5EA030
#define CEverQuest__RMouseUp_x                                     0x5E8A60
#define CEverQuest__SetGameState_x                                 0x5E52E0
#define CEverQuest__UPCNotificationFlush_x                         0x609D10
#define CEverQuest__IssuePetCommand_x                              0x6058D0
#define CEverQuest__ReportSuccessfulHit_x                          0x600150

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72BAE0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72BB40
#define CGaugeWnd__Draw_x                                          0x72B160

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF300
#define CGuild__GetGuildName_x                                     0x4AE3E0
#define CGuild__GetGuildIndex_x                                    0x4AE770

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x746F40

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61F3E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x753F70
#define CInvSlotMgr__MoveItem_x                                    0x752C80
#define CInvSlotMgr__SelectSlot_x                                  0x754040

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x751500
#define CInvSlot__SliderComplete_x                                 0x74F260
#define CInvSlot__GetItemBase_x                                    0x74EBD0
#define CInvSlot__UpdateItem_x                                     0x74ED40

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x755AC0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x754C60
#define CInvSlotWnd__HandleLButtonUp_x                             0x755640

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80F590
#define CItemDisplayWnd__UpdateStrings_x                           0x764200
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75DF50
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75E460
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x764800
#define CItemDisplayWnd__AboutToShow_x                             0x763E40
#define CItemDisplayWnd__WndNotification_x                         0x7658F0
#define CItemDisplayWnd__RequestConvertItem_x                      0x7653B0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x762EA0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x763C60

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x848140

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x769DF0

// CLabel 
#define CLabel__Draw_x                                             0x76F7E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x926540
#define CListWnd__dCListWnd_x                                      0x926860
#define CListWnd__AddColumn_x                                      0x92ACC0
#define CListWnd__AddColumn1_x                                     0x92AD10
#define CListWnd__AddLine_x                                        0x92B0A0
#define CListWnd__AddString_x                                      0x92AEA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92AA80
#define CListWnd__CalculateVSBRange_x                              0x92A870
#define CListWnd__ClearSel_x                                       0x92B880
#define CListWnd__ClearAllSel_x                                    0x92B8E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92C2F0
#define CListWnd__Compare_x                                        0x92A1A0
#define CListWnd__Draw_x                                           0x926990
#define CListWnd__DrawColumnSeparators_x                           0x929180
#define CListWnd__DrawHeader_x                                     0x9295E0
#define CListWnd__DrawItem_x                                       0x929AE0
#define CListWnd__DrawLine_x                                       0x9292E0
#define CListWnd__DrawSeparator_x                                  0x929220
#define CListWnd__EnableLine_x                                     0x928A60
#define CListWnd__EnsureVisible_x                                  0x92C210
#define CListWnd__ExtendSel_x                                      0x92B7B0
#define CListWnd__GetColumnTooltip_x                               0x9285A0
#define CListWnd__GetColumnMinWidth_x                              0x928610
#define CListWnd__GetColumnWidth_x                                 0x928510
#define CListWnd__GetCurSel_x                                      0x927EA0
#define CListWnd__GetItemAtPoint_x                                 0x928CD0
#define CListWnd__GetItemAtPoint1_x                                0x928D40
#define CListWnd__GetItemData_x                                    0x927F20
#define CListWnd__GetItemHeight_x                                  0x9282E0
#define CListWnd__GetItemIcon_x                                    0x9280B0
#define CListWnd__GetItemRect_x                                    0x928B50
#define CListWnd__GetItemText_x                                    0x927F60
#define CListWnd__GetSelList_x                                     0x92B930
#define CListWnd__GetSeparatorRect_x                               0x928F80
#define CListWnd__InsertLine_x                                     0x92B490
#define CListWnd__RemoveLine_x                                     0x92B5E0
#define CListWnd__SetColors_x                                      0x92A840
#define CListWnd__SetColumnJustification_x                         0x92A570
#define CListWnd__SetColumnWidth_x                                 0x92A490
#define CListWnd__SetCurSel_x                                      0x92B6F0
#define CListWnd__SetItemColor_x                                   0x92BEC0
#define CListWnd__SetItemData_x                                    0x92BE80
#define CListWnd__SetItemText_x                                    0x92BAA0
#define CListWnd__ShiftColumnSeparator_x                           0x92A630
#define CListWnd__Sort_x                                           0x92A320
#define CListWnd__ToggleSel_x                                      0x92B720
#define CListWnd__SetColumnsSizable_x                              0x92A6E0
#define CListWnd__SetItemWnd_x                                     0x92BD50
#define CListWnd__GetItemWnd_x                                     0x928100
#define CListWnd__SetItemIcon_x                                    0x92BB20
#define CListWnd__CalculateCustomWindowPositions_x                 0x92AB80
#define CListWnd__SetVScrollPos_x                                  0x92A470

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x784F20
#define CMapViewWnd__GetWorldCoordinates_x                         0x783630
#define CMapViewWnd__HandleLButtonDown_x                           0x780670

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A4F00
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A57E0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A5D00
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A8C90
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A3A70
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AE840
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A4B20

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AB330
#define CPacketScrambler__hton_x                                   0x8AB320

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9453C0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9457D0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9455C0
#define CSidlManager__CreateLabel_x                                0x806890
#define CSidlManager__CreateXWndFromTemplate_x                     0x948730
#define CSidlManager__CreateXWndFromTemplate1_x                    0x948900
#define CSidlManager__CreateXWnd_x                                 0x8067C0
#define CSidlManager__CreateHotButtonWnd_x                         0x806D80

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x941EC0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x941DC0
#define CSidlScreenWnd__ConvertToRes_x                             0x967350
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x941860
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x941550
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x941620
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9416F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x942350
#define CSidlScreenWnd__EnableIniStorage_x                         0x942820
#define CSidlScreenWnd__GetSidlPiece_x                             0x942540
#define CSidlScreenWnd__Init1_x                                    0x941150
#define CSidlScreenWnd__LoadIniInfo_x                              0x942870
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9433A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x940560
#define CSidlScreenWnd__StoreIniInfo_x                             0x942F20
#define CSidlScreenWnd__StoreIniVis_x                              0x943280
#define CSidlScreenWnd__WndNotification_x                          0x942260
#define CSidlScreenWnd__GetChildItem_x                             0x9427A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9320C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F7F50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x683A20
#define CSkillMgr__GetSkillCap_x                                   0x683C00
#define CSkillMgr__GetNameToken_x                                  0x6831A0
#define CSkillMgr__IsActivatedSkill_x                              0x6832E0
#define CSkillMgr__IsCombatSkill_x                                 0x683220

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9520D0
#define CSliderWnd__SetValue_x                                     0x951F40
#define CSliderWnd__SetNumTicks_x                                  0x951FA0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80CA20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95A880
#define CStmlWnd__CalculateHSBRange_x                              0x95B9A0
#define CStmlWnd__CalculateVSBRange_x                              0x95B910
#define CStmlWnd__CanBreakAtCharacter_x                            0x95FCC0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x960950
#define CStmlWnd__ForceParseNow_x                                  0x95AE70
#define CStmlWnd__GetNextTagPiece_x                                0x95FC20
#define CStmlWnd__GetSTMLText_x                                    0x505150
#define CStmlWnd__GetVisibleText_x                                 0x95AE90
#define CStmlWnd__InitializeWindowVariables_x                      0x9607A0
#define CStmlWnd__MakeStmlColorTag_x                               0x959EF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x959F60
#define CStmlWnd__SetSTMLText_x                                    0x958FA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x961A20
#define CStmlWnd__UpdateHistoryString_x                            0x960B60

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9580F0
#define CTabWnd__DrawCurrentPage_x                                 0x958820
#define CTabWnd__DrawTab_x                                         0x958540
#define CTabWnd__GetCurrentPage_x                                  0x957900
#define CTabWnd__GetPageInnerRect_x                                0x957B40
#define CTabWnd__GetTabInnerRect_x                                 0x957A80
#define CTabWnd__GetTabRect_x                                      0x957930
#define CTabWnd__InsertPage_x                                      0x957D50
#define CTabWnd__SetPage_x                                         0x957BC0
#define CTabWnd__SetPageRect_x                                     0x958030
#define CTabWnd__UpdatePage_x                                      0x958400
#define CTabWnd__GetPageFromTabIndex_x                             0x958480
#define CTabWnd__GetCurrentTabIndex_x                              0x9578F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76A1C0
#define CPageWnd__SetTabText_x                                     0x957450

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8FC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92EFE0
#define CTextureFont__GetTextExtent_x                              0x92F1A0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B69A0
#define CHtmlComponentWnd__ValidateUri_x                           0x748930
#define CHtmlWnd__SetClientCallbacks_x                             0x624440
#define CHtmlWnd__AddObserver_x                                    0x624460
#define CHtmlWnd__RemoveObserver_x                                 0x6244C0
#define Window__getProgress_x                                      0x8609E0
#define Window__getStatus_x                                        0x860A00
#define Window__getURI_x                                           0x860A10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96CDF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91C1A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8640
#define CXStr__CXStr1_x                                            0x4B6320
#define CXStr__CXStr3_x                                            0x8FE130
#define CXStr__dCXStr_x                                            0x478790
#define CXStr__operator_equal_x                                    0x8FE360
#define CXStr__operator_equal1_x                                   0x8FE3A0
#define CXStr__operator_plus_equal1_x                              0x8FEE30
#define CXStr__SetString_x                                         0x900D20
#define CXStr__operator_char_p_x                                   0x8FE8A0
#define CXStr__GetChar_x                                           0x900670
#define CXStr__Delete_x                                            0x8FFF20
#define CXStr__GetUnicode_x                                        0x9006E0
#define CXStr__GetLength_x                                         0x4A8D70
#define CXStr__Mid_x                                               0x47D4D0
#define CXStr__Insert_x                                            0x900740
#define CXStr__FindNext_x                                          0x900390

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x950380
#define CXWnd__BringToTop_x                                        0x9357F0
#define CXWnd__Center_x                                            0x935370
#define CXWnd__ClrFocus_x                                          0x935190
#define CXWnd__Destroy_x                                           0x935230
#define CXWnd__DoAllDrawing_x                                      0x931880
#define CXWnd__DrawChildren_x                                      0x931850
#define CXWnd__DrawColoredRect_x                                   0x931CC0
#define CXWnd__DrawTooltip_x                                       0x9303C0
#define CXWnd__DrawTooltipAtPoint_x                                0x930480
#define CXWnd__GetBorderFrame_x                                    0x931B20
#define CXWnd__GetChildWndAt_x                                     0x935890
#define CXWnd__GetClientClipRect_x                                 0x933AC0
#define CXWnd__GetScreenClipRect_x                                 0x933B90
#define CXWnd__GetScreenRect_x                                     0x933D40
#define CXWnd__GetTooltipRect_x                                    0x931D10
#define CXWnd__GetWindowTextA_x                                    0x49CBB0
#define CXWnd__IsActive_x                                          0x932430
#define CXWnd__IsDescendantOf_x                                    0x934710
#define CXWnd__IsReallyVisible_x                                   0x934740
#define CXWnd__IsType_x                                            0x935EF0
#define CXWnd__Move_x                                              0x9347A0
#define CXWnd__Move1_x                                             0x934850
#define CXWnd__ProcessTransition_x                                 0x935320
#define CXWnd__Refade_x                                            0x934B10
#define CXWnd__Resize_x                                            0x934DA0
#define CXWnd__Right_x                                             0x9355B0
#define CXWnd__SetFocus_x                                          0x935150
#define CXWnd__SetFont_x                                           0x9351C0
#define CXWnd__SetKeyTooltip_x                                     0x935D10
#define CXWnd__SetMouseOver_x                                      0x932C30
#define CXWnd__StartFade_x                                         0x9345F0
#define CXWnd__GetChildItem_x                                      0x935A00
#define CXWnd__SetParent_x                                         0x9344C0
#define CXWnd__Minimize_x                                          0x934E10

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9683D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x938710
#define CXWndManager__DrawWindows_x                                0x938730
#define CXWndManager__GetKeyboardFlags_x                           0x93AE30
#define CXWndManager__HandleKeyboardMsg_x                          0x93A9F0
#define CXWndManager__RemoveWnd_x                                  0x93B050
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93B5B0

// CDBStr
#define CDBStr__GetString_x                                        0x53CA20

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB9D0
#define EQ_Character__Cur_HP_x                                     0x4D2140
#define EQ_Character__Cur_Mana_x                                   0x4D9860
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEA40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B24E0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2630
#define EQ_Character__GetHPRegen_x                                 0x4DF600
#define EQ_Character__GetEnduranceRegen_x                          0x4DFC00
#define EQ_Character__GetManaRegen_x                               0x4E0040
#define EQ_Character__Max_Endurance_x                              0x64A110
#define EQ_Character__Max_HP_x                                     0x4D1F70
#define EQ_Character__Max_Mana_x                                   0x649F10
#define EQ_Character__doCombatAbility_x                            0x64C570
#define EQ_Character__UseSkill_x                                   0x4E1E20
#define EQ_Character__GetConLevel_x                                0x643480
#define EQ_Character__IsExpansionFlag_x                            0x5A6F10
#define EQ_Character__TotalEffect_x                                0x4C5490
#define EQ_Character__GetPCSpellAffect_x                           0x4BF790
#define EQ_Character__SpellDuration_x                              0x4BF2C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4EC0
#define EQ_Character__GetBaseSkill_x                               0x4D5E60
#define EQ_Character__CanUseItem_x                                 0x4D9B70

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CA6F0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x660660

//PcClient
#define PcClient__PcClient_x                                       0x640BC0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9640
#define CCharacterListWnd__EnterWorld_x                            0x4B9080
#define CCharacterListWnd__Quit_x                                  0x4B8DD0
#define CCharacterListWnd__UpdateList_x                            0x4B9210

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x625680
#define EQ_Item__CreateItemTagString_x                             0x8A4B70
#define EQ_Item__IsStackable_x                                     0x8A96C0
#define EQ_Item__GetImageNum_x                                     0x8A65C0
#define EQ_Item__CreateItemClient_x                                0x624840
#define EQ_Item__GetItemValue_x                                    0x8A78B0
#define EQ_Item__ValueSellMerchant_x                               0x8AAF00
#define EQ_Item__IsKeyRingItem_x                                   0x8A8FC0
#define EQ_Item__CanGoInBag_x                                      0x6257A0
#define EQ_Item__IsEmpty_x                                         0x8A8B20
#define EQ_Item__GetMaxItemCount_x                                 0x8A7CD0
#define EQ_Item__GetHeldItem_x                                     0x8A6490
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A44D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55AE00
#define EQ_LoadingS__Array_x                                       0xC26B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64AA70
#define EQ_PC__GetAlternateAbilityId_x                             0x8B4150
#define EQ_PC__GetCombatAbility_x                                  0x8B47C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B4830
#define EQ_PC__GetItemRecastTimer_x                                0x64CAF0
#define EQ_PC__HasLoreItem_x                                       0x643C40
#define EQ_PC__AlertInventoryChanged_x                             0x642DC0
#define EQ_PC__GetPcZoneClient_x                                   0x66F1D0
#define EQ_PC__RemoveMyAffect_x                                    0x64FD20
#define EQ_PC__GetKeyRingItems_x                                   0x8B50C0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B4E50
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B53C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AD470
#define EQItemList__add_object_x                                   0x5DAD70
#define EQItemList__add_item_x                                     0x5AD9D0
#define EQItemList__delete_item_x                                  0x5ADA20
#define EQItemList__FreeItemList_x                                 0x5AD920

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x539540

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x661EE0
#define EQPlayer__dEQPlayer_x                                      0x655230
#define EQPlayer__DoAttack_x                                       0x669E60
#define EQPlayer__EQPlayer_x                                       0x6558F0
#define EQPlayer__SetNameSpriteState_x                             0x659BC0
#define EQPlayer__SetNameSpriteTint_x                              0x65AA90
#define PlayerBase__HasProperty_j_x                                0x99AC50
#define EQPlayer__IsTargetable_x                                   0x99B0F0
#define EQPlayer__CanSee_x                                         0x99AF50
#define EQPlayer__CanSee1_x                                        0x99B020
#define PlayerBase__GetVisibilityLineSegment_x                     0x99AD10

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66CC60
#define PlayerZoneClient__GetLevel_x                               0x66F210
#define PlayerZoneClient__IsValidTeleport_x                        0x5DBEF0
#define PlayerZoneClient__LegalPlayerRace_x                        0x554240

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x664D70
#define EQPlayerManager__GetSpawnByName_x                          0x664E20
#define EQPlayerManager__GetPlayerFromPartialName_x                0x664EB0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x628D70
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x628DF0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x628E30
#define KeypressHandler__ClearCommandStateArray_x                  0x62A240
#define KeypressHandler__HandleKeyDown_x                           0x62A260
#define KeypressHandler__HandleKeyUp_x                             0x62A300
#define KeypressHandler__SaveKeymapping_x                          0x62A750

// MapViewMap 
#define MapViewMap__Clear_x                                        0x780D90
#define MapViewMap__SaveEx_x                                       0x784150
#define MapViewMap__SetZoom_x                                      0x788810

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C85E0

// StringTable 
#define StringTable__getString_x                                   0x8C3400

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64F990
#define PcZoneClient__RemovePetEffect_x                            0x64FFC0
#define PcZoneClient__HasAlternateAbility_x                        0x649D40
#define PcZoneClient__GetCurrentMod_x                              0x4E4EE0
#define PcZoneClient__GetModCap_x                                  0x4E4DE0
#define PcZoneClient__CanEquipItem_x                               0x64A410
#define PcZoneClient__GetItemByID_x                                0x64CF60
#define PcZoneClient__GetItemByItemClass_x                         0x64D0B0
#define PcZoneClient__RemoveBuffEffect_x                           0x64FFE0
#define PcZoneClient__BandolierSwap_x                              0x64B030
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64CA90

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E09B0

//IconCache
#define IconCache__GetIcon_x                                       0x721330

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x718E10
#define CContainerMgr__CloseContainer_x                            0x7190E0
#define CContainerMgr__OpenExperimentContainer_x                   0x719B60

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D8CD0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61D820

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7772A0
#define CLootWnd__RequestLootSlot_x                                0x7764D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57AA10
#define EQ_Spell__SpellAffects_x                                   0x57AE80
#define EQ_Spell__SpellAffectBase_x                                0x57AC40
#define EQ_Spell__IsStackable_x                                    0x4C9B60
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C99E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B69C0
#define EQ_Spell__IsSPAStacking_x                                  0x57BCD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57B1E0
#define EQ_Spell__IsNoRemove_x                                     0x4C9B40
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57BCE0
#define __IsResEffectSpell_x                                       0x4C8ED0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD020

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D2C40

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81FCC0
#define CTargetWnd__WndNotification_x                              0x81F550
#define CTargetWnd__RefreshTargetBuffs_x                           0x81F820
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81E6C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8242D0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536F30
#define CTaskManager__HandleMessage_x                              0x5353A0
#define CTaskManager__GetTaskStatus_x                              0x536FE0
#define CTaskManager__GetElementDescription_x                      0x537060

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575F80
#define EqSoundManager__PlayScriptMp3_x                            0x5760E0
#define EqSoundManager__SoundAssistPlay_x                          0x687950
#define EqSoundManager__WaveInstancePlay_x                         0x686EC0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52AC20

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x956960

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5628D0
#define CAltAbilityData__GetMercMaxRank_x                          0x562860
#define CAltAbilityData__GetMaxRank_x                              0x557EE0

//CTargetRing
#define CTargetRing__Cast_x                                        0x61B940

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C99C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x511F20
#define CharacterBase__CreateItemIndex_x                           0x623A00
#define CharacterBase__GetItemPossession_x                         0x4FDA80
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DB240
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DB2A0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FFF60
#define CCastSpellWnd__IsBardSongPlaying_x                         0x700790
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x700840

//messages
#define msg_spell_worn_off_x                                       0x59F0F0
#define msg_new_text_x                                             0x593E90
#define __msgTokenTextParam_x                                      0x5A1620
#define msgTokenText_x                                             0x5A1870

//SpellManager
#define SpellManager__vftable_x                                    0xAEC4CC
#define SpellManager__SpellManager_x                               0x68AC80
#define Spellmanager__LoadTextSpells_x                             0x68B570
#define SpellManager__GetSpellByGroupAndRank_x                     0x68AE50

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99EB30

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x512570
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A53C0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63C380
#define ItemGlobalIndex__IsValidIndex_x                            0x5125D0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D35E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D3860

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76FB20

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71D520
#define CCursorAttachment__AttachToCursor1_x                       0x71D560
#define CCursorAttachment__Deactivate_x                            0x71E540

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x949750
#define CSidlManagerBase__CreatePageWnd_x                          0x948F50
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9451E0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x945170

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9668B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x966570

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F490
#define CFindItemWnd__WndNotification_x                            0x50FF70
#define CFindItemWnd__Update_x                                     0x510AE0
#define CFindItemWnd__PickupSelectedItem_x                         0x50ECE0

//IString
#define IString__Append_x                                          0x4F04E0

//Camera
#define CDisplay__cameraType_x                                     0xE000D0
#define EverQuest__Cameras_x                                       0xEC3A7C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517C00
#define LootFiltersManager__GetItemFilterData_x                    0x517510
#define LootFiltersManager__RemoveItemLootFilter_x                 0x517540
#define LootFiltersManager__SetItemLootFilter_x                    0x517760

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C6C90

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A46F0
#define CResolutionHandler__GetWindowedStyle_x                     0x682600

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x715BE0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E8610
#define CDistillerInfo__Instance_x                                 0x8E85B0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x735CF0
#define CGroupWnd__UpdateDisplay_x                                 0x735050

//ItemBase
#define ItemBase__IsLore_x                                         0x8A9070
#define ItemBase__IsLoreEquipped_x                                 0x8A90F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DACD0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DAE10
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DAE70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6778F0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67B280

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505750

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F20C0
#define FactionManagerClient__HandleFactionMessage_x               0x4F2730
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2CF0
#define FactionManagerClient__GetMaxFaction_x                      0x4F2D0F
#define FactionManagerClient__GetMinFaction_x                      0x4F2CC0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FDA50

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92DF90

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BEC0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FDD30

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x561D70

//CTargetManager
#define CTargetManager__Get_x                                      0x68E4A0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6778F0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D80

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AD8C0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF61110

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
