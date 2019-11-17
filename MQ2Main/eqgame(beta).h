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
#define __ExpectedVersionDate                                     "Nov 17 2019"
#define __ExpectedVersionTime                                     "04:43:05"
#define __ActualVersionDate_x                                      0xB0A2AC
#define __ActualVersionTime_x                                      0xB0A2A0
#define __ActualVersionBuild_x                                     0xAF5F5C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62DA80
#define __MemChecker1_x                                            0x9012B0
#define __MemChecker2_x                                            0x6BCC20
#define __MemChecker3_x                                            0x6BCB70
#define __MemChecker4_x                                            0x8587E0
#define __EncryptPad0_x                                            0xC403E8
#define __EncryptPad1_x                                            0xC9E5A8
#define __EncryptPad2_x                                            0xC50C80
#define __EncryptPad3_x                                            0xC50880
#define __EncryptPad4_x                                            0xC8EC00
#define __EncryptPad5_x                                            0xF6A1A0
#define __AC1_x                                                    0x815186
#define __AC2_x                                                    0x5E7A2F
#define __AC3_x                                                    0x5EF12F
#define __AC4_x                                                    0x5F3100
#define __AC5_x                                                    0x5F940F
#define __AC6_x                                                    0x5FDA26
#define __AC7_x                                                    0x5E74A0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x193A6C

