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
#define __ExpectedVersionDate                                     "Nov 20 2020"
#define __ExpectedVersionTime                                     "04:19:16"
#define __ActualVersionDate_x                                      0xAF553C
#define __ActualVersionTime_x                                      0xAF5530
#define __ActualVersionBuild_x                                     0xAE3534

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6428B0
#define __MemChecker1_x                                            0x8F5DE0
#define __MemChecker2_x                                            0x6B2E30
#define __MemChecker3_x                                            0x6B2D80
#define __MemChecker4_x                                            0x84BC10
#define __EncryptPad0_x                                            0xC2B9D0
#define __EncryptPad1_x                                            0xC89218
#define __EncryptPad2_x                                            0xC3BD98
#define __EncryptPad3_x                                            0xC3B998
#define __EncryptPad4_x                                            0xC797A8
#define __EncryptPad5_x                                            0xF4C0E8
#define __AC1_x                                                    0x80A8E6
#define __AC2_x                                                    0x5FBFBF
#define __AC3_x                                                    0x603610
#define __AC4_x                                                    0x6075C0
#define __AC5_x                                                    0x60D8BF
#define __AC6_x                                                    0x611D76
#define __AC7_x                                                    0x5FBA30
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1972FC

// Direct Input
#define DI8__Main_x                                                0xF4C110
#define DI8__Keyboard_x                                            0xF4C114
#define DI8__Mouse_x                                               0xF4C0F4
#define DI8__Mouse_Copy_x                                          0xEA49E4
#define DI8__Mouse_Check_x                                         0xF49C3C
#define __AutoSkillArray_x                                         0xEA5900
#define __Attack_x                                                 0xF43733
#define __Autofire_x                                               0xF43734
#define __BindList_x                                               0xC1A400
#define g_eqCommandStates_x                                        0xC1B180
#define __Clicks_x                                                 0xEA4A9C
#define __CommandList_x                                            0xC1BD40
#define __CurrentMapLabel_x                                        0xF5C154
#define __CurrentSocial_x                                          0xC037D4
#define __DoAbilityList_x                                          0xEDB254
#define __do_loot_x                                                0x5C7A00
#define __DrawHandler_x                                            0x15DB148
#define __GroupCount_x                                             0xE9D502
#define __Guilds_x                                                 0xEA3920
#define __gWorld_x                                                 0xE9DC98
#define __HWnd_x                                                   0xF4C0F8
#define __heqmain_x                                                0xF4C0D0
#define __InChatMode_x                                             0xEA49CC
#define __LastTell_x                                               0xEA6950
#define __LMouseHeldTime_x                                         0xEA4B08
#define __Mouse_x                                                  0xF4C0FC
#define __MouseLook_x                                              0xEA4A62
#define __MouseEventTime_x                                         0xF44214
#define __gpbCommandEvent_x                                        0xE9D758
#define __NetStatusToggle_x                                        0xEA4A65
#define __PCNames_x                                                0xEA5EFC
#define __RangeAttackReady_x                                       0xEA5BE4
#define __RMouseHeldTime_x                                         0xEA4B04
#define __RunWalkState_x                                           0xEA49D0
#define __ScreenMode_x                                             0xDEB4AC
#define __ScreenX_x                                                0xEA4984
#define __ScreenY_x                                                0xEA4980
#define __ScreenXMax_x                                             0xEA4988
#define __ScreenYMax_x                                             0xEA498C
#define __ServerHost_x                                             0xE9D92B
#define __ServerName_x                                             0xEDB214
#define __ShiftKeyDown_x                                           0xEA5060
#define __ShowNames_x                                              0xEA5DA0
#define EverQuestInfo__bSocialChanged_x                            0xEDB29C
#define __Socials_x                                                0xEDB314
#define __SubscriptionType_x                                       0xFA0418
#define __TargetAggroHolder_x                                      0xF5EB08
#define __ZoneType_x                                               0xEA4E60
#define __GroupAggro_x                                             0xF5EB48
#define __LoginName_x                                              0xF498CC
#define __Inviter_x                                                0xF436B0
#define __AttackOnAssist_x                                         0xEA5D5C
#define __UseTellWindows_x                                         0xEA6094
#define __gfMaxZoomCameraDistance_x                                0xAED150
#define __gfMaxCameraDistance_x                                    0xB15DE8
#define __pulAutoRun_x                                             0xEA4A80
#define __pulForward_x                                             0xEA60CC
#define __pulBackward_x                                            0xEA60D0
#define __pulTurnRight_x                                           0xEA60D4
#define __pulTurnLeft_x                                            0xEA60D8
#define __pulStrafeLeft_x                                          0xEA60DC
#define __pulStrafeRight_x                                         0xEA60E0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9FCB8
#define instEQZoneInfo_x                                           0xEA4C58
#define pinstActiveBanker_x                                        0xE9DC44
#define pinstActiveCorpse_x                                        0xE9DC3C
#define pinstActiveGMaster_x                                       0xE9DC40
#define pinstActiveMerchant_x                                      0xE9DA34
#define pinstAltAdvManager_x                                       0xDEBEF0
#define pinstBandageTarget_x                                       0xE9DC54
#define pinstCamActor_x                                            0xDEB49C
#define pinstCDBStr_x                                              0xDEAC0C
#define pinstCDisplay_x                                            0xE9DCA4
#define pinstCEverQuest_x                                          0xF49190
#define pinstEverQuestInfo_x                                       0xEA4978
#define pinstCharData_x                                            0xE9D744
#define pinstCharSpawn_x                                           0xE9DC8C
#define pinstControlledMissile_x                                   0xE9DCA0
#define pinstControlledPlayer_x                                    0xE9DC8C
#define pinstCResolutionHandler_x                                  0x15DB378
#define pinstCSidlManager_x                                        0x15DA310
#define pinstCXWndManager_x                                        0x15DA30C
#define instDynamicZone_x                                          0xEA37F8
#define pinstDZMember_x                                            0xEA3908
#define pinstDZTimerInfo_x                                         0xEA390C
#define pinstEqLogin_x                                             0xF49218
#define instEQMisc_x                                               0xDEAB50
#define pinstEQSoundManager_x                                      0xDECEC0
#define pinstEQSpellStrings_x                                      0xCAD458
#define instExpeditionLeader_x                                     0xEA3842
#define instExpeditionName_x                                       0xEA3882
#define pinstGroup_x                                               0xE9D4FE
#define pinstImeManager_x                                          0x15DA308
#define pinstLocalPlayer_x                                         0xE9D824
#define pinstMercenaryData_x                                       0xF45D10
#define pinstMercenaryStats_x                                      0xF5EBD4
#define pinstModelPlayer_x                                         0xE9DC4C
#define pinstPCData_x                                              0xE9D744
#define pinstSkillMgr_x                                            0xF47E70
#define pinstSpawnManager_x                                        0xF46918
#define pinstSpellManager_x                                        0xF480B0
#define pinstSpellSets_x                                           0xF3C35C
#define pinstStringTable_x                                         0xE9D74C
#define pinstSwitchManager_x                                       0xE9D258
#define pinstTarget_x                                              0xE9DC88
#define pinstTargetObject_x                                        0xE9DC94
#define pinstTargetSwitch_x                                        0xE9DCAC
#define pinstTaskMember_x                                          0xDEA9E0
#define pinstTrackTarget_x                                         0xE9DC90
#define pinstTradeTarget_x                                         0xE9DC48
#define instTributeActive_x                                        0xDEAB71
#define pinstViewActor_x                                           0xDEB498
#define pinstWorldData_x                                           0xE9D3A8
#define pinstZoneAddr_x                                            0xEA4EF8
#define pinstPlayerPath_x                                          0xF469B0
#define pinstTargetIndicator_x                                     0xF48318
#define EQObject_Top_x                                             0xE9D820
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEAF3C
#define pinstCAchievementsWnd_x                                    0xDEB450
#define pinstCActionsWnd_x                                         0xDEAF78
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDEB510
#define pinstCAdvancedLootWnd_x                                    0xDEB4C4
#define pinstCAdventureLeaderboardWnd_x                            0xF55928
#define pinstCAdventureRequestWnd_x                                0xF559D8
#define pinstCAdventureStatsWnd_x                                  0xF55A88
#define pinstCAggroMeterWnd_x                                      0xDEB4F8
#define pinstCAlarmWnd_x                                           0xDEB47C
#define pinstCAlertHistoryWnd_x                                    0xDEAEF0
#define pinstCAlertStackWnd_x                                      0xDEB4E0
#define pinstCAlertWnd_x                                           0xDEB4F4
#define pinstCAltStorageWnd_x                                      0xF55DE8
#define pinstCAudioTriggersWindow_x                                0xC9F788
#define pinstCAuraWnd_x                                            0xDEB4C8
#define pinstCAvaZoneWnd_x                                         0xDEAEE8
#define pinstCBandolierWnd_x                                       0xDEB50C
#define pinstCBankWnd_x                                            0xDEACB0
#define pinstCBarterMerchantWnd_x                                  0xF57028
#define pinstCBarterSearchWnd_x                                    0xF570D8
#define pinstCBarterWnd_x                                          0xF57188
#define pinstCBazaarConfirmationWnd_x                              0xDEB490
#define pinstCBazaarSearchWnd_x                                    0xDEAF40
#define pinstCBazaarWnd_x                                          0xDEB45C
#define pinstCBlockedBuffWnd_x                                     0xDEB4D4
#define pinstCBlockedPetBuffWnd_x                                  0xDEB4FC
#define pinstCBodyTintWnd_x                                        0xDEB404
#define pinstCBookWnd_x                                            0xDEB544
#define pinstCBreathWnd_x                                          0xDEAF54
#define pinstCBuffWindowNORMAL_x                                   0xDEB4BC
#define pinstCBuffWindowSHORT_x                                    0xDEB4C0
#define pinstCBugReportWnd_x                                       0xDEACAC
#define pinstCButtonWnd_x                                          0x15DA578
#define pinstCCastingWnd_x                                         0xDEB538
#define pinstCCastSpellWnd_x                                       0xDEAF4C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEB410
#define pinstCChatWindowManager_x                                  0xF57C48
#define pinstCClaimWnd_x                                           0xF57DA0
#define pinstCColorPickerWnd_x                                     0xDEAF08
#define pinstCCombatAbilityWnd_x                                   0xDEB46C
#define pinstCCombatSkillsSelectWnd_x                              0xDEB424
#define pinstCCompassWnd_x                                         0xDEAF8C
#define pinstCConfirmationDialog_x                                 0xF5CCA0
#define pinstCContainerMgr_x                                       0xDEB400
#define pinstCContextMenuManager_x                                 0x15DA2C8
#define pinstCCursorAttachment_x                                   0xDEB524
#define pinstCDynamicZoneWnd_x                                     0xF58368
#define pinstCEditLabelWnd_x                                       0xDEB4B0
#define pinstCEQMainWnd_x                                          0xF585B0
#define pinstCEventCalendarWnd_x                                   0xDEAF44
#define pinstCExtendedTargetWnd_x                                  0xDEB4DC
#define pinstCPlayerCustomizationWnd_x                             0xDEB428
#define pinstCFactionWnd_x                                         0xDEB448
#define pinstCFellowshipWnd_x                                      0xF587B0
#define pinstCFileSelectionWnd_x                                   0xDEAF00
#define pinstCFindItemWnd_x                                        0xDEB438
#define pinstCFindLocationWnd_x                                    0xF58908
#define pinstCFriendsWnd_x                                         0xDEB43C
#define pinstCGemsGameWnd_x                                        0xDEB444
#define pinstCGiveWnd_x                                            0xDEB480
#define pinstCGroupSearchFiltersWnd_x                              0xDEB514
#define pinstCGroupSearchWnd_x                                     0xF58D00
#define pinstCGroupWnd_x                                           0xF58DB0
#define pinstCGuildBankWnd_x                                       0xF58E60
#define pinstCGuildCreationWnd_x                                   0xF58F10
#define pinstCGuildMgmtWnd_x                                       0xF58FC0
#define pinstCharacterCreation_x                                   0xDEB430
#define pinstCHelpWnd_x                                            0xDEB484
#define pinstCHeritageSelectionWnd_x                               0xDEB434
#define pinstCHotButtonWnd_x                                       0xF5B118
#define pinstCHotButtonWnd1_x                                      0xF5B118
#define pinstCHotButtonWnd2_x                                      0xF5B11C
#define pinstCHotButtonWnd3_x                                      0xF5B120
#define pinstCHotButtonWnd4_x                                      0xF5B124
#define pinstCIconSelectionWnd_x                                   0xDEB51C
#define pinstCInspectWnd_x                                         0xDEB500
#define pinstCInventoryWnd_x                                       0xDEB4CC
#define pinstCInvSlotMgr_x                                         0xDEAF30
#define pinstCItemDisplayManager_x                                 0xF5B6A8
#define pinstCItemExpTransferWnd_x                                 0xF5B7D8
#define pinstCItemOverflowWnd_x                                    0xDEAF48
#define pinstCJournalCatWnd_x                                      0xDEAF1C
#define pinstCJournalNPCWnd_x                                      0xDEAEDC
#define pinstCJournalTextWnd_x                                     0xDEAEDC
#define pinstCKeyRingWnd_x                                         0xDEB534
#define pinstCLargeDialogWnd_x                                     0xF5D920
#define pinstCLayoutCopyWnd_x                                      0xF5BB28
#define pinstCLFGuildWnd_x                                         0xF5BBD8
#define pinstCLoadskinWnd_x                                        0xDEB460
#define pinstCLootFiltersCopyWnd_x                                 0xCBBEE8
#define pinstCLootFiltersWnd_x                                     0xDEB4E4
#define pinstCLootSettingsWnd_x                                    0xDEB508
#define pinstCLootWnd_x                                            0xDEAF20
#define pinstCMailAddressBookWnd_x                                 0xDEAF34
#define pinstCMailCompositionWnd_x                                 0xDEAF10
#define pinstCMailIgnoreListWnd_x                                  0xDEAF38
#define pinstCMailWnd_x                                            0xDEAEF8
#define pinstCManageLootWnd_x                                      0xDEC3A0
#define pinstCMapToolbarWnd_x                                      0xDEB48C
#define pinstCMapViewWnd_x                                         0xDEB454
#define pinstCMarketplaceWnd_x                                     0xDEB4E8
#define pinstCMerchantWnd_x                                        0xDEAF2C
#define pinstCMIZoneSelectWnd_x                                    0xF5C410
#define pinstCMusicPlayerWnd_x                                     0xDEACCC
#define pinstCNameChangeMercWnd_x                                  0xDEB488
#define pinstCNameChangePetWnd_x                                   0xDEB458
#define pinstCNameChangeWnd_x                                      0xDEB4A0
#define pinstCNoteWnd_x                                            0xDEB464
#define pinstCObjectPreviewWnd_x                                   0xDEB504
#define pinstCOptionsWnd_x                                         0xDEB474
#define pinstCPetInfoWnd_x                                         0xDEAEF4
#define pinstCPetitionQWnd_x                                       0xDEB420
#define pinstCPlayerNotesWnd_x                                     0xDEB408
#define pinstCPlayerWnd_x                                          0xDEAEEC
#define pinstCPopupWndManager_x                                    0xF5CCA0
#define pinstCProgressionSelectionWnd_x                            0xF5CD50
#define pinstCPurchaseGroupWnd_x                                   0xDEACC0
#define pinstCPurchaseWnd_x                                        0xDEB53C
#define pinstCPvPLeaderboardWnd_x                                  0xF5CE00
#define pinstCPvPStatsWnd_x                                        0xF5CEB0
#define pinstCQuantityWnd_x                                        0xDEAED8
#define pinstCRaceChangeWnd_x                                      0xDEB4D0
#define pinstCRaidOptionsWnd_x                                     0xDEB518
#define pinstCRaidWnd_x                                            0xDEAF28
#define pinstCRealEstateItemsWnd_x                                 0xDEB44C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEAFF4
#define pinstCRealEstateManageWnd_x                                0xDEACC4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEAEE4
#define pinstCRealEstatePlotSearchWnd_x                            0xDEAEFC
#define pinstCRealEstatePurchaseWnd_x                              0xDEAF18
#define pinstCRespawnWnd_x                                         0xDEB4F0
#define pinstCRewardSelectionWnd_x                                 0xF5D5F8
#define pinstCSelectorWnd_x                                        0xDEB41C
#define pinstCSendMoneyWnd_x                                       0xDEB494
#define pinstCServerListWnd_x                                      0xDEAF24
#define pinstCSkillsSelectWnd_x                                    0xDEB418
#define pinstCSkillsWnd_x                                          0xDEB3FC
#define pinstCSocialEditWnd_x                                      0xDEB530
#define pinstCSocialWnd_x                                          0xDEB478
#define pinstCSpellBookWnd_x                                       0xDEB468
#define pinstCStoryWnd_x                                           0xDEAF74
#define pinstCTargetOfTargetWnd_x                                  0xF5EC58
#define pinstCTargetWnd_x                                          0xDEB4EC
#define pinstCTaskOverlayWnd_x                                     0xDEACB4
#define pinstCTaskSelectWnd_x                                      0xF5EDB0
#define pinstCTaskManager_x                                        0xCBC828
#define pinstCTaskTemplateSelectWnd_x                              0xF5EE60
#define pinstCTaskWnd_x                                            0xF5EF10
#define pinstCTextEntryWnd_x                                       0xDEB540
#define pinstCTimeLeftWnd_x                                        0xDEB414
#define pinstCTipWndCONTEXT_x                                      0xF5F114
#define pinstCTipWndOFDAY_x                                        0xF5F110
#define pinstCTitleWnd_x                                           0xF5F1C0
#define pinstCTrackingWnd_x                                        0xDEB4D8
#define pinstCTradeskillWnd_x                                      0xF5F328
#define pinstCTradeWnd_x                                           0xDEB40C
#define pinstCTrainWnd_x                                           0xDEAF14
#define pinstCTributeBenefitWnd_x                                  0xF5F528
#define pinstCTributeMasterWnd_x                                   0xF5F5D8
#define pinstCTributeTrophyWnd_x                                   0xF5F688
#define pinstCVideoModesWnd_x                                      0xDEACB8
#define pinstCVoiceMacroWnd_x                                      0xF488D0
#define pinstCVoteResultsWnd_x                                     0xDEB440
#define pinstCVoteWnd_x                                            0xDEB42C
#define pinstCWebManager_x                                         0xF48F4C
#define pinstCZoneGuideWnd_x                                       0xDEACBC
#define pinstCZonePathWnd_x                                        0xDEAED4

