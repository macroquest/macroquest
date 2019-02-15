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
#define __ExpectedVersionDate                                     "Feb 14 2019"
#define __ExpectedVersionTime                                     "14:18:21"
#define __ActualVersionDate_x                                      0xAD015C
#define __ActualVersionTime_x                                      0xAD0150

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x615FC0
#define __MemChecker1_x                                            0x8EA9B0
#define __MemChecker2_x                                            0x6A5440
#define __MemChecker3_x                                            0x6A5390
#define __MemChecker4_x                                            0x841C50
#define __EncryptPad0_x                                            0xC04348
#define __EncryptPad1_x                                            0xC625D8
#define __EncryptPad2_x                                            0xC14ED0
#define __EncryptPad3_x                                            0xC14AD0
#define __EncryptPad4_x                                            0xC52E48
#define __EncryptPad5_x                                            0x1034508
#define __AC1_x                                                    0x7FEAD6
#define __AC2_x                                                    0x5D091F
#define __AC3_x                                                    0x5D77AF
#define __AC4_x                                                    0x5DB5E0
#define __AC5_x                                                    0x5E1850
#define __AC6_x                                                    0x5E5E16
#define __AC7_x                                                    0x5D0390
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
#define __do_loot_x                                                0x59DCD0
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
#define __CastRay_x                                                0x5991F0
#define __CastRay2_x                                               0x599240
#define __ConvertItemTags_x                                        0x5B3ED0
#define __CrashHandler_x                                           0x84B610
#define __EQGetTime_x                                              0x8EA4A0
#define __ExecuteCmd_x                                             0x591B30
#define __FixHeading_x                                             0x97A1D0
#define __GameLoop_x                                               0x6A4840
#define __get_bearing_x                                            0x598D40
#define __get_melee_range_x                                        0x599430
#define __GetAnimationCache_x                                      0x708ED0
#define __GetGaugeValueFromEQ_x                                    0x7FD2E0
#define __GetLabelFromEQ_x                                         0x7FEA60
#define __GetXTargetType_x                                         0x97BCA0
#define __HandleMouseWheel_x                                       0x6A54F0
#define __HeadingDiff_x                                            0x97A240
#define __HelpPath_x                                               0xF265BC
#define __LoadFrontEnd_x                                           0x6A1320
#define __NewUIINI_x                                               0x7FCFB0
#define __pCrashHandler_x                                          0x105C430
#define __ProcessGameEvents_x                                      0x5F7220
#define __ProcessMouseEvent_x                                      0x5F69E0
#define __SaveColors_x                                             0x542B10
#define __STMLToText_x                                             0x91DA90
#define __ToggleKeyRingItem_x                                      0x505F70
#define CrashDetected_x                                            0x6A2D90
#define DrawNetStatus_x                                            0x6235B0
#define Expansion_HoT_x                                            0xE88524
#define Teleport_Table_Size_x                                      0xE79904
#define Teleport_Table_x                                           0xE776D8
#define Util__FastTime_x                                           0x8EA060
#define wwsCrashReportCheckForUploader_x                           0x84C4B0
#define wwsCrashReportPlatformLaunchUploader_x                     0x84EB70

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B570
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494410
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4941D0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54A740
#define AltAdvManager__IsAbilityReady_x                            0x549690
#define AltAdvManager__GetAAById_x                                 0x549890
#define AltAdvManager__CanTrainAbility_x                           0x549900
#define AltAdvManager__CanSeeAbility_x                             0x549C60

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7450
#define CharacterZoneClient__HasSkill_x                            0x4D2320
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3A40
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB810
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7F90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6400
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D64E0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D65C0
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
#define CharacterZoneClient__FindItemByGuid_x                      0x4D49B0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4420

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CB1D0
#define CBankWnd__WndNotification_x                                0x6CAFB0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D8C50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x605C30
#define CButtonWnd__CButtonWnd_x                                   0x919E80

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F7820
#define CChatManager__InitContextMenu_x                            0x6F1870
#define CChatManager__FreeChatWindow_x                             0x6F6730
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FB190
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F75C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92E720
#define CContextMenu__dCContextMenu_x                              0x92E950
#define CContextMenu__AddMenuItem_x                                0x92E960
#define CContextMenu__RemoveMenuItem_x                             0x92EC70
#define CContextMenu__RemoveAllMenuItems_x                         0x92EC90
#define CContextMenu__CheckMenuItem_x                              0x92ED10
#define CContextMenu__SetMenuItem_x                                0x92EB90
#define CContextMenu__AddSeparator_x                               0x92EAF0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92F2B0
#define CContextMenuManager__RemoveMenu_x                          0x92F320
#define CContextMenuManager__PopupMenu_x                           0x92F3E0
#define CContextMenuManager__Flush_x                               0x92F250
#define CContextMenuManager__GetMenu_x                             0x496690
#define CContextMenuManager__CreateDefaultMenu_x                   0x7036D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CAF90
#define CChatService__GetFriendName_x                              0x8CAFA0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F7D90
#define CChatWindow__Clear_x                                       0x6F8DF0
#define CChatWindow__WndNotification_x                             0x6F9360

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92BBB0
#define CComboWnd__Draw_x                                          0x92B090
#define CComboWnd__GetCurChoice_x                                  0x92B9F0
#define CComboWnd__GetListRect_x                                   0x92B550
#define CComboWnd__GetTextRect_x                                   0x92BC20
#define CComboWnd__InsertChoice_x                                  0x92B6E0
#define CComboWnd__SetColors_x                                     0x92B6B0
#define CComboWnd__SetChoice_x                                     0x92B9C0
#define CComboWnd__GetItemCount_x                                  0x92BA00
#define CComboWnd__GetCurChoiceText_x                              0x92BA40

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7010B0
#define CContainerWnd__vftable_x                                   0xAD9340
#define CContainerWnd__SetContainer_x                              0x702620

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5428D0
#define CDisplay__GetClickedActor_x                                0x535880
#define CDisplay__GetUserDefinedColor_x                            0x52DF60
#define CDisplay__GetWorldFilePath_x                               0x5372D0
#define CDisplay__is3dON_x                                         0x532550
#define CDisplay__ReloadUI_x                                       0x53C9F0
#define CDisplay__WriteTextHD2_x                                   0x532330
#define CDisplay__TrueDistance_x                                   0x538F30
#define CDisplay__SetViewActor_x                                   0x5351D0
#define CDisplay__GetFloorHeight_x                                 0x532610
#define CDisplay__SetRenderWindow_x                                0x530F40
#define CDisplay__ToggleScreenshotMode_x                           0x534CA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94DB10

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x932E20
#define CEditWnd__GetCharIndexPt_x                                 0x933D20
#define CEditWnd__GetDisplayString_x                               0x933BC0
#define CEditWnd__GetHorzOffset_x                                  0x932450
#define CEditWnd__GetLineForPrintableChar_x                        0x934F20
#define CEditWnd__GetSelStartPt_x                                  0x933FD0
#define CEditWnd__GetSTMLSafeText_x                                0x9339E0
#define CEditWnd__PointFromPrintableChar_x                         0x934B50
#define CEditWnd__SelectableCharFromPoint_x                        0x934CC0
#define CEditWnd__SetEditable_x                                    0x9340A0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E5340
#define CEverQuest__ClickedPlayer_x                                0x5D7590
#define CEverQuest__CreateTargetIndicator_x                        0x5F44D0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F4560
#define CEverQuest__DoTellWindow_x                                 0x4E34B0
#define CEverQuest__OutputTextToLog_x                              0x4E36E0
#define CEverQuest__DropHeldItemOnGround_x                         0x5CCE50
#define CEverQuest__dsp_chat_x                                     0x4E3A70
#define CEverQuest__trimName_x                                     0x5F07C0
#define CEverQuest__Emote_x                                        0x5E5B50
#define CEverQuest__EnterZone_x                                    0x5DFC00
#define CEverQuest__GetBodyTypeDesc_x                              0x5EA060
#define CEverQuest__GetClassDesc_x                                 0x5EA6A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EACA0
#define CEverQuest__GetDeityDesc_x                                 0x5F2E20
#define CEverQuest__GetLangDesc_x                                  0x5EAE60
#define CEverQuest__GetRaceDesc_x                                  0x5EA680
#define CEverQuest__InterpretCmd_x                                 0x5F33F0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D1040
#define CEverQuest__LMouseUp_x                                     0x5CF3C0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D1920
#define CEverQuest__RMouseUp_x                                     0x5D0350
#define CEverQuest__SetGameState_x                                 0x5CCBE0
#define CEverQuest__UPCNotificationFlush_x                         0x5F06C0
#define CEverQuest__IssuePetCommand_x                              0x5EC260
#define CEverQuest__ReportSuccessfulHit_x                          0x5E6F50

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x712F30
#define CGaugeWnd__CalcLinesFillRect_x                             0x712F90
#define CGaugeWnd__Draw_x                                          0x712620

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACAA0
#define CGuild__GetGuildName_x                                     0x4ABB80
#define CGuild__GetGuildIndex_x                                    0x4ABF10

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72E2F0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x605FF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73B1C0
#define CInvSlotMgr__MoveItem_x                                    0x739EE0
#define CInvSlotMgr__SelectSlot_x                                  0x73B290

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x738790
#define CInvSlot__SliderComplete_x                                 0x7364F0
#define CInvSlot__GetItemBase_x                                    0x735E60
#define CInvSlot__UpdateItem_x                                     0x735FD0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73CCF0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73BEA0
#define CInvSlotWnd__HandleLButtonUp_x                             0x73C870

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F9510
#define CItemDisplayWnd__UpdateStrings_x                           0x74B160
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x744F60
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x745470
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74B780
#define CItemDisplayWnd__AboutToShow_x                             0x74ADC0
#define CItemDisplayWnd__WndNotification_x                         0x74CCB0
#define CItemDisplayWnd__RequestConvertItem_x                      0x74C800
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x749E20
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x74ABE0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x830CE0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x750DA0

