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
#define __ExpectedVersionDate                                     "Nov 16 2018"
#define __ExpectedVersionTime                                     "08:10:44"
#define __ActualVersionDate_x                                      0xACAEAC
#define __ActualVersionTime_x                                      0xACAEA0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x611360
#define __MemChecker1_x                                            0x8E5BE0
#define __MemChecker2_x                                            0x6A05B0
#define __MemChecker3_x                                            0x6A0500
#define __MemChecker4_x                                            0x83D160
#define __EncryptPad0_x                                            0xBFF340
#define __EncryptPad1_x                                            0xC5D5D0
#define __EncryptPad2_x                                            0xC0FEC8
#define __EncryptPad3_x                                            0xC0FAC8
#define __EncryptPad4_x                                            0xC4DE40
#define __EncryptPad5_x                                            0xF23B34
#define __AC1_x                                                    0x7F9AD6
#define __AC2_x                                                    0x5CC35F
#define __AC3_x                                                    0x5D31EF
#define __AC4_x                                                    0x5D7010
#define __AC5_x                                                    0x5DD1CF
#define __AC6_x                                                    0x5E1706
#define __AC7_x                                                    0x5CBDD0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19BB48

// Direct Input
#define DI8__Main_x                                                0xF23B58
#define DI8__Keyboard_x                                            0xF23B5C
#define DI8__Mouse_x                                               0xF23B20
#define DI8__Mouse_Copy_x                                          0xE8187C
#define DI8__Mouse_Check_x                                         0xF24A20
#define __AutoSkillArray_x                                         0xE82794
#define __Attack_x                                                 0xF2059B
#define __Autofire_x                                               0xF2059C
#define __BindList_x                                               0xBEDF20
#define g_eqCommandStates_x                                        0xBEEC90
#define __Clicks_x                                                 0xE81934
#define __CommandList_x                                            0xBEF848
#define __CurrentMapLabel_x                                        0x1036144
#define __CurrentSocial_x                                          0xBD8BF8
#define __DoAbilityList_x                                          0xEB80BC
#define __do_loot_x                                                0x599BF0
#define __DrawHandler_x                                            0x16B2B18
#define __GroupCount_x                                             0xE7222A
#define __Guilds_x                                                 0xE78088
#define __gWorld_x                                                 0xE7220C
#define __HWnd_x                                                   0xF23B24
#define __heqmain_x                                                0x102ED7C
#define __InChatMode_x                                             0xE81864
#define __LastTell_x                                               0xE837B8
#define __LMouseHeldTime_x                                         0xE819A0
#define __Mouse_x                                                  0xF23B40
#define __MouseLook_x                                              0xE818FA
#define __MouseEventTime_x                                         0xF21050
#define __gpbCommandEvent_x                                        0xE71CA8
#define __NetStatusToggle_x                                        0xE818FD
#define __PCNames_x                                                0xE82D74
#define __RangeAttackReady_x                                       0xE82A78
#define __RMouseHeldTime_x                                         0xE8199C
#define __RunWalkState_x                                           0xE81868
#define __ScreenMode_x                                             0xDBFC24
#define __ScreenX_x                                                0xE8181C
#define __ScreenY_x                                                0xE81818
#define __ScreenXMax_x                                             0xE81820
#define __ScreenYMax_x                                             0xE81824
#define __ServerHost_x                                             0xE71EDB
#define __ServerName_x                                             0xEB807C
#define __ShiftKeyDown_x                                           0xE81EF4
#define __ShowNames_x                                              0xE82C34
#define __Socials_x                                                0xEB817C
#define __SubscriptionType_x                                       0x1077C94
#define __TargetAggroHolder_x                                      0x1038B00
#define __ZoneType_x                                               0xE81CF8
#define __GroupAggro_x                                             0x1038B40
#define __LoginName_x                                              0xF243B4
#define __Inviter_x                                                0xF20518
#define __AttackOnAssist_x                                         0xE82BF0
#define __UseTellWindows_x                                         0xE82F0C
#define __gfMaxZoomCameraDistance_x                                0xAC03C0
#define __gfMaxCameraDistance_x                                    0xAED8D4
#define __pulAutoRun_x                                             0xE81918
#define __pulForward_x                                             0xE82F44
#define __pulBackward_x                                            0xE82F48
#define __pulTurnRight_x                                           0xE82F4C
#define __pulTurnLeft_x                                            0xE82F50
#define __pulStrafeLeft_x                                          0xE82F54
#define __pulStrafeRight_x                                         0xE82F58
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE74420
#define instEQZoneInfo_x                                           0xE81AF0
#define instKeypressHandler_x                                      0xF21000
#define pinstActiveBanker_x                                        0xE71D88
#define pinstActiveCorpse_x                                        0xE71D80
#define pinstActiveGMaster_x                                       0xE71D84
#define pinstActiveMerchant_x                                      0xE71D7C
#define pinstAggroInfo_x                                           0xC7E378
#define pinstAltAdvManager_x                                       0xDC0DC8
#define pinstAuraMgr_x                                             0xC8F060
#define pinstBandageTarget_x                                       0xE71D98
#define pinstCamActor_x                                            0xDBFC18
#define pinstCDBStr_x                                              0xDBFAFC
#define pinstCDisplay_x                                            0xE721EC
#define pinstCEverQuest_x                                          0xF23C78
#define pinstEverQuestInfo_x                                       0xE81810
#define pinstCharData_x                                            0xE721F8
#define pinstCharSpawn_x                                           0xE71DD0
#define pinstControlledMissile_x                                   0xE721F4
#define pinstControlledPlayer_x                                    0xE71DD0
#define pinstCResolutionHandler_x                                  0x16B2D48
#define pinstCSidlManager_x                                        0x16B1BDC
#define pinstCXWndManager_x                                        0x16B1BD0
#define instDynamicZone_x                                          0xE77F60
#define pinstDZMember_x                                            0xE78070
#define pinstDZTimerInfo_x                                         0xE78074
#define pinstEQItemList_x                                          0xE70610
#define pinstEQObjectList_x                                        0xE71800
#define instEQMisc_x                                               0xDBFA38
#define pinstEQSoundManager_x                                      0xDC1628
#define pinstEQSpellStrings_x                                      0xC8C4B0
#define instExpeditionLeader_x                                     0xE77FAA
#define instExpeditionName_x                                       0xE77FEA
#define pinstGroup_x                                               0xE72226
#define pinstImeManager_x                                          0x16B1BD4
#define pinstLocalPlayer_x                                         0xE71D78
#define pinstMercenaryData_x                                       0xF217FC
#define pinstMercenaryStats_x                                      0x1038C4C
#define pinstMercAltAbilities_x                                    0xDC1398
#define pinstModelPlayer_x                                         0xE71D90
#define pinstPCData_x                                              0xE721F8
#define pinstRealEstateItems_x                                     0xF22CE0
#define pinstSkillMgr_x                                            0xF22DB0
#define pinstSpawnManager_x                                        0xF223A0
#define pinstSpellManager_x                                        0xF22F88
#define pinstSpellSets_x                                           0xF191C4
#define pinstStringTable_x                                         0xE71B2C
#define pinstSwitchManager_x                                       0xE719C0
#define pinstTarget_x                                              0xE71DCC
#define pinstTargetObject_x                                        0xE71FE4
#define pinstTargetSwitch_x                                        0xE72204
#define pinstTaskMember_x                                          0xDBF8CC
#define pinstTrackTarget_x                                         0xE71DD8
#define pinstTradeTarget_x                                         0xE71D8C
#define instTributeActive_x                                        0xDBFA5D
#define pinstViewActor_x                                           0xDBFC14
#define pinstWorldData_x                                           0xE721FC
#define pinstZoneAddr_x                                            0xE81D90
#define pinstPlayerPath_x                                          0xF22438
#define pinstTargetIndicator_x                                     0xF231F0
#define pinstCTargetManager_x                                      0xF23288
#define EQObject_Top_x                                             0xE71D74

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC0418
#define pinstCAchievementsWnd_x                                    0xDBFC70
#define pinstCActionsWnd_x                                         0xDBFBD0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC03D4
#define pinstCAdvancedLootWnd_x                                    0xDBFF04
#define pinstCAdventureLeaderboardWnd_x                            0x102F918
#define pinstCAdventureRequestWnd_x                                0x102F9C8
#define pinstCAdventureStatsWnd_x                                  0x102FA78
#define pinstCAggroMeterWnd_x                                      0xDBFC60
#define pinstCAlarmWnd_x                                           0xDBFBEC
#define pinstCAlertHistoryWnd_x                                    0xDBFC38
#define pinstCAlertStackWnd_x                                      0xDBFBB0
#define pinstCAlertWnd_x                                           0xDBFBBC
#define pinstCAltStorageWnd_x                                      0x102FDD8
#define pinstCAudioTriggersWindow_x                                0xC7E808
#define pinstCAuraWnd_x                                            0xDBFC5C
#define pinstCAvaZoneWnd_x                                         0xDBFC3C
#define pinstCBandolierWnd_x                                       0xDBFCA0
#define pinstCBankWnd_x                                            0xDBFF28
#define pinstCBarterMerchantWnd_x                                  0x1031018
#define pinstCBarterSearchWnd_x                                    0x10310C8
#define pinstCBarterWnd_x                                          0x1031178
#define pinstCBazaarConfirmationWnd_x                              0xDBFBA8
#define pinstCBazaarSearchWnd_x                                    0xDBFBE4
#define pinstCBazaarWnd_x                                          0xDBFC9C
#define pinstCBlockedBuffWnd_x                                     0xDBFF08
#define pinstCBlockedPetBuffWnd_x                                  0xDBFF34
#define pinstCBodyTintWnd_x                                        0xDC0420
#define pinstCBookWnd_x                                            0xDBFCC4
#define pinstCBreathWnd_x                                          0xDC0428
#define pinstCBuffWindowNORMAL_x                                   0xDBFEE4
#define pinstCBuffWindowSHORT_x                                    0xDBFEE8
#define pinstCBugReportWnd_x                                       0xDC0414
#define pinstCButtonWnd_x                                          0x16B1E00
#define pinstCCastingWnd_x                                         0xDC040C
#define pinstCCastSpellWnd_x                                       0xDBFBF0
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC042C
#define pinstCChatWindowManager_x                                  0x1031C38
#define pinstCClaimWnd_x                                           0x1031D90
#define pinstCColorPickerWnd_x                                     0xDBFBAC
#define pinstCCombatAbilityWnd_x                                   0xDBFC6C
#define pinstCCombatSkillsSelectWnd_x                              0xDBFBC8
#define pinstCCompassWnd_x                                         0xDC0408
#define pinstCConfirmationDialog_x                                 0x1036C90
#define pinstCContainerMgr_x                                       0xDBFC84
#define pinstCContextMenuManager_x                                 0x16B1B90
#define pinstCCursorAttachment_x                                   0xDC03E0
#define pinstCDistillerInfo_x                                      0x103569C
#define pinstCDynamicZoneWnd_x                                     0x1032358
#define pinstCEditLabelWnd_x                                       0xDBFCD4
#define pinstCEQMainWnd_x                                          0x10325A0
#define pinstCEventCalendarWnd_x                                   0xDBFCD0
#define pinstCExtendedTargetWnd_x                                  0xDBFC4C
#define pinstCFacePick_x                                           0xDBFBA4
#define pinstCFellowshipWnd_x                                      0x10327A0
#define pinstCFileSelectionWnd_x                                   0xDBFEF4
#define pinstCFindItemWnd_x                                        0xDBFCB0
#define pinstCFindLocationWnd_x                                    0x10328F8
#define pinstCFriendsWnd_x                                         0xDBFBE0
#define pinstCGemsGameWnd_x                                        0xDBFBC0
#define pinstCGiveWnd_x                                            0xDBFCC0
#define pinstCGroupSearchFiltersWnd_x                              0xDBFC7C
#define pinstCGroupSearchWnd_x                                     0x1032CF0
#define pinstCGroupWnd_x                                           0x1032DA0
#define pinstCGuildBankWnd_x                                       0xE82BD4
#define pinstCGuildCreationWnd_x                                   0x1032F00
#define pinstCGuildMgmtWnd_x                                       0x1032FB0
#define pinstCharacterCreation_x                                   0xDBFC68
#define pinstCHelpWnd_x                                            0xDBFC04
#define pinstCHeritageSelectionWnd_x                               0xDBFBB8
#define pinstCHotButtonWnd_x                                       0x1035108
#define pinstCHotButtonWnd1_x                                      0x1035108
#define pinstCHotButtonWnd2_x                                      0x103510C
#define pinstCHotButtonWnd3_x                                      0x1035110
#define pinstCHotButtonWnd4_x                                      0x1035114
#define pinstCIconSelectionWnd_x                                   0xDBFFB8
#define pinstCInspectWnd_x                                         0xDBFF44
#define pinstCInventoryWnd_x                                       0xDBFCA4
#define pinstCInvSlotMgr_x                                         0xDBFC34
#define pinstCItemDisplayManager_x                                 0x1035698
#define pinstCItemExpTransferWnd_x                                 0x10357C8
#define pinstCItemOverflowWnd_x                                    0xDBFBE8
#define pinstCJournalCatWnd_x                                      0xDBFF20
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDBFCC8
#define pinstCKeyRingWnd_x                                         0xDBFEFC
#define pinstCLargeDialogWnd_x                                     0x1037910
#define pinstCLayoutCopyWnd_x                                      0x1035B18
#define pinstCLFGuildWnd_x                                         0x1035BC8
#define pinstCLoadskinWnd_x                                        0xDBFBCC
#define pinstCLootFiltersCopyWnd_x                                 0xC8F990
#define pinstCLootFiltersWnd_x                                     0xDBFBDC
#define pinstCLootSettingsWnd_x                                    0xDBFBF4
#define pinstCLootWnd_x                                            0xDBFB9C
#define pinstCMailAddressBookWnd_x                                 0xDBFF4C
#define pinstCMailCompositionWnd_x                                 0xDBFF14
#define pinstCMailIgnoreListWnd_x                                  0xDBFFB4
#define pinstCMailWnd_x                                            0xDBFEF0
#define pinstCManageLootWnd_x                                      0xDC1240
#define pinstCMapToolbarWnd_x                                      0xDBFCA8
#define pinstCMapViewWnd_x                                         0xDBFC88
#define pinstCMarketplaceWnd_x                                     0xDBFEE0
#define pinstCMerchantWnd_x                                        0xDBFBC4
#define pinstCMIZoneSelectWnd_x                                    0x1036400
#define pinstCMusicPlayerWnd_x                                     0xDBFEF8
#define pinstCNameChangeMercWnd_x                                  0xDC0424
#define pinstCNameChangePetWnd_x                                   0xDC0400
#define pinstCNameChangeWnd_x                                      0xDBFCB8
#define pinstCNoteWnd_x                                            0xDBFC00
#define pinstCObjectPreviewWnd_x                                   0xDBFF18
#define pinstCOptionsWnd_x                                         0xDBFCAC
#define pinstCPetInfoWnd_x                                         0xDBFF1C
#define pinstCPetitionQWnd_x                                       0xDBFF2C
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC041C
#define pinstCPlayerWnd_x                                          0xDBFBD8
#define pinstCPopupWndManager_x                                    0x1036C90
#define pinstCProgressionSelectionWnd_x                            0x1036D40
#define pinstCPurchaseGroupWnd_x                                   0xDC03C0
#define pinstCPurchaseWnd_x                                        0xDBFF24
#define pinstCPvPLeaderboardWnd_x                                  0x1036DF0
#define pinstCPvPStatsWnd_x                                        0x1036EA0
#define pinstCQuantityWnd_x                                        0xDC03CC
#define pinstCRaceChangeWnd_x                                      0xDBFEEC
#define pinstCRaidOptionsWnd_x                                     0xDBFC80
#define pinstCRaidWnd_x                                            0xDC03D0
#define pinstCRealEstateItemsWnd_x                                 0xDBFC8C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDBFCCC
#define pinstCRealEstateManageWnd_x                                0xDBFBF8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDBFC08
#define pinstCRealEstatePlotSearchWnd_x                            0xDBFC40
#define pinstCRealEstatePurchaseWnd_x                              0xDBFC54
#define pinstCRespawnWnd_x                                         0xDBFC78
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDBFC50
#define pinstCSendMoneyWnd_x                                       0xDBFCDC
#define pinstCServerListWnd_x                                      0xDBFC30
#define pinstCSkillsSelectWnd_x                                    0xDBFBB4
#define pinstCSkillsWnd_x                                          0xDBFB98
#define pinstCSocialEditWnd_x                                      0xDC03D8
#define pinstCSocialWnd_x                                          0xDBFBA0
#define pinstCSpellBookWnd_x                                       0xDBFC48
#define pinstCStoryWnd_x                                           0xDC03DC
#define pinstCTargetOfTargetWnd_x                                  0x1038CD0
#define pinstCTargetWnd_x                                          0xDBFF10
#define pinstCTaskOverlayWnd_x                                     0xDBFC44
#define pinstCTaskSelectWnd_x                                      0x1038E28
#define pinstCTaskSomething_x                                      0xC90190
#define pinstCTaskTemplateSelectWnd_x                              0x1038ED8
#define pinstCTaskWnd_x                                            0x1038F88
#define pinstCTextEntryWnd_x                                       0xDC0410
#define pinstCTextOverlay_x                                        0xC7EB18
#define pinstCTimeLeftWnd_x                                        0xDBFF00
#define pinstCTipWndCONTEXT_x                                      0x103918C
#define pinstCTipWndOFDAY_x                                        0x1039188
#define pinstCTitleWnd_x                                           0x1039238
#define pinstCTrackingWnd_x                                        0xDBFF0C
#define pinstCTradeskillWnd_x                                      0x10393A0
#define pinstCTradeWnd_x                                           0xDBFC10
#define pinstCTrainWnd_x                                           0xDC03C4
#define pinstCTributeBenefitWnd_x                                  0x10395A0
#define pinstCTributeMasterWnd_x                                   0x1039650
#define pinstCTributeTrophyWnd_x                                   0x1039700
#define pinstCVideoModesWnd_x                                      0xDBFC74
#define pinstCVoiceMacroWnd_x                                      0xF237B8
#define pinstCVoteResultsWnd_x                                     0xDC03C8
#define pinstCVoteWnd_x                                            0xDBFF30
#define pinstCWebManager_x                                         0xF2391C
#define pinstCZoneGuideWnd_x                                       0xDBFBFC
#define pinstCZonePathWnd_x                                        0xDBFC0C