#define pinstEQSuiteTextureLoader_x                                0xC89B38
#define pinstItemIconCache_x                                       0xF58568
#define pinstLootFiltersManager_x                                  0xCBBF98
#define pinstRewardSelectionWnd_x                                  0xF5D5F8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C30F0
#define __CastRay2_x                                               0x5C3140
#define __ConvertItemTags_x                                        0x5DEE00
#define __CleanItemTags_x                                          0x47D130
#define __DoesFileExist_x                                          0x8F8E10
#define __EQGetTime_x                                              0x8F5A10
#define __ExecuteCmd_x                                             0x5BBA10
#define __FixHeading_x                                             0x98AF10
#define __FlushDxKeyboard_x                                        0x6AECD0
#define __GameLoop_x                                               0x6B2000
#define __get_bearing_x                                            0x5C2C50
#define __get_melee_range_x                                        0x5C3330
#define __GetAnimationCache_x                                      0x7172B0
#define __GetGaugeValueFromEQ_x                                    0x808D90
#define __GetLabelFromEQ_x                                         0x80A870
#define __GetXTargetType_x                                         0x98C960
#define __HandleMouseWheel_x                                       0x6B2EE0
#define __HeadingDiff_x                                            0x98AF80
#define __HelpPath_x                                               0xF43E04
#define __LoadFrontEnd_x                                           0x6AF310
#define __NewUIINI_x                                               0x808A60
#define __ProcessGameEvents_x                                      0x623C50
#define __ProcessMouseEvent_x                                      0x6233E0
#define __SaveColors_x                                             0x55CD20
#define __STMLToText_x                                             0x92E180
#define __ToggleKeyRingItem_x                                      0x51B570
#define CMemoryMappedFile__SetFile_x                               0xA7A270
#define CrashDetected_x                                            0x6B0DC0
#define DrawNetStatus_x                                            0x64FAD0
#define Expansion_HoT_x                                            0xEA5D48
#define Teleport_Table_Size_x                                      0xE9D7E0
#define Teleport_Table_x                                           0xE9DCB0
#define Util__FastTime_x                                           0x8F55E0
#define __CopyLayout_x                                             0x63DF80
#define __WndProc_x                                                0x6B12C0
#define __ProcessKeyboardEvent_x                                   0x6B0860

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490460
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499460
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499230
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A00
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564EB0
#define AltAdvManager__IsAbilityReady_x                            0x563C50
#define AltAdvManager__GetAAById_x                                 0x563FE0
#define AltAdvManager__CanTrainAbility_x                           0x564050
#define AltAdvManager__CanSeeAbility_x                             0x5643B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB030
#define CharacterZoneClient__HasSkill_x                            0x4D5EB0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D75D0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C26E0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBB70
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9F30
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA010
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA0F0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C47D0
#define CharacterZoneClient__BardCastBard_x                        0x4C7200
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF580
#define CharacterZoneClient__GetEffect_x                           0x4BBAB0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5840
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5910
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5960
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5AB0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5C90
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3A50
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8530
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7FB0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8A40
#define CBankWnd__WndNotification_x                                0x6D8820

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6310

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92B950
#define CButtonWnd__CButtonWnd_x                                   0x92A530

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706450
#define CChatManager__InitContextMenu_x                            0x6FF580
#define CChatManager__FreeChatWindow_x                             0x704F90
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E98C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x7060D0
#define CChatManager__CreateChatWindow_x                           0x7055D0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E99D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93EC30
#define CContextMenu__dCContextMenu_x                              0x93EE70
#define CContextMenu__AddMenuItem_x                                0x93EE80
#define CContextMenu__RemoveMenuItem_x                             0x93F190
#define CContextMenu__RemoveAllMenuItems_x                         0x93F1B0
#define CContextMenu__CheckMenuItem_x                              0x93F230
#define CContextMenu__SetMenuItem_x                                0x93F0B0
#define CContextMenu__AddSeparator_x                               0x93F010

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93F7D0
#define CContextMenuManager__RemoveMenu_x                          0x93F840
#define CContextMenuManager__PopupMenu_x                           0x93F900
#define CContextMenuManager__Flush_x                               0x93F770
#define CContextMenuManager__GetMenu_x                             0x49B710
#define CContextMenuManager__CreateDefaultMenu_x                   0x711C10

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x89AE80
#define CChatService__GetFriendName_x                              0x8D0610

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x706C80
#define CChatWindow__Clear_x                                       0x707F50
#define CChatWindow__WndNotification_x                             0x7086E0
#define CChatWindow__AddHistory_x                                  0x707810

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93C090
#define CComboWnd__Draw_x                                          0x93B570
#define CComboWnd__GetCurChoice_x                                  0x93BED0
#define CComboWnd__GetListRect_x                                   0x93BA30
#define CComboWnd__GetTextRect_x                                   0x93C100
#define CComboWnd__InsertChoice_x                                  0x93BBC0
#define CComboWnd__SetColors_x                                     0x93BB90
#define CComboWnd__SetChoice_x                                     0x93BEA0
#define CComboWnd__GetItemCount_x                                  0x93BEE0
#define CComboWnd__GetCurChoiceText_x                              0x93BF20
#define CComboWnd__GetChoiceText_x                                 0x93BEF0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93BC60

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70F620
#define CContainerWnd__vftable_x                                   0xAFE73C
#define CContainerWnd__SetContainer_x                              0x710B70

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x557680
#define CDisplay__PreZoneMainUI_x                                  0x557690
#define CDisplay__CleanGameUI_x                                    0x55CAE0
#define CDisplay__GetClickedActor_x                                0x54FAE0
#define CDisplay__GetUserDefinedColor_x                            0x548150
#define CDisplay__GetWorldFilePath_x                               0x551550
#define CDisplay__is3dON_x                                         0x54C740
#define CDisplay__ReloadUI_x                                       0x556B90
#define CDisplay__WriteTextHD2_x                                   0x54C530
#define CDisplay__TrueDistance_x                                   0x553210
#define CDisplay__SetViewActor_x                                   0x54F400
#define CDisplay__GetFloorHeight_x                                 0x54C800
#define CDisplay__SetRenderWindow_x                                0x54B180
#define CDisplay__ToggleScreenshotMode_x                           0x54EED0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95E9A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x942140
#define CEditWnd__EnsureCaretVisible_x                             0x944310
#define CEditWnd__GetCaretPt_x                                     0x9432C0
#define CEditWnd__GetCharIndexPt_x                                 0x943070
#define CEditWnd__GetDisplayString_x                               0x942F10
#define CEditWnd__GetHorzOffset_x                                  0x9417E0
#define CEditWnd__GetLineForPrintableChar_x                        0x944210
#define CEditWnd__GetSelStartPt_x                                  0x943320
#define CEditWnd__GetSTMLSafeText_x                                0x942D30
#define CEditWnd__PointFromPrintableChar_x                         0x943E40
#define CEditWnd__SelectableCharFromPoint_x                        0x943FB0
#define CEditWnd__SetEditable_x                                    0x9433F0
#define CEditWnd__SetWindowTextA_x                                 0x942AB0
#define CEditWnd__ReplaceSelection_x                               0x943AB0
#define CEditWnd__ReplaceSelection1_x                              0x943A30

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611250
#define CEverQuest__ClickedPlayer_x                                0x6033F0
#define CEverQuest__CreateTargetIndicator_x                        0x620DC0
#define CEverQuest__DeleteTargetIndicator_x                        0x620E50
#define CEverQuest__DoTellWindow_x                                 0x4E9AB0
#define CEverQuest__OutputTextToLog_x                              0x4E9D80
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8550
#define CEverQuest__dsp_chat_x                                     0x4EA110
#define CEverQuest__trimName_x                                     0x61CF70
#define CEverQuest__Emote_x                                        0x611AB0
#define CEverQuest__EnterZone_x                                    0x60BBB0
#define CEverQuest__GetBodyTypeDesc_x                              0x616500
#define CEverQuest__GetClassDesc_x                                 0x616B40
#define CEverQuest__GetClassThreeLetterCode_x                      0x617140
#define CEverQuest__GetDeityDesc_x                                 0x61F610
#define CEverQuest__GetLangDesc_x                                  0x617300
#define CEverQuest__GetRaceDesc_x                                  0x616B20
#define CEverQuest__InterpretCmd_x                                 0x61FBE0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FC6E0
#define CEverQuest__LMouseUp_x                                     0x5FAA70
#define CEverQuest__RightClickedOnPlayer_x                         0x5FCFC0
#define CEverQuest__RMouseUp_x                                     0x5FB9F0
#define CEverQuest__SetGameState_x                                 0x5F82E0
#define CEverQuest__UPCNotificationFlush_x                         0x61CE70
#define CEverQuest__IssuePetCommand_x                              0x618710
#define CEverQuest__ReportSuccessfulHit_x                          0x612E00

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7213C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x721420
#define CGaugeWnd__Draw_x                                          0x720A40

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFDB0
#define CGuild__GetGuildName_x                                     0x4AE860
#define CGuild__GetGuildIndex_x                                    0x4AEE60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B080

