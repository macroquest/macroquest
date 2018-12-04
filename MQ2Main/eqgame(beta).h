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
#define __ExpectedVersionDate                                     "Dec  4 2018"
#define __ExpectedVersionTime                                     "04:22:11"
#define __ActualVersionDate_x                                      0xAD212C
#define __ActualVersionTime_x                                      0xAD2120

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6170F0
#define __MemChecker1_x                                            0x8EB7B0
#define __MemChecker2_x                                            0x6A6320
#define __MemChecker3_x                                            0x6A6270
#define __MemChecker4_x                                            0x843030
#define __EncryptPad0_x                                            0xC06340
#define __EncryptPad1_x                                            0xC645D0
#define __EncryptPad2_x                                            0xC16EC8
#define __EncryptPad3_x                                            0xC16AC8
#define __EncryptPad4_x                                            0xC54E40
#define __EncryptPad5_x                                            0x1035AE0
#define __AC1_x                                                    0x7FF896
#define __AC2_x                                                    0x5D1D7F
#define __AC3_x                                                    0x5D8C0F
#define __AC4_x                                                    0x5DCA30
#define __AC5_x                                                    0x5E2C90
#define __AC6_x                                                    0x5E7266
#define __AC7_x                                                    0x5D17F0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E8A344

// Direct Input
#define DI8__Main_x                                                0x1035B04
#define DI8__Keyboard_x                                            0x1035B08
#define DI8__Mouse_x                                               0xF2B448
#define DI8__Mouse_Copy_x                                          0xE891A4
#define DI8__Mouse_Check_x                                         0xF2B76C
#define __AutoSkillArray_x                                         0xE8A0BC
#define __Attack_x                                                 0xF27EC3
#define __Autofire_x                                               0xF27EC4
#define __BindList_x                                               0xBF4F20
#define g_eqCommandStates_x                                        0xBF5C90
#define __Clicks_x                                                 0xE8925C
#define __CommandList_x                                            0xBF6848
#define __CurrentMapLabel_x                                        0x103DA6C
#define __CurrentSocial_x                                          0xBDF730
#define __DoAbilityList_x                                          0xEBF9E4
#define __do_loot_x                                                0x59F520
#define __DrawHandler_x                                            0x16BA440
#define __GroupCount_x                                             0xE79452
#define __Guilds_x                                                 0xE7F9B0
#define __gWorld_x                                                 0xE7BCD4
#define __HWnd_x                                                   0xF2B44C
#define __heqmain_x                                                0x1035AC8
#define __InChatMode_x                                             0xE8918C
#define __LastTell_x                                               0xE8B0E0
#define __LMouseHeldTime_x                                         0xE892C8
#define __Mouse_x                                                  0x1035AEC
#define __MouseLook_x                                              0xE89222
#define __MouseEventTime_x                                         0xF28978
#define __gpbCommandEvent_x                                        0xE7B774
#define __NetStatusToggle_x                                        0xE89225
#define __PCNames_x                                                0xE8A69C
#define __RangeAttackReady_x                                       0xE8A3A0
#define __RMouseHeldTime_x                                         0xE892C4
#define __RunWalkState_x                                           0xE89190
#define __ScreenMode_x                                             0xDC7A94
#define __ScreenX_x                                                0xE89144
#define __ScreenY_x                                                0xE89140
#define __ScreenXMax_x                                             0xE89148
#define __ScreenYMax_x                                             0xE8914C
#define __ServerHost_x                                             0xE7B9AB
#define __ServerName_x                                             0xEBF9A4
#define __ShiftKeyDown_x                                           0xE8981C
#define __ShowNames_x                                              0xE8A55C
#define __Socials_x                                                0xEBFAA4
#define __SubscriptionType_x                                       0x107F5BC
#define __TargetAggroHolder_x                                      0x1040428
#define __ZoneType_x                                               0xE89620
#define __GroupAggro_x                                             0x1040468
#define __LoginName_x                                              0x103635C
#define __Inviter_x                                                0xF27E40
#define __AttackOnAssist_x                                         0xE8A518
#define __UseTellWindows_x                                         0xE8A834
#define __gfMaxZoomCameraDistance_x                                0xAC7638
#define __gfMaxCameraDistance_x                                    0xAF4AA0
#define __pulAutoRun_x                                             0xE89240
#define __pulForward_x                                             0xE8A86C
#define __pulBackward_x                                            0xE8A870
#define __pulTurnRight_x                                           0xE8A874
#define __pulTurnLeft_x                                            0xE8A878
#define __pulStrafeLeft_x                                          0xE8A87C
#define __pulStrafeRight_x                                         0xE8A880
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE7BD48
#define instEQZoneInfo_x                                           0xE89418
#define instKeypressHandler_x                                      0xF28928
#define pinstActiveBanker_x                                        0xE7B854
#define pinstActiveCorpse_x                                        0xE7B84C
#define pinstActiveGMaster_x                                       0xE7B850
#define pinstActiveMerchant_x                                      0xE7B848
#define pinstAggroInfo_x                                           0xC7AE08
#define pinstAltAdvManager_x                                       0xDC86F0
#define pinstAuraMgr_x                                             0xC96988
#define pinstBandageTarget_x                                       0xE7B864
#define pinstCamActor_x                                            0xDC7A88
#define pinstCDBStr_x                                              0xDC7424
#define pinstCDisplay_x                                            0xE7BAB4
#define pinstCEverQuest_x                                          0x1035C20
#define pinstEverQuestInfo_x                                       0xE89138
#define pinstCharData_x                                            0xE7BCF0
#define pinstCharSpawn_x                                           0xE7B89C
#define pinstControlledMissile_x                                   0xE7BCDC
#define pinstControlledPlayer_x                                    0xE7B89C
#define pinstCResolutionHandler_x                                  0x16BA670
#define pinstCSidlManager_x                                        0x16B9504
#define pinstCXWndManager_x                                        0x16B94F8
#define instDynamicZone_x                                          0xE7F888
#define pinstDZMember_x                                            0xE7F998
#define pinstDZTimerInfo_x                                         0xE7F99C
#define pinstEQItemList_x                                          0xE77F38
#define pinstEQObjectList_x                                        0xE79128
#define instEQMisc_x                                               0xDC7360
#define pinstEQSoundManager_x                                      0xDC8F50
#define pinstEQSpellStrings_x                                      0xC88F40
#define instExpeditionLeader_x                                     0xE7F8D2
#define instExpeditionName_x                                       0xE7F912
#define pinstGroup_x                                               0xE7944E
#define pinstImeManager_x                                          0x16B94FC
#define pinstLocalPlayer_x                                         0xE7B844
#define pinstMercenaryData_x                                       0xF29124
#define pinstMercenaryStats_x                                      0x1040574
#define pinstMercAltAbilities_x                                    0xDC8CC0
#define pinstModelPlayer_x                                         0xE7B85C
#define pinstPCData_x                                              0xE7BCF0
#define pinstRealEstateItems_x                                     0xF2A608
#define pinstSkillMgr_x                                            0xF2A6D8
#define pinstSpawnManager_x                                        0xF29CC8
#define pinstSpellManager_x                                        0xF2A8B0
#define pinstSpellSets_x                                           0xF20AEC
#define pinstStringTable_x                                         0xE7B648
#define pinstSwitchManager_x                                       0xE792E8
#define pinstTarget_x                                              0xE7B898
#define pinstTargetObject_x                                        0xE7B8A4
#define pinstTargetSwitch_x                                        0xE7BD3C
#define pinstTaskMember_x                                          0xDC71F4
#define pinstTrackTarget_x                                         0xE7B8A8
#define pinstTradeTarget_x                                         0xE7B858
#define instTributeActive_x                                        0xDC7385
#define pinstViewActor_x                                           0xDC7A84
#define pinstWorldData_x                                           0xE7B764
#define pinstZoneAddr_x                                            0xE896B8
#define pinstPlayerPath_x                                          0xF29D60
#define pinstTargetIndicator_x                                     0xF2AB18
#define pinstCTargetManager_x                                      0xF2ABB0
#define EQObject_Top_x                                             0xE7B804

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC7544
#define pinstCAchievementsWnd_x                                    0xDC7534
#define pinstCActionsWnd_x                                         0xDC75A8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC7A48
#define pinstCAdvancedLootWnd_x                                    0xDC758C
#define pinstCAdventureLeaderboardWnd_x                            0x1037240
#define pinstCAdventureRequestWnd_x                                0x10372F0
#define pinstCAdventureStatsWnd_x                                  0x10373A0
#define pinstCAggroMeterWnd_x                                      0xDC7AC8
#define pinstCAlarmWnd_x                                           0xDC7B34
#define pinstCAlertHistoryWnd_x                                    0xDC74EC
#define pinstCAlertStackWnd_x                                      0xDC7ADC
#define pinstCAlertWnd_x                                           0xDC7B00
#define pinstCAltStorageWnd_x                                      0x1037700
#define pinstCAudioTriggersWindow_x                                0xC7B298
#define pinstCAuraWnd_x                                            0xDC7AC4
#define pinstCAvaZoneWnd_x                                         0xDC74F4
#define pinstCBandolierWnd_x                                       0xDC7B08
#define pinstCBankWnd_x                                            0xDC74F0
#define pinstCBarterMerchantWnd_x                                  0x1038940
#define pinstCBarterSearchWnd_x                                    0x10389F0
#define pinstCBarterWnd_x                                          0x1038AA0
#define pinstCBazaarConfirmationWnd_x                              0xDC7AD8
#define pinstCBazaarSearchWnd_x                                    0xDC7630
#define pinstCBazaarWnd_x                                          0xDC7B0C
#define pinstCBlockedBuffWnd_x                                     0xDC74D4
#define pinstCBlockedPetBuffWnd_x                                  0xDC7500
#define pinstCBodyTintWnd_x                                        0xDC7AA8
#define pinstCBookWnd_x                                            0xDC7B2C
#define pinstCBreathWnd_x                                          0xDC7548
#define pinstCBuffWindowNORMAL_x                                   0xDC7D48
#define pinstCBuffWindowSHORT_x                                    0xDC7D4C
#define pinstCBugReportWnd_x                                       0xDC753C
#define pinstCButtonWnd_x                                          0x16B9728
#define pinstCCastingWnd_x                                         0xDC7538
#define pinstCCastSpellWnd_x                                       0xDC7A44
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC754C
#define pinstCChatWindowManager_x                                  0x1039560
#define pinstCClaimWnd_x                                           0x10396B8
#define pinstCColorPickerWnd_x                                     0xDC757C
#define pinstCCombatAbilityWnd_x                                   0xDC7AD0
#define pinstCCombatSkillsSelectWnd_x                              0xDC75A4
#define pinstCCompassWnd_x                                         0xDC7A78
#define pinstCConfirmationDialog_x                                 0x103E5B8
#define pinstCContainerMgr_x                                       0xDC7AE0
#define pinstCContextMenuManager_x                                 0x16B94B8
#define pinstCCursorAttachment_x                                   0xDC7530
#define pinstCDistillerInfo_x                                      0x103CFC4
#define pinstCDynamicZoneWnd_x                                     0x1039C80
#define pinstCEditLabelWnd_x                                       0xDC7B3C
#define pinstCEQMainWnd_x                                          0x1039EC8
#define pinstCEventCalendarWnd_x                                   0xDC7564
#define pinstCExtendedTargetWnd_x                                  0xDC7AB8
#define pinstCFacePick_x                                           0xDC7574
#define pinstCFactionWnd_x                                         0xDC752C
#define pinstCFellowshipWnd_x                                      0x103A0C8
#define pinstCFileSelectionWnd_x                                   0xDC7578
#define pinstCFindItemWnd_x                                        0xDC7B28
#define pinstCFindLocationWnd_x                                    0x103A220
#define pinstCFriendsWnd_x                                         0xDC762C
#define pinstCGemsGameWnd_x                                        0xDC7B04
#define pinstCGiveWnd_x                                            0xDC7B30
#define pinstCGroupSearchFiltersWnd_x                              0xDC7AE8
#define pinstCGroupSearchWnd_x                                     0x103A618
#define pinstCGroupWnd_x                                           0x103A6C8
#define pinstCGuildBankWnd_x                                       0xE8A4FC
#define pinstCGuildCreationWnd_x                                   0x103A828
#define pinstCGuildMgmtWnd_x                                       0x103A8D8
#define pinstCharacterCreation_x                                   0xDC7ACC
#define pinstCHelpWnd_x                                            0xDC7A7C
#define pinstCHeritageSelectionWnd_x                               0xDC7588
#define pinstCHotButtonWnd_x                                       0x103CA30
#define pinstCHotButtonWnd1_x                                      0x103CA30
#define pinstCHotButtonWnd2_x                                      0x103CA34
#define pinstCHotButtonWnd3_x                                      0x103CA38
#define pinstCHotButtonWnd4_x                                      0x103CA3C
#define pinstCIconSelectionWnd_x                                   0xDC7510
#define pinstCInspectWnd_x                                         0xDC750C
#define pinstCInventoryWnd_x                                       0xDC7B10
#define pinstCInvSlotMgr_x                                         0xDC7AB0
#define pinstCItemDisplayManager_x                                 0x103CFC0
#define pinstCItemExpTransferWnd_x                                 0x103D0F0
#define pinstCItemOverflowWnd_x                                    0xDC7634
#define pinstCJournalCatWnd_x                                      0xDC7594
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDC7558
#define pinstCKeyRingWnd_x                                         0xDC74C8
#define pinstCLargeDialogWnd_x                                     0x103F238
#define pinstCLayoutCopyWnd_x                                      0x103D440
#define pinstCLFGuildWnd_x                                         0x103D4F0
#define pinstCLoadskinWnd_x                                        0xDC7B14
#define pinstCLootFiltersCopyWnd_x                                 0xC972B8
#define pinstCLootFiltersWnd_x                                     0xDC7B24
#define pinstCLootSettingsWnd_x                                    0xDC7D44
#define pinstCLootWnd_x                                            0xDC7568
#define pinstCMailAddressBookWnd_x                                 0xDC7504
#define pinstCMailCompositionWnd_x                                 0xDC74DC
#define pinstCMailIgnoreListWnd_x                                  0xDC7508
#define pinstCMailWnd_x                                            0xDC7D54
#define pinstCManageLootWnd_x                                      0xDC8B68
#define pinstCMapToolbarWnd_x                                      0xDC7B18
#define pinstCMapViewWnd_x                                         0xDC7AF0
#define pinstCMarketplaceWnd_x                                     0xDC756C
#define pinstCMerchantWnd_x                                        0xDC75A0
#define pinstCMIZoneSelectWnd_x                                    0x103DD28
#define pinstCMusicPlayerWnd_x                                     0xDC74C4
#define pinstCNameChangeMercWnd_x                                  0xDC7AAC
#define pinstCNameChangePetWnd_x                                   0xDC7A70
#define pinstCNameChangeWnd_x                                      0xDC7550
#define pinstCNoteWnd_x                                            0xDC7A50
#define pinstCObjectPreviewWnd_x                                   0xDC7590
#define pinstCOptionsWnd_x                                         0xDC7B1C
#define pinstCPetInfoWnd_x                                         0xDC74E0
#define pinstCPetitionQWnd_x                                       0xDC75AC
//#define pinstCPlayerCustomizationWnd_x                           0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC7AA0
#define pinstCPlayerWnd_x                                          0xDC75B0
#define pinstCPopupWndManager_x                                    0x103E5B8
#define pinstCProgressionSelectionWnd_x                            0x103E668
#define pinstCPurchaseGroupWnd_x                                   0xDC7A3C
#define pinstCPurchaseWnd_x                                        0xDC759C
#define pinstCPvPLeaderboardWnd_x                                  0x103E718
#define pinstCPvPStatsWnd_x                                        0x103E7C8
#define pinstCQuantityWnd_x                                        0xDC7518
#define pinstCRaceChangeWnd_x                                      0xDC7570
#define pinstCRaidOptionsWnd_x                                     0xDC7AEC
#define pinstCRaidWnd_x                                            0xDC751C
#define pinstCRealEstateItemsWnd_x                                 0xDC7540
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC755C
#define pinstCRealEstateManageWnd_x                                0xDC7D50
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC74CC
#define pinstCRealEstatePlotSearchWnd_x                            0xDC74F8
#define pinstCRealEstatePurchaseWnd_x                              0xDC7520
#define pinstCRespawnWnd_x                                         0xDC7AE4
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDC7ABC
#define pinstCSendMoneyWnd_x                                       0xDC7D40
#define pinstCServerListWnd_x                                      0xDC74E8
#define pinstCSkillsSelectWnd_x                                    0xDC7580
#define pinstCSkillsWnd_x                                          0xDC7560
#define pinstCSocialEditWnd_x                                      0xDC7528
#define pinstCSocialWnd_x                                          0xDC7AC0
#define pinstCSpellBookWnd_x                                       0xDC7AB4
#define pinstCStoryWnd_x                                           0xDC7A4C
#define pinstCTargetOfTargetWnd_x                                  0x10405F8
#define pinstCTargetWnd_x                                          0xDC74D8
#define pinstCTaskOverlayWnd_x                                     0xDC74FC
#define pinstCTaskSelectWnd_x                                      0x1040750
#define pinstCTaskManager_x                                        0xC97AB8
#define pinstCTaskTemplateSelectWnd_x                              0x1040800
#define pinstCTaskWnd_x                                            0x10408B0
#define pinstCTextEntryWnd_x                                       0xDC7A80
#define pinstCTextOverlay_x                                        0xC7B5A8
#define pinstCTimeLeftWnd_x                                        0xDC7584
#define pinstCTipWndCONTEXT_x                                      0x1040AB4
#define pinstCTipWndOFDAY_x                                        0x1040AB0
#define pinstCTitleWnd_x                                           0x1040B60
#define pinstCTrackingWnd_x                                        0xDC74E4
#define pinstCTradeskillWnd_x                                      0x1040CC8
#define pinstCTradeWnd_x                                           0xDC7AA4
#define pinstCTrainWnd_x                                           0xDC7514
#define pinstCTributeBenefitWnd_x                                  0x1040EC8
#define pinstCTributeMasterWnd_x                                   0x1040F78
#define pinstCTributeTrophyWnd_x                                   0x1041028
#define pinstCVideoModesWnd_x                                      0xDC7AD4
#define pinstCVoiceMacroWnd_x                                      0xF2B0E0
#define pinstCVoteResultsWnd_x                                     0xDC7A40
#define pinstCVoteWnd_x                                            0xDC75B4
#define pinstCWebManager_x                                         0xF2B244
#define pinstCZoneGuideWnd_x                                       0xDC74C0
#define pinstCZonePathWnd_x                                        0xDC74D0

