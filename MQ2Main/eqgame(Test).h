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
#define __ExpectedVersionDate                                     "Feb 22 2019"
#define __ExpectedVersionTime                                     "10:33:03"
#define __ActualVersionDate_x                                      0xAD015C
#define __ActualVersionTime_x                                      0xAD0150

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x615720
#define __MemChecker1_x                                            0x8EA080
#define __MemChecker2_x                                            0x6A4A80
#define __MemChecker3_x                                            0x6A49D0
#define __MemChecker4_x                                            0x841520
#define __EncryptPad0_x                                            0xC04348
#define __EncryptPad1_x                                            0xC625D8
#define __EncryptPad2_x                                            0xC14ED0
#define __EncryptPad3_x                                            0xC14AD0
#define __EncryptPad4_x                                            0xC52E48
#define __EncryptPad5_x                                            0x1034508
#define __AC1_x                                                    0x7FE2C6
#define __AC2_x                                                    0x5D046F
#define __AC3_x                                                    0x5D72FF
#define __AC4_x                                                    0x5DB130
#define __AC5_x                                                    0x5E13A0
#define __AC6_x                                                    0x5E5966
#define __AC7_x                                                    0x5CFEE0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E89CC4

// Direct Input
#define DI8__Main_x                                                0x1034528
#define DI8__Keyboard_x                                            0x103452C
#define DI8__Mouse_x                                               0xF29480
#define DI8__Mouse_Copy_x                                          0xE871C4
#define DI8__Mouse_Check_x                                         0xF2A1B0
#define __AutoSkillArray_x                                         0xE880DC
#define __Attack_x                                                 0xF25EEB
#define __Autofire_x                                               0xF25EEC
#define __BindList_x                                               0xBF2F28
#define g_eqCommandStates_x                                        0xBF3C98
#define __Clicks_x                                                 0xE8727C
#define __CommandList_x                                            0xBF4850
#define __CurrentMapLabel_x                                        0x103BA84
#define __CurrentSocial_x                                          0xBDD730
#define __DoAbilityList_x                                          0xEBDA0C
#define __do_loot_x                                                0x59D730
#define __DrawHandler_x                                            0x16B8458
#define __GroupCount_x                                             0xE7749A
#define __Guilds_x                                                 0xE7D9D0
#define __gWorld_x                                                 0xE79B54
#define __HWnd_x                                                   0xF29484
#define __heqmain_x                                                0x10344F0
#define __InChatMode_x                                             0xE871AC
#define __LastTell_x                                               0xE89108
#define __LMouseHeldTime_x                                         0xE872E8
#define __Mouse_x                                                  0x1034514
#define __MouseLook_x                                              0xE87242
#define __MouseEventTime_x                                         0xF269A0
#define __gpbCommandEvent_x                                        0xE79804
#define __NetStatusToggle_x                                        0xE87245
#define __PCNames_x                                                0xE886C0
#define __RangeAttackReady_x                                       0xE883C0
#define __RMouseHeldTime_x                                         0xE872E4
#define __RunWalkState_x                                           0xE871B0
#define __ScreenMode_x                                             0xDC5D0C
#define __ScreenX_x                                                0xE87164
#define __ScreenY_x                                                0xE87160
#define __ScreenXMax_x                                             0xE87168
#define __ScreenYMax_x                                             0xE8716C
#define __ServerHost_x                                             0xE79A4B
#define __ServerName_x                                             0xEBD9CC
#define __ShiftKeyDown_x                                           0xE8783C
#define __ShowNames_x                                              0xE8857C
#define __Socials_x                                                0xEBDACC
#define __SubscriptionType_x                                       0x107D5D4
#define __TargetAggroHolder_x                                      0x103E440
#define __ZoneType_x                                               0xE87640
#define __GroupAggro_x                                             0x103E480
#define __LoginName_x                                              0xF29B44
#define __Inviter_x                                                0xF25E68
#define __AttackOnAssist_x                                         0xE88538
#define __UseTellWindows_x                                         0xE8885C
#define __gfMaxZoomCameraDistance_x                                0xAC5620
#define __gfMaxCameraDistance_x                                    0xAF2A48
#define __pulAutoRun_x                                             0xE87260
#define __pulForward_x                                             0xE88894
#define __pulBackward_x                                            0xE88898
#define __pulTurnRight_x                                           0xE8889C
#define __pulTurnLeft_x                                            0xE888A0
#define __pulStrafeLeft_x                                          0xE888A4
#define __pulStrafeRight_x                                         0xE888A8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE79D68
#define instEQZoneInfo_x                                           0xE87438
#define instKeypressHandler_x                                      0xF26950
#define pinstActiveBanker_x                                        0xE798AC
#define pinstActiveCorpse_x                                        0xE798A4
#define pinstActiveGMaster_x                                       0xE798A8
#define pinstActiveMerchant_x                                      0xE798A0
#define pinstAggroInfo_x                                           0xC78E18
#define pinstAltAdvManager_x                                       0xDC6708
#define pinstAuraMgr_x                                             0xC94998
#define pinstBandageTarget_x                                       0xE798BC
#define pinstCamActor_x                                            0xDC5D00
#define pinstCDBStr_x                                              0xDC5434
#define pinstCDisplay_x                                            0xE79D5C
#define pinstCEverQuest_x                                          0x1034640
#define pinstEverQuestInfo_x                                       0xE87158
#define pinstCharData_x                                            0xE7745C
#define pinstCharSpawn_x                                           0xE798F4
#define pinstControlledMissile_x                                   0xE79D60
#define pinstControlledPlayer_x                                    0xE798F4
#define pinstCResolutionHandler_x                                  0x16B8688
#define pinstCSidlManager_x                                        0x16B751C
#define pinstCXWndManager_x                                        0x16B7510
#define instDynamicZone_x                                          0xE7D8A8
#define pinstDZMember_x                                            0xE7D9B8
#define pinstDZTimerInfo_x                                         0xE7D9BC
#define pinstEQItemList_x                                          0xE75F58
#define pinstEQObjectList_x                                        0xE77148
#define instEQMisc_x                                               0xDC5378
#define pinstEQSoundManager_x                                      0xDC6F68
#define pinstEQSpellStrings_x                                      0xC86F50
#define instExpeditionLeader_x                                     0xE7D8F2
#define instExpeditionName_x                                       0xE7D932
#define pinstGroup_x                                               0xE77496
#define pinstImeManager_x                                          0x16B7514
#define pinstLocalPlayer_x                                         0xE7981C
#define pinstMercenaryData_x                                       0xF27140
#define pinstMercenaryStats_x                                      0x103E58C
#define pinstMercAltAbilities_x                                    0xDC6CD8
#define pinstModelPlayer_x                                         0xE798B4
#define pinstPCData_x                                              0xE7745C
#define pinstRealEstateItems_x                                     0xF28640
#define pinstSkillMgr_x                                            0xF28710
#define pinstSpawnManager_x                                        0xF27D00
#define pinstSpellManager_x                                        0xF288E8
#define pinstSpellSets_x                                           0xF1EB14
#define pinstStringTable_x                                         0xE796E0
#define pinstSwitchManager_x                                       0xE77308
#define pinstTarget_x                                              0xE798F0
#define pinstTargetObject_x                                        0xE798FC
#define pinstTargetSwitch_x                                        0xE77460
#define pinstTaskMember_x                                          0xDC520C
#define pinstTrackTarget_x                                         0xE798F8
#define pinstTradeTarget_x                                         0xE798B0
#define instTributeActive_x                                        0xDC5399
#define pinstViewActor_x                                           0xDC5CFC
#define pinstWorldData_x                                           0xE7980C
#define pinstZoneAddr_x                                            0xE876D8
#define pinstPlayerPath_x                                          0xF27D98
#define pinstTargetIndicator_x                                     0xF28B50
#define pinstCTargetManager_x                                      0xF28BE8
#define EQObject_Top_x                                             0xE79818
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC5798
#define pinstCAchievementsWnd_x                                    0xDC5790
#define pinstCActionsWnd_x                                         0xDC57F0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC5CA8
#define pinstCAdvancedLootWnd_x                                    0xDC57E8
#define pinstCAdventureLeaderboardWnd_x                            0x1035258
#define pinstCAdventureRequestWnd_x                                0x1035308
#define pinstCAdventureStatsWnd_x                                  0x10353B8
#define pinstCAggroMeterWnd_x                                      0xDC5D28
#define pinstCAlarmWnd_x                                           0xDC54F8
#define pinstCAlertHistoryWnd_x                                    0xDC574C
#define pinstCAlertStackWnd_x                                      0xDC5D38
#define pinstCAlertWnd_x                                           0xDC5D4C
#define pinstCAltStorageWnd_x                                      0x1035718
#define pinstCAudioTriggersWindow_x                                0xC792A8
#define pinstCAuraWnd_x                                            0xDC5D20
#define pinstCAvaZoneWnd_x                                         0xDC5750
#define pinstCBandolierWnd_x                                       0xDC5D54
#define pinstCBankWnd_x                                            0xDC5740
#define pinstCBarterMerchantWnd_x                                  0x1036958
#define pinstCBarterSearchWnd_x                                    0x1036A08
#define pinstCBarterWnd_x                                          0x1036AB8
#define pinstCBazaarConfirmationWnd_x                              0xDC5D34
#define pinstCBazaarSearchWnd_x                                    0xDC5824
#define pinstCBazaarWnd_x                                          0xDC5D64
#define pinstCBlockedBuffWnd_x                                     0xDC5728
#define pinstCBlockedPetBuffWnd_x                                  0xDC5754
#define pinstCBodyTintWnd_x                                        0xDC5CF0
#define pinstCBookWnd_x                                            0xDC54D8
#define pinstCBreathWnd_x                                          0xDC57A4
#define pinstCBuffWindowNORMAL_x                                   0xDC54FC
#define pinstCBuffWindowSHORT_x                                    0xDC5504
#define pinstCBugReportWnd_x                                       0xDC57A0
#define pinstCButtonWnd_x                                          0x16B7740
#define pinstCCastingWnd_x                                         0xDC5794
#define pinstCCastSpellWnd_x                                       0xDC5C9C
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDC57A8
#define pinstCChatWindowManager_x                                  0x1037578
#define pinstCClaimWnd_x                                           0x10376D0
#define pinstCColorPickerWnd_x                                     0xDC57D4
#define pinstCCombatAbilityWnd_x                                   0xDC5D24
#define pinstCCombatSkillsSelectWnd_x                              0xDC57F4
#define pinstCCompassWnd_x                                         0xDC5CD8
#define pinstCConfirmationDialog_x                                 0x103C5D0
#define pinstCContainerMgr_x                                       0xDC5D40
#define pinstCContextMenuManager_x                                 0x16B74D0
#define pinstCCursorAttachment_x                                   0xDC5784
#define pinstCDistillerInfo_x                                      0x103AFDC
#define pinstCDynamicZoneWnd_x                                     0x1037C98
#define pinstCEditLabelWnd_x                                       0xDC54F0
#define pinstCEQMainWnd_x                                          0x1037EE0
#define pinstCEventCalendarWnd_x                                   0xDC57C0
#define pinstCExtendedTargetWnd_x                                  0xDC5CF8
#define pinstCFacePick_x                                           0xDC57CC
#define pinstCFactionWnd_x                                         0xDC578C
#define pinstCFellowshipWnd_x                                      0x10380E0
#define pinstCFileSelectionWnd_x                                   0xDC57DC
#define pinstCFindItemWnd_x                                        0xDC54EC
#define pinstCFindLocationWnd_x                                    0x1038238
#define pinstCFriendsWnd_x                                         0xDC580C
#define pinstCGemsGameWnd_x                                        0xDC5D58
#define pinstCGiveWnd_x                                            0xDC54F4
#define pinstCGroupSearchFiltersWnd_x                              0xDC5D3C
#define pinstCGroupSearchWnd_x                                     0x1038630
#define pinstCGroupWnd_x                                           0x10386E0
#define pinstCGuildBankWnd_x                                       0xE8851C
#define pinstCGuildCreationWnd_x                                   0x1038840
#define pinstCGuildMgmtWnd_x                                       0x10388F0
#define pinstCharacterCreation_x                                   0xDC5D2C
#define pinstCHelpWnd_x                                            0xDC5CD0
#define pinstCHeritageSelectionWnd_x                               0xDC57E0
#define pinstCHotButtonWnd_x                                       0x103AA48
#define pinstCHotButtonWnd1_x                                      0x103AA48
#define pinstCHotButtonWnd2_x                                      0x103AA4C
#define pinstCHotButtonWnd3_x                                      0x103AA50
#define pinstCHotButtonWnd4_x                                      0x103AA54
#define pinstCIconSelectionWnd_x                                   0xDC5768
#define pinstCInspectWnd_x                                         0xDC5774
#define pinstCInventoryWnd_x                                       0xDC5D50
#define pinstCInvSlotMgr_x                                         0xDC5CE4
#define pinstCItemDisplayManager_x                                 0x103AFD8
#define pinstCItemExpTransferWnd_x                                 0x103B108
#define pinstCItemOverflowWnd_x                                    0xDC5C90
#define pinstCJournalCatWnd_x                                      0xDC5800
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDC57C4
#define pinstCKeyRingWnd_x                                         0xDC5518
#define pinstCLargeDialogWnd_x                                     0x103D250
#define pinstCLayoutCopyWnd_x                                      0x103B458
#define pinstCLFGuildWnd_x                                         0x103B508
#define pinstCLoadskinWnd_x                                        0xDC54D4
#define pinstCLootFiltersCopyWnd_x                                 0xC952D0
#define pinstCLootFiltersWnd_x                                     0xDC54DC
#define pinstCLootSettingsWnd_x                                    0xDC5500
#define pinstCLootWnd_x                                            0xDC57B4
#define pinstCMailAddressBookWnd_x                                 0xDC5760
#define pinstCMailCompositionWnd_x                                 0xDC573C
#define pinstCMailIgnoreListWnd_x                                  0xDC5764
#define pinstCMailWnd_x                                            0xDC5514
#define pinstCManageLootWnd_x                                      0xDC6B80
#define pinstCMapToolbarWnd_x                                      0xDC5D5C
#define pinstCMapViewWnd_x                                         0xDC5D48
#define pinstCMarketplaceWnd_x                                     0xDC57C8
#define pinstCMerchantWnd_x                                        0xDC57FC
#define pinstCMIZoneSelectWnd_x                                    0x103BD40
#define pinstCMusicPlayerWnd_x                                     0xDC551C
#define pinstCNameChangeMercWnd_x                                  0xDC5CE0
#define pinstCNameChangePetWnd_x                                   0xDC5CBC
#define pinstCNameChangeWnd_x                                      0xDC57B0
#define pinstCNoteWnd_x                                            0xDC5CA4
#define pinstCObjectPreviewWnd_x                                   0xDC57EC
#define pinstCOptionsWnd_x                                         0xDC5D60
#define pinstCPetInfoWnd_x                                         0xDC5738
#define pinstCPetitionQWnd_x                                       0xDC5810
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDC5CEC
#define pinstCPlayerWnd_x                                          0xDC5804
#define pinstCPopupWndManager_x                                    0x103C5D0
#define pinstCProgressionSelectionWnd_x                            0x103C680
#define pinstCPurchaseGroupWnd_x                                   0xDC588C
#define pinstCPurchaseWnd_x                                        0xDC57F8
#define pinstCPvPLeaderboardWnd_x                                  0x103C730
#define pinstCPvPStatsWnd_x                                        0x103C7E0
#define pinstCQuantityWnd_x                                        0xDC576C
#define pinstCRaceChangeWnd_x                                      0xDC57D0
#define pinstCRaidOptionsWnd_x                                     0xDC5D44
#define pinstCRaidWnd_x                                            0xDC5778
#define pinstCRealEstateItemsWnd_x                                 0xDC579C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC57BC
#define pinstCRealEstateManageWnd_x                                0xDC5510
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC5730
#define pinstCRealEstatePlotSearchWnd_x                            0xDC5758
#define pinstCRealEstatePurchaseWnd_x                              0xDC577C
#define pinstCRespawnWnd_x                                         0xDC5D30
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDC5D18
#define pinstCSendMoneyWnd_x                                       0xDC5508
#define pinstCServerListWnd_x                                      0xDC5748
#define pinstCSkillsSelectWnd_x                                    0xDC57D8
#define pinstCSkillsWnd_x                                          0xDC57B8
#define pinstCSocialEditWnd_x                                      0xDC5788
#define pinstCSocialWnd_x                                          0xDC5D1C
#define pinstCSpellBookWnd_x                                       0xDC5CF4
#define pinstCStoryWnd_x                                           0xDC5CAC
#define pinstCTargetOfTargetWnd_x                                  0x103E610
#define pinstCTargetWnd_x                                          0xDC572C
#define pinstCTaskOverlayWnd_x                                     0xDC575C
#define pinstCTaskSelectWnd_x                                      0x103E768
#define pinstCTaskManager_x                                        0xC95AD0
#define pinstCTaskTemplateSelectWnd_x                              0x103E818
#define pinstCTaskWnd_x                                            0x103E8C8
#define pinstCTextEntryWnd_x                                       0xDC5CDC
#define pinstCTextOverlay_x                                        0xC795B8
#define pinstCTimeLeftWnd_x                                        0xDC57E4
#define pinstCTipWndCONTEXT_x                                      0x103EACC
#define pinstCTipWndOFDAY_x                                        0x103EAC8
#define pinstCTitleWnd_x                                           0x103EB78
#define pinstCTrackingWnd_x                                        0xDC5744
#define pinstCTradeskillWnd_x                                      0x103ECE0
#define pinstCTradeWnd_x                                           0xDC5CE8
#define pinstCTrainWnd_x                                           0xDC5770
#define pinstCTributeBenefitWnd_x                                  0x103EEE0
#define pinstCTributeMasterWnd_x                                   0x103EF90
#define pinstCTributeTrophyWnd_x                                   0x103F040
#define pinstCVideoModesWnd_x                                      0xDC54D0
#define pinstCVoiceMacroWnd_x                                      0xF29118
#define pinstCVoteResultsWnd_x                                     0xDC5C98
#define pinstCVoteWnd_x                                            0xDC5808
#define pinstCWebManager_x                                         0xF2927C
#define pinstCZoneGuideWnd_x                                       0xDC5520
#define pinstCZonePathWnd_x                                        0xDC5734

