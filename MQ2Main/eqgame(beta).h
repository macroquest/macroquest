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
#define __ExpectedVersionDate                                     "Nov 28 2018"
#define __ExpectedVersionTime                                     "04:22:20"
#define __ActualVersionDate_x                                      0xACD00C
#define __ActualVersionTime_x                                      0xACD000

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x612A90
#define __MemChecker1_x                                            0x8E71F0
#define __MemChecker2_x                                            0x6A1CA0
#define __MemChecker3_x                                            0x6A1BF0
#define __MemChecker4_x                                            0x83E940
#define __EncryptPad0_x                                            0xC01340
#define __EncryptPad1_x                                            0xC5F5D0
#define __EncryptPad2_x                                            0xC11EC8
#define __EncryptPad3_x                                            0xC11AC8
#define __EncryptPad4_x                                            0xC4FE40
#define __EncryptPad5_x                                            0x1030AD0
#define __AC1_x                                                    0x7FB0E6
#define __AC2_x                                                    0x5CDA1F
#define __AC3_x                                                    0x5D48AF
#define __AC4_x                                                    0x5D86D0
#define __AC5_x                                                    0x5DE88F
#define __AC6_x                                                    0x5E2DC6
#define __AC7_x                                                    0x5CD490
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E8A344

// Direct Input
#define DI8__Main_x                                                0x1030AF4
#define DI8__Keyboard_x                                            0x1030AF8
#define DI8__Mouse_x                                               0xF2678C
#define DI8__Mouse_Copy_x                                          0xE84194
#define DI8__Mouse_Check_x                                         0xF26754
#define __AutoSkillArray_x                                         0xE850AC
#define __Attack_x                                                 0xF22EB3
#define __Autofire_x                                               0xF22EB4
#define __BindList_x                                               0xBEFF20
#define g_eqCommandStates_x                                        0xBF0C90
#define __Clicks_x                                                 0xE8424C
#define __CommandList_x                                            0xBF1848
#define __CurrentMapLabel_x                                        0x1038A5C
#define __CurrentSocial_x                                          0xBDA730
#define __DoAbilityList_x                                          0xEBA9D4
#define __do_loot_x                                                0x59B110
#define __DrawHandler_x                                            0x16B5430
#define __GroupCount_x                                             0xE74442
#define __Guilds_x                                                 0xE7A9A0
#define __gWorld_x                                                 0xE76D1C
#define __HWnd_x                                                   0xF26790
#define __heqmain_x                                                0x1030AB8
#define __InChatMode_x                                             0xE8417C
#define __LastTell_x                                               0xE860D0
#define __LMouseHeldTime_x                                         0xE842B8
#define __Mouse_x                                                  0x1030ADC
#define __MouseLook_x                                              0xE84212
#define __MouseEventTime_x                                         0xF23968
#define __gpbCommandEvent_x                                        0xE7675C
#define __NetStatusToggle_x                                        0xE84215
#define __PCNames_x                                                0xE8568C
#define __RangeAttackReady_x                                       0xE85390
#define __RMouseHeldTime_x                                         0xE842B4
#define __RunWalkState_x                                           0xE84180
#define __ScreenMode_x                                             0xDC2A6C
#define __ScreenX_x                                                0xE84134
#define __ScreenY_x                                                0xE84130
#define __ScreenXMax_x                                             0xE84138
#define __ScreenYMax_x                                             0xE8413C
#define __ServerHost_x                                             0xE769AB
#define __ServerName_x                                             0xEBA994
#define __ShiftKeyDown_x                                           0xE8480C
#define __ShowNames_x                                              0xE8554C
#define __Socials_x                                                0xEBAA94
#define __SubscriptionType_x                                       0x107A5AC
#define __TargetAggroHolder_x                                      0x103B418
#define __ZoneType_x                                               0xE84610
#define __GroupAggro_x                                             0x103B458
#define __LoginName_x                                              0x103134C
#define __Inviter_x                                                0xF22E30
#define __AttackOnAssist_x                                         0xE85508
#define __UseTellWindows_x                                         0xE85824
#define __gfMaxZoomCameraDistance_x                                0xAC2528
#define __gfMaxCameraDistance_x                                    0xAEF970
#define __pulAutoRun_x                                             0xE84230
#define __pulForward_x                                             0xE8585C
#define __pulBackward_x                                            0xE85860
#define __pulTurnRight_x                                           0xE85864
#define __pulTurnLeft_x                                            0xE85868
#define __pulStrafeLeft_x                                          0xE8586C
#define __pulStrafeRight_x                                         0xE85870
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE76D38
#define instEQZoneInfo_x                                           0xE84408
#define instKeypressHandler_x                                      0xF23918
#define pinstActiveBanker_x                                        0xE76858
#define pinstActiveCorpse_x                                        0xE76850
#define pinstActiveGMaster_x                                       0xE76854
#define pinstActiveMerchant_x                                      0xE7684C
#define pinstAggroInfo_x                                           0xC75E08
#define pinstAltAdvManager_x                                       0xDC36D8
#define pinstAuraMgr_x                                             0xC91970
#define pinstBandageTarget_x                                       0xE76868
#define pinstCamActor_x                                            0xDC2A60
#define pinstCDBStr_x                                              0xDC240C
#define pinstCDisplay_x                                            0xE76D14
#define pinstCEverQuest_x                                          0x1030C10
#define pinstEverQuestInfo_x                                       0xE84128
#define pinstCharData_x                                            0xE76D24
#define pinstCharSpawn_x                                           0xE768A0
#define pinstControlledMissile_x                                   0xE76D20
#define pinstControlledPlayer_x                                    0xE768A0
#define pinstCResolutionHandler_x                                  0x16B5660
#define pinstCSidlManager_x                                        0x16B44F4
#define pinstCXWndManager_x                                        0x16B44E8
#define instDynamicZone_x                                          0xE7A878
#define pinstDZMember_x                                            0xE7A988
#define pinstDZTimerInfo_x                                         0xE7A98C
#define pinstEQItemList_x                                          0xE72F28
#define pinstEQObjectList_x                                        0xE74118
#define instEQMisc_x                                               0xDC2348
#define pinstEQSoundManager_x                                      0xDC3F38
#define pinstEQSpellStrings_x                                      0xC83F40
#define instExpeditionLeader_x                                     0xE7A8C2
#define instExpeditionName_x                                       0xE7A902
#define pinstGroup_x                                               0xE7443E
#define pinstImeManager_x                                          0x16B44EC
#define pinstLocalPlayer_x                                         0xE76848
#define pinstMercenaryData_x                                       0xF24114
#define pinstMercenaryStats_x                                      0x103B564
#define pinstMercAltAbilities_x                                    0xDC3CA8
#define pinstModelPlayer_x                                         0xE76860
#define pinstPCData_x                                              0xE76D24
#define pinstRealEstateItems_x                                     0xF255F8
#define pinstSkillMgr_x                                            0xF256C8
#define pinstSpawnManager_x                                        0xF24CB8
#define pinstSpellManager_x                                        0xF258A0
#define pinstSpellSets_x                                           0xF1BADC
#define pinstStringTable_x                                         0xE76638
#define pinstSwitchManager_x                                       0xE742D8
#define pinstTarget_x                                              0xE7689C
#define pinstTargetObject_x                                        0xE76CC0
#define pinstTargetSwitch_x                                        0xE76D2C
#define pinstTaskMember_x                                          0xDC21DC
#define pinstTrackTarget_x                                         0xE768A8
#define pinstTradeTarget_x                                         0xE7685C
#define instTributeActive_x                                        0xDC236D
#define pinstViewActor_x                                           0xDC2A5C
#define pinstWorldData_x                                           0xE76760
#define pinstZoneAddr_x                                            0xE846A8
#define pinstPlayerPath_x                                          0xF24D50
#define pinstTargetIndicator_x                                     0xF25B08
#define pinstCTargetManager_x                                      0xF25BA0
#define EQObject_Top_x                                             0xE76824

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC251C
#define pinstCAchievementsWnd_x                                    0xDC24D0
#define pinstCActionsWnd_x                                         0xDC29F8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC29E8
#define pinstCAdvancedLootWnd_x                                    0xDC2538
#define pinstCAdventureLeaderboardWnd_x                            0x1032230
#define pinstCAdventureRequestWnd_x                                0x10322E0
#define pinstCAdventureStatsWnd_x                                  0x1032390
#define pinstCAggroMeterWnd_x                                      0xDC2A9C
#define pinstCAlarmWnd_x                                           0xDC2AC4
#define pinstCAlertHistoryWnd_x                                    0xDC2D20
#define pinstCAlertStackWnd_x                                      0xDC2A80
#define pinstCAlertWnd_x                                           0xDC2A90
#define pinstCAltStorageWnd_x                                      0x10326F0
#define pinstCAudioTriggersWindow_x                                0xC76298
#define pinstCAuraWnd_x                                            0xDC2A98
#define pinstCAvaZoneWnd_x                                         0xDC2D2C
#define pinstCBandolierWnd_x                                       0xDC2AE0
#define pinstCBankWnd_x                                            0xDC24C8
#define pinstCBarterMerchantWnd_x                                  0x1033930
#define pinstCBarterSearchWnd_x                                    0x10339E0
#define pinstCBarterWnd_x                                          0x1033A90
#define pinstCBazaarConfirmationWnd_x                              0xDC2A7C
#define pinstCBazaarSearchWnd_x                                    0xDC2A34
#define pinstCBazaarWnd_x                                          0xDC2ADC
#define pinstCBlockedBuffWnd_x                                     0xDC24AC
#define pinstCBlockedPetBuffWnd_x                                  0xDC24D4
#define pinstCBodyTintWnd_x                                        0xDC2A40
#define pinstCBookWnd_x                                            0xDC2B04
#define pinstCBreathWnd_x                                          0xDC2524
#define pinstCBuffWindowNORMAL_x                                   0xDC2D24
#define pinstCBuffWindowSHORT_x                                    0xDC2D28
#define pinstCBugReportWnd_x                                       0xDC250C
#define pinstCButtonWnd_x                                          0x16B4718
#define pinstCCastingWnd_x                                         0xDC2508
#define pinstCCastSpellWnd_x                                       0xDC2A48
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC2528
#define pinstCChatWindowManager_x                                  0x1034550
#define pinstCClaimWnd_x                                           0x10346A8
#define pinstCColorPickerWnd_x                                     0xDC2558
#define pinstCCombatAbilityWnd_x                                   0xDC2AA8
#define pinstCCombatSkillsSelectWnd_x                              0xDC29F0
#define pinstCCompassWnd_x                                         0xDC2A28
#define pinstCConfirmationDialog_x                                 0x10395A8
#define pinstCContainerMgr_x                                       0xDC2ABC
#define pinstCContextMenuManager_x                                 0x16B44A8
#define pinstCCursorAttachment_x                                   0xDC24FC
#define pinstCDistillerInfo_x                                      0x1037FB4
#define pinstCDynamicZoneWnd_x                                     0x1034C70
#define pinstCEditLabelWnd_x                                       0xDC2B10
#define pinstCEQMainWnd_x                                          0x1034EB8
#define pinstCEventCalendarWnd_x                                   0xDC2518
#define pinstCExtendedTargetWnd_x                                  0xDC2A88
#define pinstCFacePick_x                                           0xDC2550
#define pinstCFellowshipWnd_x                                      0x10350B8
#define pinstCFileSelectionWnd_x                                   0xDC2530
#define pinstCFindItemWnd_x                                        0xDC2AFC
#define pinstCFindLocationWnd_x                                    0x1035210
#define pinstCFriendsWnd_x                                         0xDC2A30
#define pinstCGemsGameWnd_x                                        0xDC2A94
#define pinstCGiveWnd_x                                            0xDC2B00
#define pinstCGroupSearchFiltersWnd_x                              0xDC2AB8
#define pinstCGroupSearchWnd_x                                     0x1035608
#define pinstCGroupWnd_x                                           0x10356B8
#define pinstCGuildBankWnd_x                                       0xE854EC
#define pinstCGuildCreationWnd_x                                   0x1035818
#define pinstCGuildMgmtWnd_x                                       0x10358C8
#define pinstCharacterCreation_x                                   0xDC2AA4
#define pinstCHelpWnd_x                                            0xDC2A50
#define pinstCHeritageSelectionWnd_x                               0xDC2574
#define pinstCHotButtonWnd_x                                       0x1037A20
#define pinstCHotButtonWnd1_x                                      0x1037A20
#define pinstCHotButtonWnd2_x                                      0x1037A24
#define pinstCHotButtonWnd3_x                                      0x1037A28
#define pinstCHotButtonWnd4_x                                      0x1037A2C
#define pinstCIconSelectionWnd_x                                   0xDC24E4
#define pinstCInspectWnd_x                                         0xDC24D8
#define pinstCInventoryWnd_x                                       0xDC2AE4
#define pinstCInvSlotMgr_x                                         0xDC2A78
#define pinstCItemDisplayManager_x                                 0x1037FB0
#define pinstCItemExpTransferWnd_x                                 0x10380E0
#define pinstCItemOverflowWnd_x                                    0xDC2A38
#define pinstCJournalCatWnd_x                                      0xDC2548
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDC2510
#define pinstCKeyRingWnd_x                                         0xDC24A8
#define pinstCLargeDialogWnd_x                                     0x103A228
#define pinstCLayoutCopyWnd_x                                      0x1038430
#define pinstCLFGuildWnd_x                                         0x10384E0
#define pinstCLoadskinWnd_x                                        0xDC2AA0
#define pinstCLootFiltersCopyWnd_x                                 0xC922A0
#define pinstCLootFiltersWnd_x                                     0xDC2AB0
#define pinstCLootSettingsWnd_x                                    0xDC2AD8
#define pinstCLootWnd_x                                            0xDC2540
#define pinstCMailAddressBookWnd_x                                 0xDC24DC
#define pinstCMailCompositionWnd_x                                 0xDC24B8
#define pinstCMailIgnoreListWnd_x                                  0xDC24E0
#define pinstCMailWnd_x                                            0xDC2D30
#define pinstCManageLootWnd_x                                      0xDC3B50
#define pinstCMapToolbarWnd_x                                      0xDC2AEC
#define pinstCMapViewWnd_x                                         0xDC2AC8
#define pinstCMarketplaceWnd_x                                     0xDC2520
#define pinstCMerchantWnd_x                                        0xDC29EC
#define pinstCMIZoneSelectWnd_x                                    0x1038D18
#define pinstCMusicPlayerWnd_x                                     0xDC2D3C
#define pinstCNameChangeMercWnd_x                                  0xDC2A44
#define pinstCNameChangePetWnd_x                                   0xDC2A20
#define pinstCNameChangeWnd_x                                      0xDC2500
#define pinstCNoteWnd_x                                            0xDC2A4C
#define pinstCObjectPreviewWnd_x                                   0xDC2544
#define pinstCOptionsWnd_x                                         0xDC2AF0
#define pinstCPetInfoWnd_x                                         0xDC24BC
#define pinstCPetitionQWnd_x                                       0xDC2554
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC2A3C
#define pinstCPlayerWnd_x                                          0xDC2A18
#define pinstCPopupWndManager_x                                    0x10395A8
#define pinstCProgressionSelectionWnd_x                            0x1039658
#define pinstCPurchaseGroupWnd_x                                   0xDC29E0
#define pinstCPurchaseWnd_x                                        0xDC254C
#define pinstCPvPLeaderboardWnd_x                                  0x1039708
#define pinstCPvPStatsWnd_x                                        0x10397B8
#define pinstCQuantityWnd_x                                        0xDC24F0
#define pinstCRaceChangeWnd_x                                      0xDC252C
#define pinstCRaidOptionsWnd_x                                     0xDC2AC0
#define pinstCRaidWnd_x                                            0xDC24F4
#define pinstCRealEstateItemsWnd_x                                 0xDC24E8
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC2514
#define pinstCRealEstateManageWnd_x                                0xDC2AE8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC2B08
#define pinstCRealEstatePlotSearchWnd_x                            0xDC2D34
#define pinstCRealEstatePurchaseWnd_x                              0xDC24C0
#define pinstCRespawnWnd_x                                         0xDC2AB4
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDC2A8C
#define pinstCSendMoneyWnd_x                                       0xDC2D18
#define pinstCServerListWnd_x                                      0xDC2D1C
#define pinstCSkillsSelectWnd_x                                    0xDC255C
#define pinstCSkillsWnd_x                                          0xDC253C
#define pinstCSocialEditWnd_x                                      0xDC24F8
#define pinstCSocialWnd_x                                          0xDC2A58
#define pinstCSpellBookWnd_x                                       0xDC2A84
#define pinstCStoryWnd_x                                           0xDC29F4
#define pinstCTargetOfTargetWnd_x                                  0x103B5E8
#define pinstCTargetWnd_x                                          0xDC24B0
#define pinstCTaskOverlayWnd_x                                     0xDC2D38
#define pinstCTaskSelectWnd_x                                      0x103B740
#define pinstCTaskManager_x                                        0xC92AA0
#define pinstCTaskTemplateSelectWnd_x                              0x103B7F0
#define pinstCTaskWnd_x                                            0x103B8A0
#define pinstCTextEntryWnd_x                                       0xDC2A2C
#define pinstCTextOverlay_x                                        0xC765A8
#define pinstCTimeLeftWnd_x                                        0xDC2534
#define pinstCTipWndCONTEXT_x                                      0x103BAA4
#define pinstCTipWndOFDAY_x                                        0x103BAA0
#define pinstCTitleWnd_x                                           0x103BB50
#define pinstCTrackingWnd_x                                        0xDC24B4
#define pinstCTradeskillWnd_x                                      0x103BCB8
#define pinstCTradeWnd_x                                           0xDC2A54
#define pinstCTrainWnd_x                                           0xDC24EC
#define pinstCTributeBenefitWnd_x                                  0x103BEB8
#define pinstCTributeMasterWnd_x                                   0x103BF68
#define pinstCTributeTrophyWnd_x                                   0x103C018
#define pinstCVideoModesWnd_x                                      0xDC2AAC
#define pinstCVoiceMacroWnd_x                                      0xF260D0
#define pinstCVoteResultsWnd_x                                     0xDC29E4
#define pinstCVoteWnd_x                                            0xDC2560
#define pinstCWebManager_x                                         0xF26234
#define pinstCZoneGuideWnd_x                                       0xDC2AF4
#define pinstCZonePathWnd_x                                        0xDC2B0C

