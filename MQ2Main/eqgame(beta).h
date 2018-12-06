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
#define __ExpectedVersionDate                                     "Dec  6 2018"
#define __ExpectedVersionTime                                     "04:20:54"
#define __ActualVersionDate_x                                      0xAD21B4
#define __ActualVersionTime_x                                      0xAD21A8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x616D70
#define __MemChecker1_x                                            0x8EBBF0
#define __MemChecker2_x                                            0x6A6370
#define __MemChecker3_x                                            0x6A62C0
#define __MemChecker4_x                                            0x8430F0
#define __EncryptPad0_x                                            0xC06340
#define __EncryptPad1_x                                            0xC645D0
#define __EncryptPad2_x                                            0xC16EC8
#define __EncryptPad3_x                                            0xC16AC8
#define __EncryptPad4_x                                            0xC54E40
#define __EncryptPad5_x                                            0x1035AE0
#define __AC1_x                                                    0x7FF826
#define __AC2_x                                                    0x5D188F
#define __AC3_x                                                    0x5D871F
#define __AC4_x                                                    0x5DC540
#define __AC5_x                                                    0x5E27B0
#define __AC6_x                                                    0x5E6D86
#define __AC7_x                                                    0x5D1300
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
#define __do_loot_x                                                0x59ED90
#define __DrawHandler_x                                            0x16BA440
#define __GroupCount_x                                             0xE79452
#define __Guilds_x                                                 0xE7F9B0
#define __gWorld_x                                                 0xE7BCC0
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
#define __ScreenMode_x                                             0xDC7A98
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
#define __gfMaxZoomCameraDistance_x                                0xAC7680
#define __gfMaxCameraDistance_x                                    0xAF4AE0
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
#define pinstCamActor_x                                            0xDC7A8C
#define pinstCDBStr_x                                              0xDC7424
#define pinstCDisplay_x                                            0xE7BAB4
#define pinstCEverQuest_x                                          0x1035C20
#define pinstEverQuestInfo_x                                       0xE89138
#define pinstCharData_x                                            0xE7BCC8
#define pinstCharSpawn_x                                           0xE7B89C
#define pinstControlledMissile_x                                   0xE7BCC4
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
#define pinstPCData_x                                              0xE7BCC8
#define pinstRealEstateItems_x                                     0xF2A608
#define pinstSkillMgr_x                                            0xF2A6D8
#define pinstSpawnManager_x                                        0xF29CC8
#define pinstSpellManager_x                                        0xF2A8B0
#define pinstSpellSets_x                                           0xF20AEC
#define pinstStringTable_x                                         0xE7B648
#define pinstSwitchManager_x                                       0xE792E8
#define pinstTarget_x                                              0xE7B898
#define pinstTargetObject_x                                        0xE7B8A4
#define pinstTargetSwitch_x                                        0xE7BCE8
#define pinstTaskMember_x                                          0xDC71F4
#define pinstTrackTarget_x                                         0xE7B8A0
#define pinstTradeTarget_x                                         0xE7B858
#define instTributeActive_x                                        0xDC7385
#define pinstViewActor_x                                           0xDC7A88
#define pinstWorldData_x                                           0xE7B764
#define pinstZoneAddr_x                                            0xE896B8
#define pinstPlayerPath_x                                          0xF29D60
#define pinstTargetIndicator_x                                     0xF2AB18
#define pinstCTargetManager_x                                      0xF2ABB0
#define EQObject_Top_x                                             0xE7B804

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC7548
#define pinstCAchievementsWnd_x                                    0xDC7538
#define pinstCActionsWnd_x                                         0xDC75AC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC7A4C
#define pinstCAdvancedLootWnd_x                                    0xDC7590
#define pinstCAdventureLeaderboardWnd_x                            0x1037240
#define pinstCAdventureRequestWnd_x                                0x10372F0
#define pinstCAdventureStatsWnd_x                                  0x10373A0
#define pinstCAggroMeterWnd_x                                      0xDC7ACC
#define pinstCAlarmWnd_x                                           0xDC7B3C
#define pinstCAlertHistoryWnd_x                                    0xDC74F4
#define pinstCAlertStackWnd_x                                      0xDC7AE0
#define pinstCAlertWnd_x                                           0xDC7B04
#define pinstCAltStorageWnd_x                                      0x1037700
#define pinstCAudioTriggersWindow_x                                0xC7B298
#define pinstCAuraWnd_x                                            0xDC7AC8
#define pinstCAvaZoneWnd_x                                         0xDC74F8
#define pinstCBandolierWnd_x                                       0xDC7B0C
#define pinstCBankWnd_x                                            0xDC74F0
#define pinstCBarterMerchantWnd_x                                  0x1038940
#define pinstCBarterSearchWnd_x                                    0x10389F0
#define pinstCBarterWnd_x                                          0x1038AA0
#define pinstCBazaarConfirmationWnd_x                              0xDC7ADC
#define pinstCBazaarSearchWnd_x                                    0xDC7634
#define pinstCBazaarWnd_x                                          0xDC7B10
#define pinstCBlockedBuffWnd_x                                     0xDC74D4
#define pinstCBlockedPetBuffWnd_x                                  0xDC7504
#define pinstCBodyTintWnd_x                                        0xDC7AB0
#define pinstCBookWnd_x                                            0xDC7B30
#define pinstCBreathWnd_x                                          0xDC754C
#define pinstCBuffWindowNORMAL_x                                   0xDC7D4C
#define pinstCBuffWindowSHORT_x                                    0xDC7D50
#define pinstCBugReportWnd_x                                       0xDC7540
#define pinstCButtonWnd_x                                          0x16B9728
#define pinstCCastingWnd_x                                         0xDC753C
#define pinstCCastSpellWnd_x                                       0xDC7A48
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC7550
#define pinstCChatWindowManager_x                                  0x1039560
#define pinstCClaimWnd_x                                           0x10396B8
#define pinstCColorPickerWnd_x                                     0xDC757C
#define pinstCCombatAbilityWnd_x                                   0xDC7AD8
#define pinstCCombatSkillsSelectWnd_x                              0xDC75A4
#define pinstCCompassWnd_x                                         0xDC7A80
#define pinstCConfirmationDialog_x                                 0x103E5B8
#define pinstCContainerMgr_x                                       0xDC7AE4
#define pinstCContextMenuManager_x                                 0x16B94B8
#define pinstCCursorAttachment_x                                   0xDC7534
#define pinstCDistillerInfo_x                                      0x103CFC4
#define pinstCDynamicZoneWnd_x                                     0x1039C80
#define pinstCEditLabelWnd_x                                       0xDC7D40
#define pinstCEQMainWnd_x                                          0x1039EC8
#define pinstCEventCalendarWnd_x                                   0xDC7568
#define pinstCExtendedTargetWnd_x                                  0xDC7ABC
#define pinstCFacePick_x                                           0xDC7574
#define pinstCFactionWnd_x                                         0xDC7530
#define pinstCFellowshipWnd_x                                      0x103A0C8
#define pinstCFileSelectionWnd_x                                   0xDC7584
#define pinstCFindItemWnd_x                                        0xDC7B2C
#define pinstCFindLocationWnd_x                                    0x103A220
#define pinstCFriendsWnd_x                                         0xDC75CC
#define pinstCGemsGameWnd_x                                        0xDC7B08
#define pinstCGiveWnd_x                                            0xDC7B34
#define pinstCGroupSearchFiltersWnd_x                              0xDC7AEC
#define pinstCGroupSearchWnd_x                                     0x103A618
#define pinstCGroupWnd_x                                           0x103A6C8
#define pinstCGuildBankWnd_x                                       0xE8A4FC
#define pinstCGuildCreationWnd_x                                   0x103A828
#define pinstCGuildMgmtWnd_x                                       0x103A8D8
#define pinstCharacterCreation_x                                   0xDC7AD0
#define pinstCHelpWnd_x                                            0xDC7A7C
#define pinstCHeritageSelectionWnd_x                               0xDC7588
#define pinstCHotButtonWnd_x                                       0x103CA30
#define pinstCHotButtonWnd1_x                                      0x103CA30
#define pinstCHotButtonWnd2_x                                      0x103CA34
#define pinstCHotButtonWnd3_x                                      0x103CA38
#define pinstCHotButtonWnd4_x                                      0x103CA3C
#define pinstCIconSelectionWnd_x                                   0xDC7514
#define pinstCInspectWnd_x                                         0xDC7510
#define pinstCInventoryWnd_x                                       0xDC7B14
#define pinstCInvSlotMgr_x                                         0xDC7AA4
#define pinstCItemDisplayManager_x                                 0x103CFC0
#define pinstCItemExpTransferWnd_x                                 0x103D0F0
#define pinstCItemFuseWnd_x                                        0xDC7528
#define pinstCItemOverflowWnd_x                                    0xDC7638
#define pinstCJournalCatWnd_x                                      0xDC759C
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDC7560
#define pinstCKeyRingWnd_x                                         0xDC74CC
#define pinstCLargeDialogWnd_x                                     0x103F238
#define pinstCLayoutCopyWnd_x                                      0x103D440
#define pinstCLFGuildWnd_x                                         0x103D4F0
#define pinstCLoadskinWnd_x                                        0xDC7B20
#define pinstCLootFiltersCopyWnd_x                                 0xC972B8
#define pinstCLootFiltersWnd_x                                     0xDC7B28
#define pinstCLootSettingsWnd_x                                    0xDC7D48
#define pinstCLootWnd_x                                            0xDC756C
#define pinstCMailAddressBookWnd_x                                 0xDC7508
#define pinstCMailCompositionWnd_x                                 0xDC74E0
#define pinstCMailIgnoreListWnd_x                                  0xDC750C
#define pinstCMailWnd_x                                            0xDC74C0
#define pinstCManageLootWnd_x                                      0xDC8B68
#define pinstCMapToolbarWnd_x                                      0xDC7B1C
#define pinstCMapViewWnd_x                                         0xDC7AF4
#define pinstCMarketplaceWnd_x                                     0xDC7570
#define pinstCMerchantWnd_x                                        0xDC75A0
#define pinstCMIZoneSelectWnd_x                                    0x103DD28
#define pinstCMusicPlayerWnd_x                                     0xDC74C8
#define pinstCNameChangeMercWnd_x                                  0xDC7AB4
#define pinstCNameChangePetWnd_x                                   0xDC7A74
#define pinstCNameChangeWnd_x                                      0xDC7554
#define pinstCNoteWnd_x                                            0xDC7A54
#define pinstCObjectPreviewWnd_x                                   0xDC7594
#define pinstCOptionsWnd_x                                         0xDC7B24
#define pinstCPetInfoWnd_x                                         0xDC74E4
#define pinstCPetitionQWnd_x                                       0xDC75B4
//#define pinstCPlayerCustomizationWnd_x                           0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC7AAC
#define pinstCPlayerWnd_x                                          0xDC75B0
#define pinstCPopupWndManager_x                                    0x103E5B8
#define pinstCProgressionSelectionWnd_x                            0x103E668
#define pinstCPurchaseGroupWnd_x                                   0xDC7A40
#define pinstCPurchaseWnd_x                                        0xDC75A8
#define pinstCPvPLeaderboardWnd_x                                  0x103E718
#define pinstCPvPStatsWnd_x                                        0x103E7C8
#define pinstCQuantityWnd_x                                        0xDC751C
#define pinstCRaceChangeWnd_x                                      0xDC7578
#define pinstCRaidOptionsWnd_x                                     0xDC7AF0
#define pinstCRaidWnd_x                                            0xDC7520
#define pinstCRealEstateItemsWnd_x                                 0xDC7544
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC7564
#define pinstCRealEstateManageWnd_x                                0xDC7D54
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC74D0
#define pinstCRealEstatePlotSearchWnd_x                            0xDC74FC
#define pinstCRealEstatePurchaseWnd_x                              0xDC7524
#define pinstCRespawnWnd_x                                         0xDC7AE8
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDC7AC0
#define pinstCSendMoneyWnd_x                                       0xDC7D44
#define pinstCServerListWnd_x                                      0xDC74EC
#define pinstCSkillsSelectWnd_x                                    0xDC7580
#define pinstCSkillsWnd_x                                          0xDC755C
#define pinstCSocialEditWnd_x                                      0xDC752C
#define pinstCSocialWnd_x                                          0xDC7AC4
#define pinstCSpellBookWnd_x                                       0xDC7AB8
#define pinstCStoryWnd_x                                           0xDC7A50
#define pinstCTargetOfTargetWnd_x                                  0x10405F8
#define pinstCTargetWnd_x                                          0xDC74DC
#define pinstCTaskOverlayWnd_x                                     0xDC7500
#define pinstCTaskSelectWnd_x                                      0x1040750
#define pinstCTaskManager_x                                        0xC97AB8
#define pinstCTaskTemplateSelectWnd_x                              0x1040800
#define pinstCTaskWnd_x                                            0x10408B0
#define pinstCTextEntryWnd_x                                       0xDC7A84
#define pinstCTextOverlay_x                                        0xC7B5A8
#define pinstCTimeLeftWnd_x                                        0xDC758C
#define pinstCTipWndCONTEXT_x                                      0x1040AB4
#define pinstCTipWndOFDAY_x                                        0x1040AB0
#define pinstCTitleWnd_x                                           0x1040B60
#define pinstCTrackingWnd_x                                        0xDC74E8
#define pinstCTradeskillWnd_x                                      0x1040CC8
#define pinstCTradeWnd_x                                           0xDC7AA8
#define pinstCTrainWnd_x                                           0xDC7518
#define pinstCTributeBenefitWnd_x                                  0x1040EC8
#define pinstCTributeMasterWnd_x                                   0x1040F78
#define pinstCTributeTrophyWnd_x                                   0x1041028
#define pinstCVideoModesWnd_x                                      0xDC7AD4
#define pinstCVoiceMacroWnd_x                                      0xF2B0E0
#define pinstCVoteResultsWnd_x                                     0xDC7A44
#define pinstCVoteWnd_x                                            0xDC75B8
#define pinstCWebManager_x                                         0xF2B244
#define pinstCZoneGuideWnd_x                                       0xDC74C4
#define pinstCZonePathWnd_x                                        0xDC74D8