#define pinstEQSuiteTextureLoader_x                                0xC640A8
#define pinstItemIconCache_x                                       0x1037E98
#define pinstLootFiltersManager_x                                  0xC95380
#define pinstRewardSelectionWnd_x                                  0x103CF28

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC14AC0
#define __CastRay_x                                                0x598C50
#define __CastRay2_x                                               0x598CA0
#define __ConvertItemTags_x                                        0x5B3930
#define __CrashHandler_x                                           0x84AE60
#define __EQGetTime_x                                              0x8E9B70
#define __ExecuteCmd_x                                             0x5915E0
#define __FixHeading_x                                             0x979E90
#define __GameLoop_x                                               0x6A3E80
#define __get_bearing_x                                            0x5987A0
#define __get_melee_range_x                                        0x598E90
#define __GetAnimationCache_x                                      0x7084A0
#define __GetGaugeValueFromEQ_x                                    0x7FCAD0
#define __GetLabelFromEQ_x                                         0x7FE250
#define __GetXTargetType_x                                         0x97B8F0
#define __HandleMouseWheel_x                                       0x6A4B30
#define __HeadingDiff_x                                            0x979F00
#define __HelpPath_x                                               0xF265BC
#define __LoadFrontEnd_x                                           0x6A0960
#define __NewUIINI_x                                               0x7FC7A0
#define __pCrashHandler_x                                          0x105C430
#define __ProcessGameEvents_x                                      0x5F6D70
#define __ProcessMouseEvent_x                                      0x5F6530
#define __SaveColors_x                                             0x5425E0
#define __STMLToText_x                                             0x91D2C0
#define __ToggleKeyRingItem_x                                      0x5059D0
#define CrashDetected_x                                            0x6A23D0
#define DrawNetStatus_x                                            0x622A90
#define Expansion_HoT_x                                            0xE88524
#define Teleport_Table_Size_x                                      0xE79904
#define Teleport_Table_x                                           0xE776D8
#define Util__FastTime_x                                           0x8E9730
#define wwsCrashReportCheckForUploader_x                           0x84BD10
#define wwsCrashReportPlatformLaunchUploader_x                     0x84E3F0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B500
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4943A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494160

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54A120
#define AltAdvManager__IsAbilityReady_x                            0x549070
#define AltAdvManager__GetAAById_x                                 0x549270
#define AltAdvManager__CanTrainAbility_x                           0x5492E0
#define AltAdvManager__CanSeeAbility_x                             0x549640

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C73E0
#define CharacterZoneClient__HasSkill_x                            0x4D22B0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D39D0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB810
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7F90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6380
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6460
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6540
#define CharacterZoneClient__FindAffectSlot_x                      0x4C02F0
#define CharacterZoneClient__BardCastBard_x                        0x4C2F40
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8060
#define CharacterZoneClient__GetEffect_x                           0x4B7ED0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C12F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C13C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1410
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1560
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1730
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AFD30
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4940
#define CharacterZoneClient__FindItemByRecord_x                    0x4D43B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CA7D0
#define CBankWnd__WndNotification_x                                0x6CA5B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D7E00

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x605500
#define CButtonWnd__CButtonWnd_x                                   0x919710

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F6D90
#define CChatManager__InitContextMenu_x                            0x6F0DE0
#define CChatManager__FreeChatWindow_x                             0x6F5CA0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FA700
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F6B30

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92DEC0
#define CContextMenu__dCContextMenu_x                              0x92E0F0
#define CContextMenu__AddMenuItem_x                                0x92E100
#define CContextMenu__RemoveMenuItem_x                             0x92E410
#define CContextMenu__RemoveAllMenuItems_x                         0x92E430
#define CContextMenu__CheckMenuItem_x                              0x92E4B0
#define CContextMenu__SetMenuItem_x                                0x92E330
#define CContextMenu__AddSeparator_x                               0x92E290

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92EA50
#define CContextMenuManager__RemoveMenu_x                          0x92EAC0
#define CContextMenuManager__PopupMenu_x                           0x92EB80
#define CContextMenuManager__Flush_x                               0x92E9F0
#define CContextMenuManager__GetMenu_x                             0x496620
#define CContextMenuManager__CreateDefaultMenu_x                   0x702C60

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CA5C0
#define CChatService__GetFriendName_x                              0x8CA5D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F7300
#define CChatWindow__Clear_x                                       0x6F8360
#define CChatWindow__WndNotification_x                             0x6F88D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92B350
#define CComboWnd__Draw_x                                          0x92A840
#define CComboWnd__GetCurChoice_x                                  0x92B190
#define CComboWnd__GetListRect_x                                   0x92ACF0
#define CComboWnd__GetTextRect_x                                   0x92B3C0
#define CComboWnd__InsertChoice_x                                  0x92AE80
#define CComboWnd__SetColors_x                                     0x92AE50
#define CComboWnd__SetChoice_x                                     0x92B160
#define CComboWnd__GetItemCount_x                                  0x92B1A0
#define CComboWnd__GetCurChoiceText_x                              0x92B1E0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x700650
#define CContainerWnd__vftable_x                                   0xAD9340
#define CContainerWnd__SetContainer_x                              0x701BC0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5423A0
#define CDisplay__GetClickedActor_x                                0x535350
#define CDisplay__GetUserDefinedColor_x                            0x52DA30
#define CDisplay__GetWorldFilePath_x                               0x536DA0
#define CDisplay__is3dON_x                                         0x532020
#define CDisplay__ReloadUI_x                                       0x53C4C0
#define CDisplay__WriteTextHD2_x                                   0x531E00
#define CDisplay__TrueDistance_x                                   0x538A00
#define CDisplay__SetViewActor_x                                   0x534CA0
#define CDisplay__GetFloorHeight_x                                 0x5320E0
#define CDisplay__SetRenderWindow_x                                0x530A10
#define CDisplay__ToggleScreenshotMode_x                           0x534770

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94D6A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9325B0
#define CEditWnd__GetCharIndexPt_x                                 0x9334A0
#define CEditWnd__GetDisplayString_x                               0x933340
#define CEditWnd__GetHorzOffset_x                                  0x931BF0
#define CEditWnd__GetLineForPrintableChar_x                        0x934670
#define CEditWnd__GetSelStartPt_x                                  0x933750
#define CEditWnd__GetSTMLSafeText_x                                0x933160
#define CEditWnd__PointFromPrintableChar_x                         0x9342B0
#define CEditWnd__SelectableCharFromPoint_x                        0x934420
#define CEditWnd__SetEditable_x                                    0x933810

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E4E90
#define CEverQuest__ClickedPlayer_x                                0x5D70E0
#define CEverQuest__CreateTargetIndicator_x                        0x5F4020
#define CEverQuest__DeleteTargetIndicator_x                        0x5F40B0
#define CEverQuest__DoTellWindow_x                                 0x4E3480
#define CEverQuest__OutputTextToLog_x                              0x4E36B0
#define CEverQuest__DropHeldItemOnGround_x                         0x5CC9A0
#define CEverQuest__dsp_chat_x                                     0x4E3A40
#define CEverQuest__trimName_x                                     0x5F0310
#define CEverQuest__Emote_x                                        0x5E56A0
#define CEverQuest__EnterZone_x                                    0x5DF750
#define CEverQuest__GetBodyTypeDesc_x                              0x5E9BB0
#define CEverQuest__GetClassDesc_x                                 0x5EA1F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EA7F0
#define CEverQuest__GetDeityDesc_x                                 0x5F2970
#define CEverQuest__GetLangDesc_x                                  0x5EA9B0
#define CEverQuest__GetRaceDesc_x                                  0x5EA1D0
#define CEverQuest__InterpretCmd_x                                 0x5F2F40
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D0B90
#define CEverQuest__LMouseUp_x                                     0x5CEF10
#define CEverQuest__RightClickedOnPlayer_x                         0x5D1470
#define CEverQuest__RMouseUp_x                                     0x5CFEA0
#define CEverQuest__SetGameState_x                                 0x5CC730
#define CEverQuest__UPCNotificationFlush_x                         0x5F0210
#define CEverQuest__IssuePetCommand_x                              0x5EBDB0
#define CEverQuest__ReportSuccessfulHit_x                          0x5E6AA0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x712630
#define CGaugeWnd__CalcLinesFillRect_x                             0x712690
#define CGaugeWnd__Draw_x                                          0x711D30

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACAB0
#define CGuild__GetGuildName_x                                     0x4ABB90
#define CGuild__GetGuildIndex_x                                    0x4ABF20

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72DA20

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6058C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73A900
#define CInvSlotMgr__MoveItem_x                                    0x739610
#define CInvSlotMgr__SelectSlot_x                                  0x73A9D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x737EC0
#define CInvSlot__SliderComplete_x                                 0x735C20
#define CInvSlot__GetItemBase_x                                    0x7355A0
#define CInvSlot__UpdateItem_x                                     0x735710

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73C430
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73B5E0
#define CInvSlotWnd__HandleLButtonUp_x                             0x73BFB0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F8D10
#define CItemDisplayWnd__UpdateStrings_x                           0x74A870
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7445F0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x744B20
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74AE90
#define CItemDisplayWnd__AboutToShow_x                             0x74A4C0
#define CItemDisplayWnd__WndNotification_x                         0x74C3C0
#define CItemDisplayWnd__RequestConvertItem_x                      0x74BF10
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x749520
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x74A2E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8305B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7504A0