// Direct Input
#define DI8__Main_x                                                0xF6A1C8
#define DI8__Keyboard_x                                            0xF6A1CC
#define DI8__Mouse_x                                               0xF6A1AC
#define DI8__Mouse_Copy_x                                          0xEC33AC
#define DI8__Mouse_Check_x                                         0xF67CF4
#define __AutoSkillArray_x                                         0xEC42C4
#define __Attack_x                                                 0xF620EB
#define __Autofire_x                                               0xF620EC
#define __BindList_x                                               0xC2EE20
#define g_eqCommandStates_x                                        0xC2FBA0
#define __Clicks_x                                                 0xEC3464
#define __CommandList_x                                            0xC30760
#define __CurrentMapLabel_x                                        0xF7AB6C
#define __CurrentSocial_x                                          0xC187CC
#define __DoAbilityList_x                                          0xEF9C0C
#define __do_loot_x                                                0x5B3E20
#define __DrawHandler_x                                            0x15F9EE0
#define __GroupCount_x                                             0xEB5D62
#define __Guilds_x                                                 0xEB9BB8
#define __gWorld_x                                                 0xEB5BB0
#define __HWnd_x                                                   0xF6A1B0
#define __heqmain_x                                                0xF6A188
#define __InChatMode_x                                             0xEC3394
#define __LastTell_x                                               0xEC5308
#define __LMouseHeldTime_x                                         0xEC34D0
#define __Mouse_x                                                  0xF6A1B4
#define __MouseLook_x                                              0xEC342A
#define __MouseEventTime_x                                         0xF62BCC
#define __gpbCommandEvent_x                                        0xEB3650
#define __NetStatusToggle_x                                        0xEC342D
#define __PCNames_x                                                0xEC48B4
#define __RangeAttackReady_x                                       0xEC45A8
#define __RMouseHeldTime_x                                         0xEC34CC
#define __RunWalkState_x                                           0xEC3398
#define __ScreenMode_x                                             0xE01004
#define __ScreenX_x                                                0xEC334C
#define __ScreenY_x                                                0xEC3348
#define __ScreenXMax_x                                             0xEC3350
#define __ScreenYMax_x                                             0xEC3354
#define __ServerHost_x                                             0xEB3883
#define __ServerName_x                                             0xEF9BCC
#define __ShiftKeyDown_x                                           0xEC3A24
#define __ShowNames_x                                              0xEC4764
#define __Socials_x                                                0xEF9CCC
#define __SubscriptionType_x                                       0xFBF070
#define __TargetAggroHolder_x                                      0xF7D520
#define __ZoneType_x                                               0xEC3828
#define __GroupAggro_x                                             0xF7D560
#define __LoginName_x                                              0xF6A91C
#define __Inviter_x                                                0xF62068
#define __AttackOnAssist_x                                         0xEC4720
#define __UseTellWindows_x                                         0xEC4A50
#define __gfMaxZoomCameraDistance_x                                0xAFFBD0
#define __gfMaxCameraDistance_x                                    0xB2C11C
#define __pulAutoRun_x                                             0xEC3448
#define __pulForward_x                                             0xEC4A88
#define __pulBackward_x                                            0xEC4A8C
#define __pulTurnRight_x                                           0xEC4A90
#define __pulTurnLeft_x                                            0xEC4A94
#define __pulStrafeLeft_x                                          0xEC4A98
#define __pulStrafeRight_x                                         0xEC4A9C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB5F58
#define instEQZoneInfo_x                                           0xEC3620
#define pinstActiveBanker_x                                        0xEB3668
#define pinstActiveCorpse_x                                        0xEB3660
#define pinstActiveGMaster_x                                       0xEB3664
#define pinstActiveMerchant_x                                      0xEB365C
#define pinstAltAdvManager_x                                       0xE02188
#define pinstBandageTarget_x                                       0xEB3678
#define pinstCamActor_x                                            0xE00FF8
#define pinstCDBStr_x                                              0xE00EA4
#define pinstCDisplay_x                                            0xEB5BAC
#define pinstCEverQuest_x                                          0xF6A1E0
#define pinstEverQuestInfo_x                                       0xEC3340
#define pinstCharData_x                                            0xEB5D44
#define pinstCharSpawn_x                                           0xEB3730
#define pinstControlledMissile_x                                   0xEB3B9C
#define pinstControlledPlayer_x                                    0xEB3730
#define pinstCResolutionHandler_x                                  0x15FA110
#define pinstCSidlManager_x                                        0x15F90A8
#define pinstCXWndManager_x                                        0x15F90A4
#define instDynamicZone_x                                          0xEB9A90
#define pinstDZMember_x                                            0xEB9BA0
#define pinstDZTimerInfo_x                                         0xEB9BA4
#define pinstEqLogin_x                                             0xF6A268
#define instEQMisc_x                                               0xE00DE8
#define pinstEQSoundManager_x                                      0xE03158
#define pinstEQSpellStrings_x                                      0xCC3858
#define instExpeditionLeader_x                                     0xEB9ADA
#define instExpeditionName_x                                       0xEB9B1A
#define pinstGroup_x                                               0xEB5D5E
#define pinstImeManager_x                                          0x15F90A0
#define pinstLocalPlayer_x                                         0xEB3658
#define pinstMercenaryData_x                                       0xF646BC
#define pinstMercenaryStats_x                                      0xF7D66C
#define pinstModelPlayer_x                                         0xEB3670
#define pinstPCData_x                                              0xEB5D44
#define pinstSkillMgr_x                                            0xF66828
#define pinstSpawnManager_x                                        0xF652D0
#define pinstSpellManager_x                                        0xF66A48
#define pinstSpellSets_x                                           0xF5AD14
#define pinstStringTable_x                                         0xEB5D48
#define pinstSwitchManager_x                                       0xEB34F8
#define pinstTarget_x                                              0xEB36AC
#define pinstTargetObject_x                                        0xEB3738
#define pinstTargetSwitch_x                                        0xEB3BA4
#define pinstTaskMember_x                                          0xE00C78
#define pinstTrackTarget_x                                         0xEB3734
#define pinstTradeTarget_x                                         0xEB366C
#define instTributeActive_x                                        0xE00E09
#define pinstViewActor_x                                           0xE00FF4
#define pinstWorldData_x                                           0xEB3B98
#define pinstZoneAddr_x                                            0xEC38C0
#define pinstPlayerPath_x                                          0xF65368
#define pinstTargetIndicator_x                                     0xF66CB0
#define EQObject_Top_x                                             0xEB3654
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE0176C
#define pinstCAchievementsWnd_x                                    0xE01768
#define pinstCActionsWnd_x                                         0xE0152C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE00F9C
#define pinstCAdvancedLootWnd_x                                    0xE00F60
#define pinstCAdventureLeaderboardWnd_x                            0xF74340
#define pinstCAdventureRequestWnd_x                                0xF743F0
#define pinstCAdventureStatsWnd_x                                  0xF744A0
#define pinstCAggroMeterWnd_x                                      0xE0104C
#define pinstCAlarmWnd_x                                           0xE017C8
#define pinstCAlertHistoryWnd_x                                    0xE00FBC
#define pinstCAlertStackWnd_x                                      0xE017D0
#define pinstCAlertWnd_x                                           0xE00F40
#define pinstCAltStorageWnd_x                                      0xF74800
#define pinstCAudioTriggersWindow_x                                0xCB5B88
#define pinstCAuraWnd_x                                            0xE00FDC
#define pinstCAvaZoneWnd_x                                         0xE00FA0
#define pinstCBandolierWnd_x                                       0xE01034
#define pinstCBankWnd_x                                            0xE00FD8
#define pinstCBarterMerchantWnd_x                                  0xF75A40
#define pinstCBarterSearchWnd_x                                    0xF75AF0
#define pinstCBarterWnd_x                                          0xF75BA0
#define pinstCBazaarConfirmationWnd_x                              0xE01794
#define pinstCBazaarSearchWnd_x                                    0xE01508
#define pinstCBazaarWnd_x                                          0xE017B0
#define pinstCBlockedBuffWnd_x                                     0xE00FE0
#define pinstCBlockedPetBuffWnd_x                                  0xE01020
#define pinstCBodyTintWnd_x                                        0xE01740
#define pinstCBookWnd_x                                            0xE0106C
#define pinstCBreathWnd_x                                          0xE01784
#define pinstCBuffWindowNORMAL_x                                   0xE00FC0
#define pinstCBuffWindowSHORT_x                                    0xE00FC4
#define pinstCBugReportWnd_x                                       0xE00FCC
#define pinstCButtonWnd_x                                          0x15F9310
#define pinstCCastingWnd_x                                         0xE01060
#define pinstCCastSpellWnd_x                                       0xE01780
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE017B4
#define pinstCChatWindowManager_x                                  0xF76660
#define pinstCClaimWnd_x                                           0xF767B8
#define pinstCColorPickerWnd_x                                     0xE01738
#define pinstCCombatAbilityWnd_x                                   0xE017C0
#define pinstCCombatSkillsSelectWnd_x                              0xE00F48
#define pinstCCompassWnd_x                                         0xE01534
#define pinstCConfirmationDialog_x                                 0xF7B6B8
#define pinstCContainerMgr_x                                       0xE017A8
#define pinstCContextMenuManager_x                                 0x15F9060
#define pinstCCursorAttachment_x                                   0xE01054
#define pinstCDynamicZoneWnd_x                                     0xF76D80
#define pinstCEditLabelWnd_x                                       0xE00FB8
#define pinstCEQMainWnd_x                                          0xF76FC8
#define pinstCEventCalendarWnd_x                                   0xE01058
#define pinstCExtendedTargetWnd_x                                  0xE01014
#define pinstCFacePick_x                                           0xE00F58
#define pinstCFactionWnd_x                                         0xE017A4
#define pinstCFellowshipWnd_x                                      0xF771C8
#define pinstCFileSelectionWnd_x                                   0xE0105C
#define pinstCFindItemWnd_x                                        0xE01790
#define pinstCFindLocationWnd_x                                    0xF77320
#define pinstCFriendsWnd_x                                         0xE00F5C
#define pinstCGemsGameWnd_x                                        0xE017A0
#define pinstCGiveWnd_x                                            0xE017CC
#define pinstCGroupSearchFiltersWnd_x                              0xE01064
#define pinstCGroupSearchWnd_x                                     0xF77718
#define pinstCGroupWnd_x                                           0xF777C8
#define pinstCGuildBankWnd_x                                       0xEC4704
#define pinstCGuildCreationWnd_x                                   0xF77928
#define pinstCGuildMgmtWnd_x                                       0xF779D8
#define pinstCharacterCreation_x                                   0xE00F50
#define pinstCHelpWnd_x                                            0xE00F94
#define pinstCHeritageSelectionWnd_x                               0xE00F64
#define pinstCHotButtonWnd_x                                       0xF79B30
#define pinstCHotButtonWnd1_x                                      0xF79B30
#define pinstCHotButtonWnd2_x                                      0xF79B34
#define pinstCHotButtonWnd3_x                                      0xF79B38
#define pinstCHotButtonWnd4_x                                      0xF79B3C
#define pinstCIconSelectionWnd_x                                   0xE01050
#define pinstCInspectWnd_x                                         0xE00F90
#define pinstCInventoryWnd_x                                       0xE00F68
#define pinstCInvSlotMgr_x                                         0xE01764
#define pinstCItemDisplayManager_x                                 0xF7A0C0
#define pinstCItemExpTransferWnd_x                                 0xF7A1F0
#define pinstCItemOverflowWnd_x                                    0xE0150C
#define pinstCJournalCatWnd_x                                      0xE010E4
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE01018
#define pinstCKeyRingWnd_x                                         0xE00FB4
#define pinstCLargeDialogWnd_x                                     0xF7C338
#define pinstCLayoutCopyWnd_x                                      0xF7A540
#define pinstCLFGuildWnd_x                                         0xF7A5F0
#define pinstCLoadskinWnd_x                                        0xE017AC
#define pinstCLootFiltersCopyWnd_x                                 0xCD2180
#define pinstCLootFiltersWnd_x                                     0xE017D4
#define pinstCLootSettingsWnd_x                                    0xE00F54
#define pinstCLootWnd_x                                            0xE014EC
#define pinstCMailAddressBookWnd_x                                 0xE01774
#define pinstCMailCompositionWnd_x                                 0xE01750
#define pinstCMailIgnoreListWnd_x                                  0xE01778
#define pinstCMailWnd_x                                            0xE01528
#define pinstCManageLootWnd_x                                      0xE02638
#define pinstCMapToolbarWnd_x                                      0xE00F98
#define pinstCMapViewWnd_x                                         0xE00F74
#define pinstCMarketplaceWnd_x                                     0xE017D8
#define pinstCMerchantWnd_x                                        0xE014F0
#define pinstCMIZoneSelectWnd_x                                    0xF7AE28
#define pinstCMusicPlayerWnd_x                                     0xE014F8
#define pinstCNameChangeMercWnd_x                                  0xE0178C
#define pinstCNameChangePetWnd_x                                   0xE01770
#define pinstCNameChangeWnd_x                                      0xE0179C
#define pinstCNoteWnd_x                                            0xE00F78
#define pinstCObjectPreviewWnd_x                                   0xE00F4C
#define pinstCOptionsWnd_x                                         0xE00F80
#define pinstCPetInfoWnd_x                                         0xE01510
#define pinstCPetitionQWnd_x                                       0xE0175C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE01744
#define pinstCPlayerWnd_x                                          0xE01518
#define pinstCPopupWndManager_x                                    0xF7B6B8
#define pinstCProgressionSelectionWnd_x                            0xF7B768
#define pinstCPurchaseGroupWnd_x                                   0xE00F84
#define pinstCPurchaseWnd_x                                        0xE00F6C
#define pinstCPvPLeaderboardWnd_x                                  0xF7B818
#define pinstCPvPStatsWnd_x                                        0xF7B8C8
#define pinstCQuantityWnd_x                                        0xE0101C
#define pinstCRaceChangeWnd_x                                      0xE017C4
#define pinstCRaidOptionsWnd_x                                     0xE01068
#define pinstCRaidWnd_x                                            0xE01758
#define pinstCRealEstateItemsWnd_x                                 0xE01760
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE014F4
#define pinstCRealEstateManageWnd_x                                0xE00F8C
#define pinstCRealEstateNeighborhoodWnd_x                          0xE00FB0
#define pinstCRealEstatePlotSearchWnd_x                            0xE00FD0
#define pinstCRealEstatePurchaseWnd_x                              0xE00FF0
#define pinstCRespawnWnd_x                                         0xE00FEC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE0177C
#define pinstCSendMoneyWnd_x                                       0xE00F44
#define pinstCServerListWnd_x                                      0xE01048
#define pinstCSkillsSelectWnd_x                                    0xE017B8
#define pinstCSkillsWnd_x                                          0xE01798
#define pinstCSocialEditWnd_x                                      0xE00FAC
#define pinstCSocialWnd_x                                          0xE01788
#define pinstCSpellBookWnd_x                                       0xE017BC
#define pinstCStoryWnd_x                                           0xE0151C
#define pinstCTargetOfTargetWnd_x                                  0xF7D6F0
#define pinstCTargetWnd_x                                          0xE00FE8
#define pinstCTaskOverlayWnd_x                                     0xE00F7C
#define pinstCTaskSelectWnd_x                                      0xF7D848
#define pinstCTaskManager_x                                        0xCD2AC0
#define pinstCTaskTemplateSelectWnd_x                              0xF7D8F8
#define pinstCTaskWnd_x                                            0xF7D9A8
#define pinstCTextEntryWnd_x                                       0xE00FC8
#define pinstCTimeLeftWnd_x                                        0xE01524
#define pinstCTipWndCONTEXT_x                                      0xF7DBAC
#define pinstCTipWndOFDAY_x                                        0xF7DBA8
#define pinstCTitleWnd_x                                           0xF7DC58
#define pinstCTrackingWnd_x                                        0xE00F70
#define pinstCTradeskillWnd_x                                      0xF7DDC0
#define pinstCTradeWnd_x                                           0xE0174C
#define pinstCTrainWnd_x                                           0xE01748
#define pinstCTributeBenefitWnd_x                                  0xF7DFC0
#define pinstCTributeMasterWnd_x                                   0xF7E070
#define pinstCTributeTrophyWnd_x                                   0xF7E120
#define pinstCVideoModesWnd_x                                      0xE01520
#define pinstCVoiceMacroWnd_x                                      0xF67418
#define pinstCVoteResultsWnd_x                                     0xE01754
#define pinstCVoteWnd_x                                            0xE0173C
#define pinstCWebManager_x                                         0xF67A94
#define pinstCZoneGuideWnd_x                                       0xE00F88
#define pinstCZonePathWnd_x                                        0xE00FA4

