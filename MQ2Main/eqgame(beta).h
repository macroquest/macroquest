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
#define __ExpectedVersionDate                                     "Nov 16 2020"
#define __ExpectedVersionTime                                     "04:16:51"
#define __ActualVersionDate_x                                      0xAF5544
#define __ActualVersionTime_x                                      0xAF5538
#define __ActualVersionBuild_x                                     0xAE3544

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642E00
#define __MemChecker1_x                                            0x8F6390
#define __MemChecker2_x                                            0x6B3320
#define __MemChecker3_x                                            0x6B3270
#define __MemChecker4_x                                            0x84C590
#define __EncryptPad0_x                                            0xC2B9C8
#define __EncryptPad1_x                                            0xC89210
#define __EncryptPad2_x                                            0xC3BD90
#define __EncryptPad3_x                                            0xC3B990
#define __EncryptPad4_x                                            0xC797A0
#define __EncryptPad5_x                                            0xF4B650
#define __AC1_x                                                    0x80AE76
#define __AC2_x                                                    0x5FC4AF
#define __AC3_x                                                    0x603B00
#define __AC4_x                                                    0x607AB0
#define __AC5_x                                                    0x60DDAF
#define __AC6_x                                                    0x612266
#define __AC7_x                                                    0x5FBF20
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19045C

