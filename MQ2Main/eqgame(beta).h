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
#define __ExpectedVersionDate                                     "Nov 15 2020"
#define __ExpectedVersionTime                                     "04:17:02"
#define __ActualVersionDate_x                                      0xAF555C
#define __ActualVersionTime_x                                      0xAF5550
#define __ActualVersionBuild_x                                     0xAE355C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642B50
#define __MemChecker1_x                                            0x8F5940
#define __MemChecker2_x                                            0x6B2F90
#define __MemChecker3_x                                            0x6B2EE0
#define __MemChecker4_x                                            0x84BB20
#define __EncryptPad0_x                                            0xC2B9C8
#define __EncryptPad1_x                                            0xC89210
#define __EncryptPad2_x                                            0xC3BD90
#define __EncryptPad3_x                                            0xC3B990
#define __EncryptPad4_x                                            0xC797A0
#define __EncryptPad5_x                                            0xF4B650
#define __AC1_x                                                    0x80A4D6
#define __AC2_x                                                    0x5FC0AF
#define __AC3_x                                                    0x603700
#define __AC4_x                                                    0x6076B0
#define __AC5_x                                                    0x60D9AF
#define __AC6_x                                                    0x611E66
#define __AC7_x                                                    0x5FBB20
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
#define __do_loot_x                                                0x5C7BC0
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
#define __gfMaxZoomCameraDistance_x                                0xAED178
#define __gfMaxCameraDistance_x                                    0xB15DF0
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
#define __CastRay_x                                                0x5C32B0
#define __CastRay2_x                                               0x5C3300
#define __ConvertItemTags_x                                        0x5DEFD0
#define __CleanItemTags_x                                          0x47D470
#define __DoesFileExist_x                                          0x8F8970
#define __EQGetTime_x                                              0x8F5570
#define __ExecuteCmd_x                                             0x5BBB90
#define __FixHeading_x                                             0x98B1A0
#define __FlushDxKeyboard_x                                        0x6AEE30
#define __GameLoop_x                                               0x6B2160
#define __get_bearing_x                                            0x5C2E10
#define __get_melee_range_x                                        0x5C34F0
#define __GetAnimationCache_x                                      0x7174F0
#define __GetGaugeValueFromEQ_x                                    0x808980
#define __GetLabelFromEQ_x                                         0x80A460
#define __GetXTargetType_x                                         0x98CC60
#define __HandleMouseWheel_x                                       0x6B3040
#define __HeadingDiff_x                                            0x98B210
#define __HelpPath_x                                               0xF43DFC
#define __LoadFrontEnd_x                                           0x6AF470
#define __NewUIINI_x                                               0x808650
#define __ProcessGameEvents_x                                      0x623D40
#define __ProcessMouseEvent_x                                      0x6234D0
#define __SaveColors_x                                             0x55CDD0
#define __STMLToText_x                                             0x92E6F0
#define __ToggleKeyRingItem_x                                      0x51B390
#define CMemoryMappedFile__SetFile_x                               0xA7A4E0
#define CrashDetected_x                                            0x6B0F20
#define DrawNetStatus_x                                            0x64FE80
#define Expansion_HoT_x                                            0xEA5D40
#define Teleport_Table_Size_x                                      0xE9D454
#define Teleport_Table_x                                           0xE9D920
#define Util__FastTime_x                                           0x8F5140
#define __CopyLayout_x                                             0x63E250
#define __WndProc_x                                                0x6B1420
#define __ProcessKeyboardEvent_x                                   0x6B09C0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490630
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499610
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4993E0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493BD0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493020

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564F90
#define AltAdvManager__IsAbilityReady_x                            0x563D30
#define AltAdvManager__GetAAById_x                                 0x5640C0
#define AltAdvManager__CanTrainAbility_x                           0x564130
#define AltAdvManager__CanSeeAbility_x                             0x564490

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB250
#define CharacterZoneClient__HasSkill_x                            0x4D60D0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D77F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2A70
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBF00
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA1A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA280
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA360
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4B60
#define CharacterZoneClient__BardCastBard_x                        0x4C7590
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF910
#define CharacterZoneClient__GetEffect_x                           0x4BBE40
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5BD0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5CA0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5CF0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5E40
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C6020
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3E10
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8750
#define CharacterZoneClient__FindItemByRecord_x                    0x4D81D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8C50
#define CBankWnd__WndNotification_x                                0x6D8A30

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6620

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92BED0
#define CButtonWnd__CButtonWnd_x                                   0x92AAF0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706740
#define CChatManager__InitContextMenu_x                            0x6FF880
#define CChatManager__FreeChatWindow_x                             0x705280
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9C00
#define CChatManager__SetLockedActiveChatWindow_x                  0x7063C0
#define CChatManager__CreateChatWindow_x                           0x7058C0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9D10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93F190
#define CContextMenu__dCContextMenu_x                              0x93F3C0
#define CContextMenu__AddMenuItem_x                                0x93F3D0
#define CContextMenu__RemoveMenuItem_x                             0x93F6D0
#define CContextMenu__RemoveAllMenuItems_x                         0x93F6F0
#define CContextMenu__CheckMenuItem_x                              0x93F770
#define CContextMenu__SetMenuItem_x                                0x93F600
#define CContextMenu__AddSeparator_x                               0x93F560

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93FD10
#define CContextMenuManager__RemoveMenu_x                          0x93FD80
#define CContextMenuManager__PopupMenu_x                           0x93FE40
#define CContextMenuManager__Flush_x                               0x93FCB0
#define CContextMenuManager__GetMenu_x                             0x49B890
#define CContextMenuManager__CreateDefaultMenu_x                   0x711E50

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D0250
#define CChatService__GetFriendName_x                              0x8D0260

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x706F70
#define CChatWindow__Clear_x                                       0x708230
#define CChatWindow__WndNotification_x                             0x7089C0
#define CChatWindow__AddHistory_x                                  0x707AF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93C600
#define CComboWnd__Draw_x                                          0x93BB00
#define CComboWnd__GetCurChoice_x                                  0x93C440
#define CComboWnd__GetListRect_x                                   0x93BFB0
#define CComboWnd__GetTextRect_x                                   0x93C660
#define CComboWnd__InsertChoice_x                                  0x93C140
#define CComboWnd__SetColors_x                                     0x93C110
#define CComboWnd__SetChoice_x                                     0x93C410
#define CComboWnd__GetItemCount_x                                  0x93C450
#define CComboWnd__GetCurChoiceText_x                              0x93C490
#define CComboWnd__GetChoiceText_x                                 0x93C460
#define CComboWnd__InsertChoiceAtIndex_x                           0x93C1D0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70F880
#define CContainerWnd__vftable_x                                   0xAFE74C
#define CContainerWnd__SetContainer_x                              0x710DE0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x557730
#define CDisplay__PreZoneMainUI_x                                  0x557740
#define CDisplay__CleanGameUI_x                                    0x55CB90
#define CDisplay__GetClickedActor_x                                0x54FB90
#define CDisplay__GetUserDefinedColor_x                            0x548200
#define CDisplay__GetWorldFilePath_x                               0x551600
#define CDisplay__is3dON_x                                         0x54C7F0
#define CDisplay__ReloadUI_x                                       0x556C40
#define CDisplay__WriteTextHD2_x                                   0x54C5E0
#define CDisplay__TrueDistance_x                                   0x5532C0
#define CDisplay__SetViewActor_x                                   0x54F4B0
#define CDisplay__GetFloorHeight_x                                 0x54C8B0
#define CDisplay__SetRenderWindow_x                                0x54B230
#define CDisplay__ToggleScreenshotMode_x                           0x54EF80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95EFD0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x942680
#define CEditWnd__EnsureCaretVisible_x                             0x944840
#define CEditWnd__GetCaretPt_x                                     0x9437F0
#define CEditWnd__GetCharIndexPt_x                                 0x9435A0
#define CEditWnd__GetDisplayString_x                               0x943440
#define CEditWnd__GetHorzOffset_x                                  0x941D20
#define CEditWnd__GetLineForPrintableChar_x                        0x944740
#define CEditWnd__GetSelStartPt_x                                  0x943850
#define CEditWnd__GetSTMLSafeText_x                                0x943260
#define CEditWnd__PointFromPrintableChar_x                         0x944370
#define CEditWnd__SelectableCharFromPoint_x                        0x9444E0
#define CEditWnd__SetEditable_x                                    0x943920
#define CEditWnd__SetWindowTextA_x                                 0x942FE0
#define CEditWnd__ReplaceSelection_x                               0x943FE0
#define CEditWnd__ReplaceSelection1_x                              0x943F60

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611340
#define CEverQuest__ClickedPlayer_x                                0x6034E0
#define CEverQuest__CreateTargetIndicator_x                        0x620EB0
#define CEverQuest__DeleteTargetIndicator_x                        0x620F40
#define CEverQuest__DoTellWindow_x                                 0x4E9DF0
#define CEverQuest__OutputTextToLog_x                              0x4EA0C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8630
#define CEverQuest__dsp_chat_x                                     0x4EA450
#define CEverQuest__trimName_x                                     0x61D060
#define CEverQuest__Emote_x                                        0x611BA0
#define CEverQuest__EnterZone_x                                    0x60BCA0
#define CEverQuest__GetBodyTypeDesc_x                              0x6165F0
#define CEverQuest__GetClassDesc_x                                 0x616C30
#define CEverQuest__GetClassThreeLetterCode_x                      0x617230
#define CEverQuest__GetDeityDesc_x                                 0x61F700
#define CEverQuest__GetLangDesc_x                                  0x6173F0
#define CEverQuest__GetRaceDesc_x                                  0x616C10
#define CEverQuest__InterpretCmd_x                                 0x61FCD0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FC7D0
#define CEverQuest__LMouseUp_x                                     0x5FAB50
#define CEverQuest__RightClickedOnPlayer_x                         0x5FD0B0
#define CEverQuest__RMouseUp_x                                     0x5FBAE0
#define CEverQuest__SetGameState_x                                 0x5F83C0
#define CEverQuest__UPCNotificationFlush_x                         0x61CF60
#define CEverQuest__IssuePetCommand_x                              0x618800
#define CEverQuest__ReportSuccessfulHit_x                          0x612EF0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x721410
#define CGaugeWnd__CalcLinesFillRect_x                             0x721470
#define CGaugeWnd__Draw_x                                          0x720A90

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B0180
#define CGuild__GetGuildName_x                                     0x4AEC30
#define CGuild__GetGuildIndex_x                                    0x4AF230

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B020

