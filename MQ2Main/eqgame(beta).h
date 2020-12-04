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
#define __ExpectedVersionDate                                     "Nov 19 2020"
#define __ExpectedVersionTime                                     "04:19:09"
#define __ActualVersionDate_x                                      0xAF5550
#define __ActualVersionTime_x                                      0xAF5544
#define __ActualVersionBuild_x                                     0xAE3554

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642E30
#define __MemChecker1_x                                            0x8F6370
#define __MemChecker2_x                                            0x6B3350
#define __MemChecker3_x                                            0x6B32A0
#define __MemChecker4_x                                            0x84C3C0
#define __EncryptPad0_x                                            0xC2B9D0
#define __EncryptPad1_x                                            0xC89218
#define __EncryptPad2_x                                            0xC3BD98
#define __EncryptPad3_x                                            0xC3B998
#define __EncryptPad4_x                                            0xC797A8
#define __EncryptPad5_x                                            0xF4C0E8
#define __AC1_x                                                    0x80AF76
#define __AC2_x                                                    0x5FC1DF
#define __AC3_x                                                    0x603830
#define __AC4_x                                                    0x6077E0
#define __AC5_x                                                    0x60DADF
#define __AC6_x                                                    0x611F96
#define __AC7_x                                                    0x5FBC50
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
#define __do_loot_x                                                0x5C7BB0
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
#define __ScreenMode_x                                             0xDEB4A8
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
#define __gfMaxZoomCameraDistance_x                                0xAED170
#define __gfMaxCameraDistance_x                                    0xB15DE0
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
#define pinstCamActor_x                                            0xDEB498
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
#define pinstViewActor_x                                           0xDEB494
#define pinstWorldData_x                                           0xE9D3A8
#define pinstZoneAddr_x                                            0xEA4EF8
#define pinstPlayerPath_x                                          0xF469B0
#define pinstTargetIndicator_x                                     0xF48318
#define EQObject_Top_x                                             0xE9D820
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEAF38
#define pinstCAchievementsWnd_x                                    0xDEB44C
#define pinstCActionsWnd_x                                         0xDEAF74
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDEB50C
#define pinstCAdvancedLootWnd_x                                    0xDEB4C0
#define pinstCAdventureLeaderboardWnd_x                            0xF55928
#define pinstCAdventureRequestWnd_x                                0xF559D8
#define pinstCAdventureStatsWnd_x                                  0xF55A88
#define pinstCAggroMeterWnd_x                                      0xDEB4F4
#define pinstCAlarmWnd_x                                           0xDEB478
#define pinstCAlertHistoryWnd_x                                    0xDEAEEC
#define pinstCAlertStackWnd_x                                      0xDEB4DC
#define pinstCAlertWnd_x                                           0xDEB4F0
#define pinstCAltStorageWnd_x                                      0xF55DE8
#define pinstCAudioTriggersWindow_x                                0xC9F788
#define pinstCAuraWnd_x                                            0xDEB4C4
#define pinstCAvaZoneWnd_x                                         0xDEAEE4
#define pinstCBandolierWnd_x                                       0xDEB508
#define pinstCBankWnd_x                                            0xDEACAC
#define pinstCBarterMerchantWnd_x                                  0xF57028
#define pinstCBarterSearchWnd_x                                    0xF570D8
#define pinstCBarterWnd_x                                          0xF57188
#define pinstCBazaarConfirmationWnd_x                              0xDEB48C
#define pinstCBazaarSearchWnd_x                                    0xDEAF3C
#define pinstCBazaarWnd_x                                          0xDEB458
#define pinstCBlockedBuffWnd_x                                     0xDEB4D0
#define pinstCBlockedPetBuffWnd_x                                  0xDEB4F8
#define pinstCBodyTintWnd_x                                        0xDEB400
#define pinstCBookWnd_x                                            0xDEB540
#define pinstCBreathWnd_x                                          0xDEAF50
#define pinstCBuffWindowNORMAL_x                                   0xDEB4B8
#define pinstCBuffWindowSHORT_x                                    0xDEB4BC
#define pinstCBugReportWnd_x                                       0xDEACA8
#define pinstCButtonWnd_x                                          0x15DA578
#define pinstCCastingWnd_x                                         0xDEB534
#define pinstCCastSpellWnd_x                                       0xDEAF48
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEB40C
#define pinstCChatWindowManager_x                                  0xF57C48
#define pinstCClaimWnd_x                                           0xF57DA0
#define pinstCColorPickerWnd_x                                     0xDEAF04
#define pinstCCombatAbilityWnd_x                                   0xDEB468
#define pinstCCombatSkillsSelectWnd_x                              0xDEB420
#define pinstCCompassWnd_x                                         0xDEAFEC
#define pinstCConfirmationDialog_x                                 0xF5CCA0
#define pinstCContainerMgr_x                                       0xDEB3FC
#define pinstCContextMenuManager_x                                 0x15DA2C8
#define pinstCCursorAttachment_x                                   0xDEB520
#define pinstCDynamicZoneWnd_x                                     0xF58368
#define pinstCEditLabelWnd_x                                       0xDEB4AC
#define pinstCEQMainWnd_x                                          0xF585B0
#define pinstCEventCalendarWnd_x                                   0xDEAF40
#define pinstCExtendedTargetWnd_x                                  0xDEB4D8
#define pinstCPlayerCustomizationWnd_x                             0xDEB424
#define pinstCFactionWnd_x                                         0xDEB444
#define pinstCFellowshipWnd_x                                      0xF587B0
#define pinstCFileSelectionWnd_x                                   0xDEAEFC
#define pinstCFindItemWnd_x                                        0xDEB434
#define pinstCFindLocationWnd_x                                    0xF58908
#define pinstCFriendsWnd_x                                         0xDEB438
#define pinstCGemsGameWnd_x                                        0xDEB440
#define pinstCGiveWnd_x                                            0xDEB47C
#define pinstCGroupSearchFiltersWnd_x                              0xDEB510
#define pinstCGroupSearchWnd_x                                     0xF58D00
#define pinstCGroupWnd_x                                           0xF58DB0
#define pinstCGuildBankWnd_x                                       0xF58E60
#define pinstCGuildCreationWnd_x                                   0xF58F10
#define pinstCGuildMgmtWnd_x                                       0xF58FC0
#define pinstCharacterCreation_x                                   0xDEB42C
#define pinstCHelpWnd_x                                            0xDEB480
#define pinstCHeritageSelectionWnd_x                               0xDEB430
#define pinstCHotButtonWnd_x                                       0xF5B118
#define pinstCHotButtonWnd1_x                                      0xF5B118
#define pinstCHotButtonWnd2_x                                      0xF5B11C
#define pinstCHotButtonWnd3_x                                      0xF5B120
#define pinstCHotButtonWnd4_x                                      0xF5B124
#define pinstCIconSelectionWnd_x                                   0xDEB518
#define pinstCInspectWnd_x                                         0xDEB4FC
#define pinstCInventoryWnd_x                                       0xDEB4C8
#define pinstCInvSlotMgr_x                                         0xDEAF2C
#define pinstCItemDisplayManager_x                                 0xF5B6A8
#define pinstCItemExpTransferWnd_x                                 0xF5B7D8
#define pinstCItemOverflowWnd_x                                    0xDEAF44
#define pinstCJournalCatWnd_x                                      0xDEAF18
#define pinstCJournalNPCWnd_x                                      0xDEAED8
#define pinstCJournalTextWnd_x                                     0xDEAED8
#define pinstCKeyRingWnd_x                                         0xDEB530
#define pinstCLargeDialogWnd_x                                     0xF5D920
#define pinstCLayoutCopyWnd_x                                      0xF5BB28
#define pinstCLFGuildWnd_x                                         0xF5BBD8
#define pinstCLoadskinWnd_x                                        0xDEB45C
#define pinstCLootFiltersCopyWnd_x                                 0xCBBEE8
#define pinstCLootFiltersWnd_x                                     0xDEB4E0
#define pinstCLootSettingsWnd_x                                    0xDEB504
#define pinstCLootWnd_x                                            0xDEAF1C
#define pinstCMailAddressBookWnd_x                                 0xDEAF30
#define pinstCMailCompositionWnd_x                                 0xDEAF0C
#define pinstCMailIgnoreListWnd_x                                  0xDEAF34
#define pinstCMailWnd_x                                            0xDEAEF4
#define pinstCManageLootWnd_x                                      0xDEC3A0
#define pinstCMapToolbarWnd_x                                      0xDEB488
#define pinstCMapViewWnd_x                                         0xDEB450
#define pinstCMarketplaceWnd_x                                     0xDEB4E4
#define pinstCMerchantWnd_x                                        0xDEAF28
#define pinstCMIZoneSelectWnd_x                                    0xF5C410
#define pinstCMusicPlayerWnd_x                                     0xDEAEC8
#define pinstCNameChangeMercWnd_x                                  0xDEB484
#define pinstCNameChangePetWnd_x                                   0xDEB454
#define pinstCNameChangeWnd_x                                      0xDEB49C
#define pinstCNoteWnd_x                                            0xDEB460
#define pinstCObjectPreviewWnd_x                                   0xDEB500
#define pinstCOptionsWnd_x                                         0xDEB470
#define pinstCPetInfoWnd_x                                         0xDEAEF0
#define pinstCPetitionQWnd_x                                       0xDEB41C
#define pinstCPlayerNotesWnd_x                                     0xDEB404
#define pinstCPlayerWnd_x                                          0xDEAEE8
#define pinstCPopupWndManager_x                                    0xF5CCA0
#define pinstCProgressionSelectionWnd_x                            0xF5CD50
#define pinstCPurchaseGroupWnd_x                                   0xDEACBC
#define pinstCPurchaseWnd_x                                        0xDEB538
#define pinstCPvPLeaderboardWnd_x                                  0xF5CE00
#define pinstCPvPStatsWnd_x                                        0xF5CEB0
#define pinstCQuantityWnd_x                                        0xDEAED4
#define pinstCRaceChangeWnd_x                                      0xDEB4CC
#define pinstCRaidOptionsWnd_x                                     0xDEB514
#define pinstCRaidWnd_x                                            0xDEAF24
#define pinstCRealEstateItemsWnd_x                                 0xDEB448
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEB3F0
#define pinstCRealEstateManageWnd_x                                0xDEACC0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEAEE0
#define pinstCRealEstatePlotSearchWnd_x                            0xDEAEF8
#define pinstCRealEstatePurchaseWnd_x                              0xDEAF14
#define pinstCRespawnWnd_x                                         0xDEB4EC
#define pinstCRewardSelectionWnd_x                                 0xF5D5F8
#define pinstCSelectorWnd_x                                        0xDEB418
#define pinstCSendMoneyWnd_x                                       0xDEB490
#define pinstCServerListWnd_x                                      0xDEAF20
#define pinstCSkillsSelectWnd_x                                    0xDEB414
#define pinstCSkillsWnd_x                                          0xDEB3F8
#define pinstCSocialEditWnd_x                                      0xDEB52C
#define pinstCSocialWnd_x                                          0xDEB474
#define pinstCSpellBookWnd_x                                       0xDEB464
#define pinstCStoryWnd_x                                           0xDEAF70
#define pinstCTargetOfTargetWnd_x                                  0xF5EC58
#define pinstCTargetWnd_x                                          0xDEB4E8
#define pinstCTaskOverlayWnd_x                                     0xDEACB0
#define pinstCTaskSelectWnd_x                                      0xF5EDB0
#define pinstCTaskManager_x                                        0xCBC828
#define pinstCTaskTemplateSelectWnd_x                              0xF5EE60
#define pinstCTaskWnd_x                                            0xF5EF10
#define pinstCTextEntryWnd_x                                       0xDEB53C
#define pinstCTimeLeftWnd_x                                        0xDEB410
#define pinstCTipWndCONTEXT_x                                      0xF5F114
#define pinstCTipWndOFDAY_x                                        0xF5F110
#define pinstCTitleWnd_x                                           0xF5F1C0
#define pinstCTrackingWnd_x                                        0xDEB4D4
#define pinstCTradeskillWnd_x                                      0xF5F328
#define pinstCTradeWnd_x                                           0xDEB408
#define pinstCTrainWnd_x                                           0xDEAF10
#define pinstCTributeBenefitWnd_x                                  0xF5F528
#define pinstCTributeMasterWnd_x                                   0xF5F5D8
#define pinstCTributeTrophyWnd_x                                   0xF5F688
#define pinstCVideoModesWnd_x                                      0xDEACB4
#define pinstCVoiceMacroWnd_x                                      0xF488D0
#define pinstCVoteResultsWnd_x                                     0xDEB43C
#define pinstCVoteWnd_x                                            0xDEB428
#define pinstCWebManager_x                                         0xF48F4C
#define pinstCZoneGuideWnd_x                                       0xDEACB8
#define pinstCZonePathWnd_x                                        0xDEAED0