// CLabel 
#define CLabel__Draw_x                                             0x7567E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x904290
#define CListWnd__dCListWnd_x                                      0x9045B0
#define CListWnd__AddColumn_x                                      0x9088C0
#define CListWnd__AddColumn1_x                                     0x908910
#define CListWnd__AddLine_x                                        0x908CA0
#define CListWnd__AddString_x                                      0x908AA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x908690
#define CListWnd__CalculateVSBRange_x                              0x908470
#define CListWnd__ClearSel_x                                       0x909480
#define CListWnd__ClearAllSel_x                                    0x9094E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x909EE0
#define CListWnd__Compare_x                                        0x907DB0
#define CListWnd__Draw_x                                           0x9046B0
#define CListWnd__DrawColumnSeparators_x                           0x906E80
#define CListWnd__DrawHeader_x                                     0x9072F0
#define CListWnd__DrawItem_x                                       0x9076F0
#define CListWnd__DrawLine_x                                       0x906FF0
#define CListWnd__DrawSeparator_x                                  0x906F20
#define CListWnd__EnableLine_x                                     0x906770
#define CListWnd__EnsureVisible_x                                  0x909E10
#define CListWnd__ExtendSel_x                                      0x9093B0
#define CListWnd__GetColumnTooltip_x                               0x9062B0
#define CListWnd__GetColumnMinWidth_x                              0x906320
#define CListWnd__GetColumnWidth_x                                 0x906220
#define CListWnd__GetCurSel_x                                      0x905BB0
#define CListWnd__GetItemAtPoint_x                                 0x9069E0
#define CListWnd__GetItemAtPoint1_x                                0x906A50
#define CListWnd__GetItemData_x                                    0x905C30
#define CListWnd__GetItemHeight_x                                  0x905FF0
#define CListWnd__GetItemIcon_x                                    0x905DC0
#define CListWnd__GetItemRect_x                                    0x906860
#define CListWnd__GetItemText_x                                    0x905C70
#define CListWnd__GetSelList_x                                     0x909530
#define CListWnd__GetSeparatorRect_x                               0x906C90
#define CListWnd__InsertLine_x                                     0x909090
#define CListWnd__RemoveLine_x                                     0x9091E0
#define CListWnd__SetColors_x                                      0x908440
#define CListWnd__SetColumnJustification_x                         0x908170
#define CListWnd__SetColumnWidth_x                                 0x908090
#define CListWnd__SetCurSel_x                                      0x9092F0
#define CListWnd__SetItemColor_x                                   0x909AD0
#define CListWnd__SetItemData_x                                    0x909A90
#define CListWnd__SetItemText_x                                    0x9096A0
#define CListWnd__ShiftColumnSeparator_x                           0x908230
#define CListWnd__Sort_x                                           0x907F30
#define CListWnd__ToggleSel_x                                      0x909320
#define CListWnd__SetColumnsSizable_x                              0x9082D0
#define CListWnd__SetItemWnd_x                                     0x909950
#define CListWnd__GetItemWnd_x                                     0x905E10
#define CListWnd__SetItemIcon_x                                    0x909720
#define CListWnd__CalculateCustomWindowPositions_x                 0x908780

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76BD80
#define CMapViewWnd__GetWorldCoordinates_x                         0x76A490
#define CMapViewWnd__HandleLButtonDown_x                           0x7674F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78EF00
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78F7E0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78FD10
#define CMerchantWnd__SelectRecoverySlot_x                         0x792C90
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78DA50
#define CMerchantWnd__SelectBuySellSlot_x                          0x798860
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78EB20

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x898D30
#define CPacketScrambler__hton_x                                   0x898D20

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x923070
#define CSidlManager__FindScreenPieceTemplate_x                    0x923480
#define CSidlManager__FindScreenPieceTemplate1_x                   0x923270
#define CSidlManager__CreateLabel_x                                0x7F09C0
#define CSidlManager__CreateXWndFromTemplate_x                     0x926530
#define CSidlManager__CreateXWndFromTemplate1_x                    0x926710
#define CSidlManager__CreateXWnd_x                                 0x7F08F0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F0EB0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x91FBE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x91FAE0
#define CSidlScreenWnd__ConvertToRes_x                             0x944AD0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91F570
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91F260
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91F330
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91F400
#define CSidlScreenWnd__DrawSidlPiece_x                            0x920070
#define CSidlScreenWnd__EnableIniStorage_x                         0x920540
#define CSidlScreenWnd__GetSidlPiece_x                             0x920260
#define CSidlScreenWnd__Init1_x                                    0x91EE60
#define CSidlScreenWnd__LoadIniInfo_x                              0x920590
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9210D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91E270
#define CSidlScreenWnd__StoreIniInfo_x                             0x920C50
#define CSidlScreenWnd__StoreIniVis_x                              0x920FB0
#define CSidlScreenWnd__WndNotification_x                          0x91FF80
#define CSidlScreenWnd__GetChildItem_x                             0x9204C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x90FD20
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B73A0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66A720
#define CSkillMgr__GetSkillCap_x                                   0x66A900
#define CSkillMgr__GetNameToken_x                                  0x669EB0
#define CSkillMgr__IsActivatedSkill_x                              0x669FF0
#define CSkillMgr__IsCombatSkill_x                                 0x669F30

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9300A0
#define CSliderWnd__SetValue_x                                     0x92FF10
#define CSliderWnd__SetNumTicks_x                                  0x92FF70

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F6A60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x936E80
#define CStmlWnd__CalculateHSBRange_x                              0x937F50
#define CStmlWnd__CalculateVSBRange_x                              0x937EC0
#define CStmlWnd__CanBreakAtCharacter_x                            0x93C290
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93CF20
#define CStmlWnd__ForceParseNow_x                                  0x937420
#define CStmlWnd__GetNextTagPiece_x                                0x93C1F0
#define CStmlWnd__GetSTMLText_x                                    0x4F5650
#define CStmlWnd__GetVisibleText_x                                 0x937440
#define CStmlWnd__InitializeWindowVariables_x                      0x93CD70
#define CStmlWnd__MakeStmlColorTag_x                               0x936560
#define CStmlWnd__MakeWndNotificationTag_x                         0x9365D0
#define CStmlWnd__SetSTMLText_x                                    0x935610
#define CStmlWnd__StripFirstSTMLLines_x                            0x93E010
#define CStmlWnd__UpdateHistoryString_x                            0x93D130

