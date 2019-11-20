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
#define __ExpectedVersionDate                                     "Nov 20 2019"
#define __ExpectedVersionTime                                     "04:23:29"
#define __ActualVersionDate_x                                      0xB0927C
#define __ActualVersionTime_x                                      0xB09270
#define __ActualVersionBuild_x                                     0xAF4F5C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62DE50
#define __MemChecker1_x                                            0x900A90
#define __MemChecker2_x                                            0x6BC3F0
#define __MemChecker3_x                                            0x6BC340
#define __MemChecker4_x                                            0x858150
#define __EncryptPad0_x                                            0xC3F3E8
#define __EncryptPad1_x                                            0xC9D5A8
#define __EncryptPad2_x                                            0xC4FC80
#define __EncryptPad3_x                                            0xC4F880
#define __EncryptPad4_x                                            0xC8DC00
#define __EncryptPad5_x                                            0xF691A0
#define __AC1_x                                                    0x814956
#define __AC2_x                                                    0x5E7CBF
#define __AC3_x                                                    0x5EF3BF
#define __AC4_x                                                    0x5F3390
#define __AC5_x                                                    0x5F969F
#define __AC6_x                                                    0x5FDCB6
#define __AC7_x                                                    0x5E7730
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191A6C

// Direct Input
#define DI8__Main_x                                                0xF691C8
#define DI8__Keyboard_x                                            0xF691CC
#define DI8__Mouse_x                                               0xF691AC
#define DI8__Mouse_Copy_x                                          0xEC23AC
#define DI8__Mouse_Check_x                                         0xF66CF4
#define __AutoSkillArray_x                                         0xEC32C4
#define __Attack_x                                                 0xF610EB
#define __Autofire_x                                               0xF610EC
#define __BindList_x                                               0xC2DE20
#define g_eqCommandStates_x                                        0xC2EBA0
#define __Clicks_x                                                 0xEC2464
#define __CommandList_x                                            0xC2F760
#define __CurrentMapLabel_x                                        0xF79B6C
#define __CurrentSocial_x                                          0xC177CC
#define __DoAbilityList_x                                          0xEF8C0C
#define __do_loot_x                                                0x5B40B0
#define __DrawHandler_x                                            0x15F8EE0
#define __GroupCount_x                                             0xEB4D62
#define __Guilds_x                                                 0xEB8BB8
#define __gWorld_x                                                 0xEB4BB0
#define __HWnd_x                                                   0xF691B0
#define __heqmain_x                                                0xF69188
#define __InChatMode_x                                             0xEC2394
#define __LastTell_x                                               0xEC4308
#define __LMouseHeldTime_x                                         0xEC24D0
#define __Mouse_x                                                  0xF691B4
#define __MouseLook_x                                              0xEC242A
#define __MouseEventTime_x                                         0xF61BCC
#define __gpbCommandEvent_x                                        0xEB2650
#define __NetStatusToggle_x                                        0xEC242D
#define __PCNames_x                                                0xEC38B4
#define __RangeAttackReady_x                                       0xEC35A8
#define __RMouseHeldTime_x                                         0xEC24CC
#define __RunWalkState_x                                           0xEC2398
#define __ScreenMode_x                                             0xE00004
#define __ScreenX_x                                                0xEC234C
#define __ScreenY_x                                                0xEC2348
#define __ScreenXMax_x                                             0xEC2350
#define __ScreenYMax_x                                             0xEC2354
#define __ServerHost_x                                             0xEB2883
#define __ServerName_x                                             0xEF8BCC
#define __ShiftKeyDown_x                                           0xEC2A24
#define __ShowNames_x                                              0xEC3764
#define __Socials_x                                                0xEF8CCC
#define __SubscriptionType_x                                       0xFBE070
#define __TargetAggroHolder_x                                      0xF7C520
#define __ZoneType_x                                               0xEC2828
#define __GroupAggro_x                                             0xF7C560
#define __LoginName_x                                              0xF6991C
#define __Inviter_x                                                0xF61068
#define __AttackOnAssist_x                                         0xEC3720
#define __UseTellWindows_x                                         0xEC3A50
#define __gfMaxZoomCameraDistance_x                                0xAFEBD0
#define __gfMaxCameraDistance_x                                    0xB2B124
#define __pulAutoRun_x                                             0xEC2448
#define __pulForward_x                                             0xEC3A88
#define __pulBackward_x                                            0xEC3A8C
#define __pulTurnRight_x                                           0xEC3A90
#define __pulTurnLeft_x                                            0xEC3A94
#define __pulStrafeLeft_x                                          0xEC3A98
#define __pulStrafeRight_x                                         0xEC3A9C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB4F58
#define instEQZoneInfo_x                                           0xEC2620
#define pinstActiveBanker_x                                        0xEB2668
#define pinstActiveCorpse_x                                        0xEB2660
#define pinstActiveGMaster_x                                       0xEB2664
#define pinstActiveMerchant_x                                      0xEB265C
#define pinstAltAdvManager_x                                       0xE01188
#define pinstBandageTarget_x                                       0xEB2678
#define pinstCamActor_x                                            0xDFFFF8
#define pinstCDBStr_x                                              0xDFFEA4
#define pinstCDisplay_x                                            0xEB4BAC
#define pinstCEverQuest_x                                          0xF691E0
#define pinstEverQuestInfo_x                                       0xEC2340
#define pinstCharData_x                                            0xEB4D44
#define pinstCharSpawn_x                                           0xEB2730
#define pinstControlledMissile_x                                   0xEB2B9C
#define pinstControlledPlayer_x                                    0xEB2730
#define pinstCResolutionHandler_x                                  0x15F9110
#define pinstCSidlManager_x                                        0x15F80A8
#define pinstCXWndManager_x                                        0x15F80A4
#define instDynamicZone_x                                          0xEB8A90
#define pinstDZMember_x                                            0xEB8BA0
#define pinstDZTimerInfo_x                                         0xEB8BA4
#define pinstEqLogin_x                                             0xF69268
#define instEQMisc_x                                               0xDFFDE8
#define pinstEQSoundManager_x                                      0xE02158
#define pinstEQSpellStrings_x                                      0xCC2858
#define instExpeditionLeader_x                                     0xEB8ADA
#define instExpeditionName_x                                       0xEB8B1A
#define pinstGroup_x                                               0xEB4D5E
#define pinstImeManager_x                                          0x15F80A0
#define pinstLocalPlayer_x                                         0xEB2658
#define pinstMercenaryData_x                                       0xF636BC
#define pinstMercenaryStats_x                                      0xF7C66C
#define pinstModelPlayer_x                                         0xEB2670
#define pinstPCData_x                                              0xEB4D44
#define pinstSkillMgr_x                                            0xF65828
#define pinstSpawnManager_x                                        0xF642D0
#define pinstSpellManager_x                                        0xF65A48
#define pinstSpellSets_x                                           0xF59D14
#define pinstStringTable_x                                         0xEB4D48
#define pinstSwitchManager_x                                       0xEB24F8
#define pinstTarget_x                                              0xEB26AC
#define pinstTargetObject_x                                        0xEB2738
#define pinstTargetSwitch_x                                        0xEB2BA4
#define pinstTaskMember_x                                          0xDFFC78
#define pinstTrackTarget_x                                         0xEB2734
#define pinstTradeTarget_x                                         0xEB266C
#define instTributeActive_x                                        0xDFFE09
#define pinstViewActor_x                                           0xDFFFF4
#define pinstWorldData_x                                           0xEB2B98
#define pinstZoneAddr_x                                            0xEC28C0
#define pinstPlayerPath_x                                          0xF64368
#define pinstTargetIndicator_x                                     0xF65CB0
#define EQObject_Top_x                                             0xEB2654
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE0076C
#define pinstCAchievementsWnd_x                                    0xE00768
#define pinstCActionsWnd_x                                         0xE0052C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFFF9C
#define pinstCAdvancedLootWnd_x                                    0xDFFF60
#define pinstCAdventureLeaderboardWnd_x                            0xF73340
#define pinstCAdventureRequestWnd_x                                0xF733F0
#define pinstCAdventureStatsWnd_x                                  0xF734A0
#define pinstCAggroMeterWnd_x                                      0xE00038
#define pinstCAlarmWnd_x                                           0xE007C8
#define pinstCAlertHistoryWnd_x                                    0xDFFFBC
#define pinstCAlertStackWnd_x                                      0xE007D0
#define pinstCAlertWnd_x                                           0xDFFF40
#define pinstCAltStorageWnd_x                                      0xF73800
#define pinstCAudioTriggersWindow_x                                0xCB4B88
#define pinstCAuraWnd_x                                            0xDFFFDC
#define pinstCAvaZoneWnd_x                                         0xDFFFB0
#define pinstCBandolierWnd_x                                       0xE00024
#define pinstCBankWnd_x                                            0xDFFFD8
#define pinstCBarterMerchantWnd_x                                  0xF74A40
#define pinstCBarterSearchWnd_x                                    0xF74AF0
#define pinstCBarterWnd_x                                          0xF74BA0
#define pinstCBazaarConfirmationWnd_x                              0xE00794
#define pinstCBazaarSearchWnd_x                                    0xE00508
#define pinstCBazaarWnd_x                                          0xE007B0
#define pinstCBlockedBuffWnd_x                                     0xDFFFE0
#define pinstCBlockedPetBuffWnd_x                                  0xE0001C
#define pinstCBodyTintWnd_x                                        0xE00740
#define pinstCBookWnd_x                                            0xE0006C
#define pinstCBreathWnd_x                                          0xE00784
#define pinstCBuffWindowNORMAL_x                                   0xDFFFC0
#define pinstCBuffWindowSHORT_x                                    0xDFFFC4
#define pinstCBugReportWnd_x                                       0xDFFFCC
#define pinstCButtonWnd_x                                          0x15F8310
#define pinstCCastingWnd_x                                         0xE00060
#define pinstCCastSpellWnd_x                                       0xE00780
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE007B4
#define pinstCChatWindowManager_x                                  0xF75660
#define pinstCClaimWnd_x                                           0xF757B8
#define pinstCColorPickerWnd_x                                     0xE00738
#define pinstCCombatAbilityWnd_x                                   0xE007C0
#define pinstCCombatSkillsSelectWnd_x                              0xDFFF48
#define pinstCCompassWnd_x                                         0xE00534
#define pinstCConfirmationDialog_x                                 0xF7A6B8
#define pinstCContainerMgr_x                                       0xE007A8
#define pinstCContextMenuManager_x                                 0x15F8060
#define pinstCCursorAttachment_x                                   0xE00054
#define pinstCDynamicZoneWnd_x                                     0xF75D80
#define pinstCEditLabelWnd_x                                       0xDFFFB8
#define pinstCEQMainWnd_x                                          0xF75FC8
#define pinstCEventCalendarWnd_x                                   0xE00058
#define pinstCExtendedTargetWnd_x                                  0xE00010
#define pinstCFacePick_x                                           0xDFFF58
#define pinstCFactionWnd_x                                         0xE007A4
#define pinstCFellowshipWnd_x                                      0xF761C8
#define pinstCFileSelectionWnd_x                                   0xE0005C
#define pinstCFindItemWnd_x                                        0xE00790
#define pinstCFindLocationWnd_x                                    0xF76320
#define pinstCFriendsWnd_x                                         0xDFFF5C
#define pinstCGemsGameWnd_x                                        0xE007A0
#define pinstCGiveWnd_x                                            0xE007CC
#define pinstCGroupSearchFiltersWnd_x                              0xE00064
#define pinstCGroupSearchWnd_x                                     0xF76718
#define pinstCGroupWnd_x                                           0xF767C8
#define pinstCGuildBankWnd_x                                       0xEC3704
#define pinstCGuildCreationWnd_x                                   0xF76928
#define pinstCGuildMgmtWnd_x                                       0xF769D8
#define pinstCharacterCreation_x                                   0xDFFF50
#define pinstCHelpWnd_x                                            0xDFFF94
#define pinstCHeritageSelectionWnd_x                               0xDFFF64
#define pinstCHotButtonWnd_x                                       0xF78B30
#define pinstCHotButtonWnd1_x                                      0xF78B30
#define pinstCHotButtonWnd2_x                                      0xF78B34
#define pinstCHotButtonWnd3_x                                      0xF78B38
#define pinstCHotButtonWnd4_x                                      0xF78B3C
#define pinstCIconSelectionWnd_x                                   0xE0003C
#define pinstCInspectWnd_x                                         0xDFFF90
#define pinstCInventoryWnd_x                                       0xDFFF68
#define pinstCInvSlotMgr_x                                         0xE00764
#define pinstCItemDisplayManager_x                                 0xF790C0
#define pinstCItemExpTransferWnd_x                                 0xF791F0
#define pinstCItemOverflowWnd_x                                    0xE0050C
#define pinstCJournalCatWnd_x                                      0xE00070
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE00014
#define pinstCKeyRingWnd_x                                         0xDFFFB4
#define pinstCLargeDialogWnd_x                                     0xF7B338
#define pinstCLayoutCopyWnd_x                                      0xF79540
#define pinstCLFGuildWnd_x                                         0xF795F0
#define pinstCLoadskinWnd_x                                        0xE007AC
#define pinstCLootFiltersCopyWnd_x                                 0xCD1180
#define pinstCLootFiltersWnd_x                                     0xE007D4
#define pinstCLootSettingsWnd_x                                    0xDFFF54
#define pinstCLootWnd_x                                            0xE00084
#define pinstCMailAddressBookWnd_x                                 0xE00774
#define pinstCMailCompositionWnd_x                                 0xE00750
#define pinstCMailIgnoreListWnd_x                                  0xE00778
#define pinstCMailWnd_x                                            0xE00528
#define pinstCManageLootWnd_x                                      0xE01638
#define pinstCMapToolbarWnd_x                                      0xDFFF98
#define pinstCMapViewWnd_x                                         0xDFFF74
#define pinstCMarketplaceWnd_x                                     0xE007D8
#define pinstCMerchantWnd_x                                        0xE000EC
#define pinstCMIZoneSelectWnd_x                                    0xF79E28
#define pinstCMusicPlayerWnd_x                                     0xE004F8
#define pinstCNameChangeMercWnd_x                                  0xE0078C
#define pinstCNameChangePetWnd_x                                   0xE00770
#define pinstCNameChangeWnd_x                                      0xE0079C
#define pinstCNoteWnd_x                                            0xDFFF78
#define pinstCObjectPreviewWnd_x                                   0xDFFF4C
#define pinstCOptionsWnd_x                                         0xDFFF80
#define pinstCPetInfoWnd_x                                         0xE00510
#define pinstCPetitionQWnd_x                                       0xE0075C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE00744
#define pinstCPlayerWnd_x                                          0xE00518
#define pinstCPopupWndManager_x                                    0xF7A6B8
#define pinstCProgressionSelectionWnd_x                            0xF7A768
#define pinstCPurchaseGroupWnd_x                                   0xDFFF84
#define pinstCPurchaseWnd_x                                        0xDFFF6C
#define pinstCPvPLeaderboardWnd_x                                  0xF7A818
#define pinstCPvPStatsWnd_x                                        0xF7A8C8
#define pinstCQuantityWnd_x                                        0xE00018
#define pinstCRaceChangeWnd_x                                      0xE007C4
#define pinstCRaidOptionsWnd_x                                     0xE00068
#define pinstCRaidWnd_x                                            0xE00758
#define pinstCRealEstateItemsWnd_x                                 0xE00760
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE004F0
#define pinstCRealEstateManageWnd_x                                0xDFFF8C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFFFAC
#define pinstCRealEstatePlotSearchWnd_x                            0xDFFFD0
#define pinstCRealEstatePurchaseWnd_x                              0xDFFFF0
#define pinstCRespawnWnd_x                                         0xDFFFEC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE0077C
#define pinstCSendMoneyWnd_x                                       0xDFFF44
#define pinstCServerListWnd_x                                      0xE00030
#define pinstCSkillsSelectWnd_x                                    0xE007B8
#define pinstCSkillsWnd_x                                          0xE00798
#define pinstCSocialEditWnd_x                                      0xDFFFA8
#define pinstCSocialWnd_x                                          0xE00788
#define pinstCSpellBookWnd_x                                       0xE007BC
#define pinstCStoryWnd_x                                           0xE0051C
#define pinstCTargetOfTargetWnd_x                                  0xF7C6F0
#define pinstCTargetWnd_x                                          0xDFFFE8
#define pinstCTaskOverlayWnd_x                                     0xDFFF7C
#define pinstCTaskSelectWnd_x                                      0xF7C848
#define pinstCTaskManager_x                                        0xCD1AC0
#define pinstCTaskTemplateSelectWnd_x                              0xF7C8F8
#define pinstCTaskWnd_x                                            0xF7C9A8
#define pinstCTextEntryWnd_x                                       0xDFFFC8
#define pinstCTimeLeftWnd_x                                        0xE00524
#define pinstCTipWndCONTEXT_x                                      0xF7CBAC
#define pinstCTipWndOFDAY_x                                        0xF7CBA8
#define pinstCTitleWnd_x                                           0xF7CC58
#define pinstCTrackingWnd_x                                        0xDFFF70
#define pinstCTradeskillWnd_x                                      0xF7CDC0
#define pinstCTradeWnd_x                                           0xE0074C
#define pinstCTrainWnd_x                                           0xE00748
#define pinstCTributeBenefitWnd_x                                  0xF7CFC0
#define pinstCTributeMasterWnd_x                                   0xF7D070
#define pinstCTributeTrophyWnd_x                                   0xF7D120
#define pinstCVideoModesWnd_x                                      0xE00520
#define pinstCVoiceMacroWnd_x                                      0xF66418
#define pinstCVoteResultsWnd_x                                     0xE00754
#define pinstCVoteWnd_x                                            0xE0073C
#define pinstCWebManager_x                                         0xF66A94
#define pinstCZoneGuideWnd_x                                       0xDFFF88
#define pinstCZonePathWnd_x                                        0xDFFFA0