// Direct Input
#define DI8__Main_x                                                0xF4B670
#define DI8__Keyboard_x                                            0xF4B674
#define DI8__Mouse_x                                               0xF4B688
#define DI8__Mouse_Copy_x                                          0xEA49DC
#define DI8__Mouse_Check_x                                         0xF491A4
#define __AutoSkillArray_x                                         0xEA58F8
#define __Attack_x                                                 0xF4372B
#define __Autofire_x                                               0xF4372C
#define __BindList_x                                               0xC1A3F8
#define g_eqCommandStates_x                                        0xC1B178
#define __Clicks_x                                                 0xEA4A94
#define __CommandList_x                                            0xC1BD38
#define __CurrentMapLabel_x                                        0xF5C14C
#define __CurrentSocial_x                                          0xC037C8
#define __DoAbilityList_x                                          0xEDB24C
#define __do_loot_x                                                0x5C7EA0
#define __DrawHandler_x                                            0x15DB140
#define __GroupCount_x                                             0xE9FA7A
#define __Guilds_x                                                 0xEA3918
#define __gWorld_x                                                 0xE9F924
#define __HWnd_x                                                   0xF4B68C
#define __heqmain_x                                                0xF4B638
#define __InChatMode_x                                             0xEA49C4
#define __LastTell_x                                               0xEA6948
#define __LMouseHeldTime_x                                         0xEA4B00
#define __Mouse_x                                                  0xF4B65C
#define __MouseLook_x                                              0xEA4A5A
#define __MouseEventTime_x                                         0xF4420C
#define __gpbCommandEvent_x                                        0xE9D3CC
#define __NetStatusToggle_x                                        0xEA4A5D
#define __PCNames_x                                                0xEA5EF4
#define __RangeAttackReady_x                                       0xEA5BDC
#define __RMouseHeldTime_x                                         0xEA4AFC
#define __RunWalkState_x                                           0xEA49C8
#define __ScreenMode_x                                             0xDEB1D8
#define __ScreenX_x                                                0xEA497C
#define __ScreenY_x                                                0xEA4978
#define __ScreenXMax_x                                             0xEA4980
#define __ScreenYMax_x                                             0xEA4984
#define __ServerHost_x                                             0xE9D59B
#define __ServerName_x                                             0xEDB20C
#define __ShiftKeyDown_x                                           0xEA5058
#define __ShowNames_x                                              0xEA5D98
#define EverQuestInfo__bSocialChanged_x                            0xEDB294
#define __Socials_x                                                0xEDB30C
#define __SubscriptionType_x                                       0xFA0410
#define __TargetAggroHolder_x                                      0xF5EB00
#define __ZoneType_x                                               0xEA4E58
#define __GroupAggro_x                                             0xF5EB40
#define __LoginName_x                                              0xF4BDCC
#define __Inviter_x                                                0xF436A8
#define __AttackOnAssist_x                                         0xEA5D54
#define __UseTellWindows_x                                         0xEA608C
#define __gfMaxZoomCameraDistance_x                                0xAED160
#define __gfMaxCameraDistance_x                                    0xB15DF8
#define __pulAutoRun_x                                             0xEA4A78
#define __pulForward_x                                             0xEA60C4
#define __pulBackward_x                                            0xEA60C8
#define __pulTurnRight_x                                           0xEA60CC
#define __pulTurnLeft_x                                            0xEA60D0
#define __pulStrafeLeft_x                                          0xEA60D4
#define __pulStrafeRight_x                                         0xEA60D8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9FCB0
#define instEQZoneInfo_x                                           0xEA4C50
#define pinstActiveBanker_x                                        0xE9D8B8
#define pinstActiveCorpse_x                                        0xE9D8B0
#define pinstActiveGMaster_x                                       0xE9D8B4
#define pinstActiveMerchant_x                                      0xE9D8AC
#define pinstAltAdvManager_x                                       0xDEBEE0
#define pinstBandageTarget_x                                       0xE9D8C8
#define pinstCamActor_x                                            0xDEB1C8
#define pinstCDBStr_x                                              0xDEABFC
#define pinstCDisplay_x                                            0xE9D914
#define pinstCEverQuest_x                                          0xF4B690
#define pinstEverQuestInfo_x                                       0xEA4970
#define pinstCharData_x                                            0xE9D3B8
#define pinstCharSpawn_x                                           0xE9D900
#define pinstControlledMissile_x                                   0xE9D910
#define pinstControlledPlayer_x                                    0xE9D900
#define pinstCResolutionHandler_x                                  0x15DB370
#define pinstCSidlManager_x                                        0x15DA308
#define pinstCXWndManager_x                                        0x15DA304
#define instDynamicZone_x                                          0xEA37F0
#define pinstDZMember_x                                            0xEA3900
#define pinstDZTimerInfo_x                                         0xEA3904
#define pinstEqLogin_x                                             0xF4B718
#define instEQMisc_x                                               0xDEAB40
#define pinstEQSoundManager_x                                      0xDECEB0
#define pinstEQSpellStrings_x                                      0xCAD448
#define instExpeditionLeader_x                                     0xEA383A
#define instExpeditionName_x                                       0xEA387A
#define pinstGroup_x                                               0xE9FA76
#define pinstImeManager_x                                          0x15DA300
#define pinstLocalPlayer_x                                         0xE9D6A4
#define pinstMercenaryData_x                                       0xF45D00
#define pinstMercenaryStats_x                                      0xF5EBCC
#define pinstModelPlayer_x                                         0xE9D8C0
#define pinstPCData_x                                              0xE9D3B8
#define pinstSkillMgr_x                                            0xF47E68
#define pinstSpawnManager_x                                        0xF46910
#define pinstSpellManager_x                                        0xF480A8
#define pinstSpellSets_x                                           0xF3C354
#define pinstStringTable_x                                         0xE9D3C0
#define pinstSwitchManager_x                                       0xE9D250
#define pinstTarget_x                                              0xE9D8FC
#define pinstTargetObject_x                                        0xE9D908
#define pinstTargetSwitch_x                                        0xE9D91C
#define pinstTaskMember_x                                          0xDEA9D0
#define pinstTrackTarget_x                                         0xE9D904
#define pinstTradeTarget_x                                         0xE9D8BC
#define instTributeActive_x                                        0xDEAB61
#define pinstViewActor_x                                           0xDEB1C4
#define pinstWorldData_x                                           0xE9D3B4
#define pinstZoneAddr_x                                            0xEA4EF0
#define pinstPlayerPath_x                                          0xF469A8
#define pinstTargetIndicator_x                                     0xF48310
#define EQObject_Top_x                                             0xE9D494
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEB500
#define pinstCAchievementsWnd_x                                    0xDEB174
#define pinstCActionsWnd_x                                         0xDEAC9C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDEB234
#define pinstCAdvancedLootWnd_x                                    0xDEB1E8
#define pinstCAdventureLeaderboardWnd_x                            0xF55920
#define pinstCAdventureRequestWnd_x                                0xF559D0
#define pinstCAdventureStatsWnd_x                                  0xF55A80
#define pinstCAggroMeterWnd_x                                      0xDEB21C
#define pinstCAlarmWnd_x                                           0xDEB1A0
#define pinstCAlertHistoryWnd_x                                    0xDEB4B4
#define pinstCAlertStackWnd_x                                      0xDEB204
#define pinstCAlertWnd_x                                           0xDEB218
#define pinstCAltStorageWnd_x                                      0xF55DE0
#define pinstCAudioTriggersWindow_x                                0xC9F778
#define pinstCAuraWnd_x                                            0xDEB1EC
#define pinstCAvaZoneWnd_x                                         0xDEB4B0
#define pinstCBandolierWnd_x                                       0xDEB230
#define pinstCBankWnd_x                                            0xDEB274
#define pinstCBarterMerchantWnd_x                                  0xF57020
#define pinstCBarterSearchWnd_x                                    0xF570D0
#define pinstCBarterWnd_x                                          0xF57180
#define pinstCBazaarConfirmationWnd_x                              0xDEB1B4
#define pinstCBazaarSearchWnd_x                                    0xDEB504
#define pinstCBazaarWnd_x                                          0xDEB180
#define pinstCBlockedBuffWnd_x                                     0xDEB1F8
#define pinstCBlockedPetBuffWnd_x                                  0xDEB220
#define pinstCBodyTintWnd_x                                        0xDEB128
#define pinstCBookWnd_x                                            0xDEB268
#define pinstCBreathWnd_x                                          0xDEB514
#define pinstCBuffWindowNORMAL_x                                   0xDEB1D4
#define pinstCBuffWindowSHORT_x                                    0xDEB1DC
#define pinstCBugReportWnd_x                                       0xDEB26C
#define pinstCButtonWnd_x                                          0x15DA570
#define pinstCCastingWnd_x                                         0xDEB25C
#define pinstCCastSpellWnd_x                                       0xDEB510
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEB134
#define pinstCChatWindowManager_x                                  0xF57C40
#define pinstCClaimWnd_x                                           0xF57D98
#define pinstCColorPickerWnd_x                                     0xDEB4C8
#define pinstCCombatAbilityWnd_x                                   0xDEB190
#define pinstCCombatSkillsSelectWnd_x                              0xDEB148
#define pinstCCompassWnd_x                                         0xDEAD14
#define pinstCConfirmationDialog_x                                 0xF5CC98
#define pinstCContainerMgr_x                                       0xDEB124
#define pinstCContextMenuManager_x                                 0x15DA2C0
#define pinstCCursorAttachment_x                                   0xDEB244
#define pinstCDynamicZoneWnd_x                                     0xF58360
#define pinstCEditLabelWnd_x                                       0xDEB1C0
#define pinstCEQMainWnd_x                                          0xF585A8
#define pinstCEventCalendarWnd_x                                   0xDEB508
#define pinstCExtendedTargetWnd_x                                  0xDEB200
#define pinstCFacePick_x                                           0xDEB14C
#define pinstCFactionWnd_x                                         0xDEB16C
#define pinstCFellowshipWnd_x                                      0xF587A8
#define pinstCFileSelectionWnd_x                                   0xDEB4C4
#define pinstCFindItemWnd_x                                        0xDEB15C
#define pinstCFindLocationWnd_x                                    0xF58900
#define pinstCFriendsWnd_x                                         0xDEB160
#define pinstCGemsGameWnd_x                                        0xDEB168
#define pinstCGiveWnd_x                                            0xDEB1A4
#define pinstCGroupSearchFiltersWnd_x                              0xDEB238
#define pinstCGroupSearchWnd_x                                     0xF58CF8
#define pinstCGroupWnd_x                                           0xF58DA8
#define pinstCGuildBankWnd_x                                       0xEA5D38
#define pinstCGuildCreationWnd_x                                   0xF58F08
#define pinstCGuildMgmtWnd_x                                       0xF58FB8
#define pinstCharacterCreation_x                                   0xDEB154
#define pinstCHelpWnd_x                                            0xDEB1A8
#define pinstCHeritageSelectionWnd_x                               0xDEB158
#define pinstCHotButtonWnd_x                                       0xF5B110
#define pinstCHotButtonWnd1_x                                      0xF5B110
#define pinstCHotButtonWnd2_x                                      0xF5B114
#define pinstCHotButtonWnd3_x                                      0xF5B118
#define pinstCHotButtonWnd4_x                                      0xF5B11C
#define pinstCIconSelectionWnd_x                                   0xDEB240
#define pinstCInspectWnd_x                                         0xDEB224
#define pinstCInventoryWnd_x                                       0xDEB1F0
#define pinstCInvSlotMgr_x                                         0xDEB4F4
#define pinstCItemDisplayManager_x                                 0xF5B6A0
#define pinstCItemExpTransferWnd_x                                 0xF5B7D4
#define pinstCItemOverflowWnd_x                                    0xDEB50C
#define pinstCJournalCatWnd_x                                      0xDEB4E0
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDEB4A0
#define pinstCKeyRingWnd_x                                         0xDEB24C
#define pinstCLargeDialogWnd_x                                     0xF5D918
#define pinstCLayoutCopyWnd_x                                      0xF5BB20
#define pinstCLFGuildWnd_x                                         0xF5BBD0
#define pinstCLoadskinWnd_x                                        0xDEB184
#define pinstCLootFiltersCopyWnd_x                                 0xCBBED8
#define pinstCLootFiltersWnd_x                                     0xDEB208
#define pinstCLootSettingsWnd_x                                    0xDEB22C
#define pinstCLootWnd_x                                            0xDEB4E4
#define pinstCMailAddressBookWnd_x                                 0xDEB4F8
#define pinstCMailCompositionWnd_x                                 0xDEB4D0
#define pinstCMailIgnoreListWnd_x                                  0xDEB4FC
#define pinstCMailWnd_x                                            0xDEB4D4
#define pinstCManageLootWnd_x                                      0xDEC390
#define pinstCMapToolbarWnd_x                                      0xDEB1B0
#define pinstCMapViewWnd_x                                         0xDEB178
#define pinstCMarketplaceWnd_x                                     0xDEB20C
#define pinstCMerchantWnd_x                                        0xDEB4F0
#define pinstCMIZoneSelectWnd_x                                    0xF5C408
#define pinstCMusicPlayerWnd_x                                     0xDEB4BC
#define pinstCNameChangeMercWnd_x                                  0xDEB1AC
#define pinstCNameChangePetWnd_x                                   0xDEB17C
#define pinstCNameChangeWnd_x                                      0xDEB1BC
#define pinstCNoteWnd_x                                            0xDEB188
#define pinstCObjectPreviewWnd_x                                   0xDEB228
#define pinstCOptionsWnd_x                                         0xDEB194
#define pinstCPetInfoWnd_x                                         0xDEB4B8
#define pinstCPetitionQWnd_x                                       0xDEB144
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDEB12C
#define pinstCPlayerWnd_x                                          0xDEB4AC
#define pinstCPopupWndManager_x                                    0xF5CC98
#define pinstCProgressionSelectionWnd_x                            0xF5CD48
#define pinstCPurchaseGroupWnd_x                                   0xDEB280
#define pinstCPurchaseWnd_x                                        0xDEB260
#define pinstCPvPLeaderboardWnd_x                                  0xF5CDF8
#define pinstCPvPStatsWnd_x                                        0xF5CEA8
#define pinstCQuantityWnd_x                                        0xDEB49C
#define pinstCRaceChangeWnd_x                                      0xDEB1F4
#define pinstCRaidOptionsWnd_x                                     0xDEB23C
#define pinstCRaidWnd_x                                            0xDEB4EC
#define pinstCRealEstateItemsWnd_x                                 0xDEB170
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEAD18
#define pinstCRealEstateManageWnd_x                                0xDEB284
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEB4A8
#define pinstCRealEstatePlotSearchWnd_x                            0xDEB4C0
#define pinstCRealEstatePurchaseWnd_x                              0xDEB4DC
#define pinstCRespawnWnd_x                                         0xDEB214
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDEB140
#define pinstCSendMoneyWnd_x                                       0xDEB1B8
#define pinstCServerListWnd_x                                      0xDEB4E8
#define pinstCSkillsSelectWnd_x                                    0xDEB13C
#define pinstCSkillsWnd_x                                          0xDEAD1C
#define pinstCSocialEditWnd_x                                      0xDEB248
#define pinstCSocialWnd_x                                          0xDEB198
#define pinstCSpellBookWnd_x                                       0xDEB18C
#define pinstCStoryWnd_x                                           0xDEAC98
#define pinstCTargetOfTargetWnd_x                                  0xF5EC50
#define pinstCTargetWnd_x                                          0xDEB210
#define pinstCTaskOverlayWnd_x                                     0xDEB278
#define pinstCTaskSelectWnd_x                                      0xF5EDA8
#define pinstCTaskManager_x                                        0xCBC818
#define pinstCTaskTemplateSelectWnd_x                              0xF5EE58
#define pinstCTaskWnd_x                                            0xF5EF08
#define pinstCTextEntryWnd_x                                       0xDEB264
#define pinstCTimeLeftWnd_x                                        0xDEB138
#define pinstCTipWndCONTEXT_x                                      0xF5F10C
#define pinstCTipWndOFDAY_x                                        0xF5F108
#define pinstCTitleWnd_x                                           0xF5F1B8
#define pinstCTrackingWnd_x                                        0xDEB1FC
#define pinstCTradeskillWnd_x                                      0xF5F320
#define pinstCTradeWnd_x                                           0xDEB130
#define pinstCTrainWnd_x                                           0xDEB4D8
#define pinstCTributeBenefitWnd_x                                  0xF5F520
#define pinstCTributeMasterWnd_x                                   0xF5F5D0
#define pinstCTributeTrophyWnd_x                                   0xF5F680
#define pinstCVideoModesWnd_x                                      0xDEB288
#define pinstCVoiceMacroWnd_x                                      0xF488C8
#define pinstCVoteResultsWnd_x                                     0xDEB164
#define pinstCVoteWnd_x                                            0xDEB150
#define pinstCWebManager_x                                         0xF48F44
#define pinstCZoneGuideWnd_x                                       0xDEB27C
#define pinstCZonePathWnd_x                                        0xDEB498