#define pinstEQSuiteTextureLoader_x                                0xC5F0A0
#define pinstItemIconCache_x                                       0x1032558
#define pinstLootFiltersManager_x                                  0xC8FA40
#define pinstRewardSelectionWnd_x                                  0x10375E8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0FABC
#define __CastRay_x                                                0x595110
#define __CastRay2_x                                               0x595160
#define __ConvertItemTags_x                                        0x5AFD10
#define __CrashHandler_x                                           0x846AC0
#define __EQGetTime_x                                              0x8E56D0
#define __ExecuteCmd_x                                             0x58DAB0
#define __FixHeading_x                                             0x975DF0
#define __get_bearing_x                                            0x594C60
#define __get_melee_range_x                                        0x595350
#define __GetAnimationCache_x                                      0x703E20
#define __GetGaugeValueFromEQ_x                                    0x7F82F0
#define __GetLabelFromEQ_x                                         0x7F9A60
#define __GetXTargetType_x                                         0x977930
#define __HeadingDiff_x                                            0x975E60
#define __HelpPath_x                                               0xF20C6C
#define __LoadFrontEnd_x                                           0x69C410
#define __NewUIINI_x                                               0x7F7FC0
#define __pCrashHandler_x                                          0x1056AF0
#define __ProcessGameEvents_x                                      0x5F2930
#define __ProcessMouseEvent_x                                      0x5F20F0
#define __SaveColors_x                                             0x53E360
#define __STMLToText_x                                             0x919360
#define __ToggleKeyRingItem_x                                      0x501570
#define CrashDetected_x                                            0x69DF00
#define DrawNetStatus_x                                            0x61E810
#define Expansion_HoT_x                                            0xE82BDC
#define Teleport_Table_Size_x                                      0xE71D34
#define Teleport_Table_x                                           0xE72420
#define Util__FastTime_x                                           0x8E5120
#define wwsCrashReportCheckForUploader_x                           0x847870
#define wwsCrashReportPlatformLaunchUploader_x                     0x849F30
#define __HandleMouseWheel_x                                       0x6A0660

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48D8E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x496730
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4964F0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x545C50
#define AltAdvManager__IsAbilityReady_x                            0x544CD0
#define AltAdvManager__GetAAById_x                                 0x544ED0
#define AltAdvManager__CanTrainAbility_x                           0x544F40
#define AltAdvManager__CanSeeAbility_x                             0x545170

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C96E0
#define CharacterZoneClient__HasSkill_x                            0x4D43A0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D5AC0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BDAB0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA220
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8490
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8570
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8650
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2590
#define CharacterZoneClient__BardCastBard_x                        0x4C5200
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA2F0
#define CharacterZoneClient__GetEffect_x                           0x4BA160
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3590
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3660
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C36B0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3800
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C39D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C6490

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D3C80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x601010
#define CButtonWnd__CButtonWnd_x                                   0x915750

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F2870
#define CChatManager__InitContextMenu_x                            0x6EC910
#define CChatManager__FreeChatWindow_x                             0x6F1780
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F6120
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F2610

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x929FC0
#define CContextMenu__dCContextMenu_x                              0x92A1F0
#define CContextMenu__AddMenuItem_x                                0x92A200
#define CContextMenu__RemoveMenuItem_x                             0x92A500
#define CContextMenu__RemoveAllMenuItems_x                         0x92A520
#define CContextMenu__CheckMenuItem_x                              0x92A5A0
#define CContextMenu__SetMenuItem_x                                0x92A430
#define CContextMenu__AddSeparator_x                               0x92A390

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92AB40
#define CContextMenuManager__RemoveMenu_x                          0x92ABB0
#define CContextMenuManager__PopupMenu_x                           0x92AC70
#define CContextMenuManager__Flush_x                               0x92AAE0
#define CContextMenuManager__GetMenu_x                             0x498990

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C6020
#define CChatService__GetFriendName_x                              0x8C6030

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F2DE0
#define CChatWindow__Clear_x                                       0x6F3E30
#define CChatWindow__WndNotification_x                             0x6F43A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x927460
#define CComboWnd__Draw_x                                          0x926960
#define CComboWnd__GetCurChoice_x                                  0x9272A0
#define CComboWnd__GetListRect_x                                   0x926E10
#define CComboWnd__GetTextRect_x                                   0x9274C0
#define CComboWnd__InsertChoice_x                                  0x926FA0
#define CComboWnd__SetColors_x                                     0x926F70
#define CComboWnd__SetChoice_x                                     0x927270
#define CComboWnd__GetItemCount_x                                  0x9272B0
#define CComboWnd__GetCurChoiceText_x                              0x9272F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6FC010
#define CContainerWnd__vftable_x                                   0xAD4220
#define CContainerWnd__SetContainer_x                              0x6FD580

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53E120
#define CDisplay__GetClickedActor_x                                0x5310E0
#define CDisplay__GetUserDefinedColor_x                            0x5297C0
#define CDisplay__GetWorldFilePath_x                               0x532B30
#define CDisplay__is3dON_x                                         0x52DDB0
#define CDisplay__ReloadUI_x                                       0x538250
#define CDisplay__WriteTextHD2_x                                   0x52DB90
#define CDisplay__TrueDistance_x                                   0x534790
#define CDisplay__SetViewActor_x                                   0x530A30
#define CDisplay__GetFloorHeight_x                                 0x52DE70
#define CDisplay__SetRenderWindow_x                                0x52C7A0
#define CDisplay__ToggleScreenshotMode_x                           0x530500

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9494A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92E6B0
#define CEditWnd__GetCharIndexPt_x                                 0x92F5A0
#define CEditWnd__GetDisplayString_x                               0x92F440
#define CEditWnd__GetHorzOffset_x                                  0x92DCE0
#define CEditWnd__GetLineForPrintableChar_x                        0x9306D0
#define CEditWnd__GetSelStartPt_x                                  0x92F840
#define CEditWnd__GetSTMLSafeText_x                                0x92F260
#define CEditWnd__PointFromPrintableChar_x                         0x930300
#define CEditWnd__SelectableCharFromPoint_x                        0x930470
#define CEditWnd__SetEditable_x                                    0x92F910

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E0C30
#define CEverQuest__ClickedPlayer_x                                0x5D2FD0
#define CEverQuest__CreateTargetIndicator_x                        0x5EFBE0
#define CEverQuest__DeleteTargetIndicator_x                        0x5EFC70
#define CEverQuest__DoTellWindow_x                                 0x4E5590
#define CEverQuest__OutputTextToLog_x                              0x4E57C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C8890
#define CEverQuest__dsp_chat_x                                     0x4E5B50
#define CEverQuest__trimName_x                                     0x5EC150
#define CEverQuest__Emote_x                                        0x5E1440
#define CEverQuest__EnterZone_x                                    0x5DB620
#define CEverQuest__GetBodyTypeDesc_x                              0x5E59F0
#define CEverQuest__GetClassDesc_x                                 0x5E6030
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E6630
#define CEverQuest__GetDeityDesc_x                                 0x5EE530
#define CEverQuest__GetLangDesc_x                                  0x5E67F0
#define CEverQuest__GetRaceDesc_x                                  0x5E6010
#define CEverQuest__InterpretCmd_x                                 0x5EEB00
#define CEverQuest__LeftClickedOnPlayer_x                          0x5CCA80
#define CEverQuest__LMouseUp_x                                     0x5CAE00
#define CEverQuest__RightClickedOnPlayer_x                         0x5CD360
#define CEverQuest__RMouseUp_x                                     0x5CBD90
#define CEverQuest__SetGameState_x                                 0x5C8620
#define CEverQuest__UPCNotificationFlush_x                         0x5EC050
#define CEverQuest__IssuePetCommand_x                              0x5E7BF0
#define CEverQuest__ReportSuccessfulHit_x                          0x5E2840

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70E070
#define CGaugeWnd__CalcLinesFillRect_x                             0x70E0D0
#define CGaugeWnd__Draw_x                                          0x70D760

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AED40
#define CGuild__GetGuildName_x                                     0x4ADE20
#define CGuild__GetGuildIndex_x                                    0x4AE1B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x729410

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6013D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x736400
#define CInvSlotMgr__MoveItem_x                                    0x735110
#define CInvSlotMgr__SelectSlot_x                                  0x7364D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7339C0
#define CInvSlot__SliderComplete_x                                 0x731720
#define CInvSlot__GetItemBase_x                                    0x731090
#define CInvSlot__UpdateItem_x                                     0x731200

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x737E00
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7370D0
#define CInvSlotWnd__HandleLButtonUp_x                             0x737980

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F44C0
#define CItemDisplayWnd__UpdateStrings_x                           0x7460D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x740080
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7405A0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7466F0
#define CItemDisplayWnd__AboutToShow_x                             0x745D40
#define CItemDisplayWnd__WndNotification_x                         0x747C30

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x82BF00

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x74BD70

