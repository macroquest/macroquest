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
#define __ExpectedVersionDate                                     "Nov  2 2018"
#define __ExpectedVersionTime                                     "04:20:28"
#define __ActualVersionDate_x                                      0xAC7AAC
#define __ActualVersionTime_x                                      0xAC7AA0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60E0D0
#define __MemChecker1_x                                            0x8E2320
#define __MemChecker2_x                                            0x69CDA0
#define __MemChecker3_x                                            0x69CCF0
#define __MemChecker4_x                                            0x839D20
#define __EncryptPad0_x                                            0xBFA990
#define __EncryptPad1_x                                            0xC58C20
#define __EncryptPad2_x                                            0xC0B518
#define __EncryptPad3_x                                            0xC0B118
#define __EncryptPad4_x                                            0xC49490
#define __EncryptPad5_x                                            0xF14B24
#define __AC1_x                                                    0x7F6326
#define __AC2_x                                                    0x5C923F
#define __AC3_x                                                    0x5D00CF
#define __AC4_x                                                    0x5D3F50
#define __AC5_x                                                    0x5DA10F
#define __AC6_x                                                    0x5DE646
#define __AC7_x                                                    0x5C8CB0
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
#define __do_loot_x                                                0x596A80
#define __DrawHandler_x                                            0x16A3B08
#define __GroupCount_x                                             0xE63212
#define __Guilds_x                                                 0xE69078
#define __gWorld_x                                                 0xE631FC
#define __HWnd_x                                                   0xF14B18
#define __heqmain_x                                                0x101FD6C
#define __InChatMode_x                                             0xE72854
#define __LastTell_x                                               0xE747A4
#define __LMouseHeldTime_x                                         0xE72990
#define __Mouse_x                                                  0xF14B30
#define __MouseLook_x                                              0xE728EA
#define __MouseEventTime_x                                         0xF12040
#define __gpbCommandEvent_x                                        0xE62C2C
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
#define __gfMaxZoomCameraDistance_x                                0xABCED0
#define __gfMaxCameraDistance_x                                    0xAEA51C
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
#define pinstActiveBanker_x                                        0xE62D20
#define pinstActiveCorpse_x                                        0xE62D18
#define pinstActiveGMaster_x                                       0xE62D1C
#define pinstActiveMerchant_x                                      0xE62D14
#define pinstAggroInfo_x                                           0xC6F408
#define pinstAltAdvManager_x                                       0xDB1DB0
#define pinstAuraMgr_x                                             0xC800F0
#define pinstBandageTarget_x                                       0xE62D30
#define pinstCamActor_x                                            0xDB0BF0
#define pinstCDBStr_x                                              0xDB0AE4
#define pinstCDisplay_x                                            0xE631D0
#define pinstCEverQuest_x                                          0xF14C68
#define pinstEverQuestInfo_x                                       0xE72800
#define pinstCharData_x                                            0xE631E4
#define pinstCharSpawn_x                                           0xE62D68
#define pinstControlledMissile_x                                   0xE631E0
#define pinstControlledPlayer_x                                    0xE62D68
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
#define pinstLocalPlayer_x                                         0xE62D10
#define pinstMercenaryData_x                                       0xF127EC
#define pinstMercenaryStats_x                                      0x1029C3C
#define pinstMercAltAbilities_x                                    0xDB2380
#define pinstModelPlayer_x                                         0xE62D28
#define pinstPCData_x                                              0xE631E4
#define pinstRealEstateItems_x                                     0xF13CD0
#define pinstSkillMgr_x                                            0xF13DA0
#define pinstSpawnManager_x                                        0xF13390
#define pinstSpellManager_x                                        0xF13F78
#define pinstSpellSets_x                                           0xF0A1B0
#define pinstStringTable_x                                         0xE62B00
#define pinstSwitchManager_x                                       0xE629B0
#define pinstTarget_x                                              0xE62D64
#define pinstTargetObject_x                                        0xE62F7C
#define pinstTargetSwitch_x                                        0xE631F0
#define pinstTaskMember_x                                          0xDB08B4
#define pinstTrackTarget_x                                         0xE62D6C
#define pinstTradeTarget_x                                         0xE62D24
#define instTributeActive_x                                        0xDB0A45
#define pinstViewActor_x                                           0xDB0BEC
#define pinstWorldData_x                                           0xE631EC
#define pinstZoneAddr_x                                            0xE72D80
#define pinstPlayerPath_x                                          0xF13428
#define pinstTargetIndicator_x                                     0xF141E0
#define pinstCTargetManager_x                                      0xF14278
#define EQObject_Top_x                                             0xE62CF8

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
#define __CastRay_x                                                0x591FA0
#define __CastRay2_x                                               0x591FF0
#define __ConvertItemTags_x                                        0x5ACBA0
#define __CrashHandler_x                                           0x843660
#define __EQGetTime_x                                              0x8E1E10
#define __ExecuteCmd_x                                             0x58A930
#define __FixHeading_x                                             0x9726B0
#define __get_bearing_x                                            0x591AE0
#define __get_melee_range_x                                        0x5921E0
#define __GetAnimationCache_x                                      0x700A60
#define __GetGaugeValueFromEQ_x                                    0x7F4B40
#define __GetLabelFromEQ_x                                         0x7F62B0
#define __GetXTargetType_x                                         0x974110
#define __HeadingDiff_x                                            0x972720
#define __HelpPath_x                                               0xF11C5C
#define __LoadFrontEnd_x                                           0x698C00
#define __NewUIINI_x                                               0x7F4810
#define __pCrashHandler_x                                          0x1047AE0
#define __ProcessGameEvents_x                                      0x5EF6C0
#define __ProcessMouseEvent_x                                      0x5EEE80
#define __SaveColors_x                                             0x53B380
#define __STMLToText_x                                             0x915840
#define __ToggleKeyRingItem_x                                      0x4FE880
#define CrashDetected_x                                            0x69A6F0
#define DrawNetStatus_x                                            0x61B4F0
#define Expansion_HoT_x                                            0xE73BCC
#define Teleport_Table_Size_x                                      0xE62CB8
#define Teleport_Table_x                                           0xE63408
#define Util__FastTime_x                                           0x8E19D0
#define wwsCrashReportCheckForUploader_x                           0x844090
#define wwsCrashReportPlatformLaunchUploader_x                     0x846780
#define __HandleMouseWheel_x                                       0x69CE50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B180
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493F70
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493D50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x542CA0
#define AltAdvManager__IsAbilityReady_x                            0x541D20
#define AltAdvManager__GetAAById_x                                 0x541F20
#define AltAdvManager__CanTrainAbility_x                           0x541F90
#define AltAdvManager__CanSeeAbility_x                             0x5421C0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6E70
#define CharacterZoneClient__HasSkill_x                            0x4D1B30
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3250
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB310
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7A90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5C00
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5CE0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5DC0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BFDF0
#define CharacterZoneClient__BardCastBard_x                        0x4C2A50
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7B60
#define CharacterZoneClient__GetEffect_x                           0x4B79D0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0DF0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0EC0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0F10
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1060
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1230

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C2EE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D0730

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FDDB0
#define CButtonWnd__CButtonWnd_x                                   0x911C40

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EF4A0
#define CChatManager__InitContextMenu_x                            0x6E9540
#define CChatManager__FreeChatWindow_x                             0x6EE3B0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F2D30
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EF240

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x926410
#define CContextMenu__dCContextMenu_x                              0x926640
#define CContextMenu__AddMenuItem_x                                0x926650
#define CContextMenu__RemoveMenuItem_x                             0x926960
#define CContextMenu__RemoveAllMenuItems_x                         0x926980
#define CContextMenu__CheckMenuItem_x                              0x926A00
#define CContextMenu__SetMenuItem_x                                0x926880
#define CContextMenu__AddSeparator_x                               0x9267E0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x926FA0
#define CContextMenuManager__RemoveMenu_x                          0x927010
#define CContextMenuManager__PopupMenu_x                           0x9270D0
#define CContextMenuManager__Flush_x                               0x926F40
#define CContextMenuManager__GetMenu_x                             0x4961B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C2910
#define CChatService__GetFriendName_x                              0x8C2920

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EFA10
#define CChatWindow__Clear_x                                       0x6F0A60
#define CChatWindow__WndNotification_x                             0x6F0FC0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9238A0
#define CComboWnd__Draw_x                                          0x922D90
#define CComboWnd__GetCurChoice_x                                  0x9236E0
#define CComboWnd__GetListRect_x                                   0x923250
#define CComboWnd__GetTextRect_x                                   0x923910
#define CComboWnd__InsertChoice_x                                  0x9233E0
#define CComboWnd__SetColors_x                                     0x9233B0
#define CComboWnd__SetChoice_x                                     0x9236B0
#define CComboWnd__GetItemCount_x                                  0x9236F0
#define CComboWnd__GetCurChoiceText_x                              0x923730

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F8C70
#define CContainerWnd__vftable_x                                   0xAD0EB0
#define CContainerWnd__SetContainer_x                              0x6FA1E0

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
#define CEditBaseWnd__SetSel_x                                     0x945EA0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92AB10
#define CEditWnd__GetCharIndexPt_x                                 0x92BA00
#define CEditWnd__GetDisplayString_x                               0x92B8A0
#define CEditWnd__GetHorzOffset_x                                  0x92A140
#define CEditWnd__GetLineForPrintableChar_x                        0x92CB10
#define CEditWnd__GetSelStartPt_x                                  0x92BCB0
#define CEditWnd__GetSTMLSafeText_x                                0x92B6C0
#define CEditWnd__PointFromPrintableChar_x                         0x92C750
#define CEditWnd__SelectableCharFromPoint_x                        0x92C8C0
#define CEditWnd__SetEditable_x                                    0x92BD70

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DDB70
#define CEverQuest__ClickedPlayer_x                                0x5CFEB0
#define CEverQuest__CreateTargetIndicator_x                        0x5EC970
#define CEverQuest__DeleteTargetIndicator_x                        0x5ECA00
#define CEverQuest__DoTellWindow_x                                 0x4E2EC0
#define CEverQuest__OutputTextToLog_x                              0x4E30F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C5770
#define CEverQuest__dsp_chat_x                                     0x4E3480
#define CEverQuest__trimName_x                                     0x5E8EE0
#define CEverQuest__Emote_x                                        0x5DE380
#define CEverQuest__EnterZone_x                                    0x5D8560
#define CEverQuest__GetBodyTypeDesc_x                              0x5E2780
#define CEverQuest__GetClassDesc_x                                 0x5E2DC0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E33C0
#define CEverQuest__GetDeityDesc_x                                 0x5EB2C0
#define CEverQuest__GetLangDesc_x                                  0x5E3580
#define CEverQuest__GetRaceDesc_x                                  0x5E2DA0
#define CEverQuest__InterpretCmd_x                                 0x5EB890
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C9960
#define CEverQuest__LMouseUp_x                                     0x5C7CE0
#define CEverQuest__RightClickedOnPlayer_x                         0x5CA240
#define CEverQuest__RMouseUp_x                                     0x5C8C70
#define CEverQuest__SetGameState_x                                 0x5C5500
#define CEverQuest__UPCNotificationFlush_x                         0x5E8DE0
#define CEverQuest__IssuePetCommand_x                              0x5E4980
#define CEverQuest__ReportSuccessfulHit_x                          0x5DF660

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70AC30
#define CGaugeWnd__CalcLinesFillRect_x                             0x70AC90
#define CGaugeWnd__Draw_x                                          0x70A320

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC970
#define CGuild__GetGuildName_x                                     0x4ABA50
#define CGuild__GetGuildIndex_x                                    0x4ABDE0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x725FB0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FE170

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x732F60
#define CInvSlotMgr__MoveItem_x                                    0x731CC0
#define CInvSlotMgr__SelectSlot_x                                  0x733030

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x730570
#define CInvSlot__SliderComplete_x                                 0x72E2D0
#define CInvSlot__GetItemBase_x                                    0x72DC50
#define CInvSlot__UpdateItem_x                                     0x72DDC0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x734980
#define CInvSlotWnd__CInvSlotWnd_x                                 0x733C50
#define CInvSlotWnd__HandleLButtonUp_x                             0x734500

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F0D20
#define CItemDisplayWnd__UpdateStrings_x                           0x742A90
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73CB60
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73D080
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x743070
#define CItemDisplayWnd__AboutToShow_x                             0x7426D0
#define CItemDisplayWnd__WndNotification_x                         0x744380

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x828600

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x748550

