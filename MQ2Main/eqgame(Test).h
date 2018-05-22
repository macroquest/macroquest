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
#define __ExpectedVersionDate                                     "May  7 2018"
#define __ExpectedVersionTime                                     "16:06:33"
#define __ActualVersionDate_x                                      0xABD314
#define __ActualVersionTime_x                                      0xABD308

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x607EF0
#define __MemChecker1_x                                            0x8D9300
#define __MemChecker2_x                                            0x696000
#define __MemChecker3_x                                            0x695F50
#define __MemChecker4_x                                            0x831870
#define __EncryptPad0_x                                            0xBF1490
#define __EncryptPad1_x                                            0xC4F158
#define __EncryptPad2_x                                            0xC02018
#define __EncryptPad3_x                                            0xC01C18
#define __EncryptPad4_x                                            0xC3FF08
#define __EncryptPad5_x                                            0xF0CAFC
#define __AC1_x                                                    0x7EDD86
#define __AC2_x                                                    0x5C3EDF
#define __AC3_x                                                    0x5CAD6F
#define __AC4_x                                                    0x5CEBF0
#define __AC5_x                                                    0x5D4E30
#define __AC6_x                                                    0x5D9372
#define __AC7_x                                                    0x5C3950
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1ADAB8

// Direct Input
#define DI8__Main_x                                                0xF0CB20
#define DI8__Keyboard_x                                            0xF0CB24
#define DI8__Mouse_x                                               0xF0CAE8
#define DI8__Mouse_Copy_x                                          0xE6A874
#define DI8__Mouse_Check_x                                         0xF0D9E8
#define __AutoSkillArray_x                                         0xE6B784
#define __Attack_x                                                 0xF09563
#define __Autofire_x                                               0xF09564
#define __BindList_x                                               0xBE0088
#define g_eqCommandStates_x                                        0xBE0DF8
#define __Clicks_x                                                 0xE6A92C
#define __CommandList_x                                            0xBE19B0
#define __CurrentMapLabel_x                                        0x101F10C
#define __CurrentSocial_x                                          0xBCB710
#define __DoAbilityList_x                                          0xEA1084
#define __do_loot_x                                                0x591680
#define __DrawHandler_x                                            0x169A608
#define __GroupCount_x                                             0xE5D21A
#define __Guilds_x                                                 0xE61080
#define __gWorld_x                                                 0xE5B074
#define __HWnd_x                                                   0xF0CAEC
#define __heqmain_x                                                0x1017D44
#define __InChatMode_x                                             0xE6A85C
#define __LastTell_x                                               0xE6C780
#define __LMouseHeldTime_x                                         0xE6A998
#define __Mouse_x                                                  0xF0CB08
#define __MouseLook_x                                              0xE6A8F2
#define __MouseEventTime_x                                         0xF0A018
#define __gpbCommandEvent_x                                        0xE5AB98
#define __NetStatusToggle_x                                        0xE6A8F5
#define __PCNames_x                                                0xE6BD40
#define __RangeAttackReady_x                                       0xE6BA68
#define __RMouseHeldTime_x                                         0xE6A994
#define __RunWalkState_x                                           0xE6A860
#define __ScreenMode_x                                             0xDA93DC
#define __ScreenX_x                                                0xE6A814
#define __ScreenY_x                                                0xE6A810
#define __ScreenXMax_x                                             0xE6A818
#define __ScreenYMax_x                                             0xE6A81C
#define __ServerHost_x                                             0xE5AD63
#define __ServerName_x                                             0xEA1044
#define __ShiftKeyDown_x                                           0xE6AEEC
#define __ShowNames_x                                              0xE6BC20
#define __Socials_x                                                0xEA1144
#define __SubscriptionType_x                                       0x1060BEC
#define __TargetAggroHolder_x                                      0x1021ADC
#define __ZoneType_x                                               0xE6ACF0
#define __GroupAggro_x                                             0x1021B1C
#define __LoginName_x                                              0xF0D47C
#define __Inviter_x                                                0xF094E0
#define __AttackOnAssist_x                                         0xE6BBDC
#define __UseTellWindows_x                                         0xE6BED8
#define __gfMaxZoomCameraDistance_x                                0xAB2AD0
#define __gfMaxCameraDistance_x                                    0xADFBF0
#define __pulAutoRun_x                                             0xE6A910
#define __pulForward_x                                             0xE6BF10
#define __pulBackward_x                                            0xE6BF14
#define __pulTurnRight_x                                           0xE6BF18
#define __pulTurnLeft_x                                            0xE6BF1C
#define __pulStrafeLeft_x                                          0xE6BF20
#define __pulStrafeRight_x                                         0xE6BF24

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5D428
#define instEQZoneInfo_x                                           0xE6AAE8
#define instKeypressHandler_x                                      0xF09FC8
#define pinstActiveBanker_x                                        0xE5D1B8
#define pinstActiveCorpse_x                                        0xE5D1B0
#define pinstActiveGMaster_x                                       0xE5D1B4
#define pinstActiveMerchant_x                                      0xE5D1AC
#define pinstAggroInfo_x                                           0xC657D0
#define pinstAltAdvManager_x                                       0xDA9DC8
#define pinstAuraMgr_x                                             0xC764B8
#define pinstBandageTarget_x                                       0xE5D1C8
#define pinstCamActor_x                                            0xDA93CC
#define pinstCDBStr_x                                              0xDA8B24
#define pinstCDisplay_x                                            0xE5D410
#define pinstCEverQuest_x                                          0xF0CC40
#define pinstEverQuestInfo_x                                       0xE6A808
#define pinstCharData_x                                            0xE5D420
#define pinstCharSpawn_x                                           0xE5D204
#define pinstControlledMissile_x                                   0xE5AB18
#define pinstControlledPlayer_x                                    0xE5D204
#define pinstCResolutionHandler_x                                  0x169A838
#define pinstCSidlManager_x                                        0x16996CC
#define pinstCXWndManager_x                                        0x16996C0
#define instDynamicZone_x                                          0xE60F58
#define pinstDZMember_x                                            0xE61068
#define pinstDZTimerInfo_x                                         0xE6106C
#define pinstEQItemList_x                                          0xE59618
#define pinstEQObjectList_x                                        0xE5A808
#define instEQMisc_x                                               0xDA8A60
#define pinstEQSoundManager_x                                      0xDAA628
#define pinstEQSpellStrings_x                                      0xC73908
#define instExpeditionLeader_x                                     0xE60FA2
#define instExpeditionName_x                                       0xE60FE2
#define pinstGroup_x                                               0xE5D216
#define pinstImeManager_x                                          0x16996C4
#define pinstLocalPlayer_x                                         0xE5D1A8
#define pinstMercenaryData_x                                       0xF0A7B8
#define pinstMercenaryStats_x                                      0x1021C28
#define pinstMercAltAbilities_x                                    0xDAA398
#define pinstModelPlayer_x                                         0xE5D1C0
#define pinstPCData_x                                              0xE5D420
#define pinstRealEstateItems_x                                     0xF0BCA8
#define pinstSkillMgr_x                                            0xF0BD78
#define pinstSpawnManager_x                                        0xF0B368
#define pinstSpellManager_x                                        0xF0BF50
#define pinstSpellSets_x                                           0xF0218C
#define pinstStringTable_x                                         0xE5D07C
#define pinstSwitchManager_x                                       0xE5A9C8
#define pinstTarget_x                                              0xE5D1FC
#define pinstTargetObject_x                                        0xE5D40C
#define pinstTargetSwitch_x                                        0xE5AB38
#define pinstTaskMember_x                                          0xDA88F0
#define pinstTrackTarget_x                                         0xE5D408
#define pinstTradeTarget_x                                         0xE5D1BC
#define instTributeActive_x                                        0xDA8A85
#define pinstViewActor_x                                           0xDA93C8
#define pinstWorldData_x                                           0xE5AE6C
#define pinstZoneAddr_x                                            0xE6AD88
#define pinstPlayerPath_x                                          0xF0B400
#define pinstTargetIndicator_x                                     0xF0C1B8
#define pinstCTargetManager_x                                      0xF0C250
#define EQObject_Top_x                                             0xE5D1A4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDA8BEC
#define pinstCAchievementsWnd_x                                    0xDA8E88
#define pinstCActionsWnd_x                                         0xDA8E44
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDA9448
#define pinstCAdvancedLootWnd_x                                    0xDA93FC
#define pinstCAdventureLeaderboardWnd_x                            0x10188E0
#define pinstCAdventureRequestWnd_x                                0x1018990
#define pinstCAdventureStatsWnd_x                                  0x1018A40
#define pinstCAggroMeterWnd_x                                      0xDA8EB4
#define pinstCAlarmWnd_x                                           0xDA8E64
#define pinstCAlertHistoryWnd_x                                    0xDA8E40
#define pinstCAlertStackWnd_x                                      0xDA8BC4
#define pinstCAlertWnd_x                                           0xDA8BE8
#define pinstCAltStorageWnd_x                                      0x1018DA0
#define pinstCAudioTriggersWindow_x                                0xC65C60
#define pinstCAuraWnd_x                                            0xDA8EAC
#define pinstCAvaZoneWnd_x                                         0xDA8E28
#define pinstCBandolierWnd_x                                       0xDA9364
#define pinstCBankWnd_x                                            0xDA940C
#define pinstCBarterMerchantWnd_x                                  0x1019FE0
#define pinstCBarterSearchWnd_x                                    0x101A090
#define pinstCBarterWnd_x                                          0x101A140
#define pinstCBazaarConfirmationWnd_x                              0xDA8BC0
#define pinstCBazaarSearchWnd_x                                    0xDA8E58
#define pinstCBazaarWnd_x                                          0xDA8F54
#define pinstCBlockedBuffWnd_x                                     0xDA93F8
#define pinstCBlockedPetBuffWnd_x                                  0xDA941C
#define pinstCBodyTintWnd_x                                        0xDA8BF4
#define pinstCBookWnd_x                                            0xDA93A0
#define pinstCBreathWnd_x                                          0xDA8BFC
#define pinstCBuffWindowNORMAL_x                                   0xDA93B4
#define pinstCBuffWindowSHORT_x                                    0xDA93B8
#define pinstCBugReportWnd_x                                       0xDA8BD0
#define pinstCButtonWnd_x                                          0x16998B8
#define pinstCCastingWnd_x                                         0xDA8BCC
#define pinstCCastSpellWnd_x                                       0xDA8E70
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDA8C00
#define pinstCChatWindowManager_x                                  0x101AC00
#define pinstCClaimWnd_x                                           0x101AD58
#define pinstCColorPickerWnd_x                                     0xDA8E1C
#define pinstCCombatAbilityWnd_x                                   0xDA8EB0
#define pinstCCombatSkillsSelectWnd_x                              0xDA8E48
#define pinstCCompassWnd_x                                         0xDA8BE0
#define pinstCConfirmationDialog_x                                 0x101FC58
#define pinstCContainerMgr_x                                       0xDA935C
#define pinstCContextMenuManager_x                                 0x1699680
#define pinstCCursorAttachment_x                                   0xDA944C
#define pinstCDynamicZoneWnd_x                                     0x101B320
#define pinstCEditLabelWnd_x                                       0xDA93AC
#define pinstCEQMainWnd_x                                          0x101B568
#define pinstCEventCalendarWnd_x                                   0xDA8EA4
#define pinstCExtendedTargetWnd_x                                  0xDA8EA0
#define pinstCFacePick_x                                           0xDA8E24
#define pinstCFellowshipWnd_x                                      0x101B768
#define pinstCFileSelectionWnd_x                                   0xDA93E0
#define pinstCFindItemWnd_x                                        0xDA8EC0
#define pinstCFindLocationWnd_x                                    0x101B8C0
#define pinstCFriendsWnd_x                                         0xDA8E60
#define pinstCGemsGameWnd_x                                        0xDA8E3C
#define pinstCGiveWnd_x                                            0xDA9374
#define pinstCGroupSearchFiltersWnd_x                              0xDA8ECC
#define pinstCGroupSearchWnd_x                                     0x101BCB8
#define pinstCGroupWnd_x                                           0x101BD68
#define pinstCGuildBankWnd_x                                       0xE6BBC4
#define pinstCGuildCreationWnd_x                                   0x101BEC8
#define pinstCGuildMgmtWnd_x                                       0x101BF78
#define pinstCharacterCreation_x                                   0xDA8EBC
#define pinstCHelpWnd_x                                            0xDA8E7C
#define pinstCHeritageSelectionWnd_x                               0xDA8E34
#define pinstCHotButtonWnd_x                                       0x101E0D0
#define pinstCHotButtonWnd1_x                                      0x101E0D0
#define pinstCHotButtonWnd2_x                                      0x101E0D4
#define pinstCHotButtonWnd3_x                                      0x101E0D8
#define pinstCHotButtonWnd4_x                                      0x101E0DC
#define pinstCIconSelectionWnd_x                                   0xDA9424
#define pinstCInspectWnd_x                                         0xDA9418
#define pinstCInventoryWnd_x                                       0xDA9360
#define pinstCInvSlotMgr_x                                         0xDA8E9C
#define pinstCItemDisplayManager_x                                 0x101E660
#define pinstCItemExpTransferWnd_x                                 0x101E794
#define pinstCItemOverflowWnd_x                                    0xDA8E5C
#define pinstCJournalCatWnd_x                                      0xDA9410
//#define pinstCJournalNPCWnd_x                                      0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDA93B0
#define pinstCKeyRingWnd_x                                         0xDA93C0
#define pinstCLargeDialogWnd_x                                     0x10208D8
#define pinstCLayoutCopyWnd_x                                      0x101EAE0
#define pinstCLFGuildWnd_x                                         0x101EB90
#define pinstCLoadskinWnd_x                                        0xDA8E54
#define pinstCLootFiltersCopyWnd_x                                 0xC76C98
#define pinstCLootFiltersWnd_x                                     0xDA8C04
#define pinstCLootSettingsWnd_x                                    0xDA8E14
#define pinstCLootWnd_x                                            0xDA8C0C
#define pinstCMailAddressBookWnd_x                                 0xDA942C
#define pinstCMailCompositionWnd_x                                 0xDA9414
#define pinstCMailIgnoreListWnd_x                                  0xDA9434
#define pinstCMailWnd_x                                            0xDA93E4
#define pinstCManageLootWnd_x                                      0xDAA240
#define pinstCMapToolbarWnd_x                                      0xDA936C
#define pinstCMapViewWnd_x                                         0xDA8ED4
#define pinstCMarketplaceWnd_x                                     0xDA8EC4
#define pinstCMerchantWnd_x                                        0xDA8E38
#define pinstCMIZoneSelectWnd_x                                    0x101F3C8
#define pinstCMusicPlayerWnd_x                                     0xDA93D0
#define pinstCNameChangeMercWnd_x                                  0xDA9400
#define pinstCNameChangePetWnd_x                                   0xDA93C4
#define pinstCNameChangeWnd_x                                      0xDA8EA8
#define pinstCNoteWnd_x                                            0xDA8E74
#define pinstCObjectPreviewWnd_x                                   0xDA9378
#define pinstCOptionsWnd_x                                         0xDA9368
#define pinstCPetInfoWnd_x                                         0xDA9408
#define pinstCPetitionQWnd_x                                       0xDA9420
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDA8BF0
#define pinstCPlayerWnd_x                                          0xDA8E6C
#define pinstCPopupWndManager_x                                    0x101FC58
#define pinstCProgressionSelectionWnd_x                            0x101FD08
#define pinstCPurchaseGroupWnd_x                                   0xDA93BC
#define pinstCPurchaseWnd_x                                        0xDA939C
#define pinstCPvPLeaderboardWnd_x                                  0x101FDB8
#define pinstCPvPStatsWnd_x                                        0x101FE68
#define pinstCQuantityWnd_x                                        0xDA9428
#define pinstCRaceChangeWnd_x                                      0xDA8ED8
#define pinstCRaidOptionsWnd_x                                     0xDA8ED0
#define pinstCRaidWnd_x                                            0xDA9440
#define pinstCRealEstateItemsWnd_x                                 0xDA8E90
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA8EB8
#define pinstCRealEstateManageWnd_x                                0xDA8E2C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDA8E4C
#define pinstCRealEstatePlotSearchWnd_x                            0xDA8E68
#define pinstCRealEstatePurchaseWnd_x                              0xDA8E78
#define pinstCRespawnWnd_x                                         0xDA8EC8
//#define pinstCRewardSelectionWnd_x                                 0x10205B0
#define pinstCSelectorWnd_x                                        0xDA8E98
#define pinstCSendMoneyWnd_x                                       0xDA93A8
#define pinstCServerListWnd_x                                      0xDA8E8C
#define pinstCSkillsSelectWnd_x                                    0xDA8E20
#define pinstCSkillsWnd_x                                          0xDA8E10
#define pinstCSocialEditWnd_x                                      0xDA943C
#define pinstCSocialWnd_x                                          0xDA9430
#define pinstCSpellBookWnd_x                                       0xDA8E94
#define pinstCStoryWnd_x                                           0xDA8BC8
#define pinstCTargetOfTargetWnd_x                                  0x1021CB0
#define pinstCTargetWnd_x                                          0xDA9404
#define pinstCTaskOverlayWnd_x                                     0xDA8E50
#define pinstCTaskSelectWnd_x                                      0x1021E08
#define pinstCTaskSomething_x                                      0xC77498
#define pinstCTaskTemplateSelectWnd_x                              0x1021EB8
#define pinstCTaskWnd_x                                            0x1021F68
#define pinstCTextEntryWnd_x                                       0xDA8BE4
#define pinstCTextOverlay_x                                        0xC65F70
#define pinstCTimeLeftWnd_x                                        0xDA93F0
#define pinstCTipWndCONTEXT_x                                      0x102216C
#define pinstCTipWndOFDAY_x                                        0x1022168
#define pinstCTitleWnd_x                                           0x1022218
#define pinstCTrackingWnd_x                                        0xDA93F4
#define pinstCTradeskillWnd_x                                      0x1022380
#define pinstCTradeWnd_x                                           0xDA8E80
#define pinstCTrainWnd_x                                           0xDA9438
#define pinstCTributeBenefitWnd_x                                  0x1022580
#define pinstCTributeMasterWnd_x                                   0x1022630
#define pinstCTributeTrophyWnd_x                                   0x10226E0
#define pinstCVideoModesWnd_x                                      0xDA9444
#define pinstCVoiceMacroWnd_x                                      0xF0C780
#define pinstCVoteResultsWnd_x                                     0xDA93A4
#define pinstCVoteWnd_x                                            0xDA9370
#define pinstCWebManager_x                                         0xF0C8E4
#define pinstCZoneGuideWnd_x                                       0xDA8E18
#define pinstCZonePathWnd_x                                        0xDA8E30

