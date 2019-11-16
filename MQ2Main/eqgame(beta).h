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
#define __ExpectedVersionDate                                     "Nov 16 2019"
#define __ExpectedVersionTime                                     "04:25:01"
#define __ActualVersionDate_x                                      0xB0927C
#define __ActualVersionTime_x                                      0xB09270
#define __ActualVersionBuild_x                                     0xAF4F5C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62EBD0
#define __MemChecker1_x                                            0x901D00
#define __MemChecker2_x                                            0x6BD860
#define __MemChecker3_x                                            0x6BD7B0
#define __MemChecker4_x                                            0x8593D0
#define __EncryptPad0_x                                            0xC3F3E8
#define __EncryptPad1_x                                            0xC9D5A8
#define __EncryptPad2_x                                            0xC4FC80
#define __EncryptPad3_x                                            0xC4F880
#define __EncryptPad4_x                                            0xC8DC00
#define __EncryptPad5_x                                            0xF691A0
#define __AC1_x                                                    0x815F26
#define __AC2_x                                                    0x5E8A6F
#define __AC3_x                                                    0x5F016F
#define __AC4_x                                                    0x5F4140
#define __AC5_x                                                    0x5FA44F
#define __AC6_x                                                    0x5FEA66
#define __AC7_x                                                    0x5E84E0
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
#define __do_loot_x                                                0x5B4E10
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
#define pinstCAggroMeterWnd_x                                      0xE0004C
#define pinstCAlarmWnd_x                                           0xE007C8
#define pinstCAlertHistoryWnd_x                                    0xDFFFBC
#define pinstCAlertStackWnd_x                                      0xE007D0
#define pinstCAlertWnd_x                                           0xDFFF40
#define pinstCAltStorageWnd_x                                      0xF73800
#define pinstCAudioTriggersWindow_x                                0xCB4B88
#define pinstCAuraWnd_x                                            0xDFFFDC
#define pinstCAvaZoneWnd_x                                         0xDFFFA0
#define pinstCBandolierWnd_x                                       0xE00034
#define pinstCBankWnd_x                                            0xDFFFD8
#define pinstCBarterMerchantWnd_x                                  0xF74A40
#define pinstCBarterSearchWnd_x                                    0xF74AF0
#define pinstCBarterWnd_x                                          0xF74BA0
#define pinstCBazaarConfirmationWnd_x                              0xE00794
#define pinstCBazaarSearchWnd_x                                    0xE00508
#define pinstCBazaarWnd_x                                          0xE007B0
#define pinstCBlockedBuffWnd_x                                     0xDFFFE0
#define pinstCBlockedPetBuffWnd_x                                  0xE00020
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
#define pinstCExtendedTargetWnd_x                                  0xE00014
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
#define pinstCIconSelectionWnd_x                                   0xE00050
#define pinstCInspectWnd_x                                         0xDFFF90
#define pinstCInventoryWnd_x                                       0xDFFF68
#define pinstCInvSlotMgr_x                                         0xE00764
#define pinstCItemDisplayManager_x                                 0xF790C0
#define pinstCItemExpTransferWnd_x                                 0xF791F0
#define pinstCItemOverflowWnd_x                                    0xE0050C
#define pinstCJournalCatWnd_x                                      0xE000E4
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE00018
#define pinstCKeyRingWnd_x                                         0xDFFFB4
#define pinstCLargeDialogWnd_x                                     0xF7B338
#define pinstCLayoutCopyWnd_x                                      0xF79540
#define pinstCLFGuildWnd_x                                         0xF795F0
#define pinstCLoadskinWnd_x                                        0xE007AC
#define pinstCLootFiltersCopyWnd_x                                 0xCD1180
#define pinstCLootFiltersWnd_x                                     0xE007D4
#define pinstCLootSettingsWnd_x                                    0xDFFF54
#define pinstCLootWnd_x                                            0xE004EC
#define pinstCMailAddressBookWnd_x                                 0xE00774
#define pinstCMailCompositionWnd_x                                 0xE00750
#define pinstCMailIgnoreListWnd_x                                  0xE00778
#define pinstCMailWnd_x                                            0xE00528
#define pinstCManageLootWnd_x                                      0xE01638
#define pinstCMapToolbarWnd_x                                      0xDFFF98
#define pinstCMapViewWnd_x                                         0xDFFF74
#define pinstCMarketplaceWnd_x                                     0xE007D8
#define pinstCMerchantWnd_x                                        0xE004F0
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
#define pinstCQuantityWnd_x                                        0xE0001C
#define pinstCRaceChangeWnd_x                                      0xE007C4
#define pinstCRaidOptionsWnd_x                                     0xE00068
#define pinstCRaidWnd_x                                            0xE00758
#define pinstCRealEstateItemsWnd_x                                 0xE00760
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE004F4
#define pinstCRealEstateManageWnd_x                                0xDFFF8C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFFFB0
#define pinstCRealEstatePlotSearchWnd_x                            0xDFFFD0
#define pinstCRealEstatePurchaseWnd_x                              0xDFFFF0
#define pinstCRespawnWnd_x                                         0xDFFFEC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE0077C
#define pinstCSendMoneyWnd_x                                       0xDFFF44
#define pinstCServerListWnd_x                                      0xE00048
#define pinstCSkillsSelectWnd_x                                    0xE007B8
#define pinstCSkillsWnd_x                                          0xE00798
#define pinstCSocialEditWnd_x                                      0xDFFFAC
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
#define pinstCZonePathWnd_x                                        0xDFFFA4