// CTabWnd 
#define CTabWnd__Draw_x                                            0x941A50
#define CTabWnd__DrawCurrentPage_x                                 0x942070
#define CTabWnd__DrawTab_x                                         0x941E40
#define CTabWnd__GetCurrentPage_x                                  0x9412B0
#define CTabWnd__GetPageInnerRect_x                                0x9414F0
#define CTabWnd__GetTabInnerRect_x                                 0x941430
#define CTabWnd__GetTabRect_x                                      0x9412E0
#define CTabWnd__InsertPage_x                                      0x9416E0
#define CTabWnd__SetPage_x                                         0x941570
#define CTabWnd__SetPageRect_x                                     0x941990
#define CTabWnd__UpdatePage_x                                      0x941D00
#define CTabWnd__GetPageFromTabIndex_x                             0x941D80
#define CTabWnd__GetCurrentTabIndex_x                              0x9412A0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x751170
#define CPageWnd__SetTabText_x                                     0x94DF20

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6740

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90CB90
#define CTextureFont__GetTextExtent_x                              0x90CD50

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69E290
#define CHtmlComponentWnd__ValidateUri_x                           0x72FCE0
#define CHtmlWnd__SetClientCallbacks_x                             0x60AFB0
#define CHtmlWnd__AddObserver_x                                    0x60AFD0
#define CHtmlWnd__RemoveObserver_x                                 0x60B030
#define Window__getProgress_x                                      0x849280
#define Window__getStatus_x                                        0x8492A0
#define Window__getURI_x                                           0x8492B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94A540

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F9E50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADD40
#define CXStr__CXStr1_x                                            0x4B3870
#define CXStr__CXStr3_x                                            0x8E65D0
#define CXStr__dCXStr_x                                            0x473030
#define CXStr__operator_equal_x                                    0x8E6800
#define CXStr__operator_equal1_x                                   0x8E6840
#define CXStr__operator_plus_equal1_x                              0x8E72D0
#define CXStr__SetString_x                                         0x8E91C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92E340
#define CXWnd__BringToTop_x                                        0x913450
#define CXWnd__Center_x                                            0x912FD0
#define CXWnd__ClrFocus_x                                          0x912E00
#define CXWnd__Destroy_x                                           0x912EB0
#define CXWnd__DoAllDrawing_x                                      0x90F4B0
#define CXWnd__DrawChildren_x                                      0x90F480
#define CXWnd__DrawColoredRect_x                                   0x90F910
#define CXWnd__DrawTooltip_x                                       0x90DFD0
#define CXWnd__DrawTooltipAtPoint_x                                0x90E090
#define CXWnd__GetBorderFrame_x                                    0x90F770
#define CXWnd__GetChildWndAt_x                                     0x9134F0
#define CXWnd__GetClientClipRect_x                                 0x911700
#define CXWnd__GetScreenClipRect_x                                 0x9117D0
#define CXWnd__GetScreenRect_x                                     0x911990
#define CXWnd__GetTooltipRect_x                                    0x90F960
#define CXWnd__GetWindowTextA_x                                    0x497E30
#define CXWnd__IsActive_x                                          0x916390
#define CXWnd__IsDescendantOf_x                                    0x912380
#define CXWnd__IsReallyVisible_x                                   0x9123B0
#define CXWnd__IsType_x                                            0x913B40
#define CXWnd__Move_x                                              0x912410
#define CXWnd__Move1_x                                             0x9124C0
#define CXWnd__ProcessTransition_x                                 0x912F80
#define CXWnd__Refade_x                                            0x912790
#define CXWnd__Resize_x                                            0x912A30
#define CXWnd__Right_x                                             0x913210
#define CXWnd__SetFocus_x                                          0x912DC0
#define CXWnd__SetFont_x                                           0x912E30
#define CXWnd__SetKeyTooltip_x                                     0x913970
#define CXWnd__SetMouseOver_x                                      0x9108A0
#define CXWnd__StartFade_x                                         0x912250
#define CXWnd__GetChildItem_x                                      0x913660
#define CXWnd__SetParent_x                                         0x912130

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x945B60

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9163D0
#define CXWndManager__DrawWindows_x                                0x9163F0
#define CXWndManager__GetKeyboardFlags_x                           0x918B70
#define CXWndManager__HandleKeyboardMsg_x                          0x918770
#define CXWndManager__RemoveWnd_x                                  0x918DB0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x919300