// CLabel 
#define CLabel__Draw_x                                             0x755E90

// CListWnd
#define CListWnd__CListWnd_x                                       0x903A10
#define CListWnd__dCListWnd_x                                      0x903D30
#define CListWnd__AddColumn_x                                      0x908070
#define CListWnd__AddColumn1_x                                     0x9080C0
#define CListWnd__AddLine_x                                        0x908450
#define CListWnd__AddString_x                                      0x908250
#define CListWnd__CalculateFirstVisibleLine_x                      0x907E30
#define CListWnd__CalculateVSBRange_x                              0x907C10
#define CListWnd__ClearSel_x                                       0x908C30
#define CListWnd__ClearAllSel_x                                    0x908C90
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9096B0
#define CListWnd__Compare_x                                        0x907550
#define CListWnd__Draw_x                                           0x903E30
#define CListWnd__DrawColumnSeparators_x                           0x906620
#define CListWnd__DrawHeader_x                                     0x906A90
#define CListWnd__DrawItem_x                                       0x906E90
#define CListWnd__DrawLine_x                                       0x906790
#define CListWnd__DrawSeparator_x                                  0x9066C0
#define CListWnd__EnableLine_x                                     0x905EF0
#define CListWnd__EnsureVisible_x                                  0x9095D0
#define CListWnd__ExtendSel_x                                      0x908B60
#define CListWnd__GetColumnTooltip_x                               0x905A30
#define CListWnd__GetColumnMinWidth_x                              0x905AA0
#define CListWnd__GetColumnWidth_x                                 0x9059A0
#define CListWnd__GetCurSel_x                                      0x905330
#define CListWnd__GetItemAtPoint_x                                 0x906170
#define CListWnd__GetItemAtPoint1_x                                0x9061E0
#define CListWnd__GetItemData_x                                    0x9053B0
#define CListWnd__GetItemHeight_x                                  0x905770
#define CListWnd__GetItemIcon_x                                    0x905540
#define CListWnd__GetItemRect_x                                    0x905FE0
#define CListWnd__GetItemText_x                                    0x9053F0
#define CListWnd__GetSelList_x                                     0x908CE0
#define CListWnd__GetSeparatorRect_x                               0x906420
#define CListWnd__InsertLine_x                                     0x908840
#define CListWnd__RemoveLine_x                                     0x908990
#define CListWnd__SetColors_x                                      0x907BE0
#define CListWnd__SetColumnJustification_x                         0x907910
#define CListWnd__SetColumnWidth_x                                 0x907830
#define CListWnd__SetCurSel_x                                      0x908AA0
#define CListWnd__SetItemColor_x                                   0x909280
#define CListWnd__SetItemData_x                                    0x909240
#define CListWnd__SetItemText_x                                    0x908E50
#define CListWnd__ShiftColumnSeparator_x                           0x9079D0
#define CListWnd__Sort_x                                           0x9076D0
#define CListWnd__ToggleSel_x                                      0x908AD0
#define CListWnd__SetColumnsSizable_x                              0x907A70
#define CListWnd__SetItemWnd_x                                     0x909100
#define CListWnd__GetItemWnd_x                                     0x905590
#define CListWnd__SetItemIcon_x                                    0x908ED0
#define CListWnd__CalculateCustomWindowPositions_x                 0x907F30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76B5F0
#define CMapViewWnd__GetWorldCoordinates_x                         0x769D00
#define CMapViewWnd__HandleLButtonDown_x                           0x766D60

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78E5F0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78EED0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78F410
#define CMerchantWnd__SelectRecoverySlot_x                         0x7923A0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78D130
#define CMerchantWnd__SelectBuySellSlot_x                          0x797F80
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78E200

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8985E0
#define CPacketScrambler__hton_x                                   0x8985D0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9228B0
#define CSidlManager__FindScreenPieceTemplate_x                    0x922CC0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x922AB0
#define CSidlManager__CreateLabel_x                                0x7F0050
#define CSidlManager__CreateXWndFromTemplate_x                     0x925D70
#define CSidlManager__CreateXWndFromTemplate1_x                    0x925F40
#define CSidlManager__CreateXWnd_x                                 0x7EFF80
#define CSidlManager__CreateHotButtonWnd_x                         0x7F0540

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x91F420
#define CSidlScreenWnd__CalculateVSBRange_x                        0x91F310
#define CSidlScreenWnd__ConvertToRes_x                             0x9446C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91EDA0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91EA90
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91EB60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91EC30
#define CSidlScreenWnd__DrawSidlPiece_x                            0x91F8C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x91FD90
#define CSidlScreenWnd__GetSidlPiece_x                             0x91FAB0
#define CSidlScreenWnd__Init1_x                                    0x91E690
#define CSidlScreenWnd__LoadIniInfo_x                              0x91FDE0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x920920
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91DAA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9204A0
#define CSidlScreenWnd__StoreIniVis_x                              0x920800
#define CSidlScreenWnd__WndNotification_x                          0x91F7D0
#define CSidlScreenWnd__GetChildItem_x                             0x91FD10
#define CSidlScreenWnd__HandleLButtonUp_x                          0x90F490
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B73A0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x669BA0
#define CSkillMgr__GetSkillCap_x                                   0x669D80
#define CSkillMgr__GetNameToken_x                                  0x669330
#define CSkillMgr__IsActivatedSkill_x                              0x669470
#define CSkillMgr__IsCombatSkill_x                                 0x6693B0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x92F850
#define CSliderWnd__SetValue_x                                     0x92F6C0
#define CSliderWnd__SetNumTicks_x                                  0x92F720

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F6250

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9365E0
#define CStmlWnd__CalculateHSBRange_x                              0x9376D0
#define CStmlWnd__CalculateVSBRange_x                              0x937640
#define CStmlWnd__CanBreakAtCharacter_x                            0x93BA10
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93C6A0
#define CStmlWnd__ForceParseNow_x                                  0x936B80
#define CStmlWnd__GetNextTagPiece_x                                0x93B970
#define CStmlWnd__GetSTMLText_x                                    0x4F5170
#define CStmlWnd__GetVisibleText_x                                 0x936BA0
#define CStmlWnd__InitializeWindowVariables_x                      0x93C4F0
#define CStmlWnd__MakeStmlColorTag_x                               0x935CC0
#define CStmlWnd__MakeWndNotificationTag_x                         0x935D30
#define CStmlWnd__SetSTMLText_x                                    0x934D70
#define CStmlWnd__StripFirstSTMLLines_x                            0x93D7A0
#define CStmlWnd__UpdateHistoryString_x                            0x93C8B0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x941270
#define CTabWnd__DrawCurrentPage_x                                 0x941890
#define CTabWnd__DrawTab_x                                         0x941660
#define CTabWnd__GetCurrentPage_x                                  0x940AD0
#define CTabWnd__GetPageInnerRect_x                                0x940D10
#define CTabWnd__GetTabInnerRect_x                                 0x940C50
#define CTabWnd__GetTabRect_x                                      0x940B00
#define CTabWnd__InsertPage_x                                      0x940F00
#define CTabWnd__SetPage_x                                         0x940D90
#define CTabWnd__SetPageRect_x                                     0x9411B0
#define CTabWnd__UpdatePage_x                                      0x941520
#define CTabWnd__GetPageFromTabIndex_x                             0x9415A0
#define CTabWnd__GetCurrentTabIndex_x                              0x940AC0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x750870
#define CPageWnd__SetTabText_x                                     0x94DAB0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A67D0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90C2D0
#define CTextureFont__GetTextExtent_x                              0x90C490

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69D8C0
#define CHtmlComponentWnd__ValidateUri_x                           0x72F410
#define CHtmlWnd__SetClientCallbacks_x                             0x60A8B0
#define CHtmlWnd__AddObserver_x                                    0x60A8D0
#define CHtmlWnd__RemoveObserver_x                                 0x60A930
#define Window__getProgress_x                                      0x848AD0
#define Window__getStatus_x                                        0x848AF0
#define Window__getURI_x                                           0x848B00

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94A0D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F9500

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADD50
#define CXStr__CXStr1_x                                            0x9BBBA0
#define CXStr__CXStr3_x                                            0x8E5C60
#define CXStr__dCXStr_x                                            0x473050
#define CXStr__operator_equal_x                                    0x8E5E90
#define CXStr__operator_equal1_x                                   0x8E5ED0
#define CXStr__operator_plus_equal1_x                              0x8E6960
#define CXStr__SetString_x                                         0x8E8850

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92DAE0
#define CXWnd__BringToTop_x                                        0x912C80
#define CXWnd__Center_x                                            0x912800
#define CXWnd__ClrFocus_x                                          0x912630
#define CXWnd__Destroy_x                                           0x9126E0
#define CXWnd__DoAllDrawing_x                                      0x90EC20
#define CXWnd__DrawChildren_x                                      0x90EBF0
#define CXWnd__DrawColoredRect_x                                   0x90F080
#define CXWnd__DrawTooltip_x                                       0x90D730
#define CXWnd__DrawTooltipAtPoint_x                                0x90D7F0
#define CXWnd__GetBorderFrame_x                                    0x90EEE0
#define CXWnd__GetChildWndAt_x                                     0x912D20
#define CXWnd__GetClientClipRect_x                                 0x910F00
#define CXWnd__GetScreenClipRect_x                                 0x910FB0
#define CXWnd__GetScreenRect_x                                     0x911160
#define CXWnd__GetTooltipRect_x                                    0x90F0D0
#define CXWnd__GetWindowTextA_x                                    0x497D90
#define CXWnd__IsActive_x                                          0x915C10
#define CXWnd__IsDescendantOf_x                                    0x911B80
#define CXWnd__IsReallyVisible_x                                   0x911BB0
#define CXWnd__IsType_x                                            0x913380
#define CXWnd__Move_x                                              0x911C20
#define CXWnd__Move1_x                                             0x911CE0
#define CXWnd__ProcessTransition_x                                 0x9127B0
#define CXWnd__Refade_x                                            0x911FB0
#define CXWnd__Resize_x                                            0x912250
#define CXWnd__Right_x                                             0x912A40
#define CXWnd__SetFocus_x                                          0x9125F0
#define CXWnd__SetFont_x                                           0x912660
#define CXWnd__SetKeyTooltip_x                                     0x9131B0
#define CXWnd__SetMouseOver_x                                      0x910050
#define CXWnd__StartFade_x                                         0x911A50
#define CXWnd__GetChildItem_x                                      0x912E90
#define CXWnd__SetParent_x                                         0x911910

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x945750

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x915C50
#define CXWndManager__DrawWindows_x                                0x915C70
#define CXWndManager__GetKeyboardFlags_x                           0x9183F0
#define CXWndManager__HandleKeyboardMsg_x                          0x917FF0
#define CXWndManager__RemoveWnd_x                                  0x918640
#define CXWndManager__RemovePendingDeletionWnd_x                   0x918BA0

