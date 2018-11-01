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
#define __ExpectedVersionDate                                     "Nov  1 2018"
#define __ExpectedVersionTime                                     "04:19:47"
#define __ActualVersionDate_x                                      0xAC6AA4
#define __ActualVersionTime_x                                      0xAC6A98

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x60D980
#define __MemChecker1_x                                            0x8E1C60
#define __MemChecker2_x                                            0x69CA80
#define __MemChecker3_x                                            0x69C9D0
#define __MemChecker4_x                                            0x8393B0
#define __EncryptPad0_x                                            0xBF9990
#define __EncryptPad1_x                                            0xC57C20
#define __EncryptPad2_x                                            0xC0A518
#define __EncryptPad3_x                                            0xC0A118
#define __EncryptPad4_x                                            0xC48490
#define __EncryptPad5_x                                            0xF13B20
#define __AC1_x                                                    0x7F5A56
#define __AC2_x                                                    0x5C8BEF
#define __AC3_x                                                    0x5CFA7F
#define __AC4_x                                                    0x5D3900
#define __AC5_x                                                    0x5D9ABF
#define __AC6_x                                                    0x5DDFF6
#define __AC7_x                                                    0x5C8660
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1BBB48

// Direct Input
#define DI8__Main_x                                                0xF13B44
#define DI8__Keyboard_x                                            0xF13B48
#define DI8__Mouse_x                                               0xF13B10
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
#define __do_loot_x                                                0x596390
#define __DrawHandler_x                                            0x16A2B08
#define __GroupCount_x                                             0xE62212
#define __Guilds_x                                                 0xE68078
#define __gWorld_x                                                 0xE621FC
#define __HWnd_x                                                   0xF13B14
#define __heqmain_x                                                0x101ED68
#define __InChatMode_x                                             0xE71854
#define __LastTell_x                                               0xE737A4
#define __LMouseHeldTime_x                                         0xE71990
#define __Mouse_x                                                  0xF13B2C
#define __MouseLook_x                                              0xE718EA
#define __MouseEventTime_x                                         0xF11040
#define __gpbCommandEvent_x                                        0xE61C2C
#define __NetStatusToggle_x                                        0xE718ED
#define __PCNames_x                                                0xE72D64
#define __RangeAttackReady_x                                       0xE72A68
#define __RMouseHeldTime_x                                         0xE7198C
#define __RunWalkState_x                                           0xE71858
#define __ScreenMode_x                                             0xDAFBF8
#define __ScreenX_x                                                0xE7180C
#define __ScreenY_x                                                0xE71808
#define __ScreenXMax_x                                             0xE71810
#define __ScreenYMax_x                                             0xE71814
#define __ServerHost_x                                             0xE61E73
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
#define __gfMaxZoomCameraDistance_x                                0xABBEE8
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
#define pinstActiveBanker_x                                        0xE61D20
#define pinstActiveCorpse_x                                        0xE61D18
#define pinstActiveGMaster_x                                       0xE61D1C
#define pinstActiveMerchant_x                                      0xE61D14
#define pinstAggroInfo_x                                           0xC6E408
#define pinstAltAdvManager_x                                       0xDB0DB0
#define pinstAuraMgr_x                                             0xC7F0F0
#define pinstBandageTarget_x                                       0xE61D30
#define pinstCamActor_x                                            0xDAFBEC
#define pinstCDBStr_x                                              0xDAFAE4
#define pinstCDisplay_x                                            0xE621D8
#define pinstCEverQuest_x                                          0xF13C64
#define pinstEverQuestInfo_x                                       0xE71800
#define pinstCharData_x                                            0xE621E4
#define pinstCharSpawn_x                                           0xE61D68
#define pinstControlledMissile_x                                   0xE621E0
#define pinstControlledPlayer_x                                    0xE61D68
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
#define pinstLocalPlayer_x                                         0xE61D10
#define pinstMercenaryData_x                                       0xF117EC
#define pinstMercenaryStats_x                                      0x1028C3C
#define pinstMercAltAbilities_x                                    0xDB1380
#define pinstModelPlayer_x                                         0xE61D28
#define pinstPCData_x                                              0xE621E4
#define pinstRealEstateItems_x                                     0xF12CD0
#define pinstSkillMgr_x                                            0xF12DA0
#define pinstSpawnManager_x                                        0xF12390
#define pinstSpellManager_x                                        0xF12F78
#define pinstSpellSets_x                                           0xF091B0
#define pinstStringTable_x                                         0xE61B00
#define pinstSwitchManager_x                                       0xE619B0
#define pinstTarget_x                                              0xE61D64
#define pinstTargetObject_x                                        0xE61F7C
#define pinstTargetSwitch_x                                        0xE621F0
#define pinstTaskMember_x                                          0xDAF8B4
#define pinstTrackTarget_x                                         0xE61D6C
#define pinstTradeTarget_x                                         0xE61D24
#define instTributeActive_x                                        0xDAFA45
#define pinstViewActor_x                                           0xDAFBE8
#define pinstWorldData_x                                           0xE621EC
#define pinstZoneAddr_x                                            0xE71D80
#define pinstPlayerPath_x                                          0xF12428
#define pinstTargetIndicator_x                                     0xF131E0
#define pinstCTargetManager_x                                      0xF13278
#define EQObject_Top_x                                             0xE61D0C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDAFB94
#define pinstCAchievementsWnd_x                                    0xDAFC8C
#define pinstCActionsWnd_x                                         0xDAFC0C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDAFB98
#define pinstCAdvancedLootWnd_x                                    0xDB03FC
#define pinstCAdventureLeaderboardWnd_x                            0x101F908
#define pinstCAdventureRequestWnd_x                                0x101F9B8
#define pinstCAdventureStatsWnd_x                                  0x101FA68
#define pinstCAggroMeterWnd_x                                      0xDAFEA0
#define pinstCAlarmWnd_x                                           0xDAFC5C
#define pinstCAlertHistoryWnd_x                                    0xDAFC44
#define pinstCAlertStackWnd_x                                      0xDAFBBC
#define pinstCAlertWnd_x                                           0xDAFBD0
#define pinstCAltStorageWnd_x                                      0x101FDC8
#define pinstCAudioTriggersWindow_x                                0xC6E898
#define pinstCAuraWnd_x                                            0xDAFC9C
#define pinstCAvaZoneWnd_x                                         0xDAFC48
#define pinstCBandolierWnd_x                                       0xDAFED4
#define pinstCBankWnd_x                                            0xDB03B8
#define pinstCBarterMerchantWnd_x                                  0x1021008
#define pinstCBarterSearchWnd_x                                    0x10210B8
#define pinstCBarterWnd_x                                          0x1021168
#define pinstCBazaarConfirmationWnd_x                              0xDAFBB8
#define pinstCBazaarSearchWnd_x                                    0xDAFC24
#define pinstCBazaarWnd_x                                          0xDAFECC
#define pinstCBlockedBuffWnd_x                                     0xDAFF30
#define pinstCBlockedPetBuffWnd_x                                  0xDB03C0
#define pinstCBodyTintWnd_x                                        0xDAFBCC
#define pinstCBookWnd_x                                            0xDAFEF4
#define pinstCBreathWnd_x                                          0xDAFB9C
#define pinstCBuffWindowNORMAL_x                                   0xDAFF00
#define pinstCBuffWindowSHORT_x                                    0xDAFF04
#define pinstCBugReportWnd_x                                       0xDAFB90
#define pinstCButtonWnd_x                                          0x16A1DF0
#define pinstCCastingWnd_x                                         0xDAFB8C
#define pinstCCastSpellWnd_x                                       0xDAFC30
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDAFBA8
#define pinstCChatWindowManager_x                                  0x1021C28
#define pinstCClaimWnd_x                                           0x1021D80
#define pinstCColorPickerWnd_x                                     0xDAFBD4
#define pinstCCombatAbilityWnd_x                                   0xDAFEA8
#define pinstCCombatSkillsSelectWnd_x                              0xDAFC08
#define pinstCCompassWnd_x                                         0xDAFBB0
#define pinstCConfirmationDialog_x                                 0x1026C80
#define pinstCContainerMgr_x                                       0xDAFEC4
#define pinstCContextMenuManager_x                                 0x16A1B80
#define pinstCCursorAttachment_x                                   0xDAFB84
#define pinstCDistillerInfo_x                                      0x102568C
#define pinstCDynamicZoneWnd_x                                     0x1022348
#define pinstCEditLabelWnd_x                                       0xDAFEF8
#define pinstCEQMainWnd_x                                          0x1022590
#define pinstCEventCalendarWnd_x                                   0xDAFED0
#define pinstCExtendedTargetWnd_x                                  0xDAFC84
#define pinstCFacePick_x                                           0xDAFBD8
#define pinstCFellowshipWnd_x                                      0x1022790
#define pinstCFileSelectionWnd_x                                   0xDB03BC
#define pinstCFindItemWnd_x                                        0xDAFEE4
#define pinstCFindLocationWnd_x                                    0x10228E8
#define pinstCFriendsWnd_x                                         0xDAFC20
#define pinstCGemsGameWnd_x                                        0xDAFC2C
#define pinstCGiveWnd_x                                            0xDAFEEC
#define pinstCGroupSearchFiltersWnd_x                              0xDAFEB0
#define pinstCGroupSearchWnd_x                                     0x1022CE0
#define pinstCGroupWnd_x                                           0x1022D90
#define pinstCGuildBankWnd_x                                       0xE72BC4
#define pinstCGuildCreationWnd_x                                   0x1022EF0
#define pinstCGuildMgmtWnd_x                                       0x1022FA0
#define pinstCharacterCreation_x                                   0xDAFEA4
#define pinstCHelpWnd_x                                            0xDAFC54
#define pinstCHeritageSelectionWnd_x                               0xDAFBE4
#define pinstCHotButtonWnd_x                                       0x10250F8
#define pinstCHotButtonWnd1_x                                      0x10250F8
#define pinstCHotButtonWnd2_x                                      0x10250FC
#define pinstCHotButtonWnd3_x                                      0x1025100
#define pinstCHotButtonWnd4_x                                      0x1025104
#define pinstCIconSelectionWnd_x                                   0xDB03EC
#define pinstCInspectWnd_x                                         0xDB03C4
#define pinstCInventoryWnd_x                                       0xDAFED8
#define pinstCInvSlotMgr_x                                         0xDAFC70
#define pinstCItemDisplayManager_x                                 0x1025688
#define pinstCItemExpTransferWnd_x                                 0x10257BC
#define pinstCItemOverflowWnd_x                                    0xDAFC28
#define pinstCJournalCatWnd_x                                      0xDB0410
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDAFF20
#define pinstCKeyRingWnd_x                                         0xDAFF18
#define pinstCLargeDialogWnd_x                                     0x1027900
#define pinstCLayoutCopyWnd_x                                      0x1025B08
#define pinstCLFGuildWnd_x                                         0x1025BB8
#define pinstCLoadskinWnd_x                                        0xDAFC3C
#define pinstCLootFiltersCopyWnd_x                                 0xC7F978
#define pinstCLootFiltersWnd_x                                     0xDAFBE0
#define pinstCLootSettingsWnd_x                                    0xDAFC10
#define pinstCLootWnd_x                                            0xDAFBC4
#define pinstCMailAddressBookWnd_x                                 0xDB03F4
#define pinstCMailCompositionWnd_x                                 0xDB03B0
#define pinstCMailIgnoreListWnd_x                                  0xDB03F8
#define pinstCMailWnd_x                                            0xDAFF10
#define pinstCManageLootWnd_x                                      0xDB1228
#define pinstCMapToolbarWnd_x                                      0xDAFEDC
#define pinstCMapViewWnd_x                                         0xDAFEB8
#define pinstCMarketplaceWnd_x                                     0xDAFEE8
#define pinstCMerchantWnd_x                                        0xDAFC04
#define pinstCMIZoneSelectWnd_x                                    0x10263F0
#define pinstCMusicPlayerWnd_x                                     0xDAFF14
#define pinstCNameChangeMercWnd_x                                  0xDAFB80
#define pinstCNameChangePetWnd_x                                   0xDB03F0
#define pinstCNameChangeWnd_x                                      0xDAFEBC
#define pinstCNoteWnd_x                                            0xDAFC40
#define pinstCObjectPreviewWnd_x                                   0xDAFF08
#define pinstCOptionsWnd_x                                         0xDAFEE0
#define pinstCPetInfoWnd_x                                         0xDAFFA4
#define pinstCPetitionQWnd_x                                       0xDAFB88
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDAFBC8
#define pinstCPlayerWnd_x                                          0xDAFC18
#define pinstCPopupWndManager_x                                    0x1026C80
#define pinstCProgressionSelectionWnd_x                            0x1026D30
#define pinstCPurchaseGroupWnd_x                                   0xDB03AC
#define pinstCPurchaseWnd_x                                        0xDAFF0C
#define pinstCPvPLeaderboardWnd_x                                  0x1026DE0
#define pinstCPvPStatsWnd_x                                        0x1026E90
#define pinstCQuantityWnd_x                                        0xDB0404
#define pinstCRaceChangeWnd_x                                      0xDAFEF0
#define pinstCRaidOptionsWnd_x                                     0xDAFEB4
#define pinstCRaidWnd_x                                            0xDB0408
#define pinstCRealEstateItemsWnd_x                                 0xDAFC90
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDAFEC8
#define pinstCRealEstateManageWnd_x                                0xDAFC14
#define pinstCRealEstateNeighborhoodWnd_x                          0xDAFC34
#define pinstCRealEstatePlotSearchWnd_x                            0xDAFC4C
#define pinstCRealEstatePurchaseWnd_x                              0xDAFC74
#define pinstCRespawnWnd_x                                         0xDAFEAC
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDAFC88
#define pinstCSendMoneyWnd_x                                       0xDAFEFC
#define pinstCServerListWnd_x                                      0xDAFC98
#define pinstCSkillsSelectWnd_x                                    0xDAFBDC
#define pinstCSkillsWnd_x                                          0xDAFBC0
#define pinstCSocialEditWnd_x                                      0xDB040C
#define pinstCSocialWnd_x                                          0xDAFBA0
#define pinstCSpellBookWnd_x                                       0xDAFC7C
#define pinstCStoryWnd_x                                           0xDAFBA4
#define pinstCTargetOfTargetWnd_x                                  0x1028CC0
#define pinstCTargetWnd_x                                          0xDAFFA0
#define pinstCTaskOverlayWnd_x                                     0xDAFC58
#define pinstCTaskSelectWnd_x                                      0x1028E18
#define pinstCTaskSomething_x                                      0xC80178
#define pinstCTaskTemplateSelectWnd_x                              0x1028EC8
#define pinstCTaskWnd_x                                            0x1028F78
#define pinstCTextEntryWnd_x                                       0xDAFBB4
#define pinstCTextOverlay_x                                        0xC6EBA8
#define pinstCTimeLeftWnd_x                                        0xDB03E0
#define pinstCTipWndCONTEXT_x                                      0x102917C
#define pinstCTipWndOFDAY_x                                        0x1029178
#define pinstCTitleWnd_x                                           0x1029228
#define pinstCTrackingWnd_x                                        0xDAFF9C
#define pinstCTradeskillWnd_x                                      0x1029390
#define pinstCTradeWnd_x                                           0xDAFC60
#define pinstCTrainWnd_x                                           0xDB0400
#define pinstCTributeBenefitWnd_x                                  0x1029590
#define pinstCTributeMasterWnd_x                                   0x1029640
#define pinstCTributeTrophyWnd_x                                   0x10296F0
#define pinstCVideoModesWnd_x                                      0xDAFC50
#define pinstCVoiceMacroWnd_x                                      0xF137A8
#define pinstCVoteResultsWnd_x                                     0xDB03B4
#define pinstCVoteWnd_x                                            0xDAFF1C
#define pinstCWebManager_x                                         0xF1390C
#define pinstCZoneGuideWnd_x                                       0xDAFC1C
#define pinstCZonePathWnd_x                                        0xDAFC38

