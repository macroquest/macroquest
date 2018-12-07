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
#define __ExpectedVersionDate                                     "Dec  7 2018"
#define __ExpectedVersionTime                                     "04:20:15"
#define __ActualVersionDate_x                                      0xAD118C
#define __ActualVersionTime_x                                      0xAD1180

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x616190
#define __MemChecker1_x                                            0x8EABF0
#define __MemChecker2_x                                            0x6A5610
#define __MemChecker3_x                                            0x6A5560
#define __MemChecker4_x                                            0x841D70
#define __EncryptPad0_x                                            0xC05340
#define __EncryptPad1_x                                            0xC635D0
#define __EncryptPad2_x                                            0xC15EC8
#define __EncryptPad3_x                                            0xC15AC8
#define __EncryptPad4_x                                            0xC53E40
#define __EncryptPad5_x                                            0x1034AE8
#define __AC1_x                                                    0x7FEA86
#define __AC2_x                                                    0x5D0F7F
#define __AC3_x                                                    0x5D7E0F
#define __AC4_x                                                    0x5DBC30
#define __AC5_x                                                    0x5E1EA0
#define __AC6_x                                                    0x5E6476
#define __AC7_x                                                    0x5D09F0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E8A344

// Direct Input
#define DI8__Main_x                                                0x1034B0C
#define DI8__Keyboard_x                                            0x1034B10
#define DI8__Mouse_x                                               0xF2A450
#define DI8__Mouse_Copy_x                                          0xE881AC
#define DI8__Mouse_Check_x                                         0xF2A774
#define __AutoSkillArray_x                                         0xE890C4
#define __Attack_x                                                 0xF26ECB
#define __Autofire_x                                               0xF26ECC
#define __BindList_x                                               0xBF3F20
#define g_eqCommandStates_x                                        0xBF4C90
#define __Clicks_x                                                 0xE88264
#define __CommandList_x                                            0xBF5848
#define __CurrentMapLabel_x                                        0x103CA74
#define __CurrentSocial_x                                          0xBDE730
#define __DoAbilityList_x                                          0xEBE9EC
#define __do_loot_x                                                0x59E450
#define __DrawHandler_x                                            0x16B9448
#define __GroupCount_x                                             0xE7845A
#define __Guilds_x                                                 0xE7E9B8
#define __gWorld_x                                                 0xE7ACC8
#define __HWnd_x                                                   0xF2A454
#define __heqmain_x                                                0x1034AD0
#define __InChatMode_x                                             0xE88194
#define __LastTell_x                                               0xE8A0E8
#define __LMouseHeldTime_x                                         0xE882D0
#define __Mouse_x                                                  0x1034AF4
#define __MouseLook_x                                              0xE8822A
#define __MouseEventTime_x                                         0xF27980
#define __gpbCommandEvent_x                                        0xE7A77C
#define __NetStatusToggle_x                                        0xE8822D
#define __PCNames_x                                                0xE896A4
#define __RangeAttackReady_x                                       0xE893A8
#define __RMouseHeldTime_x                                         0xE882CC
#define __RunWalkState_x                                           0xE88198
#define __ScreenMode_x                                             0xDC6AA4
#define __ScreenX_x                                                0xE8814C
#define __ScreenY_x                                                0xE88148
#define __ScreenXMax_x                                             0xE88150
#define __ScreenYMax_x                                             0xE88154
#define __ServerHost_x                                             0xE7A9B3
#define __ServerName_x                                             0xEBE9AC
#define __ShiftKeyDown_x                                           0xE88824
#define __ShowNames_x                                              0xE89564
#define __Socials_x                                                0xEBEAAC
#define __SubscriptionType_x                                       0x107E5C4
#define __TargetAggroHolder_x                                      0x103F430
#define __ZoneType_x                                               0xE88628
#define __GroupAggro_x                                             0x103F470
#define __LoginName_x                                              0x1035364
#define __Inviter_x                                                0xF26E48
#define __AttackOnAssist_x                                         0xE89520
#define __UseTellWindows_x                                         0xE8983C
#define __gfMaxZoomCameraDistance_x                                0xAC66A0
#define __gfMaxCameraDistance_x                                    0xAF3AF8
#define __pulAutoRun_x                                             0xE88248
#define __pulForward_x                                             0xE89874
#define __pulBackward_x                                            0xE89878
#define __pulTurnRight_x                                           0xE8987C
#define __pulTurnLeft_x                                            0xE89880
#define __pulStrafeLeft_x                                          0xE89884
#define __pulStrafeRight_x                                         0xE89888
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE7AD50
#define instEQZoneInfo_x                                           0xE88420
#define instKeypressHandler_x                                      0xF27930
#define pinstActiveBanker_x                                        0xE7A85C
#define pinstActiveCorpse_x                                        0xE7A854
#define pinstActiveGMaster_x                                       0xE7A858
#define pinstActiveMerchant_x                                      0xE7A850
#define pinstAggroInfo_x                                           0xC79E08
#define pinstAltAdvManager_x                                       0xDC76F8
#define pinstAuraMgr_x                                             0xC95988
#define pinstBandageTarget_x                                       0xE7A86C
#define pinstCamActor_x                                            0xDC6A98
#define pinstCDBStr_x                                              0xDC642C
#define pinstCDisplay_x                                            0xE7AABC
#define pinstCEverQuest_x                                          0x1034C28
#define pinstEverQuestInfo_x                                       0xE88140
#define pinstCharData_x                                            0xE7ACD0
#define pinstCharSpawn_x                                           0xE7A8A4
#define pinstControlledMissile_x                                   0xE7ACCC
#define pinstControlledPlayer_x                                    0xE7A8A4
#define pinstCResolutionHandler_x                                  0x16B9678
#define pinstCSidlManager_x                                        0x16B850C
#define pinstCXWndManager_x                                        0x16B8500
#define instDynamicZone_x                                          0xE7E890
#define pinstDZMember_x                                            0xE7E9A0
#define pinstDZTimerInfo_x                                         0xE7E9A4
#define pinstEQItemList_x                                          0xE76F40
#define pinstEQObjectList_x                                        0xE78130
#define instEQMisc_x                                               0xDC6368
#define pinstEQSoundManager_x                                      0xDC7F58
#define pinstEQSpellStrings_x                                      0xC87F40
#define instExpeditionLeader_x                                     0xE7E8DA
#define instExpeditionName_x                                       0xE7E91A
#define pinstGroup_x                                               0xE78456
#define pinstImeManager_x                                          0x16B8504
#define pinstLocalPlayer_x                                         0xE7A84C
#define pinstMercenaryData_x                                       0xF2812C
#define pinstMercenaryStats_x                                      0x103F57C
#define pinstMercAltAbilities_x                                    0xDC7CC8
#define pinstModelPlayer_x                                         0xE7A864
#define pinstPCData_x                                              0xE7ACD0
#define pinstRealEstateItems_x                                     0xF29610
#define pinstSkillMgr_x                                            0xF296E0
#define pinstSpawnManager_x                                        0xF28CD0
#define pinstSpellManager_x                                        0xF298B8
#define pinstSpellSets_x                                           0xF1FAF4
#define pinstStringTable_x                                         0xE7A650
#define pinstSwitchManager_x                                       0xE782F0
#define pinstTarget_x                                              0xE7A8A0
#define pinstTargetObject_x                                        0xE7A8AC
#define pinstTargetSwitch_x                                        0xE7ACF0
#define pinstTaskMember_x                                          0xDC61FC
#define pinstTrackTarget_x                                         0xE7A8A8
#define pinstTradeTarget_x                                         0xE7A860
#define instTributeActive_x                                        0xDC638D
#define pinstViewActor_x                                           0xDC6A94
#define pinstWorldData_x                                           0xE7A76C
#define pinstZoneAddr_x                                            0xE886C0
#define pinstPlayerPath_x                                          0xF28D68
#define pinstTargetIndicator_x                                     0xF29B20
#define pinstCTargetManager_x                                      0xF29BB8
#define EQObject_Top_x                                             0xE7A80C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC6554
#define pinstCAchievementsWnd_x                                    0xDC6544
#define pinstCActionsWnd_x                                         0xDC65B8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC6A58
#define pinstCAdvancedLootWnd_x                                    0xDC659C
#define pinstCAdventureLeaderboardWnd_x                            0x1036248
#define pinstCAdventureRequestWnd_x                                0x10362F8
#define pinstCAdventureStatsWnd_x                                  0x10363A8
#define pinstCAggroMeterWnd_x                                      0xDC6AD8
#define pinstCAlarmWnd_x                                           0xDC6B48
#define pinstCAlertHistoryWnd_x                                    0xDC6500
#define pinstCAlertStackWnd_x                                      0xDC6AF0
#define pinstCAlertWnd_x                                           0xDC6B10
#define pinstCAltStorageWnd_x                                      0x1036708
#define pinstCAudioTriggersWindow_x                                0xC7A298
#define pinstCAuraWnd_x                                            0xDC6AD4
#define pinstCAvaZoneWnd_x                                         0xDC6504
#define pinstCBandolierWnd_x                                       0xDC6B18
#define pinstCBankWnd_x                                            0xDC64FC
#define pinstCBarterMerchantWnd_x                                  0x1037948
#define pinstCBarterSearchWnd_x                                    0x10379F8
#define pinstCBarterWnd_x                                          0x1037AA8
#define pinstCBazaarConfirmationWnd_x                              0xDC6AE8
#define pinstCBazaarSearchWnd_x                                    0xDC65DC
#define pinstCBazaarWnd_x                                          0xDC6B1C
#define pinstCBlockedBuffWnd_x                                     0xDC64DC
#define pinstCBlockedPetBuffWnd_x                                  0xDC6510
#define pinstCBodyTintWnd_x                                        0xDC6ABC
#define pinstCBookWnd_x                                            0xDC6B3C
#define pinstCBreathWnd_x                                          0xDC6558
#define pinstCBuffWindowNORMAL_x                                   0xDC6D58
#define pinstCBuffWindowSHORT_x                                    0xDC6D5C
#define pinstCBugReportWnd_x                                       0xDC654C
#define pinstCButtonWnd_x                                          0x16B8730
#define pinstCCastingWnd_x                                         0xDC6548
#define pinstCCastSpellWnd_x                                       0xDC6A54
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC655C
#define pinstCChatWindowManager_x                                  0x1038568
#define pinstCClaimWnd_x                                           0x10386C0
#define pinstCColorPickerWnd_x                                     0xDC6588
#define pinstCCombatAbilityWnd_x                                   0xDC6AE4
#define pinstCCombatSkillsSelectWnd_x                              0xDC65B0
#define pinstCCompassWnd_x                                         0xDC6A8C
#define pinstCConfirmationDialog_x                                 0x103D5C0
#define pinstCContainerMgr_x                                       0xDC6AEC
#define pinstCContextMenuManager_x                                 0x16B84C0
#define pinstCCursorAttachment_x                                   0xDC6540
#define pinstCDistillerInfo_x                                      0x103BFCC
#define pinstCDynamicZoneWnd_x                                     0x1038C88
#define pinstCEditLabelWnd_x                                       0xDC6B4C
#define pinstCEQMainWnd_x                                          0x1038ED0
#define pinstCEventCalendarWnd_x                                   0xDC6574
#define pinstCExtendedTargetWnd_x                                  0xDC6AC8
#define pinstCFacePick_x                                           0xDC6580
#define pinstCFactionWnd_x                                         0xDC653C
#define pinstCFellowshipWnd_x                                      0x10390D0
#define pinstCFileSelectionWnd_x                                   0xDC6590
#define pinstCFindItemWnd_x                                        0xDC6B38
#define pinstCFindLocationWnd_x                                    0x1039228
#define pinstCFriendsWnd_x                                         0xDC65D4
#define pinstCGemsGameWnd_x                                        0xDC6B14
#define pinstCGiveWnd_x                                            0xDC6B40
#define pinstCGroupSearchFiltersWnd_x                              0xDC6AF8
#define pinstCGroupSearchWnd_x                                     0x1039620
#define pinstCGroupWnd_x                                           0x10396D0
#define pinstCGuildBankWnd_x                                       0xE89504
#define pinstCGuildCreationWnd_x                                   0x1039830
#define pinstCGuildMgmtWnd_x                                       0x10398E0
#define pinstCharacterCreation_x                                   0xDC6ADC
#define pinstCHelpWnd_x                                            0xDC6A88
#define pinstCHeritageSelectionWnd_x                               0xDC6594
#define pinstCHotButtonWnd_x                                       0x103BA38
#define pinstCHotButtonWnd1_x                                      0x103BA38
#define pinstCHotButtonWnd2_x                                      0x103BA3C
#define pinstCHotButtonWnd3_x                                      0x103BA40
#define pinstCHotButtonWnd4_x                                      0x103BA44
#define pinstCIconSelectionWnd_x                                   0xDC6520
#define pinstCInspectWnd_x                                         0xDC651C
#define pinstCInventoryWnd_x                                       0xDC6B20
#define pinstCInvSlotMgr_x                                         0xDC6AB0
#define pinstCItemDisplayManager_x                                 0x103BFC8
#define pinstCItemExpTransferWnd_x                                 0x103C0F8
#define pinstCItemFuseWnd_x                                        0xDC6534
#define pinstCItemOverflowWnd_x                                    0xDC6644
#define pinstCJournalCatWnd_x                                      0xDC65A8
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDC656C
#define pinstCKeyRingWnd_x                                         0xDC64D8
#define pinstCLargeDialogWnd_x                                     0x103E240
#define pinstCLayoutCopyWnd_x                                      0x103C448
#define pinstCLFGuildWnd_x                                         0x103C4F8
#define pinstCLoadskinWnd_x                                        0xDC6B2C
#define pinstCLootFiltersCopyWnd_x                                 0xC962C0
#define pinstCLootFiltersWnd_x                                     0xDC6B34
#define pinstCLootSettingsWnd_x                                    0xDC6D54
#define pinstCLootWnd_x                                            0xDC6578
#define pinstCMailAddressBookWnd_x                                 0xDC6514
#define pinstCMailCompositionWnd_x                                 0xDC64EC
#define pinstCMailIgnoreListWnd_x                                  0xDC6518
#define pinstCMailWnd_x                                            0xDC64CC
#define pinstCManageLootWnd_x                                      0xDC7B70
#define pinstCMapToolbarWnd_x                                      0xDC6B28
#define pinstCMapViewWnd_x                                         0xDC6B00
#define pinstCMarketplaceWnd_x                                     0xDC657C
#define pinstCMerchantWnd_x                                        0xDC65AC
#define pinstCMIZoneSelectWnd_x                                    0x103CD30
#define pinstCMusicPlayerWnd_x                                     0xDC64D4
#define pinstCNameChangeMercWnd_x                                  0xDC6AC0
#define pinstCNameChangePetWnd_x                                   0xDC6A80
#define pinstCNameChangeWnd_x                                      0xDC6560
#define pinstCNoteWnd_x                                            0xDC6A60
#define pinstCObjectPreviewWnd_x                                   0xDC65A0
#define pinstCOptionsWnd_x                                         0xDC6B30
#define pinstCPetInfoWnd_x                                         0xDC64F0
#define pinstCPetitionQWnd_x                                       0xDC65C0
//#define pinstCPlayerCustomizationWnd_x                           0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC6AB8
#define pinstCPlayerWnd_x                                          0xDC65BC
#define pinstCPopupWndManager_x                                    0x103D5C0
#define pinstCProgressionSelectionWnd_x                            0x103D670
#define pinstCPurchaseGroupWnd_x                                   0xDC6A4C
#define pinstCPurchaseWnd_x                                        0xDC65B4
#define pinstCPvPLeaderboardWnd_x                                  0x103D720
#define pinstCPvPStatsWnd_x                                        0x103D7D0
#define pinstCQuantityWnd_x                                        0xDC6528
#define pinstCRaceChangeWnd_x                                      0xDC6584
#define pinstCRaidOptionsWnd_x                                     0xDC6AFC
#define pinstCRaidWnd_x                                            0xDC652C
#define pinstCRealEstateItemsWnd_x                                 0xDC6550
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC6570
#define pinstCRealEstateManageWnd_x                                0xDC64C8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC64E0
#define pinstCRealEstatePlotSearchWnd_x                            0xDC6508
#define pinstCRealEstatePurchaseWnd_x                              0xDC6530
#define pinstCRespawnWnd_x                                         0xDC6AF4
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDC6ACC
#define pinstCSendMoneyWnd_x                                       0xDC6D50
#define pinstCServerListWnd_x                                      0xDC64F8
#define pinstCSkillsSelectWnd_x                                    0xDC658C
#define pinstCSkillsWnd_x                                          0xDC6568
#define pinstCSocialEditWnd_x                                      0xDC6538
#define pinstCSocialWnd_x                                          0xDC6AD0
#define pinstCSpellBookWnd_x                                       0xDC6AC4
#define pinstCStoryWnd_x                                           0xDC6A5C
#define pinstCTargetOfTargetWnd_x                                  0x103F600
#define pinstCTargetWnd_x                                          0xDC64E8
#define pinstCTaskOverlayWnd_x                                     0xDC650C
#define pinstCTaskSelectWnd_x                                      0x103F758
#define pinstCTaskManager_x                                        0xC96AC0
#define pinstCTaskTemplateSelectWnd_x                              0x103F808
#define pinstCTaskWnd_x                                            0x103F8B8
#define pinstCTextEntryWnd_x                                       0xDC6A90
#define pinstCTextOverlay_x                                        0xC7A5A8
#define pinstCTimeLeftWnd_x                                        0xDC6598
#define pinstCTipWndCONTEXT_x                                      0x103FABC
#define pinstCTipWndOFDAY_x                                        0x103FAB8
#define pinstCTitleWnd_x                                           0x103FB68
#define pinstCTrackingWnd_x                                        0xDC64F4
#define pinstCTradeskillWnd_x                                      0x103FCD0
#define pinstCTradeWnd_x                                           0xDC6AB4
#define pinstCTrainWnd_x                                           0xDC6524
#define pinstCTributeBenefitWnd_x                                  0x103FED0
#define pinstCTributeMasterWnd_x                                   0x103FF80
#define pinstCTributeTrophyWnd_x                                   0x1040030
#define pinstCVideoModesWnd_x                                      0xDC6AE0
#define pinstCVoiceMacroWnd_x                                      0xF2A0E8
#define pinstCVoteResultsWnd_x                                     0xDC6A50
#define pinstCVoteWnd_x                                            0xDC65C4
#define pinstCWebManager_x                                         0xF2A24C
#define pinstCZoneGuideWnd_x                                       0xDC64D0
#define pinstCZonePathWnd_x                                        0xDC64E4

