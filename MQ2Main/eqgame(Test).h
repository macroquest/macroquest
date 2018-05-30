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
#define __ExpectedVersionDate                                     "May 18 2018"
#define __ExpectedVersionTime                                     "12:42:49"
#define __ActualVersionDate_x                                      0xABF334
#define __ActualVersionTime_x                                      0xABF328

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x609140
#define __MemChecker1_x                                            0x8DB9A0
#define __MemChecker2_x                                            0x697480
#define __MemChecker3_x                                            0x6973D0
#define __MemChecker4_x                                            0x834020
#define __EncryptPad0_x                                            0xBF3490
#define __EncryptPad1_x                                            0xC51158
#define __EncryptPad2_x                                            0xC04018
#define __EncryptPad3_x                                            0xC03C18
#define __EncryptPad4_x                                            0xC41F08
#define __EncryptPad5_x                                            0xF0EAFC
#define __AC1_x                                                    0x7F03D6
#define __AC2_x                                                    0x5C51FF
#define __AC3_x                                                    0x5CC08F
#define __AC4_x                                                    0x5CFF10
#define __AC5_x                                                    0x5D6150
#define __AC6_x                                                    0x5DA692
#define __AC7_x                                                    0x5C4C70
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1ADAB8

// Direct Input
#define DI8__Main_x                                                0xF0EB20
#define DI8__Keyboard_x                                            0xF0EB24
#define DI8__Mouse_x                                               0xF0EAE8
#define DI8__Mouse_Copy_x                                          0xE6C874
#define DI8__Mouse_Check_x                                         0xF0F9E8
#define __AutoSkillArray_x                                         0xE6D784
#define __Attack_x                                                 0xF0B563
#define __Autofire_x                                               0xF0B564
#define __BindList_x                                               0xBE2088
#define g_eqCommandStates_x                                        0xBE2DF8
#define __Clicks_x                                                 0xE6C92C
#define __CommandList_x                                            0xBE39B0
#define __CurrentMapLabel_x                                        0x102110C
#define __CurrentSocial_x                                          0xBCD710
#define __DoAbilityList_x                                          0xEA3084
#define __do_loot_x                                                0x592A40
#define __DrawHandler_x                                            0x169C608
#define __GroupCount_x                                             0xE5F21A
#define __Guilds_x                                                 0xE63080
#define __gWorld_x                                                 0xE5D074
#define __HWnd_x                                                   0xF0EAEC
#define __heqmain_x                                                0x1019D44
#define __InChatMode_x                                             0xE6C85C
#define __LastTell_x                                               0xE6E780
#define __LMouseHeldTime_x                                         0xE6C998
#define __Mouse_x                                                  0xF0EB08
#define __MouseLook_x                                              0xE6C8F2
#define __MouseEventTime_x                                         0xF0C018
#define __gpbCommandEvent_x                                        0xE5CB98
#define __NetStatusToggle_x                                        0xE6C8F5
#define __PCNames_x                                                0xE6DD40
#define __RangeAttackReady_x                                       0xE6DA68
#define __RMouseHeldTime_x                                         0xE6C994
#define __RunWalkState_x                                           0xE6C860
#define __ScreenMode_x                                             0xDAB3E0
#define __ScreenX_x                                                0xE6C814
#define __ScreenY_x                                                0xE6C810
#define __ScreenXMax_x                                             0xE6C818
#define __ScreenYMax_x                                             0xE6C81C
#define __ServerHost_x                                             0xE5CD63
#define __ServerName_x                                             0xEA3044
#define __ShiftKeyDown_x                                           0xE6CEEC
#define __ShowNames_x                                              0xE6DC20
#define __Socials_x                                                0xEA3144
#define __SubscriptionType_x                                       0x1062BEC
#define __TargetAggroHolder_x                                      0x1023ADC
#define __ZoneType_x                                               0xE6CCF0
#define __GroupAggro_x                                             0x1023B1C
#define __LoginName_x                                              0xF0F47C
#define __Inviter_x                                                0xF0B4E0
#define __AttackOnAssist_x                                         0xE6DBDC
#define __UseTellWindows_x                                         0xE6DED8
#define __gfMaxZoomCameraDistance_x                                0xAB4AF8
#define __gfMaxCameraDistance_x                                    0xAE1C00
#define __pulAutoRun_x                                             0xE6C910
#define __pulForward_x                                             0xE6DF10
#define __pulBackward_x                                            0xE6DF14
#define __pulTurnRight_x                                           0xE6DF18
#define __pulTurnLeft_x                                            0xE6DF1C
#define __pulStrafeLeft_x                                          0xE6DF20
#define __pulStrafeRight_x                                         0xE6DF24

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5F428
#define instEQZoneInfo_x                                           0xE6CAE8
#define instKeypressHandler_x                                      0xF0BFC8
#define pinstActiveBanker_x                                        0xE5F1B8
#define pinstActiveCorpse_x                                        0xE5F1B0
#define pinstActiveGMaster_x                                       0xE5F1B4
#define pinstActiveMerchant_x                                      0xE5F1AC
#define pinstAggroInfo_x                                           0xC677D0
#define pinstAltAdvManager_x                                       0xDABDC8
#define pinstAuraMgr_x                                             0xC784B8
#define pinstBandageTarget_x                                       0xE5F1C8
#define pinstCamActor_x                                            0xDAB3D0
#define pinstCDBStr_x                                              0xDAAB24
#define pinstCDisplay_x                                            0xE5F410
#define pinstCEverQuest_x                                          0xF0EC40
#define pinstEverQuestInfo_x                                       0xE6C808
#define pinstCharData_x                                            0xE5F420
#define pinstCharSpawn_x                                           0xE5F204
#define pinstControlledMissile_x                                   0xE5CB18
#define pinstControlledPlayer_x                                    0xE5F204
#define pinstCResolutionHandler_x                                  0x169C838
#define pinstCSidlManager_x                                        0x169B6CC
#define pinstCXWndManager_x                                        0x169B6C0
#define instDynamicZone_x                                          0xE62F58
#define pinstDZMember_x                                            0xE63068
#define pinstDZTimerInfo_x                                         0xE6306C
#define pinstEQItemList_x                                          0xE5B618
#define pinstEQObjectList_x                                        0xE5C808
#define instEQMisc_x                                               0xDAAA60
#define pinstEQSoundManager_x                                      0xDAC628
#define pinstEQSpellStrings_x                                      0xC75908
#define instExpeditionLeader_x                                     0xE62FA2
#define instExpeditionName_x                                       0xE62FE2
#define pinstGroup_x                                               0xE5F216
#define pinstImeManager_x                                          0x169B6C4
#define pinstLocalPlayer_x                                         0xE5F1A8
#define pinstMercenaryData_x                                       0xF0C7B8
#define pinstMercenaryStats_x                                      0x1023C28
#define pinstMercAltAbilities_x                                    0xDAC398
#define pinstModelPlayer_x                                         0xE5F1C0
#define pinstPCData_x                                              0xE5F420
#define pinstRealEstateItems_x                                     0xF0DCA8
#define pinstSkillMgr_x                                            0xF0DD78
#define pinstSpawnManager_x                                        0xF0D368
#define pinstSpellManager_x                                        0xF0DF50
#define pinstSpellSets_x                                           0xF0418C
#define pinstStringTable_x                                         0xE5F07C
#define pinstSwitchManager_x                                       0xE5C9C8
#define pinstTarget_x                                              0xE5F1FC
#define pinstTargetObject_x                                        0xE5F40C
#define pinstTargetSwitch_x                                        0xE5CB38
#define pinstTaskMember_x                                          0xDAA8F0
#define pinstTrackTarget_x                                         0xE5F408
#define pinstTradeTarget_x                                         0xE5F1BC
#define instTributeActive_x                                        0xDAAA85
#define pinstViewActor_x                                           0xDAB3CC
#define pinstWorldData_x                                           0xE5CE6C
#define pinstZoneAddr_x                                            0xE6CD88
#define pinstPlayerPath_x                                          0xF0D400
#define pinstTargetIndicator_x                                     0xF0E1B8
#define pinstCTargetManager_x                                      0xF0E250
#define EQObject_Top_x                                             0xE5F1A4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDAABF0
#define pinstCAchievementsWnd_x                                    0xDAAE8C
#define pinstCActionsWnd_x                                         0xDAAE48
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDAB44C
#define pinstCAdvancedLootWnd_x                                    0xDAB400
#define pinstCAdventureLeaderboardWnd_x                            0x101A8E0
#define pinstCAdventureRequestWnd_x                                0x101A990
#define pinstCAdventureStatsWnd_x                                  0x101AA40
#define pinstCAggroMeterWnd_x                                      0xDAAEB8
#define pinstCAlarmWnd_x                                           0xDAAE68
#define pinstCAlertHistoryWnd_x                                    0xDAAE44
#define pinstCAlertStackWnd_x                                      0xDAABC8
#define pinstCAlertWnd_x                                           0xDAABEC
#define pinstCAltStorageWnd_x                                      0x101ADA0
#define pinstCAudioTriggersWindow_x                                0xC67C60
#define pinstCAuraWnd_x                                            0xDAAEB0
#define pinstCAvaZoneWnd_x                                         0xDAAE2C
#define pinstCBandolierWnd_x                                       0xDAB368
#define pinstCBankWnd_x                                            0xDAB410
#define pinstCBarterMerchantWnd_x                                  0x101BFE0
#define pinstCBarterSearchWnd_x                                    0x101C090
#define pinstCBarterWnd_x                                          0x101C140
#define pinstCBazaarConfirmationWnd_x                              0xDAABC4
#define pinstCBazaarSearchWnd_x                                    0xDAAE5C
#define pinstCBazaarWnd_x                                          0xDAAF58
#define pinstCBlockedBuffWnd_x                                     0xDAB3FC
#define pinstCBlockedPetBuffWnd_x                                  0xDAB420
#define pinstCBodyTintWnd_x                                        0xDAABF8
#define pinstCBookWnd_x                                            0xDAB3A4
#define pinstCBreathWnd_x                                          0xDAAC00
#define pinstCBuffWindowNORMAL_x                                   0xDAB3B8
#define pinstCBuffWindowSHORT_x                                    0xDAB3BC
#define pinstCBugReportWnd_x                                       0xDAABD4
#define pinstCButtonWnd_x                                          0x169B8B8
#define pinstCCastingWnd_x                                         0xDAABD0
#define pinstCCastSpellWnd_x                                       0xDAAE74
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDAAC04
#define pinstCChatWindowManager_x                                  0x101CC00
#define pinstCClaimWnd_x                                           0x101CD58
#define pinstCColorPickerWnd_x                                     0xDAAE20
#define pinstCCombatAbilityWnd_x                                   0xDAAEB4
#define pinstCCombatSkillsSelectWnd_x                              0xDAAE4C
#define pinstCCompassWnd_x                                         0xDAABE4
#define pinstCConfirmationDialog_x                                 0x1021C58
#define pinstCContainerMgr_x                                       0xDAB360
#define pinstCContextMenuManager_x                                 0x169B680
#define pinstCCursorAttachment_x                                   0xDAABC0
#define pinstCDynamicZoneWnd_x                                     0x101D320
#define pinstCEditLabelWnd_x                                       0xDAB3B0
#define pinstCEQMainWnd_x                                          0x101D568
#define pinstCEventCalendarWnd_x                                   0xDAAEA8
#define pinstCExtendedTargetWnd_x                                  0xDAAEA4
#define pinstCFacePick_x                                           0xDAAE28
#define pinstCFellowshipWnd_x                                      0x101D768
#define pinstCFileSelectionWnd_x                                   0xDAB3E4
#define pinstCFindItemWnd_x                                        0xDAAEC4
#define pinstCFindLocationWnd_x                                    0x101D8C0
#define pinstCFriendsWnd_x                                         0xDAAE64
#define pinstCGemsGameWnd_x                                        0xDAAE40
#define pinstCGiveWnd_x                                            0xDAB378
#define pinstCGroupSearchFiltersWnd_x                              0xDAAED0
#define pinstCGroupSearchWnd_x                                     0x101DCB8
#define pinstCGroupWnd_x                                           0x101DD68
#define pinstCGuildBankWnd_x                                       0xE6DBC4
#define pinstCGuildCreationWnd_x                                   0x101DEC8
#define pinstCGuildMgmtWnd_x                                       0x101DF78
#define pinstCharacterCreation_x                                   0xDAAEC0
#define pinstCHelpWnd_x                                            0xDAAE80
#define pinstCHeritageSelectionWnd_x                               0xDAAE38
#define pinstCHotButtonWnd_x                                       0x10200D0
#define pinstCHotButtonWnd1_x                                      0x10200D0
#define pinstCHotButtonWnd2_x                                      0x10200D4
#define pinstCHotButtonWnd3_x                                      0x10200D8
#define pinstCHotButtonWnd4_x                                      0x10200DC
#define pinstCIconSelectionWnd_x                                   0xDAB428
#define pinstCInspectWnd_x                                         0xDAB41C
#define pinstCInventoryWnd_x                                       0xDAB364
#define pinstCInvSlotMgr_x                                         0xDAAEA0
#define pinstCItemDisplayManager_x                                 0x1020660
#define pinstCItemExpTransferWnd_x                                 0x1020794
#define pinstCItemOverflowWnd_x                                    0xDAAE60
#define pinstCJournalCatWnd_x                                      0xDAB414
//#define pinstCJournalNPCWnd_x                                      0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDAB3B4
#define pinstCKeyRingWnd_x                                         0xDAB3C4
#define pinstCLargeDialogWnd_x                                     0x10228D8
#define pinstCLayoutCopyWnd_x                                      0x1020AE0
#define pinstCLFGuildWnd_x                                         0x1020B90
#define pinstCLoadskinWnd_x                                        0xDAAE58
#define pinstCLootFiltersCopyWnd_x                                 0xC78C98
#define pinstCLootFiltersWnd_x                                     0xDAAC08
#define pinstCLootSettingsWnd_x                                    0xDAAE18
#define pinstCLootWnd_x                                            0xDAAE10
#define pinstCMailAddressBookWnd_x                                 0xDAB430
#define pinstCMailCompositionWnd_x                                 0xDAB418
#define pinstCMailIgnoreListWnd_x                                  0xDAB438
#define pinstCMailWnd_x                                            0xDAB3E8
#define pinstCManageLootWnd_x                                      0xDAC240
#define pinstCMapToolbarWnd_x                                      0xDAB370
#define pinstCMapViewWnd_x                                         0xDAAED8
#define pinstCMarketplaceWnd_x                                     0xDAAEC8
#define pinstCMerchantWnd_x                                        0xDAAE3C
#define pinstCMIZoneSelectWnd_x                                    0x10213C8
#define pinstCMusicPlayerWnd_x                                     0xDAB3D4
#define pinstCNameChangeMercWnd_x                                  0xDAB404
#define pinstCNameChangePetWnd_x                                   0xDAB3C8
#define pinstCNameChangeWnd_x                                      0xDAAEAC
#define pinstCNoteWnd_x                                            0xDAAE78
#define pinstCObjectPreviewWnd_x                                   0xDAB37C
#define pinstCOptionsWnd_x                                         0xDAB36C
#define pinstCPetInfoWnd_x                                         0xDAB40C
#define pinstCPetitionQWnd_x                                       0xDAB424
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDAABF4
#define pinstCPlayerWnd_x                                          0xDAAE70
#define pinstCPopupWndManager_x                                    0x1021C58
#define pinstCProgressionSelectionWnd_x                            0x1021D08
#define pinstCPurchaseGroupWnd_x                                   0xDAB3C0
#define pinstCPurchaseWnd_x                                        0xDAB3A0
#define pinstCPvPLeaderboardWnd_x                                  0x1021DB8
#define pinstCPvPStatsWnd_x                                        0x1021E68
#define pinstCQuantityWnd_x                                        0xDAB42C
#define pinstCRaceChangeWnd_x                                      0xDAAEDC
#define pinstCRaidOptionsWnd_x                                     0xDAAED4
#define pinstCRaidWnd_x                                            0xDAB444
#define pinstCRealEstateItemsWnd_x                                 0xDAAE94
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDAAEBC
#define pinstCRealEstateManageWnd_x                                0xDAAE30
#define pinstCRealEstateNeighborhoodWnd_x                          0xDAAE50
#define pinstCRealEstatePlotSearchWnd_x                            0xDAAE6C
#define pinstCRealEstatePurchaseWnd_x                              0xDAAE7C
#define pinstCRespawnWnd_x                                         0xDAAECC
//#define pinstCRewardSelectionWnd_x                                 0x10205B0
#define pinstCSelectorWnd_x                                        0xDAAE9C
#define pinstCSendMoneyWnd_x                                       0xDAB3AC
#define pinstCServerListWnd_x                                      0xDAAE90
#define pinstCSkillsSelectWnd_x                                    0xDAAE24
#define pinstCSkillsWnd_x                                          0xDAAE14
#define pinstCSocialEditWnd_x                                      0xDAB440
#define pinstCSocialWnd_x                                          0xDAB434
#define pinstCSpellBookWnd_x                                       0xDAAE98
#define pinstCStoryWnd_x                                           0xDAABCC
#define pinstCTargetOfTargetWnd_x                                  0x1023CB0
#define pinstCTargetWnd_x                                          0xDAB408
#define pinstCTaskOverlayWnd_x                                     0xDAAE54
#define pinstCTaskSelectWnd_x                                      0x1023E08
#define pinstCTaskSomething_x                                      0xC79498
#define pinstCTaskTemplateSelectWnd_x                              0x1023EB8
#define pinstCTaskWnd_x                                            0x1023F68
#define pinstCTextEntryWnd_x                                       0xDAABE8
#define pinstCTextOverlay_x                                        0xC67F70
#define pinstCTimeLeftWnd_x                                        0xDAB3F4
#define pinstCTipWndCONTEXT_x                                      0x102416C
#define pinstCTipWndOFDAY_x                                        0x1024168
#define pinstCTitleWnd_x                                           0x1024218
#define pinstCTrackingWnd_x                                        0xDAB3F8
#define pinstCTradeskillWnd_x                                      0x1024380
#define pinstCTradeWnd_x                                           0xDAAE84
#define pinstCTrainWnd_x                                           0xDAB43C
#define pinstCTributeBenefitWnd_x                                  0x1024580
#define pinstCTributeMasterWnd_x                                   0x1024630
#define pinstCTributeTrophyWnd_x                                   0x10246E0
#define pinstCVideoModesWnd_x                                      0xDAB448
#define pinstCVoiceMacroWnd_x                                      0xF0E780
#define pinstCVoteResultsWnd_x                                     0xDAB3A8
#define pinstCVoteWnd_x                                            0xDAB374
#define pinstCWebManager_x                                         0xF0E8E4
#define pinstCZoneGuideWnd_x                                       0xDAAE1C
#define pinstCZonePathWnd_x                                        0xDAAE34

