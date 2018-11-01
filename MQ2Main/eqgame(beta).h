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
#define __ExpectedVersionDate                                     "Oct 31 2018"
#define __ExpectedVersionTime                                     "04:19:59"
#define __ActualVersionDate_x                                      0xAC6AF4
#define __ActualVersionTime_x                                      0xAC6AE8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60D760
#define __MemChecker1_x                                            0x8E1AE0
#define __MemChecker2_x                                            0x69C5A0
#define __MemChecker3_x                                            0x69C4F0
#define __MemChecker4_x                                            0x839510
#define __EncryptPad0_x                                            0xBF9990
#define __EncryptPad1_x                                            0xC57C20
#define __EncryptPad2_x                                            0xC0A518
#define __EncryptPad3_x                                            0xC0A118
#define __EncryptPad4_x                                            0xC48490
#define __EncryptPad5_x                                            0xF13B18
#define __AC1_x                                                    0x7F58C6
#define __AC2_x                                                    0x5C889F
#define __AC3_x                                                    0x5CF72F
#define __AC4_x                                                    0x5D35B0
#define __AC5_x                                                    0x5D976F
#define __AC6_x                                                    0x5DDCA6
#define __AC7_x                                                    0x5C8310
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1BBB70

// Direct Input
#define DI8__Main_x                                                0xF13B44
#define DI8__Keyboard_x                                            0xF13B48
#define DI8__Mouse_x                                               0xF13B24
#define DI8__Mouse_Copy_x                                          0xE7186C
#define DI8__Mouse_Check_x                                         0xF14A0C
#define __AutoSkillArray_x                                         0xE72784
#define __Attack_x                                                 0xF10587
#define __Autofire_x                                               0xF10588
#define __BindList_x                                               0xBE8588
#define g_eqCommandStates_x                                        0xBE92F8
#define __Clicks_x                                                 0xE71924
#define __CommandList_x                                            0xBE9EB0
#define __CurrentMapLabel_x                                        0x1026134
#define __CurrentSocial_x                                          0xBD3728
#define __DoAbilityList_x                                          0xEA80A8
#define __do_loot_x                                                0x596180
#define __DrawHandler_x                                            0x16A2B08
#define __GroupCount_x                                             0xE62212
#define __Guilds_x                                                 0xE68078
#define __gWorld_x                                                 0xE62400
#define __HWnd_x                                                   0xF13B28
#define __heqmain_x                                                0x101ED68
#define __InChatMode_x                                             0xE71854
#define __LastTell_x                                               0xE737A4
#define __LMouseHeldTime_x                                         0xE71990
#define __Mouse_x                                                  0xF13B2C
#define __MouseLook_x                                              0xE718EA
#define __MouseEventTime_x                                         0xF11040
#define __gpbCommandEvent_x                                        0xE61CB0
#define __NetStatusToggle_x                                        0xE718ED
#define __PCNames_x                                                0xE72D64
#define __RangeAttackReady_x                                       0xE72A68
#define __RMouseHeldTime_x                                         0xE7198C
#define __RunWalkState_x                                           0xE71858
#define __ScreenMode_x                                             0xDAFC04
#define __ScreenX_x                                                0xE7180C
#define __ScreenY_x                                                0xE71808
#define __ScreenXMax_x                                             0xE71810
#define __ScreenYMax_x                                             0xE71814
#define __ServerHost_x                                             0xE61E1B
#define __ServerName_x                                             0xEA8068
#define __ShiftKeyDown_x                                           0xE71EE4
#define __ShowNames_x                                              0xE72C24
#define __Socials_x                                                0xEA8168
#define __SubscriptionType_x                                       0x1067C84
#define __TargetAggroHolder_x                                      0x1028AF0
#define __ZoneType_x                                               0xE71CE8
#define __GroupAggro_x                                             0x1028B30
#define __LoginName_x                                              0xF1439C
#define __Inviter_x                                                0xF10504
#define __AttackOnAssist_x                                         0xE72BE0
#define __UseTellWindows_x                                         0xE72EFC
#define __gfMaxZoomCameraDistance_x                                0xABBEE0
#define __gfMaxCameraDistance_x                                    0xAE9514
#define __pulAutoRun_x                                             0xE71908
#define __pulForward_x                                             0xE72F34
#define __pulBackward_x                                            0xE72F38
#define __pulTurnRight_x                                           0xE72F3C
#define __pulTurnLeft_x                                            0xE72F40
#define __pulStrafeLeft_x                                          0xE72F44
#define __pulStrafeRight_x                                         0xE72F48
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE64410
#define instEQZoneInfo_x                                           0xE71AE0
#define instKeypressHandler_x                                      0xF10FF0
#define pinstActiveBanker_x                                        0xE62148
#define pinstActiveCorpse_x                                        0xE6213C
#define pinstActiveGMaster_x                                       0xE62144
#define pinstActiveMerchant_x                                      0xE62134
#define pinstAggroInfo_x                                           0xC6E408
#define pinstAltAdvManager_x                                       0xDB0DB0
#define pinstAuraMgr_x                                             0xC7F0F0
#define pinstBandageTarget_x                                       0xE62180
#define pinstCamActor_x                                            0xDAFBF8
#define pinstCDBStr_x                                              0xDAFAE4
#define pinstCDisplay_x                                            0xE621DC
#define pinstCEverQuest_x                                          0xF13C64
#define pinstEverQuestInfo_x                                       0xE71800
#define pinstCharData_x                                            0xE621E8
#define pinstCharSpawn_x                                           0xE621CC
#define pinstControlledMissile_x                                   0xE621E4
#define pinstControlledPlayer_x                                    0xE621CC
#define pinstCResolutionHandler_x                                  0x16A2D38
#define pinstCSidlManager_x                                        0x16A1BCC
#define pinstCXWndManager_x                                        0x16A1BC0
#define instDynamicZone_x                                          0xE67F50
#define pinstDZMember_x                                            0xE68060
#define pinstDZTimerInfo_x                                         0xE68064
#define pinstEQItemList_x                                          0xE60600
#define pinstEQObjectList_x                                        0xE617F0
#define instEQMisc_x                                               0xDAFA20
#define pinstEQSoundManager_x                                      0xDB1610
#define pinstEQSpellStrings_x                                      0xC7C540
#define instExpeditionLeader_x                                     0xE67F9A
#define instExpeditionName_x                                       0xE67FDA
#define pinstGroup_x                                               0xE6220E
#define pinstImeManager_x                                          0x16A1BC4
#define pinstLocalPlayer_x                                         0xE62130
#define pinstMercenaryData_x                                       0xF117EC
#define pinstMercenaryStats_x                                      0x1028C3C
#define pinstMercAltAbilities_x                                    0xDB1380
#define pinstModelPlayer_x                                         0xE62150
#define pinstPCData_x                                              0xE621E8
#define pinstRealEstateItems_x                                     0xF12CD0
#define pinstSkillMgr_x                                            0xF12DA0
#define pinstSpawnManager_x                                        0xF12390
#define pinstSpellManager_x                                        0xF12F78
#define pinstSpellSets_x                                           0xF091B0
#define pinstStringTable_x                                         0xE61B04
#define pinstSwitchManager_x                                       0xE619B0
#define pinstTarget_x                                              0xE621C8
#define pinstTargetObject_x                                        0xE621D8
#define pinstTargetSwitch_x                                        0xE621F4
#define pinstTaskMember_x                                          0xDAF8B4
#define pinstTrackTarget_x                                         0xE621D0
#define pinstTradeTarget_x                                         0xE6214C
#define instTributeActive_x                                        0xDAFA45
#define pinstViewActor_x                                           0xDAFBF4
#define pinstWorldData_x                                           0xE621EC
#define pinstZoneAddr_x                                            0xE71D80
#define pinstPlayerPath_x                                          0xF12428
#define pinstTargetIndicator_x                                     0xF131E0
#define pinstCTargetManager_x                                      0xF13278
#define EQObject_Top_x                                             0xE61D10

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDAFB90
#define pinstCAchievementsWnd_x                                    0xDAFC84
#define pinstCActionsWnd_x                                         0xDAFBEC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDAFB94
#define pinstCAdvancedLootWnd_x                                    0xDB03F8
#define pinstCAdventureLeaderboardWnd_x                            0x101F908
#define pinstCAdventureRequestWnd_x                                0x101F9B8
#define pinstCAdventureStatsWnd_x                                  0x101FA68
#define pinstCAggroMeterWnd_x                                      0xDAFC98
#define pinstCAlarmWnd_x                                           0xDAFC54
#define pinstCAlertHistoryWnd_x                                    0xDAFC40
#define pinstCAlertStackWnd_x                                      0xDAFBB4
#define pinstCAlertWnd_x                                           0xDAFBCC
#define pinstCAltStorageWnd_x                                      0x101FDC8
#define pinstCAudioTriggersWindow_x                                0xC6E898
#define pinstCAuraWnd_x                                            0xDAFC94
#define pinstCAvaZoneWnd_x                                         0xDAFC44
#define pinstCBandolierWnd_x                                       0xDAFED0
#define pinstCBankWnd_x                                            0xDB03B4
#define pinstCBarterMerchantWnd_x                                  0x1021008
#define pinstCBarterSearchWnd_x                                    0x10210B8
#define pinstCBarterWnd_x                                          0x1021168
#define pinstCBazaarConfirmationWnd_x                              0xDAFBB0
#define pinstCBazaarSearchWnd_x                                    0xDAFC20
#define pinstCBazaarWnd_x                                          0xDAFEC8
#define pinstCBlockedBuffWnd_x                                     0xDAFF2C
#define pinstCBlockedPetBuffWnd_x                                  0xDB03BC
#define pinstCBodyTintWnd_x                                        0xDAFBC8
#define pinstCBookWnd_x                                            0xDAFEF0
#define pinstCBreathWnd_x                                          0xDAFB98
#define pinstCBuffWindowNORMAL_x                                   0xDAFEFC
#define pinstCBuffWindowSHORT_x                                    0xDAFF00
#define pinstCBugReportWnd_x                                       0xDAFB8C
#define pinstCButtonWnd_x                                          0x16A1DF0
#define pinstCCastingWnd_x                                         0xDAFB88
#define pinstCCastSpellWnd_x                                       0xDAFC2C
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDAFBA4
#define pinstCChatWindowManager_x                                  0x1021C28
#define pinstCClaimWnd_x                                           0x1021D80
#define pinstCColorPickerWnd_x                                     0xDAFBD0
#define pinstCCombatAbilityWnd_x                                   0xDAFCA0
#define pinstCCombatSkillsSelectWnd_x                              0xDAFBE8
#define pinstCCompassWnd_x                                         0xDAFBA8
#define pinstCConfirmationDialog_x                                 0x1026C80
#define pinstCContainerMgr_x                                       0xDAFEC0
#define pinstCContextMenuManager_x                                 0x16A1B80
#define pinstCCursorAttachment_x                                   0xDAFB80
#define pinstCDistillerInfo_x                                      0x102568C
#define pinstCDynamicZoneWnd_x                                     0x1022348
#define pinstCEditLabelWnd_x                                       0xDAFEF4
#define pinstCEQMainWnd_x                                          0x1022590
#define pinstCEventCalendarWnd_x                                   0xDAFECC
#define pinstCExtendedTargetWnd_x                                  0xDAFC7C
#define pinstCFacePick_x                                           0xDAFBD4
#define pinstCFellowshipWnd_x                                      0x1022790
#define pinstCFileSelectionWnd_x                                   0xDB03B8
#define pinstCFindItemWnd_x                                        0xDAFEE0
#define pinstCFindLocationWnd_x                                    0x10228E8
#define pinstCFriendsWnd_x                                         0xDAFC1C
#define pinstCGemsGameWnd_x                                        0xDAFC28
#define pinstCGiveWnd_x                                            0xDAFEE8
#define pinstCGroupSearchFiltersWnd_x                              0xDAFEAC
#define pinstCGroupSearchWnd_x                                     0x1022CE0
#define pinstCGroupWnd_x                                           0x1022D90
#define pinstCGuildBankWnd_x                                       0xE72BC4
#define pinstCGuildCreationWnd_x                                   0x1022EF0
#define pinstCGuildMgmtWnd_x                                       0x1022FA0
#define pinstCharacterCreation_x                                   0xDAFC9C
#define pinstCHelpWnd_x                                            0xDAFC4C
#define pinstCHeritageSelectionWnd_x                               0xDAFBE0
#define pinstCHotButtonWnd_x                                       0x10250F8
#define pinstCHotButtonWnd1_x                                      0x10250F8
#define pinstCHotButtonWnd2_x                                      0x10250FC
#define pinstCHotButtonWnd3_x                                      0x1025100
#define pinstCHotButtonWnd4_x                                      0x1025104
#define pinstCIconSelectionWnd_x                                   0xDB03E8
#define pinstCInspectWnd_x                                         0xDB03C0
#define pinstCInventoryWnd_x                                       0xDAFED4
#define pinstCInvSlotMgr_x                                         0xDAFC60
#define pinstCItemDisplayManager_x                                 0x1025688
#define pinstCItemExpTransferWnd_x                                 0x10257B8
#define pinstCItemOverflowWnd_x                                    0xDAFC24
#define pinstCJournalCatWnd_x                                      0xDB040C
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDAFF1C
#define pinstCKeyRingWnd_x                                         0xDAFF14
#define pinstCLargeDialogWnd_x                                     0x1027900
#define pinstCLayoutCopyWnd_x                                      0x1025B08
#define pinstCLFGuildWnd_x                                         0x1025BB8
#define pinstCLoadskinWnd_x                                        0xDAFC38
#define pinstCLootFiltersCopyWnd_x                                 0xC7F978
#define pinstCLootFiltersWnd_x                                     0xDAFBDC
#define pinstCLootSettingsWnd_x                                    0xDAFBF0
#define pinstCLootWnd_x                                            0xDAFBC0
#define pinstCMailAddressBookWnd_x                                 0xDB03F0
#define pinstCMailCompositionWnd_x                                 0xDB03AC
#define pinstCMailIgnoreListWnd_x                                  0xDB03F4
#define pinstCMailWnd_x                                            0xDAFF0C
#define pinstCManageLootWnd_x                                      0xDB1228
#define pinstCMapToolbarWnd_x                                      0xDAFED8
#define pinstCMapViewWnd_x                                         0xDAFEB4
#define pinstCMarketplaceWnd_x                                     0xDAFEE4
#define pinstCMerchantWnd_x                                        0xDAFBE4
#define pinstCMIZoneSelectWnd_x                                    0x10263F0
#define pinstCMusicPlayerWnd_x                                     0xDAFF10
#define pinstCNameChangeMercWnd_x                                  0xDB0410
#define pinstCNameChangePetWnd_x                                   0xDB03EC
#define pinstCNameChangeWnd_x                                      0xDAFEB8
#define pinstCNoteWnd_x                                            0xDAFC3C
#define pinstCObjectPreviewWnd_x                                   0xDAFF04
#define pinstCOptionsWnd_x                                         0xDAFEDC
#define pinstCPetInfoWnd_x                                         0xDAFFA0
#define pinstCPetitionQWnd_x                                       0xDAFB84
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDAFBC4
#define pinstCPlayerWnd_x                                          0xDAFC14
#define pinstCPopupWndManager_x                                    0x1026C80
#define pinstCProgressionSelectionWnd_x                            0x1026D30
#define pinstCPurchaseGroupWnd_x                                   0xDB03A8
#define pinstCPurchaseWnd_x                                        0xDAFF08
#define pinstCPvPLeaderboardWnd_x                                  0x1026DE0
#define pinstCPvPStatsWnd_x                                        0x1026E90
#define pinstCQuantityWnd_x                                        0xDB0400
#define pinstCRaceChangeWnd_x                                      0xDAFEEC
#define pinstCRaidOptionsWnd_x                                     0xDAFEB0
#define pinstCRaidWnd_x                                            0xDB0404
#define pinstCRealEstateItemsWnd_x                                 0xDAFC8C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDAFEC4
#define pinstCRealEstateManageWnd_x                                0xDAFC10
#define pinstCRealEstateNeighborhoodWnd_x                          0xDAFC30
#define pinstCRealEstatePlotSearchWnd_x                            0xDAFC48
#define pinstCRealEstatePurchaseWnd_x                              0xDAFC64
#define pinstCRespawnWnd_x                                         0xDAFEA8
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDAFC80
#define pinstCSendMoneyWnd_x                                       0xDAFEF8
#define pinstCServerListWnd_x                                      0xDAFC90
#define pinstCSkillsSelectWnd_x                                    0xDAFBD8
#define pinstCSkillsWnd_x                                          0xDAFBBC
#define pinstCSocialEditWnd_x                                      0xDB0408
#define pinstCSocialWnd_x                                          0xDAFB9C
#define pinstCSpellBookWnd_x                                       0xDAFC78
#define pinstCStoryWnd_x                                           0xDAFBA0
#define pinstCTargetOfTargetWnd_x                                  0x1028CC0
#define pinstCTargetWnd_x                                          0xDAFF9C
#define pinstCTaskOverlayWnd_x                                     0xDAFC50
#define pinstCTaskSelectWnd_x                                      0x1028E18
#define pinstCTaskSomething_x                                      0xC80178
#define pinstCTaskTemplateSelectWnd_x                              0x1028EC8
#define pinstCTaskWnd_x                                            0x1028F78
#define pinstCTextEntryWnd_x                                       0xDAFBAC
#define pinstCTextOverlay_x                                        0xC6EBA8
#define pinstCTimeLeftWnd_x                                        0xDB03DC
#define pinstCTipWndCONTEXT_x                                      0x102917C
#define pinstCTipWndOFDAY_x                                        0x1029178
#define pinstCTitleWnd_x                                           0x1029228
#define pinstCTrackingWnd_x                                        0xDAFF34
#define pinstCTradeskillWnd_x                                      0x1029390
#define pinstCTradeWnd_x                                           0xDAFC58
#define pinstCTrainWnd_x                                           0xDB03FC
#define pinstCTributeBenefitWnd_x                                  0x1029590
#define pinstCTributeMasterWnd_x                                   0x1029640
#define pinstCTributeTrophyWnd_x                                   0x10296F0
#define pinstCVideoModesWnd_x                                      0xDAFC5C
#define pinstCVoiceMacroWnd_x                                      0xF137A8
#define pinstCVoteResultsWnd_x                                     0xDB03B0
#define pinstCVoteWnd_x                                            0xDAFF18
#define pinstCWebManager_x                                         0xF1390C
#define pinstCZoneGuideWnd_x                                       0xDAFC18
#define pinstCZonePathWnd_x                                        0xDAFC34