#define pinstEQSuiteTextureLoader_x                                0xC660A0
#define pinstItemIconCache_x                                       0x1039E80
#define pinstLootFiltersManager_x                                  0xC97368
#define pinstRewardSelectionWnd_x                                  0x103EF10

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC16ABC
#define __CastRay_x                                                0x59AA40
#define __CastRay2_x                                               0x59AA90
#define __ConvertItemTags_x                                        0x5B56C0
#define __CrashHandler_x                                           0x84C980
#define __EQGetTime_x                                              0x8EB2A0
#define __ExecuteCmd_x                                             0x593390
#define __FixHeading_x                                             0x97BFE0
#define __get_bearing_x                                            0x59A590
#define __get_melee_range_x                                        0x59AC80
#define __GetAnimationCache_x                                      0x709C30
#define __GetGaugeValueFromEQ_x                                    0x7FE0A0
#define __GetLabelFromEQ_x                                         0x7FF820
#define __GetXTargetType_x                                         0x97DA40
#define __HeadingDiff_x                                            0x97C050
#define __HelpPath_x                                               0xF28594
#define __LoadFrontEnd_x                                           0x6A2180
#define __NewUIINI_x                                               0x7FDD70
#define __pCrashHandler_x                                          0x105E418
#define __ProcessGameEvents_x                                      0x5F8560
#define __ProcessMouseEvent_x                                      0x5F7D20
#define __SaveColors_x                                             0x543390
#define __STMLToText_x                                             0x91F290
#define __ToggleKeyRingItem_x                                      0x506460
#define CrashDetected_x                                            0x6A3C70
#define DrawNetStatus_x                                            0x624580
#define Expansion_HoT_x                                            0xE8A504
#define Teleport_Table_Size_x                                      0xE7B800
#define Teleport_Table_x                                           0xE79640
#define Util__FastTime_x                                           0x8EAE60
#define wwsCrashReportCheckForUploader_x                           0x84D4B0
#define wwsCrashReportPlatformLaunchUploader_x                     0x84FB90
#define __HandleMouseWheel_x                                       0x6A63D0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B5B0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494440
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494200

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54AE10
#define AltAdvManager__IsAbilityReady_x                            0x549D60
#define AltAdvManager__GetAAById_x                                 0x549F60
#define AltAdvManager__CanTrainAbility_x                           0x549FD0
#define AltAdvManager__CanSeeAbility_x                             0x54A330

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7530
#define CharacterZoneClient__HasSkill_x                            0x4D2200
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3920
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB930
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B80A0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D62F0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D63D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D64B0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0410
#define CharacterZoneClient__BardCastBard_x                        0x4C3080
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8170
#define CharacterZoneClient__GetEffect_x                           0x4B7FE0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1410
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C14E0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1530
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1680
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1850

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CC080

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D99A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x606D70
#define CButtonWnd__CButtonWnd_x                                   0x91B680

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F8580
#define CChatManager__InitContextMenu_x                            0x6F2620
#define CChatManager__FreeChatWindow_x                             0x6F7490
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FBEF0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F8320

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92FEA0
#define CContextMenu__dCContextMenu_x                              0x9300D0
#define CContextMenu__AddMenuItem_x                                0x9300E0
#define CContextMenu__RemoveMenuItem_x                             0x9303F0
#define CContextMenu__RemoveAllMenuItems_x                         0x930410
#define CContextMenu__CheckMenuItem_x                              0x930490
#define CContextMenu__SetMenuItem_x                                0x930310
#define CContextMenu__AddSeparator_x                               0x930270

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x930A30
#define CContextMenuManager__RemoveMenu_x                          0x930AA0
#define CContextMenuManager__PopupMenu_x                           0x930B60
#define CContextMenuManager__Flush_x                               0x9309D0
#define CContextMenuManager__GetMenu_x                             0x4965D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x895190
#define CChatService__GetFriendName_x                              0x8CBB00

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F8AF0
#define CChatWindow__Clear_x                                       0x6F9B50
#define CChatWindow__WndNotification_x                             0x6FA0C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92D310
#define CComboWnd__Draw_x                                          0x92C7F0
#define CComboWnd__GetCurChoice_x                                  0x92D150
#define CComboWnd__GetListRect_x                                   0x92CCB0
#define CComboWnd__GetTextRect_x                                   0x92D380
#define CComboWnd__InsertChoice_x                                  0x92CE40
#define CComboWnd__SetColors_x                                     0x92CE10
#define CComboWnd__SetChoice_x                                     0x92D120
#define CComboWnd__GetItemCount_x                                  0x92D160
#define CComboWnd__GetCurChoiceText_x                              0x92D1A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x701DF0
#define CContainerWnd__vftable_x                                   0xADB3D8
#define CContainerWnd__SetContainer_x                              0x703360

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x543150
#define CDisplay__GetClickedActor_x                                0x536100
#define CDisplay__GetUserDefinedColor_x                            0x52E7E0
#define CDisplay__GetWorldFilePath_x                               0x537B50
#define CDisplay__is3dON_x                                         0x532DD0
#define CDisplay__ReloadUI_x                                       0x53D270
#define CDisplay__WriteTextHD2_x                                   0x532BB0
#define CDisplay__TrueDistance_x                                   0x5397B0
#define CDisplay__SetViewActor_x                                   0x535A50
#define CDisplay__GetFloorHeight_x                                 0x532E90
#define CDisplay__SetRenderWindow_x                                0x5317C0
#define CDisplay__ToggleScreenshotMode_x                           0x535520

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94F730

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9345C0
#define CEditWnd__GetCharIndexPt_x                                 0x9354C0
#define CEditWnd__GetDisplayString_x                               0x935360
#define CEditWnd__GetHorzOffset_x                                  0x933BF0
#define CEditWnd__GetLineForPrintableChar_x                        0x936600
#define CEditWnd__GetSelStartPt_x                                  0x935770
#define CEditWnd__GetSTMLSafeText_x                                0x935180
#define CEditWnd__PointFromPrintableChar_x                         0x936230
#define CEditWnd__SelectableCharFromPoint_x                        0x9363A0
#define CEditWnd__SetEditable_x                                    0x935840

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E6790
#define CEverQuest__ClickedPlayer_x                                0x5D89F0
#define CEverQuest__CreateTargetIndicator_x                        0x5F5810
#define CEverQuest__DeleteTargetIndicator_x                        0x5F58A0
#define CEverQuest__DoTellWindow_x                                 0x4E3560
#define CEverQuest__OutputTextToLog_x                              0x4E3790
#define CEverQuest__DropHeldItemOnGround_x                         0x5CE2B0
#define CEverQuest__dsp_chat_x                                     0x4E3B20
#define CEverQuest__trimName_x                                     0x5F1B90
#define CEverQuest__Emote_x                                        0x5E6FA0
#define CEverQuest__EnterZone_x                                    0x5E1040
#define CEverQuest__GetBodyTypeDesc_x                              0x5EB440
#define CEverQuest__GetClassDesc_x                                 0x5EBA80
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EC080
#define CEverQuest__GetDeityDesc_x                                 0x5F4160
#define CEverQuest__GetLangDesc_x                                  0x5EC240
#define CEverQuest__GetRaceDesc_x                                  0x5EBA60
#define CEverQuest__InterpretCmd_x                                 0x5F4730
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D24A0
#define CEverQuest__LMouseUp_x                                     0x5D0820
#define CEverQuest__RightClickedOnPlayer_x                         0x5D2D80
#define CEverQuest__RMouseUp_x                                     0x5D17B0
#define CEverQuest__SetGameState_x                                 0x5CE040
#define CEverQuest__UPCNotificationFlush_x                         0x5F1A90
#define CEverQuest__IssuePetCommand_x                              0x5ED640
#define CEverQuest__ReportSuccessfulHit_x                          0x5E83A0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x713CB0
#define CGaugeWnd__CalcLinesFillRect_x                             0x713D10
#define CGaugeWnd__Draw_x                                          0x7133B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACBC0
#define CGuild__GetGuildName_x                                     0x4ABCA0
#define CGuild__GetGuildIndex_x                                    0x4AC030

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72F070