#define pinstEQSuiteTextureLoader_x                                0xC9F080
#define pinstItemIconCache_x                                       0xF75F80
#define pinstLootFiltersManager_x                                  0xCD1230
#define pinstRewardSelectionWnd_x                                  0xF7B010

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AF510
#define __CastRay2_x                                               0x5AF560
#define __ConvertItemTags_x                                        0x5CB0C0
#define __CleanItemTags_x                                          0x47D260
#define __DoesFileExist_x                                          0x903B20
#define __EQGetTime_x                                              0x900560
#define __ExecuteCmd_x                                             0x5A7DA0
#define __FixHeading_x                                             0x99BEF0
#define __GameLoop_x                                               0x6BB5E0
#define __get_bearing_x                                            0x5AF080
#define __get_melee_range_x                                        0x5AF750
#define __GetAnimationCache_x                                      0x720890
#define __GetGaugeValueFromEQ_x                                    0x812E00
#define __GetLabelFromEQ_x                                         0x8148E0
#define __GetXTargetType_x                                         0x99D8D0
#define __HandleMouseWheel_x                                       0x6BC4A0
#define __HeadingDiff_x                                            0x99BF60
#define __HelpPath_x                                               0xF617BC
#define __LoadFrontEnd_x                                           0x6B8900
#define __NewUIINI_x                                               0x812AD0
#define __ProcessGameEvents_x                                      0x60F520
#define __ProcessMouseEvent_x                                      0x60ECE0
#define __SaveColors_x                                             0x551DB0
#define __STMLToText_x                                             0x93F3C0
#define __ToggleKeyRingItem_x                                      0x515030
#define CMemoryMappedFile__SetFile_x                               0xA8B3C0
#define CrashDetected_x                                            0x6BA3A0
#define DrawNetStatus_x                                            0x63B190
#define Expansion_HoT_x                                            0xEC370C
#define Teleport_Table_Size_x                                      0xEB2740
#define Teleport_Table_x                                           0xEB2BA8
#define Util__FastTime_x                                           0x900130

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490580
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499490
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499260
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493B20
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492F70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559900
#define AltAdvManager__IsAbilityReady_x                            0x558830
#define AltAdvManager__GetAAById_x                                 0x558A30
#define AltAdvManager__CanTrainAbility_x                           0x558AA0
#define AltAdvManager__CanSeeAbility_x                             0x558E00

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA440
#define CharacterZoneClient__HasSkill_x                            0x4D5330
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6A50
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE7C0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BADC0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D93E0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D94C0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D95A0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C35C0
#define CharacterZoneClient__BardCastBard_x                        0x4C6120
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAE90
#define CharacterZoneClient__GetEffect_x                           0x4BAD00
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4610
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C46E0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4730
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4880
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4A50
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2C30
#define CharacterZoneClient__FindItemByGuid_x                      0x4D79B0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7430

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E1FD0
#define CBankWnd__WndNotification_x                                0x6E1DB0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EF630

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61DC50
#define CButtonWnd__CButtonWnd_x                                   0x93B7A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70FA00
#define CChatManager__InitContextMenu_x                            0x708B60
#define CChatManager__FreeChatWindow_x                             0x70E540
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8960
#define CChatManager__SetLockedActiveChatWindow_x                  0x70F680
#define CChatManager__CreateChatWindow_x                           0x70EB80

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8A70

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94FDC0
#define CContextMenu__dCContextMenu_x                              0x94FFF0
#define CContextMenu__AddMenuItem_x                                0x950000
#define CContextMenu__RemoveMenuItem_x                             0x950310
#define CContextMenu__RemoveAllMenuItems_x                         0x950330
#define CContextMenu__CheckMenuItem_x                              0x9503B0
#define CContextMenu__SetMenuItem_x                                0x950230
#define CContextMenu__AddSeparator_x                               0x950190

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x950950
#define CContextMenuManager__RemoveMenu_x                          0x9509C0
#define CContextMenuManager__PopupMenu_x                           0x950A80
#define CContextMenuManager__Flush_x                               0x9508F0
#define CContextMenuManager__GetMenu_x                             0x49B7D0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71B080

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DC140
#define CChatService__GetFriendName_x                              0x8DC150

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x710270
#define CChatWindow__Clear_x                                       0x711530
#define CChatWindow__WndNotification_x                             0x711CC0
#define CChatWindow__AddHistory_x                                  0x710DF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94D230
#define CComboWnd__Draw_x                                          0x94C730
#define CComboWnd__GetCurChoice_x                                  0x94D070
#define CComboWnd__GetListRect_x                                   0x94CBE0
#define CComboWnd__GetTextRect_x                                   0x94D2A0
#define CComboWnd__InsertChoice_x                                  0x94CD70
#define CComboWnd__SetColors_x                                     0x94CD40
#define CComboWnd__SetChoice_x                                     0x94D040
#define CComboWnd__GetItemCount_x                                  0x94D080
#define CComboWnd__GetCurChoiceText_x                              0x94D0C0
#define CComboWnd__GetChoiceText_x                                 0x94D090
#define CComboWnd__InsertChoiceAtIndex_x                           0x94CE00

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x718A60
#define CContainerWnd__vftable_x                                   0xB12464
#define CContainerWnd__SetContainer_x                              0x719FD0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54C7F0
#define CDisplay__PreZoneMainUI_x                                  0x54C800
#define CDisplay__CleanGameUI_x                                    0x551B70
#define CDisplay__GetClickedActor_x                                0x544B10
#define CDisplay__GetUserDefinedColor_x                            0x53D1D0
#define CDisplay__GetWorldFilePath_x                               0x546580
#define CDisplay__is3dON_x                                         0x541770
#define CDisplay__ReloadUI_x                                       0x54BC80
#define CDisplay__WriteTextHD2_x                                   0x541560
#define CDisplay__TrueDistance_x                                   0x548240
#define CDisplay__SetViewActor_x                                   0x544430
#define CDisplay__GetFloorHeight_x                                 0x541830
#define CDisplay__SetRenderWindow_x                                0x540190
#define CDisplay__ToggleScreenshotMode_x                           0x543F00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96FBB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9532FF
#define CEditWnd__GetCharIndexPt_x                                 0x954240
#define CEditWnd__GetDisplayString_x                               0x9540E0
#define CEditWnd__GetHorzOffset_x                                  0x952940
#define CEditWnd__GetLineForPrintableChar_x                        0x9553E0
#define CEditWnd__GetSelStartPt_x                                  0x9544F0
#define CEditWnd__GetSTMLSafeText_x                                0x953F00
#define CEditWnd__PointFromPrintableChar_x                         0x955010
#define CEditWnd__SelectableCharFromPoint_x                        0x955180
#define CEditWnd__SetEditable_x                                    0x9545C0
#define CEditWnd__SetWindowTextA_x                                 0x953C80

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FD190
#define CEverQuest__ClickedPlayer_x                                0x5EF1A0
#define CEverQuest__CreateTargetIndicator_x                        0x60C7C0
#define CEverQuest__DeleteTargetIndicator_x                        0x60C850
#define CEverQuest__DoTellWindow_x                                 0x4E8B50
#define CEverQuest__OutputTextToLog_x                              0x4E8DD0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E41E0
#define CEverQuest__dsp_chat_x                                     0x4E9160
#define CEverQuest__trimName_x                                     0x608AA0
#define CEverQuest__Emote_x                                        0x5FD9F0
#define CEverQuest__EnterZone_x                                    0x5F7970
#define CEverQuest__GetBodyTypeDesc_x                              0x602360
#define CEverQuest__GetClassDesc_x                                 0x6029A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x602FA0
#define CEverQuest__GetDeityDesc_x                                 0x60B100
#define CEverQuest__GetLangDesc_x                                  0x603160
#define CEverQuest__GetRaceDesc_x                                  0x602980
#define CEverQuest__InterpretCmd_x                                 0x60B6D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E83E0
#define CEverQuest__LMouseUp_x                                     0x5E6770
#define CEverQuest__RightClickedOnPlayer_x                         0x5E8CC0
#define CEverQuest__RMouseUp_x                                     0x5E76F0
#define CEverQuest__SetGameState_x                                 0x5E3F70
#define CEverQuest__UPCNotificationFlush_x                         0x6089A0
#define CEverQuest__IssuePetCommand_x                              0x604560
#define CEverQuest__ReportSuccessfulHit_x                          0x5FEDE0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72A990
#define CGaugeWnd__CalcLinesFillRect_x                             0x72A9F0
#define CGaugeWnd__Draw_x                                          0x72A010

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF720
#define CGuild__GetGuildName_x                                     0x4AE800
#define CGuild__GetGuildIndex_x                                    0x4AEB90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x745DF0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61E010

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x752DD0
#define CInvSlotMgr__MoveItem_x                                    0x751B30
#define CInvSlotMgr__SelectSlot_x                                  0x752EA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7503B0
#define CInvSlot__SliderComplete_x                                 0x74E110
#define CInvSlot__GetItemBase_x                                    0x74DAA0
#define CInvSlot__UpdateItem_x                                     0x74DC10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x754920
#define CInvSlotWnd__CInvSlotWnd_x                                 0x753AC0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7544A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80E140
#define CItemDisplayWnd__UpdateStrings_x                           0x762FF0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75CDC0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75D2C0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7635F0
#define CItemDisplayWnd__AboutToShow_x                             0x762C40
#define CItemDisplayWnd__WndNotification_x                         0x7646D0
#define CItemDisplayWnd__RequestConvertItem_x                      0x764190
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x761CB0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x762A60

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x846D60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x768BD0

