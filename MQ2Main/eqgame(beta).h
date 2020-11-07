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
#define __ExpectedVersionDate                                     "Nov  7 2020"
#define __ExpectedVersionTime                                     "04:20:10"
#define __ActualVersionDate_x                                      0xAF553C
#define __ActualVersionTime_x                                      0xAF5530
#define __ActualVersionBuild_x                                     0xAE3544

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x642F20
#define __MemChecker1_x                                            0x8F5EE0
#define __MemChecker2_x                                            0x6B3320
#define __MemChecker3_x                                            0x6B3270
#define __MemChecker4_x                                            0x84BE20
#define __EncryptPad0_x                                            0xC2B9C8
#define __EncryptPad1_x                                            0xC89210
#define __EncryptPad2_x                                            0xC3BD90
#define __EncryptPad3_x                                            0xC3B990
#define __EncryptPad4_x                                            0xC797A0
#define __EncryptPad5_x                                            0xF4B650
#define __AC1_x                                                    0x80AB76
#define __AC2_x                                                    0x5FC59F
#define __AC3_x                                                    0x603BF0
#define __AC4_x                                                    0x607BA0
#define __AC5_x                                                    0x60DE9F
#define __AC6_x                                                    0x612356
#define __AC7_x                                                    0x5FC010
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
#define __do_loot_x                                                0x5C8050
#define __DrawHandler_x                                            0x15DB140
#define __GroupCount_x                                             0xE9FA72
#define __Guilds_x                                                 0xEA3918
#define __gWorld_x                                                 0xE9F91C
#define __HWnd_x                                                   0xF4B68C
#define __heqmain_x                                                0xF4B638
#define __InChatMode_x                                             0xEA49C4
#define __LastTell_x                                               0xEA6948
#define __LMouseHeldTime_x                                         0xEA4B00
#define __Mouse_x                                                  0xF4B65C
#define __MouseLook_x                                              0xEA4A5A
#define __MouseEventTime_x                                         0xF4420C
#define __gpbCommandEvent_x                                        0xE9D3C4
#define __NetStatusToggle_x                                        0xEA4A5D
#define __PCNames_x                                                0xEA5EF4
#define __RangeAttackReady_x                                       0xEA5BDC
#define __RMouseHeldTime_x                                         0xEA4AFC
#define __RunWalkState_x                                           0xEA49C8
#define __ScreenMode_x                                             0xDEB1DC
#define __ScreenX_x                                                0xEA497C
#define __ScreenY_x                                                0xEA4978
#define __ScreenXMax_x                                             0xEA4980
#define __ScreenYMax_x                                             0xEA4984
#define __ServerHost_x                                             0xE9D593
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
#define pinstActiveBanker_x                                        0xE9D8B0
#define pinstActiveCorpse_x                                        0xE9D8A8
#define pinstActiveGMaster_x                                       0xE9D8AC
#define pinstActiveMerchant_x                                      0xE9D8A4
#define pinstAltAdvManager_x                                       0xDEBEE0
#define pinstBandageTarget_x                                       0xE9D8C0
#define pinstCamActor_x                                            0xDEB1C8
#define pinstCDBStr_x                                              0xDEABFC
#define pinstCDisplay_x                                            0xE9D910
#define pinstCEverQuest_x                                          0xF4B690
#define pinstEverQuestInfo_x                                       0xEA4970
#define pinstCharData_x                                            0xE9D3B0
#define pinstCharSpawn_x                                           0xE9D8F8
#define pinstControlledMissile_x                                   0xE9D908
#define pinstControlledPlayer_x                                    0xE9D8F8
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
#define pinstGroup_x                                               0xE9FA6E
#define pinstImeManager_x                                          0x15DA300
#define pinstLocalPlayer_x                                         0xE9D69C
#define pinstMercenaryData_x                                       0xF45D00
#define pinstMercenaryStats_x                                      0xF5EBCC
#define pinstModelPlayer_x                                         0xE9D8B8
#define pinstPCData_x                                              0xE9D3B0
#define pinstSkillMgr_x                                            0xF47E68
#define pinstSpawnManager_x                                        0xF46910
#define pinstSpellManager_x                                        0xF480A8
#define pinstSpellSets_x                                           0xF3C354
#define pinstStringTable_x                                         0xE9D3B8
#define pinstSwitchManager_x                                       0xE9D250
#define pinstTarget_x                                              0xE9D8F4
#define pinstTargetObject_x                                        0xE9D900
#define pinstTargetSwitch_x                                        0xE9D914
#define pinstTaskMember_x                                          0xDEA9D0
#define pinstTrackTarget_x                                         0xE9D8FC
#define pinstTradeTarget_x                                         0xE9D8B4
#define instTributeActive_x                                        0xDEAB61
#define pinstViewActor_x                                           0xDEB1C4
#define pinstWorldData_x                                           0xE9D3AC
#define pinstZoneAddr_x                                            0xEA4EF0
#define pinstPlayerPath_x                                          0xF469A8
#define pinstTargetIndicator_x                                     0xF48310
#define EQObject_Top_x                                             0xE9D48C
 
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
#define pinstCBuffWindowNORMAL_x                                   0xDEB1D0
#define pinstCBuffWindowSHORT_x                                    0xDEB1D8
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
#define __CastRay_x                                                0x5C3740
#define __CastRay2_x                                               0x5C3790
#define __ConvertItemTags_x                                        0x5DF460
#define __CleanItemTags_x                                          0x47D230
#define __DoesFileExist_x                                          0x8F8F10
#define __EQGetTime_x                                              0x8F5B10
#define __ExecuteCmd_x                                             0x5BC080
#define __FixHeading_x                                             0x98AFC0
#define __FlushDxKeyboard_x                                        0x6AF1C0
#define __GameLoop_x                                               0x6B24F0
#define __get_bearing_x                                            0x5C32A0
#define __get_melee_range_x                                        0x5C3980
#define __GetAnimationCache_x                                      0x717790
#define __GetGaugeValueFromEQ_x                                    0x809020
#define __GetLabelFromEQ_x                                         0x80AB00
#define __GetXTargetType_x                                         0x98CA10
#define __HandleMouseWheel_x                                       0x6B33D0
#define __HeadingDiff_x                                            0x98B030
#define __HelpPath_x                                               0xF43DFC
#define __LoadFrontEnd_x                                           0x6AF800
#define __NewUIINI_x                                               0x808CF0
#define __ProcessGameEvents_x                                      0x624230
#define __ProcessMouseEvent_x                                      0x6239C0
#define __SaveColors_x                                             0x55CF60
#define __STMLToText_x                                             0x92E560
#define __ToggleKeyRingItem_x                                      0x51B6E0
#define CMemoryMappedFile__SetFile_x                               0xA7A290
#define CrashDetected_x                                            0x6B12B0
#define DrawNetStatus_x                                            0x650420
#define Expansion_HoT_x                                            0xEA5D40
#define Teleport_Table_Size_x                                      0xE9D44C
#define Teleport_Table_x                                           0xE9D918
#define Util__FastTime_x                                           0x8F56E0
#define __CopyLayout_x                                             0x63E640
#define __WndProc_x                                                0x6B17B0
#define __ProcessKeyboardEvent_x                                   0x6B0D50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4906D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4996C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499490
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493C60
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x4930B0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5650B0
#define AltAdvManager__IsAbilityReady_x                            0x563E50
#define AltAdvManager__GetAAById_x                                 0x5641E0
#define AltAdvManager__CanTrainAbility_x                           0x564250
#define AltAdvManager__CanSeeAbility_x                             0x5645B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB250
#define CharacterZoneClient__HasSkill_x                            0x4D60D0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D77F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C29A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBE40
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA150
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA230
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA310
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4A90
#define CharacterZoneClient__BardCastBard_x                        0x4C74C0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF850
#define CharacterZoneClient__GetEffect_x                           0x4BBD80
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5B00
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5BD0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5C20
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5D70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5F50
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3D00
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8750
#define CharacterZoneClient__FindItemByRecord_x                    0x4D81D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8E20
#define CBankWnd__WndNotification_x                                0x6D8C00

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E67B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92BD40
#define CButtonWnd__CButtonWnd_x                                   0x92A930

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706900
#define CChatManager__InitContextMenu_x                            0x6FFA30
#define CChatManager__FreeChatWindow_x                             0x705440
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9BF0
#define CChatManager__SetLockedActiveChatWindow_x                  0x706580
#define CChatManager__CreateChatWindow_x                           0x705A80

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9D00

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93EEB0
#define CContextMenu__dCContextMenu_x                              0x93F0E0
#define CContextMenu__AddMenuItem_x                                0x93F0F0
#define CContextMenu__RemoveMenuItem_x                             0x93F3F0
#define CContextMenu__RemoveAllMenuItems_x                         0x93F410
#define CContextMenu__CheckMenuItem_x                              0x93F490
#define CContextMenu__SetMenuItem_x                                0x93F320
#define CContextMenu__AddSeparator_x                               0x93F280

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93FA20
#define CContextMenuManager__RemoveMenu_x                          0x93FA90
#define CContextMenuManager__PopupMenu_x                           0x93FB50
#define CContextMenuManager__Flush_x                               0x93F9C0
#define CContextMenuManager__GetMenu_x                             0x49B860
#define CContextMenuManager__CreateDefaultMenu_x                   0x712100

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D09D0
#define CChatService__GetFriendName_x                              0x8D09E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x707170
#define CChatWindow__Clear_x                                       0x708430
#define CChatWindow__WndNotification_x                             0x708BC0
#define CChatWindow__AddHistory_x                                  0x707CF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93C310
#define CComboWnd__Draw_x                                          0x93B820
#define CComboWnd__GetCurChoice_x                                  0x93C150
#define CComboWnd__GetListRect_x                                   0x93BCC0
#define CComboWnd__GetTextRect_x                                   0x93C370
#define CComboWnd__InsertChoice_x                                  0x93BE50
#define CComboWnd__SetColors_x                                     0x93BE20
#define CComboWnd__SetChoice_x                                     0x93C120
#define CComboWnd__GetItemCount_x                                  0x93C160
#define CComboWnd__GetCurChoiceText_x                              0x93C1A0
#define CComboWnd__GetChoiceText_x                                 0x93C170
#define CComboWnd__InsertChoiceAtIndex_x                           0x93BEE0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70FB00
#define CContainerWnd__vftable_x                                   0xAFE734
#define CContainerWnd__SetContainer_x                              0x711060

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5578C0
#define CDisplay__PreZoneMainUI_x                                  0x5578D0
#define CDisplay__CleanGameUI_x                                    0x55CD20
#define CDisplay__GetClickedActor_x                                0x54FD20
#define CDisplay__GetUserDefinedColor_x                            0x5483A0
#define CDisplay__GetWorldFilePath_x                               0x551790
#define CDisplay__is3dON_x                                         0x54C980
#define CDisplay__ReloadUI_x                                       0x556DD0
#define CDisplay__WriteTextHD2_x                                   0x54C770
#define CDisplay__TrueDistance_x                                   0x553450
#define CDisplay__SetViewActor_x                                   0x54F640
#define CDisplay__GetFloorHeight_x                                 0x54CA40
#define CDisplay__SetRenderWindow_x                                0x54B3C0
#define CDisplay__ToggleScreenshotMode_x                           0x54F110

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95EB60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x942370
#define CEditWnd__EnsureCaretVisible_x                             0x9444D0
#define CEditWnd__GetCaretPt_x                                     0x9434C0
#define CEditWnd__GetCharIndexPt_x                                 0x943280
#define CEditWnd__GetDisplayString_x                               0x943130
#define CEditWnd__GetHorzOffset_x                                  0x941A30
#define CEditWnd__GetLineForPrintableChar_x                        0x9443D0
#define CEditWnd__GetSelStartPt_x                                  0x943520
#define CEditWnd__GetSTMLSafeText_x                                0x942F50
#define CEditWnd__PointFromPrintableChar_x                         0x944020
#define CEditWnd__SelectableCharFromPoint_x                        0x944180
#define CEditWnd__SetEditable_x                                    0x9435E0
#define CEditWnd__SetWindowTextA_x                                 0x942CD0
#define CEditWnd__ReplaceSelection_x                               0x943CA0
#define CEditWnd__ReplaceSelection1_x                              0x943C20

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611830
#define CEverQuest__ClickedPlayer_x                                0x6039D0
#define CEverQuest__CreateTargetIndicator_x                        0x6213A0
#define CEverQuest__DeleteTargetIndicator_x                        0x621430
#define CEverQuest__DoTellWindow_x                                 0x4E9DE0
#define CEverQuest__OutputTextToLog_x                              0x4EA0B0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8B30
#define CEverQuest__dsp_chat_x                                     0x4EA440
#define CEverQuest__trimName_x                                     0x61D550
#define CEverQuest__Emote_x                                        0x612090
#define CEverQuest__EnterZone_x                                    0x60C190
#define CEverQuest__GetBodyTypeDesc_x                              0x616AE0
#define CEverQuest__GetClassDesc_x                                 0x617120
#define CEverQuest__GetClassThreeLetterCode_x                      0x617720
#define CEverQuest__GetDeityDesc_x                                 0x61FBF0
#define CEverQuest__GetLangDesc_x                                  0x6178E0
#define CEverQuest__GetRaceDesc_x                                  0x617100
#define CEverQuest__InterpretCmd_x                                 0x6201C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FCCC0
#define CEverQuest__LMouseUp_x                                     0x5FB050
#define CEverQuest__RightClickedOnPlayer_x                         0x5FD5A0
#define CEverQuest__RMouseUp_x                                     0x5FBFD0
#define CEverQuest__SetGameState_x                                 0x5F88C0
#define CEverQuest__UPCNotificationFlush_x                         0x61D450
#define CEverQuest__IssuePetCommand_x                              0x618CF0
#define CEverQuest__ReportSuccessfulHit_x                          0x6133E0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x721820
#define CGaugeWnd__CalcLinesFillRect_x                             0x721880
#define CGaugeWnd__Draw_x                                          0x720EA0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B0010
#define CGuild__GetGuildName_x                                     0x4AEAC0
#define CGuild__GetGuildIndex_x                                    0x4AF0C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B450