#define pinstEQSuiteTextureLoader_x                                0xC596F0
#define pinstItemIconCache_x                                       0x1022548
#define pinstLootFiltersManager_x                                  0xC7FA28
#define pinstRewardSelectionWnd_x                                  0x10275D8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0A10C
#define __CastRay_x                                                0x5918B0
#define __CastRay2_x                                               0x591900
#define __ConvertItemTags_x                                        0x5AC4B0
#define __CrashHandler_x                                           0x842CD0
#define __EQGetTime_x                                              0x8E1750
#define __ExecuteCmd_x                                             0x58A230
#define __FixHeading_x                                             0x971EC0
#define __get_bearing_x                                            0x5913F0
#define __get_melee_range_x                                        0x591AF0
#define __GetAnimationCache_x                                      0x7006F0
#define __GetGaugeValueFromEQ_x                                    0x7F4270
#define __GetLabelFromEQ_x                                         0x7F59E0
#define __GetXTargetType_x                                         0x973990
#define __HeadingDiff_x                                            0x971F30
#define __HelpPath_x                                               0xF10C5C
#define __LoadFrontEnd_x                                           0x6988E0
#define __NewUIINI_x                                               0x7F3F40
#define __pCrashHandler_x                                          0x1046AE0
#define __ProcessGameEvents_x                                      0x5EF070
#define __ProcessMouseEvent_x                                      0x5EE830
#define __SaveColors_x                                             0x53B340
#define __STMLToText_x                                             0x915490
#define __ToggleKeyRingItem_x                                      0x4FE690
#define CrashDetected_x                                            0x69A3D0
#define DrawNetStatus_x                                            0x61AF00
#define Expansion_HoT_x                                            0xE72BCC
#define Teleport_Table_Size_x                                      0xE61CB8
#define Teleport_Table_x                                           0xE62408
#define Util__FastTime_x                                           0x8E1310
#define wwsCrashReportCheckForUploader_x                           0x843A20
#define wwsCrashReportPlatformLaunchUploader_x                     0x8460F0
#define __HandleMouseWheel_x                                       0x69CB30

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AF50
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493D50
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493B30

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x542CB0
#define AltAdvManager__IsAbilityReady_x                            0x541D30
#define AltAdvManager__GetAAById_x                                 0x541F30
#define AltAdvManager__CanTrainAbility_x                           0x541FA0
#define AltAdvManager__CanSeeAbility_x                             0x5421D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C68D0
#define CharacterZoneClient__HasSkill_x                            0x4D1590
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2CB0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BAD60
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B74D0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5670
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5750
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5830
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF840
#define CharacterZoneClient__BardCastBard_x                        0x4C24B0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B75A0
#define CharacterZoneClient__GetEffect_x                           0x4B7410
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0840
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0910
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0960
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0AB0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0C80

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C2CA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D04B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5FD6D0
#define CButtonWnd__CButtonWnd_x                                   0x911890

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EF0D0
#define CChatManager__InitContextMenu_x                            0x6E9170
#define CChatManager__FreeChatWindow_x                             0x6EDFE0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F2960
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EEE70

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x925F60
#define CContextMenu__dCContextMenu_x                              0x926190
#define CContextMenu__AddMenuItem_x                                0x9261A0
#define CContextMenu__RemoveMenuItem_x                             0x9264B0
#define CContextMenu__RemoveAllMenuItems_x                         0x9264D0
#define CContextMenu__CheckMenuItem_x                              0x926550
#define CContextMenu__SetMenuItem_x                                0x9263D0
#define CContextMenu__AddSeparator_x                               0x926330

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x926AF0
#define CContextMenuManager__RemoveMenu_x                          0x926B60
#define CContextMenuManager__PopupMenu_x                           0x926C20
#define CContextMenuManager__Flush_x                               0x926A90
#define CContextMenuManager__GetMenu_x                             0x495F30

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C1FD0
#define CChatService__GetFriendName_x                              0x8C1FE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EF640
#define CChatWindow__Clear_x                                       0x6F0690
#define CChatWindow__WndNotification_x                             0x6F0BF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x923400
#define CComboWnd__Draw_x                                          0x922900
#define CComboWnd__GetCurChoice_x                                  0x923240
#define CComboWnd__GetListRect_x                                   0x922DB0
#define CComboWnd__GetTextRect_x                                   0x923470
#define CComboWnd__InsertChoice_x                                  0x922F40
#define CComboWnd__SetColors_x                                     0x922F10
#define CComboWnd__SetChoice_x                                     0x923210
#define CComboWnd__GetItemCount_x                                  0x923250
#define CComboWnd__GetCurChoiceText_x                              0x923290

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F8900
#define CContainerWnd__vftable_x                                   0xACFEA8
#define CContainerWnd__SetContainer_x                              0x6F9E70

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x53B100
#define CDisplay__GetClickedActor_x                                0x52E100
#define CDisplay__GetUserDefinedColor_x                            0x5267E0
#define CDisplay__GetWorldFilePath_x                               0x52FB50
#define CDisplay__is3dON_x                                         0x52ADD0
#define CDisplay__ReloadUI_x                                       0x535270
#define CDisplay__WriteTextHD2_x                                   0x52ABB0
#define CDisplay__TrueDistance_x                                   0x5317B0
#define CDisplay__SetViewActor_x                                   0x52DA50
#define CDisplay__GetFloorHeight_x                                 0x52AE90
#define CDisplay__SetRenderWindow_x                                0x5297C0
#define CDisplay__ToggleScreenshotMode_x                           0x52D520

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x945690

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x92A640
#define CEditWnd__GetCharIndexPt_x                                 0x92B530
#define CEditWnd__GetDisplayString_x                               0x92B3D0
#define CEditWnd__GetHorzOffset_x                                  0x929C80
#define CEditWnd__GetLineForPrintableChar_x                        0x92C640
#define CEditWnd__GetSelStartPt_x                                  0x92B7E0
#define CEditWnd__GetSTMLSafeText_x                                0x92B1F0
#define CEditWnd__PointFromPrintableChar_x                         0x92C280
#define CEditWnd__SelectableCharFromPoint_x                        0x92C3F0
#define CEditWnd__SetEditable_x                                    0x92B8A0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DD520
#define CEverQuest__ClickedPlayer_x                                0x5CF860
#define CEverQuest__CreateTargetIndicator_x                        0x5EC320
#define CEverQuest__DeleteTargetIndicator_x                        0x5EC3B0
#define CEverQuest__DoTellWindow_x                                 0x4E2920
#define CEverQuest__OutputTextToLog_x                              0x4E2B50
#define CEverQuest__DropHeldItemOnGround_x                         0x5C5120
#define CEverQuest__dsp_chat_x                                     0x4E2EE0
#define CEverQuest__trimName_x                                     0x5E8890
#define CEverQuest__Emote_x                                        0x5DDD30
#define CEverQuest__EnterZone_x                                    0x5D7F10
#define CEverQuest__GetBodyTypeDesc_x                              0x5E2130
#define CEverQuest__GetClassDesc_x                                 0x5E2770
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E2D70
#define CEverQuest__GetDeityDesc_x                                 0x5EAC70
#define CEverQuest__GetLangDesc_x                                  0x5E2F30
#define CEverQuest__GetRaceDesc_x                                  0x5E2750
#define CEverQuest__InterpretCmd_x                                 0x5EB240
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C9310
#define CEverQuest__LMouseUp_x                                     0x5C7690
#define CEverQuest__RightClickedOnPlayer_x                         0x5C9BF0
#define CEverQuest__RMouseUp_x                                     0x5C8620
#define CEverQuest__SetGameState_x                                 0x5C4EB0
#define CEverQuest__UPCNotificationFlush_x                         0x5E8790
#define CEverQuest__IssuePetCommand_x                              0x5E4330
#define CEverQuest__ReportSuccessfulHit_x                          0x5DF010

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x70A7A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x70A800
#define CGaugeWnd__Draw_x                                          0x709E90

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AC450
#define CGuild__GetGuildName_x                                     0x4AB530
#define CGuild__GetGuildIndex_x                                    0x4AB8C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x725B50

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5FDA90

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x732B80
#define CInvSlotMgr__MoveItem_x                                    0x731890
#define CInvSlotMgr__SelectSlot_x                                  0x732C50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x730140
#define CInvSlot__SliderComplete_x                                 0x72DEA0
#define CInvSlot__GetItemBase_x                                    0x72D810
#define CInvSlot__UpdateItem_x                                     0x72D980

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7345A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x733870
#define CInvSlotWnd__HandleLButtonUp_x                             0x734120

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F0460
#define CItemDisplayWnd__UpdateStrings_x                           0x742620
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x73C700
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x73CC10
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x742C00
#define CItemDisplayWnd__AboutToShow_x                             0x742280
#define CItemDisplayWnd__WndNotification_x                         0x743F20

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x828030

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7480F0