#define pinstEQSuiteTextureLoader_x                                0xC610A0
#define pinstItemIconCache_x                                       0x1034E70
#define pinstLootFiltersManager_x                                  0xC92350
#define pinstRewardSelectionWnd_x                                  0x1039F00

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC11ABC
#define __CastRay_x                                                0x596630
#define __CastRay2_x                                               0x596680
#define __ConvertItemTags_x                                        0x5B1230
#define __CrashHandler_x                                           0x8482A0
#define __EQGetTime_x                                              0x8E6CE0
#define __ExecuteCmd_x                                             0x58EFA0
#define __FixHeading_x                                             0x9776D0
#define __get_bearing_x                                            0x596180
#define __get_melee_range_x                                        0x596870
#define __GetAnimationCache_x                                      0x705510
#define __GetGaugeValueFromEQ_x                                    0x7F98F0
#define __GetLabelFromEQ_x                                         0x7FB070
#define __GetXTargetType_x                                         0x979130
#define __HeadingDiff_x                                            0x977740
#define __HelpPath_x                                               0xF23584
#define __LoadFrontEnd_x                                           0x69DB00
#define __NewUIINI_x                                               0x7F95C0
#define __pCrashHandler_x                                          0x1059408
#define __ProcessGameEvents_x                                      0x5F3FF0
#define __ProcessMouseEvent_x                                      0x5F37B0
#define __SaveColors_x                                             0x540360
#define __STMLToText_x                                             0x91AB10
#define __ToggleKeyRingItem_x                                      0x503510
#define CrashDetected_x                                            0x69F5F0
#define DrawNetStatus_x                                            0x620150
#define Expansion_HoT_x                                            0xE854F4
#define Teleport_Table_Size_x                                      0xE767F0
#define Teleport_Table_x                                           0xE74630
#define Util__FastTime_x                                           0x8E68A0
#define wwsCrashReportCheckForUploader_x                           0x848CF0
#define wwsCrashReportPlatformLaunchUploader_x                     0x84B3D0
#define __HandleMouseWheel_x                                       0x6A1D50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B650
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4944D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494290

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x547D20
#define AltAdvManager__IsAbilityReady_x                            0x546C70
#define AltAdvManager__GetAAById_x                                 0x546E70
#define AltAdvManager__CanTrainAbility_x                           0x546EE0
#define AltAdvManager__CanSeeAbility_x                             0x547240

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7650
#define CharacterZoneClient__HasSkill_x                            0x4D2310
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3A30
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBA00
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8180
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D63E0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D64C0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D65A0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C04E0
#define CharacterZoneClient__BardCastBard_x                        0x4C3140
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8250
#define CharacterZoneClient__GetEffect_x                           0x4B80C0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C14E0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C15B0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1600
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1750
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1920

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C7A70

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D5550

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x602770
#define CButtonWnd__CButtonWnd_x                                   0x916F10

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F3F10
#define CChatManager__InitContextMenu_x                            0x6EDFB0
#define CChatManager__FreeChatWindow_x                             0x6F2E20
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F77C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F3CB0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92B7F0
#define CContextMenu__dCContextMenu_x                              0x92BA20
#define CContextMenu__AddMenuItem_x                                0x92BA30
#define CContextMenu__RemoveMenuItem_x                             0x92BD40
#define CContextMenu__RemoveAllMenuItems_x                         0x92BD60
#define CContextMenu__CheckMenuItem_x                              0x92BDE0
#define CContextMenu__SetMenuItem_x                                0x92BC60
#define CContextMenu__AddSeparator_x                               0x92BBC0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92C380
#define CContextMenuManager__RemoveMenu_x                          0x92C3F0
#define CContextMenuManager__PopupMenu_x                           0x92C4B0
#define CContextMenuManager__Flush_x                               0x92C320
#define CContextMenuManager__GetMenu_x                             0x496620

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C76B0
#define CChatService__GetFriendName_x                              0x8C76C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F4480
#define CChatWindow__Clear_x                                       0x6F54D0
#define CChatWindow__WndNotification_x                             0x6F5A40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x928C80
#define CComboWnd__Draw_x                                          0x928180
#define CComboWnd__GetCurChoice_x                                  0x928AC0
#define CComboWnd__GetListRect_x                                   0x928630
#define CComboWnd__GetTextRect_x                                   0x928CF0
#define CComboWnd__InsertChoice_x                                  0x9287C0
#define CComboWnd__SetColors_x                                     0x928790
#define CComboWnd__SetChoice_x                                     0x928A90
#define CComboWnd__GetItemCount_x                                  0x928AD0
#define CComboWnd__GetCurChoiceText_x                              0x928B10

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6FD6B0
#define CContainerWnd__vftable_x                                   0xAD62B8
#define CContainerWnd__SetContainer_x                              0x6FEC20

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x540120
#define CDisplay__GetClickedActor_x                                0x5330D0
#define CDisplay__GetUserDefinedColor_x                            0x52B7B0
#define CDisplay__GetWorldFilePath_x                               0x534B20
#define CDisplay__is3dON_x                                         0x52FDA0
#define CDisplay__ReloadUI_x                                       0x53A240
#define CDisplay__WriteTextHD2_x                                   0x52FB80
#define CDisplay__TrueDistance_x                                   0x536780
#define CDisplay__SetViewActor_x                                   0x532A20
#define CDisplay__GetFloorHeight_x                                 0x52FE60
#define CDisplay__SetRenderWindow_x                                0x52E790
#define CDisplay__ToggleScreenshotMode_x                           0x5324F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94AE20

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92FF00
#define CEditWnd__GetCharIndexPt_x                                 0x930DF0
#define CEditWnd__GetDisplayString_x                               0x930C90
#define CEditWnd__GetHorzOffset_x                                  0x92F540
#define CEditWnd__GetLineForPrintableChar_x                        0x931F00
#define CEditWnd__GetSelStartPt_x                                  0x9310A0
#define CEditWnd__GetSTMLSafeText_x                                0x930AB0
#define CEditWnd__PointFromPrintableChar_x                         0x931B40
#define CEditWnd__SelectableCharFromPoint_x                        0x931CB0
#define CEditWnd__SetEditable_x                                    0x931160

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E22F0
#define CEverQuest__ClickedPlayer_x                                0x5D4690
#define CEverQuest__CreateTargetIndicator_x                        0x5F12A0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F1330
#define CEverQuest__DoTellWindow_x                                 0x4E34B0
#define CEverQuest__OutputTextToLog_x                              0x4E36E0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C9F50
#define CEverQuest__dsp_chat_x                                     0x4E3A70
#define CEverQuest__trimName_x                                     0x5ED810
#define CEverQuest__Emote_x                                        0x5E2B00
#define CEverQuest__EnterZone_x                                    0x5DCCE0
#define CEverQuest__GetBodyTypeDesc_x                              0x5E70B0
#define CEverQuest__GetClassDesc_x                                 0x5E76F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E7CF0
#define CEverQuest__GetDeityDesc_x                                 0x5EFBF0
#define CEverQuest__GetLangDesc_x                                  0x5E7EB0
#define CEverQuest__GetRaceDesc_x                                  0x5E76D0
#define CEverQuest__InterpretCmd_x                                 0x5F01C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5CE140
#define CEverQuest__LMouseUp_x                                     0x5CC4C0
#define CEverQuest__RightClickedOnPlayer_x                         0x5CEA20
#define CEverQuest__RMouseUp_x                                     0x5CD450
#define CEverQuest__SetGameState_x                                 0x5C9CE0
#define CEverQuest__UPCNotificationFlush_x                         0x5ED710
#define CEverQuest__IssuePetCommand_x                              0x5E92B0
#define CEverQuest__ReportSuccessfulHit_x                          0x5E3F00

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70F650
#define CGaugeWnd__CalcLinesFillRect_x                             0x70F6B0
#define CGaugeWnd__Draw_x                                          0x70ED40

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACCD0
#define CGuild__GetGuildName_x                                     0x4ABDB0
#define CGuild__GetGuildIndex_x                                    0x4AC140

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72AA20