//CHotButton
#define CHotButton__SetCheck_x                                     0x632520
#define CHotButton__SetButtonSize_x                                0x6328E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748120
#define CInvSlotMgr__MoveItem_x                                    0x746DF0
#define CInvSlotMgr__SelectSlot_x                                  0x7481F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x745620
#define CInvSlot__SliderComplete_x                                 0x743370
#define CInvSlot__GetItemBase_x                                    0x742D00
#define CInvSlot__UpdateItem_x                                     0x742E70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x749C70
#define CInvSlotWnd__CInvSlotWnd_x                                 0x748E10
#define CInvSlotWnd__HandleLButtonUp_x                             0x7497F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x804130
#define CItemDisplayWnd__UpdateStrings_x                           0x758390
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7520A0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7525B0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x758990
#define CItemDisplayWnd__AboutToShow_x                             0x757FD0
#define CItemDisplayWnd__WndNotification_x                         0x759C00
#define CItemDisplayWnd__RequestConvertItem_x                      0x759540
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x757030
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x757DF0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834C20

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E0F0

// CLabel 
#define CLabel__Draw_x                                             0x763BC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9147A0
#define CListWnd__dCListWnd_x                                      0x914AC0
#define CListWnd__AddColumn_x                                      0x918F50
#define CListWnd__AddColumn1_x                                     0x918FA0
#define CListWnd__AddLine_x                                        0x919330
#define CListWnd__AddString_x                                      0x919130
#define CListWnd__CalculateFirstVisibleLine_x                      0x918D10
#define CListWnd__CalculateVSBRange_x                              0x918AF0
#define CListWnd__ClearSel_x                                       0x919B10
#define CListWnd__ClearAllSel_x                                    0x919B70
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91A590
#define CListWnd__Compare_x                                        0x918420
#define CListWnd__Draw_x                                           0x914BF0
#define CListWnd__DrawColumnSeparators_x                           0x9173F0
#define CListWnd__DrawHeader_x                                     0x917860
#define CListWnd__DrawItem_x                                       0x917D60
#define CListWnd__DrawLine_x                                       0x917560
#define CListWnd__DrawSeparator_x                                  0x917490
#define CListWnd__EnableLine_x                                     0x916CC0
#define CListWnd__EnsureVisible_x                                  0x91A4B0
#define CListWnd__ExtendSel_x                                      0x919A40
#define CListWnd__GetColumnTooltip_x                               0x916800
#define CListWnd__GetColumnMinWidth_x                              0x916870
#define CListWnd__GetColumnWidth_x                                 0x916770
#define CListWnd__GetCurSel_x                                      0x916100
#define CListWnd__GetItemAtPoint_x                                 0x916F40
#define CListWnd__GetItemAtPoint1_x                                0x916FB0
#define CListWnd__GetItemData_x                                    0x916180
#define CListWnd__GetItemHeight_x                                  0x916540
#define CListWnd__GetItemIcon_x                                    0x916310
#define CListWnd__GetItemRect_x                                    0x916DB0
#define CListWnd__GetItemText_x                                    0x9161C0
#define CListWnd__GetSelList_x                                     0x919BC0
#define CListWnd__GetSeparatorRect_x                               0x9171F0
#define CListWnd__InsertLine_x                                     0x919720
#define CListWnd__RemoveLine_x                                     0x919870
#define CListWnd__SetColors_x                                      0x918AC0
#define CListWnd__SetColumnJustification_x                         0x9187F0
#define CListWnd__SetColumnLabel_x                                 0x9190D0
#define CListWnd__SetColumnWidth_x                                 0x918710
#define CListWnd__SetCurSel_x                                      0x919980
#define CListWnd__SetItemColor_x                                   0x91A160
#define CListWnd__SetItemData_x                                    0x91A120
#define CListWnd__SetItemText_x                                    0x919D30
#define CListWnd__ShiftColumnSeparator_x                           0x9188B0
#define CListWnd__Sort_x                                           0x9185A0
#define CListWnd__ToggleSel_x                                      0x9199B0
#define CListWnd__SetColumnsSizable_x                              0x918960
#define CListWnd__SetItemWnd_x                                     0x919FE0
#define CListWnd__GetItemWnd_x                                     0x916360
#define CListWnd__SetItemIcon_x                                    0x919DB0
#define CListWnd__CalculateCustomWindowPositions_x                 0x918E10
#define CListWnd__SetVScrollPos_x                                  0x9186F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7793C0
#define CMapViewWnd__GetWorldCoordinates_x                         0x777AD0
#define CMapViewWnd__HandleLButtonDown_x                           0x774B10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799730
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A010
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79A540
#define CMerchantWnd__SelectRecoverySlot_x                         0x79D4E0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7982B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A30A0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799350

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89DF60
#define CPacketScrambler__hton_x                                   0x89DF50

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x933790
#define CSidlManager__FindScreenPieceTemplate_x                    0x933BA0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x933990
#define CSidlManager__CreateLabel_x                                0x7FB300
#define CSidlManager__CreateXWndFromTemplate_x                     0x936B00
#define CSidlManager__CreateXWndFromTemplate1_x                    0x936CE0
#define CSidlManager__CreateXWnd_x                                 0x7FB230
#define CSidlManager__CreateHotButtonWnd_x                         0x7FB7F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x930250
#define CSidlScreenWnd__CalculateVSBRange_x                        0x930150
#define CSidlScreenWnd__ConvertToRes_x                             0x9594F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92FC40
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92F930
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92FA00
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92FAD0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9306F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x930BC0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9308E0
#define CSidlScreenWnd__Init1_x                                    0x92F530
#define CSidlScreenWnd__LoadIniInfo_x                              0x930C10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x931770
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92E930
#define CSidlScreenWnd__StoreIniInfo_x                             0x9312E0
#define CSidlScreenWnd__StoreIniVis_x                              0x931650
#define CSidlScreenWnd__WndNotification_x                          0x930600
#define CSidlScreenWnd__GetChildItem_x                             0x930B40
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920380
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DA198

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x697CF0
#define CSkillMgr__GetSkillCap_x                                   0x697ED0
#define CSkillMgr__GetNameToken_x                                  0x697470
#define CSkillMgr__IsActivatedSkill_x                              0x6975B0
#define CSkillMgr__IsCombatSkill_x                                 0x6974F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9405C0
#define CSliderWnd__SetValue_x                                     0x940430
#define CSliderWnd__SetNumTicks_x                                  0x940490

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801440

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x948F10
#define CStmlWnd__ParseSTML_x                                      0x94A260
#define CStmlWnd__CalculateHSBRange_x                              0x94A030
#define CStmlWnd__CalculateVSBRange_x                              0x949FB0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94E370
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94F000
#define CStmlWnd__ForceParseNow_x                                  0x949500
#define CStmlWnd__GetNextTagPiece_x                                0x94E2D0
#define CStmlWnd__GetSTMLText_x                                    0x50CEA0
#define CStmlWnd__GetVisibleText_x                                 0x949520
#define CStmlWnd__InitializeWindowVariables_x                      0x94EE50
#define CStmlWnd__MakeStmlColorTag_x                               0x948580
#define CStmlWnd__MakeWndNotificationTag_x                         0x9485F0
#define CStmlWnd__SetSTMLText_x                                    0x947630
#define CStmlWnd__StripFirstSTMLLines_x                            0x950100
#define CStmlWnd__UpdateHistoryString_x                            0x94F210

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946780
#define CTabWnd__DrawCurrentPage_x                                 0x946EB0
#define CTabWnd__DrawTab_x                                         0x946BD0
#define CTabWnd__GetCurrentPage_x                                  0x945F80
#define CTabWnd__GetPageInnerRect_x                                0x9461C0
#define CTabWnd__GetTabInnerRect_x                                 0x946100
#define CTabWnd__GetTabRect_x                                      0x945FB0
#define CTabWnd__InsertPage_x                                      0x9463D0
#define CTabWnd__RemovePage_x                                      0x946540
#define CTabWnd__SetPage_x                                         0x946240
#define CTabWnd__SetPageRect_x                                     0x9466C0
#define CTabWnd__UpdatePage_x                                      0x946A90
#define CTabWnd__GetPageFromTabIndex_x                             0x946B10
#define CTabWnd__GetCurrentTabIndex_x                              0x945F70

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75E5B0
#define CPageWnd__SetTabText_x                                     0x945AC0
#define CPageWnd__FlashTab_x                                       0x945B20

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9140

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91D210
#define CTextureFont__GetTextExtent_x                              0x91D3D0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6ABE90
#define CHtmlComponentWnd__ValidateUri_x                           0x73CA70
#define CHtmlWnd__SetClientCallbacks_x                             0x637940
#define CHtmlWnd__AddObserver_x                                    0x637960
#define CHtmlWnd__RemoveObserver_x                                 0x6379C0
#define Window__getProgress_x                                      0x853190
#define Window__getStatus_x                                        0x8531B0
#define Window__getURI_x                                           0x8531C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x956300

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90A310

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9700
#define CXStr__CXStr1_x                                            0x4B72C0
#define CXStr__CXStr3_x                                            0x8F1990
#define CXStr__dCXStr_x                                            0x4783B0
#define CXStr__operator_equal_x                                    0x8F1BC0
#define CXStr__operator_equal1_x                                   0x8F1C00
#define CXStr__operator_plus_equal1_x                              0x8F2690
#define CXStr__SetString_x                                         0x8F4580
#define CXStr__operator_char_p_x                                   0x8F20D0
#define CXStr__GetChar_x                                           0x8F3EB0
#define CXStr__Delete_x                                            0x8F3780
#define CXStr__GetUnicode_x                                        0x8F3F20
#define CXStr__GetLength_x                                         0x4A8EF0
#define CXStr__Mid_x                                               0x47D4E0
#define CXStr__Insert_x                                            0x8F3F80
#define CXStr__FindNext_x                                          0x8F3BF0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93E850
#define CXWnd__BringToTop_x                                        0x923AA0
#define CXWnd__Center_x                                            0x923620
#define CXWnd__ClrFocus_x                                          0x923430
#define CXWnd__Destroy_x                                           0x9234E0
#define CXWnd__DoAllDrawing_x                                      0x91FB10
#define CXWnd__DrawChildren_x                                      0x91FAE0
#define CXWnd__DrawColoredRect_x                                   0x91FF70
#define CXWnd__DrawTooltip_x                                       0x91E620
#define CXWnd__DrawTooltipAtPoint_x                                0x91E6E0
#define CXWnd__GetBorderFrame_x                                    0x91FDD0
#define CXWnd__GetChildWndAt_x                                     0x923B40
#define CXWnd__GetClientClipRect_x                                 0x921D70
#define CXWnd__GetScreenClipRect_x                                 0x921E10
#define CXWnd__GetScreenRect_x                                     0x921FC0
#define CXWnd__GetRelativeRect_x                                   0x922080
#define CXWnd__GetTooltipRect_x                                    0x91FFC0
#define CXWnd__GetWindowTextA_x                                    0x49CE30
#define CXWnd__IsActive_x                                          0x9206E0
#define CXWnd__IsDescendantOf_x                                    0x9229B0
#define CXWnd__IsReallyVisible_x                                   0x9229E0
#define CXWnd__IsType_x                                            0x924190
#define CXWnd__Move_x                                              0x922A40
#define CXWnd__Move1_x                                             0x922AF0
#define CXWnd__ProcessTransition_x                                 0x9235D0
#define CXWnd__Refade_x                                            0x922DD0
#define CXWnd__Resize_x                                            0x923050
#define CXWnd__Right_x                                             0x923860
#define CXWnd__SetFocus_x                                          0x9233F0
#define CXWnd__SetFont_x                                           0x923460
#define CXWnd__SetKeyTooltip_x                                     0x923FC0
#define CXWnd__SetMouseOver_x                                      0x920F00
#define CXWnd__StartFade_x                                         0x922890
#define CXWnd__GetChildItem_x                                      0x923CB0
#define CXWnd__SetParent_x                                         0x922760
#define CXWnd__Minimize_x                                          0x9230C0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95A570

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9269A0
#define CXWndManager__DrawWindows_x                                0x9269C0
#define CXWndManager__GetKeyboardFlags_x                           0x9291B0
#define CXWndManager__HandleKeyboardMsg_x                          0x928D60
#define CXWndManager__RemoveWnd_x                                  0x9293E0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x929950

