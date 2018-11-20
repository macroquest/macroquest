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
#define __ExpectedVersionDate                                     "Nov 20 2018"
#define __ExpectedVersionTime                                     "04:20:58"
#define __ActualVersionDate_x                                      0xACAEFC
#define __ActualVersionTime_x                                      0xACAEF0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x610C10
#define __MemChecker1_x                                            0x8E50E0
#define __MemChecker2_x                                            0x69FB70
#define __MemChecker3_x                                            0x69FAC0
#define __MemChecker4_x                                            0x83C410
#define __EncryptPad0_x                                            0xBFF340
#define __EncryptPad1_x                                            0xC5D5D0
#define __EncryptPad2_x                                            0xC0FEC8
#define __EncryptPad3_x                                            0xC0FAC8
#define __EncryptPad4_x                                            0xC4DE40
#define __EncryptPad5_x                                            0xF23B30
#define __AC1_x                                                    0x7F8D16
#define __AC2_x                                                    0x5CBC8F
#define __AC3_x                                                    0x5D2B1F
#define __AC4_x                                                    0x5D6940
#define __AC5_x                                                    0x5DCAFF
#define __AC6_x                                                    0x5E1036
#define __AC7_x                                                    0x5CB700
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19BB44

// Direct Input
#define DI8__Main_x                                                0xF23B54
#define DI8__Keyboard_x                                            0xF23B58
#define DI8__Mouse_x                                               0xF23B1C
#define DI8__Mouse_Copy_x                                          0xE81874
#define DI8__Mouse_Check_x                                         0xF24A18
#define __AutoSkillArray_x                                         0xE8278C
#define __Attack_x                                                 0xF20593
#define __Autofire_x                                               0xF20594
#define __BindList_x                                               0xBEDF20
#define g_eqCommandStates_x                                        0xBEEC90
#define __Clicks_x                                                 0xE8192C
#define __CommandList_x                                            0xBEF848
#define __CurrentMapLabel_x                                        0x103613C
#define __CurrentSocial_x                                          0xBD8BF8
#define __DoAbilityList_x                                          0xEB80B4
#define __do_loot_x                                                0x599470
#define __DrawHandler_x                                            0x16B2B10
#define __GroupCount_x                                             0xE7422A
#define __Guilds_x                                                 0xE78080
#define __gWorld_x                                                 0xE74210
#define __HWnd_x                                                   0xF23B20
#define __heqmain_x                                                0x102ED74
#define __InChatMode_x                                             0xE8185C
#define __LastTell_x                                               0xE837B0
#define __LMouseHeldTime_x                                         0xE81998
#define __Mouse_x                                                  0xF23B3C
#define __MouseLook_x                                              0xE818F2
#define __MouseEventTime_x                                         0xF21048
#define __gpbCommandEvent_x                                        0xE73CAC
#define __NetStatusToggle_x                                        0xE818F5
#define __PCNames_x                                                0xE82D6C
#define __RangeAttackReady_x                                       0xE82A70
#define __RMouseHeldTime_x                                         0xE81994
#define __RunWalkState_x                                           0xE81860
#define __ScreenMode_x                                             0xDBFC24
#define __ScreenX_x                                                0xE81814
#define __ScreenY_x                                                0xE81810
#define __ScreenXMax_x                                             0xE81818
#define __ScreenYMax_x                                             0xE8181C
#define __ServerHost_x                                             0xE73EE3
#define __ServerName_x                                             0xEB8074
#define __ShiftKeyDown_x                                           0xE81EEC
#define __ShowNames_x                                              0xE82C2C
#define __Socials_x                                                0xEB8174
#define __SubscriptionType_x                                       0x1077C8C
#define __TargetAggroHolder_x                                      0x1038AF8
#define __ZoneType_x                                               0xE81CF0
#define __GroupAggro_x                                             0x1038B38
#define __LoginName_x                                              0xF243AC
#define __Inviter_x                                                0xF20510
#define __AttackOnAssist_x                                         0xE82BE8
#define __UseTellWindows_x                                         0xE82F04
#define __gfMaxZoomCameraDistance_x                                0xAC03C0
#define __gfMaxCameraDistance_x                                    0xAED904
#define __pulAutoRun_x                                             0xE81910
#define __pulForward_x                                             0xE82F3C
#define __pulBackward_x                                            0xE82F40
#define __pulTurnRight_x                                           0xE82F44
#define __pulTurnLeft_x                                            0xE82F48
#define __pulStrafeLeft_x                                          0xE82F4C
#define __pulStrafeRight_x                                         0xE82F50
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE74420
#define instEQZoneInfo_x                                           0xE81AE8
#define instKeypressHandler_x                                      0xF20FF8
#define pinstActiveBanker_x                                        0xE73D8C
#define pinstActiveCorpse_x                                        0xE73D84
#define pinstActiveGMaster_x                                       0xE73D88
#define pinstActiveMerchant_x                                      0xE73D80
#define pinstAggroInfo_x                                           0xC7E378
#define pinstAltAdvManager_x                                       0xDC0DC8
#define pinstAuraMgr_x                                             0xC8F060
#define pinstBandageTarget_x                                       0xE73D9C
#define pinstCamActor_x                                            0xDBFC14
#define pinstCDBStr_x                                              0xDBFAFC
#define pinstCDisplay_x                                            0xE73FEC
#define pinstCEverQuest_x                                          0xF23C70
#define pinstEverQuestInfo_x                                       0xE81808
#define pinstCharData_x                                            0xE74200
#define pinstCharSpawn_x                                           0xE73DD4
#define pinstControlledMissile_x                                   0xE741FC
#define pinstControlledPlayer_x                                    0xE73DD4
#define pinstCResolutionHandler_x                                  0x16B2D40
#define pinstCSidlManager_x                                        0x16B1BD4
#define pinstCXWndManager_x                                        0x16B1BC8
#define instDynamicZone_x                                          0xE77F58
#define pinstDZMember_x                                            0xE78068
#define pinstDZTimerInfo_x                                         0xE7806C
#define pinstEQItemList_x                                          0xE70610
#define pinstEQObjectList_x                                        0xE71800
#define instEQMisc_x                                               0xDBFA38
#define pinstEQSoundManager_x                                      0xDC1628
#define pinstEQSpellStrings_x                                      0xC8C4B0
#define instExpeditionLeader_x                                     0xE77FA2
#define instExpeditionName_x                                       0xE77FE2
#define pinstGroup_x                                               0xE74226
#define pinstImeManager_x                                          0x16B1BCC
#define pinstLocalPlayer_x                                         0xE73D7C
#define pinstMercenaryData_x                                       0xF217F4
#define pinstMercenaryStats_x                                      0x1038C44
#define pinstMercAltAbilities_x                                    0xDC1398
#define pinstModelPlayer_x                                         0xE73D94
#define pinstPCData_x                                              0xE74200
#define pinstRealEstateItems_x                                     0xF22CD8
#define pinstSkillMgr_x                                            0xF22DA8
#define pinstSpawnManager_x                                        0xF22398
#define pinstSpellManager_x                                        0xF22F80
#define pinstSpellSets_x                                           0xF191BC
#define pinstStringTable_x                                         0xE73B30
#define pinstSwitchManager_x                                       0xE719C0
#define pinstTarget_x                                              0xE73DD0
#define pinstTargetObject_x                                        0xE73DDC
#define pinstTargetSwitch_x                                        0xE74208
#define pinstTaskMember_x                                          0xDBF8CC
#define pinstTrackTarget_x                                         0xE73DE0
#define pinstTradeTarget_x                                         0xE73D90
#define instTributeActive_x                                        0xDBFA5D
#define pinstViewActor_x                                           0xDBFC10
#define pinstWorldData_x                                           0xE741F8
#define pinstZoneAddr_x                                            0xE81D88
#define pinstPlayerPath_x                                          0xF22430
#define pinstTargetIndicator_x                                     0xF231E8
#define pinstCTargetManager_x                                      0xF23280
#define EQObject_Top_x                                             0xE73D78

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC0418
#define pinstCAchievementsWnd_x                                    0xDBFC70
#define pinstCActionsWnd_x                                         0xDBFBD4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC03D4
#define pinstCAdvancedLootWnd_x                                    0xDBFF04
#define pinstCAdventureLeaderboardWnd_x                            0x102F910
#define pinstCAdventureRequestWnd_x                                0x102F9C0
#define pinstCAdventureStatsWnd_x                                  0x102FA70
#define pinstCAggroMeterWnd_x                                      0xDBFC60
#define pinstCAlarmWnd_x                                           0xDBFBEC
#define pinstCAlertHistoryWnd_x                                    0xDBFC38
#define pinstCAlertStackWnd_x                                      0xDBFBB0
#define pinstCAlertWnd_x                                           0xDBFBBC
#define pinstCAltStorageWnd_x                                      0x102FDD0
#define pinstCAudioTriggersWindow_x                                0xC7E808
#define pinstCAuraWnd_x                                            0xDBFC5C
#define pinstCAvaZoneWnd_x                                         0xDBFC3C
#define pinstCBandolierWnd_x                                       0xDBFCA0
#define pinstCBankWnd_x                                            0xDBFF28
#define pinstCBarterMerchantWnd_x                                  0x1031010
#define pinstCBarterSearchWnd_x                                    0x10310C0
#define pinstCBarterWnd_x                                          0x1031170
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
#define pinstCButtonWnd_x                                          0x16B1DF8
#define pinstCCastingWnd_x                                         0xDC040C
#define pinstCCastSpellWnd_x                                       0xDBFBF0
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC042C
#define pinstCChatWindowManager_x                                  0x1031C30
#define pinstCClaimWnd_x                                           0x1031D88
#define pinstCColorPickerWnd_x                                     0xDBFBAC
#define pinstCCombatAbilityWnd_x                                   0xDBFC6C
#define pinstCCombatSkillsSelectWnd_x                              0xDBFBC8
#define pinstCCompassWnd_x                                         0xDC0408
#define pinstCConfirmationDialog_x                                 0x1036C88
#define pinstCContainerMgr_x                                       0xDBFC84
#define pinstCContextMenuManager_x                                 0x16B1B88
#define pinstCCursorAttachment_x                                   0xDC03E0
#define pinstCDistillerInfo_x                                      0x1035694
#define pinstCDynamicZoneWnd_x                                     0x1032350
#define pinstCEditLabelWnd_x                                       0xDBFCD4
#define pinstCEQMainWnd_x                                          0x1032598
#define pinstCEventCalendarWnd_x                                   0xDBFCD0
#define pinstCExtendedTargetWnd_x                                  0xDBFC4C
#define pinstCFacePick_x                                           0xDBFBA4
#define pinstCFellowshipWnd_x                                      0x1032798
#define pinstCFileSelectionWnd_x                                   0xDBFEF4
#define pinstCFindItemWnd_x                                        0xDBFCB4
#define pinstCFindLocationWnd_x                                    0x10328F0
#define pinstCFriendsWnd_x                                         0xDBFBE0
#define pinstCGemsGameWnd_x                                        0xDBFBC0
#define pinstCGiveWnd_x                                            0xDBFCC0
#define pinstCGroupSearchFiltersWnd_x                              0xDBFC7C
#define pinstCGroupSearchWnd_x                                     0x1032CE8
#define pinstCGroupWnd_x                                           0x1032D98
#define pinstCGuildBankWnd_x                                       0xE82BCC
#define pinstCGuildCreationWnd_x                                   0x1032EF8
#define pinstCGuildMgmtWnd_x                                       0x1032FA8
#define pinstCharacterCreation_x                                   0xDBFC68
#define pinstCHelpWnd_x                                            0xDBFC04
#define pinstCHeritageSelectionWnd_x                               0xDBFBB8
#define pinstCHotButtonWnd_x                                       0x1035100
#define pinstCHotButtonWnd1_x                                      0x1035100
#define pinstCHotButtonWnd2_x                                      0x1035104
#define pinstCHotButtonWnd3_x                                      0x1035108
#define pinstCHotButtonWnd4_x                                      0x103510C
#define pinstCIconSelectionWnd_x                                   0xDBFFB8
#define pinstCInspectWnd_x                                         0xDBFF44
#define pinstCInventoryWnd_x                                       0xDBFCA4
#define pinstCInvSlotMgr_x                                         0xDBFC34
#define pinstCItemDisplayManager_x                                 0x1035690
#define pinstCItemExpTransferWnd_x                                 0x10357C0
#define pinstCItemOverflowWnd_x                                    0xDBFBE8
#define pinstCJournalCatWnd_x                                      0xDBFF20
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDBFCC8
#define pinstCKeyRingWnd_x                                         0xDBFEFC
#define pinstCLargeDialogWnd_x                                     0x1037908
#define pinstCLayoutCopyWnd_x                                      0x1035B10
#define pinstCLFGuildWnd_x                                         0x1035BC0
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
#define pinstCMIZoneSelectWnd_x                                    0x10363F8
#define pinstCMusicPlayerWnd_x                                     0xDBFEF8
#define pinstCNameChangeMercWnd_x                                  0xDC0424
#define pinstCNameChangePetWnd_x                                   0xDC0400
#define pinstCNameChangeWnd_x                                      0xDBFCB8
#define pinstCNoteWnd_x                                            0xDBFBFC
#define pinstCObjectPreviewWnd_x                                   0xDBFF1C
#define pinstCOptionsWnd_x                                         0xDBFCAC
#define pinstCPetInfoWnd_x                                         0xDBFF18
#define pinstCPetitionQWnd_x                                       0xDBFF2C
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC041C
#define pinstCPlayerWnd_x                                          0xDBFBD8
#define pinstCPopupWndManager_x                                    0x1036C88
#define pinstCProgressionSelectionWnd_x                            0x1036D38
#define pinstCPurchaseGroupWnd_x                                   0xDC03C0
#define pinstCPurchaseWnd_x                                        0xDBFF24
#define pinstCPvPLeaderboardWnd_x                                  0x1036DE8
#define pinstCPvPStatsWnd_x                                        0x1036E98
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
#define pinstCTargetOfTargetWnd_x                                  0x1038CC8
#define pinstCTargetWnd_x                                          0xDBFF10
#define pinstCTaskOverlayWnd_x                                     0xDBFC44
#define pinstCTaskSelectWnd_x                                      0x1038E20
#define pinstCTaskSomething_x                                      0xC90190
#define pinstCTaskTemplateSelectWnd_x                              0x1038ED0
#define pinstCTaskWnd_x                                            0x1038F80
#define pinstCTextEntryWnd_x                                       0xDC0410
#define pinstCTextOverlay_x                                        0xC7EB18
#define pinstCTimeLeftWnd_x                                        0xDBFF00
#define pinstCTipWndCONTEXT_x                                      0x1039184
#define pinstCTipWndOFDAY_x                                        0x1039180
#define pinstCTitleWnd_x                                           0x1039230
#define pinstCTrackingWnd_x                                        0xDBFF0C
#define pinstCTradeskillWnd_x                                      0x1039398
#define pinstCTradeWnd_x                                           0xDBFC18
#define pinstCTrainWnd_x                                           0xDC03C4
#define pinstCTributeBenefitWnd_x                                  0x1039598
#define pinstCTributeMasterWnd_x                                   0x1039648
#define pinstCTributeTrophyWnd_x                                   0x10396F8
#define pinstCVideoModesWnd_x                                      0xDBFC74
#define pinstCVoiceMacroWnd_x                                      0xF237B0
#define pinstCVoteResultsWnd_x                                     0xDC03C8
#define pinstCVoteWnd_x                                            0xDBFF30
#define pinstCWebManager_x                                         0xF23914
#define pinstCZoneGuideWnd_x                                       0xDBFC00
#define pinstCZonePathWnd_x                                        0xDBFC0C

