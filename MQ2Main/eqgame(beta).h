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
#define __ExpectedVersionDate                                     "Nov 30 2020"
#define __ExpectedVersionTime                                     "04:17:51"
#define __ActualVersionDate_x                                      0xAF554C
#define __ActualVersionTime_x                                      0xAF5540
#define __ActualVersionBuild_x                                     0xAE356C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x643C60
#define __MemChecker1_x                                            0x8F6CD0
#define __MemChecker2_x                                            0x6B41A0
#define __MemChecker3_x                                            0x6B40F0
#define __MemChecker4_x                                            0x84D140
#define __EncryptPad0_x                                            0xC2B9C8
#define __EncryptPad1_x                                            0xC89210
#define __EncryptPad2_x                                            0xC3BD90
#define __EncryptPad3_x                                            0xC3B990
#define __EncryptPad4_x                                            0xC797A0
#define __EncryptPad5_x                                            0xF4C0E0
#define __AC1_x                                                    0x80BB16
#define __AC2_x                                                    0x5FD2AF
#define __AC3_x                                                    0x604900
#define __AC4_x                                                    0x6088B0
#define __AC5_x                                                    0x60EBAF
#define __AC6_x                                                    0x613066
#define __AC7_x                                                    0x5FCD20
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
#define __do_loot_x                                                0x5C8D50
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
#define __ScreenMode_x                                             0xDEB4B0
#define __ScreenX_x                                                0xEA4984
#define __ScreenY_x                                                0xEA4980
#define __ScreenXMax_x                                             0xEA4988
#define __ScreenYMax_x                                             0xEA498C
#define __ServerHost_x                                             0xE9D923
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
#define pinstActiveMerchant_x                                      0xE9DC38
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
#define pinstLocalPlayer_x                                         0xE9DC34
#define pinstMercenaryData_x                                       0xF45D08
#define pinstMercenaryStats_x                                      0xF5EBCC
#define pinstModelPlayer_x                                         0xE9DC4C
#define pinstPCData_x                                              0xE9D744
#define pinstSkillMgr_x                                            0xF47E68
#define pinstSpawnManager_x                                        0xF46910
#define pinstSpellManager_x                                        0xF480A8
#define pinstSpellSets_x                                           0xF3C358
#define pinstStringTable_x                                         0xE9D748
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
#define EQObject_Top_x                                             0xE9DA2C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEAF3C
#define pinstCAchievementsWnd_x                                    0xDEB454
#define pinstCActionsWnd_x                                         0xDEAF78
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDEB514
#define pinstCAdvancedLootWnd_x                                    0xDEB4C4
#define pinstCAdventureLeaderboardWnd_x                            0xF55920
#define pinstCAdventureRequestWnd_x                                0xF559D0
#define pinstCAdventureStatsWnd_x                                  0xF55A80
#define pinstCAggroMeterWnd_x                                      0xDEB4F8
#define pinstCAlarmWnd_x                                           0xDEB480
#define pinstCAlertHistoryWnd_x                                    0xDEAEEC
#define pinstCAlertStackWnd_x                                      0xDEB4E0
#define pinstCAlertWnd_x                                           0xDEB4F4
#define pinstCAltStorageWnd_x                                      0xF55DE0
#define pinstCAudioTriggersWindow_x                                0xC9F778
#define pinstCAuraWnd_x                                            0xDEB4C8
#define pinstCAvaZoneWnd_x                                         0xDEAEF0
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
#define pinstCColorPickerWnd_x                                     0xDEAF04
#define pinstCCombatAbilityWnd_x                                   0xDEB46C
#define pinstCCombatSkillsSelectWnd_x                              0xDEB424
#define pinstCCompassWnd_x                                         0xDEAF7C
#define pinstCConfirmationDialog_x                                 0xF5CC98
#define pinstCContainerMgr_x                                       0xDEB400
#define pinstCContextMenuManager_x                                 0x15DA2C0
#define pinstCCursorAttachment_x                                   0xDEB520
#define pinstCDynamicZoneWnd_x                                     0xF58360
#define pinstCEditLabelWnd_x                                       0xDEB4A8
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
#define pinstCGroupSearchFiltersWnd_x                              0xDEB510
#define pinstCGroupSearchWnd_x                                     0xF58CF8
#define pinstCGroupWnd_x                                           0xF58DA8
#define pinstCGuildBankWnd_x                                       0xF58E58
#define pinstCGuildCreationWnd_x                                   0xF58F08
#define pinstCGuildMgmtWnd_x                                       0xF58FB8
#define pinstCharacterCreation_x                                   0xDEB430
#define pinstCHelpWnd_x                                            0xDEB47C
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
#define pinstCMapToolbarWnd_x                                      0xDEB488
#define pinstCMapViewWnd_x                                         0xDEB450
#define pinstCMarketplaceWnd_x                                     0xDEB4E8
#define pinstCMerchantWnd_x                                        0xDEAF2C
#define pinstCMIZoneSelectWnd_x                                    0xF5C408
#define pinstCMusicPlayerWnd_x                                     0xDEACCC
#define pinstCNameChangeMercWnd_x                                  0xDEB48C
#define pinstCNameChangePetWnd_x                                   0xDEB458
#define pinstCNameChangeWnd_x                                      0xDEB4A0
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
#define pinstCRealEstateManageWnd_x                                0xDEACC4
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
#define pinstCSocialEditWnd_x                                      0xDEB52C
#define pinstCSocialWnd_x                                          0xDEB478
#define pinstCSpellBookWnd_x                                       0xDEB468
#define pinstCStoryWnd_x                                           0xDEAF74
#define pinstCTargetOfTargetWnd_x                                  0xF5EC50
#define pinstCTargetWnd_x                                          0xDEB4EC
#define pinstCTaskOverlayWnd_x                                     0xDEACB4
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
#define pinstCTrainWnd_x                                           0xDEAF10
#define pinstCTributeBenefitWnd_x                                  0xF5F520
#define pinstCTributeMasterWnd_x                                   0xF5F5D0
#define pinstCTributeTrophyWnd_x                                   0xF5F680
#define pinstCVideoModesWnd_x                                      0xDEACB8
#define pinstCVoiceMacroWnd_x                                      0xF488C8
#define pinstCVoteResultsWnd_x                                     0xDEB440
#define pinstCVoteWnd_x                                            0xDEB42C
#define pinstCWebManager_x                                         0xF48F44
#define pinstCZoneGuideWnd_x                                       0xDEACBC
#define pinstCZonePathWnd_x                                        0xDEAED0