// CDBStr
#define CDBStr__GetString_x                                        0x5470F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFCE0
#define EQ_Character__Cur_HP_x                                     0x4D2EF0
#define EQ_Character__Cur_Mana_x                                   0x4DA5F0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2D50
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3690
#define EQ_Character__GetFocusRangeModifier_x                      0x4B37E0
#define EQ_Character__GetHPRegen_x                                 0x4E04C0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0AC0
#define EQ_Character__GetManaRegen_x                               0x4E0F00
#define EQ_Character__Max_Endurance_x                              0x65E180
#define EQ_Character__Max_HP_x                                     0x4D2D20
#define EQ_Character__Max_Mana_x                                   0x65DF80
#define EQ_Character__doCombatAbility_x                            0x660570
#define EQ_Character__UseSkill_x                                   0x4E2D00
#define EQ_Character__GetConLevel_x                                0x656A80
#define EQ_Character__IsExpansionFlag_x                            0x5BA1B0
#define EQ_Character__TotalEffect_x                                0x4C6AF0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3AA0
#define EQ_Character__SpellDuration_x                              0x4C35D0
#define EQ_Character__MySpellDuration_x                            0x4B1FC0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5C70
#define EQ_Character__GetBaseSkill_x                               0x4D6C10
#define EQ_Character__CanUseItem_x                                 0x4DA900

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD4D0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6744B0

