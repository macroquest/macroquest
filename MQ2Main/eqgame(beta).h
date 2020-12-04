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
#define __ExpectedVersionDate                                     "Nov 25 2020"
#define __ExpectedVersionTime                                     "04:19:51"
#define __ActualVersionDate_x                                      0xAF554C
#define __ActualVersionTime_x                                      0xAF5540
#define __ActualVersionBuild_x                                     0xAE3574

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x643990
#define __MemChecker1_x                                            0x8F6A40
#define __MemChecker2_x                                            0x6B3A90
#define __MemChecker3_x                                            0x6B39E0
#define __MemChecker4_x                                            0x84CB80
#define __EncryptPad0_x                                            0xC2B9C8
#define __EncryptPad1_x                                            0xC89210
#define __EncryptPad2_x                                            0xC3BD90
#define __EncryptPad3_x                                            0xC3B990
#define __EncryptPad4_x                                            0xC797A0
#define __EncryptPad5_x                                            0xF4C0F0
#define __AC1_x                                                    0x80B6F6
#define __AC2_x                                                    0x5FCD1F
#define __AC3_x                                                    0x604370
#define __AC4_x                                                    0x608320
#define __AC5_x                                                    0x60E61F
#define __AC6_x                                                    0x612AD6
#define __AC7_x                                                    0x5FC790
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
#define __do_loot_x                                                0x5C8800
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
#define __gfMaxZoomCameraDistance_x                                0xAED170
#define __gfMaxCameraDistance_x                                    0xB15E00
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
#define __CastRay_x                                                0x5C3EF0
#define __CastRay2_x                                               0x5C3F40
#define __ConvertItemTags_x                                        0x5DFC00
#define __CleanItemTags_x                                          0x47D230
#define __DoesFileExist_x                                          0x8F9A70
#define __EQGetTime_x                                              0x8F6670
#define __ExecuteCmd_x                                             0x5BC890
#define __FixHeading_x                                             0x98BB60
#define __FlushDxKeyboard_x                                        0x6AF930
#define __GameLoop_x                                               0x6B2C60
#define __get_bearing_x                                            0x5C3A50
#define __get_melee_range_x                                        0x5C4130
#define __GetAnimationCache_x                                      0x718170
#define __GetGaugeValueFromEQ_x                                    0x809BA0
#define __GetLabelFromEQ_x                                         0x80B680
#define __GetXTargetType_x                                         0x98D620
#define __HandleMouseWheel_x                                       0x6B3B40
#define __HeadingDiff_x                                            0x98BBD0
#define __HelpPath_x                                               0xF43E04
#define __LoadFrontEnd_x                                           0x6AFF70
#define __NewUIINI_x                                               0x809870
#define __ProcessGameEvents_x                                      0x6249B0
#define __ProcessMouseEvent_x                                      0x624140
#define __SaveColors_x                                             0x55D930
#define __STMLToText_x                                             0x92F120
#define __ToggleKeyRingItem_x                                      0x51C110
#define CMemoryMappedFile__SetFile_x                               0xA7AEB0
#define CrashDetected_x                                            0x6B1A20
#define DrawNetStatus_x                                            0x650CF0
#define Expansion_HoT_x                                            0xEA5D48
#define Teleport_Table_Size_x                                      0xE9D7E0
#define Teleport_Table_x                                           0xE9DCB0
#define Util__FastTime_x                                           0x8F6240
#define __CopyLayout_x                                             0x63F040
#define __WndProc_x                                                0x6B1F20
#define __ProcessKeyboardEvent_x                                   0x6B14C0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4994D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4992A0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A80
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492ED0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565A20
#define AltAdvManager__IsAbilityReady_x                            0x5647C0
#define AltAdvManager__GetAAById_x                                 0x564B50
#define AltAdvManager__CanTrainAbility_x                           0x564BC0
#define AltAdvManager__CanSeeAbility_x                             0x564F20

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB190
#define CharacterZoneClient__HasSkill_x                            0x4D6010
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7730
#define CharacterZoneClient__IsStackBlocked_x                      0x4C27A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBC30
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA0A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA180
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA260
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4890
#define CharacterZoneClient__BardCastBard_x                        0x4C72C0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF640
#define CharacterZoneClient__GetEffect_x                           0x4BBB70
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5900
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C59D0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5A20
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5B70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5D50
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3B80
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8690
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8110

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D98C0
#define CBankWnd__WndNotification_x                                0x6D9690

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E7340

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92C910
#define CButtonWnd__CButtonWnd_x                                   0x92B4E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x707390
#define CChatManager__InitContextMenu_x                            0x7004C0
#define CChatManager__FreeChatWindow_x                             0x705ED0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E99A0
#define CChatManager__SetLockedActiveChatWindow_x                  0x707010
#define CChatManager__CreateChatWindow_x                           0x706510

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9AB0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93FB90
#define CContextMenu__dCContextMenu_x                              0x93FDC0
#define CContextMenu__AddMenuItem_x                                0x93FDD0
#define CContextMenu__RemoveMenuItem_x                             0x9400D0
#define CContextMenu__RemoveAllMenuItems_x                         0x9400F0
#define CContextMenu__CheckMenuItem_x                              0x940170
#define CContextMenu__SetMenuItem_x                                0x940000
#define CContextMenu__AddSeparator_x                               0x93FF60

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x940710
#define CContextMenuManager__RemoveMenu_x                          0x940780
#define CContextMenuManager__PopupMenu_x                           0x940840
#define CContextMenuManager__Flush_x                               0x9406B0
#define CContextMenuManager__GetMenu_x                             0x49B6B0
#define CContextMenuManager__CreateDefaultMenu_x                   0x712AF0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1370
#define CChatService__GetFriendName_x                              0x8D1380

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x707C00
#define CChatWindow__Clear_x                                       0x708EC0
#define CChatWindow__WndNotification_x                             0x709650
#define CChatWindow__AddHistory_x                                  0x708780

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93CFF0
#define CComboWnd__Draw_x                                          0x93C4F0
#define CComboWnd__GetCurChoice_x                                  0x93CE30
#define CComboWnd__GetListRect_x                                   0x93C9A0
#define CComboWnd__GetTextRect_x                                   0x93D050
#define CComboWnd__InsertChoice_x                                  0x93CB30
#define CComboWnd__SetColors_x                                     0x93CB00
#define CComboWnd__SetChoice_x                                     0x93CE00
#define CComboWnd__GetItemCount_x                                  0x93CE40
#define CComboWnd__GetCurChoiceText_x                              0x93CE80
#define CComboWnd__GetChoiceText_x                                 0x93CE50
#define CComboWnd__InsertChoiceAtIndex_x                           0x93CBC0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x710510
#define CContainerWnd__vftable_x                                   0xAFE754
#define CContainerWnd__SetContainer_x                              0x711A60

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558290
#define CDisplay__PreZoneMainUI_x                                  0x5582A0
#define CDisplay__CleanGameUI_x                                    0x55D6F0
#define CDisplay__GetClickedActor_x                                0x5506F0
#define CDisplay__GetUserDefinedColor_x                            0x548D70
#define CDisplay__GetWorldFilePath_x                               0x552160
#define CDisplay__is3dON_x                                         0x54D350
#define CDisplay__ReloadUI_x                                       0x5577A0
#define CDisplay__WriteTextHD2_x                                   0x54D140
#define CDisplay__TrueDistance_x                                   0x553E20
#define CDisplay__SetViewActor_x                                   0x550010
#define CDisplay__GetFloorHeight_x                                 0x54D410
#define CDisplay__SetRenderWindow_x                                0x54BD90
#define CDisplay__ToggleScreenshotMode_x                           0x54FAE0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95F900

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x943080
#define CEditWnd__EnsureCaretVisible_x                             0x945240
#define CEditWnd__GetCaretPt_x                                     0x9441F0
#define CEditWnd__GetCharIndexPt_x                                 0x943FA0
#define CEditWnd__GetDisplayString_x                               0x943E40
#define CEditWnd__GetHorzOffset_x                                  0x942720
#define CEditWnd__GetLineForPrintableChar_x                        0x945140
#define CEditWnd__GetSelStartPt_x                                  0x944250
#define CEditWnd__GetSTMLSafeText_x                                0x943C60
#define CEditWnd__PointFromPrintableChar_x                         0x944D70
#define CEditWnd__SelectableCharFromPoint_x                        0x944EE0
#define CEditWnd__SetEditable_x                                    0x944320
#define CEditWnd__SetWindowTextA_x                                 0x9439E0
#define CEditWnd__ReplaceSelection_x                               0x9449E0
#define CEditWnd__ReplaceSelection1_x                              0x944960

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611FB0
#define CEverQuest__ClickedPlayer_x                                0x604150
#define CEverQuest__CreateTargetIndicator_x                        0x621B20
#define CEverQuest__DeleteTargetIndicator_x                        0x621BB0
#define CEverQuest__DoTellWindow_x                                 0x4E9B90
#define CEverQuest__OutputTextToLog_x                              0x4E9E60
#define CEverQuest__DropHeldItemOnGround_x                         0x5F92B0
#define CEverQuest__dsp_chat_x                                     0x4EA1F0
#define CEverQuest__trimName_x                                     0x61DCD0
#define CEverQuest__Emote_x                                        0x612810
#define CEverQuest__EnterZone_x                                    0x60C910
#define CEverQuest__GetBodyTypeDesc_x                              0x617260
#define CEverQuest__GetClassDesc_x                                 0x6178A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x617EA0
#define CEverQuest__GetDeityDesc_x                                 0x620370
#define CEverQuest__GetLangDesc_x                                  0x618060
#define CEverQuest__GetRaceDesc_x                                  0x617880
#define CEverQuest__InterpretCmd_x                                 0x620940
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FD440
#define CEverQuest__LMouseUp_x                                     0x5FB7D0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FDD20
#define CEverQuest__RMouseUp_x                                     0x5FC750
#define CEverQuest__SetGameState_x                                 0x5F9040
#define CEverQuest__UPCNotificationFlush_x                         0x61DBD0
#define CEverQuest__IssuePetCommand_x                              0x619470
#define CEverQuest__ReportSuccessfulHit_x                          0x613B60

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7220C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x722120
#define CGaugeWnd__Draw_x                                          0x721750

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFE50
#define CGuild__GetGuildName_x                                     0x4AE900
#define CGuild__GetGuildIndex_x                                    0x4AEF00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73BD10