#define pinstEQSuiteTextureLoader_x                                0xC650A0
#define pinstItemIconCache_x                                       0x1038E88
#define pinstLootFiltersManager_x                                  0xC96370
#define pinstRewardSelectionWnd_x                                  0x103DF18

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC15ABC
#define __CastRay_x                                                0x599970
#define __CastRay2_x                                               0x5999C0
#define __ConvertItemTags_x                                        0x5B45F0
#define __CrashHandler_x                                           0x84B760
#define __EQGetTime_x                                              0x8EA6E0
#define __ExecuteCmd_x                                             0x5922B0
#define __FixHeading_x                                             0x97B140
#define __get_bearing_x                                            0x5994C0
#define __get_melee_range_x                                        0x599BB0
#define __GetAnimationCache_x                                      0x708D50
#define __GetGaugeValueFromEQ_x                                    0x7FD290
#define __GetLabelFromEQ_x                                         0x7FEA10
#define __GetXTargetType_x                                         0x97CBA0
#define __HeadingDiff_x                                            0x97B1B0
#define __HelpPath_x                                               0xF2759C
#define __LoadFrontEnd_x                                           0x6A1470
#define __NewUIINI_x                                               0x7FCF60
#define __pCrashHandler_x                                          0x105D420
#define __ProcessGameEvents_x                                      0x5F7780
#define __ProcessMouseEvent_x                                      0x5F6F40
#define __SaveColors_x                                             0x542E20
#define __STMLToText_x                                             0x91E330
#define __ToggleKeyRingItem_x                                      0x505FA0
#define CrashDetected_x                                            0x6A2F60
#define DrawNetStatus_x                                            0x623770
#define Expansion_HoT_x                                            0xE8950C
#define Teleport_Table_Size_x                                      0xE7A808
#define Teleport_Table_x                                           0xE78648
#define Util__FastTime_x                                           0x8EA2A0
#define wwsCrashReportCheckForUploader_x                           0x84C480
#define wwsCrashReportPlatformLaunchUploader_x                     0x84EB60
#define __HandleMouseWheel_x                                       0x6A56C0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B630
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4944B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494270

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54A830
#define AltAdvManager__IsAbilityReady_x                            0x549780
#define AltAdvManager__GetAAById_x                                 0x549980
#define AltAdvManager__CanTrainAbility_x                           0x5499F0
#define AltAdvManager__CanSeeAbility_x                             0x549D50

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7540
#define CharacterZoneClient__HasSkill_x                            0x4D2210
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3930
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB910
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8090
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D62C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D63A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6480
#define CharacterZoneClient__FindAffectSlot_x                      0x4C03F0
#define CharacterZoneClient__BardCastBard_x                        0x4C3060
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8160
#define CharacterZoneClient__GetEffect_x                           0x4B7FD0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C13F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C14C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1510
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1660
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1830

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CB190

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D8B50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x605F00
#define CButtonWnd__CButtonWnd_x                                   0x91A720

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F7670
#define CChatManager__InitContextMenu_x                            0x6F1710
#define CChatManager__FreeChatWindow_x                             0x6F6580
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FAFE0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F7410

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92EEF0
#define CContextMenu__dCContextMenu_x                              0x92F120
#define CContextMenu__AddMenuItem_x                                0x92F130
#define CContextMenu__RemoveMenuItem_x                             0x92F440
#define CContextMenu__RemoveAllMenuItems_x                         0x92F460
#define CContextMenu__CheckMenuItem_x                              0x92F4E0
#define CContextMenu__SetMenuItem_x                                0x92F360
#define CContextMenu__AddSeparator_x                               0x92F2C0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92FA80
#define CContextMenuManager__RemoveMenu_x                          0x92FAF0
#define CContextMenuManager__PopupMenu_x                           0x92FBB0
#define CContextMenuManager__Flush_x                               0x92FA20
#define CContextMenuManager__GetMenu_x                             0x496660

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CADF0
#define CChatService__GetFriendName_x                              0x8CAE00

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F7BE0
#define CChatWindow__Clear_x                                       0x6F8C40
#define CChatWindow__WndNotification_x                             0x6F91B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92C380
#define CComboWnd__Draw_x                                          0x92B860
#define CComboWnd__GetCurChoice_x                                  0x92C1C0
#define CComboWnd__GetListRect_x                                   0x92BD20
#define CComboWnd__GetTextRect_x                                   0x92C3F0
#define CComboWnd__InsertChoice_x                                  0x92BEB0
#define CComboWnd__SetColors_x                                     0x92BE80
#define CComboWnd__SetChoice_x                                     0x92C190
#define CComboWnd__GetItemCount_x                                  0x92C1D0
#define CComboWnd__GetCurChoiceText_x                              0x92C210

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x700EF0
#define CContainerWnd__vftable_x                                   0xADA438
#define CContainerWnd__SetContainer_x                              0x702460

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x542BE0
#define CDisplay__GetClickedActor_x                                0x535B90
#define CDisplay__GetUserDefinedColor_x                            0x52E270
#define CDisplay__GetWorldFilePath_x                               0x5375E0
#define CDisplay__is3dON_x                                         0x532860
#define CDisplay__ReloadUI_x                                       0x53CD00
#define CDisplay__WriteTextHD2_x                                   0x532640
#define CDisplay__TrueDistance_x                                   0x539240
#define CDisplay__SetViewActor_x                                   0x5354E0
#define CDisplay__GetFloorHeight_x                                 0x532920
#define CDisplay__SetRenderWindow_x                                0x531250
#define CDisplay__ToggleScreenshotMode_x                           0x534FB0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94E8B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x933610
#define CEditWnd__GetCharIndexPt_x                                 0x934510
#define CEditWnd__GetDisplayString_x                               0x9343B0
#define CEditWnd__GetHorzOffset_x                                  0x932C30
#define CEditWnd__GetLineForPrintableChar_x                        0x935710
#define CEditWnd__GetSelStartPt_x                                  0x9347C0
#define CEditWnd__GetSTMLSafeText_x                                0x9341D0
#define CEditWnd__PointFromPrintableChar_x                         0x935340
#define CEditWnd__SelectableCharFromPoint_x                        0x9354B0
#define CEditWnd__SetEditable_x                                    0x934890

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E59A0
#define CEverQuest__ClickedPlayer_x                                0x5D7BF0
#define CEverQuest__CreateTargetIndicator_x                        0x5F4A30
#define CEverQuest__DeleteTargetIndicator_x                        0x5F4AC0
#define CEverQuest__DoTellWindow_x                                 0x4E34D0
#define CEverQuest__OutputTextToLog_x                              0x4E3700
#define CEverQuest__DropHeldItemOnGround_x                         0x5CD4B0
#define CEverQuest__dsp_chat_x                                     0x4E3A90
#define CEverQuest__trimName_x                                     0x5F0DB0
#define CEverQuest__Emote_x                                        0x5E61B0
#define CEverQuest__EnterZone_x                                    0x5E0250
#define CEverQuest__GetBodyTypeDesc_x                              0x5EA650
#define CEverQuest__GetClassDesc_x                                 0x5EAC90
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EB290
#define CEverQuest__GetDeityDesc_x                                 0x5F3380
#define CEverQuest__GetLangDesc_x                                  0x5EB450
#define CEverQuest__GetRaceDesc_x                                  0x5EAC70
#define CEverQuest__InterpretCmd_x                                 0x5F3950
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D16A0
#define CEverQuest__LMouseUp_x                                     0x5CFA20
#define CEverQuest__RightClickedOnPlayer_x                         0x5D1F80
#define CEverQuest__RMouseUp_x                                     0x5D09B0
#define CEverQuest__SetGameState_x                                 0x5CD240
#define CEverQuest__UPCNotificationFlush_x                         0x5F0CB0
#define CEverQuest__IssuePetCommand_x                              0x5EC850
#define CEverQuest__ReportSuccessfulHit_x                          0x5E75B0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x712E80
#define CGaugeWnd__CalcLinesFillRect_x                             0x712EE0
#define CGaugeWnd__Draw_x                                          0x712570

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACBF0
#define CGuild__GetGuildName_x                                     0x4ABCD0
#define CGuild__GetGuildIndex_x                                    0x4AC060

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72E270

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6062C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73B230
#define CInvSlotMgr__MoveItem_x                                    0x739F50
#define CInvSlotMgr__SelectSlot_x                                  0x73B300

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x738800
#define CInvSlot__SliderComplete_x                                 0x736570
#define CInvSlot__GetItemBase_x                                    0x735EE0
#define CInvSlot__UpdateItem_x                                     0x736050

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73CC50
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73BF20
#define CInvSlotWnd__HandleLButtonUp_x                             0x73C7D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F9480
#define CItemDisplayWnd__UpdateStrings_x                           0x74AF20
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x744EB0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7453C0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74B530
#define CItemDisplayWnd__AboutToShow_x                             0x74AB70
#define CItemDisplayWnd__WndNotification_x                         0x74CA80

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x830D50

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x750BA0