#define pinstEQSuiteTextureLoader_x                                0xC660A0
#define pinstItemIconCache_x                                       0x1039E80
#define pinstLootFiltersManager_x                                  0xC97368
#define pinstRewardSelectionWnd_x                                  0x103EF10

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC16ABC
#define __CastRay_x                                                0x59A2B0
#define __CastRay2_x                                               0x59A300
#define __ConvertItemTags_x                                        0x5B4F30
#define __CrashHandler_x                                           0x84CAA0
#define __EQGetTime_x                                              0x8EB6E0
#define __ExecuteCmd_x                                             0x592BE0
#define __FixHeading_x                                             0x97C5F0
#define __get_bearing_x                                            0x599E00
#define __get_melee_range_x                                        0x59A4F0
#define __GetAnimationCache_x                                      0x7099F0
#define __GetGaugeValueFromEQ_x                                    0x7FE030
#define __GetLabelFromEQ_x                                         0x7FF7B0
#define __GetXTargetType_x                                         0x97E050
#define __HeadingDiff_x                                            0x97C660
#define __HelpPath_x                                               0xF28594
#define __LoadFrontEnd_x                                           0x6A21D0
#define __NewUIINI_x                                               0x7FDD00
#define __pCrashHandler_x                                          0x105E418
#define __ProcessGameEvents_x                                      0x5F8090
#define __ProcessMouseEvent_x                                      0x5F7850
#define __SaveColors_x                                             0x542AC0
#define __STMLToText_x                                             0x91F5D0
#define __ToggleKeyRingItem_x                                      0x505DF0
#define CrashDetected_x                                            0x6A3CC0
#define DrawNetStatus_x                                            0x624400
#define Expansion_HoT_x                                            0xE8A504
#define Teleport_Table_Size_x                                      0xE7B800
#define Teleport_Table_x                                           0xE79640
#define Util__FastTime_x                                           0x8EB2A0
#define wwsCrashReportCheckForUploader_x                           0x84D550
#define wwsCrashReportPlatformLaunchUploader_x                     0x84FC40
#define __HandleMouseWheel_x                                       0x6A6420

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B640
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4944C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494280

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54A5D0
#define AltAdvManager__IsAbilityReady_x                            0x549520
#define AltAdvManager__GetAAById_x                                 0x549720
#define AltAdvManager__CanTrainAbility_x                           0x549790
#define AltAdvManager__CanSeeAbility_x                             0x549AF0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7600
#define CharacterZoneClient__HasSkill_x                            0x4D22D0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D39F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBA30
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B81A0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D63C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D64A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6580
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0510
#define CharacterZoneClient__BardCastBard_x                        0x4C3180
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8270
#define CharacterZoneClient__GetEffect_x                           0x4B80E0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1510
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C15E0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1630
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1780
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1950

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CBF60

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D9800

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6069B0
#define CButtonWnd__CButtonWnd_x                                   0x91B9C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F8380
#define CChatManager__InitContextMenu_x                            0x6F2420
#define CChatManager__FreeChatWindow_x                             0x6F7290
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FBCE0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F8120

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9301A0
#define CContextMenu__dCContextMenu_x                              0x9303D0
#define CContextMenu__AddMenuItem_x                                0x9303E0
#define CContextMenu__RemoveMenuItem_x                             0x9306F0
#define CContextMenu__RemoveAllMenuItems_x                         0x930710
#define CContextMenu__CheckMenuItem_x                              0x930790
#define CContextMenu__SetMenuItem_x                                0x930610
#define CContextMenu__AddSeparator_x                               0x930570

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x930D30
#define CContextMenuManager__RemoveMenu_x                          0x930DA0
#define CContextMenuManager__PopupMenu_x                           0x930E60
#define CContextMenuManager__Flush_x                               0x930CD0
#define CContextMenuManager__GetMenu_x                             0x4966E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CBF40
#define CChatService__GetFriendName_x                              0x8CBF50

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F88F0
#define CChatWindow__Clear_x                                       0x6F9940
#define CChatWindow__WndNotification_x                             0x6F9EB0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92D620
#define CComboWnd__Draw_x                                          0x92CB20
#define CComboWnd__GetCurChoice_x                                  0x92D460
#define CComboWnd__GetListRect_x                                   0x92CFD0
#define CComboWnd__GetTextRect_x                                   0x92D690
#define CComboWnd__InsertChoice_x                                  0x92D160
#define CComboWnd__SetColors_x                                     0x92D130
#define CComboWnd__SetChoice_x                                     0x92D430
#define CComboWnd__GetItemCount_x                                  0x92D470
#define CComboWnd__GetCurChoiceText_x                              0x92D4B0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x701BD0
#define CContainerWnd__vftable_x                                   0xADB458
#define CContainerWnd__SetContainer_x                              0x703140

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x542880
#define CDisplay__GetClickedActor_x                                0x535830
#define CDisplay__GetUserDefinedColor_x                            0x52DF10
#define CDisplay__GetWorldFilePath_x                               0x537280
#define CDisplay__is3dON_x                                         0x532500
#define CDisplay__ReloadUI_x                                       0x53C9A0
#define CDisplay__WriteTextHD2_x                                   0x5322E0
#define CDisplay__TrueDistance_x                                   0x538EE0
#define CDisplay__SetViewActor_x                                   0x535180
#define CDisplay__GetFloorHeight_x                                 0x5325C0
#define CDisplay__SetRenderWindow_x                                0x530EF0
#define CDisplay__ToggleScreenshotMode_x                           0x534C50

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94FDD0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9348A0
#define CEditWnd__GetCharIndexPt_x                                 0x9357A0
#define CEditWnd__GetDisplayString_x                               0x935640
#define CEditWnd__GetHorzOffset_x                                  0x933ED0
#define CEditWnd__GetLineForPrintableChar_x                        0x9369A0
#define CEditWnd__GetSelStartPt_x                                  0x935A50
#define CEditWnd__GetSTMLSafeText_x                                0x935460
#define CEditWnd__PointFromPrintableChar_x                         0x9365D0
#define CEditWnd__SelectableCharFromPoint_x                        0x936740
#define CEditWnd__SetEditable_x                                    0x935B20

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E62B0
#define CEverQuest__ClickedPlayer_x                                0x5D8500
#define CEverQuest__CreateTargetIndicator_x                        0x5F5340
#define CEverQuest__DeleteTargetIndicator_x                        0x5F53D0
#define CEverQuest__DoTellWindow_x                                 0x4E3490
#define CEverQuest__OutputTextToLog_x                              0x4E36C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5CDDC0
#define CEverQuest__dsp_chat_x                                     0x4E3A50
#define CEverQuest__trimName_x                                     0x5F16C0
#define CEverQuest__Emote_x                                        0x5E6AC0
#define CEverQuest__EnterZone_x                                    0x5E0B60
#define CEverQuest__GetBodyTypeDesc_x                              0x5EAF60
#define CEverQuest__GetClassDesc_x                                 0x5EB5A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EBBA0
#define CEverQuest__GetDeityDesc_x                                 0x5F3C90
#define CEverQuest__GetLangDesc_x                                  0x5EBD60
#define CEverQuest__GetRaceDesc_x                                  0x5EB580
#define CEverQuest__InterpretCmd_x                                 0x5F4260
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D1FB0
#define CEverQuest__LMouseUp_x                                     0x5D0330
#define CEverQuest__RightClickedOnPlayer_x                         0x5D2890
#define CEverQuest__RMouseUp_x                                     0x5D12C0
#define CEverQuest__SetGameState_x                                 0x5CDB50
#define CEverQuest__UPCNotificationFlush_x                         0x5F15C0
#define CEverQuest__IssuePetCommand_x                              0x5ED160
#define CEverQuest__ReportSuccessfulHit_x                          0x5E7EC0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x713A70
#define CGaugeWnd__CalcLinesFillRect_x                             0x713AD0
#define CGaugeWnd__Draw_x                                          0x713160

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACD60
#define CGuild__GetGuildName_x                                     0x4ABE40
#define CGuild__GetGuildIndex_x                                    0x4AC1D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72EE70

