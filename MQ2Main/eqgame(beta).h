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
#define __ExpectedVersionDate                                     "Nov  5 2018"
#define __ExpectedVersionTime                                     "04:17:10"
#define __ActualVersionDate_x                                      0xAC7AFC
#define __ActualVersionTime_x                                      0xAC7AF0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60E470
#define __MemChecker1_x                                            0x8E2A90
#define __MemChecker2_x                                            0x69D5A0
#define __MemChecker3_x                                            0x69D4F0
#define __MemChecker4_x                                            0x83A330
#define __EncryptPad0_x                                            0xBFA990
#define __EncryptPad1_x                                            0xC58C20
#define __EncryptPad2_x                                            0xC0B518
#define __EncryptPad3_x                                            0xC0B118
#define __EncryptPad4_x                                            0xC49490
#define __EncryptPad5_x                                            0xF14B24
#define __AC1_x                                                    0x7F6926
#define __AC2_x                                                    0x5C96EF
#define __AC3_x                                                    0x5D057F
#define __AC4_x                                                    0x5D4400
#define __AC5_x                                                    0x5DA5BF
#define __AC6_x                                                    0x5DEAF6
#define __AC7_x                                                    0x5C9160
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1BDB4C

// Direct Input
#define DI8__Main_x                                                0xF14B48
#define DI8__Keyboard_x                                            0xF14B4C
#define DI8__Mouse_x                                               0xF14B14
#define DI8__Mouse_Copy_x                                          0xE7286C
#define DI8__Mouse_Check_x                                         0xF15A10
#define __AutoSkillArray_x                                         0xE73784
#define __Attack_x                                                 0xF11587
#define __Autofire_x                                               0xF11588
#define __BindList_x                                               0xBE9588
#define g_eqCommandStates_x                                        0xBEA2F8
#define __Clicks_x                                                 0xE72924
#define __CommandList_x                                            0xBEAEB0
#define __CurrentMapLabel_x                                        0x1027134
#define __CurrentSocial_x                                          0xBD4728
#define __DoAbilityList_x                                          0xEA90A8
#define __do_loot_x                                                0x596F80
#define __DrawHandler_x                                            0x16A3B08
#define __GroupCount_x                                             0xE63212
#define __Guilds_x                                                 0xE69078
#define __gWorld_x                                                 0xE63400
#define __HWnd_x                                                   0xF14B18
#define __heqmain_x                                                0x101FD6C
#define __InChatMode_x                                             0xE72854
#define __LastTell_x                                               0xE747A4
#define __LMouseHeldTime_x                                         0xE72990
#define __Mouse_x                                                  0xF14B30
#define __MouseLook_x                                              0xE728EA
#define __MouseEventTime_x                                         0xF12040
#define __gpbCommandEvent_x                                        0xE62C30
#define __NetStatusToggle_x                                        0xE728ED
#define __PCNames_x                                                0xE73D64
#define __RangeAttackReady_x                                       0xE73A68
#define __RMouseHeldTime_x                                         0xE7298C
#define __RunWalkState_x                                           0xE72858
#define __ScreenMode_x                                             0xDB0BFC
#define __ScreenX_x                                                0xE7280C
#define __ScreenY_x                                                0xE72808
#define __ScreenXMax_x                                             0xE72810
#define __ScreenYMax_x                                             0xE72814
#define __ServerHost_x                                             0xE62E73
#define __ServerName_x                                             0xEA9068
#define __ShiftKeyDown_x                                           0xE72EE4
#define __ShowNames_x                                              0xE73C24
#define __Socials_x                                                0xEA9168
#define __SubscriptionType_x                                       0x1068C84
#define __TargetAggroHolder_x                                      0x1029AF0
#define __ZoneType_x                                               0xE72CE8
#define __GroupAggro_x                                             0x1029B30
#define __LoginName_x                                              0xF153A4
#define __Inviter_x                                                0xF11504
#define __AttackOnAssist_x                                         0xE73BE0
#define __UseTellWindows_x                                         0xE73EFC
#define __gfMaxZoomCameraDistance_x                                0xABCEE0
#define __gfMaxCameraDistance_x                                    0xAEA514
#define __pulAutoRun_x                                             0xE72908
#define __pulForward_x                                             0xE73F34
#define __pulBackward_x                                            0xE73F38
#define __pulTurnRight_x                                           0xE73F3C
#define __pulTurnLeft_x                                            0xE73F40
#define __pulStrafeLeft_x                                          0xE73F44
#define __pulStrafeRight_x                                         0xE73F48
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE65410
#define instEQZoneInfo_x                                           0xE72AE0
#define instKeypressHandler_x                                      0xF11FF0
#define pinstActiveBanker_x                                        0xE62D24
#define pinstActiveCorpse_x                                        0xE62D1C
#define pinstActiveGMaster_x                                       0xE62D20
#define pinstActiveMerchant_x                                      0xE62D18
#define pinstAggroInfo_x                                           0xC6F408
#define pinstAltAdvManager_x                                       0xDB1DB0
#define pinstAuraMgr_x                                             0xC800F0
#define pinstBandageTarget_x                                       0xE62D34
#define pinstCamActor_x                                            0xDB0BF0
#define pinstCDBStr_x                                              0xDB0AE4
#define pinstCDisplay_x                                            0xE631D4
#define pinstCEverQuest_x                                          0xF14C68
#define pinstEverQuestInfo_x                                       0xE72800
#define pinstCharData_x                                            0xE631E8
#define pinstCharSpawn_x                                           0xE62D6C
#define pinstControlledMissile_x                                   0xE631E4
#define pinstControlledPlayer_x                                    0xE62D6C
#define pinstCResolutionHandler_x                                  0x16A3D38
#define pinstCSidlManager_x                                        0x16A2BCC
#define pinstCXWndManager_x                                        0x16A2BC0
#define instDynamicZone_x                                          0xE68F50
#define pinstDZMember_x                                            0xE69060
#define pinstDZTimerInfo_x                                         0xE69064
#define pinstEQItemList_x                                          0xE61600
#define pinstEQObjectList_x                                        0xE627F0
#define instEQMisc_x                                               0xDB0A20
#define pinstEQSoundManager_x                                      0xDB2610
#define pinstEQSpellStrings_x                                      0xC7D540
#define instExpeditionLeader_x                                     0xE68F9A
#define instExpeditionName_x                                       0xE68FDA
#define pinstGroup_x                                               0xE6320E
#define pinstImeManager_x                                          0x16A2BC4
#define pinstLocalPlayer_x                                         0xE62D14
#define pinstMercenaryData_x                                       0xF127EC
#define pinstMercenaryStats_x                                      0x1029C3C
#define pinstMercAltAbilities_x                                    0xDB2380
#define pinstModelPlayer_x                                         0xE62D2C
#define pinstPCData_x                                              0xE631E8
#define pinstRealEstateItems_x                                     0xF13CD0
#define pinstSkillMgr_x                                            0xF13DA0
#define pinstSpawnManager_x                                        0xF13390
#define pinstSpellManager_x                                        0xF13F78
#define pinstSpellSets_x                                           0xF0A1B0
#define pinstStringTable_x                                         0xE62B04
#define pinstSwitchManager_x                                       0xE629B0
#define pinstTarget_x                                              0xE62D68
#define pinstTargetObject_x                                        0xE62F7C
#define pinstTargetSwitch_x                                        0xE631F4
#define pinstTaskMember_x                                          0xDB08B4
#define pinstTrackTarget_x                                         0xE62D70
#define pinstTradeTarget_x                                         0xE62D28
#define instTributeActive_x                                        0xDB0A45
#define pinstViewActor_x                                           0xDB0BEC
#define pinstWorldData_x                                           0xE631F0
#define pinstZoneAddr_x                                            0xE72D80
#define pinstPlayerPath_x                                          0xF13428
#define pinstTargetIndicator_x                                     0xF141E0
#define pinstCTargetManager_x                                      0xF14278
#define EQObject_Top_x                                             0xE62CFC

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDB0B98
#define pinstCAchievementsWnd_x                                    0xDB0C90
#define pinstCActionsWnd_x                                         0xDB0C10
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDB0BA0
#define pinstCAdvancedLootWnd_x                                    0xDB1408
#define pinstCAdventureLeaderboardWnd_x                            0x1020908
#define pinstCAdventureRequestWnd_x                                0x10209B8
#define pinstCAdventureStatsWnd_x                                  0x1020A68
#define pinstCAggroMeterWnd_x                                      0xDB0EA0
#define pinstCAlarmWnd_x                                           0xDB0C64
#define pinstCAlertHistoryWnd_x                                    0xDB0C48
#define pinstCAlertStackWnd_x                                      0xDB0BC4
#define pinstCAlertWnd_x                                           0xDB0BD4
#define pinstCAltStorageWnd_x                                      0x1020DC8
#define pinstCAudioTriggersWindow_x                                0xC6F898
#define pinstCAuraWnd_x                                            0xDB0E98
#define pinstCAvaZoneWnd_x                                         0xDB0C54
#define pinstCBandolierWnd_x                                       0xDB0ED0
#define pinstCBankWnd_x                                            0xDB0FB0
#define pinstCBarterMerchantWnd_x                                  0x1022008
#define pinstCBarterSearchWnd_x                                    0x10220B8
#define pinstCBarterWnd_x                                          0x1022168
#define pinstCBazaarConfirmationWnd_x                              0xDB0BC0
#define pinstCBazaarSearchWnd_x                                    0xDB0C24
#define pinstCBazaarWnd_x                                          0xDB0ECC
#define pinstCBlockedBuffWnd_x                                     0xDB0F20
#define pinstCBlockedPetBuffWnd_x                                  0xDB13C0
#define pinstCBodyTintWnd_x                                        0xDB0BD0
#define pinstCBookWnd_x                                            0xDB0EF4
#define pinstCBreathWnd_x                                          0xDB0B9C
#define pinstCBuffWindowNORMAL_x                                   0xDB0F04
#define pinstCBuffWindowSHORT_x                                    0xDB0F08
#define pinstCBugReportWnd_x                                       0xDB0B94
#define pinstCButtonWnd_x                                          0x16A2DF0
#define pinstCCastingWnd_x                                         0xDB0B90
#define pinstCCastSpellWnd_x                                       0xDB0C30
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDB0BA8
#define pinstCChatWindowManager_x                                  0x1022C28
#define pinstCClaimWnd_x                                           0x1022D80
#define pinstCColorPickerWnd_x                                     0xDB0BD8
#define pinstCCombatAbilityWnd_x                                   0xDB0EAC
#define pinstCCombatSkillsSelectWnd_x                              0xDB0C0C
#define pinstCCompassWnd_x                                         0xDB0BB4
#define pinstCConfirmationDialog_x                                 0x1027C80
#define pinstCContainerMgr_x                                       0xDB0EC0
#define pinstCContextMenuManager_x                                 0x16A2B80
#define pinstCCursorAttachment_x                                   0xDB0B84
#define pinstCDistillerInfo_x                                      0x102668C
#define pinstCDynamicZoneWnd_x                                     0x1023348
#define pinstCEditLabelWnd_x                                       0xDB0EFC
#define pinstCEQMainWnd_x                                          0x1023590
#define pinstCEventCalendarWnd_x                                   0xDB0EDC
#define pinstCExtendedTargetWnd_x                                  0xDB0C88
#define pinstCFacePick_x                                           0xDB0BDC
#define pinstCFellowshipWnd_x                                      0x1023790
#define pinstCFileSelectionWnd_x                                   0xDB13C8
#define pinstCFindItemWnd_x                                        0xDB0EE8
#define pinstCFindLocationWnd_x                                    0x10238E8
#define pinstCFriendsWnd_x                                         0xDB0C20
#define pinstCGemsGameWnd_x                                        0xDB0C34
#define pinstCGiveWnd_x                                            0xDB0EF0
#define pinstCGroupSearchFiltersWnd_x                              0xDB0EB4
#define pinstCGroupSearchWnd_x                                     0x1023CE0
#define pinstCGroupWnd_x                                           0x1023D90
#define pinstCGuildBankWnd_x                                       0xE73BC4
#define pinstCGuildCreationWnd_x                                   0x1023EF0
#define pinstCGuildMgmtWnd_x                                       0x1023FA0
#define pinstCharacterCreation_x                                   0xDB0EA8
#define pinstCHelpWnd_x                                            0xDB0C50
#define pinstCHeritageSelectionWnd_x                               0xDB0BE4
#define pinstCHotButtonWnd_x                                       0x10260F8
#define pinstCHotButtonWnd1_x                                      0x10260F8
#define pinstCHotButtonWnd2_x                                      0x10260FC
#define pinstCHotButtonWnd3_x                                      0x1026100
#define pinstCHotButtonWnd4_x                                      0x1026104
#define pinstCIconSelectionWnd_x                                   0xDB13CC
#define pinstCInspectWnd_x                                         0xDB13C4
#define pinstCInventoryWnd_x                                       0xDB0ED8
#define pinstCInvSlotMgr_x                                         0xDB0C74
#define pinstCItemDisplayManager_x                                 0x1026688
#define pinstCItemExpTransferWnd_x                                 0x10267B8
#define pinstCItemOverflowWnd_x                                    0xDB0C28
#define pinstCJournalCatWnd_x                                      0xDB0B80
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDB0F2C
#define pinstCKeyRingWnd_x                                         0xDB0F18
#define pinstCLargeDialogWnd_x                                     0x1028900
#define pinstCLayoutCopyWnd_x                                      0x1026B08
#define pinstCLFGuildWnd_x                                         0x1026BB8
#define pinstCLoadskinWnd_x                                        0xDB0C44
#define pinstCLootFiltersCopyWnd_x                                 0xC80978
#define pinstCLootFiltersWnd_x                                     0xDB0BE8
#define pinstCLootSettingsWnd_x                                    0xDB0C14
#define pinstCLootWnd_x                                            0xDB0BC8
#define pinstCMailAddressBookWnd_x                                 0xDB13D0
#define pinstCMailCompositionWnd_x                                 0xDB0FAC
#define pinstCMailIgnoreListWnd_x                                  0xDB13D8
#define pinstCMailWnd_x                                            0xDB0F10
#define pinstCManageLootWnd_x                                      0xDB2228
#define pinstCMapToolbarWnd_x                                      0xDB0EE0
#define pinstCMapViewWnd_x                                         0xDB0EBC
#define pinstCMarketplaceWnd_x                                     0xDB0EEC
#define pinstCMerchantWnd_x                                        0xDB0C08
#define pinstCMIZoneSelectWnd_x                                    0x10273F0
#define pinstCMusicPlayerWnd_x                                     0xDB0F14
#define pinstCNameChangeMercWnd_x                                  0xDB0B88
#define pinstCNameChangePetWnd_x                                   0xDB1400
#define pinstCNameChangeWnd_x                                      0xDB0EC4
#define pinstCNoteWnd_x                                            0xDB0C40
#define pinstCObjectPreviewWnd_x                                   0xDB0F0C
#define pinstCOptionsWnd_x                                         0xDB0EE4
#define pinstCPetInfoWnd_x                                         0xDB0F40
#define pinstCPetitionQWnd_x                                       0xDB0B8C
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDB0BCC
#define pinstCPlayerWnd_x                                          0xDB0C18
#define pinstCPopupWndManager_x                                    0x1027C80
#define pinstCProgressionSelectionWnd_x                            0x1027D30
#define pinstCPurchaseGroupWnd_x                                   0xDB13B8
#define pinstCPurchaseWnd_x                                        0xDB0F1C
#define pinstCPvPLeaderboardWnd_x                                  0x1027DE0
#define pinstCPvPStatsWnd_x                                        0x1027E90
#define pinstCQuantityWnd_x                                        0xDB1404
#define pinstCRaceChangeWnd_x                                      0xDB0EF8
#define pinstCRaidOptionsWnd_x                                     0xDB0EB8
#define pinstCRaidWnd_x                                            0xDB140C
#define pinstCRealEstateItemsWnd_x                                 0xDB0E9C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDB0ED4
#define pinstCRealEstateManageWnd_x                                0xDB0C1C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDB0C38
#define pinstCRealEstatePlotSearchWnd_x                            0xDB0C58
#define pinstCRealEstatePurchaseWnd_x                              0xDB0C78
#define pinstCRespawnWnd_x                                         0xDB0EB0
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDB0C8C
#define pinstCSendMoneyWnd_x                                       0xDB0F00
#define pinstCServerListWnd_x                                      0xDB0EA4
#define pinstCSkillsSelectWnd_x                                    0xDB0BE0
#define pinstCSkillsWnd_x                                          0xDB0BBC
#define pinstCSocialEditWnd_x                                      0xDB1410
#define pinstCSocialWnd_x                                          0xDB0BA4
#define pinstCSpellBookWnd_x                                       0xDB0C80
#define pinstCStoryWnd_x                                           0xDB0BB0
#define pinstCTargetOfTargetWnd_x                                  0x1029CC0
#define pinstCTargetWnd_x                                          0xDB0F30
#define pinstCTaskOverlayWnd_x                                     0xDB0C5C
#define pinstCTaskSelectWnd_x                                      0x1029E18
#define pinstCTaskSomething_x                                      0xC81178
#define pinstCTaskTemplateSelectWnd_x                              0x1029EC8
#define pinstCTaskWnd_x                                            0x1029F78
#define pinstCTextEntryWnd_x                                       0xDB0BB8
#define pinstCTextOverlay_x                                        0xC6FBA8
#define pinstCTimeLeftWnd_x                                        0xDB13F0
#define pinstCTipWndCONTEXT_x                                      0x102A17C
#define pinstCTipWndOFDAY_x                                        0x102A178
#define pinstCTitleWnd_x                                           0x102A228
#define pinstCTrackingWnd_x                                        0xDB0F28
#define pinstCTradeskillWnd_x                                      0x102A390
#define pinstCTradeWnd_x                                           0xDB0C60
#define pinstCTrainWnd_x                                           0xDB13FC
#define pinstCTributeBenefitWnd_x                                  0x102A590
#define pinstCTributeMasterWnd_x                                   0x102A640
#define pinstCTributeTrophyWnd_x                                   0x102A6F0
#define pinstCVideoModesWnd_x                                      0xDB0C4C
#define pinstCVoiceMacroWnd_x                                      0xF147A8
#define pinstCVoteResultsWnd_x                                     0xDB13BC
#define pinstCVoteWnd_x                                            0xDB0F24
#define pinstCWebManager_x                                         0xF1490C
#define pinstCZoneGuideWnd_x                                       0xDB0C2C
#define pinstCZonePathWnd_x                                        0xDB0C3C