// CLabel 
#define CLabel__Draw_x                                             0x76E610

// CListWnd
#define CListWnd__CListWnd_x                                       0x9259A0
#define CListWnd__dCListWnd_x                                      0x925CC0
#define CListWnd__AddColumn_x                                      0x92A140
#define CListWnd__AddColumn1_x                                     0x92A190
#define CListWnd__AddLine_x                                        0x92A520
#define CListWnd__AddString_x                                      0x92A320
#define CListWnd__CalculateFirstVisibleLine_x                      0x929F00
#define CListWnd__CalculateVSBRange_x                              0x929CF0
#define CListWnd__ClearSel_x                                       0x92AD00
#define CListWnd__ClearAllSel_x                                    0x92AD60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92B780
#define CListWnd__Compare_x                                        0x929620
#define CListWnd__Draw_x                                           0x925DF0
#define CListWnd__DrawColumnSeparators_x                           0x9285F0
#define CListWnd__DrawHeader_x                                     0x928A60
#define CListWnd__DrawItem_x                                       0x928F60
#define CListWnd__DrawLine_x                                       0x928760
#define CListWnd__DrawSeparator_x                                  0x928690
#define CListWnd__EnableLine_x                                     0x927EC0
#define CListWnd__EnsureVisible_x                                  0x92B6A0
#define CListWnd__ExtendSel_x                                      0x92AC30
#define CListWnd__GetColumnTooltip_x                               0x927A00
#define CListWnd__GetColumnMinWidth_x                              0x927A70
#define CListWnd__GetColumnWidth_x                                 0x927970
#define CListWnd__GetCurSel_x                                      0x927300
#define CListWnd__GetItemAtPoint_x                                 0x928140
#define CListWnd__GetItemAtPoint1_x                                0x9281B0
#define CListWnd__GetItemData_x                                    0x927380
#define CListWnd__GetItemHeight_x                                  0x927740
#define CListWnd__GetItemIcon_x                                    0x927510
#define CListWnd__GetItemRect_x                                    0x927FB0
#define CListWnd__GetItemText_x                                    0x9273C0
#define CListWnd__GetSelList_x                                     0x92ADB0
#define CListWnd__GetSeparatorRect_x                               0x9283F0
#define CListWnd__InsertLine_x                                     0x92A910
#define CListWnd__RemoveLine_x                                     0x92AA60
#define CListWnd__SetColors_x                                      0x929CC0
#define CListWnd__SetColumnJustification_x                         0x9299F0
#define CListWnd__SetColumnWidth_x                                 0x929910
#define CListWnd__SetCurSel_x                                      0x92AB70
#define CListWnd__SetItemColor_x                                   0x92B350
#define CListWnd__SetItemData_x                                    0x92B310
#define CListWnd__SetItemText_x                                    0x92AF20
#define CListWnd__ShiftColumnSeparator_x                           0x929AB0
#define CListWnd__Sort_x                                           0x9297A0
#define CListWnd__ToggleSel_x                                      0x92ABA0
#define CListWnd__SetColumnsSizable_x                              0x929B60
#define CListWnd__SetItemWnd_x                                     0x92B1D0
#define CListWnd__GetItemWnd_x                                     0x927560
#define CListWnd__SetItemIcon_x                                    0x92AFA0
#define CListWnd__CalculateCustomWindowPositions_x                 0x92A000
#define CListWnd__SetVScrollPos_x                                  0x9298F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x783D90
#define CMapViewWnd__GetWorldCoordinates_x                         0x7824A0
#define CMapViewWnd__HandleLButtonDown_x                           0x77F4E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A3E50
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A4730
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A4C60
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A7BE0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A29B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AD790
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A3A60

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A9E70
#define CPacketScrambler__hton_x                                   0x8A9E60

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9449F0
#define CSidlManager__FindScreenPieceTemplate_x                    0x944E00
#define CSidlManager__FindScreenPieceTemplate1_x                   0x944BF0
#define CSidlManager__CreateLabel_x                                0x8055F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x947D60
#define CSidlManager__CreateXWndFromTemplate1_x                    0x947F40
#define CSidlManager__CreateXWnd_x                                 0x805520
#define CSidlManager__CreateHotButtonWnd_x                         0x805AE0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9414D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9413D0
#define CSidlScreenWnd__ConvertToRes_x                             0x966BB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x940E70
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x940B60
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x940C30
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x940D00
#define CSidlScreenWnd__DrawSidlPiece_x                            0x941970
#define CSidlScreenWnd__EnableIniStorage_x                         0x941E40
#define CSidlScreenWnd__GetSidlPiece_x                             0x941B60
#define CSidlScreenWnd__Init1_x                                    0x940770
#define CSidlScreenWnd__LoadIniInfo_x                              0x941E90
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9429D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93FB70
#define CSidlScreenWnd__StoreIniInfo_x                             0x942550
#define CSidlScreenWnd__StoreIniVis_x                              0x9428B0
#define CSidlScreenWnd__WndNotification_x                          0x941880
#define CSidlScreenWnd__GetChildItem_x                             0x941DC0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9315C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F7F30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x682920
#define CSkillMgr__GetSkillCap_x                                   0x682B00
#define CSkillMgr__GetNameToken_x                                  0x6820A0
#define CSkillMgr__IsActivatedSkill_x                              0x6821E0
#define CSkillMgr__IsCombatSkill_x                                 0x682120

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x951720
#define CSliderWnd__SetValue_x                                     0x951590
#define CSliderWnd__SetNumTicks_x                                  0x9515F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80B5E0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x959F20
#define CStmlWnd__CalculateHSBRange_x                              0x95B050
#define CStmlWnd__CalculateVSBRange_x                              0x95AFC0
#define CStmlWnd__CanBreakAtCharacter_x                            0x95F370
#define CStmlWnd__FastForwardToEndOfTag_x                          0x960000
#define CStmlWnd__ForceParseNow_x                                  0x95A510
#define CStmlWnd__GetNextTagPiece_x                                0x95F2D0
#define CStmlWnd__GetSTMLText_x                                    0x5046D0
#define CStmlWnd__GetVisibleText_x                                 0x95A530
#define CStmlWnd__InitializeWindowVariables_x                      0x95FE50
#define CStmlWnd__MakeStmlColorTag_x                               0x959590
#define CStmlWnd__MakeWndNotificationTag_x                         0x959600
#define CStmlWnd__SetSTMLText_x                                    0x958640
#define CStmlWnd__StripFirstSTMLLines_x                            0x961100
#define CStmlWnd__UpdateHistoryString_x                            0x960210

