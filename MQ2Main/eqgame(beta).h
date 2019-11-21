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
#define __ExpectedVersionDate                                     "Nov 21 2019"
#define __ExpectedVersionTime                                     "04:23:22"
#define __ActualVersionDate_x                                      0xB0928C
#define __ActualVersionTime_x                                      0xB09280
#define __ActualVersionBuild_x                                     0xAF4F64

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62EA70
#define __MemChecker1_x                                            0x9016F0
#define __MemChecker2_x                                            0x6BCCC0
#define __MemChecker3_x                                            0x6BCC10
#define __MemChecker4_x                                            0x858640
#define __EncryptPad0_x                                            0xC3F3E8
#define __EncryptPad1_x                                            0xC9D5A8
#define __EncryptPad2_x                                            0xC4FC80
#define __EncryptPad3_x                                            0xC4F880
#define __EncryptPad4_x                                            0xC8DC00
#define __EncryptPad5_x                                            0xF691A0
#define __AC1_x                                                    0x8155C6
#define __AC2_x                                                    0x5E891F
#define __AC3_x                                                    0x5F001F
#define __AC4_x                                                    0x5F3FF0
#define __AC5_x                                                    0x5FA2FF
#define __AC6_x                                                    0x5FE916
#define __AC7_x                                                    0x5E8390
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
#define __do_loot_x                                                0x5B4D10
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
#define __gfMaxCameraDistance_x                                    0xB2B13C
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
#define pinstCAAWnd_x                                              0xE0076C
#define pinstCAchievementsWnd_x                                    0xE00768
#define pinstCActionsWnd_x                                         0xE000B4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFFF9C
#define pinstCAdvancedLootWnd_x                                    0xDFFF60
#define pinstCAdventureLeaderboardWnd_x                            0xF73340
#define pinstCAdventureRequestWnd_x                                0xF733F0
#define pinstCAdventureStatsWnd_x                                  0xF734A0
#define pinstCAggroMeterWnd_x                                      0xE00020
#define pinstCAlarmWnd_x                                           0xE007C8
#define pinstCAlertHistoryWnd_x                                    0xDFFFB8
#define pinstCAlertStackWnd_x                                      0xE007D0
#define pinstCAlertWnd_x                                           0xDFFF40
#define pinstCAltStorageWnd_x                                      0xF73800
#define pinstCAudioTriggersWindow_x                                0xCB4B88
#define pinstCAuraWnd_x                                            0xDFFFD8
#define pinstCAvaZoneWnd_x                                         0xE00030
#define pinstCBandolierWnd_x                                       0xE00018
#define pinstCBankWnd_x                                            0xDFFFD4
#define pinstCBarterMerchantWnd_x                                  0xF74A40
#define pinstCBarterSearchWnd_x                                    0xF74AF0
#define pinstCBarterWnd_x                                          0xF74BA0
#define pinstCBazaarConfirmationWnd_x                              0xE00794
#define pinstCBazaarSearchWnd_x                                    0xE0006C
#define pinstCBazaarWnd_x                                          0xE007B0
#define pinstCBlockedBuffWnd_x                                     0xDFFFDC
#define pinstCBlockedPetBuffWnd_x                                  0xE00014
#define pinstCBodyTintWnd_x                                        0xE002C8
#define pinstCBookWnd_x                                            0xE00044
#define pinstCBreathWnd_x                                          0xE00784
#define pinstCBuffWindowNORMAL_x                                   0xDFFFBC
#define pinstCBuffWindowSHORT_x                                    0xDFFFC0
#define pinstCBugReportWnd_x                                       0xDFFFC8
#define pinstCButtonWnd_x                                          0x15F8310
#define pinstCCastingWnd_x                                         0xE00038
#define pinstCCastSpellWnd_x                                       0xE00780
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE007B4
#define pinstCChatWindowManager_x                                  0xF75660
#define pinstCClaimWnd_x                                           0xF757B8
#define pinstCColorPickerWnd_x                                     0xE002C0
#define pinstCCombatAbilityWnd_x                                   0xE007C0
#define pinstCCombatSkillsSelectWnd_x                              0xDFFF48
#define pinstCCompassWnd_x                                         0xE000BC
#define pinstCConfirmationDialog_x                                 0xF7A6B8
#define pinstCContainerMgr_x                                       0xE007A8
#define pinstCContextMenuManager_x                                 0x15F8060
#define pinstCCursorAttachment_x                                   0xE00028
#define pinstCDynamicZoneWnd_x                                     0xF75D80
#define pinstCEditLabelWnd_x                                       0xDFFFB4
#define pinstCEQMainWnd_x                                          0xF75FC8
#define pinstCEventCalendarWnd_x                                   0xE0002C
#define pinstCExtendedTargetWnd_x                                  0xE00008
#define pinstCFacePick_x                                           0xDFFF58
#define pinstCFactionWnd_x                                         0xE007A4
#define pinstCFellowshipWnd_x                                      0xF761C8
#define pinstCFileSelectionWnd_x                                   0xE00034
#define pinstCFindItemWnd_x                                        0xE00790
#define pinstCFindLocationWnd_x                                    0xF76320
#define pinstCFriendsWnd_x                                         0xDFFF5C
#define pinstCGemsGameWnd_x                                        0xE007A0
#define pinstCGiveWnd_x                                            0xE007CC
#define pinstCGroupSearchFiltersWnd_x                              0xE0003C
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
#define pinstCIconSelectionWnd_x                                   0xE00024
#define pinstCInspectWnd_x                                         0xDFFF90
#define pinstCInventoryWnd_x                                       0xDFFF68
#define pinstCInvSlotMgr_x                                         0xE00764
#define pinstCItemDisplayManager_x                                 0xF790C0
#define pinstCItemExpTransferWnd_x                                 0xF791F0
#define pinstCItemOverflowWnd_x                                    0xE00070
#define pinstCJournalCatWnd_x                                      0xE00048
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE0000C
#define pinstCKeyRingWnd_x                                         0xDFFFB0
#define pinstCLargeDialogWnd_x                                     0xF7B338
#define pinstCLayoutCopyWnd_x                                      0xF79540
#define pinstCLFGuildWnd_x                                         0xF795F0
#define pinstCLoadskinWnd_x                                        0xE007AC
#define pinstCLootFiltersCopyWnd_x                                 0xCD1180
#define pinstCLootFiltersWnd_x                                     0xE007D4
#define pinstCLootSettingsWnd_x                                    0xDFFF54
#define pinstCLootWnd_x                                            0xE0004C
#define pinstCMailAddressBookWnd_x                                 0xE00774
#define pinstCMailCompositionWnd_x                                 0xE0034C
#define pinstCMailIgnoreListWnd_x                                  0xE00778
#define pinstCMailWnd_x                                            0xE000B0
#define pinstCManageLootWnd_x                                      0xE01638
#define pinstCMapToolbarWnd_x                                      0xDFFF98
#define pinstCMapViewWnd_x                                         0xDFFF74
#define pinstCMarketplaceWnd_x                                     0xE007D8
#define pinstCMerchantWnd_x                                        0xE00050
#define pinstCMIZoneSelectWnd_x                                    0xF79E28
#define pinstCMusicPlayerWnd_x                                     0xE00058
#define pinstCNameChangeMercWnd_x                                  0xE0078C
#define pinstCNameChangePetWnd_x                                   0xE00770
#define pinstCNameChangeWnd_x                                      0xE0079C
#define pinstCNoteWnd_x                                            0xDFFF78
#define pinstCObjectPreviewWnd_x                                   0xDFFF4C
#define pinstCOptionsWnd_x                                         0xDFFF80
#define pinstCPetInfoWnd_x                                         0xE00078
#define pinstCPetitionQWnd_x                                       0xE00358
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE002CC
#define pinstCPlayerWnd_x                                          0xE00080
#define pinstCPopupWndManager_x                                    0xF7A6B8
#define pinstCProgressionSelectionWnd_x                            0xF7A768
#define pinstCPurchaseGroupWnd_x                                   0xDFFF84
#define pinstCPurchaseWnd_x                                        0xDFFF6C
#define pinstCPvPLeaderboardWnd_x                                  0xF7A818
#define pinstCPvPStatsWnd_x                                        0xF7A8C8
#define pinstCQuantityWnd_x                                        0xE00010
#define pinstCRaceChangeWnd_x                                      0xE007C4
#define pinstCRaidOptionsWnd_x                                     0xE00040
#define pinstCRaidWnd_x                                            0xE00354
#define pinstCRealEstateItemsWnd_x                                 0xE00760
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE00054
#define pinstCRealEstateManageWnd_x                                0xDFFF8C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFFFAC
#define pinstCRealEstatePlotSearchWnd_x                            0xDFFFCC
#define pinstCRealEstatePurchaseWnd_x                              0xDFFFE8
#define pinstCRespawnWnd_x                                         0xDFFFE4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE0077C
#define pinstCSendMoneyWnd_x                                       0xDFFF44
#define pinstCServerListWnd_x                                      0xE0001C
#define pinstCSkillsSelectWnd_x                                    0xE007B8
#define pinstCSkillsWnd_x                                          0xE00798
#define pinstCSocialEditWnd_x                                      0xDFFFA8
#define pinstCSocialWnd_x                                          0xE00788
#define pinstCSpellBookWnd_x                                       0xE007BC
#define pinstCStoryWnd_x                                           0xE00084
#define pinstCTargetOfTargetWnd_x                                  0xF7C6F0
#define pinstCTargetWnd_x                                          0xDFFFE0
#define pinstCTaskOverlayWnd_x                                     0xDFFF7C
#define pinstCTaskSelectWnd_x                                      0xF7C848
#define pinstCTaskManager_x                                        0xCD1AC0
#define pinstCTaskTemplateSelectWnd_x                              0xF7C8F8
#define pinstCTaskWnd_x                                            0xF7C9A8
#define pinstCTextEntryWnd_x                                       0xDFFFC4
#define pinstCTimeLeftWnd_x                                        0xE000AC
#define pinstCTipWndCONTEXT_x                                      0xF7CBAC
#define pinstCTipWndOFDAY_x                                        0xF7CBA8
#define pinstCTitleWnd_x                                           0xF7CC58
#define pinstCTrackingWnd_x                                        0xDFFF70
#define pinstCTradeskillWnd_x                                      0xF7CDC0
#define pinstCTradeWnd_x                                           0xE002D4
#define pinstCTrainWnd_x                                           0xE002D0
#define pinstCTributeBenefitWnd_x                                  0xF7CFC0
#define pinstCTributeMasterWnd_x                                   0xF7D070
#define pinstCTributeTrophyWnd_x                                   0xF7D120
#define pinstCVideoModesWnd_x                                      0xE000A8
#define pinstCVoiceMacroWnd_x                                      0xF66418
#define pinstCVoteResultsWnd_x                                     0xE00350
#define pinstCVoteWnd_x                                            0xE002C4
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
#define __CastRay_x                                                0x5B0170
#define __CastRay2_x                                               0x5B01C0
#define __ConvertItemTags_x                                        0x5CBD20
#define __CleanItemTags_x                                          0x47D160
#define __DoesFileExist_x                                          0x9047D0
#define __EQGetTime_x                                              0x9011C0
#define __ExecuteCmd_x                                             0x5A8A20
#define __FixHeading_x                                             0x99C290
#define __GameLoop_x                                               0x6BBEB0
#define __get_bearing_x                                            0x5AFCE0
#define __get_melee_range_x                                        0x5B03B0
#define __GetAnimationCache_x                                      0x721270
#define __GetGaugeValueFromEQ_x                                    0x813A70
#define __GetLabelFromEQ_x                                         0x815550
#define __GetXTargetType_x                                         0x99DDB0
#define __HandleMouseWheel_x                                       0x6BCD70
#define __HeadingDiff_x                                            0x99C300
#define __HelpPath_x                                               0xF617BC
#define __LoadFrontEnd_x                                           0x6B91D0
#define __NewUIINI_x                                               0x813740
#define __ProcessGameEvents_x                                      0x610180
#define __ProcessMouseEvent_x                                      0x60F940
#define __SaveColors_x                                             0x552570
#define __STMLToText_x                                             0x93F510
#define __ToggleKeyRingItem_x                                      0x515680
#define CMemoryMappedFile__SetFile_x                               0xA8B400
#define CrashDetected_x                                            0x6BAC70
#define DrawNetStatus_x                                            0x63BDA0
#define Expansion_HoT_x                                            0xEC370C
#define Teleport_Table_Size_x                                      0xEB2740
#define Teleport_Table_x                                           0xEB2BA8
#define Util__FastTime_x                                           0x900D90

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490500
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499400
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4991D0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A90
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492EE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55A210
#define AltAdvManager__IsAbilityReady_x                            0x559140
#define AltAdvManager__GetAAById_x                                 0x559340
#define AltAdvManager__CanTrainAbility_x                           0x5593B0
#define AltAdvManager__CanSeeAbility_x                             0x559710

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA280
#define CharacterZoneClient__HasSkill_x                            0x4D5170
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6890
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE460
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAA60
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9250
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9330
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9410
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3260
#define CharacterZoneClient__BardCastBard_x                        0x4C5DC0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB30
#define CharacterZoneClient__GetEffect_x                           0x4BA9A0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C42B0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4380
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C43D0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4520
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C46F0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B28D0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D77F0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7270

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E2890
#define CBankWnd__WndNotification_x                                0x6E2670

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F01B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61E900
#define CButtonWnd__CButtonWnd_x                                   0x93B8E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7102F0
#define CChatManager__InitContextMenu_x                            0x709440
#define CChatManager__FreeChatWindow_x                             0x70EE30
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8940
#define CChatManager__SetLockedActiveChatWindow_x                  0x70FF70
#define CChatManager__CreateChatWindow_x                           0x70F470

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8A60

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94FFB0
#define CContextMenu__dCContextMenu_x                              0x9501F0
#define CContextMenu__AddMenuItem_x                                0x950200
#define CContextMenu__RemoveMenuItem_x                             0x950510
#define CContextMenu__RemoveAllMenuItems_x                         0x950530
#define CContextMenu__CheckMenuItem_x                              0x9505B0
#define CContextMenu__SetMenuItem_x                                0x950430
#define CContextMenu__AddSeparator_x                               0x950390

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x950B50
#define CContextMenuManager__RemoveMenu_x                          0x950BC0
#define CContextMenuManager__PopupMenu_x                           0x950C80
#define CContextMenuManager__Flush_x                               0x950AF0
#define CContextMenuManager__GetMenu_x                             0x49B4C0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71BA70

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DCE00
#define CChatService__GetFriendName_x                              0x8DCE10

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x710BA0
#define CChatWindow__Clear_x                                       0x711E70
#define CChatWindow__WndNotification_x                             0x712600
#define CChatWindow__AddHistory_x                                  0x711730

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94D400
#define CComboWnd__Draw_x                                          0x94C8E0
#define CComboWnd__GetCurChoice_x                                  0x94D240
#define CComboWnd__GetListRect_x                                   0x94CDA0
#define CComboWnd__GetTextRect_x                                   0x94D470
#define CComboWnd__InsertChoice_x                                  0x94CF30
#define CComboWnd__SetColors_x                                     0x94CF00
#define CComboWnd__SetChoice_x                                     0x94D210
#define CComboWnd__GetItemCount_x                                  0x94D250
#define CComboWnd__GetCurChoiceText_x                              0x94D290
#define CComboWnd__GetChoiceText_x                                 0x94D260
#define CComboWnd__InsertChoiceAtIndex_x                           0x94CFD0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x719450
#define CContainerWnd__vftable_x                                   0xB12484
#define CContainerWnd__SetContainer_x                              0x71A9C0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54CFB0
#define CDisplay__PreZoneMainUI_x                                  0x54CFC0
#define CDisplay__CleanGameUI_x                                    0x552330
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
#define CEditBaseWnd__SetSel_x                                     0x96FE20

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x95350F
#define CEditWnd__GetCharIndexPt_x                                 0x954450
#define CEditWnd__GetDisplayString_x                               0x9542F0
#define CEditWnd__GetHorzOffset_x                                  0x952B50
#define CEditWnd__GetLineForPrintableChar_x                        0x9555F0
#define CEditWnd__GetSelStartPt_x                                  0x954700
#define CEditWnd__GetSTMLSafeText_x                                0x954110
#define CEditWnd__PointFromPrintableChar_x                         0x955220
#define CEditWnd__SelectableCharFromPoint_x                        0x955390
#define CEditWnd__SetEditable_x                                    0x9547D0
#define CEditWnd__SetWindowTextA_x                                 0x953E90

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FDDF0
#define CEverQuest__ClickedPlayer_x                                0x5EFE00
#define CEverQuest__CreateTargetIndicator_x                        0x60D420
#define CEverQuest__DeleteTargetIndicator_x                        0x60D4B0
#define CEverQuest__DoTellWindow_x                                 0x4E8B40
#define CEverQuest__OutputTextToLog_x                              0x4E8DC0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E4E40
#define CEverQuest__dsp_chat_x                                     0x4E9150
#define CEverQuest__trimName_x                                     0x609700
#define CEverQuest__Emote_x                                        0x5FE650
#define CEverQuest__EnterZone_x                                    0x5F85D0
#define CEverQuest__GetBodyTypeDesc_x                              0x602FC0
#define CEverQuest__GetClassDesc_x                                 0x603600
#define CEverQuest__GetClassThreeLetterCode_x                      0x603C00
#define CEverQuest__GetDeityDesc_x                                 0x60BD60
#define CEverQuest__GetLangDesc_x                                  0x603DC0
#define CEverQuest__GetRaceDesc_x                                  0x6035E0
#define CEverQuest__InterpretCmd_x                                 0x60C330
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E9040
#define CEverQuest__LMouseUp_x                                     0x5E73D0
#define CEverQuest__RightClickedOnPlayer_x                         0x5E9920
#define CEverQuest__RMouseUp_x                                     0x5E8350
#define CEverQuest__SetGameState_x                                 0x5E4BD0
#define CEverQuest__UPCNotificationFlush_x                         0x609600
#define CEverQuest__IssuePetCommand_x                              0x6051C0
#define CEverQuest__ReportSuccessfulHit_x                          0x5FFA40

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72B310
#define CGaugeWnd__CalcLinesFillRect_x                             0x72B370
#define CGaugeWnd__Draw_x                                          0x72A9A0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF3B0
#define CGuild__GetGuildName_x                                     0x4AE490
#define CGuild__GetGuildIndex_x                                    0x4AE820

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x746790

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61ECC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x753750
#define CInvSlotMgr__MoveItem_x                                    0x7524B0
#define CInvSlotMgr__SelectSlot_x                                  0x753820

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x750D30
#define CInvSlot__SliderComplete_x                                 0x74EA80
#define CInvSlot__GetItemBase_x                                    0x74E410
#define CInvSlot__UpdateItem_x                                     0x74E580

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7552A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x754440
#define CInvSlotWnd__HandleLButtonUp_x                             0x754E20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80ED80
#define CItemDisplayWnd__UpdateStrings_x                           0x763A10
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75D740
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75DC60
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x764020
#define CItemDisplayWnd__AboutToShow_x                             0x763650
#define CItemDisplayWnd__WndNotification_x                         0x765100
#define CItemDisplayWnd__RequestConvertItem_x                      0x764BC0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7626B0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x763470

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x847670

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x769650