#define pinstEQSuiteTextureLoader_x                                0xC5A6F0
#define pinstItemIconCache_x                                       0x1023548
#define pinstLootFiltersManager_x                                  0xC80A28
#define pinstRewardSelectionWnd_x                                  0x10285D8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0B10C
#define __CastRay_x                                                0x5924A0
#define __CastRay2_x                                               0x5924F0
#define __ConvertItemTags_x                                        0x5AD0A0
#define __CrashHandler_x                                           0x843CB0
#define __EQGetTime_x                                              0x8E2580
#define __ExecuteCmd_x                                             0x58ADE0
#define __FixHeading_x                                             0x972EC0
#define __get_bearing_x                                            0x591FE0
#define __get_melee_range_x                                        0x5926E0
#define __GetAnimationCache_x                                      0x7014D0
#define __GetGaugeValueFromEQ_x                                    0x7F5140
#define __GetLabelFromEQ_x                                         0x7F68B0
#define __GetXTargetType_x                                         0x974990
#define __HeadingDiff_x                                            0x972F30
#define __HelpPath_x                                               0xF11C5C
#define __LoadFrontEnd_x                                           0x699400
#define __NewUIINI_x                                               0x7F4E10
#define __pCrashHandler_x                                          0x1047AE0
#define __ProcessGameEvents_x                                      0x5EFB70
#define __ProcessMouseEvent_x                                      0x5EF330
#define __SaveColors_x                                             0x53B380
#define __STMLToText_x                                             0x916310
#define __ToggleKeyRingItem_x                                      0x4FE610
#define CrashDetected_x                                            0x69AEF0
#define DrawNetStatus_x                                            0x61BAC0
#define Expansion_HoT_x                                            0xE73BCC
#define Teleport_Table_Size_x                                      0xE62CBC
#define Teleport_Table_x                                           0xE63410
#define Util__FastTime_x                                           0x8E2140
#define wwsCrashReportCheckForUploader_x                           0x8447D0
#define wwsCrashReportPlatformLaunchUploader_x                     0x846EB0
#define __HandleMouseWheel_x                                       0x69D650

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AE50
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493C40
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493A20

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x542CA0
#define AltAdvManager__IsAbilityReady_x                            0x541D20
#define AltAdvManager__GetAAById_x                                 0x541F20
#define AltAdvManager__CanTrainAbility_x                           0x541F90
#define AltAdvManager__CanSeeAbility_x                             0x5421C0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6840
#define CharacterZoneClient__HasSkill_x                            0x4D1500
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2C20
#define CharacterZoneClient__IsStackBlocked_x                      0x4BACF0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7460
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D55B0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5690
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5770
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF7D0
#define CharacterZoneClient__BardCastBard_x                        0x4C2430
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7530
#define CharacterZoneClient__GetEffect_x                           0x4B73A0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C07D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C08A0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C08F0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0A40
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0C10

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C3990

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D1400

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FE230
#define CButtonWnd__CButtonWnd_x                                   0x912700

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EFEA0
#define CChatManager__InitContextMenu_x                            0x6E9F40
#define CChatManager__FreeChatWindow_x                             0x6EEDB0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F3750
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EFC40

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x926F60
#define CContextMenu__dCContextMenu_x                              0x927190
#define CContextMenu__AddMenuItem_x                                0x9271A0
#define CContextMenu__RemoveMenuItem_x                             0x9274A0
#define CContextMenu__RemoveAllMenuItems_x                         0x9274C0
#define CContextMenu__CheckMenuItem_x                              0x927540
#define CContextMenu__SetMenuItem_x                                0x9273D0
#define CContextMenu__AddSeparator_x                               0x927330

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x927AE0
#define CContextMenuManager__RemoveMenu_x                          0x927B50
#define CContextMenuManager__PopupMenu_x                           0x927C10
#define CContextMenuManager__Flush_x                               0x927A80
#define CContextMenuManager__GetMenu_x                             0x495CC0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C2FA0
#define CChatService__GetFriendName_x                              0x8C2FB0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F0410
#define CChatWindow__Clear_x                                       0x6F1470
#define CChatWindow__WndNotification_x                             0x6F19E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9243F0
#define CComboWnd__Draw_x                                          0x9238F0
#define CComboWnd__GetCurChoice_x                                  0x924230
#define CComboWnd__GetListRect_x                                   0x923DA0
#define CComboWnd__GetTextRect_x                                   0x924450
#define CComboWnd__InsertChoice_x                                  0x923F30
#define CComboWnd__SetColors_x                                     0x923F00
#define CComboWnd__SetChoice_x                                     0x924200
#define CComboWnd__GetItemCount_x                                  0x924240
#define CComboWnd__GetCurChoiceText_x                              0x924280

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F9690
#define CContainerWnd__vftable_x                                   0xAD0F00
#define CContainerWnd__SetContainer_x                              0x6FAC00

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53B140
#define CDisplay__GetClickedActor_x                                0x52E140
#define CDisplay__GetUserDefinedColor_x                            0x526820
#define CDisplay__GetWorldFilePath_x                               0x52FB90
#define CDisplay__is3dON_x                                         0x52AE10
#define CDisplay__ReloadUI_x                                       0x5352B0
#define CDisplay__WriteTextHD2_x                                   0x52ABF0
#define CDisplay__TrueDistance_x                                   0x5317F0
#define CDisplay__SetViewActor_x                                   0x52DA90
#define CDisplay__GetFloorHeight_x                                 0x52AED0
#define CDisplay__SetRenderWindow_x                                0x529800
#define CDisplay__ToggleScreenshotMode_x                           0x52D560

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x946750

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92B640
#define CEditWnd__GetCharIndexPt_x                                 0x92C530
#define CEditWnd__GetDisplayString_x                               0x92C3D0
#define CEditWnd__GetHorzOffset_x                                  0x92AC70
#define CEditWnd__GetLineForPrintableChar_x                        0x92D670
#define CEditWnd__GetSelStartPt_x                                  0x92C7E0
#define CEditWnd__GetSTMLSafeText_x                                0x92C1F0
#define CEditWnd__PointFromPrintableChar_x                         0x92D2A0
#define CEditWnd__SelectableCharFromPoint_x                        0x92D410
#define CEditWnd__SetEditable_x                                    0x92C8B0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DE020
#define CEverQuest__ClickedPlayer_x                                0x5D0360
#define CEverQuest__CreateTargetIndicator_x                        0x5ECE20
#define CEverQuest__DeleteTargetIndicator_x                        0x5ECEB0
#define CEverQuest__DoTellWindow_x                                 0x4E2800
#define CEverQuest__OutputTextToLog_x                              0x4E2A30
#define CEverQuest__DropHeldItemOnGround_x                         0x5C5C20
#define CEverQuest__dsp_chat_x                                     0x4E2DC0
#define CEverQuest__trimName_x                                     0x5E9390
#define CEverQuest__Emote_x                                        0x5DE830
#define CEverQuest__EnterZone_x                                    0x5D8A10
#define CEverQuest__GetBodyTypeDesc_x                              0x5E2C30
#define CEverQuest__GetClassDesc_x                                 0x5E3270
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E3870
#define CEverQuest__GetDeityDesc_x                                 0x5EB770
#define CEverQuest__GetLangDesc_x                                  0x5E3A30
#define CEverQuest__GetRaceDesc_x                                  0x5E3250
#define CEverQuest__InterpretCmd_x                                 0x5EBD40
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C9E10
#define CEverQuest__LMouseUp_x                                     0x5C8190
#define CEverQuest__RightClickedOnPlayer_x                         0x5CA6F0
#define CEverQuest__RMouseUp_x                                     0x5C9120
#define CEverQuest__SetGameState_x                                 0x5C59B0
#define CEverQuest__UPCNotificationFlush_x                         0x5E9290
#define CEverQuest__IssuePetCommand_x                              0x5E4E30
#define CEverQuest__ReportSuccessfulHit_x                          0x5DFB10

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70B660
#define CGaugeWnd__CalcLinesFillRect_x                             0x70B6C0
#define CGaugeWnd__Draw_x                                          0x70AD50

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC3C0
#define CGuild__GetGuildName_x                                     0x4AB4A0
#define CGuild__GetGuildIndex_x                                    0x4AB830

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x726A90

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FE5F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x733A20
#define CInvSlotMgr__MoveItem_x                                    0x732780
#define CInvSlotMgr__SelectSlot_x                                  0x733AF0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x731030
#define CInvSlot__SliderComplete_x                                 0x72EDA0
#define CInvSlot__GetItemBase_x                                    0x72E730
#define CInvSlot__UpdateItem_x                                     0x72E8A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x735440
#define CInvSlotWnd__CInvSlotWnd_x                                 0x734710
#define CInvSlotWnd__HandleLButtonUp_x                             0x734FC0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F1320
#define CItemDisplayWnd__UpdateStrings_x                           0x743420
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73D560
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73DA60
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x743A00
#define CItemDisplayWnd__AboutToShow_x                             0x743070
#define CItemDisplayWnd__WndNotification_x                         0x744D10

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x828DF0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x748DF0

