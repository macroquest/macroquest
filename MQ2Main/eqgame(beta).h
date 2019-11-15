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
#define __ExpectedVersionDate                                     "Nov 15 2019"
#define __ExpectedVersionTime                                     "04:23:45"
#define __ActualVersionDate_x                                      0xB09284
#define __ActualVersionTime_x                                      0xB09278
#define __ActualVersionBuild_x                                     0xAF4F64

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62D880
#define __MemChecker1_x                                            0x900EA0
#define __MemChecker2_x                                            0x6BC370
#define __MemChecker3_x                                            0x6BC2C0
#define __MemChecker4_x                                            0x858280
#define __EncryptPad0_x                                            0xC3F3E8
#define __EncryptPad1_x                                            0xC9D5A8
#define __EncryptPad2_x                                            0xC4FC80
#define __EncryptPad3_x                                            0xC4F880
#define __EncryptPad4_x                                            0xC8DC00
#define __EncryptPad5_x                                            0xF691A0
#define __AC1_x                                                    0x814BE6
#define __AC2_x                                                    0x5E791F
#define __AC3_x                                                    0x5EF01F
#define __AC4_x                                                    0x5F2FF0
#define __AC5_x                                                    0x5F92FF
#define __AC6_x                                                    0x5FD916
#define __AC7_x                                                    0x5E7390
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191A6C