//CHotButton
#define CHotButton__SetButtonSize_x                                0x606D70

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73BE70
#define CInvSlotMgr__MoveItem_x                                    0x73AB80
#define CInvSlotMgr__SelectSlot_x                                  0x73BF40

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x739430
#define CInvSlot__SliderComplete_x                                 0x737190
#define CInvSlot__GetItemBase_x                                    0x736B00
#define CInvSlot__UpdateItem_x                                     0x736C70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73D890
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73CB60
#define CInvSlotWnd__HandleLButtonUp_x                             0x73D410

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FA1C0
#define CItemDisplayWnd__UpdateStrings_x                           0x74BB60
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x745A80
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x745FB0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74C170
#define CItemDisplayWnd__AboutToShow_x                             0x74B7B0
#define CItemDisplayWnd__WndNotification_x                         0x74D6C0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x831C50

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x751820

// CLabel 
#define CLabel__Draw_x                                             0x757300

// CListWnd
#define CListWnd__CListWnd_x                                       0x905C90
#define CListWnd__dCListWnd_x                                      0x905FB0
#define CListWnd__AddColumn_x                                      0x90A2B0
#define CListWnd__AddColumn1_x                                     0x90A300
#define CListWnd__AddLine_x                                        0x90A690
#define CListWnd__AddString_x                                      0x90A490
#define CListWnd__CalculateFirstVisibleLine_x                      0x90A080
#define CListWnd__CalculateVSBRange_x                              0x909E60
#define CListWnd__ClearSel_x                                       0x90AE70
#define CListWnd__ClearAllSel_x                                    0x90AED0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90B8D0
#define CListWnd__Compare_x                                        0x9097B0
#define CListWnd__Draw_x                                           0x9060B0
#define CListWnd__DrawColumnSeparators_x                           0x908880
#define CListWnd__DrawHeader_x                                     0x908CF0
#define CListWnd__DrawItem_x                                       0x9090F0
#define CListWnd__DrawLine_x                                       0x9089F0
#define CListWnd__DrawSeparator_x                                  0x908920
#define CListWnd__EnableLine_x                                     0x908160
#define CListWnd__EnsureVisible_x                                  0x90B800
#define CListWnd__ExtendSel_x                                      0x90ADA0
#define CListWnd__GetColumnMinWidth_x                              0x907CA0
#define CListWnd__GetColumnWidth_x                                 0x907C10
#define CListWnd__GetCurSel_x                                      0x9075A0
#define CListWnd__GetItemAtPoint_x                                 0x9083D0
#define CListWnd__GetItemAtPoint1_x                                0x908440
#define CListWnd__GetItemData_x                                    0x907620
#define CListWnd__GetItemHeight_x                                  0x9079E0
#define CListWnd__GetItemIcon_x                                    0x9077B0
#define CListWnd__GetItemRect_x                                    0x908250
#define CListWnd__GetItemText_x                                    0x907660
#define CListWnd__GetSelList_x                                     0x90AF20
#define CListWnd__GetSeparatorRect_x                               0x908680
#define CListWnd__InsertLine_x                                     0x90AA80
#define CListWnd__RemoveLine_x                                     0x90ABD0
#define CListWnd__SetColors_x                                      0x909E40
#define CListWnd__SetColumnJustification_x                         0x909B70
#define CListWnd__SetColumnWidth_x                                 0x909A90
#define CListWnd__SetCurSel_x                                      0x90ACE0
#define CListWnd__SetItemColor_x                                   0x90B4C0
#define CListWnd__SetItemData_x                                    0x90B480
#define CListWnd__SetItemText_x                                    0x90B0A0
#define CListWnd__ShiftColumnSeparator_x                           0x909C30
#define CListWnd__Sort_x                                           0x909930
#define CListWnd__ToggleSel_x                                      0x90AD10

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76C7D0
#define CMapViewWnd__GetWorldCoordinates_x                         0x76AEE0
#define CMapViewWnd__HandleLButtonDown_x                           0x767F40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78FBC0
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7904A0
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7909E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x793820
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78E5A0
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x799420
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78F7F0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x899D60
#define CPacketScrambler__hton_x                                   0x899D50

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x924BB0
#define CSidlManager__FindScreenPieceTemplate_x                    0x924FC0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x924DB0
#define CSidlManager__CreateLabel_x                                0x7F15C0
#define CSidlManager__CreateXWndFromTemplate_x                     0x928090
#define CSidlManager__CreateXWndFromTemplate1_x                    0x928270
#define CSidlManager__CreateXWnd_x                                 0x7F14F0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F1AC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x921720
#define CSidlScreenWnd__CalculateVSBRange_x                        0x921620
#define CSidlScreenWnd__ConvertToRes_x                             0x946C20
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9210B0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x920DA0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x920E70
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x920F40
#define CSidlScreenWnd__DrawSidlPiece_x                            0x921BC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x922090
#define CSidlScreenWnd__GetSidlPiece_x                             0x921DB0
#define CSidlScreenWnd__Init1_x                                    0x9209B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9220E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x922C20
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91FDB0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9227A0
#define CSidlScreenWnd__StoreIniVis_x                              0x922B00
#define CSidlScreenWnd__WndNotification_x                          0x921AD0
#define CSidlScreenWnd__GetChildItem_x                             0x922010
#define CSidlScreenWnd__HandleLButtonUp_x                          0x911750
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B9388

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66B420
#define CSkillMgr__GetSkillCap_x                                   0x66B600
#define CSkillMgr__GetNameToken_x                                  0x66ABB0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x931B20
#define CSliderWnd__SetValue_x                                     0x931990
#define CSliderWnd__SetNumTicks_x                                  0x9319F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F73F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x938900
#define CStmlWnd__CalculateHSBRange_x                              0x9399D0
#define CStmlWnd__CalculateVSBRange_x                              0x939950
#define CStmlWnd__CanBreakAtCharacter_x                            0x93DD40
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93E9D0
#define CStmlWnd__ForceParseNow_x                                  0x938EF0
#define CStmlWnd__GetNextTagPiece_x                                0x93DCA0
#define CStmlWnd__GetSTMLText_x                                    0x4F53C0
#define CStmlWnd__GetVisibleText_x                                 0x938F10
#define CStmlWnd__InitializeWindowVariables_x                      0x93E820
#define CStmlWnd__MakeStmlColorTag_x                               0x937FE0
#define CStmlWnd__MakeWndNotificationTag_x                         0x938050
#define CStmlWnd__SetSTMLText_x                                    0x937090
#define CStmlWnd__StripFirstSTMLLines_x                            0x93FB20
#define CStmlWnd__UpdateHistoryString_x                            0x93EBE0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9437A0
#define CTabWnd__DrawCurrentPage_x                                 0x943DC0
#define CTabWnd__DrawTab_x                                         0x943B90
#define CTabWnd__GetCurrentPage_x                                  0x943000
#define CTabWnd__GetPageInnerRect_x                                0x943240
#define CTabWnd__GetTabInnerRect_x                                 0x943180
#define CTabWnd__GetTabRect_x                                      0x943030
#define CTabWnd__InsertPage_x                                      0x943430
#define CTabWnd__SetPage_x                                         0x9432C0
#define CTabWnd__SetPageRect_x                                     0x9436E0
#define CTabWnd__UpdatePage_x                                      0x943A50
#define CTabWnd__GetPageFromTabIndex_x                             0x943AD0
#define CTabWnd__GetCurrentTabIndex_x                              0x942FF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x751C80
#define CPageWnd__SetTabText_x                                     0x9501E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A68C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90E5B0
#define CTextureFont__GetTextExtent_x                              0x90E770

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69F020
#define CHtmlComponentWnd__ValidateUri_x                           0x730860
#define CHtmlWnd__SetClientCallbacks_x                             0x60BD40
#define CHtmlWnd__AddObserver_x                                    0x60BD60
#define CHtmlWnd__RemoveObserver_x                                 0x60BDC0
#define Window__getProgress_x                                      0x84A710
#define Window__getStatus_x                                        0x84A730
#define Window__getURI_x                                           0x84A740

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94C710

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FB410

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AE000
#define CXStr__CXStr1_x                                            0x4B3A10
#define CXStr__CXStr3_x                                            0x8E7810
#define CXStr__dCXStr_x                                            0x472FC0
#define CXStr__operator_equal_x                                    0x8E7A40
#define CXStr__operator_equal1_x                                   0x8E7A80
#define CXStr__operator_plus_equal1_x                              0x8E8510

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92FDB0
#define CXWnd__BringToTop_x                                        0x914F30
#define CXWnd__Center_x                                            0x914AB0
#define CXWnd__ClrFocus_x                                          0x9148E0
#define CXWnd__Destroy_x                                           0x914990
#define CXWnd__DoAllDrawing_x                                      0x910EE0
#define CXWnd__DrawChildren_x                                      0x910EB0
#define CXWnd__DrawColoredRect_x                                   0x911340
#define CXWnd__DrawTooltip_x                                       0x90FA20
#define CXWnd__DrawTooltipAtPoint_x                                0x90FAE0
#define CXWnd__GetBorderFrame_x                                    0x9111A0
#define CXWnd__GetChildWndAt_x                                     0x914FD0
#define CXWnd__GetClientClipRect_x                                 0x9131A0
#define CXWnd__GetScreenClipRect_x                                 0x913270
#define CXWnd__GetScreenRect_x                                     0x913430
#define CXWnd__GetTooltipRect_x                                    0x911390
#define CXWnd__GetWindowTextA_x                                    0x497E40
#define CXWnd__IsActive_x                                          0x917EC0
#define CXWnd__IsDescendantOf_x                                    0x913E40
#define CXWnd__IsReallyVisible_x                                   0x913E70
#define CXWnd__IsType_x                                            0x915630
#define CXWnd__Move_x                                              0x913EE0
#define CXWnd__Move1_x                                             0x913FA0
#define CXWnd__ProcessTransition_x                                 0x914A60
#define CXWnd__Refade_x                                            0x914270
#define CXWnd__Resize_x                                            0x9144F0
#define CXWnd__Right_x                                             0x914CF0
#define CXWnd__SetFocus_x                                          0x9148A0
#define CXWnd__SetFont_x                                           0x914910
#define CXWnd__SetKeyTooltip_x                                     0x915450
#define CXWnd__SetMouseOver_x                                      0x9122F0
#define CXWnd__StartFade_x                                         0x913D10
#define CXWnd__GetChildItem_x                                      0x915140
#define CXWnd__SetParent_x                                         0x913BD0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x947CF0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x917F00
#define CXWndManager__DrawWindows_x                                0x917F20
#define CXWndManager__GetKeyboardFlags_x                           0x91A6A0
#define CXWndManager__HandleKeyboardMsg_x                          0x91A2A0
#define CXWndManager__RemoveWnd_x                                  0x91A8F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91AE30

