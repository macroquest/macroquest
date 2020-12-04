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
#define __ExpectedVersionDate                                     "Nov 22 2020"
#define __ExpectedVersionTime                                     "04:19:29"
#define __ActualVersionDate_x                                      0xAF5530
#define __ActualVersionTime_x                                      0xAF5524
#define __ActualVersionBuild_x                                     0xAE3544

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6433C0
#define __MemChecker1_x                                            0x8F6650
#define __MemChecker2_x                                            0x6B37B0
#define __MemChecker3_x                                            0x6B3700
#define __MemChecker4_x                                            0x84C5D0
#define __EncryptPad0_x                                            0xC2B9C8
#define __EncryptPad1_x                                            0xC89210
#define __EncryptPad2_x                                            0xC3BD90
#define __EncryptPad3_x                                            0xC3B990
#define __EncryptPad4_x                                            0xC797A0
#define __EncryptPad5_x                                            0xF4C0E0
#define __AC1_x                                                    0x80B166
#define __AC2_x                                                    0x5FC9FF
#define __AC3_x                                                    0x604050
#define __AC4_x                                                    0x608000
#define __AC5_x                                                    0x60E2FF
#define __AC6_x                                                    0x6127B6
#define __AC7_x                                                    0x5FC470
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1972F0

// Direct Input
#define DI8__Main_x                                                0xF4C108
#define DI8__Keyboard_x                                            0xF4C10C
#define DI8__Mouse_x                                               0xF4C0EC
#define DI8__Mouse_Copy_x                                          0xEA49E4
#define DI8__Mouse_Check_x                                         0xF49C34
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
#define __do_loot_x                                                0x5C8440
#define __DrawHandler_x                                            0x15DB140
#define __GroupCount_x                                             0xE9D502
#define __Guilds_x                                                 0xEA3920
#define __gWorld_x                                                 0xE9DC98
#define __HWnd_x                                                   0xF4C0F0
#define __heqmain_x                                                0xF4C0C8
#define __InChatMode_x                                             0xEA49CC
#define __LastTell_x                                               0xEA694C
#define __LMouseHeldTime_x                                         0xEA4B08
#define __Mouse_x                                                  0xF4C0F4
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
#define __ServerName_x                                             0xEDB210
#define __ShiftKeyDown_x                                           0xEA5060
#define __ShowNames_x                                              0xEA5DA0
#define EverQuestInfo__bSocialChanged_x                            0xEDB298
#define __Socials_x                                                0xEDB310
#define __SubscriptionType_x                                       0xFA0410
#define __TargetAggroHolder_x                                      0xF5EB00
#define __ZoneType_x                                               0xEA4E60
#define __GroupAggro_x                                             0xF5EB40
#define __LoginName_x                                              0xF498C4
#define __Inviter_x                                                0xF436AC
#define __AttackOnAssist_x                                         0xEA5D5C
#define __UseTellWindows_x                                         0xEA6094
#define __gfMaxZoomCameraDistance_x                                0xAED140
#define __gfMaxCameraDistance_x                                    0xB15DD8
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
#define pinstCEverQuest_x                                          0xF49188
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
#define pinstEqLogin_x                                             0xF49210
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
#define pinstViewActor_x                                           0xDEB498
#define pinstWorldData_x                                           0xE9D3A8
#define pinstZoneAddr_x                                            0xEA4EF8
#define pinstPlayerPath_x                                          0xF469A8
#define pinstTargetIndicator_x                                     0xF48310
#define EQObject_Top_x                                             0xE9D820
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEAF3C
#define pinstCAchievementsWnd_x                                    0xDEB450
#define pinstCActionsWnd_x                                         0xDEAF78
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDEB510
#define pinstCAdvancedLootWnd_x                                    0xDEB4C4
#define pinstCAdventureLeaderboardWnd_x                            0xF55920
#define pinstCAdventureRequestWnd_x                                0xF559D0
#define pinstCAdventureStatsWnd_x                                  0xF55A80
#define pinstCAggroMeterWnd_x                                      0xDEB4F8
#define pinstCAlarmWnd_x                                           0xDEB47C
#define pinstCAlertHistoryWnd_x                                    0xDEAEF0
#define pinstCAlertStackWnd_x                                      0xDEB4E0
#define pinstCAlertWnd_x                                           0xDEB4F4
#define pinstCAltStorageWnd_x                                      0xF55DE0
#define pinstCAudioTriggersWindow_x                                0xC9F778
#define pinstCAuraWnd_x                                            0xDEB4C8
#define pinstCAvaZoneWnd_x                                         0xDEAEEC
#define pinstCBandolierWnd_x                                       0xDEB50C
#define pinstCBankWnd_x                                            0xDEACB0
#define pinstCBarterMerchantWnd_x                                  0xF57020
#define pinstCBarterSearchWnd_x                                    0xF570D0
#define pinstCBarterWnd_x                                          0xF57180
#define pinstCBazaarConfirmationWnd_x                              0xDEB490
#define pinstCBazaarSearchWnd_x                                    0xDEAF40
#define pinstCBazaarWnd_x                                          0xDEB45C
#define pinstCBlockedBuffWnd_x                                     0xDEB4D4
#define pinstCBlockedPetBuffWnd_x                                  0xDEB4FC
#define pinstCBodyTintWnd_x                                        0xDEB404
#define pinstCBookWnd_x                                            0xDEB544
#define pinstCBreathWnd_x                                          0xDEAF50
#define pinstCBuffWindowNORMAL_x                                   0xDEB4BC
#define pinstCBuffWindowSHORT_x                                    0xDEB4C0
#define pinstCBugReportWnd_x                                       0xDEACAC
#define pinstCButtonWnd_x                                          0x15DA570
#define pinstCCastingWnd_x                                         0xDEB538
#define pinstCCastSpellWnd_x                                       0xDEAF4C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEB410
#define pinstCChatWindowManager_x                                  0xF57C40
#define pinstCClaimWnd_x                                           0xF57D98
#define pinstCColorPickerWnd_x                                     0xDEAF08
#define pinstCCombatAbilityWnd_x                                   0xDEB470
#define pinstCCombatSkillsSelectWnd_x                              0xDEB424
#define pinstCCompassWnd_x                                         0xDEAF8C
#define pinstCConfirmationDialog_x                                 0xF5CC98
#define pinstCContainerMgr_x                                       0xDEB400
#define pinstCContextMenuManager_x                                 0x15DA2C0
#define pinstCCursorAttachment_x                                   0xDEB52C
#define pinstCDynamicZoneWnd_x                                     0xF58360
#define pinstCEditLabelWnd_x                                       0xDEB4B8
#define pinstCEQMainWnd_x                                          0xF585A8
#define pinstCEventCalendarWnd_x                                   0xDEAF44
#define pinstCExtendedTargetWnd_x                                  0xDEB4D8
#define pinstCPlayerCustomizationWnd_x                             0xDEB428
#define pinstCFactionWnd_x                                         0xDEB448
#define pinstCFellowshipWnd_x                                      0xF587A8
#define pinstCFileSelectionWnd_x                                   0xDEAF00
#define pinstCFindItemWnd_x                                        0xDEB43C
#define pinstCFindLocationWnd_x                                    0xF58900
#define pinstCFriendsWnd_x                                         0xDEB438
#define pinstCGemsGameWnd_x                                        0xDEB444
#define pinstCGiveWnd_x                                            0xDEB484
#define pinstCGroupSearchFiltersWnd_x                              0xDEB514
#define pinstCGroupSearchWnd_x                                     0xF58CF8
#define pinstCGroupWnd_x                                           0xF58DA8
#define pinstCGuildBankWnd_x                                       0xF58E58
#define pinstCGuildCreationWnd_x                                   0xF58F08
#define pinstCGuildMgmtWnd_x                                       0xF58FB8
#define pinstCharacterCreation_x                                   0xDEB430
#define pinstCHelpWnd_x                                            0xDEB480
#define pinstCHeritageSelectionWnd_x                               0xDEB434
#define pinstCHotButtonWnd_x                                       0xF5B110
#define pinstCHotButtonWnd1_x                                      0xF5B110
#define pinstCHotButtonWnd2_x                                      0xF5B114
#define pinstCHotButtonWnd3_x                                      0xF5B118
#define pinstCHotButtonWnd4_x                                      0xF5B11C
#define pinstCIconSelectionWnd_x                                   0xDEB51C
#define pinstCInspectWnd_x                                         0xDEB500
#define pinstCInventoryWnd_x                                       0xDEB4CC
#define pinstCInvSlotMgr_x                                         0xDEAF30
#define pinstCItemDisplayManager_x                                 0xF5B6A0
#define pinstCItemExpTransferWnd_x                                 0xF5B7D0
#define pinstCItemOverflowWnd_x                                    0xDEAF48
#define pinstCJournalCatWnd_x                                      0xDEAF1C
#define pinstCJournalNPCWnd_x                                      0xDEAEDC
#define pinstCJournalTextWnd_x                                     0xDEAEDC
#define pinstCKeyRingWnd_x                                         0xDEB534
#define pinstCLargeDialogWnd_x                                     0xF5D918
#define pinstCLayoutCopyWnd_x                                      0xF5BB20
#define pinstCLFGuildWnd_x                                         0xF5BBD0
#define pinstCLoadskinWnd_x                                        0xDEB460
#define pinstCLootFiltersCopyWnd_x                                 0xCBBEE8
#define pinstCLootFiltersWnd_x                                     0xDEB4E4
#define pinstCLootSettingsWnd_x                                    0xDEB508
#define pinstCLootWnd_x                                            0xDEAF20
#define pinstCMailAddressBookWnd_x                                 0xDEAF34
#define pinstCMailCompositionWnd_x                                 0xDEAF0C
#define pinstCMailIgnoreListWnd_x                                  0xDEAF38
#define pinstCMailWnd_x                                            0xDEAEF8
#define pinstCManageLootWnd_x                                      0xDEC3A0
#define pinstCMapToolbarWnd_x                                      0xDEB48C
#define pinstCMapViewWnd_x                                         0xDEB454
#define pinstCMarketplaceWnd_x                                     0xDEB4E8
#define pinstCMerchantWnd_x                                        0xDEAF2C
#define pinstCMIZoneSelectWnd_x                                    0xF5C408
#define pinstCMusicPlayerWnd_x                                     0xDEACCC
#define pinstCNameChangeMercWnd_x                                  0xDEB488
#define pinstCNameChangePetWnd_x                                   0xDEB458
#define pinstCNameChangeWnd_x                                      0xDEB4B0
#define pinstCNoteWnd_x                                            0xDEB464
#define pinstCObjectPreviewWnd_x                                   0xDEB504
#define pinstCOptionsWnd_x                                         0xDEB474
#define pinstCPetInfoWnd_x                                         0xDEAEF4
#define pinstCPetitionQWnd_x                                       0xDEB420
#define pinstCPlayerNotesWnd_x                                     0xDEB408
#define pinstCPlayerWnd_x                                          0xDEAEE8
#define pinstCPopupWndManager_x                                    0xF5CC98
#define pinstCProgressionSelectionWnd_x                            0xF5CD48
#define pinstCPurchaseGroupWnd_x                                   0xDEACC0
#define pinstCPurchaseWnd_x                                        0xDEB53C
#define pinstCPvPLeaderboardWnd_x                                  0xF5CDF8
#define pinstCPvPStatsWnd_x                                        0xF5CEA8
#define pinstCQuantityWnd_x                                        0xDEAED8
#define pinstCRaceChangeWnd_x                                      0xDEB4D0
#define pinstCRaidOptionsWnd_x                                     0xDEB518
#define pinstCRaidWnd_x                                            0xDEAF28
#define pinstCRealEstateItemsWnd_x                                 0xDEB44C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEAFF8
#define pinstCRealEstateManageWnd_x                                0xDEACC8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEAEE4
#define pinstCRealEstatePlotSearchWnd_x                            0xDEAEFC
#define pinstCRealEstatePurchaseWnd_x                              0xDEAF18
#define pinstCRespawnWnd_x                                         0xDEB4F0
#define pinstCRewardSelectionWnd_x                                 0xF5D5F0
#define pinstCSelectorWnd_x                                        0xDEB41C
#define pinstCSendMoneyWnd_x                                       0xDEB494
#define pinstCServerListWnd_x                                      0xDEAF24
#define pinstCSkillsSelectWnd_x                                    0xDEB418
#define pinstCSkillsWnd_x                                          0xDEAFF4
#define pinstCSocialEditWnd_x                                      0xDEB530
#define pinstCSocialWnd_x                                          0xDEB478
#define pinstCSpellBookWnd_x                                       0xDEB468
#define pinstCStoryWnd_x                                           0xDEAF74
#define pinstCTargetOfTargetWnd_x                                  0xF5EC50
#define pinstCTargetWnd_x                                          0xDEB4EC
#define pinstCTaskOverlayWnd_x                                     0xDEACB8
#define pinstCTaskSelectWnd_x                                      0xF5EDA8
#define pinstCTaskManager_x                                        0xCBC828
#define pinstCTaskTemplateSelectWnd_x                              0xF5EE58
#define pinstCTaskWnd_x                                            0xF5EF08
#define pinstCTextEntryWnd_x                                       0xDEB540
#define pinstCTimeLeftWnd_x                                        0xDEB414
#define pinstCTipWndCONTEXT_x                                      0xF5F10C
#define pinstCTipWndOFDAY_x                                        0xF5F108
#define pinstCTitleWnd_x                                           0xF5F1B8
#define pinstCTrackingWnd_x                                        0xDEB4DC
#define pinstCTradeskillWnd_x                                      0xF5F320
#define pinstCTradeWnd_x                                           0xDEB40C
#define pinstCTrainWnd_x                                           0xDEAF14
#define pinstCTributeBenefitWnd_x                                  0xF5F520
#define pinstCTributeMasterWnd_x                                   0xF5F5D0
#define pinstCTributeTrophyWnd_x                                   0xF5F680
#define pinstCVideoModesWnd_x                                      0xDEACB4
#define pinstCVoiceMacroWnd_x                                      0xF488C8
#define pinstCVoteResultsWnd_x                                     0xDEB440
#define pinstCVoteWnd_x                                            0xDEB42C
#define pinstCWebManager_x                                         0xF48F44
#define pinstCZoneGuideWnd_x                                       0xDEACBC
#define pinstCZonePathWnd_x                                        0xDEAED4