// CLabel 
#define CLabel__Draw_x                                             0x7517E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FFCE0
#define CListWnd__dCListWnd_x                                      0x900000
#define CListWnd__AddColumn_x                                      0x9042D0
#define CListWnd__AddColumn1_x                                     0x904320
#define CListWnd__AddLine_x                                        0x9046B0
#define CListWnd__AddString_x                                      0x9044B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9040A0
#define CListWnd__CalculateVSBRange_x                              0x903E90
#define CListWnd__ClearSel_x                                       0x904E90
#define CListWnd__ClearAllSel_x                                    0x904EF0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9058D0
#define CListWnd__Compare_x                                        0x9037D0
#define CListWnd__Draw_x                                           0x900100
#define CListWnd__DrawColumnSeparators_x                           0x9028B0
#define CListWnd__DrawHeader_x                                     0x902D20
#define CListWnd__DrawItem_x                                       0x903110
#define CListWnd__DrawLine_x                                       0x902A20
#define CListWnd__DrawSeparator_x                                  0x902950
#define CListWnd__EnableLine_x                                     0x9021A0
#define CListWnd__EnsureVisible_x                                  0x905810
#define CListWnd__ExtendSel_x                                      0x904DC0
#define CListWnd__GetColumnMinWidth_x                              0x901CE0
#define CListWnd__GetColumnWidth_x                                 0x901C50
#define CListWnd__GetCurSel_x                                      0x9015E0
#define CListWnd__GetItemAtPoint_x                                 0x902410
#define CListWnd__GetItemAtPoint1_x                                0x902480
#define CListWnd__GetItemData_x                                    0x901660
#define CListWnd__GetItemHeight_x                                  0x901A20
#define CListWnd__GetItemIcon_x                                    0x9017F0
#define CListWnd__GetItemRect_x                                    0x902290
#define CListWnd__GetItemText_x                                    0x9016A0
#define CListWnd__GetSelList_x                                     0x904F40
#define CListWnd__GetSeparatorRect_x                               0x9026C0
#define CListWnd__InsertLine_x                                     0x904AA0
#define CListWnd__RemoveLine_x                                     0x904BF0
#define CListWnd__SetColors_x                                      0x903E60
#define CListWnd__SetColumnJustification_x                         0x903B90
#define CListWnd__SetColumnWidth_x                                 0x903AB0
#define CListWnd__SetCurSel_x                                      0x904D00
#define CListWnd__SetItemColor_x                                   0x9054D0
#define CListWnd__SetItemData_x                                    0x905490
#define CListWnd__SetItemText_x                                    0x9050C0
#define CListWnd__ShiftColumnSeparator_x                           0x903C50
#define CListWnd__Sort_x                                           0x903950
#define CListWnd__ToggleSel_x                                      0x904D30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x766E10
#define CMapViewWnd__GetWorldCoordinates_x                         0x765520
#define CMapViewWnd__HandleLButtonDown_x                           0x762580

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x789FE0
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78A8C0
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78ADF0
#define CMerchantWnd__SelectRecoverySlot_x                         0x78DC20
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7889D0
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x793810
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x789C20

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x893EB0
#define CPacketScrambler__hton_x                                   0x893EA0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91E910
#define CSidlManager__FindScreenPieceTemplate_x                    0x91ED20
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91EB10
#define CSidlManager__CreateLabel_x                                0x7EB920
#define CSidlManager__CreateXWndFromTemplate_x                     0x921DF0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x921FD0
#define CSidlManager__CreateXWnd_x                                 0x7EB850
#define CSidlManager__CreateHotButtonWnd_x                         0x7EBE20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x91B4A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x91B3A0
#define CSidlScreenWnd__ConvertToRes_x                             0x940340
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91AE30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91AB20
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91ABF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91ACC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x91B920
#define CSidlScreenWnd__EnableIniStorage_x                         0x91BDF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x91BB10
#define CSidlScreenWnd__Init1_x                                    0x91A730
#define CSidlScreenWnd__LoadIniInfo_x                              0x91BE40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x91C980
#define CSidlScreenWnd__LoadSidlScreen_x                           0x919B40
#define CSidlScreenWnd__StoreIniInfo_x                             0x91C500
#define CSidlScreenWnd__StoreIniVis_x                              0x91C860
#define CSidlScreenWnd__WndNotification_x                          0x91B830
#define CSidlScreenWnd__GetChildItem_x                             0x91BD70
#define CSidlScreenWnd__HandleLButtonUp_x                          0x90B660
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B1A60

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x665570
#define CSkillMgr__GetSkillCap_x                                   0x665750
#define CSkillMgr__GetNameToken_x                                  0x664D00

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x92B930
#define CSliderWnd__SetValue_x                                     0x92B7A0
#define CSliderWnd__SetNumTicks_x                                  0x92B800

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F1730

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x932560
#define CStmlWnd__CalculateHSBRange_x                              0x9335D0
#define CStmlWnd__CalculateVSBRange_x                              0x933540
#define CStmlWnd__CanBreakAtCharacter_x                            0x937910
#define CStmlWnd__FastForwardToEndOfTag_x                          0x938500
#define CStmlWnd__ForceParseNow_x                                  0x932B00
#define CStmlWnd__GetNextTagPiece_x                                0x937870
#define CStmlWnd__GetSTMLText_x                                    0x4F36C0
#define CStmlWnd__GetVisibleText_x                                 0x932B20
#define CStmlWnd__InitializeWindowVariables_x                      0x938350
#define CStmlWnd__MakeStmlColorTag_x                               0x931CF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x931D60
#define CStmlWnd__SetSTMLText_x                                    0x930DC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x939650
#define CStmlWnd__UpdateHistoryString_x                            0x938710

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93D310
#define CTabWnd__DrawCurrentPage_x                                 0x93D930
#define CTabWnd__DrawTab_x                                         0x93D700
#define CTabWnd__GetCurrentPage_x                                  0x93CB70
#define CTabWnd__GetPageInnerRect_x                                0x93CDB0
#define CTabWnd__GetTabInnerRect_x                                 0x93CCF0
#define CTabWnd__GetTabRect_x                                      0x93CBA0
#define CTabWnd__InsertPage_x                                      0x93CFA0
#define CTabWnd__SetPage_x                                         0x93CE30
#define CTabWnd__SetPageRect_x                                     0x93D250
#define CTabWnd__UpdatePage_x                                      0x93D5C0
#define CTabWnd__GetPageFromTabIndex_x                             0x93D640
#define CTabWnd__GetCurrentTabIndex_x                              0x93CB60

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x74C1E0
#define CPageWnd__SetTabText_x                                     0x9498B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8840

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9084E0
#define CTextureFont__GetTextExtent_x                              0x9086A0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x699260
#define CHtmlComponentWnd__ValidateUri_x                           0x72AE00
#define CHtmlWnd__SetClientCallbacks_x                             0x6063C0
#define CHtmlWnd__AddObserver_x                                    0x6063E0
#define CHtmlWnd__RemoveObserver_x                                 0x606440
#define Window__getProgress_x                                      0x844730
#define Window__getStatus_x                                        0x844750
#define Window__getURI_x                                           0x844760

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x945E30

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F5380

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4B00A0
#define CXStr__CXStr1_x                                            0x4B5AB0
#define CXStr__CXStr3_x                                            0x8E1650
#define CXStr__dCXStr_x                                            0x471B50
#define CXStr__operator_equal_x                                    0x8E1880
#define CXStr__operator_equal1_x                                   0x8E18C0
#define CXStr__operator_plus_equal1_x                              0x8E2350

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x929BE0
#define CXWnd__BringToTop_x                                        0x90EDA0
#define CXWnd__Center_x                                            0x90E920
#define CXWnd__ClrFocus_x                                          0x90E760
#define CXWnd__Destroy_x                                           0x90E800
#define CXWnd__DoAllDrawing_x                                      0x90ADF0
#define CXWnd__DrawChildren_x                                      0x90ADC0
#define CXWnd__DrawColoredRect_x                                   0x90B250
#define CXWnd__DrawTooltip_x                                       0x909910
#define CXWnd__DrawTooltipAtPoint_x                                0x9099D0
#define CXWnd__GetBorderFrame_x                                    0x90B0B0
#define CXWnd__GetChildWndAt_x                                     0x90EE40
#define CXWnd__GetClientClipRect_x                                 0x90D080
#define CXWnd__GetScreenClipRect_x                                 0x90D150
#define CXWnd__GetScreenRect_x                                     0x90D2F0
#define CXWnd__GetTooltipRect_x                                    0x90B2A0
#define CXWnd__GetWindowTextA_x                                    0x49A050
#define CXWnd__IsActive_x                                          0x911CA0
#define CXWnd__IsDescendantOf_x                                    0x90DD00
#define CXWnd__IsReallyVisible_x                                   0x90DD30
#define CXWnd__IsType_x                                            0x90F4B0
#define CXWnd__Move_x                                              0x90DDA0
#define CXWnd__Move1_x                                             0x90DE60
#define CXWnd__ProcessTransition_x                                 0x90E8D0
#define CXWnd__Refade_x                                            0x90E130
#define CXWnd__Resize_x                                            0x90E3C0
#define CXWnd__Right_x                                             0x90EB60
#define CXWnd__SetFocus_x                                          0x90E720
#define CXWnd__SetFont_x                                           0x90E790
#define CXWnd__SetKeyTooltip_x                                     0x90F2D0
#define CXWnd__SetMouseOver_x                                      0x90C220
#define CXWnd__StartFade_x                                         0x90DBD0
#define CXWnd__GetChildItem_x                                      0x90EFB0
#define CXWnd__SetParent_x                                         0x90DA90

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x941410

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x911CE0
#define CXWndManager__DrawWindows_x                                0x911D00
#define CXWndManager__GetKeyboardFlags_x                           0x9143C0
#define CXWndManager__HandleKeyboardMsg_x                          0x913FC0
#define CXWndManager__RemoveWnd_x                                  0x914610
#define CXWndManager__RemovePendingDeletionWnd_x                   0x914B70