#define pinstEQSuiteTextureLoader_x                                0xC89B30
#define pinstItemIconCache_x                                       0xF58560
#define pinstLootFiltersManager_x                                  0xCBBF88
#define pinstRewardSelectionWnd_x                                  0xF5D5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C3590
#define __CastRay2_x                                               0x5C35E0
#define __ConvertItemTags_x                                        0x5DF2B0
#define __CleanItemTags_x                                          0x47D1A0
#define __DoesFileExist_x                                          0x8F9410
#define __EQGetTime_x                                              0x8F5FC0
#define __ExecuteCmd_x                                             0x5BBEC0
#define __FixHeading_x                                             0x98AD70
#define __FlushDxKeyboard_x                                        0x6AF1C0
#define __GameLoop_x                                               0x6B24F0
#define __get_bearing_x                                            0x5C30F0
#define __get_melee_range_x                                        0x5C37D0
#define __GetAnimationCache_x                                      0x717930
#define __GetGaugeValueFromEQ_x                                    0x809320
#define __GetLabelFromEQ_x                                         0x80AE00
#define __GetXTargetType_x                                         0x98C830
#define __HandleMouseWheel_x                                       0x6B33D0
#define __HeadingDiff_x                                            0x98ADE0
#define __HelpPath_x                                               0xF43DFC
#define __LoadFrontEnd_x                                           0x6AF800
#define __NewUIINI_x                                               0x808FF0
#define __ProcessGameEvents_x                                      0x624130
#define __ProcessMouseEvent_x                                      0x6238C0
#define __SaveColors_x                                             0x55CB90
#define __STMLToText_x                                             0x92E2E0
#define __ToggleKeyRingItem_x                                      0x51B200
#define CMemoryMappedFile__SetFile_x                               0xA7A180
#define CrashDetected_x                                            0x6B12B0
#define DrawNetStatus_x                                            0x650160
#define Expansion_HoT_x                                            0xEA5D40
#define Teleport_Table_Size_x                                      0xE9D454
#define Teleport_Table_x                                           0xE9D920
#define Util__FastTime_x                                           0x8F5B90
#define __CopyLayout_x                                             0x63E4A0
#define __WndProc_x                                                0x6B17B0
#define __ProcessKeyboardEvent_x                                   0x6B0D50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490470
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499470
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499240
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A10
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564CE0
#define AltAdvManager__IsAbilityReady_x                            0x563A80
#define AltAdvManager__GetAAById_x                                 0x563E10
#define AltAdvManager__CanTrainAbility_x                           0x563E80
#define AltAdvManager__CanSeeAbility_x                             0x5641E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAEF0
#define CharacterZoneClient__HasSkill_x                            0x4D5D70
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7490
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2670
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBB00
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9E10
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9EF0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9FD0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4760
#define CharacterZoneClient__BardCastBard_x                        0x4C7190
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF510
#define CharacterZoneClient__GetEffect_x                           0x4BBA40
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C57D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C58A0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C58F0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5A40
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5C20
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3A40
#define CharacterZoneClient__FindItemByGuid_x                      0x4D83F0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7E70

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8FA0
#define CBankWnd__WndNotification_x                                0x6D8D80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6A40

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92BAC0
#define CButtonWnd__CButtonWnd_x                                   0x92A6C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706AA0
#define CChatManager__InitContextMenu_x                            0x6FFBD0
#define CChatManager__FreeChatWindow_x                             0x7055E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9900
#define CChatManager__SetLockedActiveChatWindow_x                  0x706720
#define CChatManager__CreateChatWindow_x                           0x705C20

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9A10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93EC70
#define CContextMenu__dCContextMenu_x                              0x93EEB0
#define CContextMenu__AddMenuItem_x                                0x93EEC0
#define CContextMenu__RemoveMenuItem_x                             0x93F1D0
#define CContextMenu__RemoveAllMenuItems_x                         0x93F1F0
#define CContextMenu__CheckMenuItem_x                              0x93F270
#define CContextMenu__SetMenuItem_x                                0x93F0F0
#define CContextMenu__AddSeparator_x                               0x93F050

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93F810
#define CContextMenuManager__RemoveMenu_x                          0x93F880
#define CContextMenuManager__PopupMenu_x                           0x93F940
#define CContextMenuManager__Flush_x                               0x93F7B0
#define CContextMenuManager__GetMenu_x                             0x49B680
#define CContextMenuManager__CreateDefaultMenu_x                   0x712270

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D0D10
#define CChatService__GetFriendName_x                              0x8D0D20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7072E0
#define CChatWindow__Clear_x                                       0x7085A0
#define CChatWindow__WndNotification_x                             0x708D30
#define CChatWindow__AddHistory_x                                  0x707E60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93C0D0
#define CComboWnd__Draw_x                                          0x93B5C0
#define CComboWnd__GetCurChoice_x                                  0x93BF10
#define CComboWnd__GetListRect_x                                   0x93BA70
#define CComboWnd__GetTextRect_x                                   0x93C140
#define CComboWnd__InsertChoice_x                                  0x93BC00
#define CComboWnd__SetColors_x                                     0x93BBD0
#define CComboWnd__SetChoice_x                                     0x93BEE0
#define CComboWnd__GetItemCount_x                                  0x93BF20
#define CComboWnd__GetCurChoiceText_x                              0x93BF60
#define CComboWnd__GetChoiceText_x                                 0x93BF30
#define CComboWnd__InsertChoiceAtIndex_x                           0x93BCA0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70FC90
#define CContainerWnd__vftable_x                                   0xAFE73C
#define CContainerWnd__SetContainer_x                              0x7111E0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5574F0
#define CDisplay__PreZoneMainUI_x                                  0x557500
#define CDisplay__CleanGameUI_x                                    0x55C950
#define CDisplay__GetClickedActor_x                                0x54F950
#define CDisplay__GetUserDefinedColor_x                            0x547FC0
#define CDisplay__GetWorldFilePath_x                               0x5513C0
#define CDisplay__is3dON_x                                         0x54C5B0
#define CDisplay__ReloadUI_x                                       0x556A00
#define CDisplay__WriteTextHD2_x                                   0x54C3A0
#define CDisplay__TrueDistance_x                                   0x553080
#define CDisplay__SetViewActor_x                                   0x54F270
#define CDisplay__GetFloorHeight_x                                 0x54C670
#define CDisplay__SetRenderWindow_x                                0x54AFF0
#define CDisplay__ToggleScreenshotMode_x                           0x54ED40

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95EAC0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x942180
#define CEditWnd__EnsureCaretVisible_x                             0x944350
#define CEditWnd__GetCaretPt_x                                     0x943300
#define CEditWnd__GetCharIndexPt_x                                 0x9430B0
#define CEditWnd__GetDisplayString_x                               0x942F50
#define CEditWnd__GetHorzOffset_x                                  0x941820
#define CEditWnd__GetLineForPrintableChar_x                        0x944250
#define CEditWnd__GetSelStartPt_x                                  0x943360
#define CEditWnd__GetSTMLSafeText_x                                0x942D70
#define CEditWnd__PointFromPrintableChar_x                         0x943E80
#define CEditWnd__SelectableCharFromPoint_x                        0x943FF0
#define CEditWnd__SetEditable_x                                    0x943430
#define CEditWnd__SetWindowTextA_x                                 0x942AF0
#define CEditWnd__ReplaceSelection_x                               0x943AF0
#define CEditWnd__ReplaceSelection1_x                              0x943A70

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611740
#define CEverQuest__ClickedPlayer_x                                0x6038E0
#define CEverQuest__CreateTargetIndicator_x                        0x6212A0
#define CEverQuest__DeleteTargetIndicator_x                        0x621330
#define CEverQuest__DoTellWindow_x                                 0x4E9AF0
#define CEverQuest__OutputTextToLog_x                              0x4E9DC0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8A40
#define CEverQuest__dsp_chat_x                                     0x4EA150
#define CEverQuest__trimName_x                                     0x61D450
#define CEverQuest__Emote_x                                        0x611FA0
#define CEverQuest__EnterZone_x                                    0x60C0A0
#define CEverQuest__GetBodyTypeDesc_x                              0x6169F0
#define CEverQuest__GetClassDesc_x                                 0x617030
#define CEverQuest__GetClassThreeLetterCode_x                      0x617630
#define CEverQuest__GetDeityDesc_x                                 0x61FAF0
#define CEverQuest__GetLangDesc_x                                  0x6177F0
#define CEverQuest__GetRaceDesc_x                                  0x617010
#define CEverQuest__InterpretCmd_x                                 0x6200C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FCBD0
#define CEverQuest__LMouseUp_x                                     0x5FAF60
#define CEverQuest__RightClickedOnPlayer_x                         0x5FD4B0
#define CEverQuest__RMouseUp_x                                     0x5FBEE0
#define CEverQuest__SetGameState_x                                 0x5F87D0
#define CEverQuest__UPCNotificationFlush_x                         0x61D350
#define CEverQuest__IssuePetCommand_x                              0x618BF0
#define CEverQuest__ReportSuccessfulHit_x                          0x6132F0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7219E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x721A40
#define CGaugeWnd__Draw_x                                          0x721060

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFDD0
#define CGuild__GetGuildName_x                                     0x4AE880
#define CGuild__GetGuildIndex_x                                    0x4AEE80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B730