// CLabel 
#define CLabel__Draw_x                                             0x756620

// CListWnd
#define CListWnd__CListWnd_x                                       0x904AB0
#define CListWnd__dCListWnd_x                                      0x904DD0
#define CListWnd__AddColumn_x                                      0x909110
#define CListWnd__AddColumn1_x                                     0x909160
#define CListWnd__AddLine_x                                        0x9094F0
#define CListWnd__AddString_x                                      0x9092F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x908ED0
#define CListWnd__CalculateVSBRange_x                              0x908CA0
#define CListWnd__ClearSel_x                                       0x909CD0
#define CListWnd__ClearAllSel_x                                    0x909D30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90A760
#define CListWnd__Compare_x                                        0x9085E0
#define CListWnd__Draw_x                                           0x904ED0
#define CListWnd__DrawColumnSeparators_x                           0x9076B0
#define CListWnd__DrawHeader_x                                     0x907B20
#define CListWnd__DrawItem_x                                       0x907F20
#define CListWnd__DrawLine_x                                       0x907820
#define CListWnd__DrawSeparator_x                                  0x907750
#define CListWnd__EnableLine_x                                     0x906F80
#define CListWnd__EnsureVisible_x                                  0x90A680
#define CListWnd__ExtendSel_x                                      0x909C00
#define CListWnd__GetColumnMinWidth_x                              0x906AC0
#define CListWnd__GetColumnWidth_x                                 0x906A30
#define CListWnd__GetCurSel_x                                      0x9063C0
#define CListWnd__GetItemAtPoint_x                                 0x907200
#define CListWnd__GetItemAtPoint1_x                                0x907270
#define CListWnd__GetItemData_x                                    0x906440
#define CListWnd__GetItemHeight_x                                  0x906800
#define CListWnd__GetItemIcon_x                                    0x9065D0
#define CListWnd__GetItemRect_x                                    0x907070
#define CListWnd__GetItemText_x                                    0x906480
#define CListWnd__GetSelList_x                                     0x909D80
#define CListWnd__GetSeparatorRect_x                               0x9074B0
#define CListWnd__InsertLine_x                                     0x9098E0
#define CListWnd__RemoveLine_x                                     0x909A30
#define CListWnd__SetColors_x                                      0x908C70
#define CListWnd__SetColumnJustification_x                         0x9089A0
#define CListWnd__SetColumnWidth_x                                 0x9088C0
#define CListWnd__SetCurSel_x                                      0x909B40
#define CListWnd__SetItemColor_x                                   0x90A330
#define CListWnd__SetItemData_x                                    0x90A2F0
#define CListWnd__SetItemText_x                                    0x909F00
#define CListWnd__ShiftColumnSeparator_x                           0x908A60
#define CListWnd__Sort_x                                           0x908760
#define CListWnd__ToggleSel_x                                      0x909B70

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76BA10
#define CMapViewWnd__GetWorldCoordinates_x                         0x76A120
#define CMapViewWnd__HandleLButtonDown_x                           0x767180

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78ED70
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78F650
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78FB80
#define CMerchantWnd__SelectRecoverySlot_x                         0x7929B0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78D760
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x7985A0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78E9B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x898D10
#define CPacketScrambler__hton_x                                   0x898D00

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x923930
#define CSidlManager__FindScreenPieceTemplate_x                    0x923D40
#define CSidlManager__FindScreenPieceTemplate1_x                   0x923B30
#define CSidlManager__CreateLabel_x                                0x7F08C0
#define CSidlManager__CreateXWndFromTemplate_x                     0x926E10
#define CSidlManager__CreateXWndFromTemplate1_x                    0x926FF0
#define CSidlManager__CreateXWnd_x                                 0x7F07F0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F0DC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x920480
#define CSidlScreenWnd__CalculateVSBRange_x                        0x920370
#define CSidlScreenWnd__ConvertToRes_x                             0x9456F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91FE00
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91FAF0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91FBC0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91FC90
#define CSidlScreenWnd__DrawSidlPiece_x                            0x920920
#define CSidlScreenWnd__EnableIniStorage_x                         0x920DF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x920B10
#define CSidlScreenWnd__Init1_x                                    0x91F700
#define CSidlScreenWnd__LoadIniInfo_x                              0x920E40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9219A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91EB10
#define CSidlScreenWnd__StoreIniInfo_x                             0x921510
#define CSidlScreenWnd__StoreIniVis_x                              0x921880
#define CSidlScreenWnd__WndNotification_x                          0x920830
#define CSidlScreenWnd__GetChildItem_x                             0x920D70
#define CSidlScreenWnd__HandleLButtonUp_x                          0x910570
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B8390

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66A5E0
#define CSkillMgr__GetSkillCap_x                                   0x66A7C0
#define CSkillMgr__GetNameToken_x                                  0x669D70

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x930880
#define CSliderWnd__SetValue_x                                     0x9306F0
#define CSliderWnd__SetNumTicks_x                                  0x930750

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F66F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x937690
#define CStmlWnd__CalculateHSBRange_x                              0x938740
#define CStmlWnd__CalculateVSBRange_x                              0x9386B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x93CAB0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93D740
#define CStmlWnd__ForceParseNow_x                                  0x937C30
#define CStmlWnd__GetNextTagPiece_x                                0x93CA10
#define CStmlWnd__GetSTMLText_x                                    0x4F53E0
#define CStmlWnd__GetVisibleText_x                                 0x937C50
#define CStmlWnd__InitializeWindowVariables_x                      0x93D590
#define CStmlWnd__MakeStmlColorTag_x                               0x936D70
#define CStmlWnd__MakeWndNotificationTag_x                         0x936DE0
#define CStmlWnd__SetSTMLText_x                                    0x935E20
#define CStmlWnd__StripFirstSTMLLines_x                            0x93E8A0
#define CStmlWnd__UpdateHistoryString_x                            0x93D950

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9425C0
#define CTabWnd__DrawCurrentPage_x                                 0x942BE0
#define CTabWnd__DrawTab_x                                         0x9429B0
#define CTabWnd__GetCurrentPage_x                                  0x941E20
#define CTabWnd__GetPageInnerRect_x                                0x942060
#define CTabWnd__GetTabInnerRect_x                                 0x941FA0
#define CTabWnd__GetTabRect_x                                      0x941E50
#define CTabWnd__InsertPage_x                                      0x942250
#define CTabWnd__SetPage_x                                         0x9420E0
#define CTabWnd__SetPageRect_x                                     0x942500
#define CTabWnd__UpdatePage_x                                      0x942870
#define CTabWnd__GetPageFromTabIndex_x                             0x9428F0
#define CTabWnd__GetCurrentTabIndex_x                              0x941E10

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x751020
#define CPageWnd__SetTabText_x                                     0x94ECC0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6730

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90D3B0
#define CTextureFont__GetTextExtent_x                              0x90D570

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69E2C0
#define CHtmlComponentWnd__ValidateUri_x                           0x72FC60
#define CHtmlWnd__SetClientCallbacks_x                             0x60B270
#define CHtmlWnd__AddObserver_x                                    0x60B290
#define CHtmlWnd__RemoveObserver_x                                 0x60B2F0
#define Window__getProgress_x                                      0x8493D0
#define Window__getStatus_x                                        0x8493F0
#define Window__getURI_x                                           0x849400

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94B240

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FA2B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADE90
#define CXStr__CXStr1_x                                            0x4F0430
#define CXStr__CXStr3_x                                            0x8E67D0
#define CXStr__dCXStr_x                                            0x473030
#define CXStr__operator_equal_x                                    0x8E6A00
#define CXStr__operator_equal1_x                                   0x8E6A40
#define CXStr__operator_plus_equal1_x                              0x8E74D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92EB10
#define CXWnd__BringToTop_x                                        0x913D50
#define CXWnd__Center_x                                            0x9138D0
#define CXWnd__ClrFocus_x                                          0x913700
#define CXWnd__Destroy_x                                           0x9137B0
#define CXWnd__DoAllDrawing_x                                      0x90FD20
#define CXWnd__DrawChildren_x                                      0x90FCF0
#define CXWnd__DrawColoredRect_x                                   0x910180
#define CXWnd__DrawTooltip_x                                       0x90E830
#define CXWnd__DrawTooltipAtPoint_x                                0x90E8F0
#define CXWnd__GetBorderFrame_x                                    0x90FFE0
#define CXWnd__GetChildWndAt_x                                     0x913DF0
#define CXWnd__GetClientClipRect_x                                 0x911FD0
#define CXWnd__GetScreenClipRect_x                                 0x912080
#define CXWnd__GetScreenRect_x                                     0x912230
#define CXWnd__GetTooltipRect_x                                    0x9101D0
#define CXWnd__GetWindowTextA_x                                    0x497DF0
#define CXWnd__IsActive_x                                          0x916C90
#define CXWnd__IsDescendantOf_x                                    0x912C50
#define CXWnd__IsReallyVisible_x                                   0x912C80
#define CXWnd__IsType_x                                            0x914460
#define CXWnd__Move_x                                              0x912CF0
#define CXWnd__Move1_x                                             0x912DA0
#define CXWnd__ProcessTransition_x                                 0x913880
#define CXWnd__Refade_x                                            0x913070
#define CXWnd__Resize_x                                            0x913310
#define CXWnd__Right_x                                             0x913B10
#define CXWnd__SetFocus_x                                          0x9136C0
#define CXWnd__SetFont_x                                           0x913730
#define CXWnd__SetKeyTooltip_x                                     0x914280
#define CXWnd__SetMouseOver_x                                      0x911140
#define CXWnd__StartFade_x                                         0x912B20
#define CXWnd__GetChildItem_x                                      0x913F60
#define CXWnd__SetParent_x                                         0x9129E0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9467C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x916CD0
#define CXWndManager__DrawWindows_x                                0x916CF0
#define CXWndManager__GetKeyboardFlags_x                           0x9193C0
#define CXWndManager__HandleKeyboardMsg_x                          0x918FC0
#define CXWndManager__RemoveWnd_x                                  0x919600
#define CXWndManager__RemovePendingDeletionWnd_x                   0x919B40