// Direct Input
#define DI8__Main_x                                                0xF691C8
#define DI8__Keyboard_x                                            0xF691CC
#define DI8__Mouse_x                                               0xF691C0
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
#define __do_loot_x                                                0x5B3D00
#define __DrawHandler_x                                            0x15F8EE0
#define __GroupCount_x                                             0xEB4D62
#define __Guilds_x                                                 0xEB8BB8
#define __gWorld_x                                                 0xEB4BB0
#define __HWnd_x                                                   0xF691C4
#define __heqmain_x                                                0xF69188
#define __InChatMode_x                                             0xEC2394
#define __LastTell_x                                               0xEC4308
#define __LMouseHeldTime_x                                         0xEC24D0
#define __Mouse_x                                                  0xF691AC
#define __MouseLook_x                                              0xEC242A
#define __MouseEventTime_x                                         0xF61BCC
#define __gpbCommandEvent_x                                        0xEB2650
#define __NetStatusToggle_x                                        0xEC242D
#define __PCNames_x                                                0xEC38B4
#define __RangeAttackReady_x                                       0xEC35A8
#define __RMouseHeldTime_x                                         0xEC24CC
#define __RunWalkState_x                                           0xEC2398
#define __ScreenMode_x                                             0xDFFFFC
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
#define __gfMaxZoomCameraDistance_x                                0xAFEBD8
#define __gfMaxCameraDistance_x                                    0xB2B134
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
#define pinstCamActor_x                                            0xDFFFF0
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
#define pinstViewActor_x                                           0xDFFFEC
#define pinstWorldData_x                                           0xEB2B98
#define pinstZoneAddr_x                                            0xEC28C0
#define pinstPlayerPath_x                                          0xF64368
#define pinstTargetIndicator_x                                     0xF65CB0
#define EQObject_Top_x                                             0xEB2654
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE00764
#define pinstCAchievementsWnd_x                                    0xE00760
#define pinstCActionsWnd_x                                         0xE00524
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFFF94
#define pinstCAdvancedLootWnd_x                                    0xDFFF58
#define pinstCAdventureLeaderboardWnd_x                            0xF73340
#define pinstCAdventureRequestWnd_x                                0xF733F0
#define pinstCAdventureStatsWnd_x                                  0xF734A0
#define pinstCAggroMeterWnd_x                                      0xE00044
#define pinstCAlarmWnd_x                                           0xE007C0
#define pinstCAlertHistoryWnd_x                                    0xDFFFB4
#define pinstCAlertStackWnd_x                                      0xE007C8
#define pinstCAlertWnd_x                                           0xE007D4
#define pinstCAltStorageWnd_x                                      0xF73800
#define pinstCAudioTriggersWindow_x                                0xCB4B88
#define pinstCAuraWnd_x                                            0xDFFFD4
#define pinstCAvaZoneWnd_x                                         0xDFFF98
#define pinstCBandolierWnd_x                                       0xE0002C
#define pinstCBankWnd_x                                            0xDFFFD0
#define pinstCBarterMerchantWnd_x                                  0xF74A40
#define pinstCBarterSearchWnd_x                                    0xF74AF0
#define pinstCBarterWnd_x                                          0xF74BA0
#define pinstCBazaarConfirmationWnd_x                              0xE0078C
#define pinstCBazaarSearchWnd_x                                    0xE00500
#define pinstCBazaarWnd_x                                          0xE007A8
#define pinstCBlockedBuffWnd_x                                     0xDFFFD8
#define pinstCBlockedPetBuffWnd_x                                  0xE00018
#define pinstCBodyTintWnd_x                                        0xE00738
#define pinstCBookWnd_x                                            0xE00064
#define pinstCBreathWnd_x                                          0xE0077C
#define pinstCBuffWindowNORMAL_x                                   0xDFFFB8
#define pinstCBuffWindowSHORT_x                                    0xDFFFBC
#define pinstCBugReportWnd_x                                       0xDFFFC4
#define pinstCButtonWnd_x                                          0x15F8310
#define pinstCCastingWnd_x                                         0xE00058
#define pinstCCastSpellWnd_x                                       0xE00778
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE007AC
#define pinstCChatWindowManager_x                                  0xF75660
#define pinstCClaimWnd_x                                           0xF757B8
#define pinstCColorPickerWnd_x                                     0xE00730
#define pinstCCombatAbilityWnd_x                                   0xE007B8
#define pinstCCombatSkillsSelectWnd_x                              0xDFFF40
#define pinstCCompassWnd_x                                         0xE0052C
#define pinstCConfirmationDialog_x                                 0xF7A6B8
#define pinstCContainerMgr_x                                       0xE007A0
#define pinstCContextMenuManager_x                                 0x15F8060
#define pinstCCursorAttachment_x                                   0xE0004C
#define pinstCDynamicZoneWnd_x                                     0xF75D80
#define pinstCEditLabelWnd_x                                       0xDFFFB0
#define pinstCEQMainWnd_x                                          0xF75FC8
#define pinstCEventCalendarWnd_x                                   0xE00050
#define pinstCExtendedTargetWnd_x                                  0xE0000C
#define pinstCFacePick_x                                           0xDFFF50
#define pinstCFactionWnd_x                                         0xE0079C
#define pinstCFellowshipWnd_x                                      0xF761C8
#define pinstCFileSelectionWnd_x                                   0xE00054
#define pinstCFindItemWnd_x                                        0xE00788
#define pinstCFindLocationWnd_x                                    0xF76320
#define pinstCFriendsWnd_x                                         0xDFFF54
#define pinstCGemsGameWnd_x                                        0xE00798
#define pinstCGiveWnd_x                                            0xE007C4
#define pinstCGroupSearchFiltersWnd_x                              0xE0005C
#define pinstCGroupSearchWnd_x                                     0xF76718
#define pinstCGroupWnd_x                                           0xF767C8
#define pinstCGuildBankWnd_x                                       0xEC3704
#define pinstCGuildCreationWnd_x                                   0xF76928
#define pinstCGuildMgmtWnd_x                                       0xF769D8
#define pinstCharacterCreation_x                                   0xDFFF48
#define pinstCHelpWnd_x                                            0xDFFF8C
#define pinstCHeritageSelectionWnd_x                               0xDFFF5C
#define pinstCHotButtonWnd_x                                       0xF78B30
#define pinstCHotButtonWnd1_x                                      0xF78B30
#define pinstCHotButtonWnd2_x                                      0xF78B34
#define pinstCHotButtonWnd3_x                                      0xF78B38
#define pinstCHotButtonWnd4_x                                      0xF78B3C
#define pinstCIconSelectionWnd_x                                   0xE00048
#define pinstCInspectWnd_x                                         0xDFFF88
#define pinstCInventoryWnd_x                                       0xDFFF60
#define pinstCInvSlotMgr_x                                         0xE0075C
#define pinstCItemDisplayManager_x                                 0xF790C0
#define pinstCItemExpTransferWnd_x                                 0xF791F0
#define pinstCItemOverflowWnd_x                                    0xE00504
#define pinstCJournalCatWnd_x                                      0xE000DC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE00010
#define pinstCKeyRingWnd_x                                         0xDFFFAC
#define pinstCLargeDialogWnd_x                                     0xF7B338
#define pinstCLayoutCopyWnd_x                                      0xF79540
#define pinstCLFGuildWnd_x                                         0xF795F0
#define pinstCLoadskinWnd_x                                        0xE007A4
#define pinstCLootFiltersCopyWnd_x                                 0xCD1180
#define pinstCLootFiltersWnd_x                                     0xE007CC
#define pinstCLootSettingsWnd_x                                    0xDFFF4C
#define pinstCLootWnd_x                                            0xE004E4
#define pinstCMailAddressBookWnd_x                                 0xE0076C
#define pinstCMailCompositionWnd_x                                 0xE00748
#define pinstCMailIgnoreListWnd_x                                  0xE00770
#define pinstCMailWnd_x                                            0xE00520
#define pinstCManageLootWnd_x                                      0xE01638
#define pinstCMapToolbarWnd_x                                      0xDFFF90
#define pinstCMapViewWnd_x                                         0xDFFF6C
#define pinstCMarketplaceWnd_x                                     0xE007D0
#define pinstCMerchantWnd_x                                        0xE004E8
#define pinstCMIZoneSelectWnd_x                                    0xF79E28
#define pinstCMusicPlayerWnd_x                                     0xE004F0
#define pinstCNameChangeMercWnd_x                                  0xE00784
#define pinstCNameChangePetWnd_x                                   0xE00768
#define pinstCNameChangeWnd_x                                      0xE00794
#define pinstCNoteWnd_x                                            0xDFFF70
#define pinstCObjectPreviewWnd_x                                   0xDFFF44
#define pinstCOptionsWnd_x                                         0xDFFF78
#define pinstCPetInfoWnd_x                                         0xE00508
#define pinstCPetitionQWnd_x                                       0xE00754
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE0073C
#define pinstCPlayerWnd_x                                          0xE00510
#define pinstCPopupWndManager_x                                    0xF7A6B8
#define pinstCProgressionSelectionWnd_x                            0xF7A768
#define pinstCPurchaseGroupWnd_x                                   0xDFFF7C
#define pinstCPurchaseWnd_x                                        0xDFFF64
#define pinstCPvPLeaderboardWnd_x                                  0xF7A818
#define pinstCPvPStatsWnd_x                                        0xF7A8C8
#define pinstCQuantityWnd_x                                        0xE00014
#define pinstCRaceChangeWnd_x                                      0xE007BC
#define pinstCRaidOptionsWnd_x                                     0xE00060
#define pinstCRaidWnd_x                                            0xE00750
#define pinstCRealEstateItemsWnd_x                                 0xE00758
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE004EC
#define pinstCRealEstateManageWnd_x                                0xDFFF84
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFFFA8
#define pinstCRealEstatePlotSearchWnd_x                            0xDFFFC8
#define pinstCRealEstatePurchaseWnd_x                              0xDFFFE8
#define pinstCRespawnWnd_x                                         0xDFFFE4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE00774
#define pinstCSendMoneyWnd_x                                       0xE007D8
#define pinstCServerListWnd_x                                      0xE00040
#define pinstCSkillsSelectWnd_x                                    0xE007B0
#define pinstCSkillsWnd_x                                          0xE00790
#define pinstCSocialEditWnd_x                                      0xDFFFA4
#define pinstCSocialWnd_x                                          0xE00780
#define pinstCSpellBookWnd_x                                       0xE007B4
#define pinstCStoryWnd_x                                           0xE00514
#define pinstCTargetOfTargetWnd_x                                  0xF7C6F0
#define pinstCTargetWnd_x                                          0xDFFFE0
#define pinstCTaskOverlayWnd_x                                     0xDFFF74
#define pinstCTaskSelectWnd_x                                      0xF7C848
#define pinstCTaskManager_x                                        0xCD1AC0
#define pinstCTaskTemplateSelectWnd_x                              0xF7C8F8
#define pinstCTaskWnd_x                                            0xF7C9A8
#define pinstCTextEntryWnd_x                                       0xDFFFC0
#define pinstCTimeLeftWnd_x                                        0xE0051C
#define pinstCTipWndCONTEXT_x                                      0xF7CBAC
#define pinstCTipWndOFDAY_x                                        0xF7CBA8
#define pinstCTitleWnd_x                                           0xF7CC58
#define pinstCTrackingWnd_x                                        0xDFFF68
#define pinstCTradeskillWnd_x                                      0xF7CDC0
#define pinstCTradeWnd_x                                           0xE00744
#define pinstCTrainWnd_x                                           0xE00740
#define pinstCTributeBenefitWnd_x                                  0xF7CFC0
#define pinstCTributeMasterWnd_x                                   0xF7D070
#define pinstCTributeTrophyWnd_x                                   0xF7D120
#define pinstCVideoModesWnd_x                                      0xE00518
#define pinstCVoiceMacroWnd_x                                      0xF66418
#define pinstCVoteResultsWnd_x                                     0xE0074C
#define pinstCVoteWnd_x                                            0xE00734
#define pinstCWebManager_x                                         0xF66A94
#define pinstCZoneGuideWnd_x                                       0xDFFF80
#define pinstCZonePathWnd_x                                        0xDFFF9C