// CDBStr
#define CDBStr__GetString_x                                        0x52CED0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9150
#define EQ_Character__Cur_HP_x                                     0x4CF350
#define EQ_Character__Cur_Mana_x                                   0x4D6A80
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BC070
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFC00
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFD50
#define EQ_Character__GetHPRegen_x                                 0x4DCA00
#define EQ_Character__GetEnduranceRegen_x                          0x4DD010
#define EQ_Character__GetManaRegen_x                               0x4DD450
#define EQ_Character__Max_Endurance_x                              0x631C00
#define EQ_Character__Max_HP_x                                     0x4CF180
#define EQ_Character__Max_Mana_x                                   0x631A00
#define EQ_Character__doCombatAbility_x                            0x6340D0
#define EQ_Character__UseSkill_x                                   0x4DF260
#define EQ_Character__GetConLevel_x                                0x62B2F0
#define EQ_Character__IsExpansionFlag_x                            0x591390
#define EQ_Character__TotalEffect_x                                0x4C2700
#define EQ_Character__GetPCSpellAffect_x                           0x4BCC60
#define EQ_Character__SpellDuration_x                              0x4BC790
#define EQ_Character__FindItemByRecord_x                           0x4D4960
#define EQ_Character__GetAdjustedSkill_x                           0x4D2090
#define EQ_Character__GetBaseSkill_x                               0x4D3030
#define EQ_Character__CanUseItem_x                                 0x4D6D90

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B8F30

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x647FB0