//CHotButton
#define CHotButton__SetCheck_x                                     0x6329E0
#define CHotButton__SetButtonSize_x                                0x632DA0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7484B0
#define CInvSlotMgr__MoveItem_x                                    0x7471D0
#define CInvSlotMgr__SelectSlot_x                                  0x748580

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7459C0
#define CInvSlot__SliderComplete_x                                 0x743710
#define CInvSlot__GetItemBase_x                                    0x7430A0
#define CInvSlot__UpdateItem_x                                     0x743210

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x749FF0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x749180
#define CInvSlotWnd__HandleLButtonUp_x                             0x749B70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8043B0
#define CItemDisplayWnd__UpdateStrings_x                           0x758760
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752440
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752950
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x758D60
#define CItemDisplayWnd__AboutToShow_x                             0x7583C0
#define CItemDisplayWnd__WndNotification_x                         0x759FC0
#define CItemDisplayWnd__RequestConvertItem_x                      0x759900
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x757430
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7581E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x834EC0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75E4D0

// CLabel 
#define CLabel__Draw_x                                             0x763F50

// CListWnd
#define CListWnd__CListWnd_x                                       0x914B90
#define CListWnd__dCListWnd_x                                      0x914EB0
#define CListWnd__AddColumn_x                                      0x919310
#define CListWnd__AddColumn1_x                                     0x919360
#define CListWnd__AddLine_x                                        0x9196F0
#define CListWnd__AddString_x                                      0x9194F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9190E0
#define CListWnd__CalculateVSBRange_x                              0x918EC0
#define CListWnd__ClearSel_x                                       0x919ED0
#define CListWnd__ClearAllSel_x                                    0x919F30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91A920
#define CListWnd__Compare_x                                        0x9187F0
#define CListWnd__Draw_x                                           0x914FE0
#define CListWnd__DrawColumnSeparators_x                           0x9177C0
#define CListWnd__DrawHeader_x                                     0x917C30
#define CListWnd__DrawItem_x                                       0x918130
#define CListWnd__DrawLine_x                                       0x917930
#define CListWnd__DrawSeparator_x                                  0x917860
#define CListWnd__EnableLine_x                                     0x9170A0
#define CListWnd__EnsureVisible_x                                  0x91A860
#define CListWnd__ExtendSel_x                                      0x919E00
#define CListWnd__GetColumnTooltip_x                               0x916BE0
#define CListWnd__GetColumnMinWidth_x                              0x916C50
#define CListWnd__GetColumnWidth_x                                 0x916B50
#define CListWnd__GetCurSel_x                                      0x9164E0
#define CListWnd__GetItemAtPoint_x                                 0x917310
#define CListWnd__GetItemAtPoint1_x                                0x917380
#define CListWnd__GetItemData_x                                    0x916560
#define CListWnd__GetItemHeight_x                                  0x916920
#define CListWnd__GetItemIcon_x                                    0x9166F0
#define CListWnd__GetItemRect_x                                    0x917190
#define CListWnd__GetItemText_x                                    0x9165A0
#define CListWnd__GetSelList_x                                     0x919F80
#define CListWnd__GetSeparatorRect_x                               0x9175C0
#define CListWnd__InsertLine_x                                     0x919AE0
#define CListWnd__RemoveLine_x                                     0x919C30
#define CListWnd__SetColors_x                                      0x918E90
#define CListWnd__SetColumnJustification_x                         0x918BC0
#define CListWnd__SetColumnLabel_x                                 0x919490
#define CListWnd__SetColumnWidth_x                                 0x918AE0
#define CListWnd__SetCurSel_x                                      0x919D40
#define CListWnd__SetItemColor_x                                   0x91A520
#define CListWnd__SetItemData_x                                    0x91A4E0
#define CListWnd__SetItemText_x                                    0x91A0F0
#define CListWnd__ShiftColumnSeparator_x                           0x918C80
#define CListWnd__Sort_x                                           0x918970
#define CListWnd__ToggleSel_x                                      0x919D70
#define CListWnd__SetColumnsSizable_x                              0x918D30
#define CListWnd__SetItemWnd_x                                     0x91A3A0
#define CListWnd__GetItemWnd_x                                     0x916740
#define CListWnd__SetItemIcon_x                                    0x91A170
#define CListWnd__CalculateCustomWindowPositions_x                 0x9191D0
#define CListWnd__SetVScrollPos_x                                  0x918AC0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779650
#define CMapViewWnd__GetWorldCoordinates_x                         0x777D60
#define CMapViewWnd__HandleLButtonDown_x                           0x774DA0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799AC0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A3A0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79A8D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79D880
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x798630
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A3440
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7996D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E280
#define CPacketScrambler__hton_x                                   0x89E270

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x933B60
#define CSidlManager__FindScreenPieceTemplate_x                    0x933F70
#define CSidlManager__FindScreenPieceTemplate1_x                   0x933D60
#define CSidlManager__CreateLabel_x                                0x7FB570
#define CSidlManager__CreateXWndFromTemplate_x                     0x936ED0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9370B0
#define CSidlManager__CreateXWnd_x                                 0x7FB4A0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FBA70

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x930630
#define CSidlScreenWnd__CalculateVSBRange_x                        0x930530
#define CSidlScreenWnd__ConvertToRes_x                             0x9595F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930020
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92FD10
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92FDE0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92FEB0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x930AC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x930F90
#define CSidlScreenWnd__GetSidlPiece_x                             0x930CB0
#define CSidlScreenWnd__Init1_x                                    0x92F910
#define CSidlScreenWnd__LoadIniInfo_x                              0x930FE0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x931B40
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92ED10
#define CSidlScreenWnd__StoreIniInfo_x                             0x9316B0
#define CSidlScreenWnd__StoreIniVis_x                              0x931A20
#define CSidlScreenWnd__WndNotification_x                          0x9309D0
#define CSidlScreenWnd__GetChildItem_x                             0x930F10
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920670
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DA190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x698540
#define CSkillMgr__GetSkillCap_x                                   0x698720
#define CSkillMgr__GetNameToken_x                                  0x697CC0
#define CSkillMgr__IsActivatedSkill_x                              0x697E00
#define CSkillMgr__IsCombatSkill_x                                 0x697D40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x940810
#define CSliderWnd__SetValue_x                                     0x940680
#define CSliderWnd__SetNumTicks_x                                  0x9406E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8016C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9490A0
#define CStmlWnd__ParseSTML_x                                      0x94A3E0
#define CStmlWnd__CalculateHSBRange_x                              0x94A1B0
#define CStmlWnd__CalculateVSBRange_x                              0x94A130
#define CStmlWnd__CanBreakAtCharacter_x                            0x94E4F0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94F180
#define CStmlWnd__ForceParseNow_x                                  0x949690
#define CStmlWnd__GetNextTagPiece_x                                0x94E450
#define CStmlWnd__GetSTMLText_x                                    0x50CE10
#define CStmlWnd__GetVisibleText_x                                 0x9496B0
#define CStmlWnd__InitializeWindowVariables_x                      0x94EFD0
#define CStmlWnd__MakeStmlColorTag_x                               0x948710
#define CStmlWnd__MakeWndNotificationTag_x                         0x948780
#define CStmlWnd__SetSTMLText_x                                    0x9477C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x950270
#define CStmlWnd__UpdateHistoryString_x                            0x94F390

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946910
#define CTabWnd__DrawCurrentPage_x                                 0x947040
#define CTabWnd__DrawTab_x                                         0x946D60
#define CTabWnd__GetCurrentPage_x                                  0x946110
#define CTabWnd__GetPageInnerRect_x                                0x946350
#define CTabWnd__GetTabInnerRect_x                                 0x946290
#define CTabWnd__GetTabRect_x                                      0x946140
#define CTabWnd__InsertPage_x                                      0x946560
#define CTabWnd__RemovePage_x                                      0x9466D0
#define CTabWnd__SetPage_x                                         0x9463D0
#define CTabWnd__SetPageRect_x                                     0x946850
#define CTabWnd__UpdatePage_x                                      0x946C20
#define CTabWnd__GetPageFromTabIndex_x                             0x946CA0
#define CTabWnd__GetCurrentTabIndex_x                              0x946100

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75E940
#define CPageWnd__SetTabText_x                                     0x945C60
#define CPageWnd__FlashTab_x                                       0x945CC0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9300

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91D560
#define CTextureFont__GetTextExtent_x                              0x91D720

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC660
#define CHtmlComponentWnd__ValidateUri_x                           0x73CE40
#define CHtmlWnd__SetClientCallbacks_x                             0x637E20
#define CHtmlWnd__AddObserver_x                                    0x637E40
#define CHtmlWnd__RemoveObserver_x                                 0x637EA0
#define Window__getProgress_x                                      0x853460
#define Window__getStatus_x                                        0x853480
#define Window__getURI_x                                           0x853490

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9563F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90A660

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9A30
#define CXStr__CXStr1_x                                            0x913070
#define CXStr__CXStr3_x                                            0x8F1AD0
#define CXStr__dCXStr_x                                            0x478430
#define CXStr__operator_equal_x                                    0x8F1D00
#define CXStr__operator_equal1_x                                   0x8F1D40
#define CXStr__operator_plus_equal1_x                              0x8F27D0
#define CXStr__SetString_x                                         0x8F46C0
#define CXStr__operator_char_p_x                                   0x8F2210
#define CXStr__GetChar_x                                           0x8F3FF0
#define CXStr__Delete_x                                            0x8F38C0
#define CXStr__GetUnicode_x                                        0x8F4060
#define CXStr__GetLength_x                                         0x4A90B0
#define CXStr__Mid_x                                               0x47D5E0
#define CXStr__Insert_x                                            0x8F40C0
#define CXStr__FindNext_x                                          0x8F3D30

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93EAC0
#define CXWnd__BringToTop_x                                        0x923E00
#define CXWnd__Center_x                                            0x923980
#define CXWnd__ClrFocus_x                                          0x9237A0
#define CXWnd__Destroy_x                                           0x923840
#define CXWnd__DoAllDrawing_x                                      0x91FE00
#define CXWnd__DrawChildren_x                                      0x91FDD0
#define CXWnd__DrawColoredRect_x                                   0x920260
#define CXWnd__DrawTooltip_x                                       0x91E950
#define CXWnd__DrawTooltipAtPoint_x                                0x91EA10
#define CXWnd__GetBorderFrame_x                                    0x9200C0
#define CXWnd__GetChildWndAt_x                                     0x923EA0
#define CXWnd__GetClientClipRect_x                                 0x922070
#define CXWnd__GetScreenClipRect_x                                 0x922140
#define CXWnd__GetScreenRect_x                                     0x922300
#define CXWnd__GetRelativeRect_x                                   0x9223C0
#define CXWnd__GetTooltipRect_x                                    0x9202B0
#define CXWnd__GetWindowTextA_x                                    0x49CF80
#define CXWnd__IsActive_x                                          0x9209F0
#define CXWnd__IsDescendantOf_x                                    0x922D00
#define CXWnd__IsReallyVisible_x                                   0x922D30
#define CXWnd__IsType_x                                            0x924510
#define CXWnd__Move_x                                              0x922DA0
#define CXWnd__Move1_x                                             0x922E50
#define CXWnd__ProcessTransition_x                                 0x923930
#define CXWnd__Refade_x                                            0x923120
#define CXWnd__Resize_x                                            0x9233B0
#define CXWnd__Right_x                                             0x923BC0
#define CXWnd__SetFocus_x                                          0x923760
#define CXWnd__SetFont_x                                           0x9237D0
#define CXWnd__SetKeyTooltip_x                                     0x924330
#define CXWnd__SetMouseOver_x                                      0x921220
#define CXWnd__StartFade_x                                         0x922BE0
#define CXWnd__GetChildItem_x                                      0x924010
#define CXWnd__SetParent_x                                         0x922AA0
#define CXWnd__Minimize_x                                          0x923420

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95A670

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x926D50
#define CXWndManager__DrawWindows_x                                0x926D70
#define CXWndManager__GetKeyboardFlags_x                           0x929530
#define CXWndManager__HandleKeyboardMsg_x                          0x9290E0
#define CXWndManager__RemoveWnd_x                                  0x929760
#define CXWndManager__RemovePendingDeletionWnd_x                   0x929CE0