#define pinstEQSuiteTextureLoader_x                                0xC9F080
#define pinstItemIconCache_x                                       0xF75F80
#define pinstLootFiltersManager_x                                  0xCD1230
#define pinstRewardSelectionWnd_x                                  0xF7B010

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AF160
#define __CastRay2_x                                               0x5AF1B0
#define __ConvertItemTags_x                                        0x5CAD10
#define __CleanItemTags_x                                          0x47CFB0
#define __DoesFileExist_x                                          0x904030
#define __EQGetTime_x                                              0x900970
#define __ExecuteCmd_x                                             0x5A7A20
#define __FixHeading_x                                             0x99BB80
#define __GameLoop_x                                               0x6BB560
#define __get_bearing_x                                            0x5AECD0
#define __get_melee_range_x                                        0x5AF3A0
#define __GetAnimationCache_x                                      0x720860
#define __GetGaugeValueFromEQ_x                                    0x813090
#define __GetLabelFromEQ_x                                         0x814B70
#define __GetXTargetType_x                                         0x99D5E0
#define __HandleMouseWheel_x                                       0x6BC420
#define __HeadingDiff_x                                            0x99BBF0
#define __HelpPath_x                                               0xF617BC
#define __LoadFrontEnd_x                                           0x6B8880
#define __NewUIINI_x                                               0x812D60
#define __ProcessGameEvents_x                                      0x60F190
#define __ProcessMouseEvent_x                                      0x60E950
#define __SaveColors_x                                             0x5515A0
#define __STMLToText_x                                             0x93EFA0
#define __ToggleKeyRingItem_x                                      0x514C50
#define CMemoryMappedFile__SetFile_x                               0xA8AE10
#define CrashDetected_x                                            0x6BA320
#define DrawNetStatus_x                                            0x63ABD0
#define Expansion_HoT_x                                            0xEC370C
#define Teleport_Table_Size_x                                      0xEB2740
#define Teleport_Table_x                                           0xEB2BA8
#define Util__FastTime_x                                           0x900540

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4901E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4990F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498EC0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493780
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492BD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559110
#define AltAdvManager__IsAbilityReady_x                            0x558040
#define AltAdvManager__GetAAById_x                                 0x558240
#define AltAdvManager__CanTrainAbility_x                           0x5582B0
#define AltAdvManager__CanSeeAbility_x                             0x558610

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA070
#define CharacterZoneClient__HasSkill_x                            0x4D4F60
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6680
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE380
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA990
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8FF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D90D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D91B0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3170
#define CharacterZoneClient__BardCastBard_x                        0x4C5CD0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA60
#define CharacterZoneClient__GetEffect_x                           0x4BA8D0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C41C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4290
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C42E0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4430
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4600
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B27D0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D75E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7060

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E2070
#define CBankWnd__WndNotification_x                                0x6E1E50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EF8B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61D750
#define CButtonWnd__CButtonWnd_x                                   0x93B380

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70F9F0
#define CChatManager__InitContextMenu_x                            0x708B50
#define CChatManager__FreeChatWindow_x                             0x70E530
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E85C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70F670
#define CChatManager__CreateChatWindow_x                           0x70EB70

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E86D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94FA20
#define CContextMenu__dCContextMenu_x                              0x94FC50
#define CContextMenu__AddMenuItem_x                                0x94FC60
#define CContextMenu__RemoveMenuItem_x                             0x94FF60
#define CContextMenu__RemoveAllMenuItems_x                         0x94FF80
#define CContextMenu__CheckMenuItem_x                              0x950000
#define CContextMenu__SetMenuItem_x                                0x94FE90
#define CContextMenu__AddSeparator_x                               0x94FDF0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9505A0
#define CContextMenuManager__RemoveMenu_x                          0x950610
#define CContextMenuManager__PopupMenu_x                           0x9506D0
#define CContextMenuManager__Flush_x                               0x950540
#define CContextMenuManager__GetMenu_x                             0x49B300
#define CContextMenuManager__CreateDefaultMenu_x                   0x71B060

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DC550
#define CChatService__GetFriendName_x                              0x8DC560

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x710260
#define CChatWindow__Clear_x                                       0x711520
#define CChatWindow__WndNotification_x                             0x711CB0
#define CChatWindow__AddHistory_x                                  0x710DE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94CEA0
#define CComboWnd__Draw_x                                          0x94C3A0
#define CComboWnd__GetCurChoice_x                                  0x94CCE0
#define CComboWnd__GetListRect_x                                   0x94C850
#define CComboWnd__GetTextRect_x                                   0x94CF00
#define CComboWnd__InsertChoice_x                                  0x94C9E0
#define CComboWnd__SetColors_x                                     0x94C9B0
#define CComboWnd__SetChoice_x                                     0x94CCB0
#define CComboWnd__GetItemCount_x                                  0x94CCF0
#define CComboWnd__GetCurChoiceText_x                              0x94CD30
#define CComboWnd__GetChoiceText_x                                 0x94CD00
#define CComboWnd__InsertChoiceAtIndex_x                           0x94CA70

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x718A60
#define CContainerWnd__vftable_x                                   0xB1247C
#define CContainerWnd__SetContainer_x                              0x719FC0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54BFE0
#define CDisplay__PreZoneMainUI_x                                  0x54BFF0
#define CDisplay__CleanGameUI_x                                    0x551360
#define CDisplay__GetClickedActor_x                                0x544300
#define CDisplay__GetUserDefinedColor_x                            0x53C9C0
#define CDisplay__GetWorldFilePath_x                               0x545D70
#define CDisplay__is3dON_x                                         0x540F60
#define CDisplay__ReloadUI_x                                       0x54B470
#define CDisplay__WriteTextHD2_x                                   0x540D50
#define CDisplay__TrueDistance_x                                   0x547A30
#define CDisplay__SetViewActor_x                                   0x543C20
#define CDisplay__GetFloorHeight_x                                 0x541020
#define CDisplay__SetRenderWindow_x                                0x53F980
#define CDisplay__ToggleScreenshotMode_x                           0x5436F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96F810

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x952F50
#define CEditWnd__GetCharIndexPt_x                                 0x953E70
#define CEditWnd__GetDisplayString_x                               0x953D10
#define CEditWnd__GetHorzOffset_x                                  0x952590
#define CEditWnd__GetLineForPrintableChar_x                        0x955010
#define CEditWnd__GetSelStartPt_x                                  0x954120
#define CEditWnd__GetSTMLSafeText_x                                0x953B30
#define CEditWnd__PointFromPrintableChar_x                         0x954C40
#define CEditWnd__SelectableCharFromPoint_x                        0x954DB0
#define CEditWnd__SetEditable_x                                    0x9541F0
#define CEditWnd__SetWindowTextA_x                                 0x9538B0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FCDF0
#define CEverQuest__ClickedPlayer_x                                0x5EEE00
#define CEverQuest__CreateTargetIndicator_x                        0x60C420
#define CEverQuest__DeleteTargetIndicator_x                        0x60C4B0
#define CEverQuest__DoTellWindow_x                                 0x4E87B0
#define CEverQuest__OutputTextToLog_x                              0x4E8A30
#define CEverQuest__DropHeldItemOnGround_x                         0x5E3E40
#define CEverQuest__dsp_chat_x                                     0x4E8DC0
#define CEverQuest__trimName_x                                     0x608700
#define CEverQuest__Emote_x                                        0x5FD650
#define CEverQuest__EnterZone_x                                    0x5F75D0
#define CEverQuest__GetBodyTypeDesc_x                              0x601FC0
#define CEverQuest__GetClassDesc_x                                 0x602600
#define CEverQuest__GetClassThreeLetterCode_x                      0x602C00
#define CEverQuest__GetDeityDesc_x                                 0x60AD60
#define CEverQuest__GetLangDesc_x                                  0x602DC0
#define CEverQuest__GetRaceDesc_x                                  0x6025E0
#define CEverQuest__InterpretCmd_x                                 0x60B330
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E8040
#define CEverQuest__LMouseUp_x                                     0x5E63D0
#define CEverQuest__RightClickedOnPlayer_x                         0x5E8920
#define CEverQuest__RMouseUp_x                                     0x5E7350
#define CEverQuest__SetGameState_x                                 0x5E3BD0
#define CEverQuest__UPCNotificationFlush_x                         0x608600
#define CEverQuest__IssuePetCommand_x                              0x6041C0
#define CEverQuest__ReportSuccessfulHit_x                          0x5FEA40

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72A950
#define CGaugeWnd__CalcLinesFillRect_x                             0x72A9B0
#define CGaugeWnd__Draw_x                                          0x729FD0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF200
#define CGuild__GetGuildName_x                                     0x4AE2E0
#define CGuild__GetGuildIndex_x                                    0x4AE670

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x745D50

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61DB10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x752D80
#define CInvSlotMgr__MoveItem_x                                    0x751A90
#define CInvSlotMgr__SelectSlot_x                                  0x752E50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x750310
#define CInvSlot__SliderComplete_x                                 0x74E070
#define CInvSlot__GetItemBase_x                                    0x74D9E0
#define CInvSlot__UpdateItem_x                                     0x74DB50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7548D0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x753A70
#define CInvSlotWnd__HandleLButtonUp_x                             0x754450

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80E3E0
#define CItemDisplayWnd__UpdateStrings_x                           0x762EC0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75CC20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75D130
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7634C0
#define CItemDisplayWnd__AboutToShow_x                             0x762B00
#define CItemDisplayWnd__WndNotification_x                         0x7645B0
#define CItemDisplayWnd__RequestConvertItem_x                      0x764070
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x761B70
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x762920

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x846E90

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x768AA0

