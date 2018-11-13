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
#define __ExpectedVersionDate                                     "Nov  8 2018"
#define __ExpectedVersionTime                                     "04:21:21"
#define __ActualVersionDate_x                                      0xAC7AA4
#define __ActualVersionTime_x                                      0xAC7A98

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60DC60
#define __MemChecker1_x                                            0x8E22A0
#define __MemChecker2_x                                            0x69CEB0
#define __MemChecker3_x                                            0x69CE00
#define __MemChecker4_x                                            0x839750
#define __EncryptPad0_x                                            0xBFA990
#define __EncryptPad1_x                                            0xC58C20
#define __EncryptPad2_x                                            0xC0B518
#define __EncryptPad3_x                                            0xC0B118
#define __EncryptPad4_x                                            0xC49490
#define __EncryptPad5_x                                            0xF14B24
#define __AC1_x                                                    0x7F6226
#define __AC2_x                                                    0x5C8CDF
#define __AC3_x                                                    0x5CFB6F
#define __AC4_x                                                    0x5D39F0
#define __AC5_x                                                    0x5D9BAF
#define __AC6_x                                                    0x5DE0E6
#define __AC7_x                                                    0x5C8750
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
#define __do_loot_x                                                0x596470
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
#define __ServerHost_x                                             0xE62E7B
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
#define __gfMaxZoomCameraDistance_x                                0xABCED8
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
#define pinstCDisplay_x                                            0xE631D0
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
#define pinstTargetObject_x                                        0xE62F84
#define pinstTargetSwitch_x                                        0xE631F4
#define pinstTaskMember_x                                          0xDB08B4
#define pinstTrackTarget_x                                         0xE62D78
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
#define __CastRay_x                                                0x591990
#define __CastRay2_x                                               0x5919E0
#define __ConvertItemTags_x                                        0x5AC590
#define __CrashHandler_x                                           0x843100
#define __EQGetTime_x                                              0x8E1D90
#define __ExecuteCmd_x                                             0x58A2E0
#define __FixHeading_x                                             0x972890
#define __get_bearing_x                                            0x5914D0
#define __get_melee_range_x                                        0x591BD0
#define __GetAnimationCache_x                                      0x700D10
#define __GetGaugeValueFromEQ_x                                    0x7F4A40
#define __GetLabelFromEQ_x                                         0x7F61B0
#define __GetXTargetType_x                                         0x974360
#define __HeadingDiff_x                                            0x972900
#define __HelpPath_x                                               0xF11C5C
#define __LoadFrontEnd_x                                           0x698D10
#define __NewUIINI_x                                               0x7F4710
#define __pCrashHandler_x                                          0x1047AE0
#define __ProcessGameEvents_x                                      0x5EF1A0
#define __ProcessMouseEvent_x                                      0x5EE960
#define __SaveColors_x                                             0x53B190
#define __STMLToText_x                                             0x915C10
#define __ToggleKeyRingItem_x                                      0x4FE5D0
#define CrashDetected_x                                            0x69A800
#define DrawNetStatus_x                                            0x61B300
#define Expansion_HoT_x                                            0xE73BCC
#define Teleport_Table_Size_x                                      0xE62CBC
#define Teleport_Table_x                                           0xE63410
#define Util__FastTime_x                                           0x8E1950
#define wwsCrashReportCheckForUploader_x                           0x843FB0
#define wwsCrashReportPlatformLaunchUploader_x                     0x846670
#define __HandleMouseWheel_x                                       0x69CF60

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AFD0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493DD0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493BB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x542A20
#define AltAdvManager__IsAbilityReady_x                            0x541AA0
#define AltAdvManager__GetAAById_x                                 0x541CA0
#define AltAdvManager__CanTrainAbility_x                           0x541D10
#define AltAdvManager__CanSeeAbility_x                             0x541F40

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6950
#define CharacterZoneClient__HasSkill_x                            0x4D1610
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2D30
#define CharacterZoneClient__IsStackBlocked_x                      0x4BAD10
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7490
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D56A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5780
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5860
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF7F0
#define CharacterZoneClient__BardCastBard_x                        0x4C2460
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7560
#define CharacterZoneClient__GetEffect_x                           0x4B73D0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C07F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C08C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0910
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0A60
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0C30

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C32E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D0B20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FD980
#define CButtonWnd__CButtonWnd_x                                   0x912010

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EF700
#define CChatManager__InitContextMenu_x                            0x6E97A0
#define CChatManager__FreeChatWindow_x                             0x6EE610
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F2FC0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EF4A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x926820
#define CContextMenu__dCContextMenu_x                              0x926A50
#define CContextMenu__AddMenuItem_x                                0x926A60
#define CContextMenu__RemoveMenuItem_x                             0x926D70
#define CContextMenu__RemoveAllMenuItems_x                         0x926D90
#define CContextMenu__CheckMenuItem_x                              0x926E10
#define CContextMenu__SetMenuItem_x                                0x926C90
#define CContextMenu__AddSeparator_x                               0x926BF0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9273A0
#define CContextMenuManager__RemoveMenu_x                          0x927410
#define CContextMenuManager__PopupMenu_x                           0x9274D0
#define CContextMenuManager__Flush_x                               0x927340
#define CContextMenuManager__GetMenu_x                             0x495FC0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C26E0
#define CChatService__GetFriendName_x                              0x8C26F0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EFC80
#define CChatWindow__Clear_x                                       0x6F0CE0
#define CChatWindow__WndNotification_x                             0x6F1250

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x923CA0
#define CComboWnd__Draw_x                                          0x9231B0
#define CComboWnd__GetCurChoice_x                                  0x923AE0
#define CComboWnd__GetListRect_x                                   0x923650
#define CComboWnd__GetTextRect_x                                   0x923D10
#define CComboWnd__InsertChoice_x                                  0x9237E0
#define CComboWnd__SetColors_x                                     0x9237B0
#define CComboWnd__SetChoice_x                                     0x923AB0
#define CComboWnd__GetItemCount_x                                  0x923AF0
#define CComboWnd__GetCurChoiceText_x                              0x923B30

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F8EF0
#define CContainerWnd__vftable_x                                   0xAD0EA8
#define CContainerWnd__SetContainer_x                              0x6FA460

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53AF50
#define CDisplay__GetClickedActor_x                                0x52DF50
#define CDisplay__GetUserDefinedColor_x                            0x526630
#define CDisplay__GetWorldFilePath_x                               0x52F9A0
#define CDisplay__is3dON_x                                         0x52AC20
#define CDisplay__ReloadUI_x                                       0x5350C0
#define CDisplay__WriteTextHD2_x                                   0x52AA00
#define CDisplay__TrueDistance_x                                   0x531600
#define CDisplay__SetViewActor_x                                   0x52D8A0
#define CDisplay__GetFloorHeight_x                                 0x52ACE0
#define CDisplay__SetRenderWindow_x                                0x529610
#define CDisplay__ToggleScreenshotMode_x                           0x52D370

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x945F60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92AF00
#define CEditWnd__GetCharIndexPt_x                                 0x92BE00
#define CEditWnd__GetDisplayString_x                               0x92BCA0
#define CEditWnd__GetHorzOffset_x                                  0x92A540
#define CEditWnd__GetLineForPrintableChar_x                        0x92CF40
#define CEditWnd__GetSelStartPt_x                                  0x92C0B0
#define CEditWnd__GetSTMLSafeText_x                                0x92BAC0
#define CEditWnd__PointFromPrintableChar_x                         0x92CB70
#define CEditWnd__SelectableCharFromPoint_x                        0x92CCE0
#define CEditWnd__SetEditable_x                                    0x92C180

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DD610
#define CEverQuest__ClickedPlayer_x                                0x5CF950
#define CEverQuest__CreateTargetIndicator_x                        0x5EC450
#define CEverQuest__DeleteTargetIndicator_x                        0x5EC4E0
#define CEverQuest__DoTellWindow_x                                 0x4E28F0
#define CEverQuest__OutputTextToLog_x                              0x4E2B20
#define CEverQuest__DropHeldItemOnGround_x                         0x5C5210
#define CEverQuest__dsp_chat_x                                     0x4E2EB0
#define CEverQuest__trimName_x                                     0x5E89C0
#define CEverQuest__Emote_x                                        0x5DDE20
#define CEverQuest__EnterZone_x                                    0x5D8000
#define CEverQuest__GetBodyTypeDesc_x                              0x5E2260
#define CEverQuest__GetClassDesc_x                                 0x5E28A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E2EA0
#define CEverQuest__GetDeityDesc_x                                 0x5EADA0
#define CEverQuest__GetLangDesc_x                                  0x5E3060
#define CEverQuest__GetRaceDesc_x                                  0x5E2880
#define CEverQuest__InterpretCmd_x                                 0x5EB370
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C9400
#define CEverQuest__LMouseUp_x                                     0x5C7780
#define CEverQuest__RightClickedOnPlayer_x                         0x5C9CE0
#define CEverQuest__RMouseUp_x                                     0x5C8710
#define CEverQuest__SetGameState_x                                 0x5C4FA0
#define CEverQuest__UPCNotificationFlush_x                         0x5E88C0
#define CEverQuest__IssuePetCommand_x                              0x5E4460
#define CEverQuest__ReportSuccessfulHit_x                          0x5DF140

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70AE60
#define CGaugeWnd__CalcLinesFillRect_x                             0x70AEC0
#define CGaugeWnd__Draw_x                                          0x70A550

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC3C0
#define CGuild__GetGuildName_x                                     0x4AB4A0
#define CGuild__GetGuildIndex_x                                    0x4AB830

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x726270

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FDD40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x733240
#define CInvSlotMgr__MoveItem_x                                    0x731F60
#define CInvSlotMgr__SelectSlot_x                                  0x733310

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x730810
#define CInvSlot__SliderComplete_x                                 0x72E590
#define CInvSlot__GetItemBase_x                                    0x72DF00
#define CInvSlot__UpdateItem_x                                     0x72E070

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x734C60
#define CInvSlotWnd__CInvSlotWnd_x                                 0x733F30
#define CInvSlotWnd__HandleLButtonUp_x                             0x7347E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F0BF0
#define CItemDisplayWnd__UpdateStrings_x                           0x742CB0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73CD80
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73D290
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x743290
#define CItemDisplayWnd__AboutToShow_x                             0x742900
#define CItemDisplayWnd__WndNotification_x                         0x7447E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8285F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x748880