#define pinstEQSuiteTextureLoader_x                                0xC596F0
#define pinstItemIconCache_x                                       0x1022548
#define pinstLootFiltersManager_x                                  0xC7FA28
#define pinstRewardSelectionWnd_x                                  0x10275D8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0A10C
#define __CastRay_x                                                0x5916A0
#define __CastRay2_x                                               0x5916F0
#define __ConvertItemTags_x                                        0x5AC290
#define __CrashHandler_x                                           0x842EE0
#define __EQGetTime_x                                              0x8E15D0
#define __ExecuteCmd_x                                             0x58A030
#define __FixHeading_x                                             0x9721E0
#define __get_bearing_x                                            0x5911E0
#define __get_melee_range_x                                        0x5918E0
#define __GetAnimationCache_x                                      0x7002A0
#define __GetGaugeValueFromEQ_x                                    0x7F40E0
#define __GetLabelFromEQ_x                                         0x7F5850
#define __GetXTargetType_x                                         0x973D80
#define __HeadingDiff_x                                            0x972250
#define __HelpPath_x                                               0xF10C5C
#define __LoadFrontEnd_x                                           0x698400
#define __NewUIINI_x                                               0x7F3DB0
#define __pCrashHandler_x                                          0x1046AE0
#define __ProcessGameEvents_x                                      0x5EED20
#define __ProcessMouseEvent_x                                      0x5EE4E0
#define __SaveColors_x                                             0x53B1F0
#define __STMLToText_x                                             0x915170
#define __ToggleKeyRingItem_x                                      0x4FE5D0
#define CrashDetected_x                                            0x699EF0
#define DrawNetStatus_x                                            0x61AD60
#define Expansion_HoT_x                                            0xE72BCC
#define Teleport_Table_Size_x                                      0xE61CBC
#define Teleport_Table_x                                           0xE62410
#define Util__FastTime_x                                           0x8E1190
#define wwsCrashReportCheckForUploader_x                           0x843990
#define wwsCrashReportPlatformLaunchUploader_x                     0x846080
#define __HandleMouseWheel_x                                       0x69C650

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AFD0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493DD0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493BB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x542BD0
#define AltAdvManager__IsAbilityReady_x                            0x541C50
#define AltAdvManager__GetAAById_x                                 0x541E50
#define AltAdvManager__CanTrainAbility_x                           0x541EC0
#define AltAdvManager__CanSeeAbility_x                             0x5420F0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6B90
#define CharacterZoneClient__HasSkill_x                            0x4D1850
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2F70
#define CharacterZoneClient__IsStackBlocked_x                      0x4BAF20
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B76A0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5920
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5A00
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5AE0
#define CharacterZoneClient__FindAffectSlot_x                      0x4BFA00
#define CharacterZoneClient__BardCastBard_x                        0x4C2670
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7770
#define CharacterZoneClient__GetEffect_x                           0x4B75E0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0A00
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0AD0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0B20
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0C70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0E40

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C27A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CFF30

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FD3B0
#define CButtonWnd__CButtonWnd_x                                   0x911560

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EEC90
#define CChatManager__InitContextMenu_x                            0x6E8D30
#define CChatManager__FreeChatWindow_x                             0x6EDBA0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F2540
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EEA30

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x925CE0
#define CContextMenu__dCContextMenu_x                              0x925F10
#define CContextMenu__AddMenuItem_x                                0x925F20
#define CContextMenu__RemoveMenuItem_x                             0x926230
#define CContextMenu__RemoveAllMenuItems_x                         0x926250
#define CContextMenu__CheckMenuItem_x                              0x9262D0
#define CContextMenu__SetMenuItem_x                                0x926150
#define CContextMenu__AddSeparator_x                               0x9260B0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x926870
#define CContextMenuManager__RemoveMenu_x                          0x9268E0
#define CContextMenuManager__PopupMenu_x                           0x9269A0
#define CContextMenuManager__Flush_x                               0x926810
#define CContextMenuManager__GetMenu_x                             0x495EB0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C1FE0
#define CChatService__GetFriendName_x                              0x8C1FF0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EF200
#define CChatWindow__Clear_x                                       0x6F0260
#define CChatWindow__WndNotification_x                             0x6F07D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x923170
#define CComboWnd__Draw_x                                          0x922660
#define CComboWnd__GetCurChoice_x                                  0x922FB0
#define CComboWnd__GetListRect_x                                   0x922B10
#define CComboWnd__GetTextRect_x                                   0x9231E0
#define CComboWnd__InsertChoice_x                                  0x922CA0
#define CComboWnd__SetColors_x                                     0x922C70
#define CComboWnd__SetChoice_x                                     0x922F80
#define CComboWnd__GetItemCount_x                                  0x922FC0
#define CComboWnd__GetCurChoiceText_x                              0x923000

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F8470
#define CContainerWnd__vftable_x                                   0xACFEF8
#define CContainerWnd__SetContainer_x                              0x6F99E0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53AFB0
#define CDisplay__GetClickedActor_x                                0x52DFB0
#define CDisplay__GetUserDefinedColor_x                            0x526690
#define CDisplay__GetWorldFilePath_x                               0x52FA00
#define CDisplay__is3dON_x                                         0x52AC80
#define CDisplay__ReloadUI_x                                       0x535120
#define CDisplay__WriteTextHD2_x                                   0x52AA60
#define CDisplay__TrueDistance_x                                   0x531660
#define CDisplay__SetViewActor_x                                   0x52D900
#define CDisplay__GetFloorHeight_x                                 0x52AD40
#define CDisplay__SetRenderWindow_x                                0x529670
#define CDisplay__ToggleScreenshotMode_x                           0x52D3D0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9457D0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92A400
#define CEditWnd__GetCharIndexPt_x                                 0x92B300
#define CEditWnd__GetDisplayString_x                               0x92B1A0
#define CEditWnd__GetHorzOffset_x                                  0x929A30
#define CEditWnd__GetLineForPrintableChar_x                        0x92C440
#define CEditWnd__GetSelStartPt_x                                  0x92B5B0
#define CEditWnd__GetSTMLSafeText_x                                0x92AFC0
#define CEditWnd__PointFromPrintableChar_x                         0x92C070
#define CEditWnd__SelectableCharFromPoint_x                        0x92C1E0
#define CEditWnd__SetEditable_x                                    0x92B680

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DD1D0
#define CEverQuest__ClickedPlayer_x                                0x5CF510
#define CEverQuest__CreateTargetIndicator_x                        0x5EBFD0
#define CEverQuest__DeleteTargetIndicator_x                        0x5EC060
#define CEverQuest__DoTellWindow_x                                 0x4E2CD0
#define CEverQuest__OutputTextToLog_x                              0x4E2F00
#define CEverQuest__DropHeldItemOnGround_x                         0x5C4DE0
#define CEverQuest__dsp_chat_x                                     0x4E3290
#define CEverQuest__trimName_x                                     0x5E8540
#define CEverQuest__Emote_x                                        0x5DD9E0
#define CEverQuest__EnterZone_x                                    0x5D7BC0
#define CEverQuest__GetBodyTypeDesc_x                              0x5E1DE0
#define CEverQuest__GetClassDesc_x                                 0x5E2420
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E2A20
#define CEverQuest__GetDeityDesc_x                                 0x5EA920
#define CEverQuest__GetLangDesc_x                                  0x5E2BE0
#define CEverQuest__GetRaceDesc_x                                  0x5E2400
#define CEverQuest__InterpretCmd_x                                 0x5EAEF0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C8FC0
#define CEverQuest__LMouseUp_x                                     0x5C7340
#define CEverQuest__RightClickedOnPlayer_x                         0x5C98A0
#define CEverQuest__RMouseUp_x                                     0x5C82D0
#define CEverQuest__SetGameState_x                                 0x5C4B70
#define CEverQuest__UPCNotificationFlush_x                         0x5E8440
#define CEverQuest__IssuePetCommand_x                              0x5E3FE0
#define CEverQuest__ReportSuccessfulHit_x                          0x5DECC0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70A380
#define CGaugeWnd__CalcLinesFillRect_x                             0x70A3E0
#define CGaugeWnd__Draw_x                                          0x709A70

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC4D0
#define CGuild__GetGuildName_x                                     0x4AB5B0
#define CGuild__GetGuildIndex_x                                    0x4AB940

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x725700

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FD770

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7326F0
#define CInvSlotMgr__MoveItem_x                                    0x731410
#define CInvSlotMgr__SelectSlot_x                                  0x7327C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72FCB0
#define CInvSlot__SliderComplete_x                                 0x72DA20
#define CInvSlot__GetItemBase_x                                    0x72D390
#define CInvSlot__UpdateItem_x                                     0x72D500

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x734110
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7333E0
#define CInvSlotWnd__HandleLButtonUp_x                             0x733C90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F02C0
#define CItemDisplayWnd__UpdateStrings_x                           0x742210
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73C250
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73C780
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7427F0
#define CItemDisplayWnd__AboutToShow_x                             0x741E50
#define CItemDisplayWnd__WndNotification_x                         0x743B10

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x827DD0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x747CF0

