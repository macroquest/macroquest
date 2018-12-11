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
#define __ExpectedVersionDate                                     "Dec 10 2018"
#define __ExpectedVersionTime                                     "11:34:52"
#define __ActualVersionDate_x                                      0xAD118C
#define __ActualVersionTime_x                                      0xAD1180

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x616360
#define __MemChecker1_x                                            0x8EAA70
#define __MemChecker2_x                                            0x6A5660
#define __MemChecker3_x                                            0x6A55B0
#define __MemChecker4_x                                            0x841C80
#define __EncryptPad0_x                                            0xC05340
#define __EncryptPad1_x                                            0xC635D0
#define __EncryptPad2_x                                            0xC15EC8
#define __EncryptPad3_x                                            0xC15AC8
#define __EncryptPad4_x                                            0xC53E40
#define __EncryptPad5_x                                            0x1034AE8
#define __AC1_x                                                    0x7FE8A6
#define __AC2_x                                                    0x5D0F3F
#define __AC3_x                                                    0x5D7DCF
#define __AC4_x                                                    0x5DBBF0
#define __AC5_x                                                    0x5E1E60
#define __AC6_x                                                    0x5E6436
#define __AC7_x                                                    0x5D09B0
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
#define __do_loot_x                                                0x59E410
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
#define __gpbCommandEvent_x                                        0xE7A774
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
#define __gfMaxZoomCameraDistance_x                                0xAC6698
#define __gfMaxCameraDistance_x                                    0xAF3AF0
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
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
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
#define pinstCItemOverflowWnd_x                                    0xDC6644
#define pinstCJournalCatWnd_x                                      0xDC65A8
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
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
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
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
//#define pinstCRewardSelectionWnd_x                               0x10205B0
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
#define __CastRay_x                                                0x599930
#define __CastRay2_x                                               0x599980
#define __ConvertItemTags_x                                        0x5B45B0
#define __CrashHandler_x                                           0x84B640
#define __EQGetTime_x                                              0x8EA560
#define __ExecuteCmd_x                                             0x592270
#define __FixHeading_x                                             0x97AFB0
#define __get_bearing_x                                            0x599480
#define __get_melee_range_x                                        0x599B70
#define __GetAnimationCache_x                                      0x708D40
#define __GetGaugeValueFromEQ_x                                    0x7FD0B0
#define __GetLabelFromEQ_x                                         0x7FE830
#define __GetXTargetType_x                                         0x97CB50
#define __HandleMouseWheel_x                                       0x6A5710
#define __HeadingDiff_x                                            0x97B020
#define __HelpPath_x                                               0xF2759C
#define __LoadFrontEnd_x                                           0x6A14C0
#define __NewUIINI_x                                               0x7FCD80
#define __pCrashHandler_x                                          0x105D420
#define __ProcessGameEvents_x                                      0x5F7740
#define __ProcessMouseEvent_x                                      0x5F6F00
#define __SaveColors_x                                             0x543040
#define __STMLToText_x                                             0x91E1E0
#define __ToggleKeyRingItem_x                                      0x506000
#define CrashDetected_x                                            0x6A2FB0
#define DrawNetStatus_x                                            0x6239A0
#define Expansion_HoT_x                                            0xE8950C
#define Teleport_Table_Size_x                                      0xE7A808
#define Teleport_Table_x                                           0xE78648
#define Util__FastTime_x                                           0x8EA120
#define wwsCrashReportCheckForUploader_x                           0x84C440
#define wwsCrashReportPlatformLaunchUploader_x                     0x84EB00

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B5E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494440
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494200

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54AB30
#define AltAdvManager__IsAbilityReady_x                            0x549A80
#define AltAdvManager__GetAAById_x                                 0x549C80
#define AltAdvManager__CanTrainAbility_x                           0x549CF0
#define AltAdvManager__CanSeeAbility_x                             0x54A050

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C75D0
#define CharacterZoneClient__HasSkill_x                            0x4D22A0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D39C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB9D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8140
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6380
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6460
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6540
#define CharacterZoneClient__FindAffectSlot_x                      0x4C04B0
#define CharacterZoneClient__BardCastBard_x                        0x4C3120
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8210
#define CharacterZoneClient__GetEffect_x                           0x4B8080
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C14B0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1580
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C15D0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1720
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C18F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CB200
#define CBankWnd__WndNotification_x                                0x6CAFE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D8980

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6060B0
#define CButtonWnd__CButtonWnd_x                                   0x91A5D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F7630
#define CChatManager__InitContextMenu_x                            0x6F16D0
#define CChatManager__FreeChatWindow_x                             0x6F6540
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FAFA0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F73D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92EDB0
#define CContextMenu__dCContextMenu_x                              0x92EFE0
#define CContextMenu__AddMenuItem_x                                0x92EFF0
#define CContextMenu__RemoveMenuItem_x                             0x92F2F0
#define CContextMenu__RemoveAllMenuItems_x                         0x92F310
#define CContextMenu__CheckMenuItem_x                              0x92F390
#define CContextMenu__SetMenuItem_x                                0x92F220
#define CContextMenu__AddSeparator_x                               0x92F180

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92F930
#define CContextMenuManager__RemoveMenu_x                          0x92F9A0
#define CContextMenuManager__PopupMenu_x                           0x92FA60
#define CContextMenuManager__Flush_x                               0x92F8D0
#define CContextMenuManager__GetMenu_x                             0x4965C0
#define CContextMenuManager__CreateDefaultMenu_x                   0x703530

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CAE40
#define CChatService__GetFriendName_x                              0x8CAE50

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F7BB0
#define CChatWindow__Clear_x                                       0x6F8C00
#define CChatWindow__WndNotification_x                             0x6F9170

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92C250
#define CComboWnd__Draw_x                                          0x92B750
#define CComboWnd__GetCurChoice_x                                  0x92C090
#define CComboWnd__GetListRect_x                                   0x92BC00
#define CComboWnd__GetTextRect_x                                   0x92C2B0
#define CComboWnd__InsertChoice_x                                  0x92BD90
#define CComboWnd__SetColors_x                                     0x92BD60
#define CComboWnd__SetChoice_x                                     0x92C060
#define CComboWnd__GetItemCount_x                                  0x92C0A0
#define CComboWnd__GetCurChoiceText_x                              0x92C0E0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x700F20
#define CContainerWnd__vftable_x                                   0xADA430
#define CContainerWnd__SetContainer_x                              0x702490

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x542E00
#define CDisplay__GetClickedActor_x                                0x535DB0
#define CDisplay__GetUserDefinedColor_x                            0x52E490
#define CDisplay__GetWorldFilePath_x                               0x537800
#define CDisplay__is3dON_x                                         0x532A80
#define CDisplay__ReloadUI_x                                       0x53CF20
#define CDisplay__WriteTextHD2_x                                   0x532860
#define CDisplay__TrueDistance_x                                   0x539460
#define CDisplay__SetViewActor_x                                   0x535700
#define CDisplay__GetFloorHeight_x                                 0x532B40
#define CDisplay__SetRenderWindow_x                                0x531470
#define CDisplay__ToggleScreenshotMode_x                           0x5351D0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94E5A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9334A0
#define CEditWnd__GetCharIndexPt_x                                 0x934390
#define CEditWnd__GetDisplayString_x                               0x934230
#define CEditWnd__GetHorzOffset_x                                  0x932AD0
#define CEditWnd__GetLineForPrintableChar_x                        0x935590
#define CEditWnd__GetSelStartPt_x                                  0x934640
#define CEditWnd__GetSTMLSafeText_x                                0x934050
#define CEditWnd__PointFromPrintableChar_x                         0x9351C0
#define CEditWnd__SelectableCharFromPoint_x                        0x935330
#define CEditWnd__SetEditable_x                                    0x934710

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E5960
#define CEverQuest__ClickedPlayer_x                                0x5D7BB0
#define CEverQuest__CreateTargetIndicator_x                        0x5F49F0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F4A80
#define CEverQuest__DoTellWindow_x                                 0x4E3590
#define CEverQuest__OutputTextToLog_x                              0x4E37C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5CD470
#define CEverQuest__dsp_chat_x                                     0x4E3B50
#define CEverQuest__trimName_x                                     0x5F0D70
#define CEverQuest__Emote_x                                        0x5E6170
#define CEverQuest__EnterZone_x                                    0x5E0210
#define CEverQuest__GetBodyTypeDesc_x                              0x5EA610
#define CEverQuest__GetClassDesc_x                                 0x5EAC50
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EB250
#define CEverQuest__GetDeityDesc_x                                 0x5F3340
#define CEverQuest__GetLangDesc_x                                  0x5EB410
#define CEverQuest__GetRaceDesc_x                                  0x5EAC30
#define CEverQuest__InterpretCmd_x                                 0x5F3910
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D1660
#define CEverQuest__LMouseUp_x                                     0x5CF9E0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D1F40
#define CEverQuest__RMouseUp_x                                     0x5D0970
#define CEverQuest__SetGameState_x                                 0x5CD200
#define CEverQuest__UPCNotificationFlush_x                         0x5F0C70
#define CEverQuest__IssuePetCommand_x                              0x5EC810
#define CEverQuest__ReportSuccessfulHit_x                          0x5E7570

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x712ED0
#define CGaugeWnd__CalcLinesFillRect_x                             0x712F30
#define CGaugeWnd__Draw_x                                          0x7125D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACCD0
#define CGuild__GetGuildName_x                                     0x4ABDB0
#define CGuild__GetGuildIndex_x                                    0x4AC140

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72E250