// CLabel 
#define CLabel__Draw_x                                             0x74E8C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FCA20
#define CListWnd__dCListWnd_x                                      0x8FCD40
#define CListWnd__AddColumn_x                                      0x901040
#define CListWnd__AddColumn1_x                                     0x901090
#define CListWnd__AddLine_x                                        0x901420
#define CListWnd__AddString_x                                      0x901220
#define CListWnd__CalculateFirstVisibleLine_x                      0x900E00
#define CListWnd__CalculateVSBRange_x                              0x900BF0
#define CListWnd__ClearSel_x                                       0x901C00
#define CListWnd__ClearAllSel_x                                    0x901C60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x902650
#define CListWnd__Compare_x                                        0x900530
#define CListWnd__Draw_x                                           0x8FCE40
#define CListWnd__DrawColumnSeparators_x                           0x8FF610
#define CListWnd__DrawHeader_x                                     0x8FFA80
#define CListWnd__DrawItem_x                                       0x8FFE70
#define CListWnd__DrawLine_x                                       0x8FF780
#define CListWnd__DrawSeparator_x                                  0x8FF6B0
#define CListWnd__EnableLine_x                                     0x8FEEF0
#define CListWnd__EnsureVisible_x                                  0x902580
#define CListWnd__ExtendSel_x                                      0x901B30
#define CListWnd__GetColumnMinWidth_x                              0x8FEA30
#define CListWnd__GetColumnWidth_x                                 0x8FE9A0
#define CListWnd__GetCurSel_x                                      0x8FE330
#define CListWnd__GetItemAtPoint_x                                 0x8FF160
#define CListWnd__GetItemAtPoint1_x                                0x8FF1D0
#define CListWnd__GetItemData_x                                    0x8FE3B0
#define CListWnd__GetItemHeight_x                                  0x8FE770
#define CListWnd__GetItemIcon_x                                    0x8FE540
#define CListWnd__GetItemRect_x                                    0x8FEFE0
#define CListWnd__GetItemText_x                                    0x8FE3F0
#define CListWnd__GetSelList_x                                     0x901CB0
#define CListWnd__GetSeparatorRect_x                               0x8FF410
#define CListWnd__InsertLine_x                                     0x901810
#define CListWnd__RemoveLine_x                                     0x901960
#define CListWnd__SetColors_x                                      0x900BC0
#define CListWnd__SetColumnJustification_x                         0x9008F0
#define CListWnd__SetColumnWidth_x                                 0x900810
#define CListWnd__SetCurSel_x                                      0x901A70
#define CListWnd__SetItemColor_x                                   0x902240
#define CListWnd__SetItemData_x                                    0x902200
#define CListWnd__SetItemText_x                                    0x901E30
#define CListWnd__ShiftColumnSeparator_x                           0x9009B0
#define CListWnd__Sort_x                                           0x9006B0
#define CListWnd__ToggleSel_x                                      0x901AA0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x763FD0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7626E0
#define CMapViewWnd__HandleLButtonDown_x                           0x75F740

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7870A0
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x787980
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x787EB0
#define CMerchantWnd__SelectRecoverySlot_x                         0x78ACD0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x785A90
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x790860
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x786CE0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x890EF0
#define CPacketScrambler__hton_x                                   0x890EE0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91B920
#define CSidlManager__FindScreenPieceTemplate_x                    0x91BD30
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91BB20
#define CSidlManager__CreateLabel_x                                0x7E8780
#define CSidlManager__CreateXWndFromTemplate_x                     0x91EE00
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91EFE0
#define CSidlManager__CreateXWnd_x                                 0x7E86B0
#define CSidlManager__CreateHotButtonWnd_x                         0x7E8C80

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x918490
#define CSidlScreenWnd__CalculateVSBRange_x                        0x918380
#define CSidlScreenWnd__ConvertToRes_x                             0x93D540
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x917E10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x917B00
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x917BD0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x917CA0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x918930
#define CSidlScreenWnd__EnableIniStorage_x                         0x918E00
#define CSidlScreenWnd__GetSidlPiece_x                             0x918B20
#define CSidlScreenWnd__Init1_x                                    0x9176F0
#define CSidlScreenWnd__LoadIniInfo_x                              0x918E50
#define CSidlScreenWnd__LoadIniListWnd_x                           0x919990
#define CSidlScreenWnd__LoadSidlScreen_x                           0x916AF0
#define CSidlScreenWnd__StoreIniInfo_x                             0x919510
#define CSidlScreenWnd__StoreIniVis_x                              0x919870
#define CSidlScreenWnd__WndNotification_x                          0x918840
#define CSidlScreenWnd__GetChildItem_x                             0x918D80
#define CSidlScreenWnd__HandleLButtonUp_x                          0x908540
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A2A50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x662600
#define CSkillMgr__GetSkillCap_x                                   0x6627E0
#define CSkillMgr__GetNameToken_x                                  0x661D90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9288D0
#define CSliderWnd__SetValue_x                                     0x928740
#define CSliderWnd__SetNumTicks_x                                  0x9287A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EE590

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x92F520
#define CStmlWnd__CalculateHSBRange_x                              0x9305B0
#define CStmlWnd__CalculateVSBRange_x                              0x930520
#define CStmlWnd__CanBreakAtCharacter_x                            0x9348F0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9354E0
#define CStmlWnd__ForceParseNow_x                                  0x92FAC0
#define CStmlWnd__GetNextTagPiece_x                                0x934850
#define CStmlWnd__GetSTMLText_x                                    0x4F0C60
#define CStmlWnd__GetVisibleText_x                                 0x92FAE0
#define CStmlWnd__InitializeWindowVariables_x                      0x935330
#define CStmlWnd__MakeStmlColorTag_x                               0x92ECB0
#define CStmlWnd__MakeWndNotificationTag_x                         0x92ED20
#define CStmlWnd__SetSTMLText_x                                    0x92DD80
#define CStmlWnd__StripFirstSTMLLines_x                            0x936640
#define CStmlWnd__UpdateHistoryString_x                            0x9356F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93A350
#define CTabWnd__DrawCurrentPage_x                                 0x93A970
#define CTabWnd__DrawTab_x                                         0x93A740
#define CTabWnd__GetCurrentPage_x                                  0x939BB0
#define CTabWnd__GetPageInnerRect_x                                0x939DF0
#define CTabWnd__GetTabInnerRect_x                                 0x939D30
#define CTabWnd__GetTabRect_x                                      0x939BE0
#define CTabWnd__InsertPage_x                                      0x939FE0
#define CTabWnd__SetPage_x                                         0x939E70
#define CTabWnd__SetPageRect_x                                     0x93A290
#define CTabWnd__UpdatePage_x                                      0x93A600
#define CTabWnd__GetPageFromTabIndex_x                             0x93A680
#define CTabWnd__GetCurrentTabIndex_x                              0x939BA0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x749250
#define CPageWnd__SetTabText_x                                     0x946B60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5F00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9053C0
#define CTextureFont__GetTextExtent_x                              0x905580

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x696220
#define CHtmlComponentWnd__ValidateUri_x                           0x728480
#define CHtmlWnd__SetClientCallbacks_x                             0x6035D0
#define CHtmlWnd__AddObserver_x                                    0x6035F0
#define CHtmlWnd__RemoveObserver_x                                 0x603650
#define Window__getProgress_x                                      0x841900
#define Window__getStatus_x                                        0x841920
#define Window__getURI_x                                           0x841930

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9430E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F2230

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD670
#define CXStr__CXStr1_x                                            0x4B30D0
#define CXStr__CXStr3_x                                            0x8DE670
#define CXStr__dCXStr_x                                            0x472910
#define CXStr__operator_equal_x                                    0x8DE8A0
#define CXStr__operator_equal1_x                                   0x8DE8E0
#define CXStr__operator_plus_equal1_x                              0x8DF370

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x926B70
#define CXWnd__BringToTop_x                                        0x90BCA0
#define CXWnd__Center_x                                            0x90B820
#define CXWnd__ClrFocus_x                                          0x90B660
#define CXWnd__Destroy_x                                           0x90B700
#define CXWnd__DoAllDrawing_x                                      0x907CF0
#define CXWnd__DrawChildren_x                                      0x907CC0
#define CXWnd__DrawColoredRect_x                                   0x908150
#define CXWnd__DrawTooltip_x                                       0x906820
#define CXWnd__DrawTooltipAtPoint_x                                0x9068E0
#define CXWnd__GetBorderFrame_x                                    0x907FB0
#define CXWnd__GetChildWndAt_x                                     0x90BD40
#define CXWnd__GetClientClipRect_x                                 0x909F70
#define CXWnd__GetScreenClipRect_x                                 0x90A020
#define CXWnd__GetScreenRect_x                                     0x90A1A0
#define CXWnd__GetTooltipRect_x                                    0x9081A0
#define CXWnd__GetWindowTextA_x                                    0x497350
#define CXWnd__IsActive_x                                          0x90EC40
#define CXWnd__IsDescendantOf_x                                    0x90ABC0
#define CXWnd__IsReallyVisible_x                                   0x90ABF0
#define CXWnd__IsType_x                                            0x90C3B0
#define CXWnd__Move_x                                              0x90AC60
#define CXWnd__Move1_x                                             0x90AD20
#define CXWnd__ProcessTransition_x                                 0x90B7D0
#define CXWnd__Refade_x                                            0x90AFF0
#define CXWnd__Resize_x                                            0x90B270
#define CXWnd__Right_x                                             0x90BA60
#define CXWnd__SetFocus_x                                          0x90B620
#define CXWnd__SetFont_x                                           0x90B690
#define CXWnd__SetKeyTooltip_x                                     0x90C1D0
#define CXWnd__SetMouseOver_x                                      0x9090F0
#define CXWnd__StartFade_x                                         0x90AA90
#define CXWnd__GetChildItem_x                                      0x90BEB0
#define CXWnd__SetParent_x                                         0x90A950

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93E610

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90EC80
#define CXWndManager__DrawWindows_x                                0x90ECA0
#define CXWndManager__GetKeyboardFlags_x                           0x9113D0
#define CXWndManager__HandleKeyboardMsg_x                          0x910FD0
#define CXWndManager__RemoveWnd_x                                  0x911620
#define CXWndManager__RemovePendingDeletionWnd_x                   0x911B70