// CLabel 
#define CLabel__Draw_x                                             0x76E4F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9255D0
#define CListWnd__dCListWnd_x                                      0x9258E0
#define CListWnd__AddColumn_x                                      0x929D00
#define CListWnd__AddColumn1_x                                     0x929D50
#define CListWnd__AddLine_x                                        0x92A0E0
#define CListWnd__AddString_x                                      0x929EE0
#define CListWnd__CalculateFirstVisibleLine_x                      0x929AC0
#define CListWnd__CalculateVSBRange_x                              0x9298C0
#define CListWnd__ClearSel_x                                       0x92A8C0
#define CListWnd__ClearAllSel_x                                    0x92A920
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92B320
#define CListWnd__Compare_x                                        0x929200
#define CListWnd__Draw_x                                           0x925A10
#define CListWnd__DrawColumnSeparators_x                           0x9281F0
#define CListWnd__DrawHeader_x                                     0x928650
#define CListWnd__DrawItem_x                                       0x928B40
#define CListWnd__DrawLine_x                                       0x928350
#define CListWnd__DrawSeparator_x                                  0x928290
#define CListWnd__EnableLine_x                                     0x927AD0
#define CListWnd__EnsureVisible_x                                  0x92B250
#define CListWnd__ExtendSel_x                                      0x92A7F0
#define CListWnd__GetColumnTooltip_x                               0x927610
#define CListWnd__GetColumnMinWidth_x                              0x927680
#define CListWnd__GetColumnWidth_x                                 0x927580
#define CListWnd__GetCurSel_x                                      0x926F10
#define CListWnd__GetItemAtPoint_x                                 0x927D40
#define CListWnd__GetItemAtPoint1_x                                0x927DB0
#define CListWnd__GetItemData_x                                    0x926F90
#define CListWnd__GetItemHeight_x                                  0x927350
#define CListWnd__GetItemIcon_x                                    0x927120
#define CListWnd__GetItemRect_x                                    0x927BC0
#define CListWnd__GetItemText_x                                    0x926FD0
#define CListWnd__GetSelList_x                                     0x92A970
#define CListWnd__GetSeparatorRect_x                               0x927FF0
#define CListWnd__InsertLine_x                                     0x92A4D0
#define CListWnd__RemoveLine_x                                     0x92A620
#define CListWnd__SetColors_x                                      0x9298A0
#define CListWnd__SetColumnJustification_x                         0x9295D0
#define CListWnd__SetColumnWidth_x                                 0x9294F0
#define CListWnd__SetCurSel_x                                      0x92A730
#define CListWnd__SetItemColor_x                                   0x92AF10
#define CListWnd__SetItemData_x                                    0x92AED0
#define CListWnd__SetItemText_x                                    0x92AAE0
#define CListWnd__ShiftColumnSeparator_x                           0x929690
#define CListWnd__Sort_x                                           0x929380
#define CListWnd__ToggleSel_x                                      0x92A760
#define CListWnd__SetColumnsSizable_x                              0x929740
#define CListWnd__SetItemWnd_x                                     0x92AD90
#define CListWnd__GetItemWnd_x                                     0x927170
#define CListWnd__SetItemIcon_x                                    0x92AB60
#define CListWnd__CalculateCustomWindowPositions_x                 0x929BC0
#define CListWnd__SetVScrollPos_x                                  0x9294D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x783D80
#define CMapViewWnd__GetWorldCoordinates_x                         0x782490
#define CMapViewWnd__HandleLButtonDown_x                           0x77F4D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A3D00
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A45E0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A4B10
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A7AA0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A2860
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AD650
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A3910

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A9FE0
#define CPacketScrambler__hton_x                                   0x8A9FD0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9445E0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9449F0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9447E0
#define CSidlManager__CreateLabel_x                                0x805890
#define CSidlManager__CreateXWndFromTemplate_x                     0x947950
#define CSidlManager__CreateXWndFromTemplate1_x                    0x947B30
#define CSidlManager__CreateXWnd_x                                 0x8057C0
#define CSidlManager__CreateHotButtonWnd_x                         0x805D80

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9410D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x940FD0
#define CSidlScreenWnd__ConvertToRes_x                             0x9667D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x940A70
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x940760
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x940830
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x940900
#define CSidlScreenWnd__DrawSidlPiece_x                            0x941550
#define CSidlScreenWnd__EnableIniStorage_x                         0x941A20
#define CSidlScreenWnd__GetSidlPiece_x                             0x941740
#define CSidlScreenWnd__Init1_x                                    0x940360
#define CSidlScreenWnd__LoadIniInfo_x                              0x941A70
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9425C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93F760
#define CSidlScreenWnd__StoreIniInfo_x                             0x942130
#define CSidlScreenWnd__StoreIniVis_x                              0x9424A0
#define CSidlScreenWnd__WndNotification_x                          0x941460
#define CSidlScreenWnd__GetChildItem_x                             0x9419A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x931120
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F7F30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x682110
#define CSkillMgr__GetSkillCap_x                                   0x6822F0
#define CSkillMgr__GetNameToken_x                                  0x681890
#define CSkillMgr__IsActivatedSkill_x                              0x6819D0
#define CSkillMgr__IsCombatSkill_x                                 0x681910

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x951370
#define CSliderWnd__SetValue_x                                     0x9511E0
#define CSliderWnd__SetNumTicks_x                                  0x951240

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80B870

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x959B50
#define CStmlWnd__CalculateHSBRange_x                              0x95AC70
#define CStmlWnd__CalculateVSBRange_x                              0x95ABE0
#define CStmlWnd__CanBreakAtCharacter_x                            0x95EFA0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95FC30
#define CStmlWnd__ForceParseNow_x                                  0x95A140
#define CStmlWnd__GetNextTagPiece_x                                0x95EF00
#define CStmlWnd__GetSTMLText_x                                    0x504490
#define CStmlWnd__GetVisibleText_x                                 0x95A160
#define CStmlWnd__InitializeWindowVariables_x                      0x95FA80
#define CStmlWnd__MakeStmlColorTag_x                               0x9591C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x959230
#define CStmlWnd__SetSTMLText_x                                    0x958270
#define CStmlWnd__StripFirstSTMLLines_x                            0x960D00
#define CStmlWnd__UpdateHistoryString_x                            0x95FE40

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9573C0
#define CTabWnd__DrawCurrentPage_x                                 0x957AF0
#define CTabWnd__DrawTab_x                                         0x957810
#define CTabWnd__GetCurrentPage_x                                  0x956BD0
#define CTabWnd__GetPageInnerRect_x                                0x956E10
#define CTabWnd__GetTabInnerRect_x                                 0x956D50
#define CTabWnd__GetTabRect_x                                      0x956C00
#define CTabWnd__InsertPage_x                                      0x957020
#define CTabWnd__SetPage_x                                         0x956E90
#define CTabWnd__SetPageRect_x                                     0x957300
#define CTabWnd__UpdatePage_x                                      0x9576D0
#define CTabWnd__GetPageFromTabIndex_x                             0x957750
#define CTabWnd__GetCurrentTabIndex_x                              0x956BC0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x768E70
#define CPageWnd__SetTabText_x                                     0x956720

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8E30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92E010
#define CTextureFont__GetTextExtent_x                              0x92E1D0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B5430
#define CHtmlComponentWnd__ValidateUri_x                           0x747740
#define CHtmlWnd__SetClientCallbacks_x                             0x622B90
#define CHtmlWnd__AddObserver_x                                    0x622BB0
#define CHtmlWnd__RemoveObserver_x                                 0x622C10
#define Window__getProgress_x                                      0x85F890
#define Window__getStatus_x                                        0x85F8B0
#define Window__getURI_x                                           0x85F8C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96C2A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91B160

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8400
#define CXStr__CXStr1_x                                            0x4FF510
#define CXStr__CXStr3_x                                            0x8FCAB0
#define CXStr__dCXStr_x                                            0x4786E0
#define CXStr__operator_equal_x                                    0x8FCCE0
#define CXStr__operator_equal1_x                                   0x8FCD20
#define CXStr__operator_plus_equal1_x                              0x8FD7B0
#define CXStr__SetString_x                                         0x8FF6A0
#define CXStr__operator_char_p_x                                   0x8FD1F0
#define CXStr__GetChar_x                                           0x8FEFF0
#define CXStr__Delete_x                                            0x8FE8A0
#define CXStr__GetUnicode_x                                        0x8FF060
#define CXStr__GetLength_x                                         0x4A8BE0
#define CXStr__Mid_x                                               0x47D360
#define CXStr__Insert_x                                            0x8FF0C0
#define CXStr__FindNext_x                                          0x8FED10

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94F640
#define CXWnd__BringToTop_x                                        0x9348A0
#define CXWnd__Center_x                                            0x934420
#define CXWnd__ClrFocus_x                                          0x934240
#define CXWnd__Destroy_x                                           0x9342E0
#define CXWnd__DoAllDrawing_x                                      0x9308C0
#define CXWnd__DrawChildren_x                                      0x930890
#define CXWnd__DrawColoredRect_x                                   0x930D10
#define CXWnd__DrawTooltip_x                                       0x92F400
#define CXWnd__DrawTooltipAtPoint_x                                0x92F4C0
#define CXWnd__GetBorderFrame_x                                    0x930B70
#define CXWnd__GetChildWndAt_x                                     0x934940
#define CXWnd__GetClientClipRect_x                                 0x932B30
#define CXWnd__GetScreenClipRect_x                                 0x932BE0
#define CXWnd__GetScreenRect_x                                     0x932D90
#define CXWnd__GetTooltipRect_x                                    0x930D60
#define CXWnd__GetWindowTextA_x                                    0x49CA70
#define CXWnd__IsActive_x                                          0x931490
#define CXWnd__IsDescendantOf_x                                    0x933790
#define CXWnd__IsReallyVisible_x                                   0x9337C0
#define CXWnd__IsType_x                                            0x934FA0
#define CXWnd__Move_x                                              0x933830
#define CXWnd__Move1_x                                             0x9338E0
#define CXWnd__ProcessTransition_x                                 0x9343D0
#define CXWnd__Refade_x                                            0x933BB0
#define CXWnd__Resize_x                                            0x933E50
#define CXWnd__Right_x                                             0x934660
#define CXWnd__SetFocus_x                                          0x934200
#define CXWnd__SetFont_x                                           0x934270
#define CXWnd__SetKeyTooltip_x                                     0x934DB0
#define CXWnd__SetMouseOver_x                                      0x931CB0
#define CXWnd__StartFade_x                                         0x933670
#define CXWnd__GetChildItem_x                                      0x934AA0
#define CXWnd__SetParent_x                                         0x933530
#define CXWnd__Minimize_x                                          0x933EC0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x967850

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x937800
#define CXWndManager__DrawWindows_x                                0x937820
#define CXWndManager__GetKeyboardFlags_x                           0x93A000
#define CXWndManager__HandleKeyboardMsg_x                          0x939BC0
#define CXWndManager__RemoveWnd_x                                  0x93A230
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93A7B0