// CLabel 
#define CLabel__Draw_x                                             0x74DBD0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8FBD20
#define CListWnd__dCListWnd_x                                      0x8FC040
#define CListWnd__AddColumn_x                                      0x900310
#define CListWnd__AddColumn1_x                                     0x900360
#define CListWnd__AddLine_x                                        0x9006F0
#define CListWnd__AddString_x                                      0x9004F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9000D0
#define CListWnd__CalculateVSBRange_x                              0x8FFED0
#define CListWnd__ClearSel_x                                       0x900ED0
#define CListWnd__ClearAllSel_x                                    0x900F30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x901930
#define CListWnd__Compare_x                                        0x8FF820
#define CListWnd__Draw_x                                           0x8FC140
#define CListWnd__DrawColumnSeparators_x                           0x8FE900
#define CListWnd__DrawHeader_x                                     0x8FED60
#define CListWnd__DrawItem_x                                       0x8FF160
#define CListWnd__DrawLine_x                                       0x8FEA60
#define CListWnd__DrawSeparator_x                                  0x8FE9A0
#define CListWnd__EnableLine_x                                     0x8FE1F0
#define CListWnd__EnsureVisible_x                                  0x901850
#define CListWnd__ExtendSel_x                                      0x900E00
#define CListWnd__GetColumnMinWidth_x                              0x8FDD30
#define CListWnd__GetColumnWidth_x                                 0x8FDCA0
#define CListWnd__GetCurSel_x                                      0x8FD630
#define CListWnd__GetItemAtPoint_x                                 0x8FE460
#define CListWnd__GetItemAtPoint1_x                                0x8FE4D0
#define CListWnd__GetItemData_x                                    0x8FD6B0
#define CListWnd__GetItemHeight_x                                  0x8FDA70
#define CListWnd__GetItemIcon_x                                    0x8FD840
#define CListWnd__GetItemRect_x                                    0x8FE2E0
#define CListWnd__GetItemText_x                                    0x8FD6F0
#define CListWnd__GetSelList_x                                     0x900F80
#define CListWnd__GetSeparatorRect_x                               0x8FE710
#define CListWnd__InsertLine_x                                     0x900AE0
#define CListWnd__RemoveLine_x                                     0x900C30
#define CListWnd__SetColors_x                                      0x8FFEB0
#define CListWnd__SetColumnJustification_x                         0x8FFBE0
#define CListWnd__SetColumnWidth_x                                 0x8FFB00
#define CListWnd__SetCurSel_x                                      0x900D40
#define CListWnd__SetItemColor_x                                   0x901500
#define CListWnd__SetItemData_x                                    0x9014C0
#define CListWnd__SetItemText_x                                    0x901100
#define CListWnd__ShiftColumnSeparator_x                           0x8FFCA0
#define CListWnd__Sort_x                                           0x8FF9A0
#define CListWnd__ToggleSel_x                                      0x900D70

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x763010
#define CMapViewWnd__GetWorldCoordinates_x                         0x761720
#define CMapViewWnd__HandleLButtonDown_x                           0x75E780

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x786200
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x786AE0
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x787010
#define CMerchantWnd__SelectRecoverySlot_x                         0x789E50
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x784BE0
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x78F9E0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x785E40

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88FE90
#define CPacketScrambler__hton_x                                   0x88FE80

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x91AA50
#define CSidlManager__FindScreenPieceTemplate_x                    0x91AE60
#define CSidlManager__FindScreenPieceTemplate1_x                   0x91AC50
#define CSidlManager__CreateLabel_x                                0x7E78F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x91DF30
#define CSidlManager__CreateXWndFromTemplate1_x                    0x91E100
#define CSidlManager__CreateXWnd_x                                 0x7E7820
#define CSidlManager__CreateHotButtonWnd_x                         0x7E7DD0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9175E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9174E0
#define CSidlScreenWnd__ConvertToRes_x                             0x93C480
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x916F80
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x916C70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x916D40
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x916E10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x917A60
#define CSidlScreenWnd__EnableIniStorage_x                         0x917F30
#define CSidlScreenWnd__GetSidlPiece_x                             0x917C50
#define CSidlScreenWnd__Init1_x                                    0x916860
#define CSidlScreenWnd__LoadIniInfo_x                              0x917F80
#define CSidlScreenWnd__LoadIniListWnd_x                           0x918AC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x915C70
#define CSidlScreenWnd__StoreIniInfo_x                             0x918640
#define CSidlScreenWnd__StoreIniVis_x                              0x9189A0
#define CSidlScreenWnd__WndNotification_x                          0x917970
#define CSidlScreenWnd__GetChildItem_x                             0x917EB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x907850
#define CSidlScreenWnd__m_layoutCopy_x                             0x16A1A50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x661990
#define CSkillMgr__GetSkillCap_x                                   0x661B70
#define CSkillMgr__GetNameToken_x                                  0x661120

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9278D0
#define CSliderWnd__SetValue_x                                     0x927740
#define CSliderWnd__SetNumTicks_x                                  0x9277A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7ED6E0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x92E4F0
#define CStmlWnd__CalculateHSBRange_x                              0x92F5B0
#define CStmlWnd__CalculateVSBRange_x                              0x92F520
#define CStmlWnd__CanBreakAtCharacter_x                            0x9338D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9344C0
#define CStmlWnd__ForceParseNow_x                                  0x92EAE0
#define CStmlWnd__GetNextTagPiece_x                                0x933830
#define CStmlWnd__GetSTMLText_x                                    0x4F0D30
#define CStmlWnd__GetVisibleText_x                                 0x92EB00
#define CStmlWnd__InitializeWindowVariables_x                      0x934310
#define CStmlWnd__MakeStmlColorTag_x                               0x92DC80
#define CStmlWnd__MakeWndNotificationTag_x                         0x92DCF0
#define CStmlWnd__SetSTMLText_x                                    0x92CD50
#define CStmlWnd__StripFirstSTMLLines_x                            0x935620
#define CStmlWnd__UpdateHistoryString_x                            0x9346D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x939320
#define CTabWnd__DrawCurrentPage_x                                 0x939940
#define CTabWnd__DrawTab_x                                         0x939710
#define CTabWnd__GetCurrentPage_x                                  0x938B80
#define CTabWnd__GetPageInnerRect_x                                0x938DC0
#define CTabWnd__GetTabInnerRect_x                                 0x938D00
#define CTabWnd__GetTabRect_x                                      0x938BB0
#define CTabWnd__InsertPage_x                                      0x938FB0
#define CTabWnd__SetPage_x                                         0x938E40
#define CTabWnd__SetPageRect_x                                     0x939260
#define CTabWnd__UpdatePage_x                                      0x9395D0
#define CTabWnd__GetPageFromTabIndex_x                             0x939650
#define CTabWnd__GetCurrentTabIndex_x                              0x938B70

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x748570
#define CPageWnd__SetTabText_x                                     0x945AA0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5FA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x904700
#define CTextureFont__GetTextExtent_x                              0x9048C0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x695710
#define CHtmlComponentWnd__ValidateUri_x                           0x727540
#define CHtmlWnd__SetClientCallbacks_x                             0x602A80
#define CHtmlWnd__AddObserver_x                                    0x602AA0
#define CHtmlWnd__RemoveObserver_x                                 0x602B00
#define Window__getProgress_x                                      0x840940
#define Window__getStatus_x                                        0x840960
#define Window__getURI_x                                           0x840970

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x942020

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F14A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD700
#define CXStr__CXStr1_x                                            0x4B3130
#define CXStr__CXStr3_x                                            0x8DD840
#define CXStr__dCXStr_x                                            0x472840
#define CXStr__operator_equal_x                                    0x8DDA70
#define CXStr__operator_equal1_x                                   0x8DDAB0
#define CXStr__operator_plus_equal1_x                              0x8DE540

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x925B80
#define CXWnd__BringToTop_x                                        0x90AF10
#define CXWnd__Center_x                                            0x90AA90
#define CXWnd__ClrFocus_x                                          0x90A8C0
#define CXWnd__Destroy_x                                           0x90A970
#define CXWnd__DoAllDrawing_x                                      0x907000
#define CXWnd__DrawChildren_x                                      0x906FD0
#define CXWnd__DrawColoredRect_x                                   0x907450
#define CXWnd__DrawTooltip_x                                       0x905B30
#define CXWnd__DrawTooltipAtPoint_x                                0x905BF0
#define CXWnd__GetBorderFrame_x                                    0x9072B0
#define CXWnd__GetChildWndAt_x                                     0x90AFB0
#define CXWnd__GetClientClipRect_x                                 0x9091F0
#define CXWnd__GetScreenClipRect_x                                 0x9092A0
#define CXWnd__GetScreenRect_x                                     0x909450
#define CXWnd__GetTooltipRect_x                                    0x9074A0
#define CXWnd__GetWindowTextA_x                                    0x4975C0
#define CXWnd__IsActive_x                                          0x90DE20
#define CXWnd__IsDescendantOf_x                                    0x909E50
#define CXWnd__IsReallyVisible_x                                   0x909E80
#define CXWnd__IsType_x                                            0x90B5F0
#define CXWnd__Move_x                                              0x909EE0
#define CXWnd__Move1_x                                             0x909F90
#define CXWnd__ProcessTransition_x                                 0x90AA40
#define CXWnd__Refade_x                                            0x90A250
#define CXWnd__Resize_x                                            0x90A4F0
#define CXWnd__Right_x                                             0x90ACD0
#define CXWnd__SetFocus_x                                          0x90A880
#define CXWnd__SetFont_x                                           0x90A8F0
#define CXWnd__SetKeyTooltip_x                                     0x90B410
#define CXWnd__SetMouseOver_x                                      0x9083D0
#define CXWnd__StartFade_x                                         0x909D30
#define CXWnd__GetChildItem_x                                      0x90B110
#define CXWnd__SetParent_x                                         0x909BF0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x93D560

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x90DE60
#define CXWndManager__DrawWindows_x                                0x90DE80
#define CXWndManager__GetKeyboardFlags_x                           0x910530
#define CXWndManager__HandleKeyboardMsg_x                          0x910140
#define CXWndManager__RemoveWnd_x                                  0x910780
#define CXWndManager__RemovePendingDeletionWnd_x                   0x910CC0