#define pinstEQSuiteTextureLoader_x                                0xC52C10
#define pinstItemIconCache_x                                       0x101D520
#define pinstLootFiltersManager_x                                  0xC78D48
#define pinstRewardSelectionWnd_x                                  0x10225B0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC03C0C
#define __CastRay_x                                                0x58DF60
#define __CastRay2_x                                               0x58DFB0
#define __ConvertItemTags_x                                        0x5A8B90
#define __CrashHandler_x                                           0x83D950
#define __EQGetTime_x                                              0x8DB2D0
#define __ExecuteCmd_x                                             0x5868F0
#define __FixHeading_x                                             0x96BAA0
#define __get_bearing_x                                            0x58DAA0
#define __get_melee_range_x                                        0x58E1A0
#define __GetAnimationCache_x                                      0x6FAAA0
#define __GetGaugeValueFromEQ_x                                    0x7EEBF0
#define __GetLabelFromEQ_x                                         0x7F0360
#define __GetXTargetType_x                                         0x96D550
#define __HeadingDiff_x                                            0x96BB10
#define __HelpPath_x                                               0xF0BC34
#define __LoadFrontEnd_x                                           0x6932C0
#define __NewUIINI_x                                               0x7EE8C0
#define __pCrashHandler_x                                          0x1041A48
#define __ProcessGameEvents_x                                      0x5EAF80
#define __ProcessMouseEvent_x                                      0x5EA740
#define __SaveColors_x                                             0x538080
#define __STMLToText_x                                             0x90F1F0
#define __ToggleKeyRingItem_x                                      0x4FB4C0
#define CrashDetected_x                                            0x694DB0
#define DrawNetStatus_x                                            0x6167A0
#define Expansion_HoT_x                                            0xE6DBCC
#define Teleport_Table_Size_x                                      0xE5CC20
#define Teleport_Table_x                                           0xE5D078
#define Util__FastTime_x                                           0x8DAE90
#define wwsCrashReportCheckForUploader_x                           0x83E400
#define wwsCrashReportPlatformLaunchUploader_x                     0x840AE0
#define __SaveColors_x                                             0x538080

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A8E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4936C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4934A0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53F660
#define AltAdvManager__IsAbilityReady_x                            0x53E720
#define AltAdvManager__GetAAById_x                                 0x53E920
#define AltAdvManager__CanTrainAbility_x                           0x53E990
#define AltAdvManager__CanSeeAbility_x                             0x53EBC0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C5CF0
#define CharacterZoneClient__HasSkill_x                            0x4D0E80
#define CharacterZoneClient__MakeMeVisible_x                       0x4D25A0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA090
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B6760
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4AF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4BD0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D4CB0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BEB80
#define CharacterZoneClient__BardCastBard_x                        0x4C1800
#define CharacterZoneClient__GetMaxEffects_x                       0x4B6830
#define CharacterZoneClient__GetEffect_x                           0x4B66A0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4BFB90
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4BFC60
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4BFCB0
#define CharacterZoneClient__CalcAffectChange_x                    0x4BFE00
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4BFFD0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BD550

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CAF40

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F8F80
#define CButtonWnd__CButtonWnd_x                                   0x90B5E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6E94D0
#define CChatManager__InitContextMenu_x                            0x6E3920
#define CChatManager__FreeChatWindow_x                             0x6E8460
#define CChatManager__GetLockedActiveChatWindow_x                  0x6ECD80
#define CChatManager__SetLockedActiveChatWindow_x                  0x6E9270

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x91FE00
#define CContextMenu__dCContextMenu_x                              0x920030
#define CContextMenu__AddMenuItem_x                                0x920040
#define CContextMenu__RemoveMenuItem_x                             0x920350
#define CContextMenu__RemoveAllMenuItems_x                         0x920370
#define CContextMenu__CheckMenuItem_x                              0x9203F0
#define CContextMenu__SetMenuItem_x                                0x920270

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x920990
#define CContextMenuManager__RemoveMenu_x                          0x920A00
#define CContextMenuManager__PopupMenu_x                           0x920AC0
#define CContextMenuManager__Flush_x                               0x920930
#define CContextMenuManager__GetMenu_x                             0x495600

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BD9F0
#define CChatService__GetFriendName_x                              0x8BDA00

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6E9A40
#define CChatWindow__Clear_x                                       0x6EAAA0
#define CChatWindow__WndNotification_x                             0x6EB010

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91D280
#define CComboWnd__Draw_x                                          0x91C760
#define CComboWnd__GetCurChoice_x                                  0x91D0C0
#define CComboWnd__GetListRect_x                                   0x91CC20
#define CComboWnd__GetTextRect_x                                   0x91D2F0
#define CComboWnd__InsertChoice_x                                  0x91CDB0
#define CComboWnd__SetColors_x                                     0x91CD80
#define CComboWnd__SetChoice_x                                     0x91D090
#define CComboWnd__GetItemCount_x                                  0x91D0D0
#define CComboWnd__GetCurChoiceText_x                              0x91D110

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F2C70
#define CContainerWnd__vftable_x                                   0xAC8718

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x537E40
#define CDisplay__GetClickedActor_x                                0x52AE90
#define CDisplay__GetUserDefinedColor_x                            0x523590
#define CDisplay__GetWorldFilePath_x                               0x52C8E0
#define CDisplay__is3dON_x                                         0x527B80
#define CDisplay__ReloadUI_x                                       0x532000
#define CDisplay__WriteTextHD2_x                                   0x527960
#define CDisplay__TrueDistance_x                                   0x52E540
#define CDisplay__SetViewActor_x                                   0x52A7E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93F5A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x924500
#define CEditWnd__GetCharIndexPt_x                                 0x925400
#define CEditWnd__GetDisplayString_x                               0x9252A0
#define CEditWnd__GetHorzOffset_x                                  0x923B30
#define CEditWnd__GetLineForPrintableChar_x                        0x926540
#define CEditWnd__GetSelStartPt_x                                  0x9256B0
#define CEditWnd__GetSTMLSafeText_x                                0x9250C0
#define CEditWnd__PointFromPrintableChar_x                         0x926170
#define CEditWnd__SelectableCharFromPoint_x                        0x9262E0
#define CEditWnd__SetEditable_x                                    0x925780

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5D9BC0
#define CEverQuest__ClickedPlayer_x                                0x5CBE70
#define CEverQuest__CreateTargetIndicator_x                        0x5E8260
#define CEverQuest__DeleteTargetIndicator_x                        0x5E82F0
#define CEverQuest__DoTellWindow_x                                 0x4E0E50
#define CEverQuest__OutputTextToLog_x                              0x4E1080
#define CEverQuest__DropHeldItemOnGround_x                         0x5C1730
#define CEverQuest__dsp_chat_x                                     0x4E1410
#define CEverQuest__trimName_x                                     0x5E48E0
#define CEverQuest__Emote_x                                        0x5DA3D0
#define CEverQuest__EnterZone_x                                    0x5D4540
#define CEverQuest__GetBodyTypeDesc_x                              0x5DE170
#define CEverQuest__GetClassDesc_x                                 0x5DE7B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DEDB0
#define CEverQuest__GetDeityDesc_x                                 0x5E6C70
#define CEverQuest__GetLangDesc_x                                  0x5DEF70
#define CEverQuest__GetRaceDesc_x                                  0x5DE790
#define CEverQuest__InterpretCmd_x                                 0x5E7240
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C5920
#define CEverQuest__LMouseUp_x                                     0x5C3CA0
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6200
#define CEverQuest__RMouseUp_x                                     0x5C4C30
#define CEverQuest__SetGameState_x                                 0x5C14C0
#define CEverQuest__UPCNotificationFlush_x                         0x5E47E0
#define CEverQuest__IssuePetCommand_x                              0x5E0370
#define CEverQuest__ReportSuccessfulHit_x                          0x5DB070

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x704C30
#define CGaugeWnd__CalcLinesFillRect_x                             0x704C90
#define CGaugeWnd__Draw_x                                          0x704330

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABD10
#define CGuild__GetGuildName_x                                     0x4AAD50
#define CGuild__GetGuildIndex_x                                    0x4AB0E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7201D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72D050
#define CInvSlotMgr__MoveItem_x                                    0x72BD70
#define CInvSlotMgr__SelectSlot_x                                  0x72D120

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72A620
#define CInvSlot__SliderComplete_x                                 0x728450
#define CInvSlot__GetItemBase_x                                    0x727DD0
#define CInvSlot__UpdateItem_x                                     0x727F40

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x72EA70
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72DD40

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EAE70
#define CItemDisplayWnd__UpdateStrings_x                           0x73D6A0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x737800
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x737CD0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73DC30
#define CItemDisplayWnd__AboutToShow_x                             0x73D2F0
#define CItemDisplayWnd__WndNotification_x                         0x73EEF0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x822800

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x742F50