//CHotButton
#define CHotButton__SetButtonSize_x                                0x606470

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73B230
#define CInvSlotMgr__MoveItem_x                                    0x739F40
#define CInvSlotMgr__SelectSlot_x                                  0x73B300

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7387F0
#define CInvSlot__SliderComplete_x                                 0x736550
#define CInvSlot__GetItemBase_x                                    0x735ED0
#define CInvSlot__UpdateItem_x                                     0x736040

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73CC50
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73BF20
#define CInvSlotWnd__HandleLButtonUp_x                             0x73C7D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F92A0
#define CItemDisplayWnd__UpdateStrings_x                           0x74AE50
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x744DB0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7452D0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74B460
#define CItemDisplayWnd__AboutToShow_x                             0x74AA90
#define CItemDisplayWnd__WndNotification_x                         0x74C9B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x830B20

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x750B00

// CLabel 
#define CLabel__Draw_x                                             0x7565C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x904A10
#define CListWnd__dCListWnd_x                                      0x904D20
#define CListWnd__AddColumn_x                                      0x909010
#define CListWnd__AddColumn1_x                                     0x909060
#define CListWnd__AddLine_x                                        0x9093F0
#define CListWnd__AddString_x                                      0x9091F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x908DD0
#define CListWnd__CalculateVSBRange_x                              0x908BB0
#define CListWnd__ClearSel_x                                       0x909BD0
#define CListWnd__ClearAllSel_x                                    0x909C30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90A640
#define CListWnd__Compare_x                                        0x908500
#define CListWnd__Draw_x                                           0x904E20
#define CListWnd__DrawColumnSeparators_x                           0x9075E0
#define CListWnd__DrawHeader_x                                     0x907A50
#define CListWnd__DrawItem_x                                       0x907E40
#define CListWnd__DrawLine_x                                       0x907750
#define CListWnd__DrawSeparator_x                                  0x907680
#define CListWnd__EnableLine_x                                     0x906EC0
#define CListWnd__EnsureVisible_x                                  0x90A570
#define CListWnd__ExtendSel_x                                      0x909B00
#define CListWnd__GetColumnMinWidth_x                              0x906A00
#define CListWnd__GetColumnWidth_x                                 0x906970
#define CListWnd__GetCurSel_x                                      0x906300
#define CListWnd__GetItemAtPoint_x                                 0x907130
#define CListWnd__GetItemAtPoint1_x                                0x9071A0
#define CListWnd__GetItemData_x                                    0x906380
#define CListWnd__GetItemHeight_x                                  0x906740
#define CListWnd__GetItemIcon_x                                    0x906510
#define CListWnd__GetItemRect_x                                    0x906FB0
#define CListWnd__GetItemText_x                                    0x9063C0
#define CListWnd__GetSelList_x                                     0x909C80
#define CListWnd__GetSeparatorRect_x                               0x9073E0
#define CListWnd__InsertLine_x                                     0x9097E0
#define CListWnd__RemoveLine_x                                     0x909930
#define CListWnd__SetColors_x                                      0x908B90
#define CListWnd__SetColumnJustification_x                         0x9088C0
#define CListWnd__SetColumnWidth_x                                 0x9087E0
#define CListWnd__SetCurSel_x                                      0x909A40
#define CListWnd__SetItemColor_x                                   0x90A230
#define CListWnd__SetItemData_x                                    0x90A1F0
#define CListWnd__SetItemText_x                                    0x909E00
#define CListWnd__ShiftColumnSeparator_x                           0x908980
#define CListWnd__Sort_x                                           0x908680
#define CListWnd__ToggleSel_x                                      0x909A70

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76BB30
#define CMapViewWnd__GetWorldCoordinates_x                         0x76A240
#define CMapViewWnd__HandleLButtonDown_x                           0x7672A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78EEB0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78F790
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78FCC0
#define CMerchantWnd__SelectRecoverySlot_x                         0x792B00
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78D890
#define CMerchantWnd__SelectBuySellSlot_x                          0x7986F0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78EAF0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x898C20
#define CPacketScrambler__hton_x                                   0x898C10

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9237E0
#define CSidlManager__FindScreenPieceTemplate_x                    0x923BF0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9239E0
#define CSidlManager__CreateLabel_x                                0x7F06B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x926CC0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x926EA0
#define CSidlManager__CreateXWnd_x                                 0x7F05E0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F0BA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x920350
#define CSidlScreenWnd__CalculateVSBRange_x                        0x920240
#define CSidlScreenWnd__ConvertToRes_x                             0x9453D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91FCD0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91F9C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91FA90
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91FB60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9207F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x920CC0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9209E0
#define CSidlScreenWnd__Init1_x                                    0x91F5D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x920D10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x921850
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91E9D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9213D0
#define CSidlScreenWnd__StoreIniVis_x                              0x921730
#define CSidlScreenWnd__WndNotification_x                          0x920700
#define CSidlScreenWnd__GetChildItem_x                             0x920C40
#define CSidlScreenWnd__HandleLButtonUp_x                          0x910430
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B8390

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66AA50
#define CSkillMgr__GetSkillCap_x                                   0x66AC30
#define CSkillMgr__GetNameToken_x                                  0x66A1E0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x930730
#define CSliderWnd__SetValue_x                                     0x9305A0
#define CSliderWnd__SetNumTicks_x                                  0x930600

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F6500

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x937510
#define CStmlWnd__CalculateHSBRange_x                              0x9385C0
#define CStmlWnd__CalculateVSBRange_x                              0x938530
#define CStmlWnd__CanBreakAtCharacter_x                            0x93C930
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93D5C0
#define CStmlWnd__ForceParseNow_x                                  0x937AB0
#define CStmlWnd__GetNextTagPiece_x                                0x93C890
#define CStmlWnd__GetSTMLText_x                                    0x4F5690
#define CStmlWnd__GetVisibleText_x                                 0x937AD0
#define CStmlWnd__InitializeWindowVariables_x                      0x93D410
#define CStmlWnd__MakeStmlColorTag_x                               0x936BF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x936C60
#define CStmlWnd__SetSTMLText_x                                    0x935CA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x93E720
#define CStmlWnd__UpdateHistoryString_x                            0x93D7D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9423A0
#define CTabWnd__DrawCurrentPage_x                                 0x9429C0
#define CTabWnd__DrawTab_x                                         0x942790
#define CTabWnd__GetCurrentPage_x                                  0x941C00
#define CTabWnd__GetPageInnerRect_x                                0x941E40
#define CTabWnd__GetTabInnerRect_x                                 0x941D80
#define CTabWnd__GetTabRect_x                                      0x941C30
#define CTabWnd__InsertPage_x                                      0x942030
#define CTabWnd__SetPage_x                                         0x941EC0
#define CTabWnd__SetPageRect_x                                     0x9422E0
#define CTabWnd__UpdatePage_x                                      0x942650
#define CTabWnd__GetPageFromTabIndex_x                             0x9426D0
#define CTabWnd__GetCurrentTabIndex_x                              0x941BF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x750FB0
#define CPageWnd__SetTabText_x                                     0x94E9B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A67E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90D290
#define CTextureFont__GetTextExtent_x                              0x90D450

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69E300
#define CHtmlComponentWnd__ValidateUri_x                           0x72FC40
#define CHtmlWnd__SetClientCallbacks_x                             0x60B420
#define CHtmlWnd__AddObserver_x                                    0x60B440
#define CHtmlWnd__RemoveObserver_x                                 0x60B4A0
#define Window__getProgress_x                                      0x8492A0
#define Window__getStatus_x                                        0x8492C0
#define Window__getURI_x                                           0x8492D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94AF30

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FA2A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADF70
#define CXStr__CXStr1_x                                            0x4F08E0
#define CXStr__CXStr3_x                                            0x8E6690
#define CXStr__dCXStr_x                                            0x473020
#define CXStr__operator_equal_x                                    0x8E68C0
#define CXStr__operator_equal1_x                                   0x8E6900
#define CXStr__operator_plus_equal1_x                              0x8E7390

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92E9D0
#define CXWnd__BringToTop_x                                        0x913BE0
#define CXWnd__Center_x                                            0x913760
#define CXWnd__ClrFocus_x                                          0x9135A0
#define CXWnd__Destroy_x                                           0x913640
#define CXWnd__DoAllDrawing_x                                      0x90FBC0
#define CXWnd__DrawChildren_x                                      0x90FB90
#define CXWnd__DrawColoredRect_x                                   0x910020
#define CXWnd__DrawTooltip_x                                       0x90E6E0
#define CXWnd__DrawTooltipAtPoint_x                                0x90E7A0
#define CXWnd__GetBorderFrame_x                                    0x90FE80
#define CXWnd__GetChildWndAt_x                                     0x913C80
#define CXWnd__GetClientClipRect_x                                 0x911EA0
#define CXWnd__GetScreenClipRect_x                                 0x911F70
#define CXWnd__GetScreenRect_x                                     0x912140
#define CXWnd__GetTooltipRect_x                                    0x910070
#define CXWnd__GetWindowTextA_x                                    0x497D60
#define CXWnd__IsActive_x                                          0x916AD0
#define CXWnd__IsDescendantOf_x                                    0x912B60
#define CXWnd__IsReallyVisible_x                                   0x912B90
#define CXWnd__IsType_x                                            0x9142E0
#define CXWnd__Move_x                                              0x912C00
#define CXWnd__Move1_x                                             0x912CB0
#define CXWnd__ProcessTransition_x                                 0x913710
#define CXWnd__Refade_x                                            0x912F80
#define CXWnd__Resize_x                                            0x913200
#define CXWnd__Right_x                                             0x9139A0
#define CXWnd__SetFocus_x                                          0x913560
#define CXWnd__SetFont_x                                           0x9135D0
#define CXWnd__SetKeyTooltip_x                                     0x914110
#define CXWnd__SetMouseOver_x                                      0x910FF0
#define CXWnd__StartFade_x                                         0x912A30
#define CXWnd__GetChildItem_x                                      0x913DF0
#define CXWnd__SetParent_x                                         0x9128F0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9464B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x916B10
#define CXWndManager__DrawWindows_x                                0x916B30
#define CXWndManager__GetKeyboardFlags_x                           0x9192B0
#define CXWndManager__HandleKeyboardMsg_x                          0x918EB0
#define CXWndManager__RemoveWnd_x                                  0x919500
#define CXWndManager__RemovePendingDeletionWnd_x                   0x919A40