// CDBStr
#define CDBStr__GetString_x                                        0x52C920

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8F40
#define EQ_Character__Cur_HP_x                                     0x4CF290
#define EQ_Character__Cur_Mana_x                                   0x4D6A40
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BBE50
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF970
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFAC0
#define EQ_Character__GetHPRegen_x                                 0x4DC9C0
#define EQ_Character__GetEnduranceRegen_x                          0x4DCFD0
#define EQ_Character__GetManaRegen_x                               0x4DD410
#define EQ_Character__Max_Endurance_x                              0x6307D0
#define EQ_Character__Max_HP_x                                     0x4CF0C0
#define EQ_Character__Max_Mana_x                                   0x6305D0
#define EQ_Character__doCombatAbility_x                            0x632C90
#define EQ_Character__UseSkill_x                                   0x4DF220
#define EQ_Character__GetConLevel_x                                0x6299B0
#define EQ_Character__IsExpansionFlag_x                            0x58FDA0
#define EQ_Character__TotalEffect_x                                0x4C24C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BCA40
#define EQ_Character__SpellDuration_x                              0x4BC570
#define EQ_Character__GetAdjustedSkill_x                           0x4D2070
#define EQ_Character__GetBaseSkill_x                               0x4D3010
#define EQ_Character__CanUseItem_x                                 0x4D6D50

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B7470

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x646C90