// CLabel 
#define CLabel__Draw_x                                             0x74DFC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FC1F0
#define CListWnd__dCListWnd_x                                      0x8FC510
#define CListWnd__AddColumn_x                                      0x900830
#define CListWnd__AddColumn1_x                                     0x900880
#define CListWnd__AddLine_x                                        0x900C10
#define CListWnd__AddString_x                                      0x900A10
#define CListWnd__CalculateFirstVisibleLine_x                      0x9005F0
#define CListWnd__CalculateVSBRange_x                              0x9003E0
#define CListWnd__ClearSel_x                                       0x9013F0
#define CListWnd__ClearAllSel_x                                    0x901450
#define CListWnd__CloseAndUpdateEditWindow_x                       0x901E50
#define CListWnd__Compare_x                                        0x8FFD20
#define CListWnd__Draw_x                                           0x8FC610
#define CListWnd__DrawColumnSeparators_x                           0x8FEDF0
#define CListWnd__DrawHeader_x                                     0x8FF260
#define CListWnd__DrawItem_x                                       0x8FF660
#define CListWnd__DrawLine_x                                       0x8FEF60
#define CListWnd__DrawSeparator_x                                  0x8FEE90
#define CListWnd__EnableLine_x                                     0x8FE6C0
#define CListWnd__EnsureVisible_x                                  0x901D70
#define CListWnd__ExtendSel_x                                      0x901320
#define CListWnd__GetColumnMinWidth_x                              0x8FE200
#define CListWnd__GetColumnWidth_x                                 0x8FE170
#define CListWnd__GetCurSel_x                                      0x8FDB00
#define CListWnd__GetItemAtPoint_x                                 0x8FE940
#define CListWnd__GetItemAtPoint1_x                                0x8FE9B0
#define CListWnd__GetItemData_x                                    0x8FDB80
#define CListWnd__GetItemHeight_x                                  0x8FDF40
#define CListWnd__GetItemIcon_x                                    0x8FDD10
#define CListWnd__GetItemRect_x                                    0x8FE7B0
#define CListWnd__GetItemText_x                                    0x8FDBC0
#define CListWnd__GetSelList_x                                     0x9014A0
#define CListWnd__GetSeparatorRect_x                               0x8FEBF0
#define CListWnd__InsertLine_x                                     0x901000
#define CListWnd__RemoveLine_x                                     0x901150
#define CListWnd__SetColors_x                                      0x9003B0
#define CListWnd__SetColumnJustification_x                         0x9000E0
#define CListWnd__SetColumnWidth_x                                 0x900000
#define CListWnd__SetCurSel_x                                      0x901260
#define CListWnd__SetItemColor_x                                   0x901A20
#define CListWnd__SetItemData_x                                    0x9019E0
#define CListWnd__SetItemText_x                                    0x901620
#define CListWnd__ShiftColumnSeparator_x                           0x9001A0
#define CListWnd__Sort_x                                           0x8FFEA0
#define CListWnd__ToggleSel_x                                      0x901290

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7634A0
#define CMapViewWnd__GetWorldCoordinates_x                         0x761BB0
#define CMapViewWnd__HandleLButtonDown_x                           0x75EC10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7868A0
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x787180
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7876C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x78A4F0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x785280
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x790090
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7864D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x890530
#define CPacketScrambler__hton_x                                   0x890520

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91AE30
#define CSidlManager__FindScreenPieceTemplate_x                    0x91B240
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91B030
#define CSidlManager__CreateLabel_x                                0x7E81A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x91E310
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91E4F0
#define CSidlManager__CreateXWnd_x                                 0x7E80D0
#define CSidlManager__CreateHotButtonWnd_x                         0x7E8680

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9179A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9178A0
#define CSidlScreenWnd__ConvertToRes_x                             0x93CD30
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x917340
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x917030
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x917100
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9171D0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x917E40
#define CSidlScreenWnd__EnableIniStorage_x                         0x918310
#define CSidlScreenWnd__GetSidlPiece_x                             0x918030
#define CSidlScreenWnd__Init1_x                                    0x916C20
#define CSidlScreenWnd__LoadIniInfo_x                              0x918360
#define CSidlScreenWnd__LoadIniListWnd_x                           0x918EA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x916020
#define CSidlScreenWnd__StoreIniInfo_x                             0x918A20
#define CSidlScreenWnd__StoreIniVis_x                              0x918D80
#define CSidlScreenWnd__WndNotification_x                          0x917D50
#define CSidlScreenWnd__GetChildItem_x                             0x918290
#define CSidlScreenWnd__HandleLButtonUp_x                          0x907C10
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A2A50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x661F10
#define CSkillMgr__GetSkillCap_x                                   0x6620F0
#define CSkillMgr__GetNameToken_x                                  0x6616A0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x927D90
#define CSliderWnd__SetValue_x                                     0x927C00
#define CSliderWnd__SetNumTicks_x                                  0x927C60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EDFA0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x92E9C0
#define CStmlWnd__CalculateHSBRange_x                              0x92FA50
#define CStmlWnd__CalculateVSBRange_x                              0x92F9C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x933D80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x934970
#define CStmlWnd__ForceParseNow_x                                  0x92EF60
#define CStmlWnd__GetNextTagPiece_x                                0x933CE0
#define CStmlWnd__GetSTMLText_x                                    0x4F12D0
#define CStmlWnd__GetVisibleText_x                                 0x92EF80
#define CStmlWnd__InitializeWindowVariables_x                      0x9347C0
#define CStmlWnd__MakeStmlColorTag_x                               0x92E150
#define CStmlWnd__MakeWndNotificationTag_x                         0x92E1C0
#define CStmlWnd__SetSTMLText_x                                    0x92D220
#define CStmlWnd__StripFirstSTMLLines_x                            0x935AD0
#define CStmlWnd__UpdateHistoryString_x                            0x934B80

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9397C0
#define CTabWnd__DrawCurrentPage_x                                 0x939DE0
#define CTabWnd__DrawTab_x                                         0x939BB0
#define CTabWnd__GetCurrentPage_x                                  0x939020
#define CTabWnd__GetPageInnerRect_x                                0x939260
#define CTabWnd__GetTabInnerRect_x                                 0x9391A0
#define CTabWnd__GetTabRect_x                                      0x939050
#define CTabWnd__InsertPage_x                                      0x939450
#define CTabWnd__SetPage_x                                         0x9392E0
#define CTabWnd__SetPageRect_x                                     0x939700
#define CTabWnd__UpdatePage_x                                      0x939A70
#define CTabWnd__GetPageFromTabIndex_x                             0x939AF0
#define CTabWnd__GetCurrentTabIndex_x                              0x939010

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7489B0
#define CPageWnd__SetTabText_x                                     0x9462B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A64D0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x904AA0
#define CTextureFont__GetTextExtent_x                              0x904C60

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x695A30
#define CHtmlComponentWnd__ValidateUri_x                           0x7279A0
#define CHtmlWnd__SetClientCallbacks_x                             0x603160
#define CHtmlWnd__AddObserver_x                                    0x603180
#define CHtmlWnd__RemoveObserver_x                                 0x6031E0
#define Window__getProgress_x                                      0x8412D0
#define Window__getStatus_x                                        0x8412F0
#define Window__getURI_x                                           0x841300

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x942830

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F1A60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADCE0
#define CXStr__CXStr1_x                                            0x4EC240
#define CXStr__CXStr3_x                                            0x8DDF40
#define CXStr__dCXStr_x                                            0x472990
#define CXStr__operator_equal_x                                    0x8DE170
#define CXStr__operator_equal1_x                                   0x8DE1B0
#define CXStr__operator_plus_equal1_x                              0x8DEC40

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x926020
#define CXWnd__BringToTop_x                                        0x90B280
#define CXWnd__Center_x                                            0x90AE00
#define CXWnd__ClrFocus_x                                          0x90AC30
#define CXWnd__Destroy_x                                           0x90ACE0
#define CXWnd__DoAllDrawing_x                                      0x9073B0
#define CXWnd__DrawChildren_x                                      0x907380
#define CXWnd__DrawColoredRect_x                                   0x907800
#define CXWnd__DrawTooltip_x                                       0x905EE0
#define CXWnd__DrawTooltipAtPoint_x                                0x905FA0
#define CXWnd__GetBorderFrame_x                                    0x907660
#define CXWnd__GetChildWndAt_x                                     0x90B320
#define CXWnd__GetClientClipRect_x                                 0x9095F0
#define CXWnd__GetScreenClipRect_x                                 0x909690
#define CXWnd__GetScreenRect_x                                     0x909820
#define CXWnd__GetTooltipRect_x                                    0x907850
#define CXWnd__GetWindowTextA_x                                    0x497850
#define CXWnd__IsActive_x                                          0x90E160
#define CXWnd__IsDescendantOf_x                                    0x90A210
#define CXWnd__IsReallyVisible_x                                   0x90A240
#define CXWnd__IsType_x                                            0x90B970
#define CXWnd__Move_x                                              0x90A2A0
#define CXWnd__Move1_x                                             0x90A350
#define CXWnd__ProcessTransition_x                                 0x90ADB0
#define CXWnd__Refade_x                                            0x90A600
#define CXWnd__Resize_x                                            0x90A890
#define CXWnd__Right_x                                             0x90B040
#define CXWnd__SetFocus_x                                          0x90ABF0
#define CXWnd__SetFont_x                                           0x90AC60
#define CXWnd__SetKeyTooltip_x                                     0x90B790
#define CXWnd__SetMouseOver_x                                      0x908790
#define CXWnd__StartFade_x                                         0x90A0E0
#define CXWnd__GetChildItem_x                                      0x90B490
#define CXWnd__SetParent_x                                         0x909FB0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93DE00

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90E1A0
#define CXWndManager__DrawWindows_x                                0x90E1C0
#define CXWndManager__GetKeyboardFlags_x                           0x910920
#define CXWndManager__HandleKeyboardMsg_x                          0x910530
#define CXWndManager__RemoveWnd_x                                  0x910B70
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9110C0