// CDBStr
#define CDBStr__GetString_x                                        0x5257D0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8410
#define EQ_Character__Cur_HP_x                                     0x4CE580
#define EQ_Character__Cur_Mana_x                                   0x4D5C70
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB330
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF2C0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF410
#define EQ_Character__GetHPRegen_x                                 0x4DBC30
#define EQ_Character__GetEnduranceRegen_x                          0x4DC240
#define EQ_Character__GetManaRegen_x                               0x4DC680
#define EQ_Character__Max_Endurance_x                              0x629060
#define EQ_Character__Max_HP_x                                     0x4CE3B0
#define EQ_Character__Max_Mana_x                                   0x628E60
#define EQ_Character__doCombatAbility_x                            0x62B210
#define EQ_Character__UseSkill_x                                   0x4DE470
#define EQ_Character__GetConLevel_x                                0x6227A0
#define EQ_Character__IsExpansionFlag_x                            0x589490
#define EQ_Character__TotalEffect_x                                0x4C19B0
#define EQ_Character__GetPCSpellAffect_x                           0x4BBF20
#define EQ_Character__SpellDuration_x                              0x4BBA50
#define EQ_Character__FindItemByRecord_x                           0x4D3B90
#define EQ_Character__GetAdjustedSkill_x                           0x4D12C0
#define EQ_Character__GetBaseSkill_x                               0x4D2260
#define EQ_Character__CanUseItem_x                                 0x4D5F80

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8AFF00

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63F0A0

