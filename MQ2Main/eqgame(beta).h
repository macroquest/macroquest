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
#define __ExpectedVersionDate                                     "Nov 17 2020"
#define __ExpectedVersionTime                                     "04:18:27"
#define __ActualVersionDate_x                                      0xAF5540
#define __ActualVersionTime_x                                      0xAF5534
#define __ActualVersionBuild_x                                     0xAE3544

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642B50
#define __MemChecker1_x                                            0x8F5E50
#define __MemChecker2_x                                            0x6B3150
#define __MemChecker3_x                                            0x6B30A0
#define __MemChecker4_x                                            0x84C010
#define __EncryptPad0_x                                            0xC2B9C8
#define __EncryptPad1_x                                            0xC89210
#define __EncryptPad2_x                                            0xC3BD90
#define __EncryptPad3_x                                            0xC3B990
#define __EncryptPad4_x                                            0xC797A0
#define __EncryptPad5_x                                            0xF4B650
#define __AC1_x                                                    0x80AA06
#define __AC2_x                                                    0x5FC19F
#define __AC3_x                                                    0x6037F0
#define __AC4_x                                                    0x6077A0
#define __AC5_x                                                    0x60DA9F
#define __AC6_x                                                    0x611F56
#define __AC7_x                                                    0x5FBC10
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
#define __do_loot_x                                                0x5C7BA0
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
#define __CastRay_x                                                0x5C3290
#define __CastRay2_x                                               0x5C32E0
#define __ConvertItemTags_x                                        0x5DEFB0
#define __CleanItemTags_x                                          0x47D420
#define __DoesFileExist_x                                          0x8F8ED0
#define __EQGetTime_x                                              0x8F5A80
#define __ExecuteCmd_x                                             0x5BBB60
#define __FixHeading_x                                             0x98B560
#define __FlushDxKeyboard_x                                        0x6AEFF0
#define __GameLoop_x                                               0x6B2320
#define __get_bearing_x                                            0x5C2DF0
#define __get_melee_range_x                                        0x5C34D0
#define __GetAnimationCache_x                                      0x717660
#define __GetGaugeValueFromEQ_x                                    0x808EB0
#define __GetLabelFromEQ_x                                         0x80A990
#define __GetXTargetType_x                                         0x98CF90
#define __HandleMouseWheel_x                                       0x6B3200
#define __HeadingDiff_x                                            0x98B5D0
#define __HelpPath_x                                               0xF43DFC
#define __LoadFrontEnd_x                                           0x6AF630
#define __NewUIINI_x                                               0x808B80
#define __ProcessGameEvents_x                                      0x623E30
#define __ProcessMouseEvent_x                                      0x6235C0
#define __SaveColors_x                                             0x55CD20
#define __STMLToText_x                                             0x92E7F0
#define __ToggleKeyRingItem_x                                      0x51B510
#define CMemoryMappedFile__SetFile_x                               0xA7A8C0
#define CrashDetected_x                                            0x6B10E0
#define DrawNetStatus_x                                            0x650090
#define Expansion_HoT_x                                            0xEA5D40
#define Teleport_Table_Size_x                                      0xE9D454
#define Teleport_Table_x                                           0xE9D920
#define Util__FastTime_x                                           0x8F5650
#define __CopyLayout_x                                             0x63E250
#define __WndProc_x                                                0x6B15E0
#define __ProcessKeyboardEvent_x                                   0x6B0B80

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4906F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4996E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4994B0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493C90
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x4930E0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564E70
#define AltAdvManager__IsAbilityReady_x                            0x563C10
#define AltAdvManager__GetAAById_x                                 0x563FA0
#define AltAdvManager__CanTrainAbility_x                           0x564010
#define AltAdvManager__CanSeeAbility_x                             0x564370

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB300
#define CharacterZoneClient__HasSkill_x                            0x4D6180
#define CharacterZoneClient__MakeMeVisible_x                       0x4D78A0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2A10
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBEA0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA260
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA340
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA420
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4B00
#define CharacterZoneClient__BardCastBard_x                        0x4C7530
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF8B0
#define CharacterZoneClient__GetEffect_x                           0x4BBDE0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5B70
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5C40
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5C90
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5DE0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5FC0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3E00
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8800
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8280

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8C70
#define CBankWnd__WndNotification_x                                0x6D8A50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E64C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92BFD0
#define CButtonWnd__CButtonWnd_x                                   0x92ABB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7067E0
#define CChatManager__InitContextMenu_x                            0x6FF910
#define CChatManager__FreeChatWindow_x                             0x705320
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9C60
#define CChatManager__SetLockedActiveChatWindow_x                  0x706460
#define CChatManager__CreateChatWindow_x                           0x705960

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9D70

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93F240
#define CContextMenu__dCContextMenu_x                              0x93F480
#define CContextMenu__AddMenuItem_x                                0x93F490
#define CContextMenu__RemoveMenuItem_x                             0x93F7A0
#define CContextMenu__RemoveAllMenuItems_x                         0x93F7C0
#define CContextMenu__CheckMenuItem_x                              0x93F840
#define CContextMenu__SetMenuItem_x                                0x93F6C0
#define CContextMenu__AddSeparator_x                               0x93F620

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93FDE0
#define CContextMenuManager__RemoveMenu_x                          0x93FE50
#define CContextMenuManager__PopupMenu_x                           0x93FF10
#define CContextMenuManager__Flush_x                               0x93FD80
#define CContextMenuManager__GetMenu_x                             0x49B9C0
#define CContextMenuManager__CreateDefaultMenu_x                   0x711FC0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D0880
#define CChatService__GetFriendName_x                              0x8D0890

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x707050
#define CChatWindow__Clear_x                                       0x708320
#define CChatWindow__WndNotification_x                             0x708AB0
#define CChatWindow__AddHistory_x                                  0x707BE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93C690
#define CComboWnd__Draw_x                                          0x93BB70
#define CComboWnd__GetCurChoice_x                                  0x93C4D0
#define CComboWnd__GetListRect_x                                   0x93C030
#define CComboWnd__GetTextRect_x                                   0x93C700
#define CComboWnd__InsertChoice_x                                  0x93C1C0
#define CComboWnd__SetColors_x                                     0x93C190
#define CComboWnd__SetChoice_x                                     0x93C4A0
#define CComboWnd__GetItemCount_x                                  0x93C4E0
#define CComboWnd__GetCurChoiceText_x                              0x93C520
#define CComboWnd__GetChoiceText_x                                 0x93C4F0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93C260

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70F9F0
#define CContainerWnd__vftable_x                                   0xAFE734
#define CContainerWnd__SetContainer_x                              0x710F40

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
#define CEditBaseWnd__SetSel_x                                     0x95F1A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x942750
#define CEditWnd__EnsureCaretVisible_x                             0x944920
#define CEditWnd__GetCaretPt_x                                     0x9438D0
#define CEditWnd__GetCharIndexPt_x                                 0x943680
#define CEditWnd__GetDisplayString_x                               0x943520
#define CEditWnd__GetHorzOffset_x                                  0x941DF0
#define CEditWnd__GetLineForPrintableChar_x                        0x944820
#define CEditWnd__GetSelStartPt_x                                  0x943930
#define CEditWnd__GetSTMLSafeText_x                                0x943340
#define CEditWnd__PointFromPrintableChar_x                         0x944450
#define CEditWnd__SelectableCharFromPoint_x                        0x9445C0
#define CEditWnd__SetEditable_x                                    0x943A00
#define CEditWnd__SetWindowTextA_x                                 0x9430C0
#define CEditWnd__ReplaceSelection_x                               0x9440C0
#define CEditWnd__ReplaceSelection1_x                              0x944040

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611430
#define CEverQuest__ClickedPlayer_x                                0x6035D0
#define CEverQuest__CreateTargetIndicator_x                        0x620FA0
#define CEverQuest__DeleteTargetIndicator_x                        0x621030
#define CEverQuest__DoTellWindow_x                                 0x4E9E50
#define CEverQuest__OutputTextToLog_x                              0x4EA120
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8720
#define CEverQuest__dsp_chat_x                                     0x4EA4B0
#define CEverQuest__trimName_x                                     0x61D150
#define CEverQuest__Emote_x                                        0x611C90
#define CEverQuest__EnterZone_x                                    0x60BD90
#define CEverQuest__GetBodyTypeDesc_x                              0x6166E0
#define CEverQuest__GetClassDesc_x                                 0x616D20
#define CEverQuest__GetClassThreeLetterCode_x                      0x617320
#define CEverQuest__GetDeityDesc_x                                 0x61F7F0
#define CEverQuest__GetLangDesc_x                                  0x6174E0
#define CEverQuest__GetRaceDesc_x                                  0x616D00
#define CEverQuest__InterpretCmd_x                                 0x61FDC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FC8C0
#define CEverQuest__LMouseUp_x                                     0x5FAC40
#define CEverQuest__RightClickedOnPlayer_x                         0x5FD1A0
#define CEverQuest__RMouseUp_x                                     0x5FBBD0
#define CEverQuest__SetGameState_x                                 0x5F84B0
#define CEverQuest__UPCNotificationFlush_x                         0x61D050
#define CEverQuest__IssuePetCommand_x                              0x6188F0
#define CEverQuest__ReportSuccessfulHit_x                          0x612FE0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7216D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x721730
#define CGaugeWnd__Draw_x                                          0x720D50

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B0180
#define CGuild__GetGuildName_x                                     0x4AEC30
#define CGuild__GetGuildIndex_x                                    0x4AF230

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B370