#define pinstEQSuiteTextureLoader_x                                0xC5F0A0
#define pinstItemIconCache_x                                       0x1032550
#define pinstLootFiltersManager_x                                  0xC8FA40
#define pinstRewardSelectionWnd_x                                  0x10375E0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0FABC
#define __CastRay_x                                                0x594990
#define __CastRay2_x                                               0x5949E0
#define __ConvertItemTags_x                                        0x5AF580
#define __CrashHandler_x                                           0x845DC0
#define __EQGetTime_x                                              0x8E4BD0
#define __ExecuteCmd_x                                             0x58D300
#define __FixHeading_x                                             0x9757D0
#define __get_bearing_x                                            0x5944E0
#define __get_melee_range_x                                        0x594BD0
#define __GetAnimationCache_x                                      0x703460
#define __GetGaugeValueFromEQ_x                                    0x7F7530
#define __GetLabelFromEQ_x                                         0x7F8CA0
#define __GetXTargetType_x                                         0x977230
#define __HeadingDiff_x                                            0x975840
#define __HelpPath_x                                               0xF20C64
#define __LoadFrontEnd_x                                           0x69B9D0
#define __NewUIINI_x                                               0x7F7200
#define __pCrashHandler_x                                          0x1056AE8
#define __ProcessGameEvents_x                                      0x5F2260
#define __ProcessMouseEvent_x                                      0x5F1A20
#define __SaveColors_x                                             0x53E2A0
#define __STMLToText_x                                             0x918990
#define __ToggleKeyRingItem_x                                      0x501270
#define CrashDetected_x                                            0x69D4C0
#define DrawNetStatus_x                                            0x61E170
#define Expansion_HoT_x                                            0xE82BD4
#define Teleport_Table_Size_x                                      0xE73D38
#define Teleport_Table_x                                           0xE71B18
#define Util__FastTime_x                                           0x8E4620
#define wwsCrashReportCheckForUploader_x                           0x846B10
#define wwsCrashReportPlatformLaunchUploader_x                     0x849200
#define __HandleMouseWheel_x                                       0x69FC20

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48D630
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4964A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x496260

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x545E70
#define AltAdvManager__IsAbilityReady_x                            0x544DC0
#define AltAdvManager__GetAAById_x                                 0x544FC0
#define AltAdvManager__CanTrainAbility_x                           0x545030
#define AltAdvManager__CanSeeAbility_x                             0x545390

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9380
#define CharacterZoneClient__HasSkill_x                            0x4D4040
#define CharacterZoneClient__MakeMeVisible_x                       0x4D5760
#define CharacterZoneClient__IsStackBlocked_x                      0x4BD830
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B9FA0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8110
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D81F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D82D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2310
#define CharacterZoneClient__BardCastBard_x                        0x4C4F70
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA070
#define CharacterZoneClient__GetEffect_x                           0x4B9EE0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3310
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C33E0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3430
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3580
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C3750

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C5A10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D3330

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x600A20
#define CButtonWnd__CButtonWnd_x                                   0x914DE0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F1EB0
#define CChatManager__InitContextMenu_x                            0x6EBF50
#define CChatManager__FreeChatWindow_x                             0x6F0DC0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F5760
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F1C50

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x929600
#define CContextMenu__dCContextMenu_x                              0x929830
#define CContextMenu__AddMenuItem_x                                0x929840
#define CContextMenu__RemoveMenuItem_x                             0x929B50
#define CContextMenu__RemoveAllMenuItems_x                         0x929B70
#define CContextMenu__CheckMenuItem_x                              0x929BF0
#define CContextMenu__SetMenuItem_x                                0x929A70
#define CContextMenu__AddSeparator_x                               0x9299D0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92A190
#define CContextMenuManager__RemoveMenu_x                          0x92A200
#define CContextMenuManager__PopupMenu_x                           0x92A2C0
#define CContextMenuManager__Flush_x                               0x92A130
#define CContextMenuManager__GetMenu_x                             0x4986B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C5420
#define CChatService__GetFriendName_x                              0x8C5430

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F2420
#define CChatWindow__Clear_x                                       0x6F3470
#define CChatWindow__WndNotification_x                             0x6F39E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x926A90
#define CComboWnd__Draw_x                                          0x925F80
#define CComboWnd__GetCurChoice_x                                  0x9268D0
#define CComboWnd__GetListRect_x                                   0x926430
#define CComboWnd__GetTextRect_x                                   0x926B00
#define CComboWnd__InsertChoice_x                                  0x9265C0
#define CComboWnd__SetColors_x                                     0x926590
#define CComboWnd__SetChoice_x                                     0x9268A0
#define CComboWnd__GetItemCount_x                                  0x9268E0
#define CComboWnd__GetCurChoiceText_x                              0x926920

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6FB650
#define CContainerWnd__vftable_x                                   0xAD4298
#define CContainerWnd__SetContainer_x                              0x6FCBC0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53E060
#define CDisplay__GetClickedActor_x                                0x531020
#define CDisplay__GetUserDefinedColor_x                            0x529700
#define CDisplay__GetWorldFilePath_x                               0x532A70
#define CDisplay__is3dON_x                                         0x52DCF0
#define CDisplay__ReloadUI_x                                       0x538190
#define CDisplay__WriteTextHD2_x                                   0x52DAD0
#define CDisplay__TrueDistance_x                                   0x5346D0
#define CDisplay__SetViewActor_x                                   0x530970
#define CDisplay__GetFloorHeight_x                                 0x52DDB0
#define CDisplay__SetRenderWindow_x                                0x52C6E0
#define CDisplay__ToggleScreenshotMode_x                           0x530440

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x948F60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92DD30
#define CEditWnd__GetCharIndexPt_x                                 0x92EC20
#define CEditWnd__GetDisplayString_x                               0x92EAC0
#define CEditWnd__GetHorzOffset_x                                  0x92D360
#define CEditWnd__GetLineForPrintableChar_x                        0x92FD30
#define CEditWnd__GetSelStartPt_x                                  0x92EED0
#define CEditWnd__GetSTMLSafeText_x                                0x92E8E0
#define CEditWnd__PointFromPrintableChar_x                         0x92F970
#define CEditWnd__SelectableCharFromPoint_x                        0x92FAE0
#define CEditWnd__SetEditable_x                                    0x92EF90

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E0560
#define CEverQuest__ClickedPlayer_x                                0x5D2900
#define CEverQuest__CreateTargetIndicator_x                        0x5EF510
#define CEverQuest__DeleteTargetIndicator_x                        0x5EF5A0
#define CEverQuest__DoTellWindow_x                                 0x4E5210
#define CEverQuest__OutputTextToLog_x                              0x4E5440
#define CEverQuest__DropHeldItemOnGround_x                         0x5C81C0
#define CEverQuest__dsp_chat_x                                     0x4E57D0
#define CEverQuest__trimName_x                                     0x5EBA80
#define CEverQuest__Emote_x                                        0x5E0D70
#define CEverQuest__EnterZone_x                                    0x5DAF50
#define CEverQuest__GetBodyTypeDesc_x                              0x5E5320
#define CEverQuest__GetClassDesc_x                                 0x5E5960
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E5F60
#define CEverQuest__GetDeityDesc_x                                 0x5EDE60
#define CEverQuest__GetLangDesc_x                                  0x5E6120
#define CEverQuest__GetRaceDesc_x                                  0x5E5940
#define CEverQuest__InterpretCmd_x                                 0x5EE430
#define CEverQuest__LeftClickedOnPlayer_x                          0x5CC3B0
#define CEverQuest__LMouseUp_x                                     0x5CA730
#define CEverQuest__RightClickedOnPlayer_x                         0x5CCC90
#define CEverQuest__RMouseUp_x                                     0x5CB6C0
#define CEverQuest__SetGameState_x                                 0x5C7F50
#define CEverQuest__UPCNotificationFlush_x                         0x5EB980
#define CEverQuest__IssuePetCommand_x                              0x5E7520
#define CEverQuest__ReportSuccessfulHit_x                          0x5E2170

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70D540
#define CGaugeWnd__CalcLinesFillRect_x                             0x70D5A0
#define CGaugeWnd__Draw_x                                          0x70CC40

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AEAC0
#define CGuild__GetGuildName_x                                     0x4ADBA0
#define CGuild__GetGuildIndex_x                                    0x4ADF30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7288D0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x600DE0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x735830
#define CInvSlotMgr__MoveItem_x                                    0x734590
#define CInvSlotMgr__SelectSlot_x                                  0x735900

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x732E40
#define CInvSlot__SliderComplete_x                                 0x730BA0
#define CInvSlot__GetItemBase_x                                    0x730540
#define CInvSlot__UpdateItem_x                                     0x7306B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x737230
#define CInvSlotWnd__CInvSlotWnd_x                                 0x736500
#define CInvSlotWnd__HandleLButtonUp_x                             0x736DB0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F36D0
#define CItemDisplayWnd__UpdateStrings_x                           0x7454C0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73F440
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73F960
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x745AE0
#define CItemDisplayWnd__AboutToShow_x                             0x745110
#define CItemDisplayWnd__WndNotification_x                         0x747010

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x82B280

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x74B170