// CLabel 
#define CLabel__Draw_x                                             0x7489B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F58C0
#define CListWnd__dCListWnd_x                                      0x8F5BE0
#define CListWnd__AddColumn_x                                      0x8F9F10
#define CListWnd__AddColumn1_x                                     0x8F9F60
#define CListWnd__AddLine_x                                        0x8FA2F0
#define CListWnd__AddString_x                                      0x8FA0F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8F9CD0
#define CListWnd__CalculateVSBRange_x                              0x8F9AB0
#define CListWnd__ClearSel_x                                       0x8FAAD0
#define CListWnd__ClearAllSel_x                                    0x8FAB30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FB540
#define CListWnd__Compare_x                                        0x8F93F0
#define CListWnd__Draw_x                                           0x8F5CE0
#define CListWnd__DrawColumnSeparators_x                           0x8F84C0
#define CListWnd__DrawHeader_x                                     0x8F8930
#define CListWnd__DrawItem_x                                       0x8F8D30
#define CListWnd__DrawLine_x                                       0x8F8630
#define CListWnd__DrawSeparator_x                                  0x8F8560
#define CListWnd__EnableLine_x                                     0x8F7D90
#define CListWnd__EnsureVisible_x                                  0x8FB460
#define CListWnd__ExtendSel_x                                      0x8FAA00
#define CListWnd__GetColumnMinWidth_x                              0x8F78D0
#define CListWnd__GetColumnWidth_x                                 0x8F7840
#define CListWnd__GetCurSel_x                                      0x8F71D0
#define CListWnd__GetItemAtPoint_x                                 0x8F8010
#define CListWnd__GetItemAtPoint1_x                                0x8F8080
#define CListWnd__GetItemData_x                                    0x8F7250
#define CListWnd__GetItemHeight_x                                  0x8F7610
#define CListWnd__GetItemIcon_x                                    0x8F73E0
#define CListWnd__GetItemRect_x                                    0x8F7E80
#define CListWnd__GetItemText_x                                    0x8F7290
#define CListWnd__GetSelList_x                                     0x8FAB80
#define CListWnd__GetSeparatorRect_x                               0x8F82C0
#define CListWnd__InsertLine_x                                     0x8FA6E0
#define CListWnd__RemoveLine_x                                     0x8FA830
#define CListWnd__SetColors_x                                      0x8F9A80
#define CListWnd__SetColumnJustification_x                         0x8F97B0
#define CListWnd__SetColumnWidth_x                                 0x8F96D0
#define CListWnd__SetCurSel_x                                      0x8FA940
#define CListWnd__SetItemColor_x                                   0x8FB110
#define CListWnd__SetItemData_x                                    0x8FB0D0
#define CListWnd__SetItemText_x                                    0x8FAD00
#define CListWnd__ShiftColumnSeparator_x                           0x8F9870
#define CListWnd__Sort_x                                           0x8F9570
#define CListWnd__ToggleSel_x                                      0x8FA970

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75DE10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7810C0
#define CMerchantWnd__RequestBuyItem_x                             0x7819A0
#define CMerchantWnd__RequestSellItem_x                            0x781ED0
#define CMerchantWnd__SelectRecoverySlot_x                         0x784D00
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x781720
#define CMerchantWnd__ActualSelect_x                               0x78A820

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x889DB0
#define CPacketScrambler__hton_x                                   0x889DA0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x914800
#define CSidlManager__FindScreenPieceTemplate_x                    0x914C10
#define CSidlManager__FindScreenPieceTemplate1_x                   0x914A00
#define CSidlManager__CreateLabel_x                                0x7E2230
#define CSidlManager__CreateXWndFromTemplate_x                     0x917CE0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x917EC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x911370
#define CSidlScreenWnd__CalculateVSBRange_x                        0x911260
#define CSidlScreenWnd__ConvertToRes_x                             0x935E10
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x910CF0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9109E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x910AB0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x910B80
#define CSidlScreenWnd__DrawSidlPiece_x                            0x911810
#define CSidlScreenWnd__EnableIniStorage_x                         0x911CE0
#define CSidlScreenWnd__GetSidlPiece_x                             0x911A00
#define CSidlScreenWnd__Init1_x                                    0x9105D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x911D30
#define CSidlScreenWnd__LoadIniListWnd_x                           0x912870
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90F9D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9123F0
#define CSidlScreenWnd__StoreIniVis_x                              0x912750
#define CSidlScreenWnd__WndNotification_x                          0x911720
#define CSidlScreenWnd__GetChildItem_x                             0x911C60
#define CSidlScreenWnd__HandleLButtonUp_x                          0x901410
#define CSidlScreenWnd__m_layoutCopy_x                             0x169B550

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65CC50
#define CSkillMgr__GetSkillCap_x                                   0x65CE30
#define CSkillMgr__GetNameToken_x                                  0x65C3E0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x921780
#define CSliderWnd__SetValue_x                                     0x9215F0
#define CSliderWnd__SetNumTicks_x                                  0x921650

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E80B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9283F0
#define CStmlWnd__CalculateHSBRange_x                              0x929480
#define CStmlWnd__CalculateVSBRange_x                              0x9293F0
#define CStmlWnd__CanBreakAtCharacter_x                            0x92D7C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92E3B0
#define CStmlWnd__ForceParseNow_x                                  0x928990
#define CStmlWnd__GetNextTagPiece_x                                0x92D720
#define CStmlWnd__GetSTMLText_x                                    0x4EF380
#define CStmlWnd__GetVisibleText_x                                 0x9289B0
#define CStmlWnd__InitializeWindowVariables_x                      0x92E200
#define CStmlWnd__MakeStmlColorTag_x                               0x927B80
#define CStmlWnd__MakeWndNotificationTag_x                         0x927BF0
#define CStmlWnd__SetSTMLText_x                                    0x926C50
#define CStmlWnd__StripFirstSTMLLines_x                            0x92F510
#define CStmlWnd__UpdateHistoryString_x                            0x92E5C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x932C70
#define CTabWnd__DrawCurrentPage_x                                 0x933290
#define CTabWnd__DrawTab_x                                         0x933060
#define CTabWnd__GetCurrentPage_x                                  0x9324D0
#define CTabWnd__GetPageInnerRect_x                                0x932710
#define CTabWnd__GetTabInnerRect_x                                 0x932650
#define CTabWnd__GetTabRect_x                                      0x932500
#define CTabWnd__InsertPage_x                                      0x932900
#define CTabWnd__SetPage_x                                         0x932790
#define CTabWnd__SetPageRect_x                                     0x932BB0
#define CTabWnd__UpdatePage_x                                      0x932F20
#define CTabWnd__GetPageFromTabIndex_x                             0x932FA0
#define CTabWnd__GetCurrentTabIndex_x                              0x9324C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7433B0
#define CPageWnd__SetTabText_x                                     0x93F9B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5840

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FE260
#define CTextureFont__GetTextExtent_x                              0x8FE420

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x690070
#define CHtmlComponentWnd__ValidateUri_x                           0x721B30
#define CHtmlWnd__SetClientCallbacks_x                             0x5FE1A0
#define CHtmlWnd__AddObserver_x                                    0x5FE1C0
#define CHtmlWnd__RemoveObserver_x                                 0x5FE220
#define Window__getProgress_x                                      0x83B5C0
#define Window__getStatus_x                                        0x83B5E0
#define Window__getURI_x                                           0x83B5F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93BF30

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8EB0C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD030
#define CXStr__CXStr1_x                                            0x8F3BB0
#define CXStr__CXStr3_x                                            0x8D7400
#define CXStr__dCXStr_x                                            0x4721C0
#define CXStr__operator_equal_x                                    0x8D7630
#define CXStr__operator_equal1_x                                   0x8D7670
#define CXStr__operator_plus_equal1_x                              0x8D8100

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91FA10
#define CXWnd__BringToTop_x                                        0x904BE0
#define CXWnd__Center_x                                            0x904760
#define CXWnd__ClrFocus_x                                          0x9045A0
#define CXWnd__Destroy_x                                           0x904640
#define CXWnd__DoAllDrawing_x                                      0x900BC0
#define CXWnd__DrawChildren_x                                      0x900B90
#define CXWnd__DrawColoredRect_x                                   0x901020
#define CXWnd__DrawTooltip_x                                       0x8FF6E0
#define CXWnd__DrawTooltipAtPoint_x                                0x8FF7A0
#define CXWnd__GetBorderFrame_x                                    0x900E80
#define CXWnd__GetChildWndAt_x                                     0x904C80
#define CXWnd__GetClientClipRect_x                                 0x902E50
#define CXWnd__GetScreenClipRect_x                                 0x902F20
#define CXWnd__GetScreenRect_x                                     0x9030F0
#define CXWnd__GetTooltipRect_x                                    0x901070
#define CXWnd__GetWindowTextA_x                                    0x496BD0
#define CXWnd__IsActive_x                                          0x907B50
#define CXWnd__IsDescendantOf_x                                    0x903B10
#define CXWnd__IsReallyVisible_x                                   0x903B40
#define CXWnd__IsType_x                                            0x9052F0
#define CXWnd__Move_x                                              0x903BB0
#define CXWnd__Move1_x                                             0x903C60
#define CXWnd__ProcessTransition_x                                 0x904710
#define CXWnd__Refade_x                                            0x903F30
#define CXWnd__Resize_x                                            0x9041B0
#define CXWnd__Right_x                                             0x9049A0
#define CXWnd__SetFocus_x                                          0x904560
#define CXWnd__SetFont_x                                           0x9045D0
#define CXWnd__SetKeyTooltip_x                                     0x905110
#define CXWnd__SetMouseOver_x                                      0x901FC0
#define CXWnd__StartFade_x                                         0x9039E0
#define CXWnd__GetChildItem_x                                      0x904DF0
#define CXWnd__SetParent_x                                         0x9038A0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x936EE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x907B90
#define CXWndManager__DrawWindows_x                                0x907BB0
#define CXWndManager__GetKeyboardFlags_x                           0x90A280
#define CXWndManager__HandleKeyboardMsg_x                          0x909E80
#define CXWndManager__RemoveWnd_x                                  0x90A4C0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x90AA00