#define pinstEQSuiteTextureLoader_x                                0xCA0080
#define pinstItemIconCache_x                                       0xF76F80
#define pinstLootFiltersManager_x                                  0xCD2230
#define pinstRewardSelectionWnd_x                                  0xF7C010

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AF280
#define __CastRay2_x                                               0x5AF2D0
#define __ConvertItemTags_x                                        0x5CAE10
#define __CleanItemTags_x                                          0x47D000
#define __DoesFileExist_x                                          0x904340
#define __EQGetTime_x                                              0x900D80
#define __ExecuteCmd_x                                             0x5A7B90
#define __FixHeading_x                                             0x99CC90
#define __GameLoop_x                                               0x6BBE10
#define __get_bearing_x                                            0x5AEDF0
#define __get_melee_range_x                                        0x5AF4C0
#define __GetAnimationCache_x                                      0x721030
#define __GetGaugeValueFromEQ_x                                    0x813630
#define __GetLabelFromEQ_x                                         0x815110
#define __GetXTargetType_x                                         0x99E670
#define __HandleMouseWheel_x                                       0x6BCCD0
#define __HeadingDiff_x                                            0x99CD00
#define __HelpPath_x                                               0xF627BC
#define __LoadFrontEnd_x                                           0x6B9130
#define __NewUIINI_x                                               0x813300
#define __ProcessGameEvents_x                                      0x60F280
#define __ProcessMouseEvent_x                                      0x60EA40
#define __SaveColors_x                                             0x551530
#define __STMLToText_x                                             0x9401A0
#define __ToggleKeyRingItem_x                                      0x514D50
#define CMemoryMappedFile__SetFile_x                               0xA8BFC0
#define CrashDetected_x                                            0x6BABD0
#define DrawNetStatus_x                                            0x63AF60
#define Expansion_HoT_x                                            0xEC470C
#define Teleport_Table_Size_x                                      0xEB3740
#define Teleport_Table_x                                           0xEB3BA8
#define Util__FastTime_x                                           0x900950

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490200
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499100
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498ED0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493790
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492BE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5591D0
#define AltAdvManager__IsAbilityReady_x                            0x558100
#define AltAdvManager__GetAAById_x                                 0x558300
#define AltAdvManager__CanTrainAbility_x                           0x558370
#define AltAdvManager__CanSeeAbility_x                             0x5586D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9F70
#define CharacterZoneClient__HasSkill_x                            0x4D4E60
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6580
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE220
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA820
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8F20
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9000
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D90E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3020
#define CharacterZoneClient__BardCastBard_x                        0x4C5B80
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA8F0
#define CharacterZoneClient__GetEffect_x                           0x4BA760
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4070
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4140
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4190
#define CharacterZoneClient__CalcAffectChange_x                    0x4C42E0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C44B0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B26C0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D74E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6F60

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E2790
#define CBankWnd__WndNotification_x                                0x6E2570

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F0050

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61D890
#define CButtonWnd__CButtonWnd_x                                   0x93C560

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x710160
#define CChatManager__InitContextMenu_x                            0x7092C0
#define CChatManager__FreeChatWindow_x                             0x70ECA0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E84E0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70FDE0
#define CChatManager__CreateChatWindow_x                           0x70F2E0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E85F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x950C00
#define CContextMenu__dCContextMenu_x                              0x950E30
#define CContextMenu__AddMenuItem_x                                0x950E40
#define CContextMenu__RemoveMenuItem_x                             0x951150
#define CContextMenu__RemoveAllMenuItems_x                         0x951170
#define CContextMenu__CheckMenuItem_x                              0x9511F0
#define CContextMenu__SetMenuItem_x                                0x951070
#define CContextMenu__AddSeparator_x                               0x950FD0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x951790
#define CContextMenuManager__RemoveMenu_x                          0x951800
#define CContextMenuManager__PopupMenu_x                           0x9518C0
#define CContextMenuManager__Flush_x                               0x951730
#define CContextMenuManager__GetMenu_x                             0x49B390
#define CContextMenuManager__CreateDefaultMenu_x                   0x71B840

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DCA10
#define CChatService__GetFriendName_x                              0x8DCA20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x710A60
#define CChatWindow__Clear_x                                       0x711D20
#define CChatWindow__WndNotification_x                             0x7124B0
#define CChatWindow__AddHistory_x                                  0x7115E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94E080
#define CComboWnd__Draw_x                                          0x94D580
#define CComboWnd__GetCurChoice_x                                  0x94DEC0
#define CComboWnd__GetListRect_x                                   0x94DA30
#define CComboWnd__GetTextRect_x                                   0x94E0F0
#define CComboWnd__InsertChoice_x                                  0x94DBC0
#define CComboWnd__SetColors_x                                     0x94DB90
#define CComboWnd__SetChoice_x                                     0x94DE90
#define CComboWnd__GetItemCount_x                                  0x94DED0
#define CComboWnd__GetCurChoiceText_x                              0x94DF10
#define CComboWnd__GetChoiceText_x                                 0x94DEE0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94DC50

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x719230
#define CContainerWnd__vftable_x                                   0xB134AC
#define CContainerWnd__SetContainer_x                              0x71A790

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54BF70
#define CDisplay__PreZoneMainUI_x                                  0x54BF80
#define CDisplay__CleanGameUI_x                                    0x5512F0
#define CDisplay__GetClickedActor_x                                0x544290
#define CDisplay__GetUserDefinedColor_x                            0x53C950
#define CDisplay__GetWorldFilePath_x                               0x545D00
#define CDisplay__is3dON_x                                         0x540EF0
#define CDisplay__ReloadUI_x                                       0x54B400
#define CDisplay__WriteTextHD2_x                                   0x540CE0
#define CDisplay__TrueDistance_x                                   0x5479C0
#define CDisplay__SetViewActor_x                                   0x543BB0
#define CDisplay__GetFloorHeight_x                                 0x540FB0
#define CDisplay__SetRenderWindow_x                                0x53F910
#define CDisplay__ToggleScreenshotMode_x                           0x543680

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x970870

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x95415F
#define CEditWnd__GetCharIndexPt_x                                 0x955090
#define CEditWnd__GetDisplayString_x                               0x954F30
#define CEditWnd__GetHorzOffset_x                                  0x9537A0
#define CEditWnd__GetLineForPrintableChar_x                        0x956230
#define CEditWnd__GetSelStartPt_x                                  0x955340
#define CEditWnd__GetSTMLSafeText_x                                0x954D50
#define CEditWnd__PointFromPrintableChar_x                         0x955E60
#define CEditWnd__SelectableCharFromPoint_x                        0x955FD0
#define CEditWnd__SetEditable_x                                    0x955410
#define CEditWnd__SetWindowTextA_x                                 0x954AD0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FCF00
#define CEverQuest__ClickedPlayer_x                                0x5EEF10
#define CEverQuest__CreateTargetIndicator_x                        0x60C520
#define CEverQuest__DeleteTargetIndicator_x                        0x60C5B0
#define CEverQuest__DoTellWindow_x                                 0x4E86D0
#define CEverQuest__OutputTextToLog_x                              0x4E8950
#define CEverQuest__DropHeldItemOnGround_x                         0x5E3F50
#define CEverQuest__dsp_chat_x                                     0x4E8CE0
#define CEverQuest__trimName_x                                     0x608810
#define CEverQuest__Emote_x                                        0x5FD760
#define CEverQuest__EnterZone_x                                    0x5F76E0
#define CEverQuest__GetBodyTypeDesc_x                              0x6020D0
#define CEverQuest__GetClassDesc_x                                 0x602710
#define CEverQuest__GetClassThreeLetterCode_x                      0x602D10
#define CEverQuest__GetDeityDesc_x                                 0x60AE60
#define CEverQuest__GetLangDesc_x                                  0x602ED0
#define CEverQuest__GetRaceDesc_x                                  0x6026F0
#define CEverQuest__InterpretCmd_x                                 0x60B430
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E8150
#define CEverQuest__LMouseUp_x                                     0x5E64E0
#define CEverQuest__RightClickedOnPlayer_x                         0x5E8A30
#define CEverQuest__RMouseUp_x                                     0x5E7460
#define CEverQuest__SetGameState_x                                 0x5E3CE0
#define CEverQuest__UPCNotificationFlush_x                         0x608710
#define CEverQuest__IssuePetCommand_x                              0x6042D0
#define CEverQuest__ReportSuccessfulHit_x                          0x5FEB50

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72B190
#define CGaugeWnd__CalcLinesFillRect_x                             0x72B1F0
#define CGaugeWnd__Draw_x                                          0x72A810

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF120
#define CGuild__GetGuildName_x                                     0x4AE200
#define CGuild__GetGuildIndex_x                                    0x4AE590

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7465C0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61DC50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x753540
#define CInvSlotMgr__MoveItem_x                                    0x7522B0
#define CInvSlotMgr__SelectSlot_x                                  0x753610

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x750B30
#define CInvSlot__SliderComplete_x                                 0x74E890
#define CInvSlot__GetItemBase_x                                    0x74E220
#define CInvSlot__UpdateItem_x                                     0x74E390

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x755070
#define CInvSlotWnd__CInvSlotWnd_x                                 0x754210
#define CInvSlotWnd__HandleLButtonUp_x                             0x754BF0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80E950
#define CItemDisplayWnd__UpdateStrings_x                           0x763670
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75D3F0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75D900
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x763C70
#define CItemDisplayWnd__AboutToShow_x                             0x7632D0
#define CItemDisplayWnd__WndNotification_x                         0x764D40
#define CItemDisplayWnd__RequestConvertItem_x                      0x764810
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x762340
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7630F0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x847410

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x769280

