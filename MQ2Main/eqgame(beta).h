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
#define __ExpectedVersionDate                                     "Nov 23 2020"
#define __ExpectedVersionTime                                     "04:19:15"
#define __ActualVersionDate_x                                      0xAF5530
#define __ActualVersionTime_x                                      0xAF5524
#define __ActualVersionBuild_x                                     0xAE354C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x643A20
#define __MemChecker1_x                                            0x8F6C50
#define __MemChecker2_x                                            0x6B3E30
#define __MemChecker3_x                                            0x6B3D80
#define __MemChecker4_x                                            0x84CF30
#define __EncryptPad0_x                                            0xC2B9C8
#define __EncryptPad1_x                                            0xC89210
#define __EncryptPad2_x                                            0xC3BD90
#define __EncryptPad3_x                                            0xC3B990
#define __EncryptPad4_x                                            0xC797A0
#define __EncryptPad5_x                                            0xF4C0F0
#define __AC1_x                                                    0x80B816
#define __AC2_x                                                    0x5FD1DF
#define __AC3_x                                                    0x604830
#define __AC4_x                                                    0x6087E0
#define __AC5_x                                                    0x60EADF
#define __AC6_x                                                    0x612F96
#define __AC7_x                                                    0x5FCC50
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
#define __do_loot_x                                                0x5C8C50
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
#define __gfMaxZoomCameraDistance_x                                0xAED148
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
#define pinstMercenaryData_x                                       0xF45D0C
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
#define pinstCAchievementsWnd_x                                    0xDEB458
#define pinstCActionsWnd_x                                         0xDEAF80
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDEB518
#define pinstCAdvancedLootWnd_x                                    0xDEB4CC
#define pinstCAdventureLeaderboardWnd_x                            0xF55920
#define pinstCAdventureRequestWnd_x                                0xF559D0
#define pinstCAdventureStatsWnd_x                                  0xF55A80
#define pinstCAggroMeterWnd_x                                      0xDEB500
#define pinstCAlarmWnd_x                                           0xDEB484
#define pinstCAlertHistoryWnd_x                                    0xDEAEF8
#define pinstCAlertStackWnd_x                                      0xDEB4E8
#define pinstCAlertWnd_x                                           0xDEB4FC
#define pinstCAltStorageWnd_x                                      0xF55DE0
#define pinstCAudioTriggersWindow_x                                0xC9F778
#define pinstCAuraWnd_x                                            0xDEB4D0
#define pinstCAvaZoneWnd_x                                         0xDEAEF4
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
#define pinstCColorPickerWnd_x                                     0xDEAF10
#define pinstCCombatAbilityWnd_x                                   0xDEB478
#define pinstCCombatSkillsSelectWnd_x                              0xDEB42C
#define pinstCCompassWnd_x                                         0xDEAF94
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
#define pinstCGroupSearchFiltersWnd_x                              0xDEB51C
#define pinstCGroupSearchWnd_x                                     0xF58CF8
#define pinstCGroupWnd_x                                           0xF58DA8
#define pinstCGuildBankWnd_x                                       0xF58E58
#define pinstCGuildCreationWnd_x                                   0xF58F08
#define pinstCGuildMgmtWnd_x                                       0xF58FB8
#define pinstCharacterCreation_x                                   0xDEB438
#define pinstCHelpWnd_x                                            0xDEB488
#define pinstCHeritageSelectionWnd_x                               0xDEB43C
#define pinstCHotButtonWnd_x                                       0xF5B110
#define pinstCHotButtonWnd1_x                                      0xF5B110
#define pinstCHotButtonWnd2_x                                      0xF5B114
#define pinstCHotButtonWnd3_x                                      0xF5B118
#define pinstCHotButtonWnd4_x                                      0xF5B11C
#define pinstCIconSelectionWnd_x                                   0xDEB524
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
#define pinstCMapToolbarWnd_x                                      0xDEB494
#define pinstCMapViewWnd_x                                         0xDEB45C
#define pinstCMarketplaceWnd_x                                     0xDEB4F0
#define pinstCMerchantWnd_x                                        0xDEAF34
#define pinstCMIZoneSelectWnd_x                                    0xF5C408
#define pinstCMusicPlayerWnd_x                                     0xDEACD4
#define pinstCNameChangeMercWnd_x                                  0xDEB490
#define pinstCNameChangePetWnd_x                                   0xDEB460
#define pinstCNameChangeWnd_x                                      0xDEB4B8
#define pinstCNoteWnd_x                                            0xDEB46C
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
#define pinstCRealEstateManageWnd_x                                0xDEACD0
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
#define pinstCSpellBookWnd_x                                       0xDEB470
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
#define pinstCTrainWnd_x                                           0xDEAF1C
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
#define __CastRay_x                                                0x5C4340
#define __CastRay2_x                                               0x5C4390
#define __ConvertItemTags_x                                        0x5E0050
#define __CleanItemTags_x                                          0x47D0B0
#define __DoesFileExist_x                                          0x8F9C80
#define __EQGetTime_x                                              0x8F6880
#define __ExecuteCmd_x                                             0x5BCCD0
#define __FixHeading_x                                             0x98B6B0
#define __FlushDxKeyboard_x                                        0x6AFCD0
#define __GameLoop_x                                               0x6B3000
#define __get_bearing_x                                            0x5C3EA0
#define __get_melee_range_x                                        0x5C4580
#define __GetAnimationCache_x                                      0x718360
#define __GetGaugeValueFromEQ_x                                    0x809CC0
#define __GetLabelFromEQ_x                                         0x80B7A0
#define __GetXTargetType_x                                         0x98D100
#define __HandleMouseWheel_x                                       0x6B3EE0
#define __HeadingDiff_x                                            0x98B720
#define __HelpPath_x                                               0xF43E04
#define __LoadFrontEnd_x                                           0x6B0310
#define __NewUIINI_x                                               0x809990
#define __ProcessGameEvents_x                                      0x624E60
#define __ProcessMouseEvent_x                                      0x6245F0
#define __SaveColors_x                                             0x55D8E0
#define __STMLToText_x                                             0x92E9E0
#define __ToggleKeyRingItem_x                                      0x51C070
#define CMemoryMappedFile__SetFile_x                               0xA7AAF0
#define CrashDetected_x                                            0x6B1DC0
#define DrawNetStatus_x                                            0x650ED0
#define Expansion_HoT_x                                            0xEA5D48
#define Teleport_Table_Size_x                                      0xE9D7E0
#define Teleport_Table_x                                           0xE9DCB0
#define Util__FastTime_x                                           0x8F6450
#define __CopyLayout_x                                             0x63F0C0
#define __WndProc_x                                                0x6B22C0
#define __ProcessKeyboardEvent_x                                   0x6B1860

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490350
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499350
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499120
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4938F0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5659D0
#define AltAdvManager__IsAbilityReady_x                            0x564770
#define AltAdvManager__GetAAById_x                                 0x564B00
#define AltAdvManager__CanTrainAbility_x                           0x564B70
#define AltAdvManager__CanSeeAbility_x                             0x564ED0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAF20
#define CharacterZoneClient__HasSkill_x                            0x4D5DA0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D74C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C25F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBA80
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9E60
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9F40
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA020
#define CharacterZoneClient__FindAffectSlot_x                      0x4C46E0
#define CharacterZoneClient__BardCastBard_x                        0x4C7110
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF490
#define CharacterZoneClient__GetEffect_x                           0x4BB9C0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5750
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5820
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5870
#define CharacterZoneClient__CalcAffectChange_x                    0x4C59C0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5BA0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3A10
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8420
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7EA0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D9BF0
#define CBankWnd__WndNotification_x                                0x6D99C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E72D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92C1D0
#define CButtonWnd__CButtonWnd_x                                   0x92ADC0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x707580
#define CChatManager__InitContextMenu_x                            0x7006B0
#define CChatManager__FreeChatWindow_x                             0x7060C0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9790
#define CChatManager__SetLockedActiveChatWindow_x                  0x707200
#define CChatManager__CreateChatWindow_x                           0x706700

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E98A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93F350
#define CContextMenu__dCContextMenu_x                              0x93F580
#define CContextMenu__AddMenuItem_x                                0x93F590
#define CContextMenu__RemoveMenuItem_x                             0x93F890
#define CContextMenu__RemoveAllMenuItems_x                         0x93F8B0
#define CContextMenu__CheckMenuItem_x                              0x93F930
#define CContextMenu__SetMenuItem_x                                0x93F7C0
#define CContextMenu__AddSeparator_x                               0x93F720

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93FED0
#define CContextMenuManager__RemoveMenu_x                          0x93FF40
#define CContextMenuManager__PopupMenu_x                           0x940000
#define CContextMenuManager__Flush_x                               0x93FE70
#define CContextMenuManager__GetMenu_x                             0x49B570
#define CContextMenuManager__CreateDefaultMenu_x                   0x712CB0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D15B0
#define CChatService__GetFriendName_x                              0x8D15C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x707DB0
#define CChatWindow__Clear_x                                       0x709070
#define CChatWindow__WndNotification_x                             0x709800
#define CChatWindow__AddHistory_x                                  0x708930

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93C7B0
#define CComboWnd__Draw_x                                          0x93BCB0
#define CComboWnd__GetCurChoice_x                                  0x93C5F0
#define CComboWnd__GetListRect_x                                   0x93C160
#define CComboWnd__GetTextRect_x                                   0x93C810
#define CComboWnd__InsertChoice_x                                  0x93C2F0
#define CComboWnd__SetColors_x                                     0x93C2C0
#define CComboWnd__SetChoice_x                                     0x93C5C0
#define CComboWnd__GetItemCount_x                                  0x93C600
#define CComboWnd__GetCurChoiceText_x                              0x93C640
#define CComboWnd__GetChoiceText_x                                 0x93C610
#define CComboWnd__InsertChoiceAtIndex_x                           0x93C380

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7106C0
#define CContainerWnd__vftable_x                                   0xAFE73C
#define CContainerWnd__SetContainer_x                              0x711C10

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558240
#define CDisplay__PreZoneMainUI_x                                  0x558250
#define CDisplay__CleanGameUI_x                                    0x55D6A0
#define CDisplay__GetClickedActor_x                                0x5506A0
#define CDisplay__GetUserDefinedColor_x                            0x548D10
#define CDisplay__GetWorldFilePath_x                               0x552110
#define CDisplay__is3dON_x                                         0x54D300
#define CDisplay__ReloadUI_x                                       0x557750
#define CDisplay__WriteTextHD2_x                                   0x54D0F0
#define CDisplay__TrueDistance_x                                   0x553DD0
#define CDisplay__SetViewActor_x                                   0x54FFC0
#define CDisplay__GetFloorHeight_x                                 0x54D3C0
#define CDisplay__SetRenderWindow_x                                0x54BD40
#define CDisplay__ToggleScreenshotMode_x                           0x54FA90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95F1B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x942830
#define CEditWnd__EnsureCaretVisible_x                             0x9449F0
#define CEditWnd__GetCaretPt_x                                     0x9439A0
#define CEditWnd__GetCharIndexPt_x                                 0x943750
#define CEditWnd__GetDisplayString_x                               0x9435F0
#define CEditWnd__GetHorzOffset_x                                  0x941EE0
#define CEditWnd__GetLineForPrintableChar_x                        0x9448F0
#define CEditWnd__GetSelStartPt_x                                  0x943A00
#define CEditWnd__GetSTMLSafeText_x                                0x943410
#define CEditWnd__PointFromPrintableChar_x                         0x944520
#define CEditWnd__SelectableCharFromPoint_x                        0x944690
#define CEditWnd__SetEditable_x                                    0x943AD0
#define CEditWnd__SetWindowTextA_x                                 0x943190
#define CEditWnd__ReplaceSelection_x                               0x944190
#define CEditWnd__ReplaceSelection1_x                              0x944110

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x612470
#define CEverQuest__ClickedPlayer_x                                0x604610
#define CEverQuest__CreateTargetIndicator_x                        0x621FD0
#define CEverQuest__DeleteTargetIndicator_x                        0x622060
#define CEverQuest__DoTellWindow_x                                 0x4E9980
#define CEverQuest__OutputTextToLog_x                              0x4E9C50
#define CEverQuest__DropHeldItemOnGround_x                         0x5F9770
#define CEverQuest__dsp_chat_x                                     0x4E9FE0
#define CEverQuest__trimName_x                                     0x61E190
#define CEverQuest__Emote_x                                        0x612CD0
#define CEverQuest__EnterZone_x                                    0x60CDD0
#define CEverQuest__GetBodyTypeDesc_x                              0x617720
#define CEverQuest__GetClassDesc_x                                 0x617D60
#define CEverQuest__GetClassThreeLetterCode_x                      0x618360
#define CEverQuest__GetDeityDesc_x                                 0x620820
#define CEverQuest__GetLangDesc_x                                  0x618520
#define CEverQuest__GetRaceDesc_x                                  0x617D40
#define CEverQuest__InterpretCmd_x                                 0x620DF0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FD900
#define CEverQuest__LMouseUp_x                                     0x5FBC90
#define CEverQuest__RightClickedOnPlayer_x                         0x5FE1E0
#define CEverQuest__RMouseUp_x                                     0x5FCC10
#define CEverQuest__SetGameState_x                                 0x5F9500
#define CEverQuest__UPCNotificationFlush_x                         0x61E090
#define CEverQuest__IssuePetCommand_x                              0x619930
#define CEverQuest__ReportSuccessfulHit_x                          0x614020

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7222A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x722300
#define CGaugeWnd__Draw_x                                          0x721930

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFCD0
#define CGuild__GetGuildName_x                                     0x4AE780
#define CGuild__GetGuildIndex_x                                    0x4AED80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73BF10

