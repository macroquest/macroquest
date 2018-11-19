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
#define __ExpectedVersionDate                                     "Nov 19 2018"
#define __ExpectedVersionTime                                     "04:20:22"
#define __ActualVersionDate_x                                      0xACAF04
#define __ActualVersionTime_x                                      0xACAEF8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x611140
#define __MemChecker1_x                                            0x8E5A10
#define __MemChecker2_x                                            0x6A0460
#define __MemChecker3_x                                            0x6A03B0
#define __MemChecker4_x                                            0x83CD60
#define __EncryptPad0_x                                            0xBFF340
#define __EncryptPad1_x                                            0xC5D5D0
#define __EncryptPad2_x                                            0xC0FEC8
#define __EncryptPad3_x                                            0xC0FAC8
#define __EncryptPad4_x                                            0xC4DE40
#define __EncryptPad5_x                                            0xF23B34
#define __AC1_x                                                    0x7F98A6
#define __AC2_x                                                    0x5CC03F
#define __AC3_x                                                    0x5D2ECF
#define __AC4_x                                                    0x5D6CF0
#define __AC5_x                                                    0x5DCEAF
#define __AC6_x                                                    0x5E13E6
#define __AC7_x                                                    0x5CBAB0
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
#define __do_loot_x                                                0x599890
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
#define __gfMaxZoomCameraDistance_x                                0xAC03B8
#define __gfMaxCameraDistance_x                                    0xAED8E4
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
#define __CastRay_x                                                0x594DB0
#define __CastRay2_x                                               0x594E00
#define __ConvertItemTags_x                                        0x5AF9B0
#define __CrashHandler_x                                           0x8466E0
#define __EQGetTime_x                                              0x8E5500
#define __ExecuteCmd_x                                             0x58D700
#define __FixHeading_x                                             0x975AB0
#define __get_bearing_x                                            0x594900
#define __get_melee_range_x                                        0x594FF0
#define __GetAnimationCache_x                                      0x703E00
#define __GetGaugeValueFromEQ_x                                    0x7F80C0
#define __GetLabelFromEQ_x                                         0x7F9830
#define __GetXTargetType_x                                         0x9775E0
#define __HeadingDiff_x                                            0x975B20
#define __HelpPath_x                                               0xF20C6C
#define __LoadFrontEnd_x                                           0x69C2C0
#define __NewUIINI_x                                               0x7F7D90
#define __pCrashHandler_x                                          0x1056AF0
#define __ProcessGameEvents_x                                      0x5F2610
#define __ProcessMouseEvent_x                                      0x5F1DD0
#define __SaveColors_x                                             0x53E660
#define __STMLToText_x                                             0x919130
#define __ToggleKeyRingItem_x                                      0x5014B0
#define CrashDetected_x                                            0x69DDB0
#define DrawNetStatus_x                                            0x61E800
#define Expansion_HoT_x                                            0xE82BDC
#define Teleport_Table_Size_x                                      0xE71D34
#define Teleport_Table_x                                           0xE72420
#define Util__FastTime_x                                           0x8E4F50
#define wwsCrashReportCheckForUploader_x                           0x847490
#define wwsCrashReportPlatformLaunchUploader_x                     0x849B70
#define __HandleMouseWheel_x                                       0x6A0510

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48D9E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x496870
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x496630

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x546020
#define AltAdvManager__IsAbilityReady_x                            0x5450A0
#define AltAdvManager__GetAAById_x                                 0x5452A0
#define AltAdvManager__CanTrainAbility_x                           0x545310
#define AltAdvManager__CanSeeAbility_x                             0x545540

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9600
#define CharacterZoneClient__HasSkill_x                            0x4D42C0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D59E0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BDA80
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA1F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8370
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8450
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8530
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2560
#define CharacterZoneClient__BardCastBard_x                        0x4C51C0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA2C0
#define CharacterZoneClient__GetEffect_x                           0x4BA130
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3560
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3630
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3680
#define CharacterZoneClient__CalcAffectChange_x                    0x4C37D0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C39A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C6310

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D3B00

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x600F10
#define CButtonWnd__CButtonWnd_x                                   0x915520

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F27A0
#define CChatManager__InitContextMenu_x                            0x6EC840
#define CChatManager__FreeChatWindow_x                             0x6F16B0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F6040
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F2540

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x929CC0
#define CContextMenu__dCContextMenu_x                              0x929EF0
#define CContextMenu__AddMenuItem_x                                0x929F00
#define CContextMenu__RemoveMenuItem_x                             0x92A210
#define CContextMenu__RemoveAllMenuItems_x                         0x92A230
#define CContextMenu__CheckMenuItem_x                              0x92A2B0
#define CContextMenu__SetMenuItem_x                                0x92A130
#define CContextMenu__AddSeparator_x                               0x92A090

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92A850
#define CContextMenuManager__RemoveMenu_x                          0x92A8C0
#define CContextMenuManager__PopupMenu_x                           0x92A980
#define CContextMenuManager__Flush_x                               0x92A7F0
#define CContextMenuManager__GetMenu_x                             0x4989D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C5D90
#define CChatService__GetFriendName_x                              0x8C5DA0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F2D10
#define CChatWindow__Clear_x                                       0x6F3D60
#define CChatWindow__WndNotification_x                             0x6F42C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x927140
#define CComboWnd__Draw_x                                          0x926640
#define CComboWnd__GetCurChoice_x                                  0x926F80
#define CComboWnd__GetListRect_x                                   0x926AF0
#define CComboWnd__GetTextRect_x                                   0x9271B0
#define CComboWnd__InsertChoice_x                                  0x926C80
#define CComboWnd__SetColors_x                                     0x926C50
#define CComboWnd__SetChoice_x                                     0x926F50
#define CComboWnd__GetItemCount_x                                  0x926F90
#define CComboWnd__GetCurChoiceText_x                              0x926FD0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6FBFF0
#define CContainerWnd__vftable_x                                   0xAD4280
#define CContainerWnd__SetContainer_x                              0x6FD560

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53E420
#define CDisplay__GetClickedActor_x                                0x5313D0
#define CDisplay__GetUserDefinedColor_x                            0x529AB0
#define CDisplay__GetWorldFilePath_x                               0x532E20
#define CDisplay__is3dON_x                                         0x52E0A0
#define CDisplay__ReloadUI_x                                       0x538540
#define CDisplay__WriteTextHD2_x                                   0x52DE80
#define CDisplay__TrueDistance_x                                   0x534A80
#define CDisplay__SetViewActor_x                                   0x530D20
#define CDisplay__GetFloorHeight_x                                 0x52E160
#define CDisplay__SetRenderWindow_x                                0x52CA90
#define CDisplay__ToggleScreenshotMode_x                           0x5307F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9493C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92E3D0
#define CEditWnd__GetCharIndexPt_x                                 0x92F2D0
#define CEditWnd__GetDisplayString_x                               0x92F170
#define CEditWnd__GetHorzOffset_x                                  0x92DA00
#define CEditWnd__GetLineForPrintableChar_x                        0x930410
#define CEditWnd__GetSelStartPt_x                                  0x92F580
#define CEditWnd__GetSTMLSafeText_x                                0x92EF90
#define CEditWnd__PointFromPrintableChar_x                         0x930040
#define CEditWnd__SelectableCharFromPoint_x                        0x9301B0
#define CEditWnd__SetEditable_x                                    0x92F650

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E0910
#define CEverQuest__ClickedPlayer_x                                0x5D2CB0
#define CEverQuest__CreateTargetIndicator_x                        0x5EF8C0
#define CEverQuest__DeleteTargetIndicator_x                        0x5EF950
#define CEverQuest__DoTellWindow_x                                 0x4E5540
#define CEverQuest__OutputTextToLog_x                              0x4E5770
#define CEverQuest__DropHeldItemOnGround_x                         0x5C8570
#define CEverQuest__dsp_chat_x                                     0x4E5B00
#define CEverQuest__trimName_x                                     0x5EBE30
#define CEverQuest__Emote_x                                        0x5E1120
#define CEverQuest__EnterZone_x                                    0x5DB300
#define CEverQuest__GetBodyTypeDesc_x                              0x5E56D0
#define CEverQuest__GetClassDesc_x                                 0x5E5D10
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E6310
#define CEverQuest__GetDeityDesc_x                                 0x5EE210
#define CEverQuest__GetLangDesc_x                                  0x5E64D0
#define CEverQuest__GetRaceDesc_x                                  0x5E5CF0
#define CEverQuest__InterpretCmd_x                                 0x5EE7E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5CC760
#define CEverQuest__LMouseUp_x                                     0x5CAAE0
#define CEverQuest__RightClickedOnPlayer_x                         0x5CD040
#define CEverQuest__RMouseUp_x                                     0x5CBA70
#define CEverQuest__SetGameState_x                                 0x5C8300
#define CEverQuest__UPCNotificationFlush_x                         0x5EBD30
#define CEverQuest__IssuePetCommand_x                              0x5E78D0
#define CEverQuest__ReportSuccessfulHit_x                          0x5E2520

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70E030
#define CGaugeWnd__CalcLinesFillRect_x                             0x70E090
#define CGaugeWnd__Draw_x                                          0x70D720

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AEDE0
#define CGuild__GetGuildName_x                                     0x4ADEC0
#define CGuild__GetGuildIndex_x                                    0x4AE250

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7293E0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6012D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x736370
#define CInvSlotMgr__MoveItem_x                                    0x7350D0
#define CInvSlotMgr__SelectSlot_x                                  0x736440

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x733980
#define CInvSlot__SliderComplete_x                                 0x7316F0
#define CInvSlot__GetItemBase_x                                    0x731080
#define CInvSlot__UpdateItem_x                                     0x7311F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x737D90
#define CInvSlotWnd__CInvSlotWnd_x                                 0x737060
#define CInvSlotWnd__HandleLButtonUp_x                             0x737910

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F42B0
#define CItemDisplayWnd__UpdateStrings_x                           0x746080
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x740000
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x740520
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x746690
#define CItemDisplayWnd__AboutToShow_x                             0x745CE0
#define CItemDisplayWnd__WndNotification_x                         0x747BC0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x82BC00

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x74BCE0

