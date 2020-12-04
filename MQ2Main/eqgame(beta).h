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
#define __ExpectedVersionDate                                     "Dec  3 2020"
#define __ExpectedVersionTime                                     "04:17:37"
#define __ActualVersionDate_x                                      0xAF5558
#define __ActualVersionTime_x                                      0xAF554C
#define __ActualVersionBuild_x                                     0xAE3584

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x644310
#define __MemChecker1_x                                            0x8F72F0
#define __MemChecker2_x                                            0x6B47A0
#define __MemChecker3_x                                            0x6B46F0
#define __MemChecker4_x                                            0x84DA40
#define __EncryptPad0_x                                            0xC2B9C8
#define __EncryptPad1_x                                            0xC89210
#define __EncryptPad2_x                                            0xC3BD90
#define __EncryptPad3_x                                            0xC3B990
#define __EncryptPad4_x                                            0xC797A0
#define __EncryptPad5_x                                            0xF4C0E0
#define __AC1_x                                                    0x80C0C6
#define __AC2_x                                                    0x5FDBAF
#define __AC3_x                                                    0x605200
#define __AC4_x                                                    0x6091B0
#define __AC5_x                                                    0x60F4AF
#define __AC6_x                                                    0x613966
#define __AC7_x                                                    0x5FD620
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
#define __do_loot_x                                                0x5C9630
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
#define __gfMaxZoomCameraDistance_x                                0xAED180
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
#define __CastRay_x                                                0x5C4D20
#define __CastRay2_x                                               0x5C4D70
#define __ConvertItemTags_x                                        0x5E0A30
#define __CleanItemTags_x                                          0x47D340
#define __DoesFileExist_x                                          0x8FA320
#define __EQGetTime_x                                              0x8F6F20
#define __ExecuteCmd_x                                             0x5BD6B0
#define __FixHeading_x                                             0x98BB70
#define __FlushDxKeyboard_x                                        0x6B0640
#define __GameLoop_x                                               0x6B3970
#define __get_bearing_x                                            0x5C4880
#define __get_melee_range_x                                        0x5C4F60
#define __GetAnimationCache_x                                      0x718E40
#define __GetGaugeValueFromEQ_x                                    0x80A570
#define __GetLabelFromEQ_x                                         0x80C050
#define __GetXTargetType_x                                         0x98D5C0
#define __HandleMouseWheel_x                                       0x6B4850
#define __HeadingDiff_x                                            0x98BBE0
#define __HelpPath_x                                               0xF43E04
#define __LoadFrontEnd_x                                           0x6B0C80
#define __NewUIINI_x                                               0x80A240
#define __ProcessGameEvents_x                                      0x625840
#define __ProcessMouseEvent_x                                      0x624FD0
#define __SaveColors_x                                             0x55E310
#define __STMLToText_x                                             0x92EFA0
#define __ToggleKeyRingItem_x                                      0x51C870
#define CMemoryMappedFile__SetFile_x                               0xA7B0F0
#define CrashDetected_x                                            0x6B2730
#define DrawNetStatus_x                                            0x6515F0
#define Expansion_HoT_x                                            0xEA5D48
#define Teleport_Table_Size_x                                      0xE9D7E0
#define Teleport_Table_x                                           0xE9DCB0
#define Util__FastTime_x                                           0x8F6AF0
#define __CopyLayout_x                                             0x63FA00
#define __WndProc_x                                                0x6B2C30
#define __ProcessKeyboardEvent_x                                   0x6B21D0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4905A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4995A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499370
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493B40
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492F90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5665D0
#define AltAdvManager__IsAbilityReady_x                            0x565370
#define AltAdvManager__GetAAById_x                                 0x565700
#define AltAdvManager__CanTrainAbility_x                           0x565770
#define AltAdvManager__CanSeeAbility_x                             0x565AD0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB350
#define CharacterZoneClient__HasSkill_x                            0x4D61D0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7900
#define CharacterZoneClient__IsStackBlocked_x                      0x4C29D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBE60
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA270
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA350
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA430
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4AC0
#define CharacterZoneClient__BardCastBard_x                        0x4C74F0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF870
#define CharacterZoneClient__GetEffect_x                           0x4BBDA0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5B30
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5C00
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5C50
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5DA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5F80
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3CE0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8860
#define CharacterZoneClient__FindItemByRecord_x                    0x4D82E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DA4F0
#define CBankWnd__WndNotification_x                                0x6DA2C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E7DB0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92C780
#define CButtonWnd__CButtonWnd_x                                   0x92B360

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x708000
#define CChatManager__InitContextMenu_x                            0x701130
#define CChatManager__FreeChatWindow_x                             0x706B40
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9C80
#define CChatManager__SetLockedActiveChatWindow_x                  0x707C80
#define CChatManager__CreateChatWindow_x                           0x707180

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9D90

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93F9D0
#define CContextMenu__dCContextMenu_x                              0x93FC10
#define CContextMenu__AddMenuItem_x                                0x93FC20
#define CContextMenu__RemoveMenuItem_x                             0x93FF30
#define CContextMenu__RemoveAllMenuItems_x                         0x93FF50
#define CContextMenu__CheckMenuItem_x                              0x93FFD0
#define CContextMenu__SetMenuItem_x                                0x93FE50
#define CContextMenu__AddSeparator_x                               0x93FDB0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x940570
#define CContextMenuManager__RemoveMenu_x                          0x9405E0
#define CContextMenuManager__PopupMenu_x                           0x9406A0
#define CContextMenuManager__Flush_x                               0x940510
#define CContextMenuManager__GetMenu_x                             0x49B7A0
#define CContextMenuManager__CreateDefaultMenu_x                   0x713770

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1D20
#define CChatService__GetFriendName_x                              0x8D1D30

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x708870
#define CChatWindow__Clear_x                                       0x709B40
#define CChatWindow__WndNotification_x                             0x70A2D0
#define CChatWindow__AddHistory_x                                  0x709400

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93CE20
#define CComboWnd__Draw_x                                          0x93C300
#define CComboWnd__GetCurChoice_x                                  0x93CC60
#define CComboWnd__GetListRect_x                                   0x93C7C0
#define CComboWnd__GetTextRect_x                                   0x93CE90
#define CComboWnd__InsertChoice_x                                  0x93C950
#define CComboWnd__SetColors_x                                     0x93C920
#define CComboWnd__SetChoice_x                                     0x93CC30
#define CComboWnd__GetItemCount_x                                  0x93CC70
#define CComboWnd__GetCurChoiceText_x                              0x93CCB0
#define CComboWnd__GetChoiceText_x                                 0x93CC80
#define CComboWnd__InsertChoiceAtIndex_x                           0x93C9F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x711190
#define CContainerWnd__vftable_x                                   0xAFE74C
#define CContainerWnd__SetContainer_x                              0x7126E0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558C70
#define CDisplay__PreZoneMainUI_x                                  0x558C80
#define CDisplay__CleanGameUI_x                                    0x55E0D0
#define CDisplay__GetClickedActor_x                                0x5510D0
#define CDisplay__GetUserDefinedColor_x                            0x549740
#define CDisplay__GetWorldFilePath_x                               0x552B40
#define CDisplay__is3dON_x                                         0x54DD30
#define CDisplay__ReloadUI_x                                       0x558180
#define CDisplay__WriteTextHD2_x                                   0x54DB20
#define CDisplay__TrueDistance_x                                   0x554800
#define CDisplay__SetViewActor_x                                   0x5509F0
#define CDisplay__GetFloorHeight_x                                 0x54DDF0
#define CDisplay__SetRenderWindow_x                                0x54C770
#define CDisplay__ToggleScreenshotMode_x                           0x5504C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95F810

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x942ED0
#define CEditWnd__EnsureCaretVisible_x                             0x9450A0
#define CEditWnd__GetCaretPt_x                                     0x944050
#define CEditWnd__GetCharIndexPt_x                                 0x943E00
#define CEditWnd__GetDisplayString_x                               0x943CA0
#define CEditWnd__GetHorzOffset_x                                  0x942570
#define CEditWnd__GetLineForPrintableChar_x                        0x944FA0
#define CEditWnd__GetSelStartPt_x                                  0x9440B0
#define CEditWnd__GetSTMLSafeText_x                                0x943AC0
#define CEditWnd__PointFromPrintableChar_x                         0x944BD0
#define CEditWnd__SelectableCharFromPoint_x                        0x944D40
#define CEditWnd__SetEditable_x                                    0x944180
#define CEditWnd__SetWindowTextA_x                                 0x943840
#define CEditWnd__ReplaceSelection_x                               0x944840
#define CEditWnd__ReplaceSelection1_x                              0x9447C0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x612E40
#define CEverQuest__ClickedPlayer_x                                0x604FE0
#define CEverQuest__CreateTargetIndicator_x                        0x6229B0
#define CEverQuest__DeleteTargetIndicator_x                        0x622A40
#define CEverQuest__DoTellWindow_x                                 0x4E9E70
#define CEverQuest__OutputTextToLog_x                              0x4EA140
#define CEverQuest__DropHeldItemOnGround_x                         0x5FA140
#define CEverQuest__dsp_chat_x                                     0x4EA4D0
#define CEverQuest__trimName_x                                     0x61EB60
#define CEverQuest__Emote_x                                        0x6136A0
#define CEverQuest__EnterZone_x                                    0x60D7A0
#define CEverQuest__GetBodyTypeDesc_x                              0x6180F0
#define CEverQuest__GetClassDesc_x                                 0x618730
#define CEverQuest__GetClassThreeLetterCode_x                      0x618D30
#define CEverQuest__GetDeityDesc_x                                 0x621200
#define CEverQuest__GetLangDesc_x                                  0x618EF0
#define CEverQuest__GetRaceDesc_x                                  0x618710
#define CEverQuest__InterpretCmd_x                                 0x6217D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FE2D0
#define CEverQuest__LMouseUp_x                                     0x5FC660
#define CEverQuest__RightClickedOnPlayer_x                         0x5FEBB0
#define CEverQuest__RMouseUp_x                                     0x5FD5E0
#define CEverQuest__SetGameState_x                                 0x5F9ED0
#define CEverQuest__UPCNotificationFlush_x                         0x61EA60
#define CEverQuest__IssuePetCommand_x                              0x61A300
#define CEverQuest__ReportSuccessfulHit_x                          0x6149F0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x722D30
#define CGaugeWnd__CalcLinesFillRect_x                             0x722D90
#define CGaugeWnd__Draw_x                                          0x7223B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFFA0
#define CGuild__GetGuildName_x                                     0x4AEA50
#define CGuild__GetGuildIndex_x                                    0x4AF050

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73C990