//CHotButton
#define CHotButton__SetCheck_x                                     0x633670
#define CHotButton__SetButtonSize_x                                0x633A30

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x749180
#define CInvSlotMgr__MoveItem_x                                    0x747E50
#define CInvSlotMgr__SelectSlot_x                                  0x749250

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x746640
#define CInvSlot__SliderComplete_x                                 0x744390
#define CInvSlot__GetItemBase_x                                    0x743D10
#define CInvSlot__UpdateItem_x                                     0x743E80

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74ACE0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x749E70
#define CInvSlotWnd__HandleLButtonUp_x                             0x74A860

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x805060
#define CItemDisplayWnd__UpdateStrings_x                           0x7593A0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x753010
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x753540
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7599A0
#define CItemDisplayWnd__AboutToShow_x                             0x758FF0
#define CItemDisplayWnd__WndNotification_x                         0x75AC10
#define CItemDisplayWnd__RequestConvertItem_x                      0x75A550
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x758050
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x758E10

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x835B30

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75F130

// CLabel 
#define CLabel__Draw_x                                             0x764BC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x915260
#define CListWnd__dCListWnd_x                                      0x915570
#define CListWnd__AddColumn_x                                      0x9199C0
#define CListWnd__AddColumn1_x                                     0x919A10
#define CListWnd__AddLine_x                                        0x919DA0
#define CListWnd__AddString_x                                      0x919BA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x919780
#define CListWnd__CalculateVSBRange_x                              0x919560
#define CListWnd__ClearSel_x                                       0x91A580
#define CListWnd__ClearAllSel_x                                    0x91A5E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91AFD0
#define CListWnd__Compare_x                                        0x918EA0
#define CListWnd__Draw_x                                           0x9156A0
#define CListWnd__DrawColumnSeparators_x                           0x917E70
#define CListWnd__DrawHeader_x                                     0x9182E0
#define CListWnd__DrawItem_x                                       0x9187E0
#define CListWnd__DrawLine_x                                       0x917FE0
#define CListWnd__DrawSeparator_x                                  0x917F10
#define CListWnd__EnableLine_x                                     0x917760
#define CListWnd__EnsureVisible_x                                  0x91AF00
#define CListWnd__ExtendSel_x                                      0x91A4B0
#define CListWnd__GetColumnTooltip_x                               0x9172A0
#define CListWnd__GetColumnMinWidth_x                              0x917310
#define CListWnd__GetColumnWidth_x                                 0x917210
#define CListWnd__GetCurSel_x                                      0x916BA0
#define CListWnd__GetItemAtPoint_x                                 0x9179D0
#define CListWnd__GetItemAtPoint1_x                                0x917A40
#define CListWnd__GetItemData_x                                    0x916C20
#define CListWnd__GetItemHeight_x                                  0x916FE0
#define CListWnd__GetItemIcon_x                                    0x916DB0
#define CListWnd__GetItemRect_x                                    0x917850
#define CListWnd__GetItemText_x                                    0x916C60
#define CListWnd__GetSelList_x                                     0x91A630
#define CListWnd__GetSeparatorRect_x                               0x917C80
#define CListWnd__InsertLine_x                                     0x91A190
#define CListWnd__RemoveLine_x                                     0x91A2E0
#define CListWnd__SetColors_x                                      0x919540
#define CListWnd__SetColumnJustification_x                         0x919270
#define CListWnd__SetColumnLabel_x                                 0x919B40
#define CListWnd__SetColumnWidth_x                                 0x919190
#define CListWnd__SetCurSel_x                                      0x91A3F0
#define CListWnd__SetItemColor_x                                   0x91ABC0
#define CListWnd__SetItemData_x                                    0x91AB80
#define CListWnd__SetItemText_x                                    0x91A7A0
#define CListWnd__ShiftColumnSeparator_x                           0x919330
#define CListWnd__Sort_x                                           0x919020
#define CListWnd__ToggleSel_x                                      0x91A420
#define CListWnd__SetColumnsSizable_x                              0x9193E0
#define CListWnd__SetItemWnd_x                                     0x91AA50
#define CListWnd__GetItemWnd_x                                     0x916E00
#define CListWnd__SetItemIcon_x                                    0x91A820
#define CListWnd__CalculateCustomWindowPositions_x                 0x919880
#define CListWnd__SetVScrollPos_x                                  0x919170

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77A3D0
#define CMapViewWnd__GetWorldCoordinates_x                         0x778AE0
#define CMapViewWnd__HandleLButtonDown_x                           0x775B20

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79A830
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79B110
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79B640
#define CMerchantWnd__SelectRecoverySlot_x                         0x79E5F0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7993B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A41B0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79A450

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89EE30
#define CPacketScrambler__hton_x                                   0x89EE20

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x933FC0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9343D0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9341C0
#define CSidlManager__CreateLabel_x                                0x7FC340
#define CSidlManager__CreateXWndFromTemplate_x                     0x937330
#define CSidlManager__CreateXWndFromTemplate1_x                    0x937510
#define CSidlManager__CreateXWnd_x                                 0x7FC270
#define CSidlManager__CreateHotButtonWnd_x                         0x7FC830

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x930AA0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9309A0
#define CSidlScreenWnd__ConvertToRes_x                             0x959CA0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930490
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x930180
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x930250
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x930320
#define CSidlScreenWnd__DrawSidlPiece_x                            0x930F40
#define CSidlScreenWnd__EnableIniStorage_x                         0x931410
#define CSidlScreenWnd__GetSidlPiece_x                             0x931130
#define CSidlScreenWnd__Init1_x                                    0x92FD80
#define CSidlScreenWnd__LoadIniInfo_x                              0x931460
#define CSidlScreenWnd__LoadIniListWnd_x                           0x931FA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92F190
#define CSidlScreenWnd__StoreIniInfo_x                             0x931B10
#define CSidlScreenWnd__StoreIniVis_x                              0x931E80
#define CSidlScreenWnd__WndNotification_x                          0x930E50
#define CSidlScreenWnd__GetChildItem_x                             0x931390
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920E00
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DA190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x699020
#define CSkillMgr__GetSkillCap_x                                   0x699200
#define CSkillMgr__GetNameToken_x                                  0x6987A0
#define CSkillMgr__IsActivatedSkill_x                              0x6988E0
#define CSkillMgr__IsCombatSkill_x                                 0x698820

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x940CC0
#define CSliderWnd__SetValue_x                                     0x940B30
#define CSliderWnd__SetNumTicks_x                                  0x940B90

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8023F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9495E0
#define CStmlWnd__ParseSTML_x                                      0x94A8F0
#define CStmlWnd__CalculateHSBRange_x                              0x94A6C0
#define CStmlWnd__CalculateVSBRange_x                              0x94A630
#define CStmlWnd__CanBreakAtCharacter_x                            0x94EA10
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94F6A0
#define CStmlWnd__ForceParseNow_x                                  0x949B80
#define CStmlWnd__GetNextTagPiece_x                                0x94E970
#define CStmlWnd__GetSTMLText_x                                    0x50D690
#define CStmlWnd__GetVisibleText_x                                 0x949BA0
#define CStmlWnd__InitializeWindowVariables_x                      0x94F4F0
#define CStmlWnd__MakeStmlColorTag_x                               0x948C50
#define CStmlWnd__MakeWndNotificationTag_x                         0x948CC0
#define CStmlWnd__SetSTMLText_x                                    0x947D00
#define CStmlWnd__StripFirstSTMLLines_x                            0x9507A0
#define CStmlWnd__UpdateHistoryString_x                            0x94F8B0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946E50
#define CTabWnd__DrawCurrentPage_x                                 0x947580
#define CTabWnd__DrawTab_x                                         0x9472A0
#define CTabWnd__GetCurrentPage_x                                  0x946650
#define CTabWnd__GetPageInnerRect_x                                0x946890
#define CTabWnd__GetTabInnerRect_x                                 0x9467D0
#define CTabWnd__GetTabRect_x                                      0x946680
#define CTabWnd__InsertPage_x                                      0x946AA0
#define CTabWnd__RemovePage_x                                      0x946C10
#define CTabWnd__SetPage_x                                         0x946910
#define CTabWnd__SetPageRect_x                                     0x946D90
#define CTabWnd__UpdatePage_x                                      0x947160
#define CTabWnd__GetPageFromTabIndex_x                             0x9471E0
#define CTabWnd__GetCurrentTabIndex_x                              0x946640

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75F540
#define CPageWnd__SetTabText_x                                     0x9461A0
#define CPageWnd__FlashTab_x                                       0x946200

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9020

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91DCD0
#define CTextureFont__GetTextExtent_x                              0x91DE90

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AD180
#define CHtmlComponentWnd__ValidateUri_x                           0x73D900
#define CHtmlWnd__SetClientCallbacks_x                             0x638AA0
#define CHtmlWnd__AddObserver_x                                    0x638AC0
#define CHtmlWnd__RemoveObserver_x                                 0x638B20
#define Window__getProgress_x                                      0x8544F0
#define Window__getStatus_x                                        0x854510
#define Window__getURI_x                                           0x854520

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x956AB0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90ADA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9680
#define CXStr__CXStr1_x                                            0x4B7280
#define CXStr__CXStr3_x                                            0x8F2840
#define CXStr__dCXStr_x                                            0x4783A0
#define CXStr__operator_equal_x                                    0x8F2A70
#define CXStr__operator_equal1_x                                   0x8F2AB0
#define CXStr__operator_plus_equal1_x                              0x8F3540
#define CXStr__SetString_x                                         0x8F5430
#define CXStr__operator_char_p_x                                   0x8F2F80
#define CXStr__GetChar_x                                           0x8F4D80
#define CXStr__Delete_x                                            0x8F4630
#define CXStr__GetUnicode_x                                        0x8F4DF0
#define CXStr__GetLength_x                                         0x4A8DD0
#define CXStr__Mid_x                                               0x47D460
#define CXStr__Insert_x                                            0x8F4E50
#define CXStr__FindNext_x                                          0x8F4AA0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93EF60
#define CXWnd__BringToTop_x                                        0x924480
#define CXWnd__Center_x                                            0x924000
#define CXWnd__ClrFocus_x                                          0x923E20
#define CXWnd__Destroy_x                                           0x923EC0
#define CXWnd__DoAllDrawing_x                                      0x9205B0
#define CXWnd__DrawChildren_x                                      0x920580
#define CXWnd__DrawColoredRect_x                                   0x920A10
#define CXWnd__DrawTooltip_x                                       0x91F0D0
#define CXWnd__DrawTooltipAtPoint_x                                0x91F190
#define CXWnd__GetBorderFrame_x                                    0x920870
#define CXWnd__GetChildWndAt_x                                     0x924520
#define CXWnd__GetClientClipRect_x                                 0x9227D0
#define CXWnd__GetScreenClipRect_x                                 0x9228A0
#define CXWnd__GetScreenRect_x                                     0x922A40
#define CXWnd__GetRelativeRect_x                                   0x922B00
#define CXWnd__GetTooltipRect_x                                    0x920A60
#define CXWnd__GetWindowTextA_x                                    0x49CCF0
#define CXWnd__IsActive_x                                          0x921180
#define CXWnd__IsDescendantOf_x                                    0x923400
#define CXWnd__IsReallyVisible_x                                   0x923430
#define CXWnd__IsType_x                                            0x924B90
#define CXWnd__Move_x                                              0x923490
#define CXWnd__Move1_x                                             0x923540
#define CXWnd__ProcessTransition_x                                 0x923FB0
#define CXWnd__Refade_x                                            0x9237F0
#define CXWnd__Resize_x                                            0x923A70
#define CXWnd__Right_x                                             0x924240
#define CXWnd__SetFocus_x                                          0x923DE0
#define CXWnd__SetFont_x                                           0x923E50
#define CXWnd__SetKeyTooltip_x                                     0x9249B0
#define CXWnd__SetMouseOver_x                                      0x921990
#define CXWnd__StartFade_x                                         0x9232E0
#define CXWnd__GetChildItem_x                                      0x924690
#define CXWnd__SetParent_x                                         0x9231A0
#define CXWnd__Minimize_x                                          0x923AE0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95AD20

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x927350
#define CXWndManager__DrawWindows_x                                0x927370
#define CXWndManager__GetKeyboardFlags_x                           0x929A90
#define CXWndManager__HandleKeyboardMsg_x                          0x929640
#define CXWndManager__RemoveWnd_x                                  0x929CB0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92A200

