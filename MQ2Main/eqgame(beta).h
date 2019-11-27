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
#define __ExpectedVersionDate                                     "Nov 27 2019"
#define __ExpectedVersionTime                                     "04:23:08"
#define __ActualVersionDate_x                                      0xB092B0
#define __ActualVersionTime_x                                      0xB092A4
#define __ActualVersionBuild_x                                     0xAF4F7C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62EBD0
#define __MemChecker1_x                                            0x9018D0
#define __MemChecker2_x                                            0x6BD070
#define __MemChecker3_x                                            0x6BCFC0
#define __MemChecker4_x                                            0x858C30
#define __EncryptPad0_x                                            0xC3F3E8
#define __EncryptPad1_x                                            0xC9D5E8
#define __EncryptPad2_x                                            0xC4FC80
#define __EncryptPad3_x                                            0xC4F880
#define __EncryptPad4_x                                            0xC8DC00
#define __EncryptPad5_x                                            0xF691C0
#define __AC1_x                                                    0x815306
#define __AC2_x                                                    0x5E8A2F
#define __AC3_x                                                    0x5F012F
#define __AC4_x                                                    0x5F4100
#define __AC5_x                                                    0x5FA40F
#define __AC6_x                                                    0x5FEA26
#define __AC7_x                                                    0x5E84A0
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
#define __do_loot_x                                                0x5B4490
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
#define __gfMaxZoomCameraDistance_x                                0xAFEC10
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
#define __CastRay_x                                                0x5AF8F0
#define __CastRay2_x                                               0x5AF940
#define __ConvertItemTags_x                                        0x5CB4A0
#define __CleanItemTags_x                                          0x47D0E0
#define __DoesFileExist_x                                          0x904960
#define __EQGetTime_x                                              0x9013A0
#define __ExecuteCmd_x                                             0x5A8140
#define __FixHeading_x                                             0x99C080
#define __GameLoop_x                                               0x6BC260
#define __get_bearing_x                                            0x5AF460
#define __get_melee_range_x                                        0x5AFB30
#define __GetAnimationCache_x                                      0x721460
#define __GetGaugeValueFromEQ_x                                    0x8137B0
#define __GetLabelFromEQ_x                                         0x815290
#define __GetXTargetType_x                                         0x99DA60
#define __HandleMouseWheel_x                                       0x6BD120
#define __HeadingDiff_x                                            0x99C0F0
#define __HelpPath_x                                               0xF617DC
#define __LoadFrontEnd_x                                           0x6B9580
#define __NewUIINI_x                                               0x813480
#define __ProcessGameEvents_x                                      0x610290
#define __ProcessMouseEvent_x                                      0x60FA50
#define __SaveColors_x                                             0x552430
#define __STMLToText_x                                             0x93F3B0
#define __ToggleKeyRingItem_x                                      0x515720
#define CMemoryMappedFile__SetFile_x                               0xA8B2F0
#define CrashDetected_x                                            0x6BB020
#define DrawNetStatus_x                                            0x63BEB0
#define Expansion_HoT_x                                            0xEC372C
#define Teleport_Table_Size_x                                      0xEB2760
#define Teleport_Table_x                                           0xEB2BC8
#define Util__FastTime_x                                           0x900F70

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4993A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499170
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A30
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559FE0
#define AltAdvManager__IsAbilityReady_x                            0x558F10
#define AltAdvManager__GetAAById_x                                 0x559110
#define AltAdvManager__CanTrainAbility_x                           0x559180
#define AltAdvManager__CanSeeAbility_x                             0x5594E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA3A0
#define CharacterZoneClient__HasSkill_x                            0x4D5290
#define CharacterZoneClient__MakeMeVisible_x                       0x4D69B0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE690
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAC90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9310
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D93F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D94D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3490
#define CharacterZoneClient__BardCastBard_x                        0x4C5FF0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAD60
#define CharacterZoneClient__GetEffect_x                           0x4BABD0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C44E0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C45B0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4600
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4750
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4920
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2AF0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7910
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7390

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E2CE0
#define CBankWnd__WndNotification_x                                0x6E2AC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F0410

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61E9A0
#define CButtonWnd__CButtonWnd_x                                   0x93B780

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x710600
#define CChatManager__InitContextMenu_x                            0x709750
#define CChatManager__FreeChatWindow_x                             0x70F140
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E88C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x710280
#define CChatManager__CreateChatWindow_x                           0x70F780

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E89D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94FDF0
#define CContextMenu__dCContextMenu_x                              0x950030
#define CContextMenu__AddMenuItem_x                                0x950040
#define CContextMenu__RemoveMenuItem_x                             0x950350
#define CContextMenu__RemoveAllMenuItems_x                         0x950370
#define CContextMenu__CheckMenuItem_x                              0x9503F0
#define CContextMenu__SetMenuItem_x                                0x950270
#define CContextMenu__AddSeparator_x                               0x9501D0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x950990
#define CContextMenuManager__RemoveMenu_x                          0x950A00
#define CContextMenuManager__PopupMenu_x                           0x950AC0
#define CContextMenuManager__Flush_x                               0x950930
#define CContextMenuManager__GetMenu_x                             0x49B5C0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71BC60

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DCBE0
#define CChatService__GetFriendName_x                              0x8DCBF0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x710E70
#define CChatWindow__Clear_x                                       0x712130
#define CChatWindow__WndNotification_x                             0x7128C0
#define CChatWindow__AddHistory_x                                  0x7119F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94D250
#define CComboWnd__Draw_x                                          0x94C750
#define CComboWnd__GetCurChoice_x                                  0x94D090
#define CComboWnd__GetListRect_x                                   0x94CC00
#define CComboWnd__GetTextRect_x                                   0x94D2C0
#define CComboWnd__InsertChoice_x                                  0x94CD90
#define CComboWnd__SetColors_x                                     0x94CD60
#define CComboWnd__SetChoice_x                                     0x94D060
#define CComboWnd__GetItemCount_x                                  0x94D0A0
#define CComboWnd__GetCurChoiceText_x                              0x94D0E0
#define CComboWnd__GetChoiceText_x                                 0x94D0B0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94CE20

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x719650
#define CContainerWnd__vftable_x                                   0xB1249C
#define CContainerWnd__SetContainer_x                              0x71ABB0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54CE60
#define CDisplay__PreZoneMainUI_x                                  0x54CE70
#define CDisplay__CleanGameUI_x                                    0x5521F0
#define CDisplay__GetClickedActor_x                                0x545180
#define CDisplay__GetUserDefinedColor_x                            0x53D840
#define CDisplay__GetWorldFilePath_x                               0x546BF0
#define CDisplay__is3dON_x                                         0x541DE0
#define CDisplay__ReloadUI_x                                       0x54C2F0
#define CDisplay__WriteTextHD2_x                                   0x541BD0
#define CDisplay__TrueDistance_x                                   0x5488B0
#define CDisplay__SetViewActor_x                                   0x544AA0
#define CDisplay__GetFloorHeight_x                                 0x541EA0
#define CDisplay__SetRenderWindow_x                                0x540800
#define CDisplay__ToggleScreenshotMode_x                           0x544570

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96FC00

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x95336F
#define CEditWnd__GetCharIndexPt_x                                 0x9542A0
#define CEditWnd__GetDisplayString_x                               0x954140
#define CEditWnd__GetHorzOffset_x                                  0x9529A0
#define CEditWnd__GetLineForPrintableChar_x                        0x955440
#define CEditWnd__GetSelStartPt_x                                  0x954550
#define CEditWnd__GetSTMLSafeText_x                                0x953F60
#define CEditWnd__PointFromPrintableChar_x                         0x955070
#define CEditWnd__SelectableCharFromPoint_x                        0x9551E0
#define CEditWnd__SetEditable_x                                    0x954620
#define CEditWnd__SetWindowTextA_x                                 0x953CE0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FDF00
#define CEverQuest__ClickedPlayer_x                                0x5EFF10
#define CEverQuest__CreateTargetIndicator_x                        0x60D530
#define CEverQuest__DeleteTargetIndicator_x                        0x60D5C0
#define CEverQuest__DoTellWindow_x                                 0x4E8AB0
#define CEverQuest__OutputTextToLog_x                              0x4E8D30
#define CEverQuest__DropHeldItemOnGround_x                         0x5E4F50
#define CEverQuest__dsp_chat_x                                     0x4E90C0
#define CEverQuest__trimName_x                                     0x609810
#define CEverQuest__Emote_x                                        0x5FE760
#define CEverQuest__EnterZone_x                                    0x5F86E0
#define CEverQuest__GetBodyTypeDesc_x                              0x6030D0
#define CEverQuest__GetClassDesc_x                                 0x603710
#define CEverQuest__GetClassThreeLetterCode_x                      0x603D10
#define CEverQuest__GetDeityDesc_x                                 0x60BE70
#define CEverQuest__GetLangDesc_x                                  0x603ED0
#define CEverQuest__GetRaceDesc_x                                  0x6036F0
#define CEverQuest__InterpretCmd_x                                 0x60C440
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E9150
#define CEverQuest__LMouseUp_x                                     0x5E74E0
#define CEverQuest__RightClickedOnPlayer_x                         0x5E9A30
#define CEverQuest__RMouseUp_x                                     0x5E8460
#define CEverQuest__SetGameState_x                                 0x5E4CE0
#define CEverQuest__UPCNotificationFlush_x                         0x609710
#define CEverQuest__IssuePetCommand_x                              0x6052D0
#define CEverQuest__ReportSuccessfulHit_x                          0x5FFB50

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72B590
#define CGaugeWnd__CalcLinesFillRect_x                             0x72B5F0
#define CGaugeWnd__Draw_x                                          0x72AC10

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF4D0
#define CGuild__GetGuildName_x                                     0x4AE5B0
#define CGuild__GetGuildIndex_x                                    0x4AE940

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x746B30

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61ED60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x753AD0
#define CInvSlotMgr__MoveItem_x                                    0x752840
#define CInvSlotMgr__SelectSlot_x                                  0x753BA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7510C0
#define CInvSlot__SliderComplete_x                                 0x74EE20
#define CInvSlot__GetItemBase_x                                    0x74E7C0
#define CInvSlot__UpdateItem_x                                     0x74E930

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x755620
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7547C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7551A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80EB40
#define CItemDisplayWnd__UpdateStrings_x                           0x763BE0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75D920
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75DE40
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7641D0
#define CItemDisplayWnd__AboutToShow_x                             0x763820
#define CItemDisplayWnd__WndNotification_x                         0x7652B0
#define CItemDisplayWnd__RequestConvertItem_x                      0x764D70
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x762880
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x763640

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x847740

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7697C0