//CHotButton
#define CHotButton__SetButtonSize_x                                0x607130

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73C040
#define CInvSlotMgr__MoveItem_x                                    0x73AD70
#define CInvSlotMgr__SelectSlot_x                                  0x73C110

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x739620
#define CInvSlot__SliderComplete_x                                 0x737380
#define CInvSlot__GetItemBase_x                                    0x736D00
#define CInvSlot__UpdateItem_x                                     0x736E70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73DA60
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73CD30
#define CInvSlotWnd__HandleLButtonUp_x                             0x73D5E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FA280
#define CItemDisplayWnd__UpdateStrings_x                           0x74BD10
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x745CA0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7461B0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74C330
#define CItemDisplayWnd__AboutToShow_x                             0x74B960
#define CItemDisplayWnd__WndNotification_x                         0x74D880

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x831AA0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7519E0

// CLabel 
#define CLabel__Draw_x                                             0x757560

// CListWnd
#define CListWnd__CListWnd_x                                       0x905880
#define CListWnd__dCListWnd_x                                      0x905BA0
#define CListWnd__AddColumn_x                                      0x909ED0
#define CListWnd__AddColumn1_x                                     0x909F20
#define CListWnd__AddLine_x                                        0x90A2B0
#define CListWnd__AddString_x                                      0x90A0B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x909C90
#define CListWnd__CalculateVSBRange_x                              0x909A70
#define CListWnd__ClearSel_x                                       0x90AA90
#define CListWnd__ClearAllSel_x                                    0x90AAF0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90B520
#define CListWnd__Compare_x                                        0x9093B0
#define CListWnd__Draw_x                                           0x905CA0
#define CListWnd__DrawColumnSeparators_x                           0x908480
#define CListWnd__DrawHeader_x                                     0x9088F0
#define CListWnd__DrawItem_x                                       0x908CF0
#define CListWnd__DrawLine_x                                       0x9085F0
#define CListWnd__DrawSeparator_x                                  0x908520
#define CListWnd__EnableLine_x                                     0x907D50
#define CListWnd__EnsureVisible_x                                  0x90B440
#define CListWnd__ExtendSel_x                                      0x90A9C0
#define CListWnd__GetColumnMinWidth_x                              0x907890
#define CListWnd__GetColumnWidth_x                                 0x907800
#define CListWnd__GetCurSel_x                                      0x907190
#define CListWnd__GetItemAtPoint_x                                 0x907FD0
#define CListWnd__GetItemAtPoint1_x                                0x908040
#define CListWnd__GetItemData_x                                    0x907210
#define CListWnd__GetItemHeight_x                                  0x9075D0
#define CListWnd__GetItemIcon_x                                    0x9073A0
#define CListWnd__GetItemRect_x                                    0x907E40
#define CListWnd__GetItemText_x                                    0x907250
#define CListWnd__GetSelList_x                                     0x90AB40
#define CListWnd__GetSeparatorRect_x                               0x908280
#define CListWnd__InsertLine_x                                     0x90A6A0
#define CListWnd__RemoveLine_x                                     0x90A7F0
#define CListWnd__SetColors_x                                      0x909A40
#define CListWnd__SetColumnJustification_x                         0x909770
#define CListWnd__SetColumnWidth_x                                 0x909690
#define CListWnd__SetCurSel_x                                      0x90A900
#define CListWnd__SetItemColor_x                                   0x90B0F0
#define CListWnd__SetItemData_x                                    0x90B0B0
#define CListWnd__SetItemText_x                                    0x90ACC0
#define CListWnd__ShiftColumnSeparator_x                           0x909830
#define CListWnd__Sort_x                                           0x909530
#define CListWnd__ToggleSel_x                                      0x90A930

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76C960
#define CMapViewWnd__GetWorldCoordinates_x                         0x76B070
#define CMapViewWnd__HandleLButtonDown_x                           0x7680D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78FCD0
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7905B0
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x790AE0
#define CMerchantWnd__SelectRecoverySlot_x                         0x793920
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78E6B0
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x799510
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78F910

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x899A60
#define CPacketScrambler__hton_x                                   0x899A50

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x924880
#define CSidlManager__FindScreenPieceTemplate_x                    0x924C90
#define CSidlManager__FindScreenPieceTemplate1_x                   0x924A80
#define CSidlManager__CreateLabel_x                                0x7F1700
#define CSidlManager__CreateXWndFromTemplate_x                     0x927D60
#define CSidlManager__CreateXWndFromTemplate1_x                    0x927F40
#define CSidlManager__CreateXWnd_x                                 0x7F1630
#define CSidlManager__CreateHotButtonWnd_x                         0x7F1BF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9213F0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9212F0
#define CSidlScreenWnd__ConvertToRes_x                             0x946520
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x920D80
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x920A70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x920B40
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x920C10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x921890
#define CSidlScreenWnd__EnableIniStorage_x                         0x921D60
#define CSidlScreenWnd__GetSidlPiece_x                             0x921A80
#define CSidlScreenWnd__Init1_x                                    0x920660
#define CSidlScreenWnd__LoadIniInfo_x                              0x921DB0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9228F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91FA70
#define CSidlScreenWnd__StoreIniInfo_x                             0x922470
#define CSidlScreenWnd__StoreIniVis_x                              0x9227D0
#define CSidlScreenWnd__WndNotification_x                          0x9217A0
#define CSidlScreenWnd__GetChildItem_x                             0x921CE0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9113D0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B9388

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66B640
#define CSkillMgr__GetSkillCap_x                                   0x66B820
#define CSkillMgr__GetNameToken_x                                  0x66ADD0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x931840
#define CSliderWnd__SetValue_x                                     0x9316B0
#define CSliderWnd__SetNumTicks_x                                  0x931710

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F74F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x938580
#define CStmlWnd__CalculateHSBRange_x                              0x939610
#define CStmlWnd__CalculateVSBRange_x                              0x939580
#define CStmlWnd__CanBreakAtCharacter_x                            0x93D980
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93E610
#define CStmlWnd__ForceParseNow_x                                  0x938B20
#define CStmlWnd__GetNextTagPiece_x                                0x93D8E0
#define CStmlWnd__GetSTMLText_x                                    0x4F5A70
#define CStmlWnd__GetVisibleText_x                                 0x938B40
#define CStmlWnd__InitializeWindowVariables_x                      0x93E460
#define CStmlWnd__MakeStmlColorTag_x                               0x937C60
#define CStmlWnd__MakeWndNotificationTag_x                         0x937CD0
#define CStmlWnd__SetSTMLText_x                                    0x936D10
#define CStmlWnd__StripFirstSTMLLines_x                            0x93F770
#define CStmlWnd__UpdateHistoryString_x                            0x93E820