// CDBStr
#define CDBStr__GetString_x                                        0x52D220

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9040
#define EQ_Character__Cur_HP_x                                     0x4CF290
#define EQ_Character__Cur_Mana_x                                   0x4D6980
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BBF50
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFAA0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFBF0
#define EQ_Character__GetHPRegen_x                                 0x4DC8E0
#define EQ_Character__GetEnduranceRegen_x                          0x4DCEF0
#define EQ_Character__GetManaRegen_x                               0x4DD330
#define EQ_Character__Max_Endurance_x                              0x631350
#define EQ_Character__Max_HP_x                                     0x4CF0C0
#define EQ_Character__Max_Mana_x                                   0x631150
#define EQ_Character__doCombatAbility_x                            0x633810
#define EQ_Character__UseSkill_x                                   0x4DF120
#define EQ_Character__GetConLevel_x                                0x62A6A0
#define EQ_Character__IsExpansionFlag_x                            0x590A50
#define EQ_Character__TotalEffect_x                                0x4C25E0
#define EQ_Character__GetPCSpellAffect_x                           0x4BCB40
#define EQ_Character__SpellDuration_x                              0x4BC670
#define EQ_Character__FindItemByRecord_x                           0x4D48A0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1FD0
#define EQ_Character__GetBaseSkill_x                               0x4D2F70
#define EQ_Character__CanUseItem_x                                 0x4D6C90

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B7E40

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x647610