#define pinstEQSuiteTextureLoader_x                                0xC89B38
#define pinstItemIconCache_x                                       0xF58568
#define pinstLootFiltersManager_x                                  0xCBBF98
#define pinstRewardSelectionWnd_x                                  0xF5D5F8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C32A0
#define __CastRay2_x                                               0x5C32F0
#define __ConvertItemTags_x                                        0x5DEFB0
#define __CleanItemTags_x                                          0x47D2A0
#define __DoesFileExist_x                                          0x8F93A0
#define __EQGetTime_x                                              0x8F5FA0
#define __ExecuteCmd_x                                             0x5BBB90
#define __FixHeading_x                                             0x98BA60
#define __FlushDxKeyboard_x                                        0x6AF1F0
#define __GameLoop_x                                               0x6B2520
#define __get_bearing_x                                            0x5C2E00
#define __get_melee_range_x                                        0x5C34E0
#define __GetAnimationCache_x                                      0x7178C0
#define __GetGaugeValueFromEQ_x                                    0x809420
#define __GetLabelFromEQ_x                                         0x80AF00
#define __GetXTargetType_x                                         0x98D520
#define __HandleMouseWheel_x                                       0x6B3400
#define __HeadingDiff_x                                            0x98BAD0
#define __HelpPath_x                                               0xF43E04
#define __LoadFrontEnd_x                                           0x6AF830
#define __NewUIINI_x                                               0x8090F0
#define __ProcessGameEvents_x                                      0x623E70
#define __ProcessMouseEvent_x                                      0x623600
#define __SaveColors_x                                             0x55CB10
#define __STMLToText_x                                             0x92ED10
#define __ToggleKeyRingItem_x                                      0x51B420
#define CMemoryMappedFile__SetFile_x                               0xA7ADB0
#define CrashDetected_x                                            0x6B12E0
#define DrawNetStatus_x                                            0x650320
#define Expansion_HoT_x                                            0xEA5D48
#define Teleport_Table_Size_x                                      0xE9D7E0
#define Teleport_Table_x                                           0xE9DCB0
#define Util__FastTime_x                                           0x8F5B70
#define __CopyLayout_x                                             0x63E4D0
#define __WndProc_x                                                0x6B17E0
#define __ProcessKeyboardEvent_x                                   0x6B0D80

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490690
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499690
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499460
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493C30
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493080

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564C60
#define AltAdvManager__IsAbilityReady_x                            0x563A00
#define AltAdvManager__GetAAById_x                                 0x563D90
#define AltAdvManager__CanTrainAbility_x                           0x563E00
#define AltAdvManager__CanSeeAbility_x                             0x564160

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB1C0
#define CharacterZoneClient__HasSkill_x                            0x4D6040
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7760
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2920
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBDB0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA110
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA1F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA2D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4A10
#define CharacterZoneClient__BardCastBard_x                        0x4C7440
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF7C0
#define CharacterZoneClient__GetEffect_x                           0x4BBCF0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5A80
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5B50
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5BA0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5CF0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5ED0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3CF0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D86C0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8140

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8FA0
#define CBankWnd__WndNotification_x                                0x6D8D80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6640

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92C4F0
#define CButtonWnd__CButtonWnd_x                                   0x92B100

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706AC0
#define CChatManager__InitContextMenu_x                            0x6FFBF0
#define CChatManager__FreeChatWindow_x                             0x705600
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9C10
#define CChatManager__SetLockedActiveChatWindow_x                  0x706740
#define CChatManager__CreateChatWindow_x                           0x705C40

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9D20

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93F6D0
#define CContextMenu__dCContextMenu_x                              0x93F910
#define CContextMenu__AddMenuItem_x                                0x93F920
#define CContextMenu__RemoveMenuItem_x                             0x93FC30
#define CContextMenu__RemoveAllMenuItems_x                         0x93FC50
#define CContextMenu__CheckMenuItem_x                              0x93FCD0
#define CContextMenu__SetMenuItem_x                                0x93FB50
#define CContextMenu__AddSeparator_x                               0x93FAB0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x940270
#define CContextMenuManager__RemoveMenu_x                          0x9402E0
#define CContextMenuManager__PopupMenu_x                           0x9403A0
#define CContextMenuManager__Flush_x                               0x940210
#define CContextMenuManager__GetMenu_x                             0x49B8C0
#define CContextMenuManager__CreateDefaultMenu_x                   0x712220

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D0C80
#define CChatService__GetFriendName_x                              0x8D0C90

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7072F0
#define CChatWindow__Clear_x                                       0x7085C0
#define CChatWindow__WndNotification_x                             0x708D50
#define CChatWindow__AddHistory_x                                  0x707E80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93CB20
#define CComboWnd__Draw_x                                          0x93C010
#define CComboWnd__GetCurChoice_x                                  0x93C960
#define CComboWnd__GetListRect_x                                   0x93C4C0
#define CComboWnd__GetTextRect_x                                   0x93CB90
#define CComboWnd__InsertChoice_x                                  0x93C650
#define CComboWnd__SetColors_x                                     0x93C620
#define CComboWnd__SetChoice_x                                     0x93C930
#define CComboWnd__GetItemCount_x                                  0x93C970
#define CComboWnd__GetCurChoiceText_x                              0x93C9B0
#define CComboWnd__GetChoiceText_x                                 0x93C980
#define CComboWnd__InsertChoiceAtIndex_x                           0x93C6F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70FC30
#define CContainerWnd__vftable_x                                   0xAFE744
#define CContainerWnd__SetContainer_x                              0x711180

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x557470
#define CDisplay__PreZoneMainUI_x                                  0x557480
#define CDisplay__CleanGameUI_x                                    0x55C8D0
#define CDisplay__GetClickedActor_x                                0x54F8D0
#define CDisplay__GetUserDefinedColor_x                            0x547F40
#define CDisplay__GetWorldFilePath_x                               0x551340
#define CDisplay__is3dON_x                                         0x54C530
#define CDisplay__ReloadUI_x                                       0x556980
#define CDisplay__WriteTextHD2_x                                   0x54C320
#define CDisplay__TrueDistance_x                                   0x553000
#define CDisplay__SetViewActor_x                                   0x54F1F0
#define CDisplay__GetFloorHeight_x                                 0x54C5F0
#define CDisplay__SetRenderWindow_x                                0x54AF70
#define CDisplay__ToggleScreenshotMode_x                           0x54ECC0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95F640

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x942BE0
#define CEditWnd__EnsureCaretVisible_x                             0x944DB0
#define CEditWnd__GetCaretPt_x                                     0x943D60
#define CEditWnd__GetCharIndexPt_x                                 0x943B10
#define CEditWnd__GetDisplayString_x                               0x9439B0
#define CEditWnd__GetHorzOffset_x                                  0x942280
#define CEditWnd__GetLineForPrintableChar_x                        0x944CB0
#define CEditWnd__GetSelStartPt_x                                  0x943DC0
#define CEditWnd__GetSTMLSafeText_x                                0x9437D0
#define CEditWnd__PointFromPrintableChar_x                         0x9448E0
#define CEditWnd__SelectableCharFromPoint_x                        0x944A50
#define CEditWnd__SetEditable_x                                    0x943E90
#define CEditWnd__SetWindowTextA_x                                 0x943550
#define CEditWnd__ReplaceSelection_x                               0x944550
#define CEditWnd__ReplaceSelection1_x                              0x9444D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611470
#define CEverQuest__ClickedPlayer_x                                0x603610
#define CEverQuest__CreateTargetIndicator_x                        0x620FE0
#define CEverQuest__DeleteTargetIndicator_x                        0x621070
#define CEverQuest__DoTellWindow_x                                 0x4E9E00
#define CEverQuest__OutputTextToLog_x                              0x4EA0D0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8770
#define CEverQuest__dsp_chat_x                                     0x4EA460
#define CEverQuest__trimName_x                                     0x61D190
#define CEverQuest__Emote_x                                        0x611CD0
#define CEverQuest__EnterZone_x                                    0x60BDD0
#define CEverQuest__GetBodyTypeDesc_x                              0x616720
#define CEverQuest__GetClassDesc_x                                 0x616D60
#define CEverQuest__GetClassThreeLetterCode_x                      0x617360
#define CEverQuest__GetDeityDesc_x                                 0x61F830
#define CEverQuest__GetLangDesc_x                                  0x617520
#define CEverQuest__GetRaceDesc_x                                  0x616D40
#define CEverQuest__InterpretCmd_x                                 0x61FE00
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FC900
#define CEverQuest__LMouseUp_x                                     0x5FAC90
#define CEverQuest__RightClickedOnPlayer_x                         0x5FD1E0
#define CEverQuest__RMouseUp_x                                     0x5FBC10
#define CEverQuest__SetGameState_x                                 0x5F8500
#define CEverQuest__UPCNotificationFlush_x                         0x61D090
#define CEverQuest__IssuePetCommand_x                              0x618930
#define CEverQuest__ReportSuccessfulHit_x                          0x613020

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7219D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x721A30
#define CGaugeWnd__Draw_x                                          0x721050

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFFB0
#define CGuild__GetGuildName_x                                     0x4AEA60
#define CGuild__GetGuildIndex_x                                    0x4AF060

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B620

