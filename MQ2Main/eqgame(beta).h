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
#define __ExpectedVersionDate                                     "Nov  3 2018"
#define __ExpectedVersionTime                                     "04:24:40"
#define __ActualVersionDate_x                                      0xAC7AAC
#define __ActualVersionTime_x                                      0xAC7AA0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60E0D0
#define __MemChecker1_x                                            0x8E22C0
#define __MemChecker2_x                                            0x69CD40
#define __MemChecker3_x                                            0x69CC90
#define __MemChecker4_x                                            0x8397F0
#define __EncryptPad0_x                                            0xBFA990
#define __EncryptPad1_x                                            0xC58C20
#define __EncryptPad2_x                                            0xC0B518
#define __EncryptPad3_x                                            0xC0B118
#define __EncryptPad4_x                                            0xC49490
#define __EncryptPad5_x                                            0xF14B24
#define __AC1_x                                                    0x7F6016
#define __AC2_x                                                    0x5C91DF
#define __AC3_x                                                    0x5D006F
#define __AC4_x                                                    0x5D3EF0
#define __AC5_x                                                    0x5DA0AF
#define __AC6_x                                                    0x5DE5E6
#define __AC7_x                                                    0x5C8C50
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
#define __do_loot_x                                                0x596B10
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
#define __gfMaxZoomCameraDistance_x                                0xABCED0
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
#define __CastRay_x                                                0x592030
#define __CastRay2_x                                               0x592080
#define __ConvertItemTags_x                                        0x5ACC30
#define __CrashHandler_x                                           0x8431D0
#define __EQGetTime_x                                              0x8E1DB0
#define __ExecuteCmd_x                                             0x58A9A0
#define __FixHeading_x                                             0x9728D0
#define __get_bearing_x                                            0x591B70
#define __get_melee_range_x                                        0x592270
#define __GetAnimationCache_x                                      0x700B40
#define __GetGaugeValueFromEQ_x                                    0x7F4830
#define __GetLabelFromEQ_x                                         0x7F5FA0
#define __GetXTargetType_x                                         0x9743A0
#define __HeadingDiff_x                                            0x972940
#define __HelpPath_x                                               0xF11C5C
#define __LoadFrontEnd_x                                           0x698BA0
#define __NewUIINI_x                                               0x7F4500
#define __pCrashHandler_x                                          0x1047AE0
#define __ProcessGameEvents_x                                      0x5EF660
#define __ProcessMouseEvent_x                                      0x5EEE20
#define __SaveColors_x                                             0x53B530
#define __STMLToText_x                                             0x915A10
#define __ToggleKeyRingItem_x                                      0x4FE630
#define CrashDetected_x                                            0x69A690
#define DrawNetStatus_x                                            0x61B4B0
#define Expansion_HoT_x                                            0xE73BCC
#define Teleport_Table_Size_x                                      0xE62CBC
#define Teleport_Table_x                                           0xE63410
#define Util__FastTime_x                                           0x8E1970
#define wwsCrashReportCheckForUploader_x                           0x843F80
#define wwsCrashReportPlatformLaunchUploader_x                     0x846660
#define __HandleMouseWheel_x                                       0x69CDF0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AF00
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493CF0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493AD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x542F10
#define AltAdvManager__IsAbilityReady_x                            0x541F90
#define AltAdvManager__GetAAById_x                                 0x542190
#define AltAdvManager__CanTrainAbility_x                           0x542200
#define AltAdvManager__CanSeeAbility_x                             0x542430

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6930
#define CharacterZoneClient__HasSkill_x                            0x4D15F0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2D10
#define CharacterZoneClient__IsStackBlocked_x                      0x4BAD80
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7500
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D56C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D57A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5880
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF860
#define CharacterZoneClient__BardCastBard_x                        0x4C24D0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B75D0
#define CharacterZoneClient__GetEffect_x                           0x4B7440
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0860
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0930
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0980
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0AD0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0CA0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C2FE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D0A00

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FDDF0
#define CButtonWnd__CButtonWnd_x                                   0x911E10

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EF530
#define CChatManager__InitContextMenu_x                            0x6E95D0
#define CChatManager__FreeChatWindow_x                             0x6EE440
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F2DE0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EF2D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9266E0
#define CContextMenu__dCContextMenu_x                              0x926910
#define CContextMenu__AddMenuItem_x                                0x926920
#define CContextMenu__RemoveMenuItem_x                             0x926C30
#define CContextMenu__RemoveAllMenuItems_x                         0x926C50
#define CContextMenu__CheckMenuItem_x                              0x926CD0
#define CContextMenu__SetMenuItem_x                                0x926B50
#define CContextMenu__AddSeparator_x                               0x926AB0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x927270
#define CContextMenuManager__RemoveMenu_x                          0x9272E0
#define CContextMenuManager__PopupMenu_x                           0x9273A0
#define CContextMenuManager__Flush_x                               0x927210
#define CContextMenuManager__GetMenu_x                             0x495D80

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C2870
#define CChatService__GetFriendName_x                              0x8C2880

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EFAA0
#define CChatWindow__Clear_x                                       0x6F0B00
#define CChatWindow__WndNotification_x                             0x6F1070

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x923B60
#define CComboWnd__Draw_x                                          0x923040
#define CComboWnd__GetCurChoice_x                                  0x9239A0
#define CComboWnd__GetListRect_x                                   0x923500
#define CComboWnd__GetTextRect_x                                   0x923BD0
#define CComboWnd__InsertChoice_x                                  0x923690
#define CComboWnd__SetColors_x                                     0x923660
#define CComboWnd__SetChoice_x                                     0x923970
#define CComboWnd__GetItemCount_x                                  0x9239B0
#define CComboWnd__GetCurChoiceText_x                              0x9239F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F8D10
#define CContainerWnd__vftable_x                                   0xAD0EB8
#define CContainerWnd__SetContainer_x                              0x6FA280

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53B2F0
#define CDisplay__GetClickedActor_x                                0x52E2F0
#define CDisplay__GetUserDefinedColor_x                            0x5269D0
#define CDisplay__GetWorldFilePath_x                               0x52FD40
#define CDisplay__is3dON_x                                         0x52AFC0
#define CDisplay__ReloadUI_x                                       0x535460
#define CDisplay__WriteTextHD2_x                                   0x52ADA0
#define CDisplay__TrueDistance_x                                   0x5319A0
#define CDisplay__SetViewActor_x                                   0x52DC40
#define CDisplay__GetFloorHeight_x                                 0x52B080
#define CDisplay__SetRenderWindow_x                                0x5299B0
#define CDisplay__ToggleScreenshotMode_x                           0x52D710

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x945CD0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92AE00
#define CEditWnd__GetCharIndexPt_x                                 0x92BD00
#define CEditWnd__GetDisplayString_x                               0x92BBA0
#define CEditWnd__GetHorzOffset_x                                  0x92A430
#define CEditWnd__GetLineForPrintableChar_x                        0x92CE40
#define CEditWnd__GetSelStartPt_x                                  0x92BFB0
#define CEditWnd__GetSTMLSafeText_x                                0x92B9C0
#define CEditWnd__PointFromPrintableChar_x                         0x92CA70
#define CEditWnd__SelectableCharFromPoint_x                        0x92CBE0
#define CEditWnd__SetEditable_x                                    0x92C080

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DDB10
#define CEverQuest__ClickedPlayer_x                                0x5CFE50
#define CEverQuest__CreateTargetIndicator_x                        0x5EC910
#define CEverQuest__DeleteTargetIndicator_x                        0x5EC9A0
#define CEverQuest__DoTellWindow_x                                 0x4E2A30
#define CEverQuest__OutputTextToLog_x                              0x4E2C60
#define CEverQuest__DropHeldItemOnGround_x                         0x5C5710
#define CEverQuest__dsp_chat_x                                     0x4E2FF0
#define CEverQuest__trimName_x                                     0x5E8E80
#define CEverQuest__Emote_x                                        0x5DE320
#define CEverQuest__EnterZone_x                                    0x5D8500
#define CEverQuest__GetBodyTypeDesc_x                              0x5E2720
#define CEverQuest__GetClassDesc_x                                 0x5E2D60
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E3360
#define CEverQuest__GetDeityDesc_x                                 0x5EB260
#define CEverQuest__GetLangDesc_x                                  0x5E3520
#define CEverQuest__GetRaceDesc_x                                  0x5E2D40
#define CEverQuest__InterpretCmd_x                                 0x5EB830
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C9900
#define CEverQuest__LMouseUp_x                                     0x5C7C80
#define CEverQuest__RightClickedOnPlayer_x                         0x5CA1E0
#define CEverQuest__RMouseUp_x                                     0x5C8C10
#define CEverQuest__SetGameState_x                                 0x5C54A0
#define CEverQuest__UPCNotificationFlush_x                         0x5E8D80
#define CEverQuest__IssuePetCommand_x                              0x5E4920
#define CEverQuest__ReportSuccessfulHit_x                          0x5DF600

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70ABB0
#define CGaugeWnd__CalcLinesFillRect_x                             0x70AC10
#define CGaugeWnd__Draw_x                                          0x70A2B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC480
#define CGuild__GetGuildName_x                                     0x4AB560
#define CGuild__GetGuildIndex_x                                    0x4AB8F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x725FA0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FE1B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x732FA0
#define CInvSlotMgr__MoveItem_x                                    0x731CC0
#define CInvSlotMgr__SelectSlot_x                                  0x733070

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x730570
#define CInvSlot__SliderComplete_x                                 0x72E2D0
#define CInvSlot__GetItemBase_x                                    0x72DC40
#define CInvSlot__UpdateItem_x                                     0x72DDB0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7349C0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x733C90
#define CInvSlotWnd__HandleLButtonUp_x                             0x734540

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F09D0
#define CItemDisplayWnd__UpdateStrings_x                           0x742AD0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73CB30
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73D060
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7430B0
#define CItemDisplayWnd__AboutToShow_x                             0x742710
#define CItemDisplayWnd__WndNotification_x                         0x7443D0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x828580

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x748500