//CHotButton
#define CHotButton__SetCheck_x                                     0x632890
#define CHotButton__SetButtonSize_x                                0x632C50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748830
#define CInvSlotMgr__MoveItem_x                                    0x747500
#define CInvSlotMgr__SelectSlot_x                                  0x748900

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x745CF0
#define CInvSlot__SliderComplete_x                                 0x743A40
#define CInvSlot__GetItemBase_x                                    0x7433B0
#define CInvSlot__UpdateItem_x                                     0x743520

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74A390
#define CInvSlotWnd__CInvSlotWnd_x                                 0x749520
#define CInvSlotWnd__HandleLButtonUp_x                             0x749F10

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8046B0
#define CItemDisplayWnd__UpdateStrings_x                           0x758AF0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7527F0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752D00
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7590F0
#define CItemDisplayWnd__AboutToShow_x                             0x758740
#define CItemDisplayWnd__WndNotification_x                         0x75A370
#define CItemDisplayWnd__RequestConvertItem_x                      0x759CA0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7577B0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x758560

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8351F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E860

// CLabel 
#define CLabel__Draw_x                                             0x7642F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x914990
#define CListWnd__dCListWnd_x                                      0x914CB0
#define CListWnd__AddColumn_x                                      0x919130
#define CListWnd__AddColumn1_x                                     0x919180
#define CListWnd__AddLine_x                                        0x919510
#define CListWnd__AddString_x                                      0x919310
#define CListWnd__CalculateFirstVisibleLine_x                      0x918EF0
#define CListWnd__CalculateVSBRange_x                              0x918CD0
#define CListWnd__ClearSel_x                                       0x919CF0
#define CListWnd__ClearAllSel_x                                    0x919D50
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91A770
#define CListWnd__Compare_x                                        0x918600
#define CListWnd__Draw_x                                           0x914DE0
#define CListWnd__DrawColumnSeparators_x                           0x9175D0
#define CListWnd__DrawHeader_x                                     0x917A40
#define CListWnd__DrawItem_x                                       0x917F40
#define CListWnd__DrawLine_x                                       0x917740
#define CListWnd__DrawSeparator_x                                  0x917670
#define CListWnd__EnableLine_x                                     0x916EB0
#define CListWnd__EnsureVisible_x                                  0x91A690
#define CListWnd__ExtendSel_x                                      0x919C20
#define CListWnd__GetColumnTooltip_x                               0x9169F0
#define CListWnd__GetColumnMinWidth_x                              0x916A60
#define CListWnd__GetColumnWidth_x                                 0x916960
#define CListWnd__GetCurSel_x                                      0x9162F0
#define CListWnd__GetItemAtPoint_x                                 0x917130
#define CListWnd__GetItemAtPoint1_x                                0x9171A0
#define CListWnd__GetItemData_x                                    0x916370
#define CListWnd__GetItemHeight_x                                  0x916730
#define CListWnd__GetItemIcon_x                                    0x916500
#define CListWnd__GetItemRect_x                                    0x916FA0
#define CListWnd__GetItemText_x                                    0x9163B0
#define CListWnd__GetSelList_x                                     0x919DA0
#define CListWnd__GetSeparatorRect_x                               0x9173E0
#define CListWnd__InsertLine_x                                     0x919900
#define CListWnd__RemoveLine_x                                     0x919A50
#define CListWnd__SetColors_x                                      0x918CA0
#define CListWnd__SetColumnJustification_x                         0x9189D0
#define CListWnd__SetColumnLabel_x                                 0x9192B0
#define CListWnd__SetColumnWidth_x                                 0x9188F0
#define CListWnd__SetCurSel_x                                      0x919B60
#define CListWnd__SetItemColor_x                                   0x91A340
#define CListWnd__SetItemData_x                                    0x91A300
#define CListWnd__SetItemText_x                                    0x919F10
#define CListWnd__ShiftColumnSeparator_x                           0x918A90
#define CListWnd__Sort_x                                           0x918780
#define CListWnd__ToggleSel_x                                      0x919B90
#define CListWnd__SetColumnsSizable_x                              0x918B40
#define CListWnd__SetItemWnd_x                                     0x91A1C0
#define CListWnd__GetItemWnd_x                                     0x916550
#define CListWnd__SetItemIcon_x                                    0x919F90
#define CListWnd__CalculateCustomWindowPositions_x                 0x918FF0
#define CListWnd__SetVScrollPos_x                                  0x9188D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779B20
#define CMapViewWnd__GetWorldCoordinates_x                         0x778230
#define CMapViewWnd__HandleLButtonDown_x                           0x775270

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799F70
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A850
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79AD80
#define CMerchantWnd__SelectRecoverySlot_x                         0x79DD20
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x798AE0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A38F0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799B80

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E460
#define CPacketScrambler__hton_x                                   0x89E450

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9338D0
#define CSidlManager__FindScreenPieceTemplate_x                    0x933CE0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x933AD0
#define CSidlManager__CreateLabel_x                                0x7FB8D0
#define CSidlManager__CreateXWndFromTemplate_x                     0x936C40
#define CSidlManager__CreateXWndFromTemplate1_x                    0x936E20
#define CSidlManager__CreateXWnd_x                                 0x7FB800
#define CSidlManager__CreateHotButtonWnd_x                         0x7FBDC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x930390
#define CSidlScreenWnd__CalculateVSBRange_x                        0x930290
#define CSidlScreenWnd__ConvertToRes_x                             0x9595C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92FD80
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92FA70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92FB40
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92FC10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x930830
#define CSidlScreenWnd__EnableIniStorage_x                         0x930D00
#define CSidlScreenWnd__GetSidlPiece_x                             0x930A20
#define CSidlScreenWnd__Init1_x                                    0x92F670
#define CSidlScreenWnd__LoadIniInfo_x                              0x930D50
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9318B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92EA90
#define CSidlScreenWnd__StoreIniInfo_x                             0x931420
#define CSidlScreenWnd__StoreIniVis_x                              0x931790
#define CSidlScreenWnd__WndNotification_x                          0x930740
#define CSidlScreenWnd__GetChildItem_x                             0x930C80
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9205E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DA190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6984A0
#define CSkillMgr__GetSkillCap_x                                   0x698680
#define CSkillMgr__GetNameToken_x                                  0x697C20
#define CSkillMgr__IsActivatedSkill_x                              0x697D60
#define CSkillMgr__IsCombatSkill_x                                 0x697CA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x940600
#define CSliderWnd__SetValue_x                                     0x940470
#define CSliderWnd__SetNumTicks_x                                  0x9404D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8019C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x949020
#define CStmlWnd__ParseSTML_x                                      0x94A330
#define CStmlWnd__CalculateHSBRange_x                              0x94A100
#define CStmlWnd__CalculateVSBRange_x                              0x94A070
#define CStmlWnd__CanBreakAtCharacter_x                            0x94E440
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94F0D0
#define CStmlWnd__ForceParseNow_x                                  0x9495C0
#define CStmlWnd__GetNextTagPiece_x                                0x94E3A0
#define CStmlWnd__GetSTMLText_x                                    0x50CA10
#define CStmlWnd__GetVisibleText_x                                 0x9495E0
#define CStmlWnd__InitializeWindowVariables_x                      0x94EF20
#define CStmlWnd__MakeStmlColorTag_x                               0x948690
#define CStmlWnd__MakeWndNotificationTag_x                         0x948700
#define CStmlWnd__SetSTMLText_x                                    0x947740
#define CStmlWnd__StripFirstSTMLLines_x                            0x9501D0
#define CStmlWnd__UpdateHistoryString_x                            0x94F2E0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9467D0
#define CTabWnd__DrawCurrentPage_x                                 0x946F00
#define CTabWnd__DrawTab_x                                         0x946C20
#define CTabWnd__GetCurrentPage_x                                  0x945FD0
#define CTabWnd__GetPageInnerRect_x                                0x946210
#define CTabWnd__GetTabInnerRect_x                                 0x946150
#define CTabWnd__GetTabRect_x                                      0x946000
#define CTabWnd__InsertPage_x                                      0x946420
#define CTabWnd__RemovePage_x                                      0x946590
#define CTabWnd__SetPage_x                                         0x946290
#define CTabWnd__SetPageRect_x                                     0x946710
#define CTabWnd__UpdatePage_x                                      0x946AE0
#define CTabWnd__GetPageFromTabIndex_x                             0x946B60
#define CTabWnd__GetCurrentTabIndex_x                              0x945FC0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75EC70
#define CPageWnd__SetTabText_x                                     0x945B10
#define CPageWnd__FlashTab_x                                       0x945B70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A90A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91D490
#define CTextureFont__GetTextExtent_x                              0x91D650

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC660
#define CHtmlComponentWnd__ValidateUri_x                           0x73D120
#define CHtmlWnd__SetClientCallbacks_x                             0x637CD0
#define CHtmlWnd__AddObserver_x                                    0x637CF0
#define CHtmlWnd__RemoveObserver_x                                 0x637D50
#define Window__getProgress_x                                      0x853B50
#define Window__getStatus_x                                        0x853B70
#define Window__getURI_x                                           0x853B80

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x956390

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90A570

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9740
#define CXStr__CXStr1_x                                            0x5C11F0
#define CXStr__CXStr3_x                                            0x8F1F40
#define CXStr__dCXStr_x                                            0x4783B0
#define CXStr__operator_equal_x                                    0x8F2170
#define CXStr__operator_equal1_x                                   0x8F21B0
#define CXStr__operator_plus_equal1_x                              0x8F2C40
#define CXStr__SetString_x                                         0x8F4B30
#define CXStr__operator_char_p_x                                   0x8F2680
#define CXStr__GetChar_x                                           0x8F4480
#define CXStr__Delete_x                                            0x8F3D30
#define CXStr__GetUnicode_x                                        0x8F44F0
#define CXStr__GetLength_x                                         0x4A8E50
#define CXStr__Mid_x                                               0x47D550
#define CXStr__Insert_x                                            0x8F4550
#define CXStr__FindNext_x                                          0x8F41A0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93E890
#define CXWnd__BringToTop_x                                        0x923D40
#define CXWnd__Center_x                                            0x9238C0
#define CXWnd__ClrFocus_x                                          0x9236D0
#define CXWnd__Destroy_x                                           0x923780
#define CXWnd__DoAllDrawing_x                                      0x91FD90
#define CXWnd__DrawChildren_x                                      0x91FD60
#define CXWnd__DrawColoredRect_x                                   0x9201F0
#define CXWnd__DrawTooltip_x                                       0x91E890
#define CXWnd__DrawTooltipAtPoint_x                                0x91E950
#define CXWnd__GetBorderFrame_x                                    0x920050
#define CXWnd__GetChildWndAt_x                                     0x923DE0
#define CXWnd__GetClientClipRect_x                                 0x921FC0
#define CXWnd__GetScreenClipRect_x                                 0x922090
#define CXWnd__GetScreenRect_x                                     0x922250
#define CXWnd__GetRelativeRect_x                                   0x922310
#define CXWnd__GetTooltipRect_x                                    0x920240
#define CXWnd__GetWindowTextA_x                                    0x49CDA0
#define CXWnd__IsActive_x                                          0x920950
#define CXWnd__IsDescendantOf_x                                    0x922C50
#define CXWnd__IsReallyVisible_x                                   0x922C80
#define CXWnd__IsType_x                                            0x924460
#define CXWnd__Move_x                                              0x922CE0
#define CXWnd__Move1_x                                             0x922D90
#define CXWnd__ProcessTransition_x                                 0x923870
#define CXWnd__Refade_x                                            0x923060
#define CXWnd__Resize_x                                            0x9232F0
#define CXWnd__Right_x                                             0x923B00
#define CXWnd__SetFocus_x                                          0x923690
#define CXWnd__SetFont_x                                           0x923700
#define CXWnd__SetKeyTooltip_x                                     0x924270
#define CXWnd__SetMouseOver_x                                      0x921170
#define CXWnd__StartFade_x                                         0x922B30
#define CXWnd__GetChildItem_x                                      0x923F50
#define CXWnd__SetParent_x                                         0x9229F0
#define CXWnd__Minimize_x                                          0x923360

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95A640

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x926C50
#define CXWndManager__DrawWindows_x                                0x926C70
#define CXWndManager__GetKeyboardFlags_x                           0x929340
#define CXWndManager__HandleKeyboardMsg_x                          0x928EF0
#define CXWndManager__RemoveWnd_x                                  0x929570
#define CXWndManager__RemovePendingDeletionWnd_x                   0x929AE0