#define pinstEQSuiteTextureLoader_x                                0xC89B30
#define pinstItemIconCache_x                                       0xF58560
#define pinstLootFiltersManager_x                                  0xCBBF98
#define pinstRewardSelectionWnd_x                                  0xF5D5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C4440
#define __CastRay2_x                                               0x5C4490
#define __ConvertItemTags_x                                        0x5E0150
#define __CleanItemTags_x                                          0x47D1F0
#define __DoesFileExist_x                                          0x8F9D50
#define __EQGetTime_x                                              0x8F6900
#define __ExecuteCmd_x                                             0x5BCDB0
#define __FixHeading_x                                             0x98B340
#define __FlushDxKeyboard_x                                        0x6B0040
#define __GameLoop_x                                               0x6B3370
#define __get_bearing_x                                            0x5C3FA0
#define __get_melee_range_x                                        0x5C4680
#define __GetAnimationCache_x                                      0x7187F0
#define __GetGaugeValueFromEQ_x                                    0x809FC0
#define __GetLabelFromEQ_x                                         0x80BAA0
#define __GetXTargetType_x                                         0x98CD20
#define __HandleMouseWheel_x                                       0x6B4250
#define __HeadingDiff_x                                            0x98B3B0
#define __HelpPath_x                                               0xF43E04
#define __LoadFrontEnd_x                                           0x6B0680
#define __NewUIINI_x                                               0x809C90
#define __ProcessGameEvents_x                                      0x624F40
#define __ProcessMouseEvent_x                                      0x6246D0
#define __SaveColors_x                                             0x55DA30
#define __STMLToText_x                                             0x92E5C0
#define __ToggleKeyRingItem_x                                      0x51C340
#define CMemoryMappedFile__SetFile_x                               0xA7A5D0
#define CrashDetected_x                                            0x6B2130
#define DrawNetStatus_x                                            0x651000
#define Expansion_HoT_x                                            0xEA5D48
#define Teleport_Table_Size_x                                      0xE9D7E0
#define Teleport_Table_x                                           0xE9DCB0
#define Util__FastTime_x                                           0x8F64D0
#define __CopyLayout_x                                             0x63F3D0
#define __WndProc_x                                                0x6B2630
#define __ProcessKeyboardEvent_x                                   0x6B1BD0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490490
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499490
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499260
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A30
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565B50
#define AltAdvManager__IsAbilityReady_x                            0x5648F0
#define AltAdvManager__GetAAById_x                                 0x564C80
#define AltAdvManager__CanTrainAbility_x                           0x564CF0
#define AltAdvManager__CanSeeAbility_x                             0x565050

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB070
#define CharacterZoneClient__HasSkill_x                            0x4D5EF0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7620
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2870
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBD00
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9FC0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA0A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA180
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4960
#define CharacterZoneClient__BardCastBard_x                        0x4C7390
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF710
#define CharacterZoneClient__GetEffect_x                           0x4BBC40
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C59D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5AA0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5AF0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5C40
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5E20
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3CB0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8580
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8000

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D9E40
#define CBankWnd__WndNotification_x                                0x6D9C10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E7770

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92BDC0
#define CButtonWnd__CButtonWnd_x                                   0x92A990

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x707910
#define CChatManager__InitContextMenu_x                            0x700A40
#define CChatManager__FreeChatWindow_x                             0x706450
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9B00
#define CChatManager__SetLockedActiveChatWindow_x                  0x707590
#define CChatManager__CreateChatWindow_x                           0x706A90

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9C10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93EFD0
#define CContextMenu__dCContextMenu_x                              0x93F210
#define CContextMenu__AddMenuItem_x                                0x93F220
#define CContextMenu__RemoveMenuItem_x                             0x93F530
#define CContextMenu__RemoveAllMenuItems_x                         0x93F550
#define CContextMenu__CheckMenuItem_x                              0x93F5D0
#define CContextMenu__SetMenuItem_x                                0x93F450
#define CContextMenu__AddSeparator_x                               0x93F3B0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93FB70
#define CContextMenuManager__RemoveMenu_x                          0x93FBE0
#define CContextMenuManager__PopupMenu_x                           0x93FCA0
#define CContextMenuManager__Flush_x                               0x93FB10
#define CContextMenuManager__GetMenu_x                             0x49B770
#define CContextMenuManager__CreateDefaultMenu_x                   0x713150

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1800
#define CChatService__GetFriendName_x                              0x8D1810

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7081C0
#define CChatWindow__Clear_x                                       0x709480
#define CChatWindow__WndNotification_x                             0x709C10
#define CChatWindow__AddHistory_x                                  0x708D40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93C430
#define CComboWnd__Draw_x                                          0x93B910
#define CComboWnd__GetCurChoice_x                                  0x93C270
#define CComboWnd__GetListRect_x                                   0x93BDD0
#define CComboWnd__GetTextRect_x                                   0x93C4A0
#define CComboWnd__InsertChoice_x                                  0x93BF60
#define CComboWnd__SetColors_x                                     0x93BF30
#define CComboWnd__SetChoice_x                                     0x93C240
#define CComboWnd__GetItemCount_x                                  0x93C280
#define CComboWnd__GetCurChoiceText_x                              0x93C2C0
#define CComboWnd__GetChoiceText_x                                 0x93C290
#define CComboWnd__InsertChoiceAtIndex_x                           0x93C000

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x710B60
#define CContainerWnd__vftable_x                                   0xAFE754
#define CContainerWnd__SetContainer_x                              0x7120C0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558390
#define CDisplay__PreZoneMainUI_x                                  0x5583A0
#define CDisplay__CleanGameUI_x                                    0x55D7F0
#define CDisplay__GetClickedActor_x                                0x5507F0
#define CDisplay__GetUserDefinedColor_x                            0x548E60
#define CDisplay__GetWorldFilePath_x                               0x552260
#define CDisplay__is3dON_x                                         0x54D450
#define CDisplay__ReloadUI_x                                       0x5578A0
#define CDisplay__WriteTextHD2_x                                   0x54D240
#define CDisplay__TrueDistance_x                                   0x553F20
#define CDisplay__SetViewActor_x                                   0x550110
#define CDisplay__GetFloorHeight_x                                 0x54D510
#define CDisplay__SetRenderWindow_x                                0x54BE90
#define CDisplay__ToggleScreenshotMode_x                           0x54FBE0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95EDF0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9424D0
#define CEditWnd__EnsureCaretVisible_x                             0x9446A0
#define CEditWnd__GetCaretPt_x                                     0x943650
#define CEditWnd__GetCharIndexPt_x                                 0x943400
#define CEditWnd__GetDisplayString_x                               0x9432A0
#define CEditWnd__GetHorzOffset_x                                  0x941B70
#define CEditWnd__GetLineForPrintableChar_x                        0x9445A0
#define CEditWnd__GetSelStartPt_x                                  0x9436B0
#define CEditWnd__GetSTMLSafeText_x                                0x9430C0
#define CEditWnd__PointFromPrintableChar_x                         0x9441D0
#define CEditWnd__SelectableCharFromPoint_x                        0x944340
#define CEditWnd__SetEditable_x                                    0x943780
#define CEditWnd__SetWindowTextA_x                                 0x942E40
#define CEditWnd__ReplaceSelection_x                               0x943E40
#define CEditWnd__ReplaceSelection1_x                              0x943DC0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x612540
#define CEverQuest__ClickedPlayer_x                                0x6046E0
#define CEverQuest__CreateTargetIndicator_x                        0x6220B0
#define CEverQuest__DeleteTargetIndicator_x                        0x622140
#define CEverQuest__DoTellWindow_x                                 0x4E9CF0
#define CEverQuest__OutputTextToLog_x                              0x4E9FC0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F9840
#define CEverQuest__dsp_chat_x                                     0x4EA350
#define CEverQuest__trimName_x                                     0x61E260
#define CEverQuest__Emote_x                                        0x612DA0
#define CEverQuest__EnterZone_x                                    0x60CEA0
#define CEverQuest__GetBodyTypeDesc_x                              0x6177F0
#define CEverQuest__GetClassDesc_x                                 0x617E30
#define CEverQuest__GetClassThreeLetterCode_x                      0x618430
#define CEverQuest__GetDeityDesc_x                                 0x620900
#define CEverQuest__GetLangDesc_x                                  0x6185F0
#define CEverQuest__GetRaceDesc_x                                  0x617E10
#define CEverQuest__InterpretCmd_x                                 0x620ED0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FD9D0
#define CEverQuest__LMouseUp_x                                     0x5FBD60
#define CEverQuest__RightClickedOnPlayer_x                         0x5FE2B0
#define CEverQuest__RMouseUp_x                                     0x5FCCE0
#define CEverQuest__SetGameState_x                                 0x5F95D0
#define CEverQuest__UPCNotificationFlush_x                         0x61E160
#define CEverQuest__IssuePetCommand_x                              0x619A00
#define CEverQuest__ReportSuccessfulHit_x                          0x6140F0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7227F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x722850
#define CGaugeWnd__Draw_x                                          0x721E80

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFF70
#define CGuild__GetGuildName_x                                     0x4AEA20
#define CGuild__GetGuildIndex_x                                    0x4AF020

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73C430