// CLabel 
#define CLabel__Draw_x                                             0x74E320

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FC1A0
#define CListWnd__dCListWnd_x                                      0x8FC4C0
#define CListWnd__AddColumn_x                                      0x9007F0
#define CListWnd__AddColumn1_x                                     0x900840
#define CListWnd__AddLine_x                                        0x900BD0
#define CListWnd__AddString_x                                      0x9009D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9005B0
#define CListWnd__CalculateVSBRange_x                              0x900380
#define CListWnd__ClearSel_x                                       0x9013B0
#define CListWnd__ClearAllSel_x                                    0x901410
#define CListWnd__CloseAndUpdateEditWindow_x                       0x901E20
#define CListWnd__Compare_x                                        0x8FFCD0
#define CListWnd__Draw_x                                           0x8FC5C0
#define CListWnd__DrawColumnSeparators_x                           0x8FEDA0
#define CListWnd__DrawHeader_x                                     0x8FF210
#define CListWnd__DrawItem_x                                       0x8FF610
#define CListWnd__DrawLine_x                                       0x8FEF10
#define CListWnd__DrawSeparator_x                                  0x8FEE40
#define CListWnd__EnableLine_x                                     0x8FE670
#define CListWnd__EnsureVisible_x                                  0x901D40
#define CListWnd__ExtendSel_x                                      0x9012E0
#define CListWnd__GetColumnMinWidth_x                              0x8FE1B0
#define CListWnd__GetColumnWidth_x                                 0x8FE120
#define CListWnd__GetCurSel_x                                      0x8FDAB0
#define CListWnd__GetItemAtPoint_x                                 0x8FE8F0
#define CListWnd__GetItemAtPoint1_x                                0x8FE960
#define CListWnd__GetItemData_x                                    0x8FDB30
#define CListWnd__GetItemHeight_x                                  0x8FDEF0
#define CListWnd__GetItemIcon_x                                    0x8FDCC0
#define CListWnd__GetItemRect_x                                    0x8FE760
#define CListWnd__GetItemText_x                                    0x8FDB70
#define CListWnd__GetSelList_x                                     0x901460
#define CListWnd__GetSeparatorRect_x                               0x8FEBA0
#define CListWnd__InsertLine_x                                     0x900FC0
#define CListWnd__RemoveLine_x                                     0x901110
#define CListWnd__SetColors_x                                      0x900360
#define CListWnd__SetColumnJustification_x                         0x900090
#define CListWnd__SetColumnWidth_x                                 0x8FFFB0
#define CListWnd__SetCurSel_x                                      0x901220
#define CListWnd__SetItemColor_x                                   0x9019F0
#define CListWnd__SetItemData_x                                    0x9019B0
#define CListWnd__SetItemText_x                                    0x9015E0
#define CListWnd__ShiftColumnSeparator_x                           0x900150
#define CListWnd__Sort_x                                           0x8FFE50
#define CListWnd__ToggleSel_x                                      0x901250

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x763890
#define CMapViewWnd__GetWorldCoordinates_x                         0x761FA0
#define CMapViewWnd__HandleLButtonDown_x                           0x75F000

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x786A30
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x787310
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x787840
#define CMerchantWnd__SelectRecoverySlot_x                         0x78A670
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x785420
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x790200
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x786670

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x890590
#define CPacketScrambler__hton_x                                   0x890580

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91B220
#define CSidlManager__FindScreenPieceTemplate_x                    0x91B630
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91B420
#define CSidlManager__CreateLabel_x                                0x7E8020
#define CSidlManager__CreateXWndFromTemplate_x                     0x91E700
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91E8E0
#define CSidlManager__CreateXWnd_x                                 0x7E7F50
#define CSidlManager__CreateHotButtonWnd_x                         0x7E8520

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x917D90
#define CSidlScreenWnd__CalculateVSBRange_x                        0x917C80
#define CSidlScreenWnd__ConvertToRes_x                             0x93CD50
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x917710
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x917400
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9174D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9175A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x918230
#define CSidlScreenWnd__EnableIniStorage_x                         0x918700
#define CSidlScreenWnd__GetSidlPiece_x                             0x918420
#define CSidlScreenWnd__Init1_x                                    0x916FF0
#define CSidlScreenWnd__LoadIniInfo_x                              0x918750
#define CSidlScreenWnd__LoadIniListWnd_x                           0x919290
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9163F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x918E10
#define CSidlScreenWnd__StoreIniVis_x                              0x919170
#define CSidlScreenWnd__WndNotification_x                          0x918140
#define CSidlScreenWnd__GetChildItem_x                             0x918680
#define CSidlScreenWnd__HandleLButtonUp_x                          0x907D80
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A2A50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x661E90
#define CSkillMgr__GetSkillCap_x                                   0x662070
#define CSkillMgr__GetNameToken_x                                  0x661620

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x928190
#define CSliderWnd__SetValue_x                                     0x928000
#define CSliderWnd__SetNumTicks_x                                  0x928060

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EDE50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x92EDE0
#define CStmlWnd__CalculateHSBRange_x                              0x92FE70
#define CStmlWnd__CalculateVSBRange_x                              0x92FDE0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9341B0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x934DA0
#define CStmlWnd__ForceParseNow_x                                  0x92F380
#define CStmlWnd__GetNextTagPiece_x                                0x934110
#define CStmlWnd__GetSTMLText_x                                    0x4F0C70
#define CStmlWnd__GetVisibleText_x                                 0x92F3A0
#define CStmlWnd__InitializeWindowVariables_x                      0x934BF0
#define CStmlWnd__MakeStmlColorTag_x                               0x92E570
#define CStmlWnd__MakeWndNotificationTag_x                         0x92E5E0
#define CStmlWnd__SetSTMLText_x                                    0x92D640
#define CStmlWnd__StripFirstSTMLLines_x                            0x935F00
#define CStmlWnd__UpdateHistoryString_x                            0x934FB0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x939BD0
#define CTabWnd__DrawCurrentPage_x                                 0x93A1F0
#define CTabWnd__DrawTab_x                                         0x939FC0
#define CTabWnd__GetCurrentPage_x                                  0x939430
#define CTabWnd__GetPageInnerRect_x                                0x939670
#define CTabWnd__GetTabInnerRect_x                                 0x9395B0
#define CTabWnd__GetTabRect_x                                      0x939460
#define CTabWnd__InsertPage_x                                      0x939860
#define CTabWnd__SetPage_x                                         0x9396F0
#define CTabWnd__SetPageRect_x                                     0x939B10
#define CTabWnd__UpdatePage_x                                      0x939E80
#define CTabWnd__GetPageFromTabIndex_x                             0x939F00
#define CTabWnd__GetCurrentTabIndex_x                              0x939420

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x748D00
#define CPageWnd__SetTabText_x                                     0x946370

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5F10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x904BC0
#define CTextureFont__GetTextExtent_x                              0x904D80

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x695B40
#define CHtmlComponentWnd__ValidateUri_x                           0x727C60
#define CHtmlWnd__SetClientCallbacks_x                             0x602CE0
#define CHtmlWnd__AddObserver_x                                    0x602D00
#define CHtmlWnd__RemoveObserver_x                                 0x602D60
#define Window__getProgress_x                                      0x840D70
#define Window__getStatus_x                                        0x840D90
#define Window__getURI_x                                           0x840DA0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9428A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F1A40

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD730
#define CXStr__CXStr1_x                                            0x47B810
#define CXStr__CXStr3_x                                            0x8DDE80
#define CXStr__dCXStr_x                                            0x472950
#define CXStr__operator_equal_x                                    0x8DE0B0
#define CXStr__operator_equal1_x                                   0x8DE0F0
#define CXStr__operator_plus_equal1_x                              0x8DEB80

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x926430
#define CXWnd__BringToTop_x                                        0x90B560
#define CXWnd__Center_x                                            0x90B0E0
#define CXWnd__ClrFocus_x                                          0x90AF20
#define CXWnd__Destroy_x                                           0x90AFC0
#define CXWnd__DoAllDrawing_x                                      0x907510
#define CXWnd__DrawChildren_x                                      0x9074E0
#define CXWnd__DrawColoredRect_x                                   0x907970
#define CXWnd__DrawTooltip_x                                       0x906030
#define CXWnd__DrawTooltipAtPoint_x                                0x9060F0
#define CXWnd__GetBorderFrame_x                                    0x9077D0
#define CXWnd__GetChildWndAt_x                                     0x90B600
#define CXWnd__GetClientClipRect_x                                 0x9097E0
#define CXWnd__GetScreenClipRect_x                                 0x9098B0
#define CXWnd__GetScreenRect_x                                     0x909A50
#define CXWnd__GetTooltipRect_x                                    0x9079C0
#define CXWnd__GetWindowTextA_x                                    0x497650
#define CXWnd__IsActive_x                                          0x90E540
#define CXWnd__IsDescendantOf_x                                    0x90A470
#define CXWnd__IsReallyVisible_x                                   0x90A4A0
#define CXWnd__IsType_x                                            0x90BC80
#define CXWnd__Move_x                                              0x90A510
#define CXWnd__Move1_x                                             0x90A5D0
#define CXWnd__ProcessTransition_x                                 0x90B090
#define CXWnd__Refade_x                                            0x90A8A0
#define CXWnd__Resize_x                                            0x90AB40
#define CXWnd__Right_x                                             0x90B320
#define CXWnd__SetFocus_x                                          0x90AEE0
#define CXWnd__SetFont_x                                           0x90AF50
#define CXWnd__SetKeyTooltip_x                                     0x90BA90
#define CXWnd__SetMouseOver_x                                      0x908960
#define CXWnd__StartFade_x                                         0x90A350
#define CXWnd__GetChildItem_x                                      0x90B770
#define CXWnd__SetParent_x                                         0x90A210

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93DE20

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90E580
#define CXWndManager__DrawWindows_x                                0x90E5A0
#define CXWndManager__GetKeyboardFlags_x                           0x910D10
#define CXWndManager__HandleKeyboardMsg_x                          0x910910
#define CXWndManager__RemoveWnd_x                                  0x910F50
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9114A0