//PcClient
#define PcClient__vftable_x                                        0xAF21A4
#define PcClient__PcClient_x                                       0x6541F0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA720
#define CCharacterListWnd__EnterWorld_x                            0x4BA0F0
#define CCharacterListWnd__Quit_x                                  0x4B9E40
#define CCharacterListWnd__UpdateList_x                            0x4BA2E0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x638B00
#define EQ_Item__CreateItemTagString_x                             0x8974E0
#define EQ_Item__IsStackable_x                                     0x89C1B0
#define EQ_Item__GetImageNum_x                                     0x899040
#define EQ_Item__CreateItemClient_x                                0x637D40
#define EQ_Item__GetItemValue_x                                    0x89A360
#define EQ_Item__ValueSellMerchant_x                               0x89DB40
#define EQ_Item__IsKeyRingItem_x                                   0x89BAD0
#define EQ_Item__CanGoInBag_x                                      0x638C20
#define EQ_Item__IsEmpty_x                                         0x89B620
#define EQ_Item__GetMaxItemCount_x                                 0x89A770
#define EQ_Item__GetHeldItem_x                                     0x898F10
#define EQ_Item__GetAugmentFitBySlot_x                             0x896D40

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565BB0
#define EQ_LoadingS__Array_x                                       0xC13130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65EA80
#define EQ_PC__GetAlternateAbilityId_x                             0x8A6F80
#define EQ_PC__GetCombatAbility_x                                  0x8A75F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7660
#define EQ_PC__GetItemRecastTimer_x                                0x660AF0
#define EQ_PC__HasLoreItem_x                                       0x6572A0
#define EQ_PC__AlertInventoryChanged_x                             0x6563C0
#define EQ_PC__GetPcZoneClient_x                                   0x683440
#define EQ_PC__RemoveMyAffect_x                                    0x663D20
#define EQ_PC__GetKeyRingItems_x                                   0x8A7F30
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A7CB0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8230

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C0670
#define EQItemList__add_object_x                                   0x5EDC80
#define EQItemList__add_item_x                                     0x5C0BD0
#define EQItemList__delete_item_x                                  0x5C0C20
#define EQItemList__FreeItemList_x                                 0x5C0B20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543C40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x675DB0
#define EQPlayer__dEQPlayer_x                                      0x669120
#define EQPlayer__DoAttack_x                                       0x67DBE0
#define EQPlayer__EQPlayer_x                                       0x6697E0
#define EQPlayer__SetNameSpriteState_x                             0x66DAC0
#define EQPlayer__SetNameSpriteTint_x                              0x66E9A0
#define PlayerBase__HasProperty_j_x                                0x989310
#define EQPlayer__IsTargetable_x                                   0x9897B0
#define EQPlayer__CanSee_x                                         0x989610
#define EQPlayer__CanSee1_x                                        0x9896E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9893D0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x680EE0
#define PlayerZoneClient__GetLevel_x                               0x683480
#define PlayerZoneClient__IsValidTeleport_x                        0x5EEDF0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E970

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x678B00
#define EQPlayerManager__GetSpawnByName_x                          0x678BB0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x678C40

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C1E0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C260
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C2A0
#define KeypressHandler__ClearCommandStateArray_x                  0x63D690
#define KeypressHandler__HandleKeyDown_x                           0x63D6B0
#define KeypressHandler__HandleKeyUp_x                             0x63D750
#define KeypressHandler__SaveKeymapping_x                          0x63DBA0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x775230
#define MapViewMap__SaveEx_x                                       0x7785F0
#define MapViewMap__SetZoom_x                                      0x77CCB0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB480