//CHotButton
#define CHotButton__SetButtonSize_x                                0x602B30

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7379C0
#define CInvSlotMgr__MoveItem_x                                    0x736710
#define CInvSlotMgr__SelectSlot_x                                  0x737A90

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x734FC0
#define CInvSlot__SliderComplete_x                                 0x732D20
#define CInvSlot__GetItemBase_x                                    0x7326B0
#define CInvSlot__UpdateItem_x                                     0x732820

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7393E0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7386B0
#define CInvSlotWnd__HandleLButtonUp_x                             0x738F60

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F5AE0
#define CItemDisplayWnd__UpdateStrings_x                           0x7475F0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x741540
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x741A60
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x747C00
#define CItemDisplayWnd__AboutToShow_x                             0x747240
#define CItemDisplayWnd__WndNotification_x                         0x749140

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x82D370

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x74D2A0

// CLabel 
#define CLabel__Draw_x                                             0x752D80

// CListWnd
#define CListWnd__CListWnd_x                                       0x901280
#define CListWnd__dCListWnd_x                                      0x9015A0
#define CListWnd__AddColumn_x                                      0x9058D0
#define CListWnd__AddColumn1_x                                     0x905920
#define CListWnd__AddLine_x                                        0x905CB0
#define CListWnd__AddString_x                                      0x905AB0
#define CListWnd__CalculateFirstVisibleLine_x                      0x905690
#define CListWnd__CalculateVSBRange_x                              0x905460
#define CListWnd__ClearSel_x                                       0x906490
#define CListWnd__ClearAllSel_x                                    0x9064F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x906F00
#define CListWnd__Compare_x                                        0x904DB0
#define CListWnd__Draw_x                                           0x9016A0
#define CListWnd__DrawColumnSeparators_x                           0x903E80
#define CListWnd__DrawHeader_x                                     0x9042F0
#define CListWnd__DrawItem_x                                       0x9046F0
#define CListWnd__DrawLine_x                                       0x903FF0
#define CListWnd__DrawSeparator_x                                  0x903F20
#define CListWnd__EnableLine_x                                     0x903750
#define CListWnd__EnsureVisible_x                                  0x906E20
#define CListWnd__ExtendSel_x                                      0x9063C0
#define CListWnd__GetColumnMinWidth_x                              0x903290
#define CListWnd__GetColumnWidth_x                                 0x903200
#define CListWnd__GetCurSel_x                                      0x902B90
#define CListWnd__GetItemAtPoint_x                                 0x9039D0
#define CListWnd__GetItemAtPoint1_x                                0x903A40
#define CListWnd__GetItemData_x                                    0x902C10
#define CListWnd__GetItemHeight_x                                  0x902FD0
#define CListWnd__GetItemIcon_x                                    0x902DA0
#define CListWnd__GetItemRect_x                                    0x903840
#define CListWnd__GetItemText_x                                    0x902C50
#define CListWnd__GetSelList_x                                     0x906540
#define CListWnd__GetSeparatorRect_x                               0x903C80
#define CListWnd__InsertLine_x                                     0x9060A0
#define CListWnd__RemoveLine_x                                     0x9061F0
#define CListWnd__SetColors_x                                      0x905440
#define CListWnd__SetColumnJustification_x                         0x905170
#define CListWnd__SetColumnWidth_x                                 0x905090
#define CListWnd__SetCurSel_x                                      0x906300
#define CListWnd__SetItemColor_x                                   0x906AD0
#define CListWnd__SetItemData_x                                    0x906A90
#define CListWnd__SetItemText_x                                    0x9066C0
#define CListWnd__ShiftColumnSeparator_x                           0x905230
#define CListWnd__Sort_x                                           0x904F30
#define CListWnd__ToggleSel_x                                      0x906330

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x768250
#define CMapViewWnd__GetWorldCoordinates_x                         0x766960
#define CMapViewWnd__HandleLButtonDown_x                           0x7639C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78B6B0
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78BF90
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78C4D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x78F310
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78A080
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x794F10
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78B2E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8953A0
#define CPacketScrambler__hton_x                                   0x895390

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x920120
#define CSidlManager__FindScreenPieceTemplate_x                    0x920530
#define CSidlManager__FindScreenPieceTemplate1_x                   0x920320
#define CSidlManager__CreateLabel_x                                0x7ECEC0
#define CSidlManager__CreateXWndFromTemplate_x                     0x923600
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9237E0
#define CSidlManager__CreateXWnd_x                                 0x7ECDF0
#define CSidlManager__CreateHotButtonWnd_x                         0x7ED3C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x91CC90
#define CSidlScreenWnd__CalculateVSBRange_x                        0x91CB80
#define CSidlScreenWnd__ConvertToRes_x                             0x941C60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91C610
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91C300
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91C3D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91C4A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x91D130
#define CSidlScreenWnd__EnableIniStorage_x                         0x91D600
#define CSidlScreenWnd__GetSidlPiece_x                             0x91D320
#define CSidlScreenWnd__Init1_x                                    0x91BEF0
#define CSidlScreenWnd__LoadIniInfo_x                              0x91D650
#define CSidlScreenWnd__LoadIniListWnd_x                           0x91E190
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91B2F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x91DD10
#define CSidlScreenWnd__StoreIniVis_x                              0x91E070
#define CSidlScreenWnd__WndNotification_x                          0x91D040
#define CSidlScreenWnd__GetChildItem_x                             0x91D580
#define CSidlScreenWnd__HandleLButtonUp_x                          0x90CDB0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B4378

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x666DE0
#define CSkillMgr__GetSkillCap_x                                   0x666FC0
#define CSkillMgr__GetNameToken_x                                  0x666570

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x92D180
#define CSliderWnd__SetValue_x                                     0x92CFF0
#define CSliderWnd__SetNumTicks_x                                  0x92D050

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F2D60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x933DB0
#define CStmlWnd__CalculateHSBRange_x                              0x934E40
#define CStmlWnd__CalculateVSBRange_x                              0x934DB0
#define CStmlWnd__CanBreakAtCharacter_x                            0x939180
#define CStmlWnd__FastForwardToEndOfTag_x                          0x939D70
#define CStmlWnd__ForceParseNow_x                                  0x934350
#define CStmlWnd__GetNextTagPiece_x                                0x9390E0
#define CStmlWnd__GetSTMLText_x                                    0x4F4CE0
#define CStmlWnd__GetVisibleText_x                                 0x934370
#define CStmlWnd__InitializeWindowVariables_x                      0x939BC0
#define CStmlWnd__MakeStmlColorTag_x                               0x933540
#define CStmlWnd__MakeWndNotificationTag_x                         0x9335B0
#define CStmlWnd__SetSTMLText_x                                    0x932610
#define CStmlWnd__StripFirstSTMLLines_x                            0x93AED0
#define CStmlWnd__UpdateHistoryString_x                            0x939F80

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93EC30
#define CTabWnd__DrawCurrentPage_x                                 0x93F250
#define CTabWnd__DrawTab_x                                         0x93F020
#define CTabWnd__GetCurrentPage_x                                  0x93E490
#define CTabWnd__GetPageInnerRect_x                                0x93E6D0
#define CTabWnd__GetTabInnerRect_x                                 0x93E610
#define CTabWnd__GetTabRect_x                                      0x93E4C0
#define CTabWnd__InsertPage_x                                      0x93E8C0
#define CTabWnd__SetPage_x                                         0x93E750
#define CTabWnd__SetPageRect_x                                     0x93EB70
#define CTabWnd__UpdatePage_x                                      0x93EEE0
#define CTabWnd__GetPageFromTabIndex_x                             0x93EF60
#define CTabWnd__GetCurrentTabIndex_x                              0x93E480

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x74D700
#define CPageWnd__SetTabText_x                                     0x94B240

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A67C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x909BF0
#define CTextureFont__GetTextExtent_x                              0x909DB0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69A950
#define CHtmlComponentWnd__ValidateUri_x                           0x72C410
#define CHtmlWnd__SetClientCallbacks_x                             0x607B10
#define CHtmlWnd__AddObserver_x                                    0x607B30
#define CHtmlWnd__RemoveObserver_x                                 0x607B90
#define Window__getProgress_x                                      0x845F00
#define Window__getStatus_x                                        0x845F20
#define Window__getURI_x                                           0x845F30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9477B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F6B10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AE030
#define CXStr__CXStr1_x                                            0x9B91C0
#define CXStr__CXStr3_x                                            0x8E2E00
#define CXStr__dCXStr_x                                            0x472F00
#define CXStr__operator_equal_x                                    0x8E3030
#define CXStr__operator_equal1_x                                   0x8E3070
#define CXStr__operator_plus_equal1_x                              0x8E3B00

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92B410
#define CXWnd__BringToTop_x                                        0x9104D0
#define CXWnd__Center_x                                            0x910050
#define CXWnd__ClrFocus_x                                          0x90FE90
#define CXWnd__Destroy_x                                           0x90FF30
#define CXWnd__DoAllDrawing_x                                      0x90C540
#define CXWnd__DrawChildren_x                                      0x90C510
#define CXWnd__DrawColoredRect_x                                   0x90C9A0
#define CXWnd__DrawTooltip_x                                       0x90B040
#define CXWnd__DrawTooltipAtPoint_x                                0x90B100
#define CXWnd__GetBorderFrame_x                                    0x90C800
#define CXWnd__GetChildWndAt_x                                     0x910570
#define CXWnd__GetClientClipRect_x                                 0x90E800
#define CXWnd__GetScreenClipRect_x                                 0x90E8B0
#define CXWnd__GetScreenRect_x                                     0x90EA60
#define CXWnd__GetTooltipRect_x                                    0x90C9F0
#define CXWnd__GetWindowTextA_x                                    0x497DA0
#define CXWnd__IsActive_x                                          0x913400
#define CXWnd__IsDescendantOf_x                                    0x90F470
#define CXWnd__IsReallyVisible_x                                   0x90F4A0
#define CXWnd__IsType_x                                            0x910BF0
#define CXWnd__Move_x                                              0x90F510
#define CXWnd__Move1_x                                             0x90F5D0
#define CXWnd__ProcessTransition_x                                 0x910000
#define CXWnd__Refade_x                                            0x90F890
#define CXWnd__Resize_x                                            0x90FAE0
#define CXWnd__Right_x                                             0x910290
#define CXWnd__SetFocus_x                                          0x90FE50
#define CXWnd__SetFont_x                                           0x90FEC0
#define CXWnd__SetKeyTooltip_x                                     0x910A00
#define CXWnd__SetMouseOver_x                                      0x90D950
#define CXWnd__StartFade_x                                         0x90F350
#define CXWnd__GetChildItem_x                                      0x9106E0
#define CXWnd__SetParent_x                                         0x90F210

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x942D30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x913440
#define CXWndManager__DrawWindows_x                                0x913460
#define CXWndManager__GetKeyboardFlags_x                           0x915BE0
#define CXWndManager__HandleKeyboardMsg_x                          0x9157E0
#define CXWndManager__RemoveWnd_x                                  0x915E30
#define CXWndManager__RemovePendingDeletionWnd_x                   0x916380