//PcClient
#define PcClient__PcClient_x                                       0x627DD0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6C90
#define CCharacterListWnd__EnterWorld_x                            0x4B66D0
#define CCharacterListWnd__Quit_x                                  0x4B63E0
#define CCharacterListWnd__UpdateList_x                            0x4B6860

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60C4C0
#define EQ_Item__CreateItemTagString_x                             0x892660
#define EQ_Item__IsStackable_x                                     0x8970B0
#define EQ_Item__GetImageNum_x                                     0x894060
#define EQ_Item__CreateItemClient_x                                0x60B670
#define EQ_Item__GetItemValue_x                                    0x8952E0
#define EQ_Item__ValueSellMerchant_x                               0x8988A0
#define EQ_Item__IsKeyRingItem_x                                   0x896A00
#define EQ_Item__CanGoInBag_x                                      0x60C5E0
#define EQ_Item__GetMaxItemCount_x                                 0x8956B0
#define EQ_Item__GetHeldItem_x                                     0x893F30
#define EQ_Item__GetAugmentFitBySlot_x                             0x891FA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54B540
#define EQ_LoadingS__Array_x                                       0xBED130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x631CB0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A1AA0
#define EQ_PC__GetCombatAbility_x                                  0x8A2110
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A2180
#define EQ_PC__GetItemRecastTimer_x                                0x633D90
#define EQ_PC__HasLoreItem_x                                       0x62AE70
#define EQ_PC__AlertInventoryChanged_x                             0x629FD0
#define EQ_PC__GetPcZoneClient_x                                   0x655E80
#define EQ_PC__RemoveMyAffect_x                                    0x636F90
#define EQ_PC__GetKeyRingItems_x                                   0x8A2A20
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A27A0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A2D10