//CHotButton
#define CHotButton__SetCheck_x                                     0x6327F0
#define CHotButton__SetButtonSize_x                                0x632BB0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748760
#define CInvSlotMgr__MoveItem_x                                    0x747420
#define CInvSlotMgr__SelectSlot_x                                  0x748830

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x745C10
#define CInvSlot__SliderComplete_x                                 0x743950
#define CInvSlot__GetItemBase_x                                    0x7432C0
#define CInvSlot__UpdateItem_x                                     0x743430

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74A2C0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x749450
#define CInvSlotWnd__HandleLButtonUp_x                             0x749E40

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8047A0
#define CItemDisplayWnd__UpdateStrings_x                           0x758B10
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752770
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752CA0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x759120
#define CItemDisplayWnd__AboutToShow_x                             0x758750
#define CItemDisplayWnd__WndNotification_x                         0x75A390
#define CItemDisplayWnd__RequestConvertItem_x                      0x759CD0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7577C0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x758570

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8352D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E8D0

// CLabel 
#define CLabel__Draw_x                                             0x7643D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x915220
#define CListWnd__dCListWnd_x                                      0x915540
#define CListWnd__AddColumn_x                                      0x9199C0
#define CListWnd__AddColumn1_x                                     0x919A10
#define CListWnd__AddLine_x                                        0x919DA0
#define CListWnd__AddString_x                                      0x919BA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x919780
#define CListWnd__CalculateVSBRange_x                              0x919560
#define CListWnd__ClearSel_x                                       0x91A580
#define CListWnd__ClearAllSel_x                                    0x91A5E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91B000
#define CListWnd__Compare_x                                        0x918E90
#define CListWnd__Draw_x                                           0x915670
#define CListWnd__DrawColumnSeparators_x                           0x917E60
#define CListWnd__DrawHeader_x                                     0x9182D0
#define CListWnd__DrawItem_x                                       0x9187D0
#define CListWnd__DrawLine_x                                       0x917FD0
#define CListWnd__DrawSeparator_x                                  0x917F00
#define CListWnd__EnableLine_x                                     0x917730
#define CListWnd__EnsureVisible_x                                  0x91AF20
#define CListWnd__ExtendSel_x                                      0x91A4B0
#define CListWnd__GetColumnTooltip_x                               0x917270
#define CListWnd__GetColumnMinWidth_x                              0x9172E0
#define CListWnd__GetColumnWidth_x                                 0x9171E0
#define CListWnd__GetCurSel_x                                      0x916B70
#define CListWnd__GetItemAtPoint_x                                 0x9179B0
#define CListWnd__GetItemAtPoint1_x                                0x917A20
#define CListWnd__GetItemData_x                                    0x916BF0
#define CListWnd__GetItemHeight_x                                  0x916FB0
#define CListWnd__GetItemIcon_x                                    0x916D80
#define CListWnd__GetItemRect_x                                    0x917820
#define CListWnd__GetItemText_x                                    0x916C30
#define CListWnd__GetSelList_x                                     0x91A630
#define CListWnd__GetSeparatorRect_x                               0x917C60
#define CListWnd__InsertLine_x                                     0x91A190
#define CListWnd__RemoveLine_x                                     0x91A2E0
#define CListWnd__SetColors_x                                      0x919530
#define CListWnd__SetColumnJustification_x                         0x919260
#define CListWnd__SetColumnLabel_x                                 0x919B40
#define CListWnd__SetColumnWidth_x                                 0x919180
#define CListWnd__SetCurSel_x                                      0x91A3F0
#define CListWnd__SetItemColor_x                                   0x91ABD0
#define CListWnd__SetItemData_x                                    0x91AB90
#define CListWnd__SetItemText_x                                    0x91A7A0
#define CListWnd__ShiftColumnSeparator_x                           0x919320
#define CListWnd__Sort_x                                           0x919010
#define CListWnd__ToggleSel_x                                      0x91A420
#define CListWnd__SetColumnsSizable_x                              0x9193D0
#define CListWnd__SetItemWnd_x                                     0x91AA50
#define CListWnd__GetItemWnd_x                                     0x916DD0
#define CListWnd__SetItemIcon_x                                    0x91A820
#define CListWnd__CalculateCustomWindowPositions_x                 0x919880
#define CListWnd__SetVScrollPos_x                                  0x919160

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779AA0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7781B0
#define CMapViewWnd__HandleLButtonDown_x                           0x7751F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799DB0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A690
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79ABC0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79DB80
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x798920
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A3750
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7999D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E5D0
#define CPacketScrambler__hton_x                                   0x89E5C0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x934300
#define CSidlManager__FindScreenPieceTemplate_x                    0x934710
#define CSidlManager__FindScreenPieceTemplate1_x                   0x934500
#define CSidlManager__CreateLabel_x                                0x7FB9A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x937670
#define CSidlManager__CreateXWndFromTemplate1_x                    0x937850
#define CSidlManager__CreateXWnd_x                                 0x7FB8D0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FBEA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x930DE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x930CE0
#define CSidlScreenWnd__ConvertToRes_x                             0x95A180
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9307D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9304C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x930590
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x930660
#define CSidlScreenWnd__DrawSidlPiece_x                            0x931280
#define CSidlScreenWnd__EnableIniStorage_x                         0x931750
#define CSidlScreenWnd__GetSidlPiece_x                             0x931470
#define CSidlScreenWnd__Init1_x                                    0x9300C0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9317A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9322E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92F4C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x931E60
#define CSidlScreenWnd__StoreIniVis_x                              0x9321C0
#define CSidlScreenWnd__WndNotification_x                          0x931190
#define CSidlScreenWnd__GetChildItem_x                             0x9316D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920DD0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DA198

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x698540
#define CSkillMgr__GetSkillCap_x                                   0x698720
#define CSkillMgr__GetNameToken_x                                  0x697CC0
#define CSkillMgr__IsActivatedSkill_x                              0x697E00
#define CSkillMgr__IsCombatSkill_x                                 0x697D40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x941060
#define CSliderWnd__SetValue_x                                     0x940ED0
#define CSliderWnd__SetNumTicks_x                                  0x940F30

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801B70

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9499E0
#define CStmlWnd__ParseSTML_x                                      0x94AD30
#define CStmlWnd__CalculateHSBRange_x                              0x94AB00
#define CStmlWnd__CalculateVSBRange_x                              0x94AA80
#define CStmlWnd__CanBreakAtCharacter_x                            0x94EE40
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94FAD0
#define CStmlWnd__ForceParseNow_x                                  0x949FD0
#define CStmlWnd__GetNextTagPiece_x                                0x94EDA0
#define CStmlWnd__GetSTMLText_x                                    0x50CBF0
#define CStmlWnd__GetVisibleText_x                                 0x949FF0
#define CStmlWnd__InitializeWindowVariables_x                      0x94F920
#define CStmlWnd__MakeStmlColorTag_x                               0x949050
#define CStmlWnd__MakeWndNotificationTag_x                         0x9490C0
#define CStmlWnd__SetSTMLText_x                                    0x948100
#define CStmlWnd__StripFirstSTMLLines_x                            0x950BD0
#define CStmlWnd__UpdateHistoryString_x                            0x94FCE0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x947220
#define CTabWnd__DrawCurrentPage_x                                 0x947950
#define CTabWnd__DrawTab_x                                         0x947670
#define CTabWnd__GetCurrentPage_x                                  0x946A20
#define CTabWnd__GetPageInnerRect_x                                0x946C60
#define CTabWnd__GetTabInnerRect_x                                 0x946BA0
#define CTabWnd__GetTabRect_x                                      0x946A50
#define CTabWnd__InsertPage_x                                      0x946E70
#define CTabWnd__RemovePage_x                                      0x946FE0
#define CTabWnd__SetPage_x                                         0x946CE0
#define CTabWnd__SetPageRect_x                                     0x947160
#define CTabWnd__UpdatePage_x                                      0x947530
#define CTabWnd__GetPageFromTabIndex_x                             0x9475B0
#define CTabWnd__GetCurrentTabIndex_x                              0x946A10

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75ED50
#define CPageWnd__SetTabText_x                                     0x946560
#define CPageWnd__FlashTab_x                                       0x9465C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9310

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91DC80
#define CTextureFont__GetTextExtent_x                              0x91DE40

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC690
#define CHtmlComponentWnd__ValidateUri_x                           0x73D010
#define CHtmlWnd__SetClientCallbacks_x                             0x637C50
#define CHtmlWnd__AddObserver_x                                    0x637C70
#define CHtmlWnd__RemoveObserver_x                                 0x637CD0
#define Window__getProgress_x                                      0x853960
#define Window__getStatus_x                                        0x853980
#define Window__getURI_x                                           0x853990

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x956F90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90ACF0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9A50
#define CXStr__CXStr1_x                                            0x507EC0
#define CXStr__CXStr3_x                                            0x8F1F60
#define CXStr__dCXStr_x                                            0x4783D0
#define CXStr__operator_equal_x                                    0x8F2190
#define CXStr__operator_equal1_x                                   0x8F21D0
#define CXStr__operator_plus_equal1_x                              0x8F2C60
#define CXStr__SetString_x                                         0x8F4B50
#define CXStr__operator_char_p_x                                   0x8F26D0
#define CXStr__GetChar_x                                           0x8F44A0
#define CXStr__Delete_x                                            0x8F3D50
#define CXStr__GetUnicode_x                                        0x8F4510
#define CXStr__GetLength_x                                         0x47D650
#define CXStr__Mid_x                                               0x47D660
#define CXStr__Insert_x                                            0x8F4570
#define CXStr__FindNext_x                                          0x8F41C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93F2E0
#define CXWnd__BringToTop_x                                        0x924550
#define CXWnd__Center_x                                            0x9240D0
#define CXWnd__ClrFocus_x                                          0x923EE0
#define CXWnd__Destroy_x                                           0x923F90
#define CXWnd__DoAllDrawing_x                                      0x920560
#define CXWnd__DrawChildren_x                                      0x920530
#define CXWnd__DrawColoredRect_x                                   0x9209C0
#define CXWnd__DrawTooltip_x                                       0x91F080
#define CXWnd__DrawTooltipAtPoint_x                                0x91F140
#define CXWnd__GetBorderFrame_x                                    0x920820
#define CXWnd__GetChildWndAt_x                                     0x9245F0
#define CXWnd__GetClientClipRect_x                                 0x9227E0
#define CXWnd__GetScreenClipRect_x                                 0x9228B0
#define CXWnd__GetScreenRect_x                                     0x922A50
#define CXWnd__GetRelativeRect_x                                   0x922B10
#define CXWnd__GetTooltipRect_x                                    0x920A10
#define CXWnd__GetWindowTextA_x                                    0x49CFB0
#define CXWnd__IsActive_x                                          0x921140
#define CXWnd__IsDescendantOf_x                                    0x923430
#define CXWnd__IsReallyVisible_x                                   0x923460
#define CXWnd__IsType_x                                            0x924C70
#define CXWnd__Move_x                                              0x9234C0
#define CXWnd__Move1_x                                             0x923570
#define CXWnd__ProcessTransition_x                                 0x924080
#define CXWnd__Refade_x                                            0x923850
#define CXWnd__Resize_x                                            0x923AF0
#define CXWnd__Right_x                                             0x924310
#define CXWnd__SetFocus_x                                          0x923EA0
#define CXWnd__SetFont_x                                           0x923F10
#define CXWnd__SetKeyTooltip_x                                     0x924A80
#define CXWnd__SetMouseOver_x                                      0x921960
#define CXWnd__StartFade_x                                         0x923310
#define CXWnd__GetChildItem_x                                      0x924760
#define CXWnd__SetParent_x                                         0x9231F0
#define CXWnd__Minimize_x                                          0x923B60

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95B200

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9274B0
#define CXWndManager__DrawWindows_x                                0x9274D0
#define CXWndManager__GetKeyboardFlags_x                           0x929CC0
#define CXWndManager__HandleKeyboardMsg_x                          0x929870
#define CXWndManager__RemoveWnd_x                                  0x929EF0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92A470