#define pinstEQSuiteTextureLoader_x                                0xC50C10
#define pinstItemIconCache_x                                       0x101B520
#define pinstLootFiltersManager_x                                  0xC76D48
#define pinstRewardSelectionWnd_x                                  0x10205B0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC01C0C
#define __CastRay_x                                                0x58CBA0
#define __CastRay2_x                                               0x58CBF0
#define __ConvertItemTags_x                                        0x5A77C0
#define __CrashHandler_x                                           0x83B250
#define __EQGetTime_x                                              0x8D8C30
#define __ExecuteCmd_x                                             0x585550
#define __FixHeading_x                                             0x969560
#define __get_bearing_x                                            0x58C6E0
#define __get_melee_range_x                                        0x58CDE0
#define __GetAnimationCache_x                                      0x6F9540
#define __GetGaugeValueFromEQ_x                                    0x7EC5A0
#define __GetLabelFromEQ_x                                         0x7EDD10
#define __GetXTargetType_x                                         0x96B030
#define __HeadingDiff_x                                            0x9695D0
#define __HelpPath_x                                               0xF09C34
#define __LoadFrontEnd_x                                           0x691E40
#define __NewUIINI_x                                               0x7EC270
#define __pCrashHandler_x                                          0x103FA48
#define __ProcessGameEvents_x                                      0x5E9C60
#define __ProcessMouseEvent_x                                      0x5E9420
#define __SaveColors_x                                             0x537A20
#define __STMLToText_x                                             0x90CB40
#define __ToggleKeyRingItem_x                                      0x4FB060
#define CrashDetected_x                                            0x693930
#define DrawNetStatus_x                                            0x615320
#define Expansion_HoT_x                                            0xE6BBCC
#define Teleport_Table_Size_x                                      0xE5AC20
#define Teleport_Table_x                                           0xE5B078
#define Util__FastTime_x                                           0x8D87F0
#define wwsCrashReportCheckForUploader_x                           0x83BD70
#define wwsCrashReportPlatformLaunchUploader_x                     0x83E430
#define __SaveColors_x                                             0x537A20

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A8F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4936A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493480

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53F100
#define AltAdvManager__IsAbilityReady_x                            0x53E1C0
#define AltAdvManager__GetAAById_x                                 0x53E3C0
#define AltAdvManager__CanTrainAbility_x                           0x53E430
#define AltAdvManager__CanSeeAbility_x                             0x53E660

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C5960
#define CharacterZoneClient__HasSkill_x                            0x4D0AF0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2210
#define CharacterZoneClient__IsStackBlocked_x                      0x4B9D10
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B63E0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4770
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4850
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D4930
#define CharacterZoneClient__FindAffectSlot_x                      0x4BE800
#define CharacterZoneClient__BardCastBard_x                        0x4C1480
#define CharacterZoneClient__GetMaxEffects_x                       0x4B64B0
#define CharacterZoneClient__GetEffect_x                           0x4B6320
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4BF810
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4BF8E0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4BF930
#define CharacterZoneClient__CalcAffectChange_x                    0x4BFA80
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4BFC50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BBFC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6C9930

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F7D20
#define CButtonWnd__CButtonWnd_x                                   0x908F80

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6E7F10
#define CChatManager__InitContextMenu_x                            0x6E2360
#define CChatManager__FreeChatWindow_x                             0x6E6EA0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EB7C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6E7CB0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x91D770
#define CContextMenu__dCContextMenu_x                              0x91D9A0
#define CContextMenu__AddMenuItem_x                                0x91D9B0
#define CContextMenu__RemoveMenuItem_x                             0x91DCC0
#define CContextMenu__RemoveAllMenuItems_x                         0x91DCE0
#define CContextMenu__CheckMenuItem_x                              0x91DD60
#define CContextMenu__SetMenuItem_x                                0x91DBE0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x91E300
#define CContextMenuManager__RemoveMenu_x                          0x91E370
#define CContextMenuManager__PopupMenu_x                           0x91E430
#define CContextMenuManager__Flush_x                               0x91E2A0
#define CContextMenuManager__GetMenu_x                             0x4955F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BB3D0
#define CChatService__GetFriendName_x                              0x8BB3E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6E8480
#define CChatWindow__Clear_x                                       0x6E94E0
#define CChatWindow__WndNotification_x                             0x6E9A50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91ABF0
#define CComboWnd__Draw_x                                          0x91A0E0
#define CComboWnd__GetCurChoice_x                                  0x91AA30
#define CComboWnd__GetListRect_x                                   0x91A590
#define CComboWnd__GetTextRect_x                                   0x91AC60
#define CComboWnd__InsertChoice_x                                  0x91A720
#define CComboWnd__SetColors_x                                     0x91A6F0
#define CComboWnd__SetChoice_x                                     0x91AA00
#define CComboWnd__GetItemCount_x                                  0x91AA40
#define CComboWnd__GetCurChoiceText_x                              0x91AA80

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F1720
#define CContainerWnd__vftable_x                                   0xAC66F8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5377E0
#define CDisplay__GetClickedActor_x                                0x52A840
#define CDisplay__GetUserDefinedColor_x                            0x522F40
#define CDisplay__GetWorldFilePath_x                               0x52C290
#define CDisplay__is3dON_x                                         0x527530
#define CDisplay__ReloadUI_x                                       0x5319B0
#define CDisplay__WriteTextHD2_x                                   0x527310
#define CDisplay__TrueDistance_x                                   0x52DEF0
#define CDisplay__SetViewActor_x                                   0x52A190

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93CEF0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x921E80
#define CEditWnd__GetCharIndexPt_x                                 0x922D70
#define CEditWnd__GetDisplayString_x                               0x922C10
#define CEditWnd__GetHorzOffset_x                                  0x9214B0
#define CEditWnd__GetLineForPrintableChar_x                        0x923E80
#define CEditWnd__GetSelStartPt_x                                  0x923020
#define CEditWnd__GetSTMLSafeText_x                                0x922A30
#define CEditWnd__PointFromPrintableChar_x                         0x923AC0
#define CEditWnd__SelectableCharFromPoint_x                        0x923C30
#define CEditWnd__SetEditable_x                                    0x9230E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5D88A0
#define CEverQuest__ClickedPlayer_x                                0x5CAB50
#define CEverQuest__CreateTargetIndicator_x                        0x5E6F40
#define CEverQuest__DeleteTargetIndicator_x                        0x5E6FD0
#define CEverQuest__DoTellWindow_x                                 0x4E0AE0
#define CEverQuest__OutputTextToLog_x                              0x4E0D10
#define CEverQuest__DropHeldItemOnGround_x                         0x5C0410
#define CEverQuest__dsp_chat_x                                     0x4E10A0
#define CEverQuest__trimName_x                                     0x5E35C0
#define CEverQuest__Emote_x                                        0x5D90B0
#define CEverQuest__EnterZone_x                                    0x5D3220
#define CEverQuest__GetBodyTypeDesc_x                              0x5DCE50
#define CEverQuest__GetClassDesc_x                                 0x5DD490
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DDA90
#define CEverQuest__GetDeityDesc_x                                 0x5E5950
#define CEverQuest__GetLangDesc_x                                  0x5DDC50
#define CEverQuest__GetRaceDesc_x                                  0x5DD470
#define CEverQuest__InterpretCmd_x                                 0x5E5F20
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C4600
#define CEverQuest__LMouseUp_x                                     0x5C2980
#define CEverQuest__RightClickedOnPlayer_x                         0x5C4EE0
#define CEverQuest__RMouseUp_x                                     0x5C3910
#define CEverQuest__SetGameState_x                                 0x5C01A0
#define CEverQuest__UPCNotificationFlush_x                         0x5E34C0
#define CEverQuest__IssuePetCommand_x                              0x5DF050
#define CEverQuest__ReportSuccessfulHit_x                          0x5D9D50

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7036A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x703700
#define CGaugeWnd__Draw_x                                          0x702DA0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AB9B0
#define CGuild__GetGuildName_x                                     0x4AA9F0
#define CGuild__GetGuildIndex_x                                    0x4AAD80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x71EBD0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72BA00
#define CInvSlotMgr__MoveItem_x                                    0x72A720
#define CInvSlotMgr__SelectSlot_x                                  0x72BAD0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x728FD0
#define CInvSlot__SliderComplete_x                                 0x726E00
#define CInvSlot__GetItemBase_x                                    0x726780
#define CInvSlot__UpdateItem_x                                     0x7268F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x72D410
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72C6E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7E87F0
#define CItemDisplayWnd__UpdateStrings_x                           0x73B180
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x735320
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7357F0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73B710
#define CItemDisplayWnd__AboutToShow_x                             0x73ADE0
#define CItemDisplayWnd__WndNotification_x                         0x73C9D0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8202B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x740A40

