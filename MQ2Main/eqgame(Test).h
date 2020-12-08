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
#if defined(TEST)
#include "eqgame-private(test).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Dec  4 2020"
#define __ExpectedVersionTime                                     "23:49:11"
#define __ActualVersionDate_x                                      0xAF5558
#define __ActualVersionTime_x                                      0xAF554C
#define __ActualVersionBuild_x                                     0xAE356C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x643B70
#define __MemChecker1_x                                            0x8F72F0
#define __MemChecker2_x                                            0x6B43D0
#define __MemChecker3_x                                            0x6B4320
#define __MemChecker4_x                                            0x84D860
#define __EncryptPad0_x                                            0xC2B9C8
#define __EncryptPad1_x                                            0xC89210
#define __EncryptPad2_x                                            0xC3BD90
#define __EncryptPad3_x                                            0xC3B990
#define __EncryptPad4_x                                            0xC797A0
#define __EncryptPad5_x                                            0xF4C0F0
#define __AC1_x                                                    0x80C076
#define __AC2_x                                                    0x5FD28F
#define __AC3_x                                                    0x6048E0
#define __AC4_x                                                    0x608890
#define __AC5_x                                                    0x60EB8F
#define __AC6_x                                                    0x613036
#define __AC7_x                                                    0x5FCD00
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1972E0