// CDBStr
#define CDBStr__GetString_x                                        0x5257A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8480
#define EQ_Character__Cur_HP_x                                     0x4CE610
#define EQ_Character__Cur_Mana_x                                   0x4D5D30
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB3A0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AF320
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF470
#define EQ_Character__GetHPRegen_x                                 0x4DBCF0
#define EQ_Character__GetEnduranceRegen_x                          0x4DC300
#define EQ_Character__GetManaRegen_x                               0x4DC740
#define EQ_Character__Max_Endurance_x                              0x628860
#define EQ_Character__Max_HP_x                                     0x4CE440
#define EQ_Character__Max_Mana_x                                   0x628660
#define EQ_Character__doCombatAbility_x                            0x62AA10
#define EQ_Character__UseSkill_x                                   0x4DE550
#define EQ_Character__GetConLevel_x                                0x621CC0
#define EQ_Character__IsExpansionFlag_x                            0x5888D0
#define EQ_Character__TotalEffect_x                                0x4C1A30
#define EQ_Character__GetPCSpellAffect_x                           0x4BBF90
#define EQ_Character__SpellDuration_x                              0x4BBAC0
#define EQ_Character__FindItemByRecord_x                           0x4D3C20
#define EQ_Character__GetAdjustedSkill_x                           0x4D1350
#define EQ_Character__GetBaseSkill_x                               0x4D22F0
#define EQ_Character__CanUseItem_x                                 0x4D6040

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8AEEF0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63E810