//CHotButton
#define CHotButton__SetCheck_x                                     0x6338C0
#define CHotButton__SetButtonSize_x                                0x633C80

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x749600
#define CInvSlotMgr__MoveItem_x                                    0x748320
#define CInvSlotMgr__SelectSlot_x                                  0x7496D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x746B50
#define CInvSlot__SliderComplete_x                                 0x744890
#define CInvSlot__GetItemBase_x                                    0x744230
#define CInvSlot__UpdateItem_x                                     0x7443A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74B150
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74A2F0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74ACD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x805310
#define CItemDisplayWnd__UpdateStrings_x                           0x759830
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7535C0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x753AC0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x759E40
#define CItemDisplayWnd__AboutToShow_x                             0x759490
#define CItemDisplayWnd__WndNotification_x                         0x75B090
#define CItemDisplayWnd__RequestConvertItem_x                      0x75A9E0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x758500
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7592B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x835D30

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75F5C0

// CLabel 
#define CLabel__Draw_x                                             0x765040

// CListWnd
#define CListWnd__CListWnd_x                                       0x914C90
#define CListWnd__dCListWnd_x                                      0x914FB0
#define CListWnd__AddColumn_x                                      0x919410
#define CListWnd__AddColumn1_x                                     0x919460
#define CListWnd__AddLine_x                                        0x9197F0
#define CListWnd__AddString_x                                      0x9195F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9191E0
#define CListWnd__CalculateVSBRange_x                              0x918FC0
#define CListWnd__ClearSel_x                                       0x919FD0
#define CListWnd__ClearAllSel_x                                    0x91A030
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91AA30
#define CListWnd__Compare_x                                        0x9188F0
#define CListWnd__Draw_x                                           0x9150E0
#define CListWnd__DrawColumnSeparators_x                           0x9178D0
#define CListWnd__DrawHeader_x                                     0x917D30
#define CListWnd__DrawItem_x                                       0x918230
#define CListWnd__DrawLine_x                                       0x917A30
#define CListWnd__DrawSeparator_x                                  0x917970
#define CListWnd__EnableLine_x                                     0x9171B0
#define CListWnd__EnsureVisible_x                                  0x91A960
#define CListWnd__ExtendSel_x                                      0x919F00
#define CListWnd__GetColumnTooltip_x                               0x916CF0
#define CListWnd__GetColumnMinWidth_x                              0x916D60
#define CListWnd__GetColumnWidth_x                                 0x916C60
#define CListWnd__GetCurSel_x                                      0x9165F0
#define CListWnd__GetItemAtPoint_x                                 0x917420
#define CListWnd__GetItemAtPoint1_x                                0x917490
#define CListWnd__GetItemData_x                                    0x916670
#define CListWnd__GetItemHeight_x                                  0x916A30
#define CListWnd__GetItemIcon_x                                    0x916800
#define CListWnd__GetItemRect_x                                    0x9172A0
#define CListWnd__GetItemText_x                                    0x9166B0
#define CListWnd__GetSelList_x                                     0x91A080
#define CListWnd__GetSeparatorRect_x                               0x9176D0
#define CListWnd__InsertLine_x                                     0x919BE0
#define CListWnd__RemoveLine_x                                     0x919D30
#define CListWnd__SetColors_x                                      0x918F90
#define CListWnd__SetColumnJustification_x                         0x918CC0
#define CListWnd__SetColumnLabel_x                                 0x919590
#define CListWnd__SetColumnWidth_x                                 0x918BE0
#define CListWnd__SetCurSel_x                                      0x919E40
#define CListWnd__SetItemColor_x                                   0x91A620
#define CListWnd__SetItemData_x                                    0x91A5E0
#define CListWnd__SetItemText_x                                    0x91A1F0
#define CListWnd__ShiftColumnSeparator_x                           0x918D80
#define CListWnd__Sort_x                                           0x918A70
#define CListWnd__ToggleSel_x                                      0x919E70
#define CListWnd__SetColumnsSizable_x                              0x918E30
#define CListWnd__SetItemWnd_x                                     0x91A4A0
#define CListWnd__GetItemWnd_x                                     0x916850
#define CListWnd__SetItemIcon_x                                    0x91A270
#define CListWnd__CalculateCustomWindowPositions_x                 0x9192D0
#define CListWnd__SetVScrollPos_x                                  0x918BC0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77A860
#define CMapViewWnd__GetWorldCoordinates_x                         0x778F70
#define CMapViewWnd__HandleLButtonDown_x                           0x775FB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79ABA0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79B480
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79B9B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79E950
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x799720
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4510
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79A7C0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89F2D0
#define CPacketScrambler__hton_x                                   0x89F2C0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x933BA0
#define CSidlManager__FindScreenPieceTemplate_x                    0x933FB0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x933DA0
#define CSidlManager__CreateLabel_x                                0x7FC530
#define CSidlManager__CreateXWndFromTemplate_x                     0x936F10
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9370F0
#define CSidlManager__CreateXWnd_x                                 0x7FC460
#define CSidlManager__CreateHotButtonWnd_x                         0x7FCA20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x930690
#define CSidlScreenWnd__CalculateVSBRange_x                        0x930590
#define CSidlScreenWnd__ConvertToRes_x                             0x9598E0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930080
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92FD70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92FE40
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92FF10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x930B20
#define CSidlScreenWnd__EnableIniStorage_x                         0x930FF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x930D10
#define CSidlScreenWnd__Init1_x                                    0x92F970
#define CSidlScreenWnd__LoadIniInfo_x                              0x931040
#define CSidlScreenWnd__LoadIniListWnd_x                           0x931B80
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92ED70
#define CSidlScreenWnd__StoreIniInfo_x                             0x9316F0
#define CSidlScreenWnd__StoreIniVis_x                              0x931A60
#define CSidlScreenWnd__WndNotification_x                          0x930A30
#define CSidlScreenWnd__GetChildItem_x                             0x930F70
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920780
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DA190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x699390
#define CSkillMgr__GetSkillCap_x                                   0x699570
#define CSkillMgr__GetNameToken_x                                  0x698B10
#define CSkillMgr__IsActivatedSkill_x                              0x698C50
#define CSkillMgr__IsCombatSkill_x                                 0x698B90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x940950
#define CSliderWnd__SetValue_x                                     0x9407C0
#define CSliderWnd__SetNumTicks_x                                  0x940820

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8026A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9492A0
#define CStmlWnd__ParseSTML_x                                      0x94A620
#define CStmlWnd__CalculateHSBRange_x                              0x94A400
#define CStmlWnd__CalculateVSBRange_x                              0x94A380
#define CStmlWnd__CanBreakAtCharacter_x                            0x94E730
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94F3C0
#define CStmlWnd__ForceParseNow_x                                  0x9498E0
#define CStmlWnd__GetNextTagPiece_x                                0x94E690
#define CStmlWnd__GetSTMLText_x                                    0x50D7F0
#define CStmlWnd__GetVisibleText_x                                 0x949900
#define CStmlWnd__InitializeWindowVariables_x                      0x94F210
#define CStmlWnd__MakeStmlColorTag_x                               0x948910
#define CStmlWnd__MakeWndNotificationTag_x                         0x948980
#define CStmlWnd__SetSTMLText_x                                    0x9479C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x950480
#define CStmlWnd__UpdateHistoryString_x                            0x94F5D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946B00
#define CTabWnd__DrawCurrentPage_x                                 0x947230
#define CTabWnd__DrawTab_x                                         0x946F50
#define CTabWnd__GetCurrentPage_x                                  0x946300
#define CTabWnd__GetPageInnerRect_x                                0x946540
#define CTabWnd__GetTabInnerRect_x                                 0x946480
#define CTabWnd__GetTabRect_x                                      0x946330
#define CTabWnd__InsertPage_x                                      0x946750
#define CTabWnd__RemovePage_x                                      0x9468C0
#define CTabWnd__SetPage_x                                         0x9465C0
#define CTabWnd__SetPageRect_x                                     0x946A40
#define CTabWnd__UpdatePage_x                                      0x946E10
#define CTabWnd__GetPageFromTabIndex_x                             0x946E90
#define CTabWnd__GetCurrentTabIndex_x                              0x9462F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75F9D0
#define CPageWnd__SetTabText_x                                     0x945E40
#define CPageWnd__FlashTab_x                                       0x945EA0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9220

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91D640
#define CTextureFont__GetTextExtent_x                              0x91D800

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AD4F0
#define CHtmlComponentWnd__ValidateUri_x                           0x73DE20
#define CHtmlWnd__SetClientCallbacks_x                             0x638D00
#define CHtmlWnd__AddObserver_x                                    0x638D20
#define CHtmlWnd__RemoveObserver_x                                 0x638D80
#define Window__getProgress_x                                      0x8546E0
#define Window__getStatus_x                                        0x854700
#define Window__getURI_x                                           0x854710

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9566F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90A800

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9840
#define CXStr__CXStr1_x                                            0x9E1AF0
#define CXStr__CXStr3_x                                            0x8F28C0
#define CXStr__dCXStr_x                                            0x478400
#define CXStr__operator_equal_x                                    0x8F2AF0
#define CXStr__operator_equal1_x                                   0x8F2B30
#define CXStr__operator_plus_equal1_x                              0x8F35C0
#define CXStr__SetString_x                                         0x8F54B0
#define CXStr__operator_char_p_x                                   0x8F3000
#define CXStr__GetChar_x                                           0x8F4E00
#define CXStr__Delete_x                                            0x8F46B0
#define CXStr__GetUnicode_x                                        0x8F4E70
#define CXStr__GetLength_x                                         0x4A8FD0
#define CXStr__Mid_x                                               0x47D5A0
#define CXStr__Insert_x                                            0x8F4ED0
#define CXStr__FindNext_x                                          0x8F4B20

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93EBF0
#define CXWnd__BringToTop_x                                        0x923F50
#define CXWnd__Center_x                                            0x923AD0
#define CXWnd__ClrFocus_x                                          0x9238E0
#define CXWnd__Destroy_x                                           0x923990
#define CXWnd__DoAllDrawing_x                                      0x91FF10
#define CXWnd__DrawChildren_x                                      0x91FEE0
#define CXWnd__DrawColoredRect_x                                   0x920370
#define CXWnd__DrawTooltip_x                                       0x91EA40
#define CXWnd__DrawTooltipAtPoint_x                                0x91EB00
#define CXWnd__GetBorderFrame_x                                    0x9201D0
#define CXWnd__GetChildWndAt_x                                     0x923FF0
#define CXWnd__GetClientClipRect_x                                 0x9221D0
#define CXWnd__GetScreenClipRect_x                                 0x9222A0
#define CXWnd__GetScreenRect_x                                     0x922470
#define CXWnd__GetRelativeRect_x                                   0x922520
#define CXWnd__GetTooltipRect_x                                    0x9203C0
#define CXWnd__GetWindowTextA_x                                    0x49CE90
#define CXWnd__IsActive_x                                          0x920B00
#define CXWnd__IsDescendantOf_x                                    0x922E40
#define CXWnd__IsReallyVisible_x                                   0x922E70
#define CXWnd__IsType_x                                            0x924650
#define CXWnd__Move_x                                              0x922EE0
#define CXWnd__Move1_x                                             0x922F90
#define CXWnd__ProcessTransition_x                                 0x923A80
#define CXWnd__Refade_x                                            0x923240
#define CXWnd__Resize_x                                            0x923510
#define CXWnd__Right_x                                             0x923D10
#define CXWnd__SetFocus_x                                          0x9238A0
#define CXWnd__SetFont_x                                           0x923910
#define CXWnd__SetKeyTooltip_x                                     0x924460
#define CXWnd__SetMouseOver_x                                      0x921320
#define CXWnd__StartFade_x                                         0x922D20
#define CXWnd__GetChildItem_x                                      0x924160
#define CXWnd__SetParent_x                                         0x922BD0
#define CXWnd__Minimize_x                                          0x923580

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95A960

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x926E70
#define CXWndManager__DrawWindows_x                                0x926E90
#define CXWndManager__GetKeyboardFlags_x                           0x9295B0
#define CXWndManager__HandleKeyboardMsg_x                          0x929160
#define CXWndManager__RemoveWnd_x                                  0x9297E0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x929D60