// CTabWnd 
#define CTabWnd__Draw_x                                            0x957790
#define CTabWnd__DrawCurrentPage_x                                 0x957EC0
#define CTabWnd__DrawTab_x                                         0x957BE0
#define CTabWnd__GetCurrentPage_x                                  0x956FA0
#define CTabWnd__GetPageInnerRect_x                                0x9571E0
#define CTabWnd__GetTabInnerRect_x                                 0x957120
#define CTabWnd__GetTabRect_x                                      0x956FD0
#define CTabWnd__InsertPage_x                                      0x9573F0
#define CTabWnd__SetPage_x                                         0x957260
#define CTabWnd__SetPageRect_x                                     0x9576D0
#define CTabWnd__UpdatePage_x                                      0x957AA0
#define CTabWnd__GetPageFromTabIndex_x                             0x957B20
#define CTabWnd__GetCurrentTabIndex_x                              0x956F90

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x768FA0
#define CPageWnd__SetTabText_x                                     0x956AF0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A93A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92E4A0
#define CTextureFont__GetTextExtent_x                              0x92E660

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B5790
#define CHtmlComponentWnd__ValidateUri_x                           0x7477F0
#define CHtmlWnd__SetClientCallbacks_x                             0x623090
#define CHtmlWnd__AddObserver_x                                    0x6230B0
#define CHtmlWnd__RemoveObserver_x                                 0x623110
#define Window__getProgress_x                                      0x85F710
#define Window__getStatus_x                                        0x85F730
#define Window__getURI_x                                           0x85F740

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96C640

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91B660

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8770
#define CXStr__CXStr1_x                                            0x9F2830
#define CXStr__CXStr3_x                                            0x8FC660
#define CXStr__dCXStr_x                                            0x4787B0
#define CXStr__operator_equal_x                                    0x8FC890
#define CXStr__operator_equal1_x                                   0x8FC8D0
#define CXStr__operator_plus_equal1_x                              0x8FD360
#define CXStr__SetString_x                                         0x8FF250
#define CXStr__operator_char_p_x                                   0x8FCDD0
#define CXStr__GetChar_x                                           0x8FEBA0
#define CXStr__Delete_x                                            0x8FE450
#define CXStr__GetUnicode_x                                        0x8FEC10
#define CXStr__GetLength_x                                         0x4A9150
#define CXStr__Mid_x                                               0x47D610
#define CXStr__Insert_x                                            0x8FEC70
#define CXStr__FindNext_x                                          0x8FE8C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94F9E0
#define CXWnd__BringToTop_x                                        0x934D30
#define CXWnd__Center_x                                            0x9348B0
#define CXWnd__ClrFocus_x                                          0x9346D0
#define CXWnd__Destroy_x                                           0x934770
#define CXWnd__DoAllDrawing_x                                      0x930D70
#define CXWnd__DrawChildren_x                                      0x930D40
#define CXWnd__DrawColoredRect_x                                   0x9311B0
#define CXWnd__DrawTooltip_x                                       0x92F890
#define CXWnd__DrawTooltipAtPoint_x                                0x92F950
#define CXWnd__GetBorderFrame_x                                    0x931010
#define CXWnd__GetChildWndAt_x                                     0x934DD0
#define CXWnd__GetClientClipRect_x                                 0x932FC0
#define CXWnd__GetScreenClipRect_x                                 0x933090
#define CXWnd__GetScreenRect_x                                     0x933260
#define CXWnd__GetTooltipRect_x                                    0x931200
#define CXWnd__GetWindowTextA_x                                    0x49CEE0
#define CXWnd__IsActive_x                                          0x931930
#define CXWnd__IsDescendantOf_x                                    0x933C50
#define CXWnd__IsReallyVisible_x                                   0x933C80
#define CXWnd__IsType_x                                            0x935450
#define CXWnd__Move_x                                              0x933CF0
#define CXWnd__Move1_x                                             0x933DA0
#define CXWnd__ProcessTransition_x                                 0x934860
#define CXWnd__Refade_x                                            0x934060
#define CXWnd__Resize_x                                            0x9342F0
#define CXWnd__Right_x                                             0x934AF0
#define CXWnd__SetFocus_x                                          0x934690
#define CXWnd__SetFont_x                                           0x934700
#define CXWnd__SetKeyTooltip_x                                     0x935260
#define CXWnd__SetMouseOver_x                                      0x932150
#define CXWnd__StartFade_x                                         0x933B30
#define CXWnd__GetChildItem_x                                      0x934F40
#define CXWnd__SetParent_x                                         0x933A00
#define CXWnd__Minimize_x                                          0x934360

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x967C30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x937C90
#define CXWndManager__DrawWindows_x                                0x937CB0
#define CXWndManager__GetKeyboardFlags_x                           0x93A3B0
#define CXWndManager__HandleKeyboardMsg_x                          0x939F70
#define CXWndManager__RemoveWnd_x                                  0x93A5D0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93AB40