// CDBStr
#define CDBStr__GetString_x                                        0x546F10

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFF20
#define EQ_Character__Cur_HP_x                                     0x4D3080
#define EQ_Character__Cur_Mana_x                                   0x4DA7D0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2F90
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3930
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3A80
#define EQ_Character__GetHPRegen_x                                 0x4E06D0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0CD0
#define EQ_Character__GetManaRegen_x                               0x4E1110
#define EQ_Character__Max_Endurance_x                              0x65ECC0
#define EQ_Character__Max_HP_x                                     0x4D2EB0
#define EQ_Character__Max_Mana_x                                   0x65EAC0
#define EQ_Character__doCombatAbility_x                            0x6610B0
#define EQ_Character__UseSkill_x                                   0x4E2F20
#define EQ_Character__GetConLevel_x                                0x657250
#define EQ_Character__IsExpansionFlag_x                            0x5BA370
#define EQ_Character__TotalEffect_x                                0x4C6D30
#define EQ_Character__GetPCSpellAffect_x                           0x4C3CE0
#define EQ_Character__SpellDuration_x                              0x4C3810
#define EQ_Character__MySpellDuration_x                            0x4B2260
#define EQ_Character__GetAdjustedSkill_x                           0x4D5E00
#define EQ_Character__GetBaseSkill_x                               0x4D6DA0
#define EQ_Character__CanUseItem_x                                 0x4DAAE0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BDC70

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x674F90