// CLabel 
#define CLabel__Draw_x                                             0x76F270

// CListWnd
#define CListWnd__CListWnd_x                                       0x925A20
#define CListWnd__dCListWnd_x                                      0x925D40
#define CListWnd__AddColumn_x                                      0x92A1B0
#define CListWnd__AddColumn1_x                                     0x92A200
#define CListWnd__AddLine_x                                        0x92A590
#define CListWnd__AddString_x                                      0x92A390
#define CListWnd__CalculateFirstVisibleLine_x                      0x929F70
#define CListWnd__CalculateVSBRange_x                              0x929D50
#define CListWnd__ClearSel_x                                       0x92AD70
#define CListWnd__ClearAllSel_x                                    0x92ADD0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92B7F0
#define CListWnd__Compare_x                                        0x929690
#define CListWnd__Draw_x                                           0x925E70
#define CListWnd__DrawColumnSeparators_x                           0x928660
#define CListWnd__DrawHeader_x                                     0x928AD0
#define CListWnd__DrawItem_x                                       0x928FD0
#define CListWnd__DrawLine_x                                       0x9287D0
#define CListWnd__DrawSeparator_x                                  0x928700
#define CListWnd__EnableLine_x                                     0x927F30
#define CListWnd__EnsureVisible_x                                  0x92B710
#define CListWnd__ExtendSel_x                                      0x92ACA0
#define CListWnd__GetColumnTooltip_x                               0x927A70
#define CListWnd__GetColumnMinWidth_x                              0x927AE0
#define CListWnd__GetColumnWidth_x                                 0x9279E0
#define CListWnd__GetCurSel_x                                      0x927370
#define CListWnd__GetItemAtPoint_x                                 0x9281B0
#define CListWnd__GetItemAtPoint1_x                                0x928220
#define CListWnd__GetItemData_x                                    0x9273F0
#define CListWnd__GetItemHeight_x                                  0x9277B0
#define CListWnd__GetItemIcon_x                                    0x927580
#define CListWnd__GetItemRect_x                                    0x928020
#define CListWnd__GetItemText_x                                    0x927430
#define CListWnd__GetSelList_x                                     0x92AE20
#define CListWnd__GetSeparatorRect_x                               0x928460
#define CListWnd__InsertLine_x                                     0x92A980
#define CListWnd__RemoveLine_x                                     0x92AAD0
#define CListWnd__SetColors_x                                      0x929D30
#define CListWnd__SetColumnJustification_x                         0x929A60
#define CListWnd__SetColumnWidth_x                                 0x929980
#define CListWnd__SetCurSel_x                                      0x92ABE0
#define CListWnd__SetItemColor_x                                   0x92B3C0
#define CListWnd__SetItemData_x                                    0x92B380
#define CListWnd__SetItemText_x                                    0x92AF90
#define CListWnd__ShiftColumnSeparator_x                           0x929B20
#define CListWnd__Sort_x                                           0x929810
#define CListWnd__ToggleSel_x                                      0x92AC10
#define CListWnd__SetColumnsSizable_x                              0x929BD0
#define CListWnd__SetItemWnd_x                                     0x92B240
#define CListWnd__GetItemWnd_x                                     0x9275D0
#define CListWnd__SetItemIcon_x                                    0x92B010
#define CListWnd__CalculateCustomWindowPositions_x                 0x92A070
#define CListWnd__SetVScrollPos_x                                  0x929960

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x784940
#define CMapViewWnd__GetWorldCoordinates_x                         0x783050
#define CMapViewWnd__HandleLButtonDown_x                           0x780090

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A4860
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A5140
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A5670
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A85F0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A33D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AE1A0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A4470

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AA760
#define CPacketScrambler__hton_x                                   0x8AA750

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x944A00
#define CSidlManager__FindScreenPieceTemplate_x                    0x944E10
#define CSidlManager__FindScreenPieceTemplate1_x                   0x944C00
#define CSidlManager__CreateLabel_x                                0x805F40
#define CSidlManager__CreateXWndFromTemplate_x                     0x947D70
#define CSidlManager__CreateXWndFromTemplate1_x                    0x947F50
#define CSidlManager__CreateXWnd_x                                 0x805E70
#define CSidlManager__CreateHotButtonWnd_x                         0x806430

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9414E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9413E0
#define CSidlScreenWnd__ConvertToRes_x                             0x966BF0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x940E70
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x940B60
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x940C30
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x940D00
#define CSidlScreenWnd__DrawSidlPiece_x                            0x941980
#define CSidlScreenWnd__EnableIniStorage_x                         0x941E50
#define CSidlScreenWnd__GetSidlPiece_x                             0x941B70
#define CSidlScreenWnd__Init1_x                                    0x940760
#define CSidlScreenWnd__LoadIniInfo_x                              0x941EA0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9429E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93FB60
#define CSidlScreenWnd__StoreIniInfo_x                             0x942560
#define CSidlScreenWnd__StoreIniVis_x                              0x9428C0
#define CSidlScreenWnd__WndNotification_x                          0x941890
#define CSidlScreenWnd__GetChildItem_x                             0x941DD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9315D0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F7F50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x683650
#define CSkillMgr__GetSkillCap_x                                   0x683830
#define CSkillMgr__GetNameToken_x                                  0x682DD0
#define CSkillMgr__IsActivatedSkill_x                              0x682F10
#define CSkillMgr__IsCombatSkill_x                                 0x682E50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x951770
#define CSliderWnd__SetValue_x                                     0x9515E0
#define CSliderWnd__SetNumTicks_x                                  0x951640

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80BFD0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x959FA0
#define CStmlWnd__CalculateHSBRange_x                              0x95B080
#define CStmlWnd__CalculateVSBRange_x                              0x95AFF0
#define CStmlWnd__CanBreakAtCharacter_x                            0x95F3C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x960050
#define CStmlWnd__ForceParseNow_x                                  0x95A540
#define CStmlWnd__GetNextTagPiece_x                                0x95F320
#define CStmlWnd__GetSTMLText_x                                    0x505040
#define CStmlWnd__GetVisibleText_x                                 0x95A560
#define CStmlWnd__InitializeWindowVariables_x                      0x95FEA0
#define CStmlWnd__MakeStmlColorTag_x                               0x959610
#define CStmlWnd__MakeWndNotificationTag_x                         0x959680
#define CStmlWnd__SetSTMLText_x                                    0x9586C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x961150
#define CStmlWnd__UpdateHistoryString_x                            0x960260