// CDBStr
#define CDBStr__GetString_x                                        0x528790

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB1D0
#define EQ_Character__Cur_HP_x                                     0x4D1420
#define EQ_Character__Cur_Mana_x                                   0x4D8B50
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BE0F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B1CA0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B1DF0
#define EQ_Character__GetHPRegen_x                                 0x4DEAD0
#define EQ_Character__GetEnduranceRegen_x                          0x4DF0E0
#define EQ_Character__GetManaRegen_x                               0x4DF520
#define EQ_Character__Max_Endurance_x                              0x62BE30
#define EQ_Character__Max_HP_x                                     0x4D1250
#define EQ_Character__Max_Mana_x                                   0x62BC30
#define EQ_Character__doCombatAbility_x                            0x62E300
#define EQ_Character__UseSkill_x                                   0x4E1330
#define EQ_Character__GetConLevel_x                                0x625510
#define EQ_Character__IsExpansionFlag_x                            0x58C1C0
#define EQ_Character__TotalEffect_x                                0x4C4780
#define EQ_Character__GetPCSpellAffect_x                           0x4BECE0
#define EQ_Character__SpellDuration_x                              0x4BE810
#define EQ_Character__FindItemByRecord_x                           0x4D6A30
#define EQ_Character__GetAdjustedSkill_x                           0x4D4160
#define EQ_Character__GetBaseSkill_x                               0x4D5100
#define EQ_Character__CanUseItem_x                                 0x4D8E60

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B2F60

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x642150