// CLabel 
#define CLabel__Draw_x                                             0x751800

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FFA00
#define CListWnd__dCListWnd_x                                      0x8FFD20
#define CListWnd__AddColumn_x                                      0x904020
#define CListWnd__AddColumn1_x                                     0x904070
#define CListWnd__AddLine_x                                        0x904400
#define CListWnd__AddString_x                                      0x904200
#define CListWnd__CalculateFirstVisibleLine_x                      0x903DF0
#define CListWnd__CalculateVSBRange_x                              0x903BE0
#define CListWnd__ClearSel_x                                       0x904BE0
#define CListWnd__ClearAllSel_x                                    0x904C40
#define CListWnd__CloseAndUpdateEditWindow_x                       0x905630
#define CListWnd__Compare_x                                        0x903520
#define CListWnd__Draw_x                                           0x8FFE20
#define CListWnd__DrawColumnSeparators_x                           0x902600
#define CListWnd__DrawHeader_x                                     0x902A60
#define CListWnd__DrawItem_x                                       0x902E60
#define CListWnd__DrawLine_x                                       0x902760
#define CListWnd__DrawSeparator_x                                  0x9026A0
#define CListWnd__EnableLine_x                                     0x901EE0
#define CListWnd__EnsureVisible_x                                  0x905560
#define CListWnd__ExtendSel_x                                      0x904B10
#define CListWnd__GetColumnMinWidth_x                              0x901A20
#define CListWnd__GetColumnWidth_x                                 0x901990
#define CListWnd__GetCurSel_x                                      0x901320
#define CListWnd__GetItemAtPoint_x                                 0x902150
#define CListWnd__GetItemAtPoint1_x                                0x9021C0
#define CListWnd__GetItemData_x                                    0x9013A0
#define CListWnd__GetItemHeight_x                                  0x901760
#define CListWnd__GetItemIcon_x                                    0x901530
#define CListWnd__GetItemRect_x                                    0x901FD0
#define CListWnd__GetItemText_x                                    0x9013E0
#define CListWnd__GetSelList_x                                     0x904C90
#define CListWnd__GetSeparatorRect_x                               0x902400
#define CListWnd__InsertLine_x                                     0x9047F0
#define CListWnd__RemoveLine_x                                     0x904940
#define CListWnd__SetColors_x                                      0x903BB0
#define CListWnd__SetColumnJustification_x                         0x9038E0
#define CListWnd__SetColumnWidth_x                                 0x903800
#define CListWnd__SetCurSel_x                                      0x904A50
#define CListWnd__SetItemColor_x                                   0x905220
#define CListWnd__SetItemData_x                                    0x9051E0
#define CListWnd__SetItemText_x                                    0x904E10
#define CListWnd__ShiftColumnSeparator_x                           0x9039A0
#define CListWnd__Sort_x                                           0x9036A0
#define CListWnd__ToggleSel_x                                      0x904A80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x766DC0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7654D0
#define CMapViewWnd__HandleLButtonDown_x                           0x762530

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78A080
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78A960
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78AE90
#define CMerchantWnd__SelectRecoverySlot_x                         0x78DCD0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x788A50
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x7938C0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x789CB0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x893BB0
#define CPacketScrambler__hton_x                                   0x893BA0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91E6E0
#define CSidlManager__FindScreenPieceTemplate_x                    0x91EAF0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91E8E0
#define CSidlManager__CreateLabel_x                                0x7EB6B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x921BC0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x921DA0
#define CSidlManager__CreateXWnd_x                                 0x7EB5E0
#define CSidlManager__CreateHotButtonWnd_x                         0x7EBBA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x91B260
#define CSidlScreenWnd__CalculateVSBRange_x                        0x91B170
#define CSidlScreenWnd__ConvertToRes_x                             0x940200
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91AC10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91A900
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91A9D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91AAA0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x91B6F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x91BBC0
#define CSidlScreenWnd__GetSidlPiece_x                             0x91B8E0
#define CSidlScreenWnd__Init1_x                                    0x91A500
#define CSidlScreenWnd__LoadIniInfo_x                              0x91BC10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x91C750
#define CSidlScreenWnd__LoadSidlScreen_x                           0x919910
#define CSidlScreenWnd__StoreIniInfo_x                             0x91C2D0
#define CSidlScreenWnd__StoreIniVis_x                              0x91C630
#define CSidlScreenWnd__WndNotification_x                          0x91B600
#define CSidlScreenWnd__GetChildItem_x                             0x91BB40
#define CSidlScreenWnd__HandleLButtonUp_x                          0x90B410
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B1A60

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x665700
#define CSkillMgr__GetSkillCap_x                                   0x6658E0
#define CSkillMgr__GetNameToken_x                                  0x664E90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x92B650
#define CSliderWnd__SetValue_x                                     0x92B4C0
#define CSliderWnd__SetNumTicks_x                                  0x92B520

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F1530

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9322A0
#define CStmlWnd__CalculateHSBRange_x                              0x933340
#define CStmlWnd__CalculateVSBRange_x                              0x9332C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x937670
#define CStmlWnd__FastForwardToEndOfTag_x                          0x938260
#define CStmlWnd__ForceParseNow_x                                  0x932890
#define CStmlWnd__GetNextTagPiece_x                                0x9375D0
#define CStmlWnd__GetSTMLText_x                                    0x4F35C0
#define CStmlWnd__GetVisibleText_x                                 0x9328B0
#define CStmlWnd__InitializeWindowVariables_x                      0x9380B0
#define CStmlWnd__MakeStmlColorTag_x                               0x931A30
#define CStmlWnd__MakeWndNotificationTag_x                         0x931AA0
#define CStmlWnd__SetSTMLText_x                                    0x930B00
#define CStmlWnd__StripFirstSTMLLines_x                            0x9393B0
#define CStmlWnd__UpdateHistoryString_x                            0x938470

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93D0A0
#define CTabWnd__DrawCurrentPage_x                                 0x93D6C0
#define CTabWnd__DrawTab_x                                         0x93D490
#define CTabWnd__GetCurrentPage_x                                  0x93C900
#define CTabWnd__GetPageInnerRect_x                                0x93CB40
#define CTabWnd__GetTabInnerRect_x                                 0x93CA80
#define CTabWnd__GetTabRect_x                                      0x93C930
#define CTabWnd__InsertPage_x                                      0x93CD30
#define CTabWnd__SetPage_x                                         0x93CBC0
#define CTabWnd__SetPageRect_x                                     0x93CFE0
#define CTabWnd__UpdatePage_x                                      0x93D350
#define CTabWnd__GetPageFromTabIndex_x                             0x93D3D0
#define CTabWnd__GetCurrentTabIndex_x                              0x93C8F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x74C190
#define CPageWnd__SetTabText_x                                     0x9497D0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8950

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9082A0
#define CTextureFont__GetTextExtent_x                              0x908460

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x699100
#define CHtmlComponentWnd__ValidateUri_x                           0x72ADD0
#define CHtmlWnd__SetClientCallbacks_x                             0x606280
#define CHtmlWnd__AddObserver_x                                    0x6062A0
#define CHtmlWnd__RemoveObserver_x                                 0x606300
#define Window__getProgress_x                                      0x844350
#define Window__getStatus_x                                        0x844370
#define Window__getURI_x                                           0x844380

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x945D50

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F51F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4B0080
#define CXStr__CXStr1_x                                            0x8FDCF0
#define CXStr__CXStr3_x                                            0x8E14C0
#define CXStr__dCXStr_x                                            0x471B10
#define CXStr__operator_equal_x                                    0x8E16F0
#define CXStr__operator_equal1_x                                   0x8E1730
#define CXStr__operator_plus_equal1_x                              0x8E21C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9298C0
#define CXWnd__BringToTop_x                                        0x90EB30
#define CXWnd__Center_x                                            0x90E6B0
#define CXWnd__ClrFocus_x                                          0x90E500
#define CXWnd__Destroy_x                                           0x90E5A0
#define CXWnd__DoAllDrawing_x                                      0x90ABD0
#define CXWnd__DrawChildren_x                                      0x90ABA0
#define CXWnd__DrawColoredRect_x                                   0x90B020
#define CXWnd__DrawTooltip_x                                       0x909700
#define CXWnd__DrawTooltipAtPoint_x                                0x9097C0
#define CXWnd__GetBorderFrame_x                                    0x90AE80
#define CXWnd__GetChildWndAt_x                                     0x90EBD0
#define CXWnd__GetClientClipRect_x                                 0x90CE20
#define CXWnd__GetScreenClipRect_x                                 0x90CED0
#define CXWnd__GetScreenRect_x                                     0x90D080
#define CXWnd__GetTooltipRect_x                                    0x90B070
#define CXWnd__GetWindowTextA_x                                    0x49A0B0
#define CXWnd__IsActive_x                                          0x911A70
#define CXWnd__IsDescendantOf_x                                    0x90DA60
#define CXWnd__IsReallyVisible_x                                   0x90DA90
#define CXWnd__IsType_x                                            0x90F240
#define CXWnd__Move_x                                              0x90DAF0
#define CXWnd__Move1_x                                             0x90DBA0
#define CXWnd__ProcessTransition_x                                 0x90E660
#define CXWnd__Refade_x                                            0x90DE70
#define CXWnd__Resize_x                                            0x90E110
#define CXWnd__Right_x                                             0x90E8F0
#define CXWnd__SetFocus_x                                          0x90E4C0
#define CXWnd__SetFont_x                                           0x90E530
#define CXWnd__SetKeyTooltip_x                                     0x90F050
#define CXWnd__SetMouseOver_x                                      0x90BFA0
#define CXWnd__StartFade_x                                         0x90D930
#define CXWnd__GetChildItem_x                                      0x90ED40
#define CXWnd__SetParent_x                                         0x90D810

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9412D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x911AB0
#define CXWndManager__DrawWindows_x                                0x911AD0
#define CXWndManager__GetKeyboardFlags_x                           0x914170
#define CXWndManager__HandleKeyboardMsg_x                          0x913D80
#define CXWndManager__RemoveWnd_x                                  0x9143B0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9148F0