#define pinstEQSuiteTextureLoader_x                                0xC89B30
#define pinstItemIconCache_x                                       0xF58560
#define pinstLootFiltersManager_x                                  0xCBBF98
#define pinstRewardSelectionWnd_x                                  0xF5D5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C3B30
#define __CastRay2_x                                               0x5C3B80
#define __ConvertItemTags_x                                        0x5DF840
#define __CleanItemTags_x                                          0x47D170
#define __DoesFileExist_x                                          0x8F9680
#define __EQGetTime_x                                              0x8F6280
#define __ExecuteCmd_x                                             0x5BC4A0
#define __FixHeading_x                                             0x98BDF0
#define __FlushDxKeyboard_x                                        0x6AF650
#define __GameLoop_x                                               0x6B2980
#define __get_bearing_x                                            0x5C3690
#define __get_melee_range_x                                        0x5C3D70
#define __GetAnimationCache_x                                      0x717DF0
#define __GetGaugeValueFromEQ_x                                    0x809610
#define __GetLabelFromEQ_x                                         0x80B0F0
#define __GetXTargetType_x                                         0x98D7D0
#define __HandleMouseWheel_x                                       0x6B3860
#define __HeadingDiff_x                                            0x98BE60
#define __HelpPath_x                                               0xF43E04
#define __LoadFrontEnd_x                                           0x6AFC90
#define __NewUIINI_x                                               0x8092E0
#define __ProcessGameEvents_x                                      0x624690
#define __ProcessMouseEvent_x                                      0x623E20
#define __SaveColors_x                                             0x55DBD0
#define __STMLToText_x                                             0x92F3F0
#define __ToggleKeyRingItem_x                                      0x51C1D0
#define CMemoryMappedFile__SetFile_x                               0xA7B1A0
#define CrashDetected_x                                            0x6B1740
#define DrawNetStatus_x                                            0x650970
#define Expansion_HoT_x                                            0xEA5D48
#define Teleport_Table_Size_x                                      0xE9D7E0
#define Teleport_Table_x                                           0xE9DCB0
#define Util__FastTime_x                                           0x8F5E50
#define __CopyLayout_x                                             0x63EA20
#define __WndProc_x                                                0x6B1C40
#define __ProcessKeyboardEvent_x                                   0x6B11E0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4994F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4992C0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A90
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492EE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565DA0
#define AltAdvManager__IsAbilityReady_x                            0x564B40
#define AltAdvManager__GetAAById_x                                 0x564ED0
#define AltAdvManager__CanTrainAbility_x                           0x564F40
#define AltAdvManager__CanSeeAbility_x                             0x5652A0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAFB0
#define CharacterZoneClient__HasSkill_x                            0x4D5E30
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7550
#define CharacterZoneClient__IsStackBlocked_x                      0x4C26C0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBB50
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9EB0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9F90
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA070
#define CharacterZoneClient__FindAffectSlot_x                      0x4C47B0
#define CharacterZoneClient__BardCastBard_x                        0x4C71E0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF560
#define CharacterZoneClient__GetEffect_x                           0x4BBA90
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5820
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C58F0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5940
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5A90
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5C70
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3AB0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D84B0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7F30

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D94D0
#define CBankWnd__WndNotification_x                                0x6D92A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6D00

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92CBD0
#define CButtonWnd__CButtonWnd_x                                   0x92B7E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706F60
#define CChatManager__InitContextMenu_x                            0x7000A0
#define CChatManager__FreeChatWindow_x                             0x705AA0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9970
#define CChatManager__SetLockedActiveChatWindow_x                  0x706BE0
#define CChatManager__CreateChatWindow_x                           0x7060E0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9A80

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93FD00
#define CContextMenu__dCContextMenu_x                              0x93FF30
#define CContextMenu__AddMenuItem_x                                0x93FF40
#define CContextMenu__RemoveMenuItem_x                             0x940250
#define CContextMenu__RemoveAllMenuItems_x                         0x940270
#define CContextMenu__CheckMenuItem_x                              0x9402F0
#define CContextMenu__SetMenuItem_x                                0x940170
#define CContextMenu__AddSeparator_x                               0x9400D0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x940890
#define CContextMenuManager__RemoveMenu_x                          0x940900
#define CContextMenuManager__PopupMenu_x                           0x9409C0
#define CContextMenuManager__Flush_x                               0x940830
#define CContextMenuManager__GetMenu_x                             0x49B690
#define CContextMenuManager__CreateDefaultMenu_x                   0x712720

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x812C80
#define CChatService__GetFriendName_x                              0x8D10E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x707790
#define CChatWindow__Clear_x                                       0x708A50
#define CChatWindow__WndNotification_x                             0x7091E0
#define CChatWindow__AddHistory_x                                  0x708310

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93D170
#define CComboWnd__Draw_x                                          0x93C670
#define CComboWnd__GetCurChoice_x                                  0x93CFB0
#define CComboWnd__GetListRect_x                                   0x93CB20
#define CComboWnd__GetTextRect_x                                   0x93D1E0
#define CComboWnd__InsertChoice_x                                  0x93CCB0
#define CComboWnd__SetColors_x                                     0x93CC80
#define CComboWnd__SetChoice_x                                     0x93CF80
#define CComboWnd__GetItemCount_x                                  0x93CFC0
#define CComboWnd__GetCurChoiceText_x                              0x93D000
#define CComboWnd__GetChoiceText_x                                 0x93CFD0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93CD40

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x710140
#define CContainerWnd__vftable_x                                   0xAFE73C
#define CContainerWnd__SetContainer_x                              0x7116A0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558530
#define CDisplay__PreZoneMainUI_x                                  0x558540
#define CDisplay__CleanGameUI_x                                    0x55D990
#define CDisplay__GetClickedActor_x                                0x550990
#define CDisplay__GetUserDefinedColor_x                            0x549000
#define CDisplay__GetWorldFilePath_x                               0x552400
#define CDisplay__is3dON_x                                         0x54D5F0
#define CDisplay__ReloadUI_x                                       0x557A40
#define CDisplay__WriteTextHD2_x                                   0x54D3E0
#define CDisplay__TrueDistance_x                                   0x5540C0
#define CDisplay__SetViewActor_x                                   0x5502B0
#define CDisplay__GetFloorHeight_x                                 0x54D6B0
#define CDisplay__SetRenderWindow_x                                0x54C030
#define CDisplay__ToggleScreenshotMode_x                           0x54FD80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95FA20

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9431D0
#define CEditWnd__EnsureCaretVisible_x                             0x9453A0
#define CEditWnd__GetCaretPt_x                                     0x944350
#define CEditWnd__GetCharIndexPt_x                                 0x944100
#define CEditWnd__GetDisplayString_x                               0x943FA0
#define CEditWnd__GetHorzOffset_x                                  0x942870
#define CEditWnd__GetLineForPrintableChar_x                        0x9452A0
#define CEditWnd__GetSelStartPt_x                                  0x9443B0
#define CEditWnd__GetSTMLSafeText_x                                0x943DC0
#define CEditWnd__PointFromPrintableChar_x                         0x944ED0
#define CEditWnd__SelectableCharFromPoint_x                        0x945040
#define CEditWnd__SetEditable_x                                    0x944480
#define CEditWnd__SetWindowTextA_x                                 0x943B40
#define CEditWnd__ReplaceSelection_x                               0x944B40
#define CEditWnd__ReplaceSelection1_x                              0x944AC0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611C90
#define CEverQuest__ClickedPlayer_x                                0x603E30
#define CEverQuest__CreateTargetIndicator_x                        0x621800
#define CEverQuest__DeleteTargetIndicator_x                        0x621890
#define CEverQuest__DoTellWindow_x                                 0x4E9B60
#define CEverQuest__OutputTextToLog_x                              0x4E9E30
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8F90
#define CEverQuest__dsp_chat_x                                     0x4EA1C0
#define CEverQuest__trimName_x                                     0x61D9B0
#define CEverQuest__Emote_x                                        0x6124F0
#define CEverQuest__EnterZone_x                                    0x60C5F0
#define CEverQuest__GetBodyTypeDesc_x                              0x616F40
#define CEverQuest__GetClassDesc_x                                 0x617580
#define CEverQuest__GetClassThreeLetterCode_x                      0x617B80
#define CEverQuest__GetDeityDesc_x                                 0x620050
#define CEverQuest__GetLangDesc_x                                  0x617D40
#define CEverQuest__GetRaceDesc_x                                  0x617560
#define CEverQuest__InterpretCmd_x                                 0x620620
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FD120
#define CEverQuest__LMouseUp_x                                     0x5FB4B0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FDA00
#define CEverQuest__RMouseUp_x                                     0x5FC430
#define CEverQuest__SetGameState_x                                 0x5F8D20
#define CEverQuest__UPCNotificationFlush_x                         0x61D8B0
#define CEverQuest__IssuePetCommand_x                              0x619150
#define CEverQuest__ReportSuccessfulHit_x                          0x613840

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x721D30
#define CGaugeWnd__CalcLinesFillRect_x                             0x721D90
#define CGaugeWnd__Draw_x                                          0x7213B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFD50
#define CGuild__GetGuildName_x                                     0x4AE800
#define CGuild__GetGuildIndex_x                                    0x4AEE00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B9C0