// CLabel 
#define CLabel__Draw_x                                             0x76F040

// CListWnd
#define CListWnd__CListWnd_x                                       0x925BF0
#define CListWnd__dCListWnd_x                                      0x925F10
#define CListWnd__AddColumn_x                                      0x92A3A0
#define CListWnd__AddColumn1_x                                     0x92A3F0
#define CListWnd__AddLine_x                                        0x92A780
#define CListWnd__AddString_x                                      0x92A580
#define CListWnd__CalculateFirstVisibleLine_x                      0x92A160
#define CListWnd__CalculateVSBRange_x                              0x929F40
#define CListWnd__ClearSel_x                                       0x92AF60
#define CListWnd__ClearAllSel_x                                    0x92AFC0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92B9E0
#define CListWnd__Compare_x                                        0x929870
#define CListWnd__Draw_x                                           0x926040
#define CListWnd__DrawColumnSeparators_x                           0x928840
#define CListWnd__DrawHeader_x                                     0x928CB0
#define CListWnd__DrawItem_x                                       0x9291B0
#define CListWnd__DrawLine_x                                       0x9289B0
#define CListWnd__DrawSeparator_x                                  0x9288E0
#define CListWnd__EnableLine_x                                     0x928110
#define CListWnd__EnsureVisible_x                                  0x92B900
#define CListWnd__ExtendSel_x                                      0x92AE90
#define CListWnd__GetColumnTooltip_x                               0x927C50
#define CListWnd__GetColumnMinWidth_x                              0x927CC0
#define CListWnd__GetColumnWidth_x                                 0x927BC0
#define CListWnd__GetCurSel_x                                      0x927550
#define CListWnd__GetItemAtPoint_x                                 0x928390
#define CListWnd__GetItemAtPoint1_x                                0x928400
#define CListWnd__GetItemData_x                                    0x9275D0
#define CListWnd__GetItemHeight_x                                  0x927990
#define CListWnd__GetItemIcon_x                                    0x927760
#define CListWnd__GetItemRect_x                                    0x928200
#define CListWnd__GetItemText_x                                    0x927610
#define CListWnd__GetSelList_x                                     0x92B010
#define CListWnd__GetSeparatorRect_x                               0x928640
#define CListWnd__InsertLine_x                                     0x92AB70
#define CListWnd__RemoveLine_x                                     0x92ACC0
#define CListWnd__SetColors_x                                      0x929F10
#define CListWnd__SetColumnJustification_x                         0x929C40
#define CListWnd__SetColumnWidth_x                                 0x929B60
#define CListWnd__SetCurSel_x                                      0x92ADD0
#define CListWnd__SetItemColor_x                                   0x92B5B0
#define CListWnd__SetItemData_x                                    0x92B570
#define CListWnd__SetItemText_x                                    0x92B180
#define CListWnd__ShiftColumnSeparator_x                           0x929D00
#define CListWnd__Sort_x                                           0x9299F0
#define CListWnd__ToggleSel_x                                      0x92AE00
#define CListWnd__SetColumnsSizable_x                              0x929DB0
#define CListWnd__SetItemWnd_x                                     0x92B430
#define CListWnd__GetItemWnd_x                                     0x9277B0
#define CListWnd__SetItemIcon_x                                    0x92B200
#define CListWnd__CalculateCustomWindowPositions_x                 0x92A260
#define CListWnd__SetVScrollPos_x                                  0x929B40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x784780
#define CMapViewWnd__GetWorldCoordinates_x                         0x782E90
#define CMapViewWnd__HandleLButtonDown_x                           0x77FED0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A4840
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A5120
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A5650
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A85D0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A33A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AE190
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A4450

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AA9F0
#define CPacketScrambler__hton_x                                   0x8AA9E0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x944B30
#define CSidlManager__FindScreenPieceTemplate_x                    0x944F40
#define CSidlManager__FindScreenPieceTemplate1_x                   0x944D30
#define CSidlManager__CreateLabel_x                                0x8061E0
#define CSidlManager__CreateXWndFromTemplate_x                     0x947EA0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x948070
#define CSidlManager__CreateXWnd_x                                 0x806110
#define CSidlManager__CreateHotButtonWnd_x                         0x8066E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x941630
#define CSidlScreenWnd__CalculateVSBRange_x                        0x941530
#define CSidlScreenWnd__ConvertToRes_x                             0x966E00
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x940FC0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x940CB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x940D80
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x940E50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x941AD0
#define CSidlScreenWnd__EnableIniStorage_x                         0x941FA0
#define CSidlScreenWnd__GetSidlPiece_x                             0x941CC0
#define CSidlScreenWnd__Init1_x                                    0x9408B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x941FF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x942B00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93FCC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x942680
#define CSidlScreenWnd__StoreIniVis_x                              0x9429E0
#define CSidlScreenWnd__WndNotification_x                          0x9419E0
#define CSidlScreenWnd__GetChildItem_x                             0x941F20
#define CSidlScreenWnd__HandleLButtonUp_x                          0x931770
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F7F30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x683430
#define CSkillMgr__GetSkillCap_x                                   0x683610
#define CSkillMgr__GetNameToken_x                                  0x682BB0
#define CSkillMgr__IsActivatedSkill_x                              0x682CF0
#define CSkillMgr__IsCombatSkill_x                                 0x682C30

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x951930
#define CSliderWnd__SetValue_x                                     0x9517A0
#define CSliderWnd__SetNumTicks_x                                  0x951800

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80C200

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95A150
#define CStmlWnd__CalculateHSBRange_x                              0x95B270
#define CStmlWnd__CalculateVSBRange_x                              0x95B1F0
#define CStmlWnd__CanBreakAtCharacter_x                            0x95F5B0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x960240
#define CStmlWnd__ForceParseNow_x                                  0x95A740
#define CStmlWnd__GetNextTagPiece_x                                0x95F510
#define CStmlWnd__GetSTMLText_x                                    0x504FD0
#define CStmlWnd__GetVisibleText_x                                 0x95A760
#define CStmlWnd__InitializeWindowVariables_x                      0x960090
#define CStmlWnd__MakeStmlColorTag_x                               0x9597C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x959830
#define CStmlWnd__SetSTMLText_x                                    0x958870
#define CStmlWnd__StripFirstSTMLLines_x                            0x961340
#define CStmlWnd__UpdateHistoryString_x                            0x960450

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9579C0
#define CTabWnd__DrawCurrentPage_x                                 0x9580F0
#define CTabWnd__DrawTab_x                                         0x957E10
#define CTabWnd__GetCurrentPage_x                                  0x9571C0
#define CTabWnd__GetPageInnerRect_x                                0x957400
#define CTabWnd__GetTabInnerRect_x                                 0x957340
#define CTabWnd__GetTabRect_x                                      0x9571F0
#define CTabWnd__InsertPage_x                                      0x957610
#define CTabWnd__SetPage_x                                         0x957480
#define CTabWnd__SetPageRect_x                                     0x957900
#define CTabWnd__UpdatePage_x                                      0x957CD0
#define CTabWnd__GetPageFromTabIndex_x                             0x957D50
#define CTabWnd__GetCurrentTabIndex_x                              0x9571B0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x769A40
#define CPageWnd__SetTabText_x                                     0x956D00

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9060

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92E630
#define CTextureFont__GetTextExtent_x                              0x92E7F0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B6070
#define CHtmlComponentWnd__ValidateUri_x                           0x748180
#define CHtmlWnd__SetClientCallbacks_x                             0x623D50
#define CHtmlWnd__AddObserver_x                                    0x623D70
#define CHtmlWnd__RemoveObserver_x                                 0x623DD0
#define Window__getProgress_x                                      0x85FC00
#define Window__getStatus_x                                        0x85FC20
#define Window__getURI_x                                           0x85FC30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96C8B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91B8B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8680
#define CXStr__CXStr1_x                                            0x5000B0
#define CXStr__CXStr3_x                                            0x8FD300
#define CXStr__dCXStr_x                                            0x478770
#define CXStr__operator_equal_x                                    0x8FD530
#define CXStr__operator_equal1_x                                   0x8FD570
#define CXStr__operator_plus_equal1_x                              0x8FE000
#define CXStr__SetString_x                                         0x8FFEF0
#define CXStr__operator_char_p_x                                   0x8FDA40
#define CXStr__GetChar_x                                           0x8FF840
#define CXStr__Delete_x                                            0x8FF0F0
#define CXStr__GetUnicode_x                                        0x8FF8B0
#define CXStr__GetLength_x                                         0x47D510
#define CXStr__Mid_x                                               0x47D520
#define CXStr__Insert_x                                            0x8FF910
#define CXStr__FindNext_x                                          0x8FF560

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94FBC0
#define CXWnd__BringToTop_x                                        0x934EB0
#define CXWnd__Center_x                                            0x934A30
#define CXWnd__ClrFocus_x                                          0x934850
#define CXWnd__Destroy_x                                           0x9348F0
#define CXWnd__DoAllDrawing_x                                      0x930F20
#define CXWnd__DrawChildren_x                                      0x930EF0
#define CXWnd__DrawColoredRect_x                                   0x931380
#define CXWnd__DrawTooltip_x                                       0x92FA30
#define CXWnd__DrawTooltipAtPoint_x                                0x92FAF0
#define CXWnd__GetBorderFrame_x                                    0x9311E0
#define CXWnd__GetChildWndAt_x                                     0x934F50
#define CXWnd__GetClientClipRect_x                                 0x9331B0
#define CXWnd__GetScreenClipRect_x                                 0x933280
#define CXWnd__GetScreenRect_x                                     0x933450
#define CXWnd__GetTooltipRect_x                                    0x9313D0
#define CXWnd__GetWindowTextA_x                                    0x49CBC0
#define CXWnd__IsActive_x                                          0x931AE0
#define CXWnd__IsDescendantOf_x                                    0x933E30
#define CXWnd__IsReallyVisible_x                                   0x933E60
#define CXWnd__IsType_x                                            0x9355C0
#define CXWnd__Move_x                                              0x933ED0
#define CXWnd__Move1_x                                             0x933F80
#define CXWnd__ProcessTransition_x                                 0x9349E0
#define CXWnd__Refade_x                                            0x934230
#define CXWnd__Resize_x                                            0x9344D0
#define CXWnd__Right_x                                             0x934C70
#define CXWnd__SetFocus_x                                          0x934810
#define CXWnd__SetFont_x                                           0x934880
#define CXWnd__SetKeyTooltip_x                                     0x9353E0
#define CXWnd__SetMouseOver_x                                      0x932310
#define CXWnd__StartFade_x                                         0x933D10
#define CXWnd__GetChildItem_x                                      0x9350C0
#define CXWnd__SetParent_x                                         0x933BC0
#define CXWnd__Minimize_x                                          0x934530

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x967E80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x937D80
#define CXWndManager__DrawWindows_x                                0x937DA0
#define CXWndManager__GetKeyboardFlags_x                           0x93A550
#define CXWndManager__HandleKeyboardMsg_x                          0x93A100
#define CXWndManager__RemoveWnd_x                                  0x93A780
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93AD00