// CTabWnd 
#define CTabWnd__Draw_x                                            0x957810
#define CTabWnd__DrawCurrentPage_x                                 0x957F40
#define CTabWnd__DrawTab_x                                         0x957C60
#define CTabWnd__GetCurrentPage_x                                  0x957010
#define CTabWnd__GetPageInnerRect_x                                0x957250
#define CTabWnd__GetTabInnerRect_x                                 0x957190
#define CTabWnd__GetTabRect_x                                      0x957040
#define CTabWnd__InsertPage_x                                      0x957460
#define CTabWnd__SetPage_x                                         0x9572D0
#define CTabWnd__SetPageRect_x                                     0x957750
#define CTabWnd__UpdatePage_x                                      0x957B20
#define CTabWnd__GetPageFromTabIndex_x                             0x957BA0
#define CTabWnd__GetCurrentTabIndex_x                              0x957000

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x769C20
#define CPageWnd__SetTabText_x                                     0x956B50

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9160

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92E440
#define CTextureFont__GetTextExtent_x                              0x92E600

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B63F0
#define CHtmlComponentWnd__ValidateUri_x                           0x748520
#define CHtmlWnd__SetClientCallbacks_x                             0x623DC0
#define CHtmlWnd__AddObserver_x                                    0x623DE0
#define CHtmlWnd__RemoveObserver_x                                 0x623E40
#define Window__getProgress_x                                      0x8601F0
#define Window__getStatus_x                                        0x860210
#define Window__getURI_x                                           0x860220

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96C690

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91B6F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8700
#define CXStr__CXStr1_x                                            0x500170
#define CXStr__CXStr3_x                                            0x8FD4E0
#define CXStr__dCXStr_x                                            0x478670
#define CXStr__operator_equal_x                                    0x8FD710
#define CXStr__operator_equal1_x                                   0x8FD750
#define CXStr__operator_plus_equal1_x                              0x8FE1E0
#define CXStr__SetString_x                                         0x9000D0
#define CXStr__operator_char_p_x                                   0x8FDC20
#define CXStr__GetChar_x                                           0x8FFA00
#define CXStr__Delete_x                                            0x8FF2D0
#define CXStr__GetUnicode_x                                        0x8FFA70
#define CXStr__GetLength_x                                         0x4A8F10
#define CXStr__Mid_x                                               0x47D490
#define CXStr__Insert_x                                            0x8FFAD0
#define CXStr__FindNext_x                                          0x8FF740

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94FA10
#define CXWnd__BringToTop_x                                        0x934D40
#define CXWnd__Center_x                                            0x9348C0
#define CXWnd__ClrFocus_x                                          0x9346D0
#define CXWnd__Destroy_x                                           0x934780
#define CXWnd__DoAllDrawing_x                                      0x930D60
#define CXWnd__DrawChildren_x                                      0x930D30
#define CXWnd__DrawColoredRect_x                                   0x9311C0
#define CXWnd__DrawTooltip_x                                       0x92F870
#define CXWnd__DrawTooltipAtPoint_x                                0x92F930
#define CXWnd__GetBorderFrame_x                                    0x931020
#define CXWnd__GetChildWndAt_x                                     0x934DE0
#define CXWnd__GetClientClipRect_x                                 0x933000
#define CXWnd__GetScreenClipRect_x                                 0x9330D0
#define CXWnd__GetScreenRect_x                                     0x933290
#define CXWnd__GetTooltipRect_x                                    0x931210
#define CXWnd__GetWindowTextA_x                                    0x49CCA0
#define CXWnd__IsActive_x                                          0x931950
#define CXWnd__IsDescendantOf_x                                    0x933C90
#define CXWnd__IsReallyVisible_x                                   0x933CC0
#define CXWnd__IsType_x                                            0x935450
#define CXWnd__Move_x                                              0x933D20
#define CXWnd__Move1_x                                             0x933DD0
#define CXWnd__ProcessTransition_x                                 0x934870
#define CXWnd__Refade_x                                            0x9340B0
#define CXWnd__Resize_x                                            0x934340
#define CXWnd__Right_x                                             0x934B00
#define CXWnd__SetFocus_x                                          0x934690
#define CXWnd__SetFont_x                                           0x934700
#define CXWnd__SetKeyTooltip_x                                     0x935270
#define CXWnd__SetMouseOver_x                                      0x932160
#define CXWnd__StartFade_x                                         0x933B70
#define CXWnd__GetChildItem_x                                      0x934F50
#define CXWnd__SetParent_x                                         0x933A30
#define CXWnd__Minimize_x                                          0x9343A0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x967C70

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x937C20
#define CXWndManager__DrawWindows_x                                0x937C40
#define CXWndManager__GetKeyboardFlags_x                           0x93A400
#define CXWndManager__HandleKeyboardMsg_x                          0x939FB0
#define CXWndManager__RemoveWnd_x                                  0x93A630
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93AB90