// CDBStr
#define CDBStr__GetString_x                                        0x546F60

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFC70
#define EQ_Character__Cur_HP_x                                     0x4D2DB0
#define EQ_Character__Cur_Mana_x                                   0x4DA4D0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2CE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3680
#define EQ_Character__GetFocusRangeModifier_x                      0x4B37D0
#define EQ_Character__GetHPRegen_x                                 0x4E03A0
#define EQ_Character__GetEnduranceRegen_x                          0x4E09A0
#define EQ_Character__GetManaRegen_x                               0x4E0DE0
#define EQ_Character__Max_Endurance_x                              0x65EAC0
#define EQ_Character__Max_HP_x                                     0x4D2BE0
#define EQ_Character__Max_Mana_x                                   0x65E8C0
#define EQ_Character__doCombatAbility_x                            0x660EB0
#define EQ_Character__UseSkill_x                                   0x4E2BE0
#define EQ_Character__GetConLevel_x                                0x657050
#define EQ_Character__IsExpansionFlag_x                            0x5BA6C0
#define EQ_Character__TotalEffect_x                                0x4C6A80
#define EQ_Character__GetPCSpellAffect_x                           0x4C3A30
#define EQ_Character__SpellDuration_x                              0x4C3560
#define EQ_Character__MySpellDuration_x                            0x4B1FB0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5B30
#define EQ_Character__GetBaseSkill_x                               0x4D6AD0
#define EQ_Character__CanUseItem_x                                 0x4DA7E0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BDBA0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x674DE0