// CDBStr
#define CDBStr__GetString_x                                        0x52CF30

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8F40
#define EQ_Character__Cur_HP_x                                     0x4CF300
#define EQ_Character__Cur_Mana_x                                   0x4D6AC0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BBE50
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF970
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFAC0
#define EQ_Character__GetHPRegen_x                                 0x4DCA20
#define EQ_Character__GetEnduranceRegen_x                          0x4DD030
#define EQ_Character__GetManaRegen_x                               0x4DD470
#define EQ_Character__Max_Endurance_x                              0x630F20
#define EQ_Character__Max_HP_x                                     0x4CF130
#define EQ_Character__Max_Mana_x                                   0x630D20
#define EQ_Character__doCombatAbility_x                            0x6333E0
#define EQ_Character__UseSkill_x                                   0x4DF280
#define EQ_Character__GetConLevel_x                                0x62A470
#define EQ_Character__IsExpansionFlag_x                            0x5902B0
#define EQ_Character__TotalEffect_x                                0x4C24C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BCA40
#define EQ_Character__SpellDuration_x                              0x4BC570
#define EQ_Character__GetAdjustedSkill_x                           0x4D20E0
#define EQ_Character__GetBaseSkill_x                               0x4D3080
#define EQ_Character__CanUseItem_x                                 0x4D6DD0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B7F30

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x647440