// CDBStr
#define CDBStr__GetString_x                                        0x547350

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFFB0
#define EQ_Character__Cur_HP_x                                     0x4D3110
#define EQ_Character__Cur_Mana_x                                   0x4DA810
#define EQ_Character__GetCastingTimeModifier_x                     0x4C3010
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3940
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3A90
#define EQ_Character__GetHPRegen_x                                 0x4E06E0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0CE0
#define EQ_Character__GetManaRegen_x                               0x4E1120
#define EQ_Character__Max_Endurance_x                              0x65EC20
#define EQ_Character__Max_HP_x                                     0x4D2F40
#define EQ_Character__Max_Mana_x                                   0x65EA20
#define EQ_Character__doCombatAbility_x                            0x661010
#define EQ_Character__UseSkill_x                                   0x4E2F20
#define EQ_Character__GetConLevel_x                                0x6573A0
#define EQ_Character__IsExpansionFlag_x                            0x5BA890
#define EQ_Character__TotalEffect_x                                0x4C6DB0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3D60
#define EQ_Character__SpellDuration_x                              0x4C3890
#define EQ_Character__MySpellDuration_x                            0x4B2270
#define EQ_Character__GetAdjustedSkill_x                           0x4D5E90
#define EQ_Character__GetBaseSkill_x                               0x4D6E30
#define EQ_Character__CanUseItem_x                                 0x4DAB20

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD930

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x674F10