//CHotButton
#define CHotButton__SetCheck_x                                     0x633FA0
#define CHotButton__SetButtonSize_x                                0x634360

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x749BC0
#define CInvSlotMgr__MoveItem_x                                    0x748890
#define CInvSlotMgr__SelectSlot_x                                  0x749C90

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7470C0
#define CInvSlot__SliderComplete_x                                 0x744E10
#define CInvSlot__GetItemBase_x                                    0x7447A0
#define CInvSlot__UpdateItem_x                                     0x744910

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74B710
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74A8B0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74B290

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8058C0
#define CItemDisplayWnd__UpdateStrings_x                           0x759EC0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x753B40
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x754070
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75A4C0
#define CItemDisplayWnd__AboutToShow_x                             0x759B20
#define CItemDisplayWnd__WndNotification_x                         0x75B730
#define CItemDisplayWnd__RequestConvertItem_x                      0x75B070
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x758B80
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x759940

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8364D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75FC40

// CLabel 
#define CLabel__Draw_x                                             0x7656E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9155C0
#define CListWnd__dCListWnd_x                                      0x9158E0
#define CListWnd__AddColumn_x                                      0x919D50
#define CListWnd__AddColumn1_x                                     0x919DA0
#define CListWnd__AddLine_x                                        0x91A130
#define CListWnd__AddString_x                                      0x919F30
#define CListWnd__CalculateFirstVisibleLine_x                      0x919B20
#define CListWnd__CalculateVSBRange_x                              0x919900
#define CListWnd__ClearSel_x                                       0x91A910
#define CListWnd__ClearAllSel_x                                    0x91A970
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91B370
#define CListWnd__Compare_x                                        0x919230
#define CListWnd__Draw_x                                           0x915A10
#define CListWnd__DrawColumnSeparators_x                           0x918200
#define CListWnd__DrawHeader_x                                     0x918670
#define CListWnd__DrawItem_x                                       0x918B70
#define CListWnd__DrawLine_x                                       0x918370
#define CListWnd__DrawSeparator_x                                  0x9182A0
#define CListWnd__EnableLine_x                                     0x917AE0
#define CListWnd__EnsureVisible_x                                  0x91B2A0
#define CListWnd__ExtendSel_x                                      0x91A840
#define CListWnd__GetColumnTooltip_x                               0x917620
#define CListWnd__GetColumnMinWidth_x                              0x917690
#define CListWnd__GetColumnWidth_x                                 0x917590
#define CListWnd__GetCurSel_x                                      0x916F20
#define CListWnd__GetItemAtPoint_x                                 0x917D50
#define CListWnd__GetItemAtPoint1_x                                0x917DC0
#define CListWnd__GetItemData_x                                    0x916FA0
#define CListWnd__GetItemHeight_x                                  0x917360
#define CListWnd__GetItemIcon_x                                    0x917130
#define CListWnd__GetItemRect_x                                    0x917BD0
#define CListWnd__GetItemText_x                                    0x916FE0
#define CListWnd__GetSelList_x                                     0x91A9C0
#define CListWnd__GetSeparatorRect_x                               0x918000
#define CListWnd__InsertLine_x                                     0x91A520
#define CListWnd__RemoveLine_x                                     0x91A670
#define CListWnd__SetColors_x                                      0x9198D0
#define CListWnd__SetColumnJustification_x                         0x919600
#define CListWnd__SetColumnLabel_x                                 0x919ED0
#define CListWnd__SetColumnWidth_x                                 0x919520
#define CListWnd__SetCurSel_x                                      0x91A780
#define CListWnd__SetItemColor_x                                   0x91AF60
#define CListWnd__SetItemData_x                                    0x91AF20
#define CListWnd__SetItemText_x                                    0x91AB30
#define CListWnd__ShiftColumnSeparator_x                           0x9196C0
#define CListWnd__Sort_x                                           0x9193B0
#define CListWnd__ToggleSel_x                                      0x91A7B0
#define CListWnd__SetColumnsSizable_x                              0x919770
#define CListWnd__SetItemWnd_x                                     0x91ADE0
#define CListWnd__GetItemWnd_x                                     0x917180
#define CListWnd__SetItemIcon_x                                    0x91ABB0
#define CListWnd__CalculateCustomWindowPositions_x                 0x919C10
#define CListWnd__SetVScrollPos_x                                  0x919500

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77AE70
#define CMapViewWnd__GetWorldCoordinates_x                         0x779580
#define CMapViewWnd__HandleLButtonDown_x                           0x7765C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79B110
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79B9F0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79BF20
#define CMerchantWnd__SelectRecoverySlot_x                         0x79EED0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x799C90
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4A90
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79AD30

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89F740
#define CPacketScrambler__hton_x                                   0x89F730

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x934590
#define CSidlManager__FindScreenPieceTemplate_x                    0x9349A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x934790
#define CSidlManager__CreateLabel_x                                0x7FCBC0
#define CSidlManager__CreateXWndFromTemplate_x                     0x937900
#define CSidlManager__CreateXWndFromTemplate1_x                    0x937AE0
#define CSidlManager__CreateXWnd_x                                 0x7FCAF0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FD0B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x931070
#define CSidlScreenWnd__CalculateVSBRange_x                        0x930F70
#define CSidlScreenWnd__ConvertToRes_x                             0x95A220
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930A60
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x930750
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x930820
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9308F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x931510
#define CSidlScreenWnd__EnableIniStorage_x                         0x9319E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x931700
#define CSidlScreenWnd__Init1_x                                    0x930350
#define CSidlScreenWnd__LoadIniInfo_x                              0x931A30
#define CSidlScreenWnd__LoadIniListWnd_x                           0x932570
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92F760
#define CSidlScreenWnd__StoreIniInfo_x                             0x9320F0
#define CSidlScreenWnd__StoreIniVis_x                              0x932450
#define CSidlScreenWnd__WndNotification_x                          0x931420
#define CSidlScreenWnd__GetChildItem_x                             0x931960
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9211C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DA190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x699650
#define CSkillMgr__GetSkillCap_x                                   0x699830
#define CSkillMgr__GetNameToken_x                                  0x698DD0
#define CSkillMgr__IsActivatedSkill_x                              0x698F10
#define CSkillMgr__IsCombatSkill_x                                 0x698E50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x941350
#define CSliderWnd__SetValue_x                                     0x9411C0
#define CSliderWnd__SetNumTicks_x                                  0x941220

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x802C90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x949C90
#define CStmlWnd__ParseSTML_x                                      0x94AFD0
#define CStmlWnd__CalculateHSBRange_x                              0x94ADA0
#define CStmlWnd__CalculateVSBRange_x                              0x94AD20
#define CStmlWnd__CanBreakAtCharacter_x                            0x94F0E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94FD70
#define CStmlWnd__ForceParseNow_x                                  0x94A280
#define CStmlWnd__GetNextTagPiece_x                                0x94F040
#define CStmlWnd__GetSTMLText_x                                    0x50DC40
#define CStmlWnd__GetVisibleText_x                                 0x94A2A0
#define CStmlWnd__InitializeWindowVariables_x                      0x94FBC0
#define CStmlWnd__MakeStmlColorTag_x                               0x949300
#define CStmlWnd__MakeWndNotificationTag_x                         0x949370
#define CStmlWnd__SetSTMLText_x                                    0x9483B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x950E60
#define CStmlWnd__UpdateHistoryString_x                            0x94FF80