#define pinstEQSuiteTextureLoader_x                                0xC9F080
#define pinstItemIconCache_x                                       0xF75F80
#define pinstLootFiltersManager_x                                  0xCD1230
#define pinstRewardSelectionWnd_x                                  0xF7B010

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B0270
#define __CastRay2_x                                               0x5B02C0
#define __ConvertItemTags_x                                        0x5CBE10
#define __CleanItemTags_x                                          0x47D110
#define __DoesFileExist_x                                          0x904DE0
#define __EQGetTime_x                                              0x9017D0
#define __ExecuteCmd_x                                             0x5A8B30
#define __FixHeading_x                                             0x99BB70
#define __GameLoop_x                                               0x6BCA50
#define __get_bearing_x                                            0x5AFDE0
#define __get_melee_range_x                                        0x5B04B0
#define __GetAnimationCache_x                                      0x721B90
#define __GetGaugeValueFromEQ_x                                    0x8143D0
#define __GetLabelFromEQ_x                                         0x815EB0
#define __GetXTargetType_x                                         0x99D5C0
#define __HandleMouseWheel_x                                       0x6BD910
#define __HeadingDiff_x                                            0x99BBE0
#define __HelpPath_x                                               0xF617BC
#define __LoadFrontEnd_x                                           0x6B9D70
#define __NewUIINI_x                                               0x8140A0
#define __ProcessGameEvents_x                                      0x6102D0
#define __ProcessMouseEvent_x                                      0x60FA90
#define __SaveColors_x                                             0x551680
#define __STMLToText_x                                             0x93F1E0
#define __ToggleKeyRingItem_x                                      0x514D80
#define CMemoryMappedFile__SetFile_x                               0xA8AF20
#define CrashDetected_x                                            0x6BB810
#define DrawNetStatus_x                                            0x63BE70
#define Expansion_HoT_x                                            0xEC370C
#define Teleport_Table_Size_x                                      0xEB2740
#define Teleport_Table_x                                           0xEB2BA8
#define Util__FastTime_x                                           0x9013A0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4902D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4991D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498FA0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493860
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492CB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559280
#define AltAdvManager__IsAbilityReady_x                            0x5581B0
#define AltAdvManager__GetAAById_x                                 0x5583B0
#define AltAdvManager__CanTrainAbility_x                           0x558420
#define AltAdvManager__CanSeeAbility_x                             0x558780

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA0A0
#define CharacterZoneClient__HasSkill_x                            0x4D4F90
#define CharacterZoneClient__MakeMeVisible_x                       0x4D66B0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE2B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA8B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9040
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9120
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9200
#define CharacterZoneClient__FindAffectSlot_x                      0x4C30B0
#define CharacterZoneClient__BardCastBard_x                        0x4C5C10
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA980
#define CharacterZoneClient__GetEffect_x                           0x4BA7F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4100
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C41D0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4220
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4370
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4540
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B27B0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7610
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7090

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E32B0
#define CBankWnd__WndNotification_x                                0x6E3090

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F0BA0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61EA60
#define CButtonWnd__CButtonWnd_x                                   0x93B590

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x710CE0
#define CChatManager__InitContextMenu_x                            0x709E40
#define CChatManager__FreeChatWindow_x                             0x70F820
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8590
#define CChatManager__SetLockedActiveChatWindow_x                  0x710960
#define CChatManager__CreateChatWindow_x                           0x70FE60

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
#define CContextMenuManager__GetMenu_x                             0x49B460
#define CContextMenuManager__CreateDefaultMenu_x                   0x71C3B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8A7CF0
#define CChatService__GetFriendName_x                              0x8DD350

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x711550
#define CChatWindow__Clear_x                                       0x712810
#define CChatWindow__WndNotification_x                             0x712FA0
#define CChatWindow__AddHistory_x                                  0x7120D0

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
#define CContainerWnd__HandleCombine_x                             0x719DA0
#define CContainerWnd__vftable_x                                   0xB12464
#define CContainerWnd__SetContainer_x                              0x71B300

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
#define CEditBaseWnd__SetSel_x                                     0x96F910

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x95318F
#define CEditWnd__GetCharIndexPt_x                                 0x9540C0
#define CEditWnd__GetDisplayString_x                               0x953F60
#define CEditWnd__GetHorzOffset_x                                  0x9527D0
#define CEditWnd__GetLineForPrintableChar_x                        0x955260
#define CEditWnd__GetSelStartPt_x                                  0x954370
#define CEditWnd__GetSTMLSafeText_x                                0x953D80
#define CEditWnd__PointFromPrintableChar_x                         0x954E90
#define CEditWnd__SelectableCharFromPoint_x                        0x955000
#define CEditWnd__SetEditable_x                                    0x954440
#define CEditWnd__SetWindowTextA_x                                 0x953B00

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FDF40
#define CEverQuest__ClickedPlayer_x                                0x5EFF50
#define CEverQuest__CreateTargetIndicator_x                        0x60D560
#define CEverQuest__DeleteTargetIndicator_x                        0x60D5F0
#define CEverQuest__DoTellWindow_x                                 0x4E8780
#define CEverQuest__OutputTextToLog_x                              0x4E8A00
#define CEverQuest__DropHeldItemOnGround_x                         0x5E4F90
#define CEverQuest__dsp_chat_x                                     0x4E8D90
#define CEverQuest__trimName_x                                     0x609850
#define CEverQuest__Emote_x                                        0x5FE7A0
#define CEverQuest__EnterZone_x                                    0x5F8720
#define CEverQuest__GetBodyTypeDesc_x                              0x603110
#define CEverQuest__GetClassDesc_x                                 0x603750
#define CEverQuest__GetClassThreeLetterCode_x                      0x603D50
#define CEverQuest__GetDeityDesc_x                                 0x60BEA0
#define CEverQuest__GetLangDesc_x                                  0x603F10
#define CEverQuest__GetRaceDesc_x                                  0x603730
#define CEverQuest__InterpretCmd_x                                 0x60C470
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E9190
#define CEverQuest__LMouseUp_x                                     0x5E7520
#define CEverQuest__RightClickedOnPlayer_x                         0x5E9A70
#define CEverQuest__RMouseUp_x                                     0x5E84A0
#define CEverQuest__SetGameState_x                                 0x5E4D20
#define CEverQuest__UPCNotificationFlush_x                         0x609750
#define CEverQuest__IssuePetCommand_x                              0x605310
#define CEverQuest__ReportSuccessfulHit_x                          0x5FFB90

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72BD40
#define CGaugeWnd__CalcLinesFillRect_x                             0x72BDA0
#define CGaugeWnd__Draw_x                                          0x72B3C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF2A0
#define CGuild__GetGuildName_x                                     0x4AE380
#define CGuild__GetGuildIndex_x                                    0x4AE710

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x747150

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61EE20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x754140
#define CInvSlotMgr__MoveItem_x                                    0x752E50
#define CInvSlotMgr__SelectSlot_x                                  0x754210

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7516D0
#define CInvSlot__SliderComplete_x                                 0x74F430
#define CInvSlot__GetItemBase_x                                    0x74EDB0
#define CInvSlot__UpdateItem_x                                     0x74EF20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x755C70
#define CInvSlotWnd__CInvSlotWnd_x                                 0x754E10
#define CInvSlotWnd__HandleLButtonUp_x                             0x7557F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80F700
#define CItemDisplayWnd__UpdateStrings_x                           0x764210
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75DFA0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75E4B0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x764810
#define CItemDisplayWnd__AboutToShow_x                             0x763E70
#define CItemDisplayWnd__WndNotification_x                         0x765900
#define CItemDisplayWnd__RequestConvertItem_x                      0x7653C0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x762ED0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x763C90

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x847FB0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x769E00