// CLabel 
#define CLabel__Draw_x                                             0x74D760

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FB910
#define CListWnd__dCListWnd_x                                      0x8FBC30
#define CListWnd__AddColumn_x                                      0x8FFF70
#define CListWnd__AddColumn1_x                                     0x8FFFC0
#define CListWnd__AddLine_x                                        0x900350
#define CListWnd__AddString_x                                      0x900150
#define CListWnd__CalculateFirstVisibleLine_x                      0x8FFD30
#define CListWnd__CalculateVSBRange_x                              0x8FFB10
#define CListWnd__ClearSel_x                                       0x900B30
#define CListWnd__ClearAllSel_x                                    0x900B90
#define CListWnd__CloseAndUpdateEditWindow_x                       0x901590
#define CListWnd__Compare_x                                        0x8FF450
#define CListWnd__Draw_x                                           0x8FBD30
#define CListWnd__DrawColumnSeparators_x                           0x8FE520
#define CListWnd__DrawHeader_x                                     0x8FE990
#define CListWnd__DrawItem_x                                       0x8FED90
#define CListWnd__DrawLine_x                                       0x8FE690
#define CListWnd__DrawSeparator_x                                  0x8FE5C0
#define CListWnd__EnableLine_x                                     0x8FDDF0
#define CListWnd__EnsureVisible_x                                  0x9014B0
#define CListWnd__ExtendSel_x                                      0x900A60
#define CListWnd__GetColumnMinWidth_x                              0x8FD930
#define CListWnd__GetColumnWidth_x                                 0x8FD8A0
#define CListWnd__GetCurSel_x                                      0x8FD230
#define CListWnd__GetItemAtPoint_x                                 0x8FE070
#define CListWnd__GetItemAtPoint1_x                                0x8FE0E0
#define CListWnd__GetItemData_x                                    0x8FD2B0
#define CListWnd__GetItemHeight_x                                  0x8FD670
#define CListWnd__GetItemIcon_x                                    0x8FD440
#define CListWnd__GetItemRect_x                                    0x8FDEE0
#define CListWnd__GetItemText_x                                    0x8FD2F0
#define CListWnd__GetSelList_x                                     0x900BE0
#define CListWnd__GetSeparatorRect_x                               0x8FE320
#define CListWnd__InsertLine_x                                     0x900740
#define CListWnd__RemoveLine_x                                     0x900890
#define CListWnd__SetColors_x                                      0x8FFAE0
#define CListWnd__SetColumnJustification_x                         0x8FF810
#define CListWnd__SetColumnWidth_x                                 0x8FF730
#define CListWnd__SetCurSel_x                                      0x9009A0
#define CListWnd__SetItemColor_x                                   0x901160
#define CListWnd__SetItemData_x                                    0x901120
#define CListWnd__SetItemText_x                                    0x900D60
#define CListWnd__ShiftColumnSeparator_x                           0x8FF8D0
#define CListWnd__Sort_x                                           0x8FF5D0
#define CListWnd__ToggleSel_x                                      0x9009D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x762CD0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7613E0
#define CMapViewWnd__HandleLButtonDown_x                           0x75E440

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x786160
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x786A40
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x786F70
#define CMerchantWnd__SelectRecoverySlot_x                         0x789DB0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x784B40
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x78F940
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x785D90

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88FEE0
#define CPacketScrambler__hton_x                                   0x88FED0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91A760
#define CSidlManager__FindScreenPieceTemplate_x                    0x91AB70
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91A960
#define CSidlManager__CreateLabel_x                                0x7E7770
#define CSidlManager__CreateXWndFromTemplate_x                     0x91DC40
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91DE20
#define CSidlManager__CreateXWnd_x                                 0x7E76A0
#define CSidlManager__CreateHotButtonWnd_x                         0x7E7C70

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9172E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9171D0
#define CSidlScreenWnd__ConvertToRes_x                             0x93C670
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x916C60
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x916950
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x916A20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x916AF0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x917780
#define CSidlScreenWnd__EnableIniStorage_x                         0x917C50
#define CSidlScreenWnd__GetSidlPiece_x                             0x917970
#define CSidlScreenWnd__Init1_x                                    0x916540
#define CSidlScreenWnd__LoadIniInfo_x                              0x917CA0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9187D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x915950
#define CSidlScreenWnd__StoreIniInfo_x                             0x918350
#define CSidlScreenWnd__StoreIniVis_x                              0x9186B0
#define CSidlScreenWnd__WndNotification_x                          0x917690
#define CSidlScreenWnd__GetChildItem_x                             0x917BD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9073F0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A1A50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x661570
#define CSkillMgr__GetSkillCap_x                                   0x661750
#define CSkillMgr__GetNameToken_x                                  0x660D00

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x927670
#define CSliderWnd__SetValue_x                                     0x9274E0
#define CSliderWnd__SetNumTicks_x                                  0x927540

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7ED530

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x92E2F0
#define CStmlWnd__CalculateHSBRange_x                              0x92F380
#define CStmlWnd__CalculateVSBRange_x                              0x92F2F0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9336C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9342B0
#define CStmlWnd__ForceParseNow_x                                  0x92E890
#define CStmlWnd__GetNextTagPiece_x                                0x933620
#define CStmlWnd__GetSTMLText_x                                    0x4F1090
#define CStmlWnd__GetVisibleText_x                                 0x92E8B0
#define CStmlWnd__InitializeWindowVariables_x                      0x934100
#define CStmlWnd__MakeStmlColorTag_x                               0x92DA80
#define CStmlWnd__MakeWndNotificationTag_x                         0x92DAF0
#define CStmlWnd__SetSTMLText_x                                    0x92CB50
#define CStmlWnd__StripFirstSTMLLines_x                            0x935410
#define CStmlWnd__UpdateHistoryString_x                            0x9344C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x939180
#define CTabWnd__DrawCurrentPage_x                                 0x9397A0
#define CTabWnd__DrawTab_x                                         0x939570
#define CTabWnd__GetCurrentPage_x                                  0x9389E0
#define CTabWnd__GetPageInnerRect_x                                0x938C20
#define CTabWnd__GetTabInnerRect_x                                 0x938B60
#define CTabWnd__GetTabRect_x                                      0x938A10
#define CTabWnd__InsertPage_x                                      0x938E10
#define CTabWnd__SetPage_x                                         0x938CA0
#define CTabWnd__SetPageRect_x                                     0x9390C0
#define CTabWnd__UpdatePage_x                                      0x939430
#define CTabWnd__GetPageFromTabIndex_x                             0x9394B0
#define CTabWnd__GetCurrentTabIndex_x                              0x9389D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x748150
#define CPageWnd__SetTabText_x                                     0x945BE0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5FD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x904260
#define CTextureFont__GetTextExtent_x                              0x904420

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x695220
#define CHtmlComponentWnd__ValidateUri_x                           0x7270F0
#define CHtmlWnd__SetClientCallbacks_x                             0x602720
#define CHtmlWnd__AddObserver_x                                    0x602740
#define CHtmlWnd__RemoveObserver_x                                 0x6027A0
#define Window__getProgress_x                                      0x840B40
#define Window__getStatus_x                                        0x840B60
#define Window__getURI_x                                           0x840B70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x942160

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F1210

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD840
#define CXStr__CXStr1_x                                            0x8F9D20
#define CXStr__CXStr3_x                                            0x8DD700
#define CXStr__dCXStr_x                                            0x472870
#define CXStr__operator_equal_x                                    0x8DD930
#define CXStr__operator_equal1_x                                   0x8DD970
#define CXStr__operator_plus_equal1_x                              0x8DE400

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x925900
#define CXWnd__BringToTop_x                                        0x90AB20
#define CXWnd__Center_x                                            0x90A6A0
#define CXWnd__ClrFocus_x                                          0x90A4F0
#define CXWnd__Destroy_x                                           0x90A590
#define CXWnd__DoAllDrawing_x                                      0x906B80
#define CXWnd__DrawChildren_x                                      0x906B50
#define CXWnd__DrawColoredRect_x                                   0x906FE0
#define CXWnd__DrawTooltip_x                                       0x9056C0
#define CXWnd__DrawTooltipAtPoint_x                                0x905780
#define CXWnd__GetBorderFrame_x                                    0x906E40
#define CXWnd__GetChildWndAt_x                                     0x90ABC0
#define CXWnd__GetClientClipRect_x                                 0x908DF0
#define CXWnd__GetScreenClipRect_x                                 0x908EC0
#define CXWnd__GetScreenRect_x                                     0x909070
#define CXWnd__GetTooltipRect_x                                    0x907030
#define CXWnd__GetWindowTextA_x                                    0x497570
#define CXWnd__IsActive_x                                          0x90DA50
#define CXWnd__IsDescendantOf_x                                    0x909A70
#define CXWnd__IsReallyVisible_x                                   0x909AA0
#define CXWnd__IsType_x                                            0x90B230
#define CXWnd__Move_x                                              0x909B00
#define CXWnd__Move1_x                                             0x909BB0
#define CXWnd__ProcessTransition_x                                 0x90A650
#define CXWnd__Refade_x                                            0x909E80
#define CXWnd__Resize_x                                            0x90A100
#define CXWnd__Right_x                                             0x90A8E0
#define CXWnd__SetFocus_x                                          0x90A4B0
#define CXWnd__SetFont_x                                           0x90A520
#define CXWnd__SetKeyTooltip_x                                     0x90B050
#define CXWnd__SetMouseOver_x                                      0x907F70
#define CXWnd__StartFade_x                                         0x909940
#define CXWnd__GetChildItem_x                                      0x90AD30
#define CXWnd__SetParent_x                                         0x909810

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93D740

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90DA90
#define CXWndManager__DrawWindows_x                                0x90DAB0
#define CXWndManager__GetKeyboardFlags_x                           0x910200
#define CXWndManager__HandleKeyboardMsg_x                          0x90FE00
#define CXWndManager__RemoveWnd_x                                  0x910440
#define CXWndManager__RemovePendingDeletionWnd_x                   0x910980