// CDBStr
#define CDBStr__GetString_x                                        0x53C920

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBA40
#define EQ_Character__Cur_HP_x                                     0x4D21B0
#define EQ_Character__Cur_Mana_x                                   0x4D9910
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEAB0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2510
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2660
#define EQ_Character__GetHPRegen_x                                 0x4DF6E0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFCE0
#define EQ_Character__GetManaRegen_x                               0x4E0120
#define EQ_Character__Max_Endurance_x                              0x649F00
#define EQ_Character__Max_HP_x                                     0x4D1FE0
#define EQ_Character__Max_Mana_x                                   0x649D00
#define EQ_Character__doCombatAbility_x                            0x64C360
#define EQ_Character__UseSkill_x                                   0x4E1F00
#define EQ_Character__GetConLevel_x                                0x642DA0
#define EQ_Character__IsExpansionFlag_x                            0x5A7200
#define EQ_Character__TotalEffect_x                                0x4C5500
#define EQ_Character__GetPCSpellAffect_x                           0x4BF800
#define EQ_Character__SpellDuration_x                              0x4BF330
#define EQ_Character__GetAdjustedSkill_x                           0x4D4F30
#define EQ_Character__GetBaseSkill_x                               0x4D5ED0
#define EQ_Character__CanUseItem_x                                 0x4D9C20

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C9D20

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x660480