// Direct Input
#define DI8__Main_x                                                0xF4C118
#define DI8__Keyboard_x                                            0xF4C11C
#define DI8__Mouse_x                                               0xF4C0FC
#define DI8__Mouse_Copy_x                                          0xEA49E4
#define DI8__Mouse_Check_x                                         0xF49C44
#define __AutoSkillArray_x                                         0xEA5900
#define __Attack_x                                                 0xF4372F
#define __Autofire_x                                               0xF43730
#define __BindList_x                                               0xC1A400
#define g_eqCommandStates_x                                        0xC1B180
#define __Clicks_x                                                 0xEA4A9C
#define __CommandList_x                                            0xC1BD40
#define __CurrentMapLabel_x                                        0xF5C14C
#define __CurrentSocial_x                                          0xC037D4
#define __DoAbilityList_x                                          0xEDB250
#define __do_loot_x                                                0x5C8C00
#define __DrawHandler_x                                            0x15DB140
#define __GroupCount_x                                             0xE9D502
#define __Guilds_x                                                 0xEA3920
#define __gWorld_x                                                 0xE9DC98
#define __HWnd_x                                                   0xF4C100
#define __heqmain_x                                                0xF4C0D8
#define __InChatMode_x                                             0xEA49CC
#define __LastTell_x                                               0xEA694C
#define __LMouseHeldTime_x                                         0xEA4B08
#define __Mouse_x                                                  0xF4C104
#define __MouseLook_x                                              0xEA4A62
#define __MouseEventTime_x                                         0xF44214
#define __gpbCommandEvent_x                                        0xE9D758
#define __NetStatusToggle_x                                        0xEA4A65
#define __PCNames_x                                                0xEA5EFC
#define __RangeAttackReady_x                                       0xEA5BE4
#define __RMouseHeldTime_x                                         0xEA4B04
#define __RunWalkState_x                                           0xEA49D0
#define __ScreenMode_x                                             0xDEB4B0
#define __ScreenX_x                                                0xEA4984
#define __ScreenY_x                                                0xEA4980
#define __ScreenXMax_x                                             0xEA4988
#define __ScreenYMax_x                                             0xEA498C
#define __ServerHost_x                                             0xE9D92B
#define __ServerName_x                                             0xEDB210
#define __ShiftKeyDown_x                                           0xEA5060
#define __ShowNames_x                                              0xEA5DA0
#define EverQuestInfo__bSocialChanged_x                            0xEDB298
#define __Socials_x                                                0xEDB310
#define __SubscriptionType_x                                       0xFA0410
#define __TargetAggroHolder_x                                      0xF5EB00
#define __ZoneType_x                                               0xEA4E60
#define __GroupAggro_x                                             0xF5EB40
#define __LoginName_x                                              0xF498D4
#define __Inviter_x                                                0xF436AC
#define __AttackOnAssist_x                                         0xEA5D5C
#define __UseTellWindows_x                                         0xEA6094
#define __gfMaxZoomCameraDistance_x                                0xAED168
#define __gfMaxCameraDistance_x                                    0xB15DF0
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
#define pinstCamActor_x                                            0xDEB4A4
#define pinstCDBStr_x                                              0xDEAC0C
#define pinstCDisplay_x                                            0xE9DCA4
#define pinstCEverQuest_x                                          0xF4919C
#define pinstEverQuestInfo_x                                       0xEA4978
#define pinstCharData_x                                            0xE9D744
#define pinstCharSpawn_x                                           0xE9DC8C
#define pinstControlledMissile_x                                   0xE9DCA0
#define pinstControlledPlayer_x                                    0xE9DC8C
#define pinstCResolutionHandler_x                                  0x15DB370
#define pinstCSidlManager_x                                        0x15DA308
#define pinstCXWndManager_x                                        0x15DA304
#define instDynamicZone_x                                          0xEA37F8
#define pinstDZMember_x                                            0xEA3908
#define pinstDZTimerInfo_x                                         0xEA390C
#define pinstEqLogin_x                                             0xF49220
#define instEQMisc_x                                               0xDEAB50
#define pinstEQSoundManager_x                                      0xDECEC0
#define pinstEQSpellStrings_x                                      0xCAD448
#define instExpeditionLeader_x                                     0xEA3842
#define instExpeditionName_x                                       0xEA3882
#define pinstGroup_x                                               0xE9D4FE
#define pinstImeManager_x                                          0x15DA300
#define pinstLocalPlayer_x                                         0xE9D824
#define pinstMercenaryData_x                                       0xF45D08
#define pinstMercenaryStats_x                                      0xF5EBCC
#define pinstModelPlayer_x                                         0xE9DC4C
#define pinstPCData_x                                              0xE9D744
#define pinstSkillMgr_x                                            0xF47E68
#define pinstSpawnManager_x                                        0xF46910
#define pinstSpellManager_x                                        0xF480A8
#define pinstSpellSets_x                                           0xF3C358
#define pinstStringTable_x                                         0xE9D74C
#define pinstSwitchManager_x                                       0xE9D258
#define pinstTarget_x                                              0xE9DC88
#define pinstTargetObject_x                                        0xE9DC94
#define pinstTargetSwitch_x                                        0xE9DCAC
#define pinstTaskMember_x                                          0xDEA9E0
#define pinstTrackTarget_x                                         0xE9DC90
#define pinstTradeTarget_x                                         0xE9DC48
#define instTributeActive_x                                        0xDEAB71
#define pinstViewActor_x                                           0xDEB4A0
#define pinstWorldData_x                                           0xE9D3A8
#define pinstZoneAddr_x                                            0xEA4EF8
#define pinstPlayerPath_x                                          0xF469A8
#define pinstTargetIndicator_x                                     0xF48310
#define EQObject_Top_x                                             0xE9D820
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEAF44
#define pinstCAchievementsWnd_x                                    0xDEB45C
#define pinstCActionsWnd_x                                         0xDEAF80
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDEB51C
#define pinstCAdvancedLootWnd_x                                    0xDEB4CC
#define pinstCAdventureLeaderboardWnd_x                            0xF55920
#define pinstCAdventureRequestWnd_x                                0xF559D0
#define pinstCAdventureStatsWnd_x                                  0xF55A80
#define pinstCAggroMeterWnd_x                                      0xDEB500
#define pinstCAlarmWnd_x                                           0xDEB488
#define pinstCAlertHistoryWnd_x                                    0xDEAEF4
#define pinstCAlertStackWnd_x                                      0xDEB4E8
#define pinstCAlertWnd_x                                           0xDEB4FC
#define pinstCAltStorageWnd_x                                      0xF55DE0
#define pinstCAudioTriggersWindow_x                                0xC9F778
#define pinstCAuraWnd_x                                            0xDEB4D0
#define pinstCAvaZoneWnd_x                                         0xDEAEF8
#define pinstCBandolierWnd_x                                       0xDEB514
#define pinstCBankWnd_x                                            0xDEACB8
#define pinstCBarterMerchantWnd_x                                  0xF57020
#define pinstCBarterSearchWnd_x                                    0xF570D0
#define pinstCBarterWnd_x                                          0xF57180
#define pinstCBazaarConfirmationWnd_x                              0xDEB498
#define pinstCBazaarSearchWnd_x                                    0xDEAF48
#define pinstCBazaarWnd_x                                          0xDEB464
#define pinstCBlockedBuffWnd_x                                     0xDEB4DC
#define pinstCBlockedPetBuffWnd_x                                  0xDEB504
#define pinstCBodyTintWnd_x                                        0xDEB40C
#define pinstCBookWnd_x                                            0xDEACAC
#define pinstCBreathWnd_x                                          0xDEAF58
#define pinstCBuffWindowNORMAL_x                                   0xDEB4C4
#define pinstCBuffWindowSHORT_x                                    0xDEB4C8
#define pinstCBugReportWnd_x                                       0xDEACB4
#define pinstCButtonWnd_x                                          0x15DA570
#define pinstCCastingWnd_x                                         0xDEB540
#define pinstCCastSpellWnd_x                                       0xDEAF54
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEB418
#define pinstCChatWindowManager_x                                  0xF57C40
#define pinstCClaimWnd_x                                           0xF57D98
#define pinstCColorPickerWnd_x                                     0xDEAF0C
#define pinstCCombatAbilityWnd_x                                   0xDEB478
#define pinstCCombatSkillsSelectWnd_x                              0xDEB42C
#define pinstCCompassWnd_x                                         0xDEAF84
#define pinstCConfirmationDialog_x                                 0xF5CC98
#define pinstCContainerMgr_x                                       0xDEB408
#define pinstCContextMenuManager_x                                 0x15DA2C0
#define pinstCCursorAttachment_x                                   0xDEB534
#define pinstCDynamicZoneWnd_x                                     0xF58360
#define pinstCEditLabelWnd_x                                       0xDEB4C0
#define pinstCEQMainWnd_x                                          0xF585A8
#define pinstCEventCalendarWnd_x                                   0xDEAF4C
#define pinstCExtendedTargetWnd_x                                  0xDEB4E0
#define pinstCPlayerCustomizationWnd_x                             0xDEB430
#define pinstCFactionWnd_x                                         0xDEB450
#define pinstCFellowshipWnd_x                                      0xF587A8
#define pinstCFileSelectionWnd_x                                   0xDEAF08
#define pinstCFindItemWnd_x                                        0xDEB444
#define pinstCFindLocationWnd_x                                    0xF58900
#define pinstCFriendsWnd_x                                         0xDEB440
#define pinstCGemsGameWnd_x                                        0xDEB44C
#define pinstCGiveWnd_x                                            0xDEB48C
#define pinstCGroupSearchFiltersWnd_x                              0xDEB518
#define pinstCGroupSearchWnd_x                                     0xF58CF8
#define pinstCGroupWnd_x                                           0xF58DA8
#define pinstCGuildBankWnd_x                                       0xF58E58
#define pinstCGuildCreationWnd_x                                   0xF58F08
#define pinstCGuildMgmtWnd_x                                       0xF58FB8
#define pinstCharacterCreation_x                                   0xDEB438
#define pinstCHelpWnd_x                                            0xDEB484
#define pinstCHeritageSelectionWnd_x                               0xDEB43C
#define pinstCHotButtonWnd_x                                       0xF5B110
#define pinstCHotButtonWnd1_x                                      0xF5B110
#define pinstCHotButtonWnd2_x                                      0xF5B114
#define pinstCHotButtonWnd3_x                                      0xF5B118
#define pinstCHotButtonWnd4_x                                      0xF5B11C
#define pinstCIconSelectionWnd_x                                   0xDEB528
#define pinstCInspectWnd_x                                         0xDEB508
#define pinstCInventoryWnd_x                                       0xDEB4D4
#define pinstCInvSlotMgr_x                                         0xDEAF38
#define pinstCItemDisplayManager_x                                 0xF5B6A0
#define pinstCItemExpTransferWnd_x                                 0xF5B7D0
#define pinstCItemOverflowWnd_x                                    0xDEAF50
#define pinstCJournalCatWnd_x                                      0xDEAF24
#define pinstCJournalNPCWnd_x                                      0xDEAEE4
#define pinstCJournalTextWnd_x                                     0xDEAEE4
#define pinstCKeyRingWnd_x                                         0xDEB53C
#define pinstCLargeDialogWnd_x                                     0xF5D918
#define pinstCLayoutCopyWnd_x                                      0xF5BB20
#define pinstCLFGuildWnd_x                                         0xF5BBD0
#define pinstCLoadskinWnd_x                                        0xDEB468
#define pinstCLootFiltersCopyWnd_x                                 0xCBBEE8
#define pinstCLootFiltersWnd_x                                     0xDEB4EC
#define pinstCLootSettingsWnd_x                                    0xDEB510
#define pinstCLootWnd_x                                            0xDEAF28
#define pinstCMailAddressBookWnd_x                                 0xDEAF3C
#define pinstCMailCompositionWnd_x                                 0xDEAF14
#define pinstCMailIgnoreListWnd_x                                  0xDEAF40
#define pinstCMailWnd_x                                            0xDEAF00
#define pinstCManageLootWnd_x                                      0xDEC3A0
#define pinstCMapToolbarWnd_x                                      0xDEB490
#define pinstCMapViewWnd_x                                         0xDEB458
#define pinstCMarketplaceWnd_x                                     0xDEB4F0
#define pinstCMerchantWnd_x                                        0xDEAF34
#define pinstCMIZoneSelectWnd_x                                    0xF5C408
#define pinstCMusicPlayerWnd_x                                     0xDEAED4
#define pinstCNameChangeMercWnd_x                                  0xDEB494
#define pinstCNameChangePetWnd_x                                   0xDEB460
#define pinstCNameChangeWnd_x                                      0xDEB4BC
#define pinstCNoteWnd_x                                            0xDEB470
#define pinstCObjectPreviewWnd_x                                   0xDEB50C
#define pinstCOptionsWnd_x                                         0xDEB47C
#define pinstCPetInfoWnd_x                                         0xDEAEFC
#define pinstCPetitionQWnd_x                                       0xDEB428
#define pinstCPlayerNotesWnd_x                                     0xDEB410
#define pinstCPlayerWnd_x                                          0xDEAEF0
#define pinstCPopupWndManager_x                                    0xF5CC98
#define pinstCProgressionSelectionWnd_x                            0xF5CD48
#define pinstCPurchaseGroupWnd_x                                   0xDEACC8
#define pinstCPurchaseWnd_x                                        0xDEB544
#define pinstCPvPLeaderboardWnd_x                                  0xF5CDF8
#define pinstCPvPStatsWnd_x                                        0xF5CEA8
#define pinstCQuantityWnd_x                                        0xDEAEE0
#define pinstCRaceChangeWnd_x                                      0xDEB4D8
#define pinstCRaidOptionsWnd_x                                     0xDEB520
#define pinstCRaidWnd_x                                            0xDEAF30
#define pinstCRealEstateItemsWnd_x                                 0xDEB454
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEB000
#define pinstCRealEstateManageWnd_x                                0xDEAED0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEAEEC
#define pinstCRealEstatePlotSearchWnd_x                            0xDEAF04
#define pinstCRealEstatePurchaseWnd_x                              0xDEAF20
#define pinstCRespawnWnd_x                                         0xDEB4F8
#define pinstCRewardSelectionWnd_x                                 0xF5D5F0
#define pinstCSelectorWnd_x                                        0xDEB424
#define pinstCSendMoneyWnd_x                                       0xDEB49C
#define pinstCServerListWnd_x                                      0xDEAF2C
#define pinstCSkillsSelectWnd_x                                    0xDEB420
#define pinstCSkillsWnd_x                                          0xDEAFFC
#define pinstCSocialEditWnd_x                                      0xDEB538
#define pinstCSocialWnd_x                                          0xDEB480
#define pinstCSpellBookWnd_x                                       0xDEB474
#define pinstCStoryWnd_x                                           0xDEAF7C
#define pinstCTargetOfTargetWnd_x                                  0xF5EC50
#define pinstCTargetWnd_x                                          0xDEB4F4
#define pinstCTaskOverlayWnd_x                                     0xDEACC0
#define pinstCTaskSelectWnd_x                                      0xF5EDA8
#define pinstCTaskManager_x                                        0xCBC828
#define pinstCTaskTemplateSelectWnd_x                              0xF5EE58
#define pinstCTaskWnd_x                                            0xF5EF08
#define pinstCTextEntryWnd_x                                       0xDEACA8
#define pinstCTimeLeftWnd_x                                        0xDEB41C
#define pinstCTipWndCONTEXT_x                                      0xF5F10C
#define pinstCTipWndOFDAY_x                                        0xF5F108
#define pinstCTitleWnd_x                                           0xF5F1B8
#define pinstCTrackingWnd_x                                        0xDEB4E4
#define pinstCTradeskillWnd_x                                      0xF5F320
#define pinstCTradeWnd_x                                           0xDEB414
#define pinstCTrainWnd_x                                           0xDEAF18
#define pinstCTributeBenefitWnd_x                                  0xF5F520
#define pinstCTributeMasterWnd_x                                   0xF5F5D0
#define pinstCTributeTrophyWnd_x                                   0xF5F680
#define pinstCVideoModesWnd_x                                      0xDEACBC
#define pinstCVoiceMacroWnd_x                                      0xF488C8
#define pinstCVoteResultsWnd_x                                     0xDEB448
#define pinstCVoteWnd_x                                            0xDEB434
#define pinstCWebManager_x                                         0xF48F44
#define pinstCZoneGuideWnd_x                                       0xDEACC4
#define pinstCZonePathWnd_x                                        0xDEAEDC