// CDBStr
#define CDBStr__GetString_x                                        0x5257F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8A40
#define EQ_Character__Cur_HP_x                                     0x4CEBB0
#define EQ_Character__Cur_Mana_x                                   0x4D62C0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB950
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF8F0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFA40
#define EQ_Character__GetHPRegen_x                                 0x4DC2A0
#define EQ_Character__GetEnduranceRegen_x                          0x4DC8B0
#define EQ_Character__GetManaRegen_x                               0x4DCCF0
#define EQ_Character__Max_Endurance_x                              0x6289B0
#define EQ_Character__Max_HP_x                                     0x4CE9E0
#define EQ_Character__Max_Mana_x                                   0x6287B0
#define EQ_Character__doCombatAbility_x                            0x62AB60
#define EQ_Character__UseSkill_x                                   0x4DEB00
#define EQ_Character__GetConLevel_x                                0x622220
#define EQ_Character__IsExpansionFlag_x                            0x588FE0
#define EQ_Character__TotalEffect_x                                0x4C1FD0
#define EQ_Character__GetPCSpellAffect_x                           0x4BC540
#define EQ_Character__SpellDuration_x                              0x4BC070
#define EQ_Character__FindItemByRecord_x                           0x4D41C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D18F0
#define EQ_Character__GetBaseSkill_x                               0x4D2890
#define EQ_Character__CanUseItem_x                                 0x4D65D0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8AF890

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63EA30