// EQItemList 
#define EQItemList__EQItemList_x                                   0x596EF0
#define EQItemList__add_object_x                                   0x5C2B80
#define EQItemList__add_item_x                                     0x597500
#define EQItemList__delete_item_x                                  0x597550
#define EQItemList__FreeItemList_x                                 0x597450

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52A680

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x648E90
#define EQPlayer__dEQPlayer_x                                      0x63C590
#define EQPlayer__DoAttack_x                                       0x650B60
#define EQPlayer__EQPlayer_x                                       0x63CC40
#define EQPlayer__SetNameSpriteState_x                             0x640EC0
#define EQPlayer__SetNameSpriteTint_x                              0x641D90
#define PlayerBase__HasProperty_j_x                                0x979510
#define EQPlayer__IsTargetable_x                                   0x9799B0
#define EQPlayer__CanSee_x                                         0x979810
#define EQPlayer__CanSee1_x                                        0x9798E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9795D0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x653930
#define PlayerZoneClient__GetLevel_x                               0x655EC0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C3CE0
#define PlayerZoneClient__LegalPlayerRace_x                        0x544960

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64BBF0
#define EQPlayerManager__GetSpawnByName_x                          0x64BC10
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64BCA0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60FD40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60FD80
#define KeypressHandler__ClearCommandStateArray_x                  0x611170
#define KeypressHandler__HandleKeyDown_x                           0x611190
#define KeypressHandler__HandleKeyUp_x                             0x611230
#define KeypressHandler__SaveKeymapping_x                          0x611610

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7678A0
#define MapViewMap__SaveEx_x                                       0x76AC40
#define MapViewMap__SetZoom_x                                      0x76F310

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B5D30