//PcClient
#define PcClient__vftable_x                                        0xAF21C0
#define PcClient__PcClient_x                                       0x6547C0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA6B0
#define CCharacterListWnd__EnterWorld_x                            0x4BA080
#define CCharacterListWnd__Quit_x                                  0x4B9DD0
#define CCharacterListWnd__UpdateList_x                            0x4BA270

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x638EC0
#define EQ_Item__CreateItemTagString_x                             0x8979B0
#define EQ_Item__IsStackable_x                                     0x89C6B0
#define EQ_Item__GetImageNum_x                                     0x899550
#define EQ_Item__CreateItemClient_x                                0x6380E0
#define EQ_Item__GetItemValue_x                                    0x89A860
#define EQ_Item__ValueSellMerchant_x                               0x89E040
#define EQ_Item__IsKeyRingItem_x                                   0x89BFD0
#define EQ_Item__CanGoInBag_x                                      0x638FE0
#define EQ_Item__IsEmpty_x                                         0x89BB10
#define EQ_Item__GetMaxItemCount_x                                 0x89AC70
#define EQ_Item__GetHeldItem_x                                     0x899420
#define EQ_Item__GetAugmentFitBySlot_x                             0x897210

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565A40
#define EQ_LoadingS__Array_x                                       0xC13128

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65F3C0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A74D0
#define EQ_PC__GetCombatAbility_x                                  0x8A7B40
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7BB0
#define EQ_PC__GetItemRecastTimer_x                                0x661430
#define EQ_PC__HasLoreItem_x                                       0x657870
#define EQ_PC__AlertInventoryChanged_x                             0x656990
#define EQ_PC__GetPcZoneClient_x                                   0x683E30
#define EQ_PC__RemoveMyAffect_x                                    0x664660
#define EQ_PC__GetKeyRingItems_x                                   0x8A8480
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A8200
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8780

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C0B20
#define EQItemList__add_object_x                                   0x5EE210
#define EQItemList__add_item_x                                     0x5C1080
#define EQItemList__delete_item_x                                  0x5C10D0
#define EQItemList__FreeItemList_x                                 0x5C0FD0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543B00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6766E0
#define EQPlayer__dEQPlayer_x                                      0x669A70
#define EQPlayer__DoAttack_x                                       0x67E5D0
#define EQPlayer__EQPlayer_x                                       0x66A130
#define EQPlayer__SetNameSpriteState_x                             0x66E3F0
#define EQPlayer__SetNameSpriteTint_x                              0x66F2D0
#define PlayerBase__HasProperty_j_x                                0x989180
#define EQPlayer__IsTargetable_x                                   0x989620
#define EQPlayer__CanSee_x                                         0x989480
#define EQPlayer__CanSee1_x                                        0x989550
#define PlayerBase__GetVisibilityLineSegment_x                     0x989240

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6818D0
#define PlayerZoneClient__GetLevel_x                               0x683E70
#define PlayerZoneClient__IsValidTeleport_x                        0x5EF380
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E7E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6794C0
#define EQPlayerManager__GetSpawnByName_x                          0x679570
#define EQPlayerManager__GetPlayerFromPartialName_x                0x679600

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C700
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C780
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C7C0
#define KeypressHandler__ClearCommandStateArray_x                  0x63DBB0
#define KeypressHandler__HandleKeyDown_x                           0x63DBD0
#define KeypressHandler__HandleKeyUp_x                             0x63DC70
#define KeypressHandler__SaveKeymapping_x                          0x63E0C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x775990
#define MapViewMap__SaveEx_x                                       0x778D50
#define MapViewMap__SetZoom_x                                      0x77D410

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BBB50