//PcClient
#define PcClient__PcClient_x                                       0x61FB00

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6820
#define CCharacterListWnd__EnterWorld_x                            0x4B6260
#define CCharacterListWnd__Quit_x                                  0x4B5F70
#define CCharacterListWnd__UpdateList_x                            0x4B63F0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6043C0
#define EQ_Item__CreateItemTagString_x                             0x88A000
#define EQ_Item__IsStackable_x                                     0x88E900
#define EQ_Item__GetImageNum_x                                     0x88B910
#define EQ_Item__CreateItemClient_x                                0x603560
#define EQ_Item__GetItemValue_x                                    0x88CBA0
#define EQ_Item__ValueSellMerchant_x                               0x8900D0
#define EQ_Item__IsKeyRingItem_x                                   0x88E260
#define EQ_Item__CanGoInBag_x                                      0x6044E0
#define EQ_Item__GetMaxItemCount_x                                 0x88CF60
#define EQ_Item__GetHeldItem_x                                     0x88B7E0
#define EQ_Item__GetAugmentFitBySlot_x                             0x889960

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5439C0
#define EQ_LoadingS__Array_x                                       0xBE2798

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x629310
#define EQ_PC__GetAlternateAbilityId_x                             0x8992D0
#define EQ_PC__GetCombatAbility_x                                  0x899940
#define EQ_PC__GetCombatAbilityTimer_x                             0x8999B0
#define EQ_PC__GetItemRecastTimer_x                                0x62B0E0
#define EQ_PC__HasLoreItem_x                                       0x6229F0
#define EQ_PC__AlertInventoryChanged_x                             0x621D00
#define EQ_PC__GetPcZoneClient_x                                   0x64D190
#define EQ_PC__RemoveMyAffect_x                                    0x62E2D0
#define EQ_PC__GetKeyRingItems_x                                   0x89A250
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x899FD0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89A540

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58F540
#define EQItemList__add_object_x                                   0x5BAEA0
#define EQItemList__add_item_x                                     0x58FB50
#define EQItemList__delete_item_x                                  0x58FBA0
#define EQItemList__FreeItemList_x                                 0x58FAA0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x522DD0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6402B0
#define EQPlayer__dEQPlayer_x                                      0x6339B0
#define EQPlayer__DoAttack_x                                       0x647E70
#define EQPlayer__EQPlayer_x                                       0x634060
#define EQPlayer__SetNameSpriteState_x                             0x6382E0
#define EQPlayer__SetNameSpriteTint_x                              0x6391B0
#define PlayerBase__HasProperty_j_x                                0x970A40
#define EQPlayer__IsTargetable_x                                   0x970EE0
#define EQPlayer__CanSee_x                                         0x970D40
#define EQPlayer__CanSee1_x                                        0x970E10
#define PlayerBase__GetVisibilityLineSegment_x                     0x970B00

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64AC40
#define PlayerZoneClient__GetLevel_x                               0x64D1D0
#define PlayerZoneClient__IsValidTeleport_x                        0x5BBFF0
#define PlayerZoneClient__LegalPlayerRace_x                        0x53CF20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x642FB0
#define EQPlayerManager__GetSpawnByName_x                          0x642FD0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x643060

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x607C80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x607CC0
#define KeypressHandler__ClearCommandStateArray_x                  0x6090B0
#define KeypressHandler__HandleKeyDown_x                           0x6090D0
#define KeypressHandler__HandleKeyUp_x                             0x609170
#define KeypressHandler__SaveKeymapping_x                          0x609550

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75F330
#define MapViewMap__SaveEx_x                                       0x7626D0
#define MapViewMap__SetZoom_x                                      0x766D90

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8AD6D0