// CDBStr
#define CDBStr__GetString_x                                        0x53C810

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBC70
#define EQ_Character__Cur_HP_x                                     0x4D22D0
#define EQ_Character__Cur_Mana_x                                   0x4D99D0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BECE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2730
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2880
#define EQ_Character__GetHPRegen_x                                 0x4DF770
#define EQ_Character__GetEnduranceRegen_x                          0x4DFD70
#define EQ_Character__GetManaRegen_x                               0x4E01B0
#define EQ_Character__Max_Endurance_x                              0x64A050
#define EQ_Character__Max_HP_x                                     0x4D2100
#define EQ_Character__Max_Mana_x                                   0x649E50
#define EQ_Character__doCombatAbility_x                            0x64C4A0
#define EQ_Character__UseSkill_x                                   0x4E1F80
#define EQ_Character__GetConLevel_x                                0x642E70
#define EQ_Character__IsExpansionFlag_x                            0x5A6900
#define EQ_Character__TotalEffect_x                                0x4C5730
#define EQ_Character__GetPCSpellAffect_x                           0x4BFA30
#define EQ_Character__SpellDuration_x                              0x4BF560
#define EQ_Character__GetAdjustedSkill_x                           0x4D5050
#define EQ_Character__GetBaseSkill_x                               0x4D5FF0
#define EQ_Character__CanUseItem_x                                 0x4D9CE0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C9A50

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x660590