//PcClient
#define PcClient__PcClient_x                                       0x61F590

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6260
#define CCharacterListWnd__EnterWorld_x                            0x4B5CA0
#define CCharacterListWnd__Quit_x                                  0x4B59B0
#define CCharacterListWnd__UpdateList_x                            0x4B5E30

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x603CB0
#define EQ_Item__CreateItemTagString_x                             0x889920
#define EQ_Item__IsStackable_x                                     0x88E230
#define EQ_Item__GetImageNum_x                                     0x88B240
#define EQ_Item__CreateItemClient_x                                0x602E60
#define EQ_Item__GetItemValue_x                                    0x88C4B0
#define EQ_Item__ValueSellMerchant_x                               0x88FA20
#define EQ_Item__IsKeyRingItem_x                                   0x88DB80
#define EQ_Item__CanGoInBag_x                                      0x603DD0
#define EQ_Item__GetMaxItemCount_x                                 0x88C880
#define EQ_Item__GetHeldItem_x                                     0x88B110
#define EQ_Item__GetAugmentFitBySlot_x                             0x889260

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x543990
#define EQ_LoadingS__Array_x                                       0xBE1798

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6291C0
#define EQ_PC__GetAlternateAbilityId_x                             0x898CF0
#define EQ_PC__GetCombatAbility_x                                  0x899360
#define EQ_PC__GetCombatAbilityTimer_x                             0x8993D0
#define EQ_PC__GetItemRecastTimer_x                                0x62AF90
#define EQ_PC__HasLoreItem_x                                       0x6224E0
#define EQ_PC__AlertInventoryChanged_x                             0x621790
#define EQ_PC__GetPcZoneClient_x                                   0x64D030
#define EQ_PC__RemoveMyAffect_x                                    0x62E190
#define EQ_PC__GetKeyRingItems_x                                   0x899C70
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8999F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x899F60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58EE40
#define EQItemList__add_object_x                                   0x5BA7F0
#define EQItemList__add_item_x                                     0x58F450
#define EQItemList__delete_item_x                                  0x58F4A0
#define EQItemList__FreeItemList_x                                 0x58F3A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x522E00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x640090
#define EQPlayer__dEQPlayer_x                                      0x6337A0
#define EQPlayer__DoAttack_x                                       0x647D10
#define EQPlayer__EQPlayer_x                                       0x633E50
#define EQPlayer__SetNameSpriteState_x                             0x6380C0
#define EQPlayer__SetNameSpriteTint_x                              0x638F90
#define PlayerBase__HasProperty_j_x                                0x9702A0
#define EQPlayer__IsTargetable_x                                   0x970740
#define EQPlayer__CanSee_x                                         0x9705A0
#define EQPlayer__CanSee1_x                                        0x970670
#define PlayerBase__GetVisibilityLineSegment_x                     0x970360

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x64AAE0
#define PlayerZoneClient__GetLevel_x                               0x64D070
#define PlayerZoneClient__IsValidTeleport_x                        0x5BB940
#define PlayerZoneClient__LegalPlayerRace_x                        0x53CE80

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x642E10
#define EQPlayerManager__GetSpawnByName_x                          0x642E30
#define EQPlayerManager__GetPlayerFromPartialName_x                0x642EC0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6075B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6075F0
#define KeypressHandler__ClearCommandStateArray_x                  0x6089E0
#define KeypressHandler__HandleKeyDown_x                           0x608A00
#define KeypressHandler__HandleKeyUp_x                             0x608AA0
#define KeypressHandler__SaveKeymapping_x                          0x608E80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75EEA0
#define MapViewMap__SaveEx_x                                       0x762240
#define MapViewMap__SetZoom_x                                      0x766900

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8ACDE0