//CHotButton
#define CHotButton__SetCheck_x                                     0x632730
#define CHotButton__SetButtonSize_x                                0x632AF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748460
#define CInvSlotMgr__MoveItem_x                                    0x747120
#define CInvSlotMgr__SelectSlot_x                                  0x748530

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x745950
#define CInvSlot__SliderComplete_x                                 0x743680
#define CInvSlot__GetItemBase_x                                    0x743000
#define CInvSlot__UpdateItem_x                                     0x743170

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x749FB0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x749150
#define CInvSlotWnd__HandleLButtonUp_x                             0x749B30

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x804220
#define CItemDisplayWnd__UpdateStrings_x                           0x758710
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752420
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752930
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x758D20
#define CItemDisplayWnd__AboutToShow_x                             0x758350
#define CItemDisplayWnd__WndNotification_x                         0x759FA0
#define CItemDisplayWnd__RequestConvertItem_x                      0x7598D0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7573C0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x758170

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834D40

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E4D0

// CLabel 
#define CLabel__Draw_x                                             0x763EE0

// CListWnd
#define CListWnd__CListWnd_x                                       0x914E50
#define CListWnd__dCListWnd_x                                      0x915170
#define CListWnd__AddColumn_x                                      0x9195F0
#define CListWnd__AddColumn1_x                                     0x919640
#define CListWnd__AddLine_x                                        0x9199D0
#define CListWnd__AddString_x                                      0x9197D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9193B0
#define CListWnd__CalculateVSBRange_x                              0x919190
#define CListWnd__ClearSel_x                                       0x91A1B0
#define CListWnd__ClearAllSel_x                                    0x91A210
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91AC20
#define CListWnd__Compare_x                                        0x918AC0
#define CListWnd__Draw_x                                           0x9152A0
#define CListWnd__DrawColumnSeparators_x                           0x917A90
#define CListWnd__DrawHeader_x                                     0x917F00
#define CListWnd__DrawItem_x                                       0x918400
#define CListWnd__DrawLine_x                                       0x917C00
#define CListWnd__DrawSeparator_x                                  0x917B30
#define CListWnd__EnableLine_x                                     0x917360
#define CListWnd__EnsureVisible_x                                  0x91AB40
#define CListWnd__ExtendSel_x                                      0x91A0E0
#define CListWnd__GetColumnTooltip_x                               0x916EA0
#define CListWnd__GetColumnMinWidth_x                              0x916F10
#define CListWnd__GetColumnWidth_x                                 0x916E10
#define CListWnd__GetCurSel_x                                      0x9167A0
#define CListWnd__GetItemAtPoint_x                                 0x9175E0
#define CListWnd__GetItemAtPoint1_x                                0x917650
#define CListWnd__GetItemData_x                                    0x916820
#define CListWnd__GetItemHeight_x                                  0x916BE0
#define CListWnd__GetItemIcon_x                                    0x9169B0
#define CListWnd__GetItemRect_x                                    0x917450
#define CListWnd__GetItemText_x                                    0x916860
#define CListWnd__GetSelList_x                                     0x91A260
#define CListWnd__GetSeparatorRect_x                               0x917890
#define CListWnd__InsertLine_x                                     0x919DC0
#define CListWnd__RemoveLine_x                                     0x919F10
#define CListWnd__SetColors_x                                      0x919160
#define CListWnd__SetColumnJustification_x                         0x918E90
#define CListWnd__SetColumnLabel_x                                 0x919770
#define CListWnd__SetColumnWidth_x                                 0x918DB0
#define CListWnd__SetCurSel_x                                      0x91A020
#define CListWnd__SetItemColor_x                                   0x91A7F0
#define CListWnd__SetItemData_x                                    0x91A7B0
#define CListWnd__SetItemText_x                                    0x91A3D0
#define CListWnd__ShiftColumnSeparator_x                           0x918F50
#define CListWnd__Sort_x                                           0x918C40
#define CListWnd__ToggleSel_x                                      0x91A050
#define CListWnd__SetColumnsSizable_x                              0x919000
#define CListWnd__SetItemWnd_x                                     0x91A680
#define CListWnd__GetItemWnd_x                                     0x916A00
#define CListWnd__SetItemIcon_x                                    0x91A450
#define CListWnd__CalculateCustomWindowPositions_x                 0x9194B0
#define CListWnd__SetVScrollPos_x                                  0x918D90

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779690
#define CMapViewWnd__GetWorldCoordinates_x                         0x777DA0
#define CMapViewWnd__HandleLButtonDown_x                           0x774DE0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7999D0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A2B0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79A7E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79D7A0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x798530
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A3370
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7995E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E0D0
#define CPacketScrambler__hton_x                                   0x89E0C0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x933DE0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9341F0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x933FE0
#define CSidlManager__CreateLabel_x                                0x7FB490
#define CSidlManager__CreateXWndFromTemplate_x                     0x937150
#define CSidlManager__CreateXWndFromTemplate1_x                    0x937330
#define CSidlManager__CreateXWnd_x                                 0x7FB3C0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FB980

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9308A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9307A0
#define CSidlScreenWnd__ConvertToRes_x                             0x959C30
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930290
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92FF80
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x930050
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x930120
#define CSidlScreenWnd__DrawSidlPiece_x                            0x930D40
#define CSidlScreenWnd__EnableIniStorage_x                         0x931210
#define CSidlScreenWnd__GetSidlPiece_x                             0x930F30
#define CSidlScreenWnd__Init1_x                                    0x92FBA0
#define CSidlScreenWnd__LoadIniInfo_x                              0x931260
#define CSidlScreenWnd__LoadIniListWnd_x                           0x931DC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92EFA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x931930
#define CSidlScreenWnd__StoreIniVis_x                              0x931CA0
#define CSidlScreenWnd__WndNotification_x                          0x930C50
#define CSidlScreenWnd__GetChildItem_x                             0x931190
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920A30
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DA190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6982A0
#define CSkillMgr__GetSkillCap_x                                   0x698480
#define CSkillMgr__GetNameToken_x                                  0x697A20
#define CSkillMgr__IsActivatedSkill_x                              0x697B60
#define CSkillMgr__IsCombatSkill_x                                 0x697AA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x940BC0
#define CSliderWnd__SetValue_x                                     0x940A30
#define CSliderWnd__SetNumTicks_x                                  0x940A90

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801560

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x949520
#define CStmlWnd__ParseSTML_x                                      0x94A870
#define CStmlWnd__CalculateHSBRange_x                              0x94A640
#define CStmlWnd__CalculateVSBRange_x                              0x94A5C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94E980
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94F610
#define CStmlWnd__ForceParseNow_x                                  0x949B10
#define CStmlWnd__GetNextTagPiece_x                                0x94E8E0
#define CStmlWnd__GetSTMLText_x                                    0x50CB50
#define CStmlWnd__GetVisibleText_x                                 0x949B30
#define CStmlWnd__InitializeWindowVariables_x                      0x94F460
#define CStmlWnd__MakeStmlColorTag_x                               0x948B90
#define CStmlWnd__MakeWndNotificationTag_x                         0x948C00
#define CStmlWnd__SetSTMLText_x                                    0x947C40
#define CStmlWnd__StripFirstSTMLLines_x                            0x950710
#define CStmlWnd__UpdateHistoryString_x                            0x94F820

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946D90
#define CTabWnd__DrawCurrentPage_x                                 0x9474C0
#define CTabWnd__DrawTab_x                                         0x9471E0
#define CTabWnd__GetCurrentPage_x                                  0x946590
#define CTabWnd__GetPageInnerRect_x                                0x9467D0
#define CTabWnd__GetTabInnerRect_x                                 0x946710
#define CTabWnd__GetTabRect_x                                      0x9465C0
#define CTabWnd__InsertPage_x                                      0x9469E0
#define CTabWnd__RemovePage_x                                      0x946B50
#define CTabWnd__SetPage_x                                         0x946850
#define CTabWnd__SetPageRect_x                                     0x946CD0
#define CTabWnd__UpdatePage_x                                      0x9470A0
#define CTabWnd__GetPageFromTabIndex_x                             0x947120
#define CTabWnd__GetCurrentTabIndex_x                              0x946580

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75E8E0
#define CPageWnd__SetTabText_x                                     0x9460D0
#define CPageWnd__FlashTab_x                                       0x946130

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A94A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91D8C0
#define CTextureFont__GetTextExtent_x                              0x91DA80

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC470
#define CHtmlComponentWnd__ValidateUri_x                           0x73CD60
#define CHtmlWnd__SetClientCallbacks_x                             0x637B90
#define CHtmlWnd__AddObserver_x                                    0x637BB0
#define CHtmlWnd__RemoveObserver_x                                 0x637C10
#define Window__getProgress_x                                      0x853600
#define Window__getStatus_x                                        0x853620
#define Window__getURI_x                                           0x853630

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x956A40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90A9B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9AA0
#define CXStr__CXStr1_x                                            0x507BF0
#define CXStr__CXStr3_x                                            0x8F1A40
#define CXStr__dCXStr_x                                            0x4784C0
#define CXStr__operator_equal_x                                    0x8F1C70
#define CXStr__operator_equal1_x                                   0x8F1CB0
#define CXStr__operator_plus_equal1_x                              0x8F2740
#define CXStr__SetString_x                                         0x8F4630
#define CXStr__operator_char_p_x                                   0x8F21B0
#define CXStr__GetChar_x                                           0x8F3F60
#define CXStr__Delete_x                                            0x8F3830
#define CXStr__GetUnicode_x                                        0x8F3FD0
#define CXStr__GetLength_x                                         0x4A9250
#define CXStr__Mid_x                                               0x47D7D0
#define CXStr__Insert_x                                            0x8F4030
#define CXStr__FindNext_x                                          0x8F3CA0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93EE50
#define CXWnd__BringToTop_x                                        0x924200
#define CXWnd__Center_x                                            0x923D80
#define CXWnd__ClrFocus_x                                          0x923B90
#define CXWnd__Destroy_x                                           0x923C40
#define CXWnd__DoAllDrawing_x                                      0x9201C0
#define CXWnd__DrawChildren_x                                      0x920190
#define CXWnd__DrawColoredRect_x                                   0x920620
#define CXWnd__DrawTooltip_x                                       0x91ECD0
#define CXWnd__DrawTooltipAtPoint_x                                0x91ED90
#define CXWnd__GetBorderFrame_x                                    0x920480
#define CXWnd__GetChildWndAt_x                                     0x9242A0
#define CXWnd__GetClientClipRect_x                                 0x922470
#define CXWnd__GetScreenClipRect_x                                 0x922540
#define CXWnd__GetScreenRect_x                                     0x9226E0
#define CXWnd__GetRelativeRect_x                                   0x9227B0
#define CXWnd__GetTooltipRect_x                                    0x920670
#define CXWnd__GetWindowTextA_x                                    0x49D0E0
#define CXWnd__IsActive_x                                          0x920DA0
#define CXWnd__IsDescendantOf_x                                    0x9230E0
#define CXWnd__IsReallyVisible_x                                   0x923110
#define CXWnd__IsType_x                                            0x924900
#define CXWnd__Move_x                                              0x923180
#define CXWnd__Move1_x                                             0x923240
#define CXWnd__ProcessTransition_x                                 0x923D30
#define CXWnd__Refade_x                                            0x923520
#define CXWnd__Resize_x                                            0x9237B0
#define CXWnd__Right_x                                             0x923FC0
#define CXWnd__SetFocus_x                                          0x923B50
#define CXWnd__SetFont_x                                           0x923BC0
#define CXWnd__SetKeyTooltip_x                                     0x924720
#define CXWnd__SetMouseOver_x                                      0x9215D0
#define CXWnd__StartFade_x                                         0x922FD0
#define CXWnd__GetChildItem_x                                      0x924410
#define CXWnd__SetParent_x                                         0x922E90
#define CXWnd__Minimize_x                                          0x923820

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95ACC0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x927110
#define CXWndManager__DrawWindows_x                                0x927130
#define CXWndManager__GetKeyboardFlags_x                           0x929850
#define CXWndManager__HandleKeyboardMsg_x                          0x929400
#define CXWndManager__RemoveWnd_x                                  0x929A70
#define CXWndManager__RemovePendingDeletionWnd_x                   0x929FD0