// CTabWnd 
#define CTabWnd__Draw_x                                            0x943410
#define CTabWnd__DrawCurrentPage_x                                 0x943A30
#define CTabWnd__DrawTab_x                                         0x943800
#define CTabWnd__GetCurrentPage_x                                  0x942C70
#define CTabWnd__GetPageInnerRect_x                                0x942EB0
#define CTabWnd__GetTabInnerRect_x                                 0x942DF0
#define CTabWnd__GetTabRect_x                                      0x942CA0
#define CTabWnd__InsertPage_x                                      0x9430A0
#define CTabWnd__SetPage_x                                         0x942F30
#define CTabWnd__SetPageRect_x                                     0x943350
#define CTabWnd__UpdatePage_x                                      0x9436C0
#define CTabWnd__GetPageFromTabIndex_x                             0x943740
#define CTabWnd__GetCurrentTabIndex_x                              0x942C60

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x751E40
#define CPageWnd__SetTabText_x                                     0x94FB40

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6740

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90E210
#define CTextureFont__GetTextExtent_x                              0x90E3D0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69EFD0
#define CHtmlComponentWnd__ValidateUri_x                           0x730A60
#define CHtmlWnd__SetClientCallbacks_x                             0x60C0D0
#define CHtmlWnd__AddObserver_x                                    0x60C0F0
#define CHtmlWnd__RemoveObserver_x                                 0x60C150
#define Window__getProgress_x                                      0x84A5F0
#define Window__getStatus_x                                        0x84A610
#define Window__getURI_x                                           0x84A620

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94C0C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FB1C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADF20
#define CXStr__CXStr1_x                                            0x4F0C00
#define CXStr__CXStr3_x                                            0x8E7390
#define CXStr__dCXStr_x                                            0x473060
#define CXStr__operator_equal_x                                    0x8E75C0
#define CXStr__operator_equal1_x                                   0x8E7600
#define CXStr__operator_plus_equal1_x                              0x8E8090

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92FAA0
#define CXWnd__BringToTop_x                                        0x914C00
#define CXWnd__Center_x                                            0x914780
#define CXWnd__ClrFocus_x                                          0x9145B0
#define CXWnd__Destroy_x                                           0x914660
#define CXWnd__DoAllDrawing_x                                      0x910B60
#define CXWnd__DrawChildren_x                                      0x910B30
#define CXWnd__DrawColoredRect_x                                   0x910FC0
#define CXWnd__DrawTooltip_x                                       0x90F680
#define CXWnd__DrawTooltipAtPoint_x                                0x90F740
#define CXWnd__GetBorderFrame_x                                    0x910E20
#define CXWnd__GetChildWndAt_x                                     0x914CA0
#define CXWnd__GetClientClipRect_x                                 0x912E50
#define CXWnd__GetScreenClipRect_x                                 0x912F20
#define CXWnd__GetScreenRect_x                                     0x9130C0
#define CXWnd__GetTooltipRect_x                                    0x911010
#define CXWnd__GetWindowTextA_x                                    0x497D50
#define CXWnd__IsActive_x                                          0x917B60
#define CXWnd__IsDescendantOf_x                                    0x913AD0
#define CXWnd__IsReallyVisible_x                                   0x913B00
#define CXWnd__IsType_x                                            0x915300
#define CXWnd__Move_x                                              0x913B70
#define CXWnd__Move1_x                                             0x913C20
#define CXWnd__ProcessTransition_x                                 0x914730
#define CXWnd__Refade_x                                            0x913F00
#define CXWnd__Resize_x                                            0x9141D0
#define CXWnd__Right_x                                             0x9149C0
#define CXWnd__SetFocus_x                                          0x914570
#define CXWnd__SetFont_x                                           0x9145E0
#define CXWnd__SetKeyTooltip_x                                     0x915130
#define CXWnd__SetMouseOver_x                                      0x911FA0
#define CXWnd__StartFade_x                                         0x9139B0
#define CXWnd__GetChildItem_x                                      0x914E10
#define CXWnd__SetParent_x                                         0x913880

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9475F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x917BA0
#define CXWndManager__DrawWindows_x                                0x917BC0
#define CXWndManager__GetKeyboardFlags_x                           0x91A320
#define CXWndManager__HandleKeyboardMsg_x                          0x919F20
#define CXWndManager__RemoveWnd_x                                  0x91A570
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91AAA0