// StringTable 
#define StringTable__getString_x                                   0x8B6A00

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6642D0
#define PcZoneClient__RemovePetEffect_x                            0x664900
#define PcZoneClient__HasAlternateAbility_x                        0x65E6F0
#define PcZoneClient__GetCurrentMod_x                              0x4E5D00
#define PcZoneClient__GetModCap_x                                  0x4E5C00
#define PcZoneClient__CanEquipItem_x                               0x65EDA0
#define PcZoneClient__GetItemByID_x                                0x6618A0
#define PcZoneClient__GetItemByItemClass_x                         0x6619F0
#define PcZoneClient__RemoveBuffEffect_x                           0x664920
#define PcZoneClient__BandolierSwap_x                              0x65F980
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6613D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F3F00

//IconCache
#define IconCache__GetIcon_x                                       0x717330

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70EE30
#define CContainerMgr__CloseContainer_x                            0x70F100
#define CContainerMgr__OpenExperimentContainer_x                   0x70FB80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CE170

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631070

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76BDA0
#define CLootWnd__RequestLootSlot_x                                0x76B080

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D160
#define EQ_Spell__SpellAffects_x                                   0x58D5D0
#define EQ_Spell__SpellAffectBase_x                                0x58D390
#define EQ_Spell__IsStackable_x                                    0x4CA800
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA620
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7960
#define EQ_Spell__IsSPAStacking_x                                  0x58E420
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58D930
#define EQ_Spell__IsNoRemove_x                                     0x4CA7E0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E430
#define __IsResEffectSpell_x                                       0x4C9AD0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD2F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C62D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814D90
#define CTargetWnd__WndNotification_x                              0x8145D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8148A0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813740

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x819400
#define CTaskWnd__ConfirmAbandonTask_x                             0x81C040

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x541520
#define CTaskManager__HandleMessage_x                              0x53F990
#define CTaskManager__GetTaskStatus_x                              0x5415D0
#define CTaskManager__GetElementDescription_x                      0x541650

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5882A0
#define EqSoundManager__PlayScriptMp3_x                            0x588560
#define EqSoundManager__SoundAssistPlay_x                          0x69C450
#define EqSoundManager__WaveInstancePlay_x                         0x69B9C0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532900

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x945020
#define CTextureAnimation__Draw_x                                  0x945220

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x940F60

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D520
#define CAltAbilityData__GetMercMaxRank_x                          0x56D4B0
#define CAltAbilityData__GetMaxRank_x                              0x562900