// CDBStr
#define CDBStr__GetString_x                                        0x52A760

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9130
#define EQ_Character__Cur_HP_x                                     0x4CF390
#define EQ_Character__Cur_Mana_x                                   0x4D6AA0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BC040
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFC60
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFDB0
#define EQ_Character__GetHPRegen_x                                 0x4DCA20
#define EQ_Character__GetEnduranceRegen_x                          0x4DD030
#define EQ_Character__GetManaRegen_x                               0x4DD470
#define EQ_Character__Max_Endurance_x                              0x62DA70
#define EQ_Character__Max_HP_x                                     0x4CF1C0
#define EQ_Character__Max_Mana_x                                   0x62D870
#define EQ_Character__doCombatAbility_x                            0x62FF40
#define EQ_Character__UseSkill_x                                   0x4DF280
#define EQ_Character__GetConLevel_x                                0x626F10
#define EQ_Character__IsExpansionFlag_x                            0x58D760
#define EQ_Character__TotalEffect_x                                0x4C26C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BCC30
#define EQ_Character__SpellDuration_x                              0x4BC760
#define EQ_Character__FindItemByRecord_x                           0x4D49A0
#define EQ_Character__GetAdjustedSkill_x                           0x4D20D0
#define EQ_Character__GetBaseSkill_x                               0x4D3070
#define EQ_Character__CanUseItem_x                                 0x4D6DB0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B4670

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x643D30