//PcClient
#define PcClient__vftable_x                                        0xAF21BC
#define PcClient__PcClient_x                                       0x654B10

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA9E0
#define CCharacterListWnd__EnterWorld_x                            0x4BA3B0
#define CCharacterListWnd__Quit_x                                  0x4BA100
#define CCharacterListWnd__UpdateList_x                            0x4BA5A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x638FF0
#define EQ_Item__CreateItemTagString_x                             0x8977C0
#define EQ_Item__IsStackable_x                                     0x89C4D0
#define EQ_Item__GetImageNum_x                                     0x899390
#define EQ_Item__CreateItemClient_x                                0x638220
#define EQ_Item__GetItemValue_x                                    0x89A670
#define EQ_Item__ValueSellMerchant_x                               0x89DE60
#define EQ_Item__IsKeyRingItem_x                                   0x89BDD0
#define EQ_Item__CanGoInBag_x                                      0x639110
#define EQ_Item__IsEmpty_x                                         0x89B950
#define EQ_Item__GetMaxItemCount_x                                 0x89AA90
#define EQ_Item__GetHeldItem_x                                     0x899260
#define EQ_Item__GetAugmentFitBySlot_x                             0x897010

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565D80
#define EQ_LoadingS__Array_x                                       0xC13128

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65F520
#define EQ_PC__GetAlternateAbilityId_x                             0x8A72C0
#define EQ_PC__GetCombatAbility_x                                  0x8A7930
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A79A0
#define EQ_PC__GetItemRecastTimer_x                                0x661590
#define EQ_PC__HasLoreItem_x                                       0x657C10
#define EQ_PC__AlertInventoryChanged_x                             0x656CE0
#define EQ_PC__GetPcZoneClient_x                                   0x684060
#define EQ_PC__RemoveMyAffect_x                                    0x6647C0
#define EQ_PC__GetKeyRingItems_x                                   0x8A8270
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A7FF0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8570

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C0CC0
#define EQItemList__add_object_x                                   0x5EE380
#define EQItemList__add_item_x                                     0x5C1220
#define EQItemList__delete_item_x                                  0x5C1270
#define EQItemList__FreeItemList_x                                 0x5C1170

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543EA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x676810
#define EQPlayer__dEQPlayer_x                                      0x669B60
#define EQPlayer__DoAttack_x                                       0x67E800
#define EQPlayer__EQPlayer_x                                       0x66A220
#define EQPlayer__SetNameSpriteState_x                             0x66E520
#define EQPlayer__SetNameSpriteTint_x                              0x66F400
#define PlayerBase__HasProperty_j_x                                0x9893D0
#define EQPlayer__IsTargetable_x                                   0x989870
#define EQPlayer__CanSee_x                                         0x9896D0
#define EQPlayer__CanSee1_x                                        0x9897A0
#define PlayerBase__GetVisibilityLineSegment_x                     0x989490

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x681B00
#define PlayerZoneClient__GetLevel_x                               0x6840A0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EF4F0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55EBB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6796F0
#define EQPlayerManager__GetSpawnByName_x                          0x6797A0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x679830

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63C8A0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63C920
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63C960
#define KeypressHandler__ClearCommandStateArray_x                  0x63DD50
#define KeypressHandler__HandleKeyDown_x                           0x63DD70
#define KeypressHandler__HandleKeyUp_x                             0x63DE10
#define KeypressHandler__SaveKeymapping_x                          0x63E260

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7754C0
#define MapViewMap__SaveEx_x                                       0x778880
#define MapViewMap__SetZoom_x                                      0x77CF40

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB8F0