// CDBStr
#define CDBStr__GetString_x                                        0x52D440

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B90F0
#define EQ_Character__Cur_HP_x                                     0x4CF320
#define EQ_Character__Cur_Mana_x                                   0x4D6A40
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BC010
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFB80
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFCD0
#define EQ_Character__GetHPRegen_x                                 0x4DC9A0
#define EQ_Character__GetEnduranceRegen_x                          0x4DCFB0
#define EQ_Character__GetManaRegen_x                               0x4DD3F0
#define EQ_Character__Max_Endurance_x                              0x6312C0
#define EQ_Character__Max_HP_x                                     0x4CF150
#define EQ_Character__Max_Mana_x                                   0x6310C0
#define EQ_Character__doCombatAbility_x                            0x633790
#define EQ_Character__UseSkill_x                                   0x4DF200
#define EQ_Character__GetConLevel_x                                0x62A810
#define EQ_Character__IsExpansionFlag_x                            0x590A20
#define EQ_Character__TotalEffect_x                                0x4C26A0
#define EQ_Character__GetPCSpellAffect_x                           0x4BCC00
#define EQ_Character__SpellDuration_x                              0x4BC730
#define EQ_Character__FindItemByRecord_x                           0x4D4930
#define EQ_Character__GetAdjustedSkill_x                           0x4D2060
#define EQ_Character__GetBaseSkill_x                               0x4D3000
#define EQ_Character__CanUseItem_x                                 0x4D6D50

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B7D00

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x647630