// CLabel 
#define CLabel__Draw_x                                             0x76EC60

// CListWnd
#define CListWnd__CListWnd_x                                       0x9267E0
#define CListWnd__dCListWnd_x                                      0x926B00
#define CListWnd__AddColumn_x                                      0x92AF60
#define CListWnd__AddColumn1_x                                     0x92AFB0
#define CListWnd__AddLine_x                                        0x92B340
#define CListWnd__AddString_x                                      0x92B140
#define CListWnd__CalculateFirstVisibleLine_x                      0x92AD20
#define CListWnd__CalculateVSBRange_x                              0x92AB10
#define CListWnd__ClearSel_x                                       0x92BB20
#define CListWnd__ClearAllSel_x                                    0x92BB80
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92C590
#define CListWnd__Compare_x                                        0x92A450
#define CListWnd__Draw_x                                           0x926C30
#define CListWnd__DrawColumnSeparators_x                           0x929420
#define CListWnd__DrawHeader_x                                     0x929890
#define CListWnd__DrawItem_x                                       0x929D90
#define CListWnd__DrawLine_x                                       0x929590
#define CListWnd__DrawSeparator_x                                  0x9294C0
#define CListWnd__EnableLine_x                                     0x928CF0
#define CListWnd__EnsureVisible_x                                  0x92C4B0
#define CListWnd__ExtendSel_x                                      0x92BA50
#define CListWnd__GetColumnTooltip_x                               0x928830
#define CListWnd__GetColumnMinWidth_x                              0x9288A0
#define CListWnd__GetColumnWidth_x                                 0x9287A0
#define CListWnd__GetCurSel_x                                      0x928130
#define CListWnd__GetItemAtPoint_x                                 0x928F70
#define CListWnd__GetItemAtPoint1_x                                0x928FE0
#define CListWnd__GetItemData_x                                    0x9281B0
#define CListWnd__GetItemHeight_x                                  0x928570
#define CListWnd__GetItemIcon_x                                    0x928340
#define CListWnd__GetItemRect_x                                    0x928DE0
#define CListWnd__GetItemText_x                                    0x9281F0
#define CListWnd__GetSelList_x                                     0x92BBD0
#define CListWnd__GetSeparatorRect_x                               0x929220
#define CListWnd__InsertLine_x                                     0x92B730
#define CListWnd__RemoveLine_x                                     0x92B880
#define CListWnd__SetColors_x                                      0x92AAF0
#define CListWnd__SetColumnJustification_x                         0x92A820
#define CListWnd__SetColumnWidth_x                                 0x92A740
#define CListWnd__SetCurSel_x                                      0x92B990
#define CListWnd__SetItemColor_x                                   0x92C160
#define CListWnd__SetItemData_x                                    0x92C120
#define CListWnd__SetItemText_x                                    0x92BD40
#define CListWnd__ShiftColumnSeparator_x                           0x92A8E0
#define CListWnd__Sort_x                                           0x92A5D0
#define CListWnd__ToggleSel_x                                      0x92B9C0
#define CListWnd__SetColumnsSizable_x                              0x92A990
#define CListWnd__SetItemWnd_x                                     0x92BFF0
#define CListWnd__GetItemWnd_x                                     0x928390
#define CListWnd__SetItemIcon_x                                    0x92BDC0
#define CListWnd__CalculateCustomWindowPositions_x                 0x92AE20
#define CListWnd__SetVScrollPos_x                                  0x92A720

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x784430
#define CMapViewWnd__GetWorldCoordinates_x                         0x782B40
#define CMapViewWnd__HandleLButtonDown_x                           0x77FB80

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A44A0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A4D80
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A52B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A8230
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A3020
#define CMerchantWnd__SelectBuySellSlot_x                          0x7ADDE0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A40C0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AA500
#define CPacketScrambler__hton_x                                   0x8AA4F0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x945800
#define CSidlManager__FindScreenPieceTemplate_x                    0x945C10
#define CSidlManager__FindScreenPieceTemplate1_x                   0x945A00
#define CSidlManager__CreateLabel_x                                0x805DA0
#define CSidlManager__CreateXWndFromTemplate_x                     0x948B70
#define CSidlManager__CreateXWndFromTemplate1_x                    0x948D40
#define CSidlManager__CreateXWnd_x                                 0x805CD0
#define CSidlManager__CreateHotButtonWnd_x                         0x806290

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9422C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9421C0
#define CSidlScreenWnd__ConvertToRes_x                             0x967820
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x941C60
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x941950
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x941A20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x941AF0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x942760
#define CSidlScreenWnd__EnableIniStorage_x                         0x942C30
#define CSidlScreenWnd__GetSidlPiece_x                             0x942950
#define CSidlScreenWnd__Init1_x                                    0x941550
#define CSidlScreenWnd__LoadIniInfo_x                              0x942C80
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9437E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x940950
#define CSidlScreenWnd__StoreIniInfo_x                             0x943350
#define CSidlScreenWnd__StoreIniVis_x                              0x9436C0
#define CSidlScreenWnd__WndNotification_x                          0x942670
#define CSidlScreenWnd__GetChildItem_x                             0x942BB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9323A0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F8F30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x682910
#define CSkillMgr__GetSkillCap_x                                   0x682AF0
#define CSkillMgr__GetNameToken_x                                  0x682090
#define CSkillMgr__IsActivatedSkill_x                              0x6821D0
#define CSkillMgr__IsCombatSkill_x                                 0x682110

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x952580
#define CSliderWnd__SetValue_x                                     0x9523F0
#define CSliderWnd__SetNumTicks_x                                  0x952450

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80BDF0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95AD70
#define CStmlWnd__CalculateHSBRange_x                              0x95BE90
#define CStmlWnd__CalculateVSBRange_x                              0x95BE10
#define CStmlWnd__CanBreakAtCharacter_x                            0x9601C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x960E50
#define CStmlWnd__ForceParseNow_x                                  0x95B360
#define CStmlWnd__GetNextTagPiece_x                                0x960120
#define CStmlWnd__GetSTMLText_x                                    0x504690
#define CStmlWnd__GetVisibleText_x                                 0x95B380
#define CStmlWnd__InitializeWindowVariables_x                      0x960CA0
#define CStmlWnd__MakeStmlColorTag_x                               0x95A3E0
#define CStmlWnd__MakeWndNotificationTag_x                         0x95A450
#define CStmlWnd__SetSTMLText_x                                    0x959490
#define CStmlWnd__StripFirstSTMLLines_x                            0x961F50
#define CStmlWnd__UpdateHistoryString_x                            0x961060

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9585E0
#define CTabWnd__DrawCurrentPage_x                                 0x958D10
#define CTabWnd__DrawTab_x                                         0x958A30
#define CTabWnd__GetCurrentPage_x                                  0x957DF0
#define CTabWnd__GetPageInnerRect_x                                0x958030
#define CTabWnd__GetTabInnerRect_x                                 0x957F70
#define CTabWnd__GetTabRect_x                                      0x957E20
#define CTabWnd__InsertPage_x                                      0x958240
#define CTabWnd__SetPage_x                                         0x9580B0
#define CTabWnd__SetPageRect_x                                     0x958520
#define CTabWnd__UpdatePage_x                                      0x9588F0
#define CTabWnd__GetPageFromTabIndex_x                             0x958970
#define CTabWnd__GetCurrentTabIndex_x                              0x957DE0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x769650
#define CPageWnd__SetTabText_x                                     0x957940

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8DF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92F280
#define CTextureFont__GetTextExtent_x                              0x92F440

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B5CE0
#define CHtmlComponentWnd__ValidateUri_x                           0x747FB0
#define CHtmlWnd__SetClientCallbacks_x                             0x622CC0
#define CHtmlWnd__AddObserver_x                                    0x622CE0
#define CHtmlWnd__RemoveObserver_x                                 0x622D40
#define Window__getProgress_x                                      0x85FDB0
#define Window__getStatus_x                                        0x85FDD0
#define Window__getURI_x                                           0x85FDE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96D2C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91C4D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8320
#define CXStr__CXStr1_x                                            0x481500
#define CXStr__CXStr3_x                                            0x8FCEC0
#define CXStr__dCXStr_x                                            0x478730
#define CXStr__operator_equal_x                                    0x8FD0F0
#define CXStr__operator_equal1_x                                   0x8FD130
#define CXStr__operator_plus_equal1_x                              0x8FDBC0
#define CXStr__SetString_x                                         0x8FFAB0
#define CXStr__operator_char_p_x                                   0x8FD600
#define CXStr__GetChar_x                                           0x8FF400
#define CXStr__Delete_x                                            0x8FECB0
#define CXStr__GetUnicode_x                                        0x8FF470
#define CXStr__GetLength_x                                         0x47D3B0
#define CXStr__Mid_x                                               0x47D3C0
#define CXStr__Insert_x                                            0x8FF4D0
#define CXStr__FindNext_x                                          0x8FF120

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x950820
#define CXWnd__BringToTop_x                                        0x935B10
#define CXWnd__Center_x                                            0x935690
#define CXWnd__ClrFocus_x                                          0x9354B0
#define CXWnd__Destroy_x                                           0x935550
#define CXWnd__DoAllDrawing_x                                      0x931B40
#define CXWnd__DrawChildren_x                                      0x931B10
#define CXWnd__DrawColoredRect_x                                   0x931F90
#define CXWnd__DrawTooltip_x                                       0x930680
#define CXWnd__DrawTooltipAtPoint_x                                0x930740
#define CXWnd__GetBorderFrame_x                                    0x931DF0
#define CXWnd__GetChildWndAt_x                                     0x935BB0
#define CXWnd__GetClientClipRect_x                                 0x933DD0
#define CXWnd__GetScreenClipRect_x                                 0x933E80
#define CXWnd__GetScreenRect_x                                     0x934030
#define CXWnd__GetTooltipRect_x                                    0x931FE0
#define CXWnd__GetWindowTextA_x                                    0x49CA70
#define CXWnd__IsActive_x                                          0x932710
#define CXWnd__IsDescendantOf_x                                    0x934A10
#define CXWnd__IsReallyVisible_x                                   0x934A40
#define CXWnd__IsType_x                                            0x936220
#define CXWnd__Move_x                                              0x934AC0
#define CXWnd__Move1_x                                             0x934B70
#define CXWnd__ProcessTransition_x                                 0x935640
#define CXWnd__Refade_x                                            0x934E30
#define CXWnd__Resize_x                                            0x9350C0
#define CXWnd__Right_x                                             0x9358D0
#define CXWnd__SetFocus_x                                          0x935470
#define CXWnd__SetFont_x                                           0x9354E0
#define CXWnd__SetKeyTooltip_x                                     0x936030
#define CXWnd__SetMouseOver_x                                      0x932F50
#define CXWnd__StartFade_x                                         0x9348F0
#define CXWnd__GetChildItem_x                                      0x935D10
#define CXWnd__SetParent_x                                         0x9347C0
#define CXWnd__Minimize_x                                          0x935130

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9688A0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x938A40
#define CXWndManager__DrawWindows_x                                0x938A60
#define CXWndManager__GetKeyboardFlags_x                           0x93B200
#define CXWndManager__HandleKeyboardMsg_x                          0x93ADC0
#define CXWndManager__RemoveWnd_x                                  0x93B420
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93B990