// CDBStr
#define CDBStr__GetString_x                                        0x528A40

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB1A0
#define EQ_Character__Cur_HP_x                                     0x4D1340
#define EQ_Character__Cur_Mana_x                                   0x4D8A30
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BE0C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B1CA0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B1DF0
#define EQ_Character__GetHPRegen_x                                 0x4DE970
#define EQ_Character__GetEnduranceRegen_x                          0x4DEF80
#define EQ_Character__GetManaRegen_x                               0x4DF3C0
#define EQ_Character__Max_Endurance_x                              0x62BD70
#define EQ_Character__Max_HP_x                                     0x4D1170
#define EQ_Character__Max_Mana_x                                   0x62BB70
#define EQ_Character__doCombatAbility_x                            0x62E240
#define EQ_Character__UseSkill_x                                   0x4E11D0
#define EQ_Character__GetConLevel_x                                0x625590
#define EQ_Character__IsExpansionFlag_x                            0x58BDF0
#define EQ_Character__TotalEffect_x                                0x4C4740
#define EQ_Character__GetPCSpellAffect_x                           0x4BECB0
#define EQ_Character__SpellDuration_x                              0x4BE7E0
#define EQ_Character__FindItemByRecord_x                           0x4D6950
#define EQ_Character__GetAdjustedSkill_x                           0x4D4080
#define EQ_Character__GetBaseSkill_x                               0x4D5020
#define EQ_Character__CanUseItem_x                                 0x4D8D40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B2C40

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x642110