// CDBStr
#define CDBStr__GetString_x                                        0x5255F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8440
#define EQ_Character__Cur_HP_x                                     0x4CE690
#define EQ_Character__Cur_Mana_x                                   0x4D5D60
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB350
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF300
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF450
#define EQ_Character__GetHPRegen_x                                 0x4DBD00
#define EQ_Character__GetEnduranceRegen_x                          0x4DC310
#define EQ_Character__GetManaRegen_x                               0x4DC750
#define EQ_Character__Max_Endurance_x                              0x628D60
#define EQ_Character__Max_HP_x                                     0x4CE4C0
#define EQ_Character__Max_Mana_x                                   0x628B60
#define EQ_Character__doCombatAbility_x                            0x62AFD0
#define EQ_Character__UseSkill_x                                   0x4DE540
#define EQ_Character__GetConLevel_x                                0x621FD0
#define EQ_Character__IsExpansionFlag_x                            0x588990
#define EQ_Character__TotalEffect_x                                0x4C19E0
#define EQ_Character__GetPCSpellAffect_x                           0x4BBF40
#define EQ_Character__SpellDuration_x                              0x4BBA70
#define EQ_Character__FindItemByRecord_x                           0x4D3CA0
#define EQ_Character__GetAdjustedSkill_x                           0x4D13D0
#define EQ_Character__GetBaseSkill_x                               0x4D2370
#define EQ_Character__CanUseItem_x                                 0x4D6070

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8AF720

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63EE30