// CDBStr
#define CDBStr__GetString_x                                        0x547110

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C0010
#define EQ_Character__Cur_HP_x                                     0x4D31C0
#define EQ_Character__Cur_Mana_x                                   0x4DA920
#define EQ_Character__GetCastingTimeModifier_x                     0x4C3080
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3A40
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3B90
#define EQ_Character__GetHPRegen_x                                 0x4E0820
#define EQ_Character__GetEnduranceRegen_x                          0x4E0E20
#define EQ_Character__GetManaRegen_x                               0x4E1260
#define EQ_Character__Max_Endurance_x                              0x65EA80
#define EQ_Character__Max_HP_x                                     0x4D2FF0
#define EQ_Character__Max_Mana_x                                   0x65E880
#define EQ_Character__doCombatAbility_x                            0x660E70
#define EQ_Character__UseSkill_x                                   0x4E3070
#define EQ_Character__GetConLevel_x                                0x657070
#define EQ_Character__IsExpansionFlag_x                            0x5BA2F0
#define EQ_Character__TotalEffect_x                                0x4C6E20
#define EQ_Character__GetPCSpellAffect_x                           0x4C3DD0
#define EQ_Character__SpellDuration_x                              0x4C3900
#define EQ_Character__MySpellDuration_x                            0x4B2370
#define EQ_Character__GetAdjustedSkill_x                           0x4D5F40
#define EQ_Character__GetBaseSkill_x                               0x4D6EE0
#define EQ_Character__CanUseItem_x                                 0x4DAC30

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD7C0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x674D60