//CTargetRing
#define CTargetRing__Cast_x                                        0x62F190

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA600
#define CharacterBase__CreateItemGlobalIndex_x                     0x519310
#define CharacterBase__CreateItemIndex_x                           0x637280
#define CharacterBase__GetItemPossession_x                         0x505370
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE910
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE970
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5E30
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6660
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6710

//messages
#define msg_spell_worn_off_x                                       0x5B2720
#define msg_new_text_x                                             0x5A70C0
#define __msgTokenTextParam_x                                      0x5B49C0
#define msgTokenText_x                                             0x5B4C10

//SpellManager
#define SpellManager__vftable_x                                    0xADA54C
#define SpellManager__SpellManager_x                               0x69F780
#define Spellmanager__LoadTextSpells_x                             0x6A0070
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F950

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98D130

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519990
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8B80
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64FFC0
#define ItemGlobalIndex__IsValidIndex_x                            0x519A20

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C6C70
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6EF0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764630

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x713510
#define CCursorAttachment__AttachToCursor1_x                       0x713550
#define CCursorAttachment__Deactivate_x                            0x714540

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x937C70
#define CSidlManagerBase__CreatePageWnd_x                          0x937470
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9336F0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933680

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x954F40
#define CEQSuiteTextureLoader__GetTexture_x                        0x954C00

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516860
#define CFindItemWnd__WndNotification_x                            0x517340
#define CFindItemWnd__Update_x                                     0x517EB0
#define CFindItemWnd__PickupSelectedItem_x                         0x516090

//IString
#define IString__Append_x                                          0x506BC0

//Camera
#define CDisplay__cameraType_x                                     0xDEB290
#define EverQuest__Cameras_x                                       0xEA6098

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F380
#define LootFiltersManager__GetItemFilterData_x                    0x51EC80
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51ECB0
#define LootFiltersManager__SetItemLootFilter_x                    0x51EED0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BBF00

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x992D80
#define CResolutionHandler__GetWindowedStyle_x                     0x696E50

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70BA50

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DC310
#define CDistillerInfo__Instance_x                                 0x8DC2B0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A9C0
#define CGroupWnd__UpdateDisplay_x                                 0x729D10

//ItemBase
#define ItemBase__IsLore_x                                         0x89C080
#define ItemBase__IsLoreEquipped_x                                 0x89C0F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EE170
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EE2B0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EE310

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C570
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68FEE0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D010

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9110
#define FactionManagerClient__HandleFactionMessage_x               0x4F9780
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F9D80
#define FactionManagerClient__GetMaxFaction_x                      0x4F9D9F
#define FactionManagerClient__GetMinFaction_x                      0x4F9D50

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505340

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91C410

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C080

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5055D0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56C9A0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2FD0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C570

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E60

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C0F70

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF43730

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF730
#define CAAWnd__UpdateSelected_x                                   0x6BBFA0
#define CAAWnd__Update_x                                           0x6BEA50

//CXRect
#define CXRect__operator_and_x                                     0x721AA0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4831E0

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