// CLabel 
#define CLabel__Draw_x                                             0x74DFE0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FC2B0
#define CListWnd__dCListWnd_x                                      0x8FC5D0
#define CListWnd__AddColumn_x                                      0x900920
#define CListWnd__AddColumn1_x                                     0x900970
#define CListWnd__AddLine_x                                        0x900D00
#define CListWnd__AddString_x                                      0x900B00
#define CListWnd__CalculateFirstVisibleLine_x                      0x9006E0
#define CListWnd__CalculateVSBRange_x                              0x9004B0
#define CListWnd__ClearSel_x                                       0x9014E0
#define CListWnd__ClearAllSel_x                                    0x901540
#define CListWnd__CloseAndUpdateEditWindow_x                       0x901F50
#define CListWnd__Compare_x                                        0x8FFDF0
#define CListWnd__Draw_x                                           0x8FC6D0
#define CListWnd__DrawColumnSeparators_x                           0x8FEEC0
#define CListWnd__DrawHeader_x                                     0x8FF330
#define CListWnd__DrawItem_x                                       0x8FF730
#define CListWnd__DrawLine_x                                       0x8FF030
#define CListWnd__DrawSeparator_x                                  0x8FEF60
#define CListWnd__EnableLine_x                                     0x8FE790
#define CListWnd__EnsureVisible_x                                  0x901E70
#define CListWnd__ExtendSel_x                                      0x901410
#define CListWnd__GetColumnMinWidth_x                              0x8FE2D0
#define CListWnd__GetColumnWidth_x                                 0x8FE240
#define CListWnd__GetCurSel_x                                      0x8FDBD0
#define CListWnd__GetItemAtPoint_x                                 0x8FEA10
#define CListWnd__GetItemAtPoint1_x                                0x8FEA80
#define CListWnd__GetItemData_x                                    0x8FDC50
#define CListWnd__GetItemHeight_x                                  0x8FE010
#define CListWnd__GetItemIcon_x                                    0x8FDDE0
#define CListWnd__GetItemRect_x                                    0x8FE880
#define CListWnd__GetItemText_x                                    0x8FDC90
#define CListWnd__GetSelList_x                                     0x901590
#define CListWnd__GetSeparatorRect_x                               0x8FECC0
#define CListWnd__InsertLine_x                                     0x9010F0
#define CListWnd__RemoveLine_x                                     0x901240
#define CListWnd__SetColors_x                                      0x900480
#define CListWnd__SetColumnJustification_x                         0x9001B0
#define CListWnd__SetColumnWidth_x                                 0x9000D0
#define CListWnd__SetCurSel_x                                      0x901350
#define CListWnd__SetItemColor_x                                   0x901B20
#define CListWnd__SetItemData_x                                    0x901AE0
#define CListWnd__SetItemText_x                                    0x901710
#define CListWnd__ShiftColumnSeparator_x                           0x900270
#define CListWnd__Sort_x                                           0x8FFF70
#define CListWnd__ToggleSel_x                                      0x901380

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x763580
#define CMapViewWnd__GetWorldCoordinates_x                         0x761C90
#define CMapViewWnd__HandleLButtonDown_x                           0x75ECF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x786720
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x787000
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x787540
#define CMerchantWnd__SelectRecoverySlot_x                         0x78A380
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x785100
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x78FF20
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x786350

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x890690
#define CPacketScrambler__hton_x                                   0x890680

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91B030
#define CSidlManager__FindScreenPieceTemplate_x                    0x91B440
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91B230
#define CSidlManager__CreateLabel_x                                0x7E7E00
#define CSidlManager__CreateXWndFromTemplate_x                     0x91E510
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91E6F0
#define CSidlManager__CreateXWnd_x                                 0x7E7D30
#define CSidlManager__CreateHotButtonWnd_x                         0x7E82F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x917BA0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x917A90
#define CSidlScreenWnd__ConvertToRes_x                             0x93CB60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x917520
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x917210
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9172E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9173B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x918040
#define CSidlScreenWnd__EnableIniStorage_x                         0x918510
#define CSidlScreenWnd__GetSidlPiece_x                             0x918230
#define CSidlScreenWnd__Init1_x                                    0x916E00
#define CSidlScreenWnd__LoadIniInfo_x                              0x918560
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9190A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x916200
#define CSidlScreenWnd__StoreIniInfo_x                             0x918C10
#define CSidlScreenWnd__StoreIniVis_x                              0x918F80
#define CSidlScreenWnd__WndNotification_x                          0x917F50
#define CSidlScreenWnd__GetChildItem_x                             0x918490
#define CSidlScreenWnd__HandleLButtonUp_x                          0x907D80
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A2A50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x661F50
#define CSkillMgr__GetSkillCap_x                                   0x662130
#define CSkillMgr__GetNameToken_x                                  0x6616E0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x928080
#define CSliderWnd__SetValue_x                                     0x927EF0
#define CSliderWnd__SetNumTicks_x                                  0x927F50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7EDC00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x92ECF0
#define CStmlWnd__CalculateHSBRange_x                              0x92FD80
#define CStmlWnd__CalculateVSBRange_x                              0x92FCF0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9340C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x934CB0
#define CStmlWnd__ForceParseNow_x                                  0x92F290
#define CStmlWnd__GetNextTagPiece_x                                0x934020
#define CStmlWnd__GetSTMLText_x                                    0x4F0E60
#define CStmlWnd__GetVisibleText_x                                 0x92F2B0
#define CStmlWnd__InitializeWindowVariables_x                      0x934B00
#define CStmlWnd__MakeStmlColorTag_x                               0x92E480
#define CStmlWnd__MakeWndNotificationTag_x                         0x92E4F0
#define CStmlWnd__SetSTMLText_x                                    0x92D550
#define CStmlWnd__StripFirstSTMLLines_x                            0x935E10
#define CStmlWnd__UpdateHistoryString_x                            0x934EC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x939AA0
#define CTabWnd__DrawCurrentPage_x                                 0x93A0C0
#define CTabWnd__DrawTab_x                                         0x939E90
#define CTabWnd__GetCurrentPage_x                                  0x939300
#define CTabWnd__GetPageInnerRect_x                                0x939540
#define CTabWnd__GetTabInnerRect_x                                 0x939480
#define CTabWnd__GetTabRect_x                                      0x939330
#define CTabWnd__InsertPage_x                                      0x939730
#define CTabWnd__SetPage_x                                         0x9395C0
#define CTabWnd__SetPageRect_x                                     0x9399E0
#define CTabWnd__UpdatePage_x                                      0x939D50
#define CTabWnd__GetPageFromTabIndex_x                             0x939DD0
#define CTabWnd__GetCurrentTabIndex_x                              0x9392F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x748960
#define CPageWnd__SetTabText_x                                     0x9460E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5FA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x904BA0
#define CTextureFont__GetTextExtent_x                              0x904D60

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6959C0
#define CHtmlComponentWnd__ValidateUri_x                           0x727990
#define CHtmlWnd__SetClientCallbacks_x                             0x603180
#define CHtmlWnd__AddObserver_x                                    0x6031A0
#define CHtmlWnd__RemoveObserver_x                                 0x603200
#define Window__getProgress_x                                      0x840E30
#define Window__getStatus_x                                        0x840E50
#define Window__getURI_x                                           0x840E60

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x942660

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F1B50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD730
#define CXStr__CXStr1_x                                            0x9B4410
#define CXStr__CXStr3_x                                            0x8DDEE0
#define CXStr__dCXStr_x                                            0x472880
#define CXStr__operator_equal_x                                    0x8DE110
#define CXStr__operator_equal1_x                                   0x8DE150
#define CXStr__operator_plus_equal1_x                              0x8DEBE0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9262F0
#define CXWnd__BringToTop_x                                        0x90B450
#define CXWnd__Center_x                                            0x90AFD0
#define CXWnd__ClrFocus_x                                          0x90AE00
#define CXWnd__Destroy_x                                           0x90AEB0
#define CXWnd__DoAllDrawing_x                                      0x907500
#define CXWnd__DrawChildren_x                                      0x9074D0
#define CXWnd__DrawColoredRect_x                                   0x907970
#define CXWnd__DrawTooltip_x                                       0x906000
#define CXWnd__DrawTooltipAtPoint_x                                0x9060C0
#define CXWnd__GetBorderFrame_x                                    0x9077D0
#define CXWnd__GetChildWndAt_x                                     0x90B4F0
#define CXWnd__GetClientClipRect_x                                 0x9097B0
#define CXWnd__GetScreenClipRect_x                                 0x909880
#define CXWnd__GetScreenRect_x                                     0x909A20
#define CXWnd__GetTooltipRect_x                                    0x9079C0
#define CXWnd__GetWindowTextA_x                                    0x497400
#define CXWnd__IsActive_x                                          0x90E310
#define CXWnd__IsDescendantOf_x                                    0x90A3F0
#define CXWnd__IsReallyVisible_x                                   0x90A420
#define CXWnd__IsType_x                                            0x90BB60
#define CXWnd__Move_x                                              0x90A490
#define CXWnd__Move1_x                                             0x90A540
#define CXWnd__ProcessTransition_x                                 0x90AF80
#define CXWnd__Refade_x                                            0x90A7F0
#define CXWnd__Resize_x                                            0x90AA80
#define CXWnd__Right_x                                             0x90B210
#define CXWnd__SetFocus_x                                          0x90ADC0
#define CXWnd__SetFont_x                                           0x90AE30
#define CXWnd__SetKeyTooltip_x                                     0x90B980
#define CXWnd__SetMouseOver_x                                      0x908920
#define CXWnd__StartFade_x                                         0x90A2C0
#define CXWnd__GetChildItem_x                                      0x90B660
#define CXWnd__SetParent_x                                         0x90A180

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93DC30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90E350
#define CXWndManager__DrawWindows_x                                0x90E370
#define CXWndManager__GetKeyboardFlags_x                           0x910AE0
#define CXWndManager__HandleKeyboardMsg_x                          0x9106E0
#define CXWndManager__RemoveWnd_x                                  0x910D30
#define CXWndManager__RemovePendingDeletionWnd_x                   0x911280