#define pinstEQSuiteTextureLoader_x                                0xC89B30
#define pinstItemIconCache_x                                       0xF58560
#define pinstLootFiltersManager_x                                  0xCBBF98
#define pinstRewardSelectionWnd_x                                  0xF5D5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C42F0
#define __CastRay2_x                                               0x5C4340
#define __ConvertItemTags_x                                        0x5E0010
#define __CleanItemTags_x                                          0x47D210
#define __DoesFileExist_x                                          0x8FA320
#define __EQGetTime_x                                              0x8F6F20
#define __ExecuteCmd_x                                             0x5BCC80
#define __FixHeading_x                                             0x98B5E0
#define __FlushDxKeyboard_x                                        0x6B0270
#define __GameLoop_x                                               0x6B35A0
#define __get_bearing_x                                            0x5C3E50
#define __get_melee_range_x                                        0x5C4530
#define __GetAnimationCache_x                                      0x718930
#define __GetGaugeValueFromEQ_x                                    0x80A520
#define __GetLabelFromEQ_x                                         0x80C000
#define __GetXTargetType_x                                         0x98CFF0
#define __HandleMouseWheel_x                                       0x6B4480
#define __HeadingDiff_x                                            0x98B650
#define __HelpPath_x                                               0xF43E04
#define __LoadFrontEnd_x                                           0x6B08B0
#define __NewUIINI_x                                               0x80A1F0
#define __ProcessGameEvents_x                                      0x624F10
#define __ProcessMouseEvent_x                                      0x6246A0
#define __SaveColors_x                                             0x55DCE0
#define __STMLToText_x                                             0x92EA90
#define __ToggleKeyRingItem_x                                      0x51C670
#define CMemoryMappedFile__SetFile_x                               0xA7AA10
#define CrashDetected_x                                            0x6B2360
#define DrawNetStatus_x                                            0x651190
#define Expansion_HoT_x                                            0xEA5D48
#define Teleport_Table_Size_x                                      0xE9D7E0
#define Teleport_Table_x                                           0xE9DCB0
#define Util__FastTime_x                                           0x8F6AF0
#define __CopyLayout_x                                             0x63F1F0
#define __WndProc_x                                                0x6B2860
#define __ProcessKeyboardEvent_x                                   0x6B1E00

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4994B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499280
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A50
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492EA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565F30
#define AltAdvManager__IsAbilityReady_x                            0x564CD0
#define AltAdvManager__GetAAById_x                                 0x565060
#define AltAdvManager__CanTrainAbility_x                           0x5650D0
#define AltAdvManager__CanSeeAbility_x                             0x565430

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB130
#define CharacterZoneClient__HasSkill_x                            0x4D5FB0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D76D0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2810
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBCB0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA070
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA150
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA230
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4900
#define CharacterZoneClient__BardCastBard_x                        0x4C7330
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF6C0
#define CharacterZoneClient__GetEffect_x                           0x4BBBF0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5970
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5A40
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5A90
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5BE0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5DC0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3BD0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8630
#define CharacterZoneClient__FindItemByRecord_x                    0x4D80B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DA090
#define CBankWnd__WndNotification_x                                0x6D9E60

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E7880

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92C290
#define CButtonWnd__CButtonWnd_x                                   0x92AEA0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x707B10
#define CChatManager__InitContextMenu_x                            0x700C40
#define CChatManager__FreeChatWindow_x                             0x706650
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9AC0
#define CChatManager__SetLockedActiveChatWindow_x                  0x707790
#define CChatManager__CreateChatWindow_x                           0x706C90

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9BD0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93F410
#define CContextMenu__dCContextMenu_x                              0x93F650
#define CContextMenu__AddMenuItem_x                                0x93F660
#define CContextMenu__RemoveMenuItem_x                             0x93F970
#define CContextMenu__RemoveAllMenuItems_x                         0x93F990
#define CContextMenu__CheckMenuItem_x                              0x93FA10
#define CContextMenu__SetMenuItem_x                                0x93F890
#define CContextMenu__AddSeparator_x                               0x93F7F0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93FFB0
#define CContextMenuManager__RemoveMenu_x                          0x940020
#define CContextMenuManager__PopupMenu_x                           0x9400E0
#define CContextMenuManager__Flush_x                               0x93FF50
#define CContextMenuManager__GetMenu_x                             0x49B660
#define CContextMenuManager__CreateDefaultMenu_x                   0x713290

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1DD0
#define CChatService__GetFriendName_x                              0x8D1DE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x708380
#define CChatWindow__Clear_x                                       0x709640
#define CChatWindow__WndNotification_x                             0x709DD0
#define CChatWindow__AddHistory_x                                  0x708F00

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93C860
#define CComboWnd__Draw_x                                          0x93BD50
#define CComboWnd__GetCurChoice_x                                  0x93C6A0
#define CComboWnd__GetListRect_x                                   0x93C200
#define CComboWnd__GetTextRect_x                                   0x93C8D0
#define CComboWnd__InsertChoice_x                                  0x93C390
#define CComboWnd__SetColors_x                                     0x93C360
#define CComboWnd__SetChoice_x                                     0x93C670
#define CComboWnd__GetItemCount_x                                  0x93C6B0
#define CComboWnd__GetCurChoiceText_x                              0x93C6F0
#define CComboWnd__GetChoiceText_x                                 0x93C6C0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93C430

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x710CB0
#define CContainerWnd__vftable_x                                   0xAFE74C
#define CContainerWnd__SetContainer_x                              0x712200

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558640
#define CDisplay__PreZoneMainUI_x                                  0x558650
#define CDisplay__CleanGameUI_x                                    0x55DAA0
#define CDisplay__GetClickedActor_x                                0x550AA0
#define CDisplay__GetUserDefinedColor_x                            0x549110
#define CDisplay__GetWorldFilePath_x                               0x552510
#define CDisplay__is3dON_x                                         0x54D700
#define CDisplay__ReloadUI_x                                       0x557B50
#define CDisplay__WriteTextHD2_x                                   0x54D4F0
#define CDisplay__TrueDistance_x                                   0x5541D0
#define CDisplay__SetViewActor_x                                   0x5503C0
#define CDisplay__GetFloorHeight_x                                 0x54D7C0
#define CDisplay__SetRenderWindow_x                                0x54C140
#define CDisplay__ToggleScreenshotMode_x                           0x54FE90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95F240

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x942900
#define CEditWnd__EnsureCaretVisible_x                             0x944A90
#define CEditWnd__GetCaretPt_x                                     0x943A70
#define CEditWnd__GetCharIndexPt_x                                 0x943820
#define CEditWnd__GetDisplayString_x                               0x9436D0
#define CEditWnd__GetHorzOffset_x                                  0x941FB0
#define CEditWnd__GetLineForPrintableChar_x                        0x944990
#define CEditWnd__GetSelStartPt_x                                  0x943AD0
#define CEditWnd__GetSTMLSafeText_x                                0x9434F0
#define CEditWnd__PointFromPrintableChar_x                         0x9445D0
#define CEditWnd__SelectableCharFromPoint_x                        0x944740
#define CEditWnd__SetEditable_x                                    0x943B90
#define CEditWnd__SetWindowTextA_x                                 0x943270
#define CEditWnd__ReplaceSelection_x                               0x944250
#define CEditWnd__ReplaceSelection1_x                              0x9441D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x612510
#define CEverQuest__ClickedPlayer_x                                0x6046C0
#define CEverQuest__CreateTargetIndicator_x                        0x622080
#define CEverQuest__DeleteTargetIndicator_x                        0x622110
#define CEverQuest__DoTellWindow_x                                 0x4E9CB0
#define CEverQuest__OutputTextToLog_x                              0x4E9F80
#define CEverQuest__DropHeldItemOnGround_x                         0x5F9810
#define CEverQuest__dsp_chat_x                                     0x4EA310
#define CEverQuest__trimName_x                                     0x61E230
#define CEverQuest__Emote_x                                        0x612D70
#define CEverQuest__EnterZone_x                                    0x60CE80
#define CEverQuest__GetBodyTypeDesc_x                              0x6177C0
#define CEverQuest__GetClassDesc_x                                 0x617E00
#define CEverQuest__GetClassThreeLetterCode_x                      0x618400
#define CEverQuest__GetDeityDesc_x                                 0x6208D0
#define CEverQuest__GetLangDesc_x                                  0x6185C0
#define CEverQuest__GetRaceDesc_x                                  0x617DE0
#define CEverQuest__InterpretCmd_x                                 0x620EA0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FD9B0
#define CEverQuest__LMouseUp_x                                     0x5FBD30
#define CEverQuest__RightClickedOnPlayer_x                         0x5FE290
#define CEverQuest__RMouseUp_x                                     0x5FCCC0
#define CEverQuest__SetGameState_x                                 0x5F95A0
#define CEverQuest__UPCNotificationFlush_x                         0x61E130
#define CEverQuest__IssuePetCommand_x                              0x6199D0
#define CEverQuest__ReportSuccessfulHit_x                          0x6140C0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7229E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x722A40
#define CGaugeWnd__Draw_x                                          0x722070

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFE70
#define CGuild__GetGuildName_x                                     0x4AE920
#define CGuild__GetGuildIndex_x                                    0x4AEF20

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73C620