//PcClient
#define PcClient__PcClient_x                                       0x6270E0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6BC0
#define CCharacterListWnd__EnterWorld_x                            0x4B6600
#define CCharacterListWnd__Quit_x                                  0x4B6310
#define CCharacterListWnd__UpdateList_x                            0x4B6790

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60BAC0
#define EQ_Item__CreateItemTagString_x                             0x891EC0
#define EQ_Item__IsStackable_x                                     0x896950
#define EQ_Item__GetImageNum_x                                     0x893930
#define EQ_Item__CreateItemClient_x                                0x60AC90
#define EQ_Item__GetItemValue_x                                    0x894BD0
#define EQ_Item__ValueSellMerchant_x                               0x898180
#define EQ_Item__IsKeyRingItem_x                                   0x8962B0
#define EQ_Item__CanGoInBag_x                                      0x60BBE0
#define EQ_Item__IsEmpty_x                                         0x895DB0
#define EQ_Item__GetMaxItemCount_x                                 0x894F90
#define EQ_Item__GetHeldItem_x                                     0x893800
#define EQ_Item__GetAugmentFitBySlot_x                             0x891810

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54AE10
#define EQ_LoadingS__Array_x                                       0xBEC138

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x631130
#define EQ_PC__GetAlternateAbilityId_x                             0x8A1220
#define EQ_PC__GetCombatAbility_x                                  0x8A1890
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A1900
#define EQ_PC__GetItemRecastTimer_x                                0x633210
#define EQ_PC__HasLoreItem_x                                       0x62A120
#define EQ_PC__AlertInventoryChanged_x                             0x6292E0
#define EQ_PC__GetPcZoneClient_x                                   0x655520
#define EQ_PC__RemoveMyAffect_x                                    0x636440
#define EQ_PC__GetKeyRingItems_x                                   0x8A21A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A1F20
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A2490