// CLabel 
#define CLabel__Draw_x                                             0x76F7F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9259D0
#define CListWnd__dCListWnd_x                                      0x925CF0
#define CListWnd__AddColumn_x                                      0x92A120
#define CListWnd__AddColumn1_x                                     0x92A170
#define CListWnd__AddLine_x                                        0x92A500
#define CListWnd__AddString_x                                      0x92A300
#define CListWnd__CalculateFirstVisibleLine_x                      0x929EE0
#define CListWnd__CalculateVSBRange_x                              0x929CD0
#define CListWnd__ClearSel_x                                       0x92ACE0
#define CListWnd__ClearAllSel_x                                    0x92AD40
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92B760
#define CListWnd__Compare_x                                        0x929610
#define CListWnd__Draw_x                                           0x925E20
#define CListWnd__DrawColumnSeparators_x                           0x9285F0
#define CListWnd__DrawHeader_x                                     0x928A50
#define CListWnd__DrawItem_x                                       0x928F50
#define CListWnd__DrawLine_x                                       0x928750
#define CListWnd__DrawSeparator_x                                  0x928690
#define CListWnd__EnableLine_x                                     0x927EE0
#define CListWnd__EnsureVisible_x                                  0x92B680
#define CListWnd__ExtendSel_x                                      0x92AC10
#define CListWnd__GetColumnTooltip_x                               0x927A20
#define CListWnd__GetColumnMinWidth_x                              0x927A90
#define CListWnd__GetColumnWidth_x                                 0x927990
#define CListWnd__GetCurSel_x                                      0x927320
#define CListWnd__GetItemAtPoint_x                                 0x928150
#define CListWnd__GetItemAtPoint1_x                                0x9281C0
#define CListWnd__GetItemData_x                                    0x9273A0
#define CListWnd__GetItemHeight_x                                  0x927760
#define CListWnd__GetItemIcon_x                                    0x927530
#define CListWnd__GetItemRect_x                                    0x927FD0
#define CListWnd__GetItemText_x                                    0x9273E0
#define CListWnd__GetSelList_x                                     0x92AD90
#define CListWnd__GetSeparatorRect_x                               0x928400
#define CListWnd__InsertLine_x                                     0x92A8F0
#define CListWnd__RemoveLine_x                                     0x92AA40
#define CListWnd__SetColors_x                                      0x929CB0
#define CListWnd__SetColumnJustification_x                         0x9299E0
#define CListWnd__SetColumnWidth_x                                 0x929900
#define CListWnd__SetCurSel_x                                      0x92AB50
#define CListWnd__SetItemColor_x                                   0x92B330
#define CListWnd__SetItemData_x                                    0x92B2F0
#define CListWnd__SetItemText_x                                    0x92AF00
#define CListWnd__ShiftColumnSeparator_x                           0x929AA0
#define CListWnd__Sort_x                                           0x929790
#define CListWnd__ToggleSel_x                                      0x92AB80
#define CListWnd__SetColumnsSizable_x                              0x929B50
#define CListWnd__SetItemWnd_x                                     0x92B1B0
#define CListWnd__GetItemWnd_x                                     0x927580
#define CListWnd__SetItemIcon_x                                    0x92AF80
#define CListWnd__CalculateCustomWindowPositions_x                 0x929FE0
#define CListWnd__SetVScrollPos_x                                  0x9298E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x784FF0
#define CMapViewWnd__GetWorldCoordinates_x                         0x783700
#define CMapViewWnd__HandleLButtonDown_x                           0x780740

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A51D0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A5AB0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A5FD0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A8F60
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A3D40
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AEB00
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A4DF0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AAF70
#define CPacketScrambler__hton_x                                   0x8AAF60

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x944810
#define CSidlManager__FindScreenPieceTemplate_x                    0x944C20
#define CSidlManager__FindScreenPieceTemplate1_x                   0x944A10
#define CSidlManager__CreateLabel_x                                0x806BB0
#define CSidlManager__CreateXWndFromTemplate_x                     0x947B80
#define CSidlManager__CreateXWndFromTemplate1_x                    0x947D50
#define CSidlManager__CreateXWnd_x                                 0x806AE0
#define CSidlManager__CreateHotButtonWnd_x                         0x8070A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9412F0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9411F0
#define CSidlScreenWnd__ConvertToRes_x                             0x966900
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x940C90
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x940980
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x940A50
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x940B20
#define CSidlScreenWnd__DrawSidlPiece_x                            0x941770
#define CSidlScreenWnd__EnableIniStorage_x                         0x941C40
#define CSidlScreenWnd__GetSidlPiece_x                             0x941960
#define CSidlScreenWnd__Init1_x                                    0x940580
#define CSidlScreenWnd__LoadIniInfo_x                              0x941C90
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9427F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93F990
#define CSidlScreenWnd__StoreIniInfo_x                             0x942360
#define CSidlScreenWnd__StoreIniVis_x                              0x9426D0
#define CSidlScreenWnd__WndNotification_x                          0x941680
#define CSidlScreenWnd__GetChildItem_x                             0x941BC0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x931540
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F7F30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x683760
#define CSkillMgr__GetSkillCap_x                                   0x683940
#define CSkillMgr__GetNameToken_x                                  0x682EE0
#define CSkillMgr__IsActivatedSkill_x                              0x683020
#define CSkillMgr__IsCombatSkill_x                                 0x682F60

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9515B0
#define CSliderWnd__SetValue_x                                     0x951420
#define CSliderWnd__SetNumTicks_x                                  0x951480

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80CB90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x959DA0
#define CStmlWnd__CalculateHSBRange_x                              0x95AEC0
#define CStmlWnd__CalculateVSBRange_x                              0x95AE30
#define CStmlWnd__CanBreakAtCharacter_x                            0x95F1E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95FE70
#define CStmlWnd__ForceParseNow_x                                  0x95A390
#define CStmlWnd__GetNextTagPiece_x                                0x95F140
#define CStmlWnd__GetSTMLText_x                                    0x504670
#define CStmlWnd__GetVisibleText_x                                 0x95A3B0
#define CStmlWnd__InitializeWindowVariables_x                      0x95FCC0
#define CStmlWnd__MakeStmlColorTag_x                               0x959410
#define CStmlWnd__MakeWndNotificationTag_x                         0x959480
#define CStmlWnd__SetSTMLText_x                                    0x9584C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x960F40
#define CStmlWnd__UpdateHistoryString_x                            0x960080