// CTabWnd 
#define CTabWnd__Draw_x                                            0x947500
#define CTabWnd__DrawCurrentPage_x                                 0x947C30
#define CTabWnd__DrawTab_x                                         0x947950
#define CTabWnd__GetCurrentPage_x                                  0x946D00
#define CTabWnd__GetPageInnerRect_x                                0x946F40
#define CTabWnd__GetTabInnerRect_x                                 0x946E80
#define CTabWnd__GetTabRect_x                                      0x946D30
#define CTabWnd__InsertPage_x                                      0x947150
#define CTabWnd__RemovePage_x                                      0x9472C0
#define CTabWnd__SetPage_x                                         0x946FC0
#define CTabWnd__SetPageRect_x                                     0x947440
#define CTabWnd__UpdatePage_x                                      0x947810
#define CTabWnd__GetPageFromTabIndex_x                             0x947890
#define CTabWnd__GetCurrentTabIndex_x                              0x946CF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x760070
#define CPageWnd__SetTabText_x                                     0x946840
#define CPageWnd__FlashTab_x                                       0x9468A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A92E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91E020
#define CTextureFont__GetTextExtent_x                              0x91E1E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AD7F0
#define CHtmlComponentWnd__ValidateUri_x                           0x73E380
#define CHtmlWnd__SetClientCallbacks_x                             0x6393D0
#define CHtmlWnd__AddObserver_x                                    0x6393F0
#define CHtmlWnd__RemoveObserver_x                                 0x639450
#define Window__getProgress_x                                      0x855060
#define Window__getStatus_x                                        0x855080
#define Window__getURI_x                                           0x855090

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x956FF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90B000

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9B70
#define CXStr__CXStr1_x                                            0x9E25F0
#define CXStr__CXStr3_x                                            0x8F2ED0
#define CXStr__dCXStr_x                                            0x478450
#define CXStr__operator_equal_x                                    0x8F3100
#define CXStr__operator_equal1_x                                   0x8F3140
#define CXStr__operator_plus_equal1_x                              0x8F3BD0
#define CXStr__SetString_x                                         0x8F5AD0
#define CXStr__operator_char_p_x                                   0x8F3640
#define CXStr__GetChar_x                                           0x8F5420
#define CXStr__Delete_x                                            0x8F4CD0
#define CXStr__GetUnicode_x                                        0x8F5490
#define CXStr__GetLength_x                                         0x47D6F0
#define CXStr__Mid_x                                               0x47D700
#define CXStr__Insert_x                                            0x8F54F0
#define CXStr__FindNext_x                                          0x8F5140

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93F5E0
#define CXWnd__BringToTop_x                                        0x924980
#define CXWnd__Center_x                                            0x924500
#define CXWnd__ClrFocus_x                                          0x924310
#define CXWnd__Destroy_x                                           0x9243C0
#define CXWnd__DoAllDrawing_x                                      0x920950
#define CXWnd__DrawChildren_x                                      0x920920
#define CXWnd__DrawColoredRect_x                                   0x920DB0
#define CXWnd__DrawTooltip_x                                       0x91F450
#define CXWnd__DrawTooltipAtPoint_x                                0x91F510
#define CXWnd__GetBorderFrame_x                                    0x920C10
#define CXWnd__GetChildWndAt_x                                     0x924A20
#define CXWnd__GetClientClipRect_x                                 0x922C00
#define CXWnd__GetScreenClipRect_x                                 0x922CB0
#define CXWnd__GetScreenRect_x                                     0x922E60
#define CXWnd__GetRelativeRect_x                                   0x922F20
#define CXWnd__GetTooltipRect_x                                    0x920E00
#define CXWnd__GetWindowTextA_x                                    0x49CEA0
#define CXWnd__IsActive_x                                          0x921540
#define CXWnd__IsDescendantOf_x                                    0x923860
#define CXWnd__IsReallyVisible_x                                   0x923890
#define CXWnd__IsType_x                                            0x925080
#define CXWnd__Move_x                                              0x923900
#define CXWnd__Move1_x                                             0x9239B0
#define CXWnd__ProcessTransition_x                                 0x9244B0
#define CXWnd__Refade_x                                            0x923C90
#define CXWnd__Resize_x                                            0x923F20
#define CXWnd__Right_x                                             0x924740
#define CXWnd__SetFocus_x                                          0x9242D0
#define CXWnd__SetFont_x                                           0x924340
#define CXWnd__SetKeyTooltip_x                                     0x924EA0
#define CXWnd__SetMouseOver_x                                      0x921D80
#define CXWnd__StartFade_x                                         0x923740
#define CXWnd__GetChildItem_x                                      0x924B90
#define CXWnd__SetParent_x                                         0x923600
#define CXWnd__Minimize_x                                          0x923F90

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95B2A0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9278C0
#define CXWndManager__DrawWindows_x                                0x9278E0
#define CXWndManager__GetKeyboardFlags_x                           0x929FE0
#define CXWndManager__HandleKeyboardMsg_x                          0x929B90
#define CXWndManager__RemoveWnd_x                                  0x92A210
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92A780