// CDBStr
#define CDBStr__GetString_x                                        0x522560

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7710
#define EQ_Character__Cur_HP_x                                     0x4CDF10
#define EQ_Character__Cur_Mana_x                                   0x4D51B0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BA680
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AEA90
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEBE0
#define EQ_Character__GetHPRegen_x                                 0x4DA7A0
#define EQ_Character__GetEnduranceRegen_x                          0x4DADB0
#define EQ_Character__GetManaRegen_x                               0x4DB1F0
#define EQ_Character__Max_Endurance_x                              0x623E60
#define EQ_Character__Max_HP_x                                     0x4CDD40
#define EQ_Character__Max_Mana_x                                   0x623CE0
#define EQ_Character__doCombatAbility_x                            0x625FB0
#define EQ_Character__UseSkill_x                                   0x4DCFE0
#define EQ_Character__GetConLevel_x                                0x61D500
#define EQ_Character__IsExpansionFlag_x                            0x585290
#define EQ_Character__TotalEffect_x                                0x4C0D80
#define EQ_Character__GetPCSpellAffect_x                           0x4BB270
#define EQ_Character__SpellDuration_x                              0x4BADA0
#define EQ_Character__FindItemByRecord_x                           0x4D3510
#define EQ_Character__GetAdjustedSkill_x                           0x4D0C40
#define EQ_Character__GetBaseSkill_x                               0x4D1BE0
#define EQ_Character__CanUseItem_x                                 0x4D54C0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8A8D20

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x639DE0