// EQItemList 
#define EQItemList__EQItemList_x                                   0x596220
#define EQItemList__add_object_x                                   0x5C1FC0
#define EQItemList__add_item_x                                     0x596830
#define EQItemList__delete_item_x                                  0x596880
#define EQItemList__FreeItemList_x                                 0x596780

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x529EE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x648510
#define EQPlayer__dEQPlayer_x                                      0x63BAB0
#define EQPlayer__DoAttack_x                                       0x6501D0
#define EQPlayer__EQPlayer_x                                       0x63C160
#define EQPlayer__SetNameSpriteState_x                             0x640400
#define EQPlayer__SetNameSpriteTint_x                              0x6412D0
#define PlayerBase__HasProperty_j_x                                0x978270
#define EQPlayer__IsTargetable_x                                   0x978710
#define EQPlayer__CanSee_x                                         0x978570
#define EQPlayer__CanSee1_x                                        0x978640
#define PlayerBase__GetVisibilityLineSegment_x                     0x978330

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x652FB0
#define PlayerZoneClient__GetLevel_x                               0x655560
#define PlayerZoneClient__IsValidTeleport_x                        0x5C3110
#define PlayerZoneClient__LegalPlayerRace_x                        0x544240

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64B320
#define EQPlayerManager__GetSpawnByName_x                          0x64B340
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64B3D0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60F370
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60F3B0
#define KeypressHandler__ClearCommandStateArray_x                  0x6107A0
#define KeypressHandler__HandleKeyDown_x                           0x6107C0
#define KeypressHandler__HandleKeyUp_x                             0x610860
#define KeypressHandler__SaveKeymapping_x                          0x610C40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x767480
#define MapViewMap__SaveEx_x                                       0x76A820
#define MapViewMap__SetZoom_x                                      0x76EEF0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B52B0