//CHotButton
#define CHotButton__SetCheck_x                                     0x6336C0
#define CHotButton__SetButtonSize_x                                0x633A80

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7498D0
#define CInvSlotMgr__MoveItem_x                                    0x748590
#define CInvSlotMgr__SelectSlot_x                                  0x7499A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x746D80
#define CInvSlot__SliderComplete_x                                 0x744AB0
#define CInvSlot__GetItemBase_x                                    0x744420
#define CInvSlot__UpdateItem_x                                     0x744590

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74B430
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74A5C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74AFB0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x805820
#define CItemDisplayWnd__UpdateStrings_x                           0x759C00
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7538E0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x753DF0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75A210
#define CItemDisplayWnd__AboutToShow_x                             0x759840
#define CItemDisplayWnd__WndNotification_x                         0x75B490
#define CItemDisplayWnd__RequestConvertItem_x                      0x75ADC0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7588A0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x759660

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8363F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75F9C0

// CLabel 
#define CLabel__Draw_x                                             0x7653D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x915160
#define CListWnd__dCListWnd_x                                      0x915480
#define CListWnd__AddColumn_x                                      0x919900
#define CListWnd__AddColumn1_x                                     0x919950
#define CListWnd__AddLine_x                                        0x919CE0
#define CListWnd__AddString_x                                      0x919AE0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9196C0
#define CListWnd__CalculateVSBRange_x                              0x9194A0
#define CListWnd__ClearSel_x                                       0x91A4C0
#define CListWnd__ClearAllSel_x                                    0x91A520
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91AF30
#define CListWnd__Compare_x                                        0x918DD0
#define CListWnd__Draw_x                                           0x9155B0
#define CListWnd__DrawColumnSeparators_x                           0x917DA0
#define CListWnd__DrawHeader_x                                     0x918210
#define CListWnd__DrawItem_x                                       0x918710
#define CListWnd__DrawLine_x                                       0x917F10
#define CListWnd__DrawSeparator_x                                  0x917E40
#define CListWnd__EnableLine_x                                     0x917670
#define CListWnd__EnsureVisible_x                                  0x91AE50
#define CListWnd__ExtendSel_x                                      0x91A3F0
#define CListWnd__GetColumnTooltip_x                               0x9171B0
#define CListWnd__GetColumnMinWidth_x                              0x917220
#define CListWnd__GetColumnWidth_x                                 0x917120
#define CListWnd__GetCurSel_x                                      0x916AB0
#define CListWnd__GetItemAtPoint_x                                 0x9178F0
#define CListWnd__GetItemAtPoint1_x                                0x917960
#define CListWnd__GetItemData_x                                    0x916B30
#define CListWnd__GetItemHeight_x                                  0x916EF0
#define CListWnd__GetItemIcon_x                                    0x916CC0
#define CListWnd__GetItemRect_x                                    0x917760
#define CListWnd__GetItemText_x                                    0x916B70
#define CListWnd__GetSelList_x                                     0x91A570
#define CListWnd__GetSeparatorRect_x                               0x917BA0
#define CListWnd__InsertLine_x                                     0x91A0D0
#define CListWnd__RemoveLine_x                                     0x91A220
#define CListWnd__SetColors_x                                      0x919470
#define CListWnd__SetColumnJustification_x                         0x9191A0
#define CListWnd__SetColumnLabel_x                                 0x919A80
#define CListWnd__SetColumnWidth_x                                 0x9190C0
#define CListWnd__SetCurSel_x                                      0x91A330
#define CListWnd__SetItemColor_x                                   0x91AB00
#define CListWnd__SetItemData_x                                    0x91AAC0
#define CListWnd__SetItemText_x                                    0x91A6E0
#define CListWnd__ShiftColumnSeparator_x                           0x919260
#define CListWnd__Sort_x                                           0x918F50
#define CListWnd__ToggleSel_x                                      0x91A360
#define CListWnd__SetColumnsSizable_x                              0x919310
#define CListWnd__SetItemWnd_x                                     0x91A990
#define CListWnd__GetItemWnd_x                                     0x916D10
#define CListWnd__SetItemIcon_x                                    0x91A760
#define CListWnd__CalculateCustomWindowPositions_x                 0x9197C0
#define CListWnd__SetVScrollPos_x                                  0x9190A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77AB40
#define CMapViewWnd__GetWorldCoordinates_x                         0x779250
#define CMapViewWnd__HandleLButtonDown_x                           0x776290

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79ADF0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79B6D0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79BC00
#define CMerchantWnd__SelectRecoverySlot_x                         0x79EBC0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x799950
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4790
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79AA00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89F6F0
#define CPacketScrambler__hton_x                                   0x89F6E0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x934050
#define CSidlManager__FindScreenPieceTemplate_x                    0x934460
#define CSidlManager__FindScreenPieceTemplate1_x                   0x934250
#define CSidlManager__CreateLabel_x                                0x7FC970
#define CSidlManager__CreateXWndFromTemplate_x                     0x9373C0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9375A0
#define CSidlManager__CreateXWnd_x                                 0x7FC8A0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FCE60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x930B60
#define CSidlScreenWnd__CalculateVSBRange_x                        0x930A60
#define CSidlScreenWnd__ConvertToRes_x                             0x959D90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930550
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x930240
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x930310
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9303E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x931000
#define CSidlScreenWnd__EnableIniStorage_x                         0x9314D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9311F0
#define CSidlScreenWnd__Init1_x                                    0x92FE40
#define CSidlScreenWnd__LoadIniInfo_x                              0x931520
#define CSidlScreenWnd__LoadIniListWnd_x                           0x932030
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92F240
#define CSidlScreenWnd__StoreIniInfo_x                             0x931BB0
#define CSidlScreenWnd__StoreIniVis_x                              0x931F10
#define CSidlScreenWnd__WndNotification_x                          0x930F10
#define CSidlScreenWnd__GetChildItem_x                             0x931450
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920D80
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DA190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x699540
#define CSkillMgr__GetSkillCap_x                                   0x699720
#define CSkillMgr__GetNameToken_x                                  0x698CC0
#define CSkillMgr__IsActivatedSkill_x                              0x698E00
#define CSkillMgr__IsCombatSkill_x                                 0x698D40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x940D90
#define CSliderWnd__SetValue_x                                     0x940C00
#define CSliderWnd__SetNumTicks_x                                  0x940C60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x802B30

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x949690
#define CStmlWnd__ParseSTML_x                                      0x94A9E0
#define CStmlWnd__CalculateHSBRange_x                              0x94A7B0
#define CStmlWnd__CalculateVSBRange_x                              0x94A730
#define CStmlWnd__CanBreakAtCharacter_x                            0x94EAF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94F780
#define CStmlWnd__ForceParseNow_x                                  0x949C80
#define CStmlWnd__GetNextTagPiece_x                                0x94EA50
#define CStmlWnd__GetSTMLText_x                                    0x50DB90
#define CStmlWnd__GetVisibleText_x                                 0x949CA0
#define CStmlWnd__InitializeWindowVariables_x                      0x94F5D0
#define CStmlWnd__MakeStmlColorTag_x                               0x948D00
#define CStmlWnd__MakeWndNotificationTag_x                         0x948D70
#define CStmlWnd__SetSTMLText_x                                    0x947DB0
#define CStmlWnd__StripFirstSTMLLines_x                            0x950880
#define CStmlWnd__UpdateHistoryString_x                            0x94F990

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946F00
#define CTabWnd__DrawCurrentPage_x                                 0x947630
#define CTabWnd__DrawTab_x                                         0x947350
#define CTabWnd__GetCurrentPage_x                                  0x946700
#define CTabWnd__GetPageInnerRect_x                                0x946940
#define CTabWnd__GetTabInnerRect_x                                 0x946880
#define CTabWnd__GetTabRect_x                                      0x946730
#define CTabWnd__InsertPage_x                                      0x946B50
#define CTabWnd__RemovePage_x                                      0x946CC0
#define CTabWnd__SetPage_x                                         0x9469C0
#define CTabWnd__SetPageRect_x                                     0x946E40
#define CTabWnd__UpdatePage_x                                      0x947210
#define CTabWnd__GetPageFromTabIndex_x                             0x947290
#define CTabWnd__GetCurrentTabIndex_x                              0x9466F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75FDD0
#define CPageWnd__SetTabText_x                                     0x946240
#define CPageWnd__FlashTab_x                                       0x9462A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A91D0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91DC30
#define CTextureFont__GetTextExtent_x                              0x91DDF0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AD700
#define CHtmlComponentWnd__ValidateUri_x                           0x73E010
#define CHtmlWnd__SetClientCallbacks_x                             0x638B30
#define CHtmlWnd__AddObserver_x                                    0x638B50
#define CHtmlWnd__RemoveObserver_x                                 0x638BB0
#define Window__getProgress_x                                      0x854E60
#define Window__getStatus_x                                        0x854E80
#define Window__getURI_x                                           0x854E90

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x956BA0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90ACC0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E99B0
#define CXStr__CXStr1_x                                            0x8454E0
#define CXStr__CXStr3_x                                            0x8F2EE0
#define CXStr__dCXStr_x                                            0x4783B0
#define CXStr__operator_equal_x                                    0x8F3110
#define CXStr__operator_equal1_x                                   0x8F3150
#define CXStr__operator_plus_equal1_x                              0x8F3BE0
#define CXStr__SetString_x                                         0x8F5AD0
#define CXStr__operator_char_p_x                                   0x8F3620
#define CXStr__GetChar_x                                           0x8F5400
#define CXStr__Delete_x                                            0x8F4CD0
#define CXStr__GetUnicode_x                                        0x8F5470
#define CXStr__GetLength_x                                         0x47D5C0
#define CXStr__Mid_x                                               0x47D5D0
#define CXStr__Insert_x                                            0x8F54D0
#define CXStr__FindNext_x                                          0x8F5140

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93F020
#define CXWnd__BringToTop_x                                        0x924470
#define CXWnd__Center_x                                            0x923FF0
#define CXWnd__ClrFocus_x                                          0x923E10
#define CXWnd__Destroy_x                                           0x923EB0
#define CXWnd__DoAllDrawing_x                                      0x920520
#define CXWnd__DrawChildren_x                                      0x9204F0
#define CXWnd__DrawColoredRect_x                                   0x920970
#define CXWnd__DrawTooltip_x                                       0x91F020
#define CXWnd__DrawTooltipAtPoint_x                                0x91F0E0
#define CXWnd__GetBorderFrame_x                                    0x9207D0
#define CXWnd__GetChildWndAt_x                                     0x924510
#define CXWnd__GetClientClipRect_x                                 0x922780
#define CXWnd__GetScreenClipRect_x                                 0x922850
#define CXWnd__GetScreenRect_x                                     0x922A10
#define CXWnd__GetRelativeRect_x                                   0x922AD0
#define CXWnd__GetTooltipRect_x                                    0x9209C0
#define CXWnd__GetWindowTextA_x                                    0x49CD80
#define CXWnd__IsActive_x                                          0x9210F0
#define CXWnd__IsDescendantOf_x                                    0x9233F0
#define CXWnd__IsReallyVisible_x                                   0x923420
#define CXWnd__IsType_x                                            0x924B80
#define CXWnd__Move_x                                              0x923490
#define CXWnd__Move1_x                                             0x923540
#define CXWnd__ProcessTransition_x                                 0x923FA0
#define CXWnd__Refade_x                                            0x9237F0
#define CXWnd__Resize_x                                            0x923A90
#define CXWnd__Right_x                                             0x924230
#define CXWnd__SetFocus_x                                          0x923DD0
#define CXWnd__SetFont_x                                           0x923E40
#define CXWnd__SetKeyTooltip_x                                     0x924990
#define CXWnd__SetMouseOver_x                                      0x921900
#define CXWnd__StartFade_x                                         0x9232D0
#define CXWnd__GetChildItem_x                                      0x924680
#define CXWnd__SetParent_x                                         0x923180
#define CXWnd__Minimize_x                                          0x923AF0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95AE10

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x927330
#define CXWndManager__DrawWindows_x                                0x927350
#define CXWndManager__GetKeyboardFlags_x                           0x929B10
#define CXWndManager__HandleKeyboardMsg_x                          0x9296C0
#define CXWndManager__RemoveWnd_x                                  0x929D40
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92A2C0