// StringTable 
#define StringTable__getString_x                                   0x8B0DA0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x636C00
#define PcZoneClient__RemovePetEffect_x                            0x637230
#define PcZoneClient__HasAlternateAbility_x                        0x630F90
#define PcZoneClient__GetCurrentMod_x                              0x4E2220
#define PcZoneClient__GetModCap_x                                  0x4E2120
#define PcZoneClient__CanEquipItem_x                               0x631640
#define PcZoneClient__GetItemByID_x                                0x634210
#define PcZoneClient__GetItemByItemClass_x                         0x634360
#define PcZoneClient__RemoveBuffEffect_x                           0x637250
#define PcZoneClient__BandolierSwap_x                              0x632270

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C8980

//IconCache
#define IconCache__GetIcon_x                                       0x7085E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x700090
#define CContainerMgr__CloseContainer_x                            0x700360
#define CContainerMgr__OpenExperimentContainer_x                   0x700DE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C2E50

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6046F0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75DDA0
#define CLootWnd__RequestLootSlot_x                                0x75D160

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x563C50
#define EQ_Spell__SpellAffects_x                                   0x5640C0
#define EQ_Spell__SpellAffectBase_x                                0x563E80
#define EQ_Spell__IsStackable_x                                    0x4C6E50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6CD0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3FD0
#define EQ_Spell__IsSPAStacking_x                                  0x564EF0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x564410
#define EQ_Spell__IsNoRemove_x                                     0x4C6E30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x564F00
#define __IsResEffectSpell_x                                       0x4C6140

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA900

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C02A0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x808840
#define CTargetWnd__WndNotification_x                              0x8080D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8083A0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x807220

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80CF20

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5280D0
#define CTaskManager__HandleMessage_x                              0x526820

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55F1F0
#define EqSoundManager__PlayScriptMp3_x                            0x55F350
#define EqSoundManager__SoundAssistPlay_x                          0x66E4B0
#define EqSoundManager__WaveInstancePlay_x                         0x66DA20

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51C0C0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x932260

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5532A0
#define CAltAbilityData__GetMercMaxRank_x                          0x553240
#define CAltAbilityData__GetMaxRank_x                              0x548630