//CHotButton
#define CHotButton__SetCheck_x                                     0x632680
#define CHotButton__SetButtonSize_x                                0x632A40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748100
#define CInvSlotMgr__MoveItem_x                                    0x746E20
#define CInvSlotMgr__SelectSlot_x                                  0x7481D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x745610
#define CInvSlot__SliderComplete_x                                 0x743350
#define CInvSlot__GetItemBase_x                                    0x742CE0
#define CInvSlot__UpdateItem_x                                     0x742E50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x749C60
#define CInvSlotWnd__CInvSlotWnd_x                                 0x748DF0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7497E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x803D10
#define CItemDisplayWnd__UpdateStrings_x                           0x758410
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7520D0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7525F0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x758A20
#define CItemDisplayWnd__AboutToShow_x                             0x758060
#define CItemDisplayWnd__WndNotification_x                         0x759C80
#define CItemDisplayWnd__RequestConvertItem_x                      0x7595C0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7570C0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x757E80

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834780

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E1D0

// CLabel 
#define CLabel__Draw_x                                             0x763C70

// CListWnd
#define CListWnd__CListWnd_x                                       0x914E40
#define CListWnd__dCListWnd_x                                      0x915160
#define CListWnd__AddColumn_x                                      0x9195A0
#define CListWnd__AddColumn1_x                                     0x9195F0
#define CListWnd__AddLine_x                                        0x919980
#define CListWnd__AddString_x                                      0x919780
#define CListWnd__CalculateFirstVisibleLine_x                      0x919360
#define CListWnd__CalculateVSBRange_x                              0x919150
#define CListWnd__ClearSel_x                                       0x91A160
#define CListWnd__ClearAllSel_x                                    0x91A1C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91ABB0
#define CListWnd__Compare_x                                        0x918A80
#define CListWnd__Draw_x                                           0x915290
#define CListWnd__DrawColumnSeparators_x                           0x917A50
#define CListWnd__DrawHeader_x                                     0x917EC0
#define CListWnd__DrawItem_x                                       0x9183C0
#define CListWnd__DrawLine_x                                       0x917BC0
#define CListWnd__DrawSeparator_x                                  0x917AF0
#define CListWnd__EnableLine_x                                     0x917340
#define CListWnd__EnsureVisible_x                                  0x91AAE0
#define CListWnd__ExtendSel_x                                      0x91A090
#define CListWnd__GetColumnTooltip_x                               0x916E80
#define CListWnd__GetColumnMinWidth_x                              0x916EF0
#define CListWnd__GetColumnWidth_x                                 0x916DF0
#define CListWnd__GetCurSel_x                                      0x916780
#define CListWnd__GetItemAtPoint_x                                 0x9175B0
#define CListWnd__GetItemAtPoint1_x                                0x917620
#define CListWnd__GetItemData_x                                    0x916800
#define CListWnd__GetItemHeight_x                                  0x916BC0
#define CListWnd__GetItemIcon_x                                    0x916990
#define CListWnd__GetItemRect_x                                    0x917430
#define CListWnd__GetItemText_x                                    0x916840
#define CListWnd__GetSelList_x                                     0x91A210
#define CListWnd__GetSeparatorRect_x                               0x917860
#define CListWnd__InsertLine_x                                     0x919D70
#define CListWnd__RemoveLine_x                                     0x919EC0
#define CListWnd__SetColors_x                                      0x919120
#define CListWnd__SetColumnJustification_x                         0x918E50
#define CListWnd__SetColumnLabel_x                                 0x919720
#define CListWnd__SetColumnWidth_x                                 0x918D70
#define CListWnd__SetCurSel_x                                      0x919FD0
#define CListWnd__SetItemColor_x                                   0x91A7A0
#define CListWnd__SetItemData_x                                    0x91A760
#define CListWnd__SetItemText_x                                    0x91A380
#define CListWnd__ShiftColumnSeparator_x                           0x918F10
#define CListWnd__Sort_x                                           0x918C00
#define CListWnd__ToggleSel_x                                      0x91A000
#define CListWnd__SetColumnsSizable_x                              0x918FC0
#define CListWnd__SetItemWnd_x                                     0x91A630
#define CListWnd__GetItemWnd_x                                     0x9169E0
#define CListWnd__SetItemIcon_x                                    0x91A400
#define CListWnd__CalculateCustomWindowPositions_x                 0x919460
#define CListWnd__SetVScrollPos_x                                  0x918D50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7792B0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7779C0
#define CMapViewWnd__HandleLButtonDown_x                           0x774A00

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799660
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x799F40
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79A470
#define CMerchantWnd__SelectRecoverySlot_x                         0x79D420
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7981D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A3000
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799270

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89DA20
#define CPacketScrambler__hton_x                                   0x89DA10

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x933CB0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9340C0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x933EB0
#define CSidlManager__CreateLabel_x                                0x7FAFA0
#define CSidlManager__CreateXWndFromTemplate_x                     0x937020
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9371F0
#define CSidlManager__CreateXWnd_x                                 0x7FAED0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FB470

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x930780
#define CSidlScreenWnd__CalculateVSBRange_x                        0x930680
#define CSidlScreenWnd__ConvertToRes_x                             0x959AC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930180
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92FE70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92FF40
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x930010
#define CSidlScreenWnd__DrawSidlPiece_x                            0x930C20
#define CSidlScreenWnd__EnableIniStorage_x                         0x9310F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x930E10
#define CSidlScreenWnd__Init1_x                                    0x92FA90
#define CSidlScreenWnd__LoadIniInfo_x                              0x931140
#define CSidlScreenWnd__LoadIniListWnd_x                           0x931C90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92EEA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x931800
#define CSidlScreenWnd__StoreIniVis_x                              0x931B70
#define CSidlScreenWnd__WndNotification_x                          0x930B30
#define CSidlScreenWnd__GetChildItem_x                             0x931070
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9209A0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DA190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x698180
#define CSkillMgr__GetSkillCap_x                                   0x698360
#define CSkillMgr__GetNameToken_x                                  0x697900
#define CSkillMgr__IsActivatedSkill_x                              0x697A40
#define CSkillMgr__IsCombatSkill_x                                 0x697980

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x940B00
#define CSliderWnd__SetValue_x                                     0x940970
#define CSliderWnd__SetNumTicks_x                                  0x9409D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8010A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x949420
#define CStmlWnd__ParseSTML_x                                      0x94A720
#define CStmlWnd__CalculateHSBRange_x                              0x94A500
#define CStmlWnd__CalculateVSBRange_x                              0x94A470
#define CStmlWnd__CanBreakAtCharacter_x                            0x94E840
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94F4D0
#define CStmlWnd__ForceParseNow_x                                  0x9499C0
#define CStmlWnd__GetNextTagPiece_x                                0x94E7A0
#define CStmlWnd__GetSTMLText_x                                    0x50CC60
#define CStmlWnd__GetVisibleText_x                                 0x9499E0
#define CStmlWnd__InitializeWindowVariables_x                      0x94F320
#define CStmlWnd__MakeStmlColorTag_x                               0x948A90
#define CStmlWnd__MakeWndNotificationTag_x                         0x948B00
#define CStmlWnd__SetSTMLText_x                                    0x947B40
#define CStmlWnd__StripFirstSTMLLines_x                            0x9505D0
#define CStmlWnd__UpdateHistoryString_x                            0x94F6E0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946C90
#define CTabWnd__DrawCurrentPage_x                                 0x9473C0
#define CTabWnd__DrawTab_x                                         0x9470E0
#define CTabWnd__GetCurrentPage_x                                  0x9464A0
#define CTabWnd__GetPageInnerRect_x                                0x9466E0
#define CTabWnd__GetTabInnerRect_x                                 0x946620
#define CTabWnd__GetTabRect_x                                      0x9464D0
#define CTabWnd__InsertPage_x                                      0x9468F0
#define CTabWnd__RemovePage_x                                      0x946A60
#define CTabWnd__SetPage_x                                         0x946760
#define CTabWnd__SetPageRect_x                                     0x946BD0
#define CTabWnd__UpdatePage_x                                      0x946FA0
#define CTabWnd__GetPageFromTabIndex_x                             0x947020
#define CTabWnd__GetCurrentTabIndex_x                              0x946490

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75E5E0
#define CPageWnd__SetTabText_x                                     0x945FF0
#define CPageWnd__FlashTab_x                                       0x946050

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9440

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91D8A0
#define CTextureFont__GetTextExtent_x                              0x91DA60

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC2D0
#define CHtmlComponentWnd__ValidateUri_x                           0x73CA30
#define CHtmlWnd__SetClientCallbacks_x                             0x637AC0
#define CHtmlWnd__AddObserver_x                                    0x637AE0
#define CHtmlWnd__RemoveObserver_x                                 0x637B40
#define Window__getProgress_x                                      0x8530C0
#define Window__getStatus_x                                        0x8530E0
#define Window__getURI_x                                           0x8530F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x956890

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90A900

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9AF0
#define CXStr__CXStr1_x                                            0x4B7680
#define CXStr__CXStr3_x                                            0x8F14F0
#define CXStr__dCXStr_x                                            0x478560
#define CXStr__operator_equal_x                                    0x8F1720
#define CXStr__operator_equal1_x                                   0x8F1760
#define CXStr__operator_plus_equal1_x                              0x8F21F0
#define CXStr__SetString_x                                         0x8F40E0
#define CXStr__operator_char_p_x                                   0x8F1C30
#define CXStr__GetChar_x                                           0x8F3A10
#define CXStr__Delete_x                                            0x8F32E0
#define CXStr__GetUnicode_x                                        0x8F3A80
#define CXStr__GetLength_x                                         0x47D820
#define CXStr__Mid_x                                               0x47D830
#define CXStr__Insert_x                                            0x8F3AE0
#define CXStr__FindNext_x                                          0x8F3750

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93EDA0
#define CXWnd__BringToTop_x                                        0x924020
#define CXWnd__Center_x                                            0x923BA0
#define CXWnd__ClrFocus_x                                          0x9239C0
#define CXWnd__Destroy_x                                           0x923A60
#define CXWnd__DoAllDrawing_x                                      0x920150
#define CXWnd__DrawChildren_x                                      0x920120
#define CXWnd__DrawColoredRect_x                                   0x920590
#define CXWnd__DrawTooltip_x                                       0x91EC90
#define CXWnd__DrawTooltipAtPoint_x                                0x91ED50
#define CXWnd__GetBorderFrame_x                                    0x9203F0
#define CXWnd__GetChildWndAt_x                                     0x9240C0
#define CXWnd__GetClientClipRect_x                                 0x922300
#define CXWnd__GetScreenClipRect_x                                 0x9223D0
#define CXWnd__GetScreenRect_x                                     0x922590
#define CXWnd__GetRelativeRect_x                                   0x922650
#define CXWnd__GetTooltipRect_x                                    0x9205E0
#define CXWnd__GetWindowTextA_x                                    0x49CFB0
#define CXWnd__IsActive_x                                          0x920D10
#define CXWnd__IsDescendantOf_x                                    0x922F80
#define CXWnd__IsReallyVisible_x                                   0x922FB0
#define CXWnd__IsType_x                                            0x924720
#define CXWnd__Move_x                                              0x923010
#define CXWnd__Move1_x                                             0x9230C0
#define CXWnd__ProcessTransition_x                                 0x923B50
#define CXWnd__Refade_x                                            0x923380
#define CXWnd__Resize_x                                            0x9235D0
#define CXWnd__Right_x                                             0x923DE0
#define CXWnd__SetFocus_x                                          0x923980
#define CXWnd__SetFont_x                                           0x9239F0
#define CXWnd__SetKeyTooltip_x                                     0x924540
#define CXWnd__SetMouseOver_x                                      0x921520
#define CXWnd__StartFade_x                                         0x922E60
#define CXWnd__GetChildItem_x                                      0x924220
#define CXWnd__SetParent_x                                         0x922D20
#define CXWnd__Minimize_x                                          0x923640

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95AB40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x926F40
#define CXWndManager__DrawWindows_x                                0x926F60
#define CXWndManager__GetKeyboardFlags_x                           0x929730
#define CXWndManager__HandleKeyboardMsg_x                          0x9292F0
#define CXWndManager__RemoveWnd_x                                  0x929960
#define CXWndManager__RemovePendingDeletionWnd_x                   0x929ED0