//PcClient
#define PcClient__PcClient_x                                       0x622DE0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B8E70
#define CCharacterListWnd__EnterWorld_x                            0x4B88B0
#define CCharacterListWnd__Quit_x                                  0x4B85C0
#define CCharacterListWnd__UpdateList_x                            0x4B8A40

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x607620
#define EQ_Item__CreateItemTagString_x                             0x88D800
#define EQ_Item__IsStackable_x                                     0x892260
#define EQ_Item__GetImageNum_x                                     0x88F250
#define EQ_Item__CreateItemClient_x                                0x6067C0
#define EQ_Item__GetItemValue_x                                    0x8904E0
#define EQ_Item__ValueSellMerchant_x                               0x893A50
#define EQ_Item__IsKeyRingItem_x                                   0x891BC0
#define EQ_Item__CanGoInBag_x                                      0x607740
#define EQ_Item__GetMaxItemCount_x                                 0x8908A0
#define EQ_Item__GetHeldItem_x                                     0x88F120
#define EQ_Item__GetAugmentFitBySlot_x                             0x88D140

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x546970
#define EQ_LoadingS__Array_x                                       0xBE7130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x62C790
#define EQ_PC__GetAlternateAbilityId_x                             0x89CCC0
#define EQ_PC__GetCombatAbility_x                                  0x89D330
#define EQ_PC__GetCombatAbilityTimer_x                             0x89D3A0
#define EQ_PC__GetItemRecastTimer_x                                0x62E880
#define EQ_PC__HasLoreItem_x                                       0x625D30
#define EQ_PC__AlertInventoryChanged_x                             0x624FE0
#define EQ_PC__GetPcZoneClient_x                                   0x6509C0
#define EQ_PC__RemoveMyAffect_x                                    0x631A70
#define EQ_PC__GetKeyRingItems_x                                   0x89DC40
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89D9C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89DF30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5926D0
#define EQItemList__add_object_x                                   0x5BE010
#define EQItemList__add_item_x                                     0x592CE0
#define EQItemList__delete_item_x                                  0x592D30
#define EQItemList__FreeItemList_x                                 0x592C30

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x525CC0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6439D0
#define EQPlayer__dEQPlayer_x                                      0x6370F0
#define EQPlayer__DoAttack_x                                       0x64B6A0
#define EQPlayer__EQPlayer_x                                       0x6377A0
#define EQPlayer__SetNameSpriteState_x                             0x63BA10
#define EQPlayer__SetNameSpriteTint_x                              0x63C8D0
#define PlayerBase__HasProperty_j_x                                0x9741D0
#define EQPlayer__IsTargetable_x                                   0x974670
#define EQPlayer__CanSee_x                                         0x9744D0
#define EQPlayer__CanSee1_x                                        0x9745A0
#define PlayerBase__GetVisibilityLineSegment_x                     0x974290

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64E470
#define PlayerZoneClient__GetLevel_x                               0x650A00
#define PlayerZoneClient__IsValidTeleport_x                        0x5BF160
#define PlayerZoneClient__LegalPlayerRace_x                        0x53FF00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6467E0
#define EQPlayerManager__GetSpawnByName_x                          0x646800
#define EQPlayerManager__GetPlayerFromPartialName_x                0x646890

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60AFA0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60AFE0
#define KeypressHandler__ClearCommandStateArray_x                  0x60C3D0
#define KeypressHandler__HandleKeyDown_x                           0x60C3F0
#define KeypressHandler__HandleKeyUp_x                             0x60C490
#define KeypressHandler__SaveKeymapping_x                          0x60C870