//PcClient
#define PcClient__PcClient_x                                       0x628A30

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6DF0
#define CCharacterListWnd__EnterWorld_x                            0x4B6830
#define CCharacterListWnd__Quit_x                                  0x4B6540
#define CCharacterListWnd__UpdateList_x                            0x4B69C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60CF70
#define EQ_Item__CreateItemTagString_x                             0x8936B0
#define EQ_Item__IsStackable_x                                     0x898120
#define EQ_Item__GetImageNum_x                                     0x895110
#define EQ_Item__CreateItemClient_x                                0x60C120
#define EQ_Item__GetItemValue_x                                    0x8963B0
#define EQ_Item__ValueSellMerchant_x                               0x899900
#define EQ_Item__IsKeyRingItem_x                                   0x897A80
#define EQ_Item__CanGoInBag_x                                      0x60D090
#define EQ_Item__GetMaxItemCount_x                                 0x896770
#define EQ_Item__GetHeldItem_x                                     0x894FE0
#define EQ_Item__GetAugmentFitBySlot_x                             0x892FF0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54B2C0
#define EQ_LoadingS__Array_x                                       0xBEE130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x632560
#define EQ_PC__GetAlternateAbilityId_x                             0x8A2B00
#define EQ_PC__GetCombatAbility_x                                  0x8A3170
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A31E0
#define EQ_PC__GetItemRecastTimer_x                                0x634650
#define EQ_PC__HasLoreItem_x                                       0x62BAC0
#define EQ_PC__AlertInventoryChanged_x                             0x62AC30
#define EQ_PC__GetPcZoneClient_x                                   0x6567B0
#define EQ_PC__RemoveMyAffect_x                                    0x637840
#define EQ_PC__GetKeyRingItems_x                                   0x8A3A80
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A3800
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A3D70