// StringTable 
#define StringTable__getString_x                                   0x8B0300

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6360B0
#define PcZoneClient__RemovePetEffect_x                            0x6366E0
#define PcZoneClient__HasAlternateAbility_x                        0x630410
#define PcZoneClient__GetCurrentMod_x                              0x4E2310
#define PcZoneClient__GetModCap_x                                  0x4E2210
#define PcZoneClient__CanEquipItem_x                               0x630AC0
#define PcZoneClient__GetItemByID_x                                0x633690
#define PcZoneClient__GetItemByItemClass_x                         0x6337E0
#define PcZoneClient__RemoveBuffEffect_x                           0x636700
#define PcZoneClient__BandolierSwap_x                              0x6316F0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6331B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C7DC0

//IconCache
#define IconCache__GetIcon_x                                       0x707D30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6FF7F0
#define CContainerMgr__CloseContainer_x                            0x6FFAC0
#define CContainerMgr__OpenExperimentContainer_x                   0x700540

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C26C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x603CE0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75D7E0
#define CLootWnd__RequestLootSlot_x                                0x75CB80

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x563520
#define EQ_Spell__SpellAffects_x                                   0x563990
#define EQ_Spell__SpellAffectBase_x                                0x563750
#define EQ_Spell__IsStackable_x                                    0x4C6D00
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6B80
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3F00
#define EQ_Spell__IsSPAStacking_x                                  0x5647C0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x563CE0
#define EQ_Spell__IsNoRemove_x                                     0x4C6CE0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5647D0
#define __IsResEffectSpell_x                                       0x4C6030

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA7D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8BFA40

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x808050
#define CTargetWnd__WndNotification_x                              0x8078E0
#define CTargetWnd__RefreshTargetBuffs_x                           0x807BB0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x806A30

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80C720

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x527930
#define CTaskManager__HandleMessage_x                              0x5260A0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55EAB0
#define EqSoundManager__PlayScriptMp3_x                            0x55EC10
#define EqSoundManager__SoundAssistPlay_x                          0x66DC00
#define EqSoundManager__WaveInstancePlay_x                         0x66D170

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51B990

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x931230

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x552BA0
#define CAltAbilityData__GetMercMaxRank_x                          0x552B40
#define CAltAbilityData__GetMaxRank_x                              0x547F20