//PcClient
#define PcClient__PcClient_x                                       0x61ADB0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B54D0
#define CCharacterListWnd__EnterWorld_x                            0x4B4F10
#define CCharacterListWnd__Quit_x                                  0x4B4C20
#define CCharacterListWnd__UpdateList_x                            0x4B50A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5FF3C0
#define EQ_Item__CreateItemTagString_x                             0x884020
#define EQ_Item__IsStackable_x                                     0x888270
#define EQ_Item__GetImageNum_x                                     0x8858C0
#define EQ_Item__CreateItemClient_x                                0x5FE580
#define EQ_Item__GetItemValue_x                                    0x886960
#define EQ_Item__ValueSellMerchant_x                               0x889950
#define EQ_Item__IsKeyRingItem_x                                   0x887C30
#define EQ_Item__CanGoInBag_x                                      0x5FF4E0
#define EQ_Item__GetMaxItemCount_x                                 0x886A60
#define EQ_Item__GetHeldItem_x                                     0x8856D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x883B60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x540410
#define EQ_LoadingS__Array_x                                       0xBDB298

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x624760
#define EQ_PC__GetAlternateAbilityId_x                             0x892910
#define EQ_PC__GetCombatAbility_x                                  0x892F80
#define EQ_PC__GetCombatAbilityTimer_x                             0x892FF0
#define EQ_PC__GetItemRecastTimer_x                                0x626530
#define EQ_PC__HasLoreItem_x                                       0x61DCC0
#define EQ_PC__AlertInventoryChanged_x                             0x61CFC0
#define EQ_PC__GetPcZoneClient_x                                   0x648540
#define EQ_PC__RemoveMyAffect_x                                    0x6296F0
#define EQ_PC__GetKeyRingItems_x                                   0x893890
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x893610
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x893B80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58B500
#define EQItemList__add_object_x                                   0x5B6E90
#define EQItemList__add_item_x                                     0x58BB10
#define EQItemList__delete_item_x                                  0x58BB60
#define EQItemList__FreeItemList_x                                 0x58BA60

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51FA50

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63B660
#define EQPlayer__dEQPlayer_x                                      0x62ED50
#define EQPlayer__DoAttack_x                                       0x643270
#define EQPlayer__EQPlayer_x                                       0x62F400
#define EQPlayer__SetNameSpriteState_x                             0x6336D0
#define EQPlayer__SetNameSpriteTint_x                              0x634560
#define PlayerBase__HasProperty_j_x                                0x969E60
#define EQPlayer__IsTargetable_x                                   0x96A300
#define EQPlayer__CanSee_x                                         0x96A160
#define EQPlayer__CanSee1_x                                        0x96A230
#define PlayerBase__GetVisibilityLineSegment_x                     0x969F20

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x646030
#define PlayerZoneClient__GetLevel_x                               0x648580
#define PlayerZoneClient__IsValidTeleport_x                        0x5B7FE0
#define PlayerZoneClient__LegalPlayerRace_x                        0x539B90

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63E350
#define EQPlayerManager__GetSpawnByName_x                          0x63E370
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63E400

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x602D70
#define KeypressHandler__AttachKeyToEqCommand_x                    0x602DB0
#define KeypressHandler__ClearCommandStateArray_x                  0x6041A0
#define KeypressHandler__HandleKeyDown_x                           0x6041C0
#define KeypressHandler__HandleKeyUp_x                             0x604260
#define KeypressHandler__SaveKeymapping_x                          0x604640