// EQItemList 
#define EQItemList__EQItemList_x                                   0x597820
#define EQItemList__add_object_x                                   0x5C3540
#define EQItemList__add_item_x                                     0x597E30
#define EQItemList__delete_item_x                                  0x597E80
#define EQItemList__FreeItemList_x                                 0x597D80

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52A500

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x649830
#define EQPlayer__dEQPlayer_x                                      0x63CF10
#define EQPlayer__DoAttack_x                                       0x651470
#define EQPlayer__EQPlayer_x                                       0x63D5C0
#define EQPlayer__SetNameSpriteState_x                             0x641860
#define EQPlayer__SetNameSpriteTint_x                              0x642730
#define PlayerBase__HasProperty_j_x                                0x97A970
#define EQPlayer__IsTargetable_x                                   0x97AE10
#define EQPlayer__CanSee_x                                         0x97AC70
#define EQPlayer__CanSee1_x                                        0x97AD40
#define PlayerBase__GetVisibilityLineSegment_x                     0x97AA30

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x654240
#define PlayerZoneClient__GetLevel_x                               0x6567F0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C4690
#define PlayerZoneClient__LegalPlayerRace_x                        0x544690

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64C5B0
#define EQPlayerManager__GetSpawnByName_x                          0x64C5D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64C660

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x610960
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6109A0
#define KeypressHandler__ClearCommandStateArray_x                  0x611D90
#define KeypressHandler__HandleKeyDown_x                           0x611DB0
#define KeypressHandler__HandleKeyUp_x                             0x611E50
#define KeypressHandler__SaveKeymapping_x                          0x612230