//PcClient
#define PcClient__PcClient_x                                       0x627BB0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6BB0
#define CCharacterListWnd__EnterWorld_x                            0x4B65F0
#define CCharacterListWnd__Quit_x                                  0x4B6300
#define CCharacterListWnd__UpdateList_x                            0x4B6780

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60C1F0
#define EQ_Item__CreateItemTagString_x                             0x892670
#define EQ_Item__IsStackable_x                                     0x897070
#define EQ_Item__GetImageNum_x                                     0x8940A0
#define EQ_Item__CreateItemClient_x                                0x60B3B0
#define EQ_Item__GetItemValue_x                                    0x8952E0
#define EQ_Item__ValueSellMerchant_x                               0x8988D0
#define EQ_Item__IsKeyRingItem_x                                   0x8969C0
#define EQ_Item__CanGoInBag_x                                      0x60C310
#define EQ_Item__IsEmpty_x                                         0x896500
#define EQ_Item__GetMaxItemCount_x                                 0x8956B0
#define EQ_Item__GetHeldItem_x                                     0x893F70
#define EQ_Item__GetAugmentFitBySlot_x                             0x891FB0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54B430
#define EQ_LoadingS__Array_x                                       0xBEC138

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x631880
#define EQ_PC__GetAlternateAbilityId_x                             0x8A1980
#define EQ_PC__GetCombatAbility_x                                  0x8A1FF0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A2060
#define EQ_PC__GetItemRecastTimer_x                                0x633960
#define EQ_PC__HasLoreItem_x                                       0x62ABE0
#define EQ_PC__AlertInventoryChanged_x                             0x629DB0
#define EQ_PC__GetPcZoneClient_x                                   0x655B40
#define EQ_PC__RemoveMyAffect_x                                    0x636B90
#define EQ_PC__GetKeyRingItems_x                                   0x8A2900
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A2680
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A2BF0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x596770
#define EQItemList__add_object_x                                   0x5C2590
#define EQItemList__add_item_x                                     0x596D80
#define EQItemList__delete_item_x                                  0x596DD0
#define EQItemList__FreeItemList_x                                 0x596CD0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52A560

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x648CC0
#define EQPlayer__dEQPlayer_x                                      0x63C240
#define EQPlayer__DoAttack_x                                       0x6507F0
#define EQPlayer__EQPlayer_x                                       0x63C8F0
#define EQPlayer__SetNameSpriteState_x                             0x640BB0
#define EQPlayer__SetNameSpriteTint_x                              0x641A80
#define PlayerBase__HasProperty_j_x                                0x9785B0
#define EQPlayer__IsTargetable_x                                   0x978A50
#define EQPlayer__CanSee_x                                         0x9788B0
#define EQPlayer__CanSee1_x                                        0x978980
#define PlayerBase__GetVisibilityLineSegment_x                     0x978670

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6535D0
#define PlayerZoneClient__GetLevel_x                               0x655B80
#define PlayerZoneClient__IsValidTeleport_x                        0x5C36E0
#define PlayerZoneClient__LegalPlayerRace_x                        0x544740

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64B9A0
#define EQPlayerManager__GetSpawnByName_x                          0x64B9C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64BA50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60FBC0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60FC00
#define KeypressHandler__ClearCommandStateArray_x                  0x610FF0
#define KeypressHandler__HandleKeyDown_x                           0x611010
#define KeypressHandler__HandleKeyUp_x                             0x6110B0
#define KeypressHandler__SaveKeymapping_x                          0x611490