//CHotButton
#define CHotButton__SetCheck_x                                     0x633470
#define CHotButton__SetButtonSize_x                                0x633830

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748F90
#define CInvSlotMgr__MoveItem_x                                    0x747C60
#define CInvSlotMgr__SelectSlot_x                                  0x749060

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x746450
#define CInvSlot__SliderComplete_x                                 0x7441A0
#define CInvSlot__GetItemBase_x                                    0x743B10
#define CInvSlot__UpdateItem_x                                     0x743C80

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74AAD0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x749C60
#define CInvSlotWnd__HandleLButtonUp_x                             0x74A650

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x804F40
#define CItemDisplayWnd__UpdateStrings_x                           0x759220
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752F10
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x753420
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x759820
#define CItemDisplayWnd__AboutToShow_x                             0x758E80
#define CItemDisplayWnd__WndNotification_x                         0x75AA90
#define CItemDisplayWnd__RequestConvertItem_x                      0x75A3D0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x757EE0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x758CA0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8359A0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75EF80

// CLabel 
#define CLabel__Draw_x                                             0x7649B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9157F0
#define CListWnd__dCListWnd_x                                      0x915B10
#define CListWnd__AddColumn_x                                      0x919F70
#define CListWnd__AddColumn1_x                                     0x919FC0
#define CListWnd__AddLine_x                                        0x91A350
#define CListWnd__AddString_x                                      0x91A150
#define CListWnd__CalculateFirstVisibleLine_x                      0x919D30
#define CListWnd__CalculateVSBRange_x                              0x919B10
#define CListWnd__ClearSel_x                                       0x91AB30
#define CListWnd__ClearAllSel_x                                    0x91AB90
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91B590
#define CListWnd__Compare_x                                        0x919440
#define CListWnd__Draw_x                                           0x915C40
#define CListWnd__DrawColumnSeparators_x                           0x918410
#define CListWnd__DrawHeader_x                                     0x918880
#define CListWnd__DrawItem_x                                       0x918D80
#define CListWnd__DrawLine_x                                       0x918580
#define CListWnd__DrawSeparator_x                                  0x9184B0
#define CListWnd__EnableLine_x                                     0x917CF0
#define CListWnd__EnsureVisible_x                                  0x91B4C0
#define CListWnd__ExtendSel_x                                      0x91AA60
#define CListWnd__GetColumnTooltip_x                               0x917830
#define CListWnd__GetColumnMinWidth_x                              0x9178A0
#define CListWnd__GetColumnWidth_x                                 0x9177A0
#define CListWnd__GetCurSel_x                                      0x917130
#define CListWnd__GetItemAtPoint_x                                 0x917F60
#define CListWnd__GetItemAtPoint1_x                                0x917FD0
#define CListWnd__GetItemData_x                                    0x9171B0
#define CListWnd__GetItemHeight_x                                  0x917570
#define CListWnd__GetItemIcon_x                                    0x917340
#define CListWnd__GetItemRect_x                                    0x917DE0
#define CListWnd__GetItemText_x                                    0x9171F0
#define CListWnd__GetSelList_x                                     0x91ABE0
#define CListWnd__GetSeparatorRect_x                               0x918210
#define CListWnd__InsertLine_x                                     0x91A740
#define CListWnd__RemoveLine_x                                     0x91A890
#define CListWnd__SetColors_x                                      0x919AE0
#define CListWnd__SetColumnJustification_x                         0x919810
#define CListWnd__SetColumnLabel_x                                 0x91A0F0
#define CListWnd__SetColumnWidth_x                                 0x919730
#define CListWnd__SetCurSel_x                                      0x91A9A0
#define CListWnd__SetItemColor_x                                   0x91B180
#define CListWnd__SetItemData_x                                    0x91B140
#define CListWnd__SetItemText_x                                    0x91AD50
#define CListWnd__ShiftColumnSeparator_x                           0x9198D0
#define CListWnd__Sort_x                                           0x9195C0
#define CListWnd__ToggleSel_x                                      0x91A9D0
#define CListWnd__SetColumnsSizable_x                              0x919980
#define CListWnd__SetItemWnd_x                                     0x91B000
#define CListWnd__GetItemWnd_x                                     0x917390
#define CListWnd__SetItemIcon_x                                    0x91ADD0
#define CListWnd__CalculateCustomWindowPositions_x                 0x919E30
#define CListWnd__SetVScrollPos_x                                  0x919710

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77A110
#define CMapViewWnd__GetWorldCoordinates_x                         0x778820
#define CMapViewWnd__HandleLButtonDown_x                           0x775860

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79A560
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79AE40
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79B370
#define CMerchantWnd__SelectRecoverySlot_x                         0x79E310
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7990E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A3ED0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79A180

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89EC30
#define CPacketScrambler__hton_x                                   0x89EC20

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9346D0
#define CSidlManager__FindScreenPieceTemplate_x                    0x934AE0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9348D0
#define CSidlManager__CreateLabel_x                                0x7FC0E0
#define CSidlManager__CreateXWndFromTemplate_x                     0x937A40
#define CSidlManager__CreateXWndFromTemplate1_x                    0x937C20
#define CSidlManager__CreateXWnd_x                                 0x7FC010
#define CSidlManager__CreateHotButtonWnd_x                         0x7FC5E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9311D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9310D0
#define CSidlScreenWnd__ConvertToRes_x                             0x95A3F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930BC0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9308B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x930980
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x930A50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x931670
#define CSidlScreenWnd__EnableIniStorage_x                         0x931B40
#define CSidlScreenWnd__GetSidlPiece_x                             0x931860
#define CSidlScreenWnd__Init1_x                                    0x9304D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x931B90
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9326B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92F8D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x932230
#define CSidlScreenWnd__StoreIniVis_x                              0x932590
#define CSidlScreenWnd__WndNotification_x                          0x931580
#define CSidlScreenWnd__GetChildItem_x                             0x931AC0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x921320
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DA190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x698BC0
#define CSkillMgr__GetSkillCap_x                                   0x698DA0
#define CSkillMgr__GetNameToken_x                                  0x698340
#define CSkillMgr__IsActivatedSkill_x                              0x698480
#define CSkillMgr__IsCombatSkill_x                                 0x6983C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x941500
#define CSliderWnd__SetValue_x                                     0x941370
#define CSliderWnd__SetNumTicks_x                                  0x9413D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x802250

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x949E30
#define CStmlWnd__ParseSTML_x                                      0x94B140
#define CStmlWnd__CalculateHSBRange_x                              0x94AF10
#define CStmlWnd__CalculateVSBRange_x                              0x94AE80
#define CStmlWnd__CanBreakAtCharacter_x                            0x94F260
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94FEF0
#define CStmlWnd__ForceParseNow_x                                  0x94A3D0
#define CStmlWnd__GetNextTagPiece_x                                0x94F1C0
#define CStmlWnd__GetSTMLText_x                                    0x50D730
#define CStmlWnd__GetVisibleText_x                                 0x94A3F0
#define CStmlWnd__InitializeWindowVariables_x                      0x94FD40
#define CStmlWnd__MakeStmlColorTag_x                               0x9494A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x949510
#define CStmlWnd__SetSTMLText_x                                    0x948550
#define CStmlWnd__StripFirstSTMLLines_x                            0x950FF0
#define CStmlWnd__UpdateHistoryString_x                            0x950100

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9476A0
#define CTabWnd__DrawCurrentPage_x                                 0x947DD0
#define CTabWnd__DrawTab_x                                         0x947AF0
#define CTabWnd__GetCurrentPage_x                                  0x946EA0
#define CTabWnd__GetPageInnerRect_x                                0x9470E0
#define CTabWnd__GetTabInnerRect_x                                 0x947020
#define CTabWnd__GetTabRect_x                                      0x946ED0
#define CTabWnd__InsertPage_x                                      0x9472F0
#define CTabWnd__RemovePage_x                                      0x947460
#define CTabWnd__SetPage_x                                         0x947160
#define CTabWnd__SetPageRect_x                                     0x9475E0
#define CTabWnd__UpdatePage_x                                      0x9479B0
#define CTabWnd__GetPageFromTabIndex_x                             0x947A30
#define CTabWnd__GetCurrentTabIndex_x                              0x946E90

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75F390
#define CPageWnd__SetTabText_x                                     0x9469F0
#define CPageWnd__FlashTab_x                                       0x946A50

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9130

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91E200
#define CTextureFont__GetTextExtent_x                              0x91E3C0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6ACDA0
#define CHtmlComponentWnd__ValidateUri_x                           0x73D700
#define CHtmlWnd__SetClientCallbacks_x                             0x6388A0
#define CHtmlWnd__AddObserver_x                                    0x6388C0
#define CHtmlWnd__RemoveObserver_x                                 0x638920
#define Window__getProgress_x                                      0x854120
#define Window__getStatus_x                                        0x854140
#define Window__getURI_x                                           0x854150

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x957200

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90B320

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9890
#define CXStr__CXStr1_x                                            0x5C1B30
#define CXStr__CXStr3_x                                            0x8F2630
#define CXStr__dCXStr_x                                            0x478490
#define CXStr__operator_equal_x                                    0x8F2860
#define CXStr__operator_equal1_x                                   0x8F28A0
#define CXStr__operator_plus_equal1_x                              0x8F3330
#define CXStr__SetString_x                                         0x8F5220
#define CXStr__operator_char_p_x                                   0x8F2D70
#define CXStr__GetChar_x                                           0x8F4B50
#define CXStr__Delete_x                                            0x8F4420
#define CXStr__GetUnicode_x                                        0x8F4BC0
#define CXStr__GetLength_x                                         0x4A8EE0
#define CXStr__Mid_x                                               0x47D5E0
#define CXStr__Insert_x                                            0x8F4C20
#define CXStr__FindNext_x                                          0x8F4890

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93F7A0
#define CXWnd__BringToTop_x                                        0x924AA0
#define CXWnd__Center_x                                            0x924620
#define CXWnd__ClrFocus_x                                          0x924440
#define CXWnd__Destroy_x                                           0x9244E0
#define CXWnd__DoAllDrawing_x                                      0x920AB0
#define CXWnd__DrawChildren_x                                      0x920A80
#define CXWnd__DrawColoredRect_x                                   0x920F10
#define CXWnd__DrawTooltip_x                                       0x91F5F0
#define CXWnd__DrawTooltipAtPoint_x                                0x91F6B0
#define CXWnd__GetBorderFrame_x                                    0x920D70
#define CXWnd__GetChildWndAt_x                                     0x924B40
#define CXWnd__GetClientClipRect_x                                 0x922D60
#define CXWnd__GetScreenClipRect_x                                 0x922E30
#define CXWnd__GetScreenRect_x                                     0x923000
#define CXWnd__GetRelativeRect_x                                   0x9230C0
#define CXWnd__GetTooltipRect_x                                    0x920F60
#define CXWnd__GetWindowTextA_x                                    0x49CDA0
#define CXWnd__IsActive_x                                          0x9216A0
#define CXWnd__IsDescendantOf_x                                    0x9239D0
#define CXWnd__IsReallyVisible_x                                   0x923A00
#define CXWnd__IsType_x                                            0x9251C0
#define CXWnd__Move_x                                              0x923A80
#define CXWnd__Move1_x                                             0x923B30
#define CXWnd__ProcessTransition_x                                 0x9245D0
#define CXWnd__Refade_x                                            0x923DE0
#define CXWnd__Resize_x                                            0x924070
#define CXWnd__Right_x                                             0x924860
#define CXWnd__SetFocus_x                                          0x924400
#define CXWnd__SetFont_x                                           0x924470
#define CXWnd__SetKeyTooltip_x                                     0x924FD0
#define CXWnd__SetMouseOver_x                                      0x921ED0
#define CXWnd__StartFade_x                                         0x9238B0
#define CXWnd__GetChildItem_x                                      0x924CB0
#define CXWnd__SetParent_x                                         0x923760
#define CXWnd__Minimize_x                                          0x9240E0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95B470

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x927960
#define CXWndManager__DrawWindows_x                                0x927980
#define CXWndManager__GetKeyboardFlags_x                           0x92A180
#define CXWndManager__HandleKeyboardMsg_x                          0x929D30
#define CXWndManager__RemoveWnd_x                                  0x92A3B0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92A900