// CLabel 
#define CLabel__Draw_x                                             0x750BE0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FF0D0
#define CListWnd__dCListWnd_x                                      0x8FF3F0
#define CListWnd__AddColumn_x                                      0x903720
#define CListWnd__AddColumn1_x                                     0x903770
#define CListWnd__AddLine_x                                        0x903B00
#define CListWnd__AddString_x                                      0x903900
#define CListWnd__CalculateFirstVisibleLine_x                      0x9034E0
#define CListWnd__CalculateVSBRange_x                              0x9032C0
#define CListWnd__ClearSel_x                                       0x9042E0
#define CListWnd__ClearAllSel_x                                    0x904340
#define CListWnd__CloseAndUpdateEditWindow_x                       0x904D50
#define CListWnd__Compare_x                                        0x902C00
#define CListWnd__Draw_x                                           0x8FF4F0
#define CListWnd__DrawColumnSeparators_x                           0x901CD0
#define CListWnd__DrawHeader_x                                     0x902140
#define CListWnd__DrawItem_x                                       0x902540
#define CListWnd__DrawLine_x                                       0x901E40
#define CListWnd__DrawSeparator_x                                  0x901D70
#define CListWnd__EnableLine_x                                     0x9015A0
#define CListWnd__EnsureVisible_x                                  0x904C70
#define CListWnd__ExtendSel_x                                      0x904210
#define CListWnd__GetColumnMinWidth_x                              0x9010E0
#define CListWnd__GetColumnWidth_x                                 0x901050
#define CListWnd__GetCurSel_x                                      0x9009E0
#define CListWnd__GetItemAtPoint_x                                 0x901820
#define CListWnd__GetItemAtPoint1_x                                0x901890
#define CListWnd__GetItemData_x                                    0x900A60
#define CListWnd__GetItemHeight_x                                  0x900E20
#define CListWnd__GetItemIcon_x                                    0x900BF0
#define CListWnd__GetItemRect_x                                    0x901690
#define CListWnd__GetItemText_x                                    0x900AA0
#define CListWnd__GetSelList_x                                     0x904390
#define CListWnd__GetSeparatorRect_x                               0x901AD0
#define CListWnd__InsertLine_x                                     0x903EF0
#define CListWnd__RemoveLine_x                                     0x904040
#define CListWnd__SetColors_x                                      0x903290
#define CListWnd__SetColumnJustification_x                         0x902FC0
#define CListWnd__SetColumnWidth_x                                 0x902EE0
#define CListWnd__SetCurSel_x                                      0x904150
#define CListWnd__SetItemColor_x                                   0x904920
#define CListWnd__SetItemData_x                                    0x9048E0
#define CListWnd__SetItemText_x                                    0x904510
#define CListWnd__ShiftColumnSeparator_x                           0x903080
#define CListWnd__Sort_x                                           0x902D80
#define CListWnd__ToggleSel_x                                      0x904180

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x766140
#define CMapViewWnd__GetWorldCoordinates_x                         0x764850
#define CMapViewWnd__HandleLButtonDown_x                           0x7618B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x789440
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x789D20
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78A250
#define CMerchantWnd__SelectRecoverySlot_x                         0x78D080
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x787E20
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x792C70
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x789070

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x893130
#define CPacketScrambler__hton_x                                   0x893120

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91DF80
#define CSidlManager__FindScreenPieceTemplate_x                    0x91E390
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91E180
#define CSidlManager__CreateLabel_x                                0x7EABC0
#define CSidlManager__CreateXWndFromTemplate_x                     0x921460
#define CSidlManager__CreateXWndFromTemplate1_x                    0x921630
#define CSidlManager__CreateXWnd_x                                 0x7EAAF0
#define CSidlManager__CreateHotButtonWnd_x                         0x7EB0A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x91AAD0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x91A9D0
#define CSidlScreenWnd__ConvertToRes_x                             0x93FDF0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91A460
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91A150
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91A220
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91A2F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x91AF70
#define CSidlScreenWnd__EnableIniStorage_x                         0x91B440
#define CSidlScreenWnd__GetSidlPiece_x                             0x91B160
#define CSidlScreenWnd__Init1_x                                    0x919D60
#define CSidlScreenWnd__LoadIniInfo_x                              0x91B490
#define CSidlScreenWnd__LoadIniListWnd_x                           0x91BFF0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x919170
#define CSidlScreenWnd__StoreIniInfo_x                             0x91BB60
#define CSidlScreenWnd__StoreIniVis_x                              0x91BED0
#define CSidlScreenWnd__WndNotification_x                          0x91AE80
#define CSidlScreenWnd__GetChildItem_x                             0x91B3C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x90AC00
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B1A58

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x664DE0
#define CSkillMgr__GetSkillCap_x                                   0x664FC0
#define CSkillMgr__GetNameToken_x                                  0x664570

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x92AFA0
#define CSliderWnd__SetValue_x                                     0x92AE10
#define CSliderWnd__SetNumTicks_x                                  0x92AE70

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F0940

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x931BE0
#define CStmlWnd__CalculateHSBRange_x                              0x932C70
#define CStmlWnd__CalculateVSBRange_x                              0x932BE0
#define CStmlWnd__CanBreakAtCharacter_x                            0x936FB0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x937BA0
#define CStmlWnd__ForceParseNow_x                                  0x932180
#define CStmlWnd__GetNextTagPiece_x                                0x936F10
#define CStmlWnd__GetSTMLText_x                                    0x4F3450
#define CStmlWnd__GetVisibleText_x                                 0x9321A0
#define CStmlWnd__InitializeWindowVariables_x                      0x9379F0
#define CStmlWnd__MakeStmlColorTag_x                               0x931370
#define CStmlWnd__MakeWndNotificationTag_x                         0x9313E0
#define CStmlWnd__SetSTMLText_x                                    0x930440
#define CStmlWnd__StripFirstSTMLLines_x                            0x938D00
#define CStmlWnd__UpdateHistoryString_x                            0x937DB0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93C980
#define CTabWnd__DrawCurrentPage_x                                 0x93CFA0
#define CTabWnd__DrawTab_x                                         0x93CD70
#define CTabWnd__GetCurrentPage_x                                  0x93C1E0
#define CTabWnd__GetPageInnerRect_x                                0x93C420
#define CTabWnd__GetTabInnerRect_x                                 0x93C360
#define CTabWnd__GetTabRect_x                                      0x93C210
#define CTabWnd__InsertPage_x                                      0x93C610
#define CTabWnd__SetPage_x                                         0x93C4A0
#define CTabWnd__SetPageRect_x                                     0x93C8C0
#define CTabWnd__UpdatePage_x                                      0x93CC30
#define CTabWnd__GetPageFromTabIndex_x                             0x93CCB0
#define CTabWnd__GetCurrentTabIndex_x                              0x93C1D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x74B5D0
#define CPageWnd__SetTabText_x                                     0x949370

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8690

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x907A90
#define CTextureFont__GetTextExtent_x                              0x907C50

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x698830
#define CHtmlComponentWnd__ValidateUri_x                           0x72A2C0
#define CHtmlWnd__SetClientCallbacks_x                             0x605D80
#define CHtmlWnd__AddObserver_x                                    0x605DA0
#define CHtmlWnd__RemoveObserver_x                                 0x605E00
#define Window__getProgress_x                                      0x843A30
#define Window__getStatus_x                                        0x843A50
#define Window__getURI_x                                           0x843A60

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9458F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F4840

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AFE20
#define CXStr__CXStr1_x                                            0x47DD20
#define CXStr__CXStr3_x                                            0x8E0B80
#define CXStr__dCXStr_x                                            0x471B10
#define CXStr__operator_equal_x                                    0x8E0DB0
#define CXStr__operator_equal1_x                                   0x8E0DF0
#define CXStr__operator_plus_equal1_x                              0x8E1880

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x929220
#define CXWnd__BringToTop_x                                        0x90E420
#define CXWnd__Center_x                                            0x90DFA0
#define CXWnd__ClrFocus_x                                          0x90DDD0
#define CXWnd__Destroy_x                                           0x90DE80
#define CXWnd__DoAllDrawing_x                                      0x90A3B0
#define CXWnd__DrawChildren_x                                      0x90A380
#define CXWnd__DrawColoredRect_x                                   0x90A810
#define CXWnd__DrawTooltip_x                                       0x908EE0
#define CXWnd__DrawTooltipAtPoint_x                                0x908FA0
#define CXWnd__GetBorderFrame_x                                    0x90A670
#define CXWnd__GetChildWndAt_x                                     0x90E4C0
#define CXWnd__GetClientClipRect_x                                 0x90C670
#define CXWnd__GetScreenClipRect_x                                 0x90C740
#define CXWnd__GetScreenRect_x                                     0x90C910
#define CXWnd__GetTooltipRect_x                                    0x90A860
#define CXWnd__GetWindowTextA_x                                    0x499D30
#define CXWnd__IsActive_x                                          0x911370
#define CXWnd__IsDescendantOf_x                                    0x90D330
#define CXWnd__IsReallyVisible_x                                   0x90D360
#define CXWnd__IsType_x                                            0x90EB30
#define CXWnd__Move_x                                              0x90D3E0
#define CXWnd__Move1_x                                             0x90D490
#define CXWnd__ProcessTransition_x                                 0x90DF50
#define CXWnd__Refade_x                                            0x90D760
#define CXWnd__Resize_x                                            0x90D9F0
#define CXWnd__Right_x                                             0x90E1E0
#define CXWnd__SetFocus_x                                          0x90DD90
#define CXWnd__SetFont_x                                           0x90DE00
#define CXWnd__SetKeyTooltip_x                                     0x90E950
#define CXWnd__SetMouseOver_x                                      0x90B7D0
#define CXWnd__StartFade_x                                         0x90D200
#define CXWnd__GetChildItem_x                                      0x90E630
#define CXWnd__SetParent_x                                         0x90D0C0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x940ED0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9113B0
#define CXWndManager__DrawWindows_x                                0x9113D0
#define CXWndManager__GetKeyboardFlags_x                           0x913A80
#define CXWndManager__HandleKeyboardMsg_x                          0x913680
#define CXWndManager__RemoveWnd_x                                  0x913CC0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x914200