//PcClient
#define PcClient__PcClient_x                                       0x6247F0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6DA0
#define CCharacterListWnd__EnterWorld_x                            0x4B67E0
#define CCharacterListWnd__Quit_x                                  0x4B64F0
#define CCharacterListWnd__UpdateList_x                            0x4B6970

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x608D70
#define EQ_Item__CreateItemTagString_x                             0x88ED30
#define EQ_Item__IsStackable_x                                     0x893770
#define EQ_Item__GetImageNum_x                                     0x8907A0
#define EQ_Item__CreateItemClient_x                                0x607F10
#define EQ_Item__GetItemValue_x                                    0x891A10
#define EQ_Item__ValueSellMerchant_x                               0x894F40
#define EQ_Item__IsKeyRingItem_x                                   0x8930C0
#define EQ_Item__CanGoInBag_x                                      0x608E90
#define EQ_Item__GetMaxItemCount_x                                 0x891DE0
#define EQ_Item__GetHeldItem_x                                     0x890670
#define EQ_Item__GetAugmentFitBySlot_x                             0x88E670

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x548A10
#define EQ_LoadingS__Array_x                                       0xBE9130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x62E3D0
#define EQ_PC__GetAlternateAbilityId_x                             0x89E1C0
#define EQ_PC__GetCombatAbility_x                                  0x89E830
#define EQ_PC__GetCombatAbilityTimer_x                             0x89E8A0
#define EQ_PC__GetItemRecastTimer_x                                0x6304C0
#define EQ_PC__HasLoreItem_x                                       0x627730
#define EQ_PC__AlertInventoryChanged_x                             0x6269F0
#define EQ_PC__GetPcZoneClient_x                                   0x652550
#define EQ_PC__RemoveMyAffect_x                                    0x6336C0
#define EQ_PC__GetKeyRingItems_x                                   0x89F140
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89EEC0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89F430