// CDBStr
#define CDBStr__GetString_x                                        0x547D00

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFDA0
#define EQ_Character__Cur_HP_x                                     0x4D3050
#define EQ_Character__Cur_Mana_x                                   0x4DA760
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2E10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B37C0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3910
#define EQ_Character__GetHPRegen_x                                 0x4E0630
#define EQ_Character__GetEnduranceRegen_x                          0x4E0C30
#define EQ_Character__GetManaRegen_x                               0x4E1070
#define EQ_Character__Max_Endurance_x                              0x65F560
#define EQ_Character__Max_HP_x                                     0x4D2E80
#define EQ_Character__Max_Mana_x                                   0x65F360
#define EQ_Character__doCombatAbility_x                            0x661950
#define EQ_Character__UseSkill_x                                   0x4E2E70
#define EQ_Character__GetConLevel_x                                0x657BF0
#define EQ_Character__IsExpansionFlag_x                            0x5BB080
#define EQ_Character__TotalEffect_x                                0x4C6BB0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3B60
#define EQ_Character__SpellDuration_x                              0x4C3690
#define EQ_Character__MySpellDuration_x                            0x4B20F0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5DD0
#define EQ_Character__GetBaseSkill_x                               0x4D6D70
#define EQ_Character__CanUseItem_x                                 0x4DAA70

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BE220

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x675850