// CLabel 
#define CLabel__Draw_x                                             0x7464F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F3390
#define CListWnd__dCListWnd_x                                      0x8F36B0
#define CListWnd__AddColumn_x                                      0x8F79C0
#define CListWnd__AddColumn1_x                                     0x8F7A10
#define CListWnd__AddLine_x                                        0x8F7DA0
#define CListWnd__AddString_x                                      0x8F7BA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8F7780
#define CListWnd__CalculateVSBRange_x                              0x8F7560
#define CListWnd__ClearSel_x                                       0x8F8580
#define CListWnd__ClearAllSel_x                                    0x8F85E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8F8FF0
#define CListWnd__Compare_x                                        0x8F6EA0
#define CListWnd__Draw_x                                           0x8F37B0
#define CListWnd__DrawColumnSeparators_x                           0x8F5F80
#define CListWnd__DrawHeader_x                                     0x8F63E0
#define CListWnd__DrawItem_x                                       0x8F67E0
#define CListWnd__DrawLine_x                                       0x8F60E0
#define CListWnd__DrawSeparator_x                                  0x8F6020
#define CListWnd__EnableLine_x                                     0x8F5860
#define CListWnd__EnsureVisible_x                                  0x8F8F10
#define CListWnd__ExtendSel_x                                      0x8F84B0
#define CListWnd__GetColumnMinWidth_x                              0x8F53A0
#define CListWnd__GetColumnWidth_x                                 0x8F5310
#define CListWnd__GetCurSel_x                                      0x8F4CA0
#define CListWnd__GetItemAtPoint_x                                 0x8F5AD0
#define CListWnd__GetItemAtPoint1_x                                0x8F5B40
#define CListWnd__GetItemData_x                                    0x8F4D20
#define CListWnd__GetItemHeight_x                                  0x8F50E0
#define CListWnd__GetItemIcon_x                                    0x8F4EB0
#define CListWnd__GetItemRect_x                                    0x8F5950
#define CListWnd__GetItemText_x                                    0x8F4D60
#define CListWnd__GetSelList_x                                     0x8F8630
#define CListWnd__GetSeparatorRect_x                               0x8F5D80
#define CListWnd__InsertLine_x                                     0x8F8190
#define CListWnd__RemoveLine_x                                     0x8F82E0
#define CListWnd__SetColors_x                                      0x8F7530
#define CListWnd__SetColumnJustification_x                         0x8F7260
#define CListWnd__SetColumnWidth_x                                 0x8F7180
#define CListWnd__SetCurSel_x                                      0x8F83F0
#define CListWnd__SetItemColor_x                                   0x8F8BC0
#define CListWnd__SetItemData_x                                    0x8F8B80
#define CListWnd__SetItemText_x                                    0x8F87B0
#define CListWnd__ShiftColumnSeparator_x                           0x8F7320
#define CListWnd__Sort_x                                           0x8F7020
#define CListWnd__ToggleSel_x                                      0x8F8420

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75B8D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x77EAC0
#define CMerchantWnd__RequestBuyItem_x                             0x77F3A0
#define CMerchantWnd__RequestSellItem_x                            0x77F8D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x782710
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x77F120
#define CMerchantWnd__ActualSelect_x                               0x788230

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x887960
#define CPacketScrambler__hton_x                                   0x887950

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x912130
#define CSidlManager__FindScreenPieceTemplate_x                    0x912540
#define CSidlManager__FindScreenPieceTemplate1_x                   0x912330
#define CSidlManager__CreateLabel_x                                0x7DFCB0
#define CSidlManager__CreateXWndFromTemplate_x                     0x915610
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9157F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x90ECB0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x90EBB0
#define CSidlScreenWnd__ConvertToRes_x                             0x9336C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x90E640
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x90E330
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x90E400
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x90E4D0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x90F140
#define CSidlScreenWnd__EnableIniStorage_x                         0x90F610
#define CSidlScreenWnd__GetSidlPiece_x                             0x90F330
#define CSidlScreenWnd__Init1_x                                    0x90DF20
#define CSidlScreenWnd__LoadIniInfo_x                              0x90F660
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9101A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90D320
#define CSidlScreenWnd__StoreIniInfo_x                             0x90FD20
#define CSidlScreenWnd__StoreIniVis_x                              0x910080
#define CSidlScreenWnd__WndNotification_x                          0x90F050
#define CSidlScreenWnd__GetChildItem_x                             0x90F590
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8FEDF0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1699550

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65B6C0
#define CSkillMgr__GetSkillCap_x                                   0x65B8A0
#define CSkillMgr__GetNameToken_x                                  0x65AE50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x91F100
#define CSliderWnd__SetValue_x                                     0x91EF70
#define CSliderWnd__SetNumTicks_x                                  0x91EFD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E5A20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x925D30
#define CStmlWnd__CalculateHSBRange_x                              0x926DA0
#define CStmlWnd__CalculateVSBRange_x                              0x926D10
#define CStmlWnd__CanBreakAtCharacter_x                            0x92B0E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92BCD0
#define CStmlWnd__ForceParseNow_x                                  0x9262D0
#define CStmlWnd__GetNextTagPiece_x                                0x92B040
#define CStmlWnd__GetSTMLText_x                                    0x4EEFE0
#define CStmlWnd__GetVisibleText_x                                 0x9262F0
#define CStmlWnd__InitializeWindowVariables_x                      0x92BB20
#define CStmlWnd__MakeStmlColorTag_x                               0x9254C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x925530
#define CStmlWnd__SetSTMLText_x                                    0x924590
#define CStmlWnd__StripFirstSTMLLines_x                            0x92CE30
#define CStmlWnd__UpdateHistoryString_x                            0x92BEE0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x930500
#define CTabWnd__DrawCurrentPage_x                                 0x930B20
#define CTabWnd__DrawTab_x                                         0x9308F0
#define CTabWnd__GetCurrentPage_x                                  0x92FD60
#define CTabWnd__GetPageInnerRect_x                                0x92FFA0
#define CTabWnd__GetTabInnerRect_x                                 0x92FEE0
#define CTabWnd__GetTabRect_x                                      0x92FD90
#define CTabWnd__InsertPage_x                                      0x930190
#define CTabWnd__SetPage_x                                         0x930020
#define CTabWnd__SetPageRect_x                                     0x930440
#define CTabWnd__UpdatePage_x                                      0x9307B0
#define CTabWnd__GetPageFromTabIndex_x                             0x930830
#define CTabWnd__GetCurrentTabIndex_x                              0x92FD50

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x740EF0
#define CPageWnd__SetTabText_x                                     0x93D300

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A54B0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FBC70
#define CTextureFont__GetTextExtent_x                              0x8FBE30

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x68EBE0
#define CHtmlComponentWnd__ValidateUri_x                           0x720530
#define CHtmlWnd__SetClientCallbacks_x                             0x5FCF50
#define CHtmlWnd__AddObserver_x                                    0x5FCF70
#define CHtmlWnd__RemoveObserver_x                                 0x5FCFD0
#define Window__getProgress_x                                      0x838EC0
#define Window__getStatus_x                                        0x838EE0
#define Window__getURI_x                                           0x838EF0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x939880

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8E8B00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ACCF0
#define CXStr__CXStr1_x                                            0x9AB240
#define CXStr__CXStr3_x                                            0x8D4D20
#define CXStr__dCXStr_x                                            0x4721D0
#define CXStr__operator_equal_x                                    0x8D4F50
#define CXStr__operator_equal1_x                                   0x8D4F90
#define CXStr__operator_plus_equal1_x                              0x8D5A20

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91D380
#define CXWnd__BringToTop_x                                        0x9025B0
#define CXWnd__Center_x                                            0x902130
#define CXWnd__ClrFocus_x                                          0x901F70
#define CXWnd__Destroy_x                                           0x902020
#define CXWnd__DoAllDrawing_x                                      0x8FE5A0
#define CXWnd__DrawChildren_x                                      0x8FE570
#define CXWnd__DrawColoredRect_x                                   0x8FEA00
#define CXWnd__DrawTooltip_x                                       0x8FD0C0
#define CXWnd__DrawTooltipAtPoint_x                                0x8FD180
#define CXWnd__GetBorderFrame_x                                    0x8FE860
#define CXWnd__GetChildWndAt_x                                     0x902650
#define CXWnd__GetClientClipRect_x                                 0x900820
#define CXWnd__GetScreenClipRect_x                                 0x9008C0
#define CXWnd__GetScreenRect_x                                     0x900A70
#define CXWnd__GetTooltipRect_x                                    0x8FEA50
#define CXWnd__GetWindowTextA_x                                    0x496BC0
#define CXWnd__IsActive_x                                          0x905510
#define CXWnd__IsDescendantOf_x                                    0x901480
#define CXWnd__IsReallyVisible_x                                   0x9014B0
#define CXWnd__IsType_x                                            0x902CB0
#define CXWnd__Move_x                                              0x901520
#define CXWnd__Move1_x                                             0x9015D0
#define CXWnd__ProcessTransition_x                                 0x9020E0
#define CXWnd__Refade_x                                            0x9018B0
#define CXWnd__Resize_x                                            0x901B80
#define CXWnd__Right_x                                             0x902370
#define CXWnd__SetFocus_x                                          0x901F30
#define CXWnd__SetFont_x                                           0x901FA0
#define CXWnd__SetKeyTooltip_x                                     0x902AD0
#define CXWnd__SetMouseOver_x                                      0x8FF990
#define CXWnd__StartFade_x                                         0x901350
#define CXWnd__GetChildItem_x                                      0x9027C0
#define CXWnd__SetParent_x                                         0x901220

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x934790

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x905550
#define CXWndManager__DrawWindows_x                                0x905570
#define CXWndManager__GetKeyboardFlags_x                           0x907C40
#define CXWndManager__HandleKeyboardMsg_x                          0x907840
#define CXWndManager__RemoveWnd_x                                  0x907E90
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9083F0