// CDBStr
#define CDBStr__GetString_x                                        0x547E30

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFE70
#define EQ_Character__Cur_HP_x                                     0x4D2F30
#define EQ_Character__Cur_Mana_x                                   0x4DA680
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2EE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B38F0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3A40
#define EQ_Character__GetHPRegen_x                                 0x4E0580
#define EQ_Character__GetEnduranceRegen_x                          0x4E0B80
#define EQ_Character__GetManaRegen_x                               0x4E0FC0
#define EQ_Character__Max_Endurance_x                              0x65F850
#define EQ_Character__Max_HP_x                                     0x4D2D60
#define EQ_Character__Max_Mana_x                                   0x65F650
#define EQ_Character__doCombatAbility_x                            0x661C40
#define EQ_Character__UseSkill_x                                   0x4E2DC0
#define EQ_Character__GetConLevel_x                                0x657FA0
#define EQ_Character__IsExpansionFlag_x                            0x5BB5D0
#define EQ_Character__TotalEffect_x                                0x4C6C80
#define EQ_Character__GetPCSpellAffect_x                           0x4C3C30
#define EQ_Character__SpellDuration_x                              0x4C3760
#define EQ_Character__MySpellDuration_x                            0x4B2220
#define EQ_Character__GetAdjustedSkill_x                           0x4D5CB0
#define EQ_Character__GetBaseSkill_x                               0x4D6C50
#define EQ_Character__CanUseItem_x                                 0x4DA990

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BE7C0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x675BB0