// CDBStr
#define CDBStr__GetString_x                                        0x5471B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C0070
#define EQ_Character__Cur_HP_x                                     0x4D3110
#define EQ_Character__Cur_Mana_x                                   0x4DA860
#define EQ_Character__GetCastingTimeModifier_x                     0x4C30E0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3A50
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3BA0
#define EQ_Character__GetHPRegen_x                                 0x4E0760
#define EQ_Character__GetEnduranceRegen_x                          0x4E0D60
#define EQ_Character__GetManaRegen_x                               0x4E11A0
#define EQ_Character__Max_Endurance_x                              0x65E7A0
#define EQ_Character__Max_HP_x                                     0x4D2F40
#define EQ_Character__Max_Mana_x                                   0x65E5A0
#define EQ_Character__doCombatAbility_x                            0x660B90
#define EQ_Character__UseSkill_x                                   0x4E2FA0
#define EQ_Character__GetConLevel_x                                0x656D60
#define EQ_Character__IsExpansionFlag_x                            0x5BA380
#define EQ_Character__TotalEffect_x                                0x4C6E80
#define EQ_Character__GetPCSpellAffect_x                           0x4C3E30
#define EQ_Character__SpellDuration_x                              0x4C3960
#define EQ_Character__MySpellDuration_x                            0x4B2380
#define EQ_Character__GetAdjustedSkill_x                           0x4D5E90
#define EQ_Character__GetBaseSkill_x                               0x4D6E30
#define EQ_Character__CanUseItem_x                                 0x4DAB70

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD250

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x674AA0