//CHotButton
#define CHotButton__SetCheck_x                                     0x632EA0
#define CHotButton__SetButtonSize_x                                0x633260

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748AD0
#define CInvSlotMgr__MoveItem_x                                    0x7477A0
#define CInvSlotMgr__SelectSlot_x                                  0x748BA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x745F90
#define CInvSlot__SliderComplete_x                                 0x743CE0
#define CInvSlot__GetItemBase_x                                    0x743650
#define CInvSlot__UpdateItem_x                                     0x7437C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74A630
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7497C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74A1B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x804980
#define CItemDisplayWnd__UpdateStrings_x                           0x758E90
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752AD0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x753000
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x759490
#define CItemDisplayWnd__AboutToShow_x                             0x758AD0
#define CItemDisplayWnd__WndNotification_x                         0x75A700
#define CItemDisplayWnd__RequestConvertItem_x                      0x75A040
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x757B40
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7588F0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8354D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75EC10

// CLabel 
#define CLabel__Draw_x                                             0x7646A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x915950
#define CListWnd__dCListWnd_x                                      0x915C70
#define CListWnd__AddColumn_x                                      0x91A0F0
#define CListWnd__AddColumn1_x                                     0x91A140
#define CListWnd__AddLine_x                                        0x91A4D0
#define CListWnd__AddString_x                                      0x91A2D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x919EB0
#define CListWnd__CalculateVSBRange_x                              0x919CA0
#define CListWnd__ClearSel_x                                       0x91ACB0
#define CListWnd__ClearAllSel_x                                    0x91AD10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91B730
#define CListWnd__Compare_x                                        0x9195D0
#define CListWnd__Draw_x                                           0x915DA0
#define CListWnd__DrawColumnSeparators_x                           0x9185A0
#define CListWnd__DrawHeader_x                                     0x918A10
#define CListWnd__DrawItem_x                                       0x918F10
#define CListWnd__DrawLine_x                                       0x918710
#define CListWnd__DrawSeparator_x                                  0x918640
#define CListWnd__EnableLine_x                                     0x917E70
#define CListWnd__EnsureVisible_x                                  0x91B650
#define CListWnd__ExtendSel_x                                      0x91ABE0
#define CListWnd__GetColumnTooltip_x                               0x9179B0
#define CListWnd__GetColumnMinWidth_x                              0x917A20
#define CListWnd__GetColumnWidth_x                                 0x917920
#define CListWnd__GetCurSel_x                                      0x9172B0
#define CListWnd__GetItemAtPoint_x                                 0x9180F0
#define CListWnd__GetItemAtPoint1_x                                0x918160
#define CListWnd__GetItemData_x                                    0x917330
#define CListWnd__GetItemHeight_x                                  0x9176F0
#define CListWnd__GetItemIcon_x                                    0x9174C0
#define CListWnd__GetItemRect_x                                    0x917F60
#define CListWnd__GetItemText_x                                    0x917370
#define CListWnd__GetSelList_x                                     0x91AD60
#define CListWnd__GetSeparatorRect_x                               0x9183A0
#define CListWnd__InsertLine_x                                     0x91A8C0
#define CListWnd__RemoveLine_x                                     0x91AA10
#define CListWnd__SetColors_x                                      0x919C70
#define CListWnd__SetColumnJustification_x                         0x9199A0
#define CListWnd__SetColumnLabel_x                                 0x91A270
#define CListWnd__SetColumnWidth_x                                 0x9198C0
#define CListWnd__SetCurSel_x                                      0x91AB20
#define CListWnd__SetItemColor_x                                   0x91B300
#define CListWnd__SetItemData_x                                    0x91B2C0
#define CListWnd__SetItemText_x                                    0x91AED0
#define CListWnd__ShiftColumnSeparator_x                           0x919A60
#define CListWnd__Sort_x                                           0x919750
#define CListWnd__ToggleSel_x                                      0x91AB50
#define CListWnd__SetColumnsSizable_x                              0x919B10
#define CListWnd__SetItemWnd_x                                     0x91B180
#define CListWnd__GetItemWnd_x                                     0x917510
#define CListWnd__SetItemIcon_x                                    0x91AF50
#define CListWnd__CalculateCustomWindowPositions_x                 0x919FB0
#define CListWnd__SetVScrollPos_x                                  0x9198A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779D60
#define CMapViewWnd__GetWorldCoordinates_x                         0x778470
#define CMapViewWnd__HandleLButtonDown_x                           0x7754B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79A1D0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79AAB0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79AFE0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79DF90
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x798D50
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A3B50
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799DF0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E900
#define CPacketScrambler__hton_x                                   0x89E8F0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9349C0
#define CSidlManager__FindScreenPieceTemplate_x                    0x934DD0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x934BC0
#define CSidlManager__CreateLabel_x                                0x7FBB50
#define CSidlManager__CreateXWndFromTemplate_x                     0x937D30
#define CSidlManager__CreateXWndFromTemplate1_x                    0x937F00
#define CSidlManager__CreateXWnd_x                                 0x7FBA80
#define CSidlManager__CreateHotButtonWnd_x                         0x7FC040

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9314A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9313A0
#define CSidlScreenWnd__ConvertToRes_x                             0x95A570
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930EA0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x930B90
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x930C60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x930D30
#define CSidlScreenWnd__DrawSidlPiece_x                            0x931940
#define CSidlScreenWnd__EnableIniStorage_x                         0x931E10
#define CSidlScreenWnd__GetSidlPiece_x                             0x931B30
#define CSidlScreenWnd__Init1_x                                    0x930790
#define CSidlScreenWnd__LoadIniInfo_x                              0x931E60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9329A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92FBA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x932520
#define CSidlScreenWnd__StoreIniVis_x                              0x932880
#define CSidlScreenWnd__WndNotification_x                          0x931850
#define CSidlScreenWnd__GetChildItem_x                             0x931D90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9215C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DA190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6989C0
#define CSkillMgr__GetSkillCap_x                                   0x698BA0
#define CSkillMgr__GetNameToken_x                                  0x698140
#define CSkillMgr__IsActivatedSkill_x                              0x698280
#define CSkillMgr__IsCombatSkill_x                                 0x6981C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x941650
#define CSliderWnd__SetValue_x                                     0x9414C0
#define CSliderWnd__SetNumTicks_x                                  0x941520

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801D60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x949F90
#define CStmlWnd__ParseSTML_x                                      0x94B290
#define CStmlWnd__CalculateHSBRange_x                              0x94B070
#define CStmlWnd__CalculateVSBRange_x                              0x94AFE0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94F3A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x950030
#define CStmlWnd__ForceParseNow_x                                  0x94A530
#define CStmlWnd__GetNextTagPiece_x                                0x94F300
#define CStmlWnd__GetSTMLText_x                                    0x50D5B0
#define CStmlWnd__GetVisibleText_x                                 0x94A550
#define CStmlWnd__InitializeWindowVariables_x                      0x94FE80
#define CStmlWnd__MakeStmlColorTag_x                               0x949600
#define CStmlWnd__MakeWndNotificationTag_x                         0x949670
#define CStmlWnd__SetSTMLText_x                                    0x9486B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x951130
#define CStmlWnd__UpdateHistoryString_x                            0x950240

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9477F0
#define CTabWnd__DrawCurrentPage_x                                 0x947F20
#define CTabWnd__DrawTab_x                                         0x947C40
#define CTabWnd__GetCurrentPage_x                                  0x947000
#define CTabWnd__GetPageInnerRect_x                                0x947240
#define CTabWnd__GetTabInnerRect_x                                 0x947180
#define CTabWnd__GetTabRect_x                                      0x947030
#define CTabWnd__InsertPage_x                                      0x947450
#define CTabWnd__RemovePage_x                                      0x9475C0
#define CTabWnd__SetPage_x                                         0x9472C0
#define CTabWnd__SetPageRect_x                                     0x947730
#define CTabWnd__UpdatePage_x                                      0x947B00
#define CTabWnd__GetPageFromTabIndex_x                             0x947B80
#define CTabWnd__GetCurrentTabIndex_x                              0x946FF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75F020
#define CPageWnd__SetTabText_x                                     0x946B50
#define CPageWnd__FlashTab_x                                       0x946BB0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A90F0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91E470
#define CTextureFont__GetTextExtent_x                              0x91E630

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6ACB20
#define CHtmlComponentWnd__ValidateUri_x                           0x73D3B0
#define CHtmlWnd__SetClientCallbacks_x                             0x6382D0
#define CHtmlWnd__AddObserver_x                                    0x6382F0
#define CHtmlWnd__RemoveObserver_x                                 0x638350
#define Window__getProgress_x                                      0x853B90
#define Window__getStatus_x                                        0x853BB0
#define Window__getURI_x                                           0x853BC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x957380

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90B490

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E97B0
#define CXStr__CXStr1_x                                            0x481670
#define CXStr__CXStr3_x                                            0x8F2240
#define CXStr__dCXStr_x                                            0x4783A0
#define CXStr__operator_equal_x                                    0x8F2470
#define CXStr__operator_equal1_x                                   0x8F24B0
#define CXStr__operator_plus_equal1_x                              0x8F2F40
#define CXStr__SetString_x                                         0x8F4E30
#define CXStr__operator_char_p_x                                   0x8F29B0
#define CXStr__GetChar_x                                           0x8F4780
#define CXStr__Delete_x                                            0x8F4030
#define CXStr__GetUnicode_x                                        0x8F47F0
#define CXStr__GetLength_x                                         0x4A8EA0
#define CXStr__Mid_x                                               0x47D520
#define CXStr__Insert_x                                            0x8F4850
#define CXStr__FindNext_x                                          0x8F44A0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93F920
#define CXWnd__BringToTop_x                                        0x924DE0
#define CXWnd__Center_x                                            0x924960
#define CXWnd__ClrFocus_x                                          0x924770
#define CXWnd__Destroy_x                                           0x924820
#define CXWnd__DoAllDrawing_x                                      0x920D70
#define CXWnd__DrawChildren_x                                      0x920D40
#define CXWnd__DrawColoredRect_x                                   0x9211B0
#define CXWnd__DrawTooltip_x                                       0x91F890
#define CXWnd__DrawTooltipAtPoint_x                                0x91F950
#define CXWnd__GetBorderFrame_x                                    0x921010
#define CXWnd__GetChildWndAt_x                                     0x924E80
#define CXWnd__GetClientClipRect_x                                 0x923010
#define CXWnd__GetScreenClipRect_x                                 0x9230E0
#define CXWnd__GetScreenRect_x                                     0x923290
#define CXWnd__GetRelativeRect_x                                   0x923350
#define CXWnd__GetTooltipRect_x                                    0x921200
#define CXWnd__GetWindowTextA_x                                    0x49CE20
#define CXWnd__IsActive_x                                          0x921930
#define CXWnd__IsDescendantOf_x                                    0x923CA0
#define CXWnd__IsReallyVisible_x                                   0x923CD0
#define CXWnd__IsType_x                                            0x9254F0
#define CXWnd__Move_x                                              0x923D40
#define CXWnd__Move1_x                                             0x923DF0
#define CXWnd__ProcessTransition_x                                 0x924910
#define CXWnd__Refade_x                                            0x9240C0
#define CXWnd__Resize_x                                            0x924390
#define CXWnd__Right_x                                             0x924BA0
#define CXWnd__SetFocus_x                                          0x924730
#define CXWnd__SetFont_x                                           0x9247A0
#define CXWnd__SetKeyTooltip_x                                     0x925310
#define CXWnd__SetMouseOver_x                                      0x922180
#define CXWnd__StartFade_x                                         0x923B80
#define CXWnd__GetChildItem_x                                      0x924FF0
#define CXWnd__SetParent_x                                         0x923A30
#define CXWnd__Minimize_x                                          0x924400

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95B5F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x927D20
#define CXWndManager__DrawWindows_x                                0x927D40
#define CXWndManager__GetKeyboardFlags_x                           0x92A440
#define CXWndManager__HandleKeyboardMsg_x                          0x92A000
#define CXWndManager__RemoveWnd_x                                  0x92A670
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92ABE0