//PcClient
#define PcClient__vftable_x                                        0xAF21B8
#define PcClient__PcClient_x                                       0x655710

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA8D0
#define CCharacterListWnd__EnterWorld_x                            0x4BA2A0
#define CCharacterListWnd__Quit_x                                  0x4B9FF0
#define CCharacterListWnd__UpdateList_x                            0x4BA490

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x639EE0
#define EQ_Item__CreateItemTagString_x                             0x898740
#define EQ_Item__IsStackable_x                                     0x89D490
#define EQ_Item__GetImageNum_x                                     0x89A2B0
#define EQ_Item__CreateItemClient_x                                0x639120
#define EQ_Item__GetItemValue_x                                    0x89B590
#define EQ_Item__ValueSellMerchant_x                               0x89EEA0
#define EQ_Item__IsKeyRingItem_x                                   0x89CD20
#define EQ_Item__CanGoInBag_x                                      0x63A000
#define EQ_Item__IsEmpty_x                                         0x89C870
#define EQ_Item__GetMaxItemCount_x                                 0x89B9B0
#define EQ_Item__GetHeldItem_x                                     0x89A180
#define EQ_Item__GetAugmentFitBySlot_x                             0x897FA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566860
#define EQ_LoadingS__Array_x                                       0xC13130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x660150
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8220
#define EQ_PC__GetCombatAbility_x                                  0x8A8890
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A8900
#define EQ_PC__GetItemRecastTimer_x                                0x6621C0
#define EQ_PC__HasLoreItem_x                                       0x6587C0
#define EQ_PC__AlertInventoryChanged_x                             0x6578E0
#define EQ_PC__GetPcZoneClient_x                                   0x684B40
#define EQ_PC__RemoveMyAffect_x                                    0x6653F0
#define EQ_PC__GetKeyRingItems_x                                   0x8A91D0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A8F50
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A94D0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C19B0
#define EQItemList__add_object_x                                   0x5EF020
#define EQItemList__add_item_x                                     0x5C1F10
#define EQItemList__delete_item_x                                  0x5C1F60
#define EQItemList__FreeItemList_x                                 0x5C1E60

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544980

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6774B0
#define EQPlayer__dEQPlayer_x                                      0x66A820
#define EQPlayer__DoAttack_x                                       0x67F2E0
#define EQPlayer__EQPlayer_x                                       0x66AEE0
#define EQPlayer__SetNameSpriteState_x                             0x66F1C0
#define EQPlayer__SetNameSpriteTint_x                              0x6700A0
#define PlayerBase__HasProperty_j_x                                0x989700
#define EQPlayer__IsTargetable_x                                   0x989BA0
#define EQPlayer__CanSee_x                                         0x989A00
#define EQPlayer__CanSee1_x                                        0x989AD0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9897C0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6825E0
#define PlayerZoneClient__GetLevel_x                               0x684B80
#define PlayerZoneClient__IsValidTeleport_x                        0x5F0190
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F620

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67A1F0
#define EQPlayerManager__GetSpawnByName_x                          0x67A2A0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A330

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63D630
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63D6B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63D6F0
#define KeypressHandler__ClearCommandStateArray_x                  0x63EAE0
#define KeypressHandler__HandleKeyDown_x                           0x63EB00
#define KeypressHandler__HandleKeyUp_x                             0x63EBA0
#define KeypressHandler__SaveKeymapping_x                          0x63EFF0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7766D0
#define MapViewMap__SaveEx_x                                       0x779A90
#define MapViewMap__SetZoom_x                                      0x77E150

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BC830