// StringTable 
#define StringTable__getString_x                                   0x8B6410

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x663990
#define PcZoneClient__RemovePetEffect_x                            0x663FC0
#define PcZoneClient__HasAlternateAbility_x                        0x65DDB0
#define PcZoneClient__GetCurrentMod_x                              0x4E5E20
#define PcZoneClient__GetModCap_x                                  0x4E5D20
#define PcZoneClient__CanEquipItem_x                               0x65E460
#define PcZoneClient__GetItemByID_x                                0x660F60
#define PcZoneClient__GetItemByItemClass_x                         0x6610B0
#define PcZoneClient__RemoveBuffEffect_x                           0x663FE0
#define PcZoneClient__BandolierSwap_x                              0x65F040
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x660A90

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F39B0

//IconCache
#define IconCache__GetIcon_x                                       0x716CB0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70E7C0
#define CContainerMgr__CloseContainer_x                            0x70EA90
#define CContainerMgr__OpenExperimentContainer_x                   0x70F510

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CD940

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x630D00

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76B660
#define CLootWnd__RequestLootSlot_x                                0x76A940

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D580
#define EQ_Spell__SpellAffects_x                                   0x58D9F0
#define EQ_Spell__SpellAffectBase_x                                0x58D7B0
#define EQ_Spell__IsStackable_x                                    0x4CA930
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA750
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7980
#define EQ_Spell__IsSPAStacking_x                                  0x58E840
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DD50
#define EQ_Spell__IsNoRemove_x                                     0x4CA910
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E850
#define __IsResEffectSpell_x                                       0x4C9B40

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD330

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5BE0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814800
#define CTargetWnd__WndNotification_x                              0x814040
#define CTargetWnd__RefreshTargetBuffs_x                           0x814310
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8131A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x818E80
#define CTaskWnd__ConfirmAbandonTask_x                             0x81BAC0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x541640
#define CTaskManager__HandleMessage_x                              0x53FAB0
#define CTaskManager__GetTaskStatus_x                              0x5416F0
#define CTaskManager__GetElementDescription_x                      0x541770

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x588700
#define EqSoundManager__PlayScriptMp3_x                            0x5889C0
#define EqSoundManager__SoundAssistPlay_x                          0x69BCC0
#define EqSoundManager__WaveInstancePlay_x                         0x69B230

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532A50

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x944FD0
#define CTextureAnimation__Draw_x                                  0x9451D0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x940F20

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D6C0
#define CAltAbilityData__GetMercMaxRank_x                          0x56D650
#define CAltAbilityData__GetMaxRank_x                              0x562AD0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62EE20

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA730
#define CharacterBase__CreateItemGlobalIndex_x                     0x519780
#define CharacterBase__CreateItemIndex_x                           0x636EF0
#define CharacterBase__GetItemPossession_x                         0x505730
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE230
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE290
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F57D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6000
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F60B0