// CDBStr
#define CDBStr__GetString_x                                        0x5286D0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BAF50
#define EQ_Character__Cur_HP_x                                     0x4D10C0
#define EQ_Character__Cur_Mana_x                                   0x4D87D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BDE70
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B19F0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B1B40
#define EQ_Character__GetHPRegen_x                                 0x4DE730
#define EQ_Character__GetEnduranceRegen_x                          0x4DED40
#define EQ_Character__GetManaRegen_x                               0x4DF180
#define EQ_Character__Max_Endurance_x                              0x62BAC0
#define EQ_Character__Max_HP_x                                     0x4D0EF0
#define EQ_Character__Max_Mana_x                                   0x62B8C0
#define EQ_Character__doCombatAbility_x                            0x62DF80
#define EQ_Character__UseSkill_x                                   0x4E0F70
#define EQ_Character__GetConLevel_x                                0x624F40
#define EQ_Character__IsExpansionFlag_x                            0x58BA20
#define EQ_Character__TotalEffect_x                                0x4C44F0
#define EQ_Character__GetPCSpellAffect_x                           0x4BEA60
#define EQ_Character__SpellDuration_x                              0x4BE590
#define EQ_Character__FindItemByRecord_x                           0x4D66D0
#define EQ_Character__GetAdjustedSkill_x                           0x4D3E00
#define EQ_Character__GetBaseSkill_x                               0x4D4DA0
#define EQ_Character__CanUseItem_x                                 0x4D8AE0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B2430

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x641D90