//PcClient
#define PcClient__vftable_x                                        0xAF21BC
#define PcClient__PcClient_x                                       0x6547D0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAA50
#define CCharacterListWnd__EnterWorld_x                            0x4BA420
#define CCharacterListWnd__Quit_x                                  0x4BA170
#define CCharacterListWnd__UpdateList_x                            0x4BA610

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x638D60
#define EQ_Item__CreateItemTagString_x                             0x897630
#define EQ_Item__IsStackable_x                                     0x89C330
#define EQ_Item__GetImageNum_x                                     0x899210
#define EQ_Item__CreateItemClient_x                                0x637FB0
#define EQ_Item__GetItemValue_x                                    0x89A520
#define EQ_Item__ValueSellMerchant_x                               0x89DCB0
#define EQ_Item__IsKeyRingItem_x                                   0x89BC50
#define EQ_Item__CanGoInBag_x                                      0x638E80
#define EQ_Item__IsEmpty_x                                         0x89B790
#define EQ_Item__GetMaxItemCount_x                                 0x89A930
#define EQ_Item__GetHeldItem_x                                     0x8990E0
#define EQ_Item__GetAugmentFitBySlot_x                             0x896E80

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565B40
#define EQ_LoadingS__Array_x                                       0xC13128

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65F380
#define EQ_PC__GetAlternateAbilityId_x                             0x8A70F0
#define EQ_PC__GetCombatAbility_x                                  0x8A7760
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A77D0
#define EQ_PC__GetItemRecastTimer_x                                0x6613F0
#define EQ_PC__HasLoreItem_x                                       0x6578E0
#define EQ_PC__AlertInventoryChanged_x                             0x6569A0
#define EQ_PC__GetPcZoneClient_x                                   0x683D20
#define EQ_PC__RemoveMyAffect_x                                    0x664620
#define EQ_PC__GetKeyRingItems_x                                   0x8A80A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A7E20
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A83A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C07C0
#define EQItemList__add_object_x                                   0x5EDE70
#define EQItemList__add_item_x                                     0x5C0D20
#define EQItemList__delete_item_x                                  0x5C0D70
#define EQItemList__FreeItemList_x                                 0x5C0C70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543C40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x676660
#define EQPlayer__dEQPlayer_x                                      0x6699D0
#define EQPlayer__DoAttack_x                                       0x67E4B0
#define EQPlayer__EQPlayer_x                                       0x66A090
#define EQPlayer__SetNameSpriteState_x                             0x66E370
#define EQPlayer__SetNameSpriteTint_x                              0x66F250
#define PlayerBase__HasProperty_j_x                                0x989960
#define EQPlayer__IsTargetable_x                                   0x989E00
#define EQPlayer__CanSee_x                                         0x989C60
#define EQPlayer__CanSee1_x                                        0x989D30
#define PlayerBase__GetVisibilityLineSegment_x                     0x989A20

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6817B0
#define PlayerZoneClient__GetLevel_x                               0x683D60
#define PlayerZoneClient__IsValidTeleport_x                        0x5EEFE0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E970

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6793A0
#define EQPlayerManager__GetSpawnByName_x                          0x679450
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6794E0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C4B0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C530
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C570
#define KeypressHandler__ClearCommandStateArray_x                  0x63D960
#define KeypressHandler__HandleKeyDown_x                           0x63D980
#define KeypressHandler__HandleKeyUp_x                             0x63DA20
#define KeypressHandler__SaveKeymapping_x                          0x63DE70