// CDBStr
#define CDBStr__GetString_x                                        0x525980

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B84B0
#define EQ_Character__Cur_HP_x                                     0x4CE670
#define EQ_Character__Cur_Mana_x                                   0x4D5D80
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB3C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF330
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF480
#define EQ_Character__GetHPRegen_x                                 0x4DBD60
#define EQ_Character__GetEnduranceRegen_x                          0x4DC370
#define EQ_Character__GetManaRegen_x                               0x4DC7B0
#define EQ_Character__Max_Endurance_x                              0x628B20
#define EQ_Character__Max_HP_x                                     0x4CE4A0
#define EQ_Character__Max_Mana_x                                   0x628920
#define EQ_Character__doCombatAbility_x                            0x62ACD0
#define EQ_Character__UseSkill_x                                   0x4DE5C0
#define EQ_Character__GetConLevel_x                                0x622190
#define EQ_Character__IsExpansionFlag_x                            0x589030
#define EQ_Character__TotalEffect_x                                0x4C1A50
#define EQ_Character__GetPCSpellAffect_x                           0x4BBFB0
#define EQ_Character__SpellDuration_x                              0x4BBAE0
#define EQ_Character__FindItemByRecord_x                           0x4D3C80
#define EQ_Character__GetAdjustedSkill_x                           0x4D13B0
#define EQ_Character__GetBaseSkill_x                               0x4D2350
#define EQ_Character__CanUseItem_x                                 0x4D6090

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8AF740

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63EB20