//PcClient
#define PcClient__vftable_x                                        0xAF21C4
#define PcClient__PcClient_x                                       0x655370

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA7E0
#define CCharacterListWnd__EnterWorld_x                            0x4BA1B0
#define CCharacterListWnd__Quit_x                                  0x4B9F00
#define CCharacterListWnd__UpdateList_x                            0x4BA3A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x639A70
#define EQ_Item__CreateItemTagString_x                             0x898100
#define EQ_Item__IsStackable_x                                     0x89CE10
#define EQ_Item__GetImageNum_x                                     0x899C70
#define EQ_Item__CreateItemClient_x                                0x638CA0
#define EQ_Item__GetItemValue_x                                    0x89AF60
#define EQ_Item__ValueSellMerchant_x                               0x89E810
#define EQ_Item__IsKeyRingItem_x                                   0x89C6C0
#define EQ_Item__CanGoInBag_x                                      0x639B90
#define EQ_Item__IsEmpty_x                                         0x89C200
#define EQ_Item__GetMaxItemCount_x                                 0x89B370
#define EQ_Item__GetHeldItem_x                                     0x899B40
#define EQ_Item__GetAugmentFitBySlot_x                             0x897960

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5666F0
#define EQ_LoadingS__Array_x                                       0xC13130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65FE60
#define EQ_PC__GetAlternateAbilityId_x                             0x8A7AD0
#define EQ_PC__GetCombatAbility_x                                  0x8A8140
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A81B0
#define EQ_PC__GetItemRecastTimer_x                                0x661ED0
#define EQ_PC__HasLoreItem_x                                       0x658410
#define EQ_PC__AlertInventoryChanged_x                             0x657540
#define EQ_PC__GetPcZoneClient_x                                   0x684860
#define EQ_PC__RemoveMyAffect_x                                    0x665100
#define EQ_PC__GetKeyRingItems_x                                   0x8A8A80
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A8800
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8D80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C1460
#define EQItemList__add_object_x                                   0x5EEAA0
#define EQItemList__add_item_x                                     0x5C19C0
#define EQItemList__delete_item_x                                  0x5C1A10
#define EQItemList__FreeItemList_x                                 0x5C1910

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544890

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x677150
#define EQPlayer__dEQPlayer_x                                      0x66A4D0
#define EQPlayer__DoAttack_x                                       0x67F000
#define EQPlayer__EQPlayer_x                                       0x66AB90
#define EQPlayer__SetNameSpriteState_x                             0x66EE60
#define EQPlayer__SetNameSpriteTint_x                              0x66FD40
#define PlayerBase__HasProperty_j_x                                0x989F60
#define EQPlayer__IsTargetable_x                                   0x98A400
#define EQPlayer__CanSee_x                                         0x98A260
#define EQPlayer__CanSee1_x                                        0x98A330
#define PlayerBase__GetVisibilityLineSegment_x                     0x98A020

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x682300
#define PlayerZoneClient__GetLevel_x                               0x6848A0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EFC10
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F520

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x679F20
#define EQPlayerManager__GetSpawnByName_x                          0x679FD0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A060

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63D2A0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63D320
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63D360
#define KeypressHandler__ClearCommandStateArray_x                  0x63E750
#define KeypressHandler__HandleKeyDown_x                           0x63E770
#define KeypressHandler__HandleKeyUp_x                             0x63E810
#define KeypressHandler__SaveKeymapping_x                          0x63EC60