//PcClient
#define PcClient__vftable_x                                        0xAF21DC
#define PcClient__PcClient_x                                       0x6544C0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAAB0
#define CCharacterListWnd__EnterWorld_x                            0x4BA480
#define CCharacterListWnd__Quit_x                                  0x4BA1D0
#define CCharacterListWnd__UpdateList_x                            0x4BA670

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x638C90
#define EQ_Item__CreateItemTagString_x                             0x896FD0
#define EQ_Item__IsStackable_x                                     0x89BC90
#define EQ_Item__GetImageNum_x                                     0x898B70
#define EQ_Item__CreateItemClient_x                                0x637EC0
#define EQ_Item__GetItemValue_x                                    0x899E50
#define EQ_Item__ValueSellMerchant_x                               0x89D600
#define EQ_Item__IsKeyRingItem_x                                   0x89B590
#define EQ_Item__CanGoInBag_x                                      0x638DB0
#define EQ_Item__IsEmpty_x                                         0x89B0F0
#define EQ_Item__GetMaxItemCount_x                                 0x89A270
#define EQ_Item__GetHeldItem_x                                     0x898A40
#define EQ_Item__GetAugmentFitBySlot_x                             0x896820

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565C60
#define EQ_LoadingS__Array_x                                       0xC13128

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65F0A0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A6A70
#define EQ_PC__GetCombatAbility_x                                  0x8A70E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7150
#define EQ_PC__GetItemRecastTimer_x                                0x661110
#define EQ_PC__HasLoreItem_x                                       0x6575D0
#define EQ_PC__AlertInventoryChanged_x                             0x656690
#define EQ_PC__GetPcZoneClient_x                                   0x683B50
#define EQ_PC__RemoveMyAffect_x                                    0x664340
#define EQ_PC__GetKeyRingItems_x                                   0x8A7A20
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A77A0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A7D20

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C07F0
#define EQItemList__add_object_x                                   0x5EDE60
#define EQItemList__add_item_x                                     0x5C0D50
#define EQItemList__delete_item_x                                  0x5C0DA0
#define EQItemList__FreeItemList_x                                 0x5C0CA0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543D80

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6763A0
#define EQPlayer__dEQPlayer_x                                      0x6696F0
#define EQPlayer__DoAttack_x                                       0x67E2F0
#define EQPlayer__EQPlayer_x                                       0x669DB0
#define EQPlayer__SetNameSpriteState_x                             0x66E0B0
#define EQPlayer__SetNameSpriteTint_x                              0x66EF90
#define PlayerBase__HasProperty_j_x                                0x989590
#define EQPlayer__IsTargetable_x                                   0x989A30
#define EQPlayer__CanSee_x                                         0x989890
#define EQPlayer__CanSee1_x                                        0x989960
#define PlayerBase__GetVisibilityLineSegment_x                     0x989650

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6815F0
#define PlayerZoneClient__GetLevel_x                               0x683B90
#define PlayerZoneClient__IsValidTeleport_x                        0x5EEFD0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E9F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x679210
#define EQPlayerManager__GetSpawnByName_x                          0x6792C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x679350

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C4B0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C530
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C570
#define KeypressHandler__ClearCommandStateArray_x                  0x63D960
#define KeypressHandler__HandleKeyDown_x                           0x63D980
#define KeypressHandler__HandleKeyUp_x                             0x63DA20
#define KeypressHandler__SaveKeymapping_x                          0x63DE70