// CDBStr
#define CDBStr__GetString_x                                        0x547CD0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFBF0
#define EQ_Character__Cur_HP_x                                     0x4D2DE0
#define EQ_Character__Cur_Mana_x                                   0x4DA520
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2C60
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3650
#define EQ_Character__GetFocusRangeModifier_x                      0x4B37A0
#define EQ_Character__GetHPRegen_x                                 0x4E0410
#define EQ_Character__GetEnduranceRegen_x                          0x4E0A10
#define EQ_Character__GetManaRegen_x                               0x4E0E50
#define EQ_Character__Max_Endurance_x                              0x65F770
#define EQ_Character__Max_HP_x                                     0x4D2C10
#define EQ_Character__Max_Mana_x                                   0x65F570
#define EQ_Character__doCombatAbility_x                            0x661B60
#define EQ_Character__UseSkill_x                                   0x4E2C50
#define EQ_Character__GetConLevel_x                                0x657E00
#define EQ_Character__IsExpansionFlag_x                            0x5BB470
#define EQ_Character__TotalEffect_x                                0x4C6A00
#define EQ_Character__GetPCSpellAffect_x                           0x4C39B0
#define EQ_Character__SpellDuration_x                              0x4C34E0
#define EQ_Character__MySpellDuration_x                            0x4B1F80
#define EQ_Character__GetAdjustedSkill_x                           0x4D5B60
#define EQ_Character__GetBaseSkill_x                               0x4D6B00
#define EQ_Character__CanUseItem_x                                 0x4DA830

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BE4C0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x675AA0