// CDBStr
#define CDBStr__GetString_x                                        0x53B980

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB970
#define EQ_Character__Cur_HP_x                                     0x4D1FA0
#define EQ_Character__Cur_Mana_x                                   0x4D96B0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE9D0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2410
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2560
#define EQ_Character__GetHPRegen_x                                 0x4DF450
#define EQ_Character__GetEnduranceRegen_x                          0x4DFA50
#define EQ_Character__GetManaRegen_x                               0x4DFE90
#define EQ_Character__Max_Endurance_x                              0x648DE0
#define EQ_Character__Max_HP_x                                     0x4D1DD0
#define EQ_Character__Max_Mana_x                                   0x648BE0
#define EQ_Character__doCombatAbility_x                            0x64B240
#define EQ_Character__UseSkill_x                                   0x4E1C70
#define EQ_Character__GetConLevel_x                                0x641B70
#define EQ_Character__IsExpansionFlag_x                            0x5A61F0
#define EQ_Character__TotalEffect_x                                0x4C5410
#define EQ_Character__GetPCSpellAffect_x                           0x4BF720
#define EQ_Character__SpellDuration_x                              0x4BF250
#define EQ_Character__GetAdjustedSkill_x                           0x4D4D20
#define EQ_Character__GetBaseSkill_x                               0x4D5CC0
#define EQ_Character__CanUseItem_x                                 0x4D99C0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C9340

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65F2E0