// CDBStr
#define CDBStr__GetString_x                                        0x53B8F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB800
#define EQ_Character__Cur_HP_x                                     0x4D1EA0
#define EQ_Character__Cur_Mana_x                                   0x4D95D0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE870
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2300
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2450
#define EQ_Character__GetHPRegen_x                                 0x4DF3A0
#define EQ_Character__GetEnduranceRegen_x                          0x4DF9A0
#define EQ_Character__GetManaRegen_x                               0x4DFDE0
#define EQ_Character__Max_Endurance_x                              0x6490B0
#define EQ_Character__Max_HP_x                                     0x4D1CD0
#define EQ_Character__Max_Mana_x                                   0x648EB0
#define EQ_Character__doCombatAbility_x                            0x64B500
#define EQ_Character__UseSkill_x                                   0x4E1BB0
#define EQ_Character__GetConLevel_x                                0x641F40
#define EQ_Character__IsExpansionFlag_x                            0x5A6370
#define EQ_Character__TotalEffect_x                                0x4C52C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF5C0
#define EQ_Character__SpellDuration_x                              0x4BF0F0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4C20
#define EQ_Character__GetBaseSkill_x                               0x4D5BC0
#define EQ_Character__CanUseItem_x                                 0x4D98E0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C9850

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65FA20