// CTabWnd 
#define CTabWnd__Draw_x                                            0x957610
#define CTabWnd__DrawCurrentPage_x                                 0x957D40
#define CTabWnd__DrawTab_x                                         0x957A60
#define CTabWnd__GetCurrentPage_x                                  0x956E20
#define CTabWnd__GetPageInnerRect_x                                0x957060
#define CTabWnd__GetTabInnerRect_x                                 0x956FA0
#define CTabWnd__GetTabRect_x                                      0x956E50
#define CTabWnd__InsertPage_x                                      0x957270
#define CTabWnd__SetPage_x                                         0x9570E0
#define CTabWnd__SetPageRect_x                                     0x957550
#define CTabWnd__UpdatePage_x                                      0x957920
#define CTabWnd__GetPageFromTabIndex_x                             0x9579A0
#define CTabWnd__GetCurrentTabIndex_x                              0x956E10

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76A1F0
#define CPageWnd__SetTabText_x                                     0x956970

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8F50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92E450
#define CTextureFont__GetTextExtent_x                              0x92E610

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B6900
#define CHtmlComponentWnd__ValidateUri_x                           0x748B40
#define CHtmlWnd__SetClientCallbacks_x                             0x623EA0
#define CHtmlWnd__AddObserver_x                                    0x623EC0
#define CHtmlWnd__RemoveObserver_x                                 0x623F20
#define Window__getProgress_x                                      0x860990
#define Window__getStatus_x                                        0x8609B0
#define Window__getURI_x                                           0x8609C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96C3A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91B620

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E83D0
#define CXStr__CXStr1_x                                            0x4FF880
#define CXStr__CXStr3_x                                            0x8FD8D0
#define CXStr__dCXStr_x                                            0x478740
#define CXStr__operator_equal_x                                    0x8FDB00
#define CXStr__operator_equal1_x                                   0x8FDB40
#define CXStr__operator_plus_equal1_x                              0x8FE5D0
#define CXStr__SetString_x                                         0x9004C0
#define CXStr__operator_char_p_x                                   0x8FE010
#define CXStr__GetChar_x                                           0x8FFDF0
#define CXStr__Delete_x                                            0x8FF6C0
#define CXStr__GetUnicode_x                                        0x8FFE60
#define CXStr__GetLength_x                                         0x47D4C0
#define CXStr__Mid_x                                               0x47D4D0
#define CXStr__Insert_x                                            0x8FFEC0
#define CXStr__FindNext_x                                          0x8FFB30

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94F850
#define CXWnd__BringToTop_x                                        0x934C00
#define CXWnd__Center_x                                            0x934780
#define CXWnd__ClrFocus_x                                          0x934590
#define CXWnd__Destroy_x                                           0x934640
#define CXWnd__DoAllDrawing_x                                      0x930D10
#define CXWnd__DrawChildren_x                                      0x930CE0
#define CXWnd__DrawColoredRect_x                                   0x931150
#define CXWnd__DrawTooltip_x                                       0x92F850
#define CXWnd__DrawTooltipAtPoint_x                                0x92F910
#define CXWnd__GetBorderFrame_x                                    0x930FB0
#define CXWnd__GetChildWndAt_x                                     0x934CA0
#define CXWnd__GetClientClipRect_x                                 0x932ED0
#define CXWnd__GetScreenClipRect_x                                 0x932FA0
#define CXWnd__GetScreenRect_x                                     0x933160
#define CXWnd__GetTooltipRect_x                                    0x9311A0
#define CXWnd__GetWindowTextA_x                                    0x49CB60
#define CXWnd__IsActive_x                                          0x9318B0
#define CXWnd__IsDescendantOf_x                                    0x933B40
#define CXWnd__IsReallyVisible_x                                   0x933B70
#define CXWnd__IsType_x                                            0x935310
#define CXWnd__Move_x                                              0x933BD0
#define CXWnd__Move1_x                                             0x933C80
#define CXWnd__ProcessTransition_x                                 0x934730
#define CXWnd__Refade_x                                            0x933F40
#define CXWnd__Resize_x                                            0x9341B0
#define CXWnd__Right_x                                             0x9349C0
#define CXWnd__SetFocus_x                                          0x934550
#define CXWnd__SetFont_x                                           0x9345C0
#define CXWnd__SetKeyTooltip_x                                     0x935120
#define CXWnd__SetMouseOver_x                                      0x9320B0
#define CXWnd__StartFade_x                                         0x933A20
#define CXWnd__GetChildItem_x                                      0x934E00
#define CXWnd__SetParent_x                                         0x9338E0
#define CXWnd__Minimize_x                                          0x934220

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x967980

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x937B20
#define CXWndManager__DrawWindows_x                                0x937B40
#define CXWndManager__GetKeyboardFlags_x                           0x93A240
#define CXWndManager__HandleKeyboardMsg_x                          0x939E00
#define CXWndManager__RemoveWnd_x                                  0x93A470
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93A9C0