// MapViewMap 
#define MapViewMap__Clear_x                                        0x775F80
#define MapViewMap__SaveEx_x                                       0x779340
#define MapViewMap__SetZoom_x                                      0x77DA00

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BC280

// StringTable 
#define StringTable__getString_x                                   0x8B6FC0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x664D70
#define PcZoneClient__RemovePetEffect_x                            0x6653A0
#define PcZoneClient__HasAlternateAbility_x                        0x65F190
#define PcZoneClient__GetCurrentMod_x                              0x4E5F80
#define PcZoneClient__GetModCap_x                                  0x4E5E80
#define PcZoneClient__CanEquipItem_x                               0x65F840
#define PcZoneClient__GetItemByID_x                                0x662340
#define PcZoneClient__GetItemByItemClass_x                         0x662490
#define PcZoneClient__RemoveBuffEffect_x                           0x6653C0
#define PcZoneClient__BandolierSwap_x                              0x660420
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x661E70

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F47F0

//IconCache
#define IconCache__GetIcon_x                                       0x717B70

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70F6B0
#define CContainerMgr__CloseContainer_x                            0x70F980
#define CContainerMgr__OpenExperimentContainer_x                   0x710400

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CE7B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631C50

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76C420
#define CLootWnd__RequestLootSlot_x                                0x76B700

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E680
#define EQ_Spell__SpellAffects_x                                   0x58EAF0
#define EQ_Spell__SpellAffectBase_x                                0x58E8B0
#define EQ_Spell__IsStackable_x                                    0x4CAA70
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA860
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7A80
#define EQ_Spell__IsSPAStacking_x                                  0x58F940
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58EE50
#define EQ_Spell__IsNoRemove_x                                     0x4CAA50
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58F950
#define __IsResEffectSpell_x                                       0x4C9C00

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD370

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C69A0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x815630
#define CTargetWnd__WndNotification_x                              0x814E70
#define CTargetWnd__RefreshTargetBuffs_x                           0x815140
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813FD0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x819CA0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81C8D0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5422A0
#define CTaskManager__HandleMessage_x                              0x540720
#define CTaskManager__GetTaskStatus_x                              0x542350
#define CTaskManager__GetElementDescription_x                      0x5423D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589710
#define EqSoundManager__PlayScriptMp3_x                            0x5899D0
#define EqSoundManager__SoundAssistPlay_x                          0x69CB70
#define EqSoundManager__WaveInstancePlay_x                         0x69C0E0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5336C0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x945F00
#define CTextureAnimation__Draw_x                                  0x946100

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x941E60

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E2B0
#define CAltAbilityData__GetMercMaxRank_x                          0x56E240
#define CAltAbilityData__GetMaxRank_x                              0x563640