//PcClient
#define PcClient__PcClient_x                                       0x63F2B0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95E0
#define CCharacterListWnd__EnterWorld_x                            0x4B9020
#define CCharacterListWnd__Quit_x                                  0x4B8D70
#define CCharacterListWnd__UpdateList_x                            0x4B91B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x623DD0
#define EQ_Item__CreateItemTagString_x                             0x8A3840
#define EQ_Item__IsStackable_x                                     0x8A83A0
#define EQ_Item__GetImageNum_x                                     0x8A52B0
#define EQ_Item__CreateItemClient_x                                0x622F90
#define EQ_Item__GetItemValue_x                                    0x8A65F0
#define EQ_Item__ValueSellMerchant_x                               0x8A9BC0
#define EQ_Item__IsKeyRingItem_x                                   0x8A7CC0
#define EQ_Item__CanGoInBag_x                                      0x623EF0
#define EQ_Item__IsEmpty_x                                         0x8A7820
#define EQ_Item__GetMaxItemCount_x                                 0x8A6A00
#define EQ_Item__GetHeldItem_x                                     0x8A5180
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A31C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x559E60
#define EQ_LoadingS__Array_x                                       0xC26B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x649740
#define EQ_PC__GetAlternateAbilityId_x                             0x8B2DE0
#define EQ_PC__GetCombatAbility_x                                  0x8B3450
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B34C0
#define EQ_PC__GetItemRecastTimer_x                                0x64B7C0
#define EQ_PC__HasLoreItem_x                                       0x642380
#define EQ_PC__AlertInventoryChanged_x                             0x6414B0
#define EQ_PC__GetPcZoneClient_x                                   0x66DDA0
#define EQ_PC__RemoveMyAffect_x                                    0x64E9F0
#define EQ_PC__GetKeyRingItems_x                                   0x8B3D50
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B3AE0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B4050

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AC750
#define EQItemList__add_object_x                                   0x5D9650
#define EQItemList__add_item_x                                     0x5ACCB0
#define EQItemList__delete_item_x                                  0x5ACD00
#define EQItemList__FreeItemList_x                                 0x5ACC00

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538470

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x660B60
#define EQPlayer__dEQPlayer_x                                      0x653EA0
#define EQPlayer__DoAttack_x                                       0x668A50
#define EQPlayer__EQPlayer_x                                       0x654560
#define EQPlayer__SetNameSpriteState_x                             0x658840
#define EQPlayer__SetNameSpriteTint_x                              0x659710
#define PlayerBase__HasProperty_j_x                                0x999F70
#define EQPlayer__IsTargetable_x                                   0x99A410
#define EQPlayer__CanSee_x                                         0x99A270
#define EQPlayer__CanSee1_x                                        0x99A340
#define PlayerBase__GetVisibilityLineSegment_x                     0x99A030

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66B830
#define PlayerZoneClient__GetLevel_x                               0x66DDE0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DA7C0
#define PlayerZoneClient__LegalPlayerRace_x                        0x5531F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x663960
#define EQPlayerManager__GetSpawnByName_x                          0x663A10
#define EQPlayerManager__GetPlayerFromPartialName_x                0x663AA0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6273F0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x627470
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6274B0
#define KeypressHandler__ClearCommandStateArray_x                  0x6288C0
#define KeypressHandler__HandleKeyDown_x                           0x6288E0
#define KeypressHandler__HandleKeyUp_x                             0x628980
#define KeypressHandler__SaveKeymapping_x                          0x628DD0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77FBF0
#define MapViewMap__SaveEx_x                                       0x782FB0
#define MapViewMap__SetZoom_x                                      0x787670

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C7260