// MapViewMap 
#define MapViewMap__Clear_x                                        0x775500
#define MapViewMap__SaveEx_x                                       0x7788C0
#define MapViewMap__SetZoom_x                                      0x77CF80

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB820

// StringTable 
#define StringTable__getString_x                                   0x8B6580

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x664290
#define PcZoneClient__RemovePetEffect_x                            0x6648C0
#define PcZoneClient__HasAlternateAbility_x                        0x65E6B0
#define PcZoneClient__GetCurrentMod_x                              0x4E6190
#define PcZoneClient__GetModCap_x                                  0x4E6090
#define PcZoneClient__CanEquipItem_x                               0x65ED60
#define PcZoneClient__GetItemByID_x                                0x661860
#define PcZoneClient__GetItemByItemClass_x                         0x6619B0
#define PcZoneClient__RemoveBuffEffect_x                           0x6648E0
#define PcZoneClient__BandolierSwap_x                              0x65F940
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x661390

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F3BD0

//IconCache
#define IconCache__GetIcon_x                                       0x717060

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70EB90
#define CContainerMgr__CloseContainer_x                            0x70EE60
#define CContainerMgr__OpenExperimentContainer_x                   0x70F8E0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CDBB0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x630F00

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76B9A0
#define CLootWnd__RequestLootSlot_x                                0x76AC70

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D330
#define EQ_Spell__SpellAffects_x                                   0x58D7A0
#define EQ_Spell__SpellAffectBase_x                                0x58D560
#define EQ_Spell__IsStackable_x                                    0x4CAC20
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAA40
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7D00
#define EQ_Spell__IsSPAStacking_x                                  0x58E5F0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DB00
#define EQ_Spell__IsNoRemove_x                                     0x4CAC00
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E600
#define __IsResEffectSpell_x                                       0x4C9E70

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD690

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5ED0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814910
#define CTargetWnd__WndNotification_x                              0x814150
#define CTargetWnd__RefreshTargetBuffs_x                           0x814420
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8132C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x818F90
#define CTaskWnd__ConfirmAbandonTask_x                             0x81BBD0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x541650
#define CTaskManager__HandleMessage_x                              0x53FAD0
#define CTaskManager__GetTaskStatus_x                              0x541700
#define CTaskManager__GetElementDescription_x                      0x541780

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x588480
#define EqSoundManager__PlayScriptMp3_x                            0x588740
#define EqSoundManager__SoundAssistPlay_x                          0x69C190
#define EqSoundManager__WaveInstancePlay_x                         0x69B700

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532A40

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9455E0
#define CTextureAnimation__Draw_x                                  0x9457E0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x941530

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D640
#define CAltAbilityData__GetMercMaxRank_x                          0x56D5D0
#define CAltAbilityData__GetMaxRank_x                              0x562A90