//CTargetRing
#define CTargetRing__Cast_x                                        0x62FD70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA840
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A2B0
#define CharacterBase__CreateItemIndex_x                           0x637E50
#define CharacterBase__GetItemPossession_x                         0x505FF0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CF020
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CF080
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F65E0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6E10
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6EC0

//messages
#define msg_spell_worn_off_x                                       0x5B2FB0
#define msg_new_text_x                                             0x5A7940
#define __msgTokenTextParam_x                                      0x5B5240
#define msgTokenText_x                                             0x5B5490

//SpellManager
#define SpellManager__vftable_x                                    0xADA53C
#define SpellManager__SpellManager_x                               0x69FE90
#define Spellmanager__LoadTextSpells_x                             0x6A0780
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A0060

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98DF10

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51A930
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B94C0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x650B50
#define ItemGlobalIndex__IsValidIndex_x                            0x51A9C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C7360
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C74F0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764CF0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x713D80
#define CCursorAttachment__AttachToCursor1_x                       0x713DC0
#define CCursorAttachment__Deactivate_x                            0x714DB0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x938A80
#define CSidlManagerBase__CreatePageWnd_x                          0x938270
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9344F0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x934480

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x955D30
#define CEQSuiteTextureLoader__GetTexture_x                        0x9559F0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5175B0
#define CFindItemWnd__WndNotification_x                            0x5181E0
#define CFindItemWnd__Update_x                                     0x518D50
#define CFindItemWnd__PickupSelectedItem_x                         0x516DE0