// StringTable 
#define StringTable__getString_x                                   0x8A7DA0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62DE00
#define PcZoneClient__RemovePetEffect_x                            0x62E430
#define PcZoneClient__HasAlternateAbility_x                        0x6284A0
#define PcZoneClient__GetCurrentMod_x                              0x4E1650
#define PcZoneClient__GetModCap_x                                  0x4E1550
#define PcZoneClient__CanEquipItem_x                               0x628B50
#define PcZoneClient__GetItemByID_x                                0x62B410
#define PcZoneClient__GetItemByItemClass_x                         0x62B560
#define PcZoneClient__RemoveBuffEffect_x                           0x62E450
#define PcZoneClient__BandolierSwap_x                              0x629780

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C05A0

//IconCache
#define IconCache__GetIcon_x                                       0x6FFF80

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F7AA0
#define CContainerMgr__CloseContainer_x                            0x6F7D70
#define CContainerMgr__OpenExperimentContainer_x                   0x6F87F0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7BA050

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5FBEC0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x755360
#define CLootWnd__RequestLootSlot_x                                0x754710

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x55BEE0
#define EQ_Spell__SpellAffects_x                                   0x55C350
#define EQ_Spell__SpellAffectBase_x                                0x55C110
#define EQ_Spell__IsStackable_x                                    0x4C61E0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6030
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3860
#define EQ_Spell__IsSPAStacking_x                                  0x55D180
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x55C6A0
#define EQ_Spell__IsNoRemove_x                                     0x4C61C0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55D190
#define __IsResEffectSpell_x                                       0x4C5590

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA170

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B7460

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FF830
#define CTargetWnd__WndNotification_x                              0x7FF0C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FF390
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FE220

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x803F00

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x557480
#define EqSoundManager__PlayScriptMp3_x                            0x5575E0
#define EqSoundManager__SoundAssistPlay_x                          0x665810
#define EqSoundManager__WaveInstancePlay_x                         0x664D80

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x514700

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9292B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x54B630
#define CAltAbilityData__GetMercMaxRank_x                          0x54B5D0
#define CAltAbilityData__GetMaxRank_x                              0x540BE0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F9FD0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6010
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FAB60
#define CharacterBase__CreateItemIndex_x                           0x602090
#define CharacterBase__GetItemPossession_x                         0x4B3710
#define CharacterBase__GetItemByGlobalIndex_x                      0x8BFAF0
#define CharacterBase__GetEffectId_x                               0x4C5FC0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DFC80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E04A0