// CDBStr
#define CDBStr__GetString_x                                        0x525620

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8650
#define EQ_Character__Cur_HP_x                                     0x4CE8D0
#define EQ_Character__Cur_Mana_x                                   0x4D5FE0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB560
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF450
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF5A0
#define EQ_Character__GetHPRegen_x                                 0x4DBFA0
#define EQ_Character__GetEnduranceRegen_x                          0x4DC5B0
#define EQ_Character__GetManaRegen_x                               0x4DC9F0
#define EQ_Character__Max_Endurance_x                              0x628230
#define EQ_Character__Max_HP_x                                     0x4CE700
#define EQ_Character__Max_Mana_x                                   0x628030
#define EQ_Character__doCombatAbility_x                            0x62A3D0
#define EQ_Character__UseSkill_x                                   0x4DE7E0
#define EQ_Character__GetConLevel_x                                0x621A70
#define EQ_Character__IsExpansionFlag_x                            0x5886C0
#define EQ_Character__TotalEffect_x                                0x4C1BF0
#define EQ_Character__GetPCSpellAffect_x                           0x4BC150
#define EQ_Character__SpellDuration_x                              0x4BBC80
#define EQ_Character__FindItemByRecord_x                           0x4D3EE0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1610
#define EQ_Character__GetBaseSkill_x                               0x4D25B0
#define EQ_Character__CanUseItem_x                                 0x4D62F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8AEFE0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63E210