// MapViewMap 
#define MapViewMap__Clear_x                                        0x762CA0
#define MapViewMap__SaveEx_x                                       0x766040
#define MapViewMap__SetZoom_x                                      0x76A710

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B0E50

// StringTable 
#define StringTable__getString_x                                   0x8ABE80

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6316E0
#define PcZoneClient__RemovePetEffect_x                            0x631D10
#define PcZoneClient__HasAlternateAbility_x                        0x62BA70
#define PcZoneClient__GetCurrentMod_x                              0x4E4420
#define PcZoneClient__GetModCap_x                                  0x4E4320
#define PcZoneClient__CanEquipItem_x                               0x62C120
#define PcZoneClient__GetItemByID_x                                0x62ECF0
#define PcZoneClient__GetItemByItemClass_x                         0x62EE40
#define PcZoneClient__RemoveBuffEffect_x                           0x631D30
#define PcZoneClient__BandolierSwap_x                              0x62CD50

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C3D50

//IconCache
#define IconCache__GetIcon_x                                       0x7036B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6FB1B0
#define CContainerMgr__CloseContainer_x                            0x6FB480
#define CContainerMgr__OpenExperimentContainer_x                   0x6FBF00

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BDE40

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FF7F0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x759180
#define CLootWnd__RequestLootSlot_x                                0x758530

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55F040
#define EQ_Spell__SpellAffects_x                                   0x55F4B0
#define EQ_Spell__SpellAffectBase_x                                0x55F270
#define EQ_Spell__IsStackable_x                                    0x4C8FF0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C8E70
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B61C0
#define EQ_Spell__IsSPAStacking_x                                  0x5602E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55F800
#define EQ_Spell__IsNoRemove_x                                     0x4C8FD0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5602F0
#define __IsResEffectSpell_x                                       0x4C82E0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACA50

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8BB4B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x803880
#define CTargetWnd__WndNotification_x                              0x803110
#define CTargetWnd__RefreshTargetBuffs_x                           0x8033E0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x802260

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x807F40

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55A5C0
#define EqSoundManager__PlayScriptMp3_x                            0x55A720
#define EqSoundManager__SoundAssistPlay_x                          0x6693F0
#define EqSoundManager__WaveInstancePlay_x                         0x668960

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x517620

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92D320

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54E670
#define CAltAbilityData__GetMercMaxRank_x                          0x54E610
#define CAltAbilityData__GetMaxRank_x                              0x543B80

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FD900

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C8E50
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FDA40
#define CharacterBase__CreateItemIndex_x                           0x6059D0
#define CharacterBase__GetItemPossession_x                         0x4B6070
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C3B40
#define CharacterBase__GetEffectId_x                               0x4C8E00

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E3410
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E3C30