// CDBStr
#define CDBStr__GetString_x                                        0x53BA70

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB890
#define EQ_Character__Cur_HP_x                                     0x4D1FD0
#define EQ_Character__Cur_Mana_x                                   0x4D9700
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE900
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B23F0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2540
#define EQ_Character__GetHPRegen_x                                 0x4DF4B0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFAB0
#define EQ_Character__GetManaRegen_x                               0x4DFEF0
#define EQ_Character__Max_Endurance_x                              0x649CE0
#define EQ_Character__Max_HP_x                                     0x4D1E00
#define EQ_Character__Max_Mana_x                                   0x649AE0
#define EQ_Character__doCombatAbility_x                            0x64C140
#define EQ_Character__UseSkill_x                                   0x4E1CD0
#define EQ_Character__GetConLevel_x                                0x642E00
#define EQ_Character__IsExpansionFlag_x                            0x5A7300
#define EQ_Character__TotalEffect_x                                0x4C5350
#define EQ_Character__GetPCSpellAffect_x                           0x4BF650
#define EQ_Character__SpellDuration_x                              0x4BF180
#define EQ_Character__GetAdjustedSkill_x                           0x4D4D50
#define EQ_Character__GetBaseSkill_x                               0x4D5CF0
#define EQ_Character__CanUseItem_x                                 0x4D9A10

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CA1F0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x660660