//PcClient
#define PcClient__PcClient_x                                       0x61F350

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6430
#define CCharacterListWnd__EnterWorld_x                            0x4B5E70
#define CCharacterListWnd__Quit_x                                  0x4B5B80
#define CCharacterListWnd__UpdateList_x                            0x4B6000

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x603940
#define EQ_Item__CreateItemTagString_x                             0x8899A0
#define EQ_Item__IsStackable_x                                     0x88E290
#define EQ_Item__GetImageNum_x                                     0x88B280
#define EQ_Item__CreateItemClient_x                                0x602B00
#define EQ_Item__GetItemValue_x                                    0x88C4E0
#define EQ_Item__ValueSellMerchant_x                               0x88FA70
#define EQ_Item__IsKeyRingItem_x                                   0x88DBE0
#define EQ_Item__CanGoInBag_x                                      0x603A60
#define EQ_Item__GetMaxItemCount_x                                 0x88C8B0
#define EQ_Item__GetHeldItem_x                                     0x88B150
#define EQ_Item__GetAugmentFitBySlot_x                             0x8892E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5438E0
#define EQ_LoadingS__Array_x                                       0xBE1798

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x628B90
#define EQ_PC__GetAlternateAbilityId_x                             0x898C40
#define EQ_PC__GetCombatAbility_x                                  0x8992B0
#define EQ_PC__GetCombatAbilityTimer_x                             0x899320
#define EQ_PC__GetItemRecastTimer_x                                0x62A950
#define EQ_PC__HasLoreItem_x                                       0x622240
#define EQ_PC__AlertInventoryChanged_x                             0x621550
#define EQ_PC__GetPcZoneClient_x                                   0x64CA20
#define EQ_PC__RemoveMyAffect_x                                    0x62DB40
#define EQ_PC__GetKeyRingItems_x                                   0x899BC0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x899940
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x899EB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58EC40
#define EQItemList__add_object_x                                   0x5BA520
#define EQItemList__add_item_x                                     0x58F250
#define EQItemList__delete_item_x                                  0x58F2A0
#define EQItemList__FreeItemList_x                                 0x58F1A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x522C50

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63FA90
#define EQPlayer__dEQPlayer_x                                      0x6331B0
#define EQPlayer__DoAttack_x                                       0x647720
#define EQPlayer__EQPlayer_x                                       0x633860
#define EQPlayer__SetNameSpriteState_x                             0x637AC0
#define EQPlayer__SetNameSpriteTint_x                              0x638990
#define PlayerBase__HasProperty_j_x                                0x9705C0
#define EQPlayer__IsTargetable_x                                   0x970A60
#define EQPlayer__CanSee_x                                         0x9708C0
#define EQPlayer__CanSee1_x                                        0x970990
#define PlayerBase__GetVisibilityLineSegment_x                     0x970680

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64A4F0
#define PlayerZoneClient__GetLevel_x                               0x64CA60
#define PlayerZoneClient__IsValidTeleport_x                        0x5BB680
#define PlayerZoneClient__LegalPlayerRace_x                        0x53CD90

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x642800
#define EQPlayerManager__GetSpawnByName_x                          0x642820
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6428B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x607390
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6073D0
#define KeypressHandler__ClearCommandStateArray_x                  0x6087C0
#define KeypressHandler__HandleKeyDown_x                           0x6087E0
#define KeypressHandler__HandleKeyUp_x                             0x608880
#define KeypressHandler__SaveKeymapping_x                          0x608C60

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75EB60
#define MapViewMap__SaveEx_x                                       0x761F00
#define MapViewMap__SetZoom_x                                      0x7665D0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8ACED0