// CDBStr
#define CDBStr__GetString_x                                        0x5480B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFE20
#define EQ_Character__Cur_HP_x                                     0x4D2FF0
#define EQ_Character__Cur_Mana_x                                   0x4DA730
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2E80
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3810
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3960
#define EQ_Character__GetHPRegen_x                                 0x4E0630
#define EQ_Character__GetEnduranceRegen_x                          0x4E0C30
#define EQ_Character__GetManaRegen_x                               0x4E1070
#define EQ_Character__Max_Endurance_x                              0x65F670
#define EQ_Character__Max_HP_x                                     0x4D2E20
#define EQ_Character__Max_Mana_x                                   0x65F470
#define EQ_Character__doCombatAbility_x                            0x661A60
#define EQ_Character__UseSkill_x                                   0x4E2E80
#define EQ_Character__GetConLevel_x                                0x658100
#define EQ_Character__IsExpansionFlag_x                            0x5BB480
#define EQ_Character__TotalEffect_x                                0x4C6C20
#define EQ_Character__GetPCSpellAffect_x                           0x4C3BD0
#define EQ_Character__SpellDuration_x                              0x4C3700
#define EQ_Character__MySpellDuration_x                            0x4B2140
#define EQ_Character__GetAdjustedSkill_x                           0x4D5D70
#define EQ_Character__GetBaseSkill_x                               0x4D6D10
#define EQ_Character__CanUseItem_x                                 0x4DAA40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BECE0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6759D0