// CDBStr
#define CDBStr__GetString_x                                        0x5486E0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFFD0
#define EQ_Character__Cur_HP_x                                     0x4D3210
#define EQ_Character__Cur_Mana_x                                   0x4DA930
#define EQ_Character__GetCastingTimeModifier_x                     0x4C3040
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3920
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3A70
#define EQ_Character__GetHPRegen_x                                 0x4E0800
#define EQ_Character__GetEnduranceRegen_x                          0x4E0E00
#define EQ_Character__GetManaRegen_x                               0x4E1240
#define EQ_Character__Max_Endurance_x                              0x65FD50
#define EQ_Character__Max_HP_x                                     0x4D3040
#define EQ_Character__Max_Mana_x                                   0x65FB50
#define EQ_Character__doCombatAbility_x                            0x662140
#define EQ_Character__UseSkill_x                                   0x4E3040
#define EQ_Character__GetConLevel_x                                0x6585A0
#define EQ_Character__IsExpansionFlag_x                            0x5BBE60
#define EQ_Character__TotalEffect_x                                0x4C6DE0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3D90
#define EQ_Character__SpellDuration_x                              0x4C38C0
#define EQ_Character__MySpellDuration_x                            0x4B2250
#define EQ_Character__GetAdjustedSkill_x                           0x4D5F90
#define EQ_Character__GetBaseSkill_x                               0x4D6F30
#define EQ_Character__CanUseItem_x                                 0x4DAC40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BECD0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x676010