//CTargetRing
#define CTargetRing__Cast_x                                        0x601DD0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6B60
#define CharacterBase__CreateItemGlobalIndex_x                     0x501E50
#define CharacterBase__CreateItemIndex_x                           0x609EC0
#define CharacterBase__GetItemPossession_x                         0x4EDD00
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C8080
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8C80E0
#define CharacterBase__GetEffectId_x                               0x4C6B10

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E76F0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E7F10

//messages
#define msg_spell_worn_off_x                                       0x587F60
#define msg_new_text_x                                             0x57CD00
#define __msgTokenTextParam_x                                      0x58A480
#define msgTokenText_x                                             0x58A6D0

//SpellManager
#define SpellManager__vftable_x                                    0xAB3A38
#define SpellManager__SpellManager_x                               0x670F20
#define Spellmanager__LoadTextSpells_x                             0x6717F0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6710F0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97C1E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x502540
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58E2B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6228F0
#define ItemGlobalIndex__IsValidIndex_x                            0x5025A0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C0380
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C0600

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7561D0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x703F10
#define CCursorAttachment__AttachToCursor1_x                       0x703F50
#define CCursorAttachment__Deactivate_x                            0x704F20

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x926D80
#define CSidlManagerBase__CreatePageWnd_x                          0x926590
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9226D0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x922660

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x943BA0
#define CEQSuiteTextureLoader__GetTexture_x                        0x943860

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FF420
#define CFindItemWnd__WndNotification_x                            0x4FFF00
#define CFindItemWnd__Update_x                                     0x500A40
#define CFindItemWnd__PickupSelectedItem_x                         0x4FEC80

//IString
#define IString__Append_x                                          0x4EF360

//Camera
#define CDisplay__cameraType_x                                     0xDC5524
#define EverQuest__Cameras_x                                       0xE88868

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x507C60
#define LootFiltersManager__GetItemFilterData_x                    0x507550
#define LootFiltersManager__RemoveItemLootFilter_x                 0x507580
#define LootFiltersManager__SetItemLootFilter_x                    0x5077A0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B0630

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x981F50
#define CResolutionHandler__GetWindowedStyle_x                     0x668650

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FC560

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D2B70

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71C7C0
#define CGroupWnd__UpdateDisplay_x                                 0x71BB20

//ItemBase
#define ItemBase__IsLore_x                                         0x896310
#define ItemBase__IsLoreEquipped_x                                 0x896380

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C1EB0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C2060
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C20C0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65E0A0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x661D50

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F57B0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E4DD0
#define FactionManagerClient__HandleFactionMessage_x               0x4E5440
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E5A20
#define FactionManagerClient__GetMaxFaction_x                      0x4E5A70
#define FactionManagerClient__GetMinFaction_x                      0x4E59F0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4EDCD0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x90B330

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