// CDBStr
#define CDBStr__GetString_x                                        0x52D790

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9050
#define EQ_Character__Cur_HP_x                                     0x4CF280
#define EQ_Character__Cur_Mana_x                                   0x4D69B0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BBF70
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFAE0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFC30
#define EQ_Character__GetHPRegen_x                                 0x4DC930
#define EQ_Character__GetEnduranceRegen_x                          0x4DCF40
#define EQ_Character__GetManaRegen_x                               0x4DD380
#define EQ_Character__Max_Endurance_x                              0x631DA0
#define EQ_Character__Max_HP_x                                     0x4CF0B0
#define EQ_Character__Max_Mana_x                                   0x631BA0
#define EQ_Character__doCombatAbility_x                            0x634270
#define EQ_Character__UseSkill_x                                   0x4DF190
#define EQ_Character__GetConLevel_x                                0x62B4B0
#define EQ_Character__IsExpansionFlag_x                            0x591B50
#define EQ_Character__TotalEffect_x                                0x4C2600
#define EQ_Character__GetPCSpellAffect_x                           0x4BCB60
#define EQ_Character__SpellDuration_x                              0x4BC690
#define EQ_Character__FindItemByRecord_x                           0x4D4890
#define EQ_Character__GetAdjustedSkill_x                           0x4D1FC0
#define EQ_Character__GetBaseSkill_x                               0x4D2F60
#define EQ_Character__CanUseItem_x                                 0x4D6CC0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B8AE0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x648110