//PcClient
#define PcClient__PcClient_x                                       0x6404D0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B96B0
#define CCharacterListWnd__EnterWorld_x                            0x4B90F0
#define CCharacterListWnd__Quit_x                                  0x4B8E40
#define CCharacterListWnd__UpdateList_x                            0x4B9280

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x624FA0
#define EQ_Item__CreateItemTagString_x                             0x8A4210
#define EQ_Item__IsStackable_x                                     0x8A8DB0
#define EQ_Item__GetImageNum_x                                     0x8A5CC0
#define EQ_Item__CreateItemClient_x                                0x624170
#define EQ_Item__GetItemValue_x                                    0x8A6FC0
#define EQ_Item__ValueSellMerchant_x                               0x8AA5D0
#define EQ_Item__IsKeyRingItem_x                                   0x8A86B0
#define EQ_Item__CanGoInBag_x                                      0x6250C0
#define EQ_Item__IsEmpty_x                                         0x8A8210
#define EQ_Item__GetMaxItemCount_x                                 0x8A73E0
#define EQ_Item__GetHeldItem_x                                     0x8A5B90
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A3B80

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55AEE0
#define EQ_LoadingS__Array_x                                       0xC26B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64A860
#define EQ_PC__GetAlternateAbilityId_x                             0x8B37D0
#define EQ_PC__GetCombatAbility_x                                  0x8B3E40
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B3EB0
#define EQ_PC__GetItemRecastTimer_x                                0x64C8E0
#define EQ_PC__HasLoreItem_x                                       0x6435B0
#define EQ_PC__AlertInventoryChanged_x                             0x6426D0
#define EQ_PC__GetPcZoneClient_x                                   0x66EF50
#define EQ_PC__RemoveMyAffect_x                                    0x64FB20
#define EQ_PC__GetKeyRingItems_x                                   0x8B4740
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B44D0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B4A40

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AD750
#define EQItemList__add_object_x                                   0x5DA620
#define EQItemList__add_item_x                                     0x5ADCB0
#define EQItemList__delete_item_x                                  0x5ADD00
#define EQItemList__FreeItemList_x                                 0x5ADC00

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5393D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x661D00
#define EQPlayer__dEQPlayer_x                                      0x655040
#define EQPlayer__DoAttack_x                                       0x669BE0
#define EQPlayer__EQPlayer_x                                       0x655700
#define EQPlayer__SetNameSpriteState_x                             0x6599E0
#define EQPlayer__SetNameSpriteTint_x                              0x65A8B0
#define PlayerBase__HasProperty_j_x                                0x99A680
#define EQPlayer__IsTargetable_x                                   0x99AB20
#define EQPlayer__CanSee_x                                         0x99A980
#define EQPlayer__CanSee1_x                                        0x99AA50
#define PlayerBase__GetVisibilityLineSegment_x                     0x99A740

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66C9E0
#define PlayerZoneClient__GetLevel_x                               0x66EF90
#define PlayerZoneClient__IsValidTeleport_x                        0x5DB790
#define PlayerZoneClient__LegalPlayerRace_x                        0x554190

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x664AF0
#define EQPlayerManager__GetSpawnByName_x                          0x664BA0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x664C30

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6285C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x628640
#define KeypressHandler__AttachKeyToEqCommand_x                    0x628680
#define KeypressHandler__ClearCommandStateArray_x                  0x629A90
#define KeypressHandler__HandleKeyDown_x                           0x629AB0
#define KeypressHandler__HandleKeyUp_x                             0x629B50
#define KeypressHandler__SaveKeymapping_x                          0x629FA0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7805F0
#define MapViewMap__SaveEx_x                                       0x7839B0
#define MapViewMap__SetZoom_x                                      0x788070

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C7C10