//PcClient
#define PcClient__vftable_x                                        0xAF219C
#define PcClient__PcClient_x                                       0x655570

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA660
#define CCharacterListWnd__EnterWorld_x                            0x4BA030
#define CCharacterListWnd__Quit_x                                  0x4B9D80
#define CCharacterListWnd__UpdateList_x                            0x4BA220

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x639C90
#define EQ_Item__CreateItemTagString_x                             0x898320
#define EQ_Item__IsStackable_x                                     0x89D050
#define EQ_Item__GetImageNum_x                                     0x899EB0
#define EQ_Item__CreateItemClient_x                                0x638EC0
#define EQ_Item__GetItemValue_x                                    0x89B1B0
#define EQ_Item__ValueSellMerchant_x                               0x89EA10
#define EQ_Item__IsKeyRingItem_x                                   0x89C900
#define EQ_Item__CanGoInBag_x                                      0x639DB0
#define EQ_Item__IsEmpty_x                                         0x89C440
#define EQ_Item__GetMaxItemCount_x                                 0x89B5C0
#define EQ_Item__GetHeldItem_x                                     0x899D80
#define EQ_Item__GetAugmentFitBySlot_x                             0x897B90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566760
#define EQ_LoadingS__Array_x                                       0xC13130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x660070
#define EQ_PC__GetAlternateAbilityId_x                             0x8A7E60
#define EQ_PC__GetCombatAbility_x                                  0x8A84D0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A8540
#define EQ_PC__GetItemRecastTimer_x                                0x6620E0
#define EQ_PC__HasLoreItem_x                                       0x658620
#define EQ_PC__AlertInventoryChanged_x                             0x657740
#define EQ_PC__GetPcZoneClient_x                                   0x684AC0
#define EQ_PC__RemoveMyAffect_x                                    0x665310
#define EQ_PC__GetKeyRingItems_x                                   0x8A8E10
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A8B90
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A9110

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C18D0
#define EQItemList__add_object_x                                   0x5EEED0
#define EQItemList__add_item_x                                     0x5C1E30
#define EQItemList__delete_item_x                                  0x5C1E80
#define EQItemList__FreeItemList_x                                 0x5C1D80

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544890

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6773A0
#define EQPlayer__dEQPlayer_x                                      0x66A720
#define EQPlayer__DoAttack_x                                       0x67F260
#define EQPlayer__EQPlayer_x                                       0x66ADE0
#define EQPlayer__SetNameSpriteState_x                             0x66F0B0
#define EQPlayer__SetNameSpriteTint_x                              0x66FF90
#define PlayerBase__HasProperty_j_x                                0x989AB0
#define EQPlayer__IsTargetable_x                                   0x989F50
#define EQPlayer__CanSee_x                                         0x989DB0
#define EQPlayer__CanSee1_x                                        0x989E80
#define PlayerBase__GetVisibilityLineSegment_x                     0x989B70

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x682560
#define PlayerZoneClient__GetLevel_x                               0x684B00
#define PlayerZoneClient__IsValidTeleport_x                        0x5F0040
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F4D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67A170
#define EQPlayerManager__GetSpawnByName_x                          0x67A220
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A2B0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63D320
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63D3A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63D3E0
#define KeypressHandler__ClearCommandStateArray_x                  0x63E7D0
#define KeypressHandler__HandleKeyDown_x                           0x63E7F0
#define KeypressHandler__HandleKeyUp_x                             0x63E890
#define KeypressHandler__SaveKeymapping_x                          0x63ECE0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x776240
#define MapViewMap__SaveEx_x                                       0x779600
#define MapViewMap__SetZoom_x                                      0x77DCC0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BC520