// MapViewMap 
#define MapViewMap__Clear_x                                        0x759CA0
#define MapViewMap__SaveEx_x                                       0x75D040
#define MapViewMap__SetZoom_x                                      0x761710

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A6C10

// StringTable 
#define StringTable__getString_x                                   0x8A1B90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x629360
#define PcZoneClient__RemovePetEffect_x                            0x629990
#define PcZoneClient__HasAlternateAbility_x                        0x623B20
#define PcZoneClient__GetCurrentMod_x                              0x4DFF30
#define PcZoneClient__GetModCap_x                                  0x4DFE30
#define PcZoneClient__CanEquipItem_x                               0x6240F0
#define PcZoneClient__GetItemByID_x                                0x6269B0
#define PcZoneClient__GetItemByItemClass_x                         0x626A40
#define PcZoneClient__RemoveBuffEffect_x                           0x6299B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BCB70

//IconCache
#define IconCache__GetIcon_x                                       0x6FA330

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F1E10
#define CContainerMgr__CloseContainer_x                            0x6F20E0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B4B90

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F7780

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7500D0
#define CLootWnd__RequestLootSlot_x                                0x74F490

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x558970
#define EQ_Spell__SpellAffects_x                                   0x558DE0
#define EQ_Spell__SpellAffectBase_x                                0x558BA0
#define EQ_Spell__IsStackable_x                                    0x4C5600
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5450
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B2B50
#define EQ_Spell__IsSPAStacking_x                                  0x559A20
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x559130
#define EQ_Spell__IsNoRemove_x                                     0x4C55E0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x559A30
#define __IsResEffectSpell_x                                       0x4C4900

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9990

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B2C30

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FA300
#define CTargetWnd__WndNotification_x                              0x7F9B90
#define CTargetWnd__RefreshTargetBuffs_x                           0x7F9E60
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7F8CF0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FE9D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x553EE0
#define EqSoundManager__PlayScriptMp3_x                            0x554040
#define EqSoundManager__SoundAssistPlay_x                          0x6607B0
#define EqSoundManager__WaveInstancePlay_x                         0x65FC60

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5113B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x923160

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x548050
#define CAltAbilityData__GetMercMaxRank_x                          0x547FF0
#define CAltAbilityData__GetMaxRank_x                              0x53D810

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F5890

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5430
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F78B0
#define CharacterBase__CreateItemIndex_x                           0x5FD7B0
#define CharacterBase__GetItemPossession_x                         0x4B2A00
#define CharacterBase__GetItemByGlobalIndex_x                      0x8BB420
#define CharacterBase__GetEffectId_x                               0x4C53E0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DA450
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DAC70