// StringTable 
#define StringTable__getString_x                                   0x8C20A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64E660
#define PcZoneClient__RemovePetEffect_x                            0x64EC90
#define PcZoneClient__HasAlternateAbility_x                        0x648A10
#define PcZoneClient__GetCurrentMod_x                              0x4E4D30
#define PcZoneClient__GetModCap_x                                  0x4E4C30
#define PcZoneClient__CanEquipItem_x                               0x6490E0
#define PcZoneClient__GetItemByID_x                                0x64BC30
#define PcZoneClient__GetItemByItemClass_x                         0x64BD80
#define PcZoneClient__RemoveBuffEffect_x                           0x64ECB0
#define PcZoneClient__BandolierSwap_x                              0x649D00
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64B760

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DF340

//IconCache
#define IconCache__GetIcon_x                                       0x720100

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x717BF0
#define CContainerMgr__CloseContainer_x                            0x717EC0
#define CContainerMgr__OpenExperimentContainer_x                   0x718940

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D7D00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61BF40

//CLootWnd
#define CLootWnd__LootAll_x                                        0x775FD0
#define CLootWnd__RequestLootSlot_x                                0x775200

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x579B50
#define EQ_Spell__SpellAffects_x                                   0x579FC0
#define EQ_Spell__SpellAffectBase_x                                0x579D80
#define EQ_Spell__IsStackable_x                                    0x4C99E0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C98C0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6900
#define EQ_Spell__IsSPAStacking_x                                  0x57AE10
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A320
#define EQ_Spell__IsNoRemove_x                                     0x4C99C0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57AE20
#define __IsResEffectSpell_x                                       0x4C8E50

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACF00

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D19E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81EB80
#define CTargetWnd__WndNotification_x                              0x81E410
#define CTargetWnd__RefreshTargetBuffs_x                           0x81E6E0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81D580

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x823190

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x535EE0
#define CTaskManager__HandleMessage_x                              0x534360
#define CTaskManager__GetTaskStatus_x                              0x535F90
#define CTaskManager__GetElementDescription_x                      0x536010

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575010
#define EqSoundManager__PlayScriptMp3_x                            0x575170
#define EqSoundManager__SoundAssistPlay_x                          0x6860B0
#define EqSoundManager__WaveInstancePlay_x                         0x685620

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x529C20

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x955C30

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5617F0
#define CAltAbilityData__GetMercMaxRank_x                          0x561780
#define CAltAbilityData__GetMaxRank_x                              0x556EC0