//PcClient
#define PcClient__vftable_x                                        0xAF21C4
#define PcClient__PcClient_x                                       0x6549C0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA990
#define CCharacterListWnd__EnterWorld_x                            0x4BA360
#define CCharacterListWnd__Quit_x                                  0x4BA0B0
#define CCharacterListWnd__UpdateList_x                            0x4BA550

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x638E30
#define EQ_Item__CreateItemTagString_x                             0x897BD0
#define EQ_Item__IsStackable_x                                     0x89C830
#define EQ_Item__GetImageNum_x                                     0x899750
#define EQ_Item__CreateItemClient_x                                0x638070
#define EQ_Item__GetItemValue_x                                    0x89AA20
#define EQ_Item__ValueSellMerchant_x                               0x89E1C0
#define EQ_Item__IsKeyRingItem_x                                   0x89C150
#define EQ_Item__CanGoInBag_x                                      0x638F50
#define EQ_Item__IsEmpty_x                                         0x89BC90
#define EQ_Item__GetMaxItemCount_x                                 0x89AE30
#define EQ_Item__GetHeldItem_x                                     0x899620
#define EQ_Item__GetAugmentFitBySlot_x                             0x897440

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565960
#define EQ_LoadingS__Array_x                                       0xC13130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65F5C0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A75C0
#define EQ_PC__GetCombatAbility_x                                  0x8A7C30
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7CA0
#define EQ_PC__GetItemRecastTimer_x                                0x661630
#define EQ_PC__HasLoreItem_x                                       0x657AC0
#define EQ_PC__AlertInventoryChanged_x                             0x656B90
#define EQ_PC__GetPcZoneClient_x                                   0x684010
#define EQ_PC__RemoveMyAffect_x                                    0x664860
#define EQ_PC__GetKeyRingItems_x                                   0x8A8570
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A82F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8870

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C07F0
#define EQItemList__add_object_x                                   0x5EDE30
#define EQItemList__add_item_x                                     0x5C0D50
#define EQItemList__delete_item_x                                  0x5C0DA0
#define EQItemList__FreeItemList_x                                 0x5C0CA0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5439C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x676890
#define EQPlayer__dEQPlayer_x                                      0x669C10
#define EQPlayer__DoAttack_x                                       0x67E7A0
#define EQPlayer__EQPlayer_x                                       0x66A2D0
#define EQPlayer__SetNameSpriteState_x                             0x66E5A0
#define EQPlayer__SetNameSpriteTint_x                              0x66F480
#define PlayerBase__HasProperty_j_x                                0x989E70
#define EQPlayer__IsTargetable_x                                   0x98A310
#define EQPlayer__CanSee_x                                         0x98A170
#define EQPlayer__CanSee1_x                                        0x98A240
#define PlayerBase__GetVisibilityLineSegment_x                     0x989F30

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x681AA0
#define PlayerZoneClient__GetLevel_x                               0x684050
#define PlayerZoneClient__IsValidTeleport_x                        0x5EEFA0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E760

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x679670
#define EQPlayerManager__GetSpawnByName_x                          0x679720
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6797B0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C720
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C7A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C7E0
#define KeypressHandler__ClearCommandStateArray_x                  0x63DBD0
#define KeypressHandler__HandleKeyDown_x                           0x63DBF0
#define KeypressHandler__HandleKeyUp_x                             0x63DC90
#define KeypressHandler__SaveKeymapping_x                          0x63E0E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x775910
#define MapViewMap__SaveEx_x                                       0x778CD0
#define MapViewMap__SetZoom_x                                      0x77D390

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BBC20