//PcClient
#define PcClient__PcClient_x                                       0x640550

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9500
#define CCharacterListWnd__EnterWorld_x                            0x4B8F40
#define CCharacterListWnd__Quit_x                                  0x4B8C90
#define CCharacterListWnd__UpdateList_x                            0x4B90D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6250E0
#define EQ_Item__CreateItemTagString_x                             0x8A4800
#define EQ_Item__IsStackable_x                                     0x8A9350
#define EQ_Item__GetImageNum_x                                     0x8A6270
#define EQ_Item__CreateItemClient_x                                0x6242C0
#define EQ_Item__GetItemValue_x                                    0x8A7570
#define EQ_Item__ValueSellMerchant_x                               0x8AAB50
#define EQ_Item__IsKeyRingItem_x                                   0x8A8C70
#define EQ_Item__CanGoInBag_x                                      0x625200
#define EQ_Item__IsEmpty_x                                         0x8A87B0
#define EQ_Item__GetMaxItemCount_x                                 0x8A7980
#define EQ_Item__GetHeldItem_x                                     0x8A6140
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A4180

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x559FC0
#define EQ_LoadingS__Array_x                                       0xC26B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64A640
#define EQ_PC__GetAlternateAbilityId_x                             0x8B3DC0
#define EQ_PC__GetCombatAbility_x                                  0x8B4430
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B44A0
#define EQ_PC__GetItemRecastTimer_x                                0x64C6C0
#define EQ_PC__HasLoreItem_x                                       0x6435C0
#define EQ_PC__AlertInventoryChanged_x                             0x642750
#define EQ_PC__GetPcZoneClient_x                                   0x66F0E0
#define EQ_PC__RemoveMyAffect_x                                    0x64F8F0
#define EQ_PC__GetKeyRingItems_x                                   0x8B4D30
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B4AC0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B5030

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AD840
#define EQItemList__add_object_x                                   0x5DA710
#define EQItemList__add_item_x                                     0x5ADDA0
#define EQItemList__delete_item_x                                  0x5ADDF0
#define EQItemList__FreeItemList_x                                 0x5ADCF0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538570

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x661EE0
#define EQPlayer__dEQPlayer_x                                      0x654E10
#define EQPlayer__DoAttack_x                                       0x669D70
#define EQPlayer__EQPlayer_x                                       0x6554D0
#define EQPlayer__SetNameSpriteState_x                             0x659BD0
#define EQPlayer__SetNameSpriteTint_x                              0x65AA90
#define PlayerBase__HasProperty_j_x                                0x999F60
#define EQPlayer__IsTargetable_x                                   0x99A400
#define EQPlayer__CanSee_x                                         0x99A260
#define EQPlayer__CanSee1_x                                        0x99A330
#define PlayerBase__GetVisibilityLineSegment_x                     0x99A020

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66CB70
#define PlayerZoneClient__GetLevel_x                               0x66F120
#define PlayerZoneClient__IsValidTeleport_x                        0x5DB880
#define PlayerZoneClient__LegalPlayerRace_x                        0x5532A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x664C30
#define EQPlayerManager__GetSpawnByName_x                          0x664CE0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x664D70

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x628700
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x628780
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6287C0
#define KeypressHandler__ClearCommandStateArray_x                  0x629BD0
#define KeypressHandler__HandleKeyDown_x                           0x629BF0
#define KeypressHandler__HandleKeyUp_x                             0x629C90
#define KeypressHandler__SaveKeymapping_x                          0x62A0E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x780E60
#define MapViewMap__SaveEx_x                                       0x784220
#define MapViewMap__SetZoom_x                                      0x7888E0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C8110