// MapViewMap 
#define MapViewMap__Clear_x                                        0x768660
#define MapViewMap__SaveEx_x                                       0x76BA00
#define MapViewMap__SetZoom_x                                      0x7700D0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B6E20

// StringTable 
#define StringTable__getString_x                                   0x8B1EB0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6374B0
#define PcZoneClient__RemovePetEffect_x                            0x637AE0
#define PcZoneClient__HasAlternateAbility_x                        0x631840
#define PcZoneClient__GetCurrentMod_x                              0x4E2360
#define PcZoneClient__GetModCap_x                                  0x4E2260
#define PcZoneClient__CanEquipItem_x                               0x631EF0
#define PcZoneClient__GetItemByID_x                                0x634AC0
#define PcZoneClient__GetItemByItemClass_x                         0x634C10
#define PcZoneClient__RemoveBuffEffect_x                           0x637B00
#define PcZoneClient__BandolierSwap_x                              0x632B20

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C9210

//IconCache
#define IconCache__GetIcon_x                                       0x709280

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x700D70
#define CContainerMgr__CloseContainer_x                            0x701040
#define CContainerMgr__OpenExperimentContainer_x                   0x701AC0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C3AA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x605190

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75EAB0
#define CLootWnd__RequestLootSlot_x                                0x75DE60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x563870
#define EQ_Spell__SpellAffects_x                                   0x563CE0
#define EQ_Spell__SpellAffectBase_x                                0x563AA0
#define EQ_Spell__IsStackable_x                                    0x4C6EF0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6DD0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4120
#define EQ_Spell__IsSPAStacking_x                                  0x564B10
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x564030
#define EQ_Spell__IsNoRemove_x                                     0x4C6ED0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x564B20
#define __IsResEffectSpell_x                                       0x4C6260

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAA60

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C1380

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8095B0
#define CTargetWnd__WndNotification_x                              0x808E40
#define CTargetWnd__RefreshTargetBuffs_x                           0x809110
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x807F90

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80DC80

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x527E70
#define CTaskManager__HandleMessage_x                              0x5265E0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55EE10
#define EqSoundManager__PlayScriptMp3_x                            0x55EF70
#define EqSoundManager__SoundAssistPlay_x                          0x66F2E0
#define EqSoundManager__WaveInstancePlay_x                         0x66E850

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51BE80

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x933500

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x553050
#define CAltAbilityData__GetMercMaxRank_x                          0x552FF0
#define CAltAbilityData__GetMaxRank_x                              0x5483D0