// StringTable 
#define StringTable__getString_x                                   0x8A8640

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62DF40
#define PcZoneClient__RemovePetEffect_x                            0x62E570
#define PcZoneClient__HasAlternateAbility_x                        0x6285F0
#define PcZoneClient__GetCurrentMod_x                              0x4E1C00
#define PcZoneClient__GetModCap_x                                  0x4E1B00
#define PcZoneClient__CanEquipItem_x                               0x628CA0
#define PcZoneClient__GetItemByID_x                                0x62B550
#define PcZoneClient__GetItemByItemClass_x                         0x62B6A0
#define PcZoneClient__RemoveBuffEffect_x                           0x62E590
#define PcZoneClient__BandolierSwap_x                              0x6298D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C0C70

//IconCache
#define IconCache__GetIcon_x                                       0x7002F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F7E10
#define CContainerMgr__CloseContainer_x                            0x6F80E0
#define CContainerMgr__OpenExperimentContainer_x                   0x6F8B60

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BA660

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FC590

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7557D0
#define CLootWnd__RequestLootSlot_x                                0x754B80

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55C0E0
#define EQ_Spell__SpellAffects_x                                   0x55C550
#define EQ_Spell__SpellAffectBase_x                                0x55C310
#define EQ_Spell__IsStackable_x                                    0x4C6780
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C65D0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3E20
#define EQ_Spell__IsSPAStacking_x                                  0x55D380
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55C8A0
#define EQ_Spell__IsNoRemove_x                                     0x4C6760
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55D390
#define __IsResEffectSpell_x                                       0x4C5B10

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA6A0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B7D50

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8000D0
#define CTargetWnd__WndNotification_x                              0x7FF960
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FFC30
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FEAC0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8047B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x557680
#define EqSoundManager__PlayScriptMp3_x                            0x5577E0
#define EqSoundManager__SoundAssistPlay_x                          0x665D50
#define EqSoundManager__WaveInstancePlay_x                         0x6652C0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x514710

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x929770

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54B760
#define CAltAbilityData__GetMercMaxRank_x                          0x54B700
#define CAltAbilityData__GetMaxRank_x                              0x540BD0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FA690

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C65B0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FAC90
#define CharacterBase__CreateItemIndex_x                           0x602770
#define CharacterBase__GetItemPossession_x                         0x4B3CD0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C03F0
#define CharacterBase__GetEffectId_x                               0x4C6560

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DFF40
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E0760