//PcClient
#define PcClient__PcClient_x                                       0x622820

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B8BB0
#define CCharacterListWnd__EnterWorld_x                            0x4B85F0
#define CCharacterListWnd__Quit_x                                  0x4B8300
#define CCharacterListWnd__UpdateList_x                            0x4B8780

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x606FB0
#define EQ_Item__CreateItemTagString_x                             0x88CAE0
#define EQ_Item__IsStackable_x                                     0x8914E0
#define EQ_Item__GetImageNum_x                                     0x88E500
#define EQ_Item__CreateItemClient_x                                0x606160
#define EQ_Item__GetItemValue_x                                    0x88F730
#define EQ_Item__ValueSellMerchant_x                               0x892CD0
#define EQ_Item__IsKeyRingItem_x                                   0x890E30
#define EQ_Item__CanGoInBag_x                                      0x6070D0
#define EQ_Item__GetMaxItemCount_x                                 0x88FB00
#define EQ_Item__GetHeldItem_x                                     0x88E3D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x88C420

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x546B50
#define EQ_LoadingS__Array_x                                       0xBE7130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x62C420
#define EQ_PC__GetAlternateAbilityId_x                             0x89BEE0
#define EQ_PC__GetCombatAbility_x                                  0x89C550
#define EQ_PC__GetCombatAbilityTimer_x                             0x89C5C0
#define EQ_PC__GetItemRecastTimer_x                                0x62E500
#define EQ_PC__HasLoreItem_x                                       0x625710
#define EQ_PC__AlertInventoryChanged_x                             0x624A20
#define EQ_PC__GetPcZoneClient_x                                   0x6504C0
#define EQ_PC__RemoveMyAffect_x                                    0x631700
#define EQ_PC__GetKeyRingItems_x                                   0x89CE60
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x89CBE0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x89D150