//messages
#define msg_spell_worn_off_x                                       0x57DB80
#define msg_new_text_x                                             0x572DA0
#define __msgTokenTextParam_x                                      0x5801C0
#define msgTokenText_x                                             0x580410

//SpellManager
#define SpellManager__vftable_x                                    0xAA3810
#define SpellManager__SpellManager_x                               0x663AB0
#define Spellmanager__LoadTextSpells_x                             0x663E30
#define SpellManager__GetSpellByGroupAndRank_x                     0x663C80

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96DE40

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F7F60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x583930
#define ItemGlobalIndex__IsEquippedLocation_x                      0x616600
#define ItemGlobalIndex__IsValidIndex_x                            0x4F7FC0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B3610
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B3890

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x748CF0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F6570
#define CCursorAttachment__Deactivate_x                            0x6F7550

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x935390
#define CEQSuiteTextureLoader__GetTexture_x                        0x935050

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F4F50

//IString
#define IString__Append_x                                          0x4E92D0

//Camera
#define CDisplay__cameraType_x                                     0xDAAC0C
#define EverQuest__Cameras_x                                       0xE6DEE4

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FD740
#define LootFiltersManager__GetItemFilterData_x                    0x4FD030
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FD060
#define LootFiltersManager__SetItemLootFilter_x                    0x4FD280

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A2BE0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x973B60
#define CResolutionHandler__GetWindowedStyle_x                     0x65B8E0

//CContainerMgr
#define CContainerMgr__OpenExperimentContainer_x                   0x6F2B60

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
#ifdef EMU
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\xFD\xFF\xFF\x8B\xCE\x5E\xE9\x00\x00\xFF\xFF\xC7\x01";
static char lpMask[] = "xxxx?xxxxxxx??xxxx";
#else
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
#endif