// CDBStr
#define CDBStr__GetString_x                                        0x53C1A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBDA0
#define EQ_Character__Cur_HP_x                                     0x4D2370
#define EQ_Character__Cur_Mana_x                                   0x4D9AA0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEE10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2870
#define EQ_Character__GetFocusRangeModifier_x                      0x4B29C0
#define EQ_Character__GetHPRegen_x                                 0x4DF840
#define EQ_Character__GetEnduranceRegen_x                          0x4DFE40
#define EQ_Character__GetManaRegen_x                               0x4E0280
#define EQ_Character__Max_Endurance_x                              0x649070
#define EQ_Character__Max_HP_x                                     0x4D21A0
#define EQ_Character__Max_Mana_x                                   0x648E70
#define EQ_Character__doCombatAbility_x                            0x64B4D0
#define EQ_Character__UseSkill_x                                   0x4E2060
#define EQ_Character__GetConLevel_x                                0x642180
#define EQ_Character__IsExpansionFlag_x                            0x5A6530
#define EQ_Character__TotalEffect_x                                0x4C5860
#define EQ_Character__GetPCSpellAffect_x                           0x4BFB60
#define EQ_Character__SpellDuration_x                              0x4BF690
#define EQ_Character__GetAdjustedSkill_x                           0x4D50F0
#define EQ_Character__GetBaseSkill_x                               0x4D6090
#define EQ_Character__CanUseItem_x                                 0x4D9DB0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C90B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65F630