//PcClient
#define PcClient__PcClient_x                                       0x628BE0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6CC0
#define CCharacterListWnd__EnterWorld_x                            0x4B6700
#define CCharacterListWnd__Quit_x                                  0x4B6410
#define CCharacterListWnd__UpdateList_x                            0x4B6890

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60D300
#define EQ_Item__CreateItemTagString_x                             0x8933A0
#define EQ_Item__IsStackable_x                                     0x897E00
#define EQ_Item__GetImageNum_x                                     0x894E10
#define EQ_Item__CreateItemClient_x                                0x60C4B0
#define EQ_Item__GetItemValue_x                                    0x896070
#define EQ_Item__ValueSellMerchant_x                               0x8995F0
#define EQ_Item__IsKeyRingItem_x                                   0x897750
#define EQ_Item__CanGoInBag_x                                      0x60D420
#define EQ_Item__GetMaxItemCount_x                                 0x896440
#define EQ_Item__GetHeldItem_x                                     0x894CE0
#define EQ_Item__GetAugmentFitBySlot_x                             0x892CD0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54BB00
#define EQ_LoadingS__Array_x                                       0xBEE130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x632700
#define EQ_PC__GetAlternateAbilityId_x                             0x8A2810
#define EQ_PC__GetCombatAbility_x                                  0x8A2E80
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A2EF0
#define EQ_PC__GetItemRecastTimer_x                                0x6347F0
#define EQ_PC__HasLoreItem_x                                       0x62BCD0
#define EQ_PC__AlertInventoryChanged_x                             0x62ADE0
#define EQ_PC__GetPcZoneClient_x                                   0x656900
#define EQ_PC__RemoveMyAffect_x                                    0x6379E0
#define EQ_PC__GetKeyRingItems_x                                   0x8A3790
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A3510
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A3A80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x597FD0
#define EQItemList__add_object_x                                   0x5C3980
#define EQItemList__add_item_x                                     0x5985E0
#define EQItemList__delete_item_x                                  0x598630
#define EQItemList__FreeItemList_x                                 0x598530

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52AC90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x649990
#define EQPlayer__dEQPlayer_x                                      0x63D050
#define EQPlayer__DoAttack_x                                       0x6515C0
#define EQPlayer__EQPlayer_x                                       0x63D700
#define EQPlayer__SetNameSpriteState_x                             0x6419C0
#define EQPlayer__SetNameSpriteTint_x                              0x642890
#define PlayerBase__HasProperty_j_x                                0x97A3C0
#define EQPlayer__IsTargetable_x                                   0x97A860
#define EQPlayer__CanSee_x                                         0x97A6C0
#define EQPlayer__CanSee1_x                                        0x97A790
#define PlayerBase__GetVisibilityLineSegment_x                     0x97A480

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x654390
#define PlayerZoneClient__GetLevel_x                               0x656940
#define PlayerZoneClient__IsValidTeleport_x                        0x5C4AD0
#define PlayerZoneClient__LegalPlayerRace_x                        0x544F30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64C700
#define EQPlayerManager__GetSpawnByName_x                          0x64C720
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64C7B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x610C80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x610CC0
#define KeypressHandler__ClearCommandStateArray_x                  0x6120B0
#define KeypressHandler__HandleKeyDown_x                           0x6120D0
#define KeypressHandler__HandleKeyUp_x                             0x612170
#define KeypressHandler__SaveKeymapping_x                          0x612550

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7687F0
#define MapViewMap__SaveEx_x                                       0x76BB90
#define MapViewMap__SetZoom_x                                      0x770260

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B6920