//PcClient
#define PcClient__PcClient_x                                       0x622E60

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B8E40
#define CCharacterListWnd__EnterWorld_x                            0x4B8880
#define CCharacterListWnd__Quit_x                                  0x4B8590
#define CCharacterListWnd__UpdateList_x                            0x4B8A10

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6074D0
#define EQ_Item__CreateItemTagString_x                             0x88D5A0
#define EQ_Item__IsStackable_x                                     0x891F40
#define EQ_Item__GetImageNum_x                                     0x88EF90
#define EQ_Item__CreateItemClient_x                                0x606680
#define EQ_Item__GetItemValue_x                                    0x8901D0
#define EQ_Item__ValueSellMerchant_x                               0x893740
#define EQ_Item__IsKeyRingItem_x                                   0x891890
#define EQ_Item__CanGoInBag_x                                      0x6075F0
#define EQ_Item__GetMaxItemCount_x                                 0x8905A0
#define EQ_Item__GetHeldItem_x                                     0x88EE60
#define EQ_Item__GetAugmentFitBySlot_x                             0x88CEE0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x546D00
#define EQ_LoadingS__Array_x                                       0xBE7130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x62C6D0
#define EQ_PC__GetAlternateAbilityId_x                             0x89C920
#define EQ_PC__GetCombatAbility_x                                  0x89CF90
#define EQ_PC__GetCombatAbilityTimer_x                             0x89D000
#define EQ_PC__GetItemRecastTimer_x                                0x62E7C0
#define EQ_PC__HasLoreItem_x                                       0x625D60
#define EQ_PC__AlertInventoryChanged_x                             0x625060
#define EQ_PC__GetPcZoneClient_x                                   0x650850
#define EQ_PC__RemoveMyAffect_x                                    0x6319C0
#define EQ_PC__GetKeyRingItems_x                                   0x89D8A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89D620
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89DB90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x592340
#define EQItemList__add_object_x                                   0x5BDD50
#define EQItemList__add_item_x                                     0x592950
#define EQItemList__delete_item_x                                  0x5929A0
#define EQItemList__FreeItemList_x                                 0x5928A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x525F10

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x643990
#define EQPlayer__dEQPlayer_x                                      0x6370A0
#define EQPlayer__DoAttack_x                                       0x64B530
#define EQPlayer__EQPlayer_x                                       0x637750
#define EQPlayer__SetNameSpriteState_x                             0x63B9C0
#define EQPlayer__SetNameSpriteTint_x                              0x63C890
#define PlayerBase__HasProperty_j_x                                0x973E90
#define EQPlayer__IsTargetable_x                                   0x974330
#define EQPlayer__CanSee_x                                         0x974190
#define EQPlayer__CanSee1_x                                        0x974260
#define PlayerBase__GetVisibilityLineSegment_x                     0x973F50

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64E300
#define PlayerZoneClient__GetLevel_x                               0x650890
#define PlayerZoneClient__IsValidTeleport_x                        0x5BEEA0
#define PlayerZoneClient__LegalPlayerRace_x                        0x5401A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x646670
#define EQPlayerManager__GetSpawnByName_x                          0x646690
#define EQPlayerManager__GetPlayerFromPartialName_x                0x646720

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60AD60
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60ADA0
#define KeypressHandler__ClearCommandStateArray_x                  0x60C190
#define KeypressHandler__HandleKeyDown_x                           0x60C1B0
#define KeypressHandler__HandleKeyUp_x                             0x60C250
#define KeypressHandler__SaveKeymapping_x                          0x60C630