// StringTable 
#define StringTable__getString_x                                   0x8B6710

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x664430
#define PcZoneClient__RemovePetEffect_x                            0x664A60
#define PcZoneClient__HasAlternateAbility_x                        0x65E850
#define PcZoneClient__GetCurrentMod_x                              0x4E6030
#define PcZoneClient__GetModCap_x                                  0x4E5F30
#define PcZoneClient__CanEquipItem_x                               0x65EF00
#define PcZoneClient__GetItemByID_x                                0x661A00
#define PcZoneClient__GetItemByItemClass_x                         0x661B50
#define PcZoneClient__RemoveBuffEffect_x                           0x664A80
#define PcZoneClient__BandolierSwap_x                              0x65FAE0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x661530

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F4070

//IconCache
#define IconCache__GetIcon_x                                       0x717190

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70ECA0
#define CContainerMgr__CloseContainer_x                            0x70EF70
#define CContainerMgr__OpenExperimentContainer_x                   0x70F9F0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CDCA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6311C0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76B9D0
#define CLootWnd__RequestLootSlot_x                                0x76ACB0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D6A0
#define EQ_Spell__SpellAffects_x                                   0x58DB10
#define EQ_Spell__SpellAffectBase_x                                0x58D8D0
#define EQ_Spell__IsStackable_x                                    0x4CAB50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA9A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7C20
#define EQ_Spell__IsSPAStacking_x                                  0x58E960
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DE70
#define EQ_Spell__IsNoRemove_x                                     0x4CAB30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E970
#define __IsResEffectSpell_x                                       0x4C9DE0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD550

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C6030

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814A80
#define CTargetWnd__WndNotification_x                              0x8142C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x814590
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813430

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8190E0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81BD10

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5418D0
#define CTaskManager__HandleMessage_x                              0x53FD30
#define CTaskManager__GetTaskStatus_x                              0x541980
#define CTaskManager__GetElementDescription_x                      0x541A00

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x588760
#define EqSoundManager__PlayScriptMp3_x                            0x588A20
#define EqSoundManager__SoundAssistPlay_x                          0x69C460
#define EqSoundManager__WaveInstancePlay_x                         0x69B9D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532CB0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x945170
#define CTextureAnimation__Draw_x                                  0x945370

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x941170

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D8A0
#define CAltAbilityData__GetMercMaxRank_x                          0x56D830
#define CAltAbilityData__GetMaxRank_x                              0x562CD0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62F2E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA980
#define CharacterBase__CreateItemGlobalIndex_x                     0x519820
#define CharacterBase__CreateItemIndex_x                           0x6373D0
#define CharacterBase__GetItemPossession_x                         0x505720
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE680
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE6E0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F5BB0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F63E0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6490