//PcClient
#define PcClient__PcClient_x                                       0x620070

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B61E0
#define CCharacterListWnd__EnterWorld_x                            0x4B5C20
#define CCharacterListWnd__Quit_x                                  0x4B5930
#define CCharacterListWnd__UpdateList_x                            0x4B5DB0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x604810
#define EQ_Item__CreateItemTagString_x                             0x88A970
#define EQ_Item__IsStackable_x                                     0x88F2A0
#define EQ_Item__GetImageNum_x                                     0x88C280
#define EQ_Item__CreateItemClient_x                                0x6039D0
#define EQ_Item__GetItemValue_x                                    0x88D4E0
#define EQ_Item__ValueSellMerchant_x                               0x890A90
#define EQ_Item__IsKeyRingItem_x                                   0x88EBF0
#define EQ_Item__CanGoInBag_x                                      0x604930
#define EQ_Item__GetMaxItemCount_x                                 0x88D8B0
#define EQ_Item__GetHeldItem_x                                     0x88C150
#define EQ_Item__GetAugmentFitBySlot_x                             0x88A2B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5439C0
#define EQ_LoadingS__Array_x                                       0xBE2798

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6299C0
#define EQ_PC__GetAlternateAbilityId_x                             0x899C20
#define EQ_PC__GetCombatAbility_x                                  0x89A290
#define EQ_PC__GetCombatAbilityTimer_x                             0x89A300
#define EQ_PC__GetItemRecastTimer_x                                0x62B790
#define EQ_PC__HasLoreItem_x                                       0x622FC0
#define EQ_PC__AlertInventoryChanged_x                             0x622270
#define EQ_PC__GetPcZoneClient_x                                   0x64D7E0
#define EQ_PC__RemoveMyAffect_x                                    0x62E990
#define EQ_PC__GetKeyRingItems_x                                   0x89ABA0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89A920
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89AE90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58F9F0
#define EQItemList__add_object_x                                   0x5BB3E0
#define EQItemList__add_item_x                                     0x590000
#define EQItemList__delete_item_x                                  0x590050
#define EQItemList__FreeItemList_x                                 0x58FF50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x522E70

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x640920
#define EQPlayer__dEQPlayer_x                                      0x634020
#define EQPlayer__DoAttack_x                                       0x6484E0
#define EQPlayer__EQPlayer_x                                       0x6346D0
#define EQPlayer__SetNameSpriteState_x                             0x638950
#define EQPlayer__SetNameSpriteTint_x                              0x639820
#define PlayerBase__HasProperty_j_x                                0x971250
#define EQPlayer__IsTargetable_x                                   0x9716F0
#define EQPlayer__CanSee_x                                         0x971550
#define EQPlayer__CanSee1_x                                        0x971620
#define PlayerBase__GetVisibilityLineSegment_x                     0x971310

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64B2B0
#define PlayerZoneClient__GetLevel_x                               0x64D820
#define PlayerZoneClient__IsValidTeleport_x                        0x5BC530
#define PlayerZoneClient__LegalPlayerRace_x                        0x53CEF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x643620
#define EQPlayerManager__GetSpawnByName_x                          0x643640
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6436D0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6080E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x608120
#define KeypressHandler__ClearCommandStateArray_x                  0x609510
#define KeypressHandler__HandleKeyDown_x                           0x609530
#define KeypressHandler__HandleKeyUp_x                             0x6095D0
#define KeypressHandler__SaveKeymapping_x                          0x6099B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75FE60
#define MapViewMap__SaveEx_x                                       0x763200
#define MapViewMap__SetZoom_x                                      0x7678D0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8ADDF0