// EQItemList 
#define EQItemList__EQItemList_x                                   0x591F20
#define EQItemList__add_object_x                                   0x5BD8F0
#define EQItemList__add_item_x                                     0x592530
#define EQItemList__delete_item_x                                  0x592580
#define EQItemList__FreeItemList_x                                 0x592480

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x525D00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x643610
#define EQPlayer__dEQPlayer_x                                      0x636D30
#define EQPlayer__DoAttack_x                                       0x64B1C0
#define EQPlayer__EQPlayer_x                                       0x6373E0
#define EQPlayer__SetNameSpriteState_x                             0x63B650
#define EQPlayer__SetNameSpriteTint_x                              0x63C510
#define PlayerBase__HasProperty_j_x                                0x973B60
#define EQPlayer__IsTargetable_x                                   0x974000
#define EQPlayer__CanSee_x                                         0x973E60
#define EQPlayer__CanSee1_x                                        0x973F30
#define PlayerBase__GetVisibilityLineSegment_x                     0x973C20

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64DF90
#define PlayerZoneClient__GetLevel_x                               0x650500
#define PlayerZoneClient__IsValidTeleport_x                        0x5BEA50
#define PlayerZoneClient__LegalPlayerRace_x                        0x53FE70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x646300
#define EQPlayerManager__GetSpawnByName_x                          0x646320
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6463B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60A850
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60A890
#define KeypressHandler__ClearCommandStateArray_x                  0x60BC80
#define KeypressHandler__HandleKeyDown_x                           0x60BCA0
#define KeypressHandler__HandleKeyUp_x                             0x60BD40
#define KeypressHandler__SaveKeymapping_x                          0x60C120