//PcClient
#define PcClient__PcClient_x                                       0x63F670

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9460
#define CCharacterListWnd__EnterWorld_x                            0x4B8EA0
#define CCharacterListWnd__Quit_x                                  0x4B8BF0
#define CCharacterListWnd__UpdateList_x                            0x4B9030

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x623EF0
#define EQ_Item__CreateItemTagString_x                             0x8A3D80
#define EQ_Item__IsStackable_x                                     0x8A8900
#define EQ_Item__GetImageNum_x                                     0x8A5800
#define EQ_Item__CreateItemClient_x                                0x6230C0
#define EQ_Item__GetItemValue_x                                    0x8A6B10
#define EQ_Item__ValueSellMerchant_x                               0x8AA0E0
#define EQ_Item__IsKeyRingItem_x                                   0x8A8220
#define EQ_Item__CanGoInBag_x                                      0x624010
#define EQ_Item__IsEmpty_x                                         0x8A7D60
#define EQ_Item__GetMaxItemCount_x                                 0x8A6F20
#define EQ_Item__GetHeldItem_x                                     0x8A56D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A3710

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x559EA0
#define EQ_LoadingS__Array_x                                       0xC27B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x649A10
#define EQ_PC__GetAlternateAbilityId_x                             0x8B3340
#define EQ_PC__GetCombatAbility_x                                  0x8B39B0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B3A20
#define EQ_PC__GetItemRecastTimer_x                                0x64BA80
#define EQ_PC__HasLoreItem_x                                       0x642750
#define EQ_PC__AlertInventoryChanged_x                             0x641870
#define EQ_PC__GetPcZoneClient_x                                   0x66E5C0
#define EQ_PC__RemoveMyAffect_x                                    0x64ECB0
#define EQ_PC__GetKeyRingItems_x                                   0x8B42B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B4040
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B45B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AC8A0
#define EQItemList__add_object_x                                   0x5D96E0
#define EQItemList__add_item_x                                     0x5ACE00
#define EQItemList__delete_item_x                                  0x5ACE50
#define EQItemList__FreeItemList_x                                 0x5ACD50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5383E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6612A0
#define EQPlayer__dEQPlayer_x                                      0x6541D0
#define EQPlayer__DoAttack_x                                       0x669260
#define EQPlayer__EQPlayer_x                                       0x654890
#define EQPlayer__SetNameSpriteState_x                             0x658F90
#define EQPlayer__SetNameSpriteTint_x                              0x659E50
#define PlayerBase__HasProperty_j_x                                0x99B010
#define EQPlayer__IsTargetable_x                                   0x99B4B0
#define EQPlayer__CanSee_x                                         0x99B310
#define EQPlayer__CanSee1_x                                        0x99B3E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x99B0D0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66C060
#define PlayerZoneClient__GetLevel_x                               0x66E600
#define PlayerZoneClient__IsValidTeleport_x                        0x5DA850
#define PlayerZoneClient__LegalPlayerRace_x                        0x5531E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x664170
#define EQPlayerManager__GetSpawnByName_x                          0x664220
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6642B0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6275E0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x627660
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6276A0
#define KeypressHandler__ClearCommandStateArray_x                  0x628AB0
#define KeypressHandler__HandleKeyDown_x                           0x628AD0
#define KeypressHandler__HandleKeyUp_x                             0x628B70
#define KeypressHandler__SaveKeymapping_x                          0x628FC0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7802A0
#define MapViewMap__SaveEx_x                                       0x783660
#define MapViewMap__SetZoom_x                                      0x787D20

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C7770