//PcClient
#define PcClient__PcClient_x                                       0x6405A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B98C0
#define CCharacterListWnd__EnterWorld_x                            0x4B9300
#define CCharacterListWnd__Quit_x                                  0x4B9050
#define CCharacterListWnd__UpdateList_x                            0x4B9490

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x624FF0
#define EQ_Item__CreateItemTagString_x                             0x8A3FC0
#define EQ_Item__IsStackable_x                                     0x8A8B10
#define EQ_Item__GetImageNum_x                                     0x8A59F0
#define EQ_Item__CreateItemClient_x                                0x6241C0
#define EQ_Item__GetItemValue_x                                    0x8A6CE0
#define EQ_Item__ValueSellMerchant_x                               0x8AA330
#define EQ_Item__IsKeyRingItem_x                                   0x8A8410
#define EQ_Item__CanGoInBag_x                                      0x625110
#define EQ_Item__IsEmpty_x                                         0x8A7F80
#define EQ_Item__GetMaxItemCount_x                                 0x8A7100
#define EQ_Item__GetHeldItem_x                                     0x8A58C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A3920

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55ACB0
#define EQ_LoadingS__Array_x                                       0xC26B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64A9B0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B3540
#define EQ_PC__GetCombatAbility_x                                  0x8B3BB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B3C20
#define EQ_PC__GetItemRecastTimer_x                                0x64CA20
#define EQ_PC__HasLoreItem_x                                       0x643630
#define EQ_PC__AlertInventoryChanged_x                             0x6427A0
#define EQ_PC__GetPcZoneClient_x                                   0x66F170
#define EQ_PC__RemoveMyAffect_x                                    0x64FC50
#define EQ_PC__GetKeyRingItems_x                                   0x8B44B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B4240
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B47B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5ACE70
#define EQItemList__add_object_x                                   0x5DA800
#define EQItemList__add_item_x                                     0x5AD3D0
#define EQItemList__delete_item_x                                  0x5AD420
#define EQItemList__FreeItemList_x                                 0x5AD320

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x539330

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x661E10
#define EQPlayer__dEQPlayer_x                                      0x655170
#define EQPlayer__DoAttack_x                                       0x669E10
#define EQPlayer__EQPlayer_x                                       0x655830
#define EQPlayer__SetNameSpriteState_x                             0x659AF0
#define EQPlayer__SetNameSpriteTint_x                              0x65A9C0
#define PlayerBase__HasProperty_j_x                                0x99A420
#define EQPlayer__IsTargetable_x                                   0x99A8C0
#define EQPlayer__CanSee_x                                         0x99A720
#define EQPlayer__CanSee1_x                                        0x99A7F0
#define PlayerBase__GetVisibilityLineSegment_x                     0x99A4E0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66CC10
#define PlayerZoneClient__GetLevel_x                               0x66F1B0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DB970
#define PlayerZoneClient__LegalPlayerRace_x                        0x554020

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x664D00
#define EQPlayerManager__GetSpawnByName_x                          0x664DB0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x664E40

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6286E0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x628760
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6287A0
#define KeypressHandler__ClearCommandStateArray_x                  0x629BB0
#define KeypressHandler__HandleKeyDown_x                           0x629BD0
#define KeypressHandler__HandleKeyUp_x                             0x629C70
#define KeypressHandler__SaveKeymapping_x                          0x62A0C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7807B0
#define MapViewMap__SaveEx_x                                       0x783B70
#define MapViewMap__SetZoom_x                                      0x788230

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C7970