// MapViewMap 
#define MapViewMap__Clear_x                                        0x761FD0
#define MapViewMap__SaveEx_x                                       0x765370
#define MapViewMap__SetZoom_x                                      0x769A40

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B0270

// StringTable 
#define StringTable__getString_x                                   0x8AB170

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x631370
#define PcZoneClient__RemovePetEffect_x                            0x6319A0
#define PcZoneClient__HasAlternateAbility_x                        0x62B700
#define PcZoneClient__GetCurrentMod_x                              0x4E4060
#define PcZoneClient__GetModCap_x                                  0x4E3F60
#define PcZoneClient__CanEquipItem_x                               0x62BDB0
#define PcZoneClient__GetItemByID_x                                0x62E980
#define PcZoneClient__GetItemByItemClass_x                         0x62EAD0
#define PcZoneClient__RemoveBuffEffect_x                           0x6319C0
#define PcZoneClient__BandolierSwap_x                              0x62C9E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C35E0

//IconCache
#define IconCache__GetIcon_x                                       0x702CF0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6FA7F0
#define CContainerMgr__CloseContainer_x                            0x6FAAC0
#define CContainerMgr__OpenExperimentContainer_x                   0x6FB540

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BD2B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FF1F0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7583E0
#define CLootWnd__RequestLootSlot_x                                0x7577A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55F0D0
#define EQ_Spell__SpellAffects_x                                   0x55F540
#define EQ_Spell__SpellAffectBase_x                                0x55F300
#define EQ_Spell__IsStackable_x                                    0x4C8CB0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C8B60
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B5F20
#define EQ_Spell__IsSPAStacking_x                                  0x560370
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55F890
#define EQ_Spell__IsNoRemove_x                                     0x4C8C90
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x560380
#define __IsResEffectSpell_x                                       0x4C8030

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AC7D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8BA890

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x802AC0
#define CTargetWnd__WndNotification_x                              0x802350
#define CTargetWnd__RefreshTargetBuffs_x                           0x802620
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8014A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x807190

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55A650
#define EqSoundManager__PlayScriptMp3_x                            0x55A7B0
#define EqSoundManager__SoundAssistPlay_x                          0x668D80
#define EqSoundManager__WaveInstancePlay_x                         0x6682F0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5175A0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92C990

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54E7E0
#define CAltAbilityData__GetMercMaxRank_x                          0x54E780
#define CAltAbilityData__GetMaxRank_x                              0x543C70