//PcClient
#define PcClient__PcClient_x                                       0x61FA70

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6290
#define CCharacterListWnd__EnterWorld_x                            0x4B5CD0
#define CCharacterListWnd__Quit_x                                  0x4B59E0
#define CCharacterListWnd__UpdateList_x                            0x4B5E60

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6043B0
#define EQ_Item__CreateItemTagString_x                             0x88A1A0
#define EQ_Item__IsStackable_x                                     0x88EA90
#define EQ_Item__GetImageNum_x                                     0x88BAC0
#define EQ_Item__CreateItemClient_x                                0x603560
#define EQ_Item__GetItemValue_x                                    0x88CD20
#define EQ_Item__ValueSellMerchant_x                               0x890230
#define EQ_Item__IsKeyRingItem_x                                   0x88E3F0
#define EQ_Item__CanGoInBag_x                                      0x6044D0
#define EQ_Item__GetMaxItemCount_x                                 0x88D0E0
#define EQ_Item__GetHeldItem_x                                     0x88B990
#define EQ_Item__GetAugmentFitBySlot_x                             0x889AF0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x543BF0
#define EQ_LoadingS__Array_x                                       0xBE2798

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x629480
#define EQ_PC__GetAlternateAbilityId_x                             0x8993F0
#define EQ_PC__GetCombatAbility_x                                  0x899A60
#define EQ_PC__GetCombatAbilityTimer_x                             0x899AD0
#define EQ_PC__GetItemRecastTimer_x                                0x62B250
#define EQ_PC__HasLoreItem_x                                       0x6229B0
#define EQ_PC__AlertInventoryChanged_x                             0x621C70
#define EQ_PC__GetPcZoneClient_x                                   0x64D330
#define EQ_PC__RemoveMyAffect_x                                    0x62E440
#define EQ_PC__GetKeyRingItems_x                                   0x89A370
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89A0F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89A660

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58F5B0
#define EQItemList__add_object_x                                   0x5BAF20
#define EQItemList__add_item_x                                     0x58FBC0
#define EQItemList__delete_item_x                                  0x58FC10
#define EQItemList__FreeItemList_x                                 0x58FB10

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x522FE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6403A0
#define EQPlayer__dEQPlayer_x                                      0x633AA0
#define EQPlayer__DoAttack_x                                       0x648010
#define EQPlayer__EQPlayer_x                                       0x634150
#define EQPlayer__SetNameSpriteState_x                             0x6383D0
#define EQPlayer__SetNameSpriteTint_x                              0x6392A0
#define PlayerBase__HasProperty_j_x                                0x970C60
#define EQPlayer__IsTargetable_x                                   0x971100
#define EQPlayer__CanSee_x                                         0x970F60
#define EQPlayer__CanSee1_x                                        0x971030
#define PlayerBase__GetVisibilityLineSegment_x                     0x970D20

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64ADE0
#define PlayerZoneClient__GetLevel_x                               0x64D370
#define PlayerZoneClient__IsValidTeleport_x                        0x5BC070
#define PlayerZoneClient__LegalPlayerRace_x                        0x53D0D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x643130
#define EQPlayerManager__GetSpawnByName_x                          0x643150
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6431E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x607D30
#define KeypressHandler__AttachKeyToEqCommand_x                    0x607D70
#define KeypressHandler__ClearCommandStateArray_x                  0x609160
#define KeypressHandler__HandleKeyDown_x                           0x609180
#define KeypressHandler__HandleKeyUp_x                             0x609220
#define KeypressHandler__SaveKeymapping_x                          0x609600

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75F410
#define MapViewMap__SaveEx_x                                       0x7627B0
#define MapViewMap__SetZoom_x                                      0x766E80

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8AD630