// StringTable 
#define StringTable__getString_x                                   0x8C3030

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64F560
#define PcZoneClient__RemovePetEffect_x                            0x64FB90
#define PcZoneClient__HasAlternateAbility_x                        0x649910
#define PcZoneClient__GetCurrentMod_x                              0x4E4D80
#define PcZoneClient__GetModCap_x                                  0x4E4C80
#define PcZoneClient__CanEquipItem_x                               0x649FE0
#define PcZoneClient__GetItemByID_x                                0x64CB30
#define PcZoneClient__GetItemByItemClass_x                         0x64CC80
#define PcZoneClient__RemoveBuffEffect_x                           0x64FBB0
#define PcZoneClient__BandolierSwap_x                              0x64AC00
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64C660

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E0440

//IconCache
#define IconCache__GetIcon_x                                       0x721430

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x718F40
#define CContainerMgr__CloseContainer_x                            0x719210
#define CContainerMgr__OpenExperimentContainer_x                   0x719C90

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D8FC0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61D250

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7772A0
#define CLootWnd__RequestLootSlot_x                                0x7764D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x579CA0
#define EQ_Spell__SpellAffects_x                                   0x57A110
#define EQ_Spell__SpellAffectBase_x                                0x579ED0
#define EQ_Spell__IsStackable_x                                    0x4C9A00
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9850
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B68C0
#define EQ_Spell__IsSPAStacking_x                                  0x57AF60
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A470
#define EQ_Spell__IsNoRemove_x                                     0x4C99E0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57AF70
#define __IsResEffectSpell_x                                       0x4C8D90

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD010

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D2820

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81FEA0
#define CTargetWnd__WndNotification_x                              0x81F730
#define CTargetWnd__RefreshTargetBuffs_x                           0x81FA00
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81E8A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x824490

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x535FE0
#define CTaskManager__HandleMessage_x                              0x534480
#define CTaskManager__GetTaskStatus_x                              0x536090
#define CTaskManager__GetElementDescription_x                      0x536110

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575190
#define EqSoundManager__PlayScriptMp3_x                            0x5752F0
#define EqSoundManager__SoundAssistPlay_x                          0x687620
#define EqSoundManager__WaveInstancePlay_x                         0x686B90

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x529D20

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x955E80

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5619A0
#define CAltAbilityData__GetMercMaxRank_x                          0x561930
#define CAltAbilityData__GetMaxRank_x                              0x557030