//PcClient
#define PcClient__PcClient_x                                       0x627F40

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6D60
#define CCharacterListWnd__EnterWorld_x                            0x4B67A0
#define CCharacterListWnd__Quit_x                                  0x4B64B0
#define CCharacterListWnd__UpdateList_x                            0x4B6930

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60C660
#define EQ_Item__CreateItemTagString_x                             0x8925D0
#define EQ_Item__IsStackable_x                                     0x896FD0
#define EQ_Item__GetImageNum_x                                     0x894010
#define EQ_Item__CreateItemClient_x                                0x60B820
#define EQ_Item__GetItemValue_x                                    0x895270
#define EQ_Item__ValueSellMerchant_x                               0x8987B0
#define EQ_Item__IsKeyRingItem_x                                   0x896920
#define EQ_Item__CanGoInBag_x                                      0x60C780
#define EQ_Item__GetMaxItemCount_x                                 0x895640
#define EQ_Item__GetHeldItem_x                                     0x893EE0
#define EQ_Item__GetAugmentFitBySlot_x                             0x891F00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54B810
#define EQ_LoadingS__Array_x                                       0xBED130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x631C20
#define EQ_PC__GetAlternateAbilityId_x                             0x8A19B0
#define EQ_PC__GetCombatAbility_x                                  0x8A2020
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A2090
#define EQ_PC__GetItemRecastTimer_x                                0x633D10
#define EQ_PC__HasLoreItem_x                                       0x62AF80
#define EQ_PC__AlertInventoryChanged_x                             0x62A140
#define EQ_PC__GetPcZoneClient_x                                   0x656030
#define EQ_PC__RemoveMyAffect_x                                    0x636F10
#define EQ_PC__GetKeyRingItems_x                                   0x8A2930
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A26B0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A2C20