// StringTable 
#define StringTable__getString_x                                   0x8B76E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x665060
#define PcZoneClient__RemovePetEffect_x                            0x665690
#define PcZoneClient__HasAlternateAbility_x                        0x65F480
#define PcZoneClient__GetCurrentMod_x                              0x4E5EE0
#define PcZoneClient__GetModCap_x                                  0x4E5DE0
#define PcZoneClient__CanEquipItem_x                               0x65FB30
#define PcZoneClient__GetItemByID_x                                0x662640
#define PcZoneClient__GetItemByItemClass_x                         0x662790
#define PcZoneClient__RemoveBuffEffect_x                           0x6656B0
#define PcZoneClient__BandolierSwap_x                              0x660710
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x662160

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F4D80

//IconCache
#define IconCache__GetIcon_x                                       0x7181F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70FD00
#define CContainerMgr__CloseContainer_x                            0x70FFD0
#define CContainerMgr__OpenExperimentContainer_x                   0x710A50

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CECB0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x632060

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76CAE0
#define CLootWnd__RequestLootSlot_x                                0x76BDC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58E6E0
#define EQ_Spell__SpellAffects_x                                   0x58EB50
#define EQ_Spell__SpellAffectBase_x                                0x58E910
#define EQ_Spell__IsStackable_x                                    0x4CA970
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA760
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7BB0
#define EQ_Spell__IsSPAStacking_x                                  0x58F9A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58EEB0
#define EQ_Spell__IsNoRemove_x                                     0x4CA950
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58F9B0
#define __IsResEffectSpell_x                                       0x4C9CB0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD470

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C6E30

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x815A80
#define CTargetWnd__WndNotification_x                              0x8152C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x815590
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814430

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81A100
#define CTaskWnd__ConfirmAbandonTask_x                             0x81CD40

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x542370
#define CTaskManager__HandleMessage_x                              0x5407F0
#define CTaskManager__GetTaskStatus_x                              0x542420
#define CTaskManager__GetElementDescription_x                      0x5424A0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589630
#define EqSoundManager__PlayScriptMp3_x                            0x5898F0
#define EqSoundManager__SoundAssistPlay_x                          0x69D2C0
#define EqSoundManager__WaveInstancePlay_x                         0x69C830

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5337A0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x945350
#define CTextureAnimation__Draw_x                                  0x945550

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9412B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E3C0
#define CAltAbilityData__GetMercMaxRank_x                          0x56E350
#define CAltAbilityData__GetMaxRank_x                              0x563770