//CTargetRing
#define CTargetRing__Cast_x                                        0x61B370

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9830
#define CharacterBase__CreateItemGlobalIndex_x                     0x511330
#define CharacterBase__CreateItemIndex_x                           0x623450
#define CharacterBase__GetItemPossession_x                         0x4FD0A0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DAE20
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DAE80
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FFFA0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x7007D0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x700880

//messages
#define msg_spell_worn_off_x                                       0x59F500
#define msg_new_text_x                                             0x5942B0
#define __msgTokenTextParam_x                                      0x5A1A30
#define msgTokenText_x                                             0x5A1C80

//SpellManager
#define SpellManager__vftable_x                                    0xAEC4B0
#define SpellManager__SpellManager_x                               0x68A950
#define Spellmanager__LoadTextSpells_x                             0x68B240
#define SpellManager__GetSpellByGroupAndRank_x                     0x68AB20

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99DEB0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5119B0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A57F0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63BCD0
#define ItemGlobalIndex__IsValidIndex_x                            0x511A10

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D31C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D3440

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76FB30

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71D640
#define CCursorAttachment__AttachToCursor1_x                       0x71D680
#define CCursorAttachment__Deactivate_x                            0x71E670

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x948B90
#define CSidlManagerBase__CreatePageWnd_x                          0x948390
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x944630
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9445C0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x965C40
#define CEQSuiteTextureLoader__GetTexture_x                        0x965900

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50E8A0
#define CFindItemWnd__WndNotification_x                            0x50F380
#define CFindItemWnd__Update_x                                     0x50FEF0
#define CFindItemWnd__PickupSelectedItem_x                         0x50E0F0

//IString
#define IString__Append_x                                          0x4F0310

//Camera
#define CDisplay__cameraType_x                                     0xE00530
#define EverQuest__Cameras_x                                       0xEC3A5C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517110
#define LootFiltersManager__GetItemFilterData_x                    0x516A20
#define LootFiltersManager__RemoveItemLootFilter_x                 0x516A50
#define LootFiltersManager__SetItemLootFilter_x                    0x516C70

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C6FF0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A39E0
#define CResolutionHandler__GetWindowedStyle_x                     0x6822B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x715CB0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E7E90
#define CDistillerInfo__Instance_x                                 0x8E7E30

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x735F30
#define CGroupWnd__UpdateDisplay_x                                 0x7352A0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A8D20
#define ItemBase__IsLoreEquipped_x                                 0x8A8D90

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DA670
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DA7B0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DA810

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6777E0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67B170

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x504C70

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1E10
#define FactionManagerClient__HandleFactionMessage_x               0x4F2480
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2A80
#define FactionManagerClient__GetMaxFaction_x                      0x4F2A9F
#define FactionManagerClient__GetMinFaction_x                      0x4F2A50

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD070

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92D400

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE70

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD440

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x560E40

//CTargetManager
#define CTargetManager__Get_x                                      0x68E170

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6777E0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D10

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5ADC90

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF610F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