// StringTable 
#define StringTable__getString_x                                   0x8A85C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62E0B0
#define PcZoneClient__RemovePetEffect_x                            0x62E6E0
#define PcZoneClient__HasAlternateAbility_x                        0x628760
#define PcZoneClient__GetCurrentMod_x                              0x4E16C0
#define PcZoneClient__GetModCap_x                                  0x4E15C0
#define PcZoneClient__CanEquipItem_x                               0x628E10
#define PcZoneClient__GetItemByID_x                                0x62B6C0
#define PcZoneClient__GetItemByItemClass_x                         0x62B810
#define PcZoneClient__RemoveBuffEffect_x                           0x62E700
#define PcZoneClient__BandolierSwap_x                              0x629A40

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C0BF0

//IconCache
#define IconCache__GetIcon_x                                       0x7003D0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F7EB0
#define CContainerMgr__CloseContainer_x                            0x6F8180
#define CContainerMgr__OpenExperimentContainer_x                   0x6F8C00

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BA590

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FC5D0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7557F0
#define CLootWnd__RequestLootSlot_x                                0x754BA0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55C290
#define EQ_Spell__SpellAffects_x                                   0x55C700
#define EQ_Spell__SpellAffectBase_x                                0x55C4C0
#define EQ_Spell__IsStackable_x                                    0x4C6260
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C60E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3860
#define EQ_Spell__IsSPAStacking_x                                  0x55D530
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55CA50
#define EQ_Spell__IsNoRemove_x                                     0x4C6240
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55D540
#define __IsResEffectSpell_x                                       0x4C55B0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA180

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B7CB0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FFDB0
#define CTargetWnd__WndNotification_x                              0x7FF640
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FF910
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FE7A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x804480

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x557830
#define EqSoundManager__PlayScriptMp3_x                            0x557990
#define EqSoundManager__SoundAssistPlay_x                          0x665E00
#define EqSoundManager__WaveInstancePlay_x                         0x665370

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x514840

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x929A60

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54B910
#define CAltAbilityData__GetMercMaxRank_x                          0x54B8B0
#define CAltAbilityData__GetMaxRank_x                              0x540E40

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FA6E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C60C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FAB30
#define CharacterBase__CreateItemIndex_x                           0x6027C0
#define CharacterBase__GetItemPossession_x                         0x4B3710
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C0350
#define CharacterBase__GetEffectId_x                               0x4C6070

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E0080
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E08A0