// StringTable 
#define StringTable__getString_x                                   0x8C27B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64F8C0
#define PcZoneClient__RemovePetEffect_x                            0x64FEF0
#define PcZoneClient__HasAlternateAbility_x                        0x649C80
#define PcZoneClient__GetCurrentMod_x                              0x4E5040
#define PcZoneClient__GetModCap_x                                  0x4E4F40
#define PcZoneClient__CanEquipItem_x                               0x64A350
#define PcZoneClient__GetItemByID_x                                0x64CE90
#define PcZoneClient__GetItemByItemClass_x                         0x64CFE0
#define PcZoneClient__RemoveBuffEffect_x                           0x64FF10
#define PcZoneClient__BandolierSwap_x                              0x64AF60
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64C9C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E0420

//IconCache
#define IconCache__GetIcon_x                                       0x720D00

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7187F0
#define CContainerMgr__CloseContainer_x                            0x718AC0
#define CContainerMgr__OpenExperimentContainer_x                   0x719540

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D85F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61D180

//CLootWnd
#define CLootWnd__LootAll_x                                        0x776D50
#define CLootWnd__RequestLootSlot_x                                0x775F80

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57A9C0
#define EQ_Spell__SpellAffects_x                                   0x57AE30
#define EQ_Spell__SpellAffectBase_x                                0x57ABF0
#define EQ_Spell__IsStackable_x                                    0x4C9CF0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9B40
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6C20
#define EQ_Spell__IsSPAStacking_x                                  0x57BC80
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57B190
#define EQ_Spell__IsNoRemove_x                                     0x4C9CD0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57BC90
#define __IsResEffectSpell_x                                       0x4C9150

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD230

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D2080

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81F2C0
#define CTargetWnd__WndNotification_x                              0x81EB50
#define CTargetWnd__RefreshTargetBuffs_x                           0x81EE20
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81DCC0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8238D0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536D70
#define CTaskManager__HandleMessage_x                              0x535210
#define CTaskManager__GetTaskStatus_x                              0x536E20
#define CTaskManager__GetElementDescription_x                      0x536EA0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575F30
#define EqSoundManager__PlayScriptMp3_x                            0x576090
#define EqSoundManager__SoundAssistPlay_x                          0x687570
#define EqSoundManager__WaveInstancePlay_x                         0x686AE0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52AAE0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x956060

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5626A0
#define CAltAbilityData__GetMercMaxRank_x                          0x562630
#define CAltAbilityData__GetMaxRank_x                              0x557D90