//PcClient
#define PcClient__vftable_x                                        0xAF21D8
#define PcClient__PcClient_x                                       0x655D00

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA9F0
#define CCharacterListWnd__EnterWorld_x                            0x4BA3C0
#define CCharacterListWnd__Quit_x                                  0x4BA110
#define CCharacterListWnd__UpdateList_x                            0x4BA5B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x63A590
#define EQ_Item__CreateItemTagString_x                             0x898C10
#define EQ_Item__IsStackable_x                                     0x89D950
#define EQ_Item__GetImageNum_x                                     0x89A790
#define EQ_Item__CreateItemClient_x                                0x6397D0
#define EQ_Item__GetItemValue_x                                    0x89BA80
#define EQ_Item__ValueSellMerchant_x                               0x89F320
#define EQ_Item__IsKeyRingItem_x                                   0x89D1E0
#define EQ_Item__CanGoInBag_x                                      0x63A6B0
#define EQ_Item__IsEmpty_x                                         0x89CD50
#define EQ_Item__GetMaxItemCount_x                                 0x89BEA0
#define EQ_Item__GetHeldItem_x                                     0x89A660
#define EQ_Item__GetAugmentFitBySlot_x                             0x898460

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5672B0
#define EQ_LoadingS__Array_x                                       0xC13130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x660650
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8600
#define EQ_PC__GetCombatAbility_x                                  0x8A8C70
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A8CE0
#define EQ_PC__GetItemRecastTimer_x                                0x6626C0
#define EQ_PC__HasLoreItem_x                                       0x658DC0
#define EQ_PC__AlertInventoryChanged_x                             0x657ED0
#define EQ_PC__GetPcZoneClient_x                                   0x684FA0
#define EQ_PC__RemoveMyAffect_x                                    0x6658E0
#define EQ_PC__GetKeyRingItems_x                                   0x8A95B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9330
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A98B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C22B0
#define EQItemList__add_object_x                                   0x5EF980
#define EQItemList__add_item_x                                     0x5C2810
#define EQItemList__delete_item_x                                  0x5C2860
#define EQItemList__FreeItemList_x                                 0x5C2760

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5451D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x677910
#define EQPlayer__dEQPlayer_x                                      0x66ACA0
#define EQPlayer__DoAttack_x                                       0x67F740
#define EQPlayer__EQPlayer_x                                       0x66B360
#define EQPlayer__SetNameSpriteState_x                             0x66F620
#define EQPlayer__SetNameSpriteTint_x                              0x670500
#define PlayerBase__HasProperty_j_x                                0x989F80
#define EQPlayer__IsTargetable_x                                   0x98A420
#define EQPlayer__CanSee_x                                         0x98A280
#define EQPlayer__CanSee1_x                                        0x98A350
#define PlayerBase__GetVisibilityLineSegment_x                     0x98A040

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x682A40
#define PlayerZoneClient__GetLevel_x                               0x684FE0
#define PlayerZoneClient__IsValidTeleport_x                        0x5F0AF0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55FF30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67A650
#define EQPlayerManager__GetSpawnByName_x                          0x67A700
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A790

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63DC60
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63DCE0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63DD20
#define KeypressHandler__ClearCommandStateArray_x                  0x63F110
#define KeypressHandler__HandleKeyDown_x                           0x63F130
#define KeypressHandler__HandleKeyUp_x                             0x63F1D0
#define KeypressHandler__SaveKeymapping_x                          0x63F620