//messages
#define msg_spell_worn_off_x                                       0x5B20D0
#define msg_new_text_x                                             0x5A6A30
#define __msgTokenTextParam_x                                      0x5B4370
#define msgTokenText_x                                             0x5B45C0

//SpellManager
#define SpellManager__vftable_x                                    0xADA554
#define SpellManager__SpellManager_x                               0x69EFF0
#define Spellmanager__LoadTextSpells_x                             0x69F8E0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F1C0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98D250

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519DD0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8590
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64F930
#define ItemGlobalIndex__IsValidIndex_x                            0x519E60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C6580
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6800

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x763F00

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x712EB0
#define CCursorAttachment__AttachToCursor1_x                       0x712EF0
#define CCursorAttachment__Deactivate_x                            0x713EE0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x937B30
#define CSidlManagerBase__CreatePageWnd_x                          0x937330
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9335B0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933540

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x954C90
#define CEQSuiteTextureLoader__GetTexture_x                        0x954950

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516D30
#define CFindItemWnd__WndNotification_x                            0x517810
#define CFindItemWnd__Update_x                                     0x518350
#define CFindItemWnd__PickupSelectedItem_x                         0x516560

//IString
#define IString__Append_x                                          0x5070B0

//Camera
#define CDisplay__cameraType_x                                     0xDEACC8
#define EverQuest__Cameras_x                                       0xEA60A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F6E0
#define LootFiltersManager__GetItemFilterData_x                    0x51EFF0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51F020
#define LootFiltersManager__SetItemLootFilter_x                    0x51F240

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BB760

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x992ED0
#define CResolutionHandler__GetWindowedStyle_x                     0x696620

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70B3F0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DBC20
#define CDistillerInfo__Instance_x                                 0x8DBBC0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A3F0
#define CGroupWnd__UpdateDisplay_x                                 0x729740