//PcClient
#define PcClient__PcClient_x                                       0x63F8C0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B99F0
#define CCharacterListWnd__EnterWorld_x                            0x4B9430
#define CCharacterListWnd__Quit_x                                  0x4B9180
#define CCharacterListWnd__UpdateList_x                            0x4B95C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6242F0
#define EQ_Item__CreateItemTagString_x                             0x8A3740
#define EQ_Item__IsStackable_x                                     0x8A8240
#define EQ_Item__GetImageNum_x                                     0x8A5190
#define EQ_Item__CreateItemClient_x                                0x6234B0
#define EQ_Item__GetItemValue_x                                    0x8A6460
#define EQ_Item__ValueSellMerchant_x                               0x8A9A50
#define EQ_Item__IsKeyRingItem_x                                   0x8A7B40
#define EQ_Item__CanGoInBag_x                                      0x624410
#define EQ_Item__IsEmpty_x                                         0x8A76A0
#define EQ_Item__GetMaxItemCount_x                                 0x8A6880
#define EQ_Item__GetHeldItem_x                                     0x8A5060
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A30B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55A610
#define EQ_LoadingS__Array_x                                       0xC26B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6499D0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B2C50
#define EQ_PC__GetCombatAbility_x                                  0x8B32C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B3330
#define EQ_PC__GetItemRecastTimer_x                                0x64BA50
#define EQ_PC__HasLoreItem_x                                       0x642940
#define EQ_PC__AlertInventoryChanged_x                             0x641AC0
#define EQ_PC__GetPcZoneClient_x                                   0x66E090
#define EQ_PC__RemoveMyAffect_x                                    0x64EC90
#define EQ_PC__GetKeyRingItems_x                                   0x8B3BC0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B3950
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B3EC0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5ACAD0
#define EQItemList__add_object_x                                   0x5D9A30
#define EQItemList__add_item_x                                     0x5AD030
#define EQItemList__delete_item_x                                  0x5AD080
#define EQItemList__FreeItemList_x                                 0x5ACF80

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538CE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x660EB0
#define EQPlayer__dEQPlayer_x                                      0x654200
#define EQPlayer__DoAttack_x                                       0x668D20
#define EQPlayer__EQPlayer_x                                       0x6548C0
#define EQPlayer__SetNameSpriteState_x                             0x658B90
#define EQPlayer__SetNameSpriteTint_x                              0x659A60
#define PlayerBase__HasProperty_j_x                                0x99A2E0
#define EQPlayer__IsTargetable_x                                   0x99A780
#define EQPlayer__CanSee_x                                         0x99A5E0
#define EQPlayer__CanSee1_x                                        0x99A6B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x99A3A0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66BB20
#define PlayerZoneClient__GetLevel_x                               0x66E0D0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DABA0
#define PlayerZoneClient__LegalPlayerRace_x                        0x553A10

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x663C10
#define EQPlayerManager__GetSpawnByName_x                          0x663CC0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x663D50

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x627940
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6279C0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x627A00
#define KeypressHandler__ClearCommandStateArray_x                  0x628E10
#define KeypressHandler__HandleKeyDown_x                           0x628E30
#define KeypressHandler__HandleKeyUp_x                             0x628ED0
#define KeypressHandler__SaveKeymapping_x                          0x629320

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77FC00
#define MapViewMap__SaveEx_x                                       0x782FC0
#define MapViewMap__SetZoom_x                                      0x787680

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C6FD0