//messages
#define msg_spell_worn_off_x                                       0x5B29F0
#define msg_new_text_x                                             0x5A73A0
#define __msgTokenTextParam_x                                      0x5B4C90
#define msgTokenText_x                                             0x5B4EE0

//SpellManager
#define SpellManager__vftable_x                                    0xADA544
#define SpellManager__SpellManager_x                               0x69F790
#define Spellmanager__LoadTextSpells_x                             0x6A0080
#define SpellManager__GetSpellByGroupAndRank_x                     0x69F960

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98D300

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519E70
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8E40
#define ItemGlobalIndex__IsEquippedLocation_x                      0x650280
#define ItemGlobalIndex__IsValidIndex_x                            0x519F00

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C69D0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6C50

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764290

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7133A0
#define CCursorAttachment__AttachToCursor1_x                       0x7133E0
#define CCursorAttachment__Deactivate_x                            0x7143C0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x937F10
#define CSidlManagerBase__CreatePageWnd_x                          0x937700
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x933980
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933910

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x955010
#define CEQSuiteTextureLoader__GetTexture_x                        0x954CD0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516DA0
#define CFindItemWnd__WndNotification_x                            0x517880
#define CFindItemWnd__Update_x                                     0x5183F0
#define CFindItemWnd__PickupSelectedItem_x                         0x5165D0