//messages
#define msg_spell_worn_off_x                                       0x5810E0
#define msg_new_text_x                                             0x576030
#define __msgTokenTextParam_x                                      0x583730
#define msgTokenText_x                                             0x583980

//SpellManager
#define SpellManager__vftable_x                                    0xAAB8A0
#define SpellManager__SpellManager_x                               0x669080
#define Spellmanager__LoadTextSpells_x                             0x669950
#define SpellManager__GetSpellByGroupAndRank_x                     0x669250

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x974A00

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FB370
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x587570
#define ItemGlobalIndex__IsEquippedLocation_x                      0x588FC0
#define ItemGlobalIndex__IsValidIndex_x                            0x4FB3D0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B8690
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B8910

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74E310

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FC550
#define CCursorAttachment__Deactivate_x                            0x6FD520

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93BD30
#define CEQSuiteTextureLoader__GetTexture_x                        0x93B9F0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F8340

//IString
#define IString__Append_x                                          0x4EB380

//Camera
#define CDisplay__cameraType_x                                     0xDB0C94
#define EverQuest__Cameras_x                                       0xE73F08

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x500B00
#define LootFiltersManager__GetItemFilterData_x                    0x5003F0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x500420
#define LootFiltersManager__SetItemLootFilter_x                    0x500640

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A8670

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97A810
#define CResolutionHandler__GetWindowedStyle_x                     0x660A50

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F4BD0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CACA0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x714DA0
#define CGroupWnd__UpdateDisplay_x                                 0x714110

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