// MapViewMap 
#define MapViewMap__Clear_x                                        0x762C50
#define MapViewMap__SaveEx_x                                       0x765FF0
#define MapViewMap__SetZoom_x                                      0x76A6B0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B0A80

// StringTable 
#define StringTable__getString_x                                   0x8ABAD0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x631630
#define PcZoneClient__RemovePetEffect_x                            0x631C60
#define PcZoneClient__HasAlternateAbility_x                        0x62B9B0
#define PcZoneClient__GetCurrentMod_x                              0x4E42D0
#define PcZoneClient__GetModCap_x                                  0x4E41D0
#define PcZoneClient__CanEquipItem_x                               0x62C060
#define PcZoneClient__GetItemByID_x                                0x62EC40
#define PcZoneClient__GetItemByItemClass_x                         0x62ED90
#define PcZoneClient__RemoveBuffEffect_x                           0x631C80
#define PcZoneClient__BandolierSwap_x                              0x62CC90

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C3A30

//IconCache
#define IconCache__GetIcon_x                                       0x703690

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6FB190
#define CContainerMgr__CloseContainer_x                            0x6FB460
#define CContainerMgr__OpenExperimentContainer_x                   0x6FBEE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BDED0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FF700

//CLootWnd
#define CLootWnd__LootAll_x                                        0x759120
#define CLootWnd__RequestLootSlot_x                                0x7584D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55F070
#define EQ_Spell__SpellAffects_x                                   0x55F4E0
#define EQ_Spell__SpellAffectBase_x                                0x55F2A0
#define EQ_Spell__IsStackable_x                                    0x4C8F30
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C8DB0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B61D0
#define EQ_Spell__IsSPAStacking_x                                  0x560310
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55F830
#define EQ_Spell__IsNoRemove_x                                     0x4C8F10
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x560320
#define __IsResEffectSpell_x                                       0x4C8280

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACB20

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8BB100

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x803660
#define CTargetWnd__WndNotification_x                              0x802EF0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8031C0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x802050

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x807D30

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55A5F0
#define EqSoundManager__PlayScriptMp3_x                            0x55A750
#define EqSoundManager__SoundAssistPlay_x                          0x6695C0
#define EqSoundManager__WaveInstancePlay_x                         0x668B30

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x517840

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92D030

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54E970
#define CAltAbilityData__GetMercMaxRank_x                          0x54E910
#define CAltAbilityData__GetMaxRank_x                              0x543F50

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FD810

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C8D90
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FD8F0
#define CharacterBase__CreateItemIndex_x                           0x6058C0
#define CharacterBase__GetItemPossession_x                         0x4B6080
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C37A0
#define CharacterBase__GetEffectId_x                               0x4C8D40

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E3310
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E3B30