// MapViewMap 
#define MapViewMap__Clear_x                                        0x776CE0
#define MapViewMap__SaveEx_x                                       0x77A0A0
#define MapViewMap__SetZoom_x                                      0x77E760

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BCC80

// StringTable 
#define StringTable__getString_x                                   0x8B7AA0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x665550
#define PcZoneClient__RemovePetEffect_x                            0x665B80
#define PcZoneClient__HasAlternateAbility_x                        0x65F980
#define PcZoneClient__GetCurrentMod_x                              0x4E6160
#define PcZoneClient__GetModCap_x                                  0x4E6060
#define PcZoneClient__CanEquipItem_x                               0x660030
#define PcZoneClient__GetItemByID_x                                0x662B30
#define PcZoneClient__GetItemByItemClass_x                         0x662C80
#define PcZoneClient__RemoveBuffEffect_x                           0x665BA0
#define PcZoneClient__BandolierSwap_x                              0x660C10
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x662660

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F5670

//IconCache
#define IconCache__GetIcon_x                                       0x718840

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x710330
#define CContainerMgr__CloseContainer_x                            0x710600
#define CContainerMgr__OpenExperimentContainer_x                   0x711080

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CF3C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x632780

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76D160
#define CLootWnd__RequestLootSlot_x                                0x76C440

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58ED80
#define EQ_Spell__SpellAffects_x                                   0x58F1F0
#define EQ_Spell__SpellAffectBase_x                                0x58EFB0
#define EQ_Spell__IsStackable_x                                    0x4CAC30
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAA80
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7C20
#define EQ_Spell__IsSPAStacking_x                                  0x590040
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58F550
#define EQ_Spell__IsNoRemove_x                                     0x4CAC10
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x590050
#define __IsResEffectSpell_x                                       0x4C9E30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD530

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C7340

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x815FD0
#define CTargetWnd__WndNotification_x                              0x815810
#define CTargetWnd__RefreshTargetBuffs_x                           0x815AE0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814970

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81A640
#define CTaskWnd__ConfirmAbandonTask_x                             0x81D280

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x542C00
#define CTaskManager__HandleMessage_x                              0x541060
#define CTaskManager__GetTaskStatus_x                              0x542CB0
#define CTaskManager__GetElementDescription_x                      0x542D30

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589F20
#define EqSoundManager__PlayScriptMp3_x                            0x58A1E0
#define EqSoundManager__SoundAssistPlay_x                          0x69D5A0
#define EqSoundManager__WaveInstancePlay_x                         0x69CB10

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x533F00

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x945D50
#define CTextureAnimation__Draw_x                                  0x945F50

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x941CB0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56ED70
#define CAltAbilityData__GetMercMaxRank_x                          0x56ED00
#define CAltAbilityData__GetMaxRank_x                              0x5641F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x6308A0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CAA60
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A910
#define CharacterBase__CreateItemIndex_x                           0x638970
#define CharacterBase__GetItemPossession_x                         0x506430
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CF9D0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CFA30
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F72A0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F7AD0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F7B80