// StringTable 
#define StringTable__getString_x                                   0x8B6B80

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6644D0
#define PcZoneClient__RemovePetEffect_x                            0x664B00
#define PcZoneClient__HasAlternateAbility_x                        0x65E8F0
#define PcZoneClient__GetCurrentMod_x                              0x4E6040
#define PcZoneClient__GetModCap_x                                  0x4E5F40
#define PcZoneClient__CanEquipItem_x                               0x65EFA0
#define PcZoneClient__GetItemByID_x                                0x661AA0
#define PcZoneClient__GetItemByItemClass_x                         0x661BF0
#define PcZoneClient__RemoveBuffEffect_x                           0x664B20
#define PcZoneClient__BandolierSwap_x                              0x65FB80
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6615D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F3BD0

//IconCache
#define IconCache__GetIcon_x                                       0x7172C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70EDD0
#define CContainerMgr__CloseContainer_x                            0x70F0A0
#define CContainerMgr__OpenExperimentContainer_x                   0x70FB20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CE050

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x630FB0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76BE60
#define CLootWnd__RequestLootSlot_x                                0x76B130

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D2F0
#define EQ_Spell__SpellAffects_x                                   0x58D760
#define EQ_Spell__SpellAffectBase_x                                0x58D520
#define EQ_Spell__IsStackable_x                                    0x4CAAC0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA8E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7BF0
#define EQ_Spell__IsSPAStacking_x                                  0x58E5B0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DAC0
#define EQ_Spell__IsNoRemove_x                                     0x4CAAA0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E5C0
#define __IsResEffectSpell_x                                       0x4C9D80

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD510

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C62C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814EC0
#define CTargetWnd__WndNotification_x                              0x814700
#define CTargetWnd__RefreshTargetBuffs_x                           0x8149D0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813880

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x819530
#define CTaskWnd__ConfirmAbandonTask_x                             0x81C170

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x541410
#define CTaskManager__HandleMessage_x                              0x53F890
#define CTaskManager__GetTaskStatus_x                              0x5414C0
#define CTaskManager__GetElementDescription_x                      0x541540

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5883C0
#define EqSoundManager__PlayScriptMp3_x                            0x588680
#define EqSoundManager__SoundAssistPlay_x                          0x69C4A0
#define EqSoundManager__WaveInstancePlay_x                         0x69BA10

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5327B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x945A70
#define CTextureAnimation__Draw_x                                  0x945C70

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9419C0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D480
#define CAltAbilityData__GetMercMaxRank_x                          0x56D410
#define CAltAbilityData__GetMaxRank_x                              0x562880