// CDBStr
#define CDBStr__GetString_x                                        0x521EF0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7390
#define EQ_Character__Cur_HP_x                                     0x4CDB80
#define EQ_Character__Cur_Mana_x                                   0x4D4E30
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BA300
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AE740
#define EQ_Character__GetFocusRangeModifier_x                      0x4AE890
#define EQ_Character__GetHPRegen_x                                 0x4DA420
#define EQ_Character__GetEnduranceRegen_x                          0x4DAA30
#define EQ_Character__GetManaRegen_x                               0x4DAE70
#define EQ_Character__Max_Endurance_x                              0x622770
#define EQ_Character__Max_HP_x                                     0x4CD9B0
#define EQ_Character__Max_Mana_x                                   0x6225F0
#define EQ_Character__doCombatAbility_x                            0x6248C0
#define EQ_Character__UseSkill_x                                   0x4DCC80
#define EQ_Character__GetConLevel_x                                0x61C080
#define EQ_Character__IsExpansionFlag_x                            0x583F00
#define EQ_Character__TotalEffect_x                                0x4C0A00
#define EQ_Character__GetPCSpellAffect_x                           0x4BAEF0
#define EQ_Character__SpellDuration_x                              0x4BAA20
#define EQ_Character__FindItemByRecord_x                           0x4D3180
#define EQ_Character__GetAdjustedSkill_x                           0x4D08B0
#define EQ_Character__GetBaseSkill_x                               0x4D1850
#define EQ_Character__CanUseItem_x                                 0x4D5140

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8A6840

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x638730