// CDBStr
#define CDBStr__GetString_x                                        0x547FB0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFCC0
#define EQ_Character__Cur_HP_x                                     0x4D2E70
#define EQ_Character__Cur_Mana_x                                   0x4DA570
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2D30
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B36F0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3840
#define EQ_Character__GetHPRegen_x                                 0x4E0440
#define EQ_Character__GetEnduranceRegen_x                          0x4E0A40
#define EQ_Character__GetManaRegen_x                               0x4E0E80
#define EQ_Character__Max_Endurance_x                              0x65F230
#define EQ_Character__Max_HP_x                                     0x4D2CA0
#define EQ_Character__Max_Mana_x                                   0x65F030
#define EQ_Character__doCombatAbility_x                            0x661620
#define EQ_Character__UseSkill_x                                   0x4E2C80
#define EQ_Character__GetConLevel_x                                0x6578C0
#define EQ_Character__IsExpansionFlag_x                            0x5BAC90
#define EQ_Character__TotalEffect_x                                0x4C6AD0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3A80
#define EQ_Character__SpellDuration_x                              0x4C35B0
#define EQ_Character__MySpellDuration_x                            0x4B2020
#define EQ_Character__GetAdjustedSkill_x                           0x4D5BF0
#define EQ_Character__GetBaseSkill_x                               0x4D6B90
#define EQ_Character__CanUseItem_x                                 0x4DA880

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BE0B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x675580