// MapViewMap 
#define MapViewMap__Clear_x                                        0x767C10
#define MapViewMap__SaveEx_x                                       0x76AFB0
#define MapViewMap__SetZoom_x                                      0x76F680

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B5E20

// StringTable 
#define StringTable__getString_x                                   0x8B0CE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x636800
#define PcZoneClient__RemovePetEffect_x                            0x636E30
#define PcZoneClient__HasAlternateAbility_x                        0x630B60
#define PcZoneClient__GetCurrentMod_x                              0x4E2370
#define PcZoneClient__GetModCap_x                                  0x4E2270
#define PcZoneClient__CanEquipItem_x                               0x631210
#define PcZoneClient__GetItemByID_x                                0x633DE0
#define PcZoneClient__GetItemByItemClass_x                         0x633F30
#define PcZoneClient__RemoveBuffEffect_x                           0x636E50
#define PcZoneClient__BandolierSwap_x                              0x631E40
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x633900

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C82B0

//IconCache
#define IconCache__GetIcon_x                                       0x708760

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x700250
#define CContainerMgr__CloseContainer_x                            0x700520
#define CContainerMgr__OpenExperimentContainer_x                   0x700FA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C2F30

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x604400

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75E070
#define CLootWnd__RequestLootSlot_x                                0x75D410

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x563820
#define EQ_Spell__SpellAffects_x                                   0x563C90
#define EQ_Spell__SpellAffectBase_x                                0x563A50
#define EQ_Spell__IsStackable_x                                    0x4C6D80
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6C30
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3EF0
#define EQ_Spell__IsSPAStacking_x                                  0x564AC0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x563FE0
#define EQ_Spell__IsNoRemove_x                                     0x4C6D60
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x564AD0
#define __IsResEffectSpell_x                                       0x4C6030

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA790

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C03E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x808890
#define CTargetWnd__WndNotification_x                              0x808120
#define CTargetWnd__RefreshTargetBuffs_x                           0x8083F0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x807270

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80CF70

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x527EE0
#define CTaskManager__HandleMessage_x                              0x526630

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55EDB0
#define EqSoundManager__PlayScriptMp3_x                            0x55EF10
#define EqSoundManager__SoundAssistPlay_x                          0x66E700
#define EqSoundManager__WaveInstancePlay_x                         0x66DC70

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51BEE0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x931A90

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x553100
#define CAltAbilityData__GetMercMaxRank_x                          0x5530A0
#define CAltAbilityData__GetMaxRank_x                              0x548540