//CTargetRing
#define CTargetRing__Cast_x                                        0x6027F0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6CB0
#define CharacterBase__CreateItemGlobalIndex_x                     0x502480
#define CharacterBase__CreateItemIndex_x                           0x60A8B0
#define CharacterBase__GetItemPossession_x                         0x4B3E80
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C8920
#define CharacterBase__GetEffectId_x                               0x4C6C60

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E8130
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E8950

//messages
#define msg_spell_worn_off_x                                       0x588A70
#define msg_new_text_x                                             0x57D880
#define __msgTokenTextParam_x                                      0x58B0E0
#define msgTokenText_x                                             0x58B330

//SpellManager
#define SpellManager__vftable_x                                    0xAB4AA0
#define SpellManager__SpellManager_x                               0x6717D0
#define Spellmanager__LoadTextSpells_x                             0x6720A0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6719A0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97D4A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x502B60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58EF10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6235D0
#define ItemGlobalIndex__IsValidIndex_x                            0x502BC0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C0BE0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C0E60

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x756970

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7047F0
#define CCursorAttachment__Deactivate_x                            0x7057D0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x944BD0
#define CEQSuiteTextureLoader__GetTexture_x                        0x944890

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FFA00

//IString
#define IString__Append_x                                          0x4EF570

//Camera
#define CDisplay__cameraType_x                                     0xDC6B44
#define EverQuest__Cameras_x                                       0xE89848

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x508220
#define LootFiltersManager__GetItemFilterData_x                    0x507B10
#define LootFiltersManager__RemoveItemLootFilter_x                 0x507B40
#define LootFiltersManager__SetItemLootFilter_x                    0x507D60

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B0E40

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9831D0
#define CResolutionHandler__GetWindowedStyle_x                     0x6690C0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FCE40

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D33F0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71D020
#define CGroupWnd__UpdateDisplay_x                                 0x71C380

//ItemBase
#define ItemBase__IsLore_x                                         0x896A60
#define ItemBase__IsLoreEquipped_x                                 0x896AD0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F5D90

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C2A70
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C2C20
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C2C80

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65E9B0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x662610

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E4F20
#define FactionManagerClient__HandleFactionMessage_x               0x4E55A0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E5B80
#define FactionManagerClient__GetMaxFaction_x                      0x4E5BD0
#define FactionManagerClient__GetMinFaction_x                      0x4E5B50

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