// StringTable 
#define StringTable__getString_x                                   0x8C2A20

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64F790
#define PcZoneClient__RemovePetEffect_x                            0x64FDC0
#define PcZoneClient__HasAlternateAbility_x                        0x649B30
#define PcZoneClient__GetCurrentMod_x                              0x4E4FC0
#define PcZoneClient__GetModCap_x                                  0x4E4EC0
#define PcZoneClient__CanEquipItem_x                               0x64A200
#define PcZoneClient__GetItemByID_x                                0x64CD60
#define PcZoneClient__GetItemByItemClass_x                         0x64CEB0
#define PcZoneClient__RemoveBuffEffect_x                           0x64FDE0
#define PcZoneClient__BandolierSwap_x                              0x64AE20
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64C880

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E0310

//IconCache
#define IconCache__GetIcon_x                                       0x720B10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7185F0
#define CContainerMgr__CloseContainer_x                            0x7188C0
#define CContainerMgr__OpenExperimentContainer_x                   0x719340

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D86B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61D0B0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x776B10
#define CLootWnd__RequestLootSlot_x                                0x775D40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57AD30
#define EQ_Spell__SpellAffects_x                                   0x57B1A0
#define EQ_Spell__SpellAffectBase_x                                0x57AF60
#define EQ_Spell__IsStackable_x                                    0x4C9BC0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9A70
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6A00
#define EQ_Spell__IsSPAStacking_x                                  0x57BFF0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57B500
#define EQ_Spell__IsNoRemove_x                                     0x4C9BA0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57C000
#define __IsResEffectSpell_x                                       0x4C8F20

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD110

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D2280

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81F4D0
#define CTargetWnd__WndNotification_x                              0x81ED60
#define CTargetWnd__RefreshTargetBuffs_x                           0x81F030
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81DED0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x823AE0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536E00
#define CTaskManager__HandleMessage_x                              0x5352B0
#define CTaskManager__GetTaskStatus_x                              0x536EB0
#define CTaskManager__GetElementDescription_x                      0x536F30

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x576280
#define EqSoundManager__PlayScriptMp3_x                            0x5763E0
#define EqSoundManager__SoundAssistPlay_x                          0x687400
#define EqSoundManager__WaveInstancePlay_x                         0x686970

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52ABB0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x956210

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5628D0
#define CAltAbilityData__GetMercMaxRank_x                          0x562860
#define CAltAbilityData__GetMaxRank_x                              0x557FC0