//messages
#define msg_spell_worn_off_x                                       0x5810C0
#define msg_new_text_x                                             0x576000
#define __msgTokenTextParam_x                                      0x583710
#define msgTokenText_x                                             0x583960

//SpellManager
#define SpellManager__vftable_x                                    0xAAB890
#define SpellManager__SpellManager_x                               0x669130
#define Spellmanager__LoadTextSpells_x                             0x669A00
#define SpellManager__GetSpellByGroupAndRank_x                     0x669300

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x974C90

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FB1E0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x587570
#define ItemGlobalIndex__IsEquippedLocation_x                      0x589010
#define ItemGlobalIndex__IsValidIndex_x                            0x4FB240

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B85F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B8870

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74E330

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FC620
#define CCursorAttachment__Deactivate_x                            0x6FD600

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93BF10
#define CEQSuiteTextureLoader__GetTexture_x                        0x93BBD0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F81B0

//IString
#define IString__Append_x                                          0x4EAEA0

//Camera
#define CDisplay__cameraType_x                                     0xDB0C94
#define EverQuest__Cameras_x                                       0xE73F08

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5008B0
#define LootFiltersManager__GetItemFilterData_x                    0x5001A0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5001D0
#define LootFiltersManager__SetItemLootFilter_x                    0x5003F0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A85C0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97A9C0
#define CResolutionHandler__GetWindowedStyle_x                     0x660910

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F4C70

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CAC60

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x714D20
#define CGroupWnd__UpdateDisplay_x                                 0x714080

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