// EQItemList 
#define EQItemList__EQItemList_x                                   0x596EB0
#define EQItemList__add_object_x                                   0x5C2BA0
#define EQItemList__add_item_x                                     0x5974C0
#define EQItemList__delete_item_x                                  0x597510
#define EQItemList__FreeItemList_x                                 0x597410

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52AA50

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x648EB0
#define EQPlayer__dEQPlayer_x                                      0x63C590
#define EQPlayer__DoAttack_x                                       0x650CF0
#define EQPlayer__EQPlayer_x                                       0x63CC40
#define EQPlayer__SetNameSpriteState_x                             0x640EE0
#define EQPlayer__SetNameSpriteTint_x                              0x641DB0
#define PlayerBase__HasProperty_j_x                                0x979380
#define EQPlayer__IsTargetable_x                                   0x979820
#define EQPlayer__CanSee_x                                         0x979680
#define EQPlayer__CanSee1_x                                        0x979750
#define PlayerBase__GetVisibilityLineSegment_x                     0x979440

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x653AC0
#define PlayerZoneClient__GetLevel_x                               0x656070
#define PlayerZoneClient__IsValidTeleport_x                        0x5C3D00
#define PlayerZoneClient__LegalPlayerRace_x                        0x544BD0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64BD50
#define EQPlayerManager__GetSpawnByName_x                          0x64BD70
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64BE00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60FF00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60FF40
#define KeypressHandler__ClearCommandStateArray_x                  0x611330
#define KeypressHandler__HandleKeyDown_x                           0x611350
#define KeypressHandler__HandleKeyUp_x                             0x6113F0
#define KeypressHandler__SaveKeymapping_x                          0x6117D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7679C0
#define MapViewMap__SaveEx_x                                       0x76AD60
#define MapViewMap__SetZoom_x                                      0x76F430

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B5BF0