// StringTable 
#define StringTable__getString_x                                   0x8A7F30

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62D7B0
#define PcZoneClient__RemovePetEffect_x                            0x62DDE0
#define PcZoneClient__HasAlternateAbility_x                        0x627E70
#define PcZoneClient__GetCurrentMod_x                              0x4E18E0
#define PcZoneClient__GetModCap_x                                  0x4E17E0
#define PcZoneClient__CanEquipItem_x                               0x628520
#define PcZoneClient__GetItemByID_x                                0x62ADC0
#define PcZoneClient__GetItemByItemClass_x                         0x62AF10
#define PcZoneClient__RemoveBuffEffect_x                           0x62DE00
#define PcZoneClient__BandolierSwap_x                              0x629140

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C02D0

//IconCache
#define IconCache__GetIcon_x                                       0x6FFB30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F7610
#define CContainerMgr__CloseContainer_x                            0x6F78E0
#define CContainerMgr__OpenExperimentContainer_x                   0x6F8360

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B9E00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FBB90

//CLootWnd
#define CLootWnd__LootAll_x                                        0x754EE0
#define CLootWnd__RequestLootSlot_x                                0x7542A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55BD30
#define EQ_Spell__SpellAffects_x                                   0x55C1A0
#define EQ_Spell__SpellAffectBase_x                                0x55BF60
#define EQ_Spell__IsStackable_x                                    0x4C64C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6340
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3980
#define EQ_Spell__IsSPAStacking_x                                  0x55CFD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55C4F0
#define EQ_Spell__IsNoRemove_x                                     0x4C64A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55CFE0
#define __IsResEffectSpell_x                                       0x4C5750

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA1E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B7440

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FF680
#define CTargetWnd__WndNotification_x                              0x7FEF10
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FF1E0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FE060

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x803D50

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5572D0
#define EqSoundManager__PlayScriptMp3_x                            0x557430
#define EqSoundManager__SoundAssistPlay_x                          0x665420
#define EqSoundManager__WaveInstancePlay_x                         0x664990

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x514540

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x929060

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54B570
#define CAltAbilityData__GetMercMaxRank_x                          0x54B510
#define CAltAbilityData__GetMaxRank_x                              0x540B00

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F9C90

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6320
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FAA50
#define CharacterBase__CreateItemIndex_x                           0x601D60
#define CharacterBase__GetItemPossession_x                         0x4B3830
#define CharacterBase__GetItemByGlobalIndex_x                      0x8BFAD0
#define CharacterBase__GetEffectId_x                               0x4C62D0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DF7A0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DFFC0