//CTargetRing
#define CTargetRing__Cast_x                                        0x61B290

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9B20
#define CharacterBase__CreateItemGlobalIndex_x                     0x511D70
#define CharacterBase__CreateItemIndex_x                           0x623370
#define CharacterBase__GetItemPossession_x                         0x4FD9C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DA670
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DA6D0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FF9C0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x7001F0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x7002A0

//messages
#define msg_spell_worn_off_x                                       0x59EB30
#define msg_new_text_x                                             0x5938F0
#define __msgTokenTextParam_x                                      0x5A1060
#define msgTokenText_x                                             0x5A12B0

//SpellManager
#define SpellManager__vftable_x                                    0xAEC4D4
#define SpellManager__SpellManager_x                               0x68A8A0
#define Spellmanager__LoadTextSpells_x                             0x68B190
#define SpellManager__GetSpellByGroupAndRank_x                     0x68AA70

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99E360

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x512400
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A4E30
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63BD10
#define ItemGlobalIndex__IsValidIndex_x                            0x512460

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D2A20
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D2CA0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76F5B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71CF00
#define CCursorAttachment__AttachToCursor1_x                       0x71CF40
#define CCursorAttachment__Deactivate_x                            0x71DF30

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x948D90
#define CSidlManagerBase__CreatePageWnd_x                          0x948590
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x944820
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9447B0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x966270
#define CEQSuiteTextureLoader__GetTexture_x                        0x965F30

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F310
#define CFindItemWnd__WndNotification_x                            0x50FDF0
#define CFindItemWnd__Update_x                                     0x510930
#define CFindItemWnd__PickupSelectedItem_x                         0x50EB50