// StringTable 
#define StringTable__getString_x                                   0x8A8D70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62E600
#define PcZoneClient__RemovePetEffect_x                            0x62EC30
#define PcZoneClient__HasAlternateAbility_x                        0x628CA0
#define PcZoneClient__GetCurrentMod_x                              0x4E1570
#define PcZoneClient__GetModCap_x                                  0x4E1470
#define PcZoneClient__CanEquipItem_x                               0x629350
#define PcZoneClient__GetItemByID_x                                0x62BC10
#define PcZoneClient__GetItemByItemClass_x                         0x62BD60
#define PcZoneClient__RemoveBuffEffect_x                           0x62EC50
#define PcZoneClient__BandolierSwap_x                              0x629F80

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C10B0

//IconCache
#define IconCache__GetIcon_x                                       0x700D60

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F8830
#define CContainerMgr__CloseContainer_x                            0x6F8B00
#define CContainerMgr__OpenExperimentContainer_x                   0x6F9580

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BAE80

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FCA10

//CLootWnd
#define CLootWnd__LootAll_x                                        0x756270
#define CLootWnd__RequestLootSlot_x                                0x755630

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55BE30
#define EQ_Spell__SpellAffects_x                                   0x55C2A0
#define EQ_Spell__SpellAffectBase_x                                0x55C060
#define EQ_Spell__IsStackable_x                                    0x4C6150
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5FA0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B37E0
#define EQ_Spell__IsSPAStacking_x                                  0x55D0D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55C5F0
#define EQ_Spell__IsNoRemove_x                                     0x4C6130
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55D0E0
#define __IsResEffectSpell_x                                       0x4C54F0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA0D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B8460

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8006A0
#define CTargetWnd__WndNotification_x                              0x7FFF30
#define CTargetWnd__RefreshTargetBuffs_x                           0x800200
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FF080

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x804D70

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5573D0
#define EqSoundManager__PlayScriptMp3_x                            0x557530
#define EqSoundManager__SoundAssistPlay_x                          0x6664A0
#define EqSoundManager__WaveInstancePlay_x                         0x665A10

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x514740

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92A2B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54B650
#define CAltAbilityData__GetMercMaxRank_x                          0x54B5F0
#define CAltAbilityData__GetMaxRank_x                              0x540BD0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FAB20

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5F80
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FAA40
#define CharacterBase__CreateItemIndex_x                           0x602BE0
#define CharacterBase__GetItemPossession_x                         0x4B3690
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C0AD0
#define CharacterBase__GetEffectId_x                               0x4C5F30

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E0990
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E11B0