// StringTable 
#define StringTable__getString_x                                   0x8C1E90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64E900
#define PcZoneClient__RemovePetEffect_x                            0x64EF30
#define PcZoneClient__HasAlternateAbility_x                        0x648CA0
#define PcZoneClient__GetCurrentMod_x                              0x4E5120
#define PcZoneClient__GetModCap_x                                  0x4E5020
#define PcZoneClient__CanEquipItem_x                               0x649370
#define PcZoneClient__GetItemByID_x                                0x64BED0
#define PcZoneClient__GetItemByItemClass_x                         0x64C020
#define PcZoneClient__RemoveBuffEffect_x                           0x64EF50
#define PcZoneClient__BandolierSwap_x                              0x649F90
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64B9F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DF6C0

//IconCache
#define IconCache__GetIcon_x                                       0x720130

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x717C00
#define CContainerMgr__CloseContainer_x                            0x717ED0
#define CContainerMgr__OpenExperimentContainer_x                   0x718950

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D7C50

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61C440

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7760D0
#define CLootWnd__RequestLootSlot_x                                0x775300

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57A1F0
#define EQ_Spell__SpellAffects_x                                   0x57A660
#define EQ_Spell__SpellAffectBase_x                                0x57A420
#define EQ_Spell__IsStackable_x                                    0x4C9DC0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9C70
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6D40
#define EQ_Spell__IsSPAStacking_x                                  0x57B4B0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A9C0
#define EQ_Spell__IsNoRemove_x                                     0x4C9DA0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57B4C0
#define __IsResEffectSpell_x                                       0x4C9280

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD470

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D1600

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81E8A0
#define CTargetWnd__WndNotification_x                              0x81E130
#define CTargetWnd__RefreshTargetBuffs_x                           0x81E400
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81D2A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x822EB0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5366F0
#define CTaskManager__HandleMessage_x                              0x534B80
#define CTaskManager__GetTaskStatus_x                              0x5367A0
#define CTaskManager__GetElementDescription_x                      0x536820

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575760
#define EqSoundManager__PlayScriptMp3_x                            0x5758C0
#define EqSoundManager__SoundAssistPlay_x                          0x6868D0
#define EqSoundManager__WaveInstancePlay_x                         0x685E40

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52A470

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x956000

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562000
#define CAltAbilityData__GetMercMaxRank_x                          0x561F90
#define CAltAbilityData__GetMaxRank_x                              0x5576B0