//messages
#define msg_spell_worn_off_x                                       0x580A30
#define msg_new_text_x                                             0x575970
#define __msgTokenTextParam_x                                      0x583080
#define msgTokenText_x                                             0x5832D0

//SpellManager
#define SpellManager__vftable_x                                    0xAAA8A8
#define SpellManager__SpellManager_x                               0x668B40
#define Spellmanager__LoadTextSpells_x                             0x669410
#define SpellManager__GetSpellByGroupAndRank_x                     0x668D10

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x974280

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4FB250
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x586F10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x5888B0
#define ItemGlobalIndex__IsValidIndex_x                            0x4FB2B0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B7DA0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B8020

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74DF10

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6FC1E0
#define CCursorAttachment__Deactivate_x                            0x6FD1B0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x93B950
#define CEQSuiteTextureLoader__GetTexture_x                        0x93B610

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F81E0

//IString
#define IString__Append_x                                          0x4EAD50

//Camera
#define CDisplay__cameraType_x                                     0xDAFC94
#define EverQuest__Cameras_x                                       0xE72F08

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x500900
#define LootFiltersManager__GetItemFilterData_x                    0x500200
#define LootFiltersManager__RemoveItemLootFilter_x                 0x500230
#define LootFiltersManager__SetItemLootFilter_x                    0x500450

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A8070

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x97A070
#define CResolutionHandler__GetWindowedStyle_x                     0x6603B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F47F0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CA460

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x714920
#define CGroupWnd__UpdateDisplay_x                                 0x713C90

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