//messages
#define msg_spell_worn_off_x                                       0x581560
#define msg_new_text_x                                             0x5764D0
#define __msgTokenTextParam_x                                      0x583BB0
#define msgTokenText_x                                             0x583E00

//SpellManager
#define SpellManager__vftable_x                                    0xAAB890
#define SpellManager__SpellManager_x                               0x6697D0
#define Spellmanager__LoadTextSpells_x                             0x66A0A0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6699A0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x975280

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FB0F0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x587A30
#define ItemGlobalIndex__IsEquippedLocation_x                      0x589470
#define ItemGlobalIndex__IsValidIndex_x                            0x4FB150

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B8DA0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B9020

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74EC10

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FCFB0
#define CCursorAttachment__Deactivate_x                            0x6FDF90

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93C9D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x93C690

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F80C0

//IString
#define IString__Append_x                                          0x4EAC20

//Camera
#define CDisplay__cameraType_x                                     0xDB0C94
#define EverQuest__Cameras_x                                       0xE73F08

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5008B0
#define LootFiltersManager__GetItemFilterData_x                    0x5001A0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5001D0
#define LootFiltersManager__SetItemLootFilter_x                    0x5003F0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A8E80

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97AF00
#define CResolutionHandler__GetWindowedStyle_x                     0x660FB0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F55E0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CB400

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7157D0
#define CGroupWnd__UpdateDisplay_x                                 0x714B30

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
#if defined(ROF2EMU) || defined(UFEMU)
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\xFD\xFF\xFF\x8B\xCE\x5E\xE9\x00\x00\xFF\xFF\xC7\x01";
static char lpMask[] = "xxxx?xxxxxxx??xxxx";
#else
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
#endif