// StringTable 
#define StringTable__getString_x                                   0x8B19C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x637650
#define PcZoneClient__RemovePetEffect_x                            0x637C80
#define PcZoneClient__HasAlternateAbility_x                        0x6319E0
#define PcZoneClient__GetCurrentMod_x                              0x4E2280
#define PcZoneClient__GetModCap_x                                  0x4E2180
#define PcZoneClient__CanEquipItem_x                               0x632090
#define PcZoneClient__GetItemByID_x                                0x634C60
#define PcZoneClient__GetItemByItemClass_x                         0x634DB0
#define PcZoneClient__RemoveBuffEffect_x                           0x637CA0
#define PcZoneClient__BandolierSwap_x                              0x632CC0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C9780

//IconCache
#define IconCache__GetIcon_x                                       0x7094C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x700F90
#define CContainerMgr__CloseContainer_x                            0x701260
#define CContainerMgr__OpenExperimentContainer_x                   0x701CE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C3C70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x605560

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75ECE0
#define CLootWnd__RequestLootSlot_x                                0x75E090

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5642A0
#define EQ_Spell__SpellAffects_x                                   0x564710
#define EQ_Spell__SpellAffectBase_x                                0x5644D0
#define EQ_Spell__IsStackable_x                                    0x4C6E50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6CD0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4010
#define EQ_Spell__IsSPAStacking_x                                  0x565540
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x564A60
#define EQ_Spell__IsNoRemove_x                                     0x4C6E30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x565550
#define __IsResEffectSpell_x                                       0x4C6160

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA920

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C0F90

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x809660
#define CTargetWnd__WndNotification_x                              0x808EF0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8091C0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x808040

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80DD30

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x528640
#define CTaskManager__HandleMessage_x                              0x526DA0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55F820
#define EqSoundManager__PlayScriptMp3_x                            0x55F980
#define EqSoundManager__SoundAssistPlay_x                          0x66F4B0
#define EqSoundManager__WaveInstancePlay_x                         0x66EA20

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51C650

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x933220

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5538B0
#define CAltAbilityData__GetMercMaxRank_x                          0x553850
#define CAltAbilityData__GetMaxRank_x                              0x548C10