//PcClient
#define PcClient__PcClient_x                                       0x61F8A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6220
#define CCharacterListWnd__EnterWorld_x                            0x4B5C60
#define CCharacterListWnd__Quit_x                                  0x4B5970
#define CCharacterListWnd__UpdateList_x                            0x4B5DF0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x603F30
#define EQ_Item__CreateItemTagString_x                             0x88A040
#define EQ_Item__IsStackable_x                                     0x88E930
#define EQ_Item__GetImageNum_x                                     0x88B920
#define EQ_Item__CreateItemClient_x                                0x6030E0
#define EQ_Item__GetItemValue_x                                    0x88CB80
#define EQ_Item__ValueSellMerchant_x                               0x890120
#define EQ_Item__IsKeyRingItem_x                                   0x88E280
#define EQ_Item__CanGoInBag_x                                      0x604050
#define EQ_Item__GetMaxItemCount_x                                 0x88CF50
#define EQ_Item__GetHeldItem_x                                     0x88B7F0
#define EQ_Item__GetAugmentFitBySlot_x                             0x889980

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x543700
#define EQ_LoadingS__Array_x                                       0xBE2798

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6296C0
#define EQ_PC__GetAlternateAbilityId_x                             0x899320
#define EQ_PC__GetCombatAbility_x                                  0x899990
#define EQ_PC__GetCombatAbilityTimer_x                             0x899A00
#define EQ_PC__GetItemRecastTimer_x                                0x62B550
#define EQ_PC__HasLoreItem_x                                       0x6227A0
#define EQ_PC__AlertInventoryChanged_x                             0x621AA0
#define EQ_PC__GetPcZoneClient_x                                   0x64D570
#define EQ_PC__RemoveMyAffect_x                                    0x62E750
#define EQ_PC__GetKeyRingItems_x                                   0x89A2A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89A020
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89A590

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58EEF0
#define EQItemList__add_object_x                                   0x5BA870
#define EQItemList__add_item_x                                     0x58F500
#define EQItemList__delete_item_x                                  0x58F550
#define EQItemList__FreeItemList_x                                 0x58F450

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x522C50

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6406B0
#define EQPlayer__dEQPlayer_x                                      0x633DC0
#define EQPlayer__DoAttack_x                                       0x648270
#define EQPlayer__EQPlayer_x                                       0x634470
#define EQPlayer__SetNameSpriteState_x                             0x6386E0
#define EQPlayer__SetNameSpriteTint_x                              0x6395B0
#define PlayerBase__HasProperty_j_x                                0x970C70
#define EQPlayer__IsTargetable_x                                   0x971110
#define EQPlayer__CanSee_x                                         0x970F70
#define EQPlayer__CanSee1_x                                        0x971040
#define PlayerBase__GetVisibilityLineSegment_x                     0x970D30

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64B040
#define PlayerZoneClient__GetLevel_x                               0x64D5B0
#define PlayerZoneClient__IsValidTeleport_x                        0x5BB9C0
#define PlayerZoneClient__LegalPlayerRace_x                        0x53CCD0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6433B0
#define EQPlayerManager__GetSpawnByName_x                          0x6433D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x643460

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x607870
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6078B0
#define KeypressHandler__ClearCommandStateArray_x                  0x608CA0
#define KeypressHandler__HandleKeyDown_x                           0x608CC0
#define KeypressHandler__HandleKeyUp_x                             0x608D60
#define KeypressHandler__SaveKeymapping_x                          0x609140

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75F720
#define MapViewMap__SaveEx_x                                       0x762AC0
#define MapViewMap__SetZoom_x                                      0x767190

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8AD610