//CTargetRing
#define CTargetRing__Cast_x                                        0x61B1D0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9A50
#define CharacterBase__CreateItemGlobalIndex_x                     0x511D00
#define CharacterBase__CreateItemIndex_x                           0x623300
#define CharacterBase__GetItemPossession_x                         0x4FD9E0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DA890
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DA8F0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FF6A0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FFED0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FFF80

//messages
#define msg_spell_worn_off_x                                       0x59F3A0
#define msg_new_text_x                                             0x594120
#define __msgTokenTextParam_x                                      0x5A18D0
#define msgTokenText_x                                             0x5A1B20

//SpellManager
#define SpellManager__vftable_x                                    0xAEC4CC
#define SpellManager__SpellManager_x                               0x68A730
#define Spellmanager__LoadTextSpells_x                             0x68B020
#define SpellManager__GetSpellByGroupAndRank_x                     0x68A900

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99E6A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x512350
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A5680
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63BC00
#define ItemGlobalIndex__IsValidIndex_x                            0x5123B0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D2C20
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D2EA0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76F380

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71CD10
#define CCursorAttachment__AttachToCursor1_x                       0x71CD50
#define CCursorAttachment__Deactivate_x                            0x71DD40

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x948ED0
#define CSidlManagerBase__CreatePageWnd_x                          0x9486C0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x944950
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9448E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9660E0
#define CEQSuiteTextureLoader__GetTexture_x                        0x965DA0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F2A0
#define CFindItemWnd__WndNotification_x                            0x50FD80
#define CFindItemWnd__Update_x                                     0x5108F0
#define CFindItemWnd__PickupSelectedItem_x                         0x50EAE0