// EQItemList 
#define EQItemList__EQItemList_x                                   0x593BE0
#define EQItemList__add_object_x                                   0x5BF5C0
#define EQItemList__add_item_x                                     0x5941F0
#define EQItemList__delete_item_x                                  0x594240
#define EQItemList__FreeItemList_x                                 0x594140

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x527BF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6455B0
#define EQPlayer__dEQPlayer_x                                      0x638CD0
#define EQPlayer__DoAttack_x                                       0x64D210
#define EQPlayer__EQPlayer_x                                       0x639380
#define EQPlayer__SetNameSpriteState_x                             0x63D5E0
#define EQPlayer__SetNameSpriteTint_x                              0x63E4B0
#define PlayerBase__HasProperty_j_x                                0x975AA0
#define EQPlayer__IsTargetable_x                                   0x975F40
#define EQPlayer__CanSee_x                                         0x975DA0
#define EQPlayer__CanSee1_x                                        0x975E70
#define PlayerBase__GetVisibilityLineSegment_x                     0x975B60

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64FFE0
#define PlayerZoneClient__GetLevel_x                               0x652590
#define PlayerZoneClient__IsValidTeleport_x                        0x5C0710
#define PlayerZoneClient__LegalPlayerRace_x                        0x541EA0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6482B0
#define EQPlayerManager__GetSpawnByName_x                          0x6482D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x648360

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60C680
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60C6C0
#define KeypressHandler__ClearCommandStateArray_x                  0x60DAB0
#define KeypressHandler__HandleKeyDown_x                           0x60DAD0
#define KeypressHandler__HandleKeyUp_x                             0x60DB70
#define KeypressHandler__SaveKeymapping_x                          0x60DF50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7640E0
#define MapViewMap__SaveEx_x                                       0x767480
#define MapViewMap__SetZoom_x                                      0x76BB50

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B2560