//IString
#define IString__Append_x                                          0x4F0680

//Camera
#define CDisplay__cameraType_x                                     0xE000BC
#define EverQuest__Cameras_x                                       0xEC3A7C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517AC0
#define LootFiltersManager__GetItemFilterData_x                    0x5173C0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5173F0
#define LootFiltersManager__SetItemLootFilter_x                    0x517610

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C65D0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A3E50
#define CResolutionHandler__GetWindowedStyle_x                     0x682050

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7155C0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E7A50
#define CDistillerInfo__Instance_x                                 0x8E79F0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x735810
#define CGroupWnd__UpdateDisplay_x                                 0x734B70

//ItemBase
#define ItemBase__IsLore_x                                         0x8A84C0
#define ItemBase__IsLoreEquipped_x                                 0x8A8540

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DA760
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DA8A0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DA900

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x677890
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67B230

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505670

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2240
#define FactionManagerClient__HandleFactionMessage_x               0x4F28B0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2E70
#define FactionManagerClient__GetMaxFaction_x                      0x4F2E8F
#define FactionManagerClient__GetMinFaction_x                      0x4F2E40

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD990

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92D460

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BFB0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FDD30

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x561B40

//CTargetManager
#define CTargetManager__Get_x                                      0x68E100

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x677890

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8F20

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AD2C0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF61110

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