// StringTable 
#define StringTable__getString_x                                   0x8A85A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62E3C0
#define PcZoneClient__RemovePetEffect_x                            0x62E9F0
#define PcZoneClient__HasAlternateAbility_x                        0x6289A0
#define PcZoneClient__GetCurrentMod_x                              0x4E1640
#define PcZoneClient__GetModCap_x                                  0x4E1540
#define PcZoneClient__CanEquipItem_x                               0x629050
#define PcZoneClient__GetItemByID_x                                0x62B9D0
#define PcZoneClient__GetItemByItemClass_x                         0x62BB20
#define PcZoneClient__RemoveBuffEffect_x                           0x62EA10
#define PcZoneClient__BandolierSwap_x                              0x629C80

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C0670

//IconCache
#define IconCache__GetIcon_x                                       0x7005A0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F8090
#define CContainerMgr__CloseContainer_x                            0x6F8360
#define CContainerMgr__OpenExperimentContainer_x                   0x6F8DE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BA800

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FC170

//CLootWnd
#define CLootWnd__LootAll_x                                        0x755B10
#define CLootWnd__RequestLootSlot_x                                0x754ED0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55BC40
#define EQ_Spell__SpellAffects_x                                   0x55C0B0
#define EQ_Spell__SpellAffectBase_x                                0x55BE70
#define EQ_Spell__IsStackable_x                                    0x4C6280
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C60A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3850
#define EQ_Spell__IsSPAStacking_x                                  0x55CEE0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55C400
#define EQ_Spell__IsNoRemove_x                                     0x4C6260
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55CEF0
#define __IsResEffectSpell_x                                       0x4C5540

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA0E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B7BA0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FFFE0
#define CTargetWnd__WndNotification_x                              0x7FF870
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FFB40
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FE9D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8046B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5571C0
#define EqSoundManager__PlayScriptMp3_x                            0x557320
#define EqSoundManager__SoundAssistPlay_x                          0x665D00
#define EqSoundManager__WaveInstancePlay_x                         0x665270

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x514540

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x929B70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54B4A0
#define CAltAbilityData__GetMercMaxRank_x                          0x54B440
#define CAltAbilityData__GetMaxRank_x                              0x540950

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FA270

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6080
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FA9C0
#define CharacterBase__CreateItemIndex_x                           0x602320
#define CharacterBase__GetItemPossession_x                         0x4B3700
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C0210
#define CharacterBase__GetEffectId_x                               0x4C6030

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E0280
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E0AA0