//messages
#define msg_spell_worn_off_x                                       0x5807D0
#define msg_new_text_x                                             0x575730
#define __msgTokenTextParam_x                                      0x582E20
#define msgTokenText_x                                             0x583070

//SpellManager
#define SpellManager__vftable_x                                    0xAAA8B0
#define SpellManager__SpellManager_x                               0x668750
#define Spellmanager__LoadTextSpells_x                             0x669020
#define SpellManager__GetSpellByGroupAndRank_x                     0x668920

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x974670

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FB130
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x586CA0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x5886A0
#define ItemGlobalIndex__IsValidIndex_x                            0x4FB190

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B7D80
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B8000

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74DAB0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FBD80
#define CCursorAttachment__Deactivate_x                            0x6FCD60

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93B6C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x93B380

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F8100

//IString
#define IString__Append_x                                          0x4EB1B0

//Camera
#define CDisplay__cameraType_x                                     0xDAFCA4
#define EverQuest__Cameras_x                                       0xE72F08

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x500840
#define LootFiltersManager__GetItemFilterData_x                    0x500140
#define LootFiltersManager__RemoveItemLootFilter_x                 0x500170
#define LootFiltersManager__SetItemLootFilter_x                    0x500390

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A7E10

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97A400
#define CResolutionHandler__GetWindowedStyle_x                     0x660170

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F43D0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CA440

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7144F0
#define CGroupWnd__UpdateDisplay_x                                 0x713850

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