//CTargetRing
#define CTargetRing__Cast_x                                        0x61A560

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9C50
#define CharacterBase__CreateItemGlobalIndex_x                     0x511600
#define CharacterBase__CreateItemIndex_x                           0x622640
#define CharacterBase__GetItemPossession_x                         0x4FD200
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D9C10
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D9C70
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FED30
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FF560
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FF610

//messages
#define msg_spell_worn_off_x                                       0x59E820
#define msg_new_text_x                                             0x5935C0
#define __msgTokenTextParam_x                                      0x5A0D40
#define msgTokenText_x                                             0x5A0F90

//SpellManager
#define SpellManager__vftable_x                                    0xAEC4C8
#define SpellManager__SpellManager_x                               0x689C00
#define Spellmanager__LoadTextSpells_x                             0x68A4F0
#define SpellManager__GetSpellByGroupAndRank_x                     0x689DD0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99E1C0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x511C50
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A4AD0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63AFF0
#define ItemGlobalIndex__IsValidIndex_x                            0x511CB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D1FA0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D2220

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76E950

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71C320
#define CCursorAttachment__AttachToCursor1_x                       0x71C360
#define CCursorAttachment__Deactivate_x                            0x71D350

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x948D90
#define CSidlManagerBase__CreatePageWnd_x                          0x948590
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x944810
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9447A0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x965DF0
#define CEQSuiteTextureLoader__GetTexture_x                        0x965AB0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50EBA0
#define CFindItemWnd__WndNotification_x                            0x50F680
#define CFindItemWnd__Update_x                                     0x5101F0
#define CFindItemWnd__PickupSelectedItem_x                         0x50E3F0

//IString
#define IString__Append_x                                          0x4F0850

//Camera
#define CDisplay__cameraType_x                                     0xE00530
#define EverQuest__Cameras_x                                       0xEC3A5C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5173E0
#define LootFiltersManager__GetItemFilterData_x                    0x516CE0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x516D10
#define LootFiltersManager__SetItemLootFilter_x                    0x516F30

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C5C10

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A3E60
#define CResolutionHandler__GetWindowedStyle_x                     0x681200

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7149D0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E6BC0
#define CDistillerInfo__Instance_x                                 0x8E6B60

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x734BA0
#define CGroupWnd__UpdateDisplay_x                                 0x733F00

//ItemBase
#define ItemBase__IsLore_x                                         0x8A7BF0
#define ItemBase__IsLoreEquipped_x                                 0x8A7C70

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D9990
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D9AD0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D9B30

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6767A0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67A180

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x504F40

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F23A0
#define FactionManagerClient__HandleFactionMessage_x               0x4F2A10
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3010
#define FactionManagerClient__GetMaxFaction_x                      0x4F302F
#define FactionManagerClient__GetMinFaction_x                      0x4F2FE0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD1D0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92D420

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C1C0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD4F0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5614A0

//CTargetManager
#define CTargetManager__Get_x                                      0x68D450

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6767A0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9160

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5ACF20

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF610F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