// StringTable 
#define StringTable__getString_x                                   0x8B0BB0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x636B80
#define PcZoneClient__RemovePetEffect_x                            0x6371B0
#define PcZoneClient__HasAlternateAbility_x                        0x630F00
#define PcZoneClient__GetCurrentMod_x                              0x4E2300
#define PcZoneClient__GetModCap_x                                  0x4E2200
#define PcZoneClient__CanEquipItem_x                               0x6315B0
#define PcZoneClient__GetItemByID_x                                0x634190
#define PcZoneClient__GetItemByItemClass_x                         0x6342E0
#define PcZoneClient__RemoveBuffEffect_x                           0x6371D0
#define PcZoneClient__BandolierSwap_x                              0x6321E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C8950

//IconCache
#define IconCache__GetIcon_x                                       0x7085D0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7000B0
#define CContainerMgr__CloseContainer_x                            0x700380
#define CContainerMgr__OpenExperimentContainer_x                   0x700E00

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C2CB0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x604890

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75DDC0
#define CLootWnd__RequestLootSlot_x                                0x75D170

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x563C50
#define EQ_Spell__SpellAffects_x                                   0x5640C0
#define EQ_Spell__SpellAffectBase_x                                0x563E80
#define EQ_Spell__IsStackable_x                                    0x4C6F00
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6D80
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B40B0
#define EQ_Spell__IsSPAStacking_x                                  0x564EF0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x564410
#define EQ_Spell__IsNoRemove_x                                     0x4C6EE0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x564F00
#define __IsResEffectSpell_x                                       0x4C6200

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA9E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C0290

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x808630
#define CTargetWnd__WndNotification_x                              0x807EC0
#define CTargetWnd__RefreshTargetBuffs_x                           0x808190
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x807010

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80CD00

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x528390
#define CTaskManager__HandleMessage_x                              0x526AF0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55F1F0
#define EqSoundManager__PlayScriptMp3_x                            0x55F350
#define EqSoundManager__SoundAssistPlay_x                          0x66E8F0
#define EqSoundManager__WaveInstancePlay_x                         0x66DE60

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51C350

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x932110

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x553460
#define CAltAbilityData__GetMercMaxRank_x                          0x553400
#define CAltAbilityData__GetMaxRank_x                              0x548930