// StringTable 
#define StringTable__getString_x                                   0x8B7330

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x664F80
#define PcZoneClient__RemovePetEffect_x                            0x6655B0
#define PcZoneClient__HasAlternateAbility_x                        0x65F3A0
#define PcZoneClient__GetCurrentMod_x                              0x4E5D70
#define PcZoneClient__GetModCap_x                                  0x4E5C70
#define PcZoneClient__CanEquipItem_x                               0x65FA50
#define PcZoneClient__GetItemByID_x                                0x662550
#define PcZoneClient__GetItemByItemClass_x                         0x6626A0
#define PcZoneClient__RemoveBuffEffect_x                           0x6655D0
#define PcZoneClient__BandolierSwap_x                              0x660630
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x662080

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F4C20

//IconCache
#define IconCache__GetIcon_x                                       0x717D60

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70F860
#define CContainerMgr__CloseContainer_x                            0x70FB30
#define CContainerMgr__OpenExperimentContainer_x                   0x7105B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CE9F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631E60

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76C640
#define CLootWnd__RequestLootSlot_x                                0x76B920

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E0D0
#define EQ_Spell__SpellAffects_x                                   0x58E540
#define EQ_Spell__SpellAffectBase_x                                0x58E300
#define EQ_Spell__IsStackable_x                                    0x4CA830
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA620
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7940
#define EQ_Spell__IsSPAStacking_x                                  0x58F390
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58E8A0
#define EQ_Spell__IsNoRemove_x                                     0x4CA810
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58F3A0
#define __IsResEffectSpell_x                                       0x4C9A50

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD1E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C6BD0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x815740
#define CTargetWnd__WndNotification_x                              0x814F80
#define CTargetWnd__RefreshTargetBuffs_x                           0x815250
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8140E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x819DB0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81C9F0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x542270
#define CTaskManager__HandleMessage_x                              0x5406C0
#define CTaskManager__GetTaskStatus_x                              0x542320
#define CTaskManager__GetElementDescription_x                      0x5423A0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589270
#define EqSoundManager__PlayScriptMp3_x                            0x589530
#define EqSoundManager__SoundAssistPlay_x                          0x69CF60
#define EqSoundManager__WaveInstancePlay_x                         0x69C4D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x533650

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9456B0
#define CTextureAnimation__Draw_x                                  0x9458B0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x941620

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E350
#define CAltAbilityData__GetMercMaxRank_x                          0x56E2E0
#define CAltAbilityData__GetMaxRank_x                              0x5635F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62FF80

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA600
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A210
#define CharacterBase__CreateItemIndex_x                           0x638050
#define CharacterBase__GetItemPossession_x                         0x506130
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CF260
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CF2C0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F6920
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F7150
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F7200