//CTargetRing
#define CTargetRing__Cast_x                                        0x603290

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6DB0
#define CharacterBase__CreateItemGlobalIndex_x                     0x502340
#define CharacterBase__CreateItemIndex_x                           0x60B380
#define CharacterBase__GetItemPossession_x                         0x4B3FD0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C9A20
#define CharacterBase__GetEffectId_x                               0x4C6D60

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E8F30
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E9750

//messages
#define msg_spell_worn_off_x                                       0x589430
#define msg_new_text_x                                             0x57E220
#define __msgTokenTextParam_x                                      0x58BAA0
#define msgTokenText_x                                             0x58BCF0

//SpellManager
#define SpellManager__vftable_x                                    0xAB5A78
#define SpellManager__SpellManager_x                               0x672610
#define Spellmanager__LoadTextSpells_x                             0x672EE0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6727E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97E940

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5029F0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58F8D0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x624260
#define ItemGlobalIndex__IsValidIndex_x                            0x502A50

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C1CC0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C1F40

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x757640

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7054C0
#define CCursorAttachment__Deactivate_x                            0x7064A0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x945E30
#define CEQSuiteTextureLoader__GetTexture_x                        0x945AF0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FF8C0

//IString
#define IString__Append_x                                          0x4EF650

//Camera
#define CDisplay__cameraType_x                                     0xDC7B38
#define EverQuest__Cameras_x                                       0xE8A840

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x508070
#define LootFiltersManager__GetItemFilterData_x                    0x507960
#define LootFiltersManager__RemoveItemLootFilter_x                 0x507990
#define LootFiltersManager__SetItemLootFilter_x                    0x507BB0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B1AD0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9845C0
#define CResolutionHandler__GetWindowedStyle_x                     0x669F60

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FDB40

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D45C0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71DBC0
#define CGroupWnd__UpdateDisplay_x                                 0x71CF20

//ItemBase
#define ItemBase__IsLore_x                                         0x897AE0
#define ItemBase__IsLoreEquipped_x                                 0x897B50

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F5A80

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C3430
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C35E0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C3640

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65F2A0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x662F10

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E4F50
#define FactionManagerClient__HandleFactionMessage_x               0x4E55D0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E5BE0
#define FactionManagerClient__GetMaxFaction_x                      0x4E5C30
#define FactionManagerClient__GetMinFaction_x                      0x4E5BB0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