// MapViewMap 
#define MapViewMap__Clear_x                                        0x775120
#define MapViewMap__SaveEx_x                                       0x7784E0
#define MapViewMap__SetZoom_x                                      0x77CBA0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB2B0

// StringTable 
#define StringTable__getString_x                                   0x8B60D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x663FB0
#define PcZoneClient__RemovePetEffect_x                            0x6645E0
#define PcZoneClient__HasAlternateAbility_x                        0x65E3D0
#define PcZoneClient__GetCurrentMod_x                              0x4E60C0
#define PcZoneClient__GetModCap_x                                  0x4E5FC0
#define PcZoneClient__CanEquipItem_x                               0x65EA80
#define PcZoneClient__GetItemByID_x                                0x661580
#define PcZoneClient__GetItemByItemClass_x                         0x6616D0
#define PcZoneClient__RemoveBuffEffect_x                           0x664600
#define PcZoneClient__BandolierSwap_x                              0x65F660
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6610B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F3B60

//IconCache
#define IconCache__GetIcon_x                                       0x716EF0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70EA20
#define CContainerMgr__CloseContainer_x                            0x70ECF0
#define CContainerMgr__OpenExperimentContainer_x                   0x70F770

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CD740

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x630E60

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76B6F0
#define CLootWnd__RequestLootSlot_x                                0x76A9D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D620
#define EQ_Spell__SpellAffects_x                                   0x58DA90
#define EQ_Spell__SpellAffectBase_x                                0x58D850
#define EQ_Spell__IsStackable_x                                    0x4CAB60
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA9B0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7D20
#define EQ_Spell__IsSPAStacking_x                                  0x58E8E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DDF0
#define EQ_Spell__IsNoRemove_x                                     0x4CAB40
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E8F0
#define __IsResEffectSpell_x                                       0x4C9EB0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD690

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C58F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814400
#define CTargetWnd__WndNotification_x                              0x813C40
#define CTargetWnd__RefreshTargetBuffs_x                           0x813F10
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x812DC0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x818A70
#define CTaskWnd__ConfirmAbandonTask_x                             0x81B6B0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x541760
#define CTaskManager__HandleMessage_x                              0x53FBC0
#define CTaskManager__GetTaskStatus_x                              0x541810
#define CTaskManager__GetElementDescription_x                      0x541890

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5887C0
#define EqSoundManager__PlayScriptMp3_x                            0x588A80
#define EqSoundManager__SoundAssistPlay_x                          0x69C0E0
#define EqSoundManager__WaveInstancePlay_x                         0x69B650

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532B20

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x945500
#define CTextureAnimation__Draw_x                                  0x945700

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x941460

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D750
#define CAltAbilityData__GetMercMaxRank_x                          0x56D6E0
#define CAltAbilityData__GetMaxRank_x                              0x562BB0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62EF70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA990
#define CharacterBase__CreateItemGlobalIndex_x                     0x519570
#define CharacterBase__CreateItemIndex_x                           0x637070
#define CharacterBase__GetItemPossession_x                         0x505590
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CDF40
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CDFA0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5A50
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6280
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6330