//messages
#define msg_spell_worn_off_x                                       0x5B3340
#define msg_new_text_x                                             0x5A7CB0
#define __msgTokenTextParam_x                                      0x5B55E0
#define msgTokenText_x                                             0x5B5830

//SpellManager
#define SpellManager__vftable_x                                    0xADA544
#define SpellManager__SpellManager_x                               0x6A0290
#define Spellmanager__LoadTextSpells_x                             0x6A0B80
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A0460

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98D9F0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51A890
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B9820
#define ItemGlobalIndex__IsEquippedLocation_x                      0x650D30
#define ItemGlobalIndex__IsValidIndex_x                            0x51A920

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C7590
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7720

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764F00

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x713F60
#define CCursorAttachment__AttachToCursor1_x                       0x713FA0
#define CCursorAttachment__Deactivate_x                            0x714F90

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x938350
#define CSidlManagerBase__CreatePageWnd_x                          0x937B50
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x933DE0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933D70

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9553B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x955070

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x517640
#define CFindItemWnd__WndNotification_x                            0x518120
#define CFindItemWnd__Update_x                                     0x518C70
#define CFindItemWnd__PickupSelectedItem_x                         0x516E70

//IString
#define IString__Append_x                                          0x5079D0

//Camera
#define CDisplay__cameraType_x                                     0xDEACCC
#define EverQuest__Cameras_x                                       0xEA60A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5201B0
#define LootFiltersManager__GetItemFilterData_x                    0x51FAC0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51FAF0
#define LootFiltersManager__SetItemLootFilter_x                    0x51FD10

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BC830

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9936B0
#define CResolutionHandler__GetWindowedStyle_x                     0x697AE0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70C510

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3070
#define CDistillerInfo__Instance_x                                 0x8D3010

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72B250
#define CGroupWnd__UpdateDisplay_x                                 0x72A5B0

//ItemBase
#define ItemBase__IsLore_x                                         0x89C9B0
#define ItemBase__IsLoreEquipped_x                                 0x89CA20

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EEE30
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EEF70
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EEFD0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D1E0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x690B50

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50DD70

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9DE0
#define FactionManagerClient__HandleFactionMessage_x               0x4FA450
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAA10
#define FactionManagerClient__GetMaxFaction_x                      0x4FAA2F
#define FactionManagerClient__GetMinFaction_x                      0x4FA9E0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x506100

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91CC70

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C000

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5063F0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56D7F0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A3B20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D1E0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8DE0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1D20

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF43734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C0270
#define CAAWnd__UpdateSelected_x                                   0x6BCAE0
#define CAAWnd__Update_x                                           0x6BF590

//CXRect
#define CXRect__operator_and_x                                     0x722360

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4830A0

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