//CTargetRing
#define CTargetRing__Cast_x                                        0x602500

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6C10
#define CharacterBase__CreateItemGlobalIndex_x                     0x502430
#define CharacterBase__CreateItemIndex_x                           0x60A5F0
#define CharacterBase__GetItemPossession_x                         0x4EE1A0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C8A10
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8C8A70
#define CharacterBase__GetEffectId_x                               0x4C6BC0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E8150
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E8970

//messages
#define msg_spell_worn_off_x                                       0x5884F0
#define msg_new_text_x                                             0x57D2B0
#define __msgTokenTextParam_x                                      0x58AA00
#define msgTokenText_x                                             0x58AC50

//SpellManager
#define SpellManager__vftable_x                                    0xAB3A38
#define SpellManager__SpellManager_x                               0x671A20
#define Spellmanager__LoadTextSpells_x                             0x6722F0
#define SpellManager__GetSpellByGroupAndRank_x                     0x671BF0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97C590

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x502AE0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58E820
#define ItemGlobalIndex__IsEquippedLocation_x                      0x623410
#define ItemGlobalIndex__IsValidIndex_x                            0x502B40

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C0D20
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C0FA0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x756B30

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x704970
#define CCursorAttachment__AttachToCursor1_x                       0x7049B0
#define CCursorAttachment__Deactivate_x                            0x705990

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x927550
#define CSidlManagerBase__CreatePageWnd_x                          0x926D60
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x922E90
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x922E20

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x943F00
#define CEQSuiteTextureLoader__GetTexture_x                        0x943BC0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FF9A0
#define CFindItemWnd__WndNotification_x                            0x500480
#define CFindItemWnd__Update_x                                     0x500FF0
#define CFindItemWnd__PickupSelectedItem_x                         0x4FF210

//IString
#define IString__Append_x                                          0x4EF860

//Camera
#define CDisplay__cameraType_x                                     0xDC5524
#define EverQuest__Cameras_x                                       0xE88868

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5081E0
#define LootFiltersManager__GetItemFilterData_x                    0x507AE0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x507B10
#define LootFiltersManager__SetItemLootFilter_x                    0x507D30

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B0F50

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9822B0
#define CResolutionHandler__GetWindowedStyle_x                     0x669110

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FD000

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3500

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71D0F0
#define CGroupWnd__UpdateDisplay_x                                 0x71C450

//ItemBase
#define ItemBase__IsLore_x                                         0x896A20
#define ItemBase__IsLoreEquipped_x                                 0x896A90

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C2480
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C2630
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C2690

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65E610
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6622A0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F5C50

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E4E00
#define FactionManagerClient__HandleFactionMessage_x               0x4E5470
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E5A50
#define FactionManagerClient__GetMaxFaction_x                      0x4E5AA0
#define FactionManagerClient__GetMinFaction_x                      0x4E5A20

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4EE170

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x90BB60

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