//PcClient
#define PcClient__vftable_x                                        0xAF2198
#define PcClient__PcClient_x                                       0x655030

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA720
#define CCharacterListWnd__EnterWorld_x                            0x4BA0F0
#define CCharacterListWnd__Quit_x                                  0x4B9E40
#define CCharacterListWnd__UpdateList_x                            0x4BA2E0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6394A0
#define EQ_Item__CreateItemTagString_x                             0x897DF0
#define EQ_Item__IsStackable_x                                     0x89CB30
#define EQ_Item__GetImageNum_x                                     0x899970
#define EQ_Item__CreateItemClient_x                                0x6386D0
#define EQ_Item__GetItemValue_x                                    0x89AC50
#define EQ_Item__ValueSellMerchant_x                               0x89E4E0
#define EQ_Item__IsKeyRingItem_x                                   0x89C3C0
#define EQ_Item__CanGoInBag_x                                      0x6395C0
#define EQ_Item__IsEmpty_x                                         0x89BF30
#define EQ_Item__GetMaxItemCount_x                                 0x89B070
#define EQ_Item__GetHeldItem_x                                     0x899840
#define EQ_Item__GetAugmentFitBySlot_x                             0x897630

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566AA0
#define EQ_LoadingS__Array_x                                       0xC13130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65FB30
#define EQ_PC__GetAlternateAbilityId_x                             0x8A7940
#define EQ_PC__GetCombatAbility_x                                  0x8A7FB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A8020
#define EQ_PC__GetItemRecastTimer_x                                0x661BA0
#define EQ_PC__HasLoreItem_x                                       0x658130
#define EQ_PC__AlertInventoryChanged_x                             0x657200
#define EQ_PC__GetPcZoneClient_x                                   0x6845D0
#define EQ_PC__RemoveMyAffect_x                                    0x664DD0
#define EQ_PC__GetKeyRingItems_x                                   0x8A88F0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A8670
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8BF0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C10A0
#define EQItemList__add_object_x                                   0x5EE6F0
#define EQItemList__add_item_x                                     0x5C1600
#define EQItemList__delete_item_x                                  0x5C1650
#define EQItemList__FreeItemList_x                                 0x5C1550

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544A40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x676E80
#define EQPlayer__dEQPlayer_x                                      0x66A1D0
#define EQPlayer__DoAttack_x                                       0x67ED70
#define EQPlayer__EQPlayer_x                                       0x66A890
#define EQPlayer__SetNameSpriteState_x                             0x66EB90
#define EQPlayer__SetNameSpriteTint_x                              0x66FA70
#define PlayerBase__HasProperty_j_x                                0x98A200
#define EQPlayer__IsTargetable_x                                   0x98A6A0
#define EQPlayer__CanSee_x                                         0x98A500
#define EQPlayer__CanSee1_x                                        0x98A5D0
#define PlayerBase__GetVisibilityLineSegment_x                     0x98A2C0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x682070
#define PlayerZoneClient__GetLevel_x                               0x684610
#define PlayerZoneClient__IsValidTeleport_x                        0x5EF860
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F820

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x679C40
#define EQPlayerManager__GetSpawnByName_x                          0x679CF0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x679D80

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63CC80
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63CD00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63CD40
#define KeypressHandler__ClearCommandStateArray_x                  0x63E130
#define KeypressHandler__HandleKeyDown_x                           0x63E150
#define KeypressHandler__HandleKeyUp_x                             0x63E1F0
#define KeypressHandler__SaveKeymapping_x                          0x63E640