//PcClient
#define PcClient__vftable_x                                        0xAF21C4
#define PcClient__PcClient_x                                       0x655860

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA850
#define CCharacterListWnd__EnterWorld_x                            0x4BA220
#define CCharacterListWnd__Quit_x                                  0x4B9F70
#define CCharacterListWnd__UpdateList_x                            0x4BA410

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x639D20
#define EQ_Item__CreateItemTagString_x                             0x898B80
#define EQ_Item__IsStackable_x                                     0x89D8F0
#define EQ_Item__GetImageNum_x                                     0x89A750
#define EQ_Item__CreateItemClient_x                                0x638F50
#define EQ_Item__GetItemValue_x                                    0x89BA70
#define EQ_Item__ValueSellMerchant_x                               0x89F2D0
#define EQ_Item__IsKeyRingItem_x                                   0x89D1A0
#define EQ_Item__CanGoInBag_x                                      0x639E40
#define EQ_Item__IsEmpty_x                                         0x89CCE0
#define EQ_Item__GetMaxItemCount_x                                 0x89BE80
#define EQ_Item__GetHeldItem_x                                     0x89A620
#define EQ_Item__GetAugmentFitBySlot_x                             0x8983E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566C00
#define EQ_LoadingS__Array_x                                       0xC13130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65FF70
#define EQ_PC__GetAlternateAbilityId_x                             0x8A85D0
#define EQ_PC__GetCombatAbility_x                                  0x8A8C40
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A8CB0
#define EQ_PC__GetItemRecastTimer_x                                0x661FE0
#define EQ_PC__HasLoreItem_x                                       0x658920
#define EQ_PC__AlertInventoryChanged_x                             0x657A30
#define EQ_PC__GetPcZoneClient_x                                   0x684A00
#define EQ_PC__RemoveMyAffect_x                                    0x665210
#define EQ_PC__GetKeyRingItems_x                                   0x8A9580
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9300
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A9880

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C1880
#define EQItemList__add_object_x                                   0x5EEE90
#define EQItemList__add_item_x                                     0x5C1DE0
#define EQItemList__delete_item_x                                  0x5C1E30
#define EQItemList__FreeItemList_x                                 0x5C1D30

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544BE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6772D0
#define EQPlayer__dEQPlayer_x                                      0x66A640
#define EQPlayer__DoAttack_x                                       0x67F190
#define EQPlayer__EQPlayer_x                                       0x66AD00
#define EQPlayer__SetNameSpriteState_x                             0x66EFE0
#define EQPlayer__SetNameSpriteTint_x                              0x66FEC0
#define PlayerBase__HasProperty_j_x                                0x9899E0
#define EQPlayer__IsTargetable_x                                   0x989E80
#define EQPlayer__CanSee_x                                         0x989CE0
#define EQPlayer__CanSee1_x                                        0x989DB0
#define PlayerBase__GetVisibilityLineSegment_x                     0x989AA0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x682490
#define PlayerZoneClient__GetLevel_x                               0x684A40
#define PlayerZoneClient__IsValidTeleport_x                        0x5F0000
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F960

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67A0A0
#define EQPlayerManager__GetSpawnByName_x                          0x67A150
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A1E0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63D450
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63D4D0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63D510
#define KeypressHandler__ClearCommandStateArray_x                  0x63E900
#define KeypressHandler__HandleKeyDown_x                           0x63E920
#define KeypressHandler__HandleKeyUp_x                             0x63E9C0
#define KeypressHandler__SaveKeymapping_x                          0x63EE10

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7769B0
#define MapViewMap__SaveEx_x                                       0x779D70
#define MapViewMap__SetZoom_x                                      0x77E430

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BCC90