//messages
#define msg_spell_worn_off_x                                       0x580A50
#define msg_new_text_x                                             0x5759E0
#define __msgTokenTextParam_x                                      0x5830A0
#define msgTokenText_x                                             0x5832F0

//SpellManager
#define SpellManager__vftable_x                                    0xAAB8A0
#define SpellManager__SpellManager_x                               0x669020
#define Spellmanager__LoadTextSpells_x                             0x6698F0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6691F0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x974C50

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FB070
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x586F30
#define ItemGlobalIndex__IsEquippedLocation_x                      0x588970
#define ItemGlobalIndex__IsValidIndex_x                            0x4FB0D0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B84E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B8760

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74E660

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FC7F0
#define CCursorAttachment__Deactivate_x                            0x6FD7D0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93C120
#define CEQSuiteTextureLoader__GetTexture_x                        0x93BDE0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F8040

//IString
#define IString__Append_x                                          0x4EAD30

//Camera
#define CDisplay__cameraType_x                                     0xDB0C94
#define EverQuest__Cameras_x                                       0xE73F08

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x500840
#define LootFiltersManager__GetItemFilterData_x                    0x500140
#define LootFiltersManager__RemoveItemLootFilter_x                 0x500170
#define LootFiltersManager__SetItemLootFilter_x                    0x500390

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A8800

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97A9B0
#define CResolutionHandler__GetWindowedStyle_x                     0x6607B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F4E50

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CAB60

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x715000
#define CGroupWnd__UpdateDisplay_x                                 0x714360

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