//CTargetRing
#define CTargetRing__Cast_x                                        0x62F0E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA8C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x519600
#define CharacterBase__CreateItemIndex_x                           0x637200
#define CharacterBase__GetItemPossession_x                         0x505720
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE930
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE990
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5DC0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F65F0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F66A0

//messages
#define msg_spell_worn_off_x                                       0x5B2390
#define msg_new_text_x                                             0x5A6CB0
#define __msgTokenTextParam_x                                      0x5B4630
#define msgTokenText_x                                             0x5B4880

//SpellManager
#define SpellManager__vftable_x                                    0xADA574
#define SpellManager__SpellManager_x                               0x69F7D0
#define Spellmanager__LoadTextSpells_x                             0x6A00C0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F9A0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98DE10

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519C80
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8850
#define ItemGlobalIndex__IsEquippedLocation_x                      0x650180
#define ItemGlobalIndex__IsValidIndex_x                            0x519D10

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C6C60
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6EE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764710

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7134C0
#define CCursorAttachment__AttachToCursor1_x                       0x713500
#define CCursorAttachment__Deactivate_x                            0x7144F0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9386B0
#define CSidlManagerBase__CreatePageWnd_x                          0x937EA0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x934120
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9340B0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x955C30
#define CEQSuiteTextureLoader__GetTexture_x                        0x9558F0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516B50
#define CFindItemWnd__WndNotification_x                            0x517630
#define CFindItemWnd__Update_x                                     0x5181A0
#define CFindItemWnd__PickupSelectedItem_x                         0x516380