//IString
#define IString__Append_x                                          0x506FC0

//Camera
#define CDisplay__cameraType_x                                     0xDEB290
#define EverQuest__Cameras_x                                       0xEA6098

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F860
#define LootFiltersManager__GetItemFilterData_x                    0x51F160
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51F190
#define LootFiltersManager__SetItemLootFilter_x                    0x51F3B0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BBAF0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x992EC0
#define CResolutionHandler__GetWindowedStyle_x                     0x696FF0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70B8E0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DBFB0
#define CDistillerInfo__Instance_x                                 0x8DBF50

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72A7A0
#define CGroupWnd__UpdateDisplay_x                                 0x729AF0

//ItemBase
#define ItemBase__IsLore_x                                         0x89BE80
#define ItemBase__IsLoreEquipped_x                                 0x89BF00

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EE2E0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EE420
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EE480

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C750
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6900B0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D440

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F94A0
#define FactionManagerClient__HandleFactionMessage_x               0x4F9B10
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FA0D0
#define FactionManagerClient__GetMaxFaction_x                      0x4FA0EF
#define FactionManagerClient__GetMinFaction_x                      0x4FA0A0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5056F0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91C5C0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C260

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5059D0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CD40

//CTargetManager
#define CTargetManager__Get_x                                      0x6A2FA0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C750

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A90C0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1110

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF43730

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BF640
#define CAAWnd__UpdateSelected_x                                   0x6BBEC0
#define CAAWnd__Update_x                                           0x6BE970

//CXRect
#define CXRect__operator_and_x                                     0x7218E0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4832E0

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