//CTargetRing
#define CTargetRing__Cast_x                                        0x62F020

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CAA20
#define CharacterBase__CreateItemGlobalIndex_x                     0x519720
#define CharacterBase__CreateItemIndex_x                           0x637140
#define CharacterBase__GetItemPossession_x                         0x505430
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE530
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE590
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5A80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F62B0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6360

//messages
#define msg_spell_worn_off_x                                       0x5B2370
#define msg_new_text_x                                             0x5A6CE0
#define __msgTokenTextParam_x                                      0x5B4610
#define msgTokenText_x                                             0x5B4860

//SpellManager
#define SpellManager__vftable_x                                    0xADA55C
#define SpellManager__SpellManager_x                               0x69F4C0
#define Spellmanager__LoadTextSpells_x                             0x69FDB0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F690

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98D880

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519D70
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8800
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64FEF0
#define ItemGlobalIndex__IsValidIndex_x                            0x519E00

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C6870
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6AF0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764220

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x713260
#define CCursorAttachment__AttachToCursor1_x                       0x7132A0
#define CCursorAttachment__Deactivate_x                            0x714290

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x938180
#define CSidlManagerBase__CreatePageWnd_x                          0x937980
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x933C00
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933B90

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x955660
#define CEQSuiteTextureLoader__GetTexture_x                        0x955320

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516CA0
#define CFindItemWnd__WndNotification_x                            0x517780
#define CFindItemWnd__Update_x                                     0x5182C0
#define CFindItemWnd__PickupSelectedItem_x                         0x5164D0