//CTargetRing
#define CTargetRing__Cast_x                                        0x630180

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA740
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A3D0
#define CharacterBase__CreateItemIndex_x                           0x6382B0
#define CharacterBase__GetItemPossession_x                         0x506290
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CF4B0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CF510
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F6CA0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F74D0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F7580

//messages
#define msg_spell_worn_off_x                                       0x5B3520
#define msg_new_text_x                                             0x5A7EB0
#define __msgTokenTextParam_x                                      0x5B57B0
#define msgTokenText_x                                             0x5B5A00

//SpellManager
#define SpellManager__vftable_x                                    0xADA54C
#define SpellManager__SpellManager_x                               0x6A05F0
#define Spellmanager__LoadTextSpells_x                             0x6A0EE0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A07C0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98D610

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51AAC0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B9A10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x650E60
#define ItemGlobalIndex__IsValidIndex_x                            0x51AB50

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C77F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7980

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x765380

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7143F0
#define CCursorAttachment__AttachToCursor1_x                       0x714430
#define CCursorAttachment__Deactivate_x                            0x715420

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x937F40
#define CSidlManagerBase__CreatePageWnd_x                          0x937740
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9339C0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933950

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9551F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x954EB0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5176F0
#define CFindItemWnd__WndNotification_x                            0x518330
#define CFindItemWnd__Update_x                                     0x518EA0
#define CFindItemWnd__PickupSelectedItem_x                         0x516F20