//messages
#define msg_spell_worn_off_x                                       0x584060
#define msg_new_text_x                                             0x578F40
#define __msgTokenTextParam_x                                      0x5866B0
#define msgTokenText_x                                             0x586900

//SpellManager
#define SpellManager__vftable_x                                    0xAAE9A0
#define SpellManager__SpellManager_x                               0x66C710
#define Spellmanager__LoadTextSpells_x                             0x66CFE0
#define SpellManager__GetSpellByGroupAndRank_x                     0x66C8E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x978220

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FE0F0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58A6F0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x61E670
#define ItemGlobalIndex__IsValidIndex_x                            0x4FE150

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8BBDF0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8BC070

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x751B30

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FF900
#define CCursorAttachment__Deactivate_x                            0x7008E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93F860
#define CEQSuiteTextureLoader__GetTexture_x                        0x93F520

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FB0F0

//IString
#define IString__Append_x                                          0x4ED9D0

//Camera
#define CDisplay__cameraType_x                                     0xDBFCD8
#define EverQuest__Cameras_x                                       0xE82F18

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5037F0
#define LootFiltersManager__GetItemFilterData_x                    0x5030E0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x503110
#define LootFiltersManager__SetItemLootFilter_x                    0x503330

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7ABE80

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97E030
#define CResolutionHandler__GetWindowedStyle_x                     0x6640E0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F7F80

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CE650

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x718210
#define CGroupWnd__UpdateDisplay_x                                 0x717570

//ItemBase
#define ItemBase__IsLore_x                                         0x891C20
#define ItemBase__IsLoreEquipped_x                                 0x891C90

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