//CTargetRing
#define CTargetRing__Cast_x                                        0x603660

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6CB0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5029A0
#define CharacterBase__CreateItemIndex_x                           0x60B710
#define CharacterBase__GetItemPossession_x                         0x4B3EC0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C9620
#define CharacterBase__GetEffectId_x                               0x4C6C60

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E9070
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E9890

//messages
#define msg_spell_worn_off_x                                       0x589B90
#define msg_new_text_x                                             0x57E9B0
#define __msgTokenTextParam_x                                      0x58C200
#define msgTokenText_x                                             0x58C450

//SpellManager
#define SpellManager__vftable_x                                    0xAB5A90
#define SpellManager__SpellManager_x                               0x6727E0
#define Spellmanager__LoadTextSpells_x                             0x6730B0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6729B0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97E330

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x503060
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x590010
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6243E0
#define ItemGlobalIndex__IsValidIndex_x                            0x5030C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C18D0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C1B50

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7578A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7056E0
#define CCursorAttachment__Deactivate_x                            0x7066C0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9459F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9456B0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FFFE0

//IString
#define IString__Append_x                                          0x4EFCC0

//Camera
#define CDisplay__cameraType_x                                     0xDC7B38
#define EverQuest__Cameras_x                                       0xE8A840

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5086E0
#define LootFiltersManager__GetItemFilterData_x                    0x507FD0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x508000
#define LootFiltersManager__SetItemLootFilter_x                    0x508220

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B1C60

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x984070
#define CResolutionHandler__GetWindowedStyle_x                     0x66A160

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FDD50

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3FE0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71DE50
#define CGroupWnd__UpdateDisplay_x                                 0x71D1B0

//ItemBase
#define ItemBase__IsLore_x                                         0x8977B0
#define ItemBase__IsLoreEquipped_x                                 0x897820

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F6070

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C3870
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C3A20
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C3A80

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65F410
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x663070

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