//messages
#define msg_spell_worn_off_x                                       0x583D30
#define msg_new_text_x                                             0x578C10
#define __msgTokenTextParam_x                                      0x586380
#define msgTokenText_x                                             0x5865D0

//SpellManager
#define SpellManager__vftable_x                                    0xAAE9A0
#define SpellManager__SpellManager_x                               0x66C8F0
#define Spellmanager__LoadTextSpells_x                             0x66D1C0
#define SpellManager__GetSpellByGroupAndRank_x                     0x66CAC0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x977ED0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FDFA0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58A3E0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x61E660
#define ItemGlobalIndex__IsValidIndex_x                            0x4FE000

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8BBA40
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8BBCC0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x751B50

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FF8D0
#define CCursorAttachment__Deactivate_x                            0x7008B0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93F680
#define CEQSuiteTextureLoader__GetTexture_x                        0x93F340

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FAF70

//IString
#define IString__Append_x                                          0x4ED970

//Camera
#define CDisplay__cameraType_x                                     0xDBFCD8
#define EverQuest__Cameras_x                                       0xE82F18

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x503720
#define LootFiltersManager__GetItemFilterData_x                    0x503020
#define LootFiltersManager__RemoveItemLootFilter_x                 0x503050
#define LootFiltersManager__SetItemLootFilter_x                    0x503270

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7ABEE0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97DC50
#define CResolutionHandler__GetWindowedStyle_x                     0x6641C0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F7EA0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CE280

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7181B0
#define CGroupWnd__UpdateDisplay_x                                 0x717520

//ItemBase
#define ItemBase__IsLore_x                                         0x8918F0
#define ItemBase__IsLoreEquipped_x                                 0x891960

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