//PcClient
#define PcClient__PcClient_x                                       0x619940

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5170
#define CCharacterListWnd__EnterWorld_x                            0x4B4BB0
#define CCharacterListWnd__Quit_x                                  0x4B48C0
#define CCharacterListWnd__UpdateList_x                            0x4B4D40

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5FE160
#define EQ_Item__CreateItemTagString_x                             0x881BF0
#define EQ_Item__IsStackable_x                                     0x885E30
#define EQ_Item__GetImageNum_x                                     0x883470
#define EQ_Item__CreateItemClient_x                                0x5FD330
#define EQ_Item__GetItemValue_x                                    0x884550
#define EQ_Item__ValueSellMerchant_x                               0x887500
#define EQ_Item__IsKeyRingItem_x                                   0x885800
#define EQ_Item__CanGoInBag_x                                      0x5FE280
#define EQ_Item__GetMaxItemCount_x                                 0x884650
#define EQ_Item__GetHeldItem_x                                     0x883280
#define EQ_Item__GetAugmentFitBySlot_x                             0x881740

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x53FE90
#define EQ_LoadingS__Array_x                                       0xBD9298

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x623070
#define EQ_PC__GetAlternateAbilityId_x                             0x890500
#define EQ_PC__GetCombatAbility_x                                  0x890B70
#define EQ_PC__GetCombatAbilityTimer_x                             0x890BE0
#define EQ_PC__GetItemRecastTimer_x                                0x624E40
#define EQ_PC__HasLoreItem_x                                       0x61C7F0
#define EQ_PC__AlertInventoryChanged_x                             0x61BB50
#define EQ_PC__GetPcZoneClient_x                                   0x646E50
#define EQ_PC__RemoveMyAffect_x                                    0x627FF0
#define EQ_PC__GetKeyRingItems_x                                   0x891480
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x891200
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x891770

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58A130
#define EQItemList__add_object_x                                   0x5B5B50
#define EQItemList__add_item_x                                     0x58A740
#define EQItemList__delete_item_x                                  0x58A790
#define EQItemList__FreeItemList_x                                 0x58A690

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51F560

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x639FB0
#define EQPlayer__dEQPlayer_x                                      0x62D6A0
#define EQPlayer__DoAttack_x                                       0x641B60
#define EQPlayer__EQPlayer_x                                       0x62DD50
#define EQPlayer__SetNameSpriteState_x                             0x632020
#define EQPlayer__SetNameSpriteTint_x                              0x632EB0
#define PlayerBase__HasProperty_j_x                                0x9678F0
#define EQPlayer__IsTargetable_x                                   0x967D90
#define EQPlayer__CanSee_x                                         0x967BF0
#define EQPlayer__CanSee1_x                                        0x967CC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9679B0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x644920
#define PlayerZoneClient__GetLevel_x                               0x646E90
#define PlayerZoneClient__IsValidTeleport_x                        0x5B6CA0
#define PlayerZoneClient__LegalPlayerRace_x                        0x539560

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63CCA0
#define EQPlayerManager__GetSpawnByName_x                          0x63CCC0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63CD50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x601A50
#define KeypressHandler__AttachKeyToEqCommand_x                    0x601A90
#define KeypressHandler__ClearCommandStateArray_x                  0x602E80
#define KeypressHandler__HandleKeyDown_x                           0x602EA0
#define KeypressHandler__HandleKeyUp_x                             0x602F40
#define KeypressHandler__SaveKeymapping_x                          0x603320