//messages
#define msg_spell_worn_off_x                                       0x5B23D0
#define msg_new_text_x                                             0x5A6D70
#define __msgTokenTextParam_x                                      0x5B4670
#define msgTokenText_x                                             0x5B48C0

//SpellManager
#define SpellManager__vftable_x                                    0xADA544
#define SpellManager__SpellManager_x                               0x69F410
#define Spellmanager__LoadTextSpells_x                             0x69FD00
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F5E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98D550

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519BC0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8810
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64FCE0
#define ItemGlobalIndex__IsValidIndex_x                            0x519C50

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C6290
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6510

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x763FB0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7130F0
#define CCursorAttachment__AttachToCursor1_x                       0x713130
#define CCursorAttachment__Deactivate_x                            0x714120

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x938000
#define CSidlManagerBase__CreatePageWnd_x                          0x937820
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x933AD0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933A60

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x955350
#define CEQSuiteTextureLoader__GetTexture_x                        0x955010

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516B20
#define CFindItemWnd__WndNotification_x                            0x517600
#define CFindItemWnd__Update_x                                     0x518140
#define CFindItemWnd__PickupSelectedItem_x                         0x516340

//IString
#define IString__Append_x                                          0x506E80

//Camera
#define CDisplay__cameraType_x                                     0xDEB290
#define EverQuest__Cameras_x                                       0xEA6098

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F520
#define LootFiltersManager__GetItemFilterData_x                    0x51EE20
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51EE50
#define LootFiltersManager__SetItemLootFilter_x                    0x51F070

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BB5A0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9931F0
#define CResolutionHandler__GetWindowedStyle_x                     0x696B50

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70B6D0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DB8A0
#define CDistillerInfo__Instance_x                                 0x8DB840

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A3D0
#define CGroupWnd__UpdateDisplay_x                                 0x729730

//ItemBase
#define ItemBase__IsLore_x                                         0x89B640
#define ItemBase__IsLoreEquipped_x                                 0x89B6C0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EDDC0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EDF00
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EDF60

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C320
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68FC50

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D2A0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F93D0
#define FactionManagerClient__HandleFactionMessage_x               0x4F9A40
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FA040
#define FactionManagerClient__GetMaxFaction_x                      0x4FA05F
#define FactionManagerClient__GetMinFaction_x                      0x4FA010

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505560

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91C850

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C2C0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x505890

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CBE0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2C20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C320

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9200

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C0C40

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF43730

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF350
#define CAAWnd__UpdateSelected_x                                   0x6BBBC0
#define CAAWnd__Update_x                                           0x6BE670

//CXRect
#define CXRect__operator_and_x                                     0x7214D0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4833B0

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