// MapViewMap 
#define MapViewMap__Clear_x                                        0x775BD0
#define MapViewMap__SaveEx_x                                       0x778F90
#define MapViewMap__SetZoom_x                                      0x77D650

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BC120

// StringTable 
#define StringTable__getString_x                                   0x8B6ED0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x664A40
#define PcZoneClient__RemovePetEffect_x                            0x665070
#define PcZoneClient__HasAlternateAbility_x                        0x65EE60
#define PcZoneClient__GetCurrentMod_x                              0x4E5DA0
#define PcZoneClient__GetModCap_x                                  0x4E5CA0
#define PcZoneClient__CanEquipItem_x                               0x65F510
#define PcZoneClient__GetItemByID_x                                0x662010
#define PcZoneClient__GetItemByItemClass_x                         0x662160
#define PcZoneClient__RemoveBuffEffect_x                           0x665090
#define PcZoneClient__BandolierSwap_x                              0x6600F0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x661B40

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F4430

//IconCache
#define IconCache__GetIcon_x                                       0x7177F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70F2E0
#define CContainerMgr__CloseContainer_x                            0x70F5B0
#define CContainerMgr__OpenExperimentContainer_x                   0x710030

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CE300

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631690

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76C120
#define CLootWnd__RequestLootSlot_x                                0x76B400

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E3B0
#define EQ_Spell__SpellAffects_x                                   0x58E820
#define EQ_Spell__SpellAffectBase_x                                0x58E5E0
#define EQ_Spell__IsStackable_x                                    0x4CA8B0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA6D0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B79D0
#define EQ_Spell__IsSPAStacking_x                                  0x58F670
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58EB80
#define EQ_Spell__IsNoRemove_x                                     0x4CA890
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58F680
#define __IsResEffectSpell_x                                       0x4C9B20

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD2B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C6740

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8150A0
#define CTargetWnd__WndNotification_x                              0x8148E0
#define CTargetWnd__RefreshTargetBuffs_x                           0x814BB0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813A50

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x819710
#define CTaskWnd__ConfirmAbandonTask_x                             0x81C350

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x542480
#define CTaskManager__HandleMessage_x                              0x540900
#define CTaskManager__GetTaskStatus_x                              0x542530
#define CTaskManager__GetElementDescription_x                      0x5425B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5894F0
#define EqSoundManager__PlayScriptMp3_x                            0x5897B0
#define EqSoundManager__SoundAssistPlay_x                          0x69C880
#define EqSoundManager__WaveInstancePlay_x                         0x69BDF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x533790

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x946060
#define CTextureAnimation__Draw_x                                  0x946260

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x941FB0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E690
#define CAltAbilityData__GetMercMaxRank_x                          0x56E620
#define CAltAbilityData__GetMaxRank_x                              0x5639C0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62F7C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA6B0
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A3A0
#define CharacterBase__CreateItemIndex_x                           0x637880
#define CharacterBase__GetItemPossession_x                         0x505F00
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CED90
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CEDF0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F6290
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6AC0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6B70