//IString
#define IString__Append_x                                          0x507870

//Camera
#define CDisplay__cameraType_x                                     0xDEACCC
#define EverQuest__Cameras_x                                       0xEA60A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x520240
#define LootFiltersManager__GetItemFilterData_x                    0x51FB50
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51FB80
#define LootFiltersManager__SetItemLootFilter_x                    0x51FDA0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BC5C0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x993AA0
#define CResolutionHandler__GetWindowedStyle_x                     0x697710

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70C370

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D2E10
#define CDistillerInfo__Instance_x                                 0x8D2DB0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72B0B0
#define CGroupWnd__UpdateDisplay_x                                 0x72A400

//ItemBase
#define ItemBase__IsLore_x                                         0x89C770
#define ItemBase__IsLoreEquipped_x                                 0x89C7E0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EEA00
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EEB40
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EEBA0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68CF60
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6908B0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50DD30

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9EF0
#define FactionManagerClient__HandleFactionMessage_x               0x4FA560
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAB20
#define FactionManagerClient__GetMaxFaction_x                      0x4FAB3F
#define FactionManagerClient__GetMinFaction_x                      0x4FAAF0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505FC0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91D250

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C0B0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x506280

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56D740

//CTargetManager
#define CTargetManager__Get_x                                      0x6A36C0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68CF60

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8EF0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C18B0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF43734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BFF10
#define CAAWnd__UpdateSelected_x                                   0x6BC780
#define CAAWnd__Update_x                                           0x6BF230

//CXRect
#define CXRect__operator_and_x                                     0x722180

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4831F0

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