// StringTable 
#define StringTable__getString_x                                   0x8B7B00

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x664E80
#define PcZoneClient__RemovePetEffect_x                            0x6654B0
#define PcZoneClient__HasAlternateAbility_x                        0x65F2A0
#define PcZoneClient__GetCurrentMod_x                              0x4E5FA0
#define PcZoneClient__GetModCap_x                                  0x4E5EA0
#define PcZoneClient__CanEquipItem_x                               0x65F950
#define PcZoneClient__GetItemByID_x                                0x662450
#define PcZoneClient__GetItemByItemClass_x                         0x6625A0
#define PcZoneClient__RemoveBuffEffect_x                           0x6654D0
#define PcZoneClient__BandolierSwap_x                              0x660530
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x661F80

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F4C40

//IconCache
#define IconCache__GetIcon_x                                       0x718330

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70FE50
#define CContainerMgr__CloseContainer_x                            0x710120
#define CContainerMgr__OpenExperimentContainer_x                   0x710BA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CF0C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631E90

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76CE80
#define CLootWnd__RequestLootSlot_x                                0x76C150

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E6C0
#define EQ_Spell__SpellAffects_x                                   0x58EB30
#define EQ_Spell__SpellAffectBase_x                                0x58E8F0
#define EQ_Spell__IsStackable_x                                    0x4CAA50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA870
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7AF0
#define EQ_Spell__IsSPAStacking_x                                  0x58F980
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58EE90
#define EQ_Spell__IsNoRemove_x                                     0x4CAA30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58F990
#define __IsResEffectSpell_x                                       0x4C9C70

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD3B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C73F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x815FB0
#define CTargetWnd__WndNotification_x                              0x8157F0
#define CTargetWnd__RefreshTargetBuffs_x                           0x815AC0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814960

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81A620
#define CTaskWnd__ConfirmAbandonTask_x                             0x81D260

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x542610
#define CTaskManager__HandleMessage_x                              0x540A70
#define CTaskManager__GetTaskStatus_x                              0x5426C0
#define CTaskManager__GetElementDescription_x                      0x542740

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5897D0
#define EqSoundManager__PlayScriptMp3_x                            0x589A90
#define EqSoundManager__SoundAssistPlay_x                          0x69D4E0
#define EqSoundManager__WaveInstancePlay_x                         0x69CA50

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x533A10

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x945750
#define CTextureAnimation__Draw_x                                  0x945950

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9416F0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E6D0
#define CAltAbilityData__GetMercMaxRank_x                          0x56E660
#define CAltAbilityData__GetMaxRank_x                              0x563B50