//IString
#define IString__Append_x                                          0x507AF0

//Camera
#define CDisplay__cameraType_x                                     0xDEACC8
#define EverQuest__Cameras_x                                       0xEA60A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x520470
#define LootFiltersManager__GetItemFilterData_x                    0x51FD80
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51FDB0
#define LootFiltersManager__SetItemLootFilter_x                    0x51FFD0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BCAF0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x993270
#define CResolutionHandler__GetWindowedStyle_x                     0x697CE0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70C930

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D32A0
#define CDistillerInfo__Instance_x                                 0x8D3240

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72B7D0
#define CGroupWnd__UpdateDisplay_x                                 0x72AB20

//ItemBase
#define ItemBase__IsLore_x                                         0x89CDD0
#define ItemBase__IsLoreEquipped_x                                 0x89CE50

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EEF80
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EF0C0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EF120

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D300
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x690C90

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50DE30

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA1D0
#define FactionManagerClient__HandleFactionMessage_x               0x4FA840
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAE00
#define FactionManagerClient__GetMaxFaction_x                      0x4FAE1F
#define FactionManagerClient__GetMinFaction_x                      0x4FADD0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x506260

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91C6A0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C170

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x506500

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56D860

//CTargetManager
#define CTargetManager__Get_x                                      0x6A3E50

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D300

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8FE0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1E00

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF43734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C04F0
#define CAAWnd__UpdateSelected_x                                   0x6BCD60
#define CAAWnd__Update_x                                           0x6BF810

//CXRect
#define CXRect__operator_and_x                                     0x7228B0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483200

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