//messages
#define msg_spell_worn_off_x                                       0x5B2CB0
#define msg_new_text_x                                             0x5A7630
#define __msgTokenTextParam_x                                      0x5B4F50
#define msgTokenText_x                                             0x5B51A0

//SpellManager
#define SpellManager__vftable_x                                    0xADA554
#define SpellManager__SpellManager_x                               0x69FBB0
#define Spellmanager__LoadTextSpells_x                             0x6A04A0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69FD80

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98E0C0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51A9F0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B91B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6507D0
#define ItemGlobalIndex__IsValidIndex_x                            0x51AA80

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C70E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7270

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7649E0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7139C0
#define CCursorAttachment__AttachToCursor1_x                       0x713A00
#define CCursorAttachment__Deactivate_x                            0x7149F0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x938D50
#define CSidlManagerBase__CreatePageWnd_x                          0x938550
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9347E0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x934770

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x955D40
#define CEQSuiteTextureLoader__GetTexture_x                        0x955A00

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x517950
#define CFindItemWnd__WndNotification_x                            0x518430
#define CFindItemWnd__Update_x                                     0x518FA0
#define CFindItemWnd__PickupSelectedItem_x                         0x517180

//IString
#define IString__Append_x                                          0x5077E0

//Camera
#define CDisplay__cameraType_x                                     0xDEACC4
#define EverQuest__Cameras_x                                       0xEA60A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x520330
#define LootFiltersManager__GetItemFilterData_x                    0x51FC40
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51FC70
#define LootFiltersManager__SetItemLootFilter_x                    0x51FE90

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BC120

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x993CE0
#define CResolutionHandler__GetWindowedStyle_x                     0x697410

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70BF00

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DC730
#define CDistillerInfo__Instance_x                                 0x8DC6D0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72ACF0
#define CGroupWnd__UpdateDisplay_x                                 0x72A050

//ItemBase
#define ItemBase__IsLore_x                                         0x89C470
#define ItemBase__IsLoreEquipped_x                                 0x89C4F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EE650
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EE790
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EE7F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68CD10
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6906B0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50DFD0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9F50
#define FactionManagerClient__HandleFactionMessage_x               0x4FA5C0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAB80
#define FactionManagerClient__GetMaxFaction_x                      0x4FAB9F
#define FactionManagerClient__GetMinFaction_x                      0x4FAB50

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505ED0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91D420

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C130

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5061F0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56DB20

//CTargetManager
#define CTargetManager__Get_x                                      0x6A3410

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68CD10

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8EB0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C14F0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF43734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BFB60
#define CAAWnd__UpdateSelected_x                                   0x6BC3D0
#define CAAWnd__Update_x                                           0x6BEE80

//CXRect
#define CXRect__operator_and_x                                     0x721DF0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483170

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