//IString
#define IString__Append_x                                          0x4F06B0

//Camera
#define CDisplay__cameraType_x                                     0xE000B8
#define EverQuest__Cameras_x                                       0xEC3A5C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517A20
#define LootFiltersManager__GetItemFilterData_x                    0x517320
#define LootFiltersManager__RemoveItemLootFilter_x                 0x517350
#define LootFiltersManager__SetItemLootFilter_x                    0x517570

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C6670

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A4170
#define CResolutionHandler__GetWindowedStyle_x                     0x681DA0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x715310

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E7840
#define CDistillerInfo__Instance_x                                 0x8E77E0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x735550
#define CGroupWnd__UpdateDisplay_x                                 0x7348A0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A8760
#define ItemBase__IsLoreEquipped_x                                 0x8A87E0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DA580
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DA6C0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DA720

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6776F0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67B050

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x5055D0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F21E0
#define FactionManagerClient__HandleFactionMessage_x               0x4F2850
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2E10
#define FactionManagerClient__GetMaxFaction_x                      0x4F2E2F
#define FactionManagerClient__GetMinFaction_x                      0x4F2DE0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD9B0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92D680

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BEA0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FDC70

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x561D90

//CTargetManager
#define CTargetManager__Get_x                                      0x68DF80

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6776F0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E20

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5ADBA0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF610F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