//CTargetRing
#define CTargetRing__Cast_x                                        0x5FD300

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C8B40
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FD740
#define CharacterBase__CreateItemIndex_x                           0x6053C0
#define CharacterBase__GetItemPossession_x                         0x4B5DD0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C2F10
#define CharacterBase__GetEffectId_x                               0x4C8AF0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E2A00
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E3220

//messages
#define msg_spell_worn_off_x                                       0x583A10
#define msg_new_text_x                                             0x578910
#define __msgTokenTextParam_x                                      0x586060
#define msgTokenText_x                                             0x5862B0

//SpellManager
#define SpellManager__vftable_x                                    0xAAE990
#define SpellManager__SpellManager_x                               0x66C0C0
#define Spellmanager__LoadTextSpells_x                             0x66C990
#define SpellManager__GetSpellByGroupAndRank_x                     0x66C290

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x977B20

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FDE20
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58A090
#define ItemGlobalIndex__IsEquippedLocation_x                      0x61DFD0
#define ItemGlobalIndex__IsValidIndex_x                            0x4FDE80

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8BB1D0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8BB450

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x750F20

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FEF30
#define CCursorAttachment__Deactivate_x                            0x6FFF00

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93EF70
#define CEQSuiteTextureLoader__GetTexture_x                        0x93EC30

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FADE0

//IString
#define IString__Append_x                                          0x4ED6C0

//Camera
#define CDisplay__cameraType_x                                     0xDBFCD8
#define EverQuest__Cameras_x                                       0xE82F10

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5034F0
#define LootFiltersManager__GetItemFilterData_x                    0x502DF0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x502E20
#define LootFiltersManager__SetItemLootFilter_x                    0x503040

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7AB2F0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97D810
#define CResolutionHandler__GetWindowedStyle_x                     0x6637F0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F75C0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CD970

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7176D0
#define CGroupWnd__UpdateDisplay_x                                 0x716A30

//ItemBase
#define ItemBase__IsLore_x                                         0x890E90
#define ItemBase__IsLoreEquipped_x                                 0x890F00

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