// MapViewMap 
#define MapViewMap__Clear_x                                        0x757760
#define MapViewMap__SaveEx_x                                       0x75AB00
#define MapViewMap__SetZoom_x                                      0x75F1E0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A4730

// StringTable 
#define StringTable__getString_x                                   0x89F620

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x627C60
#define PcZoneClient__RemovePetEffect_x                            0x628290
#define PcZoneClient__HasAlternateAbility_x                        0x622430
#define PcZoneClient__GetCurrentMod_x                              0x4DFBC0
#define PcZoneClient__GetModCap_x                                  0x4DFAC0
#define PcZoneClient__CanEquipItem_x                               0x622A00
#define PcZoneClient__GetItemByID_x                                0x6252B0
#define PcZoneClient__GetItemByItemClass_x                         0x625340
#define PcZoneClient__RemoveBuffEffect_x                           0x6282B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BB830

//IconCache
#define IconCache__GetIcon_x                                       0x6F8DD0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F08C0
#define CContainerMgr__CloseContainer_x                            0x6F0B90

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B25D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F6520

//CLootWnd
#define CLootWnd__LootAll_x                                        0x74DC20
#define CLootWnd__RequestLootSlot_x                                0x74CFD0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5584B0
#define EQ_Spell__SpellAffects_x                                   0x558920
#define EQ_Spell__SpellAffectBase_x                                0x5586E0
#define EQ_Spell__IsStackable_x                                    0x4C5250
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C50A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B27F0
#define EQ_Spell__IsSPAStacking_x                                  0x559560
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x558C70
#define EQ_Spell__IsNoRemove_x                                     0x4C5230
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x559570
#define __IsResEffectSpell_x                                       0x4C4580

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9630

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B06F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7F7CC0
#define CTargetWnd__WndNotification_x                              0x7F7550
#define CTargetWnd__RefreshTargetBuffs_x                           0x7F7820
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7F66A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FC380

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5539F0
#define EqSoundManager__PlayScriptMp3_x                            0x553B50
#define EqSoundManager__SoundAssistPlay_x                          0x65F210
#define EqSoundManager__WaveInstancePlay_x                         0x65E750

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x510F70

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x920AE0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x547A60
#define CAltAbilityData__GetMercMaxRank_x                          0x547A00
#define CAltAbilityData__GetMaxRank_x                              0x53D2B0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F4630

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5080
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7450
#define CharacterBase__CreateItemIndex_x                           0x5FC560
#define CharacterBase__GetItemPossession_x                         0x4B26A0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8B8F00
#define CharacterBase__GetEffectId_x                               0x4C5030

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6D8E50
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6D9670