//CTargetRing
#define CTargetRing__Cast_x                                        0x602990

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6D60
#define CharacterBase__CreateItemGlobalIndex_x                     0x502490
#define CharacterBase__CreateItemIndex_x                           0x60AA60
#define CharacterBase__GetItemPossession_x                         0x4B3F60
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C8920
#define CharacterBase__GetEffectId_x                               0x4C6D10

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E81C0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E89E0

//messages
#define msg_spell_worn_off_x                                       0x588B20
#define msg_new_text_x                                             0x57D920
#define __msgTokenTextParam_x                                      0x58B180
#define msgTokenText_x                                             0x58B3D0

//SpellManager
#define SpellManager__vftable_x                                    0xAB4A88
#define SpellManager__SpellManager_x                               0x671C20
#define Spellmanager__LoadTextSpells_x                             0x6724F0
#define SpellManager__GetSpellByGroupAndRank_x                     0x671DF0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97D440

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x502B70
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58EFA0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x623800
#define ItemGlobalIndex__IsValidIndex_x                            0x502BD0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C0BD0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C0E50

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x756900

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x704820
#define CCursorAttachment__Deactivate_x                            0x705800

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9448B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x944570

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FFA40

//IString
#define IString__Append_x                                          0x4EFA20

//Camera
#define CDisplay__cameraType_x                                     0xDC6B44
#define EverQuest__Cameras_x                                       0xE89848

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x508280
#define LootFiltersManager__GetItemFilterData_x                    0x507B80
#define LootFiltersManager__RemoveItemLootFilter_x                 0x507BB0
#define LootFiltersManager__SetItemLootFilter_x                    0x507DD0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B0CA0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x983100
#define CResolutionHandler__GetWindowedStyle_x                     0x669410

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FCE00

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D33F0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71D040
#define CGroupWnd__UpdateDisplay_x                                 0x71C3A0

//ItemBase
#define ItemBase__IsLore_x                                         0x896980
#define ItemBase__IsLoreEquipped_x                                 0x8969F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C2A90
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C2C40
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C2CA0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65EBD0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x662830

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F5C90

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E4FE0
#define FactionManagerClient__HandleFactionMessage_x               0x4E5660
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E5C40
#define FactionManagerClient__GetMaxFaction_x                      0x4E5C90
#define FactionManagerClient__GetMinFaction_x                      0x4E5C10

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