// StringTable 
#define StringTable__getString_x                                   0x8AD4B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x633330
#define PcZoneClient__RemovePetEffect_x                            0x633960
#define PcZoneClient__HasAlternateAbility_x                        0x62D6B0
#define PcZoneClient__GetCurrentMod_x                              0x4E2380
#define PcZoneClient__GetModCap_x                                  0x4E2280
#define PcZoneClient__CanEquipItem_x                               0x62DD60
#define PcZoneClient__GetItemByID_x                                0x630940
#define PcZoneClient__GetItemByItemClass_x                         0x630A90
#define PcZoneClient__RemoveBuffEffect_x                           0x633980
#define PcZoneClient__BandolierSwap_x                              0x62E990

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C53C0

//IconCache
#define IconCache__GetIcon_x                                       0x704DA0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6FC850
#define CContainerMgr__CloseContainer_x                            0x6FCB20
#define CContainerMgr__OpenExperimentContainer_x                   0x6FD5A0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BF540

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x600F50

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75A500
#define CLootWnd__RequestLootSlot_x                                0x7598B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x561020
#define EQ_Spell__SpellAffects_x                                   0x561490
#define EQ_Spell__SpellAffectBase_x                                0x561250
#define EQ_Spell__IsStackable_x                                    0x4C6F70
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6D90
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4190
#define EQ_Spell__IsSPAStacking_x                                  0x5622C0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5617E0
#define EQ_Spell__IsNoRemove_x                                     0x4C6F50
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5622D0
#define __IsResEffectSpell_x                                       0x4C6200

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA9D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8BCAE0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x804E40
#define CTargetWnd__WndNotification_x                              0x8046D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8049A0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x803830

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x809520

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x525620

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55C590
#define EqSoundManager__PlayScriptMp3_x                            0x55C6F0
#define EqSoundManager__SoundAssistPlay_x                          0x66AC90
#define EqSoundManager__WaveInstancePlay_x                         0x66A200

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5195B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92EB70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5506F0
#define CAltAbilityData__GetMercMaxRank_x                          0x550690
#define CAltAbilityData__GetMaxRank_x                              0x545B20

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FF060

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6D70
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FF9E0
#define CharacterBase__CreateItemIndex_x                           0x607140
#define CharacterBase__GetItemPossession_x                         0x4B4040
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C5190
#define CharacterBase__GetEffectId_x                               0x4C6D20

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E4A90
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E52B0