//CTargetRing
#define CTargetRing__Cast_x                                        0x62FFB0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA850
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A7D0
#define CharacterBase__CreateItemIndex_x                           0x6380E0
#define CharacterBase__GetItemPossession_x                         0x506560
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CFA80
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CFAE0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F6E90
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F76C0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F7770

//messages
#define msg_spell_worn_off_x                                       0x5B34E0
#define msg_new_text_x                                             0x5A7E40
#define __msgTokenTextParam_x                                      0x5B5780
#define msgTokenText_x                                             0x5B59D0

//SpellManager
#define SpellManager__vftable_x                                    0xADA544
#define SpellManager__SpellManager_x                               0x6A0810
#define Spellmanager__LoadTextSpells_x                             0x6A1100
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A09E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98D8E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51AE80
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B99F0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x650FF0
#define ItemGlobalIndex__IsValidIndex_x                            0x51AF10

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C7DB0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7F40

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x765710

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x714530
#define CCursorAttachment__AttachToCursor1_x                       0x714570
#define CCursorAttachment__Deactivate_x                            0x715550

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9383F0
#define CSidlManagerBase__CreatePageWnd_x                          0x937BF0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x933E70
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933E00

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x955840
#define CEQSuiteTextureLoader__GetTexture_x                        0x955500

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x517AC0
#define CFindItemWnd__WndNotification_x                            0x518700
#define CFindItemWnd__Update_x                                     0x519270
#define CFindItemWnd__PickupSelectedItem_x                         0x5172F0

//IString
#define IString__Append_x                                          0x507E00

//Camera
#define CDisplay__cameraType_x                                     0xDEACCC
#define EverQuest__Cameras_x                                       0xEA60A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5207E0
#define LootFiltersManager__GetItemFilterData_x                    0x5200E0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x520110
#define LootFiltersManager__SetItemLootFilter_x                    0x520330

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BCF00

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x993560
#define CResolutionHandler__GetWindowedStyle_x                     0x697E90

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70CB00

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3860
#define CDistillerInfo__Instance_x                                 0x8D3800

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72B9B0
#define CGroupWnd__UpdateDisplay_x                                 0x72AD00

//ItemBase
#define ItemBase__IsLore_x                                         0x89D250
#define ItemBase__IsLoreEquipped_x                                 0x89D2C0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EEDF0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EEF30
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EEF90

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D120
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x690AD0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50E1D0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA300
#define FactionManagerClient__HandleFactionMessage_x               0x4FA970
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAF70
#define FactionManagerClient__GetMaxFaction_x                      0x4FAF8F
#define FactionManagerClient__GetMinFaction_x                      0x4FAF40

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x506530

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91CBD0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C060

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x506810

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56DB80

//CTargetManager
#define CTargetManager__Get_x                                      0x6A4060

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D120

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8F90

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1CD0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF43734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C07A0
#define CAAWnd__UpdateSelected_x                                   0x6BD010
#define CAAWnd__Update_x                                           0x6BFAC0

//CXRect
#define CXRect__operator_and_x                                     0x722AA0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483260

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