//messages
#define msg_spell_worn_off_x                                       0x5B3DB0
#define msg_new_text_x                                             0x5A8710
#define __msgTokenTextParam_x                                      0x5B6050
#define msgTokenText_x                                             0x5B62A0

//SpellManager
#define SpellManager__vftable_x                                    0xADA554
#define SpellManager__SpellManager_x                               0x6A08D0
#define Spellmanager__LoadTextSpells_x                             0x6A11C0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A0AA0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98DEB0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51AFC0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5BA2E0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x651450
#define ItemGlobalIndex__IsValidIndex_x                            0x51B050

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C7D00
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7E90

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x765A20

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x714A10
#define CCursorAttachment__AttachToCursor1_x                       0x714A50
#define CCursorAttachment__Deactivate_x                            0x715A40

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x938930
#define CSidlManagerBase__CreatePageWnd_x                          0x938130
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9343B0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x934340

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x955B70
#define CEQSuiteTextureLoader__GetTexture_x                        0x955830

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x517C20
#define CFindItemWnd__WndNotification_x                            0x518860
#define CFindItemWnd__Update_x                                     0x5193B0
#define CFindItemWnd__PickupSelectedItem_x                         0x517450

//IString
#define IString__Append_x                                          0x507D00

//Camera
#define CDisplay__cameraType_x                                     0xDEACC8
#define EverQuest__Cameras_x                                       0xEA60A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5209B0
#define LootFiltersManager__GetItemFilterData_x                    0x5202C0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5202F0
#define LootFiltersManager__SetItemLootFilter_x                    0x520510

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BD1F0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x993B50
#define CResolutionHandler__GetWindowedStyle_x                     0x698100

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70CFE0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D37C0
#define CDistillerInfo__Instance_x                                 0x8D3760

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72BD20
#define CGroupWnd__UpdateDisplay_x                                 0x72B070

//ItemBase
#define ItemBase__IsLore_x                                         0x89D290
#define ItemBase__IsLoreEquipped_x                                 0x89D310

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EF8E0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EFA20
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EFA80

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D6C0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x691040

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50E290

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA1B0
#define FactionManagerClient__HandleFactionMessage_x               0x4FA820
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAE20
#define FactionManagerClient__GetMaxFaction_x                      0x4FAE3F
#define FactionManagerClient__GetMinFaction_x                      0x4FADF0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x506400

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91CFE0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C1B0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x506710

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56E210

//CTargetManager
#define CTargetManager__Get_x                                      0x6A4120

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D6C0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A90A0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C2700

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF43734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C0C10
#define CAAWnd__UpdateSelected_x                                   0x6BD480
#define CAAWnd__Update_x                                           0x6BFF30

//CXRect
#define CXRect__operator_and_x                                     0x722DF0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483340

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