//CTargetRing
#define CTargetRing__Cast_x                                        0x61A060

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C98A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5112A0
#define CharacterBase__CreateItemIndex_x                           0x622140
#define CharacterBase__GetItemPossession_x                         0x4FCE50
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D9FE0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DA040
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FEDF0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FF620
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FF6D0

//messages
#define msg_spell_worn_off_x                                       0x59E400
#define msg_new_text_x                                             0x593190
#define __msgTokenTextParam_x                                      0x5A0930
#define msgTokenText_x                                             0x5A0B80

//SpellManager
#define SpellManager__vftable_x                                    0xAEC4C0
#define SpellManager__SpellManager_x                               0x6893D0
#define Spellmanager__LoadTextSpells_x                             0x689CC0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6895A0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99DED0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x511930
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A4710
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63AA30
#define ItemGlobalIndex__IsValidIndex_x                            0x511990

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D2380
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D2600

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76E830

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71C300
#define CCursorAttachment__AttachToCursor1_x                       0x71C340
#define CCursorAttachment__Deactivate_x                            0x71D330

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x948970
#define CSidlManagerBase__CreatePageWnd_x                          0x948170
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x944400
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x944390

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x965CF0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9659B0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50E840
#define CFindItemWnd__WndNotification_x                            0x50F320
#define CFindItemWnd__Update_x                                     0x50FE90
#define CFindItemWnd__PickupSelectedItem_x                         0x50E090

//IString
#define IString__Append_x                                          0x4F0330

//Camera
#define CDisplay__cameraType_x                                     0xE00528
#define EverQuest__Cameras_x                                       0xEC3A5C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x516FF0
#define LootFiltersManager__GetItemFilterData_x                    0x5168F0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x516920
#define LootFiltersManager__SetItemLootFilter_x                    0x516B40

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C5C60

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A3A40
#define CResolutionHandler__GetWindowedStyle_x                     0x680CD0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7149D0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E6EC0
#define CDistillerInfo__Instance_x                                 0x8E6E60

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x734B40
#define CGroupWnd__UpdateDisplay_x                                 0x733EB0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A7D70
#define ItemBase__IsLoreEquipped_x                                 0x8A7DE0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D95B0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D96F0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D9750

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x676530
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x679EC0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x504CB0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1EA0
#define FactionManagerClient__HandleFactionMessage_x               0x4F2510
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2B10
#define FactionManagerClient__GetMaxFaction_x                      0x4F2B2F
#define FactionManagerClient__GetMinFaction_x                      0x4F2AE0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FCE20

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92CFC0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD80

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD0D0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x560CB0

//CTargetManager
#define CTargetManager__Get_x                                      0x68CC20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x676530

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8BF0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5ACBA0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF610F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