// StringTable 
#define StringTable__getString_x                                   0x8C24F0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64E920
#define PcZoneClient__RemovePetEffect_x                            0x64EF50
#define PcZoneClient__HasAlternateAbility_x                        0x648CE0
#define PcZoneClient__GetCurrentMod_x                              0x4E4C50
#define PcZoneClient__GetModCap_x                                  0x4E4B50
#define PcZoneClient__CanEquipItem_x                               0x6493B0
#define PcZoneClient__GetItemByID_x                                0x64BEF0
#define PcZoneClient__GetItemByItemClass_x                         0x64C040
#define PcZoneClient__RemoveBuffEffect_x                           0x64EF70
#define PcZoneClient__BandolierSwap_x                              0x649FC0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64BA20

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DF3C0

//IconCache
#define IconCache__GetIcon_x                                       0x7208D0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7183D0
#define CContainerMgr__CloseContainer_x                            0x7186A0
#define CContainerMgr__OpenExperimentContainer_x                   0x719120

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D8280

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61C070

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7767A0
#define CLootWnd__RequestLootSlot_x                                0x7759D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5798E0
#define EQ_Spell__SpellAffects_x                                   0x579D50
#define EQ_Spell__SpellAffectBase_x                                0x579B10
#define EQ_Spell__IsStackable_x                                    0x4C98C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9740
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B67F0
#define EQ_Spell__IsSPAStacking_x                                  0x57ABA0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A0B0
#define EQ_Spell__IsNoRemove_x                                     0x4C98A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57ABB0
#define __IsResEffectSpell_x                                       0x4C8CE0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACE50

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D1E90

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81F150
#define CTargetWnd__WndNotification_x                              0x81E9E0
#define CTargetWnd__RefreshTargetBuffs_x                           0x81ECB0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81DB50

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x823760

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x535E40
#define CTaskManager__HandleMessage_x                              0x5342D0
#define CTaskManager__GetTaskStatus_x                              0x535EF0
#define CTaskManager__GetElementDescription_x                      0x535F70

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x574E50
#define EqSoundManager__PlayScriptMp3_x                            0x574FB0
#define EqSoundManager__SoundAssistPlay_x                          0x686870
#define EqSoundManager__WaveInstancePlay_x                         0x685DE0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x529BA0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x956E50

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x561840
#define CAltAbilityData__GetMercMaxRank_x                          0x5617D0
#define CAltAbilityData__GetMaxRank_x                              0x556F80