//messages
#define msg_spell_worn_off_x                                       0x585930
#define msg_new_text_x                                             0x57A740
#define __msgTokenTextParam_x                                      0x587F80
#define msgTokenText_x                                             0x5881D0

//SpellManager
#define SpellManager__vftable_x                                    0xAB0A18
#define SpellManager__SpellManager_x                               0x66DFB0
#define Spellmanager__LoadTextSpells_x                             0x66E880
#define SpellManager__GetSpellByGroupAndRank_x                     0x66E180

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x979A20

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5000C0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58BDA0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x61FFB0
#define ItemGlobalIndex__IsValidIndex_x                            0x500120

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8BD420
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8BD6A0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7530C0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x700FD0
#define CCursorAttachment__Deactivate_x                            0x701FA0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x941140
#define CEQSuiteTextureLoader__GetTexture_x                        0x940E00

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FD170

//IString
#define IString__Append_x                                          0x4EEF30

//Camera
#define CDisplay__cameraType_x                                     0xDC2B14
#define EverQuest__Cameras_x                                       0xE85830

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5057A0
#define LootFiltersManager__GetItemFilterData_x                    0x505090
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5050C0
#define LootFiltersManager__SetItemLootFilter_x                    0x5052E0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7AD560

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97F6C0
#define CResolutionHandler__GetWindowedStyle_x                     0x665920

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F9620

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CFC40

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7197C0
#define CGroupWnd__UpdateDisplay_x                                 0x718B20

//ItemBase
#define ItemBase__IsLore_x                                         0x893120
#define ItemBase__IsLoreEquipped_x                                 0x893190

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