//messages
#define msg_spell_worn_off_x                                       0x57C850
#define msg_new_text_x                                             0x571A40
#define __msgTokenTextParam_x                                      0x57EEA0
#define msgTokenText_x                                             0x57F0F0

//SpellManager
#define SpellManager__vftable_x                                    0xAA17F8
#define SpellManager__SpellManager_x                               0x6624F0
#define Spellmanager__LoadTextSpells_x                             0x662870

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96B920

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F7B00
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x582600
#define ItemGlobalIndex__IsEquippedLocation_x                      0x615180
#define ItemGlobalIndex__IsValidIndex_x                            0x4F7B60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B10D0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B1350

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x746830

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F5010
#define CCursorAttachment__Deactivate_x                            0x6F5FE0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x932A50
#define CEQSuiteTextureLoader__GetTexture_x                        0x932710

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F4AF0

//IString
#define IString__Append_x                                          0x4E90E0

//Camera
#define CDisplay__cameraType_x                                     0xDA8C08
#define EverQuest__Cameras_x                                       0xE6BEE4

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FD2E0
#define LootFiltersManager__GetItemFilterData_x                    0x4FCBD0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FCC00
#define LootFiltersManager__SetItemLootFilter_x                    0x4FCE20

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A0670

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x971620
#define CResolutionHandler__GetWindowedStyle_x                     0x65A280

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
#ifdef EMU
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\xFD\xFF\xFF\x8B\xCE\x5E\xE9\x00\x00\xFF\xFF\xC7\x01";
static char lpMask[] = "xxxx?xxxxxxx??xxxx";
#else
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
#endif