//CTargetRing
#define CTargetRing__Cast_x                                        0x61A180

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9720
#define CharacterBase__CreateItemGlobalIndex_x                     0x511390
#define CharacterBase__CreateItemIndex_x                           0x622270
#define CharacterBase__GetItemPossession_x                         0x4FCF70
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DA490
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DA4F0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FF490
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FFCC0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FFD70

//messages
#define msg_spell_worn_off_x                                       0x59E4D0
#define msg_new_text_x                                             0x593280
#define __msgTokenTextParam_x                                      0x5A0A00
#define msgTokenText_x                                             0x5A0C50

//SpellManager
#define SpellManager__vftable_x                                    0xAED4B8
#define SpellManager__SpellManager_x                               0x689BA0
#define Spellmanager__LoadTextSpells_x                             0x68A490
#define SpellManager__GetSpellByGroupAndRank_x                     0x689D70

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99EF60

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x511A10
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A47D0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63AD70
#define ItemGlobalIndex__IsValidIndex_x                            0x511A70

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D2830
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D2AB0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76EFA0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71CAD0
#define CCursorAttachment__AttachToCursor1_x                       0x71CB10
#define CCursorAttachment__Deactivate_x                            0x71DB00

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x949B80
#define CSidlManagerBase__CreatePageWnd_x                          0x949380
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x945620
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9455B0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x966E70
#define CEQSuiteTextureLoader__GetTexture_x                        0x966B30

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50E900
#define CFindItemWnd__WndNotification_x                            0x50F3E0
#define CFindItemWnd__Update_x                                     0x50FF50
#define CFindItemWnd__PickupSelectedItem_x                         0x50E140

//IString
#define IString__Append_x                                          0x4F02E0

//Camera
#define CDisplay__cameraType_x                                     0xE01530
#define EverQuest__Cameras_x                                       0xEC4A5C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5170E0
#define LootFiltersManager__GetItemFilterData_x                    0x5169F0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x516A20
#define LootFiltersManager__SetItemLootFilter_x                    0x516C40

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C62B0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A4B50
#define CResolutionHandler__GetWindowedStyle_x                     0x681340

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7151C0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E7420
#define CDistillerInfo__Instance_x                                 0x8E73C0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x735390
#define CGroupWnd__UpdateDisplay_x                                 0x734700

//ItemBase
#define ItemBase__IsLore_x                                         0x8A82D0
#define ItemBase__IsLoreEquipped_x                                 0x8A8340

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D9640
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D9780
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D97E0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x676D40
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67A6E0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x504C90

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1EF0
#define FactionManagerClient__HandleFactionMessage_x               0x4F2560
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2B20
#define FactionManagerClient__GetMaxFaction_x                      0x4F2B3F
#define FactionManagerClient__GetMinFaction_x                      0x4F2AF0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FCF40

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92E230

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD80

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD1C0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x560CF0

//CTargetManager
#define CTargetManager__Get_x                                      0x68D3D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x676D40

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8BB0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5ACCF0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF620F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