//IString
#define IString__Append_x                                          0x506F50

//Camera
#define CDisplay__cameraType_x                                     0xDEACC4
#define EverQuest__Cameras_x                                       0xEA60A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F580
#define LootFiltersManager__GetItemFilterData_x                    0x51EE90
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51EEC0
#define LootFiltersManager__SetItemLootFilter_x                    0x51F0E0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BBE50

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x993A70
#define CResolutionHandler__GetWindowedStyle_x                     0x6970B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70BA80

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DC250
#define CDistillerInfo__Instance_x                                 0x8DC1F0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A9B0
#define CGroupWnd__UpdateDisplay_x                                 0x729D00

//ItemBase
#define ItemBase__IsLore_x                                         0x89C200
#define ItemBase__IsLoreEquipped_x                                 0x89C270

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EDD90
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EDED0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EDF30

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C7F0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x690160

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D260

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9620
#define FactionManagerClient__HandleFactionMessage_x               0x4F9C90
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FA290
#define FactionManagerClient__GetMaxFaction_x                      0x4FA2AF
#define FactionManagerClient__GetMinFaction_x                      0x4FA260

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5056F0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91CCA0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C2C0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x505960

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56C910

//CTargetManager
#define CTargetManager__Get_x                                      0x6A3000

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C7F0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A90D0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C0C40

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF43738

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF6F0
#define CAAWnd__UpdateSelected_x                                   0x6BBF60
#define CAAWnd__Update_x                                           0x6BEA10

//CXRect
#define CXRect__operator_and_x                                     0x721A90

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483250

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