//IString
#define IString__Append_x                                          0x506D00

//Camera
#define CDisplay__cameraType_x                                     0xDEB290
#define EverQuest__Cameras_x                                       0xEA6098

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F6B0
#define LootFiltersManager__GetItemFilterData_x                    0x51EFB0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51EFE0
#define LootFiltersManager__SetItemLootFilter_x                    0x51F200

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BB990

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9934E0
#define CResolutionHandler__GetWindowedStyle_x                     0x696D40

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70B7C0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DBE20
#define CDistillerInfo__Instance_x                                 0x8DBDC0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A6B0
#define CGroupWnd__UpdateDisplay_x                                 0x729A00

//ItemBase
#define ItemBase__IsLore_x                                         0x89BD00
#define ItemBase__IsLoreEquipped_x                                 0x89BD70

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EDDD0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EDF10
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EDF70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C440
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68FE00

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D3A0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9650
#define FactionManagerClient__HandleFactionMessage_x               0x4F9CC0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FA2C0
#define FactionManagerClient__GetMaxFaction_x                      0x4FA2DF
#define FactionManagerClient__GetMinFaction_x                      0x4FA290

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505400

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91C910

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C3C0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x505710

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CAE0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2D30

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C440

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9260

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C0C10

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF43730

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF510
#define CAAWnd__UpdateSelected_x                                   0x6BBD80
#define CAAWnd__Update_x                                           0x6BE830

//CXRect
#define CXRect__operator_and_x                                     0x721790

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4833F0

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