//ItemBase
#define ItemBase__IsLore_x                                         0x89BB80
#define ItemBase__IsLoreEquipped_x                                 0x89BBF0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EDBE0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EDD20
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EDD80

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68BB60
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68F4C0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D4A0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9590
#define FactionManagerClient__HandleFactionMessage_x               0x4F9C00
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FA1C0
#define FactionManagerClient__GetMaxFaction_x                      0x4FA1DF
#define FactionManagerClient__GetMinFaction_x                      0x4FA190

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505700

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91C230

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C110

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x505AC0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CB60

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2800

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68BB60

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8F00

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C0AC0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF43738

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF180
#define CAAWnd__UpdateSelected_x                                   0x6BB9F0
#define CAAWnd__Update_x                                           0x6BE4A0

//CXRect
#define CXRect__operator_and_x                                     0x7214D0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4830F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

//__eqgraphics_fopen
//Jan 09 2020 EQGraphicsDX9.dll
//IDA Style Sig: E8 ? ? ? ? 83 C4 08 89 45 A0
//#define __eqgraphics_fopen_x                                       0x101473C8
static PBYTE efPattern = (PBYTE)"\xE8\x00\x00\x00\x00\x83\xC4\x08\x89\x45\xA0";
static char efMask[] = "x????xxxxxx";
